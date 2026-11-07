#ifndef OOP_PROJEKAT_TR_H
#define OOP_PROJEKAT_TR_H

#include <utility>
#include "../h/CommandBaseInterface.h"
#include "../h/Exceptions.h"


class Tr: public CommandBaseInterface{
public:
    explicit Tr(string arg, string fileNameInput, string fileNameOutput, bool app, string wh, string wi);

    // Replaces what with with in text, or deletes every what if with was not given
    void command() override;

private:
    string what;
    string with;
};

inline Tr::Tr(string arg, string fileNameInput, string fileNameOutput, bool app, string wh, string wi): CommandBaseInterface(){
    what=std::move(wh);
    with = std::move(wi);
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

#endif //OOP_PROJEKAT_TR_H
