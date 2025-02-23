#include "queue.h"

void Queue::_resize()
{
    size_t newMaxSize = _maxSize + DEFAULT_STACK_SIZE;

    IItem** newQueue = new IItem * [newMaxSize];
    for (size_t i = 0; i < _counter; i++) { newQueue[i] = _queue[i]; }

    if (_queue) { delete[] _queue; }
    _queue = newQueue;
    _maxSize = newMaxSize;
}


Queue::Queue()
	: _maxSize(DEFAULT_STACK_SIZE), _counter(0)
{ _queue = new IItem * [_maxSize]; }
Queue::~Queue()
{ for (size_t i = 0; i < _counter; i++) { delete _queue[i]; } delete [] _queue; }

bool Queue::isFull() const { return _counter == _maxSize; }
bool Queue::isEmpty() const { return _counter == 0; }
size_t Queue::getMaxSize() const { return _maxSize; }
size_t Queue::getCounter() const { return _counter; }

void Queue::enqueue(IItem* value) { if (isFull()) { _resize(); } _queue[_counter++] = value; }
IItem* Queue::dequeue()
{
	if (isEmpty()) { return nullptr; }

	IItem* item = _queue[0];
	for (size_t i = 0; i < _counter - 1; i++) { _queue[i] = _queue[i + 1]; }
	_counter--;
	return item;
}
void Queue::clear() { for (size_t i = 0; i < _counter; i++) { delete _queue[i]; } _counter = 0; }

IItem* Queue::front() { ; if (isEmpty()) { return nullptr; } return _queue[0]; }
IItem* Queue::back() { if (isEmpty()) { return nullptr; } return _queue[_counter - 1]; }

IItem* Queue::getItem(size_t i) const { return _queue[i]; }