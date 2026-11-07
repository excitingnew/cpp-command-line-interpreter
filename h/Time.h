#ifndef OOP_PROJEKAT_TIME_H
#define OOP_PROJEKAT_TIME_H

#include <utility>
#include "../h/TimeBaseInterface.h"
#include "../h/Exceptions.h"


class Time: public TimeBaseInterface{
public:
    explicit Time(string fileNameOutput, bool app);

    void command() override;

};

inline Time::Time(string fileNameOutput, bool app): TimeBaseInterface(){
    append = app;
    nameofFileOutput = std::move(fileNameOutput);
    if(!nameofFileOutput.empty()) {
        if(append){
            outputFile.open(nameofFileOutput.c_str(), std::ios::app);
            if(!outputFile.is_open()){
                throw SystemError("File can not be opened.");
            }
        }else{
            outputFile.open(nameofFileOutput.c_str());
            if(!outputFile.is_open()){
                throw SystemError("File can not be opened.");
            }
        }
        output = &outputFile;
    }else{
        output = &std::cout;
    }
}

#endif //OOP_PROJEKAT_TIME_H
