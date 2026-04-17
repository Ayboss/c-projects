#include <stdio.h>
#include <stdlib.h>

void *custom_memcpy(void *destination, void *source, size_t size);

int main()
{
    char s[] = "abcdefghijklmnopqrstuvwxyz";
    char d[27];
    custom_memcpy(d, s, sizeof(char) * 27);

    printf("s: %s \n", s);
    printf("d: %s \n", d);

    char e[10];
    custom_memcpy(e, s + 8, sizeof(char) * 9);
    e[9] = '\0';
    printf("e: %s \n", e);
    return 0;
}

void *custom_memcpy(void *destination, void *source, size_t size)
{

    unsigned char *d = destination;
    unsigned char *s = source;

    for (size_t i = 0; i < size; i++)
    {
        d[i] = s[i];
    }
    return destination;
}