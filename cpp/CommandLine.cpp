#include "../h/CommandLine.h"
#include "../h/ExecuteCommands.h"

CommandLine* CommandLine::Instance() {
    static CommandLine instance;
    return &instance;
}

void CommandLine::start(string line) {
    int numberOfCharacters = 0;
    vector<string> words;
    string word;

    while (line[numberOfCharacters] != '\0' && numberOfCharacters < maxCommandLineSize){
        if(line[numberOfCharacters] == ' ' || line[numberOfCharacters] == '\t'){
            // Word that starts with " is finished when it comes to ", other words are finished with space or tab
            if(!word.empty() && !(word[0] == '\"' && (word.size() == 1 || (word.size() > 1 && word[word.size()-1] != '\"')))){
                words.push_back(word);
                word = "";
            }else{
                if(!word.empty()){
                    word += line[numberOfCharacters];
                }
            }

        }else{
            if(line[numberOfCharacters] == '|' || line[numberOfCharacters] == '<'){
                if(!word.empty() && !(word[0] == '\"' && (word.size() == 1 || (word.size() > 1 && word[word.size()-1] != '\"')))){
                    words.push_back(word);
                    word = "";
                    word += line[numberOfCharacters];
                    words.push_back(word);
                    word = "";
                }else{
                    if(!word.empty()){
                        word += line[numberOfCharacters];
                    } else {
                        word += line[numberOfCharacters];
                        words.push_back(word);
                        word = "";
                    }
                }
            }else{
                if (line[numberOfCharacters] == '>') {
                    if(!word.empty() && !(word[0] == '\"' && (word.size() == 1 || (word.size() > 1 && word[word.size()-1] != '\"')))){
                        words.push_back(word);
                        word = "";
                        word += line[numberOfCharacters];
                        if(line[numberOfCharacters+1] == '>' && numberOfCharacters+1 < maxCommandLineSize){
                            word += line[++numberOfCharacters];
                        }
                        words.push_back(word);
                        word = "";
                    }else{
                        if(!word.empty()){
                            word += line[numberOfCharacters];
                        } else {
                            word += line[numberOfCharacters];
                            if(line[numberOfCharacters+1] == '>' && numberOfCharacters+1 < maxCommandLineSize){
                                word += line[++numberOfCharacters];
                            }
                            words.push_back(word);
                            word = "";
                        }
                    }
                }else{
                    word += line[numberOfCharacters];
                }
            }
        }
        numberOfCharacters++;
    }

    // Push last word if it exists
    if(!word.empty()){
        words.push_back(word);
    }

    ExecuteCommands::Instance()->start(words, line);
}