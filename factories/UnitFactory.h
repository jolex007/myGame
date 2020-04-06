#pragma once

#include <memory>
#include "../units/Unit.h"

class UnitFactory
{
public:
    virtual std::shared_ptr<Unit> createWorker() const = 0;
    virtual std::shared_ptr<Unit> createSwordman() const = 0;
    virtual std::shared_ptr<Unit> createArcher() const = 0;
};