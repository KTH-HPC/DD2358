dnl 1. Define name and version of project
AC_INIT([DD2358 Tutorial], 1.0)

dnl 2. Init automake as foreign project
AM_INIT_AUTOMAKE([foreign])

dnl 3. Find a C compmiler
AC_PROG_CC

dnl 4. Check if header math.h exists
AC_CHECK_HEADERS([math.h], [found_math_headers=yes; break;])
AS_IF([test "x$found_math_headers" != "xyes"],
	[AC_MSG_ERROR([Unable to find the math header.])])

dnl 5. Check and link math lib
AC_SEARCH_LIBS([pow], [m], [], [AC_MSG_ERROR([Cannot find libm.])])

dnl 6. specify the templates to fill in
AC_CONFIG_FILES(Makefile src/Makefile)

dnl 7. generate
AC_OUTPUT
