#include "../h/Echo.h"
#include "../h/Definitions.h"

void Echo::command() {

    if(!argument.empty()){

        for (int i = 1; i < argument.size()-1; ++i) {
            if(argument[i] == '\\' && i+1 < argument.size()-1 && argument[i+1] == 'n'){
                *output << endl << std::flush;
                i++;
            }else{
                *output << argument[i] << std::flush;
            }
        }
    }else{
        char character;
        string outputString;
        while (input->get(character)){
            if(character == END){
                input->get(character);
                break;
            }
            outputString += character;
        }
        *output << outputString << std::flush;
    }
}
