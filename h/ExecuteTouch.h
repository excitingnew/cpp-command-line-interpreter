#ifndef OOP_PROJEKAT_EXECUTETOUCH_H
#define OOP_PROJEKAT_EXECUTETOUCH_H

#include <iostream>
#include <vector>

using namespace std;

class ExecuteTouch{
public:
    ~ExecuteTouch();

    static ExecuteTouch* Instance();

    virtual void start(vector<string> *words, const string& line);
};

inline ExecuteTouch::~ExecuteTouch() {}


#endif //OOP_PROJEKAT_EXECUTETOUCH_H
