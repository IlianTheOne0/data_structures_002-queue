#ifndef QUEUE_DOMAINPROVIDER_INTERFACE_H
#define QUEUE_DOMAINPROVIDER_INTERFACE_H

#include "../../Core/core.h"

template<typename TValue>
class IQueueProvider
{
public:
    virtual ~IQueueProvider() = default;

    virtual bool isFull() const = 0;
    virtual bool isEmpty() const = 0;
    virtual size_t getMaxSize() const = 0;
    virtual size_t getCounter() const = 0;

    virtual void enqueue(TValue value) = 0;
    virtual TValue dequeue() = 0;
    virtual void clear() = 0;

    virtual TValue front() const = 0;
    virtual TValue back() const = 0;
};

#endif