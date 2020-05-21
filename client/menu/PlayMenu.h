#pragma once

#include <iostream>
#include "game_module/Game.h"
#include "client/Request.h"

class PlayMenu
{
private:
    std::shared_ptr<Game> game;
    Coordinates pos;
    // TODO: player_id

public:
    PlayMenu() = delete;
    PlayMenu(std::shared_ptr<Game>);

    int getKey(Request);

    ~PlayMenu() = default;

    friend class Drawer;
};