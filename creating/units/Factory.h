#pragma once
#include <iostream>
#include "creating/units/Unit.h"

class Factory
{
private:
    std::string nation;

public:
    /* Constructors */
    Factory() = default;
    Factory(const std::string&);

    /* Create Units */
    std::shared_ptr<Unit> createUnit(const std::string&);
};