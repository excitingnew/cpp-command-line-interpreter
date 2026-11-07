#include "../h/Tr.h"
#include "../h/Definitions.h"

void Tr::command() {
    if(argument.empty()) {
        char character;
        while (input->get(character)) {
            if (character == END) {
                input->get(character);
                break;
            }
            argument += character;
        }
    }else{
        argument.pop_back();
        argument.erase(0,1);
    }

    unsigned long long position = argument.find(what);
    while(position != string::npos){
        argument.replace(position, what.size(), with);
        position = argument.find(what);
    }

    for (int i = 0; i < argument.size(); ++i) {
        if(argument[i] == '\\' && i+1 < argument.size()-1 && argument[i+1] == 'n'){
            *output << endl << std::flush;
            i++;
        }else{
            *output << argument[i] << std::flush;
        }
    }
}