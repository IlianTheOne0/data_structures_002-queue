#ifndef QUEUE_H
#define QUEUE_H

#define DEFAULT_STACK_SIZE 3

template<typename TValue>
class Queue
{
private:
	TValue* _queue = nullptr;
	size_t _maxSize{};
	size_t _counter{};

	void resize()
	{
		_maxSize += DEFAULT_STACK_SIZE;

		TValue* newQueue = new TValue[_maxSize];
		for (size_t i = 0; i < _maxSize; i++) { newQueue[i] = _queue[i]; }
		delete[] _queue;
		_queue = newQueue;
	}
public:
	Queue() : _maxSize(DEFAULT_STACK_SIZE) { _queue = new TValue[_maxSize]; }
	Queue(const size_t& maxSize) : _maxSize(maxSize), Queue() {}
	~Queue() { delete[] _queue; }

	bool isFull() const { return _counter == _maxSize; }
	bool isEmpty() const { return _counter == 0; }
	size_t getMaxSize() const { return _maxSize; }
	size_t getCounter() const { return _counter; }

	void enqueue(TValue value) { if (isFull()) { resize(); } _queue[_counter++] = value; }
	TValue dequeue()
	{
		if (isEmpty()) { return TValue(); }

		TValue value = _queue[0];
		for (size_t i = 0; i < _counter - 1; i++) { _queue[i] = _queue[i + 1]; }
		_counter--;
		return value;
	}
	void clear() { _counter = 0; }

	TValue front() { if (isEmpty()) { return TValue(); } return _queue[0]; }
	TValue back() { if (isEmpty()) { return TValue(); } return _queue[_counter - 1]; }

	template<typename TReturn>
	TReturn show()
	{
		if (isEmpty()) { return TReturn(); }

		TReturn result;
		for (size_t i = 0; i < _counter; i++) { result += _queue[i]; result += " "; }
		return result;
	}
};

#endif