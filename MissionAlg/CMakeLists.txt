# CMakeList.txt : CMake project for mission algorithm, include source and define
# project specific logic here.
#
cmake_minimum_required(VERSION 3.5.0)

# add compiler option to use C++ 17 features
set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_EXTENSIONS OFF)

# add compiler option to change default MAT logging buffer size
add_compile_options(-DDEFAULT_BUFFER_SIZE=65536 -DPORTABLE_WORDSIZES -DIS_NOT_MATLAB_HOST)

# define library output path
set(CMAKE_LIBRARY_OUTPUT_DIRECTORY ${PROJECT_SOURCE_DIR}/lib)

# include the mission algorithm include directory
include_directories (${CMAKE_CURRENT_SOURCE_DIR}/include)

# glob source code files
file(GLOB_RECURSE MISSIONALG_SRC ${CMAKE_CURRENT_SOURCE_DIR}/src/*)

# add source to this project's shared library.
add_library (MissionAlg ${MISSIONALG_SRC})

# state that anybody linking to us needs to include the current source dir
# to find necessary headers, while we don't.
target_include_directories (MissionAlg INTERFACE ${CMAKE_CURRENT_SOURCE_DIR}/include)