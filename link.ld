SECTIONS
{
    . = 0x08000000;
    .isr_vector : {*(.isr)}
    .text : {
        *(.text)
        }
    .data :
        {
          *(.data)
        }
}