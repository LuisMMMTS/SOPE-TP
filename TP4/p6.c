// PROGRAMA p04a.c
#include <unistd.h>
#include <signal.h>
#include <stdio.h>
#include <stdlib.h>
#include <wait.h>

void sigint_handler(int signo)
{
    printf("process exited correctly\n");
    exit(0);
}

int main(int argc, char *argv[])
{
    
    struct sigaction action;

    action.sa_handler = sigint_handler;
    sigemptyset(&action.sa_mask);
    action.sa_flags = 0;
    if (sigaction(SIGCHLD, &action, NULL) < 0)
    {
        fprintf(stderr, "Unable to install SIGINT handler\n");
        exit(1);
    }

    int t=(atoi)*argv[1];
    pid_t pid=fork();

    if (pid==0){
        execl(argv[2],argv[2],argv[3],argv[4]);
        exit(1);
    }
    sleep(t);
    printf("Timeout\n");
    exit(1);
}