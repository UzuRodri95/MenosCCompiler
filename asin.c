/* A Bison parser, made by GNU Bison 3.5.1.  */

/* Bison implementation for Yacc-like parsers in C

   Copyright (C) 1984, 1989-1990, 2000-2015, 2018-2020 Free Software Foundation,
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
#define YYBISON_VERSION "3.5.1"

/* Skeleton name.  */
#define YYSKELETON_NAME "yacc.c"

/* Pure parsers.  */
#define YYPURE 0

/* Push parsers.  */
#define YYPUSH 0

/* Pull parsers.  */
#define YYPULL 1




/* First part of user prologue.  */
#line 10 "src/asin.y"

#include <stdio.h>
#include <string.h>
#include "header.h"
#include "libtds.h"

#define GLOBAL 0
#define LOCAL 1

int dvar;
int niv;

#line 83 "asin.c"

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

/* Enabling verbose error messages.  */
#ifdef YYERROR_VERBOSE
# undef YYERROR_VERBOSE
# define YYERROR_VERBOSE 1
#else
# define YYERROR_VERBOSE 0
#endif

/* Use api.header.include to #include this header
   instead of duplicating it here.  */
#ifndef YY_YY_ASIN_H_INCLUDED
# define YY_YY_ASIN_H_INCLUDED
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
    WHILE_ = 258,
    FOR_ = 259,
    IF_ = 260,
    ELSE_ = 261,
    PRINT_ = 262,
    READ_ = 263,
    RETURN_ = 264,
    ALLAVE_ = 265,
    CLLAVE_ = 266,
    ACORCH_ = 267,
    CCORCH_ = 268,
    APAREN_ = 269,
    CPAREN_ = 270,
    PTOCOMA_ = 271,
    PTO_ = 272,
    CMA_ = 273,
    MAS_ = 274,
    MENOS_ = 275,
    POR_ = 276,
    DIV_ = 277,
    AND_ = 278,
    OR_ = 279,
    SUMASIG_ = 280,
    RESASIG_ = 281,
    MULASIG_ = 282,
    DIVASIG_ = 283,
    IGU_ = 284,
    NOIGU_ = 285,
    MAYIGU_ = 286,
    MENIGU_ = 287,
    INC_ = 288,
    DEC_ = 289,
    MAY_ = 290,
    MEN_ = 291,
    ASIG_ = 292,
    NOT_ = 293,
    MOD_ = 294,
    INT_ = 295,
    BOOL_ = 296,
    CTE_ = 297,
    TRUE_ = 298,
    FALSE_ = 299,
    ID_ = 300
  };
#endif

/* Value type.  */
#if ! defined YYSTYPE && ! defined YYSTYPE_IS_DECLARED
union YYSTYPE
{
#line 23 "src/asin.y"

    char *ident; //NOMBRE DEL IDENTIFICADOR
    int cent;    //VALOR DE LA CTE NUMERICA ENTERA
    EXP exp;     //PARA LAS EXPRESIONES
    STR str;     //PARA LOS ELEMENTOS CON TALLA
    MAT mat;     //PARA CONSTANTE

#line 189 "asin.c"

};
typedef union YYSTYPE YYSTYPE;
# define YYSTYPE_IS_TRIVIAL 1
# define YYSTYPE_IS_DECLARED 1
#endif


extern YYSTYPE yylval;

int yyparse (void);

#endif /* !YY_YY_ASIN_H_INCLUDED  */



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
# define YYUSE(E) ((void) (E))
#else
# define YYUSE(E) /* empty */
#endif

#if defined __GNUC__ && ! defined __ICC && 407 <= __GNUC__ * 100 + __GNUC_MINOR__
/* Suppress an incorrect diagnostic about yylval being uninitialized.  */
# define YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN                            \
    _Pragma ("GCC diagnostic push")                                     \
    _Pragma ("GCC diagnostic ignored \"-Wuninitialized\"")              \
    _Pragma ("GCC diagnostic ignored \"-Wmaybe-uninitialized\"")
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
#define YYFINAL  3
/* YYLAST -- Last index in YYTABLE.  */
#define YYLAST   156

/* YYNTOKENS -- Number of terminals.  */
#define YYNTOKENS  46
/* YYNNTS -- Number of nonterminals.  */
#define YYNNTS  39
/* YYNRULES -- Number of rules.  */
#define YYNRULES  82
/* YYNSTATES -- Number of states.  */
#define YYNSTATES  144

#define YYUNDEFTOK  2
#define YYMAXUTOK   300


/* YYTRANSLATE(TOKEN-NUM) -- Symbol number corresponding to TOKEN-NUM
   as returned by yylex, with out-of-bounds checking.  */
#define YYTRANSLATE(YYX)                                                \
  (0 <= (YYX) && (YYX) <= YYMAXUTOK ? yytranslate[YYX] : YYUNDEFTOK)

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
      45
};

#if YYDEBUG
  /* YYRLINE[YYN] -- Source line where rule number YYN was defined.  */
static const yytype_int16 yyrline[] =
{
       0,    55,    55,    55,    58,    59,    76,    80,    86,    96,
     117,   121,   127,   127,   130,   130,   146,   150,   156,   163,
     174,   177,   182,   185,   192,   195,   208,   212,   218,   222,
     225,   230,   244,   269,   276,   286,   297,   314,   317,   320,
     340,   351,   375,   390,   416,   422,   450,   456,   473,   477,
     499,   503,   533,   551,   557,   571,   591,   604,   615,   621,
     624,   629,   632,   638,   642,   646,   652,   653,   656,   657,
     660,   661,   662,   663,   666,   667,   670,   671,   674,   675,
     676,   679,   680
};
#endif

#if YYDEBUG || YYERROR_VERBOSE || 0
/* YYTNAME[SYMBOL-NUM] -- String name of the symbol SYMBOL-NUM.
   First, the terminals, then, starting at YYNTOKENS, nonterminals.  */
