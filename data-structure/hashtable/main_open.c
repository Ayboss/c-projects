#include <stdio.h>
#include <stdlib.h>
#include "hash_open.h"

int main()
{
    HashTable *ht = ht_create(10);

    ht_insert(ht, "apple", 5);
    ht_insert(ht, "banana", 10);

    int *v = ht_search(ht, "banana");
    if (v)
        printf("%d\n", *v);

    ht_free(ht);
}