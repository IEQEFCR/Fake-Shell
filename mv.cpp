#include <stdio.h>
#include "include/tools.h"
#include <unistd.h>

int main(int argc, char* argv[]) {
    if (link(argv[1], argv[2]) == -1)  //先硬链接
        warn("Failed ! :-( "); 
    remove(argv[1]); //再删除原来的链接
    return 0;
}