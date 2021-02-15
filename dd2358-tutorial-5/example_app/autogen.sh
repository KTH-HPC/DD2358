#!/bin/bash

# 1. collect the m4 macros required by configure.ac
aclocal || exit 1

# 2. generate Makefile.in templates from Makefile.am
automake --add-missing || exit 1

# 3. generate configure script from configure.ac
autoreconf -i -f || exit 1
