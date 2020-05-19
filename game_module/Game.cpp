#include "Game.h"

Game::Game(size_t players_number) :
    players_number(players_number) 
{
    game_status = GameStatus::GameBegin;
    pos_x = 0;
    pos_y = 0;
    player_move = 0;

    /* TODO: do smth with field */
}


void Game::changePos(size_t new_x, size_t new_y)
{
    pos_x = new_x;
    pos_y = new_y;
}

const FieldCell& Game::getCell()
{
    return field.getCell(pos_x, pos_y);
}