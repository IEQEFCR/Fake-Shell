#include "shell.h"

int main(int argc, char** argv) {
    if (argc == 1) {
        char tp;
    }
    char tp, args[1024], cmd[2048] = "";
    int len = 1;
    args[0] = ' ';
    int cmd_site = 1;
    if (strncmp(*(argv + 1), "-d", 2) == 0) {
        char* div = *(argv + 1);
        char d = ' ';
        cmd_site = 2;
        div += 2;
        if (*div == '\0'){
            div = *(argv + 2), cmd_site++;
        }
        if (*div == '\'') {
            if (*(div + 1) == '\\')
                d = *(div + 2);
            else
                d = *(div + 1);
        } else if (*div == '\\') {
            d = *(div + 1);
        } else
            d = *div;
        while ((tp = getchar()) != EOF)
            args[len++] = (tp == d ? ' ' : tp);
        if (*(argv+cmd_site)==NULL) {
            printf("%s", args + 1);
            return 0;
        }
    } else {
        while ((tp = getchar()) != EOF)
            args[len++] = tp;
    }

    while (args[len - 1] == ' ' || args[len - 1] == '\n')
        len--;
    args[len] = '\0';
    for (int i = cmd_site; i < argc; i++) {
        if (i > 1)
            strcat(cmd, " ");
        strcat(cmd, *(argv + i));
    }
    strcat(cmd, args);
    translate(cmd);
    return 0;
}