/* A Bison parser, made by GNU Bison 2.3.  */

/* Skeleton implementation for Bison's Yacc-like parsers in C

   Copyright (C) 1984, 1989, 1990, 2000, 2001, 2002, 2003, 2004, 2005, 2006
   Free Software Foundation, Inc.

   This program is free software; you can redistribute it and/or modify
   it under the terms of the GNU General Public License as published by
   the Free Software Foundation; either version 2, or (at your option)
   any later version.

   This program is distributed in the hope that it will be useful,
   but WITHOUT ANY WARRANTY; without even the implied warranty of
   MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
   GNU General Public License for more details.

   You should have received a copy of the GNU General Public License
   along with this program; if not, write to the Free Software
   Foundation, Inc., 51 Franklin Street, Fifth Floor,
   Boston, MA 02110-1301, USA.  */

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

/* All symbols defined below should begin with yy or YY, to avoid
   infringing on user name space.  This should be done even for local
   variables, as they might otherwise be expanded by user macros.
   There are some unavoidable exceptions within include files to
   define necessary library symbols; they are noted "INFRINGES ON
   USER NAME SPACE" below.  */

/* Identify Bison output.  */
#define YYBISON 1

/* Bison version.  */
#define YYBISON_VERSION "2.3"

/* Skeleton name.  */
#define YYSKELETON_NAME "yacc.c"

/* Pure parsers.  */
#define YYPURE 0

/* Using locations.  */
#define YYLSP_NEEDED 0



/* Tokens.  */
#ifndef YYTOKENTYPE
# define YYTOKENTYPE
   /* Put the tokens into the symbol table, so that GDB and other debuggers
      know about them.  */
   enum yytokentype {
     NUM = 258,
     true = 259,
     false = 260,
     id = 261,
     T_PLUS = 262,
     T_MOD = 263,
     T_DIV = 264,
     T_SUB = 265,
     T_MUL = 266,
     int_const = 267,
     char_const = 268,
     float_const = 269,
     string = 270,
     type_const = 271,
     access_specifier = 272,
     WHILE = 273,
     DO = 274,
     IF = 275,
     T_ELSE = 276,
     ELSEIF = 277,
     BREAK = 278,
     CLASS = 279,
     CONTINUE = 280,
     RETURN = 281,
     STATIC = 282,
     MAIN = 283,
     PRINT = 284,
     EXTENDS = 285,
     or_const = 286,
     and_const = 287,
     eq_const = 288,
     rel_const = 289,
     point_const = 290,
     param_const = 291,
     ELSE = 292,
     HEADER = 293
   };
#endif
/* Tokens.  */
#define NUM 258
#define true 259
#define false 260
#define id 261
#define T_PLUS 262
#define T_MOD 263
#define T_DIV 264
#define T_SUB 265
#define T_MUL 266
#define int_const 267
#define char_const 268
#define float_const 269
#define string 270
#define type_const 271
#define access_specifier 272
#define WHILE 273
#define DO 274
#define IF 275
#define T_ELSE 276
#define ELSEIF 277
#define BREAK 278
#define CLASS 279
#define CONTINUE 280
#define RETURN 281
#define STATIC 282
#define MAIN 283
#define PRINT 284
#define EXTENDS 285
#define or_const 286
#define and_const 287
#define eq_const 288
#define rel_const 289
#define point_const 290
#define param_const 291
#define ELSE 292
#define HEADER 293




/* Copy the first part of user declarations.  */
#line 1 "project.y"

	#include<stdio.h>
	#include <stdlib.h>
	#include<ctype.h>
	#include<string.h>
	#include "symtab.h"
	int yylex(void);
	extern char *yytext;
	extern int yylineno;
	extern void s_update(char val[2024],char var[2024],int scope);
	int yyerror(const char *s);
	int success = 1;
	int tcnt = 1;
	int flag=0;
	extern char data[100];
	int bal_brack = 0;
	int ltop=0;
	//int temp = 0;
	int close_brack = 0;
	int f;
	int lnum=1;
	int start=1;
	char st[100][10];
	int top=0;
	int tnum=0;
	char temp[10]="t";
	void push(char s[2024]);
	int ptemp=0;
	int ttemp=0;
	int tcount=0;
	int wcount=0;
	int lcount=0;
	void codegen();
	void lab1();
	void lab2();
	void lab3();
	void lab1_if();
	void lab2_if();
	void lab3_if();
	int lnum_if=0;
	int label[20];
	FILE* F1;
	FILE* f2;
	void codegen_assign();
	int error_count;
	char var[100];
	extern char new_var[100];
	int var7;
	extern int extract_value(char var[2024],int scope);
	#define type_name(expr) \
    (_Generic((expr), \
              char: "char", unsigned char: "unsigned char", signed char: "signed char", \
              short: "short", unsigned short: "unsigned short", \
              int: "int", unsigned int: "unsigned int", \
              long: "long", unsigned long: "unsigned long", \
              long long: "long long", unsigned long long: "unsigned long long", \
              float: "float", \
              double: "double", \
              long double: "long double", \
              void*: "void*", \
              default: "?"))


/* Enabling traces.  */
#ifndef YYDEBUG
# define YYDEBUG 0
#endif

/* Enabling verbose error messages.  */
#ifdef YYERROR_VERBOSE
# undef YYERROR_VERBOSE
# define YYERROR_VERBOSE 1
#else
# define YYERROR_VERBOSE 0
#endif

/* Enabling the token table.  */
#ifndef YYTOKEN_TABLE
# define YYTOKEN_TABLE 0
#endif

#if ! defined YYSTYPE && ! defined YYSTYPE_IS_DECLARED
typedef union YYSTYPE
#line 63 "project.y"
{
	int ival;
	char st[256];
	
	
}
/* Line 193 of yacc.c.  */
#line 242 "y.tab.c"
	YYSTYPE;
# define yystype YYSTYPE /* obsolescent; will be withdrawn */
# define YYSTYPE_IS_DECLARED 1
# define YYSTYPE_IS_TRIVIAL 1
#endif



/* Copy the second part of user declarations.  */


/* Line 216 of yacc.c.  */
#line 255 "y.tab.c"

#ifdef short
# undef short
#endif

#ifdef YYTYPE_UINT8
typedef YYTYPE_UINT8 yytype_uint8;
#else
typedef unsigned char yytype_uint8;
#endif

#ifdef YYTYPE_INT8
typedef YYTYPE_INT8 yytype_int8;
#elif (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
typedef signed char yytype_int8;
#else
typedef short int yytype_int8;
#endif

#ifdef YYTYPE_UINT16
typedef YYTYPE_UINT16 yytype_uint16;
#else
typedef unsigned short int yytype_uint16;
#endif

#ifdef YYTYPE_INT16
typedef YYTYPE_INT16 yytype_int16;
#else
typedef short int yytype_int16;
#endif

#ifndef YYSIZE_T
# ifdef __SIZE_TYPE__
#  define YYSIZE_T __SIZE_TYPE__
# elif defined size_t
#  define YYSIZE_T size_t
# elif ! defined YYSIZE_T && (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
#  include <stddef.h> /* INFRINGES ON USER NAME SPACE */
#  define YYSIZE_T size_t
# else
#  define YYSIZE_T unsigned int
# endif
#endif

#define YYSIZE_MAXIMUM ((YYSIZE_T) -1)

#ifndef YY_
# if defined YYENABLE_NLS && YYENABLE_NLS
#  if ENABLE_NLS
#   include <libintl.h> /* INFRINGES ON USER NAME SPACE */
#   define YY_(msgid) dgettext ("bison-runtime", msgid)
#  endif
# endif
# ifndef YY_
#  define YY_(msgid) msgid
# endif
#endif

/* Suppress unused-variable warnings by "using" E.  */
#if ! defined lint || defined __GNUC__
# define YYUSE(e) ((void) (e))
#else
# define YYUSE(e) /* empty */
#endif

/* Identity function, used to suppress warnings about constant conditions.  */
#ifndef lint
# define YYID(n) (n)
#else
#if (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
static int
YYID (int i)
#else
static int
YYID (i)
    int i;
#endif
{
  return i;
}
#endif

#if ! defined yyoverflow || YYERROR_VERBOSE

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
#    if ! defined _ALLOCA_H && ! defined _STDLIB_H && (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
#     include <stdlib.h> /* INFRINGES ON USER NAME SPACE */
#     ifndef _STDLIB_H
#      define _STDLIB_H 1
#     endif
#    endif
#   endif
#  endif
# endif

# ifdef YYSTACK_ALLOC
   /* Pacify GCC's `empty if-body' warning.  */
#  define YYSTACK_FREE(Ptr) do { /* empty */; } while (YYID (0))
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
#  if (defined __cplusplus && ! defined _STDLIB_H \
       && ! ((defined YYMALLOC || defined malloc) \
	     && (defined YYFREE || defined free)))
