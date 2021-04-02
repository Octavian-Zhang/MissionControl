cmake_minimum_required(VERSION 3.5.0)
project(SwarmCircleFormation VERSION 0.1.0)

add_compile_options(-DDEFAULT_BUFFER_SIZE=65536)

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++11 -g -pthread")
SET(CMAKE_BUILD_TYPE "Debug")
SET(CMAKE_CXX_FLAGS_DEBUG "$ENV{CXXFLAGS} -O0 -Wall -ggdb")
SET(CMAKE_CXX_FLAGS_RELEASE "$ENV{CXXFLAGS} -O3 -Wall")
set(LIBRARY_OUTPUT_PATH ${PROJECT_SOURCE_DIR}/lib)

include_directories(
	${PROJECT_SOURCE_DIR}/include
)

file(GLOB_RECURSE SWARMCIRCLE_SRC_CPP "src/*.cpp")
file(GLOB_RECURSE SWARMCIRCLE_SRC_C "src/*.c")

add_executable(${PROJECT_NAME} ${SWARMCIRCLE_SRC_CPP} ${SWARMCIRCLE_SRC_C})