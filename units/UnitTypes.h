#pragma once

#include "Unit.h"

class WorkerUnit : public Unit
{
public:
    virtual ~WorkerUnit() = default;
};

class SwordmanUnit : public Unit
{
public:
    virtual ~SwordmanUnit() = default;
};

class ArcherUnit : public Unit
{
public:
    virtual ~ArcherUnit() = default;
};