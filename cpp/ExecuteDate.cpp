#include <utility>

#include "../h/ExecuteDate.h"
#include "../h/Date.h"
#include "../h/SharedFunctions.h"
#include "../h/Exceptions.h"

ExecuteDate* ExecuteDate::Instance() {
    static ExecuteDate instance;
    return &instance;
}

void ExecuteDate::start(vector<string> *words, bool *redirection,string nameOfRedirectionFile, bool *space, const string& line) {
    string argument;
    string fileNameOutput;
    bool append = false;

    if(!(*words).empty() && (*words).at(0)[0] == '>'){
        if((*words).at(0)[1] == '>') append = true;
        (*words).erase((*words).begin());
        if((*words).empty() || !SharedFunctions::isFile(*words)){
            throw SyntaxError("File for output stream redirection is not specified or not in good format.");
        }
        fileNameOutput = (*words).at(0);
        (*words).erase((*words).begin());
    }

    if(!(*words).empty() && (*words).at(0) == "|"){
        (*words).erase((*words).begin());
        if(!fileNameOutput.empty()) {
            throw SemanticError("File for output stream is already defined.");
        }
        *redirection = true;
        fileNameOutput = std::move(nameOfRedirectionFile);
    }

    if(!(*words).empty() && !*redirection){
        throw UnexpectedCharacters(1, (*words).at(0), line);
    }

    if(fileNameOutput.empty()) *space = true;
    (new Date(fileNameOutput, append))->command();
}