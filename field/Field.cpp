#include "Field.h"
#include "parser/Parser.h"

Field::Field(const std::vector<std::vector<Relief>>& map)
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

const FieldCell& Field::getCell(Coordinates coord)
{
    return cells[coord.y][coord.x];
}

void Field::moveUnit(Coordinates from, Coordinates to)
{
    if (cells[from.y][from.x].unit == nullptr) {
        throw std::runtime_error("trying to move nonexistent Unit");
    }
    if (cells[to.y][to.x].unit != nullptr) {
        throw std::runtime_error("moving Unit on another Unit");
    }

    cells[to.y][to.x].unit = std::move(cells[from.y][from.x].unit);
    cells[from.y][from.x].unit = nullptr;
}

void Field::buildBuilding(Coordinates coord)
{
    if (cells[coord.y][coord.x].building != nullptr) {
        throw std::runtime_error("trying to build Building on another building");
    }
    if (cells[coord.y][coord.x].unit == nullptr) {
        throw std::runtime_error("trying to build Building without unit");
    }

    cells[coord.y][coord.x].building = building_factories[cells[coord.y][coord.x].unit->getNation()].createBuilding("MainHall");
}

int Field::getResource(Coordinates coord)
{
    if (cells[coord.y][coord.x].unit == nullptr) {
        throw std::runtime_error("trying to get coin without unit");
    }
    int result;

    switch (cells[coord.y][coord.x].resources) {
    case Relief::Ground:
        throw std::runtime_error("trying to get coin, but there is no coin");
        break;
    
    case Relief::Coin:
        result = 1;
        break;
    };

    cells[coord.y][coord.x].resources = Relief::Ground;

    return result;
}

size_t Field::fieldSize() const 
{
    return cells.size();
}