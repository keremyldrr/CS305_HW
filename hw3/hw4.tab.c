/* A Bison parser, made by GNU Bison 3.2.  */

/* Bison implementation for Yacc-like parsers in C

   Copyright (C) 1984, 1989-1990, 2000-2015, 2018 Free Software Foundation, Inc.

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

/* Undocumented macros, especially those whose name start with YY_,
   are private implementation details.  Do not rely on them.  */

/* Identify Bison output.  */
#define YYBISON 1

/* Bison version.  */
#define YYBISON_VERSION "3.2"

/* Skeleton name.  */
#define YYSKELETON_NAME "yacc.c"

/* Pure parsers.  */
#define YYPURE 0

/* Push parsers.  */
#define YYPUSH 0

/* Pull parsers.  */
#define YYPULL 1




/* First part of user prologue.  */
#line 2 "hw4.y" /* yacc.c:338  */

#include <stdio.h>
#include <string.h>
#include "hw4.h"
  void yyerror(const char *s){//called by yyparse on error
    printf("%s\n", s);
  }
  TreeNode *rootPtr;
  TreeNode * genConst(int crn);
  TreeNode * genCourse(Attribute *,TreeNode *);
  TreeNode *mergeClass(TreeNode *,TreeNode *);
  TreeNode *mergeCourse(TreeNode *,TreeNode *);
  TreeNode *genClass(Attribute *,TreeNode *);
  int semanticCheck();
  TreeNode *genMeeting(Attribute *);
  TreeNode *mergeMeet(TreeNode *,TreeNode *);
  Attribute *makeAttr(ELEMTYPE,Tracker);
  Attribute *connectAttr(Attribute *,Attribute *);
  void printTree(TreeNode *);
  char *dicty[15] =  {"COURSE", "CONSTRAINT","MEETING","CODE","TYPE","NAME","CLASS","ITEM","SECTION","CAPACITY","CRN","INSTRUCTOR","START","END_T","DAY"};//MORE TO COME     

  int size(char *);
    

#line 94 "hw4.tab.c" /* yacc.c:338  */
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

/* Enabling verbose error messages.  */
#ifdef YYERROR_VERBOSE
# undef YYERROR_VERBOSE
# define YYERROR_VERBOSE 1
#else
# define YYERROR_VERBOSE 0
#endif

/* In a future release of Bison, this section will be replaced
   by #include "hw4.tab.h".  */
#ifndef YY_YY_HW4_TAB_H_INCLUDED
# define YY_YY_HW4_TAB_H_INCLUDED
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
    tSTRING = 258,
    tMON = 259,
    tTUE = 260,
    tWED = 261,
    tTHU = 262,
    tFRI = 263,
    tNUM = 264,
    tTIME = 265,
    tOPEN = 266,
    tCOURSE = 267,
    tCLOSE = 268,
    tEND = 269,
    tCODE = 270,
    tCLASS = 271,
    tNAME = 272,
    tTYPE = 273,
    tSECTION = 274,
    tINSTRUCTOR = 275,
    tCRN = 276,
    tCAPACITY = 277,
    tMEETING = 278,
    tSELF = 279,
    tDAY = 280,
    tSTART = 281,
    tEND_A = 282,
    tCONSTRAINT = 283,
    tITEM = 284
  };
#endif

/* Value type.  */
#if ! defined YYSTYPE && ! defined YYSTYPE_IS_DECLARED

union YYSTYPE
{
#line 25 "hw4.y" /* yacc.c:353  */

  Tracker coll;
  TreeNode *treeptr;
  Attribute *attr;

#line 173 "hw4.tab.c" /* yacc.c:353  */
};

typedef union YYSTYPE YYSTYPE;
# define YYSTYPE_IS_TRIVIAL 1
# define YYSTYPE_IS_DECLARED 1
#endif


extern YYSTYPE yylval;

int yyparse (void);

