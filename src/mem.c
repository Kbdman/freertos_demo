#include "stdint.h"
#include "stddef.h"
void *memcpy(void *dest, void *src, size_t n)
{
    for (size_t i = 0; i < n; i++)
    {
        ((char *)(dest))[i] = ((char *)(src))[i];
    }
    return dest;
}
void *memset(void *s, int c, size_t n)
{
    char da = c;
    for (size_t i = 0; i < n; i++)
    {
        ((char *)(s))[i] = da;
    }
    return s;
}