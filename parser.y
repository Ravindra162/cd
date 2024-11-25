%{
    #include<stdio.h>
    #include<stdlib.h>
    #include<ctype.h>
    #include<string.h>
    extern char* yytext;
    void yyerror(char*);

    int searchST(char*);
    void insertST(char*, char*);
    void insert_type(char*, char*);
    void insert_value(char*, double);
    void insert_scope(char*, int);
    void insert_line(char*, int);
    int check_type(char*);
    double get_value(char*);
    void print();

    int temp = 0;      // For temporary variables
    int label = 0;     // For labels
    char cur_type[20]; // Current type
    extern int line;   // Line number
    extern int scope;  // Scope number
    int param_count=0;

    // Function to generate new temporary variable
    char* newTemp() {
        static char temp_var[10];
        sprintf(temp_var, "t%d", temp++);
        return strdup(temp_var);
    }

    // Function to generate new label
    int newLabel() {
        return ++label;
    }

    // Structure for expressions
    struct ExpRecord {
        char* code;    // Generated code
        char* place;   // Place to store result
        double value;  // Actual value
    };

    // Initialize a new struct ExpRecord
    struct ExpRecord* makeExp() {
        struct ExpRecord* e = (struct ExpRecord*)malloc(sizeof(struct ExpRecord));
        e->code = (char*)malloc(1000);
        e->code[0] = '\0';
        e->place = NULL;
        e->value = 0;
        return e;
    }

    // Backpatch function for control flow
    void backpatch(char* code, int label, char* target) {
        char label_str[10];
        sprintf(label_str, "L%d", label);
        char* pos = strstr(code, label_str);
        if (pos) {
            strcpy(pos, target);
        }
    }

    extern char current_iden[30];
%}

%union{
    int integer;
    double dou;
    char str[20];
    struct ExpRecord* exp;
}

%token<integer>NUM 
%token<dou>FLOAT
%token <str> IDENTIFIER STRING
%token NL INT FLOAT_ID IF ELSE FOR WHILE IN DE LE GE L G SC EQ MAIN RETURN BREAK CONTINUE PRINTF SCANF
%type<exp> S st E T F stmt loop if_loop w f init inc cond relat iden main printf scanf return args
%%
main: type MAIN '(' ')' '{' S '}' {
        printf("\n// Main function\n");
        printf("main:\n");
        printf("%s", $6->code);
        print();
    };

start: S {printf("\n// Statement sequence\n");
        printf("%s", $1->code);
        print();
        }

S : stmt S {
        $$ = makeExp();
        sprintf($$->code, "%s%s", $1->code, $2->code);
    }
    | { 
        $$ = makeExp();
        $$->code[0] = '\0';
    };

stmt : type iden SC {
        $$ = makeExp();
        insert_type($2, cur_type);
        if(scope == 0) {
            sprintf($$->code, "// Declaration Global: %s %s\n", cur_type, $2);
            char dec[100];
            sprintf(dec, "%s = %s\n", $2, "0");
            strcat($$->code, dec);
            insert_value($2, 0);
        } else {
        sprintf($$->code, "// Declaration: %s %s\n", cur_type, $2);
        }
        insert_scope($2, scope);
    }
    | type iden '=' E SC {
        $$ = makeExp();
        insert_type($2, cur_type);
        sprintf($$->code, "%s%s = %s\n", 
            $4->code, $2, $4->place);
        insert_value($2, $4->value);
        insert_scope($2, scope);

    }
    | iden '=' E SC {
        $$ = makeExp();
        if(check_type(yytext)) {
            printf("Error in %s at line %d\n", $1, line);
            $$->code[0] = '\0';
        } else {
            sprintf($$->code, "%s%s = %s\n", 
                $3->code, $1, $3->place);
            insert_value($1, $3->value);
        }

    }
    | if_loop 
    | loop
    | return
    | printf
    | scanf
    ;


st : stmt st {
        $$ = makeExp();
        sprintf($$->code, "%s%s", $1->code, $2->code);
    }
    | {
        $$ = makeExp();
        $$->code[0] = '\0';
    };

if_loop : IF '(' cond ')' '{' st '}' ELSE '{' st '}' {
        $$ = makeExp();
        int else_label = newLabel();
        int end_label = newLabel();
        sprintf($$->code, "%s"           // Condition code
                        "if !(%s) goto L%d\n"  // False branch
                        "%s"                   // True block
                        "goto L%d\n"           // Skip else
                        "L%d:\n"               // Else label
                        "%s"                   // Else block
                        "L%d:\n",              // End label
                $3->code, $3->place, else_label,
                $6->code, 
                end_label,
                else_label,
                $10->code,
                end_label);
    }
    | IF '(' cond ')' '{' st '}' {
        $$ = makeExp();
        int end_label = newLabel();
        sprintf($$->code, "%s"           // Condition code
                        "if !(%s) goto L%d\n"  // False branch
                        "%s"                   // True block
                        "L%d:\n",              // End label
                $3->code, $3->place, end_label,
                $6->code,
                end_label);
    };

loop : f | w;

w : WHILE '(' cond ')' '{' st '}' {
        $$ = makeExp();
        int start_label = newLabel();
        int end_label = newLabel();
        sprintf($$->code, "L%d:\n"             // Loop start
                        "%s"                   // Condition
                        "if !(%s) goto L%d\n"  // Exit loop
                        "%s"                   // Loop body
                        "goto L%d\n"           // Loop back
                        "L%d:\n",              // End label
                start_label,
                $3->code, $3->place, end_label,
                $6->code,
                start_label,
                end_label);
    };

