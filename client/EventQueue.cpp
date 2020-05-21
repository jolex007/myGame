#include "EventQueue.h"

std::queue<Request>* EventQueue::request_queue = nullptr;

std::queue<Request>& EventQueue::GetQueue()
{
    if (request_queue == nullptr) {
        request_queue = new std::queue<Request>();
    }

    return *request_queue;
}

void EventQueue::Push(Request request)
{
    GetQueue().push(request);
}

Request EventQueue::Pop()
{
    Request request = GetQueue().front();
    GetQueue().pop();
    return request;
}

bool EventQueue::Empty()
{
    return GetQueue().empty();
}