//sleep函数
#include "kernel/types.h"
#include "user/user.h"

//int atoi(const char *s)
//将命令参数从字符串转换为数字

void main(int argc, char* argv[])
{
	if (argc == 1)
		printf("错误：未输入休眠时间参数\n");
	else if(argc == 2)
		sleep(atoi(argv[1]));
	else
		printf("错误：输入多余参数\n");

	exit(0);
}
