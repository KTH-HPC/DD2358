cimport libsum                        # use cimport to import libsum.so

cpdef double sum(double a, double b): # Now that we depend on an external library, we only need the Python wrapper
  return libsum.sum(a, b)             # call the sum function