static const char *const yytname[] =
{
  "$end", "error", "$undefined", "WHILE_", "FOR_", "IF_", "ELSE_",
  "PRINT_", "READ_", "RETURN_", "ALLAVE_", "CLLAVE_", "ACORCH_", "CCORCH_",
  "APAREN_", "CPAREN_", "PTOCOMA_", "PTO_", "CMA_", "MAS_", "MENOS_",
  "POR_", "DIV_", "AND_", "OR_", "SUMASIG_", "RESASIG_", "MULASIG_",
  "DIVASIG_", "IGU_", "NOIGU_", "MAYIGU_", "MENIGU_", "INC_", "DEC_",
  "MAY_", "MEN_", "ASIG_", "NOT_", "MOD_", "INT_", "BOOL_", "CTE_",
  "TRUE_", "FALSE_", "ID_", "$accept", "programa", "$@1",
  "listaDeclaraciones", "declaracion", "declaracionVariable", "tipoSimple",
  "declaracionFuncion", "@2", "cabeceraFuncion", "$@3",
  "parametrosFormales", "listaParametrosFormales", "bloque",
  "declaracionVariableLocal", "listaInstrucciones", "instruccion",
  "instruccionAsignacion", "instruccionEntradaSalida",
  "instruccionSeleccion", "instruccionIteracion", "expresionOpcional",
  "expresion", "expresionIgualdad", "expresionRelacional",
  "expresionAditiva", "expresionMultiplicativa", "expresionUnaria",
  "expresionSufija", "parametrosActuales", "listaParametrosActuales",
  "constante", "operadorLogico", "operadorIgualdad", "operadorRelacional",
  "operadorAditivo", "operadorMultiplicativo", "operadorUnario",
  "operadorIncremento", YY_NULLPTR
};
#endif

# ifdef YYPRINT
/* YYTOKNUM[NUM] -- (External) token number corresponding to the
   (internal) symbol number NUM (which must be that of a token).  */
static const yytype_int16 yytoknum[] =
{
       0,   256,   257,   258,   259,   260,   261,   262,   263,   264,
     265,   266,   267,   268,   269,   270,   271,   272,   273,   274,
     275,   276,   277,   278,   279,   280,   281,   282,   283,   284,
     285,   286,   287,   288,   289,   290,   291,   292,   293,   294,
     295,   296,   297,   298,   299,   300
};
# endif

#define YYPACT_NINF (-87)

#define yypact_value_is_default(Yyn) \
  ((Yyn) == YYPACT_NINF)

#define YYTABLE_NINF (-1)

#define yytable_value_is_error(Yyn) \
  0

  /* YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
     STATE-NUM.  */
static const yytype_int16 yypact[] =
{
     -87,    40,    -9,   -87,   -87,   -87,    -9,   -87,   -87,    15,
     -87,   -87,   -87,    45,    39,    50,   -87,    73,   -87,   -87,
      94,    -9,    -9,    49,    80,   113,   -87,   -87,    84,    -3,
     -87,    87,   -87,    45,   116,   117,   118,   119,    34,   -87,
       4,   -87,   -87,   -87,   -87,   -87,    -9,    55,    34,    34,
      89,    34,   -87,   -87,   -87,   -87,   -87,   -87,   -87,   -87,
      52,    79,    51,    86,   100,   102,   -87,   -87,   -87,    34,
      91,    10,    34,    34,   -87,    25,   121,   103,    23,    28,
     120,    67,    34,    34,   -87,   127,   -87,   -87,    34,   -87,
     -87,    34,   -87,   -87,   -87,   -87,    34,   -87,   -87,    34,
     -87,   -87,    34,   -87,   -87,   -87,     6,    85,    34,    34,
      18,   123,   124,   -87,    60,    92,   126,   -87,   -87,    51,
      86,   100,   102,   -87,   105,   -87,   103,    88,   137,   -87,
     -87,   -87,    34,   -87,    34,    55,    18,   -87,    90,   129,
     -87,   -87,    18,   -87
};

  /* YYDEFACT[STATE-NUM] -- Default reduction number in state STATE-NUM.
     Performed when YYTABLE does not specify something else to do.  Zero
     means the default is an error.  */
static const yytype_int8 yydefact[] =
{
       2,     0,     0,     1,    10,    11,     3,     4,     6,     0,
       7,    12,     5,    14,    20,     0,     8,     0,    22,    13,
       0,    16,    24,     0,     0,     0,    17,    23,     0,     0,
       9,    18,    15,     0,     0,     0,     0,     0,     0,    24,
       0,    25,    27,    29,    28,    30,     0,    37,     0,     0,
       0,     0,    78,    79,    81,    82,    80,    63,    64,    65,
      57,     0,    40,    42,    44,    46,    48,    50,    58,     0,
       0,     0,     0,     0,    19,    57,     0,    38,     0,     0,
       0,     0,     0,    59,    54,     0,    66,    67,     0,    68,
      69,     0,    72,    73,    70,    71,     0,    74,    75,     0,
      76,    77,     0,    51,    52,    26,     0,     0,     0,     0,
       0,     0,     0,    53,     0,    61,     0,    60,    21,    41,
      43,    45,    47,    49,     0,    31,    39,     0,     0,    34,
      33,    55,     0,    56,     0,    37,     0,    62,     0,     0,
      35,    32,     0,    36
};

  /* YYPGOTO[NTERM-NUM].  */
static const yytype_int16 yypgoto[] =
{
     -87,   -87,   -87,   -87,   139,   125,   -13,   -87,   -87,   -87,
     -87,   -87,   104,   -87,   -87,   107,   -86,   -87,   -87,   -87,
     -87,    13,   -38,    61,    62,    56,    57,   -66,   -87,   -87,
      19,   -87,   -87,   -87,   -87,   -87,   -87,   -87,   -48
};

  /* YYDEFGOTO[NTERM-NUM].  */
static const yytype_int8 yydefgoto[] =
{
      -1,     1,     2,     6,     7,     8,     9,    10,    14,    11,
      17,    25,    26,    19,    22,    29,    41,    42,    43,    44,
      45,    76,    77,    62,    63,    64,    65,    66,    67,   116,
     117,    68,    88,    91,    96,    99,   102,    69,    70
};

  /* YYTABLE[YYPACT[STATE-NUM]] -- What to do in state STATE-NUM.  If
     positive, shift that token.  If negative, reduce the rule whose
     number is the opposite.  If YYTABLE_NINF, syntax error.  */
static const yytype_uint8 yytable[] =
{
      61,    34,    35,   103,    36,    37,    38,    39,    24,    28,
      78,    79,    84,    81,    34,    35,    72,    36,    37,   124,
      39,   105,    34,    35,   128,    36,    37,    84,    39,    86,
      87,     4,     5,    24,   106,   107,   123,    82,   110,    83,
       3,    73,    40,   111,   114,   115,    86,    87,    51,    18,
     140,    86,    87,    52,    53,    40,   143,    15,    54,    55,
      13,    16,   108,    40,    82,    30,    83,    54,    55,    51,
     126,   127,    56,   131,    52,    53,    57,    58,    59,    60,
      89,    90,   113,    86,    87,    54,    55,    21,    54,    55,
      86,    87,    20,    56,   115,    85,   138,    57,    58,    59,
      75,   125,    86,    87,   135,    46,   141,    23,    86,    87,
     132,    86,    87,    86,    87,    86,    87,    92,    93,    97,
      98,    94,    95,   100,   101,    31,    86,    87,    32,    33,
      47,    48,    49,    50,    80,   112,   104,   109,   118,   129,
     130,   133,   134,   136,   142,    12,    71,    27,   139,   119,
      74,   137,   121,   120,     0,     0,   122
};

