#include "BST.h"
#include <stdio.h>
#include <stdlib.h>

typedef struct Node {
    struct Node* leftChild;
    struct Node* rightChild;
    int value;
} Node;

typedef struct BST {
    Node* root;
    int numOfEl;
} BST;

BST* bstInit(void)
{
    BST* tree = malloc(sizeof(BST));
    tree->root = NULL;
    tree->numOfEl = 0;
    return tree;
}

int insertRecursion(Node* vertex, int n) // NOLINT(misc-no-recursion)
{
    if (vertex->value < n) {
        if (vertex->leftChild == NULL) {
            Node* leaf = malloc(sizeof(Node));
            if (leaf == NULL)
                return -1;
            leaf->leftChild = NULL;
            leaf->rightChild = NULL;
            leaf->value = n;
            vertex->leftChild = leaf;
            return 0;
        }
        return insertRecursion(vertex->leftChild, n); // NOLINT(misc-no-recursion)
    } else if (vertex->value > n) {
        if (vertex->rightChild == NULL) {
            Node* leaf = malloc(sizeof(Node));
            if (leaf == NULL)
                return -1;
            leaf->leftChild = NULL;
            leaf->rightChild = NULL;
            leaf->value = n;
            vertex->rightChild = leaf;
            return 0;
        }
        return insertRecursion(vertex->rightChild, n); // NOLINT(misc-no-recursion)
    }
    return 0;
}

int bstInsert(BST* tree, int value)
{
    if (tree->root == NULL) {
        Node* vert = malloc(sizeof(Node));
        vert->value = value;
        vert->leftChild = NULL;
        vert->rightChild = NULL;
        tree->root = vert;
        return 0;
    }
    int error = insertRecursion(tree->root, value);
    if (error != 0)
        return -1;
    tree->numOfEl++;
    return 0;
}

bool containsRecursion(Node* vertex, int n) // NOLINT(misc-no-recursion)
{
    if (vertex->value < n) {
        if (vertex->leftChild == NULL) {
            return false;
        }
        return containsRecursion(vertex->leftChild, n); // NOLINT(misc-no-recursion)
    } else if (vertex->value > n) {
        if (vertex->rightChild == NULL) {
            return false;
        }
        return containsRecursion(vertex->rightChild, n); // NOLINT(misc-no-recursion)
    }
    return true;
}

bool bstContains(BST* tree, int value)
{
    if (tree->root == NULL)
        return false;
    return containsRecursion(tree->root, value);
}

void bstFreeRecursion(Node* vertex) // NOLINT(misc-no-recursion)
{
    if (vertex->leftChild != NULL)
        bstFreeRecursion(vertex->leftChild); // NOLINT(misc-no-recursion)
    if (vertex->rightChild != NULL)
        bstFreeRecursion(vertex->rightChild); // NOLINT(misc-no-recursion)
    free(vertex);
}

void bstFree(BST* tree)
{
    if (tree->root != NULL)
        bstFreeRecursion(tree->root);
    free(tree);
}

void inorderRecursion(Node* vertex) // NOLINT(misc-no-recursion)
{
    printf("%d ", vertex->value);
    if (vertex->leftChild != NULL)
        inorderRecursion(leftChild); // NOLINT(misc-no-recursion)
    if (vertex->rightChild != NULL)
        inorderRecursion(rightChild); // NOLINT(misc-no-recursion)
}

void bstInorder(BST* tree)
{
    inorderRecursion(tree->root);
    printf("\n");
}

void preorderRecursion(BST* tree) // NOLINT(misc-no-recursion)
{
    if (vertex->leftChild != NULL)
        inorderRecursion(leftChild); // NOLINT(misc-no-recursion)
    printf("%d ", vertex->value);
    if (vertex->rightChild != NULL)
        inorderRecursion(rightChild); // NOLINT(misc-no-recursion)

}

void bstPreorder(BST* tree)
{
    preorderRecustion(tree->root);
    printf("\n");
}


void postorderRecursion(Node* vertex) // NOLINT(misc-no-recursion)
{
    if (vertex->leftChild != NULL)
        inorderRecursion(leftChild); // NOLINT(misc-no-recursion)
    if (vertex->rightChild != NULL)
        inorderRecursion(rightChild); // NOLINT(misc-no-recursion)
    printf("%d ", vertex->value);
}

void bstPostorder(BST* tree)
{
    postorderRecursion(Node* vertex);
    printf("\n");
}

