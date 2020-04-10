cmake_minimum_required(VERSION 3.0)
project(GameUnits)

set(
    FILES
    Unit.cpp
    UnitTypes.cpp
)

add_library(game_units SHARED ${FILES})