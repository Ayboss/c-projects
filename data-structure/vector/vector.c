#include <stdio.h>
#include <stdlib.h>
#include "vector.h"

#define INITIAL_CAPACITY 4

static void vector_resize(Vector *vec, size_t new_capacity)
{
    int *newdata = realloc(vec->data, new_capacity * sizeof(int));
    if (!newdata)
    {
        return;
    }
    vec->data = newdata;
    vec->capacity = new_capacity;
}

Vector *vector_create(void)
{

    Vector *vector = malloc(sizeof(Vector));
    if (!vector)
    {
        return NULL;
    }

    vector->data = malloc(INITIAL_CAPACITY * sizeof(int));
    if (!vector->data)
    {
        free(vector);
        return NULL;
    }
    vector->capacity = INITIAL_CAPACITY;
    vector->size = 0;
    return vector;
}

void vector_push_back(Vector *vec, int value)
{

    if (vec->size == vec->capacity)
    {
        vector_resize(vec, vec->capacity * 2);
    }
    vec->data[vec->size] = value;
    vec->size++;
}

int vector_get(Vector *vec, size_t index)
{

    if (index >= vec->size)
    {
        fprintf(stderr, "Index out of bounds \n");
        exit(EXIT_FAILURE);
    }
    return vec->data[index];
}

void vector_set(Vector *vec, size_t index, int value)
{
    if (index >= vec->size)
    {
        fprintf(stderr, "Index out of bounds \n");
        exit(EXIT_FAILURE);
    }

    vec->data[index] = value;
}

void vector_pop_back(Vector *vec)
{
    if (vec->size > 0)
        vec->size--;
}

void vector_print(Vector *vec)
{

    for (size_t i = 0; i < vec->size; i++)
    {
        printf("index %zu : %d \n", i, vec->data[i]);
    }
}

void vector_free(Vector *vec)
{
    free(vec->data);
    free(vec);
}