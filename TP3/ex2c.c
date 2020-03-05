#include <sys/types.h>
#include <unistd.h>
#include <stdio.h>

int main(void) {
 printf("1");
 if(fork() > 0) {
 printf("2");
 printf("3");
 } else {
 printf("4");
 printf("5");
 }
 printf("\n");
 return 0;
} 

/**
 * com o printf tmb o buffer do printf é copiado no fork. utilizando \n a seguuir ao 1
 * estamos a dizer ao buffer para descarregar e portanto já não é duplicado.
 * outra forma é utilizar o flush
 */
