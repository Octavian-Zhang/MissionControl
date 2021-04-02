# CMakeList.txt : CMake project for mission algorithm, include source and define
# project specific logic here.
#
cmake_minimum_required(VERSION 3.5.0)

# add compiler option to change default MAT logging buffer size
add_compile_options(-DDEFAULT_BUFFER_SIZE=65536)

# include the mission algorithm include directory
include_directories (${CMAKE_CURRENT_SOURCE_DIR}/include)

file(GLOB_RECURSE MISSIONALG_SRC_CPP "src/*.cpp")
file(GLOB_RECURSE MISSIONALG_SRC_C "src/*.c")

add_library (MissionAlg SHARED 
                ${MISSIONALG_SRC_C}
                ${MISSIONALG_SRC_CPP}
			)

# state that anybody linking to us needs to include the current source dir
# to find necessary headers, while we don't.
target_include_directories (MissionAlg INTERFACE ${CMAKE_CURRENT_SOURCE_DIR}/include)