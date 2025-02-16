#include "printerUseCase.h"

PrinterUseCase::PrinterUseCase()
	: Printer()
{ CREATE_INFO("PrinterUseCase <- Default constructor: called;"); }
PrinterUseCase::~PrinterUseCase() { CREATE_INFO("PrinterUseCase <- Destructor: called;"); }

void PrinterUseCase::addJob(const string& userName) { INFO("PrinterUseCase -> method add (without Priority): called;"); addJob(userName, Priority::Lowest); }
void PrinterUseCase::addJob(const string& userName, Priority priority)
{
	INFO("PrinterUseCase -> method add: called;");

	setCounter(getCounter() + 1);
	getJobQueue().enqueue(Job(getCounter(), userName), priority);	
}

void PrinterUseCase::processJob()
{
	INFO("PrinterUseCase -> method process: called;");

	if (getJobQueue().isEmpty()) { return; }

	Item<Job> job = getJobQueue().dequeue();

	time_t currentTime = time(nullptr);
	char timeStr[26];
	ctime_s(timeStr, sizeof(timeStr), &currentTime);
	string timeString(timeStr);
	if (!timeString.empty() && timeString.back() == '\n') { timeString.pop_back(); }
	getStatQueue().enqueue(createStatQueue(job.getValue().getUserName(), timeString));
}

void PrinterUseCase::getInfo()
{
	INFO("PrinterUseCase -> method getInfo: called;");

	if (getStatQueue().isEmpty()) { cout << "No saved statistics"; return; }

	size_t spacingValue{ 100 };
	auto insertSpace = [spacingValue]() { for (size_t i = 0; i < spacingValue; i++) { cout << '-'; } cout << endl; };

	cout << "|";
	cout << setw(20) << "User name" << " | ";
	cout << setw(15) << "Print time" << " |";
	cout << endl;

	insertSpace();
	while (!getStatQueue().isEmpty())
	{
		Item<Stat> stat = getStatQueue().dequeue();

		insertSpace();
		cout << "|";
		cout << setw(20) << stat.getValue().getUserName() << " | ";
		cout << setw(15) << stat.getValue().getTime() << " |";
		cout << endl;
	}
	insertSpace();
}