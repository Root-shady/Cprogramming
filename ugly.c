#include<stdio.h>
#include<stdlib.h>
#include<stdbool.h>
typedef struct{
    int num;
}ElemType;
typedef struct{
    ElemType *array;
    int length; // The array length, the elements in heap
}UlgyArray;
int userInput(){
        int n;
        while(true){
            printf("Which ugly number do you want?(bigger than 0)");
            scanf("%d",&n);
            if(n>0){
                    break;
                }
        }
        return n;
    }
UlgyArray *initialUglyArray(int n){
        UlgyArray *ugly = (UlgyArray*)malloc(sizeof(UlgyArray));
        if(ugly == NULL){
                printf("Error Memory Allocation");
                exit(-1);
            }
        ugly->length = 4;
        ugly->array = (ElemType*)malloc(n * sizeof(ElemType));
        if(ugly->array == NULL){
                printf("Error Memory Allocation");
                exit(-1);
            }
        return ugly;
    }
void main(int argc, char* argv[]){
    // Get the requirements from the user. The Nth element
    int n = userInput();
    // Initial the heap
    UlgyArray *ugly = initialUglyArray(n);
    printf("%d    ",ugly->length);
    free(ugly->array);
    free(ugly); 
    // Start to buid the heap, and maintain it

    // print out the result to notify the user
}

