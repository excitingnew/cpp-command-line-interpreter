#ifndef OOP_PROJEKAT_EXECUTETRUNCATE_H
#define OOP_PROJEKAT_EXECUTETRUNCATE_H

#include <iostream>
#include <vector>

using namespace std;

class ExecuteTruncate{
public:
    ~ExecuteTruncate();

    static ExecuteTruncate* Instance();

    virtual void start(vector<string> *words, const string& line);
};

inline ExecuteTruncate::~ExecuteTruncate() {}

#endif //OOP_PROJEKAT_EXECUTETRUNCATE_H
