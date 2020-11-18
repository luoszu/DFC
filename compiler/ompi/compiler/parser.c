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
#line 1 "parser.y" /* yacc.c:339  */

/*
  OMPi OpenMP Compiler
  == Copyright since 2001 the OMPi Team
  == Dept. of Computer Science & Engineering, University of Ioannina

  This file is part of OMPi.

  OMPi is free software; you can redistribute it and/or modify
  it under the terms of the GNU General Public License as published by
  the Free Software Foundation; either version 2 of the License, or
  (at your option) any later version.

  OMPi is distributed in the hope that it will be useful,
  but WITHOUT ANY WARRANTY; without even the implied warranty of
  MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
  GNU General Public License for more details.

  You should have received a copy of the GNU General Public License
  along with OMPi; if not, write to the Free Software
  Foundation, Inc., 59 Temple Place, Suite 330, Boston, MA  02111-1307  USA
*/

/* parser.y */

/*
 * 2010/11/10:
 *   dropped OpenMP-specific for parsing; fewer rules, less code
 * 2009/05/11:
 *   added AUTO schedule type
 * 2009/05/03:
 *   added ATNODE ompix clause
 */

#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/time.h>
#include <stdarg.h>
#include <ctype.h>
#include <assert.h>
#include "scanner.h"
#include "boolean.h"
#include "ompi.h"
#include "ast.h"
#include "symtab.h"
#include "ast_free.h"
#include "ast_copy.h"
#include "ast_vars.h"
#include "x_arith.h"

void    check_uknown_var(char *name);
void    parse_error(int exitvalue, char *format, ...);
void    parse_warning(char *format, ...);
void    yyerror(const char *s);
void    check_for_main_and_declare(astspec s, astdecl d);
void    add_declaration_links(astspec s, astdecl d);
astdecl fix_known_typename(astspec s);

/* DF-C */
struct dfc_insert_detail
{
  aststmt body;
  astdecl inParams;
  astdecl outParams;
  int in_params_count;
  int out_params_count;
  char *func_name;
};

int __has_dfc = 0;
void dfc_insert_active_data_decl_and_update_persize(struct dfc_insert_detail *detail);
void dfc_insert_get_active_data_call(struct dfc_insert_detail *detail);
void dfc_insert_update_active_data_call(struct dfc_insert_detail *detail);
void dfc_use_detail_to_fill_main_ad_and_fn_init(struct dfc_insert_detail *detail);

aststmt pastree = NULL;       /* The generated AST */
aststmt pastree_stmt = NULL;  /* For when parsing statment strings */
astexpr pastree_expr = NULL;  /* For when parsing expression strings */
int     checkDecls = 1;       /* 0 when scanning strings (no context check) */
int     tempsave;
int     isTypedef  = 0;       /* To keep track of typedefs */

char    *parsingstring;       /* For error reporting when parsing string */

int     __has_target = 0;

//TODO this is not 100% correct (e.g. if returns lies in a dead code area).
/* Return and goto statements that lead outside the outlined region constitute
 * programmer errors and so we should stop the compilation. When simply 
 * analyzing vars (and not outlining) we ignore this rule.
 */
int     errorOnReturn = 0;

#line 162 "parser.c" /* yacc.c:339  */

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
# define YYERROR_VERBOSE 1
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
    START_SYMBOL_EXPRESSION = 258,
    START_SYMBOL_BLOCKLIST = 259,
    START_SYMBOL_TRANSUNIT = 260,
    IDENTIFIER = 261,
    TYPE_NAME = 262,
    CONSTANT = 263,
    STRING_LITERAL = 264,
    PTR_OP = 265,
    INC_OP = 266,
    DEC_OP = 267,
    LEFT_OP = 268,
    RIGHT_OP = 269,
    LE_OP = 270,
    GE_OP = 271,
    EQ_OP = 272,
    NE_OP = 273,
    AND_OP = 274,
    OR_OP = 275,
    MUL_ASSIGN = 276,
    DIV_ASSIGN = 277,
    MOD_ASSIGN = 278,
    ADD_ASSIGN = 279,
    SUB_ASSIGN = 280,
    LEFT_ASSIGN = 281,
    RIGHT_ASSIGN = 282,
    AND_ASSIGN = 283,
    XOR_ASSIGN = 284,
    OR_ASSIGN = 285,
    SIZEOF = 286,
    TYPEDEF = 287,
    EXTERN = 288,
    STATIC = 289,
    AUTO = 290,
    REGISTER = 291,
    RESTRICT = 292,
    CHAR = 293,
    SHORT = 294,
    INT = 295,
    LONG = 296,
    SIGNED = 297,
    UNSIGNED = 298,
    FLOAT = 299,
    DOUBLE = 300,
    CONST = 301,
    VOLATILE = 302,
    VOID = 303,
    INLINE = 304,
    UBOOL = 305,
    UCOMPLEX = 306,
    UIMAGINARY = 307,
    STRUCT = 308,
    UNION = 309,
    ENUM = 310,
    ELLIPSIS = 311,
    CASE = 312,
    DEFAULT = 313,
    IF = 314,
    ELSE = 315,
    SWITCH = 316,
    WHILE = 317,
    DO = 318,
    FOR = 319,
    GOTO = 320,
    CONTINUE = 321,
    BREAK = 322,
    RETURN = 323,
    __BUILTIN_VA_ARG = 324,
    __BUILTIN_OFFSETOF = 325,
    __BUILTIN_TYPES_COMPATIBLE_P = 326,
    __ATTRIBUTE__ = 327,
    PRAGMA_OMP = 328,
    PRAGMA_OMP_THREADPRIVATE = 329,
    OMP_PARALLEL = 330,
    OMP_SECTIONS = 331,
    OMP_NOWAIT = 332,
    OMP_ORDERED = 333,
    OMP_SCHEDULE = 334,
    OMP_STATIC = 335,
    OMP_DYNAMIC = 336,
    OMP_GUIDED = 337,
    OMP_RUNTIME = 338,
    OMP_AUTO = 339,
    OMP_SECTION = 340,
    OMP_AFFINITY = 341,
    OMP_SINGLE = 342,
    OMP_MASTER = 343,
    OMP_CRITICAL = 344,
    OMP_BARRIER = 345,
    OMP_ATOMIC = 346,
    OMP_FLUSH = 347,
    OMP_PRIVATE = 348,
    OMP_FIRSTPRIVATE = 349,
    OMP_LASTPRIVATE = 350,
    OMP_SHARED = 351,
    OMP_DEFAULT = 352,
    OMP_NONE = 353,
    OMP_REDUCTION = 354,
    OMP_COPYIN = 355,
    OMP_NUMTHREADS = 356,
    OMP_COPYPRIVATE = 357,
    OMP_FOR = 358,
    OMP_IF = 359,
    OMP_TASK = 360,
    OMP_UNTIED = 361,
    OMP_TASKWAIT = 362,
    OMP_COLLAPSE = 363,
    OMP_FINAL = 364,
    OMP_MERGEABLE = 365,
    OMP_TASKYIELD = 366,
    OMP_READ = 367,
    OMP_WRITE = 368,
    OMP_CAPTURE = 369,
    OMP_UPDATE = 370,
    OMP_MIN = 371,
    OMP_MAX = 372,
    OMP_PROCBIND = 373,
    OMP_CLOSE = 374,
    OMP_SPREAD = 375,
    OMP_SIMD = 376,
    OMP_INBRANCH = 377,
    OMP_NOTINBRANCH = 378,
    OMP_UNIFORM = 379,
    OMP_LINEAR = 380,
    OMP_ALIGNED = 381,
    OMP_SIMDLEN = 382,
    OMP_SAFELEN = 383,
    OMP_DECLARE = 384,
    OMP_TARGET = 385,
    OMP_DATA = 386,
    OMP_DEVICE = 387,
    OMP_MAP = 388,
    OMP_ALLOC = 389,
    OMP_TO = 390,
    OMP_FROM = 391,
    OMP_TOFROM = 392,
    OMP_END = 393,
    OMP_TEAMS = 394,
    OMP_DISTRIBUTE = 395,
    OMP_NUMTEAMS = 396,
    OMP_THREADLIMIT = 397,
    OMP_DISTSCHEDULE = 398,
    OMP_DEPEND = 399,
    OMP_IN = 400,
    OMP_OUT = 401,
    OMP_INOUT = 402,
    OMP_TASKGROUP = 403,
    OMP_SEQ_CST = 404,
    OMP_CANCEL = 405,
    OMP_INITIALIZER = 406,
    PRAGMA_OMP_CANCELLATIONPOINT = 407,
    PRAGMA_OMPIX = 408,
    OMPIX_TASKDEF = 409,
    OMPIX_IN = 410,
    OMPIX_OUT = 411,
    OMPIX_INOUT = 412,
    OMPIX_TASKSYNC = 413,
    OMPIX_UPONRETURN = 414,
    OMPIX_ATNODE = 415,
    OMPIX_DETACHED = 416,
    OMPIX_ATWORKER = 417,
    OMPIX_TASKSCHEDULE = 418,
    OMPIX_STRIDE = 419,
    OMPIX_START = 420,
    OMPIX_SCOPE = 421,
    OMPIX_NODES = 422,
    OMPIX_WORKERS = 423,
    OMPIX_LOCAL = 424,
    OMPIX_GLOBAL = 425,
    OMPIX_TIED = 426
  };
#endif
/* Tokens.  */
#define START_SYMBOL_EXPRESSION 258
#define START_SYMBOL_BLOCKLIST 259
#define START_SYMBOL_TRANSUNIT 260
#define IDENTIFIER 261
#define TYPE_NAME 262
#define CONSTANT 263
#define STRING_LITERAL 264
#define PTR_OP 265
#define INC_OP 266
#define DEC_OP 267
#define LEFT_OP 268
#define RIGHT_OP 269
#define LE_OP 270
#define GE_OP 271
#define EQ_OP 272
#define NE_OP 273
#define AND_OP 274
#define OR_OP 275
#define MUL_ASSIGN 276
#define DIV_ASSIGN 277
#define MOD_ASSIGN 278
#define ADD_ASSIGN 279
#define SUB_ASSIGN 280
#define LEFT_ASSIGN 281
#define RIGHT_ASSIGN 282
#define AND_ASSIGN 283
#define XOR_ASSIGN 284
#define OR_ASSIGN 285
#define SIZEOF 286
#define TYPEDEF 287
#define EXTERN 288
#define STATIC 289
#define AUTO 290
#define REGISTER 291
#define RESTRICT 292
#define CHAR 293
#define SHORT 294
#define INT 295
#define LONG 296
#define SIGNED 297
#define UNSIGNED 298
#define FLOAT 299
#define DOUBLE 300
#define CONST 301
#define VOLATILE 302
#define VOID 303
#define INLINE 304
#define UBOOL 305
#define UCOMPLEX 306
#define UIMAGINARY 307
#define STRUCT 308
#define UNION 309
#define ENUM 310
#define ELLIPSIS 311
#define CASE 312
#define DEFAULT 313
#define IF 314
#define ELSE 315
#define SWITCH 316
#define WHILE 317
#define DO 318
#define FOR 319
#define GOTO 320
#define CONTINUE 321
#define BREAK 322
#define RETURN 323
#define __BUILTIN_VA_ARG 324
#define __BUILTIN_OFFSETOF 325
#define __BUILTIN_TYPES_COMPATIBLE_P 326
#define __ATTRIBUTE__ 327
#define PRAGMA_OMP 328
#define PRAGMA_OMP_THREADPRIVATE 329
#define OMP_PARALLEL 330
#define OMP_SECTIONS 331
#define OMP_NOWAIT 332
#define OMP_ORDERED 333
#define OMP_SCHEDULE 334
#define OMP_STATIC 335
#define OMP_DYNAMIC 336
#define OMP_GUIDED 337
#define OMP_RUNTIME 338
#define OMP_AUTO 339
#define OMP_SECTION 340
#define OMP_AFFINITY 341
#define OMP_SINGLE 342
#define OMP_MASTER 343
#define OMP_CRITICAL 344
#define OMP_BARRIER 345
#define OMP_ATOMIC 346
#define OMP_FLUSH 347
#define OMP_PRIVATE 348
#define OMP_FIRSTPRIVATE 349
#define OMP_LASTPRIVATE 350
#define OMP_SHARED 351
#define OMP_DEFAULT 352
#define OMP_NONE 353
#define OMP_REDUCTION 354
#define OMP_COPYIN 355
#define OMP_NUMTHREADS 356
#define OMP_COPYPRIVATE 357
#define OMP_FOR 358
#define OMP_IF 359
#define OMP_TASK 360
#define OMP_UNTIED 361
#define OMP_TASKWAIT 362
#define OMP_COLLAPSE 363
#define OMP_FINAL 364
#define OMP_MERGEABLE 365
#define OMP_TASKYIELD 366
#define OMP_READ 367
#define OMP_WRITE 368
#define OMP_CAPTURE 369
#define OMP_UPDATE 370
#define OMP_MIN 371
#define OMP_MAX 372
#define OMP_PROCBIND 373
#define OMP_CLOSE 374
#define OMP_SPREAD 375
#define OMP_SIMD 376
#define OMP_INBRANCH 377
#define OMP_NOTINBRANCH 378
#define OMP_UNIFORM 379
#define OMP_LINEAR 380
#define OMP_ALIGNED 381
#define OMP_SIMDLEN 382
#define OMP_SAFELEN 383
#define OMP_DECLARE 384
#define OMP_TARGET 385
#define OMP_DATA 386
#define OMP_DEVICE 387
#define OMP_MAP 388
#define OMP_ALLOC 389
#define OMP_TO 390
#define OMP_FROM 391
#define OMP_TOFROM 392
#define OMP_END 393
#define OMP_TEAMS 394
#define OMP_DISTRIBUTE 395
#define OMP_NUMTEAMS 396
#define OMP_THREADLIMIT 397
#define OMP_DISTSCHEDULE 398
#define OMP_DEPEND 399
#define OMP_IN 400
#define OMP_OUT 401
#define OMP_INOUT 402
#define OMP_TASKGROUP 403
#define OMP_SEQ_CST 404
#define OMP_CANCEL 405
#define OMP_INITIALIZER 406
#define PRAGMA_OMP_CANCELLATIONPOINT 407
#define PRAGMA_OMPIX 408
#define OMPIX_TASKDEF 409
#define OMPIX_IN 410
#define OMPIX_OUT 411
#define OMPIX_INOUT 412
#define OMPIX_TASKSYNC 413
#define OMPIX_UPONRETURN 414
#define OMPIX_ATNODE 415
#define OMPIX_DETACHED 416
#define OMPIX_ATWORKER 417
#define OMPIX_TASKSCHEDULE 418
#define OMPIX_STRIDE 419
#define OMPIX_START 420
#define OMPIX_SCOPE 421
#define OMPIX_NODES 422
#define OMPIX_WORKERS 423
#define OMPIX_LOCAL 424
#define OMPIX_GLOBAL 425
#define OMPIX_TIED 426

/* Value type.  */
#if ! defined YYSTYPE && ! defined YYSTYPE_IS_DECLARED

union YYSTYPE
{
#line 97 "parser.y" /* yacc.c:355  */

  char      name[2048];  /* A general string */
  int       type;        /* A general integer */
  char     *string;      /* A dynamically allocated string (only for 2 rules) */
  symbol    symb;        /* A symbol */
  astexpr   expr;        /* An expression node in the AST */
  astspec   spec;        /* A declaration specifier node in the AST */
  astdecl   decl;        /* A declarator node in the AST */
  aststmt   stmt;        /* A statement node in the AST */
  ompcon    ocon;        /* An OpenMP construct */
  ompdir    odir;        /* An OpenMP directive */
  ompclause ocla;        /* An OpenMP clause */

  oxcon     xcon;        /* OMPi extensions */
  oxdir     xdir;
  oxclause  xcla;

#line 562 "parser.c" /* yacc.c:355  */
};

typedef union YYSTYPE YYSTYPE;
# define YYSTYPE_IS_TRIVIAL 1
# define YYSTYPE_IS_DECLARED 1
#endif


extern YYSTYPE yylval;

int yyparse (void);

#endif /* !YY_YY_Y_TAB_H_INCLUDED  */

/* Copy the second part of user declarations.  */

#line 579 "parser.c" /* yacc.c:358  */

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
#define YYFINAL  217
/* YYLAST -- Last index in YYTABLE.  */
#define YYLAST   4629

/* YYNTOKENS -- Number of terminals.  */
#define YYNTOKENS  197
/* YYNNTS -- Number of nonterminals.  */
#define YYNNTS  321
/* YYNRULES -- Number of rules.  */
#define YYNRULES  796
/* YYNSTATES -- Number of states.  */
#define YYNSTATES  1335

/* YYTRANSLATE[YYX] -- Symbol number corresponding to YYX as returned
   by yylex, with out-of-bounds checking.  */
#define YYUNDEFTOK  2
#define YYMAXUTOK   426

#define YYTRANSLATE(YYX)                                                \
  ((unsigned int) (YYX) <= YYMAXUTOK ? yytranslate[YYX] : YYUNDEFTOK)

/* YYTRANSLATE[TOKEN-NUM] -- Symbol number corresponding to TOKEN-NUM
   as returned by yylex, without out-of-bounds checking.  */
static const yytype_uint8 yytranslate[] =
{
       0,     2,     2,     2,     2,     2,     2,     2,     2,     2,
     196,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,   185,     2,     2,     2,   187,   180,     2,
     172,   173,   181,   182,   179,   183,   176,   186,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,   193,   195,
     188,   194,   189,   192,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,   174,     2,   175,   190,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,   177,   191,   178,   184,     2,     2,     2,
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
      45,    46,    47,    48,    49,    50,    51,    52,    53,    54,
      55,    56,    57,    58,    59,    60,    61,    62,    63,    64,
      65,    66,    67,    68,    69,    70,    71,    72,    73,    74,
      75,    76,    77,    78,    79,    80,    81,    82,    83,    84,
      85,    86,    87,    88,    89,    90,    91,    92,    93,    94,
      95,    96,    97,    98,    99,   100,   101,   102,   103,   104,
     105,   106,   107,   108,   109,   110,   111,   112,   113,   114,
     115,   116,   117,   118,   119,   120,   121,   122,   123,   124,
     125,   126,   127,   128,   129,   130,   131,   132,   133,   134,
     135,   136,   137,   138,   139,   140,   141,   142,   143,   144,
     145,   146,   147,   148,   149,   150,   151,   152,   153,   154,
     155,   156,   157,   158,   159,   160,   161,   162,   163,   164,
     165,   166,   167,   168,   169,   170,   171
};

#if YYDEBUG
  /* YYRLINE[YYN] -- Source line where rule number YYN was defined.  */
static const yytype_uint16 yyrline[] =
{
       0,   470,   470,   471,   472,   473,   490,   511,   515,   538,
     560,   564,   568,   576,   580,   590,   622,   629,   633,   637,
     641,   650,   654,   658,   662,   666,   670,   678,   682,   690,
     694,   698,   702,   709,   713,   722,   727,   732,   741,   745,
     749,   753,   757,   761,   769,   773,   781,   785,   789,   793,
     801,   805,   809,   817,   821,   825,   833,   837,   841,   845,
     849,   857,   861,   865,   873,   877,   885,   889,   897,   901,
     909,   913,   921,   925,   933,   937,   945,   949,   957,   961,
     965,   969,   973,   977,   981,   985,   989,   993,   997,  1005,
    1009,  1017,  1031,  1046,  1053,  1058,  1062,  1066,  1074,  1078,
    1082,  1086,  1090,  1094,  1098,  1102,  1110,  1114,  1128,  1145,
    1144,  1167,  1172,  1176,  1180,  1184,  1192,  1196,  1200,  1204,
    1208,  1212,  1216,  1220,  1224,  1228,  1232,  1236,  1240,  1244,
    1248,  1256,  1260,  1264,  1279,  1286,  1293,  1304,  1308,  1316,
    1320,  1328,  1332,  1340,  1344,  1348,  1352,  1360,  1364,  1372,
    1376,  1380,  1388,  1392,  1404,  1408,  1420,  1432,  1436,  1444,
    1448,  1456,  1460,  1464,  1472,  1480,  1484,  1497,  1501,  1509,
    1513,  1517,  1521,  1525,  1529,  1533,  1537,  1541,  1545,  1549,
    1553,  1558,  1563,  1568,  1573,  1581,  1585,  1589,  1593,  1601,
    1605,  1613,  1617,  1625,  1629,  1637,  1641,  1645,  1653,  1657,
    1665,  1669,  1677,  1681,  1685,  1693,  1697,  1701,  1705,  1709,
    1713,  1717,  1721,  1725,  1729,  1733,  1741,  1749,  1753,  1757,
    1765,  1769,  1773,  1777,  1785,  1793,  1797,  1805,  1809,  1813,
    1827,  1831,  1835,  1839,  1843,  1847,  1851,  1856,  1865,  1869,
    1879,  1883,  1887,  1895,  1899,  1899,  1910,  1914,  1923,  1927,
    1931,  1936,  1945,  1949,  1958,  1962,  1966,  1975,  1979,  1983,
    1987,  1991,  1995,  1999,  2003,  2007,  2011,  2015,  2019,  2023,
    2027,  2031,  2039,  2044,  2048,  2052,  2059,  2076,  2080,  2088,
    2092,  2099,  2111,  2112,  2117,  2116,  2161,  2160,  2183,  2182,
    2202,  2201,  2226,  2230,  2245,  2249,  2257,  2266,  2270,  2277,
    2281,  2285,  2289,  2293,  2297,  2301,  2305,  2309,  2313,  2318,
    2323,  2327,  2331,  2335,  2339,  2343,  2347,  2351,  2355,  2359,
    2363,  2367,  2371,  2375,  2379,  2383,  2387,  2391,  2395,  2399,
    2404,  2420,  2424,  2429,  2434,  2439,  2444,  2451,  2458,  2466,
    2474,  2477,  2481,  2488,  2492,  2496,  2500,  2504,  2508,  2515,
    2519,  2519,  2524,  2524,  2530,  2535,  2535,  2543,  2550,  2558,
    2561,  2565,  2572,  2576,  2580,  2584,  2588,  2592,  2599,  2603,
    2607,  2607,  2615,  2614,  2626,  2633,  2637,  2641,  2645,  2649,
    2653,  2658,  2665,  2673,  2676,  2680,  2687,  2691,  2695,  2699,
    2703,  2710,  2717,  2722,  2726,  2733,  2740,  2747,  2755,  2758,
    2762,  2769,  2773,  2777,  2781,  2788,  2788,  2797,  2805,  2813,
    2816,  2820,  2828,  2832,  2836,  2840,  2844,  2852,  2864,  2868,
    2876,  2880,  2888,  2888,  2897,  2897,  2906,  2906,  2915,  2918,
    2926,  2934,  2938,  2946,  2954,  2957,  2961,  2970,  2982,  2986,
    2990,  2994,  3002,  3010,  3018,  3021,  3025,  3032,  3036,  3044,
    3052,  3060,  3063,  3067,  3074,  3078,  3086,  3094,  3102,  3105,
    3109,  3116,  3120,  3124,  3132,  3132,  3141,  3141,  3146,  3146,
    3155,  3159,  3163,  3167,  3175,  3175,  3186,  3194,  3197,  3201,
    3208,  3212,  3219,  3223,  3231,  3239,  3246,  3250,  3254,  3261,
    3265,  3269,  3276,  3276,  3281,  3281,  3290,  3297,  3304,  3312,
    3320,  3328,  3331,  3335,  3342,  3346,  3350,  3354,  3358,  3362,
    3370,  3370,  3376,  3376,  3385,  3393,  3401,  3404,  3408,  3415,
    3419,  3423,  3427,  3434,  3438,  3438,  3447,  3456,  3464,  3467,
    3471,  3478,  3482,  3486,  3494,  3503,  3511,  3514,  3518,  3525,
    3529,  3537,  3546,  3554,  3557,  3561,  3568,  3572,  3580,  3588,
    3596,  3599,  3603,  3610,  3614,  3622,  3630,  3638,  3641,  3645,
    3652,  3656,  3660,  3668,  3676,  3684,  3687,  3691,  3698,  3702,
    3706,  3710,  3718,  3726,  3734,  3737,  3741,  3748,  3752,  3760,
    3768,  3777,  3780,  3785,  3793,  3797,  3805,  3814,  3823,  3826,
    3831,  3839,  3843,  3851,  3860,  3868,  3871,  3875,  3882,  3886,
    3894,  3903,  3911,  3914,  3918,  3925,  3929,  3937,  3946,  3954,
    3957,  3961,  3968,  3972,  3980,  3989,  3998,  4001,  4005,  4013,
    4017,  4021,  4025,  4029,  4037,  4041,  4041,  4046,  4050,  4055,
    4063,  4067,  4071,  4078,  4086,  4094,  4097,  4101,  4108,  4112,
    4116,  4120,  4124,  4128,  4132,  4136,  4143,  4151,  4159,  4162,
    4166,  4173,  4177,  4181,  4185,  4189,  4193,  4197,  4204,  4211,
    4218,  4225,  4229,  4236,  4243,  4251,  4259,  4267,  4275,  4282,
    4293,  4301,  4304,  4308,  4312,  4316,  4325,  4328,  4335,  4339,
    4346,  4346,  4354,  4361,  4369,  4373,  4377,  4384,  4388,  4392,
    4396,  4404,  4411,  4411,  4411,  4419,  4419,  4419,  4426,  4431,
    4435,  4439,  4443,  4447,  4451,  4455,  4459,  4463,  4467,  4474,
    4478,  4486,  4489,  4494,  4505,  4509,  4514,  4521,  4521,  4529,
    4529,  4537,  4537,  4545,  4545,  4553,  4553,  4561,  4561,  4569,
    4584,  4595,  4602,  4612,  4619,  4623,  4630,  4637,  4637,  4642,
    4642,  4650,  4654,  4662,  4666,  4670,  4682,  4700,  4726,  4730,
    4738,  4746,  4745,  4758,  4761,  4765,  4772,  4776,  4780,  4784,
    4788,  4795,  4799,  4803,  4807,  4814,  4818,  4827,  4826,  4843,
    4852,  4851,  4864,  4867,  4871,  4878,  4882,  4886,  4890,  4897,
    4901,  4908,  4913,  4921,  4929,  4937,  4945,  4948,  4952,  4959,
    4963,  4967,  4971,  4975,  4979,  4986,  4992
};
#endif

#if YYDEBUG || YYERROR_VERBOSE || 1
/* YYTNAME[SYMBOL-NUM] -- String name of the symbol SYMBOL-NUM.
   First, the terminals, then, starting at YYNTOKENS, nonterminals.  */
static const char *const yytname[] =
{
  "$end", "error", "$undefined", "START_SYMBOL_EXPRESSION",
  "START_SYMBOL_BLOCKLIST", "START_SYMBOL_TRANSUNIT", "IDENTIFIER",
  "TYPE_NAME", "CONSTANT", "STRING_LITERAL", "PTR_OP", "INC_OP", "DEC_OP",
  "LEFT_OP", "RIGHT_OP", "LE_OP", "GE_OP", "EQ_OP", "NE_OP", "AND_OP",
  "OR_OP", "MUL_ASSIGN", "DIV_ASSIGN", "MOD_ASSIGN", "ADD_ASSIGN",
  "SUB_ASSIGN", "LEFT_ASSIGN", "RIGHT_ASSIGN", "AND_ASSIGN", "XOR_ASSIGN",
  "OR_ASSIGN", "SIZEOF", "TYPEDEF", "EXTERN", "STATIC", "AUTO", "REGISTER",
  "RESTRICT", "CHAR", "SHORT", "INT", "LONG", "SIGNED", "UNSIGNED",
  "FLOAT", "DOUBLE", "CONST", "VOLATILE", "VOID", "INLINE", "UBOOL",
  "UCOMPLEX", "UIMAGINARY", "STRUCT", "UNION", "ENUM", "ELLIPSIS", "CASE",
  "DEFAULT", "IF", "ELSE", "SWITCH", "WHILE", "DO", "FOR", "GOTO",
  "CONTINUE", "BREAK", "RETURN", "__BUILTIN_VA_ARG", "__BUILTIN_OFFSETOF",
  "__BUILTIN_TYPES_COMPATIBLE_P", "__ATTRIBUTE__", "PRAGMA_OMP",
  "PRAGMA_OMP_THREADPRIVATE", "OMP_PARALLEL", "OMP_SECTIONS", "OMP_NOWAIT",
  "OMP_ORDERED", "OMP_SCHEDULE", "OMP_STATIC", "OMP_DYNAMIC", "OMP_GUIDED",
  "OMP_RUNTIME", "OMP_AUTO", "OMP_SECTION", "OMP_AFFINITY", "OMP_SINGLE",
  "OMP_MASTER", "OMP_CRITICAL", "OMP_BARRIER", "OMP_ATOMIC", "OMP_FLUSH",
  "OMP_PRIVATE", "OMP_FIRSTPRIVATE", "OMP_LASTPRIVATE", "OMP_SHARED",
  "OMP_DEFAULT", "OMP_NONE", "OMP_REDUCTION", "OMP_COPYIN",
  "OMP_NUMTHREADS", "OMP_COPYPRIVATE", "OMP_FOR", "OMP_IF", "OMP_TASK",
  "OMP_UNTIED", "OMP_TASKWAIT", "OMP_COLLAPSE", "OMP_FINAL",
  "OMP_MERGEABLE", "OMP_TASKYIELD", "OMP_READ", "OMP_WRITE", "OMP_CAPTURE",
  "OMP_UPDATE", "OMP_MIN", "OMP_MAX", "OMP_PROCBIND", "OMP_CLOSE",
  "OMP_SPREAD", "OMP_SIMD", "OMP_INBRANCH", "OMP_NOTINBRANCH",
  "OMP_UNIFORM", "OMP_LINEAR", "OMP_ALIGNED", "OMP_SIMDLEN", "OMP_SAFELEN",
  "OMP_DECLARE", "OMP_TARGET", "OMP_DATA", "OMP_DEVICE", "OMP_MAP",
  "OMP_ALLOC", "OMP_TO", "OMP_FROM", "OMP_TOFROM", "OMP_END", "OMP_TEAMS",
  "OMP_DISTRIBUTE", "OMP_NUMTEAMS", "OMP_THREADLIMIT", "OMP_DISTSCHEDULE",
  "OMP_DEPEND", "OMP_IN", "OMP_OUT", "OMP_INOUT", "OMP_TASKGROUP",
  "OMP_SEQ_CST", "OMP_CANCEL", "OMP_INITIALIZER",
  "PRAGMA_OMP_CANCELLATIONPOINT", "PRAGMA_OMPIX", "OMPIX_TASKDEF",
  "OMPIX_IN", "OMPIX_OUT", "OMPIX_INOUT", "OMPIX_TASKSYNC",
  "OMPIX_UPONRETURN", "OMPIX_ATNODE", "OMPIX_DETACHED", "OMPIX_ATWORKER",
  "OMPIX_TASKSCHEDULE", "OMPIX_STRIDE", "OMPIX_START", "OMPIX_SCOPE",
  "OMPIX_NODES", "OMPIX_WORKERS", "OMPIX_LOCAL", "OMPIX_GLOBAL",
  "OMPIX_TIED", "'('", "')'", "'['", "']'", "'.'", "'{'", "'}'", "','",
  "'&'", "'*'", "'+'", "'-'", "'~'", "'!'", "'/'", "'%'", "'<'", "'>'",
  "'^'", "'|'", "'?'", "':'", "'='", "';'", "'\\n'", "$accept",
  "start_trick", "enumeration_constant", "string_literal",
  "primary_expression", "postfix_expression", "argument_expression_list",
  "unary_expression", "unary_operator", "cast_expression",
  "multiplicative_expression", "additive_expression", "shift_expression",
  "relational_expression", "equality_expression", "AND_expression",
  "exclusive_OR_expression", "inclusive_OR_expression",
  "logical_AND_expression", "logical_OR_expression",
  "conditional_expression", "assignment_expression", "assignment_operator",
  "expression", "constant_expression", "declaration",
  "declaration_specifiers", "init_declarator_list", "init_declarator",
  "$@1", "storage_class_specifier", "type_specifier",
  "struct_or_union_specifier", "struct_or_union",
  "struct_declaration_list", "struct_declaration",
  "specifier_qualifier_list", "struct_declarator_list",
  "struct_declarator", "enum_specifier", "enumerator_list", "enumerator",
  "type_qualifier", "function_specifier", "declarator",
  "direct_declarator", "pointer", "type_qualifier_list",
  "parameter_type_list", "parameter_list", "parameter_declaration",
  "identifier_list", "type_name", "abstract_declarator",
  "direct_abstract_declarator", "typedef_name", "initializer",
  "initializer_list", "designation", "designator_list", "designator",
  "statement", "statement_for_labeled", "labeled_statement",
  "compound_statement", "@2", "block_item_list", "block_item",
  "expression_statement", "selection_statement", "iteration_statement",
  "iteration_statement_for", "jump_statement", "translation_unit",
  "external_declaration", "function_definition",
  "normal_function_definition", "$@3", "$@4",
  "oldstyle_function_definition", "$@5", "$@6", "declaration_list",
  "declaration_definition", "function_statement",
  "declarations_definitions_seq", "openmp_construct", "openmp_directive",
  "structured_block", "parallel_construct", "parallel_directive",
  "parallel_clause_optseq", "parallel_clause", "unique_parallel_clause",
  "$@7", "$@8", "$@9", "for_construct", "for_directive",
  "for_clause_optseq", "for_clause", "unique_for_clause", "$@10", "$@11",
  "schedule_kind", "sections_construct", "sections_directive",
  "sections_clause_optseq", "sections_clause", "section_scope",
  "section_sequence", "section_directive", "single_construct",
  "single_directive", "single_clause_optseq", "single_clause",
  "unique_single_clause", "$@12", "simd_construct", "simd_directive",
  "simd_clause_optseq", "simd_clause", "unique_simd_clause",
  "inbranch_clause", "uniform_clause", "$@13", "linear_clause", "$@14",
  "aligned_clause", "$@15", "optional_expression",
  "declare_simd_construct", "declare_simd_directive_seq",
  "declare_simd_directive", "declare_simd_clause_optseq",
  "declare_simd_clause", "for_simd_construct", "for_simd_directive",
  "for_simd_clause_optseq", "for_simd_clause",
  "parallel_for_simd_construct", "parallel_for_simd_directive",
  "parallel_for_simd_clause_optseq", "parallel_for_simd_clause",
  "target_data_construct", "target_data_directive",
  "target_data_clause_optseq", "target_data_clause", "device_clause",
  "$@16", "map_clause", "$@17", "$@18", "map_type", "target_construct",
  "@19", "target_directive", "target_clause_optseq", "target_clause",
  "unique_target_clause", "target_update_construct",
  "target_update_directive", "target_update_clause_seq",
  "target_update_clause", "motion_clause", "$@20", "$@21",
  "declare_target_construct", "declare_target_directive",
  "end_declare_target_directive", "teams_construct", "teams_directive",
  "teams_clause_optseq", "teams_clause", "unique_teams_clause", "$@22",
  "$@23", "distribute_construct", "distribute_directive",
  "distribute_clause_optseq", "distribute_clause",
  "unique_distribute_clause", "$@24", "distribute_simd_construct",
  "distribute_simd_directive", "distribute_simd_clause_optseq",
  "distribute_simd_clause", "distribute_parallel_for_construct",
  "distribute_parallel_for_directive",
  "distribute_parallel_for_clause_optseq",
  "distribute_parallel_for_clause",
  "distribute_parallel_for_simd_construct",
  "distribute_parallel_for_simd_directive",
  "distribute_parallel_for_simd_clause_optseq",
  "distribute_parallel_for_simd_clause", "target_teams_construct",
  "target_teams_directive", "target_teams_clause_optseq",
  "target_teams_clause", "teams_distribute_construct",
  "teams_distribute_directive", "teams_distribute_clause_optseq",
  "teams_distribute_clause", "teams_distribute_simd_construct",
  "teams_distribute_simd_directive", "teams_distribute_simd_clause_optseq",
  "teams_distribute_simd_clause", "target_teams_distribute_construct",
  "target_teams_distribute_directive",
  "target_teams_distribute_clause_optseq",
  "target_teams_distribute_clause",
  "target_teams_distribute_simd_construct",
  "target_teams_distribute_simd_directive",
  "target_teams_distribute_simd_clause_optseq",
  "target_teams_distribute_simd_clause",
  "teams_distribute_parallel_for_construct",
  "teams_distribute_parallel_for_directive",
  "teams_distribute_parallel_for_clause_optseq",
  "teams_distribute_parallel_for_clause",
  "target_teams_distribute_parallel_for_construct",
  "target_teams_distribute_parallel_for_directive",
  "target_teams_distribute_parallel_for_clause_optseq",
  "target_teams_distribute_parallel_for_clause",
  "teams_distribute_parallel_for_simd_construct",
  "teams_distribute_parallel_for_simd_directive",
  "teams_distribute_parallel_for_simd_clause_optseq",
  "teams_distribute_parallel_for_simd_clause",
  "target_teams_distribute_parallel_for_simd_construct",
  "target_teams_distribute_parallel_for_simd_directive",
  "target_teams_distribute_parallel_for_simd_clause_optseq",
  "target_teams_distribute_parallel_for_simd_clause", "task_construct",
  "task_directive", "task_clause_optseq", "task_clause",
  "unique_task_clause", "$@25", "dependence_type",
  "parallel_for_construct", "parallel_for_directive",
  "parallel_for_clause_optseq", "parallel_for_clause",
  "parallel_sections_construct", "parallel_sections_directive",
  "parallel_sections_clause_optseq", "parallel_sections_clause",
  "master_construct", "master_directive", "critical_construct",
  "critical_directive", "region_phrase", "barrier_directive",
  "taskwait_directive", "taskgroup_construct", "taskgroup_directive",
  "taskyield_directive", "atomic_construct", "atomic_directive",
  "atomic_clause_opt", "seq_cst_clause_opt", "flush_directive",
  "flush_vars", "$@26", "ordered_construct", "ordered_directive",
  "cancel_directive", "construct_type_clause",
  "cancellation_point_directive", "threadprivate_directive", "$@27",
  "$@28", "declare_reduction_directive", "$@29", "$@30",
  "reduction_identifier", "reduction_type_list", "initializer_clause_opt",
  "data_default_clause", "data_privatization_clause", "$@31",
  "data_privatization_in_clause", "$@32", "data_privatization_out_clause",
  "$@33", "data_sharing_clause", "$@34", "data_reduction_clause", "$@35",
  "if_clause", "$@36", "collapse_clause", "array_section", "variable_list",
  "variable_array_section_list", "array_section_subscript", "$@37", "$@38",
  "array_section_plain", "procbind_clause", "thrprv_variable_list",
  "ompix_directive", "ox_tasksync_directive", "ox_taskschedule_directive",
  "$@39", "ox_taskschedule_clause_optseq", "ox_taskschedule_clause",
  "ox_scope_spec", "ompix_construct", "ox_taskdef_construct", "$@40",
  "ox_taskdef_directive", "$@41", "ox_taskdef_clause_optseq",
  "ox_taskdef_clause", "ox_variable_size_list", "ox_variable_size_elem",
  "ox_task_construct", "ox_task_directive", "ox_task_clause_optseq",
  "ox_task_clause", "ox_funccall_expression", YY_NULLPTR
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
     285,   286,   287,   288,   289,   290,   291,   292,   293,   294,
     295,   296,   297,   298,   299,   300,   301,   302,   303,   304,
     305,   306,   307,   308,   309,   310,   311,   312,   313,   314,
     315,   316,   317,   318,   319,   320,   321,   322,   323,   324,
     325,   326,   327,   328,   329,   330,   331,   332,   333,   334,
     335,   336,   337,   338,   339,   340,   341,   342,   343,   344,
     345,   346,   347,   348,   349,   350,   351,   352,   353,   354,
     355,   356,   357,   358,   359,   360,   361,   362,   363,   364,
     365,   366,   367,   368,   369,   370,   371,   372,   373,   374,
     375,   376,   377,   378,   379,   380,   381,   382,   383,   384,
     385,   386,   387,   388,   389,   390,   391,   392,   393,   394,
     395,   396,   397,   398,   399,   400,   401,   402,   403,   404,
     405,   406,   407,   408,   409,   410,   411,   412,   413,   414,
     415,   416,   417,   418,   419,   420,   421,   422,   423,   424,
     425,   426,    40,    41,    91,    93,    46,   123,   125,    44,
      38,    42,    43,    45,   126,    33,    47,    37,    60,    62,
      94,   124,    63,    58,    61,    59,    10
};
# endif

#define YYPACT_NINF -1104

#define yypact_value_is_default(Yystate) \
  (!!((Yystate) == (-1104)))

#define YYTABLE_NINF -768

#define yytable_value_is_error(Yytable_value) \
  0

  /* YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
     STATE-NUM.  */
static const yytype_int16 yypact[] =
{
    2759,  2539,  1423,  2828, -1104, -1104, -1104, -1104, -1104, -1104,
   -1104, -1104, -1104, -1104, -1104, -1104, -1104, -1104, -1104, -1104,
   -1104, -1104, -1104, -1104, -1104, -1104, -1104, -1104, -1104,   107,
     -52, -1104,   -55,    33,   139,   102, -1104,   100,  4503,  4503,
   -1104,   103, -1104,  4503,  4503,   -17,    22,   122, -1104,  2828,
   -1104, -1104, -1104, -1104, -1104,  3128, -1104, -1104,  2909, -1104,
   -1104, -1104,  3209,   -50, -1104, -1104,  2605,  2605,  2658,    23,
     114,   157,  1979, -1104, -1104, -1104, -1104, -1104, -1104,   323,
   -1104,   357,   810,  2539, -1104,   294,   -20,   637,   163,   796,
     195,   288,   283,   524,    24, -1104, -1104,   336,   149,  2539,
     377,   400,   437,   441,  1493,   449,   619,   435,   452,  1117,
    3906,   396,   284,   476, -1104,   -90, -1104,   100, -1104, -1104,
   -1104,  1423, -1104, -1104, -1104, -1104, -1104, -1104, -1104, -1104,
   -1104,  1493, -1104,   602, -1104,   505, -1104,  1493, -1104,   602,
   -1104,   602, -1104,   602, -1104,  1493, -1104, -1104, -1104, -1104,
   -1104,  1493, -1104,   602, -1104,   602, -1104,   602, -1104,  1493,
   -1104,  1493, -1104,   602, -1104,   602, -1104,   602, -1104,   602,
   -1104,   602, -1104,   602, -1104,   602, -1104,   602, -1104,  1493,
   -1104,   602, -1104,   505, -1104,  1493, -1104,  1493, -1104, -1104,
   -1104,  1493, -1104, -1104,  1154, -1104, -1104,  1493, -1104, -1104,
   -1104, -1104, -1104, -1104, -1104, -1104,   680,  2828,   514,   706,
     261,   533, -1104,   560, -1104, -1104,   139, -1104, -1104,   179,
   -1104,   592, -1104, -1104,   558,  2882,   568, -1104, -1104,   573,
    4117,  1683,  1889,    22, -1104,   662,    33, -1104, -1104, -1104,
   -1104, -1104, -1104,  2978,    33, -1104,   616,  1511,  1979, -1104,
   -1104,  1979, -1104,  2539,  4476,  4476,    20,  4476,    17,  4476,
     629, -1104,   671, -1104, -1104,  2146,  2539,   850, -1104, -1104,
   -1104, -1104, -1104, -1104, -1104, -1104, -1104, -1104, -1104,  2539,
   -1104, -1104,  2539,  2539,  2539,  2539,  2539,  2539,  2539,  2539,
    2539,  2539,  2539,  2539,  2539,  2539,  2539,  2539,  2539,  2539,
    2539,  2539,  1493, -1104,   655,  1110,  2539,  2539,  2539,  3998,
     -19,   742,  1590,   658, -1104, -1104, -1104,   199,    51, -1104,
     664, -1104,   669,   -72,   674,   994,   -43,   770, -1104,   709,
     712, -1104,   298,   773,    16,   729,   396, -1104, -1104, -1104,
   -1104,   738, -1104,   746, -1104, -1104,  1423, -1104,   727, -1104,
   -1104, -1104, -1104,  1641, -1104, -1104, -1104, -1104, -1104, -1104,
    1493, -1104, -1104, -1104, -1104, -1104, -1104, -1104, -1104, -1104,
   -1104, -1104, -1104, -1104, -1104, -1104, -1104, -1104, -1104, -1104,
   -1104, -1104, -1104,   778,   750,   706, -1104,   771,   699, -1104,
     811, -1104,   795,  1006, -1104, -1104, -1104, -1104,    33, -1104,
   -1104,   573,  4117,  4476, -1104,  3032, -1104,   132,  4476, -1104,
   -1104,  3375, -1104, -1104,  3446,   165,   854,   205, -1104,   130,
    2098, -1104,   825,   848,  2029,   910,   864,   410, -1104, -1104,
   -1104,   573, -1104,   253, -1104,   888,   890,   887,   899,   906,
   -1104, -1104,  3278,  2164,   444, -1104,   601, -1104,  2194, -1104,
   -1104, -1104,   338,   232, -1104, -1104, -1104, -1104, -1104, -1104,
     294,   294,   -20,   -20,   637,   637,   637,   637,   163,   163,
     796,   195,   288,   283,   524,   147, -1104, -1104,  1110,  3972,
   -1104, -1104, -1104,   368,   373,   424,   916,  1733,   209,  1770,
   -1104, -1104, -1104,   974,  1659,   277, -1104,   328, -1104,  1104,
   -1104,   924, -1104, -1104, -1104, -1104, -1104,   975, -1104, -1104,
     940, -1104,  1003,   961, -1104, -1104,   600,   213, -1104,   999,
     -29,    21,   893,  1043, -1104,   707, -1104,   -22, -1104,   237,
   -1104, -1104,  1354,  3993, -1104,    -6,  1493, -1104,  2263, -1104,
     759,  2539, -1104,    59,   779,   684, -1104, -1104,   461,   500,
   -1104,  2329, -1104,  3375,  3228, -1104, -1104,  2539, -1104,   214,
   -1104,   958,  3297, -1104, -1104, -1104,   464,  3059, -1104,   117,
   -1104, -1104,  4453,  3470, -1104,  1147,  1009,  2098, -1104, -1104,
    2539, -1104,  1014,  1015,  1065, -1104, -1104,  2539,  1019,  1019,
    4476,  1195,  4476, -1104,  1029,  1027,  1046, -1104,  1045,  1051,
     601,  3521,  2350,  2115, -1104, -1104, -1104,  2539, -1104,  1493,
    1493,  1493,  2539,  2380,   256,  1799,  2395,   337,   788, -1104,
    2652, -1104, -1104, -1104, -1104,  1049,  1055, -1104,  1059,  1061,
    1066,  2561, -1104, -1104, -1104, -1104, -1104, -1104, -1104, -1104,
   -1104, -1104, -1104, -1104,   492, -1104, -1104, -1104, -1104, -1104,
   -1104, -1104, -1104,   412, -1104, -1104, -1104, -1104, -1104,  1067,
   -1104, -1104,  1047,  1241, -1104,  1151, -1104, -1104,  1076,  1077,
     660, -1104, -1104, -1104, -1104, -1104, -1104, -1104, -1104, -1104,
    1088, -1104,  1089,  1174, -1104, -1104, -1104, -1104, -1104, -1104,
   -1104, -1104, -1104, -1104,  1093,  1419, -1104, -1104, -1104, -1104,
   -1104, -1104, -1104, -1104, -1104,  1097, -1104, -1104, -1104,   469,
   -1104, -1104, -1104,   496,    26,   361,  1101,   423, -1104, -1104,
   -1104, -1104, -1104, -1104,  1171, -1104,  1062,  1103,  1109,  1226,
   -1104, -1104, -1104, -1104, -1104, -1104, -1104, -1104,  1164,  1778,
    1116,   502, -1104, -1104, -1104, -1104, -1104, -1104,  1192, -1104,
    1112, -1104,  1139, -1104,  1141, -1104,   603, -1104, -1104,   355,
   -1104,  1119,  1232, -1104,  1493, -1104, -1104,   488, -1104,    79,
   -1104, -1104, -1104, -1104, -1104, -1104, -1104, -1104, -1104, -1104,
   -1104, -1104, -1104, -1104,  1128, -1104, -1104, -1104,  1152,  1008,
   -1104, -1104, -1104, -1104, -1104, -1104, -1104,  1321,  1156,  1157,
    1159,  1160,   -11, -1104, -1104,  2115, -1104, -1104, -1104, -1104,
   -1104,   142, -1104,  2539, -1104, -1104,  4503, -1104, -1104, -1104,
     489, -1104, -1104,  1158,  1165, -1104, -1104,  1211, -1104,  1172,
    1175,  1177, -1104, -1104, -1104, -1104, -1104,  1180, -1104,  1169,
    1184,  2539,   946, -1104,   797,  2329,   274, -1104, -1104,  1304,
   -1104, -1104,   497,  1493,   501,  2421,  2447,   398,  1493,   508,
    2468,  1696, -1104, -1104, -1104, -1104, -1104, -1104, -1104, -1104,
   -1104,  3275,  1749, -1104, -1104, -1104, -1104, -1104, -1104, -1104,
   -1104, -1104, -1104,  1198,  1199,  1200,  1201,   347,   779,  1202,
   -1104, -1104,    -5, -1104,  1203, -1104,  1204, -1104, -1104, -1104,
   -1104,   542,  3878, -1104, -1104, -1104, -1104,   761,  2539, -1104,
   -1104,   945, -1104,  1205,  1206,  2539, -1104, -1104,  1207,  1208,
     213, -1104, -1104,   423, -1104, -1104, -1104, -1104, -1104,  1278,
   -1104,  3846,  1210, -1104, -1104, -1104, -1104,  1221, -1104,  1262,
    3806,  1766, -1104, -1104, -1104, -1104, -1104, -1104, -1104, -1104,
   -1104,  3767,   823, -1104, -1104, -1104, -1104, -1104,  1330, -1104,
    1218, -1104,  2672,  2539, -1104, -1104,  1254,  1261,  1264, -1104,
     536, -1104, -1104, -1104, -1104, -1104, -1104,  4525,  1265,  2539,
   -1104,  1242, -1104,   779,  1433,  1433,  1433, -1104,   817, -1104,
   -1104, -1104, -1104, -1104,  1244, -1104, -1104, -1104, -1104, -1104,
   -1104,  1266, -1104, -1104, -1104,  2046, -1104, -1104, -1104,  1493,
    1247, -1104,  1493,  1493,   543,  1493,   561,  2515, -1104,  1493,
    1493,   570, -1104,  4300, -1104, -1104, -1104, -1104, -1104,  1241,
    1241,  1241,  1241,  1270,  1271,  1272, -1104,  1241,  2539,  2539,
    1273,  1274,  1275,  1241,  1241, -1104,  1443, -1104, -1104, -1104,
   -1104, -1104, -1104, -1104,  1300,   610,   611,  2539, -1104, -1104,
   -1104,  1257,  1241,  1241,   648,  2539,  1445,  1445, -1104, -1104,
    1331,  3787,  4339, -1104, -1104, -1104, -1104, -1104, -1104, -1104,
   -1104, -1104,  1445,  1260, -1104,  3713,  4316, -1104, -1104, -1104,
   -1104, -1104, -1104, -1104,  2539,  2539,  3662,  4273, -1104, -1104,
   -1104, -1104, -1104,   649, -1104,  1310,  1322,  1325,  2539,  2539,
     885, -1104, -1104,   260,  1241,   650, -1104,  1307,  1329,   673,
   -1104,   688,   695, -1104,  2072, -1104, -1104, -1104, -1104,  2329,
   -1104, -1104, -1104, -1104,  1493, -1104,  1493,  1493,   696, -1104,
   -1104,  1493, -1104,   700,   720,   721,   725, -1104, -1104, -1104,
    1315,   736,   753,   757, -1104, -1104, -1104,   762,   784, -1104,
   -1104, -1104, -1104, -1104,   785,  1445,   388,   388, -1104,   798,
    1335, -1104,   801,   806, -1104,  3606,  3095, -1104, -1104, -1104,
   -1104, -1104,   815, -1104,  3555,  1114, -1104, -1104, -1104, -1104,
   -1104,   826,   830,  4237, -1104, -1104, -1104, -1104, -1104, -1104,
   -1104, -1104, -1104, -1104,  1337,  1338, -1104,  1334,  1342,  4525,
   -1104,   840, -1104,  1433,  1823, -1104,  1433, -1104, -1104, -1104,
   -1104, -1104, -1104, -1104,  1493, -1104, -1104, -1104, -1104, -1104,
    1241, -1104, -1104, -1104, -1104, -1104,  2539,  2539, -1104,   841,
    2539,  1343,  1348, -1104, -1104,  1351, -1104,  1522, -1104,  3499,
    4186, -1104, -1104, -1104, -1104, -1104, -1104,  1445,  4150, -1104,
   -1104, -1104, -1104, -1104, -1104, -1104, -1104,  2539, -1104, -1104,
     930, -1104, -1104,  2539, -1104,   842,  1523,  1355, -1104, -1104,
     857,   866,   869, -1104,   336, -1104, -1104,  2539, -1104,  1335,
   -1104,  4099, -1104, -1104, -1104, -1104, -1104,   871, -1104,   889,
   -1104, -1104,   900, -1104,  1358, -1104, -1104, -1104, -1104,   397,
    1365,  2539, -1104, -1104, -1104, -1104, -1104,  2539, -1104,  1366,
    1392,   336, -1104,  1374,  1352,  1547, -1104,   183,  2539,  2539,
     904,  1394,  1395, -1104, -1104
};

  /* YYDEFACT[STATE-NUM] -- Default reduction number in state STATE-NUM.
     Performed when YYTABLE does not specify something else to do.  Zero
     means the default is an error.  */
static const yytype_uint16 yydefact[] =
{
       0,     0,     0,     0,   167,   216,   111,   112,   113,   114,
     115,   162,   117,   118,   119,   120,   123,   124,   121,   122,
     161,   163,   116,   164,   125,   126,   127,   137,   138,     0,
       0,   692,     0,     0,   185,     0,   280,     0,    98,   100,
     128,     0,   129,   102,   104,   290,   165,     0,   130,     2,
     277,   279,   282,   283,    95,     0,   431,    96,     0,    94,
      97,   281,     0,     9,    10,     7,     0,     0,     0,     0,
       0,     0,     0,    38,    39,    40,    41,    42,    43,    11,
      13,    29,    44,     0,    46,    50,    53,    56,    61,    64,
      66,    68,    70,    72,    74,    76,    89,     3,     9,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,   244,   252,     0,   248,     0,   249,   230,
     231,     4,   246,   232,   233,   234,   259,   235,   236,   250,
     299,     0,   300,     0,   301,     0,   302,     0,   310,     0,
     311,     0,   312,     0,   313,     0,   314,   474,   315,   484,
     316,     0,   317,     0,   318,     0,   319,     0,   320,     0,
     321,     0,   322,     0,   323,     0,   324,     0,   325,     0,
     326,     0,   327,     0,   328,     0,   329,     0,   309,     0,
     303,     0,   304,     0,   305,     0,   306,     0,   331,   333,
     330,     0,   334,   307,     0,   332,   308,     0,   335,   336,
     251,   748,   749,   237,   765,   766,     0,     5,   156,     0,
       0,     0,   770,     0,   189,   187,   186,     1,    92,     0,
     106,   288,    99,   101,   135,     0,   136,   103,   105,     0,
       0,     0,     0,   166,   278,     0,     0,   296,   430,   432,
     295,   294,   297,     0,     0,   286,   769,     0,     0,    30,
      31,     0,    33,     0,     0,     0,     0,   143,   200,   145,
       0,     8,     0,    23,    24,     0,     0,     0,    79,    80,
      81,    82,    83,    84,    85,    86,    87,    88,    78,     0,
      44,    32,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,    91,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,   273,   274,   275,     0,   340,   383,
       0,   398,     0,     0,     0,   671,     0,   359,   616,     0,
       0,   409,   477,   501,   516,     0,     0,   687,   688,   689,
     690,     0,   786,     0,   751,   243,     0,   253,   108,   247,
     337,   338,   357,     0,   381,   396,   407,   442,   449,   456,
       0,   499,   514,   526,   534,   541,   548,   555,   563,   572,
     579,   586,   593,   600,   607,   614,   633,   646,   658,   660,
     666,   669,   682,     0,     0,     0,     6,   159,     0,   157,
       0,   434,     0,     0,   772,   168,   190,   188,     0,    93,
     109,     0,     0,     0,   132,     0,   139,     0,     0,   287,
     292,     0,   198,   179,     0,   196,     0,   191,   193,     0,
       0,   169,    39,     0,     0,     0,   288,     0,   298,   496,
     284,     0,    15,     0,    27,     0,     0,     0,     0,     0,
      12,   144,     0,     0,   202,   201,   203,   146,     0,    20,
      22,    17,     0,     0,    19,    21,    77,    47,    48,    49,
      51,    52,    54,    55,    59,    60,    57,    58,    62,    63,
      65,    67,    69,    71,    73,     0,    90,   240,     0,     0,
     238,   242,   239,     0,     0,     0,     0,     0,     0,     0,
     272,   276,   648,   635,     0,     0,   683,     0,   659,     0,
     661,     0,   664,   672,   673,   675,   674,   676,   680,   678,
       0,   444,     0,     0,   665,   668,     0,     0,   458,   550,
       0,   557,     0,     0,   528,     0,   667,     0,   691,     0,
     750,   753,     0,     0,   392,     0,     0,   475,     0,   784,
       0,     0,   152,     0,     0,     0,   497,   746,     0,     0,
     107,     0,   285,     0,     0,   131,   140,     0,   142,     0,
     147,   149,     0,   293,   291,   184,     0,     0,   195,   202,
     197,   178,     0,     0,   180,     0,     0,     0,   176,   171,
       0,   170,    39,     0,     0,   768,    16,     0,     0,    34,
       0,     0,     0,   212,     0,   191,     0,   206,    39,     0,
     204,     0,     0,     0,    45,    18,    14,     0,   241,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,   451,
       0,   355,   717,   719,   723,     0,     0,   352,     0,     0,
       0,     0,   339,   341,   343,   344,   345,   346,   347,   348,
     349,   354,   390,   721,     0,   382,   384,   386,   387,   388,
     389,   404,   405,     0,   397,   399,   401,   402,   403,     0,
     662,   677,     0,     0,   679,     0,   367,   368,     0,     0,
       0,   358,   360,   362,   363,   364,   365,   366,   374,   627,
       0,   628,     0,     0,   615,   617,   619,   620,   621,   622,
     623,   624,   424,   426,     0,     0,   408,   410,   412,   418,
     419,   413,   414,   415,   416,     0,   492,   494,   490,     0,
     486,   489,   491,     0,   574,     0,     0,     0,   476,   482,
     483,   478,   480,   481,     0,   565,     0,     0,     0,     0,
     500,   502,   504,   505,   506,   507,   508,   509,   536,     0,
       0,     0,   515,   517,   522,   519,   520,   521,     0,   684,
       0,   793,     0,   794,     0,   792,     0,   785,   787,     0,
     245,     0,     0,   391,     0,   393,   795,     0,   153,     0,
     160,   154,   158,   698,   705,   706,   707,   708,   702,   700,
     699,   701,   703,   704,     0,   420,   421,   422,     0,     0,
     433,   441,   440,   438,   439,   435,   693,     0,     0,     0,
       0,     0,     0,   771,   773,     0,   217,   110,   289,   133,
     151,     0,   141,     0,   134,   182,     0,   192,   194,   183,
       0,   199,   173,     0,     0,   177,   172,     0,    28,     0,
       0,     0,   214,   205,   210,   208,   213,     0,   207,    39,
       0,     0,     0,   220,     0,     0,     0,   225,    75,   254,
     256,   257,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,   647,   651,   649,   652,   653,   654,   655,   656,
     657,     0,     0,   634,   638,   639,   636,   640,   641,   642,
     643,   644,   645,     0,     0,     0,     0,     0,     0,     0,
     350,   727,     0,   342,     0,   385,     0,   400,   663,   670,
     731,     0,     0,   443,   447,   448,   445,     0,     0,   361,
     625,     0,   618,     0,     0,     0,   411,   464,     0,     0,
       0,   485,   487,     0,   457,   459,   461,   462,   463,     0,
     581,     0,     0,   549,   553,   554,   551,   468,   479,   588,
       0,     0,   556,   560,   561,   558,   562,   510,   512,   503,
     543,     0,     0,   527,   533,   531,   529,   532,     0,   518,
       0,   685,     0,     0,   788,   760,     0,     0,     0,   759,
       0,   752,   754,   395,   394,   796,   155,     0,     0,     0,
     436,     0,   747,     0,     0,     0,     0,   774,     0,   148,
     150,   181,   174,   175,     0,    35,    36,    37,   215,   211,
     209,     0,   228,   229,    25,     0,   221,   224,   226,     0,
       0,   260,     0,     0,     0,     0,     0,     0,   268,     0,
       0,     0,   650,     0,   450,   455,   452,   454,   637,     0,
       0,     0,     0,     0,     0,     0,   725,     0,     0,     0,
       0,     0,     0,     0,     0,   681,     0,   446,   380,   375,
     376,   377,   378,   379,     0,     0,     0,     0,   630,   631,
     632,     0,     0,     0,     0,     0,     0,     0,   488,   460,
     595,     0,     0,   573,   577,   578,   575,   552,   470,   471,
     472,   473,     0,     0,   602,     0,     0,   564,   568,   571,
     566,   569,   570,   559,     0,     0,     0,     0,   535,   539,
     537,   540,   530,     0,   686,    39,     0,     0,     0,     0,
       0,   755,   709,     0,     0,     0,   694,     0,   781,     0,
     779,     0,     0,   218,     0,   498,   227,    26,   222,     0,
     255,   258,   263,   262,     0,   261,     0,     0,     0,   270,
     269,     0,   453,     0,     0,     0,     0,   716,   714,   715,
       0,     0,     0,     0,   743,   744,   745,     0,     0,   732,
     372,   369,   370,   729,     0,     0,   428,   428,   417,     0,
     733,   734,     0,     0,   609,     0,     0,   580,   584,   585,
     582,   576,     0,   466,     0,     0,   587,   591,   592,   589,
     567,     0,     0,     0,   542,   547,   546,   544,   538,   523,
     524,   789,   790,   791,     0,     0,   761,   762,     0,     0,
     695,     0,   437,     0,     0,   775,     0,   776,   777,   219,
     223,   266,   265,   264,     0,   271,   356,   718,   720,   724,
       0,   353,   351,   728,   722,   406,     0,     0,   626,     0,
       0,     0,     0,   465,   739,   730,   493,     0,   495,     0,
       0,   594,   598,   599,   596,   583,   469,     0,     0,   601,
     605,   606,   603,   590,   511,   513,   545,     0,   756,   757,
       0,   758,   710,     0,   423,     0,     0,     0,   780,   267,
       0,     0,     0,   629,   429,   425,   427,     0,   737,   735,
     736,     0,   608,   612,   613,   610,   597,     0,   604,     0,
     764,   763,     0,   778,     0,   783,   726,   373,   371,   742,
       0,     0,   611,   467,   525,   696,   782,     0,   740,     0,
     711,   741,   738,     0,     0,     0,   697,     0,     0,     0,
       0,     0,     0,   712,   713
};

  /* YYPGOTO[NTERM-NUM].  */
static const yytype_int16 yypgoto[] =
{
   -1104, -1104, -1104, -1104, -1104, -1104,  -259,   -65, -1104,   -14,
     818,   827,   962,   851,  1276,  1269,  1277,  1279,  1280, -1104,
     -95,  -185, -1104,    -1,  -511,   401,    35, -1104,  1185, -1104,
   -1104,   -67, -1104, -1104,   -18,  -262,  -118, -1104,   758, -1104,
    1187,  -521,   792, -1104,     8,   -39,    25,  -211,  -221,  -217,
    -543, -1104,  -228,  -202,  -386,   -24,  -535,   765,  -944, -1104,
     732,    13,  1095, -1104,  -134, -1104,  1238,  -112,  1391, -1104,
   -1104,  4448, -1104,  1583,     1,     2,  1525, -1104, -1104, -1104,
   -1104, -1104,  1186,  1346, -1104, -1104, -1104,  -263,   137, -1104,
   -1104, -1104,   959,  -482, -1104, -1104, -1104, -1104, -1104, -1104,
    -464,  -501, -1104, -1104, -1104, -1104, -1104, -1104,   947,  1409,
   -1104,  1058, -1104, -1104, -1104,   941, -1104, -1104, -1104, -1104,
   -1104,  -483,  -461, -1104, -1104, -1104,  -514, -1104,  -513, -1104,
     442, -1104, -1104,  1555, -1104,   822, -1104, -1104, -1104,   710,
   -1104, -1104, -1104,  -760, -1104, -1104, -1104,   690,  -454, -1104,
    -662, -1104, -1104, -1104, -1104, -1104, -1104, -1104,  -507,  -863,
   -1104, -1104, -1104,  -666, -1104, -1104, -1104, -1104, -1104, -1104,
   -1104, -1104, -1104,  -469,  -174, -1104, -1104, -1104, -1104, -1104,
     873,  -433, -1104, -1104, -1104, -1104,  -699, -1104, -1104, -1104,
    -897, -1104, -1104, -1104, -1020, -1104, -1104, -1104,   683, -1104,
   -1104, -1104,  -701, -1104, -1104, -1104,  -885, -1104, -1104, -1104,
     544, -1104, -1104, -1104,   443, -1104, -1104, -1104, -1019, -1104,
   -1104, -1104,   367, -1104, -1104, -1104, -1103, -1104, -1104, -1104,
     329, -1104, -1104, -1104,   965, -1104, -1104, -1104, -1104, -1104,
   -1104,  -601, -1104, -1104, -1104,   790, -1104, -1104, -1104, -1104,
   -1104, -1104, -1104, -1104, -1104, -1104, -1104, -1104, -1104, -1104,
   -1104, -1104, -1104, -1104, -1104, -1104,  1318, -1104, -1104, -1104,
   -1104, -1104, -1104, -1104,  -824, -1104, -1104,  -382,   -12, -1104,
      41, -1104,  -488, -1104,    15, -1104,    66, -1104,  -352, -1104,
    -314,   408,  -911,  -995, -1104, -1104, -1104,   345, -1104, -1104,
   -1104, -1104, -1104, -1104, -1104,   687, -1104, -1104,    49, -1104,
   -1104, -1104, -1104,   856,  -949,   446, -1104, -1104, -1104,   911,
   -1104
};

  /* YYDEFGOTO[NTERM-NUM].  */
static const yytype_int16 yydefgoto[] =
{
      -1,    35,   387,    79,    80,    81,   433,    82,    83,    84,
      85,    86,    87,    88,    89,    90,    91,    92,    93,    94,
      95,    96,   279,   115,   304,    36,   117,   219,   220,   551,
      38,    39,    40,    41,   405,   406,   258,   559,   560,    42,
     388,   389,    43,    44,    45,    46,    47,   216,   594,   595,
     418,   419,   260,   596,   446,    48,   843,   844,   845,   846,
     847,   350,   481,   119,   120,   346,   121,   122,   123,   124,
     125,   126,   127,    49,    50,    51,    52,   401,   229,    53,
     402,   230,   411,   242,   238,   243,   128,   129,   351,   130,
     131,   494,   633,   874,  1038,   889,   883,   132,   133,   512,
     904,   875,  1237,  1236,  1055,   134,   135,   495,   646,   354,
     535,   536,   136,   137,   497,   655,   656,   896,   138,   139,
     516,   954,   698,   791,   792,   978,   699,   913,   700,   914,
    1241,    54,    55,    56,   545,   795,   140,   141,   665,   906,
     142,   143,   871,  1195,   144,   145,   713,   925,   719,  1065,
     720,  1257,  1082,  1083,   146,   360,   147,   520,   934,   722,
     148,   149,   709,   710,   711,   918,   919,    57,    58,   429,
     150,   151,   522,   943,   732,  1094,  1095,   152,   153,   525,
     743,   955,  1267,   154,   155,   739,  1089,   156,   157,   951,
    1188,   158,   159,  1096,  1261,   160,   161,   715,   936,   162,
     163,   726,  1075,   164,   165,   940,  1179,   166,   167,   931,
    1076,   168,   169,  1071,  1180,   170,   171,  1085,  1253,   172,
     173,  1175,  1254,   174,   175,  1184,  1294,   176,   177,  1249,
    1295,   178,   179,   513,   685,   686,  1057,  1061,   180,   181,
     620,  1027,   182,   183,   618,   864,   184,   185,   186,   187,
     501,   188,   189,   190,   191,   192,   193,   194,   507,   662,
     195,   510,   663,   196,   197,   198,   341,   199,    59,   211,
     981,    60,  1273,  1320,   784,  1113,  1324,   877,   878,   884,
     879,   885,   880,   894,   881,   886,   882,  1150,   640,  1039,
     678,  1171,   901,  1172,  1245,  1311,  1287,  1310,   641,   548,
     200,   201,   202,   531,   759,   972,  1208,   203,   204,   431,
      62,   394,   549,   804,  1119,  1120,   205,   206,   529,   758,
     384
};

  /* YYTABLE[YYPACT[STATE-NUM]] -- What to do in state STATE-NUM.  If
     positive, shift that token.  If negative, reduce the rule whose
     number is the opposite.  If YYTABLE_NINF, syntax error.  */
static const yytype_int16 yytable[] =
{
      97,   249,   250,   252,   303,   257,   452,   649,   233,   349,
     416,   673,   634,   721,   417,   118,   807,   226,   280,   876,
     435,   424,   772,   436,   676,   945,   438,   439,   702,   818,
     770,   793,   794,   697,   280,    37,  1121,  1122,    37,     4,
     956,   213,   482,   922,   299,   221,   810,   423,   672,    61,
     234,   927,    61,   731,  1100,  1090,   445,   237,   600,   215,
     241,  1129,   434,   708,  1036,   386,  1189,   762,   437,   281,
     245,   256,  1173,   222,   223,   629,  1197,   210,   227,   228,
     434,  1262,   629,  1040,    37,   386,   342,  1182,   798,   301,
     236,   523,   744,    37,   456,   409,   724,   244,    61,   212,
     499,   929,   217,   705,   716,   347,     4,   407,   317,   224,
       5,  1026,   635,   208,  1041,  1042,   476,   311,  1143,  1144,
    1145,  1146,   247,     4,   500,   348,  1151,   492,     4,   508,
     868,   687,  1157,  1158,   118,   212,   863,   524,     4,   441,
     733,   447,   725,   556,   799,   800,   801,   930,     4,   634,
     717,  1166,  1167,   509,   493,  1298,   649,   748,   257,  1117,
    -286,   691,   285,   286,   673,   712,  1263,   718,   723,   673,
    1239,     4,   763,  1266,   749,   750,    11,   676,   289,   290,
    1129,   257,   676,   600,   257,    20,    21,   257,   257,   442,
     257,   443,   257,   440,   231,   253,   232,   566,    34,   301,
    1198,  1190,   704,  1211,   905,    33,   909,   702,   234,   577,
     938,   747,   916,   570,    34,   482,   300,   280,   280,   280,
     280,   280,   280,   280,   280,   280,   280,   280,   280,   280,
     280,   280,   280,   280,   280,   576,   865,   771,   450,   583,
    1093,   397,    37,   455,   426,   241,   935,   256,   772,   635,
     256,   702,   430,  1102,  1068,   708,    61,   976,   599,   926,
     949,   927,  1297,  1142,  1275,   453,   415,   552,   457,   458,
     459,  1028,    33,   818,   355,   793,   794,   564,    37,   767,
     225,    34,   359,   444,   209,   407,   254,   407,   361,   567,
     407,   443,   556,   944,    33,   218,   365,   585,   366,   475,
     556,   687,   990,   574,    33,   483,   484,   485,   744,   575,
    1006,   488,  1252,    34,    33,   477,   375,   629,   480,  1280,
      34,   247,   378,    34,   379,   557,   301,   558,   380,   255,
    1001,   691,   261,   733,   382,   557,   257,   567,   257,   443,
     607,   257,   302,   751,   733,   705,    34,   733,   706,   707,
    1101,   291,   292,   434,   642,  1328,   820,   712,   398,   118,
     390,   928,   829,   723,   831,   723,   806,   262,   263,   264,
     622,   623,   643,   868,   399,   295,   626,  1329,   301,   863,
     837,   704,   391,   280,   572,   554,  1293,  1252,   301,   342,
     562,   392,   823,   811,   491,   824,   960,   752,   753,   754,
     573,   673,   828,   116,   615,   651,   348,   606,   755,   812,
    1025,   301,   946,   517,   676,   561,   756,   840,   806,   808,
     349,   622,   623,   568,  1074,   704,   586,   747,  1293,   518,
     652,  1033,   587,   757,   604,   301,   407,   519,   212,  1209,
     569,   905,   343,  1034,   407,  1035,   303,   344,   841,   415,
     842,   855,   702,  1210,   622,   623,   644,   624,   625,   240,
     626,   965,   303,   935,   702,   629,   708,   444,  1007,   926,
    1128,   337,   338,   645,   297,   282,   280,   415,   296,   865,
     283,   284,   636,   647,  1101,   657,   614,   257,   617,   651,
     534,   480,   280,   705,   716,   257,  1101,   537,   944,   339,
     674,   688,   727,   728,   701,   622,   623,   653,   944,   638,
     734,   605,   848,   745,   652,   301,   301,   587,  1099,   966,
     967,   968,   116,   257,   654,   257,   969,   629,   690,   265,
     233,   266,   860,   267,   970,   637,   648,   736,   658,   210,
     932,   609,   280,   298,   340,   118,   610,   301,   584,   733,
     733,   971,   301,   675,   689,   705,   716,   933,  1091,   733,
     639,   650,  1025,   735,  1178,  1074,   746,  1046,   712,   642,
     305,   928,   306,   629,  1101,   213,   301,   301,   677,   723,
     723,  1240,   703,   702,  1101,   622,   623,   643,   737,  1128,
    1317,   626,   569,  1017,  1220,   622,   623,   611,   702,   798,
     629,   705,   415,   301,   706,   707,   866,   415,   415,   307,
     669,   852,   854,   308,   857,   859,   442,   946,   443,   636,
     806,   312,   849,   850,   851,   313,   704,   946,   705,   716,
     314,   410,   647,   869,   796,  1025,   415,   815,   704,   944,
     797,   657,   965,   816,   240,   740,   638,   315,   920,  1101,
     287,   288,  1099,   674,   345,   799,   800,   801,   674,   867,
     806,   975,   991,  1196,  1099,   921,   105,   587,   816,  1178,
    1010,   688,   637,   765,  1012,   923,   301,   449,     5,   802,
     301,  1019,   353,   701,   870,   648,   383,   301,   702,  1091,
     733,   385,   924,   622,   658,   643,   803,   639,   690,   626,
     966,   967,   968,   734,  1091,   393,   675,   969,   669,   751,
     650,   675,   386,   489,   734,  1045,  1134,   734,   303,   723,
     723,  1046,   301,  1025,   689,   692,   693,   701,   694,   745,
     736,   677,  1025,   395,  1136,   403,   677,   666,   667,   668,
     301,   736,  1099,  1141,   736,   408,   303,   116,   280,   301,
     113,  1196,  1099,   622,   623,   643,   735,   704,   946,   626,
    1196,   703,  1048,   752,   753,   754,  1088,   735,   669,  -284,
     735,  -108,   704,   601,   755,   602,   280,  1106,  1107,   695,
     957,   737,   746,  1161,  1163,   773,   400,  -108,  1025,  1162,
     301,   425,   737,  -767,  1091,   737,   696,  1025,   774,   775,
     622,   623,   448,   410,   486,   703,   785,   786,   787,   692,
     693,   788,   563,   293,   294,   669,  1196,  1099,  1003,   561,
     806,  1168,  1199,  1212,   723,  1196,   214,   301,  1200,   301,
    1025,   268,   269,   270,   271,   272,   273,   274,   275,   276,
     277,  1049,  1050,  1051,  1052,  1053,  1215,  1054,   478,   866,
     740,   415,  1216,   490,  1014,  1016,   454,     5,  1196,  1021,
     496,  1217,   704,   789,   259,   498,  1011,  1216,  1218,  1224,
     502,  1018,   621,  1226,  1216,   301,   869,   542,   543,  1046,
     790,   622,   623,   643,   624,   625,   741,   626,   627,   628,
     674,   511,   629,  1227,  1228,   776,   777,  1088,  1229,  1046,
    1046,   974,   867,   742,  1046,   514,   630,  1056,   515,  1231,
    1112,  1187,  1088,   521,  1064,  1046,   622,   623,   643,   734,
     734,   400,   626,  1204,  1205,   526,  1232,   870,   701,   734,
    1233,   669,   301,   116,   528,  1234,   301,   768,   769,   806,
     701,  1046,   530,   675,   806,   539,   736,   736,   692,   693,
     538,   694,  1002,     5,   563,  1092,   736,  1235,  1238,   778,
     779,   780,   781,  1046,   301,   541,   740,   861,   677,   782,
     783,  1243,   735,   735,  1246,  1004,  1005,   301,  1115,  1248,
    1247,   957,   735,   544,   862,  1247,   622,   623,  1256,   624,
     625,   546,   626,   957,  1247,  1123,  1124,   737,   737,  1264,
     578,  1187,  1088,  1265,   278,   301,   703,   737,   396,   301,
    1260,  1187,   547,  1274,  1283,  1303,  1138,   259,   703,  1046,
    1247,  1216,  1130,   579,   214,  1132,  1133,   571,  1135,  1277,
    1306,   391,  1139,  1140,   727,   728,  1046,  1152,  1153,  1307,
     259,  -284,  1308,   259,  1313,   301,   259,   259,   301,   259,
    1247,   259,  1206,  1207,   622,   623,  1164,   624,   625,   701,
     734,   588,  1314,   589,  1169,   629,   590,   679,   301,  1330,
     680,   681,   729,  1315,   701,  1260,  1187,  1332,   591,   301,
     666,   667,   668,   587,  1260,   592,  1092,   736,   612,   730,
    1058,  1059,  1060,  1191,  1192,   619,   622,   623,   643,  1300,
    1301,  1092,   626,   460,   461,   682,   503,   504,   505,   506,
     659,   669,   957,   735,   462,   463,    98,  1260,    64,    65,
     660,    66,    67,    63,   661,    64,    65,   957,    66,    67,
     785,   786,   787,   692,   693,   788,   664,   703,   737,   714,
     683,    68,  1272,   434,   468,   469,   738,  1221,    68,  1222,
    1223,   813,   703,   821,  1225,   622,   623,   684,   624,   625,
      63,   626,    64,    65,   701,    66,    67,    99,   100,   101,
     669,   102,   103,   104,   105,   106,   107,   108,   109,    69,
      70,    71,   670,   479,   822,    68,    69,    70,    71,   825,
     826,  1092,   667,   668,   827,   259,   603,   259,   621,   671,
     259,   830,   832,   727,   728,   740,   572,   622,   623,   643,
     624,   625,   214,   626,   627,   628,   396,   957,   629,   833,
     834,   887,   669,    69,    70,    71,   835,   888,   666,   667,
     668,   890,   630,   891,  1331,  1281,  1282,  1279,   892,  1284,
     898,   941,   703,   899,   622,   623,   643,   900,   907,   908,
     626,   464,   465,   466,   467,   727,   728,   740,   942,   669,
     910,   911,   111,   310,   280,   915,  1299,   622,   623,   917,
     624,   625,  1302,   937,   939,   947,   692,   693,   629,   694,
     679,   948,    72,   680,   681,   950,  1309,   113,   958,    72,
      73,    74,    75,    76,    77,    78,   629,    73,    74,    75,
      76,    77,    78,   622,   623,   114,   624,   625,   961,   626,
    1309,   962,   316,   963,   629,   973,  1321,   761,   682,   622,
     623,   977,   624,   625,   979,   626,    72,   982,   983,   984,
     902,   985,   986,   992,    73,    74,    75,    76,    77,    78,
     993,   994,   705,   716,   999,   995,   259,   903,   996,   114,
     997,   727,   728,   998,   259,  1078,  1079,  1080,  1081,  1000,
      98,     5,    64,    65,  1009,    66,    67,   727,   728,   396,
    1029,  1030,  1031,  1032,  1037,  1043,  1044,  1062,  1063,  1066,
    1067,  1070,   259,  1084,   259,    68,     6,     7,     8,     9,
      10,    11,    12,    13,    14,    15,    16,    17,    18,    19,
      20,    21,    22,    23,    24,    25,    26,    27,    28,    29,
    1103,    99,   100,   101,  1104,   102,   103,   104,   105,   106,
     107,   108,   109,    69,    70,    71,  1108,   110,    31,    98,
       5,    64,    65,  1109,    66,    67,  1110,  1114,  1116,  1118,
    1125,  1126,  1131,  1147,  1148,  1149,  1154,  1155,  1156,  1159,
    1165,  1170,  1174,  1183,    68,     6,     7,     8,     9,    10,
      11,    12,    13,    14,    15,    16,    17,    18,    19,    20,
      21,    22,    23,    24,    25,    26,    27,    28,    29,  1160,
      99,   100,   101,  1201,   102,   103,   104,   105,   106,   107,
     108,   109,    69,    70,    71,  1202,   110,    31,  1203,    98,
    1213,    64,    65,  1214,    66,    67,   111,   112,  1230,  1244,
    1268,  1269,   622,  1270,   643,  1271,  1285,    63,   626,    64,
      65,  1286,    66,    67,    68,  1288,    72,   669,  1289,  1304,
    1305,   113,   760,  1316,    73,    74,    75,    76,    77,    78,
    1318,  1322,    68,  1323,   692,   693,  1325,   694,  1326,   114,
      99,   100,   101,  1327,   102,   103,   104,   105,   106,   107,
     108,   109,    69,    70,    71,   471,   309,  1333,  1334,   989,
     988,   470,   540,   608,   472,   111,   112,   473,  1008,   474,
      69,    70,    71,   550,   532,   381,   207,   246,   553,   428,
     893,   895,   377,   764,   897,    72,    63,     5,    64,    65,
     113,    66,    67,    73,    74,    75,    76,    77,    78,  1242,
     239,   980,  1047,  1069,   959,  1077,  1181,  1296,   114,  1255,
    1312,    68,     6,     7,     8,     9,    10,    11,    12,    13,
      14,    15,    16,    17,    18,    19,    20,    21,    22,    23,
      24,    25,    26,    27,    28,    29,   310,    98,   912,    64,
      65,  1022,    66,    67,   527,  1290,  1319,  1111,   987,    69,
      70,    71,  1278,    30,    31,    72,     0,   964,     0,     0,
     113,     0,    68,    73,    74,    75,    76,    77,    78,     0,
       0,     0,     0,    72,   432,     0,     0,     0,   114,   412,
       5,    73,    74,    75,    76,    77,    78,     0,    99,   100,
     101,     0,   102,   103,   104,   105,   106,   107,   108,   109,
      69,    70,    71,     0,   533,     6,     7,     8,     9,    10,
      11,    12,    13,    14,    15,    16,    17,    18,    19,    20,
      21,    22,    23,    24,    25,    26,    27,    28,    29,    63,
       0,    64,    65,   621,    66,    67,     0,     0,     0,     0,
       0,     0,   622,   623,     0,   624,   625,     0,   626,   627,
     628,     0,    72,   629,    68,     0,     0,     0,     0,     0,
      73,    74,    75,    76,    77,    78,    63,   630,    64,    65,
     621,    66,    67,     0,     0,   487,     0,     0,     0,   622,
     623,   643,   624,   625,   310,   626,   627,   628,     0,     0,
     629,    68,    69,    70,    71,    63,     0,    64,    65,     0,
      66,    67,     0,    72,   630,     0,     0,     0,   113,     0,
       0,    73,    74,    75,    76,    77,    78,   667,   668,    63,
      68,    64,    65,   621,    66,    67,   114,     0,   631,    69,
      70,    71,   622,   623,   643,   624,   625,     0,   626,   627,
     628,     0,     0,   629,    68,   632,   413,   669,     0,   622,
     623,     0,   624,   625,     0,   626,     0,   630,    69,    70,
      71,   622,   623,   643,   669,     0,     0,   626,   414,     0,
       0,     0,     0,     0,     0,     0,   669,     0,     0,     0,
       0,     0,    69,    70,    71,    63,     0,    64,    65,     0,
      66,    67,     0,   692,   693,    72,   694,   727,   728,   740,
       0,     0,     0,    73,    74,    75,    76,    77,    78,     0,
      68,   740,     0,   420,     0,     0,    11,     0,   613,     0,
       0,     0,     0,     0,     0,    20,    21,     0,     0,     0,
       0,     0,    72,     0,     0,     0,     0,     0,     0,     0,
      73,    74,    75,    76,    77,    78,     0,   952,    69,    70,
      71,     0,     0,     0,     0,   616,     0,     0,     0,     0,
       0,    72,     0,     0,   953,     0,     0,     0,     0,    73,
      74,    75,    76,    77,    78,    63,     5,    64,    65,     0,
      66,    67,     0,     0,   856,    72,     0,     0,     0,     0,
       0,     0,     0,    73,    74,    75,    76,    77,    78,     0,
      68,     0,     0,     0,     0,  1276,    11,    12,    13,    14,
      15,    16,    17,    18,    19,    20,    21,    22,     0,    24,
      25,    26,    27,    28,    29,    63,     0,    64,    65,     0,
      66,    67,     0,     0,     0,     0,     0,     0,    69,    70,
      71,     0,    63,     0,    64,    65,     0,    66,    67,     0,
      68,    72,     0,   580,   421,     0,    11,     0,     0,    73,
     422,    75,    76,    77,    78,    20,    21,    68,    63,     0,
      64,    65,     0,    66,    67,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,    69,    70,
      71,     0,     0,    68,    63,     0,    64,    65,     0,    66,
      67,     0,     0,     0,     0,    69,    70,    71,     0,     0,
       0,    63,     0,    64,    65,     0,    66,    67,     0,    68,
       0,     0,     0,     0,     0,    11,     0,     0,     0,     0,
       0,    69,    70,    71,    20,    21,    68,     0,     0,     0,
       0,    72,    63,     0,    64,    65,     0,    66,    67,    73,
      74,    75,    76,    77,    78,     0,     0,    69,    70,    71,
      63,     0,    64,    65,     0,    66,    67,    68,     0,     0,
       0,     0,     0,     0,    69,    70,    71,     0,     0,     0,
       0,     0,     0,     0,     0,    68,     0,     0,     0,     0,
      63,    72,    64,    65,   581,    66,    67,     0,     0,    73,
     582,    75,    76,    77,    78,    69,    70,    71,    72,     0,
     841,     0,   842,   805,  1127,    68,    73,    74,    75,    76,
      77,    78,     0,    69,    70,    71,     0,     0,     0,     0,
       0,     0,     0,     0,    72,     0,   841,     0,   842,   805,
    1219,     0,    73,    74,    75,    76,    77,    78,     0,     0,
       0,     0,     0,    69,    70,    71,     0,     0,     0,    63,
      72,    64,    65,     0,    66,    67,     0,     0,    73,    74,
      75,    76,    77,    78,     0,     0,     0,    72,     0,   841,
       0,   842,   805,     0,    68,    73,    74,    75,    76,    77,
      78,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,    72,   451,
       0,     0,     0,     0,     0,     0,    73,    74,    75,    76,
      77,    78,    69,    70,    71,    63,    72,    64,    65,   597,
      66,    67,     0,     0,    73,   598,    75,    76,    77,    78,
       0,     0,     0,     0,     0,     0,    63,     0,    64,    65,
      68,    66,    67,     0,     0,     0,    72,     0,     0,     0,
       0,   603,     0,     0,    73,    74,    75,    76,    77,    78,
       0,    68,     0,     0,     0,     0,    63,     0,    64,    65,
       0,    66,    67,     0,     0,     0,     0,     0,    69,    70,
      71,    63,     0,    64,    65,     0,    66,    67,     0,     0,
       0,    68,     0,     0,     0,     0,     0,     0,     0,    69,
      70,    71,     0,     0,     0,     0,    68,    63,     0,    64,
      65,     0,    66,    67,     0,    72,   766,     0,     0,     0,
       0,     0,     0,    73,    74,    75,    76,    77,    78,    69,
      70,    71,    68,    63,     0,    64,    65,     0,    66,    67,
       0,     0,     0,     0,    69,    70,    71,     0,     0,     0,
       0,     0,     0,     0,    63,     0,    64,    65,    68,    66,
      67,     0,     0,     0,     0,     0,     0,     0,     0,     0,
      69,    70,    71,     0,     0,     0,     0,     0,     0,    68,
       0,    72,     0,     0,     0,     0,   805,     0,     0,    73,
      74,    75,    76,    77,    78,     0,    69,    70,    71,     0,
       0,    63,    72,    64,    65,   838,    66,    67,     0,     0,
      73,   839,    75,    76,    77,    78,     0,    69,    70,    71,
       0,     0,     0,     0,     0,    63,    68,    64,    65,     0,
      66,    67,    72,   853,     0,     0,     0,     0,     0,     0,
      73,    74,    75,    76,    77,    78,     0,    72,   858,     0,
      68,     0,     0,     0,     0,    73,    74,    75,    76,    77,
      78,     0,     0,     0,    69,    70,    71,     0,     0,     0,
       0,     0,     0,    72,  1013,     0,     0,     0,     0,     0,
       0,    73,    74,    75,    76,    77,    78,     0,    69,    70,
      71,    63,     0,    64,    65,     0,    66,    67,     0,    72,
    1015,     0,     0,     0,     0,     0,     0,    73,    74,    75,
      76,    77,    78,     0,     0,     0,    68,     0,     0,     0,
      72,  1020,     0,     0,     0,   621,     0,     0,    73,    74,
      75,    76,    77,    78,   622,   623,     0,   624,   625,     0,
     626,   627,   628,     0,    63,   629,    64,    65,     0,    66,
      67,     0,     0,     0,    69,    70,    71,     0,    63,   630,
      64,    65,     0,    66,    67,     0,     0,    72,  1137,    68,
       0,     0,     0,     0,     0,    73,    74,    75,    76,    77,
      78,     0,     0,    68,     0,     0,     0,     0,     0,     0,
       0,    72,     0,     0,     0,     0,     0,     0,     0,    73,
      74,    75,    76,    77,    78,     0,     0,    69,    70,    71,
     667,   668,     0,     0,     0,     0,   621,     0,     0,     0,
       0,    69,    70,    71,     0,   622,   623,   643,   624,   625,
       0,   626,   627,   628,     0,     0,   629,     0,     0,     0,
     669,     0,     1,     2,     3,     4,     5,     0,     0,     0,
     630,     0,     0,     0,     0,     0,     0,   248,     0,     0,
       0,     0,     0,     0,     0,    73,    74,    75,    76,    77,
      78,     6,     7,     8,     9,    10,    11,    12,    13,    14,
      15,    16,    17,    18,    19,    20,    21,    22,    23,    24,
      25,    26,    27,    28,    29,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
     251,   872,    30,    31,     4,     5,     0,     0,    73,    74,
      75,    76,    77,    78,    72,     0,     0,     0,   873,     0,
       0,     0,    73,  1105,    75,    76,    77,    78,     0,     0,
       6,     7,     8,     9,    10,    11,    12,    13,    14,    15,
      16,    17,    18,    19,    20,    21,    22,    23,    24,    25,
      26,    27,    28,    29,     0,     0,     0,     0,     0,     5,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,    30,    31,     0,     0,     0,     0,     0,     0,     0,
       0,     0,    32,     0,     0,     4,     5,     0,     0,    11,
      12,    13,    14,    15,    16,    17,    18,    19,    20,    21,
      22,    33,    24,    25,    26,    27,    28,    29,     0,     0,
      34,     6,     7,     8,     9,    10,    11,    12,    13,    14,
      15,    16,    17,    18,    19,    20,    21,    22,    23,    24,
      25,    26,    27,    28,    29,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,    32,    30,    31,     4,     5,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
      33,     0,     0,     0,     0,     0,     0,     0,     0,    34,
       6,     7,     8,     9,    10,    11,    12,    13,    14,    15,
      16,    17,    18,    19,    20,    21,    22,    23,    24,    25,
      26,    27,    28,    29,     0,     0,     0,     0,     0,     5,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,   427,    31,     0,     0,     0,     0,     0,     0,     0,
     404,     0,     0,     0,     0,     4,     5,     0,     0,    11,
      12,    13,    14,    15,    16,    17,    18,    19,    20,    21,
      22,    33,    24,    25,    26,    27,    28,    29,     0,     0,
      34,     6,     7,     8,     9,    10,    11,    12,    13,    14,
      15,    16,    17,    18,    19,    20,    21,    22,    23,    24,
      25,    26,    27,    28,    29,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     4,     5,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
      33,     0,     0,     0,     0,     0,     0,     0,     0,    34,
       6,     7,     8,     9,    10,    11,    12,    13,    14,    15,
      16,    17,    18,    19,    20,    21,    22,    23,    24,    25,
      26,    27,    28,    29,     0,     0,     0,     0,   622,   623,
     643,   624,   625,     0,   626,     0,     0,     0,     0,   629,
       0,   235,     0,   669,     0,     0,     0,     0,     0,     0,
     555,     0,     0,     0,     0,     4,     5,     0,     0,     0,
     692,   693,     0,   694,     0,     0,     0,   705,   716,     0,
       0,   567,   593,   443,     0,     5,   727,   728,   740,     0,
      34,     6,     7,     8,     9,    10,    11,    12,    13,    14,
      15,    16,    17,    18,    19,    20,    21,    22,    23,    24,
      25,    26,    27,    28,    29,    11,    12,    13,    14,    15,
      16,    17,    18,    19,    20,    21,    22,     0,    24,    25,
      26,    27,    28,    29,     0,     5,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
      33,     0,     0,     0,     5,     0,     0,     0,     0,    34,
       6,     7,     8,     9,    10,    11,    12,    13,    14,    15,
      16,    17,    18,    19,    20,    21,    22,    23,    24,    25,
      26,    27,    28,    29,    11,    12,    13,    14,    15,    16,
      17,    18,    19,    20,    21,    22,     0,    24,    25,    26,
      27,    28,    29,   667,   668,     0,     0,     0,     0,   621,
       0,     0,     0,     0,     0,     0,     0,     0,   622,   623,
     643,   624,   625,     0,   626,   627,   628,     0,     0,   629,
       0,    33,     5,   669,     0,     0,     0,     0,     0,     0,
      34,     0,     0,   630,     0,     0,     0,     0,     0,     0,
     692,   693,     0,   694,     0,     0,   809,     6,     7,     8,
       9,    10,    11,    12,    13,    14,    15,    16,    17,    18,
      19,    20,    21,    22,    23,    24,    25,    26,    27,    28,
      29,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,    30,    31,
     442,   593,   443,     5,  1023,     0,     0,     0,     0,    34,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,  1024,     0,     0,     0,   814,     0,     5,     6,     7,
       8,     9,    10,    11,    12,    13,    14,    15,    16,    17,
      18,    19,    20,    21,    22,    23,    24,    25,    26,    27,
      28,    29,     6,     7,     8,     9,    10,    11,    12,    13,
      14,    15,    16,    17,    18,    19,    20,    21,    22,    23,
      24,    25,    26,    27,    28,    29,     0,     0,     5,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,   113,     6,     7,     8,     9,    10,    11,    12,
      13,    14,    15,    16,    17,    18,    19,    20,    21,    22,
      23,    24,    25,    26,    27,    28,    29,   667,   668,     0,
       0,     0,     0,   621,     0,     0,     0,     0,     0,     0,
       0,     0,   622,   623,   643,   624,   625,     0,   626,   627,
     628,     0,     0,   629,     0,     0,     0,   669,     0,     0,
       0,     0,     0,     0,     0,     0,     0,   630,     0,   565,
       0,     0,     0,     0,   692,   693,     0,   694,     0,     0,
       0,   705,   716,   667,   668,     0,     0,     0,     0,   621,
     727,   728,   740,   819,     0,     0,     0,     0,   622,   623,
     643,   624,   625,     0,   626,   627,   628,     0,     0,   629,
       0,     0,     0,   669,     0,     0,     0,     0,     0,     0,
       0,     0,     0,   630,     0,     0,     0,     0,  1291,     0,
     692,   693,     0,   694,   667,   668,     0,     0,     0,     0,
     621,     0,     0,     0,   836,  1292,   727,   728,   740,   622,
     623,   643,   624,   625,     0,   626,   627,   628,     0,     0,
     629,     0,     0,     0,   669,     0,     0,     0,     0,     0,
       0,     0,     0,     0,   630,     0,     0,     0,     0,     0,
       0,     0,     0,     0,  1258,     0,     0,     0,   705,   716,
     667,   668,     0,     0,     0,     0,   621,   727,   728,   740,
       0,  1259,     0,     0,     0,   622,   623,   643,   624,   625,
       0,   626,   627,   628,     0,     0,   629,     0,     0,     0,
     669,     0,     0,     0,     0,     0,     0,     0,     0,     0,
     630,     0,     0,     0,     0,  1250,     0,   692,   693,     0,
     694,   667,   668,     0,     0,     0,     0,   621,     0,     0,
       0,     0,  1251,     0,     0,   740,   622,   623,   643,   624,
     625,     0,   626,   627,   628,     0,     0,   629,     0,     0,
       0,   669,     0,     0,     0,     0,     0,     0,     0,     0,
       0,   630,     0,     0,     0,     0,     0,     0,     0,     0,
       0,  1193,     0,     0,     0,   667,   668,     0,     0,     0,
       0,   621,     0,     0,   727,   728,   740,     0,  1194,     0,
     622,   623,   643,   624,   625,     0,   626,   627,   628,     0,
       0,   629,     0,     0,     0,   669,     0,     0,     0,     0,
     622,   623,   643,   624,   625,   630,   626,     0,     0,     0,
       0,   629,  1185,     0,     0,   669,     0,     0,     0,   622,
     623,   643,   624,   625,     0,   626,     0,     0,     0,  1186,
     740,     0,   692,   693,   669,   694,     0,     0,     0,   705,
     716,     0,     0,     0,     0,     0,     0,     0,   727,   728,
     740,   692,   693,     0,   694,     0,     0,     0,     0,   622,
     623,     0,   624,   625,     0,   626,  1097,   727,   728,   740,
     629,     0,     0,     0,   669,   666,   667,   668,     0,     0,
       0,     0,     0,  1098,     0,     0,  1176,     0,     0,     0,
       0,   622,   623,   643,     0,     0,     0,   626,   705,   716,
       0,   318,   319,  1177,   320,  1086,   669,   727,   728,   740,
       0,     0,     0,   321,   322,   323,   324,   325,   326,     0,
       0,     0,  1087,   692,   693,     0,   694,     0,     0,   327,
       0,   328,     0,   329,     0,     0,     0,   330,     0,     0,
       0,     0,     0,     0,     0,  1072,     0,   331,     0,     0,
       0,     0,     0,     0,     0,   210,   332,     0,     0,     0,
       0,     0,  1073,     0,     0,   333,   334,   318,   319,     0,
     320,     0,     0,     0,   335,     0,   336,     0,     0,   321,
     322,   323,   324,   325,   326,     0,     0,     0,   318,   319,
       0,   320,     0,   318,   319,   327,   320,   328,   761,   329,
     321,   322,   323,   330,   325,   321,   322,   323,     0,   325,
       0,     0,     0,   331,     0,     0,   327,     0,   328,     0,
       0,   327,   332,   328,     0,     0,     0,     0,     0,     0,
       0,   333,   334,     0,   331,     0,     0,     0,     0,   331,
     335,     0,   336,   332,     5,     0,     0,     0,   332,     0,
       0,     0,   333,   334,     0,     0,     0,   333,   334,     0,
       0,   335,     0,     0,     0,     0,   335,     0,     0,     6,
       7,     8,     9,    10,    11,    12,    13,    14,    15,    16,
      17,    18,    19,    20,    21,    22,    23,    24,    25,    26,
      27,    28,    29,     0,     0,     0,     0,   667,   668,     0,
       0,     0,     0,   621,     0,     0,     0,     0,     0,     0,
      30,    31,   622,   623,   643,   624,   625,     0,   626,   627,
     628,     0,     0,   629,     0,     0,     0,   669,     0,     0,
       0,     0,     0,     0,     0,     0,     0,   630,     0,     0,
       0,     0,     0,     0,   692,   693,     0,   694,   667,   668,
       0,   705,   716,     0,   621,     0,     0,     0,     0,     0,
     727,   728,   740,   622,   623,   643,   624,   625,     0,   626,
     627,   628,     0,     0,   629,     0,     0,     0,   669,     0,
       0,     0,     0,     0,   667,   668,     0,     0,   630,     0,
     621,     0,     0,     0,     0,   692,   693,     0,   694,   622,
     623,   643,   624,   625,     0,   626,   627,   628,     0,     0,
     629,   727,   728,   740,   669,     0,     0,     0,     0,     0,
       0,     0,     0,     0,   630,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,   667,   668,     0,   705,   716,
       0,   621,     0,     0,     0,     0,     0,   727,   728,   740,
     622,   623,   643,   624,   625,     0,   626,   627,   628,     0,
       0,   629,     0,     0,     0,   669,     0,     0,     0,     0,
       0,   667,   668,     0,     0,   630,     0,   621,     0,     0,
       0,     0,   692,   693,     0,   694,   622,   623,   643,   624,
     625,     0,   626,   627,   628,     0,     0,   629,   667,   668,
     740,   669,     0,     0,   621,     0,     0,     0,     0,     0,
       0,   630,     0,   622,   623,   643,   624,   625,     0,   626,
     627,   628,     0,     0,   629,     0,     0,     0,   669,   622,
     623,   643,   624,   625,     0,   626,   740,     0,   630,     0,
       0,     0,     0,     0,   669,   692,   693,     0,   694,     0,
       0,     0,   622,   623,     0,   624,   625,     0,   626,     0,
       0,   692,   693,   629,   694,     0,     0,   669,     0,     0,
       0,     0,     0,     0,     0,     0,     0,   727,   728,   740,
       5,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,   705,   716,     0,     0,     0,     0,     0,     0,     0,
     727,   728,   740,     5,     0,     6,     7,     8,     9,    10,
      11,    12,    13,    14,    15,    16,    17,    18,    19,    20,
      21,    22,    23,    24,    25,    26,    27,    28,    29,   817,
       5,     0,     0,    11,    12,    13,    14,    15,    16,    17,
      18,    19,    20,    21,    22,     0,    24,    25,    26,    27,
      28,    29,     5,     0,     0,     6,     7,     8,     9,    10,
      11,    12,    13,    14,    15,    16,    17,    18,    19,    20,
      21,    22,    23,    24,    25,    26,    27,    28,    29,     0,
       0,     0,     0,    12,    13,    14,    15,    16,    17,    18,
      19,     0,     0,    22,     0,    24,    25,    26,    27,    28,
      29,   352,     0,     0,     0,     0,     0,   356,     0,   357,
       0,   358,     0,     0,     0,     0,     0,     0,     0,     0,
       0,   362,     0,   363,     0,   364,     0,     0,     0,     0,
       0,   367,     0,   368,     0,   369,     0,   370,     0,   371,
       0,   372,     0,   373,     0,   374,     0,     0,     0,   376
};

static const yytype_int16 yycheck[] =
{
       1,    66,    67,    68,    99,    72,   265,   495,    47,   121,
     231,   512,   494,   520,   231,     2,   551,    41,    83,   620,
     248,   232,   543,   251,   512,   726,   254,   255,   516,   572,
     541,   545,   545,   516,    99,     0,   985,   986,     3,     6,
     739,    33,   305,   709,    20,    37,   557,   232,   512,     0,
      49,   713,     3,   522,   951,   940,   258,    55,   444,    34,
      58,  1005,   247,   517,   888,     6,  1085,    73,   253,    83,
      62,    72,  1067,    38,    39,   104,  1096,   129,    43,    44,
     265,  1184,   104,    88,    49,     6,   105,  1082,    99,   179,
      55,    75,   525,    58,   279,   229,    75,    62,    49,   154,
     172,    75,     0,   132,   133,   195,     6,   225,   109,     6,
       7,   871,   494,     6,   119,   120,   301,   104,  1029,  1030,
    1031,  1032,   172,     6,   196,   117,  1037,    76,     6,   172,
     618,   513,  1043,  1044,   121,   154,   618,   121,     6,   257,
     522,   259,   121,   405,   155,   156,   157,   121,     6,   631,
     179,  1062,  1063,   196,   103,  1258,   644,   179,   225,   983,
     177,   513,   182,   183,   665,   517,  1185,   196,   520,   670,
    1165,     6,   178,  1193,   196,   527,    37,   665,    15,    16,
    1124,   248,   670,   569,   251,    46,    47,   254,   255,   172,
     257,   174,   259,   173,   172,   172,   174,   414,   181,   179,
    1097,  1086,   516,  1114,   665,   172,   670,   695,   207,   420,
     717,   525,   695,   415,   181,   478,   192,   282,   283,   284,
     285,   286,   287,   288,   289,   290,   291,   292,   293,   294,
     295,   296,   297,   298,   299,   420,   618,   178,   262,   424,
     941,   216,   207,   267,   236,   243,   715,   248,   769,   631,
     251,   739,   244,   952,   920,   709,   207,   178,   443,   713,
     729,   923,  1257,  1023,  1213,   266,   231,   401,   282,   283,
     284,   872,   172,   816,   137,   789,   789,   411,   243,   538,
     177,   181,   145,   258,   177,   403,   172,   405,   151,   172,
     408,   174,   554,   726,   172,   195,   159,   431,   161,   300,
     562,   683,   813,   173,   172,   306,   307,   308,   741,   179,
     845,   312,  1175,   181,   172,   302,   179,   104,   305,  1230,
     181,   172,   185,   181,   187,   193,   179,   195,   191,   172,
     841,   683,     9,   715,   197,   193,   403,   172,   405,   174,
     193,   408,   193,   106,   726,   132,   181,   729,   135,   136,
     951,   188,   189,   538,    77,   172,   573,   709,   179,   346,
      99,   713,   590,   715,   592,   717,   551,    10,    11,    12,
      93,    94,    95,   861,   195,   180,    99,   194,   179,   861,
     601,   695,   121,   448,   179,   403,  1249,  1250,   179,   105,
     408,   130,   577,   179,   195,   580,   748,   160,   161,   162,
     195,   902,   587,     2,   195,    77,   398,   175,   171,   195,
     871,   179,   726,   115,   902,   407,   179,   602,   603,   553,
     532,    93,    94,   415,   931,   739,   173,   741,  1291,   131,
     102,    84,   179,   196,   448,   179,   554,   139,   154,   179,
     415,   902,   158,    96,   562,    98,   541,   163,   174,   414,
     176,   195,   940,   193,    93,    94,   179,    96,    97,    58,
      99,   106,   557,   932,   952,   104,   920,   442,   194,   923,
    1005,    75,    76,   196,   191,   181,   541,   442,   190,   861,
     186,   187,   494,   495,  1085,   497,   487,   554,   489,    77,
     353,   478,   557,   132,   133,   562,  1097,   360,   931,   103,
     512,   513,   141,   142,   516,    93,    94,   179,   941,   494,
     522,   173,   607,   525,   102,   179,   179,   179,   951,   164,
     165,   166,   121,   590,   196,   592,   171,   104,   513,   172,
     569,   174,   195,   176,   179,   494,   495,   522,   497,   129,
     179,   173,   607,    19,   148,   532,   173,   179,   138,   931,
     932,   196,   179,   512,   513,   132,   133,   196,   940,   941,
     494,   495,  1023,   522,  1071,  1072,   525,   179,   920,    77,
     193,   923,   172,   104,  1175,   567,   179,   179,   512,   931,
     932,   193,   516,  1071,  1185,    93,    94,    95,   522,  1124,
     193,    99,   567,   195,  1129,    93,    94,   173,  1086,    99,
     104,   132,   567,   179,   135,   136,   618,   572,   573,   172,
     108,   612,   613,   172,   615,   616,   172,   931,   174,   631,
     805,   172,   609,   610,   611,     6,   940,   941,   132,   133,
     195,   230,   644,   618,   173,  1096,   601,   173,   952,  1072,
     179,   653,   106,   179,   243,   143,   631,   195,   179,  1250,
      13,    14,  1085,   665,   178,   155,   156,   157,   670,   618,
     845,   173,   173,  1096,  1097,   196,    64,   179,   179,  1176,
     173,   683,   631,   536,   173,   179,   179,     6,     7,   179,
     179,   173,   177,   695,   618,   644,     6,   179,  1176,  1071,
    1072,   177,   196,    93,   653,    95,   196,   631,   683,    99,
     164,   165,   166,   715,  1086,   172,   665,   171,   108,   106,
     644,   670,     6,   312,   726,   173,   173,   729,   813,  1071,
    1072,   179,   179,  1184,   683,   125,   126,   739,   128,   741,
     715,   665,  1193,   173,   173,   177,   670,    77,    78,    79,
     179,   726,  1175,   173,   729,   177,   841,   346,   813,   179,
     177,  1184,  1185,    93,    94,    95,   715,  1071,  1072,    99,
    1193,   695,     1,   160,   161,   162,   940,   726,   108,   177,
     729,   179,  1086,   172,   171,   174,   841,   962,   963,   179,
     739,   715,   741,   173,   173,     6,   194,   195,  1249,   179,
     179,   129,   726,   177,  1176,   729,   196,  1258,    19,    20,
      93,    94,   173,   402,    62,   739,   122,   123,   124,   125,
     126,   127,   411,    17,    18,   108,  1249,  1250,   842,   811,
    1005,   173,   173,   173,  1176,  1258,    34,   179,   179,   179,
    1291,    21,    22,    23,    24,    25,    26,    27,    28,    29,
      30,    80,    81,    82,    83,    84,   173,    86,   193,   861,
     143,   816,   179,   195,   855,   856,     6,     7,  1291,   860,
     196,   173,  1176,   179,    72,   196,   853,   179,   173,   173,
     196,   858,    84,   173,   179,   179,   861,   178,   179,   179,
     196,    93,    94,    95,    96,    97,   179,    99,   100,   101,
     902,   121,   104,   173,   173,   116,   117,  1071,   173,   179,
     179,   764,   861,   196,   179,   196,   118,   908,   196,   173,
     977,  1085,  1086,   140,   915,   179,    93,    94,    95,   931,
     932,   194,    99,  1108,  1109,   196,   173,   861,   940,   941,
     173,   108,   179,   532,   196,   173,   179,   178,   179,  1124,
     952,   179,   196,   902,  1129,   195,   931,   932,   125,   126,
     172,   128,     6,     7,   553,   940,   941,   173,   173,   180,
     181,   182,   183,   179,   179,   194,   143,   179,   902,   190,
     191,   173,   931,   932,   173,   178,   179,   179,   979,   173,
     179,   940,   941,   172,   196,   179,    93,    94,   173,    96,
      97,   196,    99,   952,   179,   178,   179,   931,   932,   173,
     175,  1175,  1176,   173,   194,   179,   940,   941,   216,   179,
    1184,  1185,     6,   173,   173,   173,  1017,   225,   952,   179,
     179,   179,  1009,   175,   232,  1012,  1013,   173,  1015,  1214,
     173,   121,  1019,  1020,   141,   142,   179,  1038,  1039,   173,
     248,   177,   173,   251,   173,   179,   254,   255,   179,   257,
     179,   259,   167,   168,    93,    94,  1057,    96,    97,  1071,
    1072,   173,   173,   173,  1065,   104,   179,   106,   179,  1328,
     109,   110,   179,   173,  1086,  1249,  1250,   173,   179,   179,
      77,    78,    79,   179,  1258,   179,  1071,  1072,   172,   196,
     145,   146,   147,  1094,  1095,   121,    93,    94,    95,   169,
     170,  1086,    99,   285,   286,   144,   112,   113,   114,   115,
       6,   108,  1071,  1072,   287,   288,     6,  1291,     8,     9,
     196,    11,    12,     6,   149,     8,     9,  1086,    11,    12,
     122,   123,   124,   125,   126,   127,   196,  1071,  1072,   140,
     179,    31,  1209,  1328,   293,   294,   103,  1134,    31,  1136,
    1137,   193,  1086,     6,  1141,    93,    94,   196,    96,    97,
       6,    99,     8,     9,  1176,    11,    12,    57,    58,    59,
     108,    61,    62,    63,    64,    65,    66,    67,    68,    69,
      70,    71,   179,    73,   175,    31,    69,    70,    71,   175,
     175,  1176,    78,    79,   129,   403,   177,   405,    84,   196,
     408,     6,   173,   141,   142,   143,   179,    93,    94,    95,
      96,    97,   420,    99,   100,   101,   424,  1176,   104,   173,
     175,   172,   108,    69,    70,    71,   175,   172,    77,    78,
      79,   172,   118,   172,  1329,  1236,  1237,  1224,   172,  1240,
     173,   179,  1176,   196,    93,    94,    95,     6,   172,   172,
      99,   289,   290,   291,   292,   141,   142,   143,   196,   108,
     172,   172,   152,   153,  1329,   172,  1267,    93,    94,   172,
      96,    97,  1273,   172,   103,   172,   125,   126,   104,   128,
     106,   172,   172,   109,   110,   121,  1287,   177,   172,   172,
     180,   181,   182,   183,   184,   185,   104,   180,   181,   182,
     183,   184,   185,    93,    94,   195,    96,    97,   196,    99,
    1311,   172,   195,   172,   104,   196,  1317,    85,   144,    93,
      94,   193,    96,    97,   172,    99,   172,     6,   172,   172,
     179,   172,   172,   175,   180,   181,   182,   183,   184,   185,
     175,   130,   132,   133,   175,   173,   554,   196,   173,   195,
     173,   141,   142,   173,   562,   134,   135,   136,   137,   175,
       6,     7,     8,     9,    60,    11,    12,   141,   142,   577,
     172,   172,   172,   172,   172,   172,   172,   172,   172,   172,
     172,   103,   590,   121,   592,    31,    32,    33,    34,    35,
      36,    37,    38,    39,    40,    41,    42,    43,    44,    45,
      46,    47,    48,    49,    50,    51,    52,    53,    54,    55,
      80,    57,    58,    59,   196,    61,    62,    63,    64,    65,
      66,    67,    68,    69,    70,    71,   172,    73,    74,     6,
       7,     8,     9,   172,    11,    12,   172,   172,   196,     6,
     196,   175,   195,   173,   173,   173,   173,   173,   173,     6,
     193,     6,   121,   193,    31,    32,    33,    34,    35,    36,
      37,    38,    39,    40,    41,    42,    43,    44,    45,    46,
      47,    48,    49,    50,    51,    52,    53,    54,    55,   179,
      57,    58,    59,   173,    61,    62,    63,    64,    65,    66,
      67,    68,    69,    70,    71,   173,    73,    74,   173,     6,
     193,     8,     9,   174,    11,    12,   152,   153,   193,   174,
     173,   173,    93,   179,    95,   173,   173,     6,    99,     8,
       9,   173,    11,    12,    31,   174,   172,   108,     6,     6,
     175,   177,   178,   175,   180,   181,   182,   183,   184,   185,
     175,   175,    31,   151,   125,   126,   172,   128,   196,   195,
      57,    58,    59,     6,    61,    62,    63,    64,    65,    66,
      67,    68,    69,    70,    71,   296,    73,   173,   173,   811,
     805,   295,   385,   478,   297,   152,   153,   298,   846,   299,
      69,    70,    71,   398,   346,   194,     3,    62,   402,   243,
     631,   644,   183,   535,   653,   172,     6,     7,     8,     9,
     177,    11,    12,   180,   181,   182,   183,   184,   185,  1167,
      55,   789,   902,   923,   741,   932,  1072,  1250,   195,  1176,
    1291,    31,    32,    33,    34,    35,    36,    37,    38,    39,
      40,    41,    42,    43,    44,    45,    46,    47,    48,    49,
      50,    51,    52,    53,    54,    55,   153,     6,   683,     8,
       9,   861,    11,    12,   336,  1247,  1311,   970,   802,    69,
      70,    71,  1216,    73,    74,   172,    -1,   756,    -1,    -1,
     177,    -1,    31,   180,   181,   182,   183,   184,   185,    -1,
      -1,    -1,    -1,   172,   173,    -1,    -1,    -1,   195,     6,
       7,   180,   181,   182,   183,   184,   185,    -1,    57,    58,
      59,    -1,    61,    62,    63,    64,    65,    66,    67,    68,
      69,    70,    71,    -1,    73,    32,    33,    34,    35,    36,
      37,    38,    39,    40,    41,    42,    43,    44,    45,    46,
      47,    48,    49,    50,    51,    52,    53,    54,    55,     6,
      -1,     8,     9,    84,    11,    12,    -1,    -1,    -1,    -1,
      -1,    -1,    93,    94,    -1,    96,    97,    -1,    99,   100,
     101,    -1,   172,   104,    31,    -1,    -1,    -1,    -1,    -1,
     180,   181,   182,   183,   184,   185,     6,   118,     8,     9,
      84,    11,    12,    -1,    -1,   195,    -1,    -1,    -1,    93,
      94,    95,    96,    97,   153,    99,   100,   101,    -1,    -1,
     104,    31,    69,    70,    71,     6,    -1,     8,     9,    -1,
      11,    12,    -1,   172,   118,    -1,    -1,    -1,   177,    -1,
      -1,   180,   181,   182,   183,   184,   185,    78,    79,     6,
      31,     8,     9,    84,    11,    12,   195,    -1,   179,    69,
      70,    71,    93,    94,    95,    96,    97,    -1,    99,   100,
     101,    -1,    -1,   104,    31,   196,   173,   108,    -1,    93,
      94,    -1,    96,    97,    -1,    99,    -1,   118,    69,    70,
      71,    93,    94,    95,   108,    -1,    -1,    99,   195,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,   108,    -1,    -1,    -1,
      -1,    -1,    69,    70,    71,     6,    -1,     8,     9,    -1,
      11,    12,    -1,   125,   126,   172,   128,   141,   142,   143,
      -1,    -1,    -1,   180,   181,   182,   183,   184,   185,    -1,
      31,   143,    -1,    34,    -1,    -1,    37,    -1,   195,    -1,
      -1,    -1,    -1,    -1,    -1,    46,    47,    -1,    -1,    -1,
      -1,    -1,   172,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
     180,   181,   182,   183,   184,   185,    -1,   179,    69,    70,
      71,    -1,    -1,    -1,    -1,   195,    -1,    -1,    -1,    -1,
      -1,   172,    -1,    -1,   196,    -1,    -1,    -1,    -1,   180,
     181,   182,   183,   184,   185,     6,     7,     8,     9,    -1,
      11,    12,    -1,    -1,   195,   172,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,   180,   181,   182,   183,   184,   185,    -1,
      31,    -1,    -1,    -1,    -1,   192,    37,    38,    39,    40,
      41,    42,    43,    44,    45,    46,    47,    48,    -1,    50,
      51,    52,    53,    54,    55,     6,    -1,     8,     9,    -1,
      11,    12,    -1,    -1,    -1,    -1,    -1,    -1,    69,    70,
      71,    -1,     6,    -1,     8,     9,    -1,    11,    12,    -1,
      31,   172,    -1,    34,   175,    -1,    37,    -1,    -1,   180,
     181,   182,   183,   184,   185,    46,    47,    31,     6,    -1,
       8,     9,    -1,    11,    12,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    69,    70,
      71,    -1,    -1,    31,     6,    -1,     8,     9,    -1,    11,
      12,    -1,    -1,    -1,    -1,    69,    70,    71,    -1,    -1,
      -1,     6,    -1,     8,     9,    -1,    11,    12,    -1,    31,
      -1,    -1,    -1,    -1,    -1,    37,    -1,    -1,    -1,    -1,
      -1,    69,    70,    71,    46,    47,    31,    -1,    -1,    -1,
      -1,   172,     6,    -1,     8,     9,    -1,    11,    12,   180,
     181,   182,   183,   184,   185,    -1,    -1,    69,    70,    71,
       6,    -1,     8,     9,    -1,    11,    12,    31,    -1,    -1,
      -1,    -1,    -1,    -1,    69,    70,    71,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    31,    -1,    -1,    -1,    -1,
       6,   172,     8,     9,   175,    11,    12,    -1,    -1,   180,
     181,   182,   183,   184,   185,    69,    70,    71,   172,    -1,
     174,    -1,   176,   177,   178,    31,   180,   181,   182,   183,
     184,   185,    -1,    69,    70,    71,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,   172,    -1,   174,    -1,   176,   177,
     178,    -1,   180,   181,   182,   183,   184,   185,    -1,    -1,
      -1,    -1,    -1,    69,    70,    71,    -1,    -1,    -1,     6,
     172,     8,     9,    -1,    11,    12,    -1,    -1,   180,   181,
     182,   183,   184,   185,    -1,    -1,    -1,   172,    -1,   174,
      -1,   176,   177,    -1,    31,   180,   181,   182,   183,   184,
     185,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   172,   173,
      -1,    -1,    -1,    -1,    -1,    -1,   180,   181,   182,   183,
     184,   185,    69,    70,    71,     6,   172,     8,     9,   175,
      11,    12,    -1,    -1,   180,   181,   182,   183,   184,   185,
      -1,    -1,    -1,    -1,    -1,    -1,     6,    -1,     8,     9,
      31,    11,    12,    -1,    -1,    -1,   172,    -1,    -1,    -1,
      -1,   177,    -1,    -1,   180,   181,   182,   183,   184,   185,
      -1,    31,    -1,    -1,    -1,    -1,     6,    -1,     8,     9,
      -1,    11,    12,    -1,    -1,    -1,    -1,    -1,    69,    70,
      71,     6,    -1,     8,     9,    -1,    11,    12,    -1,    -1,
      -1,    31,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    69,
      70,    71,    -1,    -1,    -1,    -1,    31,     6,    -1,     8,
       9,    -1,    11,    12,    -1,   172,   173,    -1,    -1,    -1,
      -1,    -1,    -1,   180,   181,   182,   183,   184,   185,    69,
      70,    71,    31,     6,    -1,     8,     9,    -1,    11,    12,
      -1,    -1,    -1,    -1,    69,    70,    71,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,     6,    -1,     8,     9,    31,    11,
      12,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      69,    70,    71,    -1,    -1,    -1,    -1,    -1,    -1,    31,
      -1,   172,    -1,    -1,    -1,    -1,   177,    -1,    -1,   180,
     181,   182,   183,   184,   185,    -1,    69,    70,    71,    -1,
      -1,     6,   172,     8,     9,   175,    11,    12,    -1,    -1,
     180,   181,   182,   183,   184,   185,    -1,    69,    70,    71,
      -1,    -1,    -1,    -1,    -1,     6,    31,     8,     9,    -1,
      11,    12,   172,   173,    -1,    -1,    -1,    -1,    -1,    -1,
     180,   181,   182,   183,   184,   185,    -1,   172,   173,    -1,
      31,    -1,    -1,    -1,    -1,   180,   181,   182,   183,   184,
     185,    -1,    -1,    -1,    69,    70,    71,    -1,    -1,    -1,
      -1,    -1,    -1,   172,   173,    -1,    -1,    -1,    -1,    -1,
      -1,   180,   181,   182,   183,   184,   185,    -1,    69,    70,
      71,     6,    -1,     8,     9,    -1,    11,    12,    -1,   172,
     173,    -1,    -1,    -1,    -1,    -1,    -1,   180,   181,   182,
     183,   184,   185,    -1,    -1,    -1,    31,    -1,    -1,    -1,
     172,   173,    -1,    -1,    -1,    84,    -1,    -1,   180,   181,
     182,   183,   184,   185,    93,    94,    -1,    96,    97,    -1,
      99,   100,   101,    -1,     6,   104,     8,     9,    -1,    11,
      12,    -1,    -1,    -1,    69,    70,    71,    -1,     6,   118,
       8,     9,    -1,    11,    12,    -1,    -1,   172,   173,    31,
      -1,    -1,    -1,    -1,    -1,   180,   181,   182,   183,   184,
     185,    -1,    -1,    31,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,   172,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   180,
     181,   182,   183,   184,   185,    -1,    -1,    69,    70,    71,
      78,    79,    -1,    -1,    -1,    -1,    84,    -1,    -1,    -1,
      -1,    69,    70,    71,    -1,    93,    94,    95,    96,    97,
      -1,    99,   100,   101,    -1,    -1,   104,    -1,    -1,    -1,
     108,    -1,     3,     4,     5,     6,     7,    -1,    -1,    -1,
     118,    -1,    -1,    -1,    -1,    -1,    -1,   172,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,   180,   181,   182,   183,   184,
     185,    32,    33,    34,    35,    36,    37,    38,    39,    40,
      41,    42,    43,    44,    45,    46,    47,    48,    49,    50,
      51,    52,    53,    54,    55,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
     172,   179,    73,    74,     6,     7,    -1,    -1,   180,   181,
     182,   183,   184,   185,   172,    -1,    -1,    -1,   196,    -1,
      -1,    -1,   180,   181,   182,   183,   184,   185,    -1,    -1,
      32,    33,    34,    35,    36,    37,    38,    39,    40,    41,
      42,    43,    44,    45,    46,    47,    48,    49,    50,    51,
      52,    53,    54,    55,    -1,    -1,    -1,    -1,    -1,     7,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    73,    74,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,   153,    -1,    -1,     6,     7,    -1,    -1,    37,
      38,    39,    40,    41,    42,    43,    44,    45,    46,    47,
      48,   172,    50,    51,    52,    53,    54,    55,    -1,    -1,
     181,    32,    33,    34,    35,    36,    37,    38,    39,    40,
      41,    42,    43,    44,    45,    46,    47,    48,    49,    50,
      51,    52,    53,    54,    55,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,   153,    73,    74,     6,     7,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
     172,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   181,
      32,    33,    34,    35,    36,    37,    38,    39,    40,    41,
      42,    43,    44,    45,    46,    47,    48,    49,    50,    51,
      52,    53,    54,    55,    -1,    -1,    -1,    -1,    -1,     7,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    73,    74,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
     178,    -1,    -1,    -1,    -1,     6,     7,    -1,    -1,    37,
      38,    39,    40,    41,    42,    43,    44,    45,    46,    47,
      48,   172,    50,    51,    52,    53,    54,    55,    -1,    -1,
     181,    32,    33,    34,    35,    36,    37,    38,    39,    40,
      41,    42,    43,    44,    45,    46,    47,    48,    49,    50,
      51,    52,    53,    54,    55,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,     6,     7,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
     172,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   181,
      32,    33,    34,    35,    36,    37,    38,    39,    40,    41,
      42,    43,    44,    45,    46,    47,    48,    49,    50,    51,
      52,    53,    54,    55,    -1,    -1,    -1,    -1,    93,    94,
      95,    96,    97,    -1,    99,    -1,    -1,    -1,    -1,   104,
      -1,    73,    -1,   108,    -1,    -1,    -1,    -1,    -1,    -1,
     178,    -1,    -1,    -1,    -1,     6,     7,    -1,    -1,    -1,
     125,   126,    -1,   128,    -1,    -1,    -1,   132,   133,    -1,
      -1,   172,   173,   174,    -1,     7,   141,   142,   143,    -1,
     181,    32,    33,    34,    35,    36,    37,    38,    39,    40,
      41,    42,    43,    44,    45,    46,    47,    48,    49,    50,
      51,    52,    53,    54,    55,    37,    38,    39,    40,    41,
      42,    43,    44,    45,    46,    47,    48,    -1,    50,    51,
      52,    53,    54,    55,    -1,     7,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
     172,    -1,    -1,    -1,     7,    -1,    -1,    -1,    -1,   181,
      32,    33,    34,    35,    36,    37,    38,    39,    40,    41,
      42,    43,    44,    45,    46,    47,    48,    49,    50,    51,
      52,    53,    54,    55,    37,    38,    39,    40,    41,    42,
      43,    44,    45,    46,    47,    48,    -1,    50,    51,    52,
      53,    54,    55,    78,    79,    -1,    -1,    -1,    -1,    84,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    93,    94,
      95,    96,    97,    -1,    99,   100,   101,    -1,    -1,   104,
      -1,   172,     7,   108,    -1,    -1,    -1,    -1,    -1,    -1,
     181,    -1,    -1,   118,    -1,    -1,    -1,    -1,    -1,    -1,
     125,   126,    -1,   128,    -1,    -1,   178,    32,    33,    34,
      35,    36,    37,    38,    39,    40,    41,    42,    43,    44,
      45,    46,    47,    48,    49,    50,    51,    52,    53,    54,
      55,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    73,    74,
     172,   173,   174,     7,   179,    -1,    -1,    -1,    -1,   181,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,   196,    -1,    -1,    -1,   178,    -1,     7,    32,    33,
      34,    35,    36,    37,    38,    39,    40,    41,    42,    43,
      44,    45,    46,    47,    48,    49,    50,    51,    52,    53,
      54,    55,    32,    33,    34,    35,    36,    37,    38,    39,
      40,    41,    42,    43,    44,    45,    46,    47,    48,    49,
      50,    51,    52,    53,    54,    55,    -1,    -1,     7,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,   177,    32,    33,    34,    35,    36,    37,    38,
      39,    40,    41,    42,    43,    44,    45,    46,    47,    48,
      49,    50,    51,    52,    53,    54,    55,    78,    79,    -1,
      -1,    -1,    -1,    84,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    93,    94,    95,    96,    97,    -1,    99,   100,
     101,    -1,    -1,   104,    -1,    -1,    -1,   108,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,   118,    -1,   173,
      -1,    -1,    -1,    -1,   125,   126,    -1,   128,    -1,    -1,
      -1,   132,   133,    78,    79,    -1,    -1,    -1,    -1,    84,
     141,   142,   143,   173,    -1,    -1,    -1,    -1,    93,    94,
      95,    96,    97,    -1,    99,   100,   101,    -1,    -1,   104,
      -1,    -1,    -1,   108,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,   118,    -1,    -1,    -1,    -1,   179,    -1,
     125,   126,    -1,   128,    78,    79,    -1,    -1,    -1,    -1,
      84,    -1,    -1,    -1,   173,   196,   141,   142,   143,    93,
      94,    95,    96,    97,    -1,    99,   100,   101,    -1,    -1,
     104,    -1,    -1,    -1,   108,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,   118,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,   179,    -1,    -1,    -1,   132,   133,
      78,    79,    -1,    -1,    -1,    -1,    84,   141,   142,   143,
      -1,   196,    -1,    -1,    -1,    93,    94,    95,    96,    97,
      -1,    99,   100,   101,    -1,    -1,   104,    -1,    -1,    -1,
     108,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
     118,    -1,    -1,    -1,    -1,   179,    -1,   125,   126,    -1,
     128,    78,    79,    -1,    -1,    -1,    -1,    84,    -1,    -1,
      -1,    -1,   196,    -1,    -1,   143,    93,    94,    95,    96,
      97,    -1,    99,   100,   101,    -1,    -1,   104,    -1,    -1,
      -1,   108,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,   118,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,   179,    -1,    -1,    -1,    78,    79,    -1,    -1,    -1,
      -1,    84,    -1,    -1,   141,   142,   143,    -1,   196,    -1,
      93,    94,    95,    96,    97,    -1,    99,   100,   101,    -1,
      -1,   104,    -1,    -1,    -1,   108,    -1,    -1,    -1,    -1,
      93,    94,    95,    96,    97,   118,    99,    -1,    -1,    -1,
      -1,   104,   179,    -1,    -1,   108,    -1,    -1,    -1,    93,
      94,    95,    96,    97,    -1,    99,    -1,    -1,    -1,   196,
     143,    -1,   125,   126,   108,   128,    -1,    -1,    -1,   132,
     133,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   141,   142,
     143,   125,   126,    -1,   128,    -1,    -1,    -1,    -1,    93,
      94,    -1,    96,    97,    -1,    99,   179,   141,   142,   143,
     104,    -1,    -1,    -1,   108,    77,    78,    79,    -1,    -1,
      -1,    -1,    -1,   196,    -1,    -1,   179,    -1,    -1,    -1,
      -1,    93,    94,    95,    -1,    -1,    -1,    99,   132,   133,
      -1,    75,    76,   196,    78,   179,   108,   141,   142,   143,
      -1,    -1,    -1,    87,    88,    89,    90,    91,    92,    -1,
      -1,    -1,   196,   125,   126,    -1,   128,    -1,    -1,   103,
      -1,   105,    -1,   107,    -1,    -1,    -1,   111,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,   179,    -1,   121,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,   129,   130,    -1,    -1,    -1,
      -1,    -1,   196,    -1,    -1,   139,   140,    75,    76,    -1,
      78,    -1,    -1,    -1,   148,    -1,   150,    -1,    -1,    87,
      88,    89,    90,    91,    92,    -1,    -1,    -1,    75,    76,
      -1,    78,    -1,    75,    76,   103,    78,   105,    85,   107,
      87,    88,    89,   111,    91,    87,    88,    89,    -1,    91,
      -1,    -1,    -1,   121,    -1,    -1,   103,    -1,   105,    -1,
      -1,   103,   130,   105,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,   139,   140,    -1,   121,    -1,    -1,    -1,    -1,   121,
     148,    -1,   150,   130,     7,    -1,    -1,    -1,   130,    -1,
      -1,    -1,   139,   140,    -1,    -1,    -1,   139,   140,    -1,
      -1,   148,    -1,    -1,    -1,    -1,   148,    -1,    -1,    32,
      33,    34,    35,    36,    37,    38,    39,    40,    41,    42,
      43,    44,    45,    46,    47,    48,    49,    50,    51,    52,
      53,    54,    55,    -1,    -1,    -1,    -1,    78,    79,    -1,
      -1,    -1,    -1,    84,    -1,    -1,    -1,    -1,    -1,    -1,
      73,    74,    93,    94,    95,    96,    97,    -1,    99,   100,
     101,    -1,    -1,   104,    -1,    -1,    -1,   108,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,   118,    -1,    -1,
      -1,    -1,    -1,    -1,   125,   126,    -1,   128,    78,    79,
      -1,   132,   133,    -1,    84,    -1,    -1,    -1,    -1,    -1,
     141,   142,   143,    93,    94,    95,    96,    97,    -1,    99,
     100,   101,    -1,    -1,   104,    -1,    -1,    -1,   108,    -1,
      -1,    -1,    -1,    -1,    78,    79,    -1,    -1,   118,    -1,
      84,    -1,    -1,    -1,    -1,   125,   126,    -1,   128,    93,
      94,    95,    96,    97,    -1,    99,   100,   101,    -1,    -1,
     104,   141,   142,   143,   108,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,   118,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    78,    79,    -1,   132,   133,
      -1,    84,    -1,    -1,    -1,    -1,    -1,   141,   142,   143,
      93,    94,    95,    96,    97,    -1,    99,   100,   101,    -1,
      -1,   104,    -1,    -1,    -1,   108,    -1,    -1,    -1,    -1,
      -1,    78,    79,    -1,    -1,   118,    -1,    84,    -1,    -1,
      -1,    -1,   125,   126,    -1,   128,    93,    94,    95,    96,
      97,    -1,    99,   100,   101,    -1,    -1,   104,    78,    79,
     143,   108,    -1,    -1,    84,    -1,    -1,    -1,    -1,    -1,
      -1,   118,    -1,    93,    94,    95,    96,    97,    -1,    99,
     100,   101,    -1,    -1,   104,    -1,    -1,    -1,   108,    93,
      94,    95,    96,    97,    -1,    99,   143,    -1,   118,    -1,
      -1,    -1,    -1,    -1,   108,   125,   126,    -1,   128,    -1,
      -1,    -1,    93,    94,    -1,    96,    97,    -1,    99,    -1,
      -1,   125,   126,   104,   128,    -1,    -1,   108,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,   141,   142,   143,
       7,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,   132,   133,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
     141,   142,   143,     7,    -1,    32,    33,    34,    35,    36,
      37,    38,    39,    40,    41,    42,    43,    44,    45,    46,
      47,    48,    49,    50,    51,    52,    53,    54,    55,    56,
       7,    -1,    -1,    37,    38,    39,    40,    41,    42,    43,
      44,    45,    46,    47,    48,    -1,    50,    51,    52,    53,
      54,    55,     7,    -1,    -1,    32,    33,    34,    35,    36,
      37,    38,    39,    40,    41,    42,    43,    44,    45,    46,
      47,    48,    49,    50,    51,    52,    53,    54,    55,    -1,
      -1,    -1,    -1,    38,    39,    40,    41,    42,    43,    44,
      45,    -1,    -1,    48,    -1,    50,    51,    52,    53,    54,
      55,   133,    -1,    -1,    -1,    -1,    -1,   139,    -1,   141,
      -1,   143,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,   153,    -1,   155,    -1,   157,    -1,    -1,    -1,    -1,
      -1,   163,    -1,   165,    -1,   167,    -1,   169,    -1,   171,
      -1,   173,    -1,   175,    -1,   177,    -1,    -1,    -1,   181
};

  /* YYSTOS[STATE-NUM] -- The (internal number of the) accessing
     symbol of state STATE-NUM.  */
static const yytype_uint16 yystos[] =
{
       0,     3,     4,     5,     6,     7,    32,    33,    34,    35,
      36,    37,    38,    39,    40,    41,    42,    43,    44,    45,
      46,    47,    48,    49,    50,    51,    52,    53,    54,    55,
      73,    74,   153,   172,   181,   198,   222,   223,   227,   228,
     229,   230,   236,   239,   240,   241,   242,   243,   252,   270,
     271,   272,   273,   276,   328,   329,   330,   364,   365,   465,
     468,   505,   507,     6,     8,     9,    11,    12,    31,    69,
      70,    71,   172,   180,   181,   182,   183,   184,   185,   200,
     201,   202,   204,   205,   206,   207,   208,   209,   210,   211,
     212,   213,   214,   215,   216,   217,   218,   220,     6,    57,
      58,    59,    61,    62,    63,    64,    65,    66,    67,    68,
      73,   152,   153,   177,   195,   220,   222,   223,   258,   260,
     261,   263,   264,   265,   266,   267,   268,   269,   283,   284,
     286,   287,   294,   295,   302,   303,   309,   310,   315,   316,
     333,   334,   337,   338,   341,   342,   351,   353,   357,   358,
     367,   368,   374,   375,   380,   381,   384,   385,   388,   389,
     392,   393,   396,   397,   400,   401,   404,   405,   408,   409,
     412,   413,   416,   417,   420,   421,   424,   425,   428,   429,
     435,   436,   439,   440,   443,   444,   445,   446,   448,   449,
     450,   451,   452,   453,   454,   457,   460,   461,   462,   464,
     497,   498,   499,   504,   505,   513,   514,   270,     6,   177,
     129,   466,   154,   241,   239,   243,   244,     0,   195,   224,
     225,   241,   223,   223,     6,   177,   252,   223,   223,   275,
     278,   172,   174,   242,   271,    73,   223,   272,   281,   330,
     222,   272,   280,   282,   223,   241,   273,   172,   172,   204,
     204,   172,   204,   172,   172,   172,   220,   228,   233,   239,
     249,     9,    10,    11,    12,   172,   174,   176,    21,    22,
      23,    24,    25,    26,    27,    28,    29,    30,   194,   219,
     204,   206,   181,   186,   187,   182,   183,    13,    14,    15,
      16,   188,   189,    17,    18,   180,   190,   191,    19,    20,
     192,   179,   193,   217,   221,   193,   172,   172,   172,    73,
     153,   258,   172,     6,   195,   195,   195,   220,    75,    76,
      78,    87,    88,    89,    90,    91,    92,   103,   105,   107,
     111,   121,   130,   139,   140,   148,   150,    75,    76,   103,
     148,   463,   105,   158,   163,   178,   262,   195,   241,   264,
     258,   285,   268,   177,   306,   285,   268,   268,   268,   285,
     352,   285,   268,   268,   268,   285,   285,   268,   268,   268,
     268,   268,   268,   268,   268,   285,   268,   306,   285,   285,
     285,   265,   285,     6,   517,   177,     6,   199,   237,   238,
      99,   121,   130,   172,   508,   173,   239,   243,   179,   195,
     194,   274,   277,   177,   178,   231,   232,   233,   177,   261,
     222,   279,     6,   173,   195,   223,   245,   246,   247,   248,
      34,   175,   181,   218,   244,   129,   241,    73,   280,   366,
     241,   506,   173,   203,   218,   249,   249,   218,   249,   249,
     173,   233,   172,   174,   243,   250,   251,   233,   173,     6,
     252,   173,   203,   220,     6,   252,   218,   206,   206,   206,
     207,   207,   208,   208,   209,   209,   209,   209,   210,   210,
     211,   212,   213,   214,   215,   220,   218,   258,   193,    73,
     258,   259,   284,   220,   220,   220,    62,   195,   220,   222,
     195,   195,    76,   103,   288,   304,   196,   311,   196,   172,
     196,   447,   196,   112,   113,   114,   115,   455,   172,   196,
     458,   121,   296,   430,   196,   196,   317,   115,   131,   139,
     354,   140,   369,    75,   121,   376,   196,   463,   196,   515,
     196,   500,   263,    73,   285,   307,   308,   285,   172,   195,
     237,   194,   178,   179,   172,   331,   196,     6,   496,   509,
     225,   226,   261,   279,   231,   178,   232,   193,   195,   234,
     235,   241,   231,   222,   261,   173,   246,   172,   241,   243,
     250,   173,   179,   195,   173,   179,   218,   244,   175,   175,
      34,   175,   181,   218,   138,   261,   173,   179,   173,   173,
     179,   179,   179,   173,   245,   246,   250,   175,   181,   218,
     251,   172,   174,   177,   206,   173,   175,   193,   259,   173,
     173,   173,   172,   195,   220,   195,   195,   220,   441,   121,
     437,    84,    93,    94,    96,    97,    99,   100,   101,   104,
     118,   179,   196,   289,   290,   474,   475,   477,   481,   483,
     485,   495,    77,    95,   179,   196,   305,   475,   477,   479,
     483,    77,   102,   179,   196,   312,   313,   475,   477,     6,
     196,   149,   456,   459,   196,   335,    77,    78,    79,   108,
     179,   196,   297,   298,   475,   477,   479,   483,   487,   106,
     109,   110,   144,   179,   196,   431,   432,   474,   475,   477,
     481,   485,   125,   126,   128,   179,   196,   318,   319,   323,
     325,   475,   479,   483,   487,   132,   135,   136,   345,   359,
     360,   361,   485,   343,   140,   394,   133,   179,   196,   345,
     347,   355,   356,   485,    75,   121,   398,   141,   142,   179,
     196,   370,   371,   474,   475,   477,   481,   483,   103,   382,
     143,   179,   196,   377,   378,   475,   477,   487,   179,   196,
     485,   106,   160,   161,   162,   171,   179,   196,   516,   501,
     178,    85,    73,   178,   308,   285,   173,   203,   178,   179,
     221,   178,   238,     6,    19,    20,   116,   117,   180,   181,
     182,   183,   190,   191,   471,   122,   123,   124,   127,   179,
     196,   320,   321,   323,   325,   332,   173,   179,    99,   155,
     156,   157,   179,   196,   510,   177,   218,   253,   261,   178,
     221,   179,   195,   193,   178,   173,   179,    56,   247,   173,
     246,     6,   175,   218,   218,   175,   175,   129,   218,   249,
       6,   249,   173,   173,   175,   175,   173,   245,   175,   181,
     218,   174,   176,   253,   254,   255,   256,   257,   217,   258,
     258,   258,   220,   173,   220,   195,   195,   220,   173,   220,
     195,   179,   196,   290,   442,   474,   475,   477,   479,   481,
     483,   339,   179,   196,   290,   298,   438,   474,   475,   477,
     479,   481,   483,   293,   476,   478,   482,   172,   172,   292,
     172,   172,   172,   289,   480,   305,   314,   312,   173,   196,
       6,   489,   179,   196,   297,   319,   336,   172,   172,   297,
     172,   172,   431,   324,   326,   172,   318,   172,   362,   363,
     179,   196,   360,   179,   196,   344,   345,   347,   485,    75,
     121,   406,   179,   196,   355,   370,   395,   172,   355,   103,
     402,   179,   196,   370,   378,   399,   487,   172,   172,   370,
     121,   386,   179,   196,   318,   378,   383,   477,   172,   377,
     485,   196,   172,   172,   516,   106,   164,   165,   166,   171,
     179,   196,   502,   196,   285,   173,   178,   193,   322,   172,
     332,   467,     6,   172,   172,   172,   172,   510,   254,   235,
     221,   173,   175,   175,   130,   173,   173,   173,   173,   175,
     175,   221,     6,   252,   178,   179,   253,   194,   257,    60,
     173,   258,   173,   173,   220,   173,   220,   195,   258,   173,
     173,   220,   442,   179,   196,   319,   340,   438,   438,   172,
     172,   172,   172,    84,    96,    98,   471,   172,   291,   486,
      88,   119,   120,   172,   172,   173,   179,   336,     1,    80,
      81,    82,    83,    84,    86,   301,   220,   433,   145,   146,
     147,   434,   172,   172,   220,   346,   172,   172,   360,   344,
     103,   410,   179,   196,   355,   399,   407,   395,   134,   135,
     136,   137,   349,   350,   121,   414,   179,   196,   371,   383,
     403,   474,   481,   399,   372,   373,   390,   179,   196,   378,
     387,   438,   383,    80,   196,   181,   218,   218,   172,   172,
     172,   502,   228,   472,   172,   220,   196,   471,     6,   511,
     512,   511,   511,   178,   179,   196,   175,   178,   253,   255,
     258,   195,   258,   258,   173,   258,   173,   173,   220,   258,
     258,   173,   340,   489,   489,   489,   489,   173,   173,   173,
     484,   489,   220,   220,   173,   173,   173,   489,   489,     6,
     179,   173,   179,   173,   220,   193,   489,   489,   173,   220,
       6,   488,   490,   490,   121,   418,   179,   196,   355,   403,
     411,   407,   490,   193,   422,   179,   196,   371,   387,   415,
     403,   220,   220,   179,   196,   340,   378,   391,   387,   173,
     179,   173,   173,   173,   218,   218,   167,   168,   503,   179,
     193,   489,   173,   193,   174,   173,   179,   173,   173,   178,
     253,   258,   258,   258,   173,   258,   173,   173,   173,   173,
     193,   173,   173,   173,   173,   173,   300,   299,   173,   490,
     193,   327,   327,   173,   174,   491,   173,   179,   173,   426,
     179,   196,   356,   415,   419,   411,   173,   348,   179,   196,
     371,   391,   423,   415,   173,   173,   391,   379,   173,   173,
     179,   173,   228,   469,   173,   511,   192,   218,   512,   258,
     489,   220,   220,   173,   220,   173,   173,   493,   174,     6,
     488,   179,   196,   356,   423,   427,   419,   490,   423,   220,
     169,   170,   220,   173,     6,   175,   173,   173,   173,   220,
     494,   492,   427,   173,   173,   173,   175,   193,   175,   494,
     470,   220,   175,   151,   473,   172,   196,     6,   172,   194,
     203,   217,   173,   173,   173
};

  /* YYR1[YYN] -- Symbol number of symbol that rule YYN derives.  */
static const yytype_uint16 yyr1[] =
{
       0,   197,   198,   198,   198,   198,   199,   200,   200,   201,
     201,   201,   201,   202,   202,   202,   202,   202,   202,   202,
     202,   202,   202,   202,   202,   202,   202,   203,   203,   204,
     204,   204,   204,   204,   204,   204,   204,   204,   205,   205,
     205,   205,   205,   205,   206,   206,   207,   207,   207,   207,
     208,   208,   208,   209,   209,   209,   210,   210,   210,   210,
     210,   211,   211,   211,   212,   212,   213,   213,   214,   214,
     215,   215,   216,   216,   217,   217,   218,   218,   219,   219,
     219,   219,   219,   219,   219,   219,   219,   219,   219,   220,
     220,   221,   222,   222,   222,   222,   222,   222,   223,   223,
     223,   223,   223,   223,   223,   223,   224,   224,   225,   226,
     225,   227,   227,   227,   227,   227,   228,   228,   228,   228,
     228,   228,   228,   228,   228,   228,   228,   228,   228,   228,
     228,   229,   229,   229,   229,   229,   229,   230,   230,   231,
     231,   232,   232,   233,   233,   233,   233,   234,   234,   235,
     235,   235,   236,   236,   236,   236,   236,   237,   237,   238,
     238,   239,   239,   239,   240,   241,   241,   242,   242,   242,
     242,   242,   242,   242,   242,   242,   242,   242,   242,   242,
     242,   242,   242,   242,   242,   243,   243,   243,   243,   244,
     244,   245,   245,   246,   246,   247,   247,   247,   248,   248,
     249,   249,   250,   250,   250,   251,   251,   251,   251,   251,
     251,   251,   251,   251,   251,   251,   252,   253,   253,   253,
     254,   254,   254,   254,   255,   256,   256,   257,   257,   257,
     258,   258,   258,   258,   258,   258,   258,   258,   259,   259,
     260,   260,   260,   261,   262,   261,   263,   263,   264,   264,
     264,   264,   265,   265,   266,   266,   266,   267,   267,   267,
     268,   268,   268,   268,   268,   268,   268,   268,   268,   268,
     268,   268,   269,   269,   269,   269,   269,   270,   270,   271,
     271,   271,   272,   272,   274,   273,   275,   273,   277,   276,
     278,   276,   279,   279,   280,   280,   281,   282,   282,   283,
     283,   283,   283,   283,   283,   283,   283,   283,   283,   283,
     283,   283,   283,   283,   283,   283,   283,   283,   283,   283,
     283,   283,   283,   283,   283,   283,   283,   283,   283,   283,
     283,   284,   284,   284,   284,   284,   284,   285,   286,   287,
     288,   288,   288,   289,   289,   289,   289,   289,   289,   290,
     291,   290,   292,   290,   290,   293,   290,   294,   295,   296,
     296,   296,   297,   297,   297,   297,   297,   297,   298,   298,
     299,   298,   300,   298,   298,   301,   301,   301,   301,   301,
     301,   302,   303,   304,   304,   304,   305,   305,   305,   305,
     305,   306,   307,   307,   307,   308,   309,   310,   311,   311,
     311,   312,   312,   312,   312,   314,   313,   315,   316,   317,
     317,   317,   318,   318,   318,   318,   318,   319,   319,   319,
     320,   320,   322,   321,   324,   323,   326,   325,   327,   327,
     328,   329,   329,   330,   331,   331,   331,   332,   332,   332,
     332,   332,   333,   334,   335,   335,   335,   336,   336,   337,
     338,   339,   339,   339,   340,   340,   341,   342,   343,   343,
     343,   344,   344,   344,   346,   345,   348,   347,   349,   347,
     350,   350,   350,   350,   352,   351,   353,   354,   354,   354,
     355,   355,   356,   356,   357,   358,   359,   359,   359,   360,
     360,   360,   362,   361,   363,   361,   364,   365,   366,   367,
     368,   369,   369,   369,   370,   370,   370,   370,   370,   370,
     372,   371,   373,   371,   374,   375,   376,   376,   376,   377,
     377,   377,   377,   378,   379,   378,   380,   381,   382,   382,
     382,   383,   383,   383,   384,   385,   386,   386,   386,   387,
     387,   388,   389,   390,   390,   390,   391,   391,   392,   393,
     394,   394,   394,   395,   395,   396,   397,   398,   398,   398,
     399,   399,   399,   400,   401,   402,   402,   402,   403,   403,
     403,   403,   404,   405,   406,   406,   406,   407,   407,   408,
     409,   410,   410,   410,   411,   411,   412,   413,   414,   414,
     414,   415,   415,   416,   417,   418,   418,   418,   419,   419,
     420,   421,   422,   422,   422,   423,   423,   424,   425,   426,
     426,   426,   427,   427,   428,   429,   430,   430,   430,   431,
     431,   431,   431,   431,   432,   433,   432,   432,   432,   432,
     434,   434,   434,   435,   436,   437,   437,   437,   438,   438,
     438,   438,   438,   438,   438,   438,   439,   440,   441,   441,
     441,   442,   442,   442,   442,   442,   442,   442,   443,   444,
     445,   446,   446,   447,   448,   449,   450,   451,   452,   453,
     454,   455,   455,   455,   455,   455,   456,   456,   457,   457,
     459,   458,   460,   461,   462,   462,   462,   463,   463,   463,
     463,   464,   466,   467,   465,   469,   470,   468,   471,   471,
     471,   471,   471,   471,   471,   471,   471,   471,   471,   472,
     472,   473,   473,   473,   474,   474,   474,   476,   475,   478,
     477,   480,   479,   482,   481,   484,   483,   486,   485,   487,
     488,   489,   489,   490,   490,   490,   490,   492,   491,   493,
     491,   494,   494,   495,   495,   495,   496,   496,   497,   497,
     498,   500,   499,   501,   501,   501,   502,   502,   502,   502,
     502,   503,   503,   503,   503,   504,   504,   506,   505,   505,
     508,   507,   509,   509,   509,   510,   510,   510,   510,   511,
     511,   512,   512,   512,   513,   514,   515,   515,   515,   516,
     516,   516,   516,   516,   516,   517,   517
};

  /* YYR2[YYN] -- Number of symbols on the right hand side of rule YYN.  */
static const yytype_uint8 yyr2[] =
{
       0,     2,     1,     2,     2,     2,     1,     1,     2,     1,
       1,     1,     3,     1,     4,     3,     4,     3,     4,     3,
       3,     3,     3,     2,     2,     6,     7,     1,     3,     1,
       2,     2,     2,     2,     4,     6,     6,     6,     1,     1,
       1,     1,     1,     1,     1,     4,     1,     3,     3,     3,
       1,     3,     3,     1,     3,     3,     1,     3,     3,     3,
       3,     1,     3,     3,     1,     3,     1,     3,     1,     3,
       1,     3,     1,     3,     1,     5,     1,     3,     1,     1,
       1,     1,     1,     1,     1,     1,     1,     1,     1,     1,
       3,     1,     2,     3,     1,     1,     1,     1,     1,     2,
       1,     2,     1,     2,     1,     2,     1,     3,     1,     0,
       4,     1,     1,     1,     1,     1,     1,     1,     1,     1,
       1,     1,     1,     1,     1,     1,     1,     1,     1,     1,
       1,     4,     3,     5,     5,     2,     2,     1,     1,     1,
       2,     3,     2,     1,     2,     1,     2,     1,     3,     1,
       3,     2,     4,     5,     5,     6,     2,     1,     3,     1,
       3,     1,     1,     1,     1,     1,     2,     1,     3,     3,
       4,     4,     5,     5,     6,     6,     4,     5,     4,     3,
       4,     6,     5,     5,     4,     1,     2,     2,     3,     1,
       2,     1,     3,     1,     3,     2,     1,     2,     1,     3,
       1,     2,     1,     1,     2,     3,     2,     3,     3,     4,
       3,     4,     2,     3,     3,     4,     1,     1,     3,     4,
       1,     2,     3,     4,     2,     1,     2,     3,     2,     2,
       1,     1,     1,     1,     1,     1,     1,     1,     1,     1,
       3,     4,     3,     2,     0,     4,     1,     2,     1,     1,
       1,     1,     1,     2,     5,     7,     5,     5,     7,     1,
       6,     7,     7,     7,     8,     8,     8,     9,     6,     7,
       7,     8,     3,     2,     2,     2,     3,     1,     2,     1,
       1,     1,     1,     1,     0,     4,     0,     3,     0,     5,
       0,     4,     1,     2,     1,     1,     1,     1,     2,     1,
       1,     1,     1,     1,     1,     1,     1,     1,     1,     1,
       1,     1,     1,     1,     1,     1,     1,     1,     1,     1,
       1,     1,     1,     1,     1,     1,     1,     1,     1,     1,
       1,     1,     1,     1,     1,     1,     1,     1,     2,     4,
       0,     2,     3,     1,     1,     1,     1,     1,     1,     1,
       0,     5,     0,     5,     1,     0,     5,     2,     4,     0,
       2,     3,     1,     1,     1,     1,     1,     1,     1,     4,
       0,     7,     0,     7,     1,     1,     1,     1,     1,     1,
       1,     2,     4,     0,     2,     3,     1,     1,     1,     1,
       1,     3,     1,     2,     3,     3,     2,     4,     0,     2,
       3,     1,     1,     1,     1,     0,     5,     2,     4,     0,
       2,     3,     1,     1,     1,     1,     1,     4,     1,     1,
       1,     1,     0,     5,     0,     6,     0,     6,     0,     2,
       2,     1,     2,     5,     0,     2,     3,     4,     1,     1,
       1,     1,     2,     5,     0,     2,     3,     1,     1,     2,
       6,     0,     2,     3,     1,     1,     2,     5,     0,     2,
       3,     1,     1,     1,     0,     5,     0,     7,     0,     5,
       1,     1,     1,     1,     0,     3,     4,     0,     2,     3,
       1,     1,     1,     1,     1,     5,     1,     2,     3,     1,
       1,     1,     0,     5,     0,     5,     3,     4,     5,     2,
       4,     0,     2,     3,     1,     1,     1,     1,     1,     1,
       0,     5,     0,     5,     2,     4,     0,     2,     3,     1,
       1,     1,     1,     4,     0,     7,     2,     5,     0,     2,
       3,     1,     1,     1,     2,     6,     0,     2,     3,     1,
       1,     2,     7,     0,     2,     3,     1,     1,     2,     5,
       0,     2,     3,     1,     1,     2,     5,     0,     2,     3,
       1,     1,     1,     2,     6,     0,     2,     3,     1,     1,
       1,     1,     2,     6,     0,     2,     3,     1,     1,     2,
       7,     0,     2,     3,     1,     1,     2,     7,     0,     2,
       3,     1,     1,     2,     8,     0,     2,     3,     1,     1,
       2,     8,     0,     2,     3,     1,     1,     2,     9,     0,
       2,     3,     1,     1,     2,     4,     0,     2,     3,     1,
       1,     1,     1,     1,     1,     0,     5,     1,     1,     6,
       1,     1,     1,     2,     5,     0,     2,     3,     1,     1,
       1,     1,     1,     1,     1,     1,     2,     5,     0,     2,
       3,     1,     1,     1,     1,     1,     1,     1,     2,     3,
       2,     3,     4,     3,     3,     3,     2,     3,     3,     2,
       5,     0,     1,     1,     1,     1,     0,     1,     3,     4,
       0,     4,     2,     3,     4,     5,     6,     1,     1,     1,
       1,     3,     0,     0,     7,     0,     0,    14,     1,     1,
       1,     1,     1,     1,     1,     1,     1,     1,     1,     1,
       3,     0,     6,     7,     4,     4,     4,     0,     5,     0,
       5,     0,     5,     0,     5,     0,     7,     0,     5,     4,
       2,     1,     3,     1,     1,     3,     3,     0,     5,     0,
       4,     3,     1,     4,     4,     4,     1,     3,     1,     1,
       3,     0,     5,     0,     2,     3,     4,     4,     4,     1,
       1,     1,     1,     3,     3,     1,     1,     0,     4,     2,
       0,     5,     0,     2,     3,     4,     4,     4,     6,     1,
       3,     1,     5,     4,     3,     4,     0,     2,     3,     4,
       4,     4,     1,     1,     1,     3,     4
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
#line 470 "parser.y" /* yacc.c:1646  */
    { /* to avoid warnings */ }
#line 3468 "parser.c" /* yacc.c:1646  */
    break;

  case 3:
#line 471 "parser.y" /* yacc.c:1646  */
    { pastree_expr = (yyvsp[0].expr); }
#line 3474 "parser.c" /* yacc.c:1646  */
    break;

  case 4:
#line 472 "parser.y" /* yacc.c:1646  */
    { pastree_stmt = (yyvsp[0].stmt); }
#line 3480 "parser.c" /* yacc.c:1646  */
    break;

  case 5:
#line 473 "parser.y" /* yacc.c:1646  */
    { pastree_stmt = (yyvsp[0].stmt); }
#line 3486 "parser.c" /* yacc.c:1646  */
    break;

  case 6:
#line 491 "parser.y" /* yacc.c:1646  */
    {
      symbol s = Symbol((yyvsp[0].name));
      if (checkDecls)
      {
        if ( symtab_get(stab, s, LABELNAME) )  /* NOT a type name */
          parse_error(-1, "enum symbol '%s' is already in use.", (yyvsp[0].name));
        symtab_put(stab, s, LABELNAME);
      }
      (yyval.symb) = s;
    }
#line 3501 "parser.c" /* yacc.c:1646  */
    break;

  case 7:
#line 512 "parser.y" /* yacc.c:1646  */
    {
      (yyval.string) = strdup((yyvsp[0].name));
    }
#line 3509 "parser.c" /* yacc.c:1646  */
    break;

  case 8:
#line 516 "parser.y" /* yacc.c:1646  */
    {
      /* Or we could leave it as is (as a SpaceList) */
      if (((yyvsp[-1].string) = realloc((yyvsp[-1].string), strlen((yyvsp[-1].string)) + strlen((yyvsp[0].name)))) == NULL)
        parse_error(-1, "string out of memory\n");
      strcpy(((yyvsp[-1].string))+(strlen((yyvsp[-1].string))-1),((yyvsp[0].name))+1);  /* Catenate on the '"' */
      (yyval.string) = (yyvsp[-1].string);
    }
#line 3521 "parser.c" /* yacc.c:1646  */
    break;

  case 9:
#line 539 "parser.y" /* yacc.c:1646  */
    {
      symbol  id = Symbol((yyvsp[0].name));
      stentry e;
      bool    chflag = false;

      if (checkDecls)
      {
        check_uknown_var((yyvsp[0].name));
        /* The parser constructs the original AST; this is the only
         * place it doesn't (actually there is one more place, when replacing
         * the "main" function): threadprivate variables are replaced on the
         * fly by pointers. This makes the job of later stages much smoother,
         * but the produced AST is semantically incorrect.
         */
        if ((e = symtab_get(stab, id, IDNAME)) != NULL) /* could be enum name */
          if (istp(e) && threadmode)
            chflag = true;
      }
      (yyval.expr) = chflag ? Parenthesis(UnaryOperator(UOP_star, Identifier(id)))
                  : Identifier(id);
    }
#line 3547 "parser.c" /* yacc.c:1646  */
    break;

  case 10:
#line 561 "parser.y" /* yacc.c:1646  */
    {
      (yyval.expr) = Constant( strdup((yyvsp[0].name)) );
    }
#line 3555 "parser.c" /* yacc.c:1646  */
    break;

  case 11:
#line 565 "parser.y" /* yacc.c:1646  */
    {
      (yyval.expr) = String((yyvsp[0].string));
    }
#line 3563 "parser.c" /* yacc.c:1646  */
    break;

  case 12:
#line 569 "parser.y" /* yacc.c:1646  */
    {
      (yyval.expr) = Parenthesis((yyvsp[-1].expr));
    }
#line 3571 "parser.c" /* yacc.c:1646  */
    break;

  case 13:
#line 577 "parser.y" /* yacc.c:1646  */
    {
      (yyval.expr) = (yyvsp[0].expr);
    }
#line 3579 "parser.c" /* yacc.c:1646  */
    break;

  case 14:
#line 581 "parser.y" /* yacc.c:1646  */
    {
      (yyval.expr) = ArrayIndex((yyvsp[-3].expr), (yyvsp[-1].expr));
    }
#line 3587 "parser.c" /* yacc.c:1646  */
    break;

  case 15:
#line 591 "parser.y" /* yacc.c:1646  */
    {
      /* Catch calls to "main()" (unlikely but possible) */
      // NOTE(luobin): Catch calls to DF_Source_Stop(), too.
      do
      {
      if(strcmp((yyvsp[-2].name), "DF_Run") == 0)
      {
        (yyval.expr) = FunctionCall(IdentName((yyvsp[-2].name)), 
                        CommaList(UnaryOperator(UOP_addr, 
                              IdentName("DF_TFL_TABLE")), 
                                      IdentName("DF_COUNT") ) );
                                      break;
      }

      if(strcmp((yyvsp[-2].name), "DF_Source_Stop") == 0)
      {
        (yyval.expr) = FunctionCall(IdentName((yyvsp[-2].name)), 
                        CommaList(UnaryOperator(UOP_addr, 
                              IdentName("DF_TFL_TABLE")), 
                                      IdentName("DF_FN_item_index") ) );
                                      break;
      }

      (yyval.expr) = strcmp((yyvsp[-2].name), "main") ?
              FunctionCall(IdentName((yyvsp[-2].name)), NULL) :
              FunctionCall(IdentName(MAIN_NEWNAME), NULL);
      }
      while(0);

    }
#line 3622 "parser.c" /* yacc.c:1646  */
    break;

  case 16:
#line 623 "parser.y" /* yacc.c:1646  */
    {
      /* Catch calls to "main()" (unlikely but possible) */
      (yyval.expr) = strcmp((yyvsp[-3].name), "main") ?
             FunctionCall(IdentName((yyvsp[-3].name)), (yyvsp[-1].expr)) :
             FunctionCall(IdentName(MAIN_NEWNAME), (yyvsp[-1].expr));
    }
#line 3633 "parser.c" /* yacc.c:1646  */
    break;

  case 17:
#line 630 "parser.y" /* yacc.c:1646  */
    {
      (yyval.expr) = FunctionCall((yyvsp[-2].expr), NULL);
    }
#line 3641 "parser.c" /* yacc.c:1646  */
    break;

  case 18:
#line 634 "parser.y" /* yacc.c:1646  */
    {
      (yyval.expr) = FunctionCall((yyvsp[-3].expr), (yyvsp[-1].expr));
    }
#line 3649 "parser.c" /* yacc.c:1646  */
    break;

  case 19:
#line 638 "parser.y" /* yacc.c:1646  */
    {
      (yyval.expr) = DotField((yyvsp[-2].expr), Symbol((yyvsp[0].name)));
    }
#line 3657 "parser.c" /* yacc.c:1646  */
    break;

  case 20:
#line 642 "parser.y" /* yacc.c:1646  */
    {
      (yyval.expr) = PtrField((yyvsp[-2].expr), Symbol((yyvsp[0].name)));
    }
#line 3665 "parser.c" /* yacc.c:1646  */
    break;

  case 21:
#line 651 "parser.y" /* yacc.c:1646  */
    {
      (yyval.expr) = DotField((yyvsp[-2].expr), (yyvsp[0].symb));
    }
#line 3673 "parser.c" /* yacc.c:1646  */
    break;

  case 22:
#line 655 "parser.y" /* yacc.c:1646  */
    {
      (yyval.expr) = PtrField((yyvsp[-2].expr), (yyvsp[0].symb));
    }
#line 3681 "parser.c" /* yacc.c:1646  */
    break;

  case 23:
#line 659 "parser.y" /* yacc.c:1646  */
    {
      (yyval.expr) = PostOperator((yyvsp[-1].expr), UOP_inc);
    }
#line 3689 "parser.c" /* yacc.c:1646  */
    break;

  case 24:
#line 663 "parser.y" /* yacc.c:1646  */
    {
      (yyval.expr) = PostOperator((yyvsp[-1].expr), UOP_dec);
    }
#line 3697 "parser.c" /* yacc.c:1646  */
    break;

  case 25:
#line 667 "parser.y" /* yacc.c:1646  */
    {
      (yyval.expr) = CastedExpr((yyvsp[-4].decl), BracedInitializer((yyvsp[-1].expr)));
    }
#line 3705 "parser.c" /* yacc.c:1646  */
    break;

  case 26:
#line 671 "parser.y" /* yacc.c:1646  */
    {
      (yyval.expr) = CastedExpr((yyvsp[-5].decl), BracedInitializer((yyvsp[-2].expr)));
    }
#line 3713 "parser.c" /* yacc.c:1646  */
    break;

  case 27:
#line 679 "parser.y" /* yacc.c:1646  */
    {
      (yyval.expr) = (yyvsp[0].expr);
    }
#line 3721 "parser.c" /* yacc.c:1646  */
    break;

  case 28:
#line 683 "parser.y" /* yacc.c:1646  */
    {
      (yyval.expr) = CommaList((yyvsp[-2].expr), (yyvsp[0].expr));
    }
#line 3729 "parser.c" /* yacc.c:1646  */
    break;

  case 29:
#line 691 "parser.y" /* yacc.c:1646  */
    {
      (yyval.expr) = (yyvsp[0].expr);
    }
#line 3737 "parser.c" /* yacc.c:1646  */
    break;

  case 30:
#line 695 "parser.y" /* yacc.c:1646  */
    {
      (yyval.expr) = PreOperator((yyvsp[0].expr), UOP_inc);
    }
#line 3745 "parser.c" /* yacc.c:1646  */
    break;

  case 31:
#line 699 "parser.y" /* yacc.c:1646  */
    {
      (yyval.expr) = PreOperator((yyvsp[0].expr), UOP_dec);
    }
#line 3753 "parser.c" /* yacc.c:1646  */
    break;

  case 32:
#line 703 "parser.y" /* yacc.c:1646  */
    {
      if ((yyvsp[-1].type) == -1)
        (yyval.expr) = (yyvsp[0].expr);                    /* simplify */
      else
        (yyval.expr) = UnaryOperator((yyvsp[-1].type), (yyvsp[0].expr));
    }
#line 3764 "parser.c" /* yacc.c:1646  */
    break;

  case 33:
#line 710 "parser.y" /* yacc.c:1646  */
    {
      (yyval.expr) = Sizeof((yyvsp[0].expr));
    }
#line 3772 "parser.c" /* yacc.c:1646  */
    break;

  case 34:
#line 714 "parser.y" /* yacc.c:1646  */
    {
      (yyval.expr) = Sizeoftype((yyvsp[-1].decl));
    }
#line 3780 "parser.c" /* yacc.c:1646  */
    break;

  case 35:
#line 723 "parser.y" /* yacc.c:1646  */
    {
      (yyval.expr) = FunctionCall(IdentName("__builtin_va_arg"),
                        CommaList((yyvsp[-3].expr), TypeTrick((yyvsp[-1].decl))));
    }
#line 3789 "parser.c" /* yacc.c:1646  */
    break;

  case 36:
#line 728 "parser.y" /* yacc.c:1646  */
    {
      (yyval.expr) = FunctionCall(IdentName("__builtin_offsetof"),
                        CommaList(TypeTrick((yyvsp[-3].decl)), IdentName((yyvsp[-1].name))));
    }
#line 3798 "parser.c" /* yacc.c:1646  */
    break;

  case 37:
#line 733 "parser.y" /* yacc.c:1646  */
    {
      (yyval.expr) = FunctionCall(IdentName("__builtin_types_compatible_p"),
                        CommaList(TypeTrick((yyvsp[-3].decl)), TypeTrick((yyvsp[-1].decl))));
    }
#line 3807 "parser.c" /* yacc.c:1646  */
    break;

  case 38:
#line 742 "parser.y" /* yacc.c:1646  */
    {
      (yyval.type) = UOP_addr;
    }
#line 3815 "parser.c" /* yacc.c:1646  */
    break;

  case 39:
#line 746 "parser.y" /* yacc.c:1646  */
    {
      (yyval.type) = UOP_star;
    }
#line 3823 "parser.c" /* yacc.c:1646  */
    break;

  case 40:
#line 750 "parser.y" /* yacc.c:1646  */
    {
      (yyval.type) = -1;         /* Ingore this one */
    }
#line 3831 "parser.c" /* yacc.c:1646  */
    break;

  case 41:
#line 754 "parser.y" /* yacc.c:1646  */
    {
      (yyval.type) = UOP_neg;
    }
#line 3839 "parser.c" /* yacc.c:1646  */
    break;

  case 42:
#line 758 "parser.y" /* yacc.c:1646  */
    {
      (yyval.type) = UOP_bnot;
    }
#line 3847 "parser.c" /* yacc.c:1646  */
    break;

  case 43:
#line 762 "parser.y" /* yacc.c:1646  */
    {
      (yyval.type) = UOP_lnot;
    }
#line 3855 "parser.c" /* yacc.c:1646  */
    break;

  case 44:
#line 770 "parser.y" /* yacc.c:1646  */
    {
      (yyval.expr) = (yyvsp[0].expr);
    }
#line 3863 "parser.c" /* yacc.c:1646  */
    break;

  case 45:
#line 774 "parser.y" /* yacc.c:1646  */
    {
      (yyval.expr) = CastedExpr((yyvsp[-2].decl), (yyvsp[0].expr));
    }
#line 3871 "parser.c" /* yacc.c:1646  */
    break;

  case 46:
#line 782 "parser.y" /* yacc.c:1646  */
    {
      (yyval.expr) = (yyvsp[0].expr);
    }
#line 3879 "parser.c" /* yacc.c:1646  */
    break;

  case 47:
#line 786 "parser.y" /* yacc.c:1646  */
    {
      (yyval.expr) = BinaryOperator(BOP_mul, (yyvsp[-2].expr), (yyvsp[0].expr));
    }
#line 3887 "parser.c" /* yacc.c:1646  */
    break;

  case 48:
#line 790 "parser.y" /* yacc.c:1646  */
    {
      (yyval.expr) = BinaryOperator(BOP_div, (yyvsp[-2].expr), (yyvsp[0].expr));
    }
#line 3895 "parser.c" /* yacc.c:1646  */
    break;

  case 49:
#line 794 "parser.y" /* yacc.c:1646  */
    {
      (yyval.expr) = BinaryOperator(BOP_mod, (yyvsp[-2].expr), (yyvsp[0].expr));
    }
#line 3903 "parser.c" /* yacc.c:1646  */
    break;

  case 50:
#line 802 "parser.y" /* yacc.c:1646  */
    {
      (yyval.expr) = (yyvsp[0].expr);
    }
#line 3911 "parser.c" /* yacc.c:1646  */
    break;

  case 51:
#line 806 "parser.y" /* yacc.c:1646  */
    {
      (yyval.expr) = BinaryOperator(BOP_add, (yyvsp[-2].expr), (yyvsp[0].expr));
    }
#line 3919 "parser.c" /* yacc.c:1646  */
    break;

  case 52:
#line 810 "parser.y" /* yacc.c:1646  */
    {
      (yyval.expr) = BinaryOperator(BOP_sub, (yyvsp[-2].expr), (yyvsp[0].expr));
    }
#line 3927 "parser.c" /* yacc.c:1646  */
    break;

  case 53:
#line 818 "parser.y" /* yacc.c:1646  */
    {
      (yyval.expr) = (yyvsp[0].expr);
    }
#line 3935 "parser.c" /* yacc.c:1646  */
    break;

  case 54:
#line 822 "parser.y" /* yacc.c:1646  */
    {
      (yyval.expr) = BinaryOperator(BOP_shl, (yyvsp[-2].expr), (yyvsp[0].expr));
    }
#line 3943 "parser.c" /* yacc.c:1646  */
    break;

  case 55:
#line 826 "parser.y" /* yacc.c:1646  */
    {
      (yyval.expr) = BinaryOperator(BOP_shr, (yyvsp[-2].expr), (yyvsp[0].expr));
    }
#line 3951 "parser.c" /* yacc.c:1646  */
    break;

  case 56:
#line 834 "parser.y" /* yacc.c:1646  */
    {
      (yyval.expr) = (yyvsp[0].expr);
    }
#line 3959 "parser.c" /* yacc.c:1646  */
    break;

  case 57:
#line 838 "parser.y" /* yacc.c:1646  */
    {
      (yyval.expr) = BinaryOperator(BOP_lt, (yyvsp[-2].expr), (yyvsp[0].expr));
    }
#line 3967 "parser.c" /* yacc.c:1646  */
    break;

  case 58:
#line 842 "parser.y" /* yacc.c:1646  */
    {
      (yyval.expr) = BinaryOperator(BOP_gt, (yyvsp[-2].expr), (yyvsp[0].expr));
    }
#line 3975 "parser.c" /* yacc.c:1646  */
    break;

  case 59:
#line 846 "parser.y" /* yacc.c:1646  */
    {
      (yyval.expr) = BinaryOperator(BOP_leq, (yyvsp[-2].expr), (yyvsp[0].expr));
     }
#line 3983 "parser.c" /* yacc.c:1646  */
    break;

  case 60:
#line 850 "parser.y" /* yacc.c:1646  */
    {
      (yyval.expr) = BinaryOperator(BOP_geq, (yyvsp[-2].expr), (yyvsp[0].expr));
    }
#line 3991 "parser.c" /* yacc.c:1646  */
    break;

  case 61:
#line 858 "parser.y" /* yacc.c:1646  */
    {
      (yyval.expr) = (yyvsp[0].expr);
    }
#line 3999 "parser.c" /* yacc.c:1646  */
    break;

  case 62:
#line 862 "parser.y" /* yacc.c:1646  */
    {
      (yyval.expr) = BinaryOperator(BOP_eqeq, (yyvsp[-2].expr), (yyvsp[0].expr));
    }
#line 4007 "parser.c" /* yacc.c:1646  */
    break;

  case 63:
#line 866 "parser.y" /* yacc.c:1646  */
    {
      (yyval.expr) = BinaryOperator(BOP_neq, (yyvsp[-2].expr), (yyvsp[0].expr));
    }
#line 4015 "parser.c" /* yacc.c:1646  */
    break;

  case 64:
#line 874 "parser.y" /* yacc.c:1646  */
    {
      (yyval.expr) = (yyvsp[0].expr);
    }
#line 4023 "parser.c" /* yacc.c:1646  */
    break;

  case 65:
#line 878 "parser.y" /* yacc.c:1646  */
    {
      (yyval.expr) = BinaryOperator(BOP_band, (yyvsp[-2].expr), (yyvsp[0].expr));
    }
#line 4031 "parser.c" /* yacc.c:1646  */
    break;

  case 66:
#line 886 "parser.y" /* yacc.c:1646  */
    {
      (yyval.expr) = (yyvsp[0].expr);
    }
#line 4039 "parser.c" /* yacc.c:1646  */
    break;

  case 67:
#line 890 "parser.y" /* yacc.c:1646  */
    {
      (yyval.expr) = BinaryOperator(BOP_xor, (yyvsp[-2].expr), (yyvsp[0].expr));
    }
#line 4047 "parser.c" /* yacc.c:1646  */
    break;

  case 68:
#line 898 "parser.y" /* yacc.c:1646  */
    {
      (yyval.expr) = (yyvsp[0].expr);
    }
#line 4055 "parser.c" /* yacc.c:1646  */
    break;

  case 69:
#line 902 "parser.y" /* yacc.c:1646  */
    {
      (yyval.expr) = BinaryOperator(BOP_bor, (yyvsp[-2].expr), (yyvsp[0].expr));
    }
#line 4063 "parser.c" /* yacc.c:1646  */
    break;

  case 70:
#line 910 "parser.y" /* yacc.c:1646  */
    {
      (yyval.expr) = (yyvsp[0].expr);
    }
#line 4071 "parser.c" /* yacc.c:1646  */
    break;

  case 71:
#line 914 "parser.y" /* yacc.c:1646  */
    {
      (yyval.expr) = BinaryOperator(BOP_land, (yyvsp[-2].expr), (yyvsp[0].expr));
    }
#line 4079 "parser.c" /* yacc.c:1646  */
    break;

  case 72:
#line 922 "parser.y" /* yacc.c:1646  */
    {
      (yyval.expr) = (yyvsp[0].expr);
    }
#line 4087 "parser.c" /* yacc.c:1646  */
    break;

  case 73:
#line 926 "parser.y" /* yacc.c:1646  */
    {
      (yyval.expr) = BinaryOperator(BOP_lor, (yyvsp[-2].expr), (yyvsp[0].expr));
    }
#line 4095 "parser.c" /* yacc.c:1646  */
    break;

  case 74:
#line 934 "parser.y" /* yacc.c:1646  */
    {
      (yyval.expr) = (yyvsp[0].expr);
    }
#line 4103 "parser.c" /* yacc.c:1646  */
    break;

  case 75:
#line 938 "parser.y" /* yacc.c:1646  */
    {
      (yyval.expr) = ConditionalExpr((yyvsp[-4].expr), (yyvsp[-2].expr), (yyvsp[0].expr));
    }
#line 4111 "parser.c" /* yacc.c:1646  */
    break;

  case 76:
#line 946 "parser.y" /* yacc.c:1646  */
    {
      (yyval.expr) = (yyvsp[0].expr);
    }
#line 4119 "parser.c" /* yacc.c:1646  */
    break;

  case 77:
#line 950 "parser.y" /* yacc.c:1646  */
    {
      (yyval.expr) = Assignment((yyvsp[-2].expr), (yyvsp[-1].type), (yyvsp[0].expr));
    }
#line 4127 "parser.c" /* yacc.c:1646  */
    break;

  case 78:
#line 958 "parser.y" /* yacc.c:1646  */
    {
      (yyval.type) = ASS_eq;  /* Need fix here! */
    }
#line 4135 "parser.c" /* yacc.c:1646  */
    break;

  case 79:
#line 962 "parser.y" /* yacc.c:1646  */
    {
      (yyval.type) = ASS_mul;
    }
#line 4143 "parser.c" /* yacc.c:1646  */
    break;

  case 80:
#line 966 "parser.y" /* yacc.c:1646  */
    {
      (yyval.type) = ASS_div;
    }
#line 4151 "parser.c" /* yacc.c:1646  */
    break;

  case 81:
#line 970 "parser.y" /* yacc.c:1646  */
    {
      (yyval.type) = ASS_mod;
    }
#line 4159 "parser.c" /* yacc.c:1646  */
    break;

  case 82:
#line 974 "parser.y" /* yacc.c:1646  */
    {
      (yyval.type) = ASS_add;
    }
#line 4167 "parser.c" /* yacc.c:1646  */
    break;

  case 83:
#line 978 "parser.y" /* yacc.c:1646  */
    {
      (yyval.type) = ASS_sub;
    }
#line 4175 "parser.c" /* yacc.c:1646  */
    break;

  case 84:
#line 982 "parser.y" /* yacc.c:1646  */
    {
      (yyval.type) = ASS_shl;
    }
#line 4183 "parser.c" /* yacc.c:1646  */
    break;

  case 85:
#line 986 "parser.y" /* yacc.c:1646  */
    {
      (yyval.type) = ASS_shr;
    }
#line 4191 "parser.c" /* yacc.c:1646  */
    break;

  case 86:
#line 990 "parser.y" /* yacc.c:1646  */
    {
      (yyval.type) = ASS_and;
    }
#line 4199 "parser.c" /* yacc.c:1646  */
    break;

  case 87:
#line 994 "parser.y" /* yacc.c:1646  */
    {
      (yyval.type) = ASS_xor;
    }
#line 4207 "parser.c" /* yacc.c:1646  */
    break;

  case 88:
#line 998 "parser.y" /* yacc.c:1646  */
    {
      (yyval.type) = ASS_or;
    }
#line 4215 "parser.c" /* yacc.c:1646  */
    break;

  case 89:
#line 1006 "parser.y" /* yacc.c:1646  */
    {
      (yyval.expr) = (yyvsp[0].expr);
    }
#line 4223 "parser.c" /* yacc.c:1646  */
    break;

  case 90:
#line 1010 "parser.y" /* yacc.c:1646  */
    {
      (yyval.expr) = CommaList((yyvsp[-2].expr), (yyvsp[0].expr));
    }
#line 4231 "parser.c" /* yacc.c:1646  */
    break;

  case 91:
#line 1018 "parser.y" /* yacc.c:1646  */
    {
      (yyval.expr) = (yyvsp[0].expr);
    }
#line 4239 "parser.c" /* yacc.c:1646  */
    break;

  case 92:
#line 1032 "parser.y" /* yacc.c:1646  */
    {
      /* There is a special case which wrongly uses this rule:
       *   typedef xxx already_known_user_type.
       * In this case the already_known_user_type (T) is re-defined,
       * and because T is known, it is not considered as a declarator,
       * but a "typedef_name", and is part of the specifier.
       * We fix it here.
       */
      if (isTypedef && (yyvsp[-1].spec)->type == SPECLIST)
        (yyval.stmt) = Declaration((yyvsp[-1].spec), fix_known_typename((yyvsp[-1].spec)));
      else
        (yyval.stmt) = Declaration((yyvsp[-1].spec), NULL);
      isTypedef = 0;
    }
#line 4258 "parser.c" /* yacc.c:1646  */
    break;

  case 93:
#line 1047 "parser.y" /* yacc.c:1646  */
    {
      (yyval.stmt) = Declaration((yyvsp[-2].spec), (yyvsp[-1].decl));
      if (checkDecls) add_declaration_links((yyvsp[-2].spec), (yyvsp[-1].decl));
      isTypedef = 0;

    }
#line 4269 "parser.c" /* yacc.c:1646  */
    break;

  case 94:
#line 1054 "parser.y" /* yacc.c:1646  */
    {
      (yyval.stmt) = OmpStmt(OmpConstruct(DCTHREADPRIVATE, (yyvsp[0].odir), NULL));
    }
#line 4277 "parser.c" /* yacc.c:1646  */
    break;

  case 95:
#line 1059 "parser.y" /* yacc.c:1646  */
    {
      //$$ = OmpStmt(OmpConstruct(DCTHREADPRIVATE, $1, NULL)); TODO
    }
#line 4285 "parser.c" /* yacc.c:1646  */
    break;

  case 96:
#line 1063 "parser.y" /* yacc.c:1646  */
    {
      (yyval.stmt) = OmpStmt((yyvsp[0].ocon));
    }
#line 4293 "parser.c" /* yacc.c:1646  */
    break;

  case 97:
#line 1067 "parser.y" /* yacc.c:1646  */
    {
      //$$ = OmpStmt(OmpConstruct(DCTHREADPRIVATE, $1, NULL)); TODO
    }
#line 4301 "parser.c" /* yacc.c:1646  */
    break;

  case 98:
#line 1075 "parser.y" /* yacc.c:1646  */
    {
      (yyval.spec) = (yyvsp[0].spec);
    }
#line 4309 "parser.c" /* yacc.c:1646  */
    break;

  case 99:
#line 1079 "parser.y" /* yacc.c:1646  */
    {
      (yyval.spec) = Speclist_right((yyvsp[-1].spec), (yyvsp[0].spec));
    }
#line 4317 "parser.c" /* yacc.c:1646  */
    break;

  case 100:
#line 1083 "parser.y" /* yacc.c:1646  */
    {
      (yyval.spec) = (yyvsp[0].spec);
    }
#line 4325 "parser.c" /* yacc.c:1646  */
    break;

  case 101:
#line 1087 "parser.y" /* yacc.c:1646  */
    {
      (yyval.spec) = Speclist_right((yyvsp[-1].spec), (yyvsp[0].spec));
    }
#line 4333 "parser.c" /* yacc.c:1646  */
    break;

  case 102:
#line 1091 "parser.y" /* yacc.c:1646  */
    {
      (yyval.spec) = (yyvsp[0].spec);
    }
#line 4341 "parser.c" /* yacc.c:1646  */
    break;

  case 103:
#line 1095 "parser.y" /* yacc.c:1646  */
    {
      (yyval.spec) = Speclist_right((yyvsp[-1].spec), (yyvsp[0].spec));
    }
#line 4349 "parser.c" /* yacc.c:1646  */
    break;

  case 104:
#line 1099 "parser.y" /* yacc.c:1646  */
    {
      (yyval.spec) = (yyvsp[0].spec);
    }
#line 4357 "parser.c" /* yacc.c:1646  */
    break;

  case 105:
#line 1103 "parser.y" /* yacc.c:1646  */
    {
      (yyval.spec) = Speclist_right((yyvsp[-1].spec), (yyvsp[0].spec));
    }
#line 4365 "parser.c" /* yacc.c:1646  */
    break;

  case 106:
#line 1111 "parser.y" /* yacc.c:1646  */
    {
      (yyval.decl) = (yyvsp[0].decl);
    }
#line 4373 "parser.c" /* yacc.c:1646  */
    break;

  case 107:
#line 1115 "parser.y" /* yacc.c:1646  */
    {
      (yyval.decl) = DeclList((yyvsp[-2].decl), (yyvsp[0].decl));
    }
#line 4381 "parser.c" /* yacc.c:1646  */
    break;

  case 108:
#line 1129 "parser.y" /* yacc.c:1646  */
    {
      astdecl s = decl_getidentifier((yyvsp[0].decl));
      int     declkind = decl_getkind((yyvsp[0].decl));
      stentry e;

      if (!isTypedef && declkind == DFUNC && strcmp(s->u.id->name, "main") == 0)
        s->u.id = Symbol(MAIN_NEWNAME);       /* Catch main()'s declaration */
      if (checkDecls)
      {
        e = symtab_put(stab, s->u.id, (isTypedef) ? TYPENAME :
                                       (declkind == DFUNC) ? FUNCNAME : IDNAME);
        e->isarray = (declkind == DARRAY);
      }
      (yyval.decl) = (yyvsp[0].decl);
    }
#line 4401 "parser.c" /* yacc.c:1646  */
    break;

  case 109:
#line 1145 "parser.y" /* yacc.c:1646  */
    {
      astdecl s = decl_getidentifier((yyvsp[-1].decl));
      int     declkind = decl_getkind((yyvsp[-1].decl));
      stentry e;

      if (!isTypedef && declkind == DFUNC && strcmp(s->u.id->name, "main") == 0)
        s->u.id = Symbol(MAIN_NEWNAME);         /* Catch main()'s declaration */
      if (checkDecls)
      {
        e = symtab_put(stab, s->u.id, (isTypedef) ? TYPENAME :
                                       (declkind == DFUNC) ? FUNCNAME : IDNAME);
        e->isarray = (declkind == DARRAY);
      }
    }
#line 4420 "parser.c" /* yacc.c:1646  */
    break;

  case 110:
#line 1160 "parser.y" /* yacc.c:1646  */
    {
      (yyval.decl) = InitDecl((yyvsp[-3].decl), (yyvsp[0].expr));
    }
#line 4428 "parser.c" /* yacc.c:1646  */
    break;

  case 111:
#line 1168 "parser.y" /* yacc.c:1646  */
    {
      (yyval.spec) = StClassSpec(SPEC_typedef);    /* Just a string */
      isTypedef = 1;
    }
#line 4437 "parser.c" /* yacc.c:1646  */
    break;

  case 112:
#line 1173 "parser.y" /* yacc.c:1646  */
    {
      (yyval.spec) = StClassSpec(SPEC_extern);
    }
#line 4445 "parser.c" /* yacc.c:1646  */
    break;

  case 113:
#line 1177 "parser.y" /* yacc.c:1646  */
    {
      (yyval.spec) = StClassSpec(SPEC_static);
    }
#line 4453 "parser.c" /* yacc.c:1646  */
    break;

  case 114:
#line 1181 "parser.y" /* yacc.c:1646  */
    {
      (yyval.spec) = StClassSpec(SPEC_auto);
    }
#line 4461 "parser.c" /* yacc.c:1646  */
    break;

  case 115:
#line 1185 "parser.y" /* yacc.c:1646  */
    {
      (yyval.spec) = StClassSpec(SPEC_register);
    }
#line 4469 "parser.c" /* yacc.c:1646  */
    break;

  case 116:
#line 1193 "parser.y" /* yacc.c:1646  */
    {
      (yyval.spec) = Declspec(SPEC_void);
    }
#line 4477 "parser.c" /* yacc.c:1646  */
    break;

  case 117:
#line 1197 "parser.y" /* yacc.c:1646  */
    {
      (yyval.spec) = Declspec(SPEC_char);
    }
#line 4485 "parser.c" /* yacc.c:1646  */
    break;

  case 118:
#line 1201 "parser.y" /* yacc.c:1646  */
    {
      (yyval.spec) = Declspec(SPEC_short);
    }
#line 4493 "parser.c" /* yacc.c:1646  */
    break;

  case 119:
#line 1205 "parser.y" /* yacc.c:1646  */
    {
      (yyval.spec) = Declspec(SPEC_int);
    }
#line 4501 "parser.c" /* yacc.c:1646  */
    break;

  case 120:
#line 1209 "parser.y" /* yacc.c:1646  */
    {
      (yyval.spec) = Declspec(SPEC_long);
    }
#line 4509 "parser.c" /* yacc.c:1646  */
    break;

  case 121:
#line 1213 "parser.y" /* yacc.c:1646  */
    {
      (yyval.spec) = Declspec(SPEC_float);
    }
#line 4517 "parser.c" /* yacc.c:1646  */
    break;

  case 122:
#line 1217 "parser.y" /* yacc.c:1646  */
    {
      (yyval.spec) = Declspec(SPEC_double);
    }
#line 4525 "parser.c" /* yacc.c:1646  */
    break;

  case 123:
#line 1221 "parser.y" /* yacc.c:1646  */
    {
      (yyval.spec) = Declspec(SPEC_signed);
    }
#line 4533 "parser.c" /* yacc.c:1646  */
    break;

  case 124:
#line 1225 "parser.y" /* yacc.c:1646  */
    {
      (yyval.spec) = Declspec(SPEC_unsigned);
    }
#line 4541 "parser.c" /* yacc.c:1646  */
    break;

  case 125:
#line 1229 "parser.y" /* yacc.c:1646  */
    {
      (yyval.spec) = Declspec(SPEC_ubool);
    }
#line 4549 "parser.c" /* yacc.c:1646  */
    break;

  case 126:
#line 1233 "parser.y" /* yacc.c:1646  */
    {
      (yyval.spec) = Declspec(SPEC_ucomplex);
    }
#line 4557 "parser.c" /* yacc.c:1646  */
    break;

  case 127:
#line 1237 "parser.y" /* yacc.c:1646  */
    {
      (yyval.spec) = Declspec(SPEC_uimaginary);
    }
#line 4565 "parser.c" /* yacc.c:1646  */
    break;

  case 128:
#line 1241 "parser.y" /* yacc.c:1646  */
    {
      (yyval.spec) = (yyvsp[0].spec);
    }
#line 4573 "parser.c" /* yacc.c:1646  */
    break;

  case 129:
#line 1245 "parser.y" /* yacc.c:1646  */
    {
      (yyval.spec) = (yyvsp[0].spec);
    }
#line 4581 "parser.c" /* yacc.c:1646  */
    break;

  case 130:
#line 1249 "parser.y" /* yacc.c:1646  */
    {
      (yyval.spec) = Usertype((yyvsp[0].symb));
    }
#line 4589 "parser.c" /* yacc.c:1646  */
    break;

  case 131:
#line 1257 "parser.y" /* yacc.c:1646  */
    {
      (yyval.spec) = SUdecl((yyvsp[-3].type), NULL, (yyvsp[-1].decl));
    }
#line 4597 "parser.c" /* yacc.c:1646  */
    break;

  case 132:
#line 1261 "parser.y" /* yacc.c:1646  */
    {
      (yyval.spec) = SUdecl((yyvsp[-2].type), NULL, NULL);
    }
#line 4605 "parser.c" /* yacc.c:1646  */
    break;

  case 133:
#line 1265 "parser.y" /* yacc.c:1646  */
    {
      symbol s = Symbol((yyvsp[-3].name));
      /* Well, struct & union names have their own name space, and
       * their own scopes. I.e. they can be re-declare in nested
       * scopes. We don't do any kind of duplicate checks.
       */
      if (checkDecls)
        symtab_put(stab, s, SUNAME);
      (yyval.spec) = SUdecl((yyvsp[-4].type), s, (yyvsp[-1].decl));
    }
#line 4620 "parser.c" /* yacc.c:1646  */
    break;

  case 134:
#line 1280 "parser.y" /* yacc.c:1646  */
    {
      symbol s = (yyvsp[-3].symb);
      if (checkDecls)
        symtab_put(stab, s, SUNAME);
      (yyval.spec) = SUdecl((yyvsp[-4].type), s, (yyvsp[-1].decl));
    }
#line 4631 "parser.c" /* yacc.c:1646  */
    break;

  case 135:
#line 1287 "parser.y" /* yacc.c:1646  */
    {
      symbol s = Symbol((yyvsp[0].name));
      if (checkDecls)
        symtab_put(stab, s, SUNAME);
      (yyval.spec) = SUdecl((yyvsp[-1].type), s, NULL);
    }
#line 4642 "parser.c" /* yacc.c:1646  */
    break;

  case 136:
#line 1294 "parser.y" /* yacc.c:1646  */
    {
      symbol s = (yyvsp[0].symb);
      if (checkDecls)
        symtab_put(stab, s, SUNAME);
      (yyval.spec) = SUdecl((yyvsp[-1].type), s, NULL);
    }
#line 4653 "parser.c" /* yacc.c:1646  */
    break;

  case 137:
#line 1305 "parser.y" /* yacc.c:1646  */
    {
      (yyval.type) = SPEC_struct;
    }
#line 4661 "parser.c" /* yacc.c:1646  */
    break;

  case 138:
#line 1309 "parser.y" /* yacc.c:1646  */
    {
      (yyval.type) = SPEC_union;
    }
#line 4669 "parser.c" /* yacc.c:1646  */
    break;

  case 139:
#line 1317 "parser.y" /* yacc.c:1646  */
    {
      (yyval.decl) = (yyvsp[0].decl);
    }
#line 4677 "parser.c" /* yacc.c:1646  */
    break;

  case 140:
#line 1321 "parser.y" /* yacc.c:1646  */
    {
      (yyval.decl) = StructfieldList((yyvsp[-1].decl), (yyvsp[0].decl));
    }
#line 4685 "parser.c" /* yacc.c:1646  */
    break;

  case 141:
#line 1329 "parser.y" /* yacc.c:1646  */
    {
      (yyval.decl) = StructfieldDecl((yyvsp[-2].spec), (yyvsp[-1].decl));
    }
#line 4693 "parser.c" /* yacc.c:1646  */
    break;

  case 142:
#line 1333 "parser.y" /* yacc.c:1646  */
    {
      (yyval.decl) = StructfieldDecl((yyvsp[-1].spec), NULL);
    }
#line 4701 "parser.c" /* yacc.c:1646  */
    break;

  case 143:
#line 1341 "parser.y" /* yacc.c:1646  */
    {
      (yyval.spec) = (yyvsp[0].spec);
    }
#line 4709 "parser.c" /* yacc.c:1646  */
    break;

  case 144:
#line 1345 "parser.y" /* yacc.c:1646  */
    {
      (yyval.spec) = Speclist_right((yyvsp[-1].spec), (yyvsp[0].spec));
    }
#line 4717 "parser.c" /* yacc.c:1646  */
    break;

  case 145:
#line 1349 "parser.y" /* yacc.c:1646  */
    {
      (yyval.spec) = (yyvsp[0].spec);
    }
#line 4725 "parser.c" /* yacc.c:1646  */
    break;

  case 146:
#line 1353 "parser.y" /* yacc.c:1646  */
    {
      (yyval.spec) = Speclist_right((yyvsp[-1].spec), (yyvsp[0].spec));
    }
#line 4733 "parser.c" /* yacc.c:1646  */
    break;

  case 147:
#line 1361 "parser.y" /* yacc.c:1646  */
    {
      (yyval.decl) = (yyvsp[0].decl);
    }
#line 4741 "parser.c" /* yacc.c:1646  */
    break;

  case 148:
#line 1365 "parser.y" /* yacc.c:1646  */
    {
      (yyval.decl) = DeclList((yyvsp[-2].decl), (yyvsp[0].decl));
    }
#line 4749 "parser.c" /* yacc.c:1646  */
    break;

  case 149:
#line 1373 "parser.y" /* yacc.c:1646  */
    {
      (yyval.decl) = (yyvsp[0].decl);
    }
#line 4757 "parser.c" /* yacc.c:1646  */
    break;

  case 150:
#line 1377 "parser.y" /* yacc.c:1646  */
    {
      (yyval.decl) = BitDecl((yyvsp[-2].decl), (yyvsp[0].expr));
    }
#line 4765 "parser.c" /* yacc.c:1646  */
    break;

  case 151:
#line 1381 "parser.y" /* yacc.c:1646  */
    {
      (yyval.decl) = BitDecl(NULL, (yyvsp[0].expr));
    }
#line 4773 "parser.c" /* yacc.c:1646  */
    break;

  case 152:
#line 1389 "parser.y" /* yacc.c:1646  */
    {
      (yyval.spec) = Enumdecl(NULL, (yyvsp[-1].spec));
    }
#line 4781 "parser.c" /* yacc.c:1646  */
    break;

  case 153:
#line 1393 "parser.y" /* yacc.c:1646  */
    {
      symbol s = Symbol((yyvsp[-3].name));

      if (checkDecls)
      {
        if (symtab_get(stab, s, ENUMNAME))
          parse_error(-1, "enum name '%s' is already in use.", (yyvsp[-3].name));
        symtab_put(stab, s, ENUMNAME);
      }
      (yyval.spec) = Enumdecl(s, (yyvsp[-1].spec));
    }
#line 4797 "parser.c" /* yacc.c:1646  */
    break;

  case 154:
#line 1405 "parser.y" /* yacc.c:1646  */
    {
      (yyval.spec) = Enumdecl(NULL, (yyvsp[-2].spec));
    }
#line 4805 "parser.c" /* yacc.c:1646  */
    break;

  case 155:
#line 1409 "parser.y" /* yacc.c:1646  */
    {
      symbol s = Symbol((yyvsp[-4].name));

      if (checkDecls)
      {
        if (symtab_get(stab, s, ENUMNAME))
          parse_error(-1, "enum name '%s' is already in use.", (yyvsp[-4].name));
        symtab_put(stab, s, ENUMNAME);
      }
      (yyval.spec) = Enumdecl(s, (yyvsp[-2].spec));
    }
#line 4821 "parser.c" /* yacc.c:1646  */
    break;

  case 156:
#line 1421 "parser.y" /* yacc.c:1646  */
    {
      /*
      if (symtab_get(stab, s, ENUMNAME))
        parse_error(-1, "enum name '%s' is unknown.", $2);
      */
      (yyval.spec) = Enumdecl(Symbol((yyvsp[0].name)), NULL);
    }
#line 4833 "parser.c" /* yacc.c:1646  */
    break;

  case 157:
#line 1433 "parser.y" /* yacc.c:1646  */
    {
      (yyval.spec) = (yyvsp[0].spec);
    }
#line 4841 "parser.c" /* yacc.c:1646  */
    break;

  case 158:
#line 1437 "parser.y" /* yacc.c:1646  */
    {
      (yyval.spec) = Enumbodylist((yyvsp[-2].spec), (yyvsp[0].spec));
    }
#line 4849 "parser.c" /* yacc.c:1646  */
    break;

  case 159:
#line 1445 "parser.y" /* yacc.c:1646  */
    {
      (yyval.spec) = Enumerator((yyvsp[0].symb), NULL);
    }
#line 4857 "parser.c" /* yacc.c:1646  */
    break;

  case 160:
#line 1449 "parser.y" /* yacc.c:1646  */
    {
      (yyval.spec) = Enumerator((yyvsp[-2].symb), (yyvsp[0].expr));
    }
#line 4865 "parser.c" /* yacc.c:1646  */
    break;

  case 161:
#line 1457 "parser.y" /* yacc.c:1646  */
    {
      (yyval.spec) = Declspec(SPEC_const);
    }
#line 4873 "parser.c" /* yacc.c:1646  */
    break;

  case 162:
#line 1461 "parser.y" /* yacc.c:1646  */
    {
      (yyval.spec) = Declspec(SPEC_restrict);
    }
#line 4881 "parser.c" /* yacc.c:1646  */
    break;

  case 163:
#line 1465 "parser.y" /* yacc.c:1646  */
    {
      (yyval.spec) = Declspec(SPEC_volatile);
    }
#line 4889 "parser.c" /* yacc.c:1646  */
    break;

  case 164:
#line 1473 "parser.y" /* yacc.c:1646  */
    {
      (yyval.spec) = Declspec(SPEC_inline);
    }
#line 4897 "parser.c" /* yacc.c:1646  */
    break;

  case 165:
#line 1481 "parser.y" /* yacc.c:1646  */
    {
      (yyval.decl) = Declarator(NULL, (yyvsp[0].decl));
    }
#line 4905 "parser.c" /* yacc.c:1646  */
    break;

  case 166:
#line 1485 "parser.y" /* yacc.c:1646  */
    {
      (yyval.decl) = Declarator((yyvsp[-1].spec), (yyvsp[0].decl));
    }
#line 4913 "parser.c" /* yacc.c:1646  */
    break;

  case 167:
#line 1498 "parser.y" /* yacc.c:1646  */
    {
      (yyval.decl) = IdentifierDecl( Symbol((yyvsp[0].name)) );
    }
#line 4921 "parser.c" /* yacc.c:1646  */
    break;

  case 168:
#line 1502 "parser.y" /* yacc.c:1646  */
    {
      /* Try to simplify a bit: (ident) -> ident */
      if ((yyvsp[-1].decl)->spec == NULL && (yyvsp[-1].decl)->decl->type == DIDENT)
        (yyval.decl) = (yyvsp[-1].decl)->decl;
      else
        (yyval.decl) = ParenDecl((yyvsp[-1].decl));
    }
#line 4933 "parser.c" /* yacc.c:1646  */
    break;

  case 169:
#line 1510 "parser.y" /* yacc.c:1646  */
    {
      (yyval.decl) = ArrayDecl((yyvsp[-2].decl), NULL, NULL);
    }
#line 4941 "parser.c" /* yacc.c:1646  */
    break;

  case 170:
#line 1514 "parser.y" /* yacc.c:1646  */
    {
      (yyval.decl) = ArrayDecl((yyvsp[-3].decl), (yyvsp[-1].spec), NULL);
    }
#line 4949 "parser.c" /* yacc.c:1646  */
    break;

  case 171:
#line 1518 "parser.y" /* yacc.c:1646  */
    {
      (yyval.decl) = ArrayDecl((yyvsp[-3].decl), NULL, (yyvsp[-1].expr));
    }
#line 4957 "parser.c" /* yacc.c:1646  */
    break;

  case 172:
#line 1522 "parser.y" /* yacc.c:1646  */
    {
      (yyval.decl) = ArrayDecl((yyvsp[-4].decl), (yyvsp[-2].spec), (yyvsp[-1].expr));
    }
#line 4965 "parser.c" /* yacc.c:1646  */
    break;

  case 173:
#line 1526 "parser.y" /* yacc.c:1646  */
    {
      (yyval.decl) = ArrayDecl((yyvsp[-4].decl), StClassSpec(SPEC_static), (yyvsp[-1].expr));
    }
#line 4973 "parser.c" /* yacc.c:1646  */
    break;

  case 174:
#line 1530 "parser.y" /* yacc.c:1646  */
    {
      (yyval.decl) = ArrayDecl((yyvsp[-5].decl), Speclist_right( StClassSpec(SPEC_static), (yyvsp[-2].spec) ), (yyvsp[-1].expr));
    }
#line 4981 "parser.c" /* yacc.c:1646  */
    break;

  case 175:
#line 1534 "parser.y" /* yacc.c:1646  */
    {
      (yyval.decl) = ArrayDecl((yyvsp[-5].decl), Speclist_left( (yyvsp[-3].spec), StClassSpec(SPEC_static) ), (yyvsp[-1].expr));
    }
#line 4989 "parser.c" /* yacc.c:1646  */
    break;

  case 176:
#line 1538 "parser.y" /* yacc.c:1646  */
    {
      (yyval.decl) = ArrayDecl((yyvsp[-3].decl), Declspec(SPEC_star), NULL);
    }
#line 4997 "parser.c" /* yacc.c:1646  */
    break;

  case 177:
#line 1542 "parser.y" /* yacc.c:1646  */
    {
      (yyval.decl) = ArrayDecl((yyvsp[-4].decl), Speclist_left( (yyvsp[-2].spec), Declspec(SPEC_star) ), NULL);
    }
#line 5005 "parser.c" /* yacc.c:1646  */
    break;

  case 178:
#line 1546 "parser.y" /* yacc.c:1646  */
    {
      (yyval.decl) = FuncDecl((yyvsp[-3].decl), (yyvsp[-1].decl));
    }
#line 5013 "parser.c" /* yacc.c:1646  */
    break;

  case 179:
#line 1550 "parser.y" /* yacc.c:1646  */
    {
      (yyval.decl) = FuncDecl((yyvsp[-2].decl), NULL);
    }
#line 5021 "parser.c" /* yacc.c:1646  */
    break;

  case 180:
#line 1554 "parser.y" /* yacc.c:1646  */
    {
      (yyval.decl) = FuncDecl((yyvsp[-3].decl), (yyvsp[-1].decl));
    }
#line 5029 "parser.c" /* yacc.c:1646  */
    break;

  case 181:
#line 1559 "parser.y" /* yacc.c:1646  */
    {
      __has_dfc = 1;
      (yyval.decl) = DfcFuncDecl((yyvsp[-5].decl), DfcMakeVars((yyvsp[-3].decl), (yyvsp[-1].decl)));
    }
#line 5038 "parser.c" /* yacc.c:1646  */
    break;

  case 182:
#line 1564 "parser.y" /* yacc.c:1646  */
    {
      __has_dfc = 1;
      (yyval.decl) = DfcFuncDecl((yyvsp[-4].decl), DfcMakeVars(NULL, (yyvsp[-1].decl)));
    }
#line 5047 "parser.c" /* yacc.c:1646  */
    break;

  case 183:
#line 1569 "parser.y" /* yacc.c:1646  */
    {
      __has_dfc = 1;
      (yyval.decl) = DfcFuncDecl((yyvsp[-4].decl), DfcMakeVars((yyvsp[-2].decl), NULL));
    }
#line 5056 "parser.c" /* yacc.c:1646  */
    break;

  case 184:
#line 1574 "parser.y" /* yacc.c:1646  */
    {
      (yyval.decl) = DfcFuncDecl((yyvsp[-3].decl), DfcMakeVars(NULL, NULL));
    }
#line 5064 "parser.c" /* yacc.c:1646  */
    break;

  case 185:
#line 1582 "parser.y" /* yacc.c:1646  */
    {
      (yyval.spec) = Pointer();
    }
#line 5072 "parser.c" /* yacc.c:1646  */
    break;

  case 186:
#line 1586 "parser.y" /* yacc.c:1646  */
    {
      (yyval.spec) = Speclist_right(Pointer(), (yyvsp[0].spec));
    }
#line 5080 "parser.c" /* yacc.c:1646  */
    break;

  case 187:
#line 1590 "parser.y" /* yacc.c:1646  */
    {
      (yyval.spec) = Speclist_right(Pointer(), (yyvsp[0].spec));
    }
#line 5088 "parser.c" /* yacc.c:1646  */
    break;

  case 188:
#line 1594 "parser.y" /* yacc.c:1646  */
    {
      (yyval.spec) = Speclist_right( Pointer(), Speclist_left((yyvsp[-1].spec), (yyvsp[0].spec)) );
    }
#line 5096 "parser.c" /* yacc.c:1646  */
    break;

  case 189:
#line 1602 "parser.y" /* yacc.c:1646  */
    {
      (yyval.spec) = (yyvsp[0].spec);
    }
#line 5104 "parser.c" /* yacc.c:1646  */
    break;

  case 190:
#line 1606 "parser.y" /* yacc.c:1646  */
    {
      (yyval.spec) = Speclist_left((yyvsp[-1].spec), (yyvsp[0].spec));
    }
#line 5112 "parser.c" /* yacc.c:1646  */
    break;

  case 191:
#line 1614 "parser.y" /* yacc.c:1646  */
    {
      (yyval.decl) = (yyvsp[0].decl);
    }
#line 5120 "parser.c" /* yacc.c:1646  */
    break;

  case 192:
#line 1618 "parser.y" /* yacc.c:1646  */
    {
      (yyval.decl) = ParamList((yyvsp[-2].decl), Ellipsis());
    }
#line 5128 "parser.c" /* yacc.c:1646  */
    break;

  case 193:
#line 1626 "parser.y" /* yacc.c:1646  */
    {
      (yyval.decl) = (yyvsp[0].decl);
    }
#line 5136 "parser.c" /* yacc.c:1646  */
    break;

  case 194:
#line 1630 "parser.y" /* yacc.c:1646  */
    {
      (yyval.decl) = ParamList((yyvsp[-2].decl), (yyvsp[0].decl));
    }
#line 5144 "parser.c" /* yacc.c:1646  */
    break;

  case 195:
#line 1638 "parser.y" /* yacc.c:1646  */
    {
      (yyval.decl) = ParamDecl((yyvsp[-1].spec), (yyvsp[0].decl));
    }
#line 5152 "parser.c" /* yacc.c:1646  */
    break;

  case 196:
#line 1642 "parser.y" /* yacc.c:1646  */
    {
      (yyval.decl) = ParamDecl((yyvsp[0].spec), NULL);
    }
#line 5160 "parser.c" /* yacc.c:1646  */
    break;

  case 197:
#line 1646 "parser.y" /* yacc.c:1646  */
    {
      (yyval.decl) = ParamDecl((yyvsp[-1].spec), (yyvsp[0].decl));
    }
#line 5168 "parser.c" /* yacc.c:1646  */
    break;

  case 198:
#line 1654 "parser.y" /* yacc.c:1646  */
    {
      (yyval.decl) = IdentifierDecl( Symbol((yyvsp[0].name)) );
    }
#line 5176 "parser.c" /* yacc.c:1646  */
    break;

  case 199:
#line 1658 "parser.y" /* yacc.c:1646  */
    {
      (yyval.decl) = IdList((yyvsp[-2].decl), IdentifierDecl( Symbol((yyvsp[0].name)) ));
    }
#line 5184 "parser.c" /* yacc.c:1646  */
    break;

  case 200:
#line 1666 "parser.y" /* yacc.c:1646  */
    {
      (yyval.decl) = Casttypename((yyvsp[0].spec), NULL);
    }
#line 5192 "parser.c" /* yacc.c:1646  */
    break;

  case 201:
#line 1670 "parser.y" /* yacc.c:1646  */
    {
      (yyval.decl) = Casttypename((yyvsp[-1].spec), (yyvsp[0].decl));
    }
#line 5200 "parser.c" /* yacc.c:1646  */
    break;

  case 202:
#line 1678 "parser.y" /* yacc.c:1646  */
    {
      (yyval.decl) = AbstractDeclarator((yyvsp[0].spec), NULL);
    }
#line 5208 "parser.c" /* yacc.c:1646  */
    break;

  case 203:
#line 1682 "parser.y" /* yacc.c:1646  */
    {
      (yyval.decl) = AbstractDeclarator(NULL, (yyvsp[0].decl));
    }
#line 5216 "parser.c" /* yacc.c:1646  */
    break;

  case 204:
#line 1686 "parser.y" /* yacc.c:1646  */
    {
      (yyval.decl) = AbstractDeclarator((yyvsp[-1].spec), (yyvsp[0].decl));
    }
#line 5224 "parser.c" /* yacc.c:1646  */
    break;

  case 205:
#line 1694 "parser.y" /* yacc.c:1646  */
    {
      (yyval.decl) = ParenDecl((yyvsp[-1].decl));
    }
#line 5232 "parser.c" /* yacc.c:1646  */
    break;

  case 206:
#line 1698 "parser.y" /* yacc.c:1646  */
    {
      (yyval.decl) = ArrayDecl(NULL, NULL, NULL);
    }
#line 5240 "parser.c" /* yacc.c:1646  */
    break;

  case 207:
#line 1702 "parser.y" /* yacc.c:1646  */
    {
      (yyval.decl) = ArrayDecl((yyvsp[-2].decl), NULL, NULL);
    }
#line 5248 "parser.c" /* yacc.c:1646  */
    break;

  case 208:
#line 1706 "parser.y" /* yacc.c:1646  */
    {
      (yyval.decl) = ArrayDecl(NULL, NULL, (yyvsp[-1].expr));
    }
#line 5256 "parser.c" /* yacc.c:1646  */
    break;

  case 209:
#line 1710 "parser.y" /* yacc.c:1646  */
    {
      (yyval.decl) = ArrayDecl((yyvsp[-3].decl), NULL, (yyvsp[-1].expr));
    }
#line 5264 "parser.c" /* yacc.c:1646  */
    break;

  case 210:
#line 1714 "parser.y" /* yacc.c:1646  */
    {
      (yyval.decl) = ArrayDecl(NULL, Declspec(SPEC_star), NULL);
    }
#line 5272 "parser.c" /* yacc.c:1646  */
    break;

  case 211:
#line 1718 "parser.y" /* yacc.c:1646  */
    {
      (yyval.decl) = ArrayDecl((yyvsp[-3].decl), Declspec(SPEC_star), NULL);
    }
#line 5280 "parser.c" /* yacc.c:1646  */
    break;

  case 212:
#line 1722 "parser.y" /* yacc.c:1646  */
    {
      (yyval.decl) = FuncDecl(NULL, NULL);
    }
#line 5288 "parser.c" /* yacc.c:1646  */
    break;

  case 213:
#line 1726 "parser.y" /* yacc.c:1646  */
    {
      (yyval.decl) = FuncDecl((yyvsp[-2].decl), NULL);
    }
#line 5296 "parser.c" /* yacc.c:1646  */
    break;

  case 214:
#line 1730 "parser.y" /* yacc.c:1646  */
    {
      (yyval.decl) = FuncDecl(NULL, (yyvsp[-1].decl));
    }
#line 5304 "parser.c" /* yacc.c:1646  */
    break;

  case 215:
#line 1734 "parser.y" /* yacc.c:1646  */
    {
      (yyval.decl) = FuncDecl((yyvsp[-3].decl), (yyvsp[-1].decl));
    }
#line 5312 "parser.c" /* yacc.c:1646  */
    break;

  case 216:
#line 1742 "parser.y" /* yacc.c:1646  */
    {
      (yyval.symb) = Symbol((yyvsp[0].name));
    }
#line 5320 "parser.c" /* yacc.c:1646  */
    break;

  case 217:
#line 1750 "parser.y" /* yacc.c:1646  */
    {
      (yyval.expr) = (yyvsp[0].expr);
    }
#line 5328 "parser.c" /* yacc.c:1646  */
    break;

  case 218:
#line 1754 "parser.y" /* yacc.c:1646  */
    {
      (yyval.expr) = BracedInitializer((yyvsp[-1].expr));
    }
#line 5336 "parser.c" /* yacc.c:1646  */
    break;

  case 219:
#line 1758 "parser.y" /* yacc.c:1646  */
    {
      (yyval.expr) = BracedInitializer((yyvsp[-2].expr));
    }
#line 5344 "parser.c" /* yacc.c:1646  */
    break;

  case 220:
#line 1766 "parser.y" /* yacc.c:1646  */
    {
      (yyval.expr) = (yyvsp[0].expr);
    }
#line 5352 "parser.c" /* yacc.c:1646  */
    break;

  case 221:
#line 1770 "parser.y" /* yacc.c:1646  */
    {
      (yyval.expr) = Designated((yyvsp[-1].expr), (yyvsp[0].expr));
    }
#line 5360 "parser.c" /* yacc.c:1646  */
    break;

  case 222:
#line 1774 "parser.y" /* yacc.c:1646  */
    {
      (yyval.expr) = CommaList((yyvsp[-2].expr), (yyvsp[0].expr));
    }
#line 5368 "parser.c" /* yacc.c:1646  */
    break;

  case 223:
#line 1778 "parser.y" /* yacc.c:1646  */
    {
      (yyval.expr) = CommaList((yyvsp[-3].expr), Designated((yyvsp[-1].expr), (yyvsp[0].expr)));
    }
#line 5376 "parser.c" /* yacc.c:1646  */
    break;

  case 224:
#line 1786 "parser.y" /* yacc.c:1646  */
    {
      (yyval.expr) = (yyvsp[-1].expr);
    }
#line 5384 "parser.c" /* yacc.c:1646  */
    break;

  case 225:
#line 1794 "parser.y" /* yacc.c:1646  */
    {
      (yyval.expr) = (yyvsp[0].expr);
    }
#line 5392 "parser.c" /* yacc.c:1646  */
    break;

  case 226:
#line 1798 "parser.y" /* yacc.c:1646  */
    {
      (yyval.expr) = SpaceList((yyvsp[-1].expr), (yyvsp[0].expr));
    }
#line 5400 "parser.c" /* yacc.c:1646  */
    break;

  case 227:
#line 1806 "parser.y" /* yacc.c:1646  */
    {
      (yyval.expr) = IdxDesignator((yyvsp[-1].expr));
    }
#line 5408 "parser.c" /* yacc.c:1646  */
    break;

  case 228:
#line 1810 "parser.y" /* yacc.c:1646  */
    {
      (yyval.expr) = DotDesignator( Symbol((yyvsp[0].name)) );
    }
#line 5416 "parser.c" /* yacc.c:1646  */
    break;

  case 229:
#line 1814 "parser.y" /* yacc.c:1646  */
    {
      (yyval.expr) = DotDesignator((yyvsp[0].symb));
    }
#line 5424 "parser.c" /* yacc.c:1646  */
    break;

  case 230:
#line 1828 "parser.y" /* yacc.c:1646  */
    {
      (yyval.stmt) = (yyvsp[0].stmt);
    }
#line 5432 "parser.c" /* yacc.c:1646  */
    break;

  case 231:
#line 1832 "parser.y" /* yacc.c:1646  */
    {
      (yyval.stmt) = (yyvsp[0].stmt);
    }
#line 5440 "parser.c" /* yacc.c:1646  */
    break;

  case 232:
#line 1836 "parser.y" /* yacc.c:1646  */
    {
      (yyval.stmt) = (yyvsp[0].stmt);
    }
#line 5448 "parser.c" /* yacc.c:1646  */
    break;

  case 233:
#line 1840 "parser.y" /* yacc.c:1646  */
    {
      (yyval.stmt) = (yyvsp[0].stmt);
    }
#line 5456 "parser.c" /* yacc.c:1646  */
    break;

  case 234:
#line 1844 "parser.y" /* yacc.c:1646  */
    {
      (yyval.stmt) = (yyvsp[0].stmt);
    }
#line 5464 "parser.c" /* yacc.c:1646  */
    break;

  case 235:
#line 1848 "parser.y" /* yacc.c:1646  */
    {
      (yyval.stmt) = (yyvsp[0].stmt);
    }
#line 5472 "parser.c" /* yacc.c:1646  */
    break;

  case 236:
#line 1852 "parser.y" /* yacc.c:1646  */
    {
      (yyval.stmt) = OmpStmt((yyvsp[0].ocon));
      (yyval.stmt)->l = (yyvsp[0].ocon)->l;
    }
#line 5481 "parser.c" /* yacc.c:1646  */
    break;

  case 237:
#line 1857 "parser.y" /* yacc.c:1646  */
    {
      (yyval.stmt) = OmpixStmt((yyvsp[0].xcon));
      (yyval.stmt)->l = (yyvsp[0].xcon)->l;
    }
#line 5490 "parser.c" /* yacc.c:1646  */
    break;

  case 238:
#line 1866 "parser.y" /* yacc.c:1646  */
    { 
      (yyval.stmt) = (yyvsp[0].stmt); 
    }
#line 5498 "parser.c" /* yacc.c:1646  */
    break;

  case 239:
#line 1870 "parser.y" /* yacc.c:1646  */
    {       
      (yyval.stmt) = OmpStmt((yyvsp[0].ocon));
      (yyval.stmt)->l = (yyvsp[0].ocon)->l;
    }
#line 5507 "parser.c" /* yacc.c:1646  */
    break;

  case 240:
#line 1880 "parser.y" /* yacc.c:1646  */
    {
      (yyval.stmt) = Labeled( Symbol((yyvsp[-2].name)), (yyvsp[0].stmt) );
    }
#line 5515 "parser.c" /* yacc.c:1646  */
    break;

  case 241:
#line 1884 "parser.y" /* yacc.c:1646  */
    {
      (yyval.stmt) = Case((yyvsp[-2].expr), (yyvsp[0].stmt));
    }
#line 5523 "parser.c" /* yacc.c:1646  */
    break;

  case 242:
#line 1888 "parser.y" /* yacc.c:1646  */
    {
      (yyval.stmt) = Default((yyvsp[0].stmt));
    }
#line 5531 "parser.c" /* yacc.c:1646  */
    break;

  case 243:
#line 1896 "parser.y" /* yacc.c:1646  */
    {
      (yyval.stmt) = Compound(NULL);
    }
#line 5539 "parser.c" /* yacc.c:1646  */
    break;

  case 244:
#line 1899 "parser.y" /* yacc.c:1646  */
    { (yyval.type) = sc_original_line()-1; scope_start(stab); }
#line 5545 "parser.c" /* yacc.c:1646  */
    break;

  case 245:
#line 1901 "parser.y" /* yacc.c:1646  */
    {
      (yyval.stmt) = Compound((yyvsp[-1].stmt));
      scope_end(stab);
      (yyval.stmt)->l = (yyvsp[-2].type);     /* Remember 1st line */
    }
#line 5555 "parser.c" /* yacc.c:1646  */
    break;

  case 246:
#line 1911 "parser.y" /* yacc.c:1646  */
    {
      (yyval.stmt) = (yyvsp[0].stmt);
    }
#line 5563 "parser.c" /* yacc.c:1646  */
    break;

  case 247:
#line 1915 "parser.y" /* yacc.c:1646  */
    {
      (yyval.stmt) = BlockList((yyvsp[-1].stmt), (yyvsp[0].stmt));
      (yyval.stmt)->l = (yyvsp[-1].stmt)->l;
    }
#line 5572 "parser.c" /* yacc.c:1646  */
    break;

  case 248:
#line 1924 "parser.y" /* yacc.c:1646  */
    {
      (yyval.stmt) = (yyvsp[0].stmt);
    }
#line 5580 "parser.c" /* yacc.c:1646  */
    break;

  case 249:
#line 1928 "parser.y" /* yacc.c:1646  */
    {
      (yyval.stmt) = (yyvsp[0].stmt);
    }
#line 5588 "parser.c" /* yacc.c:1646  */
    break;

  case 250:
#line 1932 "parser.y" /* yacc.c:1646  */
    {
      (yyval.stmt) = OmpStmt((yyvsp[0].ocon));
      (yyval.stmt)->l = (yyvsp[0].ocon)->l;
    }
#line 5597 "parser.c" /* yacc.c:1646  */
    break;

  case 251:
#line 1937 "parser.y" /* yacc.c:1646  */
    {
      (yyval.stmt) = OmpixStmt((yyvsp[0].xcon));
      (yyval.stmt)->l = (yyvsp[0].xcon)->l;
    }
#line 5606 "parser.c" /* yacc.c:1646  */
    break;

  case 252:
#line 1946 "parser.y" /* yacc.c:1646  */
    {
      (yyval.stmt) = Expression(NULL);
    }
#line 5614 "parser.c" /* yacc.c:1646  */
    break;

  case 253:
#line 1950 "parser.y" /* yacc.c:1646  */
    {
      (yyval.stmt) = Expression((yyvsp[-1].expr));
      (yyval.stmt)->l = (yyvsp[-1].expr)->l;
    }
#line 5623 "parser.c" /* yacc.c:1646  */
    break;

  case 254:
#line 1959 "parser.y" /* yacc.c:1646  */
    {
      (yyval.stmt) = If((yyvsp[-2].expr), (yyvsp[0].stmt), NULL);
    }
#line 5631 "parser.c" /* yacc.c:1646  */
    break;

  case 255:
#line 1963 "parser.y" /* yacc.c:1646  */
    {
      (yyval.stmt) = If((yyvsp[-4].expr), (yyvsp[-2].stmt), (yyvsp[0].stmt));
    }
#line 5639 "parser.c" /* yacc.c:1646  */
    break;

  case 256:
#line 1967 "parser.y" /* yacc.c:1646  */
    {
      (yyval.stmt) = Switch((yyvsp[-2].expr), (yyvsp[0].stmt));
    }
#line 5647 "parser.c" /* yacc.c:1646  */
    break;

  case 257:
#line 1976 "parser.y" /* yacc.c:1646  */
    {
      (yyval.stmt) = While((yyvsp[-2].expr), (yyvsp[0].stmt));
    }
#line 5655 "parser.c" /* yacc.c:1646  */
    break;

  case 258:
#line 1980 "parser.y" /* yacc.c:1646  */
    {
      (yyval.stmt) = Do((yyvsp[-5].stmt), (yyvsp[-2].expr));
    }
#line 5663 "parser.c" /* yacc.c:1646  */
    break;

  case 260:
#line 1988 "parser.y" /* yacc.c:1646  */
    {
      (yyval.stmt) = For(NULL, NULL, NULL, (yyvsp[0].stmt));
    }
#line 5671 "parser.c" /* yacc.c:1646  */
    break;

  case 261:
#line 1992 "parser.y" /* yacc.c:1646  */
    {
      (yyval.stmt) = For(Expression((yyvsp[-4].expr)), NULL, NULL, (yyvsp[0].stmt));
    }
#line 5679 "parser.c" /* yacc.c:1646  */
    break;

  case 262:
#line 1996 "parser.y" /* yacc.c:1646  */
    {
      (yyval.stmt) = For(NULL, (yyvsp[-3].expr), NULL, (yyvsp[0].stmt));
    }
#line 5687 "parser.c" /* yacc.c:1646  */
    break;

  case 263:
#line 2000 "parser.y" /* yacc.c:1646  */
    {
      (yyval.stmt) = For(NULL, NULL, (yyvsp[-2].expr), (yyvsp[0].stmt));
    }
#line 5695 "parser.c" /* yacc.c:1646  */
    break;

  case 264:
#line 2004 "parser.y" /* yacc.c:1646  */
    {
      (yyval.stmt) = For(Expression((yyvsp[-5].expr)), (yyvsp[-3].expr), NULL, (yyvsp[0].stmt));
    }
#line 5703 "parser.c" /* yacc.c:1646  */
    break;

  case 265:
#line 2008 "parser.y" /* yacc.c:1646  */
    {
      (yyval.stmt) = For(Expression((yyvsp[-5].expr)), NULL, (yyvsp[-2].expr), (yyvsp[0].stmt));
    }
#line 5711 "parser.c" /* yacc.c:1646  */
    break;

  case 266:
#line 2012 "parser.y" /* yacc.c:1646  */
    {
      (yyval.stmt) = For(NULL, (yyvsp[-4].expr), (yyvsp[-2].expr), (yyvsp[0].stmt));
    }
#line 5719 "parser.c" /* yacc.c:1646  */
    break;

  case 267:
#line 2016 "parser.y" /* yacc.c:1646  */
    {
      (yyval.stmt) = For(Expression((yyvsp[-6].expr)), (yyvsp[-4].expr), (yyvsp[-2].expr), (yyvsp[0].stmt));
    }
#line 5727 "parser.c" /* yacc.c:1646  */
    break;

  case 268:
#line 2020 "parser.y" /* yacc.c:1646  */
    {
      (yyval.stmt) = For((yyvsp[-3].stmt), NULL, NULL, (yyvsp[0].stmt));
    }
#line 5735 "parser.c" /* yacc.c:1646  */
    break;

  case 269:
#line 2024 "parser.y" /* yacc.c:1646  */
    {
      (yyval.stmt) = For((yyvsp[-4].stmt), (yyvsp[-3].expr), NULL, (yyvsp[0].stmt));
    }
#line 5743 "parser.c" /* yacc.c:1646  */
    break;

  case 270:
#line 2028 "parser.y" /* yacc.c:1646  */
    {
      (yyval.stmt) = For((yyvsp[-4].stmt), NULL, (yyvsp[-2].expr), (yyvsp[0].stmt));
    }
#line 5751 "parser.c" /* yacc.c:1646  */
    break;

  case 271:
#line 2032 "parser.y" /* yacc.c:1646  */
    {
      (yyval.stmt) = For((yyvsp[-5].stmt), (yyvsp[-4].expr), (yyvsp[-2].expr), (yyvsp[0].stmt));
    }
#line 5759 "parser.c" /* yacc.c:1646  */
    break;

  case 272:
#line 2040 "parser.y" /* yacc.c:1646  */
    {
      /* We don't keep track of labels -- we leave it to the native compiler */
      (yyval.stmt) = Goto( Symbol((yyvsp[-1].name)) );
    }
#line 5768 "parser.c" /* yacc.c:1646  */
    break;

  case 273:
#line 2045 "parser.y" /* yacc.c:1646  */
    {
      (yyval.stmt) = Continue();
    }
#line 5776 "parser.c" /* yacc.c:1646  */
    break;

  case 274:
#line 2049 "parser.y" /* yacc.c:1646  */
    {
      (yyval.stmt) = Break();
    }
#line 5784 "parser.c" /* yacc.c:1646  */
    break;

  case 275:
#line 2053 "parser.y" /* yacc.c:1646  */
    {
      //TODO: simple hack, not 100% correct, does not cover goto
      if (errorOnReturn)
        parse_error(1, "return statement not allowed in an outlined region\n");
      (yyval.stmt) = Return(NULL);
    }
#line 5795 "parser.c" /* yacc.c:1646  */
    break;

  case 276:
#line 2060 "parser.y" /* yacc.c:1646  */
    {
      //TODO: simple hack, not 100% correct, does not cover goto
      if (errorOnReturn)
        parse_error(1, "return statement not allowed in an outlined region\n");
      (yyval.stmt) = Return((yyvsp[-1].expr));
    }
#line 5806 "parser.c" /* yacc.c:1646  */
    break;

  case 277:
#line 2077 "parser.y" /* yacc.c:1646  */
    {
      (yyval.stmt) = pastree = (yyvsp[0].stmt);
    }
#line 5814 "parser.c" /* yacc.c:1646  */
    break;

  case 278:
#line 2081 "parser.y" /* yacc.c:1646  */
    {
      (yyval.stmt) = pastree = BlockList((yyvsp[-1].stmt), (yyvsp[0].stmt));
    }
#line 5822 "parser.c" /* yacc.c:1646  */
    break;

  case 279:
#line 2089 "parser.y" /* yacc.c:1646  */
    {
      (yyval.stmt) = (yyvsp[0].stmt);
    }
#line 5830 "parser.c" /* yacc.c:1646  */
    break;

  case 280:
#line 2093 "parser.y" /* yacc.c:1646  */
    {
      (yyval.stmt) = (yyvsp[0].stmt);
    }
#line 5838 "parser.c" /* yacc.c:1646  */
    break;

  case 281:
#line 2100 "parser.y" /* yacc.c:1646  */
    {
      (yyval.stmt) = OmpixStmt((yyvsp[0].xcon));
    }
#line 5846 "parser.c" /* yacc.c:1646  */
    break;

  case 282:
#line 2111 "parser.y" /* yacc.c:1646  */
    { (yyval.stmt) = (yyvsp[0].stmt); }
#line 5852 "parser.c" /* yacc.c:1646  */
    break;

  case 283:
#line 2112 "parser.y" /* yacc.c:1646  */
    { (yyval.stmt) = (yyvsp[0].stmt); }
#line 5858 "parser.c" /* yacc.c:1646  */
    break;

  case 284:
#line 2117 "parser.y" /* yacc.c:1646  */
    {
      if (isTypedef ||
          ((yyvsp[0].decl)->decl->type != DFUNC && /* DF-C function */ (yyvsp[0].decl)->decl->type != DDFCFUNC))
        parse_error(1, "function definition cannot be parsed.\n");
      if (symtab_get(stab, decl_getidentifier_symbol((yyvsp[0].decl)), FUNCNAME) == NULL)
        symtab_put(stab, decl_getidentifier_symbol((yyvsp[0].decl)), FUNCNAME);

      scope_start(stab);
      ast_declare_function_params((yyvsp[0].decl));
    }
#line 5873 "parser.c" /* yacc.c:1646  */
    break;

  case 285:
#line 2128 "parser.y" /* yacc.c:1646  */
    {
      scope_end(stab);
        
      if( (yyvsp[-2].decl)->decl->type == DFUNC)
      {
        check_for_main_and_declare((yyvsp[-3].spec), (yyvsp[-2].decl));
        (yyval.stmt) = FuncDef((yyvsp[-3].spec), (yyvsp[-2].decl), NULL, (yyvsp[0].stmt));
      }
      else /* DDFCFUNC */
      {
        char *func_name = decl_getidentifier((yyvsp[-2].decl))->u.id->name;
        aststmt body = Verbatim(strdup("{"));
        
        struct dfc_insert_detail detail = {};
        detail.body = body;
        detail.inParams = (yyvsp[-2].decl)->decl->u.dfcvars->inParams;
        detail.outParams = (yyvsp[-2].decl)->decl->u.dfcvars->outParams;
		    detail.func_name = func_name;
        
        dfc_insert_active_data_decl_and_update_persize(&detail);
        dfc_insert_get_active_data_call(&detail);
        detail.body = BlockList(detail.body, (yyvsp[0].stmt));
        dfc_insert_update_active_data_call(&detail);
        
        detail.body = BlockList(detail.body, Verbatim(strdup("\n}")));

        (yyval.stmt) = FuncDef((yyvsp[-3].spec), (yyvsp[-2].decl), NULL, detail.body);

        // NOTE(luobin): It's convenient to prepare for 'append_new_main()' here.
        dfc_use_detail_to_fill_main_ad_and_fn_init(&detail);
      }
    }
#line 5910 "parser.c" /* yacc.c:1646  */
    break;

  case 286:
#line 2161 "parser.y" /* yacc.c:1646  */
    {
      if (isTypedef ||
          ((yyvsp[0].decl)->decl->type != DFUNC && /* DF-C function */ (yyvsp[0].decl)->decl->type != DDFCFUNC))
        parse_error(1, "function definition cannot be parsed.\n");
      if (symtab_get(stab, decl_getidentifier_symbol((yyvsp[0].decl)), FUNCNAME) == NULL)
        symtab_put(stab, decl_getidentifier_symbol((yyvsp[0].decl)), FUNCNAME);

      scope_start(stab);
      ast_declare_function_params((yyvsp[0].decl));
    }
#line 5925 "parser.c" /* yacc.c:1646  */
    break;

  case 287:
#line 2172 "parser.y" /* yacc.c:1646  */
    {
      astspec s = Declspec(SPEC_int);  /* return type defaults to "int" */

      scope_end(stab);
      check_for_main_and_declare(s, (yyvsp[-2].decl));
      (yyval.stmt) = FuncDef(s, (yyvsp[-2].decl), NULL, (yyvsp[0].stmt));
    }
#line 5937 "parser.c" /* yacc.c:1646  */
    break;

  case 288:
#line 2183 "parser.y" /* yacc.c:1646  */
    {
      if (isTypedef ||
          ((yyvsp[0].decl)->decl->type != DFUNC && /* DF-C function */ (yyvsp[0].decl)->decl->type != DDFCFUNC))
        parse_error(1, "function definition cannot be parsed.\n");
      if (symtab_get(stab, decl_getidentifier_symbol((yyvsp[0].decl)), FUNCNAME) == NULL)
        symtab_put(stab, decl_getidentifier_symbol((yyvsp[0].decl)), FUNCNAME);

      scope_start(stab);
      /* Notice here that the function parameters are declared through
       * the declaration_list and we need to do nothing else!
       */
    }
#line 5954 "parser.c" /* yacc.c:1646  */
    break;

  case 289:
#line 2196 "parser.y" /* yacc.c:1646  */
    {
      scope_end(stab);
      check_for_main_and_declare((yyvsp[-4].spec), (yyvsp[-3].decl));
      (yyval.stmt) = FuncDef((yyvsp[-4].spec), (yyvsp[-3].decl), (yyvsp[-1].stmt), (yyvsp[0].stmt));
    }
#line 5964 "parser.c" /* yacc.c:1646  */
    break;

  case 290:
#line 2202 "parser.y" /* yacc.c:1646  */
    {
      if (isTypedef ||
          ((yyvsp[0].decl)->decl->type != DFUNC && /* DF-C function */ (yyvsp[0].decl)->decl->type != DDFCFUNC))
        parse_error(1, "function definition cannot be parsed.\n");
      if (symtab_get(stab, decl_getidentifier_symbol((yyvsp[0].decl)), FUNCNAME) == NULL)
        symtab_put(stab, decl_getidentifier_symbol((yyvsp[0].decl)), FUNCNAME);

      scope_start(stab);
      /* Notice here that the function parameters are declared through
       * the declaration_list and we need to do nothing else!
       */
    }
#line 5981 "parser.c" /* yacc.c:1646  */
    break;

  case 291:
#line 2215 "parser.y" /* yacc.c:1646  */
    {
      astspec s = Declspec(SPEC_int);  /* return type defaults to "int" */

      scope_end(stab);
      check_for_main_and_declare(s, (yyvsp[-3].decl));
      (yyval.stmt) = FuncDef(s, (yyvsp[-3].decl), (yyvsp[-1].stmt), (yyvsp[0].stmt));
    }
#line 5993 "parser.c" /* yacc.c:1646  */
    break;

  case 292:
#line 2227 "parser.y" /* yacc.c:1646  */
    {
      (yyval.stmt) = (yyvsp[0].stmt);
    }
#line 6001 "parser.c" /* yacc.c:1646  */
    break;

  case 293:
#line 2231 "parser.y" /* yacc.c:1646  */
    {
      (yyval.stmt) = BlockList((yyvsp[-1].stmt), (yyvsp[0].stmt));         /* Same as block list */
    }
#line 6009 "parser.c" /* yacc.c:1646  */
    break;

  case 294:
#line 2246 "parser.y" /* yacc.c:1646  */
    {
      (yyval.stmt) = (yyvsp[0].stmt);
    }
#line 6017 "parser.c" /* yacc.c:1646  */
    break;

  case 295:
#line 2250 "parser.y" /* yacc.c:1646  */
    {
      (yyval.stmt) = (yyvsp[0].stmt);
    }
#line 6025 "parser.c" /* yacc.c:1646  */
    break;

  case 296:
#line 2258 "parser.y" /* yacc.c:1646  */
    {
      (yyval.stmt) = (yyvsp[0].stmt);
    }
#line 6033 "parser.c" /* yacc.c:1646  */
    break;

  case 297:
#line 2267 "parser.y" /* yacc.c:1646  */
    {
      (yyval.stmt) = (yyvsp[0].stmt);
    }
#line 6041 "parser.c" /* yacc.c:1646  */
    break;

  case 298:
#line 2271 "parser.y" /* yacc.c:1646  */
    {
      (yyval.stmt) = pastree = BlockList((yyvsp[-1].stmt), (yyvsp[0].stmt));
    }
#line 6049 "parser.c" /* yacc.c:1646  */
    break;

  case 299:
#line 2278 "parser.y" /* yacc.c:1646  */
    {
      (yyval.ocon) = (yyvsp[0].ocon);
    }
#line 6057 "parser.c" /* yacc.c:1646  */
    break;

  case 300:
#line 2282 "parser.y" /* yacc.c:1646  */
    {
      (yyval.ocon) = (yyvsp[0].ocon);
    }
#line 6065 "parser.c" /* yacc.c:1646  */
    break;

  case 301:
#line 2286 "parser.y" /* yacc.c:1646  */
    {
      (yyval.ocon) = (yyvsp[0].ocon);
    }
#line 6073 "parser.c" /* yacc.c:1646  */
    break;

  case 302:
#line 2290 "parser.y" /* yacc.c:1646  */
    {
      (yyval.ocon) = (yyvsp[0].ocon);
    }
#line 6081 "parser.c" /* yacc.c:1646  */
    break;

  case 303:
#line 2294 "parser.y" /* yacc.c:1646  */
    {
      (yyval.ocon) = (yyvsp[0].ocon);
    }
#line 6089 "parser.c" /* yacc.c:1646  */
    break;

  case 304:
#line 2298 "parser.y" /* yacc.c:1646  */
    {
      (yyval.ocon) = (yyvsp[0].ocon);
    }
#line 6097 "parser.c" /* yacc.c:1646  */
    break;

  case 305:
#line 2302 "parser.y" /* yacc.c:1646  */
    {
      (yyval.ocon) = (yyvsp[0].ocon);
    }
#line 6105 "parser.c" /* yacc.c:1646  */
    break;

  case 306:
#line 2306 "parser.y" /* yacc.c:1646  */
    {
      (yyval.ocon) = (yyvsp[0].ocon);
    }
#line 6113 "parser.c" /* yacc.c:1646  */
    break;

  case 307:
#line 2310 "parser.y" /* yacc.c:1646  */
    {
      (yyval.ocon) = (yyvsp[0].ocon);
    }
#line 6121 "parser.c" /* yacc.c:1646  */
    break;

  case 308:
#line 2314 "parser.y" /* yacc.c:1646  */
    {
      (yyval.ocon) = (yyvsp[0].ocon);
    }
#line 6129 "parser.c" /* yacc.c:1646  */
    break;

  case 309:
#line 2319 "parser.y" /* yacc.c:1646  */
    {
      (yyval.ocon) = (yyvsp[0].ocon);
    }
#line 6137 "parser.c" /* yacc.c:1646  */
    break;

  case 310:
#line 2324 "parser.y" /* yacc.c:1646  */
    {
      (yyval.ocon) = (yyvsp[0].ocon);
    }
#line 6145 "parser.c" /* yacc.c:1646  */
    break;

  case 311:
#line 2328 "parser.y" /* yacc.c:1646  */
    {
      (yyval.ocon) = (yyvsp[0].ocon);
    }
#line 6153 "parser.c" /* yacc.c:1646  */
    break;

  case 312:
#line 2332 "parser.y" /* yacc.c:1646  */
    {
      (yyval.ocon) = (yyvsp[0].ocon);
    }
#line 6161 "parser.c" /* yacc.c:1646  */
    break;

  case 313:
#line 2336 "parser.y" /* yacc.c:1646  */
    {
      (yyval.ocon) = (yyvsp[0].ocon);
    }
#line 6169 "parser.c" /* yacc.c:1646  */
    break;

  case 314:
#line 2340 "parser.y" /* yacc.c:1646  */
    {
      (yyval.ocon) = (yyvsp[0].ocon);
    }
#line 6177 "parser.c" /* yacc.c:1646  */
    break;

  case 315:
#line 2344 "parser.y" /* yacc.c:1646  */
    {
      (yyval.ocon) = (yyvsp[0].ocon);
    }
#line 6185 "parser.c" /* yacc.c:1646  */
    break;

  case 316:
#line 2348 "parser.y" /* yacc.c:1646  */
    {
      (yyval.ocon) = (yyvsp[0].ocon);
    }
#line 6193 "parser.c" /* yacc.c:1646  */
    break;

  case 317:
#line 2352 "parser.y" /* yacc.c:1646  */
    {
      (yyval.ocon) = (yyvsp[0].ocon);
    }
#line 6201 "parser.c" /* yacc.c:1646  */
    break;

  case 318:
#line 2356 "parser.y" /* yacc.c:1646  */
    {
      (yyval.ocon) = (yyvsp[0].ocon);
    }
#line 6209 "parser.c" /* yacc.c:1646  */
    break;

  case 319:
#line 2360 "parser.y" /* yacc.c:1646  */
    {
      (yyval.ocon) = (yyvsp[0].ocon);
    }
#line 6217 "parser.c" /* yacc.c:1646  */
    break;

  case 320:
#line 2364 "parser.y" /* yacc.c:1646  */
    {
      (yyval.ocon) = (yyvsp[0].ocon);
    }
#line 6225 "parser.c" /* yacc.c:1646  */
    break;

  case 321:
#line 2368 "parser.y" /* yacc.c:1646  */
    {
      (yyval.ocon) = (yyvsp[0].ocon);
    }
#line 6233 "parser.c" /* yacc.c:1646  */
    break;

  case 322:
#line 2372 "parser.y" /* yacc.c:1646  */
    {
      (yyval.ocon) = (yyvsp[0].ocon);
    }
#line 6241 "parser.c" /* yacc.c:1646  */
    break;

  case 323:
#line 2376 "parser.y" /* yacc.c:1646  */
    {
      (yyval.ocon) = (yyvsp[0].ocon);
    }
#line 6249 "parser.c" /* yacc.c:1646  */
    break;

  case 324:
#line 2380 "parser.y" /* yacc.c:1646  */
    {
      (yyval.ocon) = (yyvsp[0].ocon);
    }
#line 6257 "parser.c" /* yacc.c:1646  */
    break;

  case 325:
#line 2384 "parser.y" /* yacc.c:1646  */
    {
      (yyval.ocon) = (yyvsp[0].ocon);
    }
#line 6265 "parser.c" /* yacc.c:1646  */
    break;

  case 326:
#line 2388 "parser.y" /* yacc.c:1646  */
    {
      (yyval.ocon) = (yyvsp[0].ocon);
    }
#line 6273 "parser.c" /* yacc.c:1646  */
    break;

  case 327:
#line 2392 "parser.y" /* yacc.c:1646  */
    {
      (yyval.ocon) = (yyvsp[0].ocon);
    }
#line 6281 "parser.c" /* yacc.c:1646  */
    break;

  case 328:
#line 2396 "parser.y" /* yacc.c:1646  */
    {
      (yyval.ocon) = (yyvsp[0].ocon);
    }
#line 6289 "parser.c" /* yacc.c:1646  */
    break;

  case 329:
#line 2400 "parser.y" /* yacc.c:1646  */
    {
      (yyval.ocon) = (yyvsp[0].ocon);
    }
#line 6297 "parser.c" /* yacc.c:1646  */
    break;

  case 330:
#line 2405 "parser.y" /* yacc.c:1646  */
    {
      (yyval.ocon) = (yyvsp[0].ocon);
    }
#line 6305 "parser.c" /* yacc.c:1646  */
    break;

  case 331:
#line 2421 "parser.y" /* yacc.c:1646  */
    {
      (yyval.ocon) = OmpConstruct(DCBARRIER, (yyvsp[0].odir), NULL);
    }
#line 6313 "parser.c" /* yacc.c:1646  */
    break;

  case 332:
#line 2425 "parser.y" /* yacc.c:1646  */
    {
      (yyval.ocon) = OmpConstruct(DCFLUSH, (yyvsp[0].odir), NULL);
    }
#line 6321 "parser.c" /* yacc.c:1646  */
    break;

  case 333:
#line 2430 "parser.y" /* yacc.c:1646  */
    {
      (yyval.ocon) = OmpConstruct(DCTASKWAIT, (yyvsp[0].odir), NULL);
    }
#line 6329 "parser.c" /* yacc.c:1646  */
    break;

  case 334:
#line 2435 "parser.y" /* yacc.c:1646  */
    {
      (yyval.ocon) = OmpConstruct(DCTASKYIELD, (yyvsp[0].odir), NULL);
    }
#line 6337 "parser.c" /* yacc.c:1646  */
    break;

  case 335:
#line 2440 "parser.y" /* yacc.c:1646  */
    {
      (yyval.ocon) = OmpConstruct(DCCANCEL, (yyvsp[0].odir), NULL);
    }
#line 6345 "parser.c" /* yacc.c:1646  */
    break;

  case 336:
#line 2445 "parser.y" /* yacc.c:1646  */
    {
      (yyval.ocon) = OmpConstruct(DCCANCELLATIONPOINT, (yyvsp[0].odir), NULL);
    }
#line 6353 "parser.c" /* yacc.c:1646  */
    break;

  case 337:
#line 2452 "parser.y" /* yacc.c:1646  */
    {
      (yyval.stmt) = (yyvsp[0].stmt);
    }
#line 6361 "parser.c" /* yacc.c:1646  */
    break;

  case 338:
#line 2459 "parser.y" /* yacc.c:1646  */
    {
      (yyval.ocon) = OmpConstruct(DCPARALLEL, (yyvsp[-1].odir), (yyvsp[0].stmt));
      (yyval.ocon)->l = (yyvsp[-1].odir)->l;
    }
#line 6370 "parser.c" /* yacc.c:1646  */
    break;

  case 339:
#line 2467 "parser.y" /* yacc.c:1646  */
    {
      (yyval.odir) = OmpDirective(DCPARALLEL, (yyvsp[-1].ocla));
    }
#line 6378 "parser.c" /* yacc.c:1646  */
    break;

  case 340:
#line 2474 "parser.y" /* yacc.c:1646  */
    {
      (yyval.ocla) = NULL;
    }
#line 6386 "parser.c" /* yacc.c:1646  */
    break;

  case 341:
#line 2478 "parser.y" /* yacc.c:1646  */
    {
      (yyval.ocla) = OmpClauseList((yyvsp[-1].ocla), (yyvsp[0].ocla));
    }
#line 6394 "parser.c" /* yacc.c:1646  */
    break;

  case 342:
#line 2482 "parser.y" /* yacc.c:1646  */
    {
      (yyval.ocla) = OmpClauseList((yyvsp[-2].ocla), (yyvsp[0].ocla));
    }
#line 6402 "parser.c" /* yacc.c:1646  */
    break;

  case 343:
#line 2489 "parser.y" /* yacc.c:1646  */
    {
      (yyval.ocla) = (yyvsp[0].ocla);
    }
#line 6410 "parser.c" /* yacc.c:1646  */
    break;

  case 344:
#line 2493 "parser.y" /* yacc.c:1646  */
    {
      (yyval.ocla) = (yyvsp[0].ocla);
    }
#line 6418 "parser.c" /* yacc.c:1646  */
    break;

  case 345:
#line 2497 "parser.y" /* yacc.c:1646  */
    {
      (yyval.ocla) = (yyvsp[0].ocla);
    }
#line 6426 "parser.c" /* yacc.c:1646  */
    break;

  case 346:
#line 2501 "parser.y" /* yacc.c:1646  */
    {
      (yyval.ocla) = (yyvsp[0].ocla);
    }
#line 6434 "parser.c" /* yacc.c:1646  */
    break;

  case 347:
#line 2505 "parser.y" /* yacc.c:1646  */
    {
      (yyval.ocla) = (yyvsp[0].ocla);
    }
#line 6442 "parser.c" /* yacc.c:1646  */
    break;

  case 348:
#line 2509 "parser.y" /* yacc.c:1646  */
    {
      (yyval.ocla) = (yyvsp[0].ocla);
    }
#line 6450 "parser.c" /* yacc.c:1646  */
    break;

  case 349:
#line 2516 "parser.y" /* yacc.c:1646  */
    {
      (yyval.ocla) = (yyvsp[0].ocla);
    }
#line 6458 "parser.c" /* yacc.c:1646  */
    break;

  case 350:
#line 2519 "parser.y" /* yacc.c:1646  */
    { sc_pause_openmp(); }
#line 6464 "parser.c" /* yacc.c:1646  */
    break;

  case 351:
#line 2520 "parser.y" /* yacc.c:1646  */
    {
      sc_start_openmp();
      (yyval.ocla) = NumthreadsClause((yyvsp[-1].expr));
    }
#line 6473 "parser.c" /* yacc.c:1646  */
    break;

  case 352:
#line 2524 "parser.y" /* yacc.c:1646  */
    { sc_pause_openmp(); }
#line 6479 "parser.c" /* yacc.c:1646  */
    break;

  case 353:
#line 2525 "parser.y" /* yacc.c:1646  */
    {
      sc_start_openmp();
      (yyval.ocla) = VarlistClause(OCCOPYIN, (yyvsp[-1].decl));
    }
#line 6488 "parser.c" /* yacc.c:1646  */
    break;

  case 354:
#line 2531 "parser.y" /* yacc.c:1646  */
    {
      (yyval.ocla) = (yyvsp[0].ocla);
    }
#line 6496 "parser.c" /* yacc.c:1646  */
    break;

  case 355:
#line 2535 "parser.y" /* yacc.c:1646  */
    { sc_pause_openmp(); }
#line 6502 "parser.c" /* yacc.c:1646  */
    break;

  case 356:
#line 2536 "parser.y" /* yacc.c:1646  */
    {
      sc_start_openmp();
      (yyval.ocla) = VarlistClause(OCAUTO, (yyvsp[-1].decl));
    }
#line 6511 "parser.c" /* yacc.c:1646  */
    break;

  case 357:
#line 2544 "parser.y" /* yacc.c:1646  */
    {
      (yyval.ocon) = OmpConstruct(DCFOR, (yyvsp[-1].odir), (yyvsp[0].stmt));
    }
#line 6519 "parser.c" /* yacc.c:1646  */
    break;

  case 358:
#line 2551 "parser.y" /* yacc.c:1646  */
    {
      (yyval.odir) = OmpDirective(DCFOR, (yyvsp[-1].ocla));
    }
#line 6527 "parser.c" /* yacc.c:1646  */
    break;

  case 359:
#line 2558 "parser.y" /* yacc.c:1646  */
    {
      (yyval.ocla) = NULL;
    }
#line 6535 "parser.c" /* yacc.c:1646  */
    break;

  case 360:
#line 2562 "parser.y" /* yacc.c:1646  */
    {
      (yyval.ocla) = OmpClauseList((yyvsp[-1].ocla), (yyvsp[0].ocla));
    }
#line 6543 "parser.c" /* yacc.c:1646  */
    break;

  case 361:
#line 2566 "parser.y" /* yacc.c:1646  */
    {
      (yyval.ocla) = OmpClauseList((yyvsp[-2].ocla), (yyvsp[0].ocla));
    }
#line 6551 "parser.c" /* yacc.c:1646  */
    break;

  case 362:
#line 2573 "parser.y" /* yacc.c:1646  */
    {
      (yyval.ocla) = (yyvsp[0].ocla);
    }
#line 6559 "parser.c" /* yacc.c:1646  */
    break;

  case 363:
#line 2577 "parser.y" /* yacc.c:1646  */
    {
      (yyval.ocla) = (yyvsp[0].ocla);
    }
#line 6567 "parser.c" /* yacc.c:1646  */
    break;

  case 364:
#line 2581 "parser.y" /* yacc.c:1646  */
    {
      (yyval.ocla) = (yyvsp[0].ocla);
    }
#line 6575 "parser.c" /* yacc.c:1646  */
    break;

  case 365:
#line 2585 "parser.y" /* yacc.c:1646  */
    {
      (yyval.ocla) = (yyvsp[0].ocla);
    }
#line 6583 "parser.c" /* yacc.c:1646  */
    break;

  case 366:
#line 2589 "parser.y" /* yacc.c:1646  */
    {
      (yyval.ocla) = (yyvsp[0].ocla);
    }
#line 6591 "parser.c" /* yacc.c:1646  */
    break;

  case 367:
#line 2593 "parser.y" /* yacc.c:1646  */
    {
      (yyval.ocla) = PlainClause(OCNOWAIT);
    }
#line 6599 "parser.c" /* yacc.c:1646  */
    break;

  case 368:
#line 2600 "parser.y" /* yacc.c:1646  */
    {
      (yyval.ocla) = PlainClause(OCORDERED);
    }
#line 6607 "parser.c" /* yacc.c:1646  */
    break;

  case 369:
#line 2604 "parser.y" /* yacc.c:1646  */
    {
      (yyval.ocla) = ScheduleClause((yyvsp[-1].type), NULL);
    }
#line 6615 "parser.c" /* yacc.c:1646  */
    break;

  case 370:
#line 2607 "parser.y" /* yacc.c:1646  */
    { sc_pause_openmp(); }
#line 6621 "parser.c" /* yacc.c:1646  */
    break;

  case 371:
#line 2608 "parser.y" /* yacc.c:1646  */
    {
      sc_start_openmp();
      if ((yyvsp[-4].type) == OC_runtime)
        parse_error(1, "\"runtime\" schedules may not have a chunksize.\n");
      (yyval.ocla) = ScheduleClause((yyvsp[-4].type), (yyvsp[-1].expr));
    }
#line 6632 "parser.c" /* yacc.c:1646  */
    break;

  case 372:
#line 2615 "parser.y" /* yacc.c:1646  */
    {  /* non-OpenMP schedule */
      tempsave = checkDecls;
      checkDecls = 0;   /* Because the index of the loop is usualy involved */
      sc_pause_openmp();
    }
#line 6642 "parser.c" /* yacc.c:1646  */
    break;

  case 373:
#line 2621 "parser.y" /* yacc.c:1646  */
    {
      sc_start_openmp();
      checkDecls = tempsave;
      (yyval.ocla) = ScheduleClause(OC_affinity, (yyvsp[-1].expr));
    }
#line 6652 "parser.c" /* yacc.c:1646  */
    break;

  case 374:
#line 2627 "parser.y" /* yacc.c:1646  */
    {
      (yyval.ocla) = (yyvsp[0].ocla);
    }
#line 6660 "parser.c" /* yacc.c:1646  */
    break;

  case 375:
#line 2634 "parser.y" /* yacc.c:1646  */
    {
      (yyval.type) = OC_static;
    }
#line 6668 "parser.c" /* yacc.c:1646  */
    break;

  case 376:
#line 2638 "parser.y" /* yacc.c:1646  */
    {
      (yyval.type) = OC_dynamic;
    }
#line 6676 "parser.c" /* yacc.c:1646  */
    break;

  case 377:
#line 2642 "parser.y" /* yacc.c:1646  */
    {
      (yyval.type) = OC_guided;
    }
#line 6684 "parser.c" /* yacc.c:1646  */
    break;

  case 378:
#line 2646 "parser.y" /* yacc.c:1646  */
    {
      (yyval.type) = OC_runtime;
    }
#line 6692 "parser.c" /* yacc.c:1646  */
    break;

  case 379:
#line 2650 "parser.y" /* yacc.c:1646  */
    {
      (yyval.type) = OC_auto;
    }
#line 6700 "parser.c" /* yacc.c:1646  */
    break;

  case 380:
#line 2653 "parser.y" /* yacc.c:1646  */
    { parse_error(1, "invalid openmp schedule type.\n"); }
#line 6706 "parser.c" /* yacc.c:1646  */
    break;

  case 381:
#line 2659 "parser.y" /* yacc.c:1646  */
    {
      (yyval.ocon) = OmpConstruct(DCSECTIONS, (yyvsp[-1].odir), (yyvsp[0].stmt));
    }
#line 6714 "parser.c" /* yacc.c:1646  */
    break;

  case 382:
#line 2666 "parser.y" /* yacc.c:1646  */
    {
      (yyval.odir) = OmpDirective(DCSECTIONS, (yyvsp[-1].ocla));
    }
#line 6722 "parser.c" /* yacc.c:1646  */
    break;

  case 383:
#line 2673 "parser.y" /* yacc.c:1646  */
    {
      (yyval.ocla) = NULL;
    }
#line 6730 "parser.c" /* yacc.c:1646  */
    break;

  case 384:
#line 2677 "parser.y" /* yacc.c:1646  */
    {
      (yyval.ocla) = OmpClauseList((yyvsp[-1].ocla), (yyvsp[0].ocla));
    }
#line 6738 "parser.c" /* yacc.c:1646  */
    break;

  case 385:
#line 2681 "parser.y" /* yacc.c:1646  */
    {
      (yyval.ocla) = OmpClauseList((yyvsp[-2].ocla), (yyvsp[0].ocla));
    }
#line 6746 "parser.c" /* yacc.c:1646  */
    break;

  case 386:
#line 2688 "parser.y" /* yacc.c:1646  */
    {
      (yyval.ocla) = (yyvsp[0].ocla);
    }
#line 6754 "parser.c" /* yacc.c:1646  */
    break;

  case 387:
#line 2692 "parser.y" /* yacc.c:1646  */
    {
      (yyval.ocla) = (yyvsp[0].ocla);
    }
#line 6762 "parser.c" /* yacc.c:1646  */
    break;

  case 388:
#line 2696 "parser.y" /* yacc.c:1646  */
    {
      (yyval.ocla) = (yyvsp[0].ocla);
    }
#line 6770 "parser.c" /* yacc.c:1646  */
    break;

  case 389:
#line 2700 "parser.y" /* yacc.c:1646  */
    {
      (yyval.ocla) = (yyvsp[0].ocla);
    }
#line 6778 "parser.c" /* yacc.c:1646  */
    break;

  case 390:
#line 2704 "parser.y" /* yacc.c:1646  */
    {
      (yyval.ocla) = PlainClause(OCNOWAIT);
    }
#line 6786 "parser.c" /* yacc.c:1646  */
    break;

  case 391:
#line 2711 "parser.y" /* yacc.c:1646  */
    {
      (yyval.stmt) = Compound((yyvsp[-1].stmt));
    }
#line 6794 "parser.c" /* yacc.c:1646  */
    break;

  case 392:
#line 2718 "parser.y" /* yacc.c:1646  */
    {
      /* Make it look like it had a section pragma */
      (yyval.stmt) = OmpStmt( OmpConstruct(DCSECTION, OmpDirective(DCSECTION,NULL), (yyvsp[0].stmt)) );
    }
#line 6803 "parser.c" /* yacc.c:1646  */
    break;

  case 393:
#line 2723 "parser.y" /* yacc.c:1646  */
    {
      (yyval.stmt) = OmpStmt( OmpConstruct(DCSECTION, (yyvsp[-1].odir), (yyvsp[0].stmt)) );
    }
#line 6811 "parser.c" /* yacc.c:1646  */
    break;

  case 394:
#line 2727 "parser.y" /* yacc.c:1646  */
    {
      (yyval.stmt) = BlockList((yyvsp[-2].stmt), OmpStmt( OmpConstruct(DCSECTION, (yyvsp[-1].odir), (yyvsp[0].stmt)) ));
    }
#line 6819 "parser.c" /* yacc.c:1646  */
    break;

  case 395:
#line 2734 "parser.y" /* yacc.c:1646  */
    {
      (yyval.odir) = OmpDirective(DCSECTION, NULL);
    }
#line 6827 "parser.c" /* yacc.c:1646  */
    break;

  case 396:
#line 2741 "parser.y" /* yacc.c:1646  */
    {
      (yyval.ocon) = OmpConstruct(DCSINGLE, (yyvsp[-1].odir), (yyvsp[0].stmt));
    }
#line 6835 "parser.c" /* yacc.c:1646  */
    break;

  case 397:
#line 2748 "parser.y" /* yacc.c:1646  */
    {
      (yyval.odir) = OmpDirective(DCSINGLE, (yyvsp[-1].ocla));
    }
#line 6843 "parser.c" /* yacc.c:1646  */
    break;

  case 398:
#line 2755 "parser.y" /* yacc.c:1646  */
    {
      (yyval.ocla) = NULL;
    }
#line 6851 "parser.c" /* yacc.c:1646  */
    break;

  case 399:
#line 2759 "parser.y" /* yacc.c:1646  */
    {
      (yyval.ocla) = OmpClauseList((yyvsp[-1].ocla), (yyvsp[0].ocla));
    }
#line 6859 "parser.c" /* yacc.c:1646  */
    break;

  case 400:
#line 2763 "parser.y" /* yacc.c:1646  */
    {
      (yyval.ocla) = OmpClauseList((yyvsp[-2].ocla), (yyvsp[0].ocla));
    }
#line 6867 "parser.c" /* yacc.c:1646  */
    break;

  case 401:
#line 2770 "parser.y" /* yacc.c:1646  */
    {
      (yyval.ocla) = (yyvsp[0].ocla);
    }
#line 6875 "parser.c" /* yacc.c:1646  */
    break;

  case 402:
#line 2774 "parser.y" /* yacc.c:1646  */
    {
      (yyval.ocla) = (yyvsp[0].ocla);
    }
#line 6883 "parser.c" /* yacc.c:1646  */
    break;

  case 403:
#line 2778 "parser.y" /* yacc.c:1646  */
    {
      (yyval.ocla) = (yyvsp[0].ocla);
    }
#line 6891 "parser.c" /* yacc.c:1646  */
    break;

  case 404:
#line 2782 "parser.y" /* yacc.c:1646  */
    {
      (yyval.ocla) = PlainClause(OCNOWAIT);
    }
#line 6899 "parser.c" /* yacc.c:1646  */
    break;

  case 405:
#line 2788 "parser.y" /* yacc.c:1646  */
    { sc_pause_openmp(); }
#line 6905 "parser.c" /* yacc.c:1646  */
    break;

  case 406:
#line 2789 "parser.y" /* yacc.c:1646  */
    {
      sc_start_openmp();
      (yyval.ocla) = VarlistClause(OCCOPYPRIVATE, (yyvsp[-1].decl));
    }
#line 6914 "parser.c" /* yacc.c:1646  */
    break;

  case 407:
#line 2798 "parser.y" /* yacc.c:1646  */
    {
      //$$ = OmpConstruct(DCSIMD, $1, $2); TODO DCSIMD
    }
#line 6922 "parser.c" /* yacc.c:1646  */
    break;

  case 408:
#line 2806 "parser.y" /* yacc.c:1646  */
    {
      //$$ = OmpDirective(DCSIMD, $3); TODO DCSIMD
    }
#line 6930 "parser.c" /* yacc.c:1646  */
    break;

  case 409:
#line 2813 "parser.y" /* yacc.c:1646  */
    {
      (yyval.ocla) = NULL;
    }
#line 6938 "parser.c" /* yacc.c:1646  */
    break;

  case 410:
#line 2817 "parser.y" /* yacc.c:1646  */
    {
      (yyval.ocla) = OmpClauseList((yyvsp[-1].ocla), (yyvsp[0].ocla));
    }
#line 6946 "parser.c" /* yacc.c:1646  */
    break;

  case 411:
#line 2821 "parser.y" /* yacc.c:1646  */
    {
      (yyval.ocla) = OmpClauseList((yyvsp[-2].ocla), (yyvsp[0].ocla));
    }
#line 6954 "parser.c" /* yacc.c:1646  */
    break;

  case 412:
#line 2829 "parser.y" /* yacc.c:1646  */
    {
      (yyval.ocla) = (yyvsp[0].ocla);
    }
#line 6962 "parser.c" /* yacc.c:1646  */
    break;

  case 413:
#line 2833 "parser.y" /* yacc.c:1646  */
    {
      (yyval.ocla) = (yyvsp[0].ocla);
    }
#line 6970 "parser.c" /* yacc.c:1646  */
    break;

  case 414:
#line 2837 "parser.y" /* yacc.c:1646  */
    {
      (yyval.ocla) = (yyvsp[0].ocla);
    }
#line 6978 "parser.c" /* yacc.c:1646  */
    break;

  case 415:
#line 2841 "parser.y" /* yacc.c:1646  */
    {
      (yyval.ocla) = (yyvsp[0].ocla);
    }
#line 6986 "parser.c" /* yacc.c:1646  */
    break;

  case 416:
#line 2845 "parser.y" /* yacc.c:1646  */
    {
      (yyval.ocla) = (yyvsp[0].ocla);
    }
#line 6994 "parser.c" /* yacc.c:1646  */
    break;

  case 417:
#line 2853 "parser.y" /* yacc.c:1646  */
    {
      int n = 0, er = 0;
      if (xar_expr_is_constant((yyvsp[-1].expr)))
      {
        n = xar_calc_int_expr((yyvsp[-1].expr), &er);
        if (er) n = 0;
      }
      if (n <= 0)
        parse_error(1, "invalid number in simdlen() clause.\n");
      //$$ = CollapseClause(n); //TODO SAFELEN
    }
#line 7010 "parser.c" /* yacc.c:1646  */
    break;

  case 418:
#line 2865 "parser.y" /* yacc.c:1646  */
    {
      (yyval.ocla) = (yyvsp[0].ocla);
    }
#line 7018 "parser.c" /* yacc.c:1646  */
    break;

  case 419:
#line 2869 "parser.y" /* yacc.c:1646  */
    {
      (yyval.ocla) = (yyvsp[0].ocla);
    }
#line 7026 "parser.c" /* yacc.c:1646  */
    break;

  case 420:
#line 2877 "parser.y" /* yacc.c:1646  */
    {
      //$$ = PlainClause(OCINBRANCH); TODO ast
    }
#line 7034 "parser.c" /* yacc.c:1646  */
    break;

  case 421:
#line 2881 "parser.y" /* yacc.c:1646  */
    {
      //$$ = PlainClause(OCNOTINBRANCH); TODO ast
    }
#line 7042 "parser.c" /* yacc.c:1646  */
    break;

  case 422:
#line 2888 "parser.y" /* yacc.c:1646  */
    { sc_pause_openmp(); }
#line 7048 "parser.c" /* yacc.c:1646  */
    break;

  case 423:
#line 2889 "parser.y" /* yacc.c:1646  */
    {
      sc_start_openmp();
      //$$ = VarlistClause(OCUNIFORM, $4); TODO ast
    }
#line 7057 "parser.c" /* yacc.c:1646  */
    break;

  case 424:
#line 2897 "parser.y" /* yacc.c:1646  */
    { sc_pause_openmp(); }
#line 7063 "parser.c" /* yacc.c:1646  */
    break;

  case 425:
#line 2898 "parser.y" /* yacc.c:1646  */
    {
      sc_start_openmp();
      // TODO ast
    }
#line 7072 "parser.c" /* yacc.c:1646  */
    break;

  case 426:
#line 2906 "parser.y" /* yacc.c:1646  */
    { sc_pause_openmp(); }
#line 7078 "parser.c" /* yacc.c:1646  */
    break;

  case 427:
#line 2907 "parser.y" /* yacc.c:1646  */
    {
      sc_start_openmp();
      // TODO ast
    }
#line 7087 "parser.c" /* yacc.c:1646  */
    break;

  case 428:
#line 2915 "parser.y" /* yacc.c:1646  */
    {
      (yyval.expr) = NULL;
    }
#line 7095 "parser.c" /* yacc.c:1646  */
    break;

  case 429:
#line 2919 "parser.y" /* yacc.c:1646  */
    {
      // TODO ast
    }
#line 7103 "parser.c" /* yacc.c:1646  */
    break;

  case 430:
#line 2927 "parser.y" /* yacc.c:1646  */
    {
      //$$ = OmpConstruct(DCDECLSIMD, $1, $2); TODO DCDECLSIMD or change it to stmt
    }
#line 7111 "parser.c" /* yacc.c:1646  */
    break;

  case 431:
#line 2935 "parser.y" /* yacc.c:1646  */
    {
      //TODO
    }
#line 7119 "parser.c" /* yacc.c:1646  */
    break;

  case 432:
#line 2939 "parser.y" /* yacc.c:1646  */
    {
        //TODO
    }
#line 7127 "parser.c" /* yacc.c:1646  */
    break;

  case 433:
#line 2947 "parser.y" /* yacc.c:1646  */
    {
      //$$ = OmpDirective(DCDECLSIMD, $4); TODO DCDECLSIMD
    }
#line 7135 "parser.c" /* yacc.c:1646  */
    break;

  case 434:
#line 2954 "parser.y" /* yacc.c:1646  */
    {
      (yyval.ocla) = NULL;
    }
#line 7143 "parser.c" /* yacc.c:1646  */
    break;

  case 435:
#line 2958 "parser.y" /* yacc.c:1646  */
    {
      (yyval.ocla) = OmpClauseList((yyvsp[-1].ocla), (yyvsp[0].ocla));
    }
#line 7151 "parser.c" /* yacc.c:1646  */
    break;

  case 436:
#line 2962 "parser.y" /* yacc.c:1646  */
    {
      (yyval.ocla) = OmpClauseList((yyvsp[-2].ocla), (yyvsp[0].ocla));
    }
#line 7159 "parser.c" /* yacc.c:1646  */
    break;

  case 437:
#line 2971 "parser.y" /* yacc.c:1646  */
    {
      int n = 0, er = 0;
      if (xar_expr_is_constant((yyvsp[-1].expr)))
      {
        n = xar_calc_int_expr((yyvsp[-1].expr), &er);
        if (er) n = 0;
      }
      if (n <= 0)
        parse_error(1, "invalid number in simdlen() clause.\n");
      //$$ = CollapseClause(n); //TODO SIMDLEN
    }
#line 7175 "parser.c" /* yacc.c:1646  */
    break;

  case 438:
#line 2983 "parser.y" /* yacc.c:1646  */
    {
      (yyval.ocla) = (yyvsp[0].ocla);
    }
#line 7183 "parser.c" /* yacc.c:1646  */
    break;

  case 439:
#line 2987 "parser.y" /* yacc.c:1646  */
    {
      (yyval.ocla) = (yyvsp[0].ocla);
    }
#line 7191 "parser.c" /* yacc.c:1646  */
    break;

  case 440:
#line 2991 "parser.y" /* yacc.c:1646  */
    {
      (yyval.ocla) = (yyvsp[0].ocla);
    }
#line 7199 "parser.c" /* yacc.c:1646  */
    break;

  case 441:
#line 2995 "parser.y" /* yacc.c:1646  */
    {
      (yyval.ocla) = (yyvsp[0].ocla);
    }
#line 7207 "parser.c" /* yacc.c:1646  */
    break;

  case 442:
#line 3003 "parser.y" /* yacc.c:1646  */
    {
      //$$ = OmpConstruct(DCFORSIMD, $1, $2); TODO DCFORSIMD
    }
#line 7215 "parser.c" /* yacc.c:1646  */
    break;

  case 443:
#line 3011 "parser.y" /* yacc.c:1646  */
    {
      //$$ = OmpDirective(DCFORSIMD, $4); TODO DCFORSIMD
    }
#line 7223 "parser.c" /* yacc.c:1646  */
    break;

  case 444:
#line 3018 "parser.y" /* yacc.c:1646  */
    {
      (yyval.ocla) = NULL;
    }
#line 7231 "parser.c" /* yacc.c:1646  */
    break;

  case 445:
#line 3022 "parser.y" /* yacc.c:1646  */
    {
      (yyval.ocla) = OmpClauseList((yyvsp[-1].ocla), (yyvsp[0].ocla));
    }
#line 7239 "parser.c" /* yacc.c:1646  */
    break;

  case 446:
#line 3026 "parser.y" /* yacc.c:1646  */
    {
      (yyval.ocla) = OmpClauseList((yyvsp[-2].ocla), (yyvsp[0].ocla));
    }
#line 7247 "parser.c" /* yacc.c:1646  */
    break;

  case 447:
#line 3033 "parser.y" /* yacc.c:1646  */
    {
      (yyval.ocla) = (yyvsp[0].ocla);
    }
#line 7255 "parser.c" /* yacc.c:1646  */
    break;

  case 448:
#line 3037 "parser.y" /* yacc.c:1646  */
    {
      (yyval.ocla) = (yyvsp[0].ocla);
    }
#line 7263 "parser.c" /* yacc.c:1646  */
    break;

  case 449:
#line 3045 "parser.y" /* yacc.c:1646  */
    {
      //$$ = OmpConstruct(DCPARFORSIMD, $1, $2); TODO DCPARFORSIMD
    }
#line 7271 "parser.c" /* yacc.c:1646  */
    break;

  case 450:
#line 3053 "parser.y" /* yacc.c:1646  */
    {
      //$$ = OmpDirective(DCPARFORSIMD, $5); TODO DCFORSIMD
    }
#line 7279 "parser.c" /* yacc.c:1646  */
    break;

  case 451:
#line 3060 "parser.y" /* yacc.c:1646  */
    {
      (yyval.ocla) = NULL;
    }
#line 7287 "parser.c" /* yacc.c:1646  */
    break;

  case 452:
#line 3064 "parser.y" /* yacc.c:1646  */
    {
      (yyval.ocla) = OmpClauseList((yyvsp[-1].ocla), (yyvsp[0].ocla));
    }
#line 7295 "parser.c" /* yacc.c:1646  */
    break;

  case 453:
#line 3068 "parser.y" /* yacc.c:1646  */
    {
      (yyval.ocla) = OmpClauseList((yyvsp[-2].ocla), (yyvsp[0].ocla));
    }
#line 7303 "parser.c" /* yacc.c:1646  */
    break;

  case 454:
#line 3075 "parser.y" /* yacc.c:1646  */
    {
      (yyval.ocla) = (yyvsp[0].ocla);
    }
#line 7311 "parser.c" /* yacc.c:1646  */
    break;

  case 455:
#line 3079 "parser.y" /* yacc.c:1646  */
    {
      (yyval.ocla) = (yyvsp[0].ocla);
    }
#line 7319 "parser.c" /* yacc.c:1646  */
    break;

  case 456:
#line 3087 "parser.y" /* yacc.c:1646  */
    {
      (yyval.ocon) = OmpConstruct(DCTARGETDATA, (yyvsp[-1].odir), (yyvsp[0].stmt));
    }
#line 7327 "parser.c" /* yacc.c:1646  */
    break;

  case 457:
#line 3095 "parser.y" /* yacc.c:1646  */
    {
      (yyval.odir) = OmpDirective(DCTARGETDATA, (yyvsp[-1].ocla));
    }
#line 7335 "parser.c" /* yacc.c:1646  */
    break;

  case 458:
#line 3102 "parser.y" /* yacc.c:1646  */
    {
      (yyval.ocla) = NULL;
    }
#line 7343 "parser.c" /* yacc.c:1646  */
    break;

  case 459:
#line 3106 "parser.y" /* yacc.c:1646  */
    {
      (yyval.ocla) = OmpClauseList((yyvsp[-1].ocla), (yyvsp[0].ocla));
    }
#line 7351 "parser.c" /* yacc.c:1646  */
    break;

  case 460:
#line 3110 "parser.y" /* yacc.c:1646  */
    {
      (yyval.ocla) = OmpClauseList((yyvsp[-2].ocla), (yyvsp[0].ocla));
    }
#line 7359 "parser.c" /* yacc.c:1646  */
    break;

  case 461:
#line 3117 "parser.y" /* yacc.c:1646  */
    {
      (yyval.ocla) = (yyvsp[0].ocla);
    }
#line 7367 "parser.c" /* yacc.c:1646  */
    break;

  case 462:
#line 3121 "parser.y" /* yacc.c:1646  */
    {
      (yyval.ocla) = (yyvsp[0].ocla);
    }
#line 7375 "parser.c" /* yacc.c:1646  */
    break;

  case 463:
#line 3125 "parser.y" /* yacc.c:1646  */
    {
      (yyval.ocla) = (yyvsp[0].ocla);
    }
#line 7383 "parser.c" /* yacc.c:1646  */
    break;

  case 464:
#line 3132 "parser.y" /* yacc.c:1646  */
    { sc_pause_openmp(); }
#line 7389 "parser.c" /* yacc.c:1646  */
    break;

  case 465:
#line 3133 "parser.y" /* yacc.c:1646  */
    {
      sc_start_openmp();
      (yyval.ocla) = DeviceClause((yyvsp[-1].expr));
    }
#line 7398 "parser.c" /* yacc.c:1646  */
    break;

  case 466:
#line 3141 "parser.y" /* yacc.c:1646  */
    { sc_pause_openmp(); }
#line 7404 "parser.c" /* yacc.c:1646  */
    break;

  case 467:
#line 3142 "parser.y" /* yacc.c:1646  */
    {
      sc_start_openmp();
      (yyval.ocla) = MapClause((yyvsp[-4].type), (yyvsp[-1].decl));
    }
#line 7413 "parser.c" /* yacc.c:1646  */
    break;

  case 468:
#line 3146 "parser.y" /* yacc.c:1646  */
    { sc_pause_openmp(); }
#line 7419 "parser.c" /* yacc.c:1646  */
    break;

  case 469:
#line 3147 "parser.y" /* yacc.c:1646  */
    {
      sc_start_openmp();
	  (yyval.ocla) = MapClause(OC_tofrom, (yyvsp[-1].decl));
    }
#line 7428 "parser.c" /* yacc.c:1646  */
    break;

  case 470:
#line 3156 "parser.y" /* yacc.c:1646  */
    {
      (yyval.type) = OC_alloc;
    }
#line 7436 "parser.c" /* yacc.c:1646  */
    break;

  case 471:
#line 3160 "parser.y" /* yacc.c:1646  */
    {
      (yyval.type) = OC_to;
    }
#line 7444 "parser.c" /* yacc.c:1646  */
    break;

  case 472:
#line 3164 "parser.y" /* yacc.c:1646  */
    {
      (yyval.type) = OC_from;
    }
#line 7452 "parser.c" /* yacc.c:1646  */
    break;

  case 473:
#line 3168 "parser.y" /* yacc.c:1646  */
    {
      (yyval.type) = OC_tofrom;
    }
#line 7460 "parser.c" /* yacc.c:1646  */
    break;

  case 474:
#line 3175 "parser.y" /* yacc.c:1646  */
    { (yyval.type) = errorOnReturn;  errorOnReturn = 1; }
#line 7466 "parser.c" /* yacc.c:1646  */
    break;

  case 475:
#line 3177 "parser.y" /* yacc.c:1646  */
    {
      errorOnReturn = (yyvsp[-1].type);
      (yyval.ocon) = OmpConstruct(DCTARGET, (yyvsp[-2].odir), (yyvsp[0].stmt));
      __has_target = 1;
    }
#line 7476 "parser.c" /* yacc.c:1646  */
    break;

  case 476:
#line 3187 "parser.y" /* yacc.c:1646  */
    {
      (yyval.odir) = OmpDirective(DCTARGET, (yyvsp[-1].ocla));
    }
#line 7484 "parser.c" /* yacc.c:1646  */
    break;

  case 477:
#line 3194 "parser.y" /* yacc.c:1646  */
    {
      (yyval.ocla) = NULL;
    }
#line 7492 "parser.c" /* yacc.c:1646  */
    break;

  case 478:
#line 3198 "parser.y" /* yacc.c:1646  */
    {
      (yyval.ocla) = OmpClauseList((yyvsp[-1].ocla), (yyvsp[0].ocla));
    }
#line 7500 "parser.c" /* yacc.c:1646  */
    break;

  case 479:
#line 3202 "parser.y" /* yacc.c:1646  */
    {
      (yyval.ocla) = OmpClauseList((yyvsp[-2].ocla), (yyvsp[0].ocla));
    }
#line 7508 "parser.c" /* yacc.c:1646  */
    break;

  case 480:
#line 3209 "parser.y" /* yacc.c:1646  */
    {
      (yyval.ocla) = (yyvsp[0].ocla);
    }
#line 7516 "parser.c" /* yacc.c:1646  */
    break;

  case 481:
#line 3213 "parser.y" /* yacc.c:1646  */
    {
      (yyval.ocla) = (yyvsp[0].ocla);
    }
#line 7524 "parser.c" /* yacc.c:1646  */
    break;

  case 482:
#line 3220 "parser.y" /* yacc.c:1646  */
    {
      (yyval.ocla) = (yyvsp[0].ocla);
    }
#line 7532 "parser.c" /* yacc.c:1646  */
    break;

  case 483:
#line 3224 "parser.y" /* yacc.c:1646  */
    {
      (yyval.ocla) = (yyvsp[0].ocla);
    }
#line 7540 "parser.c" /* yacc.c:1646  */
    break;

  case 484:
#line 3232 "parser.y" /* yacc.c:1646  */
    {
      (yyval.ocon) = OmpConstruct(DCTARGETUPD, (yyvsp[0].odir), NULL);
    }
#line 7548 "parser.c" /* yacc.c:1646  */
    break;

  case 485:
#line 3240 "parser.y" /* yacc.c:1646  */
    {
      (yyval.odir) = OmpDirective(DCTARGETUPD, (yyvsp[-1].ocla));
    }
#line 7556 "parser.c" /* yacc.c:1646  */
    break;

  case 486:
#line 3247 "parser.y" /* yacc.c:1646  */
    {
      (yyval.ocla) = (yyvsp[0].ocla);
    }
#line 7564 "parser.c" /* yacc.c:1646  */
    break;

  case 487:
#line 3251 "parser.y" /* yacc.c:1646  */
    {
      (yyval.ocla) = OmpClauseList((yyvsp[-1].ocla), (yyvsp[0].ocla));
    }
#line 7572 "parser.c" /* yacc.c:1646  */
    break;

  case 488:
#line 3255 "parser.y" /* yacc.c:1646  */
    {
      (yyval.ocla) = OmpClauseList((yyvsp[-2].ocla), (yyvsp[0].ocla));
    }
#line 7580 "parser.c" /* yacc.c:1646  */
    break;

  case 489:
#line 3262 "parser.y" /* yacc.c:1646  */
    {
      (yyval.ocla) = (yyvsp[0].ocla);
    }
#line 7588 "parser.c" /* yacc.c:1646  */
    break;

  case 490:
#line 3266 "parser.y" /* yacc.c:1646  */
    {
      (yyval.ocla) = (yyvsp[0].ocla);
    }
#line 7596 "parser.c" /* yacc.c:1646  */
    break;

  case 491:
#line 3270 "parser.y" /* yacc.c:1646  */
    {
      (yyval.ocla) = (yyvsp[0].ocla);
    }
#line 7604 "parser.c" /* yacc.c:1646  */
    break;

  case 492:
#line 3276 "parser.y" /* yacc.c:1646  */
    { sc_pause_openmp(); }
#line 7610 "parser.c" /* yacc.c:1646  */
    break;

  case 493:
#line 3277 "parser.y" /* yacc.c:1646  */
    {
      sc_start_openmp();
      (yyval.ocla) = VarlistClause(OCTO, (yyvsp[-1].decl));
    }
#line 7619 "parser.c" /* yacc.c:1646  */
    break;

  case 494:
#line 3281 "parser.y" /* yacc.c:1646  */
    { sc_pause_openmp(); }
#line 7625 "parser.c" /* yacc.c:1646  */
    break;

  case 495:
#line 3282 "parser.y" /* yacc.c:1646  */
    {
      sc_start_openmp();
      (yyval.ocla) = VarlistClause(OCFROM, (yyvsp[-1].decl));
    }
#line 7634 "parser.c" /* yacc.c:1646  */
    break;

  case 496:
#line 3291 "parser.y" /* yacc.c:1646  */
    {
      (yyval.ocon) = OmpConstruct(DCDECLTARGET, (yyvsp[-2].odir), (yyvsp[-1].stmt));
    }
#line 7642 "parser.c" /* yacc.c:1646  */
    break;

  case 497:
#line 3298 "parser.y" /* yacc.c:1646  */
    {
      (yyval.odir) = OmpDirective(DCDECLTARGET, NULL);
    }
#line 7650 "parser.c" /* yacc.c:1646  */
    break;

  case 498:
#line 3305 "parser.y" /* yacc.c:1646  */
    {
      //$$ = OmpDirective(DCENDDECLTARGET, NULL); TODO DCENDDECLTARGET
    }
#line 7658 "parser.c" /* yacc.c:1646  */
    break;

  case 499:
#line 3313 "parser.y" /* yacc.c:1646  */
    {
      //$$ = OmpConstruct(DCTEAMS, $1, $2); TODO DCTEAMS
    }
#line 7666 "parser.c" /* yacc.c:1646  */
    break;

  case 500:
#line 3321 "parser.y" /* yacc.c:1646  */
    {
      //$$ = OmpDirective(DCTEAMS, $3); TODO DCTEAMS
    }
#line 7674 "parser.c" /* yacc.c:1646  */
    break;

  case 501:
#line 3328 "parser.y" /* yacc.c:1646  */
    {
      (yyval.ocla) = NULL;
    }
#line 7682 "parser.c" /* yacc.c:1646  */
    break;

  case 502:
#line 3332 "parser.y" /* yacc.c:1646  */
    {
      (yyval.ocla) = OmpClauseList((yyvsp[-1].ocla), (yyvsp[0].ocla));
    }
#line 7690 "parser.c" /* yacc.c:1646  */
    break;

  case 503:
#line 3336 "parser.y" /* yacc.c:1646  */
    {
      (yyval.ocla) = OmpClauseList((yyvsp[-2].ocla), (yyvsp[0].ocla));
    }
#line 7698 "parser.c" /* yacc.c:1646  */
    break;

  case 504:
#line 3343 "parser.y" /* yacc.c:1646  */
    {
      (yyval.ocla) = (yyvsp[0].ocla);
    }
#line 7706 "parser.c" /* yacc.c:1646  */
    break;

  case 505:
#line 3347 "parser.y" /* yacc.c:1646  */
    {
      (yyval.ocla) = (yyvsp[0].ocla);
    }
#line 7714 "parser.c" /* yacc.c:1646  */
    break;

  case 506:
#line 3351 "parser.y" /* yacc.c:1646  */
    {
      (yyval.ocla) = (yyvsp[0].ocla);
    }
#line 7722 "parser.c" /* yacc.c:1646  */
    break;

  case 507:
#line 3355 "parser.y" /* yacc.c:1646  */
    {
      (yyval.ocla) = (yyvsp[0].ocla);
    }
#line 7730 "parser.c" /* yacc.c:1646  */
    break;

  case 508:
#line 3359 "parser.y" /* yacc.c:1646  */
    {
      (yyval.ocla) = (yyvsp[0].ocla);
    }
#line 7738 "parser.c" /* yacc.c:1646  */
    break;

  case 509:
#line 3363 "parser.y" /* yacc.c:1646  */
    {
      (yyval.ocla) = (yyvsp[0].ocla);
    }
#line 7746 "parser.c" /* yacc.c:1646  */
    break;

  case 510:
#line 3370 "parser.y" /* yacc.c:1646  */
    { sc_pause_openmp(); }
#line 7752 "parser.c" /* yacc.c:1646  */
    break;

  case 511:
#line 3371 "parser.y" /* yacc.c:1646  */
    {
      sc_start_openmp();
      //$$ = NumthreadsClause($4); //TODO check if numthreads is good or if I should make something new
    }
#line 7761 "parser.c" /* yacc.c:1646  */
    break;

  case 512:
#line 3376 "parser.y" /* yacc.c:1646  */
    { sc_pause_openmp(); }
#line 7767 "parser.c" /* yacc.c:1646  */
    break;

  case 513:
#line 3377 "parser.y" /* yacc.c:1646  */
    {
      sc_start_openmp();
      //$$ = NumthreadsClause($4); //TODO check if numthreads is good or if I should make something new
    }
#line 7776 "parser.c" /* yacc.c:1646  */
    break;

  case 514:
#line 3386 "parser.y" /* yacc.c:1646  */
    {
      //$$ = OmpConstruct(DCDISTRIBUTE, $1, $2); TODO DCDISTRIBUTE
    }
#line 7784 "parser.c" /* yacc.c:1646  */
    break;

  case 515:
#line 3394 "parser.y" /* yacc.c:1646  */
    {
      //$$ = OmpDirective(DCDISTRIBUTE, $3); TODO DCDISTRIBUTE
    }
#line 7792 "parser.c" /* yacc.c:1646  */
    break;

  case 516:
#line 3401 "parser.y" /* yacc.c:1646  */
    {
      (yyval.ocla) = NULL;
    }
#line 7800 "parser.c" /* yacc.c:1646  */
    break;

  case 517:
#line 3405 "parser.y" /* yacc.c:1646  */
    {
      (yyval.ocla) = OmpClauseList((yyvsp[-1].ocla), (yyvsp[0].ocla));
    }
#line 7808 "parser.c" /* yacc.c:1646  */
    break;

  case 518:
#line 3409 "parser.y" /* yacc.c:1646  */
    {
      (yyval.ocla) = OmpClauseList((yyvsp[-2].ocla), (yyvsp[0].ocla));
    }
#line 7816 "parser.c" /* yacc.c:1646  */
    break;

  case 519:
#line 3416 "parser.y" /* yacc.c:1646  */
    {
      (yyval.ocla) = (yyvsp[0].ocla);
    }
#line 7824 "parser.c" /* yacc.c:1646  */
    break;

  case 520:
#line 3420 "parser.y" /* yacc.c:1646  */
    {
      (yyval.ocla) = (yyvsp[0].ocla);
    }
#line 7832 "parser.c" /* yacc.c:1646  */
    break;

  case 521:
#line 3424 "parser.y" /* yacc.c:1646  */
    {
      (yyval.ocla) = (yyvsp[0].ocla);
    }
#line 7840 "parser.c" /* yacc.c:1646  */
    break;

  case 522:
#line 3428 "parser.y" /* yacc.c:1646  */
    {
      (yyval.ocla) = (yyvsp[0].ocla);
    }
#line 7848 "parser.c" /* yacc.c:1646  */
    break;

  case 523:
#line 3435 "parser.y" /* yacc.c:1646  */
    {
      (yyval.ocla) = ScheduleClause(OC_static, NULL);
    }
#line 7856 "parser.c" /* yacc.c:1646  */
    break;

  case 524:
#line 3438 "parser.y" /* yacc.c:1646  */
    { sc_pause_openmp(); }
#line 7862 "parser.c" /* yacc.c:1646  */
    break;

  case 525:
#line 3439 "parser.y" /* yacc.c:1646  */
    {
      sc_start_openmp();
      (yyval.ocla) = ScheduleClause(OC_static, (yyvsp[-1].expr));
    }
#line 7871 "parser.c" /* yacc.c:1646  */
    break;

  case 526:
#line 3448 "parser.y" /* yacc.c:1646  */
    {
      //$$ = OmpConstruct(DCDISTSIMD, $1, $2); TODO DCDISTSIMD
      //$$->l = $1->l;
    }
#line 7880 "parser.c" /* yacc.c:1646  */
    break;

  case 527:
#line 3457 "parser.y" /* yacc.c:1646  */
    {
      //$$ = OmpDirective(DCDISTSIMD, $4); TODO DCDISTSIMD
    }
#line 7888 "parser.c" /* yacc.c:1646  */
    break;

  case 528:
#line 3464 "parser.y" /* yacc.c:1646  */
    {
      (yyval.ocla) = NULL;
    }
#line 7896 "parser.c" /* yacc.c:1646  */
    break;

  case 529:
#line 3468 "parser.y" /* yacc.c:1646  */
    {
      (yyval.ocla) = OmpClauseList((yyvsp[-1].ocla), (yyvsp[0].ocla));
    }
#line 7904 "parser.c" /* yacc.c:1646  */
    break;

  case 530:
#line 3472 "parser.y" /* yacc.c:1646  */
    {
      (yyval.ocla) = OmpClauseList((yyvsp[-2].ocla), (yyvsp[0].ocla));
    }
#line 7912 "parser.c" /* yacc.c:1646  */
    break;

  case 531:
#line 3479 "parser.y" /* yacc.c:1646  */
    {
      (yyval.ocla) = (yyvsp[0].ocla);
    }
#line 7920 "parser.c" /* yacc.c:1646  */
    break;

  case 532:
#line 3483 "parser.y" /* yacc.c:1646  */
    {
      (yyval.ocla) = (yyvsp[0].ocla);
    }
#line 7928 "parser.c" /* yacc.c:1646  */
    break;

  case 533:
#line 3487 "parser.y" /* yacc.c:1646  */
    {
      (yyval.ocla) = (yyvsp[0].ocla);
    }
#line 7936 "parser.c" /* yacc.c:1646  */
    break;

  case 534:
#line 3495 "parser.y" /* yacc.c:1646  */
    {
      //$$ = OmpConstruct(DCDISTPARFOR, $1, $2); TODO DCDISTPARFOR
      //$$->l = $1->l;
    }
#line 7945 "parser.c" /* yacc.c:1646  */
    break;

  case 535:
#line 3504 "parser.y" /* yacc.c:1646  */
    {
      //$$ = OmpDirective(DCDISTPARFOR, $5); TODO DCDISTPARFOR
    }
#line 7953 "parser.c" /* yacc.c:1646  */
    break;

  case 536:
#line 3511 "parser.y" /* yacc.c:1646  */
    {
      (yyval.ocla) = NULL;
    }
#line 7961 "parser.c" /* yacc.c:1646  */
    break;

  case 537:
#line 3515 "parser.y" /* yacc.c:1646  */
    {
      (yyval.ocla) = OmpClauseList((yyvsp[-1].ocla), (yyvsp[0].ocla));
    }
#line 7969 "parser.c" /* yacc.c:1646  */
    break;

  case 538:
#line 3519 "parser.y" /* yacc.c:1646  */
    {
      (yyval.ocla) = OmpClauseList((yyvsp[-2].ocla), (yyvsp[0].ocla));
    }
#line 7977 "parser.c" /* yacc.c:1646  */
    break;

  case 539:
#line 3526 "parser.y" /* yacc.c:1646  */
    {
      (yyval.ocla) = (yyvsp[0].ocla);
    }
#line 7985 "parser.c" /* yacc.c:1646  */
    break;

  case 540:
#line 3530 "parser.y" /* yacc.c:1646  */
    {
      (yyval.ocla) = (yyvsp[0].ocla);
    }
#line 7993 "parser.c" /* yacc.c:1646  */
    break;

  case 541:
#line 3538 "parser.y" /* yacc.c:1646  */
    {
      //$$ = OmpConstruct(DCDISTPARFORSIMD, $1, $2); TODO DCDISTPARFORSIMD
      //$$->l = $1->l;
    }
#line 8002 "parser.c" /* yacc.c:1646  */
    break;

  case 542:
#line 3547 "parser.y" /* yacc.c:1646  */
    {
      //$$ = OmpDirective(DCDISTPARFORSIMD, $6); TODO DCDISTPARFORSIMD
    }
#line 8010 "parser.c" /* yacc.c:1646  */
    break;

  case 543:
#line 3554 "parser.y" /* yacc.c:1646  */
    {
      (yyval.ocla) = NULL;
    }
#line 8018 "parser.c" /* yacc.c:1646  */
    break;

  case 544:
#line 3558 "parser.y" /* yacc.c:1646  */
    {
      (yyval.ocla) = OmpClauseList((yyvsp[-1].ocla), (yyvsp[0].ocla));
    }
#line 8026 "parser.c" /* yacc.c:1646  */
    break;

  case 545:
#line 3562 "parser.y" /* yacc.c:1646  */
    {
      (yyval.ocla) = OmpClauseList((yyvsp[-2].ocla), (yyvsp[0].ocla));
    }
#line 8034 "parser.c" /* yacc.c:1646  */
    break;

  case 546:
#line 3569 "parser.y" /* yacc.c:1646  */
    {
      (yyval.ocla) = (yyvsp[0].ocla);
    }
#line 8042 "parser.c" /* yacc.c:1646  */
    break;

  case 547:
#line 3573 "parser.y" /* yacc.c:1646  */
    {
      (yyval.ocla) = (yyvsp[0].ocla);
    }
#line 8050 "parser.c" /* yacc.c:1646  */
    break;

  case 548:
#line 3581 "parser.y" /* yacc.c:1646  */
    {
      //$$ = OmpConstruct(DCTARGETTEAMS, $1, $2); TODO DCTARGETTEAMS
    }
#line 8058 "parser.c" /* yacc.c:1646  */
    break;

  case 549:
#line 3589 "parser.y" /* yacc.c:1646  */
    {
      //$$ = OmpDirective(DCTARGETTEAMS, $4); TODO DCTARGETTEAMS
    }
#line 8066 "parser.c" /* yacc.c:1646  */
    break;

  case 550:
#line 3596 "parser.y" /* yacc.c:1646  */
    {
      (yyval.ocla) = NULL;
    }
#line 8074 "parser.c" /* yacc.c:1646  */
    break;

  case 551:
#line 3600 "parser.y" /* yacc.c:1646  */
    {
      (yyval.ocla) = OmpClauseList((yyvsp[-1].ocla), (yyvsp[0].ocla));
    }
#line 8082 "parser.c" /* yacc.c:1646  */
    break;

  case 552:
#line 3604 "parser.y" /* yacc.c:1646  */
    {
      (yyval.ocla) = OmpClauseList((yyvsp[-2].ocla), (yyvsp[0].ocla));
    }
#line 8090 "parser.c" /* yacc.c:1646  */
    break;

  case 553:
#line 3611 "parser.y" /* yacc.c:1646  */
    {
      (yyval.ocla) = (yyvsp[0].ocla);
    }
#line 8098 "parser.c" /* yacc.c:1646  */
    break;

  case 554:
#line 3615 "parser.y" /* yacc.c:1646  */
    {
      (yyval.ocla) = (yyvsp[0].ocla);
    }
#line 8106 "parser.c" /* yacc.c:1646  */
    break;

  case 555:
#line 3623 "parser.y" /* yacc.c:1646  */
    {
      //$$ = OmpConstruct(DCTEAMSDIST, $1, $2); TODO DCTEAMSDIST
    }
#line 8114 "parser.c" /* yacc.c:1646  */
    break;

  case 556:
#line 3631 "parser.y" /* yacc.c:1646  */
    {
      //$$ = OmpDirective(DCTEAMSDIST, $4); TODO DCTEAMSDIST
    }
#line 8122 "parser.c" /* yacc.c:1646  */
    break;

  case 557:
#line 3638 "parser.y" /* yacc.c:1646  */
    {
      (yyval.ocla) = NULL;
    }
#line 8130 "parser.c" /* yacc.c:1646  */
    break;

  case 558:
#line 3642 "parser.y" /* yacc.c:1646  */
    {
      (yyval.ocla) = OmpClauseList((yyvsp[-1].ocla), (yyvsp[0].ocla));
    }
#line 8138 "parser.c" /* yacc.c:1646  */
    break;

  case 559:
#line 3646 "parser.y" /* yacc.c:1646  */
    {
      (yyval.ocla) = OmpClauseList((yyvsp[-2].ocla), (yyvsp[0].ocla));
    }
#line 8146 "parser.c" /* yacc.c:1646  */
    break;

  case 560:
#line 3653 "parser.y" /* yacc.c:1646  */
    {
      (yyval.ocla) = (yyvsp[0].ocla);
    }
#line 8154 "parser.c" /* yacc.c:1646  */
    break;

  case 561:
#line 3657 "parser.y" /* yacc.c:1646  */
    {
      (yyval.ocla) = (yyvsp[0].ocla);
    }
#line 8162 "parser.c" /* yacc.c:1646  */
    break;

  case 562:
#line 3661 "parser.y" /* yacc.c:1646  */
    {
      (yyval.ocla) = (yyvsp[0].ocla);
    }
#line 8170 "parser.c" /* yacc.c:1646  */
    break;

  case 563:
#line 3669 "parser.y" /* yacc.c:1646  */
    {
      //$$ = OmpConstruct(DCTEAMSDISTSIMD, $1, $2); TODO DCTEAMSDISTSIMD
    }
#line 8178 "parser.c" /* yacc.c:1646  */
    break;

  case 564:
#line 3677 "parser.y" /* yacc.c:1646  */
    {
      //$$ = OmpDirective(DCTEAMSDISTSIMD, $5); TODO DCTEAMSDISTSIMD
    }
#line 8186 "parser.c" /* yacc.c:1646  */
    break;

  case 565:
#line 3684 "parser.y" /* yacc.c:1646  */
    {
      (yyval.ocla) = NULL;
    }
#line 8194 "parser.c" /* yacc.c:1646  */
    break;

  case 566:
#line 3688 "parser.y" /* yacc.c:1646  */
    {
      (yyval.ocla) = OmpClauseList((yyvsp[-1].ocla), (yyvsp[0].ocla));
    }
#line 8202 "parser.c" /* yacc.c:1646  */
    break;

  case 567:
#line 3692 "parser.y" /* yacc.c:1646  */
    {
      (yyval.ocla) = OmpClauseList((yyvsp[-2].ocla), (yyvsp[0].ocla));
    }
#line 8210 "parser.c" /* yacc.c:1646  */
    break;

  case 568:
#line 3699 "parser.y" /* yacc.c:1646  */
    {
      (yyval.ocla) = (yyvsp[0].ocla);
    }
#line 8218 "parser.c" /* yacc.c:1646  */
    break;

  case 569:
#line 3703 "parser.y" /* yacc.c:1646  */
    {
      (yyval.ocla) = (yyvsp[0].ocla);
    }
#line 8226 "parser.c" /* yacc.c:1646  */
    break;

  case 570:
#line 3707 "parser.y" /* yacc.c:1646  */
    {
      (yyval.ocla) = (yyvsp[0].ocla);
    }
#line 8234 "parser.c" /* yacc.c:1646  */
    break;

  case 571:
#line 3711 "parser.y" /* yacc.c:1646  */
    {
      (yyval.ocla) = (yyvsp[0].ocla);
    }
#line 8242 "parser.c" /* yacc.c:1646  */
    break;

  case 572:
#line 3719 "parser.y" /* yacc.c:1646  */
    {
      //$$ = OmpConstruct(DCTARGETTEAMSDIST, $1, $2); TODO DCTARGETTEAMSDIST
    }
#line 8250 "parser.c" /* yacc.c:1646  */
    break;

  case 573:
#line 3727 "parser.y" /* yacc.c:1646  */
    {
      //$$ = OmpDirective(DCTARGETTEAMSDIST, $5); TODO DCTARGETTEAMSDIST
    }
#line 8258 "parser.c" /* yacc.c:1646  */
    break;

  case 574:
#line 3734 "parser.y" /* yacc.c:1646  */
    {
      (yyval.ocla) = NULL;
    }
#line 8266 "parser.c" /* yacc.c:1646  */
    break;

  case 575:
#line 3738 "parser.y" /* yacc.c:1646  */
    {
      (yyval.ocla) = OmpClauseList((yyvsp[-1].ocla), (yyvsp[0].ocla));
    }
#line 8274 "parser.c" /* yacc.c:1646  */
    break;

  case 576:
#line 3742 "parser.y" /* yacc.c:1646  */
    {
      (yyval.ocla) = OmpClauseList((yyvsp[-2].ocla), (yyvsp[0].ocla));
    }
#line 8282 "parser.c" /* yacc.c:1646  */
    break;

  case 577:
#line 3749 "parser.y" /* yacc.c:1646  */
    {
      (yyval.ocla) = (yyvsp[0].ocla);
    }
#line 8290 "parser.c" /* yacc.c:1646  */
    break;

  case 578:
#line 3753 "parser.y" /* yacc.c:1646  */
    {
      (yyval.ocla) = (yyvsp[0].ocla);
    }
#line 8298 "parser.c" /* yacc.c:1646  */
    break;

  case 579:
#line 3761 "parser.y" /* yacc.c:1646  */
    {
      //$$ = OmpConstruct(DCTARGETTEAMSDISTSIMD, $1, $2); TODO DCTARGETTEAMSDISTSIMD
    }
#line 8306 "parser.c" /* yacc.c:1646  */
    break;

  case 580:
#line 3770 "parser.y" /* yacc.c:1646  */
    {
      //$$ = OmpDirective(DCTARGETTEAMSDISTSIMD, $6); TODO DCTARGETTEAMSDISTSIMD
    }
#line 8314 "parser.c" /* yacc.c:1646  */
    break;

  case 581:
#line 3777 "parser.y" /* yacc.c:1646  */
    {
      (yyval.ocla) = NULL;
    }
#line 8322 "parser.c" /* yacc.c:1646  */
    break;

  case 582:
#line 3782 "parser.y" /* yacc.c:1646  */
    {
      (yyval.ocla) = OmpClauseList((yyvsp[-1].ocla), (yyvsp[0].ocla));
    }
#line 8330 "parser.c" /* yacc.c:1646  */
    break;

  case 583:
#line 3787 "parser.y" /* yacc.c:1646  */
    {
      (yyval.ocla) = OmpClauseList((yyvsp[-2].ocla), (yyvsp[0].ocla));
    }
#line 8338 "parser.c" /* yacc.c:1646  */
    break;

  case 584:
#line 3794 "parser.y" /* yacc.c:1646  */
    {
      (yyval.ocla) = (yyvsp[0].ocla);
    }
#line 8346 "parser.c" /* yacc.c:1646  */
    break;

  case 585:
#line 3798 "parser.y" /* yacc.c:1646  */
    {
      (yyval.ocla) = (yyvsp[0].ocla);
    }
#line 8354 "parser.c" /* yacc.c:1646  */
    break;

  case 586:
#line 3806 "parser.y" /* yacc.c:1646  */
    {
      //$$ = OmpConstruct(DCTEAMSDISTPARFOR, $1, $2); TODO DCTEAMSDISTPARFOR
      //$$->l = $1->l;
    }
#line 8363 "parser.c" /* yacc.c:1646  */
    break;

  case 587:
#line 3816 "parser.y" /* yacc.c:1646  */
    {
      //$$ = OmpDirective(DCTEAMSDISTPARFOR, $3); TODO DCTEAMSDISTPARFOR
    }
#line 8371 "parser.c" /* yacc.c:1646  */
    break;

  case 588:
#line 3823 "parser.y" /* yacc.c:1646  */
    {
      (yyval.ocla) = NULL;
    }
#line 8379 "parser.c" /* yacc.c:1646  */
    break;

  case 589:
#line 3828 "parser.y" /* yacc.c:1646  */
    {
      (yyval.ocla) = OmpClauseList((yyvsp[-1].ocla), (yyvsp[0].ocla));
    }
#line 8387 "parser.c" /* yacc.c:1646  */
    break;

  case 590:
#line 3833 "parser.y" /* yacc.c:1646  */
    {
      (yyval.ocla) = OmpClauseList((yyvsp[-2].ocla), (yyvsp[0].ocla));
    }
#line 8395 "parser.c" /* yacc.c:1646  */
    break;

  case 591:
#line 3840 "parser.y" /* yacc.c:1646  */
    {
      (yyval.ocla) = (yyvsp[0].ocla);
    }
#line 8403 "parser.c" /* yacc.c:1646  */
    break;

  case 592:
#line 3844 "parser.y" /* yacc.c:1646  */
    {
      (yyval.ocla) = (yyvsp[0].ocla);
    }
#line 8411 "parser.c" /* yacc.c:1646  */
    break;

  case 593:
#line 3852 "parser.y" /* yacc.c:1646  */
    {
      //$$ = OmpConstruct(DCTARGETTEAMSDISTPARFOR, $1, $2); TODO DCTARGETTEAMSDISTPARFOR
      //$$->l = $1->l;
    }
#line 8420 "parser.c" /* yacc.c:1646  */
    break;

  case 594:
#line 3861 "parser.y" /* yacc.c:1646  */
    {
      //$$ = OmpDirective(DCTARGETTEAMSDISTPARFOR, $7); TODO DCTARGETTEAMSDISTPARFOR
    }
#line 8428 "parser.c" /* yacc.c:1646  */
    break;

  case 595:
#line 3868 "parser.y" /* yacc.c:1646  */
    {
      (yyval.ocla) = NULL;
    }
#line 8436 "parser.c" /* yacc.c:1646  */
    break;

  case 596:
#line 3872 "parser.y" /* yacc.c:1646  */
    {
      (yyval.ocla) = OmpClauseList((yyvsp[-1].ocla), (yyvsp[0].ocla));
    }
#line 8444 "parser.c" /* yacc.c:1646  */
    break;

  case 597:
#line 3876 "parser.y" /* yacc.c:1646  */
    {
      (yyval.ocla) = OmpClauseList((yyvsp[-2].ocla), (yyvsp[0].ocla));
    }
#line 8452 "parser.c" /* yacc.c:1646  */
    break;

  case 598:
#line 3883 "parser.y" /* yacc.c:1646  */
    {
      (yyval.ocla) = (yyvsp[0].ocla);
    }
#line 8460 "parser.c" /* yacc.c:1646  */
    break;

  case 599:
#line 3887 "parser.y" /* yacc.c:1646  */
    {
      (yyval.ocla) = (yyvsp[0].ocla);
    }
#line 8468 "parser.c" /* yacc.c:1646  */
    break;

  case 600:
#line 3895 "parser.y" /* yacc.c:1646  */
    {
      //$$ = OmpConstruct(DCTEAMSDISTPARFORSIMD, $1, $2); TODO DCTEAMSDISTPARFORSIMD
      //$$->l = $1->l;
    }
#line 8477 "parser.c" /* yacc.c:1646  */
    break;

  case 601:
#line 3904 "parser.y" /* yacc.c:1646  */
    {
      //$$ = OmpDirective(DCTEAMSDISTPARFORSIMD, $7); TODO DCTEAMSDISTPARFORSIMD
    }
#line 8485 "parser.c" /* yacc.c:1646  */
    break;

  case 602:
#line 3911 "parser.y" /* yacc.c:1646  */
    {
      (yyval.ocla) = NULL;
    }
#line 8493 "parser.c" /* yacc.c:1646  */
    break;

  case 603:
#line 3915 "parser.y" /* yacc.c:1646  */
    {
      (yyval.ocla) = OmpClauseList((yyvsp[-1].ocla), (yyvsp[0].ocla));
    }
#line 8501 "parser.c" /* yacc.c:1646  */
    break;

  case 604:
#line 3919 "parser.y" /* yacc.c:1646  */
    {
      (yyval.ocla) = OmpClauseList((yyvsp[-2].ocla), (yyvsp[0].ocla));
    }
#line 8509 "parser.c" /* yacc.c:1646  */
    break;

  case 605:
#line 3926 "parser.y" /* yacc.c:1646  */
    {
      (yyval.ocla) = (yyvsp[0].ocla);
    }
#line 8517 "parser.c" /* yacc.c:1646  */
    break;

  case 606:
#line 3930 "parser.y" /* yacc.c:1646  */
    {
      (yyval.ocla) = (yyvsp[0].ocla);
    }
#line 8525 "parser.c" /* yacc.c:1646  */
    break;

  case 607:
#line 3938 "parser.y" /* yacc.c:1646  */
    {
      //$$ = OmpConstruct(DCTARGETTEAMSDISTPARFORSIMD, $1, $2); TODO DCTARGETTEAMSDISTPARFORSIMD
      //$$->l = $1->l;
    }
#line 8534 "parser.c" /* yacc.c:1646  */
    break;

  case 608:
#line 3947 "parser.y" /* yacc.c:1646  */
    {
      //$$ = OmpDirective(DCTARGETTEAMSDISTPARFORSIMD, $8); TODO DCTARGETTEAMSDISTPARFORSIMD
    }
#line 8542 "parser.c" /* yacc.c:1646  */
    break;

  case 609:
#line 3954 "parser.y" /* yacc.c:1646  */
    {
      (yyval.ocla) = NULL;
    }
#line 8550 "parser.c" /* yacc.c:1646  */
    break;

  case 610:
#line 3958 "parser.y" /* yacc.c:1646  */
    {
      (yyval.ocla) = OmpClauseList((yyvsp[-1].ocla), (yyvsp[0].ocla));
    }
#line 8558 "parser.c" /* yacc.c:1646  */
    break;

  case 611:
#line 3962 "parser.y" /* yacc.c:1646  */
    {
      (yyval.ocla) = OmpClauseList((yyvsp[-2].ocla), (yyvsp[0].ocla));
    }
#line 8566 "parser.c" /* yacc.c:1646  */
    break;

  case 612:
#line 3969 "parser.y" /* yacc.c:1646  */
    {
      (yyval.ocla) = (yyvsp[0].ocla);
    }
#line 8574 "parser.c" /* yacc.c:1646  */
    break;

  case 613:
#line 3973 "parser.y" /* yacc.c:1646  */
    {
      (yyval.ocla) = (yyvsp[0].ocla);
    }
#line 8582 "parser.c" /* yacc.c:1646  */
    break;

  case 614:
#line 3981 "parser.y" /* yacc.c:1646  */
    {
      (yyval.ocon) = OmpConstruct(DCTASK, (yyvsp[-1].odir), (yyvsp[0].stmt));
      (yyval.ocon)->l = (yyvsp[-1].odir)->l;
    }
#line 8591 "parser.c" /* yacc.c:1646  */
    break;

  case 615:
#line 3990 "parser.y" /* yacc.c:1646  */
    {
      (yyval.odir) = OmpDirective(DCTASK, (yyvsp[-1].ocla));
    }
#line 8599 "parser.c" /* yacc.c:1646  */
    break;

  case 616:
#line 3998 "parser.y" /* yacc.c:1646  */
    {
      (yyval.ocla) = NULL;
    }
#line 8607 "parser.c" /* yacc.c:1646  */
    break;

  case 617:
#line 4002 "parser.y" /* yacc.c:1646  */
    {
      (yyval.ocla) = OmpClauseList((yyvsp[-1].ocla), (yyvsp[0].ocla));
    }
#line 8615 "parser.c" /* yacc.c:1646  */
    break;

  case 618:
#line 4006 "parser.y" /* yacc.c:1646  */
    {
      (yyval.ocla) = OmpClauseList((yyvsp[-2].ocla), (yyvsp[0].ocla));
    }
#line 8623 "parser.c" /* yacc.c:1646  */
    break;

  case 619:
#line 4014 "parser.y" /* yacc.c:1646  */
    {
      (yyval.ocla) = (yyvsp[0].ocla);
    }
#line 8631 "parser.c" /* yacc.c:1646  */
    break;

  case 620:
#line 4018 "parser.y" /* yacc.c:1646  */
    {
      (yyval.ocla) = (yyvsp[0].ocla);
    }
#line 8639 "parser.c" /* yacc.c:1646  */
    break;

  case 621:
#line 4022 "parser.y" /* yacc.c:1646  */
    {
      (yyval.ocla) = (yyvsp[0].ocla);
    }
#line 8647 "parser.c" /* yacc.c:1646  */
    break;

  case 622:
#line 4026 "parser.y" /* yacc.c:1646  */
    {
      (yyval.ocla) = (yyvsp[0].ocla);
    }
#line 8655 "parser.c" /* yacc.c:1646  */
    break;

  case 623:
#line 4030 "parser.y" /* yacc.c:1646  */
    {
      (yyval.ocla) = (yyvsp[0].ocla);
    }
#line 8663 "parser.c" /* yacc.c:1646  */
    break;

  case 624:
#line 4038 "parser.y" /* yacc.c:1646  */
    {
      (yyval.ocla) = (yyvsp[0].ocla);
    }
#line 8671 "parser.c" /* yacc.c:1646  */
    break;

  case 625:
#line 4041 "parser.y" /* yacc.c:1646  */
    { sc_pause_openmp(); }
#line 8677 "parser.c" /* yacc.c:1646  */
    break;

  case 626:
#line 4042 "parser.y" /* yacc.c:1646  */
    {
      sc_start_openmp();
      (yyval.ocla) = FinalClause((yyvsp[-1].expr));
    }
#line 8686 "parser.c" /* yacc.c:1646  */
    break;

  case 627:
#line 4047 "parser.y" /* yacc.c:1646  */
    {
      (yyval.ocla) = PlainClause(OCUNTIED);
    }
#line 8694 "parser.c" /* yacc.c:1646  */
    break;

  case 628:
#line 4051 "parser.y" /* yacc.c:1646  */
    {
      (yyval.ocla) = PlainClause(OCMERGEABLE);
    }
#line 8702 "parser.c" /* yacc.c:1646  */
    break;

  case 629:
#line 4056 "parser.y" /* yacc.c:1646  */
    {
      //$$ = VarlistClause(OCPRIVATE, $6); TODO find out how to do this. It needs type OCDEPEND subtype from $3 and a list from $6
    }
#line 8710 "parser.c" /* yacc.c:1646  */
    break;

  case 630:
#line 4064 "parser.y" /* yacc.c:1646  */
    {
      //$$ = OC_in; TODO OC_in
    }
#line 8718 "parser.c" /* yacc.c:1646  */
    break;

  case 631:
#line 4068 "parser.y" /* yacc.c:1646  */
    {
      //$$ = OC_out; TODO OC_out
    }
#line 8726 "parser.c" /* yacc.c:1646  */
    break;

  case 632:
#line 4072 "parser.y" /* yacc.c:1646  */
    {
      //$$ = OC_inout; TODO OC_inout
    }
#line 8734 "parser.c" /* yacc.c:1646  */
    break;

  case 633:
#line 4079 "parser.y" /* yacc.c:1646  */
    {
      (yyval.ocon) = OmpConstruct(DCPARFOR, (yyvsp[-1].odir), (yyvsp[0].stmt));
      (yyval.ocon)->l = (yyvsp[-1].odir)->l;
    }
#line 8743 "parser.c" /* yacc.c:1646  */
    break;

  case 634:
#line 4087 "parser.y" /* yacc.c:1646  */
    {
      (yyval.odir) = OmpDirective(DCPARFOR, (yyvsp[-1].ocla));
    }
#line 8751 "parser.c" /* yacc.c:1646  */
    break;

  case 635:
#line 4094 "parser.y" /* yacc.c:1646  */
    {
      (yyval.ocla) = NULL;
    }
#line 8759 "parser.c" /* yacc.c:1646  */
    break;

  case 636:
#line 4098 "parser.y" /* yacc.c:1646  */
    {
      (yyval.ocla) = OmpClauseList((yyvsp[-1].ocla), (yyvsp[0].ocla));
    }
#line 8767 "parser.c" /* yacc.c:1646  */
    break;

  case 637:
#line 4102 "parser.y" /* yacc.c:1646  */
    {
      (yyval.ocla) = OmpClauseList((yyvsp[-2].ocla), (yyvsp[0].ocla));
    }
#line 8775 "parser.c" /* yacc.c:1646  */
    break;

  case 638:
#line 4109 "parser.y" /* yacc.c:1646  */
    {
      (yyval.ocla) = (yyvsp[0].ocla);
    }
#line 8783 "parser.c" /* yacc.c:1646  */
    break;

  case 639:
#line 4113 "parser.y" /* yacc.c:1646  */
    {
      (yyval.ocla) = (yyvsp[0].ocla);
    }
#line 8791 "parser.c" /* yacc.c:1646  */
    break;

  case 640:
#line 4117 "parser.y" /* yacc.c:1646  */
    {
      (yyval.ocla) = (yyvsp[0].ocla);
    }
#line 8799 "parser.c" /* yacc.c:1646  */
    break;

  case 641:
#line 4121 "parser.y" /* yacc.c:1646  */
    {
      (yyval.ocla) = (yyvsp[0].ocla);
    }
#line 8807 "parser.c" /* yacc.c:1646  */
    break;

  case 642:
#line 4125 "parser.y" /* yacc.c:1646  */
    {
      (yyval.ocla) = (yyvsp[0].ocla);
    }
#line 8815 "parser.c" /* yacc.c:1646  */
    break;

  case 643:
#line 4129 "parser.y" /* yacc.c:1646  */
    {
      (yyval.ocla) = (yyvsp[0].ocla);
    }
#line 8823 "parser.c" /* yacc.c:1646  */
    break;

  case 644:
#line 4133 "parser.y" /* yacc.c:1646  */
    {
      (yyval.ocla) = (yyvsp[0].ocla);
    }
#line 8831 "parser.c" /* yacc.c:1646  */
    break;

  case 645:
#line 4137 "parser.y" /* yacc.c:1646  */
    {
      (yyval.ocla) = (yyvsp[0].ocla);
    }
#line 8839 "parser.c" /* yacc.c:1646  */
    break;

  case 646:
#line 4144 "parser.y" /* yacc.c:1646  */
    {
      (yyval.ocon) = OmpConstruct(DCPARSECTIONS, (yyvsp[-1].odir), (yyvsp[0].stmt));
      (yyval.ocon)->l = (yyvsp[-1].odir)->l;
    }
#line 8848 "parser.c" /* yacc.c:1646  */
    break;

  case 647:
#line 4152 "parser.y" /* yacc.c:1646  */
    {
      (yyval.odir) = OmpDirective(DCPARSECTIONS, (yyvsp[-1].ocla));
    }
#line 8856 "parser.c" /* yacc.c:1646  */
    break;

  case 648:
#line 4159 "parser.y" /* yacc.c:1646  */
    {
      (yyval.ocla) = NULL;
    }
#line 8864 "parser.c" /* yacc.c:1646  */
    break;

  case 649:
#line 4163 "parser.y" /* yacc.c:1646  */
    {
      (yyval.ocla) = OmpClauseList((yyvsp[-1].ocla), (yyvsp[0].ocla));
    }
#line 8872 "parser.c" /* yacc.c:1646  */
    break;

  case 650:
#line 4167 "parser.y" /* yacc.c:1646  */
    {
      (yyval.ocla) = OmpClauseList((yyvsp[-2].ocla), (yyvsp[0].ocla));
    }
#line 8880 "parser.c" /* yacc.c:1646  */
    break;

  case 651:
#line 4174 "parser.y" /* yacc.c:1646  */
    {
      (yyval.ocla) = (yyvsp[0].ocla);
    }
#line 8888 "parser.c" /* yacc.c:1646  */
    break;

  case 652:
#line 4178 "parser.y" /* yacc.c:1646  */
    {
      (yyval.ocla) = (yyvsp[0].ocla);
    }
#line 8896 "parser.c" /* yacc.c:1646  */
    break;

  case 653:
#line 4182 "parser.y" /* yacc.c:1646  */
    {
      (yyval.ocla) = (yyvsp[0].ocla);
    }
#line 8904 "parser.c" /* yacc.c:1646  */
    break;

  case 654:
#line 4186 "parser.y" /* yacc.c:1646  */
    {
      (yyval.ocla) = (yyvsp[0].ocla);
    }
#line 8912 "parser.c" /* yacc.c:1646  */
    break;

  case 655:
#line 4190 "parser.y" /* yacc.c:1646  */
    {
      (yyval.ocla) = (yyvsp[0].ocla);
    }
#line 8920 "parser.c" /* yacc.c:1646  */
    break;

  case 656:
#line 4194 "parser.y" /* yacc.c:1646  */
    {
      (yyval.ocla) = (yyvsp[0].ocla);
    }
#line 8928 "parser.c" /* yacc.c:1646  */
    break;

  case 657:
#line 4198 "parser.y" /* yacc.c:1646  */
    {
      (yyval.ocla) = (yyvsp[0].ocla);
    }
#line 8936 "parser.c" /* yacc.c:1646  */
    break;

  case 658:
#line 4205 "parser.y" /* yacc.c:1646  */
    {
      (yyval.ocon) = OmpConstruct(DCMASTER, (yyvsp[-1].odir), (yyvsp[0].stmt));
    }
#line 8944 "parser.c" /* yacc.c:1646  */
    break;

  case 659:
#line 4212 "parser.y" /* yacc.c:1646  */
    {
      (yyval.odir) = OmpDirective(DCMASTER, NULL);
    }
#line 8952 "parser.c" /* yacc.c:1646  */
    break;

  case 660:
#line 4219 "parser.y" /* yacc.c:1646  */
    {
      (yyval.ocon) = OmpConstruct(DCCRITICAL, (yyvsp[-1].odir), (yyvsp[0].stmt));
    }
#line 8960 "parser.c" /* yacc.c:1646  */
    break;

  case 661:
#line 4226 "parser.y" /* yacc.c:1646  */
    {
      (yyval.odir) = OmpCriticalDirective(NULL);
    }
#line 8968 "parser.c" /* yacc.c:1646  */
    break;

  case 662:
#line 4230 "parser.y" /* yacc.c:1646  */
    {
      (yyval.odir) = OmpCriticalDirective((yyvsp[-1].symb));
    }
#line 8976 "parser.c" /* yacc.c:1646  */
    break;

  case 663:
#line 4237 "parser.y" /* yacc.c:1646  */
    {
      (yyval.symb) = Symbol((yyvsp[-1].name));
    }
#line 8984 "parser.c" /* yacc.c:1646  */
    break;

  case 664:
#line 4244 "parser.y" /* yacc.c:1646  */
    {
      (yyval.odir) = OmpDirective(DCBARRIER, NULL);
    }
#line 8992 "parser.c" /* yacc.c:1646  */
    break;

  case 665:
#line 4252 "parser.y" /* yacc.c:1646  */
    {
      (yyval.odir) = OmpDirective(DCTASKWAIT, NULL);
    }
#line 9000 "parser.c" /* yacc.c:1646  */
    break;

  case 666:
#line 4260 "parser.y" /* yacc.c:1646  */
    {
      (yyval.ocon) = OmpConstruct(DCTASKGROUP, (yyvsp[-1].odir), (yyvsp[0].stmt));
    }
#line 9008 "parser.c" /* yacc.c:1646  */
    break;

  case 667:
#line 4268 "parser.y" /* yacc.c:1646  */
    {
      (yyval.odir) = OmpDirective(DCTASKGROUP, NULL);
    }
#line 9016 "parser.c" /* yacc.c:1646  */
    break;

  case 668:
#line 4276 "parser.y" /* yacc.c:1646  */
    {
      (yyval.odir) = OmpDirective(DCTASKYIELD, NULL);
    }
#line 9024 "parser.c" /* yacc.c:1646  */
    break;

  case 669:
#line 4283 "parser.y" /* yacc.c:1646  */
    {
      (yyval.ocon) = OmpConstruct(DCATOMIC, (yyvsp[-1].odir), (yyvsp[0].stmt));
    }
#line 9032 "parser.c" /* yacc.c:1646  */
    break;

  case 670:
#line 4294 "parser.y" /* yacc.c:1646  */
    {
      (yyval.odir) = OmpDirective(DCATOMIC, NULL);  //TODO Check how to do it since it now has 2 clauses
    }
#line 9040 "parser.c" /* yacc.c:1646  */
    break;

  case 671:
#line 4301 "parser.y" /* yacc.c:1646  */
    {
      (yyval.ocla) = NULL;
    }
#line 9048 "parser.c" /* yacc.c:1646  */
    break;

  case 672:
#line 4305 "parser.y" /* yacc.c:1646  */
    {
      //$$ = TODO
    }
#line 9056 "parser.c" /* yacc.c:1646  */
    break;

  case 673:
#line 4309 "parser.y" /* yacc.c:1646  */
    {
      //$$ = TODO
    }
#line 9064 "parser.c" /* yacc.c:1646  */
    break;

  case 674:
#line 4313 "parser.y" /* yacc.c:1646  */
    {
      //$$ = TODO
    }
#line 9072 "parser.c" /* yacc.c:1646  */
    break;

  case 675:
#line 4317 "parser.y" /* yacc.c:1646  */
    {
      //$$ = TODO
    }
#line 9080 "parser.c" /* yacc.c:1646  */
    break;

  case 676:
#line 4325 "parser.y" /* yacc.c:1646  */
    {
      (yyval.ocla) = NULL;
    }
#line 9088 "parser.c" /* yacc.c:1646  */
    break;

  case 677:
#line 4329 "parser.y" /* yacc.c:1646  */
    {
      //$$ = TODO
    }
#line 9096 "parser.c" /* yacc.c:1646  */
    break;

  case 678:
#line 4336 "parser.y" /* yacc.c:1646  */
    {
      (yyval.odir) = OmpFlushDirective(NULL);
    }
#line 9104 "parser.c" /* yacc.c:1646  */
    break;

  case 679:
#line 4340 "parser.y" /* yacc.c:1646  */
    {
      (yyval.odir) = OmpFlushDirective((yyvsp[-1].decl));
    }
#line 9112 "parser.c" /* yacc.c:1646  */
    break;

  case 680:
#line 4346 "parser.y" /* yacc.c:1646  */
    { sc_pause_openmp(); }
#line 9118 "parser.c" /* yacc.c:1646  */
    break;

  case 681:
#line 4347 "parser.y" /* yacc.c:1646  */
    {
      sc_start_openmp();
      (yyval.decl) = (yyvsp[-1].decl);
    }
#line 9127 "parser.c" /* yacc.c:1646  */
    break;

  case 682:
#line 4355 "parser.y" /* yacc.c:1646  */
    {
      (yyval.ocon) = OmpConstruct(DCORDERED, (yyvsp[-1].odir), (yyvsp[0].stmt));
    }
#line 9135 "parser.c" /* yacc.c:1646  */
    break;

  case 683:
#line 4362 "parser.y" /* yacc.c:1646  */
    {
      (yyval.odir) = OmpDirective(DCORDERED, NULL);
    }
#line 9143 "parser.c" /* yacc.c:1646  */
    break;

  case 684:
#line 4370 "parser.y" /* yacc.c:1646  */
    {
      (yyval.odir) = OmpDirective(DCCANCEL, (yyvsp[-1].ocla));
    }
#line 9151 "parser.c" /* yacc.c:1646  */
    break;

  case 685:
#line 4374 "parser.y" /* yacc.c:1646  */
    {
      (yyval.odir) = OmpDirective(DCCANCEL, OmpClauseList((yyvsp[-2].ocla), (yyvsp[-1].ocla)));
    }
#line 9159 "parser.c" /* yacc.c:1646  */
    break;

  case 686:
#line 4378 "parser.y" /* yacc.c:1646  */
    {
      (yyval.odir) = OmpDirective(DCCANCEL, OmpClauseList((yyvsp[-3].ocla), (yyvsp[-1].ocla)));
    }
#line 9167 "parser.c" /* yacc.c:1646  */
    break;

  case 687:
#line 4385 "parser.y" /* yacc.c:1646  */
    {
      (yyval.ocla) = PlainClause(OCPARALLEL);
    }
#line 9175 "parser.c" /* yacc.c:1646  */
    break;

  case 688:
#line 4389 "parser.y" /* yacc.c:1646  */
    {
      (yyval.ocla) = PlainClause(OCSECTIONS);
    }
#line 9183 "parser.c" /* yacc.c:1646  */
    break;

  case 689:
#line 4393 "parser.y" /* yacc.c:1646  */
    {
      (yyval.ocla) = PlainClause(OCFOR);
    }
#line 9191 "parser.c" /* yacc.c:1646  */
    break;

  case 690:
#line 4397 "parser.y" /* yacc.c:1646  */
    {
      (yyval.ocla) = PlainClause(OCTASKGROUP);
    }
#line 9199 "parser.c" /* yacc.c:1646  */
    break;

  case 691:
#line 4405 "parser.y" /* yacc.c:1646  */
    {
      (yyval.odir) = OmpDirective(DCCANCELLATIONPOINT, (yyvsp[-1].ocla));
    }
#line 9207 "parser.c" /* yacc.c:1646  */
    break;

  case 692:
#line 4411 "parser.y" /* yacc.c:1646  */
    { sc_pause_openmp(); }
#line 9213 "parser.c" /* yacc.c:1646  */
    break;

  case 693:
#line 4411 "parser.y" /* yacc.c:1646  */
    { sc_start_openmp(); }
#line 9219 "parser.c" /* yacc.c:1646  */
    break;

  case 694:
#line 4412 "parser.y" /* yacc.c:1646  */
    {
      (yyval.odir) = OmpThreadprivateDirective((yyvsp[-3].decl));
    }
#line 9227 "parser.c" /* yacc.c:1646  */
    break;

  case 695:
#line 4419 "parser.y" /* yacc.c:1646  */
    { sc_pause_openmp(); }
#line 9233 "parser.c" /* yacc.c:1646  */
    break;

  case 696:
#line 4419 "parser.y" /* yacc.c:1646  */
    { sc_start_openmp(); }
#line 9239 "parser.c" /* yacc.c:1646  */
    break;

  case 697:
#line 4420 "parser.y" /* yacc.c:1646  */
    {
      //$$ = TODO
    }
#line 9247 "parser.c" /* yacc.c:1646  */
    break;

  case 698:
#line 4427 "parser.y" /* yacc.c:1646  */
    {
      //$$ = OC_identifier TODO
      //Symbol($2);  TODO
    }
#line 9256 "parser.c" /* yacc.c:1646  */
    break;

  case 699:
#line 4432 "parser.y" /* yacc.c:1646  */
    {
      (yyval.type) = OC_plus;
    }
#line 9264 "parser.c" /* yacc.c:1646  */
    break;

  case 700:
#line 4436 "parser.y" /* yacc.c:1646  */
    {
      (yyval.type) = OC_times;
    }
#line 9272 "parser.c" /* yacc.c:1646  */
    break;

  case 701:
#line 4440 "parser.y" /* yacc.c:1646  */
    {
      (yyval.type) = OC_minus;
    }
#line 9280 "parser.c" /* yacc.c:1646  */
    break;

  case 702:
#line 4444 "parser.y" /* yacc.c:1646  */
    {
      (yyval.type) = OC_band;
    }
#line 9288 "parser.c" /* yacc.c:1646  */
    break;

  case 703:
#line 4448 "parser.y" /* yacc.c:1646  */
    {
      (yyval.type) = OC_xor;
    }
#line 9296 "parser.c" /* yacc.c:1646  */
    break;

  case 704:
#line 4452 "parser.y" /* yacc.c:1646  */
    {
      (yyval.type) = OC_bor;
    }
#line 9304 "parser.c" /* yacc.c:1646  */
    break;

  case 705:
#line 4456 "parser.y" /* yacc.c:1646  */
    {
      (yyval.type) = OC_land;
    }
#line 9312 "parser.c" /* yacc.c:1646  */
    break;

  case 706:
#line 4460 "parser.y" /* yacc.c:1646  */
    {
      (yyval.type) = OC_lor;
    }
#line 9320 "parser.c" /* yacc.c:1646  */
    break;

  case 707:
#line 4464 "parser.y" /* yacc.c:1646  */
    {
      (yyval.type) = OC_min;
    }
#line 9328 "parser.c" /* yacc.c:1646  */
    break;

  case 708:
#line 4468 "parser.y" /* yacc.c:1646  */
    {
      (yyval.type) = OC_max;
    }
#line 9336 "parser.c" /* yacc.c:1646  */
    break;

  case 709:
#line 4475 "parser.y" /* yacc.c:1646  */
    {
      //TODO
    }
#line 9344 "parser.c" /* yacc.c:1646  */
    break;

  case 710:
#line 4479 "parser.y" /* yacc.c:1646  */
    {
      //TODO
    }
#line 9352 "parser.c" /* yacc.c:1646  */
    break;

  case 711:
#line 4486 "parser.y" /* yacc.c:1646  */
    {
      (yyval.ocla) = NULL;
    }
#line 9360 "parser.c" /* yacc.c:1646  */
    break;

  case 712:
#line 4490 "parser.y" /* yacc.c:1646  */
    {
        //TODO must check if identifier is omp_priv and that conditional
        //expression contains only omp_priv and omp_orig variables
    }
#line 9369 "parser.c" /* yacc.c:1646  */
    break;

  case 713:
#line 4495 "parser.y" /* yacc.c:1646  */
    {
      //TODO in argument_expression_list one of the variables must be &omp_priv
      // TODO check ox_funccall_expression
      //$$ = strcmp($1, "main") ?
      //       FunctionCall(IdentName($1), $3) :
      //       FunctionCall(IdentName(MAIN_NEWNAME), $3);
    }
#line 9381 "parser.c" /* yacc.c:1646  */
    break;

  case 714:
#line 4506 "parser.y" /* yacc.c:1646  */
    {
      (yyval.ocla) = DefaultClause(OC_defshared);
    }
#line 9389 "parser.c" /* yacc.c:1646  */
    break;

  case 715:
#line 4510 "parser.y" /* yacc.c:1646  */
    {
      (yyval.ocla) = DefaultClause(OC_defnone);
    }
#line 9397 "parser.c" /* yacc.c:1646  */
    break;

  case 716:
#line 4515 "parser.y" /* yacc.c:1646  */
    {
      (yyval.ocla) = DefaultClause(OC_auto); //I'm using the existing subtype (Alexandros)
    }
#line 9405 "parser.c" /* yacc.c:1646  */
    break;

  case 717:
#line 4521 "parser.y" /* yacc.c:1646  */
    { sc_pause_openmp(); }
#line 9411 "parser.c" /* yacc.c:1646  */
    break;

  case 718:
#line 4522 "parser.y" /* yacc.c:1646  */
    {
      sc_start_openmp();
      (yyval.ocla) = VarlistClause(OCPRIVATE, (yyvsp[-1].decl));
    }
#line 9420 "parser.c" /* yacc.c:1646  */
    break;

  case 719:
#line 4529 "parser.y" /* yacc.c:1646  */
    { sc_pause_openmp(); }
#line 9426 "parser.c" /* yacc.c:1646  */
    break;

  case 720:
#line 4530 "parser.y" /* yacc.c:1646  */
    {
      sc_start_openmp();
      (yyval.ocla) = VarlistClause(OCFIRSTPRIVATE, (yyvsp[-1].decl));
    }
#line 9435 "parser.c" /* yacc.c:1646  */
    break;

  case 721:
#line 4537 "parser.y" /* yacc.c:1646  */
    { sc_pause_openmp(); }
#line 9441 "parser.c" /* yacc.c:1646  */
    break;

  case 722:
#line 4538 "parser.y" /* yacc.c:1646  */
    {
      sc_start_openmp();
      (yyval.ocla) = VarlistClause(OCLASTPRIVATE, (yyvsp[-1].decl));
    }
#line 9450 "parser.c" /* yacc.c:1646  */
    break;

  case 723:
#line 4545 "parser.y" /* yacc.c:1646  */
    { sc_pause_openmp(); }
#line 9456 "parser.c" /* yacc.c:1646  */
    break;

  case 724:
#line 4546 "parser.y" /* yacc.c:1646  */
    {
      sc_start_openmp();
      (yyval.ocla) = VarlistClause(OCSHARED, (yyvsp[-1].decl));
    }
#line 9465 "parser.c" /* yacc.c:1646  */
    break;

  case 725:
#line 4553 "parser.y" /* yacc.c:1646  */
    { sc_pause_openmp(); }
#line 9471 "parser.c" /* yacc.c:1646  */
    break;

  case 726:
#line 4554 "parser.y" /* yacc.c:1646  */
    {
      sc_start_openmp();
      (yyval.ocla) = ReductionClause((yyvsp[-4].type), (yyvsp[-1].decl));
    }
#line 9480 "parser.c" /* yacc.c:1646  */
    break;

  case 727:
#line 4561 "parser.y" /* yacc.c:1646  */
    { sc_pause_openmp(); }
#line 9486 "parser.c" /* yacc.c:1646  */
    break;

  case 728:
#line 4562 "parser.y" /* yacc.c:1646  */
    {
      sc_start_openmp();
      (yyval.ocla) = IfClause((yyvsp[-1].expr));
    }
#line 9495 "parser.c" /* yacc.c:1646  */
    break;

  case 729:
#line 4570 "parser.y" /* yacc.c:1646  */
    {
      int n = 0, er = 0;
      if (xar_expr_is_constant((yyvsp[-1].expr)))
      {
        n = xar_calc_int_expr((yyvsp[-1].expr), &er);
        if (er) n = 0;
      }
      if (n <= 0)
        parse_error(1, "invalid number in collapse() clause.\n");
      (yyval.ocla) = CollapseClause(n);
    }
#line 9511 "parser.c" /* yacc.c:1646  */
    break;

  case 730:
#line 4585 "parser.y" /* yacc.c:1646  */
    {
      if (checkDecls)
        if (symtab_get(stab, Symbol((yyvsp[-1].name)), IDNAME) == NULL)
          parse_error(-1, "unknown identifier `%s'.\n", (yyvsp[-1].name));
      (yyval.decl) = IdentifierDecl( Symbol((yyvsp[-1].name)) );
      parse_warning("Array section not supported yet. Ignored.\n");
    }
#line 9523 "parser.c" /* yacc.c:1646  */
    break;

  case 731:
#line 4596 "parser.y" /* yacc.c:1646  */
    {
      if (checkDecls)
        if (symtab_get(stab, Symbol((yyvsp[0].name)), IDNAME) == NULL)
          parse_error(-1, "unknown identifier `%s'.\n", (yyvsp[0].name));
      (yyval.decl) = IdentifierDecl( Symbol((yyvsp[0].name)) );
    }
#line 9534 "parser.c" /* yacc.c:1646  */
    break;

  case 732:
#line 4603 "parser.y" /* yacc.c:1646  */
    {
      if (checkDecls)
        if (symtab_get(stab, Symbol((yyvsp[0].name)), IDNAME) == NULL)
          parse_error(-1, "unknown identifier `%s'.\n", (yyvsp[0].name));
      (yyval.decl) = IdList((yyvsp[-2].decl), IdentifierDecl( Symbol((yyvsp[0].name)) ));
    }
#line 9545 "parser.c" /* yacc.c:1646  */
    break;

  case 733:
#line 4613 "parser.y" /* yacc.c:1646  */
    {
      if (checkDecls)
        if (symtab_get(stab, Symbol((yyvsp[0].name)), IDNAME) == NULL)
          parse_error(-1, "unknown identifier `%s'.\n", (yyvsp[0].name));
      (yyval.decl) = IdentifierDecl( Symbol((yyvsp[0].name)) );
    }
#line 9556 "parser.c" /* yacc.c:1646  */
    break;

  case 734:
#line 4620 "parser.y" /* yacc.c:1646  */
    {
      (yyval.decl) = (yyvsp[0].decl);
    }
#line 9564 "parser.c" /* yacc.c:1646  */
    break;

  case 735:
#line 4624 "parser.y" /* yacc.c:1646  */
    {
      if (checkDecls)
        if (symtab_get(stab, Symbol((yyvsp[0].name)), IDNAME) == NULL)
          parse_error(-1, "unknown identifier `%s'.\n", (yyvsp[0].name));
      (yyval.decl) = IdList((yyvsp[-2].decl), IdentifierDecl( Symbol((yyvsp[0].name)) ));
    }
#line 9575 "parser.c" /* yacc.c:1646  */
    break;

  case 736:
#line 4631 "parser.y" /* yacc.c:1646  */
    {
      (yyval.decl) = IdList((yyvsp[-2].decl), (yyvsp[0].decl));
    }
#line 9583 "parser.c" /* yacc.c:1646  */
    break;

  case 737:
#line 4637 "parser.y" /* yacc.c:1646  */
    { sc_pause_openmp(); }
#line 9589 "parser.c" /* yacc.c:1646  */
    break;

  case 738:
#line 4638 "parser.y" /* yacc.c:1646  */
    {
      sc_start_openmp();
      //TODO
    }
#line 9598 "parser.c" /* yacc.c:1646  */
    break;

  case 739:
#line 4642 "parser.y" /* yacc.c:1646  */
    { sc_pause_openmp(); }
#line 9604 "parser.c" /* yacc.c:1646  */
    break;

  case 740:
#line 4643 "parser.y" /* yacc.c:1646  */
    {
      sc_start_openmp();
      //TODO
    }
#line 9613 "parser.c" /* yacc.c:1646  */
    break;

  case 741:
#line 4651 "parser.y" /* yacc.c:1646  */
    {
      //TODO
    }
#line 9621 "parser.c" /* yacc.c:1646  */
    break;

  case 742:
#line 4655 "parser.y" /* yacc.c:1646  */
    {
      //TODO
    }
#line 9629 "parser.c" /* yacc.c:1646  */
    break;

  case 743:
#line 4663 "parser.y" /* yacc.c:1646  */
    {
      (yyval.ocla) = ProcBindClause(OC_bindmaster);
    }
#line 9637 "parser.c" /* yacc.c:1646  */
    break;

  case 744:
#line 4667 "parser.y" /* yacc.c:1646  */
    {
      (yyval.ocla) = ProcBindClause(OC_bindclose);
    }
#line 9645 "parser.c" /* yacc.c:1646  */
    break;

  case 745:
#line 4671 "parser.y" /* yacc.c:1646  */
    {
      (yyval.ocla) = ProcBindClause(OC_bindspread);
    }
#line 9653 "parser.c" /* yacc.c:1646  */
    break;

  case 746:
#line 4683 "parser.y" /* yacc.c:1646  */
    {
      if (checkDecls)
      {
        stentry e = symtab_get(stab, Symbol((yyvsp[0].name)), IDNAME);
        if (e == NULL)
          parse_error(-1, "unknown identifier `%s'.\n", (yyvsp[0].name));
        if (e->scopelevel != stab->scopelevel)
          parse_error(-1, "threadprivate directive appears at different "
                          "scope level\nfrom the one `%s' was declared.\n", (yyvsp[0].name));
        if (stab->scopelevel > 0)    /* Don't care for globals */
          if (speclist_getspec(e->spec, STCLASSSPEC, SPEC_static) == NULL)
            parse_error(-1, "threadprivate variable `%s' does not have static "
                            "storage type.\n", (yyvsp[0].name));
        e->isthrpriv = true;   /* Mark */
      }
      (yyval.decl) = IdentifierDecl( Symbol((yyvsp[0].name)) );
    }
#line 9675 "parser.c" /* yacc.c:1646  */
    break;

  case 747:
#line 4701 "parser.y" /* yacc.c:1646  */
    {
      if (checkDecls)
      {
        stentry e = symtab_get(stab, Symbol((yyvsp[0].name)), IDNAME);
        if (e == NULL)
          parse_error(-1, "unknown identifier `%s'.\n", (yyvsp[0].name));
        if (e->scopelevel != stab->scopelevel)
          parse_error(-1, "threadprivate directive appears at different "
                          "scope level\nfrom the one `%s' was declared.\n", (yyvsp[0].name));
        if (stab->scopelevel > 0)    /* Don't care for globals */
          if (speclist_getspec(e->spec, STCLASSSPEC, SPEC_static) == NULL)
            parse_error(-1, "threadprivate variable `%s' does not have static "
                            "storage type.\n", (yyvsp[0].name));
        e->isthrpriv = true;   /* Mark */
      }
      (yyval.decl) = IdList((yyvsp[-2].decl), IdentifierDecl( Symbol((yyvsp[0].name)) ));
    }
#line 9697 "parser.c" /* yacc.c:1646  */
    break;

  case 748:
#line 4727 "parser.y" /* yacc.c:1646  */
    {
      (yyval.xcon) = OmpixConstruct(OX_DCTASKSYNC, (yyvsp[0].xdir), NULL);
    }
#line 9705 "parser.c" /* yacc.c:1646  */
    break;

  case 749:
#line 4731 "parser.y" /* yacc.c:1646  */
    {
      (yyval.xcon) = OmpixConstruct(OX_DCTASKSCHEDULE, (yyvsp[0].xdir), NULL);
    }
#line 9713 "parser.c" /* yacc.c:1646  */
    break;

  case 750:
#line 4739 "parser.y" /* yacc.c:1646  */
    {
      (yyval.xdir) = OmpixDirective(OX_DCTASKSYNC, NULL);
    }
#line 9721 "parser.c" /* yacc.c:1646  */
    break;

  case 751:
#line 4746 "parser.y" /* yacc.c:1646  */
    {
      scope_start(stab);
    }
#line 9729 "parser.c" /* yacc.c:1646  */
    break;

  case 752:
#line 4750 "parser.y" /* yacc.c:1646  */
    {
      scope_end(stab);
      (yyval.xdir) = OmpixDirective(OX_DCTASKSCHEDULE, (yyvsp[-1].xcla));
    }
#line 9738 "parser.c" /* yacc.c:1646  */
    break;

  case 753:
#line 4758 "parser.y" /* yacc.c:1646  */
    {
      (yyval.xcla) = NULL;
    }
#line 9746 "parser.c" /* yacc.c:1646  */
    break;

  case 754:
#line 4762 "parser.y" /* yacc.c:1646  */
    {
      (yyval.xcla) = OmpixClauseList((yyvsp[-1].xcla), (yyvsp[0].xcla));
    }
#line 9754 "parser.c" /* yacc.c:1646  */
    break;

  case 755:
#line 4766 "parser.y" /* yacc.c:1646  */
    {
      (yyval.xcla) = OmpixClauseList((yyvsp[-2].xcla), (yyvsp[0].xcla));
    }
#line 9762 "parser.c" /* yacc.c:1646  */
    break;

  case 756:
#line 4773 "parser.y" /* yacc.c:1646  */
    {
      (yyval.xcla) = OmpixStrideClause((yyvsp[-1].expr));
    }
#line 9770 "parser.c" /* yacc.c:1646  */
    break;

  case 757:
#line 4777 "parser.y" /* yacc.c:1646  */
    {
      (yyval.xcla) = OmpixStartClause((yyvsp[-1].expr));
    }
#line 9778 "parser.c" /* yacc.c:1646  */
    break;

  case 758:
#line 4781 "parser.y" /* yacc.c:1646  */
    {
      (yyval.xcla) = OmpixScopeClause((yyvsp[-1].type));
    }
#line 9786 "parser.c" /* yacc.c:1646  */
    break;

  case 759:
#line 4785 "parser.y" /* yacc.c:1646  */
    {
      (yyval.xcla) = OmpixPlainClause(OX_OCTIED);
    }
#line 9794 "parser.c" /* yacc.c:1646  */
    break;

  case 760:
#line 4789 "parser.y" /* yacc.c:1646  */
    {
      (yyval.xcla) = OmpixPlainClause(OX_OCUNTIED);
    }
#line 9802 "parser.c" /* yacc.c:1646  */
    break;

  case 761:
#line 4796 "parser.y" /* yacc.c:1646  */
    {
      (yyval.type) = OX_SCOPE_NODES;
    }
#line 9810 "parser.c" /* yacc.c:1646  */
    break;

  case 762:
#line 4800 "parser.y" /* yacc.c:1646  */
    {
      (yyval.type) = OX_SCOPE_WGLOBAL;
    }
#line 9818 "parser.c" /* yacc.c:1646  */
    break;

  case 763:
#line 4804 "parser.y" /* yacc.c:1646  */
    {
      (yyval.type) = OX_SCOPE_WGLOBAL;
    }
#line 9826 "parser.c" /* yacc.c:1646  */
    break;

  case 764:
#line 4808 "parser.y" /* yacc.c:1646  */
    {
      (yyval.type) = OX_SCOPE_WLOCAL;
    }
#line 9834 "parser.c" /* yacc.c:1646  */
    break;

  case 765:
#line 4815 "parser.y" /* yacc.c:1646  */
    {
      (yyval.xcon) = (yyvsp[0].xcon);
    }
#line 9842 "parser.c" /* yacc.c:1646  */
    break;

  case 766:
#line 4819 "parser.y" /* yacc.c:1646  */
    {
      (yyval.xcon) = (yyvsp[0].xcon);
    }
#line 9850 "parser.c" /* yacc.c:1646  */
    break;

  case 767:
#line 4827 "parser.y" /* yacc.c:1646  */
    {
      /* Should put the name of the callback function in the stab, too
      if (symtab_get(stab, decl_getidentifier_symbol($2->u.declaration.decl),
            FUNCNAME) == NULL)
        symtab_put(stab, decl_getidentifier_symbol($2->u.declaration.spec),
            FUNCNAME);
      */
      scope_start(stab);   /* re-declare the arguments of the task function */
      ast_declare_function_params((yyvsp[0].stmt)->u.declaration.decl);
    }
#line 9865 "parser.c" /* yacc.c:1646  */
    break;

  case 768:
#line 4838 "parser.y" /* yacc.c:1646  */
    {
      scope_end(stab);
      (yyval.xcon) = OmpixTaskdef((yyvsp[-3].xdir), (yyvsp[-2].stmt), (yyvsp[0].stmt));
      (yyval.xcon)->l = (yyvsp[-3].xdir)->l;
    }
#line 9875 "parser.c" /* yacc.c:1646  */
    break;

  case 769:
#line 4844 "parser.y" /* yacc.c:1646  */
    {
      (yyval.xcon) = OmpixTaskdef((yyvsp[-1].xdir), (yyvsp[0].stmt), NULL);
      (yyval.xcon)->l = (yyvsp[-1].xdir)->l;
    }
#line 9884 "parser.c" /* yacc.c:1646  */
    break;

  case 770:
#line 4852 "parser.y" /* yacc.c:1646  */
    {
      scope_start(stab);
    }
#line 9892 "parser.c" /* yacc.c:1646  */
    break;

  case 771:
#line 4856 "parser.y" /* yacc.c:1646  */
    {
      scope_end(stab);
      (yyval.xdir) = OmpixDirective(OX_DCTASKDEF, (yyvsp[-1].xcla));
    }
#line 9901 "parser.c" /* yacc.c:1646  */
    break;

  case 772:
#line 4864 "parser.y" /* yacc.c:1646  */
    {
      (yyval.xcla) = NULL;
    }
#line 9909 "parser.c" /* yacc.c:1646  */
    break;

  case 773:
#line 4868 "parser.y" /* yacc.c:1646  */
    {
      (yyval.xcla) = OmpixClauseList((yyvsp[-1].xcla), (yyvsp[0].xcla));
    }
#line 9917 "parser.c" /* yacc.c:1646  */
    break;

  case 774:
#line 4872 "parser.y" /* yacc.c:1646  */
    {
      (yyval.xcla) = OmpixClauseList((yyvsp[-2].xcla), (yyvsp[0].xcla));
    }
#line 9925 "parser.c" /* yacc.c:1646  */
    break;

  case 775:
#line 4879 "parser.y" /* yacc.c:1646  */
    {
      (yyval.xcla) = OmpixVarlistClause(OX_OCIN, (yyvsp[-1].decl));
    }
#line 9933 "parser.c" /* yacc.c:1646  */
    break;

  case 776:
#line 4883 "parser.y" /* yacc.c:1646  */
    {
      (yyval.xcla) = OmpixVarlistClause(OX_OCOUT, (yyvsp[-1].decl));
    }
#line 9941 "parser.c" /* yacc.c:1646  */
    break;

  case 777:
#line 4887 "parser.y" /* yacc.c:1646  */
    {
      (yyval.xcla) = OmpixVarlistClause(OX_OCINOUT, (yyvsp[-1].decl));
    }
#line 9949 "parser.c" /* yacc.c:1646  */
    break;

  case 778:
#line 4891 "parser.y" /* yacc.c:1646  */
    {
      (yyval.xcla) = OmpixReductionClause((yyvsp[-3].type), (yyvsp[-1].decl));
    }
#line 9957 "parser.c" /* yacc.c:1646  */
    break;

  case 779:
#line 4898 "parser.y" /* yacc.c:1646  */
    {
      (yyval.decl) = (yyvsp[0].decl);
    }
#line 9965 "parser.c" /* yacc.c:1646  */
    break;

  case 780:
#line 4902 "parser.y" /* yacc.c:1646  */
    {
      (yyval.decl) = IdList((yyvsp[-2].decl), (yyvsp[0].decl));
    }
#line 9973 "parser.c" /* yacc.c:1646  */
    break;

  case 781:
#line 4909 "parser.y" /* yacc.c:1646  */
    {
      (yyval.decl) = IdentifierDecl( Symbol((yyvsp[0].name)) );
      symtab_put(stab, Symbol((yyvsp[0].name)), IDNAME);
    }
#line 9982 "parser.c" /* yacc.c:1646  */
    break;

  case 782:
#line 4914 "parser.y" /* yacc.c:1646  */
    {
      if (checkDecls) check_uknown_var((yyvsp[-1].name));
      /* Use extern to differentiate */
      (yyval.decl) = ArrayDecl(IdentifierDecl( Symbol((yyvsp[-4].name)) ), StClassSpec(SPEC_extern),
                     IdentName((yyvsp[-1].name)));
      symtab_put(stab, Symbol((yyvsp[-4].name)), IDNAME);
    }
#line 9994 "parser.c" /* yacc.c:1646  */
    break;

  case 783:
#line 4922 "parser.y" /* yacc.c:1646  */
    {
      (yyval.decl) = ArrayDecl(IdentifierDecl( Symbol((yyvsp[-3].name)) ), NULL, (yyvsp[-1].expr));
      symtab_put(stab, Symbol((yyvsp[-3].name)), IDNAME);
    }
#line 10003 "parser.c" /* yacc.c:1646  */
    break;

  case 784:
#line 4930 "parser.y" /* yacc.c:1646  */
    {
      (yyval.xcon) = OmpixConstruct(OX_DCTASK, (yyvsp[-2].xdir), Expression((yyvsp[-1].expr)));
      (yyval.xcon)->l = (yyvsp[-2].xdir)->l;
    }
#line 10012 "parser.c" /* yacc.c:1646  */
    break;

  case 785:
#line 4938 "parser.y" /* yacc.c:1646  */
    {
      (yyval.xdir) = OmpixDirective(OX_DCTASK, (yyvsp[-1].xcla));
    }
#line 10020 "parser.c" /* yacc.c:1646  */
    break;

  case 786:
#line 4945 "parser.y" /* yacc.c:1646  */
    {
      (yyval.xcla) = NULL;
    }
#line 10028 "parser.c" /* yacc.c:1646  */
    break;

  case 787:
#line 4949 "parser.y" /* yacc.c:1646  */
    {
      (yyval.xcla) = OmpixClauseList((yyvsp[-1].xcla), (yyvsp[0].xcla));
    }
#line 10036 "parser.c" /* yacc.c:1646  */
    break;

  case 788:
#line 4953 "parser.y" /* yacc.c:1646  */
    {
      (yyval.xcla) = OmpixClauseList((yyvsp[-2].xcla), (yyvsp[0].xcla));
    }
#line 10044 "parser.c" /* yacc.c:1646  */
    break;

  case 789:
#line 4960 "parser.y" /* yacc.c:1646  */
    {
      (yyval.xcla) = OmpixPlainClause(OX_OCATALL);
    }
#line 10052 "parser.c" /* yacc.c:1646  */
    break;

  case 790:
#line 4964 "parser.y" /* yacc.c:1646  */
    {
      (yyval.xcla) = OmpixAtnodeClause((yyvsp[-1].expr));
    }
#line 10060 "parser.c" /* yacc.c:1646  */
    break;

  case 791:
#line 4968 "parser.y" /* yacc.c:1646  */
    {
      (yyval.xcla) = OmpixAtworkerClause((yyvsp[-1].expr));
    }
#line 10068 "parser.c" /* yacc.c:1646  */
    break;

  case 792:
#line 4972 "parser.y" /* yacc.c:1646  */
    {
      (yyval.xcla) = OmpixPlainClause(OX_OCTIED);
    }
#line 10076 "parser.c" /* yacc.c:1646  */
    break;

  case 793:
#line 4976 "parser.y" /* yacc.c:1646  */
    {
      (yyval.xcla) = OmpixPlainClause(OX_OCUNTIED);
    }
#line 10084 "parser.c" /* yacc.c:1646  */
    break;

  case 794:
#line 4980 "parser.y" /* yacc.c:1646  */
    {
      (yyval.xcla) = OmpixPlainClause(OX_OCDETACHED);
    }
#line 10092 "parser.c" /* yacc.c:1646  */
    break;

  case 795:
#line 4987 "parser.y" /* yacc.c:1646  */
    {
      (yyval.expr) = strcmp((yyvsp[-2].name), "main") ?
             FunctionCall(IdentName((yyvsp[-2].name)), NULL) :
             FunctionCall(IdentName(MAIN_NEWNAME), NULL);
    }
#line 10102 "parser.c" /* yacc.c:1646  */
    break;

  case 796:
#line 4993 "parser.y" /* yacc.c:1646  */
    {
      (yyval.expr) = strcmp((yyvsp[-3].name), "main") ?
             FunctionCall(IdentName((yyvsp[-3].name)), (yyvsp[-1].expr)) :
             FunctionCall(IdentName(MAIN_NEWNAME), (yyvsp[-1].expr));
    }
#line 10112 "parser.c" /* yacc.c:1646  */
    break;


#line 10116 "parser.c" /* yacc.c:1646  */
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
#line 5000 "parser.y" /* yacc.c:1906  */



/* * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * *
 *                                                               *
 *     CODE                                                      *
 *                                                               *
 * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * */


void yyerror(const char *s)
{
  fprintf(stderr, "(file %s, line %d, column %d):\n\t%s\n",
                  sc_original_file(), sc_original_line(), sc_column(), s);
}


/* Check whether the identifier is known or not
 */
void check_uknown_var(char *name)
{
  /* Hack for DF-C */
  if(strncmp(name, "DF", 2) == 0)
    return;

  symbol s = Symbol(name);
  if (symtab_get(stab, s, IDNAME) == NULL &&
      symtab_get(stab, s, LABELNAME) == NULL &&
      symtab_get(stab, s, FUNCNAME) == NULL)
    parse_error(-1, "unknown identifier `%s'.\n", name);
}



/* See the "declaration" rule: if the last element of the list
 * is a user typename, we remove it, and we return it as an
 * identifier declarator.
 * The list should have 3 elements (typedef xxx type).
 */
astdecl fix_known_typename(astspec s)
{
  astspec prev;
  astdecl d;

  if (s->type != SPECLIST || s->u.next->type != SPECLIST) return (NULL);

  for (; s->u.next->type == SPECLIST; prev = s, s = s->u.next)
    ;   /* goto last list node */
  if (s->u.next->type != USERTYPE)         /* nope */
    return (NULL);

  prev->u.next = s->body;

  d = Declarator(NULL, IdentifierDecl(s->u.next->name));
  if (checkDecls)
    symtab_put(stab, s->u.next->name, TYPENAME);
  free(s);
  return (d);
}


void check_for_main_and_declare(astspec s, astdecl d)
{
  astdecl n = decl_getidentifier(d);

  assert(d->type == DECLARATOR);
  assert(d->decl->type == DFUNC ||
         /* DF-C */ d->decl->type == DDFCFUNC);

  if (strcmp(n->u.id->name, "main") == 0)
  {
    n->u.id = Symbol(MAIN_NEWNAME);         /* Catch main()'s definition */
    hasMainfunc = 1;

    /* Now check for return type and # parameters */
    /* It d != NULL then its parameters is either (id or idlist) or
     * (paramtype or parmatypelist). If it is a list, assume the
     * standard 2 params, otherwise, we guess the single argument
     * must be the type "void" which means no params.
     * In any case, we always force main have (argc, argv[]).
     */
    if(!__has_dfc)
    {
      if (d->decl->u.params == NULL || d->decl->u.params->type != DLIST)
        d->decl->u.params =
            ParamList(
              ParamDecl(
                Declspec(SPEC_int),
                Declarator( NULL, IdentifierDecl( Symbol("_argc_ignored") ) )
              ),
              ParamDecl(
                Declspec(SPEC_char),
                Declarator(Speclist_right( Pointer(), Pointer() ),
                          IdentifierDecl( Symbol("_argv_ignored") ))
              )
            );
    }
    
    mainfuncRettype = 0; /* int */
    if (s != NULL)
    {
      for (; s->type == SPECLIST && s->subtype == SPEC_Rlist; s = s->u.next)
        if (s->body->type == SPEC && s->body->subtype == SPEC_void)
        {
          s = s->body;
          break;
        };
      if (s->type == SPEC && s->subtype == SPEC_void)
        mainfuncRettype = 1; /* void */
    }
  }
  if (symtab_get(stab, n->u.id, FUNCNAME) == NULL)/* From earlier declaration */
    symtab_put(stab, n->u.id, FUNCNAME);
}


/* For each variable/typename in the given declaration, add pointers in the
 * symbol table entries back to the declaration nodes.
 */
void add_declaration_links(astspec s, astdecl d)
{
  astdecl ini = NULL;

  if (d->type == DLIST && d->subtype == DECL_decllist)
  {
    add_declaration_links(s, d->u.next);
    d = d->decl;
  }
  if (d->type == DINIT) d = (ini = d)->decl;   /* Skip the initializer */
  assert(d->type == DECLARATOR);
  if (d->decl != NULL && d->decl->type != ABSDECLARATOR)
  {
    symbol  t = decl_getidentifier_symbol(d->decl);
    stentry e = isTypedef ?
                symtab_get(stab,t,TYPENAME) :
                symtab_get(stab,t,(decl_getkind(d)==DFUNC) ? FUNCNAME : IDNAME);
    e->spec  = s;
    e->decl  = d;
    e->idecl = ini;
  }
}


void parse_error(int exitvalue, char *format, ...)
{
  va_list ap;

  va_start(ap, format);
  fprintf(stderr, "(%s, line %d)\n\t", sc_original_file(), sc_original_line());
  vfprintf(stderr, format, ap);
  va_end(ap);
  if (strcmp(sc_original_file(), "injected_code") == 0)
    fprintf(stderr, "\n>>>>>>>\n%s\n>>>>>>>\n", parsingstring);
  _exit(exitvalue);
}


void parse_warning(char *format, ...)
{
  va_list ap;

  va_start(ap, format);
  fprintf(stderr, "[warning] ");
  vfprintf(stderr, format, ap);
  va_end(ap);
}


aststmt parse_file(char *fname, int *error)
{
  *error = 0;
  if ( (yyin = fopen(fname, "r")) == NULL )
    return (NULL);
  sc_set_filename(fname);      /* Inform the scanner */
  *error = yyparse();
  // if(yyin)
    fclose(yyin);                /* No longer needed */
  return (pastree);
}


#define PARSE_STRING_SIZE 8192


astexpr parse_expression_string(char *format, ...)
{
  static char s[PARSE_STRING_SIZE];
  int    savecD;

  va_list ap;
  va_start(ap, format);
  vsnprintf(s, PARSE_STRING_SIZE-1, format, ap);
  va_end(ap);
  parsingstring = s;
  sc_scan_string(s);
  sc_set_start_token(START_SYMBOL_EXPRESSION);

  savecD = checkDecls;
  checkDecls = 0;         /* Don't check identifiers & don't declare them */
  yyparse();
  checkDecls = savecD;    /* Reset it */
  return ( pastree_expr );
}


aststmt parse_blocklist_string(char *format, ...)
{
  static char s[PARSE_STRING_SIZE];
  int    savecD;

  va_list ap;
  va_start(ap, format);
  vsnprintf(s, PARSE_STRING_SIZE-1, format, ap);
  va_end(ap);
  parsingstring = s;
  sc_scan_string(s);
  sc_set_start_token(START_SYMBOL_BLOCKLIST);

  savecD = checkDecls;
  checkDecls = 0;         /* Don't check identifiers & don't declare them */
  yyparse();
  checkDecls = savecD;    /* Reset it */
  return ( pastree_stmt );
}


aststmt parse_and_declare_blocklist_string(char *format, ...)
{
  static char s[PARSE_STRING_SIZE];
  int    savecD;

  va_list ap;
  va_start(ap, format);
  vsnprintf(s, PARSE_STRING_SIZE-1, format, ap);
  va_end(ap);
  parsingstring = s;
  sc_scan_string(s);
  sc_set_start_token(START_SYMBOL_BLOCKLIST);

  savecD = checkDecls;
  checkDecls = 1;         /* Do check identifiers & do declare them */
  yyparse();
  checkDecls = savecD;    /* Reset it */
  return ( pastree_stmt );
}


aststmt parse_transunit_string(char *format, ...)
{
  static char s[PARSE_STRING_SIZE];
  int    savecD;

  va_list ap;
  va_start(ap, format);
  vsnprintf(s, PARSE_STRING_SIZE-1, format, ap);
  va_end(ap);
  parsingstring = s;
  sc_scan_string(s);
  sc_set_start_token(START_SYMBOL_TRANSUNIT);

  savecD = checkDecls;
  checkDecls = 0;         /* Don't check identifiers & don't declare them */
  yyparse();
  checkDecls = savecD;    /* Reset it */
  return ( pastree_stmt );
}


void dfc_insert_active_data_decl_and_update_persize(struct dfc_insert_detail *detail)
{

  //ljr:  定义变量和记录开始时间
  if(sched_info)
  {
    (*detail).body = BlockList((*detail).body, verbit("  struct timeval begin;"));
    (*detail).body = BlockList((*detail).body, verbit("  struct timeval end;"));
    (*detail).body = BlockList((*detail).body, verbit("  gettimeofday(&begin,NULL);\n"));    
  }



  if(detail->inParams == NULL)
  {
    (*detail).body = BlockList((*detail).body, verbit("  int DF_count;\n"));
  }
  else
  {
    astdecl params = detail->inParams;

    while(params->type == DPARAM || 
        (params->type == DLIST && params->subtype == DECL_paramlist))
    {
	    char *name;
      name = dfc_get_decl_identifier_name(params);
      (*detail).body = BlockList((*detail).body, 
	                             (params->type == DPARAM ? 
								 Declaration(params->spec, params->decl) :
								 Declaration(params->decl->spec, params->decl->decl)));
      (*detail).body = BlockList((*detail).body, verbit("  DF_persize_%s = sizeof(%s);",
                                 name, name));
      ++(*detail).in_params_count;
      
	  if(params->type == DPARAM)
      {
        break;
      }
        
      else if(params->type == DLIST && params->subtype == DECL_paramlist)
      {
        params = params->u.next;
      }
      else
        parse_error(68, "dfc func def broken.\n");
    }
  }

  if(detail->outParams)
  {
    astdecl params = detail->outParams;

    while(params->type == DPARAM || 
        (params->type == DLIST && params->subtype == DECL_paramlist))
    {
      char *name;
      name = dfc_get_decl_identifier_name(params);
      (*detail).body = BlockList((*detail).body, 
	                             (params->type == DPARAM ?
								 Declaration(params->spec, params->decl) :
								 Declaration(params->decl->spec, params->decl->decl)));
      (*detail).body = BlockList((*detail).body, verbit("  DF_persize_%s = sizeof(%s);",
                                 name, name));
      ++(*detail).out_params_count;

	  if(params->type == DPARAM)
      {
        break;
      }
        
      else if(params->type == DLIST && params->subtype == DECL_paramlist)
      {
        params = params->u.next;
      }
      else
        parse_error(68, "dfc func def broken.\n");
    }
  }

  /*ljr:没必要
  if(detail->in_params_count == 0)
  {
    (*detail).body = BlockList((*detail).body,
                       verbit("  int DF_FN_item_index = DF_FN_%s.item_index;\n", 
					          detail->func_name));
  }
  */
}


void dfc_insert_get_active_data_call(struct dfc_insert_detail *detail)
{
  char str[1024];
  int strLength = 0;

  if(detail->in_params_count == 0)
    snprintf(str+strLength, 1023-strLength, 
             "  DF_SOURCE_Get_And_Update(&DF_FN_%s, &DF_count);", detail->func_name);
  else
  {
    snprintf(str+strLength, 1023-strLength, "  int DF_count = DF_AD_GetData(&DF_FN_%s", detail->func_name);
    strLength = strlen(str);
    
    astdecl params = detail->inParams;
    for(int Counter = 0; 
        Counter < detail->in_params_count; 
        ++Counter, params = params->u.next)
    {
      snprintf(str+strLength, 1023-strLength, 
                 ", &%s, DF_persize_%s", 
                 dfc_get_decl_identifier_name(params),
                 dfc_get_decl_identifier_name(params));
      
      strLength = strlen(str);
    }
    
    snprintf(str+strLength, 1023-strLength, ");");
  }
  
  (*detail).body = BlockList((*detail).body, verbit(str));
}

void dfc_insert_update_active_data_call(struct dfc_insert_detail *detail)
{
  char str[1024];
  int strLength = 0;

  snprintf(str+strLength, 1023-strLength, 
           "  DF_AD_UpData(DF_count,&DF_TFL_TABLE, &DF_FN_%s",
           detail->func_name);
  strLength = strlen(str);
  
  astdecl params = detail->outParams;
  for(int Counter = 0; 
      Counter < detail->out_params_count; 
      ++Counter, params = params->u.next)
  {
    snprintf(str+strLength, 1023-strLength, 
             ", &%s, DF_persize_%s", 
             dfc_get_decl_identifier_name(params),
             dfc_get_decl_identifier_name(params));
    
    strLength = strlen(str);
  }
  
  snprintf(str+strLength, 1023-strLength, ");");
  
  (*detail).body = BlockList((*detail).body, verbit(str));

  //ljr: 输出调度信息
  if(sched_info)
  {
    (*detail).body = BlockList((*detail).body, verbit("  gettimeofday(&end,NULL);"));
    (*detail).body = BlockList((*detail).body, verbit("  int tid = gettid();//获取线程号"));
    (*detail).body = BlockList((*detail).body, verbit("  long start_time, end_time;\n"));
    (*detail).body = BlockList((*detail).body, verbit("  start_time = (begin.tv_sec - program_start.tv_sec) *1000000 + (begin.tv_usec - program_start.tv_usec);"));
    (*detail).body = BlockList((*detail).body, verbit("  end_time = (end.tv_sec - program_start.tv_sec) *1000000 + (end.tv_usec - program_start.tv_usec);"));
    (*detail).body = BlockList((*detail).body, verbit("  char s[20];\n"
                                                      "  sprintf(s, \"/proc/%%d/stat\", tid);\n"
                                                      "  FILE *fp_temp = fopen(s, \"r\");\n"
                                                      "  for(int i=0; i<39; i++)\n"
                                                      "    fscanf(fp_temp,\"%%s\",&s);\n"
                                                      "  fclose(fp_temp);"));
    (*detail).body = BlockList((*detail).body, verbit("  pthread_mutex_lock(&sched_info_mutex);\n"));
    (*detail).body = BlockList((*detail).body, verbit("  fprintf(fp_sche, \"func:%%s, pass:%%d, tid:%%d, core:%%s, start:%%ldus, end:%%ldus\\n\","
                                                      "  __FUNCTION__, DF_count, tid, s,start_time, end_time);\n"));
    (*detail).body = BlockList((*detail).body, verbit("  pthread_mutex_unlock(&sched_info_mutex);\n"));   
  }

}
        
void dfc_use_detail_to_fill_main_ad_and_fn_init(struct dfc_insert_detail *detail)
{

  astdecl params = detail->outParams;
  for(int Counter = 0; Counter < detail->out_params_count; ++Counter, params = params->u.next)
  {
    char *name;
    //ljr
  	name = dfc_get_decl_identifier_name(params);
  	dfc_main_subtree_for_ad = BlockList(dfc_main_subtree_for_ad, 
                                          verbit("DF_ADInit(&DF_AD_%s, sizeof(%s), DF_fanout_%s);\n",
                                                 dfc_get_decl_identifier_name(params),
                                                 (params->type == DPARAM) ? params->spec->name : params->decl->spec->name,
                                                 dfc_get_decl_identifier_name(params)));
  }  


                                
              
  char str[1024];
  int strLength = 0;
  
  str[0] = '\0';
  params = detail->outParams;
  for(int Counter = 0;
      Counter < detail->out_params_count;
      ++Counter, params = params->u.next)
  {
    char *name;
	name = dfc_get_decl_identifier_name(params);
	snprintf(str+strLength, 1023-strLength, ", &DF_AD_%s", 
	                                        dfc_get_decl_identifier_name(params));
	strLength = strlen(str);
  }
  
  dfc_main_subtree_for_fn = BlockList(dfc_main_subtree_for_fn,
                                      verbit("DF_FNInit2(&DF_FN_%s, %d%s);\n",
                                             detail->func_name, detail->out_params_count, str));
  
  str[0] = '\0';
  strLength = 0;
  params = detail->inParams;
  for(int Counter = 0;
      Counter < detail->in_params_count;
      ++Counter, params = params->u.next)
  {
    char *name;
	name = dfc_get_decl_identifier_name(params);
	snprintf(str+strLength, 1023-strLength, ", &DF_AD_%s", 
	                                        dfc_get_decl_identifier_name(params));
	strLength = strlen(str);      
  }

  dfc_main_subtree_for_fn = BlockList(dfc_main_subtree_for_fn,
                                      verbit("DF_FNInit1(&DF_FN_%s, &%s, \"%s\", %d%s);\n",
                                             detail->func_name, 
											 detail->func_name, 
											 detail->func_name, 
                                             detail->in_params_count,
                                             str));
}
