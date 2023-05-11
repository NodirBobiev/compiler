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
#line 3 "grammar/parser.y"

#include <stdio.h>
#include <iostream>
#include <string>
#include <stdarg.h>
#include "lexer.hpp"
#include "../common/node.hpp"



void yyerror(void ** root, const char* msg, ...) {
    std::cerr << "Syntax error at line " << yylineno << ": " << msg << std::endl;
}


#line 87 "grammar/parser.cpp"

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

#include "parser.hpp"
/* Symbol kind.  */
enum yysymbol_kind_t
{
  YYSYMBOL_YYEMPTY = -2,
  YYSYMBOL_YYEOF = 0,                      /* "end of file"  */
  YYSYMBOL_YYerror = 1,                    /* error  */
  YYSYMBOL_YYUNDEF = 2,                    /* "invalid token"  */
  YYSYMBOL_VAR = 3,                        /* VAR  */
  YYSYMBOL_IS = 4,                         /* IS  */
  YYSYMBOL_ROUTINE = 5,                    /* ROUTINE  */
  YYSYMBOL_END = 6,                        /* END  */
  YYSYMBOL_IDENTIFIER = 7,                 /* IDENTIFIER  */
  YYSYMBOL_TYPE = 8,                       /* TYPE  */
  YYSYMBOL_INTEGER = 9,                    /* INTEGER  */
  YYSYMBOL_REAL = 10,                      /* REAL  */
  YYSYMBOL_BOOLEAN = 11,                   /* BOOLEAN  */
  YYSYMBOL_RECORD = 12,                    /* RECORD  */
  YYSYMBOL_ARRAY = 13,                     /* ARRAY  */
  YYSYMBOL_ASSIGNMENT_SIGN = 14,           /* ASSIGNMENT_SIGN  */
  YYSYMBOL_RANGE_SIGN = 15,                /* RANGE_SIGN  */
  YYSYMBOL_WHILE = 16,                     /* WHILE  */
  YYSYMBOL_LOOP = 17,                      /* LOOP  */
  YYSYMBOL_FOR = 18,                       /* FOR  */
  YYSYMBOL_REVERSE = 19,                   /* REVERSE  */
  YYSYMBOL_IN = 20,                        /* IN  */
  YYSYMBOL_IF = 21,                        /* IF  */
  YYSYMBOL_THEN = 22,                      /* THEN  */
  YYSYMBOL_ELSE = 23,                      /* ELSE  */
  YYSYMBOL_AND = 24,                       /* AND  */
  YYSYMBOL_OR = 25,                        /* OR  */
  YYSYMBOL_XOR = 26,                       /* XOR  */
  YYSYMBOL_NOT = 27,                       /* NOT  */
  YYSYMBOL_LT_SIGN = 28,                   /* LT_SIGN  */
  YYSYMBOL_LET_SIGN = 29,                  /* LET_SIGN  */
  YYSYMBOL_GT_SIGN = 30,                   /* GT_SIGN  */
  YYSYMBOL_GET_SIGN = 31,                  /* GET_SIGN  */
  YYSYMBOL_EQ_SIGN = 32,                   /* EQ_SIGN  */
  YYSYMBOL_NEQ_SIGN = 33,                  /* NEQ_SIGN  */
  YYSYMBOL_MULT_SIGN = 34,                 /* MULT_SIGN  */
  YYSYMBOL_DIV_SIGN = 35,                  /* DIV_SIGN  */
  YYSYMBOL_MOD_SIGN = 36,                  /* MOD_SIGN  */
  YYSYMBOL_PLUS_SIGN = 37,                 /* PLUS_SIGN  */
  YYSYMBOL_MINUS_SIGN = 38,                /* MINUS_SIGN  */
  YYSYMBOL_TRUE = 39,                      /* TRUE  */
  YYSYMBOL_FALSE = 40,                     /* FALSE  */
  YYSYMBOL_REAL_LITERAL = 41,              /* REAL_LITERAL  */
  YYSYMBOL_INTEGER_LITERAL = 42,           /* INTEGER_LITERAL  */
  YYSYMBOL_RETURN = 43,                    /* RETURN  */
  YYSYMBOL_L_SQ_BR = 44,                   /* L_SQ_BR  */
  YYSYMBOL_R_SQ_BR = 45,                   /* R_SQ_BR  */
  YYSYMBOL_L_BR = 46,                      /* L_BR  */
  YYSYMBOL_R_BR = 47,                      /* R_BR  */
  YYSYMBOL_COLON = 48,                     /* COLON  */
  YYSYMBOL_DOT = 49,                       /* DOT  */
  YYSYMBOL_COMMA = 50,                     /* COMMA  */
  YYSYMBOL_SEMICOLON = 51,                 /* SEMICOLON  */
  YYSYMBOL_INVALID_CHARACTER = 52,         /* INVALID_CHARACTER  */
  YYSYMBOL_YYACCEPT = 53,                  /* $accept  */
  YYSYMBOL_program = 54,                   /* program  */
  YYSYMBOL_simple_declaration = 55,        /* simple_declaration  */
  YYSYMBOL_variable_declaration = 56,      /* variable_declaration  */
  YYSYMBOL_variable_expression = 57,       /* variable_expression  */
  YYSYMBOL_type_declaration = 58,          /* type_declaration  */
  YYSYMBOL_routine_declaration = 59,       /* routine_declaration  */
  YYSYMBOL_routine_return_type = 60,       /* routine_return_type  */
  YYSYMBOL_routine_parameters = 61,        /* routine_parameters  */
  YYSYMBOL_parameters = 62,                /* parameters  */
  YYSYMBOL_parameter_declaration = 63,     /* parameter_declaration  */
  YYSYMBOL_type = 64,                      /* type  */
  YYSYMBOL_primitive_type = 65,            /* primitive_type  */
  YYSYMBOL_record_type = 66,               /* record_type  */
  YYSYMBOL_variables_declaration = 67,     /* variables_declaration  */
  YYSYMBOL_array_type = 68,                /* array_type  */
  YYSYMBOL_body = 69,                      /* body  */
  YYSYMBOL_statement = 70,                 /* statement  */
  YYSYMBOL_return = 71,                    /* return  */
  YYSYMBOL_assignment = 72,                /* assignment  */
  YYSYMBOL_routine_call = 73,              /* routine_call  */
  YYSYMBOL_arguments = 74,                 /* arguments  */
  YYSYMBOL_expressions = 75,               /* expressions  */
  YYSYMBOL_while_loop = 76,                /* while_loop  */
  YYSYMBOL_for_loop = 77,                  /* for_loop  */
  YYSYMBOL_range = 78,                     /* range  */
  YYSYMBOL_reverse = 79,                   /* reverse  */
  YYSYMBOL_if_statement = 80,              /* if_statement  */
  YYSYMBOL_else_body = 81,                 /* else_body  */
  YYSYMBOL_expression = 82,                /* expression  */
  YYSYMBOL_logic_operation = 83,           /* logic_operation  */
  YYSYMBOL_relation = 84,                  /* relation  */
  YYSYMBOL_compare_sign = 85,              /* compare_sign  */
  YYSYMBOL_simple = 86,                    /* simple  */
  YYSYMBOL_mult_sign_f = 87,               /* mult_sign_f  */
  YYSYMBOL_factor = 88,                    /* factor  */
  YYSYMBOL_mult_sign_s = 89,               /* mult_sign_s  */
  YYSYMBOL_summand = 90,                   /* summand  */
  YYSYMBOL_primary = 91,                   /* primary  */
  YYSYMBOL_modifiable_primary = 92,        /* modifiable_primary  */
  YYSYMBOL_identifier = 93                 /* identifier  */
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
typedef yytype_uint8 yy_state_t;

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

#if 1

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
#endif /* 1 */

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
#define YYFINAL  2
/* YYLAST -- Last index in YYTABLE.  */
#define YYLAST   203

/* YYNTOKENS -- Number of terminals.  */
#define YYNTOKENS  53
/* YYNNTS -- Number of nonterminals.  */
#define YYNNTS  41
/* YYNRULES -- Number of rules.  */
#define YYNRULES  91
/* YYNSTATES -- Number of states.  */
#define YYNSTATES  147

/* YYMAXUTOK -- Last valid token kind.  */
#define YYMAXUTOK   307


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
      25,    26,    27,    28,    29,    30,    31,    32,    33,    34,
      35,    36,    37,    38,    39,    40,    41,    42,    43,    44,
      45,    46,    47,    48,    49,    50,    51,    52
};

