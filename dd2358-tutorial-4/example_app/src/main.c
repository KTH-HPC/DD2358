#include <stdio.h>

#include "sum.h"
#include "product.h"
#include "division.h"
#include "power.h"

int main(int argc, char *argv[])
{
  printf("%f\n", sum(2, 2));
  printf("%f\n", product(2, 2));
  printf("%f\n", division(4, 2));
  printf("%f\n", power(4, 2));

  return 0;
}
