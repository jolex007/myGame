#include "PlayMenu.h"

PlayMenu::PlayMenu(std::shared_ptr<Game> game_ptr) :
    game(game_ptr), pos({0, 0}), selected({0, 0}), is_selected(false) {}

void PlayMenu::moveUnit(Coordinates from, Coordinates to)
{
    if (game->getCell(from).unit == nullptr) {
        return;
    }
    if (Coordinates::dist(from, to) > game->getCell(from).unit->getSteps()) {
        return;
    }

    game->moveUnit(from, to);
}

void PlayMenu::select()
{
    if (is_selected) {
        if (selected != pos) {
            moveUnit(selected, pos);
        }
        is_selected = false;
    } else {
        if (game->getCell(pos).unit != nullptr && game->getCell(pos).resources == Relief::Coin) {
            /* save it */ game->getResource(pos);
        } else {
            selected = pos;
            is_selected = true;
        }
    }
}

// 0 - nothing to do
int PlayMenu::getKey(Request request)
{
    switch(request.key) {
        case Key::UpArrow:
        case Key::WKey:
            pos.y -= (pos.y > 0 ? 1 : 0);
            return 0;
            break;
        
        case Key::DownArrow:
        case Key::SKey:
            pos.y += (pos.y < game->fieldSize() - 1 ? 1 : 0);
            return 0;
            break;
        
        case Key::LeftArrow:
        case Key::AKey:
            pos.x -= (pos.x > 0 ? 1 : 0);
            return 0;
            break;
        
        case Key::RightArrow:
        case Key::DKey:
            pos.x += (pos.x < game->fieldSize() - 1 ? 1 : 0);
            return 0;
            break;
        
        case Key::SpaceKey:
        case Key::EnterKey:
            select();

            break;
    }

    
    return 0;
}

