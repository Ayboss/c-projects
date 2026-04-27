#ifndef AVL_H
#define AVL_H

typedef struct AVLNode
{
    int value;
    int height;
    struct AVLNode *left;
    struct AVLNode *right;
} AVLNode;

AVLNode *create_node(int value);
AVLNode *avl_insert(AVLNode *root, int value);
AVLNode *avl_delete(AVLNode *root, int value);
AVLNode *avl_search(AVLNode *root, int value);
void avl_inorder(AVLNode *root);
void avl_free(AVLNode *root);

#endif