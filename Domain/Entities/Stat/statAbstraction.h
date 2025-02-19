#ifndef PRINTER_STAT_ABSTRACTION_H
#define PRINTER_STAT_ABSTRACTION_H

#include "../../../lib.h"
#include "../../../Core/core.h"
#include "statInterface.h"

class AStat abstract
    : public IStat<string>
{
private:
    size_t _id;

    string _userName;
    string _time;
    string _executedTime;
public:
    AStat() = delete;
    AStat(const size_t& id, const string& userName, const string& time, const string& executedTime);
    virtual ~AStat();

    size_t getId() const;

    string getUserName() const override;
    string getTime() const override;

    string getExecutedTime() const override;
    void setExecutedTime(const string& value) override;
};

#endif