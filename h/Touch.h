#ifndef OOP_PROJEKAT_TOUCH_H
#define OOP_PROJEKAT_TOUCH_H

#include "../h/CommandBaseInterface.h"


class Touch: public CommandBaseInterface{
public:
    explicit Touch(string fileNameInput);

    // Makes a file if it does not exist
    void command() override;

};
inline Touch::Touch(string fileNameInput): CommandBaseInterface(){ nameOfFileInput = std::move(fileNameInput);}


#endif //OOP_PROJEKAT_TOUCH_H
