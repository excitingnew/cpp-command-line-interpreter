#ifndef OOP_PROJEKAT_PROMPT_H
#define OOP_PROJEKAT_PROMPT_H

#include "../h/CommandBaseInterface.h"


class Prompt: public CommandBaseInterface{
public:
    explicit Prompt(string arg);

    // Prints changed command prompt
    void command() override;
};

inline Prompt::Prompt(string arg): CommandBaseInterface(){ argument = std::move(arg);}

#endif //OOP_PROJEKAT_PROMPT_H
