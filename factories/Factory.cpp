#include "Factory.h"

#include "../parser/Parser.h"

Factory::Factory(const std::string& nation) :
    nation(nation) {}

std::shared_ptr<Unit> Factory::createWorker(const std::string& unit_name)
{
    const json& unit = Parser::getUnitParams(nation, unit_name);
    return std::make_shared<Worker>(unit["name"], unit["power"], unit["steps"]);
}

std::shared_ptr<Unit> Factory::createWarrior(const std::string& unit_name)
{
    const json& unit = Parser::getUnitParams(nation, unit_name);
    return std::make_shared<Warrior>(unit["name"], unit["power"], unit["steps"]);
}