f : FOR '(' init SC cond SC inc ')' '{' st '}' {
        $$ = makeExp();
        int start_label = newLabel();
        int end_label = newLabel();
        int inc_label = newLabel();
        sprintf($$->code, "%s"                 // Initialization
                        "L%d:\n"               // Loop start
                        "%s"                   // Condition
                        "if !(%s) goto L%d\n"  // Exit loop
                        "%s"                   // Loop body
                        "L%d:\n"               // Increment
                        "%s"                   // Increment code
                        "goto L%d\n"           // Loop back
                        "L%d:\n",              // End label
                $3->code,
                start_label,
                $5->code, $5->place, end_label,
                $10->code,
                inc_label,
                $7->code,
                start_label,
                end_label);
    };

init : type iden '=' NUM {
        $$ = makeExp();
        insert_type($2, cur_type);
        insert_value($2, $4);
        sprintf($$->code, "%s = %d\n", $2, $4);
    };

inc : iden IN {
        $$ = makeExp();
        char* temp = newTemp();
        sprintf($$->code, "%s = %s + 1\n%s = %s\n", 
                temp, $1, $1, temp);
    } 
    | iden DE {
        $$ = makeExp();
        char* temp = newTemp();
        sprintf($$->code, "%s = %s - 1\n%s = %s\n",
                temp, $1, $1, temp);
    };

cond : iden relat iden {
        $$ = makeExp();
        $$->place = newTemp();
        sprintf($$->code, "%s = %s %s %s\n",
                $$->place, $1, $2->place, $3);
    }
    | iden relat NUM {
        $$ = makeExp();
        $$->place = newTemp();
        sprintf($$->code, "%s = %s %s %d\n",
                $$->place, $1, $2->place, $3);
    };

relat : GE { 
        $$ = makeExp();
        $$->place = ">=";
    }
    | LE {
        $$ = makeExp();
        $$->place = "<=";
    }
    | L {
        $$ = makeExp();
        $$->place = "<";
    }
    | G {
        $$ = makeExp();
        $$->place = ">";
    }
    |
    EQ {
        $$ = makeExp();
        $$->place = "==";
    };
    ;

type : INT {strcpy(cur_type, "integer");}
     | FLOAT_ID {strcpy(cur_type, "float");};

E : E '+' T {
        $$ = makeExp();
        $$->place = newTemp();
        sprintf($$->code, "%s%s%s = %s + %s\n",
                $1->code, $3->code,
                $$->place, $1->place, $3->place);
        $$->value = $1->value + $3->value;
    }
    | E '-' T {
        $$ = makeExp();
        $$->place = newTemp();
        sprintf($$->code, "%s%s%s = %s - %s\n",
                $1->code, $3->code,
                $$->place, $1->place, $3->place);
        $$->value = $1->value - $3->value;
    }
    | T {
        $$ = $1;
    };

T : T '*' F {
        $$ = makeExp();
        $$->place = newTemp();
        sprintf($$->code, "%s%s%s = %s * %s\n",
                $1->code, $3->code,
                $$->place, $1->place, $3->place);
        $$->value = $1->value * $3->value;
    }
    | T '/' F {
        $$ = makeExp();
        if($3->value != 0) {
            $$->place = newTemp();
            sprintf($$->code, "%s%s%s = %s / %s\n",
                    $1->code, $3->code,
                    $$->place, $1->place, $3->place);
            $$->value = $1->value / $3->value;
        } else {
            printf("Division by zero error\n");
            $$->code[0] = '\0';
            $$->place = "INF";
            $$->value = 0;
        }
    }
    | F {
        $$ = $1;
    };

F : '(' E ')' {
        $$ = $2;
    }
    | NUM {
        $$ = makeExp();
        $$->place = (char*)malloc(20);
        sprintf($$->place, "%d", $1);
        $$->code[0] = '\0';
        $$->value = $1;
        $$ = makeExp();
        $$->place = (char*)malloc(20);
        sprintf($$->place, "%d", $1);
        $$->code[0] = '\0';
        $$->value = $1;
    }
    | iden {
        $$ = makeExp();
        // printf("iden: %s\n", $1);
        if(check_type($1)) {
            printf("Error in %s at line %d\n", $1, line);
            $$->code[0] = '\0';
            $$->place = "0";
            $$->value = 0;
        } else {
            $$->place = strdup($1);
            $$->code[0] = '\0';
            $$->value = get_value($1);
        }
    }
    ;

iden: IDENTIFIER {
        $$ = strdup(current_iden);
        
    };

return : RETURN E SC {
        $$ = makeExp();
        sprintf($$->code, "%sreturn %s\n", $2->code, $2->place);
    };

printf : PRINTF '(' args ')' SC {
        $$ = makeExp();
        sprintf($$->code, "%s call printf, %d\n",$3->code, (int) $3->value);
    };

scanf : SCANF '(' args')' SC {
        $$ = makeExp();
        sprintf($$->code, "%s call scanf, %l\n",$3->code,(int) $3->value);
    };

args : args ',' args {
        $$ = makeExp();
        $$->value = $1->value + $3->value;
        sprintf($$->code, "%s%s", $1->code, $3->code);
    }
    | STRING {
        $$ = makeExp();
        $$->value = 1;
        sprintf($$->code,"putparam %s\n", $1);
    }
    | iden {
        $$ = makeExp();
        $$->value = 1;
        sprintf($$->code,"putparam %s\n", $1);
    };



%%

void yyerror(char*s) {
    printf("Error: %s at line %d\n", s, line);
}

int main() {
    printf("Starting compilation...\n");
    yyparse();
    return 0;
}