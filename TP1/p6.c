// PROGRAMA p6a.c
#include <stdio.h>
#include <stdlib.h>
#include <errno.h>
#include <string.h>
#define BUF_LENGTH 256
int main(int argc, char* argv[], char* envp[])
{
    FILE *src, *dst;
    char buf[BUF_LENGTH];
    if (argv[1]==NULL || argv[2]==NULL){
        printf("usage: nome_do_executavel file1 file2\n");
        exit(3);
    }

    
    if ( ( src = fopen( "argv[1]", "r" ) ) == NULL )
    {
    printf("an error: %s\n", strerror(errno));
    printf("errno %i\n",errno);
    perror("infile error");
    exit(1);
    }
    if ( ( dst = fopen( "argv[2]", "w" ) ) == NULL )
    {
    perror("outfile error");
    exit(2);
    }
    while( ( fgets( buf, BUF_LENGTH, src ) ) != NULL )
    {
    fputs( buf, dst );
    printf("an error: %s\n", strerror(errno));
    //perror("fputs error");
    }
    fclose( src );
    fclose( dst );
    exit(0); // zero é geralmente indicativo de "sucesso"
} 