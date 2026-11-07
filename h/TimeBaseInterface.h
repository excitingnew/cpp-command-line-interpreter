#ifndef OOP_PROJEKAT_TIMEBASEINTERFACE_H
#define OOP_PROJEKAT_TIMEBASEINTERFACE_H

#include "../h/CommandBaseInterface.h"
#include <iostream>
using namespace std;
#include <ctime>

// Commands that uses time
class TimeBaseInterface: public CommandBaseInterface{
protected:
    TimeBaseInterface();

    time_t time;
};

inline TimeBaseInterface::TimeBaseInterface() { time = std::time(nullptr);}

#endif //OOP_PROJEKAT_TIMEBASEINTERFACE_H
