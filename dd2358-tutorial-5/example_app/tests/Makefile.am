check_PROGRAMS = func_test
TESTS = $(check_PROGRAMS)

func_test_SOURCES = test.cpp

func_test_CPPFLAGS = -I$(top_srcdir)/include

func_test_CXXFLAGS = $(GTEST_CFLAGS)

func_test_LDFLAGS = -pthread

func_test_LDADD = $(GTEST_LIBS) \
                  $(top_builddir)/src/__top_builddir__bin_main_out-division.o \
                  $(top_builddir)/src/__top_builddir__bin_main_out-sum.o \
                  $(top_builddir)/src/__top_builddir__bin_main_out-product.o \
                  $(top_builddir)/src/__top_builddir__bin_main_out-power.o
