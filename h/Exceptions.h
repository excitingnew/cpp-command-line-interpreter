#ifndef OOP_PROJEKAT_EXCEPTIONS_H
#define OOP_PROJEKAT_EXCEPTIONS_H

#include <string>
#include <exception>
#include <utility>
using namespace std;

class UnknownCommand: public exception{
public:
    explicit UnknownCommand(const string& command);
    [[nodiscard]] const char* what() const noexcept override {
        return message.c_str();
    }
private:
    string message;
};

class UnexpectedCharacters: public exception{
public:
    explicit UnexpectedCharacters(unsigned long long pos, const string& word, const string& line);
    [[nodiscard]] const char* what() const noexcept override {
        return message.c_str();
    }
private:
    string message;
};

class SyntaxError: public exception{
public:
    explicit SyntaxError(const string& msg);
    [[nodiscard]] const char* what() const noexcept override {
        return message.c_str();
    }
private:
    string message;
};

class SemanticError: public exception{
public:
    explicit SemanticError(const string& msg);
    [[nodiscard]] const char* what() const noexcept override {
        return message.c_str();
    }
private:
    string message;
};

class SystemError: public exception{
public:
    explicit SystemError(const string& msg);
    [[nodiscard]] const char* what() const noexcept override {
        return message.c_str();
    }
private:
    string message;
};

inline SystemError::SystemError(const string& msg){
    message = "System error: " + msg;
}

inline SemanticError::SemanticError(const string& msg){
    message = "Semantic error: " + msg;
}

inline SyntaxError::SyntaxError(const string& msg){
    message = "Syntax error: " + msg;
}

inline UnexpectedCharacters::UnexpectedCharacters(unsigned long long pos, const string& word, const string& line){
    unsigned long long position;
    position = line.find(word);
    position += pos-1;
    message = "Error: Unexpected characters:\n" + line + "\n";
    string pointer;
    while (position){
        pointer += ' ';
        position--;
    }
    pointer += '^';
    message += pointer;
}

inline UnknownCommand::UnknownCommand(const string& command){
    message = "Error: Unknown command: " + command;
}
#endif //OOP_PROJEKAT_EXCEPTIONS_H
