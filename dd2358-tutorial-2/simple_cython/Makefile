.PHONY: all clean

all:
	python setup.py build_ext --inplace

clean:
	python setup.py clean
	rm -rf build *.so
	rm cython_sum.c