static const yytype_int16 yycheck[] =
{
      38,     4,     5,    69,     7,     8,     9,    10,    21,    22,
      48,    49,    60,    51,     4,     5,    12,     7,     8,    13,
      10,    11,     4,     5,   110,     7,     8,    75,    10,    23,
      24,    40,    41,    46,    72,    73,   102,    12,    15,    14,
       0,    37,    45,    15,    82,    83,    23,    24,    14,    10,
     136,    23,    24,    19,    20,    45,   142,    12,    33,    34,
      45,    16,    37,    45,    12,    16,    14,    33,    34,    14,
     108,   109,    38,    13,    19,    20,    42,    43,    44,    45,
      29,    30,    15,    23,    24,    33,    34,    14,    33,    34,
      23,    24,    42,    38,   132,    16,   134,    42,    43,    44,
      45,    16,    23,    24,    16,    18,    16,    13,    23,    24,
      18,    23,    24,    23,    24,    23,    24,    31,    32,    19,
      20,    35,    36,    21,    22,    45,    23,    24,    15,    45,
      14,    14,    14,    14,    45,    15,    45,    16,    11,    16,
      16,    15,    37,     6,    15,     6,    39,    22,   135,    88,
      46,   132,    96,    91,    -1,    -1,    99
};

  /* YYSTOS[STATE-NUM] -- The (internal number of the) accessing
     symbol of state STATE-NUM.  */
static const yytype_int8 yystos[] =
{
       0,    47,    48,     0,    40,    41,    49,    50,    51,    52,
      53,    55,    50,    45,    54,    12,    16,    56,    10,    59,
      42,    14,    60,    13,    52,    57,    58,    51,    52,    61,
      16,    45,    15,    45,     4,     5,     7,     8,     9,    10,
      45,    62,    63,    64,    65,    66,    18,    14,    14,    14,
      14,    14,    19,    20,    33,    34,    38,    42,    43,    44,
      45,    68,    69,    70,    71,    72,    73,    74,    77,    83,
      84,    61,    12,    37,    58,    45,    67,    68,    68,    68,
      45,    68,    12,    14,    84,    16,    23,    24,    78,    29,
      30,    79,    31,    32,    35,    36,    80,    19,    20,    81,
      21,    22,    82,    73,    45,    11,    68,    68,    37,    16,
      15,    15,    15,    15,    68,    68,    75,    76,    11,    69,
      70,    71,    72,    73,    13,    16,    68,    68,    62,    16,
      16,    13,    18,    15,    37,    16,     6,    76,    68,    67,
      62,    16,    15,    62
};

  /* YYR1[YYN] -- Symbol number of symbol that rule YYN derives.  */
static const yytype_int8 yyr1[] =
{
       0,    46,    48,    47,    49,    49,    50,    50,    51,    51,
      52,    52,    54,    53,    56,    55,    57,    57,    58,    58,
      59,    59,    60,    60,    61,    61,    62,    62,    62,    62,
      62,    63,    63,    64,    64,    65,    66,    67,    67,    67,
      68,    68,    69,    69,    70,    70,    71,    71,    72,    72,
      73,    73,    73,    74,    74,    74,    74,    74,    74,    75,
      75,    76,    76,    77,    77,    77,    78,    78,    79,    79,
      80,    80,    80,    80,    81,    81,    82,    82,    83,    83,
      83,    84,    84
};

  /* YYR2[YYN] -- Number of symbols on the right hand side of rule YYN.  */
static const yytype_int8 yyr2[] =
{
       0,     2,     0,     2,     1,     2,     1,     1,     3,     6,
       1,     1,     0,     3,     0,     6,     0,     1,     2,     4,
       0,     7,     0,     2,     0,     2,     3,     1,     1,     1,
       1,     4,     7,     5,     5,     7,     9,     0,     1,     3,
       1,     3,     1,     3,     1,     3,     1,     3,     1,     3,
       1,     2,     2,     3,     2,     4,     4,     1,     1,     0,
       1,     1,     3,     1,     1,     1,     1,     1,     1,     1,
       1,     1,     1,     1,     1,     1,     1,     1,     1,     1,
       1,     1,     1
};


#define yyerrok         (yyerrstatus = 0)
#define yyclearin       (yychar = YYEMPTY)
#define YYEMPTY         (-2)
#define YYEOF           0

