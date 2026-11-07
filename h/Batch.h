#ifndef OOP_PROJEKAT_BATCH_H
#define OOP_PROJEKAT_BATCH_H

#include <utility>
#include "../h/CommandBaseInterface.h"
#include "../h/Exceptions.h"

class Batch: public CommandBaseInterface{
public:
    explicit Batch(string arg, string fileNameInput);

    // Batch interprets each commend like a separate unit
    void command() override;
};

inline Batch::Batch(string arg, string fileNameInput): CommandBaseInterface(){
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
}

#endif //OOP_PROJEKAT_BATCH_H
