#include <stdio.h>
#include "bst.h"

int main(void)
{
    BSTNode *root = NULL;

    int values[] = {8, 3, 10, 1, 6, 14, 4, 7, 13};

    for (int i = 0; i < 9; i++)
        root = bst_insert(root, values[i]);

    printf("Inorder traversal:\n");
    bst_inorder(root);
    printf("\n");

    BSTNode *found = bst_search(root, 6);
    if (found)
        printf("Found: %d\n", found->value);

    root = bst_delete(root, 3);

    printf("After deletion:\n");
    bst_inorder(root);
    printf("\n");

    bst_free(root);

    return 0;
}