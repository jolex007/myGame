#pragma once

#include <iostream>

class Unit
{
private:
    std::string name;
    double power;
    size_t steps;
    std::string nation;

public:
    Unit(const std::string&, double, size_t, std::string nation);

    std::string getUnitName() const;
    double getPower() const;
    size_t getSteps() const;
    std::string getNation() const;

    void nextMove();
};