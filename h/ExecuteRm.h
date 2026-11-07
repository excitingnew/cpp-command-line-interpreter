#ifndef OOP_PROJEKAT_EXECUTERM_H
#define OOP_PROJEKAT_EXECUTERM_H

#include <iostream>
#include <vector>

using namespace std;

class ExecuteRm{
public:
    ~ExecuteRm();

    static ExecuteRm* Instance();

    virtual void start(vector<string> *words, const string& line);
};

inline ExecuteRm::~ExecuteRm() {}


#endif //OOP_PROJEKAT_EXECUTERM_H
