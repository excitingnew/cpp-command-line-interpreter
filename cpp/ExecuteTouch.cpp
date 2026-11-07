//
// Created by majaa on 7/5/2025.
//

#include "../h/ExecuteTouch.h"
#include "../h/Touch.h"
#include "../h/SharedFunctions.h"
#include "../h/Exceptions.h"

ExecuteTouch* ExecuteTouch::Instance() {
    static ExecuteTouch instance;
    return &instance;
}

void ExecuteTouch::start(vector<string> *words, const string& line) {

    string fileNameInput;
    if(!(*words).empty() && SharedFunctions::isFile(*words)){
        fileNameInput = (*words).at(0);
        (*words).erase((*words).begin());
    }

    if(fileNameInput.empty()){
        throw SyntaxError("No file name or not in right format.");
    }

    if(!(*words).empty()){
        throw UnexpectedCharacters(1, (*words).at(0), line);
    }

    (new Touch(fileNameInput))->command();
}