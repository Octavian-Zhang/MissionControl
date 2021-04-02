cmake_minimum_required(VERSION 3.5.0)
project(MissionControl VERSION 0.1.0)

SET(CMAKE_BUILD_TYPE "Debug")
SET(CMAKE_CXX_FLAGS_DEBUG "$ENV{CXXFLAGS} -O0 -Wall -ggdb")
SET(CMAKE_CXX_FLAGS_RELEASE "$ENV{CXXFLAGS} -O3 -Wall")

# Include sub-projects.
add_subdirectory (MissionAlg)
add_subdirectory(MissionApp)