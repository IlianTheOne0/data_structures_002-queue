#ifndef PRIORITY_ITEM_H
#define PRIORITY_ITEM_H

#include "../Item/item.h"
#include "IPriorityItem.h"

template<typename TValue>
class PriorityItem
    : public Item<TValue>, public IPriorityItem
{
private:
    Priority _priority;
public:
    PriorityItem(const TValue& value, Priority priority = Normal);
    ~PriorityItem() override = default;

    Priority getPriority() const override;
    void setPriority(const Priority& priority) override;
};
#endif