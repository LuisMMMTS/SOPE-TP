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
    /*if (argc<2){
        printf("Usage: limit t prog prog_arg1 prog_arg2...\n");
    }


    struct sigaction action;

    action.sa_handler = sigint_handler;
    sigemptyset(&action.sa_mask);
    action.sa_flags = 0;
    if (sigaction(SIGCHLD, &action, NULL) < 0)
    {
        fprintf(stderr, "Unable to install SIGINT handler\n");
        exit(1);
    }*/

    pid_t pids[argc];
    for (int i=1;i<argc;i++){
        pids[i]=fork()
    }

    if (pid==0){
        execvp(argv[2], &argv[2]);
        printf("Error in running %s\n", argv[2]);
        exit(1);
    }
    sleep(t);
    kill(pid,SIGKILL);
    printf("Timeout\n");
    exit(1);
}