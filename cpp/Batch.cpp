#include "../h/Batch.h"
#include "../h/Definitions.h"
#include "../h/CommandLineInterpreter.h"
#include "../h/CommandLine.h"

void Batch::command() {
    string oldArgument = CommandLineInterpreter::argument;
    istream* oldInput = CommandLineInterpreter::input;
    if(!argument.empty())
        CommandLineInterpreter::argument = argument;
    else{
        if(!nameOfFileInput.empty()){
            CommandLineInterpreter::input = input;
        }else{
            string line;
            vector<string> lines;
            while (getline(*input,line)){
                if(line[line.size()-1] == END) break;
                lines.push_back(line);
            }
            line.pop_back();
            if(!line.empty())
                lines.push_back(line);
            while (!lines.empty()){
                CommandLine::Instance()->start(lines.at(0));
                lines.erase(lines.begin());
            }
            return;
        }
    }

    CommandLineInterpreter::Instance()->start();
    // Returning to original state
    CommandLineInterpreter::argument = oldArgument;
    CommandLineInterpreter::input = oldInput;
}