#   include <stdlib.h> /* INFRINGES ON USER NAME SPACE */
#   ifndef _STDLIB_H
#    define _STDLIB_H 1
#   endif
#  endif
#  ifndef YYMALLOC
#   define YYMALLOC malloc
#   if ! defined malloc && ! defined _STDLIB_H && (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
void *malloc (YYSIZE_T); /* INFRINGES ON USER NAME SPACE */
#   endif
#  endif
#  ifndef YYFREE
#   define YYFREE free
#   if ! defined free && ! defined _STDLIB_H && (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
void free (void *); /* INFRINGES ON USER NAME SPACE */
#   endif
#  endif
# endif
#endif /* ! defined yyoverflow || YYERROR_VERBOSE */


#if (! defined yyoverflow \
     && (! defined __cplusplus \
	 || (defined YYSTYPE_IS_TRIVIAL && YYSTYPE_IS_TRIVIAL)))

/* A type that is properly aligned for any stack member.  */
union yyalloc
{
  yytype_int16 yyss;
  YYSTYPE yyvs;
  };

/* The size of the maximum gap between one aligned stack and the next.  */
# define YYSTACK_GAP_MAXIMUM (sizeof (union yyalloc) - 1)

/* The size of an array large to enough to hold all stacks, each with
   N elements.  */
# define YYSTACK_BYTES(N) \
     ((N) * (sizeof (yytype_int16) + sizeof (YYSTYPE)) \
      + YYSTACK_GAP_MAXIMUM)

/* Copy COUNT objects from FROM to TO.  The source and destination do
   not overlap.  */
# ifndef YYCOPY
#  if defined __GNUC__ && 1 < __GNUC__
#   define YYCOPY(To, From, Count) \
      __builtin_memcpy (To, From, (Count) * sizeof (*(From)))
#  else
#   define YYCOPY(To, From, Count)		\
      do					\
	{					\
	  YYSIZE_T yyi;				\
	  for (yyi = 0; yyi < (Count); yyi++)	\
	    (To)[yyi] = (From)[yyi];		\
	}					\
      while (YYID (0))
#  endif
# endif

/* Relocate STACK from its old location to the new one.  The
   local variables YYSIZE and YYSTACKSIZE give the old and new number of
   elements in the stack, and YYPTR gives the new location of the
   stack.  Advance YYPTR to a properly aligned location for the next
   stack.  */
# define YYSTACK_RELOCATE(Stack)					\
    do									\
      {									\
	YYSIZE_T yynewbytes;						\
	YYCOPY (&yyptr->Stack, Stack, yysize);				\
	Stack = &yyptr->Stack;						\
	yynewbytes = yystacksize * sizeof (*Stack) + YYSTACK_GAP_MAXIMUM; \
	yyptr += yynewbytes / sizeof (*yyptr);				\
      }									\
    while (YYID (0))

#endif

/* YYFINAL -- State number of the termination state.  */
#define YYFINAL  8
/* YYLAST -- Last index in YYTABLE.  */
#define YYLAST   168

/* YYNTOKENS -- Number of terminals.  */
#define YYNTOKENS  48
/* YYNNTS -- Number of nonterminals.  */
#define YYNNTS  40
/* YYNRULES -- Number of rules.  */
#define YYNRULES  81
/* YYNRULES -- Number of states.  */
#define YYNSTATES  176

/* YYTRANSLATE(YYLEX) -- Bison symbol number corresponding to YYLEX.  */
#define YYUNDEFTOK  2
#define YYMAXUTOK   293

#define YYTRANSLATE(YYX)						\
  ((unsigned int) (YYX) <= YYMAXUTOK ? yytranslate[YYX] : YYUNDEFTOK)

/* YYTRANSLATE[YYLEX] -- Bison symbol number corresponding to YYLEX.  */
static const yytype_uint8 yytranslate[] =
{
       0,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
      41,    44,     2,     2,    46,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,    45,
       2,    47,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,    42,     2,    43,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,    39,     2,    40,     2,     2,     2,     2,
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
      35,    36,    37,    38
};

#if YYDEBUG
/* YYPRHS[YYN] -- Index of the first RHS symbol of rule number YYN in
   YYRHS.  */
static const yytype_uint16 yyprhs[] =
{
       0,     0,     3,     9,    16,    19,    33,    36,    37,    42,
      45,    48,    51,    54,    57,    60,    63,    64,    68,    71,
      72,    73,    80,    82,    86,    88,    92,    93,    94,    95,
      96,   107,   108,   109,   121,   122,   123,   134,   135,   145,
     146,   152,   154,   156,   157,   159,   163,   165,   167,   170,
     172,   174,   177,   180,   184,   186,   188,   189,   194,   195,
     200,   204,   206,   208,   212,   215,   217,   221,   223,   229,
     234,   238,   242,   244,   248,   252,   256,   258,   260,   262,
     264,   266
};

/* YYRHS -- A `-1'-separated list of the rules' RHS.  */
static const yytype_int8 yyrhs[] =
{
      49,     0,    -1,    24,     6,    39,    50,    40,    -1,    17,
      24,     6,    39,    50,    40,    -1,     1,    24,    -1,    17,
      27,    16,    28,    41,    16,    42,    43,     6,    44,    39,
      51,    40,    -1,     1,    28,    -1,    -1,    85,    45,    52,
      51,    -1,    84,    51,    -1,    81,    51,    -1,    74,    51,
      -1,    54,    51,    -1,    64,    51,    -1,    57,    51,    -1,
      61,    51,    -1,    -1,    45,    53,    51,    -1,     1,    51,
      -1,    -1,    -1,    29,    41,    56,    55,    44,    45,    -1,
      15,    -1,    15,     7,    56,    -1,     6,    -1,     6,     7,
      56,    -1,    -1,    -1,    -1,    -1,    18,    58,    41,    72,
      59,    44,    60,    39,    51,    40,    -1,    -1,    -1,    19,
      62,    39,    51,    40,    18,    41,    72,    63,    44,    45,
      -1,    -1,    -1,    20,    41,    72,    65,    44,    39,    51,
      66,    40,    71,    -1,    -1,    22,    41,    72,    44,    39,
      51,    68,    40,    71,    -1,    -1,    21,    39,    51,    70,
      40,    -1,    67,    -1,    69,    -1,    -1,    75,    -1,    75,
      80,    73,    -1,     4,    -1,     5,    -1,     1,    45,    -1,
      85,    -1,    75,    -1,    25,    45,    -1,    23,    45,    -1,
      26,    85,    45,    -1,    76,    -1,    79,    -1,    -1,    85,
      34,    77,    85,    -1,    -1,    85,    33,    78,    85,    -1,
      85,    80,    85,    -1,    31,    -1,    32,    -1,    82,    83,
      45,    -1,    82,    84,    -1,    16,    -1,    83,    46,     6,
      -1,     6,    -1,     6,    47,    85,    46,    84,    -1,     6,
      47,    85,    45,    -1,    85,     7,    86,    -1,    85,    10,
      86,    -1,    86,    -1,    86,    11,    87,    -1,    86,     9,
      87,    -1,    86,     8,    87,    -1,    87,    -1,     6,    -1,
       3,    -1,     4,    -1,     5,    -1,    41,    85,    44,    -1
};

/* YYRLINE[YYN] -- source line where rule number YYN was defined.  */
static const yytype_uint8 yyrline[] =
{
       0,    82,    82,    83,    84,    87,    88,    93,    93,    94,
      95,    96,    97,    98,    99,   100,   101,   101,   102,   103,
     106,   106,   108,   109,   110,   111,   112,   116,   116,   116,
     116,   120,   120,   120,   123,   123,   123,   124,   124,   125,
     125,   127,   128,   129,   133,   134,   135,   136,   137,   140,
     141,   144,   145,   146,   149,   151,   155,   155,   156,   156,
     159,   162,   163,   167,   168,   171,   175,   176,   179,   186,
     190,   193,   194,   197,   198,   199,   200,   204,   208,   211,
     212,   213
};
#endif

#if YYDEBUG || YYERROR_VERBOSE || YYTOKEN_TABLE
/* YYTNAME[SYMBOL-NUM] -- String name of the symbol SYMBOL-NUM.
   First, the terminals, then, starting at YYNTOKENS, nonterminals.  */
