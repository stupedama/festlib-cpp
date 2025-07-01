cmake_minimum_required(VERSION 3.15...4.0)

# Use C++17
set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_EXTENSIONS OFF)

set(CMAKE_CXX_FLAGS_DEBUG "${CMAKE_CXX_FLAGS_DEBUG} -Wall -Wpedantic -pedantic-errors -fexceptions")
set(CMAKE_CXX_FLAGS_RELEASE "${CMAKE_CXX_FLAGS_RELEASE} -O2 -Wall -Wpedantic -Werror -Wshadow -Wextra -pedantic-errors -fexceptions")

project(
    festlib
    VERSION 0.3.0
    DESCRIPTION "Library for reading FEST xml file from Legemiddelverket"
    LANGUAGES CXX)

include_directories(${CMAKE_SOURCE_DIR}/include)

find_package(pugixml CONFIG REQUIRED)

add_subdirectory(src)

target_include_directories(${PROJECT_NAME} PUBLIC
    $<BUILD_INTERFACE:${CMAKE_CURRENT_SOURCE_DIR}/include>
    $<INSTALL_INTERFACE:include/${PROJECT_NAME}>)

target_link_libraries(${PROJECT_NAME} pugixml::pugixml)

if(ENABLE_TESTING)
  enable_testing()
  message(STATUS "Building tests. Look at /tests for unit tests.")
  add_subdirectory(tests)
  target_compile_definitions(festlib PUBLIC ENABLE_TESTING)
endif()

## Install library
install(TARGETS ${PROJECT_NAME} DESTINATION lib)

## Install library headers
file(GLOB HEADERS include/*.h)
install(FILES ${HEADERS} DESTINATION include/${PROJECT_NAME})

