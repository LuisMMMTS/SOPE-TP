#include <stdio.h> 
//#include <sys/types.h> 
#include <unistd.h> 
int main(void){
    //pid_t pid;
    int pid=fork();
    if (pid==0){
        printf(" World!\n");
    }else{
        printf("Hello");
    }
    return 0;
}

//resultado->de quando em vez o processo filho coloca o World mais rápido no buffer do que o pai