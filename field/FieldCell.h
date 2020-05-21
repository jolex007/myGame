#pragma once

#include <iostream>
#include "MapProperties.h"
#include "creating/buildings/Building.h"

class FieldCell
{
private:
    Relief resources;
    std::unique_ptr<Building> building;
    std::shared_ptr<Unit> unit;

public:
    FieldCell() = default;
    FieldCell(Relief);

    friend class Field;
    friend class Drawer;
};