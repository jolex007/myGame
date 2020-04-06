cmake_minimum_required(VERSION 3.0)
project(GameFactories)

set(
    FILES
    UnitFactory.cpp
    RussianUnitFactory.cpp
    EnglandUnitFactory.cpp
)

add_library(game_factories SHARED ${FILES})
target_link_libraries(game_factories game_units)