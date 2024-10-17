#include<stdio.h>
#include<stdlib.h>


// define a node structure
typedef struct node { 
int key;
struct node* rightChild  ; 
struct node* leftChild ;
} node; 
    

//we create a node 

node * createNode (int val){

    node* E = (node*)malloc(sizeof(node ));

        E->key= val;
        E->rightChild = E->leftChild = NULL;
        
        return E;     
}


// for inserting a new node in BST
void insert( node ** root ,int val  ){
    
    node * N;
    node * temp;
    N = createNode(val);

    //check if root is NULL
    if(*root==NULL){
        
        *root=N; 
        return ;
    }

    // if root is not NULL
    temp=*root;

    while(1){

        //we compare val to the node.key where temp in pointing to
        if (val > temp->key){

            //if the node which temp is pointing to is a leaf
            if ( temp->rightChild== NULL){

                //we assign it the new node
                temp->rightChild= N;
                break;      
            } else {
                temp= temp->rightChild;
            }
        }
        else {

            //if the node which temp is pointing to is a leaf
            if(temp->leftChild== NULL){

                //we assign it the new node
                temp->leftChild= N;
                break;
            }
            else temp=temp->leftChild;
        }
    }
}



void preorder( node *root){
   // this function traverses the BST using preorder algortithm 
   // root => leftChild => rightChild

    if (root== NULL) return;
    printf("%d\t", root->key);
    preorder(root->leftChild);
    preorder(root->rightChild);
}

void inorder(node * root){
       // this function traverses the BST using inorder algortithm 
       // leftChild => root => rightChild

    if (root== NULL) return; 

    inorder(root->leftChild);
    printf("%d\t", root->key);
    inorder(root-> rightChild);
}

void postorder(node * root){
       // this function traverses the BST using postorder algortithm 
       // leftChild => rightChild => root

    if (root== NULL) return;
    postorder(root->leftChild);
    postorder(root-> rightChild);
    printf("%d\t", root->key); 
    
}

//this function returns a pointer to the max key value in the BST
node*  max( node * root){
    node * temp;
    if (root == NULL ) return NULL;
    temp= root;

    while(temp->rightChild) {
        temp=temp->rightChild;
    }

    return temp;
}

//this function returns a pointer to the minimum key value in the BST
node * min( node * root){
    node * temp = root; 

    if (root == NULL) return NULL;

    temp= root ; 
    while(temp->leftChild){
        temp=temp->leftChild;
    }  
    return temp;
}

// this function returns a pointer the node containing a given key, NULL if it doesn't exist in the BST
node* search( node * root, int val  ){

    node * temp;
    if (root == NULL) return NULL;

    temp= root ; 
    while( temp ){
        if (val> temp->key){
            temp=temp->rightChild;
        }
        else if (val < temp->key){
            temp=temp->leftChild;
        }
        else return temp;
    }
    return NULL;
}

//this function deletes a node based on it key
node* deleteNode(node * root, int val ){
    node* temp= search( root, val); 
    
    //check if the tree is empty
    if (root==NULL) return NULL;

    // the node to delete is the root
    if (val==root->key){

        //the root is a leaf
        if (!root->leftChild && !root->rightChild ){
            free(root );
            root=NULL;
        }     
        //the node to delete has only a leftChild
        else{

            if (root->rightChild==NULL){
                node* temp = root;
                root= root->leftChild;
                free(temp);
            }
            // the node to delete has two children
        
            else if(temp->rightChild && temp->leftChild) {
                node * temp = min(root->rightChild);
                root->key= temp->key;
                root->rightChild= deleteNode(root->rightChild, temp->key);
            }
            //has only a right child
            else {
                node* temp =root;
                root= root->rightChild;
                free(temp);
            }    
        }    
    }

    // we compare val to root's key 
    else if (val < root->key){
        //we call deleteNode with the same val and root->leftChild as new root
        root->leftChild= deleteNode(root->leftChild, val);
    }
    //we call deleteNode with the same val and root->rightChild as new root
    else root->rightChild= deleteNode(root->rightChild, val);
}




void main(){
    // define a node pointer 
    node * tree = NULL;

    insert(&tree,11);
    insert(&tree,5);
    insert(&tree,6);
    insert(&tree,0);
    insert(&tree,8);
    insert(&tree,13);
    insert(&tree,55);
    insert(&tree,2);
    insert(&tree,23);
    insert(&tree,19);

    printf("le parcours infixe est :\t");
    inorder(tree);
    printf("\n la parcours prefixe est : \t");
    preorder(tree);
    printf("\nle parcours postfixe est: ");
    postorder(tree);

    printf("\n le valeur maximale est de %d", max(tree)->key);

    printf("\n le valeur minimale est de %d", min(tree)->key);


    printf("\n");

    node* p=search(tree, 13);
    if (p==NULL) printf("la valeur n'existe pas\n ");
    else printf("la valeur existe a l'adressse %p\n",p);
    
    deleteNode(tree, 23);
    printf("\n la parcours prefixe est : \t");
    inorder(tree);
}