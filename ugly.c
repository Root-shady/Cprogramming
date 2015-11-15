#include<stdio.h>
#include<stdlib.h>
#include<stdbool.h>
typedef struct{
    int num;
}ElemType;
typedef struct{
    ElemType *array;
    int length; // The array length, the elements in heap
    int capacity;
}UglyArray;
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
UglyArray *initialUglyArray(int n){
    UglyArray *ugly = (UglyArray*)malloc(sizeof(UglyArray));
    if(ugly == NULL){
            printf("Error Memory Allocation");
            exit(-1);
        }
    ugly->length = 0;
    // Roughly calculating the length of the array
    ugly->array = (ElemType*)malloc((3n+1) * sizeof(ElemType));
    if(ugly->array == NULL){
            printf("Error Memory Allocation");
            exit(-1);
        }
    // Adding the first element
    ugly->array[0] = 1;
    ugly->capacity = 3*n+1;
    return ugly;
}
int getRoot(UglyArray *ugly){
    if(ugly->length == 0){
            printf("Empty Heap, Error Operation");
            exit(-1);
        }
    return ugly->array[0];
}
void addNode(UglyArray *ugly, int n){
//Value assignment, Not a good practice
    ugly->array[ugly->length].num = n;
    ugly->length ++;
    upAdjust(UglyArray *ugly);
}
int removeRoot(UglyArray *ugly){
    int result = getRoot(ugly);
    ugly->array[0] = ugly->array[length-1];
    ugly->length --;
    downAdjust(ugly);
}
void upAdjust(UglyArray *ugly){
    // The index of the last element is ugly->length - 1
    int track = ugly->length-1;
    while(track > 0){
        if(ugly->array[track].num < ugly->array[(track-1)/2].num){
            // Swap the child and parent node
            ElemType temp = ugly->array[track];
            ugly->array[track] = ugly->array[(track-1)/2];
            ugly->array[(track-1)/2] = temp;
            track = (track-1)/2 ;
        }
        else{
                break;
            }
    }

}
bool hasChildren(UglyArray ugly, int track){
         
}
int minChildIndex(UglyArray ugly, int track)
int minChildren(UglyArray *ugly, int track){
        
    }
void downAdjust(UglyArray *ugly){
    int track = 0;
    while(track < ugly->length){
        if(hasChildren(ugly, track)){
            if(ugly->array[track].num > minChildren(ugly, track)){
                // Swap it with the smallest children
                int index = minChildIndex(ugly, track);
                ElemType temp = ugly->array[track];
                ugly->array[track] = ugly->array[index];
                ugly->array[index] = temp;
                track = index;        
            } 
        else{
                break;
            }
        }            
    }
}

int uglyNumber(UglyArray *ugly, int n){
    int count = 0, result = 0; while(count < n){
            if(result != getRoot(ugly)){
                result = removeRoot(ugly);
                addNode(ugly, result*2);
                addNode(ugly, result*3);
                addNode(ugly, result*5);
                addNode(ugly, result*7);
                count ++;
            }
            else{
                result = removeRoot(ugly);
            }
        }
        return result;
}
void main(int argc, char* argv[]){
    // Get the requirements from the user. The Nth element
    int n = userInput();
    // Initial the heap
    UglyArray *ugly = initialUglyArray(n);
    // Start to buid the heap, and maintain it
    int result = uglyNumber(ugly, n);
    // print out the result to notify the user
    free(ugly->array);
    free(ugly); 
}

