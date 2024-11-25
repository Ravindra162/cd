/* A Bison parser, made by GNU Bison 3.8.2.  */

/* Bison implementation for Yacc-like parsers in C

   Copyright (C) 1984, 1989-1990, 2000-2015, 2018-2021 Free Software Foundation,
   Inc.

   This program is free software: you can redistribute it and/or modify
   it under the terms of the GNU General Public License as published by
   the Free Software Foundation, either version 3 of the License, or
   (at your option) any later version.

   This program is distributed in the hope that it will be useful,
   but WITHOUT ANY WARRANTY; without even the implied warranty of
   MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
   GNU General Public License for more details.

   You should have received a copy of the GNU General Public License
   along with this program.  If not, see <https://www.gnu.org/licenses/>.  */

/* As a special exception, you may create a larger work that contains
   part or all of the Bison parser skeleton and distribute that work
   under terms of your choice, so long as that work isn't itself a
   parser generator using the skeleton or a modified version thereof
   as a parser skeleton.  Alternatively, if you modify or redistribute
   the parser skeleton itself, you may (at your option) remove this
   special exception, which will cause the skeleton and the resulting
   Bison output files to be licensed under the GNU General Public
   License without this special exception.

   This special exception was added by the Free Software Foundation in
   version 2.2 of Bison.  */

/* C LALR(1) parser skeleton written by Richard Stallman, by
   simplifying the original so-called "semantic" parser.  */

/* DO NOT RELY ON FEATURES THAT ARE NOT DOCUMENTED in the manual,
   especially those whose name start with YY_ or yy_.  They are
   private implementation details that can be changed or removed.  */

/* All symbols defined below should begin with yy or YY, to avoid
   infringing on user name space.  This should be done even for local
   variables, as they might otherwise be expanded by user macros.
   There are some unavoidable exceptions within include files to
   define necessary library symbols; they are noted "INFRINGES ON
   USER NAME SPACE" below.  */

/* Identify Bison output, and Bison version.  */
#define YYBISON 30802

/* Bison version string.  */
#define YYBISON_VERSION "3.8.2"

/* Skeleton name.  */
#define YYSKELETON_NAME "yacc.c"

/* Pure parsers.  */
#define YYPURE 0

/* Push parsers.  */
#define YYPUSH 0

/* Pull parsers.  */
#define YYPULL 1




/* First part of user prologue.  */
#line 1 "parser.y"

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

#line 138 "y.tab.c"

# ifndef YY_CAST
#  ifdef __cplusplus
#   define YY_CAST(Type, Val) static_cast<Type> (Val)
#   define YY_REINTERPRET_CAST(Type, Val) reinterpret_cast<Type> (Val)
#  else
#   define YY_CAST(Type, Val) ((Type) (Val))
#   define YY_REINTERPRET_CAST(Type, Val) ((Type) (Val))
#  endif
# endif
# ifndef YY_NULLPTR
#  if defined __cplusplus
#   if 201103L <= __cplusplus
#    define YY_NULLPTR nullptr
#   else
#    define YY_NULLPTR 0
#   endif
#  else
#   define YY_NULLPTR ((void*)0)
#  endif
# endif

/* Use api.header.include to #include this header
   instead of duplicating it here.  */
#ifndef YY_YY_Y_TAB_H_INCLUDED
# define YY_YY_Y_TAB_H_INCLUDED
/* Debug traces.  */
#ifndef YYDEBUG
# define YYDEBUG 0
#endif
#if YYDEBUG
extern int yydebug;
#endif

/* Token kinds.  */
#ifndef YYTOKENTYPE
# define YYTOKENTYPE
  enum yytokentype
  {
    YYEMPTY = -2,
    YYEOF = 0,                     /* "end of file"  */
    YYerror = 256,                 /* error  */
    YYUNDEF = 257,                 /* "invalid token"  */
    NUM = 258,                     /* NUM  */
    FLOAT = 259,                   /* FLOAT  */
    IDENTIFIER = 260,              /* IDENTIFIER  */
    STRING = 261,                  /* STRING  */
    NL = 262,                      /* NL  */
    INT = 263,                     /* INT  */
    FLOAT_ID = 264,                /* FLOAT_ID  */
    IF = 265,                      /* IF  */
    ELSE = 266,                    /* ELSE  */
    FOR = 267,                     /* FOR  */
    WHILE = 268,                   /* WHILE  */
    IN = 269,                      /* IN  */
    DE = 270,                      /* DE  */
    LE = 271,                      /* LE  */
    GE = 272,                      /* GE  */
    L = 273,                       /* L  */
    G = 274,                       /* G  */
    SC = 275,                      /* SC  */
    EQ = 276,                      /* EQ  */
    MAIN = 277,                    /* MAIN  */
    RETURN = 278,                  /* RETURN  */
    BREAK = 279,                   /* BREAK  */
    CONTINUE = 280,                /* CONTINUE  */
    PRINTF = 281,                  /* PRINTF  */
    SCANF = 282                    /* SCANF  */
  };
  typedef enum yytokentype yytoken_kind_t;
#endif
/* Token kinds.  */
#define YYEMPTY -2
#define YYEOF 0
#define YYerror 256
#define YYUNDEF 257
#define NUM 258
#define FLOAT 259
#define IDENTIFIER 260
#define STRING 261
#define NL 262
#define INT 263
#define FLOAT_ID 264
#define IF 265
#define ELSE 266
#define FOR 267
#define WHILE 268
#define IN 269
#define DE 270
#define LE 271
#define GE 272
#define L 273
#define G 274
#define SC 275
#define EQ 276
#define MAIN 277
#define RETURN 278
#define BREAK 279
#define CONTINUE 280
#define PRINTF 281
#define SCANF 282

/* Value type.  */
#if ! defined YYSTYPE && ! defined YYSTYPE_IS_DECLARED
union YYSTYPE
{
#line 68 "parser.y"

    int integer;
    double dou;
    char str[20];
    struct ExpRecord* exp;

#line 252 "y.tab.c"

};
typedef union YYSTYPE YYSTYPE;
# define YYSTYPE_IS_TRIVIAL 1
# define YYSTYPE_IS_DECLARED 1
#endif


extern YYSTYPE yylval;


int yyparse (void);


#endif /* !YY_YY_Y_TAB_H_INCLUDED  */
/* Symbol kind.  */
enum yysymbol_kind_t
{
  YYSYMBOL_YYEMPTY = -2,
  YYSYMBOL_YYEOF = 0,                      /* "end of file"  */
  YYSYMBOL_YYerror = 1,                    /* error  */
  YYSYMBOL_YYUNDEF = 2,                    /* "invalid token"  */
  YYSYMBOL_NUM = 3,                        /* NUM  */
  YYSYMBOL_FLOAT = 4,                      /* FLOAT  */
  YYSYMBOL_IDENTIFIER = 5,                 /* IDENTIFIER  */
  YYSYMBOL_STRING = 6,                     /* STRING  */
  YYSYMBOL_NL = 7,                         /* NL  */
  YYSYMBOL_INT = 8,                        /* INT  */
  YYSYMBOL_FLOAT_ID = 9,                   /* FLOAT_ID  */
  YYSYMBOL_IF = 10,                        /* IF  */
  YYSYMBOL_ELSE = 11,                      /* ELSE  */
  YYSYMBOL_FOR = 12,                       /* FOR  */
  YYSYMBOL_WHILE = 13,                     /* WHILE  */
  YYSYMBOL_IN = 14,                        /* IN  */
  YYSYMBOL_DE = 15,                        /* DE  */
  YYSYMBOL_LE = 16,                        /* LE  */
  YYSYMBOL_GE = 17,                        /* GE  */
  YYSYMBOL_L = 18,                         /* L  */
  YYSYMBOL_G = 19,                         /* G  */
  YYSYMBOL_SC = 20,                        /* SC  */
  YYSYMBOL_EQ = 21,                        /* EQ  */
  YYSYMBOL_MAIN = 22,                      /* MAIN  */
  YYSYMBOL_RETURN = 23,                    /* RETURN  */
  YYSYMBOL_BREAK = 24,                     /* BREAK  */
  YYSYMBOL_CONTINUE = 25,                  /* CONTINUE  */
  YYSYMBOL_PRINTF = 26,                    /* PRINTF  */
  YYSYMBOL_SCANF = 27,                     /* SCANF  */
  YYSYMBOL_28_ = 28,                       /* '('  */
  YYSYMBOL_29_ = 29,                       /* ')'  */
  YYSYMBOL_30_ = 30,                       /* '{'  */
  YYSYMBOL_31_ = 31,                       /* '}'  */
  YYSYMBOL_32_ = 32,                       /* '='  */
  YYSYMBOL_33_ = 33,                       /* '+'  */
  YYSYMBOL_34_ = 34,                       /* '-'  */
  YYSYMBOL_35_ = 35,                       /* '*'  */
  YYSYMBOL_36_ = 36,                       /* '/'  */
  YYSYMBOL_37_ = 37,                       /* ','  */
  YYSYMBOL_YYACCEPT = 38,                  /* $accept  */
  YYSYMBOL_main = 39,                      /* main  */
  YYSYMBOL_S = 40,                         /* S  */
  YYSYMBOL_stmt = 41,                      /* stmt  */
  YYSYMBOL_st = 42,                        /* st  */
  YYSYMBOL_if_loop = 43,                   /* if_loop  */
  YYSYMBOL_loop = 44,                      /* loop  */
  YYSYMBOL_w = 45,                         /* w  */
  YYSYMBOL_f = 46,                         /* f  */
  YYSYMBOL_init = 47,                      /* init  */
  YYSYMBOL_inc = 48,                       /* inc  */
  YYSYMBOL_cond = 49,                      /* cond  */
  YYSYMBOL_relat = 50,                     /* relat  */
  YYSYMBOL_type = 51,                      /* type  */
  YYSYMBOL_E = 52,                         /* E  */
  YYSYMBOL_T = 53,                         /* T  */
  YYSYMBOL_F = 54,                         /* F  */
  YYSYMBOL_iden = 55,                      /* iden  */
  YYSYMBOL_return = 56,                    /* return  */
  YYSYMBOL_printf = 57,                    /* printf  */
  YYSYMBOL_scanf = 58,                     /* scanf  */
  YYSYMBOL_args = 59                       /* args  */
};
typedef enum yysymbol_kind_t yysymbol_kind_t;




