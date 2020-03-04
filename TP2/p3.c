//FOLHA 2 - p2b.c
//FILE COPY
//USAGE: copy source destination

#include <stdio.h>
#include <unistd.h>
#include <fcntl.h>
#include <errno.h>

#define BUFFER_SIZE 512

int main(int argc, char *argv[])
{
 int fd1, fd2, nr;
 unsigned char buffer[BUFFER_SIZE];

 if (argc==3){
   //printf("%d",argc);
   fd2 = open(argv[2], O_WRONLY | O_CREAT , 0644);
    dup2(fd2,STDOUT_FILENO);
 }

 fd1 = open(argv[1], O_RDONLY);
 if (fd1 == -1) {
  perror(argv[1]);
  return 2;
 }
 
  while ((nr = read(fd1, buffer, BUFFER_SIZE)) > 0){
    printf("%s",buffer);
    
    }

  close(fd1);
  close(fd2);
return 0;
}