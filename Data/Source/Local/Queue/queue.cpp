#include "../../../../Domain/domain.h"
#include "queue.h"

template<typename TValue>
void Queue<TValue>::resize()
{
    INFO("Queue -> Method resize: called;");
    INFO("Queue -> Method resize -> size: current: " + to_string(getMaxSize()));

    _maxSize += DEFAULT_QUEUE_SIZE;

    INFO("Queue -> Method resize -> size: new: " + to_string(getMaxSize()));

    TValue* newQueue = new TValue[_maxSize];
    for (size_t i = 0; i < _counter; i++) { newQueue[i] = _queue[i]; }
    delete[] _queue; _queue = newQueue;
}

template<typename TValue> Queue<TValue>::Queue() : _maxSize(DEFAULT_QUEUE_SIZE) { CREATE_INFO("Queue <- Default constructor: called;"); _queue = new TValue[_maxSize]; }
template<typename TValue> Queue<TValue>::Queue(const size_t& maxSize) : _maxSize(maxSize) { CREATE_INFO("Queue <- Constructor: called;"); _queue = new TValue[_maxSize]; }
template<typename TValue> Queue<TValue>::~Queue() { CREATE_INFO("Queue <- Destructor: called;"); delete[] _queue; }

template<typename TValue> bool Queue<TValue>::isFull() const { INFO("Queue -> method isFull: called;"); return _counter == _maxSize; }
template<typename TValue> bool Queue<TValue>::isEmpty() const { INFO("Queue -> method isEmpty: called;"); return _counter == 0; }
template<typename TValue> size_t Queue<TValue>::getMaxSize() const { INFO("Queue -> method getMaxSize: called;"); return _maxSize; }
template<typename TValue> size_t Queue<TValue>::getCounter() const { INFO("Queue -> method getCounter: called;"); return _counter; }

template<typename TValue>
void Queue<TValue>::enqueue(TValue value) { INFO("Queue -> method enqueue: called;"); if (isFull()) { resize(); } _queue[_counter++] = value; }
template<typename TValue>
TValue Queue<TValue>::dequeue()
{
    INFO("Dequeue -> method enqueue: called;");

    if (isEmpty()) { return TValue(); }
    
    TValue value = _queue[0];
    for (size_t i = 0; i < _counter - 1; i++) { _queue[i] = _queue[i + 1]; }
    _counter--;
    
    return value;
}
template<typename TValue> void Queue<TValue>::clear() { INFO("Queue -> method clear: called;"); _counter = 0; }

template<typename TValue> TValue Queue<TValue>::front() const { INFO("Queue -> method front: called;"); return isEmpty() ? TValue() : _queue[0]; }
template<typename TValue> TValue Queue<TValue>::back() const { INFO("Queue -> method back: called;"); return isEmpty() ? TValue() : _queue[_counter - 1]; }

template<typename TValue>
template<typename TReturn>
TReturn Queue<TValue>::show() const
{
    INFO("Queue -> method show: called;");

    if (isEmpty()) { return TReturn(); }

    TReturn result;
    for (size_t i = 0; i < _counter; i++) { result += _queue[i]; result += " "; }
    return result;
}
template<>
template<>
string Queue<Passenger>::show<string>() const {
    INFO("Queue -> method show: called;");

    if (isEmpty()) { return string(); }

    string result;
    for (size_t i = 0; i < _counter; i++) { result += to_string(i) + ". Arrival time: "; result += std::to_string(_queue[i].getArrivalTime()); result += "\n"; }
    return result;
}

template class Queue<char>;
template string Queue<char>::show<string>() const;

template class Queue<Passenger>;
template string Queue<Passenger>::show<string>() const;