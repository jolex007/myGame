#pragma once

#include "field/Field.h"
#include "field/FieldCell.h"
#include "field/MapProperties.h"

class Game
{
private:
    enum GameStatus {
        GameBegin,
        Move,
        EndingMove
    };

    Field field;
    GameStatus game_status;

public:
    Game();

    const FieldCell& getCell(Coordinates);
    size_t fieldSize() const;
    
};