#ifdef short
# undef short
#endif

/* On compilers that do not define __PTRDIFF_MAX__ etc., make sure
   <limits.h> and (if available) <stdint.h> are included
   so that the code can choose integer types of a good width.  */

#ifndef __PTRDIFF_MAX__
# include <limits.h> /* INFRINGES ON USER NAME SPACE */
# if defined __STDC_VERSION__ && 199901 <= __STDC_VERSION__
#  include <stdint.h> /* INFRINGES ON USER NAME SPACE */
#  define YY_STDINT_H
# endif
#endif

/* Narrow types that promote to a signed type and that can represent a
   signed or unsigned integer of at least N bits.  In tables they can
   save space and decrease cache pressure.  Promoting to a signed type
   helps avoid bugs in integer arithmetic.  */

#ifdef __INT_LEAST8_MAX__
typedef __INT_LEAST8_TYPE__ yytype_int8;
#elif defined YY_STDINT_H
typedef int_least8_t yytype_int8;
#else
typedef signed char yytype_int8;
#endif

#ifdef __INT_LEAST16_MAX__
typedef __INT_LEAST16_TYPE__ yytype_int16;
#elif defined YY_STDINT_H
typedef int_least16_t yytype_int16;
#else
typedef short yytype_int16;
#endif

/* Work around bug in HP-UX 11.23, which defines these macros
   incorrectly for preprocessor constants.  This workaround can likely
   be removed in 2023, as HPE has promised support for HP-UX 11.23
   (aka HP-UX 11i v2) only through the end of 2022; see Table 2 of
   <https://h20195.www2.hpe.com/V2/getpdf.aspx/4AA4-7673ENW.pdf>.  */
#ifdef __hpux
# undef UINT_LEAST8_MAX
# undef UINT_LEAST16_MAX
# define UINT_LEAST8_MAX 255
# define UINT_LEAST16_MAX 65535
#endif

#if defined __UINT_LEAST8_MAX__ && __UINT_LEAST8_MAX__ <= __INT_MAX__
typedef __UINT_LEAST8_TYPE__ yytype_uint8;
#elif (!defined __UINT_LEAST8_MAX__ && defined YY_STDINT_H \
       && UINT_LEAST8_MAX <= INT_MAX)
typedef uint_least8_t yytype_uint8;
#elif !defined __UINT_LEAST8_MAX__ && UCHAR_MAX <= INT_MAX
typedef unsigned char yytype_uint8;
#else
typedef short yytype_uint8;
#endif

#if defined __UINT_LEAST16_MAX__ && __UINT_LEAST16_MAX__ <= __INT_MAX__
typedef __UINT_LEAST16_TYPE__ yytype_uint16;
#elif (!defined __UINT_LEAST16_MAX__ && defined YY_STDINT_H \
       && UINT_LEAST16_MAX <= INT_MAX)
typedef uint_least16_t yytype_uint16;
#elif !defined __UINT_LEAST16_MAX__ && USHRT_MAX <= INT_MAX
typedef unsigned short yytype_uint16;
#else
typedef int yytype_uint16;
#endif

#ifndef YYPTRDIFF_T
# if defined __PTRDIFF_TYPE__ && defined __PTRDIFF_MAX__
#  define YYPTRDIFF_T __PTRDIFF_TYPE__
#  define YYPTRDIFF_MAXIMUM __PTRDIFF_MAX__
# elif defined PTRDIFF_MAX
#  ifndef ptrdiff_t
#   include <stddef.h> /* INFRINGES ON USER NAME SPACE */
#  endif
#  define YYPTRDIFF_T ptrdiff_t
#  define YYPTRDIFF_MAXIMUM PTRDIFF_MAX
# else
#  define YYPTRDIFF_T long
#  define YYPTRDIFF_MAXIMUM LONG_MAX
# endif
#endif

#ifndef YYSIZE_T
# ifdef __SIZE_TYPE__
#  define YYSIZE_T __SIZE_TYPE__
# elif defined size_t
#  define YYSIZE_T size_t
# elif defined __STDC_VERSION__ && 199901 <= __STDC_VERSION__
#  include <stddef.h> /* INFRINGES ON USER NAME SPACE */
#  define YYSIZE_T size_t
# else
#  define YYSIZE_T unsigned
# endif
#endif

#define YYSIZE_MAXIMUM                                  \
  YY_CAST (YYPTRDIFF_T,                                 \
           (YYPTRDIFF_MAXIMUM < YY_CAST (YYSIZE_T, -1)  \
            ? YYPTRDIFF_MAXIMUM                         \
            : YY_CAST (YYSIZE_T, -1)))

#define YYSIZEOF(X) YY_CAST (YYPTRDIFF_T, sizeof (X))


/* Stored state numbers (used for stacks). */
typedef yytype_int8 yy_state_t;

/* State numbers in computations.  */
typedef int yy_state_fast_t;

#ifndef YY_
# if defined YYENABLE_NLS && YYENABLE_NLS
#  if ENABLE_NLS
#   include <libintl.h> /* INFRINGES ON USER NAME SPACE */
#   define YY_(Msgid) dgettext ("bison-runtime", Msgid)
#  endif
# endif
# ifndef YY_
#  define YY_(Msgid) Msgid
# endif
#endif


#ifndef YY_ATTRIBUTE_PURE
# if defined __GNUC__ && 2 < __GNUC__ + (96 <= __GNUC_MINOR__)
#  define YY_ATTRIBUTE_PURE __attribute__ ((__pure__))
# else
#  define YY_ATTRIBUTE_PURE
# endif
#endif

#ifndef YY_ATTRIBUTE_UNUSED
# if defined __GNUC__ && 2 < __GNUC__ + (7 <= __GNUC_MINOR__)
#  define YY_ATTRIBUTE_UNUSED __attribute__ ((__unused__))
# else
#  define YY_ATTRIBUTE_UNUSED
# endif
#endif

/* Suppress unused-variable warnings by "using" E.  */
#if ! defined lint || defined __GNUC__
# define YY_USE(E) ((void) (E))
#else
# define YY_USE(E) /* empty */
#endif

/* Suppress an incorrect diagnostic about yylval being uninitialized.  */
#if defined __GNUC__ && ! defined __ICC && 406 <= __GNUC__ * 100 + __GNUC_MINOR__
# if __GNUC__ * 100 + __GNUC_MINOR__ < 407
#  define YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN                           \
    _Pragma ("GCC diagnostic push")                                     \
    _Pragma ("GCC diagnostic ignored \"-Wuninitialized\"")
# else
#  define YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN                           \
    _Pragma ("GCC diagnostic push")                                     \
    _Pragma ("GCC diagnostic ignored \"-Wuninitialized\"")              \
    _Pragma ("GCC diagnostic ignored \"-Wmaybe-uninitialized\"")
# endif
# define YY_IGNORE_MAYBE_UNINITIALIZED_END      \
    _Pragma ("GCC diagnostic pop")
#else
# define YY_INITIAL_VALUE(Value) Value
#endif
#ifndef YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
# define YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
# define YY_IGNORE_MAYBE_UNINITIALIZED_END
#endif
#ifndef YY_INITIAL_VALUE
# define YY_INITIAL_VALUE(Value) /* Nothing. */
#endif

#if defined __cplusplus && defined __GNUC__ && ! defined __ICC && 6 <= __GNUC__
# define YY_IGNORE_USELESS_CAST_BEGIN                          \
    _Pragma ("GCC diagnostic push")                            \
    _Pragma ("GCC diagnostic ignored \"-Wuseless-cast\"")
# define YY_IGNORE_USELESS_CAST_END            \
    _Pragma ("GCC diagnostic pop")
