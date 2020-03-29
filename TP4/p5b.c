// PROGRAMA p04a.c
#include <unistd.h>
#include <signal.h>
#include <stdio.h>
#include <stdlib.h>
#include <wait.h>

void sigint_handler(int signo)
{
    printf("Entering SIGCHLD handler ...\n");
    sleep(10);
    printf("Exiting SIGCHLD handler ...\n");
}

int main(void)
{
    pid_t pid = -1;
    struct sigaction action;

    action.sa_handler = sigint_handler;
    sigemptyset(&action.sa_mask);
    action.sa_flags = 0;
    if (sigaction(SIGCHLD, &action, NULL) < 0)
    {
        fprintf(stderr, "Unable to install SIGINT handler\n");
        exit(1);
    }

    for (int i = 0; i < 10; i++)
    {
        if (pid == 0)
        {
            printf("process %d going to sleep", i);
            sleep(15);
            printf("process %d exiting", i);
            exit(0);
        }
        fork();
    }
}