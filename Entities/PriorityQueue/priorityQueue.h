#ifndef PRIORITY_QUEUE_H
#define PRIORITY_QUEUE_H

#include "../Queue/queue.h"
#include "priorityItem.h"

class PriorityQueue
    : public Queue
{
private:
    void sort();
public:
    PriorityQueue();

    void enqueue(IItem* value) override;
    IItem* dequeue() override;
    IItem* front() override;
    IItem* back() override;
};

#endif