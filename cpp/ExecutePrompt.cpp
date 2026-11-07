#include "../h/ExecutePrompt.h"
#include "../h/Prompt.h"
#include "../h/Exceptions.h"

ExecutePrompt* ExecutePrompt::Instance() {
    static ExecutePrompt instance;
    return &instance;
}

void ExecutePrompt::start(vector<string> *words, const string& line) {
    string argument;

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

    if(argument.empty()){
        throw SyntaxError("Argument missing.");
    }

    if(!(*words).empty()){
        throw UnexpectedCharacters(1, (*words).at(0), line);
    }

    (new Prompt(argument))->command();
}