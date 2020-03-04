#include <stdlib.h>
#include <stdio.h>

int main (int argc, char* argv[]){
    char *j;
    FILE* file=fopen(argv[1],"r");
    FILE* final=fopen(argv[2],"w");
    printf("%d",argc);
    int i=0;
    while (i==0){
    i=fread(j, 1,1,file);
    fwrite(j, 1, 1, final);
    }

}