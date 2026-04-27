#include <stdio.h>
#include "linkedlist.h"

int main()
{
    Node *head = NULL;
    head = ll_push_back(10, head);
    head = ll_push_back(20, head);
    head = ll_push_back(30, head);

    ll_print_node(head);

    head = ll_push_front(5, head);
    ll_print_node(head);

    head = ll_reverse(head);
    ll_print_node(head);

    head = ll_delete(head, 20);
    ll_print_node(head);

    printf("Length: %d\n", ll_length(head));

    ll_free(head);
    return 0;
}