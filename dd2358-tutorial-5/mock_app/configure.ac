AC_INIT([DD2358 Tutorial], 1.0) # Init our project
: ${CFLAGS=""}

AM_INIT_AUTOMAKE([foreign])     # Ignore the missing GNU files
AC_PROG_CC                      # We want a C compiler
AC_PROG_CXX                     # We want a C++ compiler as well
# AX_CXX_COMPILE_STDCXX([11], [noext], [mandatory])

# Google Test
PKG_CHECK_MODULES([GTEST], [gtest_main])
PKG_CHECK_MODULES([GMOCK], [gmock_main])

AC_CONFIG_FILES(Makefile src/Makefile tests/Makefile)
AC_OUTPUT
