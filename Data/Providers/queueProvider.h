#ifndef QUEUE_PROVIDER_H
#define QUEUE_PROVIDER_H

#include "../Source/Local/Queue/queue.h"

template<typename TValue>
class QueueProvider
{
private:
    Queue<TValue> _queue;

public:
    QueueProvider();
    QueueProvider(const size_t& maxSize);
    ~QueueProvider();

    void addItem(TValue value);
    void addItem(TValue value, Priority priority);
    Item<TValue> removeItem();
    Item<TValue> removeHighestPriorityItem();
    bool isQueueFull() const;
    bool isQueueEmpty() const;
    size_t getQueueSize() const;
    void clearQueue();
    Item<TValue> getFrontItem();
    Item<TValue> getBackItem();
    Item<TValue> peekHighestPriorityItem();
};

template<typename TValue> QueueProvider<TValue>::QueueProvider() : _queue() { }
template<typename TValue> QueueProvider<TValue>::QueueProvider(const size_t& maxSize) : _queue(maxSize) { }
template<typename TValue> QueueProvider<TValue>::~QueueProvider() {}
template<typename TValue> void QueueProvider<TValue>::addItem(TValue value) { _queue.enqueue(value); }
template<typename TValue> void QueueProvider<TValue>::addItem(TValue value, Priority priority) { _queue.enqueue(value, priority); }
template<typename TValue> Item<TValue> QueueProvider<TValue>::removeItem() { return _queue.dequeue(); }
template<typename TValue> Item<TValue> QueueProvider<TValue>::removeHighestPriorityItem() { return _queue.dequeueWithHighestPriority(); }
template<typename TValue> bool QueueProvider<TValue>::isQueueFull() const { return _queue.isFull(); }
template<typename TValue> bool QueueProvider<TValue>::isQueueEmpty() const { return _queue.isEmpty(); }
template<typename TValue> size_t QueueProvider<TValue>::getQueueSize() const { return _queue.getCounter(); }
template<typename TValue> void QueueProvider<TValue>::clearQueue() { _queue.clear(); }
template<typename TValue> Item<TValue> QueueProvider<TValue>::getFrontItem() { return _queue.front(); }
template<typename TValue> Item<TValue> QueueProvider<TValue>::getBackItem() { return _queue.back(); }
template<typename TValue> Item<TValue> QueueProvider<TValue>::peekHighestPriorityItem() { return _queue.peek(); }

#endif