#if YYDEBUG
/* YYRLINE[YYN] -- Source line where rule number YYN was defined.  */
static const yytype_int16 yyrline[] =
{
       0,    62,    62,    63,    64,    68,    69,    73,    74,    78,
      79,    83,    87,    91,    92,    96,    97,   101,   102,   107,
     111,   112,   113,   114,   118,   119,   120,   124,   128,   129,
     133,   137,   138,   139,   143,   144,   145,   146,   147,   148,
     152,   153,   158,   162,   166,   167,   171,   172,   176,   180,
     184,   189,   190,   194,   198,   199,   203,   204,   208,   209,
     210,   214,   215,   219,   220,   221,   222,   223,   224,   228,
     229,   233,   234,   235,   239,   240,   241,   242,   246,   247,
     251,   252,   257,   258,   259,   260,   261,   262,   266,   267,
     268,   273
};
#endif

/** Accessing symbol of state STATE.  */
#define YY_ACCESSING_SYMBOL(State) YY_CAST (yysymbol_kind_t, yystos[State])

#if 1
/* The user-facing name of the symbol whose (internal) number is
   YYSYMBOL.  No bounds checking.  */
static const char *yysymbol_name (yysymbol_kind_t yysymbol) YY_ATTRIBUTE_UNUSED;

/* YYTNAME[SYMBOL-NUM] -- String name of the symbol SYMBOL-NUM.
   First, the terminals, then, starting at YYNTOKENS, nonterminals.  */
static const char *const yytname[] =
{
  "\"end of file\"", "error", "\"invalid token\"", "VAR", "IS", "ROUTINE",
  "END", "IDENTIFIER", "TYPE", "INTEGER", "REAL", "BOOLEAN", "RECORD",
  "ARRAY", "ASSIGNMENT_SIGN", "RANGE_SIGN", "WHILE", "LOOP", "FOR",
  "REVERSE", "IN", "IF", "THEN", "ELSE", "AND", "OR", "XOR", "NOT",
  "LT_SIGN", "LET_SIGN", "GT_SIGN", "GET_SIGN", "EQ_SIGN", "NEQ_SIGN",
  "MULT_SIGN", "DIV_SIGN", "MOD_SIGN", "PLUS_SIGN", "MINUS_SIGN", "TRUE",
  "FALSE", "REAL_LITERAL", "INTEGER_LITERAL", "RETURN", "L_SQ_BR",
  "R_SQ_BR", "L_BR", "R_BR", "COLON", "DOT", "COMMA", "SEMICOLON",
  "INVALID_CHARACTER", "$accept", "program", "simple_declaration",
  "variable_declaration", "variable_expression", "type_declaration",
  "routine_declaration", "routine_return_type", "routine_parameters",
  "parameters", "parameter_declaration", "type", "primitive_type",
  "record_type", "variables_declaration", "array_type", "body",
  "statement", "return", "assignment", "routine_call", "arguments",
  "expressions", "while_loop", "for_loop", "range", "reverse",
  "if_statement", "else_body", "expression", "logic_operation", "relation",
  "compare_sign", "simple", "mult_sign_f", "factor", "mult_sign_s",
  "summand", "primary", "modifiable_primary", "identifier", YY_NULLPTR
};

static const char *
yysymbol_name (yysymbol_kind_t yysymbol)
{
  return yytname[yysymbol];
}
#endif

#define YYPACT_NINF (-88)

#define yypact_value_is_default(Yyn) \
  ((Yyn) == YYPACT_NINF)

#define YYTABLE_NINF (-1)

#define yytable_value_is_error(Yyn) \
  0

/* YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
   STATE-NUM.  */
static const yytype_int16 yypact[] =
{
     -88,   183,   -88,     5,     5,     5,   -88,   -88,   -88,   -88,
     -88,     4,   -26,    22,   105,   185,     5,   185,   118,   -88,
     -88,   -88,   -88,   -88,   -88,   105,   -88,   128,   -88,   146,
      62,   118,   -88,   -88,   -35,   -21,   -88,   -88,   -88,   -88,
     -14,    28,   -88,   -88,   -88,   -88,   -13,   -15,   -88,    -4,
     -88,   -88,    35,   -88,   -88,   -88,   105,   -88,   -88,   -88,
     -88,   -88,   -88,   -88,   -88,   -88,   105,   105,   118,   -88,
     105,     5,   105,     7,   105,   105,   -88,     3,     5,   185,
     -88,   -88,   136,    62,   -88,    79,   -35,   -88,     8,    12,
     128,   -88,   -88,   124,   128,   185,    53,   -88,   -88,   -88,
     -88,   105,   185,   -88,   -88,   128,   -88,    15,   -88,   105,
       5,   105,   105,   -88,   -88,   -88,   -88,   -88,   -88,   -88,
     -88,    -3,    48,    46,   177,   128,   105,   -88,    49,    60,
     -88,   128,    21,   -88,   105,   -88,    90,   -88,    65,   113,
     -88,    75,   105,   -88,   119,   -88,   128
};

/* YYDEFACT[STATE-NUM] -- Default reduction number in state STATE-NUM.
   Performed when YYTABLE does not specify something else to do.  Zero
   means the default is an error.  */
