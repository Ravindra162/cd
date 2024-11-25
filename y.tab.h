/* A Bison parser, made by GNU Bison 3.8.2.  */

/* Bison interface for Yacc-like parsers in C

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

/* DO NOT RELY ON FEATURES THAT ARE NOT DOCUMENTED in the manual,
   especially those whose name start with YY_ or yy_.  They are
   private implementation details that can be changed or removed.  */

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

#line 128 "y.tab.h"

};
typedef union YYSTYPE YYSTYPE;
# define YYSTYPE_IS_TRIVIAL 1
# define YYSTYPE_IS_DECLARED 1
#endif


extern YYSTYPE yylval;


int yyparse (void);


#endif /* !YY_YY_Y_TAB_H_INCLUDED  */