static const char *const yytname[] =
{
  "$end", "error", "$undefined", "NUM", "true", "false", "id", "T_PLUS",
  "T_MOD", "T_DIV", "T_SUB", "T_MUL", "int_const", "char_const",
  "float_const", "string", "type_const", "access_specifier", "WHILE", "DO",
  "IF", "T_ELSE", "ELSEIF", "BREAK", "CLASS", "CONTINUE", "RETURN",
  "STATIC", "MAIN", "PRINT", "EXTENDS", "or_const", "and_const",
  "eq_const", "rel_const", "point_const", "param_const", "ELSE", "HEADER",
  "'{'", "'}'", "'('", "'['", "']'", "')'", "';'", "','", "'='", "$accept",
  "program_unit", "BODY", "STMT", "@1", "@2", "PRNT", "@3", "PRNT_STAT",
  "LOOP", "@4", "@5", "@6", "DO_WHILE", "@7", "@8", "IF_CONDITION", "@9",
  "@10", "ELIF", "@11", "IF_ELSE", "@12", "ELSE_ELIF", "COND", "EXPR_E",
  "JUMP_STMT", "EXPR", "RELEXP", "@13", "@14", "LOGEXP", "LOGOP", "DECL",
  "TYPE", "VARLIST", "ASSIGNEXPR", "E", "T", "F", 0
};
#endif

# ifdef YYPRINT
/* YYTOKNUM[YYLEX-NUM] -- Internal token number corresponding to
   token YYLEX-NUM.  */
static const yytype_uint16 yytoknum[] =
{
       0,   256,   257,   258,   259,   260,   261,   262,   263,   264,
     265,   266,   267,   268,   269,   270,   271,   272,   273,   274,
     275,   276,   277,   278,   279,   280,   281,   282,   283,   284,
     285,   286,   287,   288,   289,   290,   291,   292,   293,   123,
     125,    40,    91,    93,    41,    59,    44,    61
};
# endif

/* YYR1[YYN] -- Symbol number of symbol that rule YYN derives.  */
static const yytype_uint8 yyr1[] =
{
       0,    48,    49,    49,    49,    50,    50,    52,    51,    51,
      51,    51,    51,    51,    51,    51,    53,    51,    51,    51,
      55,    54,    56,    56,    56,    56,    56,    58,    59,    60,
      57,    62,    63,    61,    65,    66,    64,    68,    67,    70,
      69,    71,    71,    71,    72,    72,    72,    72,    72,    73,
      73,    74,    74,    74,    75,    75,    77,    76,    78,    76,
      79,    80,    80,    81,    81,    82,    83,    83,    84,    84,
      85,    85,    85,    86,    86,    86,    86,    87,    87,    87,
      87,    87
};

/* YYR2[YYN] -- Number of symbols composing right hand side of rule YYN.  */
static const yytype_uint8 yyr2[] =
{
       0,     2,     5,     6,     2,    13,     2,     0,     4,     2,
       2,     2,     2,     2,     2,     2,     0,     3,     2,     0,
       0,     6,     1,     3,     1,     3,     0,     0,     0,     0,
      10,     0,     0,    11,     0,     0,    10,     0,     9,     0,
       5,     1,     1,     0,     1,     3,     1,     1,     2,     1,
       1,     2,     2,     3,     1,     1,     0,     4,     0,     4,
       3,     1,     1,     3,     2,     1,     3,     1,     5,     4,
       3,     3,     1,     3,     3,     3,     1,     1,     1,     1,
       1,     3
};

/* YYDEFACT[STATE-NAME] -- Default rule to reduce with in state
   STATE-NUM when YYTABLE doesn't specify something else to do.  Zero
   means the default is an error.  */
static const yytype_uint8 yydefact[] =
{
       0,     0,     0,     0,     0,     4,     0,     0,     1,     0,
       0,     0,     0,     0,     0,     0,     6,     0,     2,     3,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
      78,    79,    80,    77,    65,    27,    31,     0,     0,     0,
       0,     0,     0,    16,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,    72,    76,    18,     0,     0,     0,
       0,    52,    51,    77,     0,    26,     0,     0,     5,    12,
      14,    15,    13,    11,    10,    67,     0,    64,     9,     0,
       0,     7,     0,     0,     0,     0,     0,     0,     0,    79,
      80,    34,    44,    54,    55,     0,    53,    24,    22,    20,
      81,    17,    63,     0,    70,    71,     0,    75,    74,    73,
      69,     0,    28,     0,    48,     0,    61,    62,     0,    58,
      56,     0,    26,    26,     0,    66,     8,     0,    68,     0,
       0,     0,    45,    50,    49,     0,     0,    60,    25,    23,
       0,    29,     0,     0,    59,    57,    21,     0,     0,    35,
       0,    32,     0,     0,     0,    43,    30,     0,     0,     0,
      41,    42,    36,    33,     0,     0,    39,     0,     0,     0,
      40,     0,    37,     0,    43,    38
};

/* YYDEFGOTO[NTERM-NUM].  */
static const yytype_int16 yydefgoto[] =
{
      -1,     4,    14,    44,   106,    67,    45,   124,    99,    46,
      58,   129,   147,    47,    59,   154,    48,   115,   152,   160,
     173,   161,   168,   162,    91,   132,    49,    92,    93,   136,
     135,    94,   121,    50,    51,    76,    52,    53,    54,    55
};

/* YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
   STATE-NUM.  */
#define YYPACT_NINF -86
static const yytype_int16 yypact[] =
{
      35,   -16,   -14,    -2,    15,   -86,    39,    21,   -86,    27,
      29,    29,     7,    44,    68,    70,   -86,    90,   -86,   -86,
      56,    71,    91,    73,    74,   103,    72,    79,     8,     8,
     -86,   -86,   -86,    64,   -86,   -86,   -86,    78,    75,    77,
      51,    82,    51,   -86,    84,     8,     8,     8,     8,     8,
       8,   119,     8,    40,    67,   -86,   -86,    51,    85,    88,
      38,   -86,   -86,   -86,    54,    59,    -4,     8,   -86,   -86,
     -86,   -86,   -86,   -86,   -86,    64,    36,   -86,   -86,    51,
      51,   -86,    51,    51,    51,    22,    38,     8,    83,    87,
      89,   -86,    66,   -86,   -86,    62,   -86,   122,   125,   -86,
     -86,   -86,   -86,   128,    67,    67,     8,   -86,   -86,   -86,
     -86,   130,   -86,    97,   -86,    94,   -86,   -86,    51,   -86,
     -86,    51,    59,    59,    95,   -86,   -86,    64,   -86,    96,
     123,   104,   -86,   -86,    62,    51,    51,    63,   -86,   -86,
      99,   -86,   105,     8,    63,    63,   -86,   106,    38,   -86,
       8,   -86,   107,   108,   109,    69,   -86,   110,   111,   113,
     -86,   -86,   -86,   -86,     8,    38,   -86,   112,   117,   120,
     -86,     8,   -86,   118,    69,   -86
};

/* YYPGOTO[NTERM-NUM].  */
static const yytype_int16 yypgoto[] =
{
     -86,   -86,   138,   -29,   -86,   -86,   -86,   -86,   -20,   -86,
     -86,   -86,   -86,   -86,   -86,   -86,   -86,   -86,   -86,   -86,
     -86,   -86,   -86,   -23,   -85,   -86,   -86,    34,   -86,   -86,
     -86,   -86,    76,   -86,   -86,   -86,   -49,   -35,    25,     5
};

/* YYTABLE[YYPACT[STATE-NUM]].  What to do in state STATE-NUM.  If
   positive, shift that token.  If negative, reduce the rule which
   number is the opposite.  If zero, do what YYDEFACT says.
   If YYTABLE_NINF, syntax error.  */
#define YYTABLE_NINF -48
static const yytype_int16 yytable[] =
{
      56,   112,    77,    79,     7,    64,    80,    66,     5,    29,
       6,    30,    31,    32,    33,     8,    69,    70,    71,    72,
      73,    74,    85,    78,    34,    95,    35,    36,    37,    79,
      12,    38,    80,    39,    40,    16,     1,    41,   101,    88,
     100,    30,    89,    90,    63,     9,    13,    79,   -19,    42,
      80,    95,     2,    43,    30,    31,    32,    63,   113,     3,
      10,    79,   128,   151,    80,    97,    11,   110,   111,    79,
      79,    17,    80,    80,    98,    82,    83,   126,    84,    42,
     167,   102,   103,   134,    21,    81,   137,   107,   108,   109,
     158,   159,    42,   116,   117,   119,   120,   116,   117,    96,
     144,   145,   138,   139,   104,   105,    20,    23,    18,    26,
      19,    57,    22,    95,   149,    24,    27,    25,    28,    60,
      61,   153,    62,    65,    68,    75,    86,    87,   114,   122,
      95,   -46,   123,   -47,   125,   166,   127,   130,   131,   140,
     141,   142,   172,   143,   146,   150,   148,   155,   156,    15,
     164,   175,   133,   157,   165,   163,   169,   170,   174,   171,
       0,     0,     0,     0,     0,     0,     0,     0,   118
};

