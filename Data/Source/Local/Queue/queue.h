#ifndef QUEUE_H
#define QUEUE_H

#define DEFAULT_QUEUE_SIZE 5

#include "../../../../lib.h"
#include "../../../../Core/core.h"
#include "../../../Providers/queueProvider.h"

template<typename TValue>
class Queue
    : public IQueueProvider<TValue>
{
private:
    TValue* _queue = nullptr;
    size_t _maxSize{};
    size_t _counter{};

    void resize();
public:
    Queue();
    Queue(const size_t& maxSize);
    ~Queue() override;

    bool isFull() const override;
    bool isEmpty() const override;
    size_t getMaxSize() const override;
    size_t getCounter() const override;

    void enqueue(TValue value) override;
    TValue dequeue() override;
    void clear() override;

    TValue front() const override;
    TValue back() const override;

    template<typename TReturn>
    TReturn show() const;
};

#endif