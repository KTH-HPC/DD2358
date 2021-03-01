import numpy as np
from matrix import gemm

a = np.random.random([4,4])
b = np.random.random([4,4])
c = np.random.random([4,4])

d = np.matmul(a, b)
gemm(c, a, b)

print(c - d)
print(np.abs(c-d).flatten().max())
