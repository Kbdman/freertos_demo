
#define STM32F407xx
#include "stdint-gcc.h"
#include "stm32f4xx.h"
#include "FreeRTOS.h"
#include "task.h"
#define ISR(x) ((void *)(&x))
extern char DataVM,
    DataVMEnd, DataStart;

extern char BSSVM, BSSVMEnd;
extern void *memcpy(void *dest, void *src, size_t n);
extern void *memset(void *s, int c, size_t n);
extern void xPortPendSVHandler(void) __attribute__((naked));
extern void xPortSysTickHandler(void);
extern void vPortSVCHandler(void) __attribute__((naked));
void initialize()
{
    memcpy(&DataVM, &DataStart, &DataVMEnd - &DataVM);
    memset(&BSSVM, 0, &BSSVMEnd - &BSSVM);
}
void DummyTask(void *pvParam)
{
    for (;;)
    {
    }
}
void main()
{
    initialize();

    xTaskCreate(&DummyTask, "DummyTask", 100, NULL, 1, NULL);
    xTaskCreate(&DummyTask, "DummyTask2", 100, NULL, 1, NULL);
    vTaskStartScheduler();
    for (;;)
    {
    }
}
void DefaultHandler(void) {};
void *reset_vector[] __attribute__((section(".isr"))) = {
    (void *)0x2001FFFF,
    (void *)(&main),
    ISR(DefaultHandler),
    ISR(DefaultHandler),
    ISR(DefaultHandler),
    ISR(DefaultHandler),
    ISR(DefaultHandler),
    ISR(DefaultHandler),
    ISR(vPortSVCHandler),
    ISR(DefaultHandler),
    ISR(DefaultHandler),
    ISR(xPortPendSVHandler),
    ISR(xPortSysTickHandler)};