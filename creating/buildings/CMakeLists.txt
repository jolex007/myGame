cmake_minimum_required(VERSION 3.0)
project(Building)

set(
    FILES
    Building.cpp
    BuildingFactory.cpp
)

add_library(game_buildings SHARED ${FILES})
target_link_libraries(game_buildings
                      game_units
                      nlohmann_json::nlohmann_json)
