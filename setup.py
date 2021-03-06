import os
from distutils.core import setup, Extension

os.environ["CC"] = "clang"
os.environ["CXX"] = "clang++"

source_dir = "cpp_backend"

sources = ["a_star.cpp",
           "cpp_backend_module.cpp",
           "get_neighbours.cpp",
           "get_sequence.cpp",
           "heuristics.cpp"]
sources = [os.path.join(source_dir, source) for source in sources]

cpp_backend = Extension("cpp_backend",
                        sources=sources,
                        extra_compile_args=["-std=c++11"])

setup(name="cpp_backend",
      version="1.0",
      description="Ah yes, enslaved C++",
      ext_modules=[cpp_backend])
