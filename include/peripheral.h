#include "common.h"
void setGPIOMode(GPIO_TypeDef *gpio, uint8_t port, uint8_t mode);
void setGPIOAF(GPIO_TypeDef *gpio, uint8_t port, uint8_t af);
void DMAStreamSelectChannel(DMA_Stream_TypeDef *stream, uint8_t ch);
void DMAStreamSetDirection(DMA_Stream_TypeDef *stream, uint8_t dir);
