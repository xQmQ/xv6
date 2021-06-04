/*
 *  Description: xv6的pingpong
 *  Author: xQmQ
 *  Date: 2020-12-01 10:12:33
 *  LastEditTime: 2020-12-01 14:24:59
 */
#include "kernel/types.h"
#include "user/user.h"

void main(int argc, char *argv[]) {
  int parent_fd[2], child_fd[2];
  char buf[5];

  if (pipe(parent_fd) == -1 || pipe(child_fd) == -1) printf("管道创建失败");
  // fd[0]用于读，fd[1]用于写

  if (fork() > 0)  //父进程
  {
    write(child_fd[1], "ping", strlen("ping"));
    read(parent_fd[0], buf, 4);
    printf("%d:received %s\n", getpid(), buf);
  } else  //子进程
  {
    read(child_fd[0], buf, 4);
    printf("%d:received %s\n", getpid(), buf);
    write(parent_fd[1], "pong", strlen("pong"));
  }

  exit(0);
}
