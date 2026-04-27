#include "bst.h"
#include <stdio.h>
#include <stdlib.h>

BSTNode *bst_create_node(int value)
{

    BSTNode *bst = malloc(sizeof(BSTNode));
    if (!bst)
    {
        return NULL;
    }

    bst->left = NULL;
    bst->right = NULL;
    bst->value = value;
    return bst;
}

BSTNode *bst_insert(BSTNode *root, int value)
{
    if (!root)
    {
        return bst_create_node(value);
    }
    if (value > root->value)
    {
        root->right = bst_insert(root->right, value);
    }
    else if (value < root->value)
    {
        root->left = bst_insert(root->left, value);
    }
    return root;
}

BSTNode *bst_search(BSTNode *root, int value)
{

    if (!root)
    {
        return NULL;
    }
    if (value == root->value)
        return root;

    if (value > root->value)
    {
        return bst_search(root->right, value);
    }
    if (value < root->value)
    {
        return bst_search(root->left, value);
    }

    return NULL;
}

void bst_inorder(BSTNode *root)
{

    if (!root)
        return;

    bst_inorder(root->left);
    printf("%d, ", root->value);
    bst_inorder(root->right);
}

BSTNode *bst_min(BSTNode *root)
{
    while (root && root->left)
    {
        root = root->left;
    }
    return root;
}

BSTNode *bst_delete(BSTNode *root, int value)
{
    if (!root)
        return root;

    if (value > root->value)
    {
        root->right = bst_delete(root->right, value);
    }
    else if (value < root->value)
    {
        root->left = bst_delete(root->left, value);
    }
    else
    {
        if (!root->left)
        {
            BSTNode *temp = root;
            free(root);
            return temp->right;
        }
        else if (!root->right)
        {
            BSTNode *temp = root;
            free(root);
            return temp->left;
        }
        else
        {
            BSTNode *temp = bst_min(root->right);
            root->value = temp->value;
            root->right = bst_delete(root->right, temp->value);
        }
    }
    return root;
}

void bst_free(BSTNode *root)
{

    if (!root)
        return;

    bst_free(root->left);
    bst_free(root->right);
    free(root);
}