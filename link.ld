MEMORY
{
  ROM0 (rx) : ORIGIN = 0x08000000, LENGTH = 0x00100000
  RAM0 (rwx) : ORIGIN = 0x20000000, LENGTH = 0x00020000
}
SECTIONS
{
    .isr_vector : {
            . = ALIGN(4);
      . = ALIGN(4);
      KEEP(*(.isr))
      } > ROM0
    .text : {
        *(.text)
        }

    . = 0x20000000;
    .data : ALIGN(4) {
        DataVM = .;
        *(.data)
        }
    DataStart = LOADADDR(.data);
    DataSize = SIZEOF(.data) ;
    .bss : ALIGN(4)
    {
      BSSVM = .;
      *(.bss)
    }
    BSSStart = LOADADDR(.bss);
    BSSSize = SIZEOF(.bss) ;

    .stack (NOLOAD):
    {
      . = ALIGN(8);
      __stacktop = .;
    } >RAM0
}
