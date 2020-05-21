#pragma once

#include <iostream>
#include <vector>
#include "menu/MainMenu.h"
#include "menu/PlayMenu.h"

class Client
{
private:
    enum MenuType {
        MAINMenu,
        PLAYMenu
    };

    std::shared_ptr<MainMenu> main_menu;
    std::vector<std::shared_ptr<PlayMenu> > play_menu;
    MenuType curr_menu_type;

    void changeMenu();
    void createNewGame();
    void closeGame();
    static bool isFirstPlayerKey(Key);


public:
    Client();
    void run();
};