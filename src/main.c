#include "FreeRTOS.h"
#include "task.h"
extern void *DataVM, *DataStart;
extern size_t DataSize;
extern void *BSSVM, *BSSStart;
extern size_t BSSSize;
extern void *memcpy(void *dest, void *src, size_t n);
extern void *memset(void *s, int c, size_t n);
void main()
{
    memcpy(DataVM, DataStart, DataSize);
    memcpy(BSSVM, BSSStart, BSSSize);
    vTaskStartScheduler();
    for (;;)
    {
    }
}

void *reset_vector[2] __attribute__((section(".isr"))) = {(void *)0x2001FFFF, (void *)(&main)};