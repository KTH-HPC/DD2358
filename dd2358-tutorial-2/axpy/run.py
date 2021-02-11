import numpy as np
import math_kernels

x = np.random.random(5).astype(np.float32)
y = np.random.random(5).astype(np.float32)
a = 0.5
z = a * x + y
math_kernels.axpy(a, x, y)
print(z, z.dtype)
print(y, y.dtype)
print(y - z)

x = np.random.random(5).astype(np.float64)
y = np.random.random(5).astype(np.float64)
z = a * x + y
math_kernels.axpy(a, x, y)
print(z, z.dtype)
print(y, y.dtype)
print(y - z)
