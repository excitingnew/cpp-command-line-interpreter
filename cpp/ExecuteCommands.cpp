#include "../h/ExecuteCommands.h"
#include "../h/AllExecuteCommand.h"
#include "../h/Exceptions.h"
#include <unordered_map>
#include <string>

void initializeMap(unordered_map<string, int> *map){
    (*map)["echo"] = 1;
    (*map)["prompt"] = 2;
    (*map)["time"] = 3;
    (*map)["date"] = 4;
    (*map)["touch"] = 5;
    (*map)["truncate"] = 6;
    (*map)["rm"] = 7;
    (*map)["wc"] = 8;
    (*map)["tr"] = 9;
    (*map)["head"] = 10;
    (*map)["batch"] = 11;
}

ExecuteCommands* ExecuteCommands::Instance() {
    static ExecuteCommands instance;
    return &instance;
}

void ExecuteCommands::start(vector<string> words, const string& line) {

    bool redirection = false;
    bool space = false;
    string nameOfRedirectionFileIn = "redirection1.txt";
    string nameOfRedirectionFileOut = "redirection2.txt";
    unordered_map<string, int> map;

    initializeMap(&map);

    while(!words.empty()){
        try{
            auto it = map.find(words.at(0));
            if(it != map.end()){
                switch (it->second) {
                    case 1:
                        words.erase(words.begin());
                        ExecuteEcho::Instance()->start(&words, &redirection, nameOfRedirectionFileIn, nameOfRedirectionFileOut, &space, line);
                        break;
                    case 2:
                        words.erase(words.begin());
                        ExecutePrompt::Instance()->start(&words, line);
                        break;
                    case 3:
                        if(redirection){
                            throw SyntaxError("Time can not have input stream.");
                        }
                        words.erase(words.begin());
                        ExecuteTime::Instance()->start(&words, &redirection, nameOfRedirectionFileOut, &space, line);
                        break;
                    case 4:
                        if(redirection){
                            throw SyntaxError("Date can not have input stream.");
                        }
                        words.erase(words.begin());
                        ExecuteDate::Instance()->start(&words, &redirection, nameOfRedirectionFileOut, &space, line);
                        break;
                    case 5:
                        if(redirection){
                            throw SyntaxError("Touch can not have input stream.");
                        }
                        words.erase(words.begin());
                        ExecuteTouch::Instance()->start(&words, line);
                        break;
                    case 6:
                        if(redirection){
                            throw SyntaxError("Truncate can not have input stream.");
                        }
                        words.erase(words.begin());
                        ExecuteTruncate::Instance()->start(&words, line);
                        break;
                    case 7:
                        if(redirection){
                            throw SyntaxError("Rm can not have input stream.");
                        }
                        words.erase(words.begin());
                        ExecuteRm::Instance()->start(&words, line);
                        break;
                    case 8:
                        words.erase(words.begin());
                        ExecuteWc::Instance()->start(&words, &redirection, nameOfRedirectionFileIn, nameOfRedirectionFileOut, &space, line);
                        break;
                    case 9:
                        words.erase(words.begin());
                        ExecuteTr::Instance()->start(&words, &redirection, nameOfRedirectionFileIn, nameOfRedirectionFileOut, &space, line);
                        break;
                    case 10:
                        words.erase(words.begin());
                        ExecuteHead::Instance()->start(&words, &redirection, nameOfRedirectionFileIn, nameOfRedirectionFileOut, &space, line);
                        break;
                    case 11:
                        words.erase(words.begin());
                        ExecuteBatch::Instance()->start(&words, &redirection, nameOfRedirectionFileIn, line);
                        break;
                }
                if(space){
                    space = false;
                    cout << endl;
                }
                swap(nameOfRedirectionFileIn,nameOfRedirectionFileOut);
            }else{
                for (auto& [key,value] : map) {
                    unsigned long long position = words.at(0).find(key);
                    if(position != string::npos){
                        if(position == 0) position = words.at(0).size();
                        throw UnexpectedCharacters(position, words.at(0), line);
                    }
                }
                throw UnknownCommand(words.at(0));
            }
        } catch (exception& e) {
            cout << e.what()<<endl;
            break;
        }
    }
}