#include "queue.h"
#include "../../../../lib.h"
#include "../../../../Core/core.h"

void Queue::_resize()
{
	INFO("Item -> method resize: called;");

	_maxSize += DEFAULT_STACK_SIZE;

	IItem** newQueue = new IItem*[_maxSize];
	for (size_t i = 0; i < _counter; i++) { newQueue[i] = _queue[i]; }
	delete[] _queue;
	_queue = newQueue;
}

void Queue::_sort()
{
	INFO("Item -> method sort: called;");

	for (size_t i = 1; i < _counter; i++)
	{
		IItem* key = _queue[i];
		size_t j = i;

		while (j > 0 && _queue[j - 1]->getPriority() > key->getPriority()) { _queue[j] = _queue[j - 1]; j--; }
		_queue[j] = key;
	}
}

Queue::Queue()
	: _maxSize(DEFAULT_STACK_SIZE), _counter(0)
{ INFO("Queue <- Default constructor: called;"); _queue = new IItem*[_maxSize]; }
 Queue::~Queue() { INFO("Queue <- Destructor: called;"); delete[] _queue; }

 bool Queue::isFull() const { INFO("Queue -> method isFull: called;"); return _counter == _maxSize; }
 bool Queue::isEmpty() const { INFO("Queue -> method isEmpty: called;"); return _counter == 0; }
 size_t Queue::getMaxSize() const { INFO("Queue -> method getMaxSize: called;"); return _maxSize; }
 size_t Queue::getCounter() const { INFO("Queue -> method getCounter: called;"); return _counter; }

void Queue::enqueue(IItem* value) { if (isFull()) { _resize(); } _queue[_counter++] = value; _sort(); }

IItem* Queue::dequeue()
{
	INFO("Queue -> method dequeue: called;");

	if (isEmpty()) { return nullptr; }

	IItem* item = _queue[0];
	for (size_t i = 0; i < _counter - 1; i++) { _queue[i] = _queue[i + 1]; }
	_counter--;
	return item;
}
 IItem* Queue::dequeueWithHighestPriority()
{
	INFO("Queue -> method dequeueWithHighestPriority: called;");

	if (isEmpty()) { return nullptr; }

	size_t id{};
	for (size_t i = 1; i < _counter; i++) { if (_queue[i]->getPriority() > _queue[id]->getPriority()) { id = i; } }

	IItem* item = _queue[id];
	for (size_t i = id; i < _counter - 1; i++) { _queue[i] = _queue[i + 1]; }
	_counter--;
	return item;
}
 void Queue::clear() { INFO("Queue -> method clear: called;"); for (size_t i = 0; i < _counter; i++) { delete _queue[i]; } _counter = 0; }

 IItem* Queue::front() { INFO("Queue -> method front: called;"); if (isEmpty()) { return nullptr; } return _queue[0]; }
 IItem* Queue::back() { INFO("Queue -> method back: called;"); if (isEmpty()) { return nullptr; } return _queue[_counter - 1]; }
 IItem* Queue::peek()
 {
	INFO("Queue -> method peek: called;");

	if (isEmpty()) { return nullptr; }

	size_t id{};
	for (size_t i = 1; i < _counter; i++) { if (_queue[i]->getPriority() > _queue[id]->getPriority()) { id = i; } }

	return _queue[id];
}