#include "../view.h"

void View::Intro0()
{
    CREATE_INFO("View -> static method Intro0: called;");

    AEventHandler* eventHandler = nullptr;
    UserInput(&eventHandler);
    
    if (eventHandler != nullptr) {
        cout << "Simulating..." << endl;
        eventHandler->startLoop();
        delete eventHandler;
    }
    else {
        ERROR("View -> static method Intro0: eventHandler is null;");
    }
}