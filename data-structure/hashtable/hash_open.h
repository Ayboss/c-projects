#ifndef HASH_OPEN_H
#define HASH_OPEN_H

#include <stdbool.h>

typedef struct
{
    char *key;
    int value;
    bool occupied;
} HashEntry;

typedef struct
{
    HashEntry *entries;
    int capacity;
    int size;
} HashTable;

HashTable *ht_create(int capacity);
void ht_insert(HashTable *ht, const char *key, int value);
int *ht_search(HashTable *ht, const char *key);
void ht_free(HashTable *ht);

#endif