#define STM32F407xx
#include "stdint.h"
#include "stm32f4xx.h"
#include "stdint-gcc.h"
#include "stddef.h"
uint32_t clearBit(uint32_t data, uint8_t start, uint8_t len);
uint32_t setBits(uint32_t data, uint8_t start, uint8_t len, uint8_t bits);
uint32_t strlen(const char *src);