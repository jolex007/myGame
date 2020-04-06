#include "EnglandUnitFactory.h"

#include "../units/EnglandUnits.h"

std::shared_ptr<Unit> EnglandUnitFactory::createWorker() const
{
    return std::make_shared<EnglandWorkerUnit>();
}

std::shared_ptr<Unit> EnglandUnitFactory::createSwordman() const
{
    return std::make_shared<EnglandSwordmanUnit>();
}

std::shared_ptr<Unit> EnglandUnitFactory::createArcher() const
{
    return std::make_shared<EnglandArcherUnit>();
}