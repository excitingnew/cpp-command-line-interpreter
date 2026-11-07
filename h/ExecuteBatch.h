//
// Created by majaa on 7/6/2025.
//

#ifndef OOP_PROJEKAT_EXECUTEBATCH_H
#define OOP_PROJEKAT_EXECUTEBATCH_H

#include <iostream>
#include <vector>

using namespace std;

class ExecuteBatch{
public:
    ~ExecuteBatch();

    static ExecuteBatch* Instance();

    virtual void start(vector<string> *words, bool *redirection, string nameOfRedirectionFileIn, const string& line);
};

inline ExecuteBatch::~ExecuteBatch() {}

#endif //OOP_PROJEKAT_EXECUTEBATCH_H
