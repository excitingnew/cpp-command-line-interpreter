#include "../h/Date.h"

void Date::command() {
    tm* now = localtime(&time);
    *output << now->tm_mday << "." << now->tm_mon + 1 << "." << now->tm_year + 1900 << "." << std::flush;
}