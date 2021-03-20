cmake_minimum_required(VERSION 3.5.0)
project(SwarmCircleFormation VERSION 0.1.0)

add_compile_options(-DDEFAULT_BUFFER_SIZE=65536)

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++11 -lpthread -g -pthread")
SET(CMAKE_BUILD_TYPE "Debug")
SET(CMAKE_CXX_FLAGS_DEBUG "$ENV{CXXFLAGS} -O0 -Wall -g2 -ggdb")
SET(CMAKE_CXX_FLAGS_RELEASE "$ENV{CXXFLAGS} -O3 -Wall")
set(LIBRARY_OUTPUT_PATH ${PROJECT_SOURCE_DIR}/lib)

find_package(Boost REQUIRED COMPONENTS regex)
find_package(Threads REQUIRED)
find_package(PkgConfig)

include_directories(
	${PROJECT_SOURCE_DIR}/include
	/usr/include/aarch64-linux-gnu
)
file(GLOB_RECURSE SWARMCIRCLE_SRC_CPP "src/*.cpp")
file(GLOB_RECURSE SWARMCIRCLE_SRC_C "src/*.c")

link_directories(
	#${PROJECT_SOURCE_DIR}/lib
	/usr/lib/aarch64-linux-gnu
	${CMAKE_BINARY_DIR}/generated
)
#add_library(UavPlane SHARED src/geometry.cpp src/ObstacleAvoidance.cpp src/position.cpp)
#add_library(UavPlane STATIC src/geometry.cpp 
#			   src/ObstacleAvoidance.cpp src/position.cpp src/video_capture.cpp src/mnet.cpp
#			   src/plugin_factory.cpp)

#add_library(SwarmCircleFmAlg SHARED ${SWARMCIRCLE_SRC_CPP} ${SWARMCIRCLE_SRC_C})

add_executable(${PROJECT_NAME} ${SWARMCIRCLE_SRC_CPP} ${SWARMCIRCLE_SRC_C})

#target_link_libraries(${PROJECT_NAME})
