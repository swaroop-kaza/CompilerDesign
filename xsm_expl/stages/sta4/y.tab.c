/* A Bison parser, made by GNU Bison 3.0.4.  */

/* Bison implementation for Yacc-like parsers in C

   Copyright (C) 1984, 1989-1990, 2000-2015 Free Software Foundation, Inc.

   This program is free software: you can redistribute it and/or modify
   it under the terms of the GNU General Public License as published by
   the Free Software Foundation, either version 3 of the License, or
   (at your option) any later version.

   This program is distributed in the hope that it will be useful,
   but WITHOUT ANY WARRANTY; without even the implied warranty of
   MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
   GNU General Public License for more details.

   You should have received a copy of the GNU General Public License
   along with this program.  If not, see <http://www.gnu.org/licenses/>.  */

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
#define YYBISON_VERSION "3.0.4"

/* Skeleton name.  */
#define YYSKELETON_NAME "yacc.c"

/* Pure parsers.  */
#define YYPURE 0

/* Push parsers.  */
#define YYPUSH 0

/* Pull parsers.  */
#define YYPULL 1




/* Copy the first part of user declarations.  */
#line 1 "1.a.dec.y" /* yacc.c:339  */

	#include <stdio.h>
	#include <stdlib.h>
	#include <string.h>

	#define YYSTYPE tnode *

	#include "1.c.dec.h"
	#include "1.d.dec.c"

	#include "1.e.symbolTable.h"
	#include "1.f.symbolTable.c"

	#include "1.g.codegen.c"

	int yylex(void);
	void yyerror(char const *s);

	FILE *yyin,*targetFile;
	int reg,type;

#line 88 "y.tab.c" /* yacc.c:339  */

# ifndef YY_NULLPTR
#  if defined __cplusplus && 201103L <= __cplusplus
#   define YY_NULLPTR nullptr
#  else
#   define YY_NULLPTR 0
#  endif
# endif

/* Enabling verbose error messages.  */
#ifdef YYERROR_VERBOSE
# undef YYERROR_VERBOSE
# define YYERROR_VERBOSE 1
#else
# define YYERROR_VERBOSE 0
#endif

/* In a future release of Bison, this section will be replaced
   by #include "y.tab.h".  */
#ifndef YY_YY_Y_TAB_H_INCLUDED
# define YY_YY_Y_TAB_H_INCLUDED
/* Debug traces.  */
#ifndef YYDEBUG
# define YYDEBUG 0
#endif
#if YYDEBUG
extern int yydebug;
#endif

/* Token type.  */
#ifndef YYTOKENTYPE
# define YYTOKENTYPE
  enum yytokentype
  {
    NUM = 258,
    ID = 259,
    PLUS = 260,
    MINUS = 261,
    MUL = 262,
    DIV = 263,
    START = 264,
    END = 265,
    NL = 266,
    READ = 267,
    WRITE = 268,
    IF = 269,
    THEN = 270,
    ELSE = 271,
    ENDIF = 272,
    WHILE = 273,
    DO = 274,
    ENDWHILE = 275,
    LT = 276,
    LE = 277,
    GT = 278,
    GE = 279,
    EQ = 280,
    NE = 281,
    INC = 282,
    DEC = 283,
    BREAK = 284,
    CNTU = 285,
    REPEAT = 286,
    UNTIL = 287,
    STRING = 288,
    DECL = 289,
    ENDDECL = 290,
    INTG = 291,
    STR = 292,
    POINTER = 293
  };
#endif
/* Tokens.  */
#define NUM 258
#define ID 259
#define PLUS 260
#define MINUS 261
#define MUL 262
#define DIV 263
#define START 264
#define END 265
#define NL 266
#define READ 267
#define WRITE 268
#define IF 269
#define THEN 270
#define ELSE 271
#define ENDIF 272
#define WHILE 273
#define DO 274
#define ENDWHILE 275
#define LT 276
#define LE 277
#define GT 278
#define GE 279
#define EQ 280
#define NE 281
#define INC 282
#define DEC 283
#define BREAK 284
#define CNTU 285
#define REPEAT 286
#define UNTIL 287
#define STRING 288
#define DECL 289
#define ENDDECL 290
#define INTG 291
#define STR 292
#define POINTER 293

/* Value type.  */
#if ! defined YYSTYPE && ! defined YYSTYPE_IS_DECLARED
typedef int YYSTYPE;
# define YYSTYPE_IS_TRIVIAL 1
# define YYSTYPE_IS_DECLARED 1
#endif


extern YYSTYPE yylval;

int yyparse (void);

#endif /* !YY_YY_Y_TAB_H_INCLUDED  */

/* Copy the second part of user declarations.  */

#line 215 "y.tab.c" /* yacc.c:358  */

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
#else
typedef signed char yytype_int8;
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
# elif ! defined YYSIZE_T
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
#   define YY_(Msgid) dgettext ("bison-runtime", Msgid)
#  endif
# endif
# ifndef YY_
#  define YY_(Msgid) Msgid
# endif
#endif

#ifndef YY_ATTRIBUTE
# if (defined __GNUC__                                               \
      && (2 < __GNUC__ || (__GNUC__ == 2 && 96 <= __GNUC_MINOR__)))  \
     || defined __SUNPRO_C && 0x5110 <= __SUNPRO_C
#  define YY_ATTRIBUTE(Spec) __attribute__(Spec)
# else
#  define YY_ATTRIBUTE(Spec) /* empty */
# endif
#endif

#ifndef YY_ATTRIBUTE_PURE
# define YY_ATTRIBUTE_PURE   YY_ATTRIBUTE ((__pure__))
#endif

#ifndef YY_ATTRIBUTE_UNUSED
# define YY_ATTRIBUTE_UNUSED YY_ATTRIBUTE ((__unused__))
#endif

#if !defined _Noreturn \
     && (!defined __STDC_VERSION__ || __STDC_VERSION__ < 201112)
# if defined _MSC_VER && 1200 <= _MSC_VER
#  define _Noreturn __declspec (noreturn)
# else
#  define _Noreturn YY_ATTRIBUTE ((__noreturn__))
# endif
#endif

/* Suppress unused-variable warnings by "using" E.  */
#if ! defined lint || defined __GNUC__
# define YYUSE(E) ((void) (E))
#else
# define YYUSE(E) /* empty */
#endif

#if defined __GNUC__ && 407 <= __GNUC__ * 100 + __GNUC_MINOR__
/* Suppress an incorrect diagnostic about yylval being uninitialized.  */
# define YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN \
    _Pragma ("GCC diagnostic push") \
    _Pragma ("GCC diagnostic ignored \"-Wuninitialized\"")\
    _Pragma ("GCC diagnostic ignored \"-Wmaybe-uninitialized\"")
# define YY_IGNORE_MAYBE_UNINITIALIZED_END \
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
#endif /* ! defined yyoverflow || YYERROR_VERBOSE */


#if (! defined yyoverflow \
     && (! defined __cplusplus \
         || (defined YYSTYPE_IS_TRIVIAL && YYSTYPE_IS_TRIVIAL)))

/* A type that is properly aligned for any stack member.  */
union yyalloc
{
  yytype_int16 yyss_alloc;
  YYSTYPE yyvs_alloc;
};

/* The size of the maximum gap between one aligned stack and the next.  */
# define YYSTACK_GAP_MAXIMUM (sizeof (union yyalloc) - 1)

/* The size of an array large to enough to hold all stacks, each with
   N elements.  */
# define YYSTACK_BYTES(N) \
     ((N) * (sizeof (yytype_int16) + sizeof (YYSTYPE)) \
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
        YYSIZE_T yynewbytes;                                            \
        YYCOPY (&yyptr->Stack_alloc, Stack, yysize);                    \
        Stack = &yyptr->Stack_alloc;                                    \
        yynewbytes = yystacksize * sizeof (*Stack) + YYSTACK_GAP_MAXIMUM; \
        yyptr += yynewbytes / sizeof (*yyptr);                          \
      }                                                                 \
    while (0)

