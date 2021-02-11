import ctypes
_libsum = ctypes.CDLL('libsum.so')
_libsum.sum.argtypes = [ctypes.c_double, ctypes.c_double]
_libsum.sum.restype = ctypes.c_double
_libsum.sum(ctypes.c_double(3.1), ctypes.c_double(3.3))
