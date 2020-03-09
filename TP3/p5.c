#include <stdio.h> 
//#include <sys/types.h> 
#include <unistd.h> 
int main(void){
    //pid_t pid;
    int pid1=fork();
    int pid2=fork(); //o filho gera um filho e o pai gera um filho, então há 3 filhos
    if (pid1!=0 && pid2==0){//first child of main parent
        write(STDOUT_FILENO,"friends!",8);
    }else if (pid2!=0 && pid1==0){ //second child of main parent
        write(STDOUT_FILENO,"my ",3);
    }else if (pid1!=0 && pid2!=0){ //grandchild
        write(STDOUT_FILENO,"Hello ",6);
    }
    return 0;
}

//se as palavras estiverm por esta ordem escreve tudo fixe
//se estiverem na ordem inversa o hello é impresso na teoria depois de o programa acabar. porque?