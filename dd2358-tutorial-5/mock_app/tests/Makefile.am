check_PROGRAMS = test_led test_color
TESTS = $(check_PROGRAMS)

test_led_SOURCES  = test_led.cpp
test_led_CPPFLAGS = -I$(top_srcdir)/include
test_led_CXXFLAGS = $(GTEST_CFLAGS) $(GMOCK_CFLAGS)
test_led_LDFLAGS  = -pthread
test_led_LDADD    = $(GTEST_LIBS) \
                    $(GMOCK_LIBS) \
                    $(top_builddir)/src/__top_builddir__bin_main_out-led_light.o \
                    $(top_builddir)/src/__top_builddir__bin_main_out-print_light_color.o

test_color_SOURCES  = test_color.cpp
test_color_CPPFLAGS = -I$(top_srcdir)/include
test_color_CXXFLAGS = $(GTEST_CFLAGS) $(GMOCK_CFLAGS)
test_color_LDFLAGS  = -pthread
test_color_LDADD    = $(GTEST_LIBS) \
                      $(GMOCK_LIBS) \
                      $(top_builddir)/src/__top_builddir__bin_main_out-print_light_color.o
