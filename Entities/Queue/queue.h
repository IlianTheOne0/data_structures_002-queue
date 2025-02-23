#ifndef QUEUE_H
#define QUEUE_H

#define DEFAULT_STACK_SIZE 3

#include "../Item/item.h"
#include "../../lib.h"

class Queue
{
private:
	IItem** _queue;
	size_t _maxSize{};
	size_t _counter{};

	virtual void _resize();
public:
	Queue();
	virtual ~Queue();

	virtual bool isFull() const;
	virtual bool isEmpty() const;
	virtual size_t getMaxSize() const;
	virtual size_t getCounter() const;

	virtual void enqueue(IItem* value);
	virtual IItem* dequeue();
	virtual void clear();

	virtual IItem* front();
	virtual IItem* back();

	virtual IItem* getItem(size_t i) const;
};

#endif