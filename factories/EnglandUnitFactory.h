#pragma once

#include "UnitFactory.h"

class EnglandUnitFactory : public UnitFactory
{
public:
    std::shared_ptr<Unit> createWorker() const override;
    std::shared_ptr<Unit> createSwordman() const override;
    std::shared_ptr<Unit> createArcher() const override;
};