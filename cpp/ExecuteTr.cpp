#include "../h/ExecuteTr.h"
#include "../h/Tr.h"
#include "../h/SharedFunctions.h"
#include "../h/Exceptions.h"

ExecuteTr* ExecuteTr::Instance() {
    static ExecuteTr instance;
    return &instance;
}

void ExecuteTr::start(vector<string> *words, bool *redirection,string nameOfRedirectionFileIn, string nameOfRedirectionFileOut, bool *space,const string& line) {
    string argument;
    string fileNameInput;
    string fileNameOutput;
    string what;
    string with;
    bool append = false;

    if(*redirection){
        fileNameInput = std::move(nameOfRedirectionFileIn);
        *redirection = false;
    }

    if(!(*words).empty() && (*words).at(0)[0] == '\"' && (*words).at(0).size() > 1 && (*words).at(0)[(*words).at(0).size()-1] == '\"'){
        argument = (*words).at(0);
        (*words).erase((*words).begin());
    }

    if(!(*words).empty() && SharedFunctions::isFile(*words)){
        if(!fileNameInput.empty()) {
            throw SemanticError("File for input stream is already defined.");
        }
        fileNameInput = (*words).at(0);
        (*words).erase((*words).begin());
    }

    if(!(*words).empty() && (*words).at(0)[0] == '\"' && (*words).at(0).size() > 1 && (*words).at(0)[(*words).at(0).size()-1] == '\"'){
        what = (*words).at(0);
        what = what.substr(1, what.size()-2);
        (*words).erase((*words).begin());
    }

    if(!(*words).empty() && (*words).at(0)[0] == '\"' && (*words).at(0).size() > 1 && (*words).at(0)[(*words).at(0).size()-1] == '\"'){
        with = (*words).at(0);
        with = with.substr(1, with.size()-2);
        (*words).erase((*words).begin());
    }

    if(!(*words).empty() && (*words).at(0) == "<"){
        (*words).erase((*words).begin());
        if((*words).empty() || !SharedFunctions::isFile(*words)){
            throw SyntaxError("File for input stream redirection is not specified or not in good format.");
        }
        if(!fileNameInput.empty()) {
            throw SemanticError("File for input stream is already defined.");
        }
        fileNameInput = (*words).at(0);
        (*words).erase((*words).begin());
    }

    if(!(*words).empty() && (*words).at(0)[0] == '>'){
        if((*words).at(0)[1] == '>') append = true;
        (*words).erase((*words).begin());
        if((*words).empty() || !SharedFunctions::isFile(*words)){
            throw SyntaxError("File for output stream redirection is not specified or not in good format.");
        }
        fileNameOutput = (*words).at(0);
        (*words).erase((*words).begin());
        if(!(*words).empty() && (*words).at(0) == "<"){
            (*words).erase((*words).begin());
            if((*words).empty() || !SharedFunctions::isFile(*words)){
                throw SyntaxError("File for input stream redirection is not specified or not in good format.");
            }
            if(!fileNameInput.empty()) {
                throw SemanticError("File for input stream is already defined.");
            }
            fileNameInput = (*words).at(0);
            (*words).erase((*words).begin());
        }
    }

    if(!(*words).empty() && (*words).at(0) == "|"){
        (*words).erase((*words).begin());
        if(!fileNameOutput.empty()) {
            throw SemanticError("File for output stream is already defined.");
        }
        *redirection = true;
        fileNameOutput = std::move(nameOfRedirectionFileOut);
    }

    if(what.empty()){
        if(!argument.empty()){
            swap(argument,what);
            what = what.substr(1, what.size()-2);
        }else{
            throw SyntaxError("What has to be defined.");
        }
    }

    if(!argument.empty() && !fileNameInput.empty()) {
        if(with.empty()){
            swap(what,with);
            swap(argument,what);
            what = what.substr(1, what.size()-2);
        }else{
            throw SemanticError("File and argument for input stream can not be defined at the same time.");
        }
    }

    if(!(*words).empty() && !*redirection){
        throw UnexpectedCharacters(1, (*words).at(0), line);
    }

    if(fileNameOutput.empty()) *space = true;
    (new Tr(argument, fileNameInput, fileNameOutput, append, what, with))->command();
}