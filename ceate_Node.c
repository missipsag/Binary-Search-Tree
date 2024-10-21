#include<stdio.h>
#include<stdlib.h>

// define a node structure
typedef struct node { 
int key;
struct node* rightChild  ; 
struct node* leftChild ;
} node; 

// create a node 
node* createNode (int val){
    node* E = (node*)malloc(sizeof(node ));    // allocate memory for the the new node
    E->key= val;
    E->rightChild = E->leftChild = NULL;
    return E;     
}