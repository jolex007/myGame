#include "Building.h"


std::string Building::getBuildingName() const
{
    return name;
}

void Building::nextMove()
{
    std::cout << "Building did next move...\n";
}

Building::Building(const std::string& name, size_t radius, const std::string& nation) :
    name(name), radius(radius), nation(nation), unit_factory(std::make_unique<Factory>(nation)) {}