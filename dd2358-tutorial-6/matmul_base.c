#include "matmul.h"

void matmul(double *restrict c,
	    const double *restrict a,
	    const double *restrict b, int n)
{
  int i,j,k;
  for(i = 0; i < n; i++)
    for(j = 0; j < n; j++)
      for(k = 0; k < n; k++)
	c[i * n + j] += a[i * n + k] * b[j + k * n];
}
