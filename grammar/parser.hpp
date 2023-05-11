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

#ifndef YY_YY_GRAMMAR_PARSER_HPP_INCLUDED
# define YY_YY_GRAMMAR_PARSER_HPP_INCLUDED
/* Debug traces.  */
#ifndef YYDEBUG
# define YYDEBUG 0
#endif
#if YYDEBUG
extern int yydebug;
#endif
/* "%code requires" blocks.  */
#line 19 "grammar/parser.y"

    #include "../common/node.hpp"

#line 53 "grammar/parser.hpp"

/* Token kinds.  */
#ifndef YYTOKENTYPE
# define YYTOKENTYPE
  enum yytokentype
  {
    YYEMPTY = -2,
    YYEOF = 0,                     /* "end of file"  */
    YYerror = 256,                 /* error  */
    YYUNDEF = 257,                 /* "invalid token"  */
    VAR = 258,                     /* VAR  */
    IS = 259,                      /* IS  */
    ROUTINE = 260,                 /* ROUTINE  */
    END = 261,                     /* END  */
    IDENTIFIER = 262,              /* IDENTIFIER  */
    TYPE = 263,                    /* TYPE  */
    INTEGER = 264,                 /* INTEGER  */
    REAL = 265,                    /* REAL  */
    BOOLEAN = 266,                 /* BOOLEAN  */
    RECORD = 267,                  /* RECORD  */
    ARRAY = 268,                   /* ARRAY  */
    ASSIGNMENT_SIGN = 269,         /* ASSIGNMENT_SIGN  */
    RANGE_SIGN = 270,              /* RANGE_SIGN  */
    WHILE = 271,                   /* WHILE  */
    LOOP = 272,                    /* LOOP  */
    FOR = 273,                     /* FOR  */
    REVERSE = 274,                 /* REVERSE  */
    IN = 275,                      /* IN  */
    IF = 276,                      /* IF  */
    THEN = 277,                    /* THEN  */
    ELSE = 278,                    /* ELSE  */
    AND = 279,                     /* AND  */
    OR = 280,                      /* OR  */
    XOR = 281,                     /* XOR  */
    NOT = 282,                     /* NOT  */
    LT_SIGN = 283,                 /* LT_SIGN  */
    LET_SIGN = 284,                /* LET_SIGN  */
    GT_SIGN = 285,                 /* GT_SIGN  */
    GET_SIGN = 286,                /* GET_SIGN  */
    EQ_SIGN = 287,                 /* EQ_SIGN  */
    NEQ_SIGN = 288,                /* NEQ_SIGN  */
    MULT_SIGN = 289,               /* MULT_SIGN  */
    DIV_SIGN = 290,                /* DIV_SIGN  */
    MOD_SIGN = 291,                /* MOD_SIGN  */
    PLUS_SIGN = 292,               /* PLUS_SIGN  */
    MINUS_SIGN = 293,              /* MINUS_SIGN  */
    TRUE = 294,                    /* TRUE  */
    FALSE = 295,                   /* FALSE  */
    REAL_LITERAL = 296,            /* REAL_LITERAL  */
    INTEGER_LITERAL = 297,         /* INTEGER_LITERAL  */
    RETURN = 298,                  /* RETURN  */
    L_SQ_BR = 299,                 /* L_SQ_BR  */
    R_SQ_BR = 300,                 /* R_SQ_BR  */
    L_BR = 301,                    /* L_BR  */
    R_BR = 302,                    /* R_BR  */
    COLON = 303,                   /* COLON  */
    DOT = 304,                     /* DOT  */
    COMMA = 305,                   /* COMMA  */
    SEMICOLON = 306,               /* SEMICOLON  */
    INVALID_CHARACTER = 307        /* INVALID_CHARACTER  */
  };
  typedef enum yytokentype yytoken_kind_t;
#endif

/* Value type.  */
#if ! defined YYSTYPE && ! defined YYSTYPE_IS_DECLARED
union YYSTYPE
{
#line 23 "grammar/parser.y"

    Node* node;
    char* value;

#line 127 "grammar/parser.hpp"

};
typedef union YYSTYPE YYSTYPE;
# define YYSTYPE_IS_TRIVIAL 1
# define YYSTYPE_IS_DECLARED 1
#endif


extern YYSTYPE yylval;


int yyparse (void **root);


#endif /* !YY_YY_GRAMMAR_PARSER_HPP_INCLUDED  */
