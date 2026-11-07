#include "../h/ExecuteWc.h"
#include "../h/Wc.h"
#include <utility>
#include "../h/Exceptions.h"
#include "../h/SharedFunctions.h"


ExecuteWc* ExecuteWc::Instance() {
    static ExecuteWc instance;
    return &instance;
}

void ExecuteWc::start(vector<string> *words, bool *redirection,string nameOfRedirectionFileIn, string nameOfRedirectionFileOut, bool *space, const string& line) {
    string argument;
    string fileNameInput;
    string fileNameOutput;
    string option;
    bool append = false;

    if(*redirection){
        fileNameInput = std::move(nameOfRedirectionFileIn);
        *redirection = false;
    }

    if(!(*words).empty() && ((*words).at(0) == "-w" || (*words).at(0) == "-c")){
        option = (*words).at(0);
        (*words).erase((*words).begin());
    }

    if(option.empty()){
        if((*words).empty()){
            throw SyntaxError("Option not found.");
        }else{
            unsigned long long position = (*words).at(0).find("-w");
            if(position != string::npos){
                if(position == 0) position = 3;
                throw UnexpectedCharacters(position, (*words).at(0), line);
            }
            position = (*words).at(0).find("-c");
            if(position != string::npos){
                if(position == 0) position = 3;
                throw UnexpectedCharacters(position, (*words).at(0), line);
            }

            throw SyntaxError("Option is not valid.");
        }
    }

    if(!(*words).empty() && (*words).at(0)[0] == '\"' && (*words).at(0).size() > 1 && (*words).at(0)[(*words).at(0).size()-1] == '\"'){
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

    if(!argument.empty() && !fileNameInput.empty()) {
        throw SemanticError("File and argument for input stream can not be defined at the same time.");
    }

    if(!(*words).empty() && !*redirection){
        throw UnexpectedCharacters(1, (*words).at(0), line);
    }

    if(fileNameOutput.empty()) *space = true;
    (new Wc(argument, fileNameInput, fileNameOutput, append, option))->command();
}