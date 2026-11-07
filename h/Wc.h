#ifndef OOP_PROJEKAT_WC_H
#define OOP_PROJEKAT_WC_H

#include <utility>
#include "../h/CommandBaseInterface.h"
#include "../h/Exceptions.h"


class Wc: public CommandBaseInterface{
public:
    explicit Wc(string arg, string fileNameInput, string fileNameOutput, bool app, string opt);
    // Counts words or characters depending on an option
    void command() override;

private:
    int countWordInArgument();
    string option;
};

inline Wc::Wc(string arg, string fileNameInput, string fileNameOutput, bool app, string opt): CommandBaseInterface(){
    option = std::move(opt);
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

#endif //OOP_PROJEKAT_WC_H
