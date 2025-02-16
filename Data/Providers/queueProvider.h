#ifndef QUEUE_PROVIDER_H
#define QUEUE_PROVIDER_H

#include "../Source/Local/Queue/queue.h"
//#include "../Source/Local/enum.h"

template<typename TValue>
class QueueProvider
{
private:
    Queue<TValue> _queue;
public:
    QueueProvider() : _queue() {}
    QueueProvider(const size_t& maxSize) : _queue(maxSize) {}
    ~QueueProvider() {}

    void enqueue(TValue value) { _queue.enqueue(value); }
    void enqueue(TValue value, Priority priority) { _queue.enqueue(value, priority); }
    Item<TValue> dequeue() { return _queue.dequeue(); }
    Item<TValue> dequeueWithHighestPriority() { return _queue.dequeueWithHighestPriority(); }
    bool isFull() const { return _queue.isFull(); }
    bool isEmpty() const { return _queue.isEmpty(); }
    size_t getCounter() const { return _queue.getCounter(); }
    void clear() { _queue.clear(); }
    Item<TValue> front() { return _queue.front(); }
    Item<TValue> back() { return _queue.back(); }
    Item<TValue> peek() { return _queue.peek(); }
};

#endif