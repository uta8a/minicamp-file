#include <stdio.h>

void fn1(){
    int var1 = 10;
    printf("fn1: %d\n", var1);
    return;
}

void fn2(){
    int var2 = 20;
    fn1();
    printf("fn2: %d\n", var2);
    return;
}

void fn3(){
    int var3 = 30;
    fn2();
    printf("fn3: %d\n", var3);
    return;
}

int main(void){
    int var0 = 0;
    fn3();
    printf("main: %d\n", var0);
    return 0;
}
// gcc -g stack.c -o stack