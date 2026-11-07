#include "../h/Rm.h"
#include <filesystem>

void Rm::command() {
    filesystem::path path = nameOfFileInput;
    filesystem::remove(path);
}