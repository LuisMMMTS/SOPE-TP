// PROGRAMA p8.c
#include <stdio.h>
#include <sys/types.h>
#include <unistd.h>
#include <stdlib.h>
#include <fcntl.h>
#include <dirent.h>

int main(int argc, char *argv[], char *envp[])
{
    pid_t pid;
    DIR *dirp;
    struct dirent *direntp;
    struct stat stat_buf;


    if ((dirp = opendir(argv[1])) == NULL)
    {
        perror(argv[1]);
        exit(2);
    }
    while ((direntp = readdir(dirp)) != NULL)
    {
        lstat(direntp->d_name, &stat_buf);

        if (S_ISREG(stat_buf.st_mode)){
            fork();
            if (pid==0){
                execlp("cp","cp",argv[1]+"/"+direntp->d_name,argv[2]+"/"+direntp->d_name,NULL);
            }
            

        }else if (S_ISDIR){
            fork();
            if (pid==0){
                execlp("mkdir","mkdir",argv[1]+"/"+direntp->d_name,argv[2]+"/"+direntp->d_name,NULL);
            }
        }
    }
}