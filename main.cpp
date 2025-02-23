#include "lib.h"
#include "Entities/Queue/queue.h"

ostream& operator<<(ostream& os, IItem& item)
{
    char* value = static_cast<char*>(item.getValue());

    if (value) { os << *value; }
    else { os << "null"; }

    return os;
}

template<typename TValue>
void testEnqueue(Queue& queue, TValue value)
{
    cout << "  enqueue '" << value << "'. Result: ";
    queue.enqueue(new Item<TValue>(value));
    cout << *static_cast<Item<TValue>*>(queue.back()) << endl;
}

void testDequeue(Queue& queue)
{
    cout << "  dequeue + back. Result: ";
    queue.dequeue();

    IItem* backItem = queue.back();
    if (backItem) { cout << *static_cast<Item<char>*>(backItem) << endl; }
    else { cout << "Queue is empty!" << endl; }
}

void testQueueState(Queue& queue)
{
    cout << "Checks: " << endl;
    cout << "  Max size. Result: " << queue.getMaxSize() << endl;
    cout << "  Counting the number of characters in the queue. Result: " << queue.getCounter() << endl;
    cout << "  isEmpty. Result: " << (queue.isEmpty() ? "true" : "false") << endl;
    cout << "  isFull. Result: " << (queue.isFull() ? "true" : "false") << endl;
    cout << endl;
}

void testClearQueue(Queue& queue)
{
    cout << "Clear the queue. Result (isEmpty): ";
    queue.clear();
    cout << (queue.isEmpty() ? "true" : "false") << endl;
}

void testQueue()
{
    Queue queue;

    cout << "Adding characters to the queue:" << endl;
    testEnqueue<char>(queue, 'a');
    testEnqueue<char>(queue, 'b');
    testEnqueue<char>(queue, 'c');
    testEnqueue<char>(queue, 'd');
    cout << endl;

    testQueueState(queue);

    cout << "Deleting characters from the queue + getting without deleting the back character in the queue:" << endl;
    testDequeue(queue);
    testDequeue(queue);
    testDequeue(queue);
    cout << endl;

    testQueueState(queue);

    cout << "Adding more characters to the queue:" << endl;
    testEnqueue<char>(queue, 'a');
    testEnqueue<char>(queue, 'b');
    cout << "  Counting the number of characters in the queue. Result: " << queue.getCounter() << endl;
    testEnqueue(queue, 'c');
    testEnqueue<char>(queue, 'd');
    testEnqueue<char>(queue, 'e');
    testEnqueue<char>(queue, 'f');
    testEnqueue<char>(queue, 'g');
    testEnqueue<char>(queue, 'h');
    testEnqueue<char>(queue, 'j');
    cout << endl;

    cout << "Max size. Result: " << queue.getMaxSize() << endl;
    cout << "Counting the number of characters in the queue. Result: " << queue.getCounter() << endl;
    testClearQueue(queue);
    cout << "Max size. Result: " << queue.getMaxSize() << endl;
    cout << "Counting the number of characters in the queue. Result: " << queue.getCounter() << endl;
    cout << endl;
}

int main()
{
    testQueue();

    return 0;
}