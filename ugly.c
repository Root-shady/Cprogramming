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

// Get the user input 
int userInput(){
    int n;
    while(true){
        printf("Which ugly number do you want?(bigger than 0)");
        scanf("%d",&n);
        if(n>0)
            break;
    }
    return n;
}
// Initial the heap
UglyArray *initialUglyArray(int n){
    UglyArray *ugly = (UglyArray*)malloc(sizeof(UglyArray));
    if(ugly == NULL){
            printf("Error Memory Allocation");
            exit(-1);
        }
    // Roughly calculating the length of the array
    ugly->array = (ElemType*)malloc((4*n+1) * sizeof(ElemType));
    if(ugly->array == NULL){
            printf("Error Memory Allocation");
            exit(-1);
        }
    // Adding the first element
    ugly->array[0].num = 1;
    ugly->length = 1;
    ugly->capacity = 3*n+1;
    return ugly;
}
// Return the min(root) of the heap
int getRoot(UglyArray *ugly){
    if(ugly->length == 0){
            printf("Empty Heap, Error Operation");
            exit(-1);
        }
    return ugly->array[0].num;
}

// Adjust the last element to the right place
void upAdjust(UglyArray *ugly){
    // The index of the last element is ugly->length - 1
    int track = ugly->length-1;
    while(track > 0){
        if(ugly->array[track].num < ugly->array[(track-1)/2].num){
            // Swap the child and parent node
            int temp = ugly->array[track].num;
            ugly->array[track].num = ugly->array[(track-1)/2].num;
            ugly->array[(track-1)/2].num = temp;
            track = (track-1)/2 ;
        }
        else{
                break;
            }
    }
}

//Detemrine a node had child or not
bool hasChildren(UglyArray *ugly, int track){
    return track*2 + 1 < ugly->length;     
}

// Return the smallest child of the node
int minChildren(UglyArray *ugly, int track){
    // precondition --> hasChildren is true
    //Determine if the node have right child
    if(track*2+2 < ugly->length){
        return ugly->array[track*2+1].num <ugly->array[track*2+2].num ?ugly->array[track*2+1].num:ugly->array[track*2+2].num;
    }   
    else{
            return ugly->array[track*2+1].num;
        } 
}

// Return the index of the smallest child node
int minChildIndex(UglyArray *ugly, int track){
    if(ugly->array[track*2+1].num == minChildren(ugly, track)){
        return track*2+1;
    } 
    return track*2+2;
}

// Djust the root node to the proper plcae
void downAdjust(UglyArray *ugly){
    int track = 0;
    while(track < ugly->length){
        if(hasChildren(ugly, track)){
            if(ugly->array[track].num > minChildren(ugly, track)){
                // Swap it with the smallest children
                int index = minChildIndex(ugly, track);
                int temp = ugly->array[track].num;
                ugly->array[track].num = ugly->array[index].num;
                ugly->array[index].num = temp;
                track = index;        
            }
            else
                break;
        }
        // has no children
        else
            break;    
    } // End of the while
}

void addNode(UglyArray *ugly, int n){
//Value assignment, Not a good practice
    ugly->array[ugly->length].num = n;
    ugly->length ++;
    upAdjust(ugly);
}

int removeRoot(UglyArray *ugly){
    int result = getRoot(ugly);
    ugly->array[0].num = ugly->array[ugly->length-1].num;
    ugly->length --;
    downAdjust(ugly);
    return result;
}

int uglyNumber(UglyArray *ugly, int n){
    printf("The n is %d\n", n);
    int count = 0, result = 0; 
    while(count <= n){
            if(result != getRoot(ugly)){
                result = removeRoot(ugly);
                // Debugging
                printf("%d:  %d\n", count, result);
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

    // print out the result to notify the user
    int result = uglyNumber(ugly, n);
    printf("The result: %d\n", result);
    free(ugly->array);
    free(ugly); 
}