static const yytype_int16 yycheck[] =
{
      29,    86,    51,     7,     6,    40,    10,    42,    24,     1,
      24,     3,     4,     5,     6,     0,    45,    46,    47,    48,
      49,    50,    57,    52,    16,    60,    18,    19,    20,     7,
       1,    23,    10,    25,    26,    28,     1,    29,    67,     1,
      44,     3,     4,     5,     6,     6,    17,     7,    40,    41,
      10,    86,    17,    45,     3,     4,     5,     6,    87,    24,
      39,     7,   111,   148,    10,     6,    39,    45,    46,     7,
       7,    27,    10,    10,    15,     8,     9,   106,    11,    41,
     165,    45,    46,   118,    28,    45,   121,    82,    83,    84,
      21,    22,    41,    31,    32,    33,    34,    31,    32,    45,
     135,   136,   122,   123,    79,    80,    16,    16,    40,     6,
      40,    47,    41,   148,   143,    42,    44,    43,    39,    41,
      45,   150,    45,    41,    40,     6,    41,    39,    45,     7,
     165,    44,     7,    44,     6,   164,     6,    40,    44,    44,
      44,    18,   171,    39,    45,    39,    41,    40,    40,    11,
      39,   174,   118,    44,    41,    45,    44,    40,    40,    39,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    92
};

/* YYSTOS[STATE-NUM] -- The (internal number of the) accessing
   symbol of state STATE-NUM.  */
static const yytype_uint8 yystos[] =
{
       0,     1,    17,    24,    49,    24,    24,     6,     0,     6,
      39,    39,     1,    17,    50,    50,    28,    27,    40,    40,
      16,    28,    41,    16,    42,    43,     6,    44,    39,     1,
       3,     4,     5,     6,    16,    18,    19,    20,    23,    25,
      26,    29,    41,    45,    51,    54,    57,    61,    64,    74,
      81,    82,    84,    85,    86,    87,    51,    47,    58,    62,
      41,    45,    45,     6,    85,    41,    85,    53,    40,    51,
      51,    51,    51,    51,    51,     6,    83,    84,    51,     7,
      10,    45,     8,     9,    11,    85,    41,    39,     1,     4,
       5,    72,    75,    76,    79,    85,    45,     6,    15,    56,
      44,    51,    45,    46,    86,    86,    52,    87,    87,    87,
      45,    46,    72,    51,    45,    65,    31,    32,    80,    33,
      34,    80,     7,     7,    55,     6,    51,     6,    84,    59,
      40,    44,    73,    75,    85,    78,    77,    85,    56,    56,
      44,    44,    18,    39,    85,    85,    45,    60,    41,    51,
      39,    72,    66,    51,    63,    40,    40,    44,    21,    22,
      67,    69,    71,    45,    39,    41,    51,    72,    70,    44,
      40,    39,    51,    68,    40,    71
};

#define yyerrok		(yyerrstatus = 0)
#define yyclearin	(yychar = YYEMPTY)
#define YYEMPTY		(-2)
#define YYEOF		0

#define YYACCEPT	goto yyacceptlab
#define YYABORT		goto yyabortlab
#define YYERROR		goto yyerrorlab


/* Like YYERROR except do call yyerror.  This remains here temporarily
   to ease the transition to the new meaning of YYERROR, for GCC.
   Once GCC version 2 has supplanted version 1, this can go.  */

#define YYFAIL		goto yyerrlab

#define YYRECOVERING()  (!!yyerrstatus)

#define YYBACKUP(Token, Value)					\
do								\
  if (yychar == YYEMPTY && yylen == 1)				\
    {								\
      yychar = (Token);						\
      yylval = (Value);						\
      yytoken = YYTRANSLATE (yychar);				\
      YYPOPSTACK (1);						\
      goto yybackup;						\
    }								\
  else								\
    {								\
      yyerror (YY_("syntax error: cannot back up")); \
      YYERROR;							\
    }								\
while (YYID (0))


#define YYTERROR	1
#define YYERRCODE	256


/* YYLLOC_DEFAULT -- Set CURRENT to span from RHS[1] to RHS[N].
   If N is 0, then set CURRENT to the empty location which ends
   the previous symbol: RHS[0] (always defined).  */

#define YYRHSLOC(Rhs, K) ((Rhs)[K])
#ifndef YYLLOC_DEFAULT
# define YYLLOC_DEFAULT(Current, Rhs, N)				\
    do									\
      if (YYID (N))                                                    \
	{								\
	  (Current).first_line   = YYRHSLOC (Rhs, 1).first_line;	\
	  (Current).first_column = YYRHSLOC (Rhs, 1).first_column;	\
	  (Current).last_line    = YYRHSLOC (Rhs, N).last_line;		\
	  (Current).last_column  = YYRHSLOC (Rhs, N).last_column;	\
	}								\
      else								\
	{								\
	  (Current).first_line   = (Current).last_line   =		\
	    YYRHSLOC (Rhs, 0).last_line;				\
	  (Current).first_column = (Current).last_column =		\
	    YYRHSLOC (Rhs, 0).last_column;				\
	}								\
    while (YYID (0))
#endif


/* YY_LOCATION_PRINT -- Print the location on the stream.
   This macro was not mandated originally: define only if we know
   we won't break user code: when these are the locations we know.  */

#ifndef YY_LOCATION_PRINT
# if defined YYLTYPE_IS_TRIVIAL && YYLTYPE_IS_TRIVIAL
#  define YY_LOCATION_PRINT(File, Loc)			\
     fprintf (File, "%d.%d-%d.%d",			\
	      (Loc).first_line, (Loc).first_column,	\
	      (Loc).last_line,  (Loc).last_column)
# else
#  define YY_LOCATION_PRINT(File, Loc) ((void) 0)
# endif
#endif


/* YYLEX -- calling `yylex' with the right arguments.  */

#ifdef YYLEX_PARAM
# define YYLEX yylex (YYLEX_PARAM)
#else
# define YYLEX yylex ()
#endif

/* Enable debugging if requested.  */
#if YYDEBUG

# ifndef YYFPRINTF
#  include <stdio.h> /* INFRINGES ON USER NAME SPACE */
#  define YYFPRINTF fprintf
# endif

# define YYDPRINTF(Args)			\
do {						\
  if (yydebug)					\
    YYFPRINTF Args;				\
} while (YYID (0))

# define YY_SYMBOL_PRINT(Title, Type, Value, Location)			  \
do {									  \
  if (yydebug)								  \
    {									  \
      YYFPRINTF (stderr, "%s ", Title);					  \
      yy_symbol_print (stderr,						  \
		  Type, Value); \
      YYFPRINTF (stderr, "\n");						  \
    }									  \
} while (YYID (0))


/*--------------------------------.
| Print this symbol on YYOUTPUT.  |
`--------------------------------*/

/*ARGSUSED*/
#if (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
static void
yy_symbol_value_print (FILE *yyoutput, int yytype, YYSTYPE const * const yyvaluep)
#else
static void
yy_symbol_value_print (yyoutput, yytype, yyvaluep)
    FILE *yyoutput;
    int yytype;
    YYSTYPE const * const yyvaluep;
#endif
{
  if (!yyvaluep)
    return;
# ifdef YYPRINT
  if (yytype < YYNTOKENS)
    YYPRINT (yyoutput, yytoknum[yytype], *yyvaluep);
# else
  YYUSE (yyoutput);
# endif
  switch (yytype)
    {
      default:
	break;
    }
}


/*--------------------------------.
| Print this symbol on YYOUTPUT.  |
`--------------------------------*/

#if (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
static void
yy_symbol_print (FILE *yyoutput, int yytype, YYSTYPE const * const yyvaluep)
#else
static void
yy_symbol_print (yyoutput, yytype, yyvaluep)
    FILE *yyoutput;
    int yytype;
    YYSTYPE const * const yyvaluep;
#endif
{
  if (yytype < YYNTOKENS)
    YYFPRINTF (yyoutput, "token %s (", yytname[yytype]);
  else
    YYFPRINTF (yyoutput, "nterm %s (", yytname[yytype]);

  yy_symbol_value_print (yyoutput, yytype, yyvaluep);
  YYFPRINTF (yyoutput, ")");
}

/*------------------------------------------------------------------.
| yy_stack_print -- Print the state stack from its BOTTOM up to its |
| TOP (included).                                                   |
`------------------------------------------------------------------*/

#if (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
static void
yy_stack_print (yytype_int16 *bottom, yytype_int16 *top)
#else
static void
yy_stack_print (bottom, top)
    yytype_int16 *bottom;
    yytype_int16 *top;
