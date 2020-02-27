#include <stdio.h>
#include <stdlib.h>
int main(int argc, char* argv[])
{
    //printf("%d %d",atoi(argv[2]), argc);
    for (int i=0;i<atoi(argv[2]);i++){
    printf("Hello %s !\n", argv[1]);
    }
    return 0;
}  

/*to print multiple names please enclose them in quotes on the terminal*/ 
