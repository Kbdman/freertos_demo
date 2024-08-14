

void main()
{
    for (;;)
    {
    }
}

void *reset_vector[2] __attribute__((section(".isr"))) = {(void *)0x2001FFFF, (void *)(&main)};