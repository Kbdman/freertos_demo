MEMORY
{
  ROM0 (rx) : ORIGIN = 0x08000000, LENGTH = 0x00100000
  RAM0 (rwx) : ORIGIN = 0x20000000, LENGTH = 0x00020000
}
SECTIONS
{
    .isr_vector : {
      . = ALIGN(4);
      KEEP(*(.isr))
      } > ROM0

    .text : {
        *(.text)
      } > ROM0

    .data : {
        DataVM = .;
        *(.data)
        DataVMEnd = .;
      } > RAM0 AT > ROM0

    DataStart = LOADADDR(.data);


    .bss : ALIGN(4)
    {
      BSSVM = .;
      *(.bss)
      BSSVMEnd = .;
    } > RAM0 AT > RAM0

    .stack (NOLOAD):
    {
      . = ALIGN(8);
      __stacktop = .;
    } >RAM0
}
