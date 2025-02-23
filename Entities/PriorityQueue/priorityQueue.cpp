#include "priorityQueue.h"

void PriorityQueue::sort() {
    for (size_t i = 1; i < _counter; i++) {
        IItem* key = _queue[i];
        size_t j = i;

        while (j > 0 && static_cast<PriorityItem*>(_queue[j - 1])->getPriority() < static_cast<PriorityItem*>(key)->getPriority()) {
            _queue[j] = _queue[j - 1];
            j--;
        }
        _queue[j] = key;
    }
}

PriorityQueue::PriorityQueue()
    : Queue()
{
}

void PriorityQueue::enqueue(IItem* value) {
    if (isFull()) {
        _resize();
    }
    _queue[_counter++] = value;
    sort();
}

IItem* PriorityQueue::dequeue() {
    if (isEmpty()) {
        return nullptr;
    }

    IItem* item = _queue[0];
    for (size_t i = 0; i < _counter - 1; i++) {
        _queue[i] = _queue[i + 1];
    }
    _counter--;
    return item;
}

IItem* PriorityQueue::front() {
    if (isEmpty()) {
        return nullptr;
    }
    return _queue[0];
}

IItem* PriorityQueue::back() {
    if (isEmpty()) {
        return nullptr;
    }
    return _queue[_counter - 1];
}