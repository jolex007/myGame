#include "MainMenu.h"

const std::vector<std::string> MainMenu::main_choices {"new game",
                                                       "exit"};

const std::vector<std::string> MainMenu::game_choices = {"continue",
                                                         "exit"};

MainMenu::MainMenu() :
    is_playing(false), choices_pos(0) {}

bool MainMenu::isPlaying()
{
    return is_playing;
}

// 0 - nothing to do
// 1 - change menu
// 2 - create new game
// 3 - exit from game
// 4 - exit from porgramm
int MainMenu::getKey(Request request)
{
    switch(request.key) {
        case Key::UpArrow:
        case Key::WKey:
            if (is_playing) {
                choices_pos = (choices_pos - 1) % game_choices.size();
            } else {
                choices_pos = (choices_pos - 1) % main_choices.size();
            }
            break;
        
        case Key::DownArrow:
        case Key::SKey:
            if (is_playing) {
                choices_pos = (choices_pos + 1) % game_choices.size();
            } else {
                choices_pos = (choices_pos + 1) % main_choices.size();
            }
            break;

        case Key::EnterKey:
            if (is_playing) {
                if (choices_pos == 0) {
                    return 1;
                } else if (choices_pos == 1) {
                    is_playing = false;
                    return 3;
                }
            } else {
                if (choices_pos == 0) {
                    is_playing = true;
                    return 2;
                } else if (choices_pos == 1) {
                    return 4;
                }
            }

        default:
            return 0;
            break;
    };

    // std::cout << "pos: " << choices_pos << std::endl;

    return 0;
}