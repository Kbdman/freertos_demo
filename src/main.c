#include "FreeRTOS.h"
#include "task.h"
void main()
{
    vTaskStartScheduler();
    for (;;)
    {
    }
}

void *reset_vector[2] __attribute__((section(".isr"))) = {(void *)0x2001FFFF, (void *)(&main)};