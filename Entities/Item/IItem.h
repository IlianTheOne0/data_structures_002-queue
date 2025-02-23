#ifndef ITEM_INTERFACE_H
#define ITEM_INTERFACE_H

class IItem
{
public:
    virtual ~IItem() = default;
    virtual void* getValue() = 0;
    virtual void setValue(const void* value) = 0;
};

#endif