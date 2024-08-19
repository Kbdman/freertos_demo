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


    .data : {
        DataVM = .;
        *(.data)
        } > RAM0 AT > ROM0
    DataStart = LOADADDR(.data);
    DataSize = SIZEOF(.data) ;
    .bss : ALIGN(4)
    {
      BSSVM = .;
      *(.bss)
    } > RAM0 AT > RAM0
    BSSStart = LOADADDR(.bss);
    BSSSize = SIZEOF(.bss) ;

    .stack (NOLOAD):
    {
      . = ALIGN(8);
      __stacktop = .;
    } >RAM0
}
