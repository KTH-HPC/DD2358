AC_INIT([DD2358 Tutorial], 1.0) # Init our project
: ${CFLAGS=""}

AM_INIT_AUTOMAKE([foreign])     # Ignore the missing GNU files
AC_PROG_CC                      # We want a C compiler
AC_PROG_CXX                     # We want a C++ compiler as well
# AX_CXX_COMPILE_STDCXX([11], [noext], [mandatory])

# Google Test
PKG_CHECK_MODULES([GTEST], [gtest_main])

AC_CHECK_HEADERS([math.h], [found_math_headers=yes; break;])
AS_IF([test "x$found_math_headers" != "xyes"],
	[AC_MSG_ERROR([Unable to find the math header.])])

dnl 5. Check and link math lib
AC_SEARCH_LIBS([pow], [m], [], [AC_MSG_ERROR([Cannot find libm.])])

AC_CONFIG_FILES(Makefile src/Makefile tests/Makefile)
AC_OUTPUT

