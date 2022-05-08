#include <stdio.h>
#include <tools.h>
#include <unistd.h>
#include <shell.h>

int main(int argc, char* argv[]) {
    char cmd[1024]="cat ";
    strcat(cmd,argv[1]);
    strcat(cmd,">");
    strcat(cmd,argv[2]);
    translate(cmd); //偷懒写法
}