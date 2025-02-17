// PROGRAMA p04a.c
#include <unistd.h>
#include <signal.h>
#include <stdio.h>
#include <stdlib.h>
#include <wait.h>

int main(void)
{
    pid_t pid;
    int i, n, status;
    for (i = 1; i <= 3; i++)
    {
        pid = fork();
        if (pid == 0)
        {
            printf("CHILD no. %d (PID=%d) working ... \n", i, getpid());
            sleep(i * 7); // child working ...
            printf("CHILD no. %d (PID=%d) exiting ... \n", i, getpid());
            exit(0);
        }
    }

    for (i = 1; i <= 4; i++)
    {
        printf("PARENT: working hard (task no. %d) ...\n", i);
        n = 20;
        while ((n = sleep(n)) != 0)
            ;
        printf("PARENT: end of task no. %d\n", i);
        printf("PARENT: waiting for child no. %d ...\n", i);
        pid=1; //pid 1 is the kernel so that can never be the return of wait
        while (pid!=-1 && pid !=0){
            pid = waitpid(-1,&status,WNOHANG);
        }
        if (pid != -1)
            printf("PARENT: child with PID=%d terminated with exit code %d\n", pid, WEXITSTATUS(status));
    }
    exit(0);
}