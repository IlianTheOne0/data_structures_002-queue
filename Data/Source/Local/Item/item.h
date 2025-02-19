#ifndef QUEUE_ITEM_ABSTRACTION_H
#define QUEUE_ITEM_ABSTRACTION_H

#include "../../../../lib.h"
#include "../../../../Core/core.h"
#include "itemInterface.h"

template<typename TValue>
class Item
	: public IItem
{
private:
	TValue _value;
	Priority _priority;
public:
	Item();
	Item(const TValue& value);
	Item(const TValue& value, const Priority& priority);
	virtual ~Item();

	TValue getValue() const;
	void setValue(const TValue& value);

	Priority getPriority() const override;
	void setPriority(const Priority& value);
};

#endif