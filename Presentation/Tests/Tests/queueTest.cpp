#include "../test.h"
#include "../../../Data/data.h"

void Test::queueTest()
{
	Queue<char> queue;
	cout << "Adding a character to the queue:" << endl;
	cout << "  enqueue 'a'. Result: "; queue.enqueue('a'); cout << queue.back() << endl;
	cout << "  enqueue 'b'. Result: "; queue.enqueue('b'); cout << queue.back() << endl;
	cout << "  enqueue 'c'. Result: "; queue.enqueue('c'); cout << queue.back() << endl;
	cout << "  enqueue 'd'. Result: "; queue.enqueue('d'); cout << queue.back() << endl;
	cout << endl;

	cout << "Checks: " << endl;
	cout << "  Max size. Result: " << queue.getMaxSize() << endl;
	cout << "  Counting the number of characters in the queue. Result: " << queue.getCounter() << endl;
	cout << "  isEmpty. Result: "; (queue.isEmpty()) ? cout << "true" : cout << "false"; cout << endl;
	cout << "  isFull. Result: "; (queue.isFull()) ? cout << "true" : cout << "false"; cout << endl;
	cout << endl;

	cout << "Deleting a character from the queue + getting without deleting the back character in the queue:" << endl;
	cout << "  dequeue + back. Result: "; queue.dequeue(); cout << queue.back() << endl;
	cout << "  dequeue + back. Result: "; queue.dequeue(); cout << queue.back() << endl;
	cout << "  dequeue + back. Result: "; queue.dequeue(); cout << queue.back() << endl;
	cout << endl;

	cout << "Checks: " << endl;
	cout << "  isEmpty. Result: "; (queue.isEmpty()) ? cout << "true" : cout << "false"; cout << endl;
	cout << "  isFull. Result: "; (queue.isFull()) ? cout << "true" : cout << "false"; cout << endl;
	cout << endl;

	cout << "Adding a character to the queue:" << endl;
	cout << "  enqueue 'a'. Result: "; queue.enqueue('a'); cout << queue.back() << endl;
	cout << "  enqueue 'b'. Result: "; queue.enqueue('b'); cout << queue.back() << endl;
	cout << "  Counting the number of characters in the queue. Result: " << queue.getCounter() << endl;
	cout << "  enqueue 'c'. Result: "; queue.enqueue('c'); cout << queue.back() << endl;
	cout << "  enqueue 'd'. Result: "; queue.enqueue('d'); cout << queue.back() << endl;
	cout << "  enqueue 'e'. Result: "; queue.enqueue('e'); cout << queue.back() << endl;
	cout << "  enqueue 'f'. Result: "; queue.enqueue('f'); cout << queue.back() << endl;
	cout << "  enqueue 'g'. Result: "; queue.enqueue('g'); cout << queue.back() << endl;
	cout << "  enqueue 'h'. Result: "; queue.enqueue('h'); cout << queue.back() << endl;
	cout << "  enqueue 'j'. Result: "; queue.enqueue('j'); cout << queue.back() << endl;
	cout << endl;

	cout << "Show: " << queue.show<string>() << endl;
	cout << endl;

	cout << "Max size. Result: " << queue.getMaxSize() << endl;
	cout << "Counting the number of characters in the queue. Result: " << queue.getCounter() << endl;
	cout << "Clear the queue. Result (isEmpty): "; queue.clear(); (queue.isEmpty()) ? cout << "true" : cout << "false"; cout << endl;
	cout << "Max size. Result: " << queue.getMaxSize() << endl;
	cout << "Counting the number of characters in the queue. Result: " << queue.getCounter() << endl;
	cout << endl;

	cout << "Show: " << queue.show<string>() << endl;
	cout << endl;
}