#endif
#ifndef YY_IGNORE_USELESS_CAST_BEGIN
# define YY_IGNORE_USELESS_CAST_BEGIN
# define YY_IGNORE_USELESS_CAST_END
#endif


#define YY_ASSERT(E) ((void) (0 && (E)))

#if !defined yyoverflow

/* The parser invokes alloca or malloc; define the necessary symbols.  */

# ifdef YYSTACK_USE_ALLOCA
#  if YYSTACK_USE_ALLOCA
#   ifdef __GNUC__
#    define YYSTACK_ALLOC __builtin_alloca
#   elif defined __BUILTIN_VA_ARG_INCR
#    include <alloca.h> /* INFRINGES ON USER NAME SPACE */
#   elif defined _AIX
#    define YYSTACK_ALLOC __alloca
#   elif defined _MSC_VER
#    include <malloc.h> /* INFRINGES ON USER NAME SPACE */
#    define alloca _alloca
#   else
#    define YYSTACK_ALLOC alloca
#    if ! defined _ALLOCA_H && ! defined EXIT_SUCCESS
#     include <stdlib.h> /* INFRINGES ON USER NAME SPACE */
      /* Use EXIT_SUCCESS as a witness for stdlib.h.  */
#     ifndef EXIT_SUCCESS
#      define EXIT_SUCCESS 0
#     endif
#    endif
#   endif
#  endif
# endif

# ifdef YYSTACK_ALLOC
   /* Pacify GCC's 'empty if-body' warning.  */
#  define YYSTACK_FREE(Ptr) do { /* empty */; } while (0)
#  ifndef YYSTACK_ALLOC_MAXIMUM
    /* The OS might guarantee only one guard page at the bottom of the stack,
       and a page size can be as small as 4096 bytes.  So we cannot safely
       invoke alloca (N) if N exceeds 4096.  Use a slightly smaller number
       to allow for a few compiler-allocated temporary stack slots.  */
#   define YYSTACK_ALLOC_MAXIMUM 4032 /* reasonable circa 2006 */
#  endif
# else
#  define YYSTACK_ALLOC YYMALLOC
#  define YYSTACK_FREE YYFREE
#  ifndef YYSTACK_ALLOC_MAXIMUM
#   define YYSTACK_ALLOC_MAXIMUM YYSIZE_MAXIMUM
#  endif
#  if (defined __cplusplus && ! defined EXIT_SUCCESS \
       && ! ((defined YYMALLOC || defined malloc) \
             && (defined YYFREE || defined free)))
#   include <stdlib.h> /* INFRINGES ON USER NAME SPACE */
#   ifndef EXIT_SUCCESS
#    define EXIT_SUCCESS 0
#   endif
#  endif
#  ifndef YYMALLOC
#   define YYMALLOC malloc
#   if ! defined malloc && ! defined EXIT_SUCCESS
void *malloc (YYSIZE_T); /* INFRINGES ON USER NAME SPACE */
#   endif
#  endif
#  ifndef YYFREE
#   define YYFREE free
#   if ! defined free && ! defined EXIT_SUCCESS
void free (void *); /* INFRINGES ON USER NAME SPACE */
#   endif
#  endif
# endif
#endif /* !defined yyoverflow */

#if (! defined yyoverflow \
     && (! defined __cplusplus \
         || (defined YYSTYPE_IS_TRIVIAL && YYSTYPE_IS_TRIVIAL)))

/* A type that is properly aligned for any stack member.  */
union yyalloc
{
  yy_state_t yyss_alloc;
  YYSTYPE yyvs_alloc;
};

/* The size of the maximum gap between one aligned stack and the next.  */
# define YYSTACK_GAP_MAXIMUM (YYSIZEOF (union yyalloc) - 1)

/* The size of an array large to enough to hold all stacks, each with
   N elements.  */
# define YYSTACK_BYTES(N) \
     ((N) * (YYSIZEOF (yy_state_t) + YYSIZEOF (YYSTYPE)) \
      + YYSTACK_GAP_MAXIMUM)

# define YYCOPY_NEEDED 1

/* Relocate STACK from its old location to the new one.  The
   local variables YYSIZE and YYSTACKSIZE give the old and new number of
   elements in the stack, and YYPTR gives the new location of the
   stack.  Advance YYPTR to a properly aligned location for the next
   stack.  */
# define YYSTACK_RELOCATE(Stack_alloc, Stack)                           \
    do                                                                  \
      {                                                                 \
        YYPTRDIFF_T yynewbytes;                                         \
        YYCOPY (&yyptr->Stack_alloc, Stack, yysize);                    \
        Stack = &yyptr->Stack_alloc;                                    \
        yynewbytes = yystacksize * YYSIZEOF (*Stack) + YYSTACK_GAP_MAXIMUM; \
        yyptr += yynewbytes / YYSIZEOF (*yyptr);                        \
      }                                                                 \
    while (0)

#endif

#if defined YYCOPY_NEEDED && YYCOPY_NEEDED
/* Copy COUNT objects from SRC to DST.  The source and destination do
   not overlap.  */
# ifndef YYCOPY
#  if defined __GNUC__ && 1 < __GNUC__
#   define YYCOPY(Dst, Src, Count) \
      __builtin_memcpy (Dst, Src, YY_CAST (YYSIZE_T, (Count)) * sizeof (*(Src)))
#  else
#   define YYCOPY(Dst, Src, Count)              \
      do                                        \
        {                                       \
          YYPTRDIFF_T yyi;                      \
          for (yyi = 0; yyi < (Count); yyi++)   \
            (Dst)[yyi] = (Src)[yyi];            \
        }                                       \
      while (0)
#  endif
# endif
#endif /* !YYCOPY_NEEDED */

/* YYFINAL -- State number of the termination state.  */
#define YYFINAL  5
/* YYLAST -- Last index in YYTABLE.  */
#define YYLAST   117

/* YYNTOKENS -- Number of terminals.  */
#define YYNTOKENS  38
/* YYNNTS -- Number of nonterminals.  */
#define YYNNTS  22
/* YYNRULES -- Number of rules.  */
#define YYNRULES  48
/* YYNSTATES -- Number of states.  */
#define YYNSTATES  111

/* YYMAXUTOK -- Last valid token kind.  */
#define YYMAXUTOK   282


/* YYTRANSLATE(TOKEN-NUM) -- Symbol number corresponding to TOKEN-NUM
   as returned by yylex, with out-of-bounds checking.  */
#define YYTRANSLATE(YYX)                                \
  (0 <= (YYX) && (YYX) <= YYMAXUTOK                     \
   ? YY_CAST (yysymbol_kind_t, yytranslate[YYX])        \
   : YYSYMBOL_YYUNDEF)

/* YYTRANSLATE[TOKEN-NUM] -- Symbol number corresponding to TOKEN-NUM
   as returned by yylex.  */
static const yytype_int8 yytranslate[] =
{
       0,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
      28,    29,    35,    33,    37,    34,     2,    36,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,    32,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,    30,     2,    31,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     1,     2,     3,     4,
       5,     6,     7,     8,     9,    10,    11,    12,    13,    14,
      15,    16,    17,    18,    19,    20,    21,    22,    23,    24,
      25,    26,    27
};

#if YYDEBUG
/* YYRLINE[YYN] -- Source line where rule number YYN was defined.  */
static const yytype_int16 yyrline[] =
{
       0,    81,    81,    93,    97,   102,   116,   125,   137,   138,
     139,   140,   141,   145,   149,   154,   172,   184,   184,   186,
     203,   227,   234,   240,   247,   253,   260,   264,   268,   272,
     277,   283,   284,   286,   294,   302,   306,   314,   329,   333,
     336,   348,   364,   369,   374,   379,   384,   389,   394
};
#endif

/** Accessing symbol of state STATE.  */
#define YY_ACCESSING_SYMBOL(State) YY_CAST (yysymbol_kind_t, yystos[State])

#if YYDEBUG || 0
/* The user-facing name of the symbol whose (internal) number is
   YYSYMBOL.  No bounds checking.  */
static const char *yysymbol_name (yysymbol_kind_t yysymbol) YY_ATTRIBUTE_UNUSED;

/* YYTNAME[SYMBOL-NUM] -- String name of the symbol SYMBOL-NUM.
   First, the terminals, then, starting at YYNTOKENS, nonterminals.  */
static const char *const yytname[] =
{
  "\"end of file\"", "error", "\"invalid token\"", "NUM", "FLOAT",
  "IDENTIFIER", "STRING", "NL", "INT", "FLOAT_ID", "IF", "ELSE", "FOR",
  "WHILE", "IN", "DE", "LE", "GE", "L", "G", "SC", "EQ", "MAIN", "RETURN",
  "BREAK", "CONTINUE", "PRINTF", "SCANF", "'('", "')'", "'{'", "'}'",
  "'='", "'+'", "'-'", "'*'", "'/'", "','", "$accept", "main", "S", "stmt",
  "st", "if_loop", "loop", "w", "f", "init", "inc", "cond", "relat",
  "type", "E", "T", "F", "iden", "return", "printf", "scanf", "args", YY_NULLPTR
};

