// g++ -o shell main.cpp shell.cpp tools.cpp -lreadline

#include "shell.h"

int main(int argc, char** argv) {
    init();
    loop();
    exit();
    return 0;
}