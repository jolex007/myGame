cmake_minimum_required(VERSION 3.0)
project(GameUnits)

set(
    FILES
    Unit.cpp
    Factory.cpp
)

add_library(game_units SHARED ${FILES})

target_link_libraries(game_units
                      game_info_parser)