#ifndef HASH_CHAIN_H
#define HASH_CHAIN_H

typedef struct HashNode
{
    char *key;
    int value;
    struct HashNode *next;
} HashNode;

typedef struct
{
    HashNode **buckets;
    int capacity;
} ChainHashTable;

ChainHashTable *cht_create(int capacity);
void cht_insert(ChainHashTable *ht, const char *key, int value);
int *cht_search(ChainHashTable *ht, const char *key);
void cht_free(ChainHashTable *ht);

#endif