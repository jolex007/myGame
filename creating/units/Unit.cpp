#include "Unit.h"

double Unit::getPower() const
{
    return power;
}

size_t Unit::getSteps() const
{
    return steps;
}

std::string Unit::getUnitName() const
{
    return name;
}

std::string Unit::getNation() const
{
    return nation;
}

void Unit::nextMove()
{
    std::cout << "Unit did next move...\n";
}

Unit::Unit(const std::string& name, double power, size_t steps, std::string nation) : 
    name(name), power(power), steps(steps), nation(nation) {}