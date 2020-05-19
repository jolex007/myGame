#pragma once

#include "field/Field.h"
#include "field/FieldCell.h"

class Game
{
private:
    enum GameStatus {
        GameBegin,
        Move,
        EndingMove
    };

    Field field;
    size_t pos_x;
    size_t pos_y;
    size_t player_move;
    size_t players_number;
    GameStatus game_status;

public:
    Game() = delete;
    Game(size_t);

    void changePos(size_t, size_t);
    const FieldCell& getCell();
};