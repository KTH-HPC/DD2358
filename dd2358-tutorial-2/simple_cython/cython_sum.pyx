cdef double cython_sum(double a, double b): # define a callable function within Cython with cdef
  return a + b

cpdef double sum(double a, double b):       # define a wrapper function callable by Python with cpdef
  return cython_sum(a, b)