static const yytype_int8 yydefact[] =
{
       2,     0,     1,     0,     0,     0,     3,     5,     6,     4,
      91,     0,     0,     0,     0,     0,    15,     0,     0,    78,
      79,    82,    83,    84,    85,     0,    87,     8,    57,    61,
      70,     0,    75,    80,    86,    88,    24,    25,    26,    28,
       0,     9,    20,    22,    21,    23,     0,    16,    18,     0,
      11,    77,     0,    58,    59,    60,     0,    63,    64,    65,
      66,    67,    68,    71,    72,    73,     0,     0,     0,    76,
       0,     0,    44,     0,     0,     0,     7,    13,     0,     0,
      81,    56,    62,    69,    74,     0,    90,    88,     0,    45,
      47,    27,    29,     0,    10,     0,     0,    17,    19,    89,
      43,     0,     0,    14,    31,    46,    30,     0,    12,     0,
       0,     0,    41,    32,    33,    39,    34,    35,    36,    37,
      38,     0,     0,     0,     0,    40,     0,    31,    51,     0,
      31,    42,     0,    52,     0,    31,    54,    48,     0,     0,
      31,     0,     0,    49,    55,    53,    50
};

/* YYPGOTO[NTERM-NUM].  */
static const yytype_int8 yypgoto[] =
{
     -88,   -88,    82,    23,   -88,   -88,   -88,   -88,   -88,   -88,
      10,   -10,   -88,   -88,   -88,   -88,   -87,   -88,   -88,   -88,
      29,   -88,   -88,   -88,   -88,   -88,   -88,   -88,   -88,   -25,
     -88,    38,   -88,    41,   -88,    47,   -29,   -12,   -88,   -69,
       0
};

/* YYDEFGOTO[NTERM-NUM].  */
static const yytype_uint8 yydefgoto[] =
{
       0,     1,   113,     7,    76,     8,     9,    96,    46,    47,
      48,    41,    42,    43,    73,    44,   107,   114,   115,   116,
      26,    88,    89,   118,   119,   129,   134,   120,   141,    27,
      56,    28,    66,    29,    67,    30,    31,    32,    33,    34,
      35
};

/* YYTABLE[YYPACT[STATE-NUM]] -- What to do in state STATE-NUM.  If
   positive, shift that token.  If negative, reduce the rule whose
   number is the opposite.  If YYTABLE_NINF, syntax error.  */
static const yytype_uint8 yytable[] =
{
      52,    68,    86,    11,    12,    13,    51,    50,    14,    70,
       3,   126,    10,    91,    71,    45,    49,    45,     3,    69,
      16,   108,    10,     5,     3,    72,    17,   137,    10,     5,
      74,   109,    75,   110,    77,    78,   111,   109,   121,   110,
     132,    70,   111,   136,    79,    85,    71,    90,   139,    93,
      94,    95,    15,   144,    68,   100,    84,   104,   112,    53,
      54,    55,   101,   121,   112,   127,   128,   121,   133,    98,
     121,    87,    53,    54,    55,   121,   105,   135,    49,    45,
     142,   145,    80,     6,   122,   103,   124,   125,    97,    53,
      54,    55,   106,     3,    81,    45,    92,    10,     5,    19,
      20,   131,    45,    53,    54,    55,   109,    82,   110,   138,
     123,   111,    10,   140,    83,     0,     3,   146,     0,   143,
      10,     5,     3,     0,    99,    10,    10,     5,     0,   109,
       0,   110,    18,   112,   111,   109,   117,   110,     0,     0,
     111,     0,    19,    20,    21,    22,    23,    24,    53,    54,
      55,    25,    53,    54,    55,     0,   112,    21,    22,    23,
      24,   117,   112,     0,    25,   117,     0,     0,   117,   102,
      63,    64,    65,   117,    57,    58,    59,    60,    61,    62,
      63,    64,    65,     2,     0,     0,     3,     0,     4,     0,
       0,     5,    10,     0,    36,    37,    38,    39,    40,   130,
       0,    53,    54,    55
};

static const yytype_int16 yycheck[] =
{
      25,    30,    71,     3,     4,     5,    18,    17,     4,    44,
       3,    14,     7,     6,    49,    15,    16,    17,     3,    31,
      46,     6,     7,     8,     3,    46,     4,     6,     7,     8,
      44,    16,     4,    18,    47,    50,    21,    16,   107,    18,
     127,    44,    21,   130,    48,    70,    49,    72,   135,    74,
      75,    48,    48,   140,    83,    47,    68,     4,    43,    24,
      25,    26,    50,   132,    43,    17,    20,   136,    19,    79,
     139,    71,    24,    25,    26,   144,   101,    17,    78,    79,
      15,     6,    47,     1,   109,    95,   111,   112,    78,    24,
      25,    26,   102,     3,    56,    95,    73,     7,     8,    37,
      38,   126,   102,    24,    25,    26,    16,    66,    18,   134,
     110,    21,     7,    23,    67,    -1,     3,   142,    -1,     6,
       7,     8,     3,    -1,    45,     7,     7,     8,    -1,    16,
      -1,    18,    27,    43,    21,    16,   107,    18,    -1,    -1,
      21,    -1,    37,    38,    39,    40,    41,    42,    24,    25,
      26,    46,    24,    25,    26,    -1,    43,    39,    40,    41,
      42,   132,    43,    -1,    46,   136,    -1,    -1,   139,    45,
      34,    35,    36,   144,    28,    29,    30,    31,    32,    33,
      34,    35,    36,     0,    -1,    -1,     3,    -1,     5,    -1,
      -1,     8,     7,    -1,     9,    10,    11,    12,    13,    22,
      -1,    24,    25,    26
};

/* YYSTOS[STATE-NUM] -- The symbol kind of the accessing symbol of
   state STATE-NUM.  */
static const yytype_int8 yystos[] =
{
       0,    54,     0,     3,     5,     8,    55,    56,    58,    59,
       7,    93,    93,    93,     4,    48,    46,     4,    27,    37,
      38,    39,    40,    41,    42,    46,    73,    82,    84,    86,
      88,    89,    90,    91,    92,    93,     9,    10,    11,    12,
      13,    64,    65,    66,    68,    93,    61,    62,    63,    93,
      64,    90,    82,    24,    25,    26,    83,    28,    29,    30,
      31,    32,    33,    34,    35,    36,    85,    87,    89,    90,
      44,    49,    46,    67,    44,     4,    57,    47,    50,    48,
      47,    84,    86,    88,    90,    82,    92,    93,    74,    75,
      82,     6,    56,    82,    82,    48,    60,    63,    64,    45,
      47,    50,    45,    64,     4,    82,    64,    69,     6,    16,
      18,    21,    43,    55,    70,    71,    72,    73,    76,    77,
      80,    92,    82,    93,    82,    82,    14,    17,    20,    78,
      22,    82,    69,    19,    79,    17,    69,     6,    82,    69,
      23,    81,    15,     6,    69,     6,    82
};

/* YYR1[RULE-NUM] -- Symbol kind of the left-hand side of rule RULE-NUM.  */
static const yytype_int8 yyr1[] =
{
       0,    53,    54,    54,    54,    55,    55,    56,    56,    57,
      57,    58,    59,    60,    60,    61,    61,    62,    62,    63,
      64,    64,    64,    64,    65,    65,    65,    66,    67,    67,
      68,    69,    69,    69,    70,    70,    70,    70,    70,    70,
      71,    71,    72,    73,    74,    74,    75,    75,    76,    77,
      78,    79,    79,    80,    81,    81,    82,    82,    83,    83,
      83,    84,    84,    85,    85,    85,    85,    85,    85,    86,
      86,    87,    87,    87,    88,    88,    88,    88,    89,    89,
      90,    90,    91,    91,    91,    91,    91,    91,    92,    92,
      92,    93
};

