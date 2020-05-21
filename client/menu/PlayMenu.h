#pragma once

#include <iostream>
#include "game_module/Game.h"
#include "client/Request.h"

class PlayMenu
{
private:
    std::shared_ptr<Game> game;
    Coordinates pos;
    Coordinates selected;
    bool is_selected;

    void select();
    void moveUnit(Coordinates, Coordinates);

public:
    PlayMenu() = delete;
    PlayMenu(std::shared_ptr<Game>);

    int getKey(Request);

    ~PlayMenu() = default;

    friend class Drawer;
};