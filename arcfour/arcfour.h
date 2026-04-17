
#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>
#include <string.h>
#include <assert.h>
#include <errno.h>

// #define export __atribute__((visibility("default")))
#define MS 500
#define rc4whitewash(x, y)             \
    for (x = 0; x < MS * 1000000; x++) \
        (volatile int8) rc4byte(y);
#define rc4decrypt(p, x, y) rc4encrypt(p, x, y)
#define rc4uninit(x) free(x)
#define MY_ASSERT_PERROR(errnum)                                                                \
    do                                                                                          \
    {                                                                                           \
        if (errnum != 0)                                                                        \
        {                                                                                       \
            fprintf(stderr, "%s:%d: %s: %s\n", __FILE__, __LINE__, __func__, strerror(errnum)); \
            abort();                                                                            \
        }                                                                                       \
    } while (0)

typedef unsigned char int8;
typedef unsigned short int int16;
typedef unsigned int int32;
typedef struct s_arcfour Arcfour;
struct s_arcfour
{
    int16 i, j, k;
    int8 s[256];
};

Arcfour *rc4init(int8 *, int16);
int8 rc4byte(Arcfour *);
int8 *rc4encrypt(Arcfour *, int8 *, int16);
