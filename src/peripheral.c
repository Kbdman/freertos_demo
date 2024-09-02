#include "gpio.h"
void setGPIOMode(GPIO_TypeDef *gpio, uint8_t port, uint8_t mode)
{
    gpio->MODER = clearBit(gpio->MODER, port * 2, 2) | (mode << (port * 2));
}
void setGPIOAF(GPIO_TypeDef *gpio, uint8_t port, uint8_t af)
{
    volatile uint32_t *AFR = &(gpio->AFR[0]);
    if (port > 7)
    {
        AFR = &(gpio->AFR[1]);
        port -= 7;
    }
    *AFR = clearBit(*AFR, port * 4, 4) | (af << (port * 4));
}
void DMAStreamSelectChannel(DMA_Stream_TypeDef *stream, uint8_t ch)
{
    if (ch > 7)
        return;
    stream->CR = clearBit(stream->CR, 0, 1);
    stream->CR = setBits(stream->CR, 25, 3, ch);
}
void DMAStreamSetDirection(DMA_Stream_TypeDef *stream, uint8_t dir)
{

    stream->CR = clearBit(stream->CR, 0, 1);
    stream->CR = setBits(stream->CR, 6, 2, dir);
}