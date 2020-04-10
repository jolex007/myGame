cmake_minimum_required(VERSION 3.1)

set (CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++17")
set (CMAKE_CXX_STANDARD_REQUIRED on)

project(MyGame)

find_package(nlohmann_json REQUIRED)
find_package(GTest REQUIRED)

set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${MyGame_SOURCE_DIR}/bin)
set(CMAKE_LIBRARY_OUTPUT_DIRECTORY ${MyGame_SOURCE_DIR}/lib)

add_subdirectory(factories)
add_subdirectory(units)
add_subdirectory(parser)

include_directories(factories units parser)

add_executable(Main main.cpp)

target_link_libraries(Main 
                      game_units
                      game_factories
                      game_info_parser
                      nlohmann_json::nlohmann_json)