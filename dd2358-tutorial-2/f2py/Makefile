FC=f2py
CFLAGS=-Wall -g
TARGET=math_kernels
DEPS=math_kernels.f90

$(TARGET): $(DEPS)
	$(FC) -m $@ -c $<

.PHONY: clean

clean:
	rm -f $(TARGET) *.mod
