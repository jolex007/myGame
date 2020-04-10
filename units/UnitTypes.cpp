#include "UnitTypes.h"

/* Worker class */

Worker::Worker(std::string name, double power, size_t steps) :
    Unit(name, power, steps) {}

void Worker::nextMove()
{
    std::cout << "Worker did next move...\n";
}

/* Warrior class */

Warrior::Warrior(std::string name, double power, size_t steps) :
    Unit(name, power, steps) {}

void Warrior::nextMove()
{
    std::cout << "Warrior did next move...\n";
}