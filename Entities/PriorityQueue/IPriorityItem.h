#ifndef PRIORITY_ITEM_INTEFACE_H
#define PRIORITY_ITEM_INTEFACE_H

#include "enum.h"

class IPriorityItem
{
public:
    virtual Priority getPriority() const = 0;
    virtual void setPriority(const Priority& priority) = 0;
};

#endif