#include "BST.h"
#include <stdio.h>
#include <stdlib.h>

int main(void)
{
    BST* tree1 = bstInit();

    for (int i = 0; i < 10; ++i)
        bstInsert(tree1, i);

    bstInorder(tree1);
    bstPreorder(tree1);
    bstPostorder(tree1);

    bstFree(tree1);

    BST* tree2 = bstInit();
    int a[5] = { 3, 2, 4, 1, 5 };
    for (int i = 0; i < 5; ++i)
        bstInsert(tree2, a[i]);
    bstInorder(tree2);
    bstPreorder(tree2);
    bstPostorder(tree2);
    bstFree(tree2);

    BST* tree3 = bstInit();
    int b[7] = { 50, 30, 70, 20, 40, 60, 80 };
    for (int i = 0; i < 7; ++i)
        bstInsert(tree3, b[i]);
    bstInorder(tree3);
    bstPreorder(tree3);
    bstPostorder(tree3);
    bstFree(tree3);
    return 0;
}
