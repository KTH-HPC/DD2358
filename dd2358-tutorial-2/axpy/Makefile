CXX=g++
CFLAGS=-Wall -g
TARGET=math_kernels$(shell python3-config --extension-suffix)
CFLAGS=-O -Wall -shared -std=c++11 -fPIC $(shell python3 -m pybind11 --includes)

$(TARGET): math_kernels.cc
	$(CXX) $(CFLAGS) $< -o $@

.PHONY: clean

clean:
	rm -f $(TARGET)
