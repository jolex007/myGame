#pragma once

#include <iostream>
#include <vector>
#include "client/menu/PlayMenu.h"
#include "client/menu/MainMenu.h"

class Drawer
{
private:
    static void clearConsole();
    static const std::string red;
    static const std::string green;
    static const std::string yellow;
    static const std::string magenta;
    static const std::string underline;
    static const std::string reset;

public:
    static void draw(std::shared_ptr<MainMenu>);
    static void draw(std::vector<std::shared_ptr<PlayMenu>>);
};