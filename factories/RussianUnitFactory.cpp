#include "RussianUnitFactory.h"

#include "../units/RussianUnits.h"

std::shared_ptr<Unit> RussianUnitFactory::createWorker() const
{
    return std::make_shared<RussianWorkerUnit>();
}

std::shared_ptr<Unit> RussianUnitFactory::createSwordman() const
{
    return std::make_shared<RussianSwordmanUnit>();
}

std::shared_ptr<Unit> RussianUnitFactory::createArcher() const
{
    return std::make_shared<RussianArcherUnit>();
}