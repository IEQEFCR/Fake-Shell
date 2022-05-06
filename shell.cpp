#include "shell.h"

std::string username = "Kai", hostname = "Magicbook", path = "~";
// char tpath[100]=" ";
const char CMD[20][100] = {"exit", "echo", "pwd", "cd"};
char tmpcmd[20][100];
int child = 0;

void signal_handler(int sig) {
    if (sig == SIGINT) {
        int* status;
        if (!waitpid(child, status, WNOHANG))
            kill(child, SIGINT);
        std::cout << "\nCtrl+C Pressed!\n";
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

void echo(
    char* msg) {  //写复杂了，可以直接遇到"和'跳过，然后用栈记录引号匹配情况
    char* head = msg;  //下面粗略处理了转义符号，不过好像真正的echo也不转义？
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

bool meet(char* single, char* div) { //判断single是否与div中字符有一样的
    char* head = div;
    while (*head != '\0') {
        if (*head == *single)
            return 1;
        head++;
    }
    return 0;
}

int divide(char* cmd, char* div, char** site) { //切分函数
    char* head = cmd;
    while (meet(head, div) && *head != '\0')
        head++;
    int num = 0;
    while (1) {
        int len = 0;
        *(site + num) = head;
        while (!meet(head, div) && *head != '\0') head++;
        while (meet(head, div) && *head != '\0') {
            *head = '\0';
            head++;
        }
        if (*head == '\0') return num;
        num++;
    }
}

int translate(char* cmd) {
    char* head = cmd;
    while (*head == ' ')
        head++;
    char* tail = head;
    while (*tail != '\0') {  //处理管道
        if (*tail == '|') {
            *tail = '\0';
            int fd[2];
            pipe(fd);
            pid_t child_pid;
            int* status;
            if ((child_pid = fork()) == 0) {
                int cp = dup(0);
                close(fd[1]);
                dup2(fd[0], 0);
                translate(tail + 1);
                close(fd[0]);
                dup2(cp, 0);
                close(cp);
                exit(0);
            } else {
                int cp = dup(1);
                close(fd[0]);
                dup2(fd[1], 1);
                translate(head);
                close(fd[1]);
                dup2(cp, 1);
                close(cp);
                while (!waitpid(child_pid, status, WNOHANG))
                    ;  //阻塞
            }
            return 0;
        }
        tail++;
    }
    char* site[20];
    int num = divide(head, ">", site);
    if (num >= 1) {  //处理输出重定向 ，优先级低于输入重定向
        char* tp[10];
        divide(site[1], " ", tp);
        int cp = dup(1);
        close(1);
        FILE* fp = fopen(tp[0], "w");
        int fd = fileno(fp);
        translate(site[0]);
        dup2(cp, 1);
        close(cp);
        return 0;
    }
    num = divide(head, "<", site);
    if (num >= 1) {  //处理输入重定向
        char* tp[10];
        divide(site[1], " ", tp);
        int cp = dup(0);
        close(0);
        FILE* fp = fopen(tp[0], "r");
        int fd = fileno(fp);
        translate(site[0]);
        dup2(cp, 0);
        close(cp);
        return 0;
    }

    char* argv[20];
    bool isbackstage = 0;  //是否后台运行
    int arg_num = divide(head, " ", argv);
    if (*argv[arg_num] == '&')
        isbackstage = 1, argv[arg_num--] = NULL;
    else
        argv[arg_num + 1] = NULL;
    pid_t child_pid;
    int* status;
    std::string realcmd = argv[0];
    if (!strcmp(argv[0], CMD[0]))
        return 1;
    if (!strcmp(argv[0], CMD[3])) {
        cd(argv[1]);
        return 0;
    }
    if ((child_pid = fork()) == 0) {
        if (!strcmp(argv[0], CMD[1])) {
            for (int i = 1; i <= arg_num; i++) {
                echo(argv[i]);
                if (i < arg_num)
                    putchar(' ');
                else
                    putchar(10);
            }
        } else if (!strcmp(argv[0], CMD[2]))
            pwd();
        else {
            char buffer[256];
            FILE* fp = fopen("/home/kai/shell/build/.my_env", "r");
            while (fgets(buffer, 256, fp) != nullptr) {
                char* find = strchr(buffer, '\n');
                if (find)
                    *find = '\0';
                // printf("<%s>\n", buffer); 输出当前命令路径
                strcat(buffer, argv[0]);
                if (execv(buffer, argv) != -1)
                    break;
            }
            fclose(fp);
            exit(0);
        }
        exit(0);
    } else {
        child = child_pid;
        if (isbackstage) {
            printf("[%d] is running backstage\n", child_pid);  //如果后台，不阻塞，直接走
            return 0;
        } else {
            int* status;
            while (!waitpid(child_pid, status, WNOHANG)); //阻塞，不进行下一次命令处理
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
