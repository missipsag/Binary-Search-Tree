#include<stdio.h>
#include<stdlib.h>

// define a node structure
typedef struct node { 
int key;
struct node* rightChild  ; 
struct node* leftChild ;
} node; 

// this function returns a pointer the node containing a given key, NULL if it doesn't exist in the BST
node* searchNode( node* root, int val  ){
    node* temp;
    if (root == NULL) return NULL;   // check  if the tree is empty

    temp = root; 
    while( temp ){                   // walk the tree
        if (val > temp->key){        
            temp=temp->rightChild;
        }
        else if (val < temp->key){
            temp=temp->leftChild;
        }
        else return temp;           // return the node 
    }
    return NULL;                    // if the no node is found, we return NULL
}