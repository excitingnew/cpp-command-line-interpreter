//
// Created by majaa on 7/4/2025.
//

#ifndef OOP_PROJEKAT_COMMANDLINE_H
#define OOP_PROJEKAT_COMMANDLINE_H

#include <iostream>
#include <vector>
using namespace std;

// Singleton class that simulates one line from CLI
class CommandLine{
public:
    ~CommandLine();

    static CommandLine* Instance();

    // Parses a line into words
    virtual void start(string line);

private:
    // Max size of one line in CLI
    const int maxCommandLineSize = 512;
};

inline CommandLine::~CommandLine() {}

#endif //OOP_PROJEKAT_COMMANDLINE_H
