#include "../h/Truncate.h"
#include "../h/Exceptions.h"

void Truncate::command() {
    fstream f(nameOfFileInput, std::ios::out | std::ios::trunc);
    if(!f.is_open()){
        throw SystemError("File can not be opened.");
    }
    f.close();
}