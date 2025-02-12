#include "../test.h"
#include "../../../Domain/Entites/BusStop/busStop.h"
#include "../../../lib.h"
void Test::busStopTest()
{
	double currentTime{};
	double maxQueueLength{ 10 };
	BusStop* value0 = new BusStop(false, maxQueueLength);

	cout << "addPasenger:" << endl;
	cout << "  CurrentTime: +5;" << endl; currentTime += 5.0; value0->addPassenger(Passenger(currentTime));
	cout << "  CurrentTime: +7.5;" << endl; currentTime += 7.5; value0->addPassenger(Passenger(currentTime));
	cout << "  CurrentTime: +10;" << endl; currentTime += 10.0; value0->addPassenger(Passenger(currentTime));
	cout << "  CurrentTime: +12.5;" << endl; currentTime += 12.5; value0->addPassenger(Passenger(currentTime));
	cout << "  CurrentTime: +15;" << endl; currentTime += 15; value0->addPassenger(Passenger(currentTime));
	cout << "  Results:" << endl;
	cout << "    Is terminal? Result: " << value0->getIsTerminal() << ";" << endl;
	cout << "    getPassengers (list). Result: " << endl << value0->getPassengers() << ";" << endl;
	cout << "    getTotalPassengers (number). Result: " << value0->getTotalPassengers() << ";" << endl;
	cout << endl;

	cout << "addBus" << endl;
	cout << "  CurrentTime: +5;" << endl; currentTime += 5.0; value0->addBus(currentTime, 3);
	cout << "    getPassengers (list). Result: " << endl << value0->getPassengers() << ";" << endl;
	cout << "    getTotalWaitTime. Result: " << value0->getTotalWaitTime() << ";" << endl;
	cout << "    getTotalPassengers (number). Result: " << value0->getTotalPassengers() << ";" << endl;
	cout << "    getTotalWaitTime. Result: " << value0->getTotalWaitTime() << ";" << endl;
	cout << "  CurrentTime: +5;" << endl; currentTime += 5.0; value0->addBus(currentTime, 15);
	cout << "    getPassengers (list). Result: " << endl << value0->getPassengers() << ";" << endl;
	cout << endl;

	delete value0;


	BusStop value1{ BusStop(true, maxQueueLength) };

	cout << "addPasenger:" << endl;
	cout << "  CurrentTime: +5;" << endl; currentTime += 5.0; value1.addPassenger(Passenger(currentTime));
	cout << "  Results:" << endl;
	cout << "    Is terminal? Result: " << value1.getIsTerminal() << ";" << endl;
	cout << "    getPassengers (list). Result: " << endl << value1.getPassengers() << ";" << endl;
	cout << "    getTotalPassengers (number). Result: " << value1.getTotalPassengers() << ";" << endl;
	cout << "    getTotalWaitTime. Result: " << value1.getTotalWaitTime() << ";" << endl;
	cout << endl;

	cout << "addBus" << endl;
	cout << "  CurrentTime: +5;" << endl; currentTime += 5.0; value1.addBus(currentTime, 3);
	cout << endl;
}