static const char *
yysymbol_name (yysymbol_kind_t yysymbol)
{
  return yytname[yysymbol];
}
#endif

#define YYPACT_NINF (-42)

#define yypact_value_is_default(Yyn) \
  ((Yyn) == YYPACT_NINF)

#define YYTABLE_NINF (-1)

#define yytable_value_is_error(Yyn) \
  0

/* YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
   STATE-NUM.  */
static const yytype_int8 yypact[] =
{
      71,   -42,   -42,     5,   -15,   -42,   -17,     1,    -8,    34,
     -42,     4,     8,    21,     7,    27,    35,     3,    34,   -42,
     -42,   -42,   -42,    48,    49,   -42,   -42,   -42,    48,    71,
      48,   -42,     7,   -16,    50,   -42,   -42,    82,    82,   -42,
     -42,   -12,     7,    38,    57,    63,    48,    40,    37,   -42,
       7,     7,     7,     7,   -42,   -42,    19,    25,   -42,     7,
      -7,    68,   -42,   -42,   -42,   -42,   -42,    20,    48,    61,
      69,   -42,    50,    50,   -42,   -42,    80,    82,    81,    18,
     -42,    34,   -42,   -42,    83,    99,    34,   -42,    67,   -42,
     -42,    34,    74,    48,   -42,    76,   -42,    95,    79,    75,
     -42,    84,    85,   -42,   -42,    34,    34,    78,    86,   -42,
     -42
};

/* YYDEFACT[STATE-NUM] -- Default reduction number in state STATE-NUM.
   Performed when YYTABLE does not specify something else to do.  Zero
   means the default is an error.  */
static const yytype_int8 yydefact[] =
{
       0,    31,    32,     0,     0,     1,     0,     0,     0,     4,
      42,     0,     0,     0,     0,     0,     0,     0,     4,     8,
       9,    18,    17,     0,     0,    10,    11,    12,     0,     0,
       0,    40,     0,     0,    35,    38,    41,     0,     0,     2,
       3,     0,     0,     0,     0,     0,     0,     0,     0,    43,
       0,     0,     0,     0,    47,    48,     0,     0,     5,     0,
       0,     0,    27,    26,    28,    29,    30,     0,     0,     0,
       0,    39,    33,    34,    36,    37,     0,     0,     0,     0,
       7,    14,    25,    24,     0,     0,    14,    44,    46,    45,
       6,    14,     0,     0,    21,     0,    13,    16,     0,     0,
      19,     0,     0,    22,    23,    14,    14,     0,     0,    15,
      20
};

/* YYPGOTO[NTERM-NUM].  */
static const yytype_int8 yypgoto[] =
{
     -42,   -42,    92,     6,   -41,   -42,   -42,   -42,   -42,   -42,
     -42,   -27,   -42,     2,   -26,    41,    42,    -9,   -42,   -42,
     -42,   -37
};

/* YYDEFGOTO[NTERM-NUM].  */
static const yytype_int8 yydefgoto[] =
{
       0,     3,    17,    91,    92,    19,    20,    21,    22,    45,
      98,    43,    67,    23,    33,    34,    35,    36,    25,    26,
      27,    56
};

/* YYTABLE[YYPACT[STATE-NUM]] -- What to do in state STATE-NUM.  If
   positive, shift that token.  If negative, reduce the rule whose
   number is the opposite.  If YYTABLE_NINF, syntax error.  */
static const yytype_int8 yytable[] =
{
      24,    57,     4,    47,    49,     5,    48,     6,    58,    24,
      31,     7,    10,    80,    41,    18,    60,    50,    51,    44,
      59,    44,     9,    82,    18,    10,    50,    51,    55,    55,
       8,    46,    28,    79,    39,    32,    29,    69,    90,    10,
      88,    84,     1,     2,    11,    95,    12,    13,    76,    30,
      96,    50,    51,    10,    78,    37,    77,    14,    83,    44,
      15,    16,    77,    38,   107,   108,    71,    61,    55,    70,
      50,    51,    24,    62,    63,    64,    65,    24,    66,     1,
       2,    42,    24,    68,    99,    52,    53,    10,    54,   103,
     104,    72,    73,    85,    74,    75,    24,    24,    81,    86,
      87,    89,    94,    93,    77,    97,   101,   100,   102,   109,
      40,     0,     0,     0,   105,   106,     0,   110
};

static const yytype_int8 yycheck[] =
{
       9,    38,     0,    30,    20,     0,    32,    22,    20,    18,
       3,    28,     5,    20,    23,     9,    42,    33,    34,    28,
      32,    30,    30,     3,    18,     5,    33,    34,    37,    38,
      29,    29,    28,    59,    31,    28,    28,    46,    20,     5,
      77,    68,     8,     9,    10,    86,    12,    13,    29,    28,
      91,    33,    34,     5,    29,    28,    37,    23,    67,    68,
      26,    27,    37,    28,   105,   106,    29,    29,    77,    29,
      33,    34,    81,    16,    17,    18,    19,    86,    21,     8,
       9,    32,    91,    20,    93,    35,    36,     5,     6,    14,
      15,    50,    51,    32,    52,    53,   105,   106,    30,    30,
      20,    20,     3,    20,    37,    31,    11,    31,    29,    31,
      18,    -1,    -1,    -1,    30,    30,    -1,    31
};

/* YYSTOS[STATE-NUM] -- The symbol kind of the accessing symbol of
   state STATE-NUM.  */
static const yytype_int8 yystos[] =
{
       0,     8,     9,    39,    51,     0,    22,    28,    29,    30,
       5,    10,    12,    13,    23,    26,    27,    40,    41,    43,
      44,    45,    46,    51,    55,    56,    57,    58,    28,    28,
      28,     3,    28,    52,    53,    54,    55,    28,    28,    31,
      40,    55,    32,    49,    55,    47,    51,    49,    52,    20,
      33,    34,    35,    36,     6,    55,    59,    59,    20,    32,
      52,    29,    16,    17,    18,    19,    21,    50,    20,    55,
      29,    29,    53,    53,    54,    54,    29,    37,    29,    52,
      20,    30,     3,    55,    49,    32,    30,    20,    59,    20,
      20,    41,    42,    20,     3,    42,    42,    31,    48,    55,
      31,    11,    29,    14,    15,    30,    30,    42,    42,    31,
      31
};

/* YYR1[RULE-NUM] -- Symbol kind of the left-hand side of rule RULE-NUM.  */
static const yytype_int8 yyr1[] =
{
       0,    38,    39,    40,    40,    41,    41,    41,    41,    41,
      41,    41,    41,    42,    42,    43,    43,    44,    44,    45,
      46,    47,    48,    48,    49,    49,    50,    50,    50,    50,
      50,    51,    51,    52,    52,    52,    53,    53,    53,    54,
      54,    54,    55,    56,    57,    58,    59,    59,    59
};

/* YYR2[RULE-NUM] -- Number of symbols on the right-hand side of rule RULE-NUM.  */
static const yytype_int8 yyr2[] =
{
       0,     2,     7,     2,     0,     3,     5,     4,     1,     1,
       1,     1,     1,     2,     0,    11,     7,     1,     1,     7,
      11,     4,     2,     2,     3,     3,     1,     1,     1,     1,
       1,     1,     1,     3,     3,     1,     3,     3,     1,     3,
       1,     1,     1,     3,     5,     5,     3,     1,     1
};


enum { YYENOMEM = -2 };

#define yyerrok         (yyerrstatus = 0)
#define yyclearin       (yychar = YYEMPTY)

#define YYACCEPT        goto yyacceptlab
#define YYABORT         goto yyabortlab
#define YYERROR         goto yyerrorlab
#define YYNOMEM         goto yyexhaustedlab


#define YYRECOVERING()  (!!yyerrstatus)

#define YYBACKUP(Token, Value)                                    \
  do                                                              \
    if (yychar == YYEMPTY)                                        \
      {                                                           \
        yychar = (Token);                                         \
        yylval = (Value);                                         \
        YYPOPSTACK (yylen);                                       \
        yystate = *yyssp;                                         \
        goto yybackup;                                            \
      }                                                           \
    else                                                          \
      {                                                           \
        yyerror (YY_("syntax error: cannot back up")); \
        YYERROR;                                                  \
      }                                                           \
  while (0)

/* Backward compatibility with an undocumented macro.
   Use YYerror or YYUNDEF. */
#define YYERRCODE YYUNDEF


/* Enable debugging if requested.  */
#if YYDEBUG

# ifndef YYFPRINTF
#  include <stdio.h> /* INFRINGES ON USER NAME SPACE */
#  define YYFPRINTF fprintf
# endif

# define YYDPRINTF(Args)                        \
do {                                            \
  if (yydebug)                                  \
    YYFPRINTF Args;                             \
} while (0)




