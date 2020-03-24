#include <unistd.h>
#include <signal.h>
#include <stdio.h>
#include <stdlib.h>


void signal_handler(int signal){
    extern int v;
    if (signal==SIGUSR1){
        v+=1;
    }
    if (signal==SIGUSR2){
        v-=1;
    }
}

int v=0;

int main(){
    extern int v;
    struct sigaction sa1;
    sa1.sa_handler=signal_handler;
    if (sigaction(SIGUSR1, &sa1, NULL)){
        printf("Failed to subscribe SIGUSR1\n");
        exit(1);
    }
    if (sigaction(SIGUSR2, &sa1, NULL)){
        printf("Failed to subscribe SIGUSR2\n");
        exit(1);
    }
    while (1){
        printf("%d",v);
        sleep(1);
    }
    return 0;
}