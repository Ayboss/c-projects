#ifndef HEAP_H
#define HEAP_H

#include <stddef.h>

typedef struct
{
    int *data;
    size_t size;
    size_t capacity;
} MinHeap;

MinHeap *heap_create(size_t capacity);
void heap_insert(MinHeap *heap, int value);
int heap_peek(MinHeap *heap);
int heap_extract_min(MinHeap *heap);
void heap_print(MinHeap *heap);
void heap_free(MinHeap *heap);

#endif