#endif /* !YY_YY_HW4_TAB_H_INCLUDED  */



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
typedef unsigned short yytype_uint16;
#endif

#ifdef YYTYPE_INT16
typedef YYTYPE_INT16 yytype_int16;
#else
typedef short yytype_int16;
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
#  define YYSIZE_T unsigned
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

/* Suppress unused-variable warnings by "using" E.  */
#if ! defined lint || defined __GNUC__
# define YYUSE(E) ((void) (E))
#else
# define YYUSE(E) /* empty */
#endif

#if defined __GNUC__ && ! defined __ICC && 407 <= __GNUC__ * 100 + __GNUC_MINOR__
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
#define YYFINAL  9
/* YYLAST -- Last index in YYTABLE.  */
#define YYLAST   64

/* YYNTOKENS -- Number of terminals.  */
#define YYNTOKENS  30
/* YYNNTS -- Number of nonterminals.  */
#define YYNNTS  29
/* YYNRULES -- Number of rules.  */
#define YYNRULES  50
/* YYNSTATES -- Number of states.  */
#define YYNSTATES  88

/* YYTRANSLATE[YYX] -- Symbol number corresponding to YYX as returned
   by yylex, with out-of-bounds checking.  */
#define YYUNDEFTOK  2
#define YYMAXUTOK   284

#define YYTRANSLATE(YYX)                                                \
  ((unsigned) (YYX) <= YYMAXUTOK ? yytranslate[YYX] : YYUNDEFTOK)

/* YYTRANSLATE[TOKEN-NUM] -- Symbol number corresponding to TOKEN-NUM
   as returned by yylex, without out-of-bounds checking.  */
static const yytype_uint8 yytranslate[] =
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
      25,    26,    27,    28,    29
};

#if YYDEBUG
  /* YYRLINE[YYN] -- Source line where rule number YYN was defined.  */
static const yytype_uint8 yyrline[] =
{
       0,    59,    59,    59,    60,    60,    61,    61,    62,    63,
      64,    64,    65,    65,    65,    66,    68,    70,    71,    72,
      73,    74,    74,    75,    75,    75,    75,    76,    76,    77,
      78,    79,    80,    80,    81,    81,    81,    82,    82,    82,
      82,    82,    83,    84,    85,    85,    86,    87,    88,    89,
      89
};
#endif

#if YYDEBUG || YYERROR_VERBOSE || 0
/* YYTNAME[SYMBOL-NUM] -- String name of the symbol SYMBOL-NUM.
   First, the terminals, then, starting at YYNTOKENS, nonterminals.  */
static const char *const yytname[] =
{
  "$end", "error", "$undefined", "tSTRING", "tMON", "tTUE", "tWED",
  "tTHU", "tFRI", "tNUM", "tTIME", "tOPEN", "tCOURSE", "tCLOSE", "tEND",
  "tCODE", "tCLASS", "tNAME", "tTYPE", "tSECTION", "tINSTRUCTOR", "tCRN",
  "tCAPACITY", "tMEETING", "tSELF", "tDAY", "tSTART", "tEND_A",
  "tCONSTRAINT", "tITEM", "$accept", "prog", "elementList", "element",
  "beginCourse", "endCourse", "courseAttrList", "courseAttr", "classList",
  "class", "beginClass", "endClass", "closeClass", "classAttrList",
  "classAttr", "meetingList", "meeting", "beginMeeting", "endMeeting",
  "meetingAttrList", "meetingAttr", "day", "beginConstraint",
  "endConstraint", "itemList", "item", "beginItem", "endItem", "itemAttr", YY_NULLPTR
};
#endif

# ifdef YYPRINT
/* YYTOKNUM[NUM] -- (External) token number corresponding to the
   (internal) symbol number NUM (which must be that of a token).  */
