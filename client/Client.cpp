#include "Client.h"
#include "EventQueue.h"
#include "field/Field.h"
#include "game_module/Game.h"
#include "graphics/Drawer.h"

Client::Client() :
    main_menu(std::make_shared<MainMenu>()), curr_menu_type(MenuType::MAINMenu) {}

void Client::changeMenu()
{
    if (curr_menu_type == MenuType::MAINMenu) {
        curr_menu_type = MenuType::PLAYMenu;
    } else {
        curr_menu_type = MenuType::MAINMenu;
    }
}

void Client::createNewGame()
{
    play_menu.clear();
    std::shared_ptr<Game> game_ptr = std::make_shared<Game>();
    play_menu.emplace_back(std::make_shared<PlayMenu>(game_ptr));
    play_menu.emplace_back(std::make_shared<PlayMenu>(game_ptr));
    changeMenu();
}

void Client::closeGame()
{
    std::cout << "DEBUG\n";
    play_menu.clear();
    curr_menu_type = MenuType::MAINMenu;
    // TODO: I dont know what
}

bool Client::isFirstPlayerKey(Key key)
{
    if (key == Key::WKey ||
        key == Key::AKey ||
        key == Key::SKey ||
        key == Key::DKey || 
        key == Key::SpaceKey) {

        return true;
    } else {
        return false;
    }
}

void Client::run()
{
    Drawer::draw(main_menu);
    while (true) {
        if (EventQueue::Empty()) {
            continue;
        }

        Request request = EventQueue::Pop();

        if (curr_menu_type == MenuType::MAINMenu) {
            int result = main_menu->getKey(request);
            if (result == 0) {
                // nothing to do
            } else if (result == 1) {
                // change menu
                changeMenu();
            } else if (result == 2) {
                // create new game
                createNewGame();
            } else if (result == 3) {
                // exit from game
                closeGame();
            } else if (result == 4) {
                // exit from programm
                return;
            }
        } else if (curr_menu_type == MenuType::PLAYMenu) {
            int result = 0;
            if (request.key == Key::EscKey) {
                changeMenu();
            } else if (Client::isFirstPlayerKey(request.key)) {
                result = play_menu[0]->getKey(request);
            } else if (!Client::isFirstPlayerKey(request.key)) {
                result = play_menu[1]->getKey(request);
            }

        }

        // Draw
        if (curr_menu_type == MenuType::MAINMenu) {
            Drawer::draw(main_menu);
        } else if (curr_menu_type == MenuType::PLAYMenu) {
            Drawer::draw(play_menu);
        }
    }
}

