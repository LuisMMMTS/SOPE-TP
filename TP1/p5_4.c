#include <stdio.h>
#include <stdlib.h>
int main(int argc, char* argv[], char* envp[])
{
    printf("Hello %s!\n", getenv("USER_NAME"));
    printf("%s",getenv("USER"));

 return 0;
}
