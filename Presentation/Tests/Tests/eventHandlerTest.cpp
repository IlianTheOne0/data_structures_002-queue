#include "../test.h"
#include "../../../Domain/Entites/EventHandler/eventHandler.h"

void Test::eventHandlerTest()
{
    ABusStop* busStop0 = new BusStop(false, 15);
    ABusStop* busStop1 = new BusStop(true, 15);
    ABusStop* busStops[] = { busStop0, busStop1 };

    AEventHandler* value0 = new EventHandler
    (
        busStops, 2, 15,
        100,
        15.0, 20.0, 30.0, 35.0,
        5.0, 10.0, 20.0, 25.0,
        3.5, 7.5, 12.5, 20.0
    );

    cout << "Number of Bus Stops:" << endl;
    cout << "  getNumOfBusStops(). Result: " << value0->getNumOfBusStops() << ';' << endl;

    cout << "Max Passengers at Stops:" << endl;
    cout << "  getMaxPassengersAtStops(). Result: " << value0->getMaxPassengersAtStops() << ';' << endl;

    cout << "Day Counter:" << endl;
    cout << "  getDayCounter(). Result: " << value0->getDayCounter() << ';' << endl;

    cout << "Total Wait Time:" << endl;
    cout << "  getTotalWaitTime(). Result: " << value0->getTotalWaitTime() << ';' << endl;

    cout << "Total Transported Passengers:" << endl;
    cout << "  getTotalTransportedPassengers(). Result: " << value0->getTotalTransportedPassengers() << ';' << endl;

    delete value0;
    delete busStop0;
    delete busStop1;
}