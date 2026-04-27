#include <stdio.h>
#include <stdlib.h>

typedef struct Node
{
    int val;
    struct Node *next;
    struct Node *prev;
} Node;

Node *dll_create_node(int val);

Node *ll_push_front(Node *head, int val);
Node *dll_push_back(Node *head, int val);

void ll_print_node(Node *head);
int ll_length(Node *head);

Node *ll_find(Node *head, int val);

Node *ll_delete(Node *head, int val);
void ll_free(Node *head);