#define YYACCEPT        goto yyacceptlab
#define YYABORT         goto yyabortlab
#define YYERROR         goto yyerrorlab


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
  YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
  YYUSE (yytype);
  YY_IGNORE_MAYBE_UNINITIALIZED_END
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
yy_reduce_print (yy_state_t *yyssp, YYSTYPE *yyvsp, int yyrule)
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
                       yystos[+yyssp[yyi + 1 - yynrhs]],
                       &yyvsp[(yyi + 1) - (yynrhs)]
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
#   define yystrlen(S) (YY_CAST (YYPTRDIFF_T, strlen (S)))
#  else
/* Return the length of YYSTR.  */
static YYPTRDIFF_T
yystrlen (const char *yystr)
{
  YYPTRDIFF_T yylen;
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
# endif

/* Copy into *YYMSG, which is of size *YYMSG_ALLOC, an error message
   about the unexpected token YYTOKEN for the state stack whose top is
   YYSSP.

   Return 0 if *YYMSG was successfully written.  Return 1 if *YYMSG is
   not large enough to hold the message.  In that case, also set
   *YYMSG_ALLOC to the required number of bytes.  Return 2 if the
   required number of bytes is too large to store.  */
static int
yysyntax_error (YYPTRDIFF_T *yymsg_alloc, char **yymsg,
                yy_state_t *yyssp, int yytoken)
{
  enum { YYERROR_VERBOSE_ARGS_MAXIMUM = 5 };
  /* Internationalized format string. */
  const char *yyformat = YY_NULLPTR;
  /* Arguments of yyformat: reported tokens (one for the "unexpected",
     one per "expected"). */
  char const *yyarg[YYERROR_VERBOSE_ARGS_MAXIMUM];
  /* Actual size of YYARG. */
  int yycount = 0;
  /* Cumulated lengths of YYARG.  */
  YYPTRDIFF_T yysize = 0;

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
      int yyn = yypact[+*yyssp];
      YYPTRDIFF_T yysize0 = yytnamerr (YY_NULLPTR, yytname[yytoken]);
      yysize = yysize0;
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
                  YYPTRDIFF_T yysize1
                    = yysize + yytnamerr (YY_NULLPTR, yytname[yyx]);
                  if (yysize <= yysize1 && yysize1 <= YYSTACK_ALLOC_MAXIMUM)
                    yysize = yysize1;
                  else
                    return 2;
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
    /* Don't count the "%s"s in the final size, but reserve room for
       the terminator.  */
    YYPTRDIFF_T yysize1 = yysize + (yystrlen (yyformat) - 2 * yycount) + 1;
    if (yysize <= yysize1 && yysize1 <= YYSTACK_ALLOC_MAXIMUM)
      yysize = yysize1;
    else
      return 2;
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
          ++yyp;
          ++yyformat;
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
    yy_state_fast_t yystate;
    /* Number of tokens to shift before error messages enabled.  */
    int yyerrstatus;

    /* The stacks and their tools:
       'yyss': related to states.
       'yyvs': related to semantic values.

       Refer to the stacks through separate pointers, to allow yyoverflow
       to reallocate them elsewhere.  */

    /* The state stack.  */
    yy_state_t yyssa[YYINITDEPTH];
    yy_state_t *yyss;
    yy_state_t *yyssp;

    /* The semantic value stack.  */
    YYSTYPE yyvsa[YYINITDEPTH];
    YYSTYPE *yyvs;
    YYSTYPE *yyvsp;

    YYPTRDIFF_T yystacksize;

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
  YYPTRDIFF_T yymsg_alloc = sizeof yymsgbuf;
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

  if (yyss + yystacksize - 1 <= yyssp)
#if !defined yyoverflow && !defined YYSTACK_RELOCATE
    goto yyexhaustedlab;
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
        goto yyexhaustedlab;
      yystacksize *= 2;
      if (YYMAXDEPTH < yystacksize)
        yystacksize = YYMAXDEPTH;

      {
        yy_state_t *yyss1 = yyss;
        union yyalloc *yyptr =
          YY_CAST (union yyalloc *,
                   YYSTACK_ALLOC (YY_CAST (YYSIZE_T, YYSTACK_BYTES (yystacksize))));
        if (! yyptr)
          goto yyexhaustedlab;
        YYSTACK_RELOCATE (yyss_alloc, yyss);
        YYSTACK_RELOCATE (yyvs_alloc, yyvs);
# undef YYSTACK_RELOCATE
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
  case 2:
#line 55 "src/asin.y"
                                 { niv = GLOBAL; dvar = 0; cargaContexto(niv); if(verTdS) mostrarTdS(); }
#line 1479 "asin.c"
    break;

  case 3:
#line 55 "src/asin.y"
                                                                                                                             { if((yyvsp[0].exp).t == 0) yyerror("El programa no tiene main. 2");}
#line 1485 "asin.c"
    break;

  case 4:
#line 58 "src/asin.y"
                                              { (yyval.exp).t = (yyvsp[0].exp).t; }
#line 1491 "asin.c"
    break;

  case 5:
#line 59 "src/asin.y"
                                                                {
                                    printf("LUGMANSITO69 CHORREA FUERTE 1: %d    2:  %d ", (yyvsp[-1].exp).t, (yyvsp[0].exp).t);
                                    yyerror("\n");
                                    if((yyvsp[-1].exp).t == 0 && (yyvsp[0].exp).t == 0){
                                        yyerror("El programa no tiene main.");
                                    }        
                                    else{
                                        if((yyvsp[0].exp).t == 0){
                                            (yyval.exp).t = (yyvsp[-1].exp).t;
                                        }   
                                        else{
                                            (yyval.exp).t = (yyvsp[0].exp).t;
                                        }
                                    } 
                                  }
#line 1511 "asin.c"
    break;

  case 6:
#line 76 "src/asin.y"
                                                     {
                                        dvar = dvar + (yyvsp[0].str).talla;
                                        (yyval.exp).t = (yyvsp[0].str).t;
                                    }
#line 1520 "asin.c"
    break;

  case 7:
#line 80 "src/asin.y"
                                                    {
                                        dvar = dvar + (yyvsp[0].str).talla;
                                        (yyval.exp).t = (yyvsp[0].str).t;
                                    }
#line 1529 "asin.c"
    break;

  case 8:
#line 86 "src/asin.y"
                                                         {
                                        if(insTdS((yyvsp[-1].ident),VARIABLE,(yyvsp[-2].str).t,niv,dvar,-1)){
                                            (yyval.str).n = (yyvsp[-1].ident);
                                            (yyval.str).talla = (yyval.str).talla + TALLA_TIPO_SIMPLE;
                                            (yyval.str).t = (yyvsp[-2].str).t;
                                        }else{
                                            (yyval.str).t = T_ERROR;
                                            yyerror("Identificador repetido");
                                        }
                                    }
#line 1544 "asin.c"
    break;

  case 9:
#line 96 "src/asin.y"
                                                                              {
                                        int numelem = (yyvsp[-2].cent);
                                        if(numelem <= 0){
                                            yyerror("Talla inapropiada del array");
                                            numelem = 0;
                                        }
                                        else{
                                            int refe = insTdA((yyvsp[-5].str).t, numelem);
                                            if(insTdS((yyvsp[-4].ident),VARIABLE,T_ARRAY,niv,dvar,refe)){
                                                (yyval.str).n = (yyvsp[-4].ident);
                                                (yyval.str).t = (yyvsp[-5].str).t;
                                                (yyval.str).talla = (yyval.str).talla + numelem * TALLA_TIPO_SIMPLE;
                                            }
                                            else{
                                                yyerror("Identificador repetido");
                                            }
                                        }
                                         mostrarTdS();
                                    }
#line 1568 "asin.c"
    break;

  case 10:
#line 117 "src/asin.y"
                                       {                                   
                                    (yyval.str).t = T_ENTERO;
                                    (yyval.str).talla = TALLA_TIPO_SIMPLE;
                                    }
#line 1577 "asin.c"
    break;

  case 11:
#line 121 "src/asin.y"
                                       {
                                    (yyval.str).t = T_LOGICO;
                                    (yyval.str).talla = TALLA_TIPO_SIMPLE;
                                    }
#line 1586 "asin.c"
    break;

  case 12:
#line 127 "src/asin.y"
                                                  { (yyval.cent) = dvar; dvar = 0; }
#line 1592 "asin.c"
    break;

  case 13:
#line 127 "src/asin.y"
                                                                                        { descargaContexto(niv); niv = GLOBAL; dvar = (yyvsp[-1].cent); }
#line 1598 "asin.c"
    break;

  case 14:
#line 130 "src/asin.y"
                                                 { niv = LOCAL; cargaContexto(niv);}
#line 1604 "asin.c"
    break;

  case 15:
#line 130 "src/asin.y"
                                                                                                                       { 
                                        //mostrarTdS();
                                        if(insTdS((yyvsp[-4].ident),FUNCION,(yyvsp[-5].str).t,niv,(yyvsp[-1].str).talla,-1)){
                                           (yyval.str).n = (yyvsp[-4].ident);
                                           (yyval.str).t = (yyvsp[-5].str).t;
                                           (yyval.str).talla = (yyvsp[-1].str).talla;   
                                       }
                                       else{
                                           (yyval.str).t = T_ERROR;
                                           yyerror("Ya existe variable, se ha declarado previamente");
                                       }
                                       //mostrarTdS();
                                      
                                    }
#line 1623 "asin.c"
    break;

  case 16:
#line 146 "src/asin.y"
                                             {
                                        (yyval.str).t = T_VACIO;
                                        (yyval.str).talla = 0;
                                    }
#line 1632 "asin.c"
    break;

  case 17:
#line 150 "src/asin.y"
                                                         {
                                        (yyval.str).t = (yyvsp[0].str).t;
                                        (yyval.str).talla =  (yyval.str).talla - TALLA_SEGENLACES;
                                    }
#line 1641 "asin.c"
    break;

  case 18:
#line 156 "src/asin.y"
                                                {
                                    (yyval.str).t = (yyvsp[-1].str).t;
                                    (yyval.str).talla = TALLA_SEGENLACES + (yyvsp[-1].str).talla;
                                    int ref = insTdD(-1,(yyvsp[-1].str).t);
                                    (yyval.str).refe = ref; 
                                    insTdS((yyvsp[0].ident),PARAMETRO,(yyvsp[-1].str).t,niv,-(yyval.str).talla,ref);
                                }
#line 1653 "asin.c"
    break;

  case 19:
#line 163 "src/asin.y"
                                                                             {
                                     if((yyvsp[-3].str).t == (yyvsp[0].str).t && (yyvsp[-3].str).t != T_ERROR){
                                         (yyval.str).t == (yyvsp[-3].str).t;
                                         (yyval.str).talla = (yyvsp[0].str).talla + (yyvsp[-3].str).talla;
                                         
                                         int ref = insTdD((yyvsp[0].str).refe, (yyvsp[-3].str).t);
                                         insTdS((yyvsp[-2].ident),PARAMETRO,(yyvsp[-3].str).t,niv,-(yyval.str).talla,ref);
                                     }
                                }
#line 1667 "asin.c"
    break;

  case 20:
#line 174 "src/asin.y"
                                  {
                                    /* vacio */
                                }
#line 1675 "asin.c"
    break;

  case 21:
#line 177 "src/asin.y"
                                                                                                                        {
                                    /* vacio */
                                }
#line 1683 "asin.c"
    break;

  case 22:
#line 182 "src/asin.y"
                                              {

                                }
#line 1691 "asin.c"
    break;

  case 23:
#line 185 "src/asin.y"
                                                                              {
                                        if(insTdS((yyvsp[-1].str).n,VARIABLE,(yyvsp[0].str).t,niv,dvar,-1)){
                                          dvar += TALLA_TIPO_SIMPLE;
                                        }
                                    }
#line 1701 "asin.c"
    break;

  case 24:
#line 192 "src/asin.y"
                                             {
                                    (yyval.mat).t = T_VACIO;
                                }
#line 1709 "asin.c"
    break;

  case 25:
#line 195 "src/asin.y"
                                                                {
                                    printf("VALORES $1 %d      $2 %d ",(yyvsp[-1].mat).t, (yyvsp[0].mat).t);
                                    yyerror("\n");
                                    if((yyvsp[-1].mat).t != T_ERROR && (yyvsp[0].mat).t != T_ERROR){
                                        (yyval.mat).t = (yyvsp[-1].mat).t;
                                        (yyval.mat).v = (yyvsp[-1].mat).v;
                                    }else{
                                        (yyval.mat).t = T_ERROR;
                                        yyerror("Error de tipo");
                                    } 
                                }
#line 1725 "asin.c"
    break;

  case 26:
#line 208 "src/asin.y"
                                                                    {
                                    (yyval.mat).t = (yyvsp[-1].mat).t;
                                    (yyval.mat).v = (yyvsp[-1].mat).v;
                                }
#line 1734 "asin.c"
    break;

  case 27:
#line 213 "src/asin.y"
                                {
                                    (yyval.mat).t = (yyvsp[0].mat).t;
                                    (yyval.mat).v = (yyvsp[0].mat).v;
                                    mostrarTdS();
                                }
#line 1744 "asin.c"
    break;

  case 28:
#line 218 "src/asin.y"
                                                      {
                                    (yyval.mat).t = (yyvsp[0].mat).t;
                                    (yyval.mat).v = (yyvsp[0].mat).v;
                                }
#line 1753 "asin.c"
    break;

  case 29:
#line 222 "src/asin.y"
                                                          {
                                    (yyval.mat).t = (yyvsp[0].mat).t;
                                }
#line 1761 "asin.c"
    break;

  case 30:
#line 225 "src/asin.y"
                                                      {
                                    
                                }
#line 1769 "asin.c"
    break;

  case 31:
#line 230 "src/asin.y"
                                                              {
                                        SIMB simb = obtTdS((yyvsp[-3].ident));
                                        if(simb.t == T_ERROR){
                                            (yyval.mat).t = T_ERROR;
                                            yyerror("Objeto no declarado");
                                        }
                                        else if (!((simb.t == (yyvsp[-1].mat).t) && ((yyvsp[-1].mat).t == T_ENTERO || (yyvsp[-1].mat).t == T_LOGICO))){
                                            (yyval.mat).t = T_ERROR;
                                            yyerror("Error de tipos en la <asignacion>");
                                        } else{
                                            (yyval.mat).v = (yyvsp[-1].mat).v;
                                            (yyval.mat).t = (yyvsp[-1].mat).t;
                                        }
                                    }
#line 1788 "asin.c"
    break;

  case 32:
#line 244 "src/asin.y"
                                                                                        {
                                        SIMB simb = obtTdS((yyvsp[-6].ident));
                                        if(simb.t == T_ERROR){
                                            (yyval.mat).t = T_ERROR;
                                            yyerror("Objeto no declarado");
                                        }
                                        else if(! ((yyvsp[-4].mat).t == T_ENTERO)){
                                            (yyval.mat).t = T_ERROR;
                                            yyerror("El indice del <array> debe ser entero");
                                        } 
                                        else if (! (simb.t == (yyvsp[-1].mat).t)){
                                            (yyval.mat).t = T_ERROR;
                                            yyerror("Error de tipos en la <asignacion>");
                                        }
                                        else if( ! (simb.t == T_ARRAY)){
                                            (yyval.mat).t = T_ERROR;
                                            yyerror("El identificado debe ser de tipo <array>");
                                        }
                                        else{
                                            (yyval.mat).t = simb.t;
                                        }  
                                            
                                    }
#line 1816 "asin.c"
    break;

  case 33:
#line 269 "src/asin.y"
                                                                    {
                                    SIMB sim = obtTdS((yyvsp[-2].ident));
                                    if (sim.t != T_ENTERO) {
                                        (yyval.mat).t = T_ERROR;
                                        yyerror("identificador no valido para la instruccion entrada : se esperaba identificador entero");
                                    }
                                }
#line 1828 "asin.c"
    break;

  case 34:
#line 276 "src/asin.y"
                                                                           {
                                    if ((yyvsp[-2].mat).t != T_ERROR) { 
                                        if ((yyvsp[-2].mat).t != T_ENTERO) {
                                            (yyval.mat).t = T_ERROR;
                                            yyerror("expresion no valida para la instruccion salida : se esperaba expresion entera");
                                        } 
                                    }
                                }
#line 1841 "asin.c"
    break;

  case 35:
#line 286 "src/asin.y"
                                                                                             {
                                    if((yyvsp[-4].mat).t != T_ERROR){
                                        if((yyvsp[-4].mat).t != T_LOGICO){
                                            (yyval.mat).t = T_ERROR;
                                            yyerror("expresion no valida para la instruccion seleccion : se esperaba una expresion logica");
                                        }
                                    }
                                    
                                }
#line 1855 "asin.c"
    break;

  case 36:
#line 297 "src/asin.y"
                                                                                                                                  {
                                        if((yyvsp[-4].mat).t == T_LOGICO){
                                            if(((yyvsp[-6].exp).t != T_ERROR || (yyvsp[-6].exp).t == T_VACIO ) && ((yyvsp[-2].exp).t != T_ERROR || (yyvsp[-2].exp).t == T_VACIO )){

                                            }
                                            else{
                                                (yyval.mat).t = T_ERROR;
                                                yyerror("Instrucción mal formada");
                                            }
                                        }
                                        else{
                                            (yyval.mat).t = T_ERROR;
                                            yyerror("Error en el operador lógico");
                                        }
                                    }
#line 1875 "asin.c"
    break;

  case 37:
#line 314 "src/asin.y"
                                                {

                                }
#line 1883 "asin.c"
    break;

  case 38:
#line 317 "src/asin.y"
                                           {
                                    (yyval.exp).t = (yyvsp[0].mat).t;
                                }
#line 1891 "asin.c"
    break;

  case 39:
#line 320 "src/asin.y"
                                                     {
                                    SIMB simb = obtTdS((yyvsp[-2].ident));
                                    if (simb.t == T_ERROR) {
                                        (yyval.exp).t = T_ERROR;
                                        yyerror("identificador no declarado : es necesario declararlo antes de utilizarlo");
                                    } 
                                    else{
                                        if ((yyvsp[0].mat).t != T_ERROR) {
                                            if((simb.t != (yyvsp[0].mat).t) || (simb.t == (yyvsp[0].mat).t && simb.t != T_ENTERO && simb.t != T_LOGICO)) {
                                                (yyval.exp).t = T_ERROR;
                                                yyerror("identificador o expresion no valida para la expresion : se esperaba un identificador y una expresion del mismo tipo");
                                            } 
                                            else {
                                                (yyval.exp).t = simb.t;
                                            }
                                        }
                                    } 
                                }
#line 1914 "asin.c"
    break;

  case 40:
#line 340 "src/asin.y"
                                                   {
                                    if ((yyvsp[0].mat).t != T_LOGICO && (yyvsp[0].mat).t != T_ENTERO ) {
                                        (yyval.mat).t = T_ERROR;
                                        yyerror("Error en <expresion logica 1>");
                                    }else{
                                        (yyval.mat).t = (yyvsp[0].mat).t;
                                        (yyval.mat).v = (yyvsp[0].mat).v;
                                        printf("ESTOY AQUI %d", (yyvsp[0].mat).v);
                                    }                                        
                                
                                }
#line 1930 "asin.c"
    break;

  case 41:
#line 351 "src/asin.y"
                                                                            {
                                    if ((yyvsp[-2].mat).t != T_ERROR && (yyvsp[0].mat).t != T_ERROR) {
                                        if ((yyvsp[-2].mat).t != T_LOGICO) {
                                            (yyval.mat).t = T_ERROR;
                                            yyerror("expresion igualdad no valida para la expresion igualdad : se esperaba una expresion igualdad de tipo logica o entera");
                                        } else if ((yyvsp[0].mat).t != T_LOGICO){
                                            (yyval.mat).t = T_ERROR;
                                            yyerror("Error en <expresion logica 2>");
                                        } if ((yyvsp[-2].mat).t != (yyvsp[0].mat).t) {
                                            (yyval.mat).t = T_ERROR;
                                            yyerror("expresion igualdad o expresion relacional no valida para la expresion igualdad : se esperaba una expresion igualdad y una expresion relacional del mismo tipo");
                                        }
                                    } 
                                    else { 
                                        if((yyvsp[-1].cent) == AND_)
                                            (yyval.mat).v = (yyvsp[-2].mat).v && (yyvsp[0].mat).v;
                                        if((yyvsp[-1].cent) == OR_)
                                            (yyval.mat).v = (yyvsp[-2].mat).v || (yyvsp[0].mat).v;

                                        (yyval.mat).t = T_LOGICO;                                        
                                    }   
                                }
#line 1957 "asin.c"
    break;

  case 42:
#line 375 "src/asin.y"
                                                     {
                                    if((yyvsp[0].mat).t != T_LOGICO && (yyvsp[0].mat).t != T_ENTERO)
                                    {   
                                        (yyval.mat).t = T_ERROR;
                                        yyerror("expresion igualdad no valida para la expresion igualdad : se esperaba una expresion igualdad de tipo logica");
                                    } 
                                    else
                                    {
                                        (yyval.mat).t = (yyvsp[0].mat).t;
                                        (yyval.mat).v = (yyvsp[0].mat).v; 
                                        printf("\tSOY FAMOSOOO %d", (yyvsp[0].mat).v);
                                        yyerror("\n");
                                    }  
                                        
                                }
#line 1977 "asin.c"
    break;

  case 43:
#line 390 "src/asin.y"
                                                                                        {
                                    if ((yyvsp[-2].mat).t != T_ERROR && (yyvsp[0].mat).t != T_ERROR) {
                                        if ((yyvsp[-2].mat).t != T_LOGICO && (yyvsp[-2].mat).t != T_ENTERO ) {
                                            (yyval.mat).t = T_ERROR;
                                            yyerror("expresion igualdad no valida para la expresion igualdad : se esperaba una expresion igualdad de tipo logica o entera");
                                        } else if ((yyvsp[0].mat).t != T_LOGICO && (yyvsp[0].mat).t != T_ENTERO) {
                                            (yyval.mat).t = T_ERROR;
                                            yyerror("expresion relacional no valida para la expresion igualdad : se esperaba una expresion relacional de tipo logica o entera");
                                        } if ((yyvsp[-2].mat).t != (yyvsp[0].mat).t) {
                                            (yyval.mat).t = T_ERROR;
                                            yyerror("expresion igualdad o expresion relacional no valida para la expresion igualdad : se esperaba una expresion igualdad y una expresion relacional del mismo tipo");
                                        }
                                    } 
                                    else { 
                                        if((yyvsp[-1].cent) == IGU_)
                                        {
                                            (yyval.mat).v = (yyvsp[-2].mat).v == (yyvsp[0].mat).v;
                                        }else{
                                            (yyval.mat).v = (yyvsp[-2].mat).v != (yyvsp[0].mat).v;
                                        } 
                                        
                                        (yyval.mat).t = (yyvsp[-2].mat).t;
                                    }                                     
                                }
#line 2006 "asin.c"
    break;

  case 44:
#line 416 "src/asin.y"
                                                   {
                                    (yyval.mat).t = (yyvsp[0].mat).t; 
                                    (yyval.mat).v = (yyvsp[0].mat).v;
                                    printf("\tSOY YOUTUBER %d", (yyvsp[0].mat).v);
                                        yyerror("\n");
                                }
#line 2017 "asin.c"
    break;

  case 45:
#line 422 "src/asin.y"
                                                                                         {
                                    if ((yyvsp[-2].mat).t != T_ERROR && (yyvsp[0].mat).t != T_ERROR) {
                                        if ((yyvsp[-2].mat).t == T_ENTERO && (yyvsp[-2].mat).t==(yyvsp[0].mat).t) {
                                              (yyval.mat).t = T_ENTERO;
                                              switch((yyvsp[-1].cent))
                                                {
                                                    case MAYIGU_:
                                                        (yyval.mat).v = (yyvsp[-2].mat).v >= (yyvsp[0].mat).v;
                                                        break; 
                                                    case MENIGU_:
                                                        (yyval.mat).v = (yyvsp[-2].mat).v <= (yyvsp[0].mat).v;
                                                        break;
                                                    case MAY_:
                                                        (yyval.mat).v = (yyvsp[-2].mat).v > (yyvsp[0].mat).v;
                                                        break;  
                                                    case MEN_:
                                                        (yyval.mat).v = (yyvsp[-2].mat).v < (yyvsp[0].mat).v;
                                                        break;  
                                                } 

                                        } 
                                    else { 
                                        (yyval.mat).t = T_ERROR;
                                        yyerror("Error en expresionRelacional : operandos nos son de tipo entero.");
                                    }                                      
                                    }
                                }
#line 2049 "asin.c"
    break;

  case 46:
#line 450 "src/asin.y"
                                                            {
                                        printf("\tTENGO 1 M DE SUBS %i", (yyvsp[0].mat).v);
                                        yyerror("\n");
                                    (yyval.mat).t = (yyvsp[0].mat).t; 
                                    (yyval.mat).v = (yyvsp[0].mat).v;
                                }
#line 2060 "asin.c"
    break;

  case 47:
#line 456 "src/asin.y"
                                                                                          {
                                    printf("##############################n\t %d %d ", (yyvsp[-2].mat).v,(yyvsp[0].mat).v);
                                        yyerror("\n");
                                    if ((yyvsp[-2].mat).t == (yyvsp[0].mat).t && (yyvsp[0].mat).t == T_ENTERO){
                                        (yyval.mat).t = T_ENTERO;
                                        if((yyvsp[-1].cent) == MAS_)
                                            (yyval.mat).v = (yyvsp[-2].mat).v + (yyvsp[0].mat).v;
                                        else
                                            (yyval.mat).v = (yyvsp[-2].mat).v - (yyvsp[0].mat).v;
                                    } 
                                    else{
                                        (yyval.mat).t = T_ERROR;
                                        yyerror("Error de tipos en la expresion aditiva");
                                    }
                                }
#line 2080 "asin.c"
    break;

  case 48:
#line 473 "src/asin.y"
                                                 {
                                        (yyval.mat).t = (yyvsp[0].mat).t;
                                        (yyval.mat).v = (yyvsp[0].mat).v;
                                }
#line 2089 "asin.c"
    break;

  case 49:
#line 477 "src/asin.y"
                                                                                                {
                                    if ((yyvsp[-2].mat).t == T_ENTERO && (yyvsp[0].mat).t == T_ENTERO) {
                                        (yyval.mat).t = (yyvsp[-2].mat).t;
                                        printf("\tSOY UNICO %i", (yyvsp[-2].mat).v);
                                        yyerror("\n");
                                        printf("\tSOY UNICO TAMBIEN %i", (yyvsp[0].mat).v);
                                        yyerror("\n");
                                        if((yyvsp[-1].cent)==DIV_)
                                        {
                                            (yyval.mat).v = (yyvsp[-2].mat).v / (yyvsp[0].mat).v;
                                        }else
                                        {
                                            (yyval.mat).v = (yyvsp[-2].mat).v * (yyvsp[0].mat).v;
                                        }                          
                                    }
                                    else{
                                        (yyval.mat).t = T_ERROR;
                                        yyerror("Error en expresion multiplicativa");
                                    } 
                                }
#line 2114 "asin.c"
    break;

  case 50:
#line 499 "src/asin.y"
                                                 {
                                    (yyval.mat).t = (yyvsp[0].mat).t;
                                    (yyval.mat).v = (yyvsp[0].mat).v;
                                }
#line 2123 "asin.c"
    break;

  case 51:
#line 503 "src/asin.y"
                                                                {
                                    if ((yyvsp[0].mat).t != T_ERROR) {
                                        if ((yyvsp[-1].cent) == NOT_) {
                                            if ((yyvsp[0].mat).t != T_LOGICO) {
                                                (yyval.mat).t = T_ERROR;
                                            } else { 
                                                (yyval.mat).t = (yyvsp[0].mat).t;
                                                (yyval.mat).v = !(yyvsp[0].mat).v;
                                            }  
                                        } 
                                        else {
                                            if ((yyvsp[0].mat).t != T_ENTERO) {
                                                (yyval.mat).t = T_ERROR;
                                            } else { 
                                                (yyval.mat).t = (yyvsp[0].mat).t;
                                                if((yyvsp[-1].cent) == MAS_)
                                                {
                                                    (yyval.mat).v = (yyvsp[0].mat).v;
                                                } else
                                                {
                                                    (yyval.mat).v = -(yyvsp[0].mat).v;
                                                } 
                                            } 
                                        }                                     
                                    }   

                                    if((yyval.mat).t == T_ERROR){
                                        yyerror("Error en expresion unaria, tipo no valido");
                                    }                                 
                                }
#line 2158 "asin.c"
    break;

  case 52:
#line 533 "src/asin.y"
                                                         {
                                    //$$.t = T_ERROR;
                                    SIMB simb = obtTdS((yyvsp[0].ident));
                                    if (simb.t == T_ERROR) {
                                        (yyval.mat).t = T_ERROR;
                                        yyerror("identificador no declarado : declarelo antes de utilizarlo");
                                    }
                                    else{
                                        (yyval.mat).t = simb.t;
                                        if((yyvsp[-1].cent) == INC_)
                                            (yyval.mat).v = (yyval.mat).v + 1;
                                        else
                                            (yyval.mat).v = (yyval.mat).v - 1;
                                    }                                                   
                                }
#line 2178 "asin.c"
    break;

  case 53:
#line 551 "src/asin.y"
                                                            {
                                        printf("\tCIERRA PARENTESIS %i", (yyvsp[-1].mat).t);
                                        yyerror("\n");
                                        (yyval.mat).t = (yyvsp[-1].mat).t;
                                        (yyval.mat).v = (yyvsp[-1].mat).v;
                                    }
#line 2189 "asin.c"
    break;

  case 54:
#line 557 "src/asin.y"
                                                        {
                                        //$$.t = T_ERROR;
                                        SIMB simb = obtTdS((yyvsp[-1].ident));
                                        if(simb.t == T_ERROR){
                                            (yyval.mat).t = T_ERROR;
                                            yyerror("identificador no declarado.");
                                        }else if(simb.t != T_ENTERO){
                                            (yyval.mat).t = T_ERROR;
                                            yyerror("identificador no valido, unicamente valido con tipo int");
                                        }else{
                                            (yyval.mat).t = simb.t;
                                            (yyval.mat).v = (yyval.mat).v +1;
                                        }
                                    }
#line 2208 "asin.c"
    break;

  case 55:
#line 571 "src/asin.y"
                                                               {
                                        //$$.t = T_ERROR;
                                        SIMB simb = obtTdS((yyvsp[-3].ident));
                                        if(simb.t == T_ERROR){
                                            (yyval.mat).t = T_ERROR;
                                            yyerror("identificador no declarado.");
                                        }else if(simb.t != T_ERROR){
                                            if((yyvsp[-1].mat).t != T_ENTERO){
                                                (yyval.mat).t = T_ERROR;
                                                yyerror("expresion no valida : se espera tipo int");
                                            }
                                            if(simb.t != T_ARRAY){
                                                (yyval.mat).t = T_ERROR;
                                                yyerror("identificador no valido : se espera tipo array");
                                            }
                                            if((yyvsp[-1].mat).t == T_ENTERO && simb.t == T_ARRAY){
                                                    (yyval.mat).t = simb.t;
                                            } 
                                        }
                                    }
#line 2233 "asin.c"
    break;

  case 56:
#line 591 "src/asin.y"
                                                                        {
                                        //$$.t = T_ERROR;
                                        SIMB simb = obtTdS((yyvsp[-3].ident));
                                        if(simb.t != T_ENTERO && simb.t != T_LOGICO){
                                            (yyval.mat).t = T_ERROR;
                                            yyerror("inconsistencia de tipos : identificador y parametros actuales no son del mismo tipo");
                                        }else if(simb.t != (yyvsp[-1].cent)){
                                            (yyval.mat).t = T_ERROR;
                                            yyerror("identificador no valido : no corresponde con el tipo de parametros actuales");
                                        }else{
                                            (yyval.mat).t = simb.t;
                                        }
                                    }
#line 2251 "asin.c"
    break;

  case 57:
#line 604 "src/asin.y"
                                      {
                                        //$$.t = T_ERROR;
                                        SIMB simb = obtTdS((yyvsp[0].ident));
                                        if (simb.t == T_ERROR) {
                                            (yyval.mat).t = T_ERROR;
                                            yyerror("identificador no declarado : declarelo antes de utilizarlo");
                                        } 
                                        else {
                                            (yyval.mat).t = simb.t;
                                        }
                                    }
#line 2267 "asin.c"
    break;

  case 58:
#line 615 "src/asin.y"
                                           {
                                        (yyval.mat).t = (yyvsp[0].mat).t;
                                        (yyval.mat).v = (yyvsp[0].mat).v;
                                    }
#line 2276 "asin.c"
    break;

  case 59:
#line 621 "src/asin.y"
                                                {
                                    (yyval.cent) = T_VACIO;
                                }
#line 2284 "asin.c"
    break;

  case 60:
#line 624 "src/asin.y"
                                                         {
                                    (yyval.cent) = (yyvsp[0].str).t;
                                }
#line 2292 "asin.c"
    break;

  case 61:
#line 629 "src/asin.y"
                                           {

                                }
#line 2300 "asin.c"
    break;

  case 62:
#line 632 "src/asin.y"
                                                                        {

                                }
#line 2308 "asin.c"
    break;

  case 63:
#line 638 "src/asin.y"
                                          {
                                    (yyval.mat).t = T_ENTERO;
                                    (yyval.mat).v = (yyvsp[0].cent);
                                }
#line 2317 "asin.c"
    break;

  case 64:
#line 642 "src/asin.y"
                                          {
                                    (yyval.mat).t = T_LOGICO;
                                    (yyval.mat).v = 1;
                                }
#line 2326 "asin.c"
    break;

  case 65:
#line 646 "src/asin.y"
                                          {
                                    (yyval.mat).t = T_LOGICO;
                                    (yyval.mat).v = 0;
                                }
#line 2335 "asin.c"
    break;


#line 2339 "asin.c"

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
            yymsg = YY_CAST (char *, YYSTACK_ALLOC (YY_CAST (YYSIZE_T, yymsg_alloc)));
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
  /* Pacify compilers when the user code never invokes YYERROR and the
     label yyerrorlab therefore never appears in user code.  */
  if (0)
    YYERROR;

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


/*-----------------------------------------------------.
| yyreturn -- parsing is finished, return the result.  |
`-----------------------------------------------------*/
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
                  yystos[+*yyssp], yyvsp);
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
#line 683 "src/asin.y"

