cmake_minimum_required(VERSION 3.0)
project(GameInfoParser)

set(
    FILES
    Factory.cpp
)

add_library(game_factories SHARED ${FILES})
target_link_libraries(game_factories 
                      game_units
                      game_info_parser
                      nlohmann_json::nlohmann_json)
