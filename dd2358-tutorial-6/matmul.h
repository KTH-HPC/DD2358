#define restrict __restrict__

void matmul(double* restrict c, 
	    const double* restrict a, 
	    const double* restrict b, int n);
