#include "item.h"

#include "../../../../Domain/Entities/Printer/printer.h"
#include "../../../../Domain/Entities/Job/job.h"

template<typename TValue>
Item<TValue>::Item()
	: _priority(Priority::Normal)
{ CREATE_INFO("Item <- Default constructor: called;"); }
template<typename TValue>
Item<TValue>::Item(const TValue& value)
	: _value(value), _priority(Priority::Normal)
{ CREATE_INFO("Item <- Constructor with custom value: called;"); }
template<typename TValue>
Item<TValue>::Item(const TValue& value, const Priority& priority)
	: _value(value), _priority(static_cast<Priority>(priority))
{ CREATE_INFO("Item <- Constructor with custom value and priority of it: called;"); }
template<typename TValue> Item<TValue>::~Item() { CREATE_INFO("Item <- Destructor: called;"); }

template<typename TValue> TValue Item<TValue>::getValue() const { INFO("Item -> method getValue: called;"); return _value; }
template<typename TValue> void Item<TValue>::setValue(const TValue& value) { INFO("Item -> method setValue: called;"); _value = value; }

template<typename TValue> Priority Item<TValue>::getPriority() const { INFO("Item -> method getPriority: called;"); return _priority; }
template<typename TValue> void Item<TValue>::setPriority(const Priority& value) { INFO("Item -> method setPriority: called;"); _priority = value; }

template class Item<int>;
template class Item<Job>;
template class Item<Stat>;