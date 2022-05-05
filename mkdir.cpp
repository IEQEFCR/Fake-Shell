#include <sys/stat.h>
#include <sys/types.h>
#include <unistd.h>

int main(int argc, char** argv) {
    if (argc == 1)
        return 0;
    for (int i = 1; i < argc; i++)
        if (0 != access(*(argv + i), 0))
            mkdir(*(argv + i), S_IRWXU | S_IRWXG | S_IRWXO);
}