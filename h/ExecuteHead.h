#ifndef OOP_PROJEKAT_EXECUTEHEAD_H
#define OOP_PROJEKAT_EXECUTEHEAD_H

#include <iostream>
#include <vector>

using namespace std;

class ExecuteHead{
public:
    ~ExecuteHead();

    static ExecuteHead* Instance();

    virtual void start(vector<string> *words, bool *redirection, string nameOfRedirectionFileIn, string nameOfRedirectionFileOut, bool *space, const string& line);
};

inline ExecuteHead::~ExecuteHead() {}

#endif //OOP_PROJEKAT_EXECUTEHEAD_H
