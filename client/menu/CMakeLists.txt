cmake_minimum_required(VERSION 3.0)
project(ClientMenuBlock)

set(
    FILES
    PlayMenu.cpp
    MainMenu.cpp
)

add_library(game_client_menu SHARED ${FILES})
target_link_libraries(game_client_menu
                      game_game_module)