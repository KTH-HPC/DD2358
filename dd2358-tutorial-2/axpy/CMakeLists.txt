cmake_minimum_required(VERSION 3.4...3.18)
project(math_kernels)

add_subdirectory(pybind11)
pybind11_add_module(math_kernels math_kernels.cc)

target_compile_options(math_kernels PRIVATE -g -Wall -O3)