#endif

#if defined YYCOPY_NEEDED && YYCOPY_NEEDED
/* Copy COUNT objects from SRC to DST.  The source and destination do
   not overlap.  */
# ifndef YYCOPY
#  if defined __GNUC__ && 1 < __GNUC__
#   define YYCOPY(Dst, Src, Count) \
      __builtin_memcpy (Dst, Src, (Count) * sizeof (*(Src)))
#  else
#   define YYCOPY(Dst, Src, Count)              \
      do                                        \
        {                                       \
          YYSIZE_T yyi;                         \
          for (yyi = 0; yyi < (Count); yyi++)   \
            (Dst)[yyi] = (Src)[yyi];            \
        }                                       \
      while (0)
#  endif
# endif
#endif /* !YYCOPY_NEEDED */

/* YYFINAL -- State number of the termination state.  */
#define YYFINAL  10
/* YYLAST -- Last index in YYTABLE.  */
#define YYLAST   508

/* YYNTOKENS -- Number of terminals.  */
#define YYNTOKENS  47
/* YYNNTS -- Number of nonterminals.  */
#define YYNNTS  16
/* YYNRULES -- Number of rules.  */
#define YYNRULES  59
/* YYNSTATES -- Number of states.  */
#define YYNSTATES  163

/* YYTRANSLATE[YYX] -- Symbol number corresponding to YYX as returned
   by yylex, with out-of-bounds checking.  */
#define YYUNDEFTOK  2
#define YYMAXUTOK   293

#define YYTRANSLATE(YYX)                                                \
  ((unsigned int) (YYX) <= YYMAXUTOK ? yytranslate[YYX] : YYUNDEFTOK)

/* YYTRANSLATE[TOKEN-NUM] -- Symbol number corresponding to TOKEN-NUM
   as returned by yylex, without out-of-bounds checking.  */
static const yytype_uint8 yytranslate[] =
{
       0,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,    45,     2,
      40,    41,     2,     2,    46,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,    39,
       2,    44,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,    42,     2,    43,     2,     2,     2,     2,     2,     2,
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
      35,    36,    37,    38
};

#if YYDEBUG
  /* YYRLINE[YYN] -- Source line where rule number YYN was defined.  */
static const yytype_uint16 yyrline[] =
{
       0,    40,    40,    46,    47,    50,    51,    54,    55,    56,
      57,    58,    59,    60,    63,    78,    94,   116,   119,   143,
     167,   194,   220,   222,   226,   228,   229,   233,   234,   235,
     236,   237,   238,   239,   240,   241,   242,   243,   244,   245,
     246,   265,   289,   312,   343,   368,   369,   372,   373,   376,
     379,   380,   383,   384,   385,   386,   393,   401,   408,   415
};
#endif

#if YYDEBUG || YYERROR_VERBOSE || 0
/* YYTNAME[SYMBOL-NUM] -- String name of the symbol SYMBOL-NUM.
   First, the terminals, then, starting at YYNTOKENS, nonterminals.  */
static const char *const yytname[] =
{
  "$end", "error", "$undefined", "NUM", "ID", "PLUS", "MINUS", "MUL",
  "DIV", "START", "END", "NL", "READ", "WRITE", "IF", "THEN", "ELSE",
  "ENDIF", "WHILE", "DO", "ENDWHILE", "LT", "LE", "GT", "GE", "EQ", "NE",
  "INC", "DEC", "BREAK", "CNTU", "REPEAT", "UNTIL", "STRING", "DECL",
  "ENDDECL", "INTG", "STR", "POINTER", "';'", "'('", "')'", "'['", "']'",
  "'='", "'&'", "','", "$accept", "program", "main", "Slist", "Stmt",
  "InputStmt", "OutputStmt", "AsgStmt", "IfStmt", "WhileStmt", "expr",
  "Declarations", "DeclList", "Decl", "Type", "VarList", YY_NULLPTR
};
#endif

# ifdef YYPRINT
/* YYTOKNUM[NUM] -- (External) token number corresponding to the
   (internal) symbol number NUM (which must be that of a token).  */
static const yytype_uint16 yytoknum[] =
{
       0,   256,   257,   258,   259,   260,   261,   262,   263,   264,
     265,   266,   267,   268,   269,   270,   271,   272,   273,   274,
     275,   276,   277,   278,   279,   280,   281,   282,   283,   284,
     285,   286,   287,   288,   289,   290,   291,   292,   293,    59,
      40,    41,    91,    93,    61,    38,    44
};
# endif

#define YYPACT_NINF -37

#define yypact_value_is_default(Yystate) \
  (!!((Yystate) == (-37)))

#define YYTABLE_NINF -1

#define yytable_value_is_error(Yytable_value) \
  (!!((Yytable_value) == (-1)))

  /* YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
     STATE-NUM.  */
static const yytype_int16 yypact[] =
{
     -32,     6,    30,    50,   -37,   -37,   -37,    19,   -37,     8,
     -37,   369,   -37,   -37,   -37,    18,    57,   -33,   -26,    71,
      31,    36,    37,    40,    53,   457,    55,    56,   457,   397,
     -37,   -37,   -37,   -37,   -37,   -37,    95,   -37,   -37,    10,
      24,    24,    61,   -37,   102,    24,    24,    24,   477,   -37,
     -37,   320,    68,   -37,    65,    69,   106,   -37,    76,   115,
     -37,    24,   116,    60,   252,    24,   -34,   170,   180,   192,
      59,    81,   -37,    85,   125,   -37,    24,   -37,   202,   -37,
      24,    24,    24,    24,    24,    24,    24,    24,    24,    24,
     -18,   -37,   261,    96,    24,    97,   122,   119,    24,    24,
     142,   107,    66,   -37,    13,    13,   340,   340,   368,   368,
     368,   368,   368,   368,    24,    24,   -37,   -37,   108,   -37,
     457,   457,   224,   230,   113,   117,   132,   118,   287,    -9,
     341,   417,   -16,   121,   -37,   154,    24,   114,   -37,   140,
      24,   457,   143,   144,   -37,   -37,   137,   141,    24,   -37,
     147,   437,   -37,   -37,   -37,   -37,   296,   148,   173,   -37,
     181,   -37,   -37
};

  /* YYDEFACT[STATE-NUM] -- Default reduction number in state STATE-NUM.
     Performed when YYTABLE does not specify something else to do.  Zero
     means the default is an error.  */
static const yytype_uint8 yydefact[] =
{
       0,     0,     0,     0,    46,    50,    51,     0,    48,     0,
       1,     0,     2,    45,    47,    54,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       6,     7,     8,     9,    10,    11,     0,    59,    49,     0,
       0,     0,     0,     4,     0,     0,     0,     0,     0,    12,
      13,     0,     0,     5,     0,    52,     0,    32,    40,     0,
      33,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     3,    58,     0,    53,     0,    43,     0,    44,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,    18,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,    31,    27,    28,    29,    30,    34,    35,
      36,    37,    38,    39,     0,     0,    21,    14,     0,    17,
       0,     0,     0,     0,     0,    55,    41,     0,     0,     0,
       0,     0,     0,     0,    57,     0,     0,     0,    19,     0,
       0,     0,     0,     0,    25,    26,     0,     0,     0,    15,
       0,     0,    23,    24,    56,    42,     0,     0,     0,    20,
       0,    22,    16
};

  /* YYPGOTO[NTERM-NUM].  */
static const yytype_int16 yypgoto[] =
{
     -37,   -37,   -37,   -24,   -29,   -37,   -37,   -37,   -37,   -37,
     -36,   -37,   -37,   174,   -37,   -37
};

  /* YYDEFGOTO[NTERM-NUM].  */
