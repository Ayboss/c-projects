#include <stdlib.h>
#include <stdio.h>

typedef struct Node
{
    int val;
    struct Node *next;
} Node;

Node *ll_create_node(int val)
{
    Node *head = malloc(sizeof(Node));
    head->val = val;
    head->next = head;
}
Node *ll_push_front(Node *head, int val)
{
    Node *node = ll_create_node(val);
    Node *temp = head->next;
    head->next = node;
    node->next = temp;
    return head;
}
Node *ll_push_back(Node *head, int val)
{
    Node *node = ll_create_node(val);
    Node *curr = head;
    while (curr->next != head)
    {
        curr = curr->next;
    }
    curr->next = node;
    node->next = head;
    return head;
}

void ll_print_node(Node *head)
{
    if (!head)
        return NULL;
    printf("%d -> ", head->val);
    Node *curr = head->next;
    while (curr && curr != head)
    {
        printf("%d -> ", curr->val);
        curr = curr->next;
    }
    printf("\n");
}

int ll_length(Node *head)
{
    if (!head)
        return NULL;
    int count = 1;
    Node *curr = head->next;
    while (curr && curr != head)
    {
        count += 1;
        curr = curr->next;
    }
    return count;
}
Node *ll_reverse(Node *head);
Node *ll_find(Node *head, int val);

Node *ll_delete(Node *head, int val);

void ll_free(Node *head);

int main()
{
    return 0;
}