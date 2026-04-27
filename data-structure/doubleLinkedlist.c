#include <stdio.h>
#include <stdlib.h>
#include "doubleLinkedlist.h"

Node *dll_create_node(int val)
{
    Node *node = malloc(sizeof(Node));
    node->val = val;
    node->next = NULL;
    node->prev = NULL;
    return node;
}

Node *ll_push_front(Node *head, int val)
{

    Node *node = dll_create_node(val);
    if (!head->prev)
    {
        head->prev = node;
        node->next = head;
        return head;
    }
    Node *prevnode = head->prev;
    prevnode->next = node;
    head->prev = node;
    node->prev = prevnode;
    node->next = head;
    return head;
}
Node *dll_push_back(Node *head, int val)
{
    Node *node = dll_create_node(val);
    if (!head->next)
    {
        head->next = node;
        node->prev = head;
        return head;
    }
    Node *nextnode = head->next;
    nextnode->prev = node;
    head->next = node;
    node->next = nextnode;
    node->prev = head;
    return head;
}

void ll_print_node(Node *head)
{

    while (head)
    {
        printf("%d ->", head->val);
        head = head->next;
    }
    printf("\n");
}
int ll_length(Node *head)
{
    int count = 0;
    while (head)
    {
        count++;
        head = head->next;
    }
    return count;
}

Node *ll_find(Node *head, int val)
{
    Node *curr = head;

    while (curr)
    {
        if (curr->val == val)
        {

            return curr;
        }
        curr = curr->next;
    }
    curr = head;
    while (curr)
    {
        if (curr->val == val)
        {

            return curr;
        }
        curr = curr->prev;
    }
    return NULL;
}

Node *ll_delete(Node *head, int val)
{

    if (!head)
        return NULL;
    Node *curr = head;
    Node *del = NULL;
    while (curr)
    {
        if (curr->val == val)
        {

            del = curr;
            break;
        }
        curr = curr->next;
    }
    curr = head;
    while (!del && curr)
    {
        if (curr->val == val)
        {
            del = curr;
            break;
        }
        curr = curr->prev;
    }
    if (!del)
        return NULL;

    if (!del->next && !del->prev)
    {
        free(del);
        return NULL;
    }
    if (!del->prev)
    {
        Node *temp = del->next;
        temp->prev = NULL;
        free(del);
        return temp;
    }
    if (!del->next)
    {
        Node *temp = del->prev;
        temp->next = NULL;
        free(del);
        return temp;
    }

    Node *prevnode = del->prev;
    Node *nextnode = del->next;
    prevnode->next = nextnode;
    nextnode->prev = prevnode;
    free(del);
    return prevnode;
}

void ll_free(Node *head)
{
    Node *curr = head;

    while (curr)
    {
        Node *temp = curr;
        free(temp);
        curr = curr->next;
    }
    curr = head;
    while (curr)
    {
        Node *temp = curr;
        free(temp);
        curr = curr->prev;
    }
    return NULL;
}