/* YYR2[RULE-NUM] -- Number of symbols on the right-hand side of rule RULE-NUM.  */
static const yytype_int8 yyr2[] =
{
       0,     2,     0,     2,     2,     1,     1,     5,     4,     0,
       2,     4,     9,     0,     2,     0,     1,     3,     1,     3,
       1,     1,     1,     1,     1,     1,     1,     3,     0,     2,
       5,     0,     2,     2,     1,     1,     1,     1,     1,     1,
       2,     1,     3,     4,     0,     1,     3,     1,     5,     6,
       5,     0,     1,     6,     0,     2,     3,     1,     1,     1,
       1,     1,     3,     1,     1,     1,     1,     1,     1,     3,
       1,     1,     1,     1,     3,     1,     2,     2,     1,     1,
       1,     3,     1,     1,     1,     1,     1,     1,     1,     4,
       3,     1
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
        yyerror (root, YY_("syntax error: cannot back up")); \
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
                  Kind, Value, root); \
      YYFPRINTF (stderr, "\n");                                           \
    }                                                                     \
} while (0)


/*-----------------------------------.
| Print this symbol's value on YYO.  |
`-----------------------------------*/

static void
yy_symbol_value_print (FILE *yyo,
                       yysymbol_kind_t yykind, YYSTYPE const * const yyvaluep, void **root)
{
  FILE *yyoutput = yyo;
  YY_USE (yyoutput);
  YY_USE (root);
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
                 yysymbol_kind_t yykind, YYSTYPE const * const yyvaluep, void **root)
{
  YYFPRINTF (yyo, "%s %s (",
             yykind < YYNTOKENS ? "token" : "nterm", yysymbol_name (yykind));

  yy_symbol_value_print (yyo, yykind, yyvaluep, root);
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
                 int yyrule, void **root)
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
                       &yyvsp[(yyi + 1) - (yynrhs)], root);
      YYFPRINTF (stderr, "\n");
    }
}

