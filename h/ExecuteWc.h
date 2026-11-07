#ifndef OOP_PROJEKAT_EXECUTEWC_H
#define OOP_PROJEKAT_EXECUTEWC_H

#include <iostream>
#include <vector>

using namespace std;

class ExecuteWc{
public:
    ~ExecuteWc();

    static ExecuteWc* Instance();

    virtual void start(vector<string> *words, bool *redirection, string nameOfRedirectionFileIn, string nameOfRedirectionFileOut, bool *space, const string& line);
};

inline ExecuteWc::~ExecuteWc() {}

#endif //OOP_PROJEKAT_EXECUTEWC_H
