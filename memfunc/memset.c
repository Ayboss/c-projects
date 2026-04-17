#include <stdlib.h>
#include <stdio.h>

void *custom_memset(void *destination, int value, size_t size);

int main()
{

    char buffer[10];

    custom_memset(buffer, 'a', sizeof(char) * 5);
    custom_memset(buffer + 5, 'b', sizeof(char) * 5);

    for (int i = 0; i < 10; i++)
        printf("%c", buffer[i]);
    printf("\n");
    return 0;
}

void *custom_memset(void *destination, int value, size_t size)
{

    unsigned char *d = destination;
    for (size_t i = 0; i < size; i++)
    {
        d[i] = (unsigned char)value;
    }
    return destination;
}