# define YY_REDUCE_PRINT(Rule)          \
do {                                    \
  if (yydebug)                          \
    yy_reduce_print (yyssp, yyvsp, Rule, root); \
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


/* Context of a parse error.  */
typedef struct
{
  yy_state_t *yyssp;
  yysymbol_kind_t yytoken;
} yypcontext_t;

/* Put in YYARG at most YYARGN of the expected tokens given the
   current YYCTX, and return the number of tokens stored in YYARG.  If
   YYARG is null, return the number of expected tokens (guaranteed to
   be less than YYNTOKENS).  Return YYENOMEM on memory exhaustion.
   Return 0 if there are more than YYARGN expected tokens, yet fill
   YYARG up to YYARGN. */
static int
yypcontext_expected_tokens (const yypcontext_t *yyctx,
                            yysymbol_kind_t yyarg[], int yyargn)
{
  /* Actual size of YYARG. */
  int yycount = 0;
  int yyn = yypact[+*yyctx->yyssp];
  if (!yypact_value_is_default (yyn))
    {
      /* Start YYX at -YYN if negative to avoid negative indexes in
         YYCHECK.  In other words, skip the first -YYN actions for
         this state because they are default actions.  */
      int yyxbegin = yyn < 0 ? -yyn : 0;
      /* Stay within bounds of both yycheck and yytname.  */
      int yychecklim = YYLAST - yyn + 1;
      int yyxend = yychecklim < YYNTOKENS ? yychecklim : YYNTOKENS;
      int yyx;
      for (yyx = yyxbegin; yyx < yyxend; ++yyx)
        if (yycheck[yyx + yyn] == yyx && yyx != YYSYMBOL_YYerror
            && !yytable_value_is_error (yytable[yyx + yyn]))
          {
            if (!yyarg)
              ++yycount;
            else if (yycount == yyargn)
              return 0;
            else
              yyarg[yycount++] = YY_CAST (yysymbol_kind_t, yyx);
          }
    }
  if (yyarg && yycount == 0 && 0 < yyargn)
    yyarg[0] = YYSYMBOL_YYEMPTY;
  return yycount;
}




#ifndef yystrlen
# if defined __GLIBC__ && defined _STRING_H
#  define yystrlen(S) (YY_CAST (YYPTRDIFF_T, strlen (S)))
# else
/* Return the length of YYSTR.  */
static YYPTRDIFF_T
yystrlen (const char *yystr)
{
  YYPTRDIFF_T yylen;
  for (yylen = 0; yystr[yylen]; yylen++)
    continue;
  return yylen;
}
# endif
#endif

#ifndef yystpcpy
# if defined __GLIBC__ && defined _STRING_H && defined _GNU_SOURCE
#  define yystpcpy stpcpy
# else
/* Copy YYSRC to YYDEST, returning the address of the terminating '\0' in
   YYDEST.  */
static char *
yystpcpy (char *yydest, const char *yysrc)
{
  char *yyd = yydest;
  const char *yys = yysrc;

  while ((*yyd++ = *yys++) != '\0')
    continue;

  return yyd - 1;
}
# endif
#endif

#ifndef yytnamerr
/* Copy to YYRES the contents of YYSTR after stripping away unnecessary
   quotes and backslashes, so that it's suitable for yyerror.  The
   heuristic is that double-quoting is unnecessary unless the string
   contains an apostrophe, a comma, or backslash (other than
   backslash-backslash).  YYSTR is taken from yytname.  If YYRES is
   null, do not copy; instead, return the length of what the result
   would have been.  */
static YYPTRDIFF_T
yytnamerr (char *yyres, const char *yystr)
{
  if (*yystr == '"')
    {
      YYPTRDIFF_T yyn = 0;
      char const *yyp = yystr;
      for (;;)
        switch (*++yyp)
          {
          case '\'':
          case ',':
            goto do_not_strip_quotes;

          case '\\':
            if (*++yyp != '\\')
              goto do_not_strip_quotes;
            else
              goto append;

          append:
          default:
            if (yyres)
              yyres[yyn] = *yyp;
            yyn++;
            break;

          case '"':
            if (yyres)
              yyres[yyn] = '\0';
            return yyn;
          }
    do_not_strip_quotes: ;
    }

  if (yyres)
    return yystpcpy (yyres, yystr) - yyres;
  else
    return yystrlen (yystr);
}
#endif


static int
yy_syntax_error_arguments (const yypcontext_t *yyctx,
                           yysymbol_kind_t yyarg[], int yyargn)
{
  /* Actual size of YYARG. */
  int yycount = 0;
  /* There are many possibilities here to consider:
     - If this state is a consistent state with a default action, then
       the only way this function was invoked is if the default action
       is an error action.  In that case, don't check for expected
       tokens because there are none.
     - The only way there can be no lookahead present (in yychar) is if
       this state is a consistent state with a default action.  Thus,
       detecting the absence of a lookahead is sufficient to determine
       that there is no unexpected or expected token to report.  In that
       case, just report a simple "syntax error".
     - Don't assume there isn't a lookahead just because this state is a
       consistent state with a default action.  There might have been a
       previous inconsistent state, consistent state with a non-default
       action, or user semantic action that manipulated yychar.
     - Of course, the expected token list depends on states to have
       correct lookahead information, and it depends on the parser not
       to perform extra reductions after fetching a lookahead from the
       scanner and before detecting a syntax error.  Thus, state merging
       (from LALR or IELR) and default reductions corrupt the expected
       token list.  However, the list is correct for canonical LR with
       one exception: it will still contain any token that will not be
       accepted due to an error action in a later state.
  */
  if (yyctx->yytoken != YYSYMBOL_YYEMPTY)
    {
      int yyn;
      if (yyarg)
        yyarg[yycount] = yyctx->yytoken;
      ++yycount;
      yyn = yypcontext_expected_tokens (yyctx,
                                        yyarg ? yyarg + 1 : yyarg, yyargn - 1);
      if (yyn == YYENOMEM)
        return YYENOMEM;
      else
        yycount += yyn;
    }
  return yycount;
}

/* Copy into *YYMSG, which is of size *YYMSG_ALLOC, an error message
   about the unexpected token YYTOKEN for the state stack whose top is
   YYSSP.

   Return 0 if *YYMSG was successfully written.  Return -1 if *YYMSG is
   not large enough to hold the message.  In that case, also set
   *YYMSG_ALLOC to the required number of bytes.  Return YYENOMEM if the
   required number of bytes is too large to store.  */
static int
yysyntax_error (YYPTRDIFF_T *yymsg_alloc, char **yymsg,
                const yypcontext_t *yyctx)
{
  enum { YYARGS_MAX = 5 };
  /* Internationalized format string. */
  const char *yyformat = YY_NULLPTR;
  /* Arguments of yyformat: reported tokens (one for the "unexpected",
     one per "expected"). */
  yysymbol_kind_t yyarg[YYARGS_MAX];
  /* Cumulated lengths of YYARG.  */
  YYPTRDIFF_T yysize = 0;

  /* Actual size of YYARG. */
  int yycount = yy_syntax_error_arguments (yyctx, yyarg, YYARGS_MAX);
  if (yycount == YYENOMEM)
    return YYENOMEM;

  switch (yycount)
    {
#define YYCASE_(N, S)                       \
      case N:                               \
        yyformat = S;                       \
        break
    default: /* Avoid compiler warnings. */
      YYCASE_(0, YY_("syntax error"));
      YYCASE_(1, YY_("syntax error, unexpected %s"));
      YYCASE_(2, YY_("syntax error, unexpected %s, expecting %s"));
      YYCASE_(3, YY_("syntax error, unexpected %s, expecting %s or %s"));
      YYCASE_(4, YY_("syntax error, unexpected %s, expecting %s or %s or %s"));
      YYCASE_(5, YY_("syntax error, unexpected %s, expecting %s or %s or %s or %s"));
#undef YYCASE_
    }

  /* Compute error message size.  Don't count the "%s"s, but reserve
     room for the terminator.  */
  yysize = yystrlen (yyformat) - 2 * yycount + 1;
  {
    int yyi;
    for (yyi = 0; yyi < yycount; ++yyi)
      {
        YYPTRDIFF_T yysize1
          = yysize + yytnamerr (YY_NULLPTR, yytname[yyarg[yyi]]);
        if (yysize <= yysize1 && yysize1 <= YYSTACK_ALLOC_MAXIMUM)
          yysize = yysize1;
        else
          return YYENOMEM;
      }
  }

  if (*yymsg_alloc < yysize)
    {
      *yymsg_alloc = 2 * yysize;
      if (! (yysize <= *yymsg_alloc
             && *yymsg_alloc <= YYSTACK_ALLOC_MAXIMUM))
        *yymsg_alloc = YYSTACK_ALLOC_MAXIMUM;
      return -1;
    }

  /* Avoid sprintf, as that infringes on the user's name space.
     Don't have undefined behavior even if the translation
     produced a string with the wrong number of "%s"s.  */
  {
    char *yyp = *yymsg;
    int yyi = 0;
    while ((*yyp = *yyformat) != '\0')
      if (*yyp == '%' && yyformat[1] == 's' && yyi < yycount)
        {
          yyp += yytnamerr (yyp, yytname[yyarg[yyi++]]);
          yyformat += 2;
        }
      else
        {
          ++yyp;
          ++yyformat;
        }
  }
  return 0;
}


/*-----------------------------------------------.
| Release the memory associated to this symbol.  |
`-----------------------------------------------*/

static void
yydestruct (const char *yymsg,
            yysymbol_kind_t yykind, YYSTYPE *yyvaluep, void **root)
{
  YY_USE (yyvaluep);
  YY_USE (root);
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
yyparse (void **root)
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

  /* Buffer for error messages, and its allocated size.  */
  char yymsgbuf[128];
  char *yymsg = yymsgbuf;
  YYPTRDIFF_T yymsg_alloc = sizeof yymsgbuf;

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
  case 2: /* program: %empty  */
#line 62 "grammar/parser.y"
      {(yyval.node) = mNode("program");}
#line 1563 "grammar/parser.cpp"
    break;

  case 3: /* program: program simple_declaration  */
#line 63 "grammar/parser.y"
                                 { (yyval.node) = (yyvsp[-1].node)->add((yyvsp[0].node)); *root = (yyval.node);}
#line 1569 "grammar/parser.cpp"
    break;

  case 4: /* program: program routine_declaration  */
#line 64 "grammar/parser.y"
                                  { (yyval.node) = (yyvsp[-1].node)->add((yyvsp[0].node)); *root = (yyval.node);}
#line 1575 "grammar/parser.cpp"
    break;

  case 5: /* simple_declaration: variable_declaration  */
#line 68 "grammar/parser.y"
                           { (yyval.node) = mpNode("simple_declaration", 1, (yyvsp[0].node)); }
#line 1581 "grammar/parser.cpp"
    break;

  case 6: /* simple_declaration: type_declaration  */
#line 69 "grammar/parser.y"
                       { (yyval.node) = mpNode("simple_declaration", 1, (yyvsp[0].node)); }
#line 1587 "grammar/parser.cpp"
    break;

  case 7: /* variable_declaration: VAR identifier COLON type variable_expression  */
#line 73 "grammar/parser.y"
                                                    { (yyval.node) = mpNode("variable_declaration", 3, (yyvsp[-3].node), (yyvsp[-1].node), (yyvsp[0].node));}
#line 1593 "grammar/parser.cpp"
    break;

  case 8: /* variable_declaration: VAR identifier IS expression  */
#line 74 "grammar/parser.y"
                                   { (yyval.node) = mpNode("variable_declaration_auto", 2, (yyvsp[-2].node), (yyvsp[0].node));}
#line 1599 "grammar/parser.cpp"
    break;

  case 9: /* variable_expression: %empty  */
#line 78 "grammar/parser.y"
      {(yyval.node) = nullptr;}
#line 1605 "grammar/parser.cpp"
    break;

  case 10: /* variable_expression: IS expression  */
#line 79 "grammar/parser.y"
                    { (yyval.node) = (yyvsp[0].node);}
#line 1611 "grammar/parser.cpp"
    break;

  case 11: /* type_declaration: TYPE identifier IS type  */
#line 83 "grammar/parser.y"
                              { (yyval.node) = mpNode("type_declaration", 2, (yyvsp[-2].node), (yyvsp[0].node));}
#line 1617 "grammar/parser.cpp"
    break;

  case 12: /* routine_declaration: ROUTINE identifier L_BR routine_parameters R_BR routine_return_type IS body END  */
#line 87 "grammar/parser.y"
                                                                                      { (yyval.node) = mpNode("routine_declaration", 4, (yyvsp[-7].node), (yyvsp[-5].node), (yyvsp[-3].node), (yyvsp[-1].node));}
#line 1623 "grammar/parser.cpp"
    break;

  case 13: /* routine_return_type: %empty  */
#line 91 "grammar/parser.y"
      {(yyval.node) = nullptr;}
#line 1629 "grammar/parser.cpp"
    break;

  case 14: /* routine_return_type: COLON type  */
#line 92 "grammar/parser.y"
                 { (yyval.node) = (yyvsp[0].node);}
#line 1635 "grammar/parser.cpp"
    break;

  case 15: /* routine_parameters: %empty  */
#line 96 "grammar/parser.y"
      {(yyval.node) = nullptr;}
#line 1641 "grammar/parser.cpp"
    break;

  case 16: /* routine_parameters: parameters  */
#line 97 "grammar/parser.y"
                 { (yyval.node) = (yyvsp[0].node);}
#line 1647 "grammar/parser.cpp"
    break;

  case 17: /* parameters: parameters COMMA parameter_declaration  */
#line 101 "grammar/parser.y"
                                             { (yyval.node) = (yyvsp[-2].node)->add((yyvsp[0].node));}
#line 1653 "grammar/parser.cpp"
    break;

  case 18: /* parameters: parameter_declaration  */
#line 102 "grammar/parser.y"
                            { (yyval.node) = mpNode("parameters", 1, (yyvsp[0].node));}
#line 1659 "grammar/parser.cpp"
    break;

  case 19: /* parameter_declaration: identifier COLON type  */
#line 107 "grammar/parser.y"
                            { (yyval.node) = mpNode("parameter_declaration", 2, (yyvsp[-2].node), (yyvsp[0].node));}
#line 1665 "grammar/parser.cpp"
    break;

  case 20: /* type: primitive_type  */
#line 111 "grammar/parser.y"
                     { (yyval.node) = mpNode("type", 1, (yyvsp[0].node));}
#line 1671 "grammar/parser.cpp"
    break;

  case 21: /* type: array_type  */
#line 112 "grammar/parser.y"
                 { (yyval.node) = mpNode("type", 1, (yyvsp[0].node));}
#line 1677 "grammar/parser.cpp"
    break;

  case 22: /* type: record_type  */
#line 113 "grammar/parser.y"
                  { (yyval.node) = mpNode("type", 1, (yyvsp[0].node));}
#line 1683 "grammar/parser.cpp"
    break;

  case 23: /* type: identifier  */
#line 114 "grammar/parser.y"
                 { (yyval.node) = mpNode("type", 1, (yyvsp[0].node));}
#line 1689 "grammar/parser.cpp"
    break;

  case 24: /* primitive_type: INTEGER  */
#line 118 "grammar/parser.y"
              { (yyval.node) = mNode("primitive_type", "integer");}
#line 1695 "grammar/parser.cpp"
    break;

  case 25: /* primitive_type: REAL  */
#line 119 "grammar/parser.y"
           { (yyval.node) = mNode("primitive_type", "real");}
#line 1701 "grammar/parser.cpp"
    break;

  case 26: /* primitive_type: BOOLEAN  */
#line 120 "grammar/parser.y"
              { (yyval.node) = mNode("primitive_type", "boolean");}
#line 1707 "grammar/parser.cpp"
    break;

  case 27: /* record_type: RECORD variables_declaration END  */
#line 124 "grammar/parser.y"
                                       { (yyval.node) = mpNode("record_type", 1, (yyvsp[-1].node));}
#line 1713 "grammar/parser.cpp"
    break;

  case 28: /* variables_declaration: %empty  */
#line 128 "grammar/parser.y"
      {(yyval.node) = mNode("variables_declaration");}
#line 1719 "grammar/parser.cpp"
    break;

  case 29: /* variables_declaration: variables_declaration variable_declaration  */
#line 129 "grammar/parser.y"
                                                 { (yyval.node) =  (yyvsp[-1].node)->add((yyvsp[0].node));}
#line 1725 "grammar/parser.cpp"
    break;

  case 30: /* array_type: ARRAY L_SQ_BR expression R_SQ_BR type  */
#line 133 "grammar/parser.y"
                                            { (yyval.node) = mpNode("array_type", 2, (yyvsp[-2].node), (yyvsp[0].node));}
#line 1731 "grammar/parser.cpp"
    break;

  case 31: /* body: %empty  */
#line 137 "grammar/parser.y"
      {(yyval.node) = mNode("body");}
#line 1737 "grammar/parser.cpp"
    break;

  case 32: /* body: body simple_declaration  */
#line 138 "grammar/parser.y"
                              { (yyval.node) = (yyvsp[-1].node)->add((yyvsp[0].node));}
#line 1743 "grammar/parser.cpp"
    break;

  case 33: /* body: body statement  */
#line 139 "grammar/parser.y"
                     { (yyval.node) = (yyvsp[-1].node)->add((yyvsp[0].node));}
#line 1749 "grammar/parser.cpp"
    break;

  case 34: /* statement: assignment  */
#line 143 "grammar/parser.y"
                  { (yyval.node) = mpNode("statement", 1, (yyvsp[0].node));}
#line 1755 "grammar/parser.cpp"
    break;

  case 35: /* statement: routine_call  */
#line 144 "grammar/parser.y"
                   { (yyval.node) = mpNode("statement", 1, (yyvsp[0].node));}
#line 1761 "grammar/parser.cpp"
    break;

  case 36: /* statement: while_loop  */
#line 145 "grammar/parser.y"
                 { (yyval.node) = mpNode("statement", 1, (yyvsp[0].node));}
#line 1767 "grammar/parser.cpp"
    break;

  case 37: /* statement: for_loop  */
#line 146 "grammar/parser.y"
               { (yyval.node) = mpNode("statement", 1, (yyvsp[0].node));}
#line 1773 "grammar/parser.cpp"
    break;

  case 38: /* statement: if_statement  */
#line 147 "grammar/parser.y"
                   { (yyval.node) = mpNode("statement", 1, (yyvsp[0].node));}
#line 1779 "grammar/parser.cpp"
    break;

  case 39: /* statement: return  */
#line 148 "grammar/parser.y"
             { (yyval.node) = mpNode("statement", 1, (yyvsp[0].node));}
#line 1785 "grammar/parser.cpp"
    break;

  case 40: /* return: RETURN expression  */
#line 152 "grammar/parser.y"
                        { (yyval.node) = mpNode("return", 1, (yyvsp[0].node)); }
#line 1791 "grammar/parser.cpp"
    break;

  case 41: /* return: RETURN  */
#line 153 "grammar/parser.y"
             { (yyval.node) = mNode("return"); }
#line 1797 "grammar/parser.cpp"
    break;

  case 42: /* assignment: modifiable_primary ASSIGNMENT_SIGN expression  */
#line 158 "grammar/parser.y"
                                                    { (yyval.node) = mpNode("assignment", 2, (yyvsp[-2].node), (yyvsp[0].node));}
#line 1803 "grammar/parser.cpp"
    break;

  case 43: /* routine_call: identifier L_BR arguments R_BR  */
#line 162 "grammar/parser.y"
                                     { (yyval.node) = mpNode("routine_call", 2, (yyvsp[-3].node), (yyvsp[-1].node));}
#line 1809 "grammar/parser.cpp"
    break;

  case 44: /* arguments: %empty  */
#line 166 "grammar/parser.y"
      {(yyval.node) = nullptr;}
#line 1815 "grammar/parser.cpp"
    break;

  case 45: /* arguments: expressions  */
#line 167 "grammar/parser.y"
                  { (yyval.node) = (yyvsp[0].node);}
#line 1821 "grammar/parser.cpp"
    break;

  case 46: /* expressions: expressions COMMA expression  */
#line 171 "grammar/parser.y"
                                   { (yyval.node) = (yyvsp[-2].node)->add((yyvsp[0].node));}
#line 1827 "grammar/parser.cpp"
    break;

  case 47: /* expressions: expression  */
#line 172 "grammar/parser.y"
                 { (yyval.node) = mpNode("arguments", 1, (yyvsp[0].node));}
#line 1833 "grammar/parser.cpp"
    break;

  case 48: /* while_loop: WHILE expression LOOP body END  */
#line 176 "grammar/parser.y"
                                     { (yyval.node) = mpNode("while_loop", 2, (yyvsp[-3].node), (yyvsp[-1].node));}
#line 1839 "grammar/parser.cpp"
    break;

  case 49: /* for_loop: FOR identifier range LOOP body END  */
#line 180 "grammar/parser.y"
                                         { (yyval.node) = mpNode("for_loop", 3, (yyvsp[-4].node), (yyvsp[-3].node), (yyvsp[-1].node));}
#line 1845 "grammar/parser.cpp"
    break;

  case 50: /* range: IN reverse expression RANGE_SIGN expression  */
#line 184 "grammar/parser.y"
                                                  { (yyval.node) = mpNode("range", 3, (yyvsp[-3].node), (yyvsp[-2].node), (yyvsp[0].node));}
#line 1851 "grammar/parser.cpp"
    break;

  case 51: /* reverse: %empty  */
#line 189 "grammar/parser.y"
      {(yyval.node) = nullptr;}
#line 1857 "grammar/parser.cpp"
    break;

  case 52: /* reverse: REVERSE  */
#line 190 "grammar/parser.y"
              { (yyval.node) = mNode("reverse");}
#line 1863 "grammar/parser.cpp"
    break;

  case 53: /* if_statement: IF expression THEN body else_body END  */
#line 194 "grammar/parser.y"
                                            { (yyval.node) = mpNode("if_statement", 3, (yyvsp[-4].node), (yyvsp[-2].node), (yyvsp[-1].node));}
#line 1869 "grammar/parser.cpp"
    break;

  case 54: /* else_body: %empty  */
#line 198 "grammar/parser.y"
      {(yyval.node) = nullptr;}
#line 1875 "grammar/parser.cpp"
    break;

  case 55: /* else_body: ELSE body  */
#line 199 "grammar/parser.y"
                { (yyval.node) = mpNode("else_body", 1, (yyvsp[0].node));}
#line 1881 "grammar/parser.cpp"
    break;

  case 56: /* expression: expression logic_operation relation  */
#line 203 "grammar/parser.y"
                                          { (yyval.node) = mpNode("expression", 3, (yyvsp[-2].node), (yyvsp[-1].node), (yyvsp[0].node));}
#line 1887 "grammar/parser.cpp"
    break;

  case 57: /* expression: relation  */
#line 204 "grammar/parser.y"
               { (yyval.node) = mpNode("expression", 1, (yyvsp[0].node));}
#line 1893 "grammar/parser.cpp"
    break;

  case 58: /* logic_operation: AND  */
#line 208 "grammar/parser.y"
          { (yyval.node) = mNode("logic_operation", "and");}
#line 1899 "grammar/parser.cpp"
    break;

  case 59: /* logic_operation: OR  */
#line 209 "grammar/parser.y"
         { (yyval.node) = mNode("logic_operation", "or");}
#line 1905 "grammar/parser.cpp"
    break;

  case 60: /* logic_operation: XOR  */
#line 210 "grammar/parser.y"
          { (yyval.node) = mNode("logic_opeartion", "xor");}
#line 1911 "grammar/parser.cpp"
    break;

  case 61: /* relation: simple  */
#line 214 "grammar/parser.y"
             { (yyval.node) = mpNode("relation", 1, (yyvsp[0].node));}
#line 1917 "grammar/parser.cpp"
    break;

  case 62: /* relation: simple compare_sign simple  */
#line 215 "grammar/parser.y"
                                 { (yyval.node) = mpNode("relation", 3, (yyvsp[-2].node), (yyvsp[-1].node), (yyvsp[0].node));}
#line 1923 "grammar/parser.cpp"
    break;

  case 63: /* compare_sign: LT_SIGN  */
#line 219 "grammar/parser.y"
              { (yyval.node) = mNode("compare_sign", "<");}
#line 1929 "grammar/parser.cpp"
    break;

  case 64: /* compare_sign: LET_SIGN  */
#line 220 "grammar/parser.y"
               { (yyval.node) = mNode("compare_sign", "<=");}
#line 1935 "grammar/parser.cpp"
    break;

  case 65: /* compare_sign: GT_SIGN  */
#line 221 "grammar/parser.y"
              { (yyval.node) = mNode("compare_sign", ">");}
#line 1941 "grammar/parser.cpp"
    break;

  case 66: /* compare_sign: GET_SIGN  */
#line 222 "grammar/parser.y"
               { (yyval.node) = mNode("compare_sign", ">=");}
#line 1947 "grammar/parser.cpp"
    break;

  case 67: /* compare_sign: EQ_SIGN  */
#line 223 "grammar/parser.y"
              { (yyval.node) = mNode("compare_sign", "=");}
#line 1953 "grammar/parser.cpp"
    break;

  case 68: /* compare_sign: NEQ_SIGN  */
#line 224 "grammar/parser.y"
               { (yyval.node) = mNode("compare_sign", "/=");}
#line 1959 "grammar/parser.cpp"
    break;

  case 69: /* simple: simple mult_sign_f factor  */
#line 228 "grammar/parser.y"
                                { (yyval.node) = mpNode("simple", 3, (yyvsp[-2].node), (yyvsp[-1].node), (yyvsp[0].node));}
#line 1965 "grammar/parser.cpp"
    break;

  case 70: /* simple: factor  */
#line 229 "grammar/parser.y"
             { (yyval.node) = mpNode("simple", 1, (yyvsp[0].node));}
#line 1971 "grammar/parser.cpp"
    break;

  case 71: /* mult_sign_f: MULT_SIGN  */
#line 233 "grammar/parser.y"
                { (yyval.node) = mNode("mult_sign", "*");}
#line 1977 "grammar/parser.cpp"
    break;

  case 72: /* mult_sign_f: DIV_SIGN  */
#line 234 "grammar/parser.y"
               { (yyval.node) = mNode("mult_sign", "/");}
#line 1983 "grammar/parser.cpp"
    break;

  case 73: /* mult_sign_f: MOD_SIGN  */
#line 235 "grammar/parser.y"
               { (yyval.node) = mNode("mod_sign", "%");}
#line 1989 "grammar/parser.cpp"
    break;

  case 74: /* factor: factor mult_sign_s summand  */
#line 239 "grammar/parser.y"
                                 { (yyval.node) = mpNode("factor", 3, (yyvsp[-2].node), (yyvsp[-1].node), (yyvsp[0].node));}
#line 1995 "grammar/parser.cpp"
    break;

  case 75: /* factor: summand  */
#line 240 "grammar/parser.y"
              { (yyval.node) = mpNode("factor", 1, (yyvsp[0].node));}
#line 2001 "grammar/parser.cpp"
    break;

  case 76: /* factor: mult_sign_s summand  */
#line 241 "grammar/parser.y"
                          { (yyval.node) = mpNode("unary_factor", 2, (yyvsp[-1].node), (yyvsp[0].node));}
#line 2007 "grammar/parser.cpp"
    break;

  case 77: /* factor: NOT summand  */
#line 242 "grammar/parser.y"
                  { (yyval.node) = mpNode("not_factor", 2, (yyvsp[-1].value), (yyvsp[0].node));}
#line 2013 "grammar/parser.cpp"
    break;

  case 78: /* mult_sign_s: PLUS_SIGN  */
#line 246 "grammar/parser.y"
                { (yyval.node) = mNode("sum_sign", "+");}
#line 2019 "grammar/parser.cpp"
    break;

  case 79: /* mult_sign_s: MINUS_SIGN  */
#line 247 "grammar/parser.y"
                 { (yyval.node) = mNode("sum_sign", "-");}
#line 2025 "grammar/parser.cpp"
    break;

  case 80: /* summand: primary  */
#line 251 "grammar/parser.y"
              { (yyval.node) = mpNode("summand", 1, (yyvsp[0].node));}
#line 2031 "grammar/parser.cpp"
    break;

  case 81: /* summand: L_BR expression R_BR  */
#line 252 "grammar/parser.y"
                           { (yyval.node) = mpNode("summand", 1, (yyvsp[-1].node));}
#line 2037 "grammar/parser.cpp"
    break;

  case 82: /* primary: TRUE  */
#line 257 "grammar/parser.y"
           { (yyval.node) = mNode("boolean", "true");}
#line 2043 "grammar/parser.cpp"
    break;

  case 83: /* primary: FALSE  */
#line 258 "grammar/parser.y"
            { (yyval.node) = mNode("boolean", "false");}
#line 2049 "grammar/parser.cpp"
    break;

  case 84: /* primary: REAL_LITERAL  */
#line 259 "grammar/parser.y"
                   { (yyval.node) = mNode("real", (yyvsp[0].value));}
#line 2055 "grammar/parser.cpp"
    break;

  case 85: /* primary: INTEGER_LITERAL  */
#line 260 "grammar/parser.y"
                      { (yyval.node) = mNode("integer", (yyvsp[0].value));}
#line 2061 "grammar/parser.cpp"
    break;

  case 86: /* primary: modifiable_primary  */
#line 261 "grammar/parser.y"
                         { (yyval.node) = (yyvsp[0].node);}
#line 2067 "grammar/parser.cpp"
    break;

  case 87: /* primary: routine_call  */
#line 262 "grammar/parser.y"
                   { (yyval.node) = (yyvsp[0].node);}
#line 2073 "grammar/parser.cpp"
    break;

  case 88: /* modifiable_primary: identifier  */
#line 266 "grammar/parser.y"
                 { (yyval.node) = mpNode("modifiable_primary", 1, (yyvsp[0].node));}
#line 2079 "grammar/parser.cpp"
    break;

  case 89: /* modifiable_primary: modifiable_primary L_SQ_BR expression R_SQ_BR  */
#line 267 "grammar/parser.y"
                                                    { (yyval.node) = mpNode("modifiable_primary_array", 2, (yyvsp[-3].node), (yyvsp[-1].node));}
#line 2085 "grammar/parser.cpp"
    break;

  case 90: /* modifiable_primary: modifiable_primary DOT modifiable_primary  */
#line 268 "grammar/parser.y"
                                                { (yyval.node) = mpNode("modifiable_primary_field", 2, (yyvsp[-2].node), (yyvsp[0].node));}
#line 2091 "grammar/parser.cpp"
    break;

  case 91: /* identifier: IDENTIFIER  */
#line 273 "grammar/parser.y"
                 { (yyval.node) = mNode("identifier", (yyvsp[0].value)); }
#line 2097 "grammar/parser.cpp"
    break;


#line 2101 "grammar/parser.cpp"

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
      {
        yypcontext_t yyctx
          = {yyssp, yytoken};
        char const *yymsgp = YY_("syntax error");
        int yysyntax_error_status;
        yysyntax_error_status = yysyntax_error (&yymsg_alloc, &yymsg, &yyctx);
        if (yysyntax_error_status == 0)
          yymsgp = yymsg;
        else if (yysyntax_error_status == -1)
          {
            if (yymsg != yymsgbuf)
              YYSTACK_FREE (yymsg);
            yymsg = YY_CAST (char *,
                             YYSTACK_ALLOC (YY_CAST (YYSIZE_T, yymsg_alloc)));
            if (yymsg)
              {
                yysyntax_error_status
                  = yysyntax_error (&yymsg_alloc, &yymsg, &yyctx);
                yymsgp = yymsg;
              }
            else
              {
                yymsg = yymsgbuf;
                yymsg_alloc = sizeof yymsgbuf;
                yysyntax_error_status = YYENOMEM;
              }
          }
        yyerror (root, yymsgp);
        if (yysyntax_error_status == YYENOMEM)
          YYNOMEM;
      }
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
                      yytoken, &yylval, root);
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
                  YY_ACCESSING_SYMBOL (yystate), yyvsp, root);
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
  yyerror (root, YY_("memory exhausted"));
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
                  yytoken, &yylval, root);
    }
  /* Do not reclaim the symbols of the rule whose action triggered
     this YYABORT or YYACCEPT.  */
  YYPOPSTACK (yylen);
  YY_STACK_PRINT (yyss, yyssp);
  while (yyssp != yyss)
    {
      yydestruct ("Cleanup: popping",
                  YY_ACCESSING_SYMBOL (+*yyssp), yyvsp, root);
      YYPOPSTACK (1);
    }
#ifndef yyoverflow
  if (yyss != yyssa)
    YYSTACK_FREE (yyss);
#endif
  if (yymsg != yymsgbuf)
    YYSTACK_FREE (yymsg);
  return yyresult;
}

#line 276 "grammar/parser.y"

