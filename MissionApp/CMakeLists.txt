# CMakeList.txt : CMake project for mission application, include source and define
# project specific logic here.
#
cmake_minimum_required(VERSION 3.5.0)

# add compiler option to use C++11 features
set (CMAKE_CXX_STANDARD 11)

# set preprocessor flag to include pthread
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -g -pthread")

# define runtime output path
set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${PROJECT_SOURCE_DIR}/runtime)

# include the mission application include directory
include_directories (${CMAKE_CURRENT_SOURCE_DIR}/include)

# add the mission algorithm library
list (APPEND EXTRA_LIBS MissionAlg)

# glob source code files
file(GLOB_RECURSE MISSIONALG_SRC ${CMAKE_CURRENT_SOURCE_DIR}/src/*)

# add source to this project's executable.
add_executable(${PROJECT_NAME} ${MISSIONALG_SRC})

# Define target link libraries
target_link_libraries (${PROJECT_NAME} ${EXTRA_LIBS} rt)