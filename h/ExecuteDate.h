//
// Created by majaa on 7/5/2025.
//

#ifndef OOP_PROJEKAT_EXECUTEDATE_H
#define OOP_PROJEKAT_EXECUTEDATE_H

#include <iostream>
#include <vector>

using namespace std;

class ExecuteDate{
public:
    ~ExecuteDate();

    static ExecuteDate* Instance();

    virtual void start(vector<string> *words, bool *redirection, string nameOfRedirectionFile, bool *space, const string& line);
};

inline ExecuteDate::~ExecuteDate() {}


#endif //OOP_PROJEKAT_EXECUTEDATE_H
