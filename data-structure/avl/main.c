#include <stdio.h>
#include "avl.h"

int main(void)
{
    AVLNode *root = NULL;

    int vals[] = {20, 10, 30, 5, 15, 25, 40};

    for (int i = 0; i < 7; i++)
        root = avl_insert(root, vals[i]);

    printf("Before delete:\n");
    avl_inorder(root);
    printf("\n");

    root = avl_delete(root, 20);

    printf("After delete:\n");
    avl_inorder(root);
    printf("\n");

    avl_free(root);
}