static const yytype_int8 yydefgoto[] =
{
      -1,     2,    12,    29,    30,    31,    32,    33,    34,    35,
      63,     3,     7,     8,     9,    17
};

  /* YYTABLE[YYPACT[STATE-NUM]] -- What to do in state STATE-NUM.  If
     positive, shift that token.  If negative, reduce the rule whose
     number is the opposite.  If YYTABLE_NINF, syntax error.  */
static const yytype_int16 yytable[] =
{
      53,    48,     1,   121,    51,    64,    38,    93,    94,    67,
      68,    69,    15,    39,    55,    16,    40,    56,    41,    53,
      82,    83,    53,   144,   114,    78,   115,    57,    58,    92,
      10,    59,   139,   140,    84,    85,    86,    87,    88,    89,
     102,     4,     5,     6,   104,   105,   106,   107,   108,   109,
     110,   111,   112,   113,    13,     5,     6,    60,   118,    11,
      36,    37,   122,   123,    61,    80,    81,    82,    83,    62,
      43,    80,    81,    82,    83,    42,    44,    45,   127,   128,
      46,    84,    85,    86,    87,    88,    89,    84,    85,    86,
      87,    88,    89,    47,    49,    50,   130,   131,    54,    98,
     147,    53,    53,    90,   150,    65,    66,    72,    73,   126,
      75,    74,   156,    80,    81,    82,    83,   151,    76,    77,
      79,    99,    53,    80,    81,    82,    83,   100,   101,    84,
      85,    86,    87,    88,    89,   117,   119,   120,   121,    84,
      85,    86,    87,    88,    89,   124,    80,    81,    82,    83,
     125,   129,    80,    81,    82,    83,   134,   146,   148,   135,
     145,   137,    84,    85,    86,    87,    88,    89,    84,    85,
      86,    87,    88,    89,   136,    80,    81,    82,    83,   149,
     154,    14,   152,   153,   155,    80,    81,    82,    83,   160,
     157,    84,    85,    86,    87,    88,    89,    80,    81,    82,
      83,    84,    85,    86,    87,    88,    89,    80,    81,    82,
      83,    95,   161,    84,    85,    86,    87,    88,    89,     0,
     162,    96,     0,    84,    85,    86,    87,    88,    89,    80,
      81,    82,    83,    97,     0,    80,    81,    82,    83,     0,
       0,     0,     0,   103,     0,    84,    85,    86,    87,    88,
      89,    84,    85,    86,    87,    88,    89,    80,    81,    82,
      83,     0,     0,     0,     0,   132,    80,    81,    82,    83,
       0,   133,     0,    84,    85,    86,    87,    88,    89,     0,
       0,     0,    84,    85,    86,    87,    88,    89,     0,     0,
       0,    91,    80,    81,    82,    83,     0,     0,     0,     0,
     116,    80,    81,    82,    83,     0,     0,     0,    84,    85,
      86,    87,    88,    89,     0,     0,     0,    84,    85,    86,
      87,    88,    89,     0,    18,     0,   138,    19,     0,     0,
       0,     0,    21,    22,    23,   159,     0,     0,    24,    25,
       0,     0,     0,     0,     0,    18,     0,     0,    19,    26,
      27,    28,    71,    21,    22,    23,     0,   141,   142,    24,
      25,    84,    85,    86,    87,    88,    89,     0,     0,     0,
      26,    27,    28,    18,     0,     0,    19,     0,     0,    20,
       0,    21,    22,    23,     0,     0,     0,    24,    25,    -1,
      -1,    -1,    -1,    -1,    -1,     0,     0,     0,    26,    27,
      28,    18,     0,     0,    19,     0,     0,    52,     0,    21,
      22,    23,     0,     0,     0,    24,    25,     0,     0,     0,
       0,    18,     0,     0,    19,     0,    26,    27,    28,    21,
      22,    23,     0,     0,     0,    24,    25,   143,     0,     0,
       0,    18,     0,     0,    19,     0,    26,    27,    28,    21,
      22,    23,     0,     0,   158,    24,    25,     0,     0,     0,
       0,    18,     0,     0,    19,     0,    26,    27,    28,    21,
      22,    23,     0,     0,     0,    24,    25,     0,     0,     0,
       0,    18,     0,     0,    19,     0,    26,    27,    28,    21,
      22,    23,     0,     0,     0,    70,    25,     0,     0,     0,
       0,     0,     0,     0,     0,     0,    26,    27,    28
};

static const yytype_int16 yycheck[] =
{
      29,    25,    34,    19,    28,    41,    39,    41,    42,    45,
      46,    47,     4,    46,     4,     7,    42,     7,    44,    48,
       7,     8,    51,    39,    42,    61,    44,     3,     4,    65,
       0,     7,    41,    42,    21,    22,    23,    24,    25,    26,
      76,    35,    36,    37,    80,    81,    82,    83,    84,    85,
      86,    87,    88,    89,    35,    36,    37,    33,    94,     9,
      42,     4,    98,    99,    40,     5,     6,     7,     8,    45,
      39,     5,     6,     7,     8,     4,    40,    40,   114,   115,
      40,    21,    22,    23,    24,    25,    26,    21,    22,    23,
      24,    25,    26,    40,    39,    39,   120,   121,     3,    40,
     136,   130,   131,    43,   140,    44,     4,    39,    43,    43,
       4,    42,   148,     5,     6,     7,     8,   141,    42,     4,
       4,    40,   151,     5,     6,     7,     8,    42,     3,    21,
      22,    23,    24,    25,    26,    39,    39,    15,    19,    21,
      22,    23,    24,    25,    26,     3,     5,     6,     7,     8,
      43,    43,     5,     6,     7,     8,    43,     3,    44,    42,
      39,    43,    21,    22,    23,    24,    25,    26,    21,    22,
      23,    24,    25,    26,    42,     5,     6,     7,     8,    39,
      43,     7,    39,    39,    43,     5,     6,     7,     8,    41,
      43,    21,    22,    23,    24,    25,    26,     5,     6,     7,
       8,    21,    22,    23,    24,    25,    26,     5,     6,     7,
       8,    41,    39,    21,    22,    23,    24,    25,    26,    -1,
      39,    41,    -1,    21,    22,    23,    24,    25,    26,     5,
       6,     7,     8,    41,    -1,     5,     6,     7,     8,    -1,
      -1,    -1,    -1,    41,    -1,    21,    22,    23,    24,    25,
      26,    21,    22,    23,    24,    25,    26,     5,     6,     7,
       8,    -1,    -1,    -1,    -1,    41,     5,     6,     7,     8,
      -1,    41,    -1,    21,    22,    23,    24,    25,    26,    -1,
      -1,    -1,    21,    22,    23,    24,    25,    26,    -1,    -1,
      -1,    39,     5,     6,     7,     8,    -1,    -1,    -1,    -1,
      39,     5,     6,     7,     8,    -1,    -1,    -1,    21,    22,
      23,    24,    25,    26,    -1,    -1,    -1,    21,    22,    23,
      24,    25,    26,    -1,     4,    -1,    39,     7,    -1,    -1,
      -1,    -1,    12,    13,    14,    39,    -1,    -1,    18,    19,
      -1,    -1,    -1,    -1,    -1,     4,    -1,    -1,     7,    29,
      30,    31,    32,    12,    13,    14,    -1,    16,    17,    18,
      19,    21,    22,    23,    24,    25,    26,    -1,    -1,    -1,
      29,    30,    31,     4,    -1,    -1,     7,    -1,    -1,    10,
      -1,    12,    13,    14,    -1,    -1,    -1,    18,    19,    21,
      22,    23,    24,    25,    26,    -1,    -1,    -1,    29,    30,
      31,     4,    -1,    -1,     7,    -1,    -1,    10,    -1,    12,
      13,    14,    -1,    -1,    -1,    18,    19,    -1,    -1,    -1,
      -1,     4,    -1,    -1,     7,    -1,    29,    30,    31,    12,
      13,    14,    -1,    -1,    -1,    18,    19,    20,    -1,    -1,
      -1,     4,    -1,    -1,     7,    -1,    29,    30,    31,    12,
      13,    14,    -1,    -1,    17,    18,    19,    -1,    -1,    -1,
      -1,     4,    -1,    -1,     7,    -1,    29,    30,    31,    12,
      13,    14,    -1,    -1,    -1,    18,    19,    -1,    -1,    -1,
      -1,     4,    -1,    -1,     7,    -1,    29,    30,    31,    12,
      13,    14,    -1,    -1,    -1,    18,    19,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    29,    30,    31
};

  /* YYSTOS[STATE-NUM] -- The (internal number of the) accessing
     symbol of state STATE-NUM.  */
