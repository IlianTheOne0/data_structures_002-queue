#ifndef QUEUE_PROVIDER_H
#define QUEUE_PROVIDER_H

#include "../Source/Local/Queue/queue.h"
#include "../Source/Local/Item/item.h"

template<typename TValue>
class QueueProvider
{
private:
    Queue _queue;
public:
    QueueProvider() : _queue() {}
    QueueProvider(const size_t& maxSize) : _queue(maxSize) {}
    ~QueueProvider() {}

    void enqueue(const TValue& value) { _queue.enqueue(new Item<TValue>(value)); }
    void enqueue(const TValue& value, const Priority& priority) { _queue.enqueue(new Item<TValue>(value, priority)); }
    Item<TValue>* dequeue() { return dynamic_cast<Item<TValue>*>(_queue.dequeue()); }
    Item<TValue>* dequeueWithHighestPriority() { return dynamic_cast<Item<TValue>*>(_queue.dequeueWithHighestPriority()); }
    bool isFull() const { return _queue.isFull(); }
    bool isEmpty() const { return _queue.isEmpty(); }
    size_t getCounter() const { return _queue.getCounter(); }
    void clear() { _queue.clear(); }
    Item<TValue>* front() { return dynamic_cast<Item<TValue>*>(_queue.front()); }
    Item<TValue>* back() { return dynamic_cast<Item<TValue>*>(_queue.back()); }
    Item<TValue>* peek() { return dynamic_cast<Item<TValue>*>(_queue.peek()); }
};

#endif