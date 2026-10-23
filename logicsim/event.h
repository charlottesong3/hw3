#ifndef EVENT_H
#define EVENT_H
#include "wire.h"

struct Event
{
    uint64_t time;
    Wire* wire;
    char state;
};



// works


struct EventLess
{

    bool operator()(const Event* lhs, const Event* rhs) const
    {

        //earlier events receive priority in the min heap 

        return lhs->time < rhs->time; //:D
    }
};

#endif