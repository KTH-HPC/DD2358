# 1. define the minimum CMake version
cmake_minimum_required(VERSION 3.1)

# 2. create a new C project
project(DD2356-tutorial VERSION 1.0
                        DESCRIPTION "CMake Tutorial"
                        LANGUAGES C)

# 3. set C compiler
set(CMAKE_C_COMPILER gcc)

# 4. add the source files that are needed to build an exe
add_executable(main.out # our executable is the target
    src/main.c
    src/sum.c
    src/product.c
    src/division.c
    src/power.c)

# 5. set output target properties
set_target_properties(main.out
    PROPERTIES
    ARCHIVE_OUTPUT_DIRECTORY "lib/"
    LIBRARY_OUTPUT_DIRECTORY "lib/"
    RUNTIME_OUTPUT_DIRECTORY "bin/"
)

# 6. find the math library
find_library(MATH_LIBRARY m)
if(MATH_LIBRARY)
    # link target with math library
    target_link_libraries(main.out PRIVATE ${MATH_LIBRARY})
endif()

# 7. define header file path
target_include_directories(main.out PRIVATE include)

# 8. set to use C11 features
target_compile_features(main.out PRIVATE c_std_11)

# 9. set compiler options
target_compile_options(main.out PRIVATE -Wall -O3)

# 10. specify what to install when we run 'make install'
install(TARGETS main.out DESTINATION bin) 
