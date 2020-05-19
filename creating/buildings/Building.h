#pragma once

#include <iostream>
#include <map>
#include "nlohmann/json.hpp"
#include "creating/units/Factory.h"

using json = nlohmann::json;

class Building
{
protected:
    std::string name;
    size_t radius;
    std::string nation;
    std::unique_ptr<Factory> unit_factory;


public:
    Building(const std::string&, size_t, const std::string&);

    virtual std::string getBuildingName() const;

    virtual void nextMove();
};