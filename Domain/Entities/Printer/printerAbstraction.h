#ifndef PRINTER_ABSTRACTION_H
#define PRINTER_ABSTRACTION_H

#include "../../../lib.h"
#include "../../../Core/core.h"
#include "../../../Data/data.h"
#include "../Job/job.h"
#include "printerInterface.h"

class AStat abstract
    : public IStat
{
private:
    string _userName;
    string _time;
public:
    AStat() = delete;
    AStat(const string& userName, const string& time);
    virtual ~AStat();

    string getUserName() const override;
    string getTime() const override;
};

template<typename TValue0, typename TValue1>
class APrinter abstract
    : public IPrinter<TValue0, TValue1>
{
private:
    QueueProvider<TValue0> _jobQueue;
    QueueProvider<TValue1> _statQueue;
    size_t _counter;
protected:
    QueueProvider<TValue0>& getJobQueue() override;
    QueueProvider<TValue1>& getStatQueue() override;
    TValue1 createStatQueue(const string& userName, const string& time) override;

    size_t getCounter() const override;
    void setCounter(const size_t& value) override;
public:
    APrinter();
    virtual ~APrinter();
};

#endif