#include <stdio.h>
#include <unistd.h>
#include "include/tools.h"

int main(int argc, char* argv[]) {
    if (argc == 3) {
        if (link(argv[1], argv[2]) == -1)
            warn("Failed ! :-( ");
    } else if (argc == 4 && strcmp(argv[1], "-s") == 0) {
        warn("hahaha\n");
        if (symlink(argv[2], argv[3]) == -1) //源文件必须写绝对目录
            warn("Failed ! :-( ");
    }else warn("Wrong Command");
    return 0;
}