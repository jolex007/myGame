cmake_minimum_required(VERSION 3.0)
project(ClientBlock)

set(
    FILES
    Client.cpp
    # EventQueue.cpp
    Handler.cpp
)

add_subdirectory(menu)

add_library(game_queue SHARED EventQueue.cpp)

add_library(game_client SHARED ${FILES})
target_link_libraries(game_client 
                      game_queue
                      game_client_menu
                      game_game_module
                      game_graphics)