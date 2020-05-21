#include "Game.h"
#include "field/MapProperties.h"
#include "parser/Parser.h"

Game::Game() :
    field(Parser::getMap())
{
    game_status = GameStatus::GameBegin;
    /* do smth maybe */

    field.cells[2][2].unit = std::make_shared<Unit>("Swordman", 5.0, 2, "Russian");
    field.cells[17][17].unit = std::make_shared<Unit>("Swordman", 7.0, 2, "England");
    field.buildBuilding({2, 2});
    field.buildBuilding({17, 17});

    /* end of smth */
    game_status = GameStatus::Move;
}

int Game::getResource(Coordinates pos)
{
    return field.getResource(pos);
}

const FieldCell& Game::getCell(Coordinates pos)
{
    return field.getCell(pos);
}

size_t Game::fieldSize() const
{
    return field.fieldSize();
}

void Game::moveUnit(Coordinates from, Coordinates to)
{
    field.cells[to.y][to.x].unit = std::move(field.cells[from.y][from.x].unit);
}