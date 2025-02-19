#ifndef QUEUE_H
#define QUEUE_H

#define DEFAULT_STACK_SIZE 3

#include "../Item/item.h"

class Queue
{
private:
	IItem** _queue;
	size_t _maxSize{};
	size_t _counter{};

	void _resize();
	void _sort();
public:
	Queue();
	~Queue();

	bool isFull() const;
	bool isEmpty() const;
	size_t getMaxSize() const;
	size_t getCounter() const;

	void enqueue(IItem* value);
	IItem* dequeue();
	IItem* dequeueWithHighestPriority();
	void clear();

	IItem* front();
	IItem* back();
	IItem* peek();
};

#endif