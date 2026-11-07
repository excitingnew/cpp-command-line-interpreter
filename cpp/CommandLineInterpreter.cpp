#include "../h/CommandLineInterpreter.h"
#include "../h/CommandLine.h"
#include <string>

string CommandLineInterpreter::commandPrompt = "$ ";
istream* CommandLineInterpreter::input = &std::cin;
string CommandLineInterpreter::argument;

CommandLineInterpreter* CommandLineInterpreter::Instance() {
    static CommandLineInterpreter instance;
    return &instance;
}

void CommandLineInterpreter::start() {
    string line;
    // Get line by line from file or cin
    if(argument.empty()){
        if(input == &std::cin) cout << commandPrompt;
        while (getline(*input,line)){
            CommandLine::Instance()->start(line);
            if(input == &std::cin) cout << commandPrompt;
        }
    // For batch with "argument"
    }else{
        for (int i = 1; i < argument.size()-1; ++i) {
            if(argument[i] == '\\' && i+1 < argument.size()-1 && argument[i+1] == 'n'){
                i++;
                CommandLine::Instance()->start(line);
                line = "";
            }else{
                line += argument[i];
            }
        }
        if(!line.empty()) CommandLine::Instance()->start(line);
    }
}