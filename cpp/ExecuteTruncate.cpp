#include "../h/ExecuteTruncate.h"
#include "../h/Truncate.h"
#include "../h/Exceptions.h"
#include "../h/SharedFunctions.h"

ExecuteTruncate* ExecuteTruncate::Instance() {
    static ExecuteTruncate instance;
    return &instance;
}

void ExecuteTruncate::start(vector<string> *words, const string& line) {
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

    (new Truncate(fileNameInput))->command();
}