#include <unistd.h>
#include <fstream>
#include <iostream>
int main(int argc, char** argv) {
    if (argc == 1) {
        char tp;
        while ((tp = getchar()) != EOF)
            putchar(tp);
        return 0;
    }
    for (int i = 1; i < argc; i++) {
        close(0);
        fopen(*(argv+i),"r");
        char tp;
        while ((tp = getchar()) != EOF)
            putchar(tp);
    }
    return 0;
}
