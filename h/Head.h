#ifndef OOP_PROJEKAT_HEAD_H
#define OOP_PROJEKAT_HEAD_H

#include <utility>
#include "../h/CommandBaseInterface.h"
#include "../h/Exceptions.h"


class Head: public CommandBaseInterface{
public:
    explicit Head(string arg, string fileNameInput, string fileNameOutput, bool app, string n);

    // Prints first -n lines from input
    void command() override;

private:
    string ncount;
};

inline Head::Head(string arg, string fileNameInput, string fileNameOutput, bool app, string n): CommandBaseInterface(){
    ncount = std::move(n);
    append = app;
    argument = std::move(arg);
    nameOfFileInput = std::move(fileNameInput);
    if(!nameOfFileInput.empty()) {
        inputFile.open(nameOfFileInput);
        if(!inputFile.is_open()){
            throw SystemError("File can not be opened.");
        }
        input = &inputFile;
    }else{
        input = &std::cin;
    }
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

#endif //OOP_PROJEKAT_HEAD_H
