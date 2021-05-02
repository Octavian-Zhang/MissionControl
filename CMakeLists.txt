# Top-level CMake project file, do global configuration
# and include sub-projects here.

cmake_minimum_required(VERSION 3.5.0)

# declare project name and version number
project(MissionControl VERSION 2.398)

# set project name and version number flag
set(CPACK_PROJECT_NAME ${PROJECT_NAME})
set(CPACK_PROJECT_VERSION ${PROJECT_VERSION})

# set optimization and warning options
SET(CMAKE_CXX_FLAGS_DEBUG "$ENV{CXXFLAGS} -Wall -ggdb")
SET(CMAKE_CXX_FLAGS_RELEASE "$ENV{CXXFLAGS} -O3 -Wall")

# set build type
SET(CMAKE_BUILD_TYPE "Debug")

# Include sub-projects.
add_subdirectory (MissionAlg)
add_subdirectory(MissionApp)