#ifndef PRIORITY_ITEM_H
#define PRIORITY_ITEM_H

#include "../Item/item.h"
#include "enum.h"

template<typename TValue>
class PriorityItem
	: public IItem
{
private:
	Priority _priority;
public:
	PriorityItem();
	PriorityItem(TValue value);
	PriorityItem(TValue value, Priority priority);
	~PriorityItem() override = default;

	virtual Priority getPriority() const;
	virtual void setPriority(const Priority& value);
};

#endif