CC=gcc
FC=gfortran
CFLAGS=-Wall -g
TARGET=main.out
DEPS=main.o product.o

%.o: %.c
	$(CC) -c -o $@ $< $(CFLAGS)

%.o: %.f90
	$(FC) -c -o $@ $< $(CFLAGS)

$(TARGET): $(DEPS)
	$(FC) -o $@ $(DEPS)

.PHONY: clean

clean:
	rm -f $(DEPS) $(TARGET) *.mod
