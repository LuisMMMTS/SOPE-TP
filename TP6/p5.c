// PROGRAMA p03.c
#include <pthread.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

typedef struct{
    int number1;
    int number2;
}numbers;


void* soma(void *threadnum)
{
    printf("Hello from thread soma\n");
    int * ptr=(int*)threadnum;
    printf("recebi os números %d e %d, cuja soma é %d \n", ptr[0], ptr[1], ptr[0]+ptr[1]);
    //return (void *)(threadnum[0]+threadnum[1]);
    return NULL;
}

// void subtracao(void *threadnum)
// {
//     printf("Hello from thread subtração\n");
//     printf("recebi os números %d e %d, cuja divisão é %d\n",&threadnum[0],&threadnum[1],&threadnum[0]-&threadnum[1];
//     //return (threadnum[0]-threadnum[1]);
// }

void* produto(void *threadnum)
{
    printf("Hello from thread produto\n");
    numbers *ptr=(numbers *)threadnum;
    //numbers copia=*(numbers *)threadnum;
    printf("recebi os números %d e %d, cuja produto é %d\n",ptr->number1, ptr->number2,ptr->number1*(*ptr).number2);
    return NULL;
}

// void divisao(void *threadnum)
// {
//     printf("Hello from thread divisao inteira\n");
//     printf("recebi os números %d e %d, cuja divisão é %d\n",&threadnum.number1,&threadnum.number2,&threadnum.number1/&threadnum.number2);
//     //return (void *)(threadnum.number1/threadnum.number2);
// }


int main()
{
    int user_numbers[2];
    numbers user_numbers_struct;
    pthread_t threads[4];

    for (int i=0;i<2;i++){
        scanf("%d",&user_numbers[i]);
    }
    user_numbers_struct.number1=user_numbers[0];
    user_numbers_struct.number2=user_numbers[1];

    pthread_create(&threads[0], NULL, soma, (void *)user_numbers); //é assim, ou passo só o apontador. se passar só o apontador se esta thread fizer exit a memoria associada a este array não vai ser reescrita mesmo que as threads precisem de lhe aceder, ou seja perder os valores que queremos utilizar?
    //pthread_create(&threads[1], NULL, subtracao, (void *)&user_numbers);
    pthread_create(&threads[2], NULL, produto, (void *)&user_numbers_struct);
    //pthread_create(&threads[3], NULL, divisao, (void *)&user_numbers_struct);
    
    pthread_exit(0);
    //return 0;//n imprime nada provavelmente porque afunc n dá flush antes de eliminar o processo, já que não está ativado o join para esperar que as threads acabem
    //exit(0);//n imprime nada provavelmente porque afunc n dá flush antes de eliminar o processo, já que não está ativado o join para esperar que as threads acabem
}