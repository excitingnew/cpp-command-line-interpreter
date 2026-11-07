#include "../h/Touch.h"
#include "../h/Exceptions.h"
#include <filesystem>

void Touch::command() {
    if(filesystem::exists(nameOfFileInput)){
        throw SemanticError("File already exists." );
    }else{
        ofstream{nameOfFileInput};
    }
}