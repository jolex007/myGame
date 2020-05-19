#include "BuildingFactory.h"

BuildingFactory::BuildingFactory(const std::string& nation) :
    nation(nation) {}

std::unique_ptr<Building> BuildingFactory::createBuilding(const std::string& name)
{
    return std::make_unique<Building>(name, 2, nation);
}