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

Unit::Unit(const std::string& name, double power, size_t steps) : 
    name(name), power(power), steps(steps) {}