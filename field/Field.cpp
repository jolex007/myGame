#include "Field.h"
#include "parser/Parser.h"

Field::Field(std::vector<std::vector<Relief>> map)
{
    cells.resize(map.size());

    for (size_t i = 0; i < map.size(); i++) {
        cells[i].reserve(map[i].size());
        for (size_t j = 0; j < map[j].size(); j++) {
            cells[i].emplace_back(map[i][j]);
        }
    }

    std::vector<std::string> nations = Parser::getNationNames();

    for (size_t i = 0; i < nations.size(); i++) {
        building_factories[nations[i]] = BuildingFactory(nations[i]);
    }

}

const FieldCell& Field::getCell(size_t x, size_t y)
{
    return cells[y][x]; // Maybe [x][y]
}

void Field::moveUnit(size_t from_x, size_t from_y, size_t to_x, size_t to_y)
{
    if (cells[from_y][from_x].unit == nullptr) {
        throw std::runtime_error("trying to move nonexistent Unit");
    }
    if (cells[to_y][to_x].unit != nullptr) {
        throw std::runtime_error("moving Unit on another Unit");
    }

    cells[to_y][to_x].unit = std::move(cells[from_y][from_x].unit);
    cells[from_y][from_x].unit = nullptr;
}

void Field::buildBuilding(size_t x, size_t y)
{
    if (cells[y][x].building != nullptr) {
        throw std::runtime_error("trying to build Building on another building");
    }
    if (cells[y][x].building == nullptr) {
        throw std::runtime_error("trying to build Building without unit");
    }
    cells[y][x].building = building_factories[cells[y][x].unit->getNation()].createBuilding("MainHall");
}