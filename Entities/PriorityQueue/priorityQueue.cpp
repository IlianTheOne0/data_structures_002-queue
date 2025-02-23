#include "priorityQueue.h"

void PriorityQueue::sort()
{
    for (size_t i = 0; i < _counter; i++)
    {
        for (size_t j = i + 1; j < _counter; j++)
        {
            auto item_i = dynamic_cast<IPriorityItem*>(_queue[i]);
            auto item_j = dynamic_cast<IPriorityItem*>(_queue[j]);

            if (item_i && item_j)
            {
                if (item_j->getPriority() > item_i->getPriority())
                {
                    IItem* temp = _queue[i]; _queue[i] = _queue[j]; _queue[j] = temp;
                }
            }
        }
    }
}

PriorityQueue::PriorityQueue()
    : Queue()
{}

void PriorityQueue::enqueue(IItem* value) { Queue::enqueue(value); sort(); }
IItem* PriorityQueue::dequeueWithHighestPriority()
{
    if (isEmpty()) { return nullptr; }

    IItem* item = _queue[0];
    for (size_t i = 0; i < _counter - 1; i++) { _queue[i] = _queue[i + 1]; }
    _counter--;
    return item;
}
IItem* PriorityQueue::peek() { if (isEmpty()) { return nullptr; } return _queue[0]; }