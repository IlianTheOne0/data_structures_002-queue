#include "../view.h"
#include "../../../Domain/domain.h"

void View::Intro0()
{
    PrinterUseCase value0;
    
    cout << "Processing..." << endl;
    value0.addJob("Alice", Priority::Normal);
    value0.addJob("Bob", Priority::High);
    Sleep(1000);
    value0.addJob("Yana");
    Sleep(2000);
    value0.addJob("Charlie", Priority::Lowest);
    value0.addJob("Diana", Priority::Highest);
    Sleep(2000);
    value0.addJob("Eve", Priority::Low);
    
    value0.processJob();
    system("cls");
    value0.getInfo();
}