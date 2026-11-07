#ifndef OOP_PROJEKAT_ECHO_H
#define OOP_PROJEKAT_ECHO_H

#include <utility>
#include "../h/CommandBaseInterface.h"
#include "../h/Exceptions.h"

class Echo: public CommandBaseInterface{
public:
    explicit Echo(string arg, string fileNameInput, string fileNameOutput, bool app);

    // Prints file content on standard output
    void command() override;

};

inline Echo::Echo(string arg, string fileNameInput, string fileNameOutput, bool app): CommandBaseInterface(){
    append = app;
    argument = std::move(arg);
    nameOfFileInput = std::move(fileNameInput);
    if(!nameOfFileInput.empty()) {
        inputFile.open(nameOfFileInput);
        if(!inputFile.is_open()){
            throw SystemError("File can not be opened.");
        }
        input = &inputFile;  //input istream reference to inputFile ifstream
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

#endif //OOP_PROJEKAT_ECHO_H