# define YY_SYMBOL_PRINT(Title, Kind, Value, Location)                    \
do {                                                                      \
  if (yydebug)                                                            \
    {                                                                     \
      YYFPRINTF (stderr, "%s ", Title);                                   \
      yy_symbol_print (stderr,                                            \
                  Kind, Value); \
      YYFPRINTF (stderr, "\n");                                           \
    }                                                                     \
} while (0)


/*-----------------------------------.
| Print this symbol's value on YYO.  |
`-----------------------------------*/

static void
yy_symbol_value_print (FILE *yyo,
                       yysymbol_kind_t yykind, YYSTYPE const * const yyvaluep)
{
  FILE *yyoutput = yyo;
  YY_USE (yyoutput);
  if (!yyvaluep)
    return;
  YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
  YY_USE (yykind);
  YY_IGNORE_MAYBE_UNINITIALIZED_END
}


/*---------------------------.
| Print this symbol on YYO.  |
`---------------------------*/

static void
yy_symbol_print (FILE *yyo,
                 yysymbol_kind_t yykind, YYSTYPE const * const yyvaluep)
{
  YYFPRINTF (yyo, "%s %s (",
             yykind < YYNTOKENS ? "token" : "nterm", yysymbol_name (yykind));

  yy_symbol_value_print (yyo, yykind, yyvaluep);
  YYFPRINTF (yyo, ")");
}

/*------------------------------------------------------------------.
| yy_stack_print -- Print the state stack from its BOTTOM up to its |
| TOP (included).                                                   |
`------------------------------------------------------------------*/

static void
yy_stack_print (yy_state_t *yybottom, yy_state_t *yytop)
{
  YYFPRINTF (stderr, "Stack now");
  for (; yybottom <= yytop; yybottom++)
    {
      int yybot = *yybottom;
      YYFPRINTF (stderr, " %d", yybot);
    }
  YYFPRINTF (stderr, "\n");
}

# define YY_STACK_PRINT(Bottom, Top)                            \
do {                                                            \
  if (yydebug)                                                  \
    yy_stack_print ((Bottom), (Top));                           \
} while (0)


/*------------------------------------------------.
| Report that the YYRULE is going to be reduced.  |
`------------------------------------------------*/

static void
yy_reduce_print (yy_state_t *yyssp, YYSTYPE *yyvsp,
                 int yyrule)
{
  int yylno = yyrline[yyrule];
  int yynrhs = yyr2[yyrule];
  int yyi;
  YYFPRINTF (stderr, "Reducing stack by rule %d (line %d):\n",
             yyrule - 1, yylno);
  /* The symbols being reduced.  */
  for (yyi = 0; yyi < yynrhs; yyi++)
    {
      YYFPRINTF (stderr, "   $%d = ", yyi + 1);
      yy_symbol_print (stderr,
                       YY_ACCESSING_SYMBOL (+yyssp[yyi + 1 - yynrhs]),
                       &yyvsp[(yyi + 1) - (yynrhs)]);
      YYFPRINTF (stderr, "\n");
    }
}

# define YY_REDUCE_PRINT(Rule)          \
do {                                    \
  if (yydebug)                          \
    yy_reduce_print (yyssp, yyvsp, Rule); \
} while (0)

/* Nonzero means print parse trace.  It is left uninitialized so that
   multiple parsers can coexist.  */
int yydebug;
#else /* !YYDEBUG */
# define YYDPRINTF(Args) ((void) 0)
# define YY_SYMBOL_PRINT(Title, Kind, Value, Location)
# define YY_STACK_PRINT(Bottom, Top)
# define YY_REDUCE_PRINT(Rule)
#endif /* !YYDEBUG */


/* YYINITDEPTH -- initial size of the parser's stacks.  */
#ifndef YYINITDEPTH
# define YYINITDEPTH 200
#endif

/* YYMAXDEPTH -- maximum size the stacks can grow to (effective only
   if the built-in stack extension method is used).

   Do not make this value too large; the results are undefined if
   YYSTACK_ALLOC_MAXIMUM < YYSTACK_BYTES (YYMAXDEPTH)
   evaluated with infinite-precision integer arithmetic.  */

#ifndef YYMAXDEPTH
# define YYMAXDEPTH 10000
#endif






/*-----------------------------------------------.
| Release the memory associated to this symbol.  |
`-----------------------------------------------*/

static void
yydestruct (const char *yymsg,
            yysymbol_kind_t yykind, YYSTYPE *yyvaluep)
{
  YY_USE (yyvaluep);
  if (!yymsg)
    yymsg = "Deleting";
  YY_SYMBOL_PRINT (yymsg, yykind, yyvaluep, yylocationp);

  YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
  YY_USE (yykind);
  YY_IGNORE_MAYBE_UNINITIALIZED_END
}


/* Lookahead token kind.  */
int yychar;

/* The semantic value of the lookahead symbol.  */
YYSTYPE yylval;
/* Number of syntax errors so far.  */
int yynerrs;




/*----------.
| yyparse.  |
`----------*/

