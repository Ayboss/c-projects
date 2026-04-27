#include <stdio.h>
#include "vector.h"

int main(void)
{
    Vector *vec = vector_create();

    for (int i = 0; i < 10; i++)
    {
        vector_push_back(vec, i * 10);
    }

    vector_print(vec);

    printf("Element at index 3: %d\n", vector_get(vec, 3));

    vector_set(vec, 3, 999);

    vector_print(vec);

    vector_pop_back(vec);

    vector_print(vec);

    vector_free(vec);

    return 0;
}