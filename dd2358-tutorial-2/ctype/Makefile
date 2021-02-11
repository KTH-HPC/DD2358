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

.PHONY: clean

clean:
	rm -f $(DEPS) $(TARGET) *.mod