static const yytype_uint16 yytoknum[] =
{
       0,   256,   257,   258,   259,   260,   261,   262,   263,   264,
     265,   266,   267,   268,   269,   270,   271,   272,   273,   274,
     275,   276,   277,   278,   279,   280,   281,   282,   283,   284
};
# endif

#define YYPACT_NINF -28

#define yypact_value_is_default(Yystate) \
  (!!((Yystate) == (-28)))

#define YYTABLE_NINF -1

#define yytable_value_is_error(Yytable_value) \
  0

  /* YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
     STATE-NUM.  */
static const yytype_int8 yypact[] =
{
       2,   -12,    20,   -28,     2,    10,    11,    -3,    12,   -28,
     -28,     7,    13,    10,   -11,    -5,    14,    11,   -14,    23,
      26,    27,    18,    -3,   -28,   -28,    21,   -28,   -28,    29,
      31,    28,    30,    22,   -11,   -28,     8,   -28,   -28,    35,
      32,    16,   -28,   -28,   -28,   -28,   -28,    33,   -28,   -28,
     -28,   -28,   -28,    34,   -28,    36,   -28,   -28,   -28,   -28,
     -28,    19,    37,    34,    -8,   -28,   -28,    38,   -28,   -28,
      -2,    40,    42,    24,    -8,    43,   -28,   -28,   -28,   -28,
     -28,   -28,   -28,   -28,   -28,   -28,   -28,   -28
};

  /* YYDEFACT[STATE-NUM] -- Default reduction number in state STATE-NUM.
     Performed when YYTABLE does not specify something else to do.  Zero
     means the default is an error.  */
static const yytype_uint8 yydefact[] =
{
       3,     0,     0,     2,     4,     0,     0,     0,     0,     1,
       5,     0,     0,    15,     0,     0,     0,    44,     0,     0,
       0,     0,     0,    10,    42,    18,     0,     6,    16,     0,
       0,     0,     0,     0,    21,    47,     0,     7,    45,     0,
       0,     0,    12,    13,    14,     8,    11,     0,    23,    24,
      25,    26,    19,     0,    22,     0,    49,    50,    48,    46,
       9,     0,     0,    27,     0,    43,    30,     0,    17,    28,
       0,     0,     0,     0,    32,     0,    37,    38,    39,    40,
      41,    34,    35,    36,    31,    29,    33,    20
};

  /* YYPGOTO[NTERM-NUM].  */
static const yytype_int8 yypgoto[] =
{
     -28,   -28,    39,   -28,   -28,   -28,    41,   -28,    44,   -28,
     -28,   -28,   -28,    25,   -28,   -19,   -28,   -28,   -28,   -27,
     -28,   -28,   -28,   -28,    45,   -28,   -28,   -28,   -28
};

  /* YYDEFGOTO[NTERM-NUM].  */
static const yytype_int8 yydefgoto[] =
{
      -1,     2,     3,     4,     5,    27,    22,    23,    12,    13,
      14,    53,    68,    33,    34,    62,    63,    64,    85,    73,
      74,    81,     6,    37,    16,    17,    18,    59,    41
};

  /* YYTABLE[YYPACT[STATE-NUM]] -- What to do in state STATE-NUM.  If
     positive, shift that token.  If negative, reduce the rule whose
     number is the opposite.  If YYTABLE_NINF, syntax error.  */
static const yytype_uint8 yytable[] =
{
       7,    39,    76,    77,    78,    79,    80,    40,    29,    30,
      31,    32,    19,     1,    20,    21,     8,    70,    71,    72,
       9,    11,    15,    25,    35,    24,    42,    26,    36,    43,
      44,    45,    48,    47,    49,    52,    55,    50,    56,    51,
      58,    57,    66,    10,    69,    61,    60,    86,    84,    65,
      82,    67,    83,     0,    75,     0,    87,    28,     0,    54,
       0,     0,    38,     0,    46
};

