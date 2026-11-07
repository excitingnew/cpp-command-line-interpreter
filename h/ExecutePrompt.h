//
// Created by majaa on 7/5/2025.
//

#ifndef OOP_PROJEKAT_EXECUTEPROMPT_H
#define OOP_PROJEKAT_EXECUTEPROMPT_H

#include <iostream>
#include <vector>

using namespace std;

// Find argument to call Prompt
class ExecutePrompt{
public:
    ~ExecutePrompt();

    static ExecutePrompt* Instance();

    virtual void start(vector<string> *words, const string& line);
};

inline ExecutePrompt::~ExecutePrompt() {}

#endif //OOP_PROJEKAT_EXECUTEPROMPT_H
