#include <stdlib.h>
#include <stdio.h>
#include "linkedlist.h"

Node *ll_create_node(int val)
{
    Node *node = malloc(sizeof(Node));
    if (!node)
    {
        return NULL;
    }
    node->val = val;
    node->next = NULL;
    return node;
}
Node *ll_push_front(int val, Node *head)
{
    Node *node = ll_create_node(val);
    if (!node)
    {
        return NULL;
    }
    node->next = head;
    return node;
}
Node *ll_push_back(int val, Node *head)
{
    Node *node = ll_create_node(val);
    if (!node)
    {
        return NULL;
    }
    if (!head)
    {
        return node;
    }
    Node *curr = head;

    while (curr->next)
    {
        curr = curr->next;
    }
    curr->next = node;
    return head;
}

void ll_print_node(Node *head)
{
    Node *curr = head;

    while (curr)
    {
        printf("%d -> ", curr->val);
        curr = curr->next;
    }

    printf("\n");
}
int ll_length(Node *head)
{
    Node *curr = head;
    int count = 0;
    while (curr)
    {
        count++;
        curr = curr->next;
    }

    return count;
}
Node *ll_reverse(Node *head)
{
    Node *prev = NULL;
    Node *curr = head;
    Node *next = head;

    while (curr)
    {
        next = curr->next;
        curr->next = prev;
        prev = curr;
        curr = next;
    }
    curr = prev;
    return curr;
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
    return NULL;
}

Node *ll_delete(Node *head, int val)
{

    // if the first value is the int

    if (!head)
        return NULL;

    if (head->val == val)
    {
        Node *temp = head->next;
        free(head);
        return temp;
    }
    // find the curr

    Node *curr = head;

    while (curr && curr->next && curr->next->val != val)
    {
        curr = curr->next;
    }

    if (curr->next->val == val)
    {
        Node *del = curr->next;
        curr->next = del->next;
        free(del);
    }

    return head;
}

void ll_free(Node *head)
{

    Node *curr = head;
    Node *temp = curr;
    while (curr)
    {
        temp = curr;
        curr = curr->next;
        free(temp);
    }
}