static const yytype_uint8 yystos[] =
{
       0,    34,    48,    58,    35,    36,    37,    59,    60,    61,
       0,     9,    49,    35,    60,     4,     7,    62,     4,     7,
      10,    12,    13,    14,    18,    19,    29,    30,    31,    50,
      51,    52,    53,    54,    55,    56,    42,     4,    39,    46,
      42,    44,     4,    39,    40,    40,    40,    40,    50,    39,
      39,    50,    10,    51,     3,     4,     7,     3,     4,     7,
      33,    40,    45,    57,    57,    44,     4,    57,    57,    57,
      18,    32,    39,    43,    42,     4,    42,     4,    57,     4,
       5,     6,     7,     8,    21,    22,    23,    24,    25,    26,
      43,    39,    57,    41,    42,    41,    41,    41,    40,    40,
      42,     3,    57,    41,    57,    57,    57,    57,    57,    57,
      57,    57,    57,    57,    42,    44,    39,    39,    57,    39,
      15,    19,    57,    57,     3,    43,    43,    57,    57,    43,
      50,    50,    41,    41,    43,    42,    42,    43,    39,    41,
      42,    16,    17,    20,    39,    39,     3,    57,    44,    39,
      57,    50,    39,    39,    43,    43,    57,    43,    17,    39,
      41,    39,    39
};

  /* YYR1[YYN] -- Symbol number of symbol that rule YYN derives.  */
static const yytype_uint8 yyr1[] =
{
       0,    47,    48,    49,    49,    50,    50,    51,    51,    51,
      51,    51,    51,    51,    52,    52,    52,    53,    54,    54,
      54,    54,    55,    55,    56,    56,    56,    57,    57,    57,
      57,    57,    57,    57,    57,    57,    57,    57,    57,    57,
      57,    57,    57,    57,    57,    58,    58,    59,    59,    60,
      61,    61,    62,    62,    62,    62,    62,    62,    62,    62
};

  /* YYR2[YYN] -- Number of symbols on the right hand side of rule YYN.  */
static const yytype_uint8 yyr2[] =
{
       0,     2,     2,     4,     3,     2,     1,     1,     1,     1,
       1,     1,     2,     2,     5,     8,    11,     5,     4,     7,
      10,     5,    10,     8,     8,     7,     7,     3,     3,     3,
       3,     3,     1,     1,     3,     3,     3,     3,     3,     3,
       1,     4,     7,     2,     2,     3,     2,     2,     1,     3,
       1,     1,     3,     4,     1,     6,     9,     7,     4,     2
};


#define yyerrok         (yyerrstatus = 0)
#define yyclearin       (yychar = YYEMPTY)
#define YYEMPTY         (-2)
#define YYEOF           0

#define YYACCEPT        goto yyacceptlab
#define YYABORT         goto yyabortlab
#define YYERROR         goto yyerrorlab


#define YYRECOVERING()  (!!yyerrstatus)

#define YYBACKUP(Token, Value)                                  \
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

/* Error token number */
#define YYTERROR        1
#define YYERRCODE       256



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

/* This macro is provided for backward compatibility. */
#ifndef YY_LOCATION_PRINT
# define YY_LOCATION_PRINT(File, Loc) ((void) 0)
#endif


# define YY_SYMBOL_PRINT(Title, Type, Value, Location)                    \
do {                                                                      \
  if (yydebug)                                                            \
    {                                                                     \
      YYFPRINTF (stderr, "%s ", Title);                                   \
      yy_symbol_print (stderr,                                            \
                  Type, Value); \
      YYFPRINTF (stderr, "\n");                                           \
    }                                                                     \
} while (0)


/*----------------------------------------.
| Print this symbol's value on YYOUTPUT.  |
`----------------------------------------*/

static void
yy_symbol_value_print (FILE *yyoutput, int yytype, YYSTYPE const * const yyvaluep)
{
  FILE *yyo = yyoutput;
  YYUSE (yyo);
  if (!yyvaluep)
    return;
# ifdef YYPRINT
  if (yytype < YYNTOKENS)
    YYPRINT (yyoutput, yytoknum[yytype], *yyvaluep);
# endif
  YYUSE (yytype);
}


/*--------------------------------.
| Print this symbol on YYOUTPUT.  |
`--------------------------------*/

static void
yy_symbol_print (FILE *yyoutput, int yytype, YYSTYPE const * const yyvaluep)
{
  YYFPRINTF (yyoutput, "%s %s (",
             yytype < YYNTOKENS ? "token" : "nterm", yytname[yytype]);

  yy_symbol_value_print (yyoutput, yytype, yyvaluep);
  YYFPRINTF (yyoutput, ")");
}

/*------------------------------------------------------------------.
| yy_stack_print -- Print the state stack from its BOTTOM up to its |
| TOP (included).                                                   |
`------------------------------------------------------------------*/

