#include "../test.h"
#include "../../../Domain/Entites/Passenger/passenger.h"

void Test::passengerTest()
{
	APassenger* value0 = new Passenger(1.5);

	cout << "Arrival time:" << endl;
	cout << "  getArrivalTime(). Result: " << value0->getArrivalTime() << ';' << endl;
	cout << "  setArrivalTime(3.5);" << endl; value0->setArrivalTime(3.5);
	cout << "  getArrivalTime(). Result: " << value0->getArrivalTime() << ';' << endl;

	delete value0;
}