int
yyparse (void)
{
    yy_state_fast_t yystate = 0;
    /* Number of tokens to shift before error messages enabled.  */
    int yyerrstatus = 0;

    /* Refer to the stacks through separate pointers, to allow yyoverflow
       to reallocate them elsewhere.  */

    /* Their size.  */
    YYPTRDIFF_T yystacksize = YYINITDEPTH;

    /* The state stack: array, bottom, top.  */
    yy_state_t yyssa[YYINITDEPTH];
    yy_state_t *yyss = yyssa;
    yy_state_t *yyssp = yyss;

    /* The semantic value stack: array, bottom, top.  */
    YYSTYPE yyvsa[YYINITDEPTH];
    YYSTYPE *yyvs = yyvsa;
    YYSTYPE *yyvsp = yyvs;

  int yyn;
  /* The return value of yyparse.  */
  int yyresult;
  /* Lookahead symbol kind.  */
  yysymbol_kind_t yytoken = YYSYMBOL_YYEMPTY;
  /* The variables used to return semantic value and location from the
     action routines.  */
  YYSTYPE yyval;



#define YYPOPSTACK(N)   (yyvsp -= (N), yyssp -= (N))

  /* The number of symbols on the RHS of the reduced rule.
     Keep to zero when no symbol should be popped.  */
  int yylen = 0;

  YYDPRINTF ((stderr, "Starting parse\n"));

  yychar = YYEMPTY; /* Cause a token to be read.  */

  goto yysetstate;


/*------------------------------------------------------------.
| yynewstate -- push a new state, which is found in yystate.  |
`------------------------------------------------------------*/
yynewstate:
  /* In all cases, when you get here, the value and location stacks
     have just been pushed.  So pushing a state here evens the stacks.  */
  yyssp++;


/*--------------------------------------------------------------------.
| yysetstate -- set current state (the top of the stack) to yystate.  |
`--------------------------------------------------------------------*/
yysetstate:
  YYDPRINTF ((stderr, "Entering state %d\n", yystate));
  YY_ASSERT (0 <= yystate && yystate < YYNSTATES);
  YY_IGNORE_USELESS_CAST_BEGIN
  *yyssp = YY_CAST (yy_state_t, yystate);
  YY_IGNORE_USELESS_CAST_END
  YY_STACK_PRINT (yyss, yyssp);

  if (yyss + yystacksize - 1 <= yyssp)
#if !defined yyoverflow && !defined YYSTACK_RELOCATE
    YYNOMEM;
#else
    {
      /* Get the current used size of the three stacks, in elements.  */
      YYPTRDIFF_T yysize = yyssp - yyss + 1;

# if defined yyoverflow
      {
        /* Give user a chance to reallocate the stack.  Use copies of
           these so that the &'s don't force the real ones into
           memory.  */
        yy_state_t *yyss1 = yyss;
        YYSTYPE *yyvs1 = yyvs;

        /* Each stack pointer address is followed by the size of the
           data in use in that stack, in bytes.  This used to be a
           conditional around just the two extra args, but that might
           be undefined if yyoverflow is a macro.  */
        yyoverflow (YY_("memory exhausted"),
                    &yyss1, yysize * YYSIZEOF (*yyssp),
                    &yyvs1, yysize * YYSIZEOF (*yyvsp),
                    &yystacksize);
        yyss = yyss1;
        yyvs = yyvs1;
      }
# else /* defined YYSTACK_RELOCATE */
      /* Extend the stack our own way.  */
      if (YYMAXDEPTH <= yystacksize)
        YYNOMEM;
      yystacksize *= 2;
      if (YYMAXDEPTH < yystacksize)
        yystacksize = YYMAXDEPTH;

      {
        yy_state_t *yyss1 = yyss;
        union yyalloc *yyptr =
          YY_CAST (union yyalloc *,
                   YYSTACK_ALLOC (YY_CAST (YYSIZE_T, YYSTACK_BYTES (yystacksize))));
        if (! yyptr)
          YYNOMEM;
        YYSTACK_RELOCATE (yyss_alloc, yyss);
        YYSTACK_RELOCATE (yyvs_alloc, yyvs);
#  undef YYSTACK_RELOCATE
        if (yyss1 != yyssa)
          YYSTACK_FREE (yyss1);
      }
# endif

      yyssp = yyss + yysize - 1;
      yyvsp = yyvs + yysize - 1;

      YY_IGNORE_USELESS_CAST_BEGIN
      YYDPRINTF ((stderr, "Stack size increased to %ld\n",
                  YY_CAST (long, yystacksize)));
      YY_IGNORE_USELESS_CAST_END

      if (yyss + yystacksize - 1 <= yyssp)
        YYABORT;
    }
#endif /* !defined yyoverflow && !defined YYSTACK_RELOCATE */


  if (yystate == YYFINAL)
    YYACCEPT;

  goto yybackup;


/*-----------.
| yybackup.  |
`-----------*/
yybackup:
  /* Do appropriate processing given the current state.  Read a
     lookahead token if we need one and don't already have one.  */

  /* First try to decide what to do without reference to lookahead token.  */
  yyn = yypact[yystate];
  if (yypact_value_is_default (yyn))
    goto yydefault;

  /* Not known => get a lookahead token if don't already have one.  */

  /* YYCHAR is either empty, or end-of-input, or a valid lookahead.  */
  if (yychar == YYEMPTY)
    {
      YYDPRINTF ((stderr, "Reading a token\n"));
      yychar = yylex ();
    }

  if (yychar <= YYEOF)
    {
      yychar = YYEOF;
      yytoken = YYSYMBOL_YYEOF;
      YYDPRINTF ((stderr, "Now at end of input.\n"));
    }
  else if (yychar == YYerror)
    {
      /* The scanner already issued an error message, process directly
         to error recovery.  But do not keep the error token as
         lookahead, it is too special and may lead us to an endless
         loop in error recovery. */
      yychar = YYUNDEF;
      yytoken = YYSYMBOL_YYerror;
      goto yyerrlab1;
    }
  else
    {
      yytoken = YYTRANSLATE (yychar);
      YY_SYMBOL_PRINT ("Next token is", yytoken, &yylval, &yylloc);
    }

  /* If the proper action on seeing token YYTOKEN is to reduce or to
     detect an error, take that action.  */
  yyn += yytoken;
  if (yyn < 0 || YYLAST < yyn || yycheck[yyn] != yytoken)
    goto yydefault;
  yyn = yytable[yyn];
  if (yyn <= 0)
    {
      if (yytable_value_is_error (yyn))
        goto yyerrlab;
      yyn = -yyn;
      goto yyreduce;
    }

  /* Count tokens shifted since error; after three, turn off error
     status.  */
  if (yyerrstatus)
    yyerrstatus--;

  /* Shift the lookahead token.  */
  YY_SYMBOL_PRINT ("Shifting", yytoken, &yylval, &yylloc);
  yystate = yyn;
  YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
  *++yyvsp = yylval;
  YY_IGNORE_MAYBE_UNINITIALIZED_END

  /* Discard the shifted token.  */
  yychar = YYEMPTY;
  goto yynewstate;


/*-----------------------------------------------------------.
| yydefault -- do the default action for the current state.  |
`-----------------------------------------------------------*/
yydefault:
  yyn = yydefact[yystate];
  if (yyn == 0)
    goto yyerrlab;
  goto yyreduce;


/*-----------------------------.
| yyreduce -- do a reduction.  |
`-----------------------------*/
yyreduce:
  /* yyn is the number of a rule to reduce with.  */
  yylen = yyr2[yyn];

  /* If YYLEN is nonzero, implement the default value of the action:
     '$$ = $1'.

     Otherwise, the following line sets YYVAL to garbage.
     This behavior is undocumented and Bison
     users should not rely upon it.  Assigning to YYVAL
     unconditionally makes the parser a bit smaller, and it avoids a
     GCC warning that YYVAL may be used uninitialized.  */
  yyval = yyvsp[1-yylen];


  YY_REDUCE_PRINT (yyn);
  switch (yyn)
    {
  case 2: /* main: type MAIN '(' ')' '{' S '}'  */
#line 81 "parser.y"
                                  {
        printf("\n// Main function\n");
        printf("main:\n");
        printf("%s", (yyvsp[-1].exp)->code);
        print();
    }
#line 1360 "y.tab.c"
    break;

  case 3: /* S: stmt S  */
#line 93 "parser.y"
           {
        (yyval.exp) = makeExp();
        sprintf((yyval.exp)->code, "%s%s", (yyvsp[-1].exp)->code, (yyvsp[0].exp)->code);
    }
#line 1369 "y.tab.c"
    break;

  case 4: /* S: %empty  */
#line 97 "parser.y"
      { 
        (yyval.exp) = makeExp();
        (yyval.exp)->code[0] = '\0';
    }
#line 1378 "y.tab.c"
    break;

  case 5: /* stmt: type iden SC  */
#line 102 "parser.y"
                    {
        (yyval.exp) = makeExp();
        insert_type((yyvsp[-1].exp), cur_type);
        if(scope == 0) {
            sprintf((yyval.exp)->code, "// Declaration Global: %s %s\n", cur_type, (yyvsp[-1].exp));
            char dec[100];
            sprintf(dec, "%s = %s\n", (yyvsp[-1].exp), "0");
            strcat((yyval.exp)->code, dec);
            insert_value((yyvsp[-1].exp), 0);
        } else {
        sprintf((yyval.exp)->code, "// Declaration: %s %s\n", cur_type, (yyvsp[-1].exp));
        }
        insert_scope((yyvsp[-1].exp), scope);
    }
#line 1397 "y.tab.c"
    break;

  case 6: /* stmt: type iden '=' E SC  */
#line 116 "parser.y"
                         {
        (yyval.exp) = makeExp();
        insert_type((yyvsp[-3].exp), cur_type);
        sprintf((yyval.exp)->code, "%s%s = %s\n", 
            (yyvsp[-1].exp)->code, (yyvsp[-3].exp), (yyvsp[-1].exp)->place);
        insert_value((yyvsp[-3].exp), (yyvsp[-1].exp)->value);
        insert_scope((yyvsp[-3].exp), scope);

    }
#line 1411 "y.tab.c"
    break;

  case 7: /* stmt: iden '=' E SC  */
#line 125 "parser.y"
                    {
        (yyval.exp) = makeExp();
        if(check_type(yytext)) {
            printf("Error in %s at line %d\n", (yyvsp[-3].exp), line);
            (yyval.exp)->code[0] = '\0';
        } else {
            sprintf((yyval.exp)->code, "%s%s = %s\n", 
                (yyvsp[-1].exp)->code, (yyvsp[-3].exp), (yyvsp[-1].exp)->place);
            insert_value((yyvsp[-3].exp), (yyvsp[-1].exp)->value);
        }

    }
#line 1428 "y.tab.c"
    break;

  case 13: /* st: stmt st  */
#line 145 "parser.y"
             {
        (yyval.exp) = makeExp();
        sprintf((yyval.exp)->code, "%s%s", (yyvsp[-1].exp)->code, (yyvsp[0].exp)->code);
    }
#line 1437 "y.tab.c"
    break;

  case 14: /* st: %empty  */
#line 149 "parser.y"
      {
        (yyval.exp) = makeExp();
        (yyval.exp)->code[0] = '\0';
    }
#line 1446 "y.tab.c"
    break;

  case 15: /* if_loop: IF '(' cond ')' '{' st '}' ELSE '{' st '}'  */
#line 154 "parser.y"
                                                     {
        (yyval.exp) = makeExp();
        int else_label = newLabel();
        int end_label = newLabel();
        sprintf((yyval.exp)->code, "%s"           // Condition code
                        "if !(%s) goto L%d\n"  // False branch
                        "%s"                   // True block
                        "goto L%d\n"           // Skip else
                        "L%d:\n"               // Else label
                        "%s"                   // Else block
                        "L%d:\n",              // End label
                (yyvsp[-8].exp)->code, (yyvsp[-8].exp)->place, else_label,
                (yyvsp[-5].exp)->code, 
                end_label,
                else_label,
                (yyvsp[-1].exp)->code,
                end_label);
    }
#line 1469 "y.tab.c"
    break;

  case 16: /* if_loop: IF '(' cond ')' '{' st '}'  */
#line 172 "parser.y"
                                 {
        (yyval.exp) = makeExp();
        int end_label = newLabel();
        sprintf((yyval.exp)->code, "%s"           // Condition code
                        "if !(%s) goto L%d\n"  // False branch
                        "%s"                   // True block
                        "L%d:\n",              // End label
                (yyvsp[-4].exp)->code, (yyvsp[-4].exp)->place, end_label,
                (yyvsp[-1].exp)->code,
                end_label);
    }
#line 1485 "y.tab.c"
    break;

  case 19: /* w: WHILE '(' cond ')' '{' st '}'  */
#line 186 "parser.y"
                                  {
        (yyval.exp) = makeExp();
        int start_label = newLabel();
        int end_label = newLabel();
        sprintf((yyval.exp)->code, "L%d:\n"             // Loop start
                        "%s"                   // Condition
                        "if !(%s) goto L%d\n"  // Exit loop
                        "%s"                   // Loop body
                        "goto L%d\n"           // Loop back
                        "L%d:\n",              // End label
                start_label,
                (yyvsp[-4].exp)->code, (yyvsp[-4].exp)->place, end_label,
                (yyvsp[-1].exp)->code,
                start_label,
                end_label);
    }
#line 1506 "y.tab.c"
    break;

  case 20: /* f: FOR '(' init SC cond SC inc ')' '{' st '}'  */
#line 203 "parser.y"
                                               {
        (yyval.exp) = makeExp();
        int start_label = newLabel();
        int end_label = newLabel();
        int inc_label = newLabel();
        sprintf((yyval.exp)->code, "%s"                 // Initialization
                        "L%d:\n"               // Loop start
                        "%s"                   // Condition
                        "if !(%s) goto L%d\n"  // Exit loop
                        "%s"                   // Loop body
                        "L%d:\n"               // Increment
                        "%s"                   // Increment code
                        "goto L%d\n"           // Loop back
                        "L%d:\n",              // End label
                (yyvsp[-8].exp)->code,
                start_label,
                (yyvsp[-6].exp)->code, (yyvsp[-6].exp)->place, end_label,
                (yyvsp[-1].exp)->code,
                inc_label,
                (yyvsp[-4].exp)->code,
                start_label,
                end_label);
    }
#line 1534 "y.tab.c"
    break;

  case 21: /* init: type iden '=' NUM  */
#line 227 "parser.y"
                         {
        (yyval.exp) = makeExp();
        insert_type((yyvsp[-2].exp), cur_type);
        insert_value((yyvsp[-2].exp), (yyvsp[0].integer));
        sprintf((yyval.exp)->code, "%s = %d\n", (yyvsp[-2].exp), (yyvsp[0].integer));
    }
#line 1545 "y.tab.c"
    break;

  case 22: /* inc: iden IN  */
#line 234 "parser.y"
              {
        (yyval.exp) = makeExp();
        char* temp = newTemp();
        sprintf((yyval.exp)->code, "%s = %s + 1\n%s = %s\n", 
                temp, (yyvsp[-1].exp), (yyvsp[-1].exp), temp);
    }
#line 1556 "y.tab.c"
    break;

  case 23: /* inc: iden DE  */
#line 240 "parser.y"
              {
        (yyval.exp) = makeExp();
        char* temp = newTemp();
        sprintf((yyval.exp)->code, "%s = %s - 1\n%s = %s\n",
                temp, (yyvsp[-1].exp), (yyvsp[-1].exp), temp);
    }
#line 1567 "y.tab.c"
    break;

  case 24: /* cond: iden relat iden  */
#line 247 "parser.y"
                       {
        (yyval.exp) = makeExp();
        (yyval.exp)->place = newTemp();
        sprintf((yyval.exp)->code, "%s = %s %s %s\n",
                (yyval.exp)->place, (yyvsp[-2].exp), (yyvsp[-1].exp)->place, (yyvsp[0].exp));
    }
#line 1578 "y.tab.c"
    break;

  case 25: /* cond: iden relat NUM  */
#line 253 "parser.y"
                     {
        (yyval.exp) = makeExp();
        (yyval.exp)->place = newTemp();
        sprintf((yyval.exp)->code, "%s = %s %s %d\n",
                (yyval.exp)->place, (yyvsp[-2].exp), (yyvsp[-1].exp)->place, (yyvsp[0].integer));
    }
#line 1589 "y.tab.c"
    break;

  case 26: /* relat: GE  */
#line 260 "parser.y"
           { 
        (yyval.exp) = makeExp();
        (yyval.exp)->place = ">=";
    }
#line 1598 "y.tab.c"
    break;

  case 27: /* relat: LE  */
#line 264 "parser.y"
         {
        (yyval.exp) = makeExp();
        (yyval.exp)->place = "<=";
    }
#line 1607 "y.tab.c"
    break;

  case 28: /* relat: L  */
#line 268 "parser.y"
        {
        (yyval.exp) = makeExp();
        (yyval.exp)->place = "<";
    }
#line 1616 "y.tab.c"
    break;

  case 29: /* relat: G  */
#line 272 "parser.y"
        {
        (yyval.exp) = makeExp();
        (yyval.exp)->place = ">";
    }
#line 1625 "y.tab.c"
    break;

  case 30: /* relat: EQ  */
#line 277 "parser.y"
       {
        (yyval.exp) = makeExp();
        (yyval.exp)->place = "==";
    }
#line 1634 "y.tab.c"
    break;

  case 31: /* type: INT  */
#line 283 "parser.y"
           {strcpy(cur_type, "integer");}
#line 1640 "y.tab.c"
    break;

  case 32: /* type: FLOAT_ID  */
#line 284 "parser.y"
                {strcpy(cur_type, "float");}
#line 1646 "y.tab.c"
    break;

  case 33: /* E: E '+' T  */
#line 286 "parser.y"
            {
        (yyval.exp) = makeExp();
        (yyval.exp)->place = newTemp();
        sprintf((yyval.exp)->code, "%s%s%s = %s + %s\n",
                (yyvsp[-2].exp)->code, (yyvsp[0].exp)->code,
                (yyval.exp)->place, (yyvsp[-2].exp)->place, (yyvsp[0].exp)->place);
        (yyval.exp)->value = (yyvsp[-2].exp)->value + (yyvsp[0].exp)->value;
    }
#line 1659 "y.tab.c"
    break;

  case 34: /* E: E '-' T  */
#line 294 "parser.y"
              {
        (yyval.exp) = makeExp();
        (yyval.exp)->place = newTemp();
        sprintf((yyval.exp)->code, "%s%s%s = %s - %s\n",
                (yyvsp[-2].exp)->code, (yyvsp[0].exp)->code,
                (yyval.exp)->place, (yyvsp[-2].exp)->place, (yyvsp[0].exp)->place);
        (yyval.exp)->value = (yyvsp[-2].exp)->value - (yyvsp[0].exp)->value;
    }
#line 1672 "y.tab.c"
    break;

  case 35: /* E: T  */
#line 302 "parser.y"
        {
        (yyval.exp) = (yyvsp[0].exp);
    }
#line 1680 "y.tab.c"
    break;

  case 36: /* T: T '*' F  */
#line 306 "parser.y"
            {
        (yyval.exp) = makeExp();
        (yyval.exp)->place = newTemp();
        sprintf((yyval.exp)->code, "%s%s%s = %s * %s\n",
                (yyvsp[-2].exp)->code, (yyvsp[0].exp)->code,
                (yyval.exp)->place, (yyvsp[-2].exp)->place, (yyvsp[0].exp)->place);
        (yyval.exp)->value = (yyvsp[-2].exp)->value * (yyvsp[0].exp)->value;
    }
#line 1693 "y.tab.c"
    break;

  case 37: /* T: T '/' F  */
#line 314 "parser.y"
              {
        (yyval.exp) = makeExp();
        if((yyvsp[0].exp)->value != 0) {
            (yyval.exp)->place = newTemp();
            sprintf((yyval.exp)->code, "%s%s%s = %s / %s\n",
                    (yyvsp[-2].exp)->code, (yyvsp[0].exp)->code,
                    (yyval.exp)->place, (yyvsp[-2].exp)->place, (yyvsp[0].exp)->place);
            (yyval.exp)->value = (yyvsp[-2].exp)->value / (yyvsp[0].exp)->value;
        } else {
            printf("Division by zero error\n");
            (yyval.exp)->code[0] = '\0';
            (yyval.exp)->place = "INF";
            (yyval.exp)->value = 0;
        }
    }
#line 1713 "y.tab.c"
    break;

  case 38: /* T: F  */
#line 329 "parser.y"
        {
        (yyval.exp) = (yyvsp[0].exp);
    }
#line 1721 "y.tab.c"
    break;

  case 39: /* F: '(' E ')'  */
#line 333 "parser.y"
              {
        (yyval.exp) = (yyvsp[-1].exp);
    }
#line 1729 "y.tab.c"
    break;

  case 40: /* F: NUM  */
#line 336 "parser.y"
          {
        (yyval.exp) = makeExp();
        (yyval.exp)->place = (char*)malloc(20);
        sprintf((yyval.exp)->place, "%d", (yyvsp[0].integer));
        (yyval.exp)->code[0] = '\0';
        (yyval.exp)->value = (yyvsp[0].integer);
        (yyval.exp) = makeExp();
        (yyval.exp)->place = (char*)malloc(20);
        sprintf((yyval.exp)->place, "%d", (yyvsp[0].integer));
        (yyval.exp)->code[0] = '\0';
        (yyval.exp)->value = (yyvsp[0].integer);
    }
#line 1746 "y.tab.c"
    break;

  case 41: /* F: iden  */
#line 348 "parser.y"
           {
        (yyval.exp) = makeExp();
        // printf("iden: %s\n", $1);
        if(check_type((yyvsp[0].exp))) {
            printf("Error in %s at line %d\n", (yyvsp[0].exp), line);
            (yyval.exp)->code[0] = '\0';
            (yyval.exp)->place = "0";
            (yyval.exp)->value = 0;
        } else {
            (yyval.exp)->place = strdup((yyvsp[0].exp));
            (yyval.exp)->code[0] = '\0';
            (yyval.exp)->value = get_value((yyvsp[0].exp));
        }
    }
#line 1765 "y.tab.c"
    break;

  case 42: /* iden: IDENTIFIER  */
#line 364 "parser.y"
                 {
        (yyval.exp) = strdup(current_iden);
        
    }
#line 1774 "y.tab.c"
    break;

  case 43: /* return: RETURN E SC  */
#line 369 "parser.y"
                     {
        (yyval.exp) = makeExp();
        sprintf((yyval.exp)->code, "%sreturn %s\n", (yyvsp[-1].exp)->code, (yyvsp[-1].exp)->place);
    }
#line 1783 "y.tab.c"
    break;

  case 44: /* printf: PRINTF '(' args ')' SC  */
#line 374 "parser.y"
                                {
        (yyval.exp) = makeExp();
        sprintf((yyval.exp)->code, "%s call printf, %d\n",(yyvsp[-2].exp)->code, (int) (yyvsp[-2].exp)->value);
    }
#line 1792 "y.tab.c"
    break;

  case 45: /* scanf: SCANF '(' args ')' SC  */
#line 379 "parser.y"
                             {
        (yyval.exp) = makeExp();
        sprintf((yyval.exp)->code, "%s call scanf, %l\n",(yyvsp[-2].exp)->code,(int) (yyvsp[-2].exp)->value);
    }
#line 1801 "y.tab.c"
    break;

  case 46: /* args: args ',' args  */
#line 384 "parser.y"
                     {
        (yyval.exp) = makeExp();
        (yyval.exp)->value = (yyvsp[-2].exp)->value + (yyvsp[0].exp)->value;
        sprintf((yyval.exp)->code, "%s%s", (yyvsp[-2].exp)->code, (yyvsp[0].exp)->code);
    }
#line 1811 "y.tab.c"
    break;

  case 47: /* args: STRING  */
#line 389 "parser.y"
             {
        (yyval.exp) = makeExp();
        (yyval.exp)->value = 1;
        sprintf((yyval.exp)->code,"putparam %s\n", (yyvsp[0].str));
    }
#line 1821 "y.tab.c"
    break;

  case 48: /* args: iden  */
#line 394 "parser.y"
           {
        (yyval.exp) = makeExp();
        (yyval.exp)->value = 1;
        sprintf((yyval.exp)->code,"putparam %s\n", (yyvsp[0].exp));
    }
#line 1831 "y.tab.c"
    break;


#line 1835 "y.tab.c"

      default: break;
    }
  /* User semantic actions sometimes alter yychar, and that requires
     that yytoken be updated with the new translation.  We take the
     approach of translating immediately before every use of yytoken.
     One alternative is translating here after every semantic action,
     but that translation would be missed if the semantic action invokes
     YYABORT, YYACCEPT, or YYERROR immediately after altering yychar or
     if it invokes YYBACKUP.  In the case of YYABORT or YYACCEPT, an
     incorrect destructor might then be invoked immediately.  In the
     case of YYERROR or YYBACKUP, subsequent parser actions might lead
     to an incorrect destructor call or verbose syntax error message
     before the lookahead is translated.  */
  YY_SYMBOL_PRINT ("-> $$ =", YY_CAST (yysymbol_kind_t, yyr1[yyn]), &yyval, &yyloc);

  YYPOPSTACK (yylen);
  yylen = 0;

  *++yyvsp = yyval;

  /* Now 'shift' the result of the reduction.  Determine what state
     that goes to, based on the state we popped back to and the rule
     number reduced by.  */
  {
    const int yylhs = yyr1[yyn] - YYNTOKENS;
    const int yyi = yypgoto[yylhs] + *yyssp;
    yystate = (0 <= yyi && yyi <= YYLAST && yycheck[yyi] == *yyssp
               ? yytable[yyi]
               : yydefgoto[yylhs]);
  }

  goto yynewstate;


/*--------------------------------------.
| yyerrlab -- here on detecting error.  |
`--------------------------------------*/
yyerrlab:
  /* Make sure we have latest lookahead translation.  See comments at
     user semantic actions for why this is necessary.  */
  yytoken = yychar == YYEMPTY ? YYSYMBOL_YYEMPTY : YYTRANSLATE (yychar);
  /* If not already recovering from an error, report this error.  */
  if (!yyerrstatus)
    {
      ++yynerrs;
      yyerror (YY_("syntax error"));
    }

  if (yyerrstatus == 3)
    {
      /* If just tried and failed to reuse lookahead token after an
         error, discard it.  */

      if (yychar <= YYEOF)
        {
          /* Return failure if at end of input.  */
          if (yychar == YYEOF)
            YYABORT;
        }
      else
        {
          yydestruct ("Error: discarding",
                      yytoken, &yylval);
          yychar = YYEMPTY;
        }
    }

  /* Else will try to reuse lookahead token after shifting the error
     token.  */
  goto yyerrlab1;


/*---------------------------------------------------.
| yyerrorlab -- error raised explicitly by YYERROR.  |
`---------------------------------------------------*/
yyerrorlab:
  /* Pacify compilers when the user code never invokes YYERROR and the
     label yyerrorlab therefore never appears in user code.  */
  if (0)
    YYERROR;
  ++yynerrs;

  /* Do not reclaim the symbols of the rule whose action triggered
     this YYERROR.  */
  YYPOPSTACK (yylen);
  yylen = 0;
  YY_STACK_PRINT (yyss, yyssp);
  yystate = *yyssp;
  goto yyerrlab1;


/*-------------------------------------------------------------.
| yyerrlab1 -- common code for both syntax error and YYERROR.  |
`-------------------------------------------------------------*/
yyerrlab1:
  yyerrstatus = 3;      /* Each real token shifted decrements this.  */

  /* Pop stack until we find a state that shifts the error token.  */
  for (;;)
    {
      yyn = yypact[yystate];
      if (!yypact_value_is_default (yyn))
        {
          yyn += YYSYMBOL_YYerror;
          if (0 <= yyn && yyn <= YYLAST && yycheck[yyn] == YYSYMBOL_YYerror)
            {
              yyn = yytable[yyn];
              if (0 < yyn)
                break;
            }
        }

      /* Pop the current state because it cannot handle the error token.  */
      if (yyssp == yyss)
        YYABORT;


      yydestruct ("Error: popping",
                  YY_ACCESSING_SYMBOL (yystate), yyvsp);
      YYPOPSTACK (1);
      yystate = *yyssp;
      YY_STACK_PRINT (yyss, yyssp);
    }

  YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
  *++yyvsp = yylval;
  YY_IGNORE_MAYBE_UNINITIALIZED_END


  /* Shift the error token.  */
  YY_SYMBOL_PRINT ("Shifting", YY_ACCESSING_SYMBOL (yyn), yyvsp, yylsp);

  yystate = yyn;
  goto yynewstate;


/*-------------------------------------.
| yyacceptlab -- YYACCEPT comes here.  |
`-------------------------------------*/
yyacceptlab:
  yyresult = 0;
  goto yyreturnlab;


/*-----------------------------------.
| yyabortlab -- YYABORT comes here.  |
`-----------------------------------*/
yyabortlab:
  yyresult = 1;
  goto yyreturnlab;


/*-----------------------------------------------------------.
| yyexhaustedlab -- YYNOMEM (memory exhaustion) comes here.  |
`-----------------------------------------------------------*/
yyexhaustedlab:
  yyerror (YY_("memory exhausted"));
  yyresult = 2;
  goto yyreturnlab;


/*----------------------------------------------------------.
| yyreturnlab -- parsing is finished, clean up and return.  |
`----------------------------------------------------------*/
yyreturnlab:
  if (yychar != YYEMPTY)
    {
      /* Make sure we have latest lookahead translation.  See comments at
         user semantic actions for why this is necessary.  */
      yytoken = YYTRANSLATE (yychar);
      yydestruct ("Cleanup: discarding lookahead",
                  yytoken, &yylval);
    }
  /* Do not reclaim the symbols of the rule whose action triggered
     this YYABORT or YYACCEPT.  */
  YYPOPSTACK (yylen);
  YY_STACK_PRINT (yyss, yyssp);
  while (yyssp != yyss)
    {
      yydestruct ("Cleanup: popping",
                  YY_ACCESSING_SYMBOL (+*yyssp), yyvsp);
      YYPOPSTACK (1);
    }
#ifndef yyoverflow
  if (yyss != yyssa)
    YYSTACK_FREE (yyss);
#endif

  return yyresult;
}

#line 402 "parser.y"


void yyerror(char*s) {
    printf("Error: %s at line %d\n", s, line);
}

int main() {
    printf("Starting compilation...\n");
    yyparse();
    return 0;
}
