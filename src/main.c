
#define STM32F407xx
#include "stm32f4xx.h"
#include "FreeRTOS.h"
#include "task.h"
#include "log.h"
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
        log_str(pvParam);
    }
}
void main()
{

    initialize();
    init_log();

    xTaskCreate(&DummyTask, "DummyTask", 100, "This is Task1", 1, NULL);
    xTaskCreate(&DummyTask, "DummyTask2", 100, "This is Task2", 1, NULL);
    vTaskStartScheduler();
    for (;;)
    {
    }
}
uint32_t exception_id = 0;
void DefaultHandler(void) { exception_id = SCB->ICSR & SCB_ICSR_VECTACTIVE_Msk; };
void *reset_vector[] __attribute__((section(".isr"))) = {
    (void *)(0x20020000),
    (void *)(&main),
    ISR(DefaultHandler),
    ISR(DefaultHandler),
    ISR(DefaultHandler),
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
    ISR(xPortSysTickHandler),
    ISR(DefaultHandler),
    ISR(DefaultHandler),
    ISR(DefaultHandler),
    ISR(DefaultHandler),
    ISR(DefaultHandler),
    ISR(DefaultHandler),
    ISR(DefaultHandler),
    ISR(DefaultHandler),
    ISR(DefaultHandler),
    ISR(DefaultHandler),
    ISR(DefaultHandler),
    ISR(DefaultHandler),
    ISR(DefaultHandler),
    ISR(DefaultHandler),
    ISR(DefaultHandler),
    ISR(DefaultHandler),
    ISR(DefaultHandler),
    ISR(DefaultHandler),
    ISR(DefaultHandler),
    ISR(DefaultHandler),
    ISR(DefaultHandler),
    ISR(DefaultHandler),
    ISR(DefaultHandler),
    ISR(DefaultHandler),
    ISR(DefaultHandler),
    ISR(DefaultHandler),
    ISR(DefaultHandler),
    ISR(DefaultHandler),
    ISR(DefaultHandler),
    ISR(DefaultHandler),
    ISR(DefaultHandler),
    ISR(DefaultHandler),
    ISR(DefaultHandler),
    ISR(DefaultHandler),
    ISR(DefaultHandler),
    ISR(DefaultHandler),
    ISR(DefaultHandler),
    ISR(DefaultHandler),
    ISR(DefaultHandler),
    ISR(DefaultHandler),
    ISR(DefaultHandler),
    ISR(DefaultHandler),
    ISR(DefaultHandler),
    ISR(DefaultHandler),
    ISR(DefaultHandler),
    ISR(DefaultHandler),
    ISR(DefaultHandler),
    ISR(DefaultHandler),
    ISR(DefaultHandler),
    ISR(DefaultHandler),
    ISR(DefaultHandler),
    ISR(DefaultHandler),
    ISR(DefaultHandler),
    ISR(DefaultHandler),
    ISR(DefaultHandler),
    ISR(DefaultHandler),
    ISR(DefaultHandler),
    ISR(DefaultHandler),
    ISR(DefaultHandler),
    ISR(DefaultHandler),
    ISR(DefaultHandler),
    ISR(DefaultHandler),
    ISR(DefaultHandler),
    ISR(DefaultHandler),
    ISR(DefaultHandler),
    ISR(DefaultHandler),
    ISR(DefaultHandler),
    ISR(DefaultHandler),
    ISR(DefaultHandler),
    ISR(DefaultHandler),
    ISR(DMA2_Stream7_IRQHandler),
    ISR(DefaultHandler)};