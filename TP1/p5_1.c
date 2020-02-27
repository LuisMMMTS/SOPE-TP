#include <stdio.h>
int main(int argc, char* argv[], char* envp[])
{
 printf("Hello !\n");
 for (int i=0;i>=0;i++){
     if (envp[i]==NULL){
         break;
     }
     printf("%s\n",envp[i]);
     
 }
 return 0;
}  
