#include "PlayMenu.h"

PlayMenu::PlayMenu(std::shared_ptr<Game> game_ptr) :
    game(game_ptr) {}

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
    }

    
    return 0;
}

