#pragma once

#include <iostream>
#include <map>
#include "FieldCell.h"
#include "MapProperties.h"
#include "creating/buildings/BuildingFactory.h"

class Field
{
private:
    std::vector<std::vector<FieldCell>> cells;
    std::map<std::string, BuildingFactory> building_factories;

public:
    Field() = default;
    Field(std::vector<std::vector<Relief>>);

    const FieldCell& getCell(size_t, size_t);
    void moveUnit(size_t, size_t, size_t, size_t);
    void buildBuilding(size_t, size_t);
};