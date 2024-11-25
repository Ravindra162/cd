%{
    #include "y.tab.h"
    #include <stdio.h>
    #include <stdlib.h>
    #include <ctype.h>
    #include <string.h>

    int scope = 0, line = 1;
    
    struct SymbolTable {
        char name[20];
        char type[20];
        char t[20];
        int scope;
        int exist;
        double value;
        int line;
    } ST[100];

    int searchST(char* s) {
        for(int i = 0; i < 100; i++) {
            if(ST[i].exist == 1 && strcmp(ST[i].name, s) == 0) {
                return 1;
            }
        }
        return 0;
    }

    void insertST(char* s, char* t) {
        if(searchST(s)) return;

        for(int i = 0; i < 100; i++) {
            if(ST[i].exist == 0) {
                strcpy(ST[i].name, s);
                strcpy(ST[i].type, t);
                ST[i].line = yylineno;
                ST[i].scope = scope;
                ST[i].exist = 1;  // Fixed: Set exist flag
                ST[i].value = -1;

                if(strcmp(t, "integer") != 0 && strcmp(t, "float") != 0) {
                    ST[i].scope = 0;
                }
                return;
            }
        }
        printf("Symbol table is full\n");
    }

    void insert_type(char* s, char* t) {
        for(int i = 0; i < 100; i++) {
            if(ST[i].exist == 1 && strcmp(ST[i].name, s) == 0) {
                strcpy(ST[i].t, t);
                return;
            }
        }
    }

    void insert_value(char* s, double x) {
        for(int i = 0; i < 100; i++) {
            if(ST[i].exist == 1 && strcmp(ST[i].name, s) == 0) {
                ST[i].value = x;
                return;
            }
        }
    }

    void insert_scope(char* s, int t) {
        for(int i = 0; i < 100; i++) {
            if(ST[i].exist == 1 && strcmp(ST[i].name, s) == 0) {
                ST[i].scope = t;
                return;
            }
        }
    }

    void insert_line(char* s, int t) {
        for(int i = 0; i < 100; i++) {
            if(ST[i].exist == 1 && strcmp(ST[i].name, s) == 0) {
                ST[i].line = t;
                return;
            }
        }
    }

    int check_type(char* s) {
        for(int i = 0; i < 100; i++) {
            if(ST[i].exist == 1 && strcmp(ST[i].name, s) == 0) {
                if(strcmp(ST[i].t, "integer") != 0 && strcmp(ST[i].t, "float") != 0) {
                    return 1;
                }
            }
        }
        return 0;
    }

    double get_value(char* s) {
        for(int i = 0; i < 100; i++) {
            if(ST[i].exist == 1 && strcmp(ST[i].name, s) == 0) {
                return ST[i].value;
            }
        }
        printf("Variable not found: %s\n", s);
        return -1;
    }

    void print() {
        printf("\nSYMBOL TABLE\n");
        printf("%-20s %-10s %-10s %-8s %-8s %-10s %-6s\n", 
               "Name", "Type", "DataType", "Scope", "Exists", "Value", "Line");
        printf("----------------------------------------------------------------\n");
        for(int i = 0; i < 100; i++) {
            if(ST[i].exist == 1) {
                printf("%-20s %-10s %-10s %-8d %-8d %-10.2f %-6d\n",
                       ST[i].name, ST[i].type, ST[i].t, ST[i].scope, 
                       ST[i].exist, ST[i].value, ST[i].line);
            }
        }
        printf("\n");
    }

    char current_iden[30];
%}
DE "define"
IN "include"

%%
([#][" "]*({IN})[ ]*([<]?)([A-Za-z]+)[.]?([A-Za-z]*)([>]?))/["\n"|\/|" "|"\t"]	{ }
([#][" "]*({DE})[" "]*([A-Za-z]+)(" ")*[0-9]+)/["\n"|\/|" "|"\t"]				{ } 
\/\/(.*)																		{ }
\/\*([^*]|[\r\n]|(\*+([^*/]|[\r\n])))*\*+\/										{ }

[0-9]+\.[0-9]+    { yylval.dou = atof(yytext); insertST(yytext, "float"); return FLOAT; }
[0-9]+            { yylval.integer = atoi(yytext); insertST(yytext, "integer"); return NUM; }
"+"               { insertST(yytext, "operator"); return '+'; }
"*"               { insertST(yytext, "operator"); return '*'; }
"-"               { insertST(yytext, "operator"); return '-'; }
"="               { insertST(yytext, "operator"); return '='; }
"++"              { insertST(yytext, "operator"); return IN; }
"--"              { insertST(yytext, "operator"); return DE; }
"=="              { insertST(yytext, "operator"); return EQ; }
">="              { insertST(yytext, "operator"); return GE; }
"<="              { insertST(yytext, "operator"); return LE; }
"<"               { insertST(yytext, "operator"); return L; }
">"               { insertST(yytext, "operator"); return G; }
"/"               { insertST(yytext, "operator"); return '/'; }
"("               { insertST(yytext, "separator"); scope++; return '('; }
")"               { insertST(yytext, "separator"); scope--; return ')'; }
"{"               { insertST(yytext, "separator"); scope++; return '{'; }
"}"               { insertST(yytext, "separator"); scope--; return '}'; }
"int"             { insertST(yytext, "keyword"); return INT; }
"float"           { insertST(yytext, "keyword"); return FLOAT_ID; }
"if"              { insertST(yytext, "keyword"); return IF; }
"else"            { insertST(yytext, "keyword"); return ELSE; }
"while"           { insertST(yytext, "keyword"); return WHILE; }
"for"             { insertST(yytext, "keyword"); return FOR; }
"main"            { insertST(yytext, "keyword"); return MAIN; }
"return"          { insertST(yytext, "keyword"); return RETURN; }
"break"           { insertST(yytext, "keyword"); return BREAK; }
"continue"        { insertST(yytext, "keyword"); return CONTINUE; }
"printf"          { insertST(yytext, "function"); return PRINTF; }
"scanf"           { insertST(yytext, "function"); return SCANF; }
[A-Za-z_][A-Za-z0-9_]* { insertST(yytext, "identifier"); strcpy(current_iden,yytext); return IDENTIFIER; }
";"               {  return SC; }
","              { insertST(yytext, "separator"); return ','; }
\"[^\"]*\"        { insertST(yytext, "string"); strcpy(yylval.str,yytext); return STRING; }
[\n]              { line++; }
[ \t\r]           ; /* Skip whitespace */
.                 { printf("Lexical error: Unknown character '%s' at line %d\n", yytext, line); }

%%

int yywrap() {
    return 1;
}