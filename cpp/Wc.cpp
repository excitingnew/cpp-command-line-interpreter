#include "../h/Wc.h"
#include "../h/Definitions.h"

int Wc::countWordInArgument(){
    int numberOfCharacters = 0;
    int count = 0;
    string word;

    while (argument[numberOfCharacters] != '\0'){
        if(isspace(argument[numberOfCharacters])){
            if(!word.empty()){
                count++;
            }

            word = "";
            numberOfCharacters++;

            while (isspace(argument[numberOfCharacters])){
                numberOfCharacters++;
            }
        }else{
            word += argument[numberOfCharacters];
            numberOfCharacters++;
        }
    }

    if(!word.empty()){
        count++;
    }

    return count;
}

void Wc::command() {
    if(!argument.empty()){
        if(option == "-w")
            *output << countWordInArgument() << std::flush;
        else
            *output << argument.size()-2 << std::flush;
    }else{
        char character;
        int count = 0;

        if(option == "-w"){
            string word;

            while (input->get(character)){
                if(character == END){
                    input->get(character);
                    break;
                }
                if(isspace(character)){
                    if(!word.empty()){
                        count++;
                    }
                    word = "";
                }else{
                    word += character;
                }
            }

            if(!word.empty()){
                count++;
            }
        }else{
            while (input->get(character)){
                if(character == END){
                    input->get(character);
                    break;
                }
                if(character != '\n') count++;
            }
        }
        *output << count << std::flush;
    }
}