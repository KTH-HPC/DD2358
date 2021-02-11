#include "sum.h"
#include <pybind11/pybind11.h>
#include <pybind11/numpy.h>     // Include the Pybind11 header

double sum(double a, double b)
{
  printf("hello world from sum()\n");
  return a + b;
}

/* name of module-   ---a variable with type py::module_ to create the binding */
/*               |   |                                                                                                */
/*               v   v                                                                                               */
PYBIND11_MODULE(sum, m) {                            // Create a module using the PYBIND11_MODULE macro
    m.doc() = "pybind11 sum module";
    m.def("sum", &sum, "sum two numbers in double"); // calls module::def() to create generate binding code that exposes sum()
}
