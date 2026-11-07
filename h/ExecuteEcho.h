#ifndef OOP_PROJEKAT_EXECUTEECHO_H
#define OOP_PROJEKAT_EXECUTEECHO_H

#include <iostream>
#include <vector>

using namespace std;

class ExecuteEcho{
public:
    ~ExecuteEcho();

    static ExecuteEcho* Instance();

    virtual void start(vector<string> *words, bool *redirection, string nameOfRedirectionFileIn, string nameOfRedirectionFileOut, bool *space, const string& line);
};

inline ExecuteEcho::~ExecuteEcho() {}

#endif //OOP_PROJEKAT_EXECUTEECHO_H
