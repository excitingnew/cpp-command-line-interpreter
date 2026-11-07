#ifndef OOP_PROJEKAT_TRUNCATE_H
#define OOP_PROJEKAT_TRUNCATE_H

#include "../h/CommandBaseInterface.h"

class Truncate: public CommandBaseInterface{
public:
    explicit Truncate(string fileNameInput);
    // Deletes content of file
    void command() override;

};

inline Truncate::Truncate(string fileNameInput): CommandBaseInterface(){ nameOfFileInput = std::move(fileNameInput);}

#endif //OOP_PROJEKAT_TRUNCATE_H
