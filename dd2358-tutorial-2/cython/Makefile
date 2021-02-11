CC=gcc
F90=gfortran
CFLAGS=-Wall -g
TARGET=libsum.so
DEPS=sum_src.o

%.o: %.c
	$(CC) -c -o $@ $< $(CFLAGS)

%.o: %.f90
	$(F90) -c -o $@ $< $(CFLAGS)


$(TARGET): $(DEPS)
	$(F90) -fPIC -shared -o $@ $(DEPS)
	python setup.py build_ext --inplace

.PHONY: clean

clean:
	python setup.py clean
	rm -rf build *.so
	rm cython_sum.c
	rm -f $(DEPS) $(TARGET) *.mod
