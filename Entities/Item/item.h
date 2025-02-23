#ifndef ITEM_H
#define ITEM_H

#include "IItem.h"

template<typename TValue>
class Item
	: public IItem
{
private:
	TValue* _value = nullptr;
public:
	Item() = delete;
	Item(const TValue& value);
	~Item() override;

	void* getValue() override;
	void setValue(const void* value) override;

	TValue* getValueWithType() const;
};

#endif