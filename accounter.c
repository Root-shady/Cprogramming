#include<stdio.h>
#include<stdlib.h>
#include<stdbool.h>
typedef struct tree_node{
    int item;
    int size;
    struct tree_node *left, *right;
    struct tree_node *father;    
}tree_node, *SplayTree;
//typedef struct{
//    bool noFound;
//    struct tree_node *ptr;   
//}Bundle;
// Zag operation
void leftRotate(tree_node *newRoot){
    tree_node *oldRoot;
    oldRoot = newRoot->father; // The root node
    oldRoot->right = newRoot->left;
    if(newRoot->left != NULL)
        newRoot->left->father = oldRoot;
    newRoot->father = oldRoot->father; // X become the root
    if(oldRoot->father != NULL){
        if(oldRoot == oldRoot->father->left)
            oldRoot->father->left = newRoot;
        else
            oldRoot->father->right = newRoot;
    }
    oldRoot->father = newRoot;
    newRoot->left = oldRoot;
}
//Zig operation
void rightRotate(tree_node *newRoot){
    tree_node *oldRoot = newRoot->father;
    oldRoot->left = newRoot->right;
    if(newRoot->right != NULL)
        newRoot->right->father = oldRoot;
    newRoot->father = oldRoot->father;
    if(oldRoot->father != NULL){
        if(oldRoot == oldRoot->father->left)
            oldRoot->father->left = newRoot;
        else
            oldRoot->father->right = newRoot;
    }
    oldRoot->father = newRoot;
    newRoot->left = oldRoot;    
}
void splay(SplayTree newRoot, SplayTree tree){
    tree_node *p;
    while(newRoot->father != NULL){ // newRoot is already root
        p = newRoot->father;
        if(p->father == NULL){
            if(newRoot == p->left)
                rightRotate(newRoot);//Zig
            else
                leftRotate(newRoot);//Zag
            break; //We are in the root position
        }
        if(newRoot == p->left){ //newRoot is the left child
            if(p == p->father->left){ // p is the left child
                rightRotate(p);  //Zig-Zig
                rightRotate(newRoot);
            }
            else{  //Zig - Zag Situation
                rightRotate(newRoot);
                leftRotate(newRoot);
            }
        }
        else{ // newRoot is the right child
            if(p == p->father->right){ // p is the right child
                leftRotate(p); // Zag-Zag Situation
                leftRotate(newRoot);
            }
            else{
                leftRotate(newRoot); //Zag-Zig Situation
                rightRotate(newRoot);    
            }
        }
    }
    tree = newRoot; //Resign the new root
}
//Bundle searchBST(int x, SplayTree tree){
//    if(tree == NULL){
//        Bundle result = {true, NULL};
//        return result;
//    }
//    tree_node *current;
//    current = tree;
//    bool noFound = false;
//    while(current->item != x){
//        if(current->item > x){
//            if(current->left != NULL)
//                current = current->left;
//            else{
//                noFound = true;
//                break;
//            }
//        }    
//        else{
//            if(current->right != NULL)
//                current = current->right;
//            else{
//                noFound = true;
//                break;    
//            }
//        }
//    }
//    Bundle result = {noFound, current};
//    //result.onFound = noFound;
//    //result.ptr = current;
//    return result;
//}
// Find the element, then splay the tree, even when the element not found
tree_node *find(int x, SplayTree tree){
    if(tree == NULL)
        return NULL;
    tree_node *current;
    current = tree;
    bool noFound = false;
    while(current->item != x){
        if(current->item > x){
            if(current->left != NULL)
                current = current->left;
            else{
                noFound = true;
                break;
            }
        }    
        else{
            if(current->right != NULL)
                current = current->right;
            else{
                noFound = true;
                break;    
            }
        }
    }
    splay(current, tree);
    return noFound?NULL:current;
}
int searchBST(int x, tree_node *s, tree_node *f, SplayTree p){
    if(s == NULL){
        p = f;
        return 0;
    }
    if(x == s->item){
        p = s; return 1;    
    }
    else if(x<s->item)
        return searchBST(x, s->left, s, p);
    else
        return searchBST(x, s->right, s, p);     
}
tree_node *insertBST(int x, SplayTree tree){
    tree_node *p, *t;
    if(!searchBST(x, tree, NULL, p)){
        t = (SplayTree)malloc(sizeof(tree_node));
        t->item = x;
        t->left = t->right = NULL;
        t->father = p;
        if(!p)
            tree = t;
        else if(x < p->item) 
            p->left = t;
        else 
            p->right = t;
        return t;   
    }
    return NULL;
}
void insert(int x, SplayTree tree){
    tree_node *p;
    p = insertBST(x, tree);
    if(p)
        splay(p, tree);
}
tree_node *maximum(tree_node *s){
    if(node == NULL)
        return NULL;
    tree_node *p = s;
    while(p->right != NULL)
        p = p->right;
    splay(p, s);
    return p;    
}
tree_node* join(SplayTree Atree, SplayTree Btree){
    tree_node *p;
    if(Atree == NULL){
        if(Btree)
            Btree->father = NULL;
        return Btree;    
    }
    if(Btree == NULL){
        if(Atree)
            Atree->father = NULL;
        return Atree;    
    }    
    p = maximum(Atree);
    p->right = Btree;
    Btree->father = p;
    return p;
}
void delete(int x, SplayTree &tree){
    // Suppose x can be found
    tree_node *p;
    p = find(x, tree);
if(p)
        s = join(p->left, p->right);
}
int main(int argc, char* argv[]){
    int n, min, delta = 0, num;
    char opr;
    rppt = NULL;
    printf("How many command you wanna enter? and what's the minimum salary:(eg 5 3000) ");
    scanf("%d %d", &n, &min); //Take n commands and minimum of salary
    for(int i=0; i<n; i++){
        printf("Enter the command in the following format:\n (Operation code salary)(eg. I 200)\n ");
        scanf("%c %d", &opr, &num);
        switch(opt){
            case 'I': 
                if(num >= min)    
                    insert(num-delta, root);
                break;
            case 'A':
                delta += num;
                break;
            case 'S':
                delta -= num;
                delMin(min-delta-1, root); 
                break;
            case 'F':
                if(!root || num > root->size)
                    printf("-1\n");
                else{
                    findK(root->size-num+1, root);
                    printf("%d\n", root->item + delta);    
                }
                break;
        }    
    }
      
}
