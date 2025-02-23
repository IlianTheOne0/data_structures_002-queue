#ifndef PRIORITY_QUEUE_H
#define PRIORITY_QUEUE_H

#include "../Queue/queue.h"
#include "priorityItem.h"

class PriorityQueue
    : public Queue {
private:
    void sort();
public:
    PriorityQueue();
    ~PriorityQueue() override = default;

    void enqueue(IItem* value) override;
    virtual IItem* dequeueWithHighestPriority();
    virtual IItem* peek();
};

#endif