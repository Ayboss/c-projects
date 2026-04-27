#include <stdio.h>
#include "heap.h"

int main(void)
{
    MinHeap *heap = heap_create(20);

    heap_insert(heap, 10);
    heap_insert(heap, 4);
    heap_insert(heap, 15);
    heap_insert(heap, 2);
    heap_insert(heap, 8);

    heap_print(heap);

    printf("Min: %d\n", heap_peek(heap));

    printf("Extracted: %d\n", heap_extract_min(heap));

    heap_print(heap);

    heap_free(heap);

    return 0;
}