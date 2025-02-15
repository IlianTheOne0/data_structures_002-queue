#include "queue.h"

template<typename TValue>
Item<TValue>::Item()
	: _priority(Priority::Normal)
{ CREATE_INFO("Item <- Default constructor: called;"); }
template<typename TValue>
Item<TValue>::Item(TValue value)
	: _value(value), _priority(Priority::Normal)
{ CREATE_INFO("Item <- Constructor with custom value: called;"); }
template<typename TValue>
Item<TValue>::Item(TValue value, Priority priority)
	: _value(value), _priority(static_cast<Priority>(priority))
{ CREATE_INFO("Item <- Constructor with custom value and priority of it: called;"); }
template<typename TValue> Item<TValue>::~Item() { CREATE_INFO("Item <- Destructor: called;"); }

template<typename TValue> TValue Item<TValue>::getValue() const { INFO("Item -> method getValue: called;"); return _value; }
template<typename TValue> void Item<TValue>::setValue(const TValue& value) { INFO("Item -> method setValue: called;"); _value = value; }

template<typename TValue> Priority Item<TValue>::getPriority() const { INFO("Item -> method getPriority: called;"); return _priority; }
template<typename TValue> void Item<TValue>::setPriority(const Priority& value) { INFO("Item -> method setPriority: called;"); _priority = value; }

template<typename TValue>
void Queue<TValue>::_resize()
{
	INFO("Item -> method resize: called;");

	_maxSize += DEFAULT_STACK_SIZE;

	Item<TValue>* newQueue = new Item<TValue>[_maxSize];
	for (size_t i = 0; i < _counter; i++) { newQueue[i] = _queue[i]; }
	delete[] _queue;
	_queue = newQueue;
}
template<typename TValue>
void Queue<TValue>::_sort()
{
	INFO("Item -> method sort: called;");

	for (size_t i = 1; i < _counter; i++)
	{
		Item<TValue> key = _queue[i];
		size_t j = i;

		while (j > 0 && _queue[j - 1].getPriority() < key.getPriority()) { _queue[j] = _queue[j - 1]; j--; }
		_queue[j] = key;
	}
}

template<typename TValue>
Queue<TValue>::Queue()
	: _maxSize(DEFAULT_STACK_SIZE)
{ INFO("Queue <- Default constructor: called;"); _queue = new Item<TValue>[_maxSize]; }
template<typename TValue>
Queue<TValue>::Queue(const size_t& maxSize)
	: _maxSize(maxSize)
{ INFO("Queue <- Constructor with custom size: called;"); _queue = new Item<TValue>[_maxSize]; }
template<typename TValue> Queue<TValue>::~Queue() { INFO("Queue <- Destructor: called;"); delete[] _queue; }

template<typename TValue> bool Queue<TValue>::isFull() const { INFO("Queue -> method isFull: called;"); return _counter == _maxSize; }
template<typename TValue> bool Queue<TValue>::isEmpty() const { INFO("Queue -> method isEmpty: called;"); return _counter == 0; }
template<typename TValue> size_t Queue<TValue>::getMaxSize() const { INFO("Queue -> method getMaxSize: called;"); return _maxSize; }
template<typename TValue> size_t Queue<TValue>::getCounter() const { INFO("Queue -> method getCounter: called;"); return _counter; }

template<typename TValue> void Queue<TValue>::enqueue(TValue value) { if (isFull()) { _resize(); } _queue[_counter++] = Item<TValue>(value); _sort(); }
template<typename TValue> void Queue<TValue>::enqueue(TValue value, Priority priority) { if (isFull()) { _resize(); } _queue[_counter++] = Item<TValue>(value, priority); _sort(); }

template<typename TValue> Item<TValue> Queue<TValue>::dequeue()
{
	INFO("Queue -> method dequeue: called;");

	if (isEmpty()) { return Item<TValue>(); }

	Item<TValue> item = _queue[0];
	for (size_t i = 0; i < _counter - 1; i++) { _queue[i] = _queue[i + 1]; }
	_counter--;
	return item;
}
template<typename TValue> Item<TValue> Queue<TValue>::dequeueWithHighestPriority()
{
	INFO("Queue -> method dequeueWithHighestPriority: called;");

	if (isEmpty()) { return Item<TValue>(); }

	size_t id{};
	for (size_t i = 1; i < _counter; i++) { if (_queue[i].getPriority() > _queue[id].getPriority()) { id = i; } }

	Item<TValue> item = _queue[id];
	for (size_t i = id; i < _counter - 1; i++) { _queue[i] = _queue[i + 1]; }
	_counter--;
	return item;
}
template<typename TValue> void Queue<TValue>::clear() { INFO("Queue -> method clear: called;"); _counter = 0; }

template<typename TValue> Item<TValue> Queue<TValue>::front() { INFO("Queue -> method front: called;"); if (isEmpty()) { return Item<TValue>(); } return _queue[0]; }
template<typename TValue> Item<TValue> Queue<TValue>::back() { INFO("Queue -> method back: called;"); if (isEmpty()) { return Item<TValue>(); } return _queue[_counter - 1]; }
template<typename TValue> Item<TValue> Queue<TValue>::peek() {
	INFO("Queue -> method dequeue: peek;");

	if (isEmpty()) { return Item<TValue>(); }

	size_t id{};
	for (size_t i = 1; i < _counter; i++) { if (_queue[i].getPriority() > _queue[id].getPriority()) { id = i; } }

	return _queue[id];
}

template class Item<int>;
template class Queue<int>;