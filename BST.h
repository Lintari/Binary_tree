#pragma once

#include <stdbool.h>

typedef struct BST BST;

BST* bstInit(void);
int bstInsert(BST*, int);
bool bstContains(BST*, int);
void bstFree(BST*);

void bstInorder(BST*);
void bstPreorder(BST*);
void bstPostoreder(BST*);

int bstHeight(BST*);
int bstSize(BST*);
int bstMin(BST*);
int bstMax(BST*);
