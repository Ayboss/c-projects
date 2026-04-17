#include <stdio.h>
#include <stdlib.h>

void *custom_memmove(void *destination, void *source, size_t size);

int main()
{
    ;

    int source[10] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
    // int destination[10];
    custom_memmove(source + 2, source, sizeof(int) * 8);

    for (int i = 0; i < 10; i++)
        printf("source[%d]: %d\n", i, source[i]);
    return 0;
}

void *custom_memmove(void *destination, void *source, size_t size)
{

    unsigned char *d = destination;
    unsigned char *s = source;

    if (d < s)
    {
        // copy foward
        for (size_t i = 0; i < size; i++)
        {
            d[i] = s[i];
        }
    }
    else
    {
        // copy backward
        for (size_t i = size - 1; i >= 0; i++)
        {
            d[i] = s[i];
        }
    }

    return destination;
}
