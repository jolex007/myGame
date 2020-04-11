#pragma once

#include <iostream>

class Unit
{
protected:
    std::string name;
    double power;
    size_t steps;

public:
    Unit(const std::string&, double, size_t);

    virtual std::string getUnitName() const;
    virtual double getPower() const;
    virtual size_t getSteps() const;

    virtual void nextMove() = 0;
};