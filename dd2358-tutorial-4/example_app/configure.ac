AC_INIT([DD2358 Tutorial], 1.0) # Init our project
: ${CFLAGS=""}
AM_INIT_AUTOMAKE([foreign])     # Ignore the missing GNU files
AC_PROG_CC                      # We want a C compijler

AC_CHECK_HEADERS([math.h],      # check if math.h exists, if not, throw an error
        [found_math_headers=yes; break;])
AS_IF([test "x$found_math_headers" != "xyes"],
        [AC_MSG_ERROR([Unable to find the math header])])

AC_SEARCH_LIBS([pow], [m], [], [
  AC_MSG_ERROR([No library found that provides pow()])
])

AC_CONFIG_FILES(Makefile src/Makefile)
AC_OUTPUT
