#include <stdio.h> 
//#include <sys/types.h> 
#include <unistd.h> 
int main(void){
    //pid_t pid;
    int pid=fork();
    if (pid==0){
        write(STDOUT_FILENO,"Hello",5); //para escrever mais depressa do que o buffer do printf. Alternativamente poderia ter metido um sleep antes do printf do pai para ele ser mais lento
    }else{
        printf(" World!\n");
    }
    return 0;
}