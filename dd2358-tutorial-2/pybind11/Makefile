CXX=g++
CFLAGS=-Wall -g
TARGET=sum$(shell python3-config --extension-suffix)
CFLAGS=-O -Wall -shared -std=c++11 -fPIC $(shell python3 -m pybind11 --includes)

$(TARGET): sum_src.cc
	$(CXX) $(CFLAGS) $< -o $@

.PHONY: clean

clean:
	rm -f $(TARGET)
