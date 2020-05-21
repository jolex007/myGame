cmake_minimum_required(VERSION 3.0)
project(FieldBlock)

set(
    FILES
    Game.cpp
)

add_library(game_game_module SHARED ${FILES})
target_link_libraries(game_game_module 
                      game_field
                      game_info_parser)