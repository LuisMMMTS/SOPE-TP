#include <unistd.h>
#include <sys/types.h>
#include <stdlib.h>
#include <limits.h>
#include <stdio.h>

#define READ 0
#define WRITE 1
#define MAX_LINE 1024

int main(){

int pipe_descriptors[2];
pipe (pipe_descriptors);
pid_t pid =fork();
if (pid==0){
    close(pipe_descriptors[WRITE]);
    int received[2];
    for(int i=0;i<2;i++){
        printf("i'm reading\n");
        read(pipe_descriptors[READ],&received[i],MAX_LINE); //arbitrary size to read, could not find buffer max const
        printf("y=%ls\n",&received[i]);
        printf("done reading\n");
    }
    printf("The sum of the values is: %i\n", received[0]+received[1]);
    printf("The difference between the values is: %i\n", abs(received[0]-received[1]));
    printf("The product of the values is: %d\n", received[0]*received[1]);
    if (received[1]!=0){
    printf("The sum of the values is: %d\n", received[0]/received[1]);
    }else{
        printf("Cannot divide such values!\n");
    }
    exit(0);
}
close(pipe_descriptors[READ]);
for(int i=0;i<2;i++){
        fflush(stdin);
        printf("insert a number:\n");
        //fflush(stdout);
        int c=getchar();
        write(pipe_descriptors[WRITE],&c,sizeof c); //arbitrary size to read, could not find buffer max const
        printf("x=%ls\n",&c);
    }

}