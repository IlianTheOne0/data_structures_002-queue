#include "lib.h"
#include "Entities/Queue/queue.h"
#include "Entities/PriorityQueue/priorityQueue.h"

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

string priorityToString(Priority priority) {
    switch (priority) {
        case Highest: { return "The highest"; }
        case High: { return "High"; }
        case Normal: { return "Normal"; }
        case Low: { return "Low"; }
        case Lowest: { return "The lowest"; }
        default: { return "Unknown"; }
    }
}

void testPriorityQueue() {
    PriorityQueue pQueue;

    cout << "Adding priority items:" << endl;
    pQueue.enqueue(new PriorityItem<char>('a', Normal));
    pQueue.enqueue(new PriorityItem<char>('b', Highest));
    pQueue.enqueue(new PriorityItem<char>('c', Lowest));
    pQueue.enqueue(new PriorityItem<char>('d', High));
    pQueue.enqueue(new PriorityItem<char>('e', Low));
    pQueue.enqueue(new PriorityItem<char>('f'));
    cout << endl;
    
    IItem* topItem = pQueue.peek();
    if (topItem)
    {
        PriorityItem<char>* pItem = static_cast<PriorityItem<char>*>(topItem);
        cout << "Peek: Top item is '" << *pItem << "' with priority " << priorityToString(pItem->getPriority()) << endl;
    }
    else { cout << "Peek: Priority Queue is empty!" << endl; }
    cout << endl;

    cout << "Dequeueing items based on highest priority:" << endl;
    while (!pQueue.isEmpty())
    {
        IItem* item = pQueue.dequeueWithHighestPriority();
    
        if (item)
        {
            PriorityItem<char>* pItem = static_cast<PriorityItem<char>*>(item);
            cout << "  Dequeued: '" << *pItem << "' with priority " << priorityToString(pItem->getPriority()) << endl;
            delete pItem;
        }
    }
    cout << endl;

    cout << "  isEmpty: " << (pQueue.isEmpty() ? "true" : "false") << endl;
    cout << "  Item count: " << pQueue.getCounter() << endl;
}

int main() {

    testQueue(); cout << endl << endl << endl << endl << endl;
    testPriorityQueue(); cout << endl << endl << endl << endl << endl;

    return 0;
}