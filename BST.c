#include "BST.h"
#include <stdio.h>
#include <stdlib.h>


typedef struct Node{
    struct Node* leftChild;
    Node* rightChild; 
    int value;
}Node; 


typedef struct BST{
    Node* root;
    int numOfEl;
}BST; 


BST* bstInit (void){
    BST* tree = malloc (sizeof(BST));
    tree -> root = NULL;
    tree -> numOfEl = 0;
    return tree;
}

int insertRecursion(Node* vertex, int n){
    if (vertex -> value < n) {
        if (vertex -> leftChild == NULL) {
            Node* leaf = malloc(sizeof(Node));
            if (leaf == NULL)
                return -1;
            leaf -> leftChild = NULL;
            leaf -> rightChild = NULL;
            leaf -> value = n;
            return 0;
        }
        return insertRecursion(vertex -> leftChild, n); 
    } 
    else if (vertex -> value > n) {
        if (vertex -> rightChild == NULL) {
            Node* leaf = malloc(sizeof(Node));
            if (leaf == NULL)
                return -1;
            leaf -> leftChild = NULL;
            leaf -> rightChild = NULL;
            leaf -> value = n;
            return 0;
        }
        return insertRecursion(vertex -> rightChild, n);
    }
    return 0;
}

int bstInsert(BST* tree, int value){
    if (tree -> root == NULL) {
       Node* vert = malloc(sizeof(Node));
       vert -> value = value;
       vert -> leftChild = NULL;
       vert -> rightChild = NULL;
       tree -> root = vert;
       return;
    }
    int error = insertRecursion(tree -> root, value);
    if (error != 0)
        return -1;
    tree -> numOfEl++;
    return 0;
} 

bool containsRecursion (Node* vertex, int n){
    if (vertex -> value < n) {
        if (vertex -> leftChild == NULL) {
            return False;
        }
        return containsRecursion(vertex -> leftChild, n); 
    } 
    else if (vertex -> value > n) {
        if (vertex -> rightChild == NULL) {
            return False;
        }
        return containsRecursion(vertex -> rightChild, n);
    }
    return True;
}

bool bstContains(BST* tree, int value){
    if (tree -> root == NULL)
        return False;
    return containsRecursion(tree -> root, value);
}

void bstFreeRecursion (Node* vertex){
    if (vertex -> leftChild != NULL)
	bstFreeRecursion( vertex -> leftChild);
    
    if (vertex -> rightChild != NULL)
	bstFreeRecursion( vertex -> rightChild); 
    free(vertex);
}

void bstFree(BST* tree){ 
    bstFreeRecursion( tree->root);
    free(tree);
}
