#ifndef OOP_PROJEKAT_EXECUTETR_H
#define OOP_PROJEKAT_EXECUTETR_H

#include <iostream>
#include <vector>

using namespace std;

class ExecuteTr{
public:
    ~ExecuteTr();

    static ExecuteTr* Instance();

    virtual void start(vector<string> *words, bool *redirection, string nameOfRedirectionFileIn, string nameOfRedirectionFileOut, bool *space, const string& line);
};

inline ExecuteTr::~ExecuteTr() {}


#endif //OOP_PROJEKAT_EXECUTETR_H
