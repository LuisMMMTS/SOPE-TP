// PROGRAMA p8.c
#include <stdio.h>
#include <sys/types.h>
#include <unistd.h>
#include <stdlib.h>
#include <sys/wait.h>
#include <errno.h>
int main(int argc, char *argv[], char *envp[])
{
 pid_t pid;
 if (argc != 2) {
 printf("usage: %s dirname\n",argv[0]);
 exit(1);
 }
 pid=fork();
 if (pid > 0){
 printf("My child is going to execute command \"ls -laR %s\" \n", argv[1]);
 int termination_status;
 wait(&termination_status);
 //perror(termination_status);
 printf("termination_status %d\n",termination_status);
 if (WIFEXITED(termination_status)){
     printf("%d\n",WEXITSTATUS(termination_status));
    printf("termination successful\n");
    exit(0);}
 if (WIFSIGNALED(termination_status)){
    printf("unsuccessful termination\n");
    exit(1);}
 }else if (pid == 0){
 execlp("ls", "ls", "-laR", argv[1], NULL);
 printf("Command not executed !\n");
 exit(1);
 }
 
printf("no execption catched");
} 