static const yytype_int8 yycheck[] =
{
      12,    15,     4,     5,     6,     7,     8,    21,    19,    20,
      21,    22,    15,    11,    17,    18,    28,    25,    26,    27,
       0,    11,    11,    16,    29,    13,     3,    14,    14,     3,
       3,    13,     3,    12,     3,    13,    28,     9,     3,     9,
      24,     9,    23,     4,    63,    11,    13,    74,    24,    13,
      10,    14,    10,    -1,    16,    -1,    13,    13,    -1,    34,
      -1,    -1,    17,    -1,    23
};

  /* YYSTOS[STATE-NUM] -- The (internal number of the) accessing
     symbol of state STATE-NUM.  */
static const yytype_uint8 yystos[] =
{
       0,    11,    31,    32,    33,    34,    52,    12,    28,     0,
      32,    11,    38,    39,    40,    11,    54,    55,    56,    15,
      17,    18,    36,    37,    13,    16,    14,    35,    38,    19,
      20,    21,    22,    43,    44,    29,    14,    53,    54,    15,
      21,    58,     3,     3,     3,    13,    36,    12,     3,     3,
       9,     9,    13,    41,    43,    28,     3,     9,    24,    57,
      13,    11,    45,    46,    47,    13,    23,    14,    42,    45,
      25,    26,    27,    49,    50,    16,     4,     5,     6,     7,
       8,    51,    10,    10,    24,    48,    49,    13
};

  /* YYR1[YYN] -- Symbol number of symbol that rule YYN derives.  */
static const yytype_uint8 yyr1[] =
{
       0,    30,    31,    31,    32,    32,    33,    33,    34,    35,
      36,    36,    37,    37,    37,    38,    38,    39,    40,    41,
      42,    43,    43,    44,    44,    44,    44,    45,    45,    46,
      47,    48,    49,    49,    50,    50,    50,    51,    51,    51,
      51,    51,    52,    53,    54,    54,    55,    56,    57,    58,
      58
};

  /* YYR2[YYN] -- Number of symbols on the right hand side of rule YYN.  */
