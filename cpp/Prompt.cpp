#include "../h/Prompt.h"
#include "../h/CommandLineInterpreter.h"

void Prompt::command() {
    string arg;

    for (int i = 1; i < argument.size()-1; ++i) {
        arg += argument.at(i);
    }
    //Updates the new command prompt string so future commands use the new prompt character
    CommandLineInterpreter::commandPrompt = arg + " ";
}