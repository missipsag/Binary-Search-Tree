#include<stdio.h>
#include<stdlib.h>

// define a node structure
typedef struct node { 
int key;
struct node* rightChild  ; 
struct node* leftChild ;
} node; 

//this function returns a pointer to the max key value in the BST, which is the last rightchild
node*  max( node * root){
    node* temp;
    if (root == NULL ) return NULL;  // check if the tree is empty
    temp = root;

    while(temp->rightChild) {       // go for the max value
        temp=temp->rightChild;
    }
    return temp;
}

//this function returns a pointer to the minimum key value in the BST, which is the last lefchild
node* min( node * root){
    node* temp = root; 
    if (root == NULL) return NULL;  // if the tree is empty
    temp = root ; 
    while(temp->leftChild){         // go for the min value
        temp=temp->leftChild;
    }  
    return temp;
}

