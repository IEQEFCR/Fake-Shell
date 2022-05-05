#include <dirent.h>
#include <sys/types.h>
#include <unistd.h>
#include "tools.h"

int ls(DIR* dir) {
    struct dirent* filename;
    if (dir == nullptr) {
        warn("No such dir\n");
        return 1;
    }
    bool flag = 0;
    while ((filename = readdir(dir)) != NULL) {
        if (!strcmp(filename->d_name, ".") || !strcmp(filename->d_name, "..")) {
            continue;
        }
        printf("%-27s", filename->d_name);
        if (flag)
            putchar(10);
        flag = !flag;
    }
    if (flag)
        putchar(10);
    closedir(dir);
}

int main(int argc, char** argv) {
    DIR* dir;
    if (argc == 1) {
        char tp[100];
        getcwd(tp, 100);
        dir = opendir(tp);
        ls(dir);
    } else {
        for (int i = 1; i < argc; i++) {
            printf("%s :\n",*(argv+i));
            dir = opendir(*(argv + i));
            ls(dir);
            putchar(10);
        }
    }
}