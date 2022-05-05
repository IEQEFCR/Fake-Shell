#include "shell.h"

int main(int argc, char** argv) {
    if (argc == 1){
        char tp;
        while ((tp = getchar()) != EOF) putchar(tp);
        return 0;
    }
    char tp,args[1024],cmd[2048];
    int len=1;
    args[0]=' ';
    while ((tp = getchar()) != EOF)
        args[len++]=tp;
    while(args[len-1]==' '||args[len-1]=='\n') len--;
    args[len]='\0';
    for(int i=1;i<argc;i++){
        if(i>1)strcat(cmd," ");
        strcat(cmd,*(argv+i));
    }
    strcat(cmd,args);
    // printf("<%s>",cmd);
    translate(cmd);
    return 0;
}