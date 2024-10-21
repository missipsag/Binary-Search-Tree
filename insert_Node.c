#include<stdio.h>
#include<stdlib.h>

// define a node structure
typedef struct node { 
int key;
struct node* rightChild  ; 
struct node* leftChild ;
} node; 
node* createNode(int val);

// for inserting a new node in BST
void insertNode( node** root ,int val  ){
    
    node* N;
    node* temp;
    N = createNode(val);

    if(*root == NULL){      //if root is NULL, the new node will be root
        *root=N; 
        return ;
    }
    
    temp = *root;
    while(1){
        if (val > temp->key){                   // if val is greater than current key,
            if ( temp->rightChild == NULL){     // check if temp has no right child
                temp->rightChild = N;           //we assign it the new node
                break;      
            } else {
                temp = temp->rightChild;        // if temp has a right child, then tmp will point to it.
            }

        } else {                                // val is inferior than the current key
            if(temp->leftChild == NULL){        // temp has no left child
                temp->leftChild = N;            //we assign it the new node
                break;
            }
            else temp = temp->leftChild;        // if temp has a left child, then tmp will point to it.
        }
    }
}

