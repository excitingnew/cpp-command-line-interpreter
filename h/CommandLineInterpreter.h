//
// Created by majaa on 7/4/2025.
//

#ifndef OOP_PROJEKAT_COMMANDLINEINTERPRETER_H
#define OOP_PROJEKAT_COMMANDLINEINTERPRETER_H

#include <iostream>
using namespace std;

// Singleton class that represents CLI
class CommandLineInterpreter{
public:
    ~CommandLineInterpreter();

    static CommandLineInterpreter* Instance();

    // Parses input of CLI into lines
    virtual void start();
    friend class Prompt;
    friend class Batch;
private:
    static string commandPrompt;
    static string argument;
    static istream* input; //Batch can have file as input
};

inline CommandLineInterpreter::~CommandLineInterpreter() {}

#endif //OOP_PROJEKAT_COMMANDLINEINTERPRETER_H
