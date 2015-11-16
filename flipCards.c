#include<stdio.h>
#include<stdlib.h>
#include<stdbool.h>
#define CARD 100
int *initialCard(){
    int i;
    int *card = (int*)malloc(CARD+1 * sizeof(int));
    for(i=0; i<CARD; i++){
        *(card+i) = 0;    
    }        
    return card;
}
int lowBit(int x){
    return x & -x;    
}
int query(int *card, int i){
    int sum = 0;
    while(i>0){
        sum += card[i];
        i -= lowBit(i);    
    }    
    //return sum;
    if(sum % 2 == 0)
        return 0;
    else
        return 1;
}
void modify(int *card, int index, int d){
    while(index<=CARD){
        card[index] += d;
        index += lowBit(index);    
    }    
}
bool turn(int* card, int start, int end){
    if(start > end)
        return false;
    if(start>CARD || end > CARD || start < 0 || end < 0)
        return false;
    modify(card, start, 1);
    modify(card, end+1, -1);
    return true;
}
void makeDecision(int *card){
    int decision;
    while(true){
        printf("\n");
        system("clear");
        //system("cls"); On windows
        printf("1. Make a turn\n");
        printf("2. Make a query\n");
        printf("3. Make a whole list\n");
        printf("0. Exit the program\n");
        printf("Make a decison:(0~3)\n");
        scanf("%d", &decision);       
        if(decision>3 || decision<0){
            printf("Invalid Operation\n");
            exit(-1);        
        }
        switch(decision){
            case 0:
                printf("Bye~\n");
                exit(0);
            case 1:
                printf("Please enter two integer, separateed by a blank space(eg.13 45)\n");
                printf("Make sure that the integer fall between 0 ~ %d\n", CARD);
                int start, end;
                scanf("%d %d", &start, &end);
                if(turn(card, start, end))
                    printf("The card Being turn, Back...\n");
                else
                    printf("Invalid parameter\n");
                sleep(3);
                break;
            case 2:
                printf("Enter the index you want to query:(0~%d)\n", CARD);
                int index;
                scanf("%d", &index);
                printf("Number being entered %d\n", index);
                printf("The card is %d\n", query(card, index));
                sleep(3);
                break;
            case 3:
                printf("The whole card: ");
                int i;
                for(i=0; i<CARD; i++){
                    if(i%10 == 0)
                        printf("\n");
                    printf("%d ", query(card, i));    
                }
                sleep(3);
                break;
        }
    }

}
int main(int argc, char*argv[]){
    // Initialize the card array
    int *card = initialCard();
    //Ask the user to enter the range of card to flip
    makeDecision(card);
    free(card);
}
