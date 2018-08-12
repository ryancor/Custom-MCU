ENTRY(Reset_Handler)
SECTIONS
{
  . = 0x10000;
  .startup . : { startup.o(.text) }
  .text : { *(.text) }

  /* Used by the startup to initialize data */
  _sidata = LOADADDR(.data);

  /* Initialized data sections into RAM memory */
  .data : {
    . = ALIGN(4);
    _sdata = .;
    *(.data)
    *(.data*)

    . = ALIGN(4);
    _edata = .;
  }

  .bss : {
    _sbss = .;
    *(.bss COMMON)

    . = ALIGN(4);
    _ebss = .;
    __bss_end__ = _ebss;
  }

  . = ALIGN(8);
  . = . + 0x1000; /* 4kB of stack memory */
  stack_top = .;
}
