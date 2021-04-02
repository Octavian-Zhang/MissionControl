cmake_minimum_required(VERSION 3.5.0)

# add compiler option to use C++11 features
add_compile_options(-std=c++11)

# set preprocessor flag to include pthread
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -g -pthread")

# include the mission application include directory
include_directories (${CMAKE_CURRENT_SOURCE_DIR}/include)

# add the mission algorithm library
list (APPEND EXTRA_LIBS MissionAlg)

# glob source code files
file(GLOB_RECURSE MISSIONAPP_SRC_CPP "src/*.cpp")
file(GLOB_RECURSE MISSIONAPP_SRC_C "src/*.c")

# add source to this project's executable.
add_executable(${PROJECT_NAME} ${MISSIONAPP_SRC_CPP} ${MISSIONAPP_SRC_C})

# Define target link libraries
target_link_libraries (${PROJECT_NAME} ${EXTRA_LIBS})