static const yytype_uint8 yyr2[] =
{
       0,     2,     1,     0,     1,     2,     3,     3,     4,     3,
       1,     2,     2,     2,     2,     1,     2,     5,     2,     1,
       3,     1,     2,     2,     2,     2,     2,     1,     2,     3,
       2,     1,     1,     2,     2,     2,     2,     1,     1,     1,
       1,     1,     3,     3,     1,     2,     3,     2,     1,     2,
       2
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


/*-----------------------------------.
| Print this symbol's value on YYO.  |
`-----------------------------------*/

static void
yy_symbol_value_print (FILE *yyo, int yytype, YYSTYPE const * const yyvaluep)
{
  FILE *yyoutput = yyo;
  YYUSE (yyoutput);
  if (!yyvaluep)
    return;
# ifdef YYPRINT
  if (yytype < YYNTOKENS)
    YYPRINT (yyo, yytoknum[yytype], *yyvaluep);
# endif
  YYUSE (yytype);
}


/*---------------------------.
| Print this symbol on YYO.  |
`---------------------------*/

static void
yy_symbol_print (FILE *yyo, int yytype, YYSTYPE const * const yyvaluep)
{
  YYFPRINTF (yyo, "%s %s (",
             yytype < YYNTOKENS ? "token" : "nterm", yytname[yytype]);

  yy_symbol_value_print (yyo, yytype, yyvaluep);
  YYFPRINTF (yyo, ")");
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
  unsigned long yylno = yyrline[yyrule];
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

  return (YYSIZE_T) (yystpcpy (yyres, yystr) - yyres);
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
    default: /* Avoid compiler warnings. */
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
  *yyssp = (yytype_int16) yystate;

  if (yyss + yystacksize - 1 <= yyssp)
    {
      /* Get the current used size of the three stacks, in elements.  */
      YYSIZE_T yysize = (YYSIZE_T) (yyssp - yyss + 1);

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
                  (unsigned long) yystacksize));

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
#line 59 "hw4.y" /* yacc.c:1645  */
    {rootPtr = (yyvsp[0].treeptr);}
#line 1312 "hw4.tab.c" /* yacc.c:1645  */
    break;

  case 4:
#line 60 "hw4.y" /* yacc.c:1645  */
    {(yyval.treeptr) = mergeCourse((yyvsp[0].treeptr),NULL);}
#line 1318 "hw4.tab.c" /* yacc.c:1645  */
    break;

  case 5:
#line 60 "hw4.y" /* yacc.c:1645  */
    {(yyval.treeptr) = mergeCourse((yyvsp[-1].treeptr),(yyvsp[0].treeptr)); }
#line 1324 "hw4.tab.c" /* yacc.c:1645  */
    break;

  case 6:
#line 61 "hw4.y" /* yacc.c:1645  */
    {(yyval.treeptr) = genCourse((yyvsp[-2].attr),(yyvsp[-1].treeptr));}
#line 1330 "hw4.tab.c" /* yacc.c:1645  */
    break;

  case 8:
#line 62 "hw4.y" /* yacc.c:1645  */
    {(yyval.attr) = (yyvsp[-1].attr);}
#line 1336 "hw4.tab.c" /* yacc.c:1645  */
    break;

  case 10:
#line 64 "hw4.y" /* yacc.c:1645  */
    { (yyval.attr) = connectAttr((yyvsp[0].attr),NULL); }
#line 1342 "hw4.tab.c" /* yacc.c:1645  */
    break;

  case 11:
#line 64 "hw4.y" /* yacc.c:1645  */
    {(yyval.attr) = connectAttr((yyvsp[-1].attr),(yyvsp[0].attr));}
#line 1348 "hw4.tab.c" /* yacc.c:1645  */
    break;

  case 12:
#line 65 "hw4.y" /* yacc.c:1645  */
    {(yyval.attr) = makeAttr(CODE,(yyvsp[0].coll));}
#line 1354 "hw4.tab.c" /* yacc.c:1645  */
    break;

  case 13:
#line 65 "hw4.y" /* yacc.c:1645  */
    {(yyval.attr)=makeAttr(NAME,(yyvsp[0].coll));}
#line 1360 "hw4.tab.c" /* yacc.c:1645  */
    break;

  case 14:
#line 65 "hw4.y" /* yacc.c:1645  */
    {(yyval.attr)=makeAttr(TYPE,(yyvsp[0].coll)); }
#line 1366 "hw4.tab.c" /* yacc.c:1645  */
    break;

  case 15:
#line 66 "hw4.y" /* yacc.c:1645  */
    {(yyval.treeptr) =mergeClass((yyvsp[0].treeptr),NULL);}
#line 1372 "hw4.tab.c" /* yacc.c:1645  */
    break;

  case 16:
#line 68 "hw4.y" /* yacc.c:1645  */
    {(yyval.treeptr) = mergeClass((yyvsp[-1].treeptr),(yyvsp[0].treeptr));}
#line 1378 "hw4.tab.c" /* yacc.c:1645  */
    break;

  case 17:
#line 70 "hw4.y" /* yacc.c:1645  */
    {(yyval.treeptr) = genClass((yyvsp[-3].attr),(yyvsp[-1].treeptr));}
#line 1384 "hw4.tab.c" /* yacc.c:1645  */
    break;

  case 21:
#line 74 "hw4.y" /* yacc.c:1645  */
    {(yyval.attr) = connectAttr((yyvsp[0].attr),NULL);}
#line 1390 "hw4.tab.c" /* yacc.c:1645  */
    break;

  case 22:
#line 74 "hw4.y" /* yacc.c:1645  */
    {(yyval.attr)= connectAttr((yyvsp[-1].attr),(yyvsp[0].attr));}
#line 1396 "hw4.tab.c" /* yacc.c:1645  */
    break;

  case 23:
#line 75 "hw4.y" /* yacc.c:1645  */
    {(yyval.attr) = makeAttr(SECTION,(yyvsp[0].coll));}
#line 1402 "hw4.tab.c" /* yacc.c:1645  */
    break;

  case 24:
#line 75 "hw4.y" /* yacc.c:1645  */
    {(yyval.attr) = makeAttr(INSTRUCTOR,(yyvsp[0].coll)); }
#line 1408 "hw4.tab.c" /* yacc.c:1645  */
    break;

  case 25:
#line 75 "hw4.y" /* yacc.c:1645  */
    {(yyval.attr) = makeAttr(CRN,(yyvsp[0].coll));}
#line 1414 "hw4.tab.c" /* yacc.c:1645  */
    break;

  case 26:
#line 75 "hw4.y" /* yacc.c:1645  */
    {(yyval.attr) = makeAttr(CAPACITY,(yyvsp[0].coll));}
#line 1420 "hw4.tab.c" /* yacc.c:1645  */
    break;

  case 27:
#line 76 "hw4.y" /* yacc.c:1645  */
    {(yyval.treeptr)=mergeMeet((yyvsp[0].treeptr),NULL);}
#line 1426 "hw4.tab.c" /* yacc.c:1645  */
    break;

  case 28:
#line 76 "hw4.y" /* yacc.c:1645  */
    {(yyval.treeptr) = mergeMeet((yyvsp[-1].treeptr),(yyvsp[0].treeptr));}
#line 1432 "hw4.tab.c" /* yacc.c:1645  */
    break;

  case 29:
#line 77 "hw4.y" /* yacc.c:1645  */
    {(yyval.treeptr)=genMeeting((yyvsp[-1].attr));}
#line 1438 "hw4.tab.c" /* yacc.c:1645  */
    break;

  case 32:
#line 80 "hw4.y" /* yacc.c:1645  */
    {(yyval.attr) = connectAttr((yyvsp[0].attr),NULL);}
#line 1444 "hw4.tab.c" /* yacc.c:1645  */
    break;

  case 33:
#line 80 "hw4.y" /* yacc.c:1645  */
    {(yyval.attr) = connectAttr((yyvsp[-1].attr),(yyvsp[0].attr));}
#line 1450 "hw4.tab.c" /* yacc.c:1645  */
    break;

  case 34:
#line 81 "hw4.y" /* yacc.c:1645  */
    {(yyval.attr) = makeAttr(DAY,(yyvsp[0].coll));}
#line 1456 "hw4.tab.c" /* yacc.c:1645  */
    break;

  case 35:
#line 81 "hw4.y" /* yacc.c:1645  */
    {(yyval.attr) = makeAttr(START,(yyvsp[0].coll));}
#line 1462 "hw4.tab.c" /* yacc.c:1645  */
    break;

  case 36:
#line 81 "hw4.y" /* yacc.c:1645  */
    {(yyval.attr) = makeAttr(END_T,(yyvsp[0].coll));}
#line 1468 "hw4.tab.c" /* yacc.c:1645  */
    break;


#line 1472 "hw4.tab.c" /* yacc.c:1645  */
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
#line 90 "hw4.y" /* yacc.c:1903  */



int semanticCheck(){

  TreeNode *ptr = rootPtr;
  while(ptr){
  if(ptr->thisElemType == COURSE)
    {
      printf("here we go \n");
      courseNode current = ptr->node->course;
      int codeCount = 0;
      int nameCount = 0;
      int typeCount = 0;
      Attribute *attrs  = current.attr;
      int ck1 = 0;
      int ck2 = 0;
      int ck3 = 0;
      while(attrs !=NULL){
	ELEMTYPE ch;
	ch = attrs->type;
	if(ch == CODE)
	  codeCount+=1;
	else if(ch==NAME)
	  nameCount +=1;
	else if(ch == TYPE)
	  typeCount+=1;
	attrs = attrs->next;
      }
      if(typeCount>1 || typeCount < 1 && ck1 == 0)
	{
	  printf("ERROR: course element at line %d has %d occurrences of type type \n",current.attr->lineNumber,typeCount);
	  ck1=1;
	}	
      if(codeCount>1 || codeCount < 1 && ck2 == 0)
	{
	  printf("ERROR: course element at line %d has %d occurrences of type code \n",current.attr->lineNumber,codeCount);
	  ck2 = 1;
	}
      if(nameCount>1 || nameCount < 1 && ck3 == 0)
	{
	  printf("ERROR: course element at line %d has %d occurrences of type name \n",current.attr->lineNumber,nameCount);
	  ck3 = 1;
	}
      
      //CLASS CHECK

      TreeNode *cls_list = current.classes;
      
      while(cls_list != NULL){

	int section = 0;
	int inst = 0;
	int crn = 0;
	int cap = 0;
	ck1 = ck2 = ck3 = 0;
	int ck4 = 0;
	attrs = cls_list->node->class.attr;
	while(attrs !=NULL){
	  ELEMTYPE ch;
	  ch = attrs->type;
	  if(ch == SECTION)
	    section+=1;
	  else if(ch==INSTRUCTOR)
	    inst +=1;
	  else if(ch == CAPACITY)
	    cap+=1;
	  else if(ch == CRN)
	    crn+=1;
	
	  attrs = attrs->next;
	}
      
	if(section>1 || section < 1 && ck1 == 0)
	  {
	    printf("ERROR: class element at line %d has %d occurrences of type section \n",cls_list->node->class.attr->lineNumber,section);
	    ck1=1;
	  }	
	if(inst>1 || inst < 1 && ck2 == 0)
	  {
	    printf("ERROR: class element at line %d has %d occurrences of type instructor \n",cls_list->node->class.attr->lineNumber,inst);
	    ck2 = 1;
	  }
      if(cap>1 || cap < 1 && ck3 == 0)
	{
	  printf("ERROR: class element at line %d has %d occurrences of type capacity \n",cls_list->node->class.attr->lineNumber,cap);
	  ck3 = 1;}
      if(crn>1 || crn < 1 && ck4 == 0)
	{
	  printf("ERROR: class element at line %d has %d occurrences of type name \n",cls_list->node->class.attr->lineNumber,crn);
	  ck4 = 1;}

      
      //check for meetings here
      TreeNode *meety = cls_list->node->class.meetings;
      while(meety != NULL){
      int lineNum = meety->node->meeting.attr->lineNumber;
      int start = 0;
      int end = 0;
      int day = 0;
      ck1 = ck2 = ck3 = 0;
      attrs = meety->node->meeting.attr;
      while(attrs != NULL)
	{
	  ELEMTYPE ch;
	  ch = attrs->type;
	  if(ch == START)
	    start+=1;
	  else if(ch==END_T)
	    end +=1;
	  else if(ch == DAY)
	    day+=1;
	 	
	  attrs = attrs->next;
	  
	}
      ///////////////////////////////////
	if(start>1 || start < 1 && ck1 == 0)
	  {
	    printf("ERROR: meeting element at line %d has %d occurrences of type start \n",lineNum,start);
	    ck1=1;
	  }	
	if(end>1 || end < 1 && ck2 == 0)
	  {
	    printf("ERROR: meeting  element at line %d has %d occurrences of type end \n",lineNum,end);
	    ck2 = 1;
	  }
      if(day>1 || day < 1 && ck3 == 0)
	{
	  printf("ERROR: meeting element at line %d has %d occurrences of type day \n",lineNum,day);
	  ck3 = 1;}



      ///////////////////////////////////
      meety = meety->next;
      }
      cls_list = cls_list->next;
      }
    }
  else{

    //constraint thingy here

  }
  ptr = ptr->next;
  }
  return 1;
}


Attribute * makeAttr(ELEMTYPE elem,Tracker tr){
  
  Attribute *ret = (Attribute *)malloc(sizeof(Attribute));
  ret->type = elem;
  ret->next = NULL;
  ret->lineNumber = tr.lineNum;
  printf("%d NUMLINE",ret->lineNumber);
  //&ret->str[0] = (char *)malloc(sizeof(char)*100);
  strcpy(ret->str,tr.str);
  printf("%s %s \n ",ret->str,dicty[elem]);
  //  memset(&strink[0], 0, sizeof(char)*100);

  return ret;

}

Attribute * connectAttr(Attribute *a1,Attribute *a2){
  
  
  a1->next = a2;
  return a1;



}
 TreeNode* genCourse(Attribute *attributes,TreeNode *classes)
{
  TreeNode *ret = (struct TreeNode *)malloc(sizeof(TreeNode));
  ret ->thisElemType = COURSE;
  ret->node = (wildCard *)malloc(sizeof(wildCard));
  ret->node->course.attr =attributes;
  ret->node->course.classes = classes;
 
  return ret;
}


TreeNode *mergeClass(TreeNode *a1,TreeNode *a2){
  
  a1->next = a2;
  return a1;
  
}
TreeNode *mergeCourse(TreeNode *a1,TreeNode *a2){
  
  a1->next = a2;
  return a1;
  
}
TreeNode *genClass(Attribute * attributes,TreeNode *meetings){
  
  TreeNode *ret = (TreeNode *)malloc(sizeof(TreeNode));
  ret->thisElemType = CLASS;
  
  Attribute *p = (Attribute *)malloc(sizeof(Attribute));
  
  ret->node = (wildCard *)malloc(sizeof(wildCard));
  
  ret->node->class.attr = attributes;

  ret->node->class.meetings = meetings;


  //set meetings here
  return ret;
}
TreeNode *mergeMeet(TreeNode *a1,TreeNode *a2){
  a1->next = a2;
  return a1;
  
}
TreeNode *genMeeting(Attribute * attributes){
  
  TreeNode *ret = (TreeNode *)malloc(sizeof(TreeNode));
  ret->thisElemType = MEETING;
  
 
  
  ret->node = (wildCard *)malloc(sizeof(wildCard));
 
  ret->node->meeting.attr = attributes;  
  return ret;
}
int size(char *ptr){
  //variable used to access the subsequent array elements.
  int offset = 0;
  //variable that counts the number of elements in your array
  int count = 0;

  //While loop that tests whether the end of the array has been reached
  while (*(ptr + offset) != '\0')
    {
      //increment the count variable
      ++count;
      //advance to the next element of the array
      ++offset;
    }
    //return the size of the array
  return count;
}
int main(){
  
  if(yyparse()){
    printf("ERROR\n");
		return 1;		
  }else{
    printf("OK\n");
    TreeNode *q = rootPtr;
    /*while(q){
    TreeNode *p = q->node->course.classes;
    
    while(p != NULL)
      {
	printf("%d cls  \n",p->thisElemType);
	Attribute *pp = p->node->class.attr;
	while(pp != NULL)
	  {
	    printf("clsattr %d \n",pp->type);
	    pp = pp->next;
	  }
	TreeNode *pp2 = p->node->class.meetings;
	while(pp2!= NULL)
	  {

	    Attribute * pp3 = pp2->node->meeting.attr;
	    while(pp3 != NULL)
	      {
		//		printf("meetattr %s \n",pp3->str);
		pp3 = pp3->next;
	      }
	    printf("\n");
	    pp2 = pp2->next;
	  }
	p = p->next;
	}
    q = q->next;
    }*/
    semanticCheck();
    return 0;
  }	
} 
