#ifndef OOP_PROJEKAT_COMMANDBASEINTERFACE_H
#define OOP_PROJEKAT_COMMANDBASEINTERFACE_H

#include <iostream>
#include <fstream>

using namespace std;

// Interface for all commands
class CommandBaseInterface{
public:
    virtual void command() = 0;
protected:
    string argument;
    string nameOfFileInput;
    string nameofFileOutput;
    istream *input;
    ostream *output;
    ifstream inputFile;
    ofstream outputFile;
    bool append;
};

#endif //OOP_PROJEKAT_COMMANDBASEINTERFACE_H
