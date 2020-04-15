#include <unistd.h>
#include <sys/types.h>
#include <stdlib.h>
#include <limits.h>
#include <stdio.h>

#define READ 0
#define WRITE 1
#define MAX_LINE 1024

typedef struct numbers
{
    int x;
    int y;
} numbers;

int main()
{

    int pipe_descriptors[2];
    pipe(pipe_descriptors);
    pid_t pid = fork();
    if (pid == 0)
    {
        close(pipe_descriptors[WRITE]);
        numbers op1;
        read(pipe_descriptors[READ], &op1.x, MAX_LINE); //arbitrary size to read, could not find buffer max const
        read(pipe_descriptors[READ], &op1.y, MAX_LINE); //arbitrary size to read, could not find buffer max const
    }
    printf("The sum of the values is: %i\n", op1.x + op1.y);
    printf("The difference between the values is: %i\n", abs(op1.x - op1.y));
    printf("The product of the values is: %d\n", op1.x * op1.y);
    if (op.y != 0)
    {
        printf("The sum of the values is: %d\n", op1.x / op1.y);
    }
    else
    {
        printf("Cannot divide such values!\n");
    }
    exit(0);
}

numbers op1;
close(pipe_descriptors[READ]);
printf("insert a number:\n");
op1.x = getchar();
printf("insert another number:\n");
op1.y = getchar();

write(pipe_descriptors[WRITE], &numbers, sizeof numbers); //arbitrary size to read, could not find buffer max const
}