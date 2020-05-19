cmake_minimum_required(VERSION 3.1)

set (CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++17")
set (CMAKE_CXX_STANDARD_REQUIRED on)

project(MyGame)

configure_file(src/config.h.in config.h @ONLY)

find_package(nlohmann_json REQUIRED)
find_package(GTest REQUIRED)

include_directories (${GTEST_INCLUDE_DIRS})

set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${MyGame_SOURCE_DIR}/bin)
set(CMAKE_LIBRARY_OUTPUT_DIRECTORY ${MyGame_SOURCE_DIR}/lib)

include_directories(.)

# add_subdirectory(factories)
# add_subdirectory(units)
# add_subdirectory(parser)
# add_subdirectory(buildings)

add_subdirectory(parser)
add_subdirectory(creating)
add_subdirectory(field)
add_subdirectory(game_module)

add_executable(Main src/main.cpp)

add_executable(Test tests/main_test.cpp)

target_link_libraries(Main 
                      game_units
                      game_info_parser
                      game_buildings
                      nlohmann_json::nlohmann_json)

target_link_libraries(Test
                      game_units
                      game_info_parser
                      game_buildings
                      nlohmann_json::nlohmann_json
                      ${GTEST_LIBRARIES} Threads::Threads)

include_directories(${CMAKE_CURRENT_BINARY_DIR})