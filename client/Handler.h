#pragma once

#include <iostream>
#include "Request.h"
#include "EventQueue.h"

class Handler
{
private:


public:
    Handler() = default;
    static void handle();
};