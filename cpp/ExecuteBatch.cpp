#include <utility>
#include "../h/ExecuteBatch.h"
#include "../h/Batch.h"
#include "../h/SharedFunctions.h"
#include "../h/Exceptions.h"

ExecuteBatch* ExecuteBatch::Instance() {
    static ExecuteBatch instance;
    return &instance;
}

void ExecuteBatch::start(vector<string> *words, bool *redirection,string nameOfRedirectionFileIn, const string& line) {
    string argument;
    string fileNameInput;

    if(*redirection){
        fileNameInput = std::move(nameOfRedirectionFileIn);
        *redirection = false;
    }

    if(!(*words).empty() && (*words).at(0)[0] == '\"'&& (*words).at(0).size() > 1 && (*words).at(0)[(*words).at(0).size()-1] == '\"'){
        argument = (*words).at(0);
        (*words).erase((*words).begin());
    }

    if(!(*words).empty() && ((*words).at(0) == "<" || SharedFunctions::isFile(*words))){
        if((*words).at(0) == "<") (*words).erase((*words).begin());
        if((*words).empty() || !SharedFunctions::isFile(*words)){
            throw SyntaxError("File for input stream redirection is not specified or not in good format.");
        }
        if(!fileNameInput.empty()) {
            throw SemanticError("File for input stream is already defined.");
        }
        fileNameInput = (*words).at(0);
        (*words).erase((*words).begin());
    }

    if(!argument.empty() && !fileNameInput.empty()) {
        throw SemanticError("File and argument for input stream can not be defined at the same time.");
    }

    if(!(*words).empty() && !*redirection){
        throw UnexpectedCharacters(1, (*words).at(0), line);
    }

    (new Batch(argument, fileNameInput))->command();
}