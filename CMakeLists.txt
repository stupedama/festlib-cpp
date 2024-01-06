cmake_minimum_required(VERSION 3.16...3.26)

# Use C++17
set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_EXTENSIONS OFF)

set(CMAKE_CXX_FLAGS_DEBUG "${CMAKE_CXX_FLAGS_DEBUG} -Wall -Wpedantic -fexceptions")
set(CMAKE_CXX_FLAGS_RELEASE "${CMAKE_CXX_FLAGS_RELEASE} -O2 -Wall -Wpedantic -fexceptions")

project(
    festlib
    VERSION 0.1.0
    DESCRIPTION "Library for reading FEST xml file from Legemiddelverket"
    LANGUAGES CXX)

include(CTest)
include_directories(${CMAKE_SOURCE_DIR}/include)

find_package(pugixml CONFIG REQUIRED)

add_subdirectory(src)

if(ENABLE_TESTING)
  enable_testing()
  message(STATUS "Building tests. Look at /tests for unit tests.")
  add_subdirectory(tests)
endif()
