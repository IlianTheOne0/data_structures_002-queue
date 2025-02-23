#include "priorityItem.h"

template<typename TValue> PriorityItem<TValue>::PriorityItem()
	: Item<TValue>(), _priority(Priority::Normal)
{}
template<typename TValue> PriorityItem<TValue>::PriorityItem(TValue value)
	: Item<TValue>(value), _priority(Priority::Normal)
{}
template<typename TValue> PriorityItem<TValue>::PriorityItem(TValue value, Priority priority)
	: Item<TValue>(value), _priority(priority)
{}

template<typename TValue> Priority PriorityItem<TValue>::getPriority() const { return _priority; }
template<typename TValue> void PriorityItem<TValue>::setPriority(const Priority& value) { _priority = value; }