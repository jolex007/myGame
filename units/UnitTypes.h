#pragma once
#include "Unit.h"

class Worker : public Unit
{
public:
    /* Constructors and Destructor */
    Worker(const std::string&, double, size_t);

    virtual ~Worker() = default;

    void nextMove() override;
};

class Warrior : public Unit
{
public:
    /* Constructors and Destructor */
    Warrior(const std::string&, double, size_t);

    virtual ~Warrior() = default;

    void nextMove() override;
};