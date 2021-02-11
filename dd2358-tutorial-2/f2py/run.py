from math_kernels import kernels
import numpy as np
x = np.random.random(5)
y = np.random.random(5)
a = 0.2
z = a * x + y
kernels.axpy(a, x, y)
print(z)
print(y)
