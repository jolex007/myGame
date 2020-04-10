#pragma once
#include <iostream>
// #include "../units/Unit.h"
#include "../units/UnitTypes.h"

class Factory
{
private:
    std::string nation;

public:
    /* Constructors */
    Factory(std::string);

    /* Create Units */
    std::shared_ptr<Unit> createWorker(std::string);
    std::shared_ptr<Unit> createWarrior(std::string);
};