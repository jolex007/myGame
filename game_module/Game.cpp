#include "Game.h"
#include "field/MapProperties.h"
#include "parser/Parser.h"

Game::Game() :
    field(Parser::getMap())
{
    game_status = GameStatus::GameBegin;
    /* do smth maybe */
    game_status = GameStatus::Move;
}

const FieldCell& Game::getCell(Coordinates pos)
{
    return field.getCell(pos);
}

size_t Game::fieldSize() const
{
    return field.fieldSize();
}