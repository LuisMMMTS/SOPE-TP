// PROGRAMA p7.c
#include <stdio.h>
#include <sys/types.h>
#include <unistd.h>
#include <stdlib.h>
int main(int argc, char *argv[])
{
 char prog[20];
 sprintf(prog,"%s.c",argv[1]);
 execlp("gcc","gcc",prog,"-Wall","-o",argv[1],NULL);
 //printf("im here");  does not print?? because the execution code was changed in previous command
 printf("successfully compiled %s. New file is %s",argv[1],prog);
 //exit(...);
} 