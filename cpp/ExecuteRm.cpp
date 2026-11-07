#include "../h/ExecuteRm.h"
#include "../h/Rm.h"
#include "../h/Exceptions.h"
#include "../h/SharedFunctions.h"

ExecuteRm* ExecuteRm::Instance() {
    static ExecuteRm instance;
    return &instance;
}

void ExecuteRm::start(vector<string> *words, const string& line) {
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

    (new Rm(fileNameInput))->command();
}