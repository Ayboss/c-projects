#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include "hash_open.h"

// #define HASH_CAPACITY 20

static unsigned long hash_function(const char *key)
{
    unsigned long h = 5381;
    int c;

    while ((c = *key++))
        h = ((h << 5) + h) + c;

    return h;
}

HashTable *ht_create(int capacity)
{

    HashTable *hashtable = malloc(sizeof(HashTable));
    if (!hashtable)
    {
        return NULL;
    }
    hashtable->capacity = capacity;
    hashtable->size = 0;
    hashtable->entries = calloc(capacity, sizeof(HashEntry));
    if (!hashtable->entries)
    {
        return NULL;
    }

    return hashtable;
}

void ht_insert(HashTable *ht, const char *key, int value)
{
    int hash_idx = hash_function(key) % ht->capacity;

    if (ht->size >= ht->capacity)
    {
        fprintf(stderr, "HASH TABLE IS FULL");
        exit(EXIT_FAILURE);
    }
    // normal insert
    while (ht->entries[hash_idx].occupied)
    {

        if (
            strcmp(ht->entries[hash_idx].key, key) == 0)
        {
            ht->entries[hash_idx].value = value;
            return;
        }
        hash_idx = (hash_idx + 1) % ht->capacity;
    }
    ht->entries[hash_idx].value = value;
    ht->entries[hash_idx].key = strdup(key);
    ht->entries[hash_idx].occupied = true;
    ht->size++;
}

int *ht_search(HashTable *ht, const char *key)
{
    int hash_idx = hash_function(key) % ht->capacity;
    int start = hash_idx;
    while (ht->entries[hash_idx].occupied)
    {
        if (strcmp(ht->entries[hash_idx].key, key) == 0)
        {
            return &ht->entries[hash_idx].value;
        }
        hash_idx = (hash_idx + 1) % ht->capacity;

        if (hash_idx == start)
            break;
    }
    return NULL;
}

void ht_free(HashTable *ht)
{

    for (int i = 0; i < ht->capacity; i++)
    {
        free(ht->entries[i].key);
    }
    free(ht->entries);
    free(ht);
}