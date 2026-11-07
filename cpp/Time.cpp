#include "../h/Time.h"

void Time::command() {
    tm* now = localtime(&time);
    *output << now->tm_hour << ":" << now->tm_min << ":" << now->tm_sec << std::flush;
}