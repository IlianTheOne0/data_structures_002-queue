#ifndef QUEUE_H
#define QUEUE_H

#define DEFAULT_STACK_SIZE 3

#include "../../../../lib.h"
#include "../../../../Core/core.h"
#include "../../../../Domain/domain.h"
#include "../enum.h"

template<typename TValue>
class Item
{
private:
	TValue _value;
	Priority _priority;
public:
	Item();
	Item(TValue value);
	Item(TValue value, Priority priority);
	~Item();

	TValue getValue() const;
	void setValue(const TValue& value);

	Priority getPriority() const;
	void setPriority(const Priority& value);
};

template<typename TValue>
class Queue
{
private:
	Item<TValue>* _queue = nullptr;
	size_t _maxSize{};
	size_t _counter{};

	void _resize();
	void _sort();
public:
	Queue();
	Queue(const size_t& maxSize);
	~Queue();

	bool isFull() const;
	bool isEmpty() const;
	size_t getMaxSize() const;
	size_t getCounter() const;

	void enqueue(TValue value);
	void enqueue(TValue value, Priority priority);
	Item<TValue> dequeue();
	Item<TValue> dequeueWithHighestPriority();
	void clear();

	Item<TValue> front();
	Item<TValue> back();
	Item<TValue> peek();
};

#endif