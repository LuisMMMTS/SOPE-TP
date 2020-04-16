// PROGRAMA p03.c
#include <pthread.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#define NUM_THREADS 10
void *PrintHello(void *threadnum)
{
 sleep(1);
 printf("Hello from thread no. %ld!\n", pthread_self());
 return(threadnum);
}
int main()
{
 pthread_t threads[NUM_THREADS];
 int thread_number[NUM_THREADS];
 //int* j;
 int t;
 for(t=0; t< NUM_THREADS; t++){
 printf("Creating thread %d\n", t);
 //j=t;não funciona porquê??
 thread_number[t]=t;
 pthread_create(&threads[t], NULL, PrintHello, (void *)&thread_number[t]);
 }
 pthread_exit(0);
 //exit(0);n imprime nada provavelmente porque afunc n dá flush antes de eliminar o processo, já que não está ativado o join para esperar que as threads acabem
}