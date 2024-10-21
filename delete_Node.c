#include<stdio.h>
#include<stdlib.h>

// define a node structure
typedef struct node { 
int key;
struct node* rightChild  ; 
struct node* leftChild ;
} node; 

node* searchNode(node* root, int val);
node* min(node* root);

//this function deletes a node based on it key
node* deleteNode(node* root, int val ){
    node* temp= searchNode( root, val);         
    if (root==NULL) return NULL;            //check if the tree is empty

    if (val==root->key){                    // the node to delete is the root

        if (!root->leftChild && !root->rightChild ){        //the root is a leaf
            free(root );
            root=NULL;
        } else {                               //the node to delete has only one child or is a leaf
            if (root->rightChild == NULL){     // has only a left child
                node* temp = root;
                root = root->leftChild;
                free(temp);
            } else if(root->leftChild == NULL)  {                //has only a right child
                node* temp =root;
                root= root->rightChild;
                free(temp);
            } else {
                node * temp = min(root->rightChild);
                root->key= temp->key;
                root->rightChild= deleteNode(root->rightChild, temp->key);
            }          
        }    
    }

    // we compare val to root's key 
    else if (val < root->key){  
        root->leftChild= deleteNode(root->leftChild, val);        //we call deleteNode with the same val and root->leftChild as new root
    }
    else root->rightChild= deleteNode(root->rightChild, val);     //we call deleteNode with the same val and root->rightChild as new root
}

