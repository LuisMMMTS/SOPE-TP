#include <unistd.h>
#include <sys/types.h>
#include <stdlib.h>
#include <limits.h>

int main(int argc, char argv[]){

int pipe_descriptors[2];
pipe (pipe_descriptors);
pid_t pid =fork();
if (pid==0){
    int received[2];
    for(int i=0;i<2;i++){
        read(pipe_descriptors[1],received[i],4096); //arbitrary size to read, could not find buffer max const
    }
    printf("The sum of the values is: %i\n", received[0]+received[1]);
    printf("The difference between the values is: %i\n", abs(received[0]-received[1]));
    printf("The product of the values is: %li\n", received[0]*received[1]);
    if (received[1]!=0){
    printf("The sum of the values is: %f\n", received[0]/received[1]);
    }else{
        printf("Cannot divide such values!\n");
    }
    exit(0);
}
for(int i=0;i<2;i++){
        write(pipe_descriptors[0],atoi(getchar()),4096); //arbitrary size to read, could not find buffer max const
    }

}