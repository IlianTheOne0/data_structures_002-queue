#include "../view.h"

#define MAX_BUS_STOPS 10

void View::UserInput(AEventHandler** eventHandler)
{
	CREATE_INFO("View -> static method userInput: called;");
	
	string input;

	unsigned short numOfBusStops;
	ABusStop** busStops;
	unsigned short maxPassengersAtStops;

	size_t dayCounter;
	
	double passengerMorningMin, passengerMorningMax, busMorningMin, busMorningMax;
	double passengerAfternoonMin, passengerAfternoonMax, busAfternoonMin, busAfternoonMax;
	double passengerEveningMin, passengerEveningMax, busEveningMin, busEveningMax;
	
	auto clear = []() { INFO("View -> static method userInput -> clear: called;"); if (!Logger::getLoggerState()) { system("cls"); } };
	auto pause = []() { INFO("View -> static method userInput -> pause: called;"); system("pause"); };

	auto print = [pause](const string& message, const unsigned short& color = 7, const bool& isTransfer = true, const bool& isPause = false)
		{
			INFO("View -> static method userInput -> print: called;");

			HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
			SetConsoleTextAttribute(hConsole, color);
			cout << message;
			SetConsoleTextAttribute(hConsole, 7);
			
			if (isTransfer) { cout << endl; }
			if (isPause) { pause(); }
		};
	auto printError = [pause](const bool& isPause = true, const bool& isTransfer = true, const string& message = "Incorrect input!")
		{
			INFO("View -> static method userInput -> printError: called;");

			HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);

			SetConsoleTextAttribute(hConsole, 4);
			cout << message;
			SetConsoleTextAttribute(hConsole, 7);
			
			if (isTransfer) { cout << endl; }
			if (isPause) { pause(); }
		};

	auto setIntervals = [print, clear](const string& message, double& passengerMin, double& passengerMax, double& busMin, double& busMax)
		{
			clear();

			print(message, 6);
			cout << "  Enter the minimum passenger arrival time (in hours): "; cin >> passengerMin;
			cout << "  Enter the max passenger arrival time (in hours): "; cin >> passengerMax;
			cout << endl;
			cout << "  Enter the minimum bus arrival time (in hours): "; cin >> busMin;
			cout << "  Enter the max bus arrival time (in hours): "; cin >> busMax;
		};

	INFO("View -> static method userInput -> input: maxPassengersAtStops;");
	cout << "Maximum number of people at a bus stop: "; cin >> maxPassengersAtStops;

	INFO("View -> static method userInput -> input: numOfBusStops;");
	do
	{
		clear();

		cout << "Enter number of bus stops: ";
		cin >> numOfBusStops;

		if (numOfBusStops < 2 || numOfBusStops > MAX_BUS_STOPS) { WARNING("View -> static method userInput -> input numOfBusStops: Incorrect input! (" + to_string(numOfBusStops) + ");"); printError(); continue; }
		break;
	} while (true);

	INFO("View -> static method userInput -> creating: busStops;");
	busStops = new ABusStop * [numOfBusStops];
	busStops[0] = new BusStop(true, maxPassengersAtStops); busStops[numOfBusStops - 1] = new BusStop(true, maxPassengersAtStops);
	for (unsigned short i = 1; i < numOfBusStops - 1; i++) { busStops[i] = new BusStop(false, maxPassengersAtStops); }

	clear();

	INFO("View -> static method userInput -> input: dayCounter;");
	cout << "Enter the length of the simulation (in days): "; cin >> dayCounter;

	INFO("View -> static method userInput -> input: Morning (passenger: min / max; bus: min / max);"); setIntervals("Morning (05:30 - 11:59)", passengerMorningMin, passengerMorningMax, busMorningMin, busMorningMax);
	INFO("View -> static method userInput -> input: Afternoon (passenger: min / max; bus: min / max);"); setIntervals("Afternoon (12:00 - 19:59)", passengerAfternoonMin, passengerAfternoonMax, busAfternoonMin, busAfternoonMax);
	INFO("View -> static method userInput -> input: Evening (passenger: min / max; bus: min / max);"); setIntervals("Evening (20:00 - 23:00)", passengerEveningMin, passengerEveningMax, busEveningMin, busEveningMax);

	*eventHandler = new EventHandler
	(
		busStops, numOfBusStops, maxPassengersAtStops,
		dayCounter,
		passengerMorningMin, passengerMorningMax, busMorningMin, busMorningMax,
		passengerAfternoonMin, passengerAfternoonMax, busAfternoonMin, busAfternoonMax,
		passengerEveningMin, passengerEveningMax, busEveningMin, busEveningMax
	);

	clear();
}