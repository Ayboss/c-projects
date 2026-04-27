#include "avl.h"
#include <stdlib.h>
#include <stdio.h>

AVLNode *create_node(int value)
{
    AVLNode *node = malloc(sizeof(AVLNode));
    if (!node)
        return NULL;
    node->value = value;
    node->height = 1;
    node->left = NULL;
    node->right = NULL;
    return node;
}

static int max(int a, int b)
{
    return (a > b) ? a : b;
}

static int height(AVLNode *node)
{
    return node ? node->height : 0;
}

static AVLNode *rotate_right(AVLNode *root)
{
    AVLNode *A = root->left;
    root->left = A->right;
    A->right = root;

    root->height = 1 + max(height(root->left), height(root->right));
    A->height = 1 + max(height(A->left), height(A->right));
    return A;
}

static AVLNode *rotate_left(AVLNode *root)
{
    AVLNode *B = root->right;
    root->right = B->left;
    B->left = root;

    root->height = 1 + max(height(root->left), height(root->right));
    B->height = 1 + max(height(B->left), height(B->right));
    return B;
}

static int get_balance(AVLNode *node)
{
    return node ? height(node->left) - height(node->right) : 0;
}

AVLNode *avl_insert(AVLNode *root, int value)
{

    if (!root)
        return create_node(value);

    if (value < root->value)
    {
        root->left = avl_insert(root->left, value);
    }
    else if (value > root->value)
    {
        root->right = avl_insert(root->right, value);
    }
    else
    {
        return root;
    }

    root->height = 1 + max(height(root->left), height(root->right));

    int balance = get_balance(root);

    if (balance > 1 && value < root->left->value)
    {
        return rotate_right(root);
    }

    if (balance < -1 && value > root->right->value)
    {
        return rotate_left(root);
    }
    if (balance > 1 && value > root->left->value)
    {
        root->left = rotate_left(root->left);
        return rotate_right(root);
    }
    if (balance < -1 && value < root->right->value)
    {
        root->right = rotate_right(root->right);
        return rotate_left(root);
    }

    return root;
}

AVLNode *avl_search(AVLNode *root, int value)
{
    if (!root)
        return NULL;
    if (value < root->value)
    {
        return avl_search(root->left, value);
    }
    else if (value > root->value)
    {
        return avl_search(root->right, value);
    }
    else
    {
        return root;
    }
}

void avl_inorder(AVLNode *root)
{
    if (!root)
        return;
    avl_inorder(root->left);
    printf("%d, ", root->value);
    avl_inorder(root->right);
}

void avl_free(AVLNode *root)
{
    if (!root)
        return;
    avl_free(root->left);
    avl_free(root->right);
    free(root);
}

AVLNode *find_min(AVLNode *root)
{
    AVLNode *curr = root;

    while (curr && curr->left)
    {
        curr = curr->left;
    }

    return curr;
}
AVLNode *avl_delete(AVLNode *root, int value)
{
    if (!root)
        return root;
    if (value < root->value)
    {
        root->left = avl_delete(root->left, value);
    }
    else if (value > root->value)
    {
        root->right = avl_delete(root->right, value);
    }
    else
    {
        if (!root->right)
        {
            AVLNode *temp = root->left;
            free(root);
            root = temp;
        }
        else if (!root->left)
        {
            AVLNode *temp = root->right;
            free(root);
            root = temp;
        }
        else
        {
            AVLNode *temp = find_min(root->right);

            root->value = temp->value;
            root->right = avl_delete(root->right, temp->value);
        }
    }

    if (!root)
    {
        return NULL;
    }

    root->height = 1 + max(height(root->left), height(root->right));
    int balance = get_balance(root);

    if (balance > 1 && get_balance(root->left) >= 0)
        return rotate_right(root);

    if (balance > 1 && get_balance(root->left) < 0)
    {
        root->left = rotate_left(root->left);
        return rotate_right(root);
    }

    if (balance < -1 && get_balance(root->right) <= 0)
        return rotate_left(root);

    if (balance < -1 && get_balance(root->right) > 0)
    {
        root->right = rotate_right(root->right);
        return rotate_left(root);
    }

    return root;
}