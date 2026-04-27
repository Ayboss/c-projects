typedef struct Node {
    int val;
    struct Node* next;
} Node;


Node* ll_create_node(int val);
Node* ll_push_front(int val, Node* head);
Node* ll_push_back(int val, Node* head);

void ll_print_node(Node* head);
int ll_length(Node* head);
Node* ll_reverse(Node* head);
Node* ll_find(Node* head, int val);

Node* ll_delete(Node* head, int val);

void ll_free(Node* head);

