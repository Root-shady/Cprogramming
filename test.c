#include<stdlib.h>
#include<stdio.h>
#define MAX 100
int lowbit(int x){
    return x & -x ;        
}
void main(int argc, char*argv[]){
    int i;
    printf("Hello, world");
    for(i=1; i<=16; i++){
        printf("%d :  %d\n", i, lowbit(i));    
    }
    printf("The max is %d\n", MAX);
}
