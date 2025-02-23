#include "../../lib.h"
#include "item.h"

template<typename TValue> Item<TValue>::Item(const TValue& value)
	: _value(new TValue(value))
{}
template<typename TValue> Item<TValue>::~Item() { if (_value) { delete _value; } }

template<typename TValue> void* Item<TValue>::getValue() { return static_cast<void*>(_value); }
template<typename TValue> void Item<TValue>::setValue(const void* value) { if (_value) { delete _value; } _value = new TValue(*static_cast<const TValue*>(value)); }

template<typename TValue> TValue* Item<TValue>::getValueWithType() const { return _value; }

template class Item<int>;
template class Item<unsigned int>;
template class Item<long long>;
template class Item<unsigned long long>;
template class Item<short>;
template class Item<unsigned short>;
template class Item<double>;
template class Item<float>;
template class Item<bool>;
template class Item<char>;
template class Item<string>;
