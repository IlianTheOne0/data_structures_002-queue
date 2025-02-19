#include "printerUseCase.h"

string PrinterUseCase::getCurrentTime() const
{
    time_t currentTime = time(nullptr);
    char timeStr[26];
    ctime_s(timeStr, sizeof(timeStr), &currentTime);
    string timeString(timeStr);

    if (!timeString.empty() && timeString.back() == '\n') { timeString.pop_back(); }
    return timeString;
}

PrinterUseCase::PrinterUseCase()
	: Printer()
{ CREATE_INFO("PrinterUseCase <- Default constructor: called;"); }
PrinterUseCase::~PrinterUseCase() { CREATE_INFO("PrinterUseCase <- Destructor: called;"); }

void PrinterUseCase::addJob(const string& userName) { INFO("PrinterUseCase -> method add (without Priority): called;"); addJob(userName, Priority::Lowest, getCurrentTime()); }
void PrinterUseCase::addJob(const string& userName, Priority priority) { addJob(userName, priority, getCurrentTime()); }
void PrinterUseCase::addJob(const string& userName, Priority priority, const string& time)
{
    INFO("PrinterUseCase -> method add: called;");

    setCounter(getCounter() + 1);
    getJobQueue().enqueue(Job(getCounter(), userName, time), priority);
}


void PrinterUseCase::processJob()
{
    INFO("PrinterUseCase -> method process: called;");

    if (getJobQueue().isEmpty()) { return; }

    while (!getJobQueue().isEmpty())
    {
        Item<Job>* job = getJobQueue().dequeue();
        Sleep(500);

        getStatQueue().enqueue(createStatQueue(0, job->getValue().getUserName(), job->getValue().getTime(), getCurrentTime()));
    }
}

void PrinterUseCase::getInfo()
{
    INFO("PrinterUseCase -> method getInfo: called;");

    if (getStatQueue().isEmpty()) { cout << "No saved statistics"; return; }

    size_t spacingValue{ 70 };
    auto insertSpace = [spacingValue]() { for (size_t i = 0; i < spacingValue; i++) { cout << '-'; } cout << endl; };

    insertSpace();
    cout << "|";
    cout << setw(10) << "User name" << " | ";
    cout << setw(26) << "Time of request acceptance" << " |";
    cout << setw(26) << "Start time of execution" << " |";
    cout << endl;
    insertSpace();

    while (!getStatQueue().isEmpty()) {
        Item<Stat>* stat = getStatQueue().dequeue();
        cout << "|";
        cout << setw(10) << stat->getValue().getUserName() << " | ";
        cout << setw(26) << stat->getValue().getTime() << " |";
        cout << setw(26) << stat->getValue().getExecutedTime() << " |";
        cout << endl;
    }
    insertSpace();
}