#endif
{
  YYFPRINTF (stderr, "Stack now");
  for (; bottom <= top; ++bottom)
    YYFPRINTF (stderr, " %d", *bottom);
  YYFPRINTF (stderr, "\n");
}

# define YY_STACK_PRINT(Bottom, Top)				\
do {								\
  if (yydebug)							\
    yy_stack_print ((Bottom), (Top));				\
} while (YYID (0))


/*------------------------------------------------.
| Report that the YYRULE is going to be reduced.  |
`------------------------------------------------*/

#if (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
static void
yy_reduce_print (YYSTYPE *yyvsp, int yyrule)
#else
static void
yy_reduce_print (yyvsp, yyrule)
    YYSTYPE *yyvsp;
    int yyrule;
#endif
{
  int yynrhs = yyr2[yyrule];
  int yyi;
  unsigned long int yylno = yyrline[yyrule];
  YYFPRINTF (stderr, "Reducing stack by rule %d (line %lu):\n",
	     yyrule - 1, yylno);
  /* The symbols being reduced.  */
  for (yyi = 0; yyi < yynrhs; yyi++)
    {
      fprintf (stderr, "   $%d = ", yyi + 1);
      yy_symbol_print (stderr, yyrhs[yyprhs[yyrule] + yyi],
		       &(yyvsp[(yyi + 1) - (yynrhs)])
		       		       );
      fprintf (stderr, "\n");
    }
}

# define YY_REDUCE_PRINT(Rule)		\
do {					\
  if (yydebug)				\
    yy_reduce_print (yyvsp, Rule); \
} while (YYID (0))

/* Nonzero means print parse trace.  It is left uninitialized so that
   multiple parsers can coexist.  */
int yydebug;
#else /* !YYDEBUG */
# define YYDPRINTF(Args)
# define YY_SYMBOL_PRINT(Title, Type, Value, Location)
# define YY_STACK_PRINT(Bottom, Top)
# define YY_REDUCE_PRINT(Rule)
#endif /* !YYDEBUG */


/* YYINITDEPTH -- initial size of the parser's stacks.  */
#ifndef	YYINITDEPTH
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



#if YYERROR_VERBOSE

# ifndef yystrlen
#  if defined __GLIBC__ && defined _STRING_H
#   define yystrlen strlen
#  else
/* Return the length of YYSTR.  */
#if (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
static YYSIZE_T
yystrlen (const char *yystr)
#else
static YYSIZE_T
yystrlen (yystr)
    const char *yystr;
#endif
{
  YYSIZE_T yylen;
  for (yylen = 0; yystr[yylen]; yylen++)
    continue;
  return yylen;
}
#  endif
# endif

# ifndef yystpcpy
#  if defined __GLIBC__ && defined _STRING_H && defined _GNU_SOURCE
#   define yystpcpy stpcpy
#  else
/* Copy YYSRC to YYDEST, returning the address of the terminating '\0' in
   YYDEST.  */
#if (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
static char *
yystpcpy (char *yydest, const char *yysrc)
#else
static char *
yystpcpy (yydest, yysrc)
    char *yydest;
    const char *yysrc;
#endif
{
  char *yyd = yydest;
  const char *yys = yysrc;

  while ((*yyd++ = *yys++) != '\0')
    continue;

  return yyd - 1;
}
#  endif
# endif

# ifndef yytnamerr
/* Copy to YYRES the contents of YYSTR after stripping away unnecessary
   quotes and backslashes, so that it's suitable for yyerror.  The
   heuristic is that double-quoting is unnecessary unless the string
   contains an apostrophe, a comma, or backslash (other than
   backslash-backslash).  YYSTR is taken from yytname.  If YYRES is
   null, do not copy; instead, return the length of what the result
   would have been.  */
