#include<stdio.h>
#include<stdlib.h>

// define a node structure
typedef struct node { 
int key;
struct node* rightChild  ; 
struct node* leftChild ;
} node; 

node* deleteNode(node* root, int val);
node* searchNode(node* root, int val);
node* Node(node* root, int val);
node* createNode(int val);
void preorder(node* root);
void postorder(node* root);
void inorder(node* root);
node* max(node* root);
node* min(node* root);
void insertNode(node** root, int val);

void main(){
    // define a node pointer 
    node* tree = NULL;

    insertNode(&tree,11);
    insertNode(&tree,5);
    insertNode(&tree,6);
    insertNode(&tree,0);
    insertNode(&tree,8);
    insertNode(&tree,13);
    insertNode(&tree,55);
    insertNode(&tree,2);
    insertNode(&tree,23);
    insertNode(&tree,19);

    printf("le parcours infixe est :\t");
    inorder(tree);
    printf("\n la parcours prefixe est : \t");
    preorder(tree);
    printf("\nle parcours postfixe est: ");
    postorder(tree);

    printf("\n le valeur maximale est de %d", max(tree)->key);
    printf("\n le valeur minimale est de %d", min(tree)->key);
    printf("\n");

    node* p = searchNode(tree, 13);
    if (p == NULL) printf("la valeur n'existe pas\n ");
    else printf("la valeur existe a l'adressse %p\n",p);
    
    deleteNode(tree, 23);
    printf("\n la parcours prefixe est : \t");
    inorder(tree);
}