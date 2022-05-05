#include "shell.h"

std::string username = "Kai", hostname = "Magicbook", path = "~";
// char tpath[100]=" ";
const char CMD[20][100] = {"exit", "echo", "pwd", "cd"};
char tmpcmd[20][100];
bool stopped = 0;

void signal_handler(int sig) {
    if (sig == SIGINT) {
        std::cout << "\nctrl+c pressed!\n";
        stopped = true;
    }
}

void init() {
    signal(SIGINT, signal_handler);
    char tp[100];
    getcwd(tp, 100);
    path = tp;
}

void exit() {
    warn("\nExited! :-)\n");
}

void cd(char* path_name) {
    int res;
    res = chdir(path_name);
    if (res == -1) {
        warn(path_name);
        warn(": No such file or directory ! :-(\n");
        return;
    }
    char tp[100];
    getcwd(tp, 100);
    path = tp;
    return;
}

void echo(char* msg) {
    char* head = msg;
    if (*head == '\0' || *head == '\n')
        return;
    while (*head == ' ')
        head++;
    if (*head == '\"') {
        while (1) {  //*head!='\"'
            head++;
            if (*head == '\\') {
                putchar(*(head + 1));
                head += 2;
            }
            if (*head == '\"') {
                if (*(head + 1) == ' ')
                    putchar(' ');
                echo(head + 1);
                break;
            }
            putchar(*head);
        }
    } else {
        while (1) {  //*head!='\"'
            if (*head == '\\') {
                putchar(*(head + 1));
                head += 2;
            }
            if (*head == ' ') {
                putchar(' ');
                echo(head + 1);
                break;
            } else if (*head == '\0')
                break;
            else if (*head == '\"') {
                echo(head);
                break;
            }
            putchar(*head);
            head++;
        }
    }
    return;
}

void pwd() {
    char tp[100];
    getcwd(tp, 100);
    printf("%s\n", tp);
    return;
}

bool meet(char* single, char* div) {
    char* head = div;
    while (*head != '\0') {
        if (*head == *single)
            return 1;
        head++;
    }
    return 0;
}

int divide(char* cmd, char* div, char** site) {
    char* head = cmd;
    while (meet(head, div) && *head != '\0')
        head++;
    int num = 0;
    while (1) {
        int len = 0;
        *(site + num) = head;
        while (!meet(head, div) && *head != '\0') {
            // tmpcmd[num][len++] = *head;
            head++;
        }
        // tmpcmd[num][len] = '\0';
        while (meet(head, div) && *head != '\0') {
            *head = '\0';
            head++;
        }

        if (*head == '\0') {
            // ++num;
            // for (int i = 0; i < path.length(); i++)
            //     tmpcmd[num][i] = path[i];
            // tmpcmd[num][path.length()] = '\0';
            return num;
        }
        num++;
    }
}

int translate(char* cmd)  //可用trie树查找命令
{
    char* head = cmd;
    while (*head == ' ')
        head++;
    char* site[20];
    int num = divide(head, "|", site);
    if (num >= 1) {
        int fd[2];
        pipe(fd);
        pid_t child_pid;
        int* status;
        if ((child_pid = fork()) == 0) {
            int cp = dup(0);
            close(fd[1]);
            dup2(fd[0], 0);
            translate(site[1]);
            close(fd[0]);
            dup2(cp, 0);
            close(cp);
            exit(0);
        } else {
            int cp = dup(1);
            close(fd[0]);
            dup2(fd[1], 1);
            translate(site[0]);
            close(fd[1]);
            dup2(cp, 1);
            close(cp);
            while (!waitpid(child_pid, status, WNOHANG)) {
                if (stopped) {
                    stopped = 0;
                    kill(child_pid, SIGKILL);
                    return 0;
                }
            }
        }
        return 0;
    }
    num = divide(head, ">", site);
    if (num >= 1) {
        char* tp[10];
        divide(site[1], " ", tp);
        int cp=dup(1);
        close(1);
        FILE* fp = fopen(tp[0], "w");
        int fd = fileno(fp);
        translate(site[0]);
        dup2(cp, 1);
        close(cp);
        return 0;
    }
    num = divide(head, "<", site);
    if (num >= 1) {
        char* tp[10];
        divide(site[1], " ", tp);
        int cp=dup(0);
        close(0);
        FILE* fp = fopen(tp[0], "r");
        int fd = fileno(fp);
        translate(site[0]);
        dup2(cp, 0);
        close(cp);
        return 0;
    }
    char* tail = head;
    while (*tail != ' ' && *tail != '\0')
        tail++;
    char tmp = *tail;
    *tail = '\0';

    if (!strcmp(head, CMD[1])) {
        *tail = tmp;
        echo(head + 4);
        putchar(10);
        return 0;
    }

    if (!strcmp(head, CMD[3])) {
        *tail = tmp;
        head += 2;
        while (*head == ' ')
            head++;
        cd(head);
        return 0;
    }

    if (!strcmp(head, CMD[2])) {
        *tail = tmp;
        pwd();
        return 0;
    }

    if (!strcmp(head, CMD[0])) {
        *tail = tmp;
        return 1;
    }

    *tail = tmp;

    // std::cout << num << "\n";
    // char* argv[20];
    // for (int i = 0; i <= num; i++) {
    //     // argv[i] = tmpcmd[i];
    //     printf("[%s]\n", site[i]);
    // }
   // xargs cat > file3 这
    char* argv[20];
    argv[divide(head, " ", argv) + 1] = NULL;
    pid_t child_pid;
    int* status;
    std::string realcmd = argv[0];
    realcmd = "/home/kai/shell/build/" + realcmd;

    if ((child_pid = fork()) == 0) {
        if (execv(realcmd.c_str(), argv) == -1)
            exit(0);
    } else {
        while (!waitpid(child_pid, status, WNOHANG)) {
            if (stopped) {
                stopped = 0;
                kill(child_pid, SIGKILL);
                return 0;
            }
        }
    }
}

void loop() {
    char cmd[1000] = "", *tmp = nullptr;
    while (1) {
        tmp = readline((FONT_COLOR_KAI + username + "@" + hostname + END_COLOR +
                        ":" + FONT_COLOR_BLUE + path + END_COLOR + "$ ")
                           .c_str());
        if (tmp == nullptr)  //检测到EOF
            break;
        strcpy(cmd, tmp);
        free(tmp);
        if (translate(cmd) == 1)
            break;
    }
}
