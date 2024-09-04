
#include "log.h"
#include "peripheral.h"

char buf[512] = {};
uint32_t buflen = 0;
int count = 0;
void init_log()
{
    RCC->APB2ENR |= RCC_APB2ENR_USART1EN;
    RCC->AHB1ENR |= RCC_AHB1ENR_GPIOBEN;
    setGPIOMode(GPIOB, 6, 0b10);
    setGPIOMode(GPIOB, 7, 0b10);
    setGPIOAF(GPIOB, 6, 0x7);
    setGPIOAF(GPIOB, 7, 0x7);
    USART1->BRR = 0x8B;
    USART1->CR3 |= (1 << 7); // Enable DMA mode
    //  ENABLE USART ,transmitter,interuption for TXE
    USART1->CR1 |= USART_CR1_TXEIE | USART_CR1_UE | USART_CR1_TE;
    RCC->AHB1ENR |= RCC_AHB1ENR_DMA2EN;      // Enable DMA2
    DMAStreamSelectChannel(DMA2_Stream7, 4); // select channel
    DMAStreamSetDirection(DMA2_Stream7, 1);  // set direction "Memory-to-peripheral"

    DMA2_Stream7->CR = setBits(DMA2_Stream7->CR, 10, 1, 1); // Src Memory Address increases
    DMA2_Stream7->CR = setBits(DMA2_Stream7->CR, 9, 1, 0);  // dest Memory Address increases
    DMA2_Stream7->CR = setBits(DMA2_Stream7->CR, 13, 2, 0); // Src Memory Address increases by byte
    DMA2_Stream7->CR = setBits(DMA2_Stream7->CR, 4, 1, 1);  // enable interrupt for transfer complete
    NVIC_EnableIRQ(DMA2_Stream7_IRQn);                      // enable IRQN
}
void logBuf(const char *msg, uint32_t len)
{
    if (len == 0 || msg == NULL)
        return;

    if (len > sizeof(buf) - 2)
        len = sizeof(buf) - 2;

    buflen = len + 2;
    memcpy(buf, msg, len); // copy data to send buffer
    buf[len] = '\r';
    buf[len + 1] = '\n';
    while (DMA2_Stream7->CR & 1) // wait for unfinished transfer
        ;
    DMA2_Stream7->M0AR = (uint32_t)buf;            // setup src address
    DMA2_Stream7->NDTR = buflen;                   // setup data len
    DMA2_Stream7->PAR = (uint32_t)(&(USART1->DR)); // set DR of USART1 as dest
    DMA2_Stream7->CR |= 1;                         // Start transfer
}
void log_str(const char *str)
{
    logBuf(str, strlen(str));
}

void DMA2_Stream7_IRQHandler()
{

    if (DMA2->HISR & (1 << 27))
    {
        DMA2->HIFCR |= 1 << 27;
    }
    if (DMA2->HISR & (1 << 25))
    {
        count++;
        DMA2->HIFCR |= 1 << 25;
    }
}