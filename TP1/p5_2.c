#include <stdio.h>
#include <string.h>
int main(int argc, char* argv[], char* envp[])
{
    for (int i=0;i>=0;i++){
        if (envp[i]==NULL){
            break;
        }
        if (!strncmp("USER=", envp[i], 5)){ //se strncmp der 0 é a situação de sucesso
            char* new_string=&envp[i][5];
            printf("Hello %s!\n", new_string);
            printf("%s",envp[i]);
        }
    }
      

 return 0;
}
