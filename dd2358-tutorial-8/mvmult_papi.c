#include <papi.h>
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

#define PAPI_CALL(fn, ok_code) do { \
	if (ok_code != fn) { \
		fprintf(stderr, "Error: " #fn " failed, aborting\n"); \
		exit(1); \
	} \
} while (0)

#define NEV 2

int main(int argc, char **argv) {
	int n=1000,trans=0;
	if (argc > 1) 
		n = strtol(argv[1], NULL, 10); 
	if (argc > 2) 
		trans = (argv[2][0] == 't');
	int evset = PAPI_NULL;

	PAPI_CALL(PAPI_library_init(PAPI_VER_CURRENT), PAPI_VER_CURRENT); 
	PAPI_CALL(PAPI_create_eventset(&evset), PAPI_OK); 
	PAPI_CALL(PAPI_add_event(evset, PAPI_DP_OPS), PAPI_OK); 
	PAPI_CALL(PAPI_add_event(evset, PAPI_VEC_DP), PAPI_OK);

	double *m, *v, *p;
	PAPI_CALL(PAPI_start(evset), PAPI_OK);

	init(n, &m, &v, &p, trans);
	long long v1[NEV], v2[NEV], v3[NEV];
	PAPI_CALL(PAPI_read(evset, v1), PAPI_OK);
	mult(n, m, v, p, trans);
	PAPI_CALL(PAPI_read(evset, v2), PAPI_OK);
	double s = cblas_dasum(n, p, 1);
	PAPI_CALL(PAPI_stop(evset, v3), PAPI_OK);
	printf("Size %d; abs. sum: %f (expected: %d)\n", n, s, (n+1)/2); 
	printf("PAPI counts:\n");
	printf(" init: event1: %15lld event2: %15lld\n", v1[0], v1[1]);
	printf(" mult: event1: %15lld event2: %15lld\n", v2[0]-v1[0], v2[1]-v1[1]); 
	printf(" sum: event1: %15lld event2: %15lld\n", v3[0]-v2[0], v3[1]-v2[1]); 

	return 0;

 }
