#include <unistd.h>
#include <sys/types.h>
#include <dirent.h>
#include "tools.h"

int main (int argc, char **argv)
{
    char *path_name=*(argv+2);
    char *path=*(argv+1);
	struct dirent *filename;
	DIR *dir;
	if (path_name == nullptr)
		dir = opendir(path);//.c_str()
	else
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
		// //获取文件属性
		// struct stat s;
		// if (lstat(path, &s) < 0)
		// {
		// 	printf("get status is fail.\n");
		// 	printf(path);
		// }

		// //判断是否为目录，如果是目录递归调用
		// if (S_ISDIR(s.st_mode))
		// {
		// 	printf("find dir : %s\n", path);
		// 	printDir(path);
		// }
		// else
		// {
		// 	printf("file: %s/%s\n", dirname, filename->d_name);
		// }
	}
	if(flag) putchar(10);
	closedir(dir);
}