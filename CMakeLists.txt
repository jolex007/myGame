cmake_minimum_required(VERSION 3.1)
project(MyGame)

set (CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++17")
set (CMAKE_CXX_STANDARD_REQUIRED on)

set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${MyGame_SOURCE_DIR}/bin)
set(CMAKE_LIBRARY_OUTPUT_DIRECTORY ${MyGame_SOURCE_DIR}/lib)

add_subdirectory(factories)
add_subdirectory(units)

include_directories(factories units)

add_executable(Main main.cpp)

target_link_libraries(Main game_units game_factories)