#include <stdio.h>
#include <stdlib.h>
#include "hash_chain.h"

int main()
{
    ChainHashTable *ht = cht_create(10);

    cht_insert(ht, "apple", 5);
    cht_insert(ht, "banana", 10);

    int *v = cht_search(ht, "banana");
    if (v)
        printf("%d\n", *v);

    cht_free(ht);
}