#include <pybind11/pybind11.h>
#include <pybind11/numpy.h>    // Include header that supports Numpy arrays

namespace py = pybind11;

template <typename T>
void axpy(size_t n, T a, T *x, T *y)
{
  for (size_t i = 0; i < n; i++)
    y[i] = a * x[i] + y[i];
}

template <typename T>
void axpy_wrapper(T a, py::array_t<T> py_x, py::array_t<T> py_y)
{
  // Request for buffer information
  py::buffer_info x_buffer = py_x.request();
  py::buffer_info y_buffer = py_y.request();

  // check dim
  if (x_buffer.ndim != 1 || y_buffer.ndim != 1) {
    throw std::runtime_error("Error: dimension of vector should be 1");
  }

  // check shape match
  if (x_buffer.shape[0] != y_buffer.shape[0]) {
    throw std::runtime_error("Error: size of X and Y not match");
  }

  // extract raw pointer
  T *x = (T*)x_buffer.ptr;
  T *y = (T*)y_buffer.ptr;
  
  return axpy<T>(x_buffer.shape[0], a, x, y);
}

PYBIND11_MODULE(math_kernels, m)
{
  m.def("axpy", &axpy_wrapper<float>,  py::arg("a"), py::arg("x").noconvert(true), py::arg("y").noconvert(true));
  m.def("axpy", &axpy_wrapper<double>, py::arg("a"), py::arg("x").noconvert(true), py::arg("y").noconvert(true));
}
