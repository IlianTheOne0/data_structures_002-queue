#include "priorityItem.h"

#include "../../lib.h"

template<typename TValue> PriorityItem<TValue>::PriorityItem(const TValue& value, Priority priority)
    : Item<TValue>(value), _priority(priority)
{}

template<typename TValue> Priority PriorityItem<TValue>::getPriority() const { return _priority; }
template<typename TValue> void PriorityItem<TValue>::setPriority(const Priority& priority) { _priority = priority; }

template class PriorityItem<int>;
template class PriorityItem<unsigned int>;
template class PriorityItem<long long>;
template class PriorityItem<unsigned long long>;
template class PriorityItem<short>;
template class PriorityItem<unsigned short>;
template class PriorityItem<double>;
template class PriorityItem<float>;
template class PriorityItem<bool>;
template class PriorityItem<char>;
template class PriorityItem<string>;