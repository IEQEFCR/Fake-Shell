#include <unistd.h>
#include <sys/types.h>
#include <dirent.h>
#include "tools.h"

int main (int argc, char **argv){
    char *path_name;
    path_name=*(argv+1);
    // printf("<%s  %d>\n",*argv,argc);
    // char *path=*(argv+1);
	struct dirent *filename;
	DIR *dir;
	// if (path_name == nullptr)
	// 	dir = opendir(path);//.c_str()
	// else
	dir = opendir(path_name);
	if (dir == nullptr)
	{
		warn("No such dir\n");
		return 1;
	}
	bool flag=0;
	while ((filename = readdir(dir)) != NULL)
	{
		//排除当前目录和上一级目录
		if (!strcmp(filename->d_name, ".") || !strcmp(filename->d_name, ".."))
		{
			continue;
		}
		printf("%-27s",  filename->d_name);
		if(flag) putchar(10);
		flag=!flag;
	}
	if(flag) putchar(10);
	closedir(dir);
}