#include "../view.h"
#include "../../../Domain/domain.h"

void View::Intro0()
{
    PrinterUseCase value0;

    value0.addJob("Alice", Priority::Normal);
    value0.addJob("Bob", Priority::High);
    value0.addJob("Charlie", Priority::Lowest);
    value0.addJob("Diana", Priority::Highest);
    value0.addJob("Eve", Priority::Low);

    value0.processJob();

    value0.getInfo();
}