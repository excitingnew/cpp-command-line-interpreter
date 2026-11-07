#include "../h/Head.h"
#include "../h/Definitions.h"

void Head::command() {
    try{
        ncount = ncount.substr(2,5);

        int count = stoi(ncount);
        int current = 0;

        if(!argument.empty()){
            for (int i = 1; i < argument.size()-1 && current < count; ++i) {
                if(argument[i] == '\\' && i+1 < argument.size()-1 && argument[i+1] == 'n'){
                    i++;
                    current++;
                    if(current < count) *output << endl << std::flush;
                }else{
                    *output << argument[i] << std::flush;
                }
            }
        }else{
            string line;
            string outputString[count];
            while(getline(*input, line)){
                if(current < count){
                    if(line[line.size()-1] == END){
                        line.pop_back();
                        if(!line.empty()){
                            outputString[current] = line;
                            current++;
                        }
                        break;
                    }
                    outputString[current] = line;
                    current++;
                }
                if(line[line.size()-1] == END) break;
            }

            for (current = 0; current < count-1; ++current) {
                *output << outputString[current]<< endl << std::flush;
            }
            *output << outputString[current] << std::flush;
        }
    } catch (const std::invalid_argument& e) {
        throw SystemError("Argument for -ncount is not in good format.");
    }
}