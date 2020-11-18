/* common/config.h.  Generated from config.h.in by configure.  */
/* common/config.h.in.  Generated from configure.ac by autoheader.  */

/* For pthread affinity */
/* #undef CAN_BIND */

/* Atomic boolean compare & swap */
#define HAVE_ATOMIC_CAS /**/

/* Atomic fetch & add */
#define HAVE_ATOMIC_FAA /**/

/* Define to 1 if you have the `clock_gettime' function. */
#define HAVE_CLOCK_GETTIME 1

/* Define to 1 if you have the <dlfcn.h> header file. */
#define HAVE_DLFCN_H 1

/* Define if dlopen exists. */
#define HAVE_DLOPEN 1

/* Define to 1 if you have the <inttypes.h> header file. */
#define HAVE_INTTYPES_H 1

/* Define to 1 if the system has the type `long long int'. */
#define HAVE_LONG_LONG_INT 1

/* Memory barrier */
#define HAVE_MEMBAR /**/

/* Define to 1 if you have the <memory.h> header file. */
#define HAVE_MEMORY_H 1

/* Define to 1 if you have the `posix_memalign' function. */
#define HAVE_POSIX_MEMALIGN 1

/* Define to 1 if you have the `pthread_setconcurrency' function. */
/* #undef HAVE_PTHREAD_SETCONCURRENCY */

/* Define to 1 if you have the `realpath' function. */
#define HAVE_REALPATH 1

/* Define to 1 if you have the `sched_yield' function. */
#define HAVE_SCHED_YIELD 1

/* Define to 1 if stdbool.h conforms to C99. */
#define HAVE_STDBOOL_H 1

/* Define to 1 if you have the <stdint.h> header file. */
#define HAVE_STDINT_H 1

/* Define to 1 if you have the <stdlib.h> header file. */
#define HAVE_STDLIB_H 1

/* Define to 1 if you have the <strings.h> header file. */
#define HAVE_STRINGS_H 1

/* Define to 1 if you have the <string.h> header file. */
#define HAVE_STRING_H 1

/* Define to 1 if you have the <sys/stat.h> header file. */
#define HAVE_SYS_STAT_H 1

/* Define to 1 if you have the <sys/types.h> header file. */
#define HAVE_SYS_TYPES_H 1

/* Define to 1 if wave struct timespec */
#define HAVE_TIMESPEC 1

/* Define to 1 if you have the <unistd.h> header file. */
#define HAVE_UNISTD_H 1

/* Define to 1 if the system has the type `unsigned long long int'. */
#define HAVE_UNSIGNED_LONG_LONG_INT 1

/* Define to 1 if the system has the type `_Bool'. */
#define HAVE__BOOL 1

/* Define to the sub-directory in which libtool stores uninstalled libraries.
   */
#define LT_OBJDIR ".libs/"

/* The installed device modules. */
#define MODULES_CONFIG ""

/* not found */
/* #undef NO_CLOCK_GETTIME */

/* Define to 1 if your C compiler doesn't accept -c and -o together. */
/* #undef NO_MINUS_C_MINUS_O */

/* not found */
/* #undef NO_SCHED_YIELD */

/* Name of package */
#define PACKAGE "ompi"

/* Define to the address where bug reports for this package should be sent. */
#define PACKAGE_BUGREPORT ""

/* Define to the full name of this package. */
#define PACKAGE_NAME "OMPi compiler with torc extensions"

/* Define to the full name and version of this package. */
#define PACKAGE_STRING "OMPi compiler with torc extensions obsolete"

/* Define to the one symbol short name of this package. */
#define PACKAGE_TARNAME "ompi"

/* Define to the home page for this package. */
#define PACKAGE_URL ""

/* Define to the version of this package. */
#define PACKAGE_VERSION "obsolete"

/* The size of `char *', as computed by sizeof. */
#define SIZEOF_CHAR_P 8

/* The size of `int', as computed by sizeof. */
#define SIZEOF_INT 4

/* The size of `long', as computed by sizeof. */
#define SIZEOF_LONG 8

/* Define to 1 if you have the ANSI C header files. */
#define STDC_HEADERS 1

/* For thread local storage */
#define TLS_KEYWORD __thread

/* Version number of package */
#define VERSION "obsolete"

/* Define to 1 if `lex' declares `yytext' as a `char *' by default, not a
   `char[]'. */
#define YYTEXT_POINTER 1

/* */
/* #undef __SYSCOMPILER_cygwin */

/* */
#define __SYSCOMPILER_gcc 1

/* */
/* #undef __SYSCOMPILER_intel */

/* */
/* #undef __SYSCOMPILER_mipspro */

/* */
/* #undef __SYSCOMPILER_sun */

/* */
/* #undef __SYSOS_cygwin */

/* */
/* #undef __SYSOS_irix */

/* */
#define __SYSOS_linux 1

/* */
/* #undef __SYSOS_solaris */

/* CAS function */
#define _cas __sync_bool_compare_and_swap

/* FAA function */
#define _faa __sync_fetch_and_add

/* Membar function */
#define _mb __sync_synchronize

/* Define to `__inline__' or `__inline' if that's what the C compiler
   calls it, or to nothing if 'inline' is not supported under any name.  */
#ifndef __cplusplus
/* #undef inline */
#endif

/* Define to `unsigned int' if <sys/types.h> does not define. */
/* #undef size_t */
