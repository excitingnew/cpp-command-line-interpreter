#ifndef OOP_PROJEKAT_EXECUTETIME_H
#define OOP_PROJEKAT_EXECUTETIME_H

#include <iostream>
#include <vector>

using namespace std;

class ExecuteTime{
public:
    ~ExecuteTime();

    static ExecuteTime* Instance();

    virtual void start(vector<string> *words, bool *redirection, string nameOfRedirectionFile, bool *space, const string& line);
};

inline ExecuteTime::~ExecuteTime() {}

#endif //OOP_PROJEKAT_EXECUTETIME_H
