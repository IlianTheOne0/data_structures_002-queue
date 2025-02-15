#include "../test.h"
#include "../../../Data/Providers/queueProvider.h"

void testAddItem() {
    QueueProvider<int> queueProvider;

    queueProvider.addItem(1);
    
    if (queueProvider.getQueueSize() == 1 && queueProvider.getFrontItem().getValue() == 1) { cout << "testAddItem passed" << endl; }
    else { cout << "testAddItem failed" << endl; }
}

void testRemoveItem() {
    QueueProvider<int> queueProvider;
    
    queueProvider.addItem(1);
    
    auto item = queueProvider.removeItem();
    if (item.getValue() == 1 && queueProvider.isQueueEmpty()) { cout << "testRemoveItem passed" << endl; }
    else { cout << "testRemoveItem failed" << endl; }
}

void testIsQueueEmpty() {
    QueueProvider<int> queueProvider;

    if (queueProvider.isQueueEmpty()) { cout << "testIsQueueEmpty passed" << endl; }
    else { cout << "testIsQueueEmpty failed" << endl; }
    
    queueProvider.addItem(1);
    
    if (!queueProvider.isQueueEmpty()) { cout << "testIsQueueEmpty passed" << endl; }
    else { cout << "testIsQueueEmpty failed" << endl; }
}

void testGetQueueSize() {
    QueueProvider<int> queueProvider;

    if (queueProvider.getQueueSize() == 0) { cout << "testGetQueueSize passed" << endl; }
    else { cout << "testGetQueueSize failed" << endl; }
    
    queueProvider.addItem(1);
    
    if (queueProvider.getQueueSize() == 1) { cout << "testGetQueueSize passed" << endl; }
    else { cout << "testGetQueueSize failed" << endl; }
}

void Test::queueTest() {
    testAddItem();
    testRemoveItem();
    testIsQueueEmpty();
    testGetQueueSize();
}