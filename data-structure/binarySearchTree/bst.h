#ifndef BST_H
#define BST_H

typedef struct BSTNode
{
    int value;
    struct BSTNode *left;
    struct BSTNode *right;
} BSTNode;

BSTNode *bst_create_node(int value);
BSTNode *bst_insert(BSTNode *root, int value);
BSTNode *bst_search(BSTNode *root, int value);
void bst_inorder(BSTNode *root);
BSTNode *bst_delete(BSTNode *root, int value);
void bst_free(BSTNode *root);

#endif