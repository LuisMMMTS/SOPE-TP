// PROGRAMA p8.c
#include <stdio.h>
#include <sys/types.h>
#include <unistd.h>
#include <stdlib.h>
#include <fcntl.h>
int main(int argc, char *argv[], char *envp[])
{
 pid_t pid;
 if (argc != 3) {
 printf("usage: %s dirname destination file\n",argv[0]);
 exit(1);
 }
 pid=fork();
 if (pid > 0)
 printf("My child is going to execute command \"ls -laR %s\" \n", argv[1]);
 else if (pid == 0){
 int file=open(argv[2],O_WRONLY|O_CREAT|O_TRUNC, 0777);
 dup2(file, STDOUT_FILENO);
 execlp("ls", "ls", "-laR", argv[1], NULL);
 printf("Command not executed !\n");
 exit(1);
 }
 exit(0);
} 
