#include "FreeRTOS.h"
#include "task.h"
#define ISR(x) ((void *)(&x))
extern char DataVM, DataVMEnd, DataStart;

extern char BSSVM, BSSVMEnd;
extern void *memcpy(void *dest, void *src, size_t n);
extern void *memset(void *s, int c, size_t n);
extern void xPortPendSVHandler(void) __attribute__((naked));
extern void xPortSysTickHandler(void);
extern void vPortSVCHandler(void) __attribute__((naked));
void main()
{
    memcpy(&DataVM, &DataStart, &DataVMEnd - &DataVM);
    memset(&BSSVM, 0, &BSSVMEnd - &BSSVM);
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