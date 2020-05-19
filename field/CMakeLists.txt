cmake_minimum_required(VERSION 3.0)
project(FieldBlock)

set(
    FILES
    FieldCell.cpp
    Field.cpp
)

add_library(game_field SHARED ${FILES})
target_link_libraries(game_field 
                      game_buildings)