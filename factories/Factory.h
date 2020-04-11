#pragma once
#include <iostream>
#include "../units/UnitTypes.h"

class Factory
{
private:
    std::string nation;

public:
    /* Constructors */
    Factory() = default;
    Factory(const std::string&);

    /* Create Units */
    std::shared_ptr<Unit> createWorker(const std::string&);
    std::shared_ptr<Unit> createWarrior(const std::string&);
};