#include <stdio.h>
#include <stdlib.h>
#include <cblas.h>
#include <time.h>

void init(int n, double **m, double **v, double **p, int trans) {
	*m = calloc(n*n, sizeof(double));
	*v = calloc(n, sizeof(double));
	*p = calloc(n, sizeof(double));
	for (int i = 0; i < n; i++) {
		(*v)[i] = (i & 1)? -1.0: 1.0;
		if (trans) 
			for (int j = 0; j <= i; j++) 
				(*m)[j*n+i] = 1.0;
		else 
			for (int j = 0; j <= i; j++) 
				(*m)[i*n+j] = 1.0;
	}
}

void mult(int size, double *m, double *v, double *p, int trans) {
	int stride = trans? size: 1;
	for (int i = 0; i < size; i++) {
		int mi = trans? i: i*size;
		p[i] = cblas_ddot(size, m+mi, stride, v, 1);
	}
}


double sec(struct timespec *ts) {
	return ts->tv_sec+1e-9*ts->tv_nsec;
}



int main(int argc, char **argv) {
	struct timespec t0, t1, t2, t3, t4;
	clock_gettime(CLOCK_MONOTONIC, &t0);
	int n = 1000, trans = 0;
	if (argc > 1) 
		n = strtol(argv[1], NULL, 10);
	if (argc > 2) 
		trans = (argv[2][0] == 't');
	double *m, *v, *p;
	clock_gettime(CLOCK_MONOTONIC, &t1);
	init(n, &m, &v, &p, trans);
	clock_gettime(CLOCK_MONOTONIC, &t2);
	mult(n, m, v, p, trans);
	clock_gettime(CLOCK_MONOTONIC, &t3);
	double s = cblas_dasum(n, p, 1);
	clock_gettime(CLOCK_MONOTONIC, &t4);

	printf("Size %d; abs. sum: %f (expected: %d)\n", n, s, (n+1)/2);
	printf("Timings:\n program: %f s\n", sec(&t4)-sec(&t0));
	printf(" init: %f s\n mult: %f s\n sum: %f s\n",sec(&t2)-sec(&t1), sec(&t3)-sec(&t2), sec(&t4)-sec(&t3));

	return 0;

}