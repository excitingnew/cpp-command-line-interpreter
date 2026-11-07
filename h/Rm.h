#ifndef OOP_PROJEKAT_RM_H
#define OOP_PROJEKAT_RM_H

#include "../h/CommandBaseInterface.h"

class Rm: public CommandBaseInterface{
public:
    explicit Rm(string fileNameInput);

    // Deletes a file with given name
    void command() override;
};

inline Rm::Rm(string fileNameInput): CommandBaseInterface(){ nameOfFileInput = std::move(fileNameInput);}

#endif //OOP_PROJEKAT_RM_H
