#include "Factory.h"

#include "parser/Parser.h"

Factory::Factory(const std::string& nation) :
    nation(nation) {}

std::shared_ptr<Unit> Factory::createUnit(const std::string& unit_name)
{
    const json& unit = Parser::getUnitParams(nation, unit_name);
    return std::make_shared<Unit>(unit["name"], unit["power"], unit["steps"], nation);
}