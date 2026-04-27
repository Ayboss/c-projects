#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

typedef struct Node
{
    int val;
    struct Node *next;
} Node;

typedef struct
{
    Node *head;
    Node *tail;
    int size;
} Queue;

Queue *create_queue();
int size(Queue *queue);
bool is_empty(Queue *queue);
int peek(Queue *queue, bool *status);
void enqueue(Queue *queue, int val);
int dequeue(Queue *queue, bool *status);
void destroy_queue(Queue *queue);

int main()
{

    // Create a queue
    Queue *queue = create_queue();

    // The queue should initially be empty
    if (is_empty(queue))
        printf("Queue is empty.\n");

    // Try to enqueue the value 4 onto the queue
    enqueue(queue, 4);

    // The queue should not be empty now
    if (!is_empty(queue))
        printf("Queue is not empty.\n");

    // Enqueue the values 5 and 6 onto the queue
    enqueue(queue, 5);
    enqueue(queue, 6);

    // The queue size should now be 3
    printf("Queue size: %d\n", size(queue));

    // We'll try using the peek and dequeue operations.  We'll declare a bool
    // variable to store the status returned via "pass-by-pointer", and a variable
    // value to store the value peek'ed or dequeued.
    bool status = false;
    int value = 0;

    // Peek at the value stored at the head of the queue, which should be 4
    value = peek(queue, &status);
    if (status)
        printf("Peek successful: %d\n", value);

    // Now dequeue the value
    value = dequeue(queue, &status);
    if (status)
        printf("Dequeue succesful: %d\n", value);

    // Peek and dequeue the next two values 5 and 6
    value = peek(queue, &status);
    if (status)
        printf("Peek successful: %d\n", value);

    value = dequeue(queue, &status);
    if (status)
        printf("Dequeue succesful: %d\n", value);

    value = peek(queue, &status);
    if (status)
        printf("Peek successful: %d\n", value);

    value = dequeue(queue, &status);
    if (status)
        printf("Dequeue succesful: %d\n", value);

    // Now the queue should be empty, so both peek and dequeue should fail with
    // the variable status being set to false as a result.
    value = peek(queue, &status);
    if (!status)
        printf("Peek unsuccessful.\n");

    value = dequeue(queue, &status);
    if (!status)
        printf("Dequeue unsuccesful.\n");

    // destroy/delete the queue
    destroy_queue(queue);

    return 0;
}

Queue *create_queue()
{
    Queue *queue = malloc(sizeof(Queue));
    printf("Queue has the size of %lu \n", sizeof(Queue));
    printf("Node has the size of %lu \n", sizeof(Node));
    printf("Int has the size of %lu \n", sizeof(int));
    queue->head = NULL;
    queue->tail = NULL;
    queue->size = 0;
    return queue;
}
int size(Queue *queue)
{
    return queue->size;
}
bool is_empty(Queue *queue)
{
    return queue->size == 0;
}

int peek(Queue *queue, bool *status)
{
    if (is_empty(queue))
    {
        *status = false;
        return 0;
    }
    *status = true;
    return queue->head->val;
}
void enqueue(Queue *queue, int val)
{
    Node *node = malloc(sizeof(Node));
    node->val = val;
    node->next = NULL;
    if (is_empty(queue))
    {
        queue->tail = node;
        queue->head = node;
    }
    else
    {
        queue->tail->next = node;
        queue->tail = node;
    }
    queue->size++;
}
int dequeue(Queue *queue, bool *status)
{
    if (is_empty(queue))
    {
        *status = false;
        return 0;
    }
    Node *node = queue->head;
    int value = node->val;
    if (size(queue) == 1)
    {
        queue->head = NULL;
        queue->tail = NULL;
    }
    else
    {
        queue->head = node->next;
    }
    queue->size--;
    free(node);
    *status = true;
    return value;
}
void destroy_queue(Queue *queue)
{

    while (queue->head != NULL)
    {
        Node *oldnode = queue->head;
        queue->head = oldnode->next;
        free(oldnode);
    }
    free(queue);
}
