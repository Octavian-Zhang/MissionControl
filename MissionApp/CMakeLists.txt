# CMakeList.txt : CMake project for mission application, include source and define
# project specific logic here.
#
cmake_minimum_required(VERSION 3.5.0)
configure_file(version.h.config version.h)

# add compiler option to use C++ 17 features
set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_EXTENSIONS OFF)

# set preprocessor flag to include pthread
set(THREADS_PREFER_PTHREAD_FLAG ON)
find_package(Threads REQUIRED)

# define runtime output path
set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${PROJECT_SOURCE_DIR}/runtime)

# include the mission application include directory
include_directories (
    ${CMAKE_CURRENT_SOURCE_DIR}/include 
    ${CMAKE_CURRENT_BINARY_DIR}
)

# add the mission algorithm library
list (APPEND EXTRA_LIBS MissionAlg)

# glob source code files
file(GLOB_RECURSE MISSIONALG_SRC ${CMAKE_CURRENT_SOURCE_DIR}/src/*)

# add source to this project's executable.
add_executable(${PROJECT_NAME} ${MISSIONALG_SRC})

# Define target link libraries
target_link_libraries (${PROJECT_NAME} ${EXTRA_LIBS} rt dl Threads::Threads -static)