#ifndef QUEUE_ITEM_INTERFACE_H
#define QUEUE_ITEM_INTERFACE_H

#include "../priorityEnum.h"

class IItem
{
public:
	virtual Priority getPriority() const = 0;
};

#endif