static YYSIZE_T
yytnamerr (char *yyres, const char *yystr)
{
  if (*yystr == '"')
    {
      YYSIZE_T yyn = 0;
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
	    /* Fall through.  */
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

  if (! yyres)
    return yystrlen (yystr);

  return yystpcpy (yyres, yystr) - yyres;
}
# endif

/* Copy into YYRESULT an error message about the unexpected token
   YYCHAR while in state YYSTATE.  Return the number of bytes copied,
   including the terminating null byte.  If YYRESULT is null, do not
   copy anything; just return the number of bytes that would be
   copied.  As a special case, return 0 if an ordinary "syntax error"
   message will do.  Return YYSIZE_MAXIMUM if overflow occurs during
   size calculation.  */
static YYSIZE_T
yysyntax_error (char *yyresult, int yystate, int yychar)
{
  int yyn = yypact[yystate];

  if (! (YYPACT_NINF < yyn && yyn <= YYLAST))
    return 0;
  else
    {
      int yytype = YYTRANSLATE (yychar);
      YYSIZE_T yysize0 = yytnamerr (0, yytname[yytype]);
      YYSIZE_T yysize = yysize0;
      YYSIZE_T yysize1;
      int yysize_overflow = 0;
      enum { YYERROR_VERBOSE_ARGS_MAXIMUM = 5 };
      char const *yyarg[YYERROR_VERBOSE_ARGS_MAXIMUM];
      int yyx;

# if 0
      /* This is so xgettext sees the translatable formats that are
	 constructed on the fly.  */
      YY_("syntax error, unexpected %s");
      YY_("syntax error, unexpected %s, expecting %s");
      YY_("syntax error, unexpected %s, expecting %s or %s");
      YY_("syntax error, unexpected %s, expecting %s or %s or %s");
      YY_("syntax error, unexpected %s, expecting %s or %s or %s or %s");
# endif
      char *yyfmt;
      char const *yyf;
      static char const yyunexpected[] = "syntax error, unexpected %s";
      static char const yyexpecting[] = ", expecting %s";
      static char const yyor[] = " or %s";
      char yyformat[sizeof yyunexpected
		    + sizeof yyexpecting - 1
		    + ((YYERROR_VERBOSE_ARGS_MAXIMUM - 2)
		       * (sizeof yyor - 1))];
      char const *yyprefix = yyexpecting;

      /* Start YYX at -YYN if negative to avoid negative indexes in
	 YYCHECK.  */
      int yyxbegin = yyn < 0 ? -yyn : 0;

      /* Stay within bounds of both yycheck and yytname.  */
      int yychecklim = YYLAST - yyn + 1;
      int yyxend = yychecklim < YYNTOKENS ? yychecklim : YYNTOKENS;
      int yycount = 1;

      yyarg[0] = yytname[yytype];
      yyfmt = yystpcpy (yyformat, yyunexpected);

      for (yyx = yyxbegin; yyx < yyxend; ++yyx)
	if (yycheck[yyx + yyn] == yyx && yyx != YYTERROR)
	  {
	    if (yycount == YYERROR_VERBOSE_ARGS_MAXIMUM)
	      {
		yycount = 1;
		yysize = yysize0;
		yyformat[sizeof yyunexpected - 1] = '\0';
		break;
	      }
	    yyarg[yycount++] = yytname[yyx];
	    yysize1 = yysize + yytnamerr (0, yytname[yyx]);
	    yysize_overflow |= (yysize1 < yysize);
	    yysize = yysize1;
	    yyfmt = yystpcpy (yyfmt, yyprefix);
	    yyprefix = yyor;
	  }

      yyf = YY_(yyformat);
      yysize1 = yysize + yystrlen (yyf);
      yysize_overflow |= (yysize1 < yysize);
      yysize = yysize1;

      if (yysize_overflow)
	return YYSIZE_MAXIMUM;

      if (yyresult)
	{
	  /* Avoid sprintf, as that infringes on the user's name space.
	     Don't have undefined behavior even if the translation
	     produced a string with the wrong number of "%s"s.  */
	  char *yyp = yyresult;
	  int yyi = 0;
	  while ((*yyp = *yyf) != '\0')
	    {
	      if (*yyp == '%' && yyf[1] == 's' && yyi < yycount)
		{
		  yyp += yytnamerr (yyp, yyarg[yyi++]);
		  yyf += 2;
		}
	      else
		{
		  yyp++;
		  yyf++;
		}
	    }
	}
      return yysize;
    }
}
#endif /* YYERROR_VERBOSE */


/*-----------------------------------------------.
| Release the memory associated to this symbol.  |
`-----------------------------------------------*/

/*ARGSUSED*/
#if (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
static void
yydestruct (const char *yymsg, int yytype, YYSTYPE *yyvaluep)
#else
static void
yydestruct (yymsg, yytype, yyvaluep)
    const char *yymsg;
    int yytype;
    YYSTYPE *yyvaluep;
#endif
{
  YYUSE (yyvaluep);

  if (!yymsg)
    yymsg = "Deleting";
  YY_SYMBOL_PRINT (yymsg, yytype, yyvaluep, yylocationp);

  switch (yytype)
    {

      default:
	break;
    }
}


/* Prevent warnings from -Wmissing-prototypes.  */

#ifdef YYPARSE_PARAM
#if defined __STDC__ || defined __cplusplus
int yyparse (void *YYPARSE_PARAM);
#else
int yyparse ();
#endif
#else /* ! YYPARSE_PARAM */
#if defined __STDC__ || defined __cplusplus
int yyparse (void);
#else
int yyparse ();
#endif
#endif /* ! YYPARSE_PARAM */



/* The look-ahead symbol.  */
int yychar;

/* The semantic value of the look-ahead symbol.  */
YYSTYPE yylval;

/* Number of syntax errors so far.  */
int yynerrs;



/*----------.
| yyparse.  |
`----------*/

#ifdef YYPARSE_PARAM
#if (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
int
yyparse (void *YYPARSE_PARAM)
#else
int
yyparse (YYPARSE_PARAM)
    void *YYPARSE_PARAM;
#endif
#else /* ! YYPARSE_PARAM */
#if (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
int
yyparse (void)
#else
int
yyparse ()

#endif
#endif
{
  
  int yystate;
  int yyn;
  int yyresult;
  /* Number of tokens to shift before error messages enabled.  */
  int yyerrstatus;
  /* Look-ahead token as an internal (translated) token number.  */
  int yytoken = 0;
#if YYERROR_VERBOSE
  /* Buffer for error messages, and its allocated size.  */
  char yymsgbuf[128];
  char *yymsg = yymsgbuf;
  YYSIZE_T yymsg_alloc = sizeof yymsgbuf;
#endif

  /* Three stacks and their tools:
     `yyss': related to states,
     `yyvs': related to semantic values,
     `yyls': related to locations.

     Refer to the stacks thru separate pointers, to allow yyoverflow
     to reallocate them elsewhere.  */

  /* The state stack.  */
  yytype_int16 yyssa[YYINITDEPTH];
  yytype_int16 *yyss = yyssa;
  yytype_int16 *yyssp;

  /* The semantic value stack.  */
  YYSTYPE yyvsa[YYINITDEPTH];
  YYSTYPE *yyvs = yyvsa;
  YYSTYPE *yyvsp;



#define YYPOPSTACK(N)   (yyvsp -= (N), yyssp -= (N))

  YYSIZE_T yystacksize = YYINITDEPTH;

  /* The variables used to return semantic value and location from the
     action routines.  */
  YYSTYPE yyval;


  /* The number of symbols on the RHS of the reduced rule.
     Keep to zero when no symbol should be popped.  */
  int yylen = 0;

  YYDPRINTF ((stderr, "Starting parse\n"));

  yystate = 0;
  yyerrstatus = 0;
  yynerrs = 0;
  yychar = YYEMPTY;		/* Cause a token to be read.  */

  /* Initialize stack pointers.
     Waste one element of value and location stack
     so that they stay on the same level as the state stack.
     The wasted elements are never initialized.  */

  yyssp = yyss;
  yyvsp = yyvs;

  goto yysetstate;

/*------------------------------------------------------------.
| yynewstate -- Push a new state, which is found in yystate.  |
`------------------------------------------------------------*/
 yynewstate:
  /* In all cases, when you get here, the value and location stacks
     have just been pushed.  So pushing a state here evens the stacks.  */
  yyssp++;

 yysetstate:
  *yyssp = yystate;

  if (yyss + yystacksize - 1 <= yyssp)
    {
      /* Get the current used size of the three stacks, in elements.  */
      YYSIZE_T yysize = yyssp - yyss + 1;

#ifdef yyoverflow
      {
	/* Give user a chance to reallocate the stack.  Use copies of
	   these so that the &'s don't force the real ones into
	   memory.  */
	YYSTYPE *yyvs1 = yyvs;
	yytype_int16 *yyss1 = yyss;


	/* Each stack pointer address is followed by the size of the
	   data in use in that stack, in bytes.  This used to be a
	   conditional around just the two extra args, but that might
	   be undefined if yyoverflow is a macro.  */
	yyoverflow (YY_("memory exhausted"),
		    &yyss1, yysize * sizeof (*yyssp),
		    &yyvs1, yysize * sizeof (*yyvsp),

		    &yystacksize);

	yyss = yyss1;
	yyvs = yyvs1;
      }
#else /* no yyoverflow */
# ifndef YYSTACK_RELOCATE
      goto yyexhaustedlab;
# else
      /* Extend the stack our own way.  */
      if (YYMAXDEPTH <= yystacksize)
	goto yyexhaustedlab;
      yystacksize *= 2;
      if (YYMAXDEPTH < yystacksize)
	yystacksize = YYMAXDEPTH;

      {
	yytype_int16 *yyss1 = yyss;
	union yyalloc *yyptr =
	  (union yyalloc *) YYSTACK_ALLOC (YYSTACK_BYTES (yystacksize));
	if (! yyptr)
	  goto yyexhaustedlab;
	YYSTACK_RELOCATE (yyss);
	YYSTACK_RELOCATE (yyvs);

#  undef YYSTACK_RELOCATE
	if (yyss1 != yyssa)
	  YYSTACK_FREE (yyss1);
      }
# endif
#endif /* no yyoverflow */

      yyssp = yyss + yysize - 1;
      yyvsp = yyvs + yysize - 1;


      YYDPRINTF ((stderr, "Stack size increased to %lu\n",
		  (unsigned long int) yystacksize));

      if (yyss + yystacksize - 1 <= yyssp)
	YYABORT;
    }

  YYDPRINTF ((stderr, "Entering state %d\n", yystate));

  goto yybackup;

/*-----------.
| yybackup.  |
`-----------*/
yybackup:

  /* Do appropriate processing given the current state.  Read a
     look-ahead token if we need one and don't already have one.  */

  /* First try to decide what to do without reference to look-ahead token.  */
  yyn = yypact[yystate];
  if (yyn == YYPACT_NINF)
    goto yydefault;

  /* Not known => get a look-ahead token if don't already have one.  */

  /* YYCHAR is either YYEMPTY or YYEOF or a valid look-ahead symbol.  */
  if (yychar == YYEMPTY)
    {
      YYDPRINTF ((stderr, "Reading a token: "));
      yychar = YYLEX;
    }

  if (yychar <= YYEOF)
    {
      yychar = yytoken = YYEOF;
      YYDPRINTF ((stderr, "Now at end of input.\n"));
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
      if (yyn == 0 || yyn == YYTABLE_NINF)
	goto yyerrlab;
      yyn = -yyn;
      goto yyreduce;
    }

  if (yyn == YYFINAL)
    YYACCEPT;

  /* Count tokens shifted since error; after three, turn off error
     status.  */
  if (yyerrstatus)
    yyerrstatus--;

  /* Shift the look-ahead token.  */
  YY_SYMBOL_PRINT ("Shifting", yytoken, &yylval, &yylloc);

  /* Discard the shifted token unless it is eof.  */
  if (yychar != YYEOF)
    yychar = YYEMPTY;

  yystate = yyn;
  *++yyvsp = yylval;

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
| yyreduce -- Do a reduction.  |
`-----------------------------*/
yyreduce:
  /* yyn is the number of a rule to reduce with.  */
  yylen = yyr2[yyn];

  /* If YYLEN is nonzero, implement the default value of the action:
     `$$ = $1'.

     Otherwise, the following line sets YYVAL to garbage.
     This behavior is undocumented and Bison
     users should not rely upon it.  Assigning to YYVAL
     unconditionally makes the parser a bit smaller, and it avoids a
     GCC warning that YYVAL may be used uninitialized.  */
  yyval = yyvsp[1-yylen];


  YY_REDUCE_PRINT (yyn);
  switch (yyn)
    {
        case 2:
#line 82 "project.y"
    {YYACCEPT;}
    break;

  case 3:
#line 83 "project.y"
    {YYACCEPT;}
    break;

  case 4:
#line 84 "project.y"
    {yyerrok;}
    break;

  case 6:
#line 88 "project.y"
    {yyerrok;}
    break;

  case 7:
#line 93 "project.y"
    {strcpy(data,"-");}
    break;

  case 16:
#line 101 "project.y"
    {strcpy(data,"null");}
    break;

  case 18:
#line 102 "project.y"
    {yyerrok;}
    break;

  case 20:
#line 106 "project.y"
    {ptemp=1;}
    break;

  case 27:
#line 116 "project.y"
    { wcount=1;lab1();}
    break;

  case 28:
#line 116 "project.y"
    { codegen(); tnum++;  }
    break;

  case 29:
#line 116 "project.y"
    {lab2(); 							lcount=1;}
    break;

  case 30:
#line 116 "project.y"
    {lab3();}
    break;

  case 31:
#line 120 "project.y"
    {lab1();}
    break;

  case 32:
#line 120 "project.y"
    {codegen(); tnum++; lab2();}
    break;

  case 33:
#line 120 "project.y"
    {lab3();}
    break;

  case 34:
#line 123 "project.y"
    { codegen();tnum++; lab1_if();  }
    break;

  case 35:
#line 123 "project.y"
    {lab2_if(); }
    break;

  case 37:
#line 124 "project.y"
    {lab2_if(); }
    break;

  case 39:
#line 125 "project.y"
    {lab3_if();}
    break;

  case 46:
#line 135 "project.y"
    {flag=1; ttemp=1; push((yyvsp[(1) - (1)].st));}
    break;

  case 47:
#line 136 "project.y"
    {flag=1; push((yyvsp[(1) - (1)].st));}
    break;

  case 48:
#line 137 "project.y"
    {yyerrok;}
    break;

  case 56:
#line 155 "project.y"
    {push(yytext); }
    break;

  case 58:
#line 156 "project.y"
    {push(yytext);}
    break;

  case 63:
#line 167 "project.y"
    {strcpy(data,"-");}
    break;

  case 68:
#line 179 "project.y"
    {if(wcount==1){push((yyvsp[(1) - (5)].st));char y[100]; 									char str[10];strcpy(y,"t");sprintf(str, "%d", tnum);
									strcat(y,str);push("=");push (y); codegen_assign(); }
									else {char y[100];char str[10];strcpy(y,"t");
									sprintf(str, "%d", tnum);strcat(y,str);
									push((yyvsp[(1) - (5)].st));push("="); char x[2024]; 
									snprintf (x, sizeof(2024), "%d",(yyvsp[(3) - (5)].ival)); push(y);codegen_assign();}if(type_name((yyvsp[(3) - (5)].ival))=="int"){char x[2024];
									snprintf (x, sizeof(2024), "%d",(yyvsp[(3) - (5)].ival));s_update(x,(yyvsp[(1) - (5)].st),bal_brack);} }
    break;

  case 69:
#line 186 "project.y"
    {tcount=0;if(wcount==1){ push((yyvsp[(1) - (4)].st));char y[100];char str[10];strcpy(y,"t");sprintf(str, "%d", tnum);strcat(y,str);push("=");push(y);codegen_assign(); }else {char y[100];char str[10]; strcpy(y,"t");sprintf(str, "%d", tnum);strcat(y,str);push((yyvsp[(1) - (4)].st));push("="); char x[2024]; 
									snprintf (x, sizeof(2024), "%d",(yyvsp[(3) - (4)].ival)); push(y);codegen_assign();} if(type_name((yyvsp[(3) - (4)].ival))=="int"){char x[2024];snprintf (x, sizeof(2024), "%d",(yyvsp[(3) - (4)].ival));s_update(x,(yyvsp[(1) - (4)].st),bal_brack);} }
    break;

  case 70:
#line 190 "project.y"
    { 
										codegen();	
									  (yyval.ival)=((yyvsp[(1) - (3)].ival))+((yyvsp[(3) - (3)].ival)); }
    break;

  case 71:
#line 193 "project.y"
    { codegen(); (yyval.ival)=(yyvsp[(1) - (3)].ival)-(yyvsp[(3) - (3)].ival);}
    break;

  case 72:
#line 194 "project.y"
    {(yyval.ival)=(yyvsp[(1) - (1)].ival);}
    break;

  case 73:
#line 197 "project.y"
    { codegen(); (yyval.ival)=(yyvsp[(1) - (3)].ival)*atoi((yyvsp[(3) - (3)].st));}
    break;

  case 74:
#line 198 "project.y"
    { codegen();  if (atoi((yyvsp[(3) - (3)].st))!=0){(yyval.ival) = (yyvsp[(1) - (3)].ival)/atoi((yyvsp[(3) - (3)].st));} else {printf("Error: divide by Zero");}}
    break;

  case 75:
#line 199 "project.y"
    { codegen(); if (atoi((yyvsp[(3) - (3)].st))!=0){(yyval.ival) = (yyvsp[(1) - (3)].ival)%atoi((yyvsp[(3) - (3)].st));} else {printf("Error: Divided by Zero");}}
    break;

  case 76:
#line 200 "project.y"
    {(yyval.ival)=atoi((yyvsp[(1) - (1)].st));}
    break;

  case 77:
#line 204 "project.y"
    { push((yyvsp[(1) - (1)].st)); 
										int t=extract_value((yyvsp[(1) - (1)].st),bal_brack);
										char j[2024];
										snprintf(j, sizeof(2024), "%d",t);strcpy((yyval.st),j);s_update(j,(yyvsp[(1) - (1)].st),bal_brack);}
    break;

  case 78:
#line 208 "project.y"
    { char j[2024];
											snprintf(j, sizeof(2024), "%d",(yyvsp[(1) - (1)].ival));strcpy((yyval.st),j); push(j);}
    break;

  case 79:
#line 211 "project.y"
    {push((yyvsp[(1) - (1)].st));strcpy((yyval.st),(yyvsp[(1) - (1)].st));s_update((yyvsp[(1) - (1)].st),new_var,bal_brack);}
    break;

  case 80:
#line 212 "project.y"
    {push((yyvsp[(1) - (1)].st));strcpy((yyval.st),(yyvsp[(1) - (1)].st));s_update((yyvsp[(1) - (1)].st),new_var,bal_brack);}
    break;

  case 81:
#line 213 "project.y"
    {char j[2024];
										snprintf(j, sizeof(2024), "%d",(yyvsp[(2) - (3)].ival));strcpy((yyval.st),j);}
    break;


/* Line 1267 of yacc.c.  */
#line 1808 "y.tab.c"
      default: break;
    }
  YY_SYMBOL_PRINT ("-> $$ =", yyr1[yyn], &yyval, &yyloc);

  YYPOPSTACK (yylen);
  yylen = 0;
  YY_STACK_PRINT (yyss, yyssp);

  *++yyvsp = yyval;


  /* Now `shift' the result of the reduction.  Determine what state
     that goes to, based on the state we popped back to and the rule
     number reduced by.  */

  yyn = yyr1[yyn];

  yystate = yypgoto[yyn - YYNTOKENS] + *yyssp;
  if (0 <= yystate && yystate <= YYLAST && yycheck[yystate] == *yyssp)
    yystate = yytable[yystate];
  else
    yystate = yydefgoto[yyn - YYNTOKENS];

  goto yynewstate;


/*------------------------------------.
| yyerrlab -- here on detecting error |
`------------------------------------*/
yyerrlab:
  /* If not already recovering from an error, report this error.  */
  if (!yyerrstatus)
    {
      ++yynerrs;
#if ! YYERROR_VERBOSE
      yyerror (YY_("syntax error"));
#else
      {
	YYSIZE_T yysize = yysyntax_error (0, yystate, yychar);
	if (yymsg_alloc < yysize && yymsg_alloc < YYSTACK_ALLOC_MAXIMUM)
	  {
	    YYSIZE_T yyalloc = 2 * yysize;
	    if (! (yysize <= yyalloc && yyalloc <= YYSTACK_ALLOC_MAXIMUM))
	      yyalloc = YYSTACK_ALLOC_MAXIMUM;
	    if (yymsg != yymsgbuf)
	      YYSTACK_FREE (yymsg);
	    yymsg = (char *) YYSTACK_ALLOC (yyalloc);
	    if (yymsg)
	      yymsg_alloc = yyalloc;
	    else
	      {
		yymsg = yymsgbuf;
		yymsg_alloc = sizeof yymsgbuf;
	      }
	  }

	if (0 < yysize && yysize <= yymsg_alloc)
	  {
	    (void) yysyntax_error (yymsg, yystate, yychar);
	    yyerror (yymsg);
	  }
	else
	  {
	    yyerror (YY_("syntax error"));
	    if (yysize != 0)
	      goto yyexhaustedlab;
	  }
      }
#endif
    }



  if (yyerrstatus == 3)
    {
      /* If just tried and failed to reuse look-ahead token after an
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

  /* Else will try to reuse look-ahead token after shifting the error
     token.  */
  goto yyerrlab1;


/*---------------------------------------------------.
| yyerrorlab -- error raised explicitly by YYERROR.  |
`---------------------------------------------------*/
yyerrorlab:

  /* Pacify compilers like GCC when the user code never invokes
     YYERROR and the label yyerrorlab therefore never appears in user
     code.  */
  if (/*CONSTCOND*/ 0)
     goto yyerrorlab;

  /* Do not reclaim the symbols of the rule which action triggered
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
  yyerrstatus = 3;	/* Each real token shifted decrements this.  */

  for (;;)
    {
      yyn = yypact[yystate];
      if (yyn != YYPACT_NINF)
	{
	  yyn += YYTERROR;
	  if (0 <= yyn && yyn <= YYLAST && yycheck[yyn] == YYTERROR)
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
		  yystos[yystate], yyvsp);
      YYPOPSTACK (1);
      yystate = *yyssp;
      YY_STACK_PRINT (yyss, yyssp);
    }

  if (yyn == YYFINAL)
    YYACCEPT;

  *++yyvsp = yylval;


  /* Shift the error token.  */
  YY_SYMBOL_PRINT ("Shifting", yystos[yyn], yyvsp, yylsp);

  yystate = yyn;
  goto yynewstate;


/*-------------------------------------.
| yyacceptlab -- YYACCEPT comes here.  |
`-------------------------------------*/
yyacceptlab:
  yyresult = 0;
  goto yyreturn;

/*-----------------------------------.
| yyabortlab -- YYABORT comes here.  |
`-----------------------------------*/
yyabortlab:
  yyresult = 1;
  goto yyreturn;

#ifndef yyoverflow
/*-------------------------------------------------.
| yyexhaustedlab -- memory exhaustion comes here.  |
`-------------------------------------------------*/
yyexhaustedlab:
  yyerror (YY_("memory exhausted"));
  yyresult = 2;
  /* Fall through.  */
#endif

yyreturn:
  if (yychar != YYEOF && yychar != YYEMPTY)
     yydestruct ("Cleanup: discarding lookahead",
		 yytoken, &yylval);
  /* Do not reclaim the symbols of the rule which action triggered
     this YYABORT or YYACCEPT.  */
  YYPOPSTACK (yylen);
  YY_STACK_PRINT (yyss, yyssp);
  while (yyssp != yyss)
    {
      yydestruct ("Cleanup: popping",
		  yystos[*yyssp], yyvsp);
      YYPOPSTACK (1);
    }
#ifndef yyoverflow
  if (yyss != yyssa)
    YYSTACK_FREE (yyss);
#endif
#if YYERROR_VERBOSE
  if (yymsg != yymsgbuf)
    YYSTACK_FREE (yymsg);
#endif
  /* Make sure YYID is used.  */
  return YYID (yyresult);
}


#line 221 "project.y"


void push(char s[2024])
{
	strcpy(st[++top],s);
}

void codegen()
 {	
	 char str[10];
	 strcpy(temp,"t");
	 sprintf(str, "%d", tnum);
	 strcat(temp,str);
	 if(flag==1)  
	 {
	 fprintf(F1,"%s = %s \n",temp,st[top]);
	 tcount=0;
	 strcpy(st[top],temp);
	 flag=0;
	 }
	else if(tcount>1)
	{
	 fprintf(F1,"%s = %s %s %s\n",temp,st[top-3],st[top-2],st[top-1]);
	 tcount--;
	 top-=2;
	 strcpy(st[top-1],temp);
	 tnum++;
	}
	else
	{
	 fprintf(F1,"%s = %s %s %s\n",temp,st[top-2],st[top-1],st[top]);
	 top-=2;
	 strcpy(st[top],temp);
	
	}
	
	
		

	 //top-=2;
	 //strcpy(st[top],temp);
	 
	  //printf(" \n plus:%s\n",st[top-1]);
	
	 //push(temp);
	 //printf("%d",i_[0]);
 }
void codegen_assign()
 {	
	
	 fprintf(F1,"%s = %s\n",st[top-2],st[top-3]);
	 top-=2;
	 tnum++;	
	 
	
	
	 
 }
void lab1()
{	
	start=lnum;
	fprintf(F1,"L%d: \n",lnum);
	lnum++;
	
}

void lab2()
{	
	 char str[10];
	 strcpy(temp,"t");
	 sprintf(str, "%d", tnum);
	 strcat(temp,str);
	 fprintf(F1,"%s = not %s\n",temp,st[top]);
	 fprintf(F1,"if %s goto L%d\n",temp,lnum);
	 tnum++;
 }

void lab3()
{
	
	fprintf(F1,"goto L%d \n",start);
	fprintf(F1,"L%d: \n",lnum);
}
void lab1_if()
{

	 //lnum_if++;
	 char str[10];
	 strcpy(temp,"t");
	 sprintf(str, "%d", tnum);
	 strcat(temp,str);
	 fprintf(F1,"%s = not %s\n",temp,st[top]);
	 if(lnum==1)
	 fprintf(F1,"if %s goto L%d\n",temp,lnum++);
	 else
	 fprintf(F1,"if %s goto L%d\n",temp,++lnum);
	 tnum++;
	 label[++ltop]=lnum;
}

void lab2_if()
{
	int x;
	//lnum_if++;
	x=label[ltop--];
	if(lnum!=2)
	{
	lnum++;
	fprintf(F1,"goto L%d\n",lnum);
	fprintf(F1,"L%d: \n",x);
	}
	else
	{
	fprintf(F1,"goto L%d\n",lnum++);
	fprintf(F1,"L%d: \n",--x);
	}
	label[++ltop]=lnum;
	
}

void lab3_if()
{
	int y;
	y=label[ltop--];
	if(lnum==3)
	fprintf(F1,"L%d: \n",--y);
	else
	fprintf(F1,"L%d: \n",y);
}



int main()
{
    F1= fopen("icg.txt","w");
    printf("\nAfter Removal of Multi-line and Single-line  Comments:");
    printf("\n--------------------------------------------------------------------------------------------------------\n");
    yyparse();
    FILE *ftpr= fopen("sample.txt","w");
    
    printf("\n--------------------------------------------------------------------------------------------------------\n");
    if(success)
    	printf("\n\t\t\t\t\tParsing Successful!\n\n");
    else
    	{
    	if(error_count==1)
    	printf("\n\t\t\t\t\t%d Error Generated!\n\n",error_count);
    	else
    	printf("\n\t\t\t\t\t%d Errors Generated!\n\n",error_count);
    	}
			int i = 0;
		printf("--------------------------------------------------------------------------------------------------------\n");

		printf("Semantic Errors: \n");
		int count=0;
		for(i = 0; i < tcnt; i ++)
		{
			if(symtab[i].tok_num != 0)
				{
				//printf("datatype:%s value:%s\n",symtab[i].datatype,symtab[i].cvalue);
				if(strcmp(symtab[i].datatype,"int")==0)
				{
					if(symtab[i].cvalue[0]=='\0')
					{
					//printf("null chararcter\n");
					}
					else
					for (int j =0;j<strlen(symtab[i].cvalue);j++)
					{
					//printf("%c\n",)
						if(isalpha(symtab[i].cvalue[j]))
						{
						printf("invalid datatype %s for variable %s\n",symtab[i].datatype,symtab[i].symbol);
						count++;
						break;
						}
					}
				}
				if(strcmp(symtab[i].datatype,"boolean")==0)
				{
				if(strcmp(symtab[i].cvalue,"true")!=0 && strcmp(symtab[i].cvalue,"false")!=0)
				{
				printf("invalid datatype %s for variable %s\n",symtab[i].datatype,symtab[i].symbol);
				count++;
				}
				}
				
			}
				
		}
		for(i = 0; i < tcnt; i ++)
		{
			if(strcmp(symtab[i].datatype,"-")==0)
			{
			printf("undeclared variable : %s\n",symtab[i].symbol);
			count++;
			}		
		}	
		if(count==0)
		{
		printf("0 semantic errors\n");
		}

		printf("--------------------------------------------------------------------------------------------------------;\n");

		printf("\n\t\t\t\t\tSYMBOL TABLE\n\n");
		printf("--------------------------------------------------------------------------------------------------------;\n");
		printf("  Scope_Num\t|\tDatatype\t|\tSymbol\t\t|\tLine Number\t|\tValue\t|\n");
		int c=0;
		printf("--------------------------------------------------------------------------------------------------------|\n");
		for(i = 0; i < tcnt; i ++)
		{
			if(symtab[i].tok_num != 0)
				{
				if(symtab[i].scope_num==0 || symtab[i].scope_num==1)
				{
				continue;
				}
			
					printf("%5d\t\t|\t%5s\t\t|\t%4s\t\t|\t%5d\t\t|\t%4s\t|\n",symtab[i].scope_num,symtab[i].datatype,symtab[i].symbol,symtab[i].lineno,symtab[i].cvalue);
			}
				
		}
		

		printf("--------------------------------------------------------------------------------------------------------;\n");
		printf("\nTotal number of tokens : %d\n",tcnt);
		printf("\n--------------------------------------------------------------------------------------------------------\n");

    return 0;
}

int yyerror(const char *msg)
{
	extern int yylineno;
	printf("Parsing Failed\nLine Number: %d %s\n",yylineno,msg);
	success = 0;
	error_count++;
	return 0;
}

