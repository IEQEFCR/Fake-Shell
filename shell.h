#ifndef SHELL
#define SHELL

#include <iostream>
#include <signal.h>
#include <readline/readline.h>
#include <readline/history.h>
#include <stdlib.h>
#include <cstring>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <dirent.h>
#include "tools.h"

void signal_handler(int sig);
void init();
void exit();
void cd(char *path_name);
void echo(char *msg);
void pwd();
int translate(char *cmd);
int divide(char *cmd);
void loop();

#endif