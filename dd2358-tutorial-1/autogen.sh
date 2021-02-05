#!/bin/bash

# 1. collect the m4 macros required by configure.ac
aclocal

# 2. generate Makefile.in templates from Makefile.am
automake --add-missing

# 3. generate configure script from configure.ac
autoreconf -i -f
