#include "heap.h"
#include <stdio.h>
#include <stdlib.h>

MinHeap *heap_create(size_t capacity)
{
    MinHeap *heap = malloc(sizeof(MinHeap));
    if (!heap)
        return NULL;
    heap->capacity = capacity;
    heap->size = 0;
    heap->data = malloc(capacity * sizeof(int));

    if (!heap->data)
    {
        free(heap);
        return NULL;
    }

    return heap;
}

static void swap(int *a, int *b)
{
    int temp = *a;
    *a = *b;
    *b = temp;
}

void heapify_up(MinHeap *heap, size_t index)
{
    while (index > 0)
    {
        size_t parent_idx = (index - 1) / 2;
        if (heap->data[parent_idx] < heap->data[index])
            break;

        swap(&heap->data[parent_idx], &heap->data[index]);

        index = parent_idx;
    }
}

void heapify_down(MinHeap *heap, size_t index)
{

    while (1)
    {

        size_t left_child_idx = index * 2 + 1;
        size_t right_child_idx = index * 2 + 2;
        size_t smallest_idx = index;

        if (left_child_idx < heap->size && heap->data[left_child_idx] < heap->data[smallest_idx])
            smallest_idx = left_child_idx;

        if (right_child_idx < heap->size && heap->data[right_child_idx] < heap->data[smallest_idx])
            smallest_idx = right_child_idx;

        if (smallest_idx == index)
            break;

        swap(&heap->data[index], &heap->data[smallest_idx]);
        index = smallest_idx;
    }
}
void heap_insert(MinHeap *heap, int value)
{

    if (heap->size == heap->capacity)
    {
        return;
    }

    heap->data[heap->size] = value;
    heapify_up(heap, heap->size);
    heap->size++;
}
int heap_peek(MinHeap *heap)
{
    return heap->data[0];
}
int heap_extract_min(MinHeap *heap)
{
    int val = heap_peek(heap);
    swap(&heap->data[0], &heap->data[heap->size - 1]);
    heap->size--;
    heapify_down(heap, 0);
    return val;
}
void heap_print(MinHeap *heap)
{

    for (size_t i = 0; i < heap->size; i++)
    {
        printf("%d, ", heap->data[i]);
    }

    printf("\n");
}
void heap_free(MinHeap *heap)
{

    free(heap->data);
    free(heap);
}
