from setuptools import setup
from setuptools.extension import Extension
from Cython.Build import cythonize

ext = Extension(name="sum", sources=["cython_sum.pyx"], libraries=["sum"])
setup(ext_modules=cythonize(ext))
