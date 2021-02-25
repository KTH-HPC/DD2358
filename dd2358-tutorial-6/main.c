#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <sys/time.h>
#include <math.h>
#include "matmul.h"

double gettime(void) 
{
  struct timeval tv;
  gettimeofday(&tv,NULL);
  return tv.tv_sec + 1e-6*tv.tv_usec;
}

int main(int argc, char **argv)
{
  int i;
  if (argc < 2) {
    fprintf(stderr, "Usage: %s <size>\n", argv[0]);
    exit(-1);
  }
  
  const int m = atoi(argv[1]);

  double *A = (double *) malloc( m * m * sizeof(double));
  double *B = (double *) malloc( m * m * sizeof(double));
  double *C = (double *) malloc( m * m * sizeof(double));
  
  memset(A, 1, m * m * sizeof(double));
  memset(B, 2, m * m * sizeof(double));
  memset(C, 0, m * m * sizeof(double));
  
  double t = gettime();
  for(i = 0; i < 100; i++)
    matmul(C, A, B, m);
  t = gettime() - t;

  printf("%d\t%f\t%E\n", m, t, 100 * 2 * pow(m, 3) / t);

  free(A);
  free(B);
  free(C);
  return 0;
}
