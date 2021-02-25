#include "matmul.h"
#include "cblas.h"

void matmul(double *restrict c,
	    const double *restrict a,
	    const double *restrict b, int n)
{
  const double alpha = 1.0;
  const double beta = 0.0;
  const int lda = n;
  const int ldb = n;
  const int ldc = n;

  cblas_dgemm(CblasRowMajor, CblasNoTrans, CblasNoTrans,
	      n, n, n, alpha, a, lda, b, ldb, beta, c, ldc);
}
