#include <utility>
#include "../h/ExecuteEcho.h"
#include "../h/Echo.h"
#include "../h/SharedFunctions.h"
#include "../h/Exceptions.h"

ExecuteEcho* ExecuteEcho::Instance() {
    static ExecuteEcho instance;
    return &instance;
}

void ExecuteEcho::start(vector<string> *words, bool *redirection,string nameOfRedirectionFileIn, string nameOfRedirectionFileOut, bool *space, const string& line) {
    string argument;
    string fileNameInput;
    string fileNameOutput;
    bool append = false;

    if(*redirection){
        fileNameInput = std::move(nameOfRedirectionFileIn);
        *redirection = false;
    }

    if(!(*words).empty() && (*words).at(0)[0] == '\"' && (*words).at(0).size() > 1 && (*words).at(0)[(*words).at(0).size()-1] == '\"'){
        argument = (*words).at(0);
        (*words).erase((*words).begin());
    }

    if(!(*words).empty() && argument.empty() && (*words).at(0).find('\"') != string::npos){
        unsigned long long position = (*words).at(0).find('\"');
        string second = (*words).at(0).substr(position+1);
        unsigned long long position2 = second.find('\"');
        if(position2 != string::npos){
            if(position == 0) position = position2+3;
            throw UnexpectedCharacters(position, (*words).at(0), line);
        }
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
    (new Echo(argument, fileNameInput, fileNameOutput, append))->command();
}