static void
yy_stack_print (yytype_int16 *yybottom, yytype_int16 *yytop)
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
yy_reduce_print (yytype_int16 *yyssp, YYSTYPE *yyvsp, int yyrule)
{
  unsigned long int yylno = yyrline[yyrule];
  int yynrhs = yyr2[yyrule];
  int yyi;
  YYFPRINTF (stderr, "Reducing stack by rule %d (line %lu):\n",
             yyrule - 1, yylno);
  /* The symbols being reduced.  */
  for (yyi = 0; yyi < yynrhs; yyi++)
    {
      YYFPRINTF (stderr, "   $%d = ", yyi + 1);
      yy_symbol_print (stderr,
                       yystos[yyssp[yyi + 1 - yynrhs]],
                       &(yyvsp[(yyi + 1) - (yynrhs)])
                                              );
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
# define YYDPRINTF(Args)
# define YY_SYMBOL_PRINT(Title, Type, Value, Location)
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


#if YYERROR_VERBOSE

# ifndef yystrlen
#  if defined __GLIBC__ && defined _STRING_H
#   define yystrlen strlen
#  else
/* Return the length of YYSTR.  */
static YYSIZE_T
yystrlen (const char *yystr)
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
static char *
yystpcpy (char *yydest, const char *yysrc)
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

/* Copy into *YYMSG, which is of size *YYMSG_ALLOC, an error message
   about the unexpected token YYTOKEN for the state stack whose top is
   YYSSP.

   Return 0 if *YYMSG was successfully written.  Return 1 if *YYMSG is
   not large enough to hold the message.  In that case, also set
   *YYMSG_ALLOC to the required number of bytes.  Return 2 if the
   required number of bytes is too large to store.  */
static int
yysyntax_error (YYSIZE_T *yymsg_alloc, char **yymsg,
                yytype_int16 *yyssp, int yytoken)
{
  YYSIZE_T yysize0 = yytnamerr (YY_NULLPTR, yytname[yytoken]);
  YYSIZE_T yysize = yysize0;
  enum { YYERROR_VERBOSE_ARGS_MAXIMUM = 5 };
  /* Internationalized format string. */
  const char *yyformat = YY_NULLPTR;
  /* Arguments of yyformat. */
  char const *yyarg[YYERROR_VERBOSE_ARGS_MAXIMUM];
  /* Number of reported tokens (one for the "unexpected", one per
     "expected"). */
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
  if (yytoken != YYEMPTY)
    {
      int yyn = yypact[*yyssp];
      yyarg[yycount++] = yytname[yytoken];
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
            if (yycheck[yyx + yyn] == yyx && yyx != YYTERROR
                && !yytable_value_is_error (yytable[yyx + yyn]))
              {
                if (yycount == YYERROR_VERBOSE_ARGS_MAXIMUM)
                  {
                    yycount = 1;
                    yysize = yysize0;
                    break;
                  }
                yyarg[yycount++] = yytname[yyx];
                {
                  YYSIZE_T yysize1 = yysize + yytnamerr (YY_NULLPTR, yytname[yyx]);
                  if (! (yysize <= yysize1
                         && yysize1 <= YYSTACK_ALLOC_MAXIMUM))
                    return 2;
                  yysize = yysize1;
                }
              }
        }
    }

  switch (yycount)
    {
# define YYCASE_(N, S)                      \
      case N:                               \
        yyformat = S;                       \
      break
      YYCASE_(0, YY_("syntax error"));
      YYCASE_(1, YY_("syntax error, unexpected %s"));
      YYCASE_(2, YY_("syntax error, unexpected %s, expecting %s"));
      YYCASE_(3, YY_("syntax error, unexpected %s, expecting %s or %s"));
      YYCASE_(4, YY_("syntax error, unexpected %s, expecting %s or %s or %s"));
      YYCASE_(5, YY_("syntax error, unexpected %s, expecting %s or %s or %s or %s"));
# undef YYCASE_
    }

  {
    YYSIZE_T yysize1 = yysize + yystrlen (yyformat);
    if (! (yysize <= yysize1 && yysize1 <= YYSTACK_ALLOC_MAXIMUM))
      return 2;
    yysize = yysize1;
  }

  if (*yymsg_alloc < yysize)
    {
      *yymsg_alloc = 2 * yysize;
      if (! (yysize <= *yymsg_alloc
             && *yymsg_alloc <= YYSTACK_ALLOC_MAXIMUM))
        *yymsg_alloc = YYSTACK_ALLOC_MAXIMUM;
      return 1;
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
          yyp += yytnamerr (yyp, yyarg[yyi++]);
          yyformat += 2;
        }
      else
        {
          yyp++;
          yyformat++;
        }
  }
  return 0;
}
#endif /* YYERROR_VERBOSE */

/*-----------------------------------------------.
| Release the memory associated to this symbol.  |
`-----------------------------------------------*/

static void
yydestruct (const char *yymsg, int yytype, YYSTYPE *yyvaluep)
{
  YYUSE (yyvaluep);
  if (!yymsg)
    yymsg = "Deleting";
  YY_SYMBOL_PRINT (yymsg, yytype, yyvaluep, yylocationp);

  YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
  YYUSE (yytype);
  YY_IGNORE_MAYBE_UNINITIALIZED_END
}




/* The lookahead symbol.  */
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
    int yystate;
    /* Number of tokens to shift before error messages enabled.  */
    int yyerrstatus;

    /* The stacks and their tools:
       'yyss': related to states.
       'yyvs': related to semantic values.

       Refer to the stacks through separate pointers, to allow yyoverflow
       to reallocate them elsewhere.  */

    /* The state stack.  */
    yytype_int16 yyssa[YYINITDEPTH];
    yytype_int16 *yyss;
    yytype_int16 *yyssp;

    /* The semantic value stack.  */
    YYSTYPE yyvsa[YYINITDEPTH];
    YYSTYPE *yyvs;
    YYSTYPE *yyvsp;

    YYSIZE_T yystacksize;

  int yyn;
  int yyresult;
  /* Lookahead token as an internal (translated) token number.  */
  int yytoken = 0;
  /* The variables used to return semantic value and location from the
     action routines.  */
  YYSTYPE yyval;

#if YYERROR_VERBOSE
  /* Buffer for error messages, and its allocated size.  */
  char yymsgbuf[128];
  char *yymsg = yymsgbuf;
  YYSIZE_T yymsg_alloc = sizeof yymsgbuf;
#endif

#define YYPOPSTACK(N)   (yyvsp -= (N), yyssp -= (N))

  /* The number of symbols on the RHS of the reduced rule.
     Keep to zero when no symbol should be popped.  */
  int yylen = 0;

  yyssp = yyss = yyssa;
  yyvsp = yyvs = yyvsa;
  yystacksize = YYINITDEPTH;

  YYDPRINTF ((stderr, "Starting parse\n"));

  yystate = 0;
  yyerrstatus = 0;
  yynerrs = 0;
  yychar = YYEMPTY; /* Cause a token to be read.  */
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
        YYSTACK_RELOCATE (yyss_alloc, yyss);
        YYSTACK_RELOCATE (yyvs_alloc, yyvs);
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

  /* YYCHAR is either YYEMPTY or YYEOF or a valid lookahead symbol.  */
  if (yychar == YYEMPTY)
    {
      YYDPRINTF ((stderr, "Reading a token: "));
      yychar = yylex ();
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

  /* Discard the shifted token.  */
  yychar = YYEMPTY;

  yystate = yyn;
  YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
  *++yyvsp = yylval;
  YY_IGNORE_MAYBE_UNINITIALIZED_END

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
        case 2:
#line 40 "1.a.dec.y" /* yacc.c:1646  */
    {
								generate((yyvsp[0]),targetFile);
								exit(1);
							}
#line 1462 "y.tab.c" /* yacc.c:1646  */
    break;

  case 3:
#line 46 "1.a.dec.y" /* yacc.c:1646  */
    { (yyval)=(yyvsp[-2]); }
#line 1468 "y.tab.c" /* yacc.c:1646  */
    break;

  case 4:
#line 47 "1.a.dec.y" /* yacc.c:1646  */
    {}
#line 1474 "y.tab.c" /* yacc.c:1646  */
    break;

  case 5:
#line 50 "1.a.dec.y" /* yacc.c:1646  */
    { (yyval)=createTree(0,nodetypeNULL,typenull,NULL,(yyvsp[-1]),(yyvsp[0]),NULL); }
#line 1480 "y.tab.c" /* yacc.c:1646  */
    break;

  case 6:
#line 51 "1.a.dec.y" /* yacc.c:1646  */
    { (yyval)=(yyvsp[0]); }
#line 1486 "y.tab.c" /* yacc.c:1646  */
    break;

  case 7:
#line 54 "1.a.dec.y" /* yacc.c:1646  */
    { (yyval)=(yyvsp[0]); }
#line 1492 "y.tab.c" /* yacc.c:1646  */
    break;

  case 8:
#line 55 "1.a.dec.y" /* yacc.c:1646  */
    { (yyval)=(yyvsp[0]); }
#line 1498 "y.tab.c" /* yacc.c:1646  */
    break;

  case 9:
#line 56 "1.a.dec.y" /* yacc.c:1646  */
    { (yyval)=(yyvsp[0]); }
#line 1504 "y.tab.c" /* yacc.c:1646  */
    break;

  case 10:
#line 57 "1.a.dec.y" /* yacc.c:1646  */
    { (yyval)=(yyvsp[0]); }
#line 1510 "y.tab.c" /* yacc.c:1646  */
    break;

  case 11:
#line 58 "1.a.dec.y" /* yacc.c:1646  */
    { (yyval)=(yyvsp[0]); }
#line 1516 "y.tab.c" /* yacc.c:1646  */
    break;

  case 12:
#line 59 "1.a.dec.y" /* yacc.c:1646  */
    { (yyval)=createTree(0,nodetypeBRK,typenull,NULL,NULL,NULL,NULL); }
#line 1522 "y.tab.c" /* yacc.c:1646  */
    break;

  case 13:
#line 60 "1.a.dec.y" /* yacc.c:1646  */
    { (yyval)=createTree(0,nodetypeCNTU,typenull,NULL,NULL,NULL,NULL); }
#line 1528 "y.tab.c" /* yacc.c:1646  */
    break;

  case 14:
#line 63 "1.a.dec.y" /* yacc.c:1646  */
    {
								tempST=LookUp((yyvsp[-2])->varname);

								if(tempST==NULL)
								{
									yyerror("undefined Variable");
								
									printf("%s\n",(yyvsp[-2])->varname );
									exit(1);
								}
								else 
									(yyvsp[-2])->Gentry=tempST;
									
								(yyval)=createTree(0,nodetypeREAD,typenull,NULL,(yyvsp[-2]),NULL,NULL);
							}
#line 1548 "y.tab.c" /* yacc.c:1646  */
    break;

  case 15:
#line 78 "1.a.dec.y" /* yacc.c:1646  */
    {
								tempST=LookUp((yyvsp[-5])->varname);
									
								if(tempST==NULL)
								{
									yyerror("undefined Variable");
									
									printf("%s\n",(yyvsp[-5])->varname );
									exit(1);
								}

								else 
									(yyvsp[-5])->Gentry=tempST;

								(yyval)=createTree(0,nodetypeARRREAD,typenull,NULL,(yyvsp[-5]),(yyvsp[-3]),NULL);
							}
#line 1569 "y.tab.c" /* yacc.c:1646  */
    break;

  case 16:
#line 95 "1.a.dec.y" /* yacc.c:1646  */
    {
								tempST=LookUp((yyvsp[-8])->varname);
								
								if(tempST==NULL)
								{
									yyerror("undefined Variable");
										
									printf("%s\n",(yyvsp[-8])->varname );
									exit(1);
								}

								else 
									(yyvsp[-8])->Gentry=tempST;

								struct tnode *temp=createTree(tempST->s2,nodetypeLEAF,typeint,NULL,NULL, NULL,NULL);
								(yyvsp[-6])=createTree(0,nodetypeMUL,typeint,NULL,(yyvsp[-6]),temp,NULL);
								(yyvsp[-6])=createTree(0,nodetypePLUS,typeint,NULL,(yyvsp[-6]),(yyvsp[-3]),NULL);
								(yyval)=createTree(0,nodetypeARRREAD,typenull,NULL,(yyvsp[-8]),(yyvsp[-6]),NULL);
							}
#line 1593 "y.tab.c" /* yacc.c:1646  */
    break;

  case 17:
#line 116 "1.a.dec.y" /* yacc.c:1646  */
    { (yyval)=createTree(0,nodetypeWRITE,typenull,NULL,(yyvsp[-2]),NULL,NULL); }
#line 1599 "y.tab.c" /* yacc.c:1646  */
    break;

  case 18:
#line 119 "1.a.dec.y" /* yacc.c:1646  */
    {
								tempST=LookUp((yyvsp[-3])->varname);
									
								if(tempST==NULL)
								{
									yyerror("undefined Variable");
							
									printf("%s\n",(yyvsp[-3])->varname );
									exit(1);
								}
				
								else 
								{
									(yyvsp[-3])->Gentry=tempST;
									
									if(tempST->type==typeint || tempST->type==typeintptr)
										(yyvsp[-3])->type=typeint;
									
									else if(tempST->type==typechar||tempST->type==typestrptr)
										(yyvsp[-3])->type=typechar;
								}
								
								(yyval)=createTree(0,nodetypeASGN,typenull,NULL,(yyvsp[-3]),(yyvsp[-1]),NULL);
							}
#line 1628 "y.tab.c" /* yacc.c:1646  */
    break;

  case 19:
#line 143 "1.a.dec.y" /* yacc.c:1646  */
    {
								tempST=LookUp((yyvsp[-6])->varname);

								if(tempST==NULL)
								{
									yyerror("undefined Variable");
									
									printf("%s\n",(yyvsp[-6])->varname );
									exit(1);
								}

								else 
								{
									(yyvsp[-6])->Gentry=tempST;
						
									if(tempST->type==typearrint)
										(yyvsp[-6])->type=typeint;
							
									else if(tempST->type==typestr)
										(yyvsp[-6])->type=typechar;
								}
								
								(yyval)=createTree(0,nodetypeARRASGN,typenull,NULL,(yyvsp[-6]),(yyvsp[-4]),(yyvsp[-1]));
							}
#line 1657 "y.tab.c" /* yacc.c:1646  */
    break;

  case 20:
#line 168 "1.a.dec.y" /* yacc.c:1646  */
    { 
								tempST=LookUp((yyvsp[-9])->varname);
						
								if(tempST==NULL)
								{
									yyerror("undefined Variable");

									printf("%s\n",(yyvsp[-9])->varname );
									exit(1);
								}
								
								else 
								{
									(yyvsp[-9])->Gentry=tempST;
									
									if(tempST->type==typearrint)
										(yyvsp[-9])->type=typeint;
									
									else if(tempST->type==typestr)
										(yyvsp[-9])->type=typechar;
								}
								struct tnode *temp=createTree(tempST->s2,nodetypeLEAF,typeint,NULL,NULL, NULL,NULL);
								(yyvsp[-7])=createTree(0,nodetypeMUL,typeint,NULL,(yyvsp[-7]),temp,NULL);
								(yyvsp[-7])=createTree(0,nodetypePLUS,typeint,NULL,(yyvsp[-7]),(yyvsp[-4]),NULL);
								(yyval)=createTree(0,nodetypeARRASGN,typenull,NULL,(yyvsp[-9]),(yyvsp[-7]),(yyvsp[-1])); 
							}
#line 1688 "y.tab.c" /* yacc.c:1646  */
    break;

  case 21:
#line 194 "1.a.dec.y" /* yacc.c:1646  */
    {
								tempST=LookUp((yyvsp[-3])->varname);

								if(tempST==NULL)
								{
									yyerror("undefined Variable");
			
									printf("%s\n",(yyvsp[-3])->varname );
									exit(1);
								}

								else 
								{
									(yyvsp[-3])->Gentry=tempST;
							
									if(tempST->type==typeintptr)
										(yyvsp[-3])->type=typeint;
								
									else if(tempST->type==typestrptr)
										(yyvsp[-3])->type=typechar;
								}
					
								(yyval)=createTree(0,nodetypePASGN,typenull,NULL,(yyvsp[-3]),(yyvsp[-1]),NULL);
							}
#line 1717 "y.tab.c" /* yacc.c:1646  */
    break;

  case 22:
#line 221 "1.a.dec.y" /* yacc.c:1646  */
    { (yyval)=createTree(0,nodetypeIF,typenull,NULL,(yyvsp[-7]),(yyvsp[-4]),(yyvsp[-2])); }
#line 1723 "y.tab.c" /* yacc.c:1646  */
    break;

  case 23:
#line 223 "1.a.dec.y" /* yacc.c:1646  */
    { (yyval)=createTree(0,nodetypeIF,typenull,NULL,(yyvsp[-5]),(yyvsp[-2]),NULL); }
#line 1729 "y.tab.c" /* yacc.c:1646  */
    break;

  case 24:
#line 227 "1.a.dec.y" /* yacc.c:1646  */
    { (yyval)=createTree(0,nodetypeWHILE,typenull,NULL,(yyvsp[-5]),(yyvsp[-2]),NULL); }
#line 1735 "y.tab.c" /* yacc.c:1646  */
    break;

  case 25:
#line 228 "1.a.dec.y" /* yacc.c:1646  */
    { (yyval)=createTree(0,nodetypeDOWHILE,typenull,NULL,(yyvsp[-2]),(yyvsp[-5]),NULL); }
#line 1741 "y.tab.c" /* yacc.c:1646  */
    break;

  case 26:
#line 230 "1.a.dec.y" /* yacc.c:1646  */
    { (yyval)=createTree(0,nodetypeREPEAT,typenull,NULL,(yyvsp[-2]),(yyvsp[-5]),NULL); }
#line 1747 "y.tab.c" /* yacc.c:1646  */
    break;

  case 27:
#line 233 "1.a.dec.y" /* yacc.c:1646  */
    { (yyval)=createTree(0,nodetypePLUS,typeint,NULL,(yyvsp[-2]),(yyvsp[0]),NULL); }
#line 1753 "y.tab.c" /* yacc.c:1646  */
    break;

  case 28:
#line 234 "1.a.dec.y" /* yacc.c:1646  */
    { (yyval)=createTree(0,nodetypeMINUS,typeint,NULL,(yyvsp[-2]),(yyvsp[0]),NULL); }
#line 1759 "y.tab.c" /* yacc.c:1646  */
    break;

  case 29:
#line 235 "1.a.dec.y" /* yacc.c:1646  */
    { (yyval)=createTree(0,nodetypeMUL,typeint,NULL,(yyvsp[-2]),(yyvsp[0]),NULL); }
#line 1765 "y.tab.c" /* yacc.c:1646  */
    break;

  case 30:
#line 236 "1.a.dec.y" /* yacc.c:1646  */
    { (yyval)=createTree(0,nodetypeDIV,typeint,NULL,(yyvsp[-2]),(yyvsp[0]),NULL); }
#line 1771 "y.tab.c" /* yacc.c:1646  */
    break;

  case 31:
#line 237 "1.a.dec.y" /* yacc.c:1646  */
    { (yyval)=(yyvsp[-1]); }
#line 1777 "y.tab.c" /* yacc.c:1646  */
    break;

  case 32:
#line 238 "1.a.dec.y" /* yacc.c:1646  */
    { (yyval)=(yyvsp[0]); }
#line 1783 "y.tab.c" /* yacc.c:1646  */
    break;

  case 33:
#line 239 "1.a.dec.y" /* yacc.c:1646  */
    { (yyval)=(yyvsp[0]); }
#line 1789 "y.tab.c" /* yacc.c:1646  */
    break;

  case 34:
#line 240 "1.a.dec.y" /* yacc.c:1646  */
    { (yyval)=createTree(0,nodetypeLT,typebool,NULL,(yyvsp[-2]),(yyvsp[0]),NULL); }
#line 1795 "y.tab.c" /* yacc.c:1646  */
    break;

  case 35:
#line 241 "1.a.dec.y" /* yacc.c:1646  */
    { (yyval)=createTree(0,nodetypeLE,typebool,NULL,(yyvsp[-2]),(yyvsp[0]),NULL); }
#line 1801 "y.tab.c" /* yacc.c:1646  */
    break;

  case 36:
#line 242 "1.a.dec.y" /* yacc.c:1646  */
    { (yyval)=createTree(0,nodetypeGT,typebool,NULL,(yyvsp[-2]),(yyvsp[0]),NULL); }
#line 1807 "y.tab.c" /* yacc.c:1646  */
    break;

  case 37:
#line 243 "1.a.dec.y" /* yacc.c:1646  */
    { (yyval)=createTree(0,nodetypeGE,typebool,NULL,(yyvsp[-2]),(yyvsp[0]),NULL); }
#line 1813 "y.tab.c" /* yacc.c:1646  */
    break;

  case 38:
#line 244 "1.a.dec.y" /* yacc.c:1646  */
    { (yyval)=createTree(0,nodetypeEQ,typebool,NULL,(yyvsp[-2]),(yyvsp[0]),NULL); }
#line 1819 "y.tab.c" /* yacc.c:1646  */
    break;

  case 39:
#line 245 "1.a.dec.y" /* yacc.c:1646  */
    { (yyval)=createTree(0,nodetypeNE,typebool,NULL,(yyvsp[-2]),(yyvsp[0]),NULL); }
#line 1825 "y.tab.c" /* yacc.c:1646  */
    break;

  case 40:
#line 246 "1.a.dec.y" /* yacc.c:1646  */
    {
								tempST=LookUp((yyvsp[0])->varname);
								
								if(tempST==NULL)
								{
									yyerror("undefined Variable ");
									
									printf(" %s\n",(yyvsp[0])->varname );
									exit(1);
								}
								
								else 
								{
									(yyvsp[0])->Gentry=tempST;
									(yyvsp[0])->type=tempST->type;
								}

								(yyval) = (yyvsp[0]);
							}
#line 1849 "y.tab.c" /* yacc.c:1646  */
    break;

  case 41:
#line 265 "1.a.dec.y" /* yacc.c:1646  */
    {
								tempST=LookUp((yyvsp[-3])->varname);
								
								if(tempST==NULL)
								{
									yyerror("undefined Variable");
			
									printf("%s\n",(yyvsp[-3])->varname );
									exit(1);
								}

								else
								{
									(yyvsp[-3])->Gentry=tempST; 
								
									if(tempST->type==typearrint)
										(yyvsp[-3])->type=typeint;
										
									else if(tempST->type==typestr)
										(yyvsp[-3])->type=typechar;
								}
								
								(yyval) = createTree(0,nodetypeARRID,(yyvsp[-3])->type,NULL,(yyvsp[-3]),(yyvsp[-1]),NULL);
							}
#line 1878 "y.tab.c" /* yacc.c:1646  */
    break;

  case 42:
#line 289 "1.a.dec.y" /* yacc.c:1646  */
    {
								tempST=LookUp((yyvsp[-6])->varname);
								
								if(tempST==NULL)
								{
									yyerror("undefined Variable");
	
									printf("%s\n",(yyvsp[-6])->varname );
									exit(1);
								}

								else 
								{
									(yyvsp[-6])->Gentry=tempST; 
									
									if(tempST->type==typearrint)
										(yyvsp[-6])->type=typeint;
										
									else if(tempST->type==typestr)
										(yyvsp[-6])->type=typechar;
								}
								(yyval)=createTree(0,nodetypeARRID,(yyvsp[-6])->type,NULL,(yyvsp[-6]),(yyvsp[-4]),(yyvsp[-1]));
							}
#line 1906 "y.tab.c" /* yacc.c:1646  */
    break;

  case 43:
#line 312 "1.a.dec.y" /* yacc.c:1646  */
    {
								tempST=LookUp((yyvsp[0])->varname);
							
								if(tempST==NULL)
								{
									yyerror("undefined Variable");

									printf("%s\n",(yyvsp[0])->varname );
									exit(1);
								}
								
								if(tempST->type!=typeintptr && tempST->type!=typestrptr)
								{
									yyerror("type mismatch");

									printf("%s\n",(yyvsp[0])->varname );
									exit(1);
								}

								else 
								{
									(yyvsp[0])->Gentry=tempST; 
										
									if(tempST->type==typeintptr)
										(yyvsp[0])->type=typeint;
										
									else if(tempST->type==typestrptr)
										(yyvsp[0])->type=typechar;
								}
								(yyval)=createTree(0,nodetypePOINTER,(yyvsp[0])->type,NULL,(yyvsp[0]),NULL,NULL);
							}
#line 1942 "y.tab.c" /* yacc.c:1646  */
    break;

  case 44:
#line 343 "1.a.dec.y" /* yacc.c:1646  */
    {
								tempST=LookUp((yyvsp[0])->varname);
								
								if(tempST==NULL)
								{
									yyerror("undefined Variable");
									
									printf("%s\n",(yyvsp[0])->varname );
									exit(1);
								}
								
								else 
								{
									(yyvsp[0])->Gentry=tempST; 
									
									if(tempST->type==typeint || tempST->type==typeintptr)
										(yyvsp[0])->type=typeint;
										
									else if(tempST->type==typechar || tempST->type==typestrptr)
										(yyvsp[0])->type=typechar;
								}
								(yyval)=createTree(0,nodetypeADDR,(yyvsp[0])->type,NULL,(yyvsp[0]),NULL,NULL);
							}
#line 1970 "y.tab.c" /* yacc.c:1646  */
    break;

  case 45:
#line 368 "1.a.dec.y" /* yacc.c:1646  */
    { printsymbolTable(); }
#line 1976 "y.tab.c" /* yacc.c:1646  */
    break;

  case 46:
#line 369 "1.a.dec.y" /* yacc.c:1646  */
    {}
#line 1982 "y.tab.c" /* yacc.c:1646  */
    break;

  case 47:
#line 372 "1.a.dec.y" /* yacc.c:1646  */
    {}
#line 1988 "y.tab.c" /* yacc.c:1646  */
    break;

  case 48:
#line 373 "1.a.dec.y" /* yacc.c:1646  */
    {}
#line 1994 "y.tab.c" /* yacc.c:1646  */
    break;

  case 49:
#line 376 "1.a.dec.y" /* yacc.c:1646  */
    {}
#line 2000 "y.tab.c" /* yacc.c:1646  */
    break;

  case 50:
#line 379 "1.a.dec.y" /* yacc.c:1646  */
    { type=typeint; }
#line 2006 "y.tab.c" /* yacc.c:1646  */
    break;

  case 51:
#line 380 "1.a.dec.y" /* yacc.c:1646  */
    { type=typechar; }
#line 2012 "y.tab.c" /* yacc.c:1646  */
    break;

  case 52:
#line 383 "1.a.dec.y" /* yacc.c:1646  */
    { Install((yyvsp[0])->varname,type,1,1); }
#line 2018 "y.tab.c" /* yacc.c:1646  */
    break;

  case 53:
#line 384 "1.a.dec.y" /* yacc.c:1646  */
    { Install((yyvsp[0])->varname,type,1,1); }
#line 2024 "y.tab.c" /* yacc.c:1646  */
    break;

  case 54:
#line 385 "1.a.dec.y" /* yacc.c:1646  */
    { Install((yyvsp[0])->varname,type,1,1); }
#line 2030 "y.tab.c" /* yacc.c:1646  */
    break;

  case 55:
#line 386 "1.a.dec.y" /* yacc.c:1646  */
    {		
								if(type==typeint)
									Install((yyvsp[-3])->varname,typearrint,(yyvsp[-1])->val,1);
											
								else if(type==typechar)
									Install((yyvsp[-3])->varname,typestr,(yyvsp[-1])->val,1);	
							}
#line 2042 "y.tab.c" /* yacc.c:1646  */
    break;

  case 56:
#line 394 "1.a.dec.y" /* yacc.c:1646  */
    {		
								if(type==typeint)
									Install((yyvsp[-6])->varname,typearrint,(yyvsp[-4])->val,(yyvsp[-1])->val);
											
								else if(type==typechar)
									Install((yyvsp[-6])->varname,typestr,(yyvsp[-4])->val,(yyvsp[-1])->val);	
							}
#line 2054 "y.tab.c" /* yacc.c:1646  */
    break;

  case 57:
#line 401 "1.a.dec.y" /* yacc.c:1646  */
    {
								if(type==typeint)
									Install((yyvsp[-6])->varname,typearrint,(yyvsp[-4])->val,(yyvsp[-1])->val);
											
								else if(type==typechar)
									Install((yyvsp[-6])->varname,typestr,(yyvsp[-4])->val,(yyvsp[-1])->val);
							}
#line 2066 "y.tab.c" /* yacc.c:1646  */
    break;

  case 58:
#line 408 "1.a.dec.y" /* yacc.c:1646  */
    {
								if(type==typeint)
									Install((yyvsp[-3])->varname,typearrint,(yyvsp[-1])->val,1);
									
								else if(type==typechar)
									Install((yyvsp[-3])->varname,typestr,(yyvsp[-1])->val,1);
							}
#line 2078 "y.tab.c" /* yacc.c:1646  */
    break;

  case 59:
#line 415 "1.a.dec.y" /* yacc.c:1646  */
    {
								if(type==typeint)
									Install((yyvsp[0])->varname,typeintptr,1,1);
								
								else if(type==typechar)
									Install((yyvsp[0])->varname,typestrptr,1,1);
							}
#line 2090 "y.tab.c" /* yacc.c:1646  */
    break;


#line 2094 "y.tab.c" /* yacc.c:1646  */
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
  YY_SYMBOL_PRINT ("-> $$ =", yyr1[yyn], &yyval, &yyloc);

  YYPOPSTACK (yylen);
  yylen = 0;
  YY_STACK_PRINT (yyss, yyssp);

  *++yyvsp = yyval;

  /* Now 'shift' the result of the reduction.  Determine what state
     that goes to, based on the state we popped back to and the rule
     number reduced by.  */

  yyn = yyr1[yyn];

  yystate = yypgoto[yyn - YYNTOKENS] + *yyssp;
  if (0 <= yystate && yystate <= YYLAST && yycheck[yystate] == *yyssp)
    yystate = yytable[yystate];
  else
    yystate = yydefgoto[yyn - YYNTOKENS];

  goto yynewstate;


/*--------------------------------------.
| yyerrlab -- here on detecting error.  |
`--------------------------------------*/
yyerrlab:
  /* Make sure we have latest lookahead translation.  See comments at
     user semantic actions for why this is necessary.  */
  yytoken = yychar == YYEMPTY ? YYEMPTY : YYTRANSLATE (yychar);

  /* If not already recovering from an error, report this error.  */
  if (!yyerrstatus)
    {
      ++yynerrs;
#if ! YYERROR_VERBOSE
      yyerror (YY_("syntax error"));
#else
# define YYSYNTAX_ERROR yysyntax_error (&yymsg_alloc, &yymsg, \
                                        yyssp, yytoken)
      {
        char const *yymsgp = YY_("syntax error");
        int yysyntax_error_status;
        yysyntax_error_status = YYSYNTAX_ERROR;
        if (yysyntax_error_status == 0)
          yymsgp = yymsg;
        else if (yysyntax_error_status == 1)
          {
            if (yymsg != yymsgbuf)
              YYSTACK_FREE (yymsg);
            yymsg = (char *) YYSTACK_ALLOC (yymsg_alloc);
            if (!yymsg)
              {
                yymsg = yymsgbuf;
                yymsg_alloc = sizeof yymsgbuf;
                yysyntax_error_status = 2;
              }
            else
              {
                yysyntax_error_status = YYSYNTAX_ERROR;
                yymsgp = yymsg;
              }
          }
        yyerror (yymsgp);
        if (yysyntax_error_status == 2)
          goto yyexhaustedlab;
      }
# undef YYSYNTAX_ERROR
#endif
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

  /* Pacify compilers like GCC when the user code never invokes
     YYERROR and the label yyerrorlab therefore never appears in user
     code.  */
  if (/*CONSTCOND*/ 0)
     goto yyerrorlab;

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

  for (;;)
    {
      yyn = yypact[yystate];
      if (!yypact_value_is_default (yyn))
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

  YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
  *++yyvsp = yylval;
  YY_IGNORE_MAYBE_UNINITIALIZED_END


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

#if !defined yyoverflow || YYERROR_VERBOSE
/*-------------------------------------------------.
| yyexhaustedlab -- memory exhaustion comes here.  |
`-------------------------------------------------*/
yyexhaustedlab:
  yyerror (YY_("memory exhausted"));
  yyresult = 2;
  /* Fall through.  */
#endif

yyreturn:
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
  return yyresult;
}
#line 424 "1.a.dec.y" /* yacc.c:1906  */



void yyerror(char const *s)
{
	printf("yyerror %s at line %d\n",s,lcnt);
}

int main(void) 
{
	FILE *fp=fopen("1.input","r");
	
	lcnt=1;
	Ghead=NULL;
	varadrs=4096;

	if(fp)
		yyin=fp;
	else
		printf("Input file error\n");

	targetFile=fopen("1.intermediate.xsm","w");

	yyparse();
	return 0;
}
