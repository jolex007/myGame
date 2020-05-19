#pragma once

#include <iostream>
#include "creating/buildings/Building.h"

class BuildingFactory
{
private:
    static const size_t BASE_RADIUS = 2;
    std::string nation;

public:
    /* Constructors */
    BuildingFactory() = default;
    BuildingFactory(const std::string&);

    /* Create Building */
    std::unique_ptr<Building> createBuilding(const std::string&);
};