cmake_minimum_required(VERSION 3.1)

set (CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++17")
set (CMAKE_CXX_STANDARD_REQUIRED on)

project(MyGame)

configure_file(config.h.in config.h @ONLY)

find_package(nlohmann_json REQUIRED)
find_package(GTest REQUIRED)

include_directories (${GTEST_INCLUDE_DIRS})

set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${MyGame_SOURCE_DIR}/bin)
set(CMAKE_LIBRARY_OUTPUT_DIRECTORY ${MyGame_SOURCE_DIR}/lib)

add_subdirectory(factories)
add_subdirectory(units)
add_subdirectory(parser)

include_directories(factories units parser)

add_executable(Main main.cpp)

add_executable(Test main_test.cpp)

target_link_libraries(Main 
                      game_units
                      game_factories
                      game_info_parser
                      nlohmann_json::nlohmann_json)

target_link_libraries(Test
                      game_units
                      game_factories
                      game_info_parser
                      nlohmann_json::nlohmann_json
                      ${GTEST_LIBRARIES} Threads::Threads)

include_directories(${CMAKE_CURRENT_BINARY_DIR})