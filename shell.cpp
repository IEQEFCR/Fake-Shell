#include "shell.h"

std::string username = "Kai", hostname = "Magicbook", path = "~";
const char CMD[20][100]={"exit","echo","pwd","cd"};
char tmpcmd[20][100];
bool stopped=0;

void signal_handler(int sig)
{
	if (sig == SIGINT) {
		std::cout << "\nctrl+c pressed!\n";
		stopped = true;
	}
		// app_
}

void init()
{
	signal(SIGINT, signal_handler);
	char tp[100];
	getcwd(tp, 100);
	path = tp;
}

void exit()
{
	warn("\nExited! :-)\n");
}

void cd(char *path_name)
{
	int res;
	res = chdir(path_name);
	if (res == -1)
	{
		warn(path_name);
		warn(": No such file or directory ! :-(\n");
		return;
	}
	char tp[100];
	getcwd(tp, 100);
	path = tp;
	return;
}

void echo(char *msg){
	char *head=msg;
	if(*head=='\0'||*head=='\n') return ;
	while(*head==' ') head++;
	if(*head=='\"'){
		while(1) { //*head!='\"'
			head++;
			if(*head=='\\'){
				putchar(*(head+1));
				head+=2;
			}
			if(*head=='\"') {
				if(*(head+1)==' ') putchar(' ');
				echo(head+1);
				break;
			}
			putchar(*head);
		}
	}else{
		while(1) { //*head!='\"'
			if(*head=='\\'){
				putchar(*(head+1));
				head+=2;
			}
			if(*head==' '){
				putchar(' ');
				echo(head+1);
				break;
			}else if(*head=='\0')
				break;
			else if(*head=='\"'){
				echo(head);
				break;
			}
			putchar(*head);
			head++;
		}
	}
	return ;
}

void pwd(){
	char tp[100];
	getcwd(tp, 100);
	printf("%s\n",tp);
	return ;
}

int divide(char *cmd){
	char *head = cmd;
	int num=0;
	while(1){
		int len=0;
		while (*head !=' '&&*head!='\0'){
			tmpcmd[num][len++]=*head;
			head++;
		}
		tmpcmd[num][len]='\0';
		if(*head==' ') 
			while(*head==' ') head++;
		if(*head=='\0') {
			++num;
			for(int i=0;i<path.length();i++)
				tmpcmd[num][i]=path[i];
			tmpcmd[num][path.length()]='\0';
			return num;
		}
		num++;
	}

}

int translate(char *cmd)  //可用trie树查找命令
{
	char *head = cmd;
	while(*head==' ') head++;

	if(strncmp(head,CMD[1],4)==0 ){
		bool flag=1;
		for(int i=1;i<=3;i++) if(*(head+i)!=CMD[1][i]) flag=0;
		if(flag) {
			echo(head+4);
			putchar(10);
			return 0;
		}
		flag=1;
		for(int i=1;i<=3;i++) if(*(head+i)!=CMD[0][i]) flag=0;
		if(flag) return 1;
	}

	if(strncmp(head,CMD[3],2)==0)
	{
		head += 2;
		while (*head == ' ')
			head++;
		cd(head);
		return 0;
	}

	if(strncmp(head,CMD[2],3)==0){
		pwd();
		return 0;
	}
	
	if(strncmp(head,CMD[0],4)==0) return 1;
	int num=divide(head);
	char *argv[20];
	for(int i=0;i<=num;i++)
		argv[i]=tmpcmd[i];
	argv[num+1]=NULL;
	pid_t child_pid;
	int *status;
	std::string realcmd=argv[0];
	realcmd="/home/kai/shell/"+realcmd;
	// std::cout<<"<<"<<realcmd<<">>\n";
	if((child_pid=fork())==0){
		execv(realcmd.c_str(),argv);
	}else {
		while(!waitpid(child_pid,status,WNOHANG)){
			if(stopped){
				stopped=0;
				kill(child_pid,SIGKILL);
				return 0;
			}
		}
	}

}

void loop()
{
	char cmd[1000] = "", *tmp = nullptr;
	while (1)
	{
		tmp = readline((FONT_COLOR_KAI + username + "@" + hostname + END_COLOR + ":" +
						FONT_COLOR_BLUE + path + END_COLOR + "$ ")
						   .c_str());
		if (tmp == nullptr)
			break;
		strcpy(cmd, tmp);
		free(tmp);
		if(translate(cmd)==1) break;
	}
}
