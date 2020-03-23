// PROGRAMA p8.c
#include <stdio.h>
#include <sys/types.h>
#include <unistd.h>
#include <stdlib.h>
#include <fcntl.h>
int main(int argc, char *argv[], char *envp[])
{
 pid_t pid;
 char command[]='a';
 while (command!='quit'){
    printf("minish >");
 
    pid=fork();
 
    if (pid == 0){
        if (command[-2]=="-o"){
            int file=open(argv[-1],O_WRONLY|O_CREAT|O_TRUNC, 0777);
            dup2(file, STDOUT_FILENO);
        }
        execlp(argv[0], argv[]);
        printf("Command not executed !\n");
        exit(1);
    }else{
        wait();
    }
 }
 exit(0);
} 
