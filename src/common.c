#include "common.h"
uint32_t clearBit(uint32_t data, uint8_t start, uint8_t len)
{
    if (start + len >= 32 || len == 0)
        return data;
    uint32_t clearbits = 1;
    for (int c = 1; c < len; c++)
    {
        clearbits = (clearbits << 1) + 1;
    }
    clearbits = clearbits << start;
    clearbits = ~clearbits;
    data &= clearbits;
    return data;
}
uint32_t setBits(uint32_t data, uint8_t start, uint8_t len, uint8_t bits)
{
    if (bits > ((1 << len) - 1))
        return data;
    data = clearBit(data, start, len) | (bits << start);
    return data;
}
uint32_t strlen(const char *src)
{
    uint32_t res = 0;
    while (src[res] != 0)
        ++res;
    return res;
}