#pragma once

#include <iostream>
#include <vector>
#include "client/Request.h"


class MainMenu
{
private:
    static const std::vector<std::string> main_choices;
    
    static const std::vector<std::string> game_choices;

    bool is_playing;
    int choices_pos;

public:
    MainMenu();
    int getKey(Request);
    bool isPlaying();

    ~MainMenu() = default;

    friend class Drawer;
};