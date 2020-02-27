#include <stdio.h>
#include <stdlib.h>

void handler1(){
    printf("executing atexit handler 1\n");
}
void handler2(char* message){
    printf("%s",message);
}
void handler3(){
    printf("executing athandler 3\n");
    //_Exit(0);
}

int main(void){
    atexit(handler1);  //note the missing parenthesis
    //é possivel fazer algo como isto//void* a=&handler2("executing atexit handler 1");
    //atexit(a);
    printf("nos ainda estamos aqui\n");
    atexit(handler3);
    atexit(handler1);
    //exit;
    return 0;
}