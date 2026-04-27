#include "hash_chain.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

static unsigned long hash(const char *str)
{
    unsigned long h = 5381;
    int c;

    while ((c = *str++))
        h = ((h << 5) + h) + c;

    return h;
}

ChainHashTable *cht_create(int capacity)
{

    ChainHashTable *hashtable = malloc(sizeof(ChainHashTable));
    hashtable->capacity = capacity;
    hashtable->buckets = calloc(capacity, sizeof(HashNode *));
    return hashtable;
}

void cht_insert(ChainHashTable *ht, const char *key, int value)
{
    int hash_key = hash(key) % ht->capacity;

    HashNode *curr = ht->buckets[hash_key];
    while (curr)
    {
        if (strcmp(curr->key, key) == 0)
        {
            curr->value = value;
            return;
        }
        curr = curr->next;
    }

    HashNode *node = malloc(sizeof(HashNode));
    node->value = value;
    node->key = strdup(key);
    node->next = ht->buckets[hash_key];
    ht->buckets[hash_key] = node;
}

int *cht_search(ChainHashTable *ht, const char *key)
{

    int hash_key = hash(key) % ht->capacity;

    HashNode *curr = ht->buckets[hash_key];
    while (curr)
    {
        if (strcmp(curr->key, key) == 0)
        {
            return &curr->value;
        }
        curr = curr->next;
    }
    return NULL;
}

void cht_free(ChainHashTable *ht)
{

    for (int i = 0; i < ht->capacity; i++)
    {

        HashNode *curr = ht->buckets[i];
        while (curr)
        {
            HashNode *temp = curr;
            curr = curr->next;
            free(temp->key);
            free(temp);
        }
    }
    free(ht->buckets);
    free(ht);
}