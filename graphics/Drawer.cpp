#include "Drawer.h"
#include <iomanip>

const std::string Drawer::red = "\033[1;31m";
const std::string Drawer::green = "\033[1;32m";
const std::string Drawer::yellow = "\033[1;33m";
const std::string Drawer::magenta = "\033[1;35m";
const std::string Drawer::underline = "\033[1;4m";
const std::string Drawer::reset = "\033[0m";

void Drawer::clearConsole()
{
#if defined _WIN32
    system("cls");
#elif defined (__LINUX__) || defined(__gnu_linux__) || defined(__linux__)
    system("clear");
#elif defined (__APPLE__)
    system("clear");
#endif
}

void Drawer::draw(std::shared_ptr<MainMenu> menu)
{
    clearConsole();
    if (menu->is_playing) {
        std::cout << std::setw(10) << (menu->choices_pos == 0 ? ">" : "") <<
                                      (menu->choices_pos == 0 ? red : "") << menu->game_choices[0] << reset << std::endl;
        std::cout << std::setw(10) << (menu->choices_pos == 1 ? ">" : "") << 
                                      (menu->choices_pos == 1 ? red : "") << menu->game_choices[1] << reset << std::endl;
    } else {
        std::cout << std::setw(10) << (menu->choices_pos == 0 ? ">" : "") << 
                                      (menu->choices_pos == 0 ? red : "") << menu->main_choices[0] << reset << std::endl;
        std::cout << std::setw(10) << (menu->choices_pos == 1 ? ">" : "") <<
                                      (menu->choices_pos == 1 ? red : "") << menu->main_choices[1] << reset << std::endl;
    }
}

void Drawer::draw(std::vector<std::shared_ptr<PlayMenu>> vec_menu)
{
    clearConsole();
    const auto& game = vec_menu[0]->game;
    size_t field_size = game->fieldSize();
    for (size_t y = 0; y < field_size; y++) {
        for (size_t x = 0; x < field_size; x++) {
            const FieldCell& cell = game->getCell({x, y});
            if (vec_menu[0]->pos.x == x && vec_menu[0]->pos.y == y) {
                std::cout << underline;
            }
            if (vec_menu[1]->pos.x == x && vec_menu[1]->pos.y == y) {
                std::cout << underline;
            }
            if (cell.unit != nullptr) {
                std::cout << red << "U";
            } else if (cell.building != nullptr) {
                std::cout << red << "B";
            } else if (cell.resources == Relief::Ground) {
                std::cout << green << ".";
            } else if (cell.resources == Relief::Coin) {
                std::cout << red << "@";
            }

            std::cout << reset;
        }
        std::cout << std::endl;
    }
}
