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
    Field(const std::vector<std::vector<Relief>>&);

    const FieldCell& getCell(Coordinates);
    void moveUnit(Coordinates, Coordinates);
    void buildBuilding(Coordinates);
    int getResource(Coordinates);
    size_t fieldSize() const;
};