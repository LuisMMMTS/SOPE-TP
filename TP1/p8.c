#include <stdio.h>
#include <stdlib.h>
#include<time.h>

int main(int argc, char* argv[]){
    clock_t start, end;
    double cpu_time_used;
    start = clock();
    srand(time(0));
    int i;
    int iteration_counter=0;
    do{
        i=rand()%atoi(argv[1]);
        printf("Número: %d\t",i);
        printf("Iteração: %d\n",iteration_counter);
        iteration_counter++;
    }while (i!=atoi(argv[2]));
    end = clock();
    cpu_time_used = ((double) (end - start)) / CLOCKS_PER_SEC;
    printf("cpu time: %f\n",cpu_time_used);
    //printf("real time: %fms\n",(double) (end - start));


}

