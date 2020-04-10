#include "Factory.h"

#include "../parser/Parser.h"

Factory::Factory(std::string nation) :
    nation(nation) {}

std::shared_ptr<Unit> Factory::createWorker(std::string unit_name)
{
    const json& unit = Parser::getUnitParams(unit_name);
    return std::make_shared<Worker>(unit["name"], unit["power"], unit["steps"]);
}

std::shared_ptr<Unit> Factory::createWarrior(std::string unit_name)
{
    const json& unit = Parser::getUnitParams(unit_name);
    return std::make_shared<Warrior>(unit["name"], unit["power"], unit["steps"]);
}