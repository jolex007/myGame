cmake_minimum_required(VERSION 3.0)
project(GameInfoParser)

set(
    FILES
    Parser.cpp
)

add_library(game_info_parser SHARED ${FILES})
target_link_libraries(game_info_parser 
                      PRIVATE nlohmann_json::nlohmann_json)