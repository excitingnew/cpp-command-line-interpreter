//
// Created by majaa on 7/4/2025.
//

#ifndef OOP_PROJEKAT_EXECUTECOMMANDS_H
#define OOP_PROJEKAT_EXECUTECOMMANDS_H

#include <iostream>
#include <vector>
using namespace std;

// Based on words calls commands
class ExecuteCommands{
public:
    ~ExecuteCommands();

    static ExecuteCommands* Instance();

    virtual void start(vector<string> words,const string& line);
};

inline ExecuteCommands::~ExecuteCommands() {}

#endif //OOP_PROJEKAT_EXECUTECOMMANDS_H
