#include<stdio.h>
#include<stdlib.h>

// define a node structure
typedef struct node { 
int key;
struct node* rightChild  ; 
struct node* leftChild ;
} node; 

// this function traverses the BST using preorder algortithm 
// root => leftChild => rightChild

void preorder( node* root){ 
    if (root== NULL) return;       // if the tree is empty
    printf("%d\t", root->key);     // print the key 
    preorder(root->leftChild);
    preorder(root->rightChild);
}

// this function traverses the BST using inorder algortithm 
// leftChild => root => rightChild

void inorder(node* root){
    if (root== NULL) return;        // if the tree is empty
    inorder(root->leftChild);
    printf("%d\t", root->key);      // print the key 
    inorder(root-> rightChild);
}

// this function traverses the BST using postorder algortithm 
// leftChild => rightChild => root

void postorder(node* root){
    if (root== NULL) return;        // if the tree is empty
    postorder(root->leftChild);
    postorder(root-> rightChild);   
    printf("%d\t", root->key);      // print the key
}