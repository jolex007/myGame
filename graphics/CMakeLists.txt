cmake_minimum_required(VERSION 3.0)
project(GraphicsBlock)

set(
    FILES
    Drawer.cpp
)

add_library(game_graphics SHARED ${FILES})

target_link_libraries(game_graphics
                      game_client_menu)