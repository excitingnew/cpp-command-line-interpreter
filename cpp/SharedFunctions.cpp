#include "../h/SharedFunctions.h"

bool SharedFunctions::isFile(vector<string> words){
    unsigned long long size = words.at(0).size();
    return size > 4 && words.at(0)[size-4] == '.' && words.at(0)[size-3] == 't' && words.at(0)[size-2] == 'x' && words.at(0)[size-1] == 't';
}