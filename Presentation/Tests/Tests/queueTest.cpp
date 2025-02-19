#include "../test.h"
#include "../../../Data/Providers/queueProvider.h"

void testAddItem() {
    QueueProvider<int> queueProvider;

    queueProvider.enqueue(1);

    if (queueProvider.getCounter() == 1 && queueProvider.front()->getValue() == 1) { cout << "testAddItem passed" << endl; }
    else { cout << "testAddItem failed" << endl; }
}

void testRemoveItem() {
    QueueProvider<int> queueProvider;

    queueProvider.enqueue(1);

    auto item = queueProvider.dequeue();
    if (item->getValue() == 1 && queueProvider.isEmpty()) { cout << "testRemoveItem passed" << endl; }
    else { cout << "testRemoveItem failed" << endl; }
}

void testIsQueueEmpty() {
    QueueProvider<int> queueProvider;

    if (queueProvider.isEmpty()) { cout << "testIsQueueEmpty passed" << endl; }
    else { cout << "testIsQueueEmpty failed" << endl; }

    queueProvider.enqueue(1);

    if (!queueProvider.isEmpty()) { cout << "testIsQueueEmpty passed" << endl; }
    else { cout << "testIsQueueEmpty failed" << endl; }
}

void testGetQueueSize() {
    QueueProvider<int> queueProvider;

    if (queueProvider.getCounter() == 0) { cout << "testGetQueueSize passed" << endl; }
    else { cout << "testGetQueueSize failed" << endl; }

    queueProvider.enqueue(1);

    if (queueProvider.getCounter() == 1) { cout << "testGetQueueSize passed" << endl; }
    else { cout << "testGetQueueSize failed" << endl; }
}

void Test::queueTest() {
    testAddItem();
    testRemoveItem();
    testIsQueueEmpty();
    testGetQueueSize();
}