#pragma once

#include <iostream>
#include <queue>
#include "Request.h"

class EventQueue
{
private:
    static std::queue<Request>* request_queue;
    static std::queue<Request>& GetQueue();

public:
    EventQueue() = default;

    static void Push(Request);
    static Request Pop();
    static bool Empty();
};