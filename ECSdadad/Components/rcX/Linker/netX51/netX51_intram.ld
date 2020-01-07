/*******************************************************************************

   Copyright (c) Hilscher GmbH. All Rights Reserved.

 *******************************************************************************

   Filename:
    $Workfile: netX_sdram.ld $
   Last Modification:
    $Author: mtrensch $
    $Modtime: 14.10.08 18:10 $
    $Revision: 434 $

   Targets:
    netX10      : yes

   Description:
      GNU Linker Description file sample for internal RAM

   Changes:

     Version    Date        Author   Description
     ---------------------------------------------------------------------------
      1         07.07.2011  MT       ported from rcX V2

*******************************************************************************/

MEMORY
{
        INTRAM0_6(rwx)    : ORIGIN = 0x08000080, LENGTH = 512K - 0x80 /* Internal memory usable by ARM. Start of internal RAM is reserved for IRQ vectors */
        XC0_AREA(rwx)     : ORIGIN = 0x08080000, LENGTH = 64K
        XC1_AREA(rwx)     : ORIGIN = 0x08090000, LENGTH = 64K
}

/* Define entry point of firmware (defined in InitGnu.s) */
ENTRY(start)

_FIQ_STACK_SIZE = 256;
_IRQ_STACK_SIZE = 3K;
_ABT_STACK_SIZE = 256;
_UND_STACK_SIZE = 256;
_SVC_STACK_SIZE = 256;
_SYS_STACK_SIZE = 4K;

/* Section Definitions */
SECTIONS
{
        .stacks (NOLOAD):
        {
                . = . + _FIQ_STACK_SIZE;
                _FIQ_STACK_TOP = .;

                . = . + _IRQ_STACK_SIZE;
                _IRQ_STACK_TOP = .;

                . = . + _SVC_STACK_SIZE;
                _SVC_STACK_TOP = .;

                . = . + _UND_STACK_SIZE;
                _UND_STACK_TOP = .;

                . = . + _ABT_STACK_SIZE;
                _ABT_STACK_TOP = .;

                . = . + _SYS_STACK_SIZE;
                _SYS_STACK_TOP = .;
        } >INTRAM0_6

        /* EABI requires us to align stacks on 8 Byte boundary */
        ASSERT (!(_FIQ_STACK_TOP & 7), "EABI violation: FIQ stack not aligned to 8 byte boundary")
        ASSERT (!(_IRQ_STACK_TOP & 7), "EABI violation: IRQ stack not aligned to 8 byte boundary")
        ASSERT (!(_SVC_STACK_TOP & 7), "EABI violation: SVC stack not aligned to 8 byte boundary")
        ASSERT (!(_UND_STACK_TOP & 7), "EABI violation: UND stack not aligned to 8 byte boundary")
        ASSERT (!(_ABT_STACK_TOP & 7), "EABI violation: ABT stack not aligned to 8 byte boundary")
        ASSERT (!(_SYS_STACK_TOP & 7), "EABI violation: SYS stack not aligned to 8 byte boundary")

        /* code section */
        .sec0 :
        {
                *(.init_code)

                /* Prepare a special BootTokenParser for Firmware */
                rXParseBootTokens = DEFINED(rXParseBootTokens) ? rXParseBootTokens : 0;

                /* This section must be filled with relocation information if any */
                _rx_relocation_table_start = .;

                /* Example:
                  LONG(ADDR(_reloc));
                  LONG(LOADADDR(_reloc));
                  LONG(SIZEOF(_reloc));
                */

                _rx_relocation_table_end   = .;

                *(.text* .gnu.linkonce.t.*)
                *(.ARM.extab* .gnu.linkonce.armextab.*)
                *(.gcc_except_table)

                *(.glue_7t*) *(.glue_7*)

                /* .rodata section which is used for read-only data (constants) */
                *(.rodata* .gnu.linkonce.r.*)

                . = ALIGN(4);

                _etext = . ;
                PROVIDE (etext = .);
        } >INTRAM0_6

        .ARM.exidx :
        {
                __exidx_start = .;
                *(.ARM.exidx* .gnu.linkonce.armexidx.*)
                __exidx_end   = .;
        } >INTRAM0_6

        /* .data section which is used for initialized data */
        .data :
        {
                . = ALIGN(4) ;

                _data = . ;
                *(.data* .gnu.linkonce.d.*)

                SORT(CONSTRUCTORS)
        } >INTRAM0_6

        /* .bss section which is used for uninitialized data */
        .bss (NOLOAD) :
        {
                . = ALIGN(4) ;

                __bss_start__ = . ;

                *(.bss* .gnu.linkonce.b.*)

                /* uninitialized data, see "Using LD, the GNU linker",
                   "Section Placement":
                   Specify where in your output file to place uninitialized
                   data with this notation. *(COMMON) by itself refers to all
                   uninitialized data from all input files (so far as it is
                   not yet allocated); */
                *(COMMON*)

                /* align the end of the section to 32bit boundary */
                . = ALIGN(4);

                __bss_end__ = . ;
        } >INTRAM0_6

        . = ALIGN(4);
        _edata = . ;
        PROVIDE (edata = .);

        . = ALIGN(4);
        _end = .;
        PROVIDE (end = .);
        PROVIDE (_end = .);

        /* Define the area for global heap memory (used by malloc / free) */
        PROVIDE (_heap_start = .);
        
        /* ATTENTION: When  using RAM disc we need to adjust the start / length */
        PROVIDE (_heap_end = ORIGIN(INTRAM0_6) + LENGTH(INTRAM0_6));

        /* Stabs debugging sections.  */
        .stab          0 : { *(.stab) }
        .stabstr       0 : { *(.stabstr) }
        .stab.excl     0 : { *(.stab.excl) }
        .stab.exclstr  0 : { *(.stab.exclstr) }
        .stab.index    0 : { *(.stab.index) }
        .stab.indexstr 0 : { *(.stab.indexstr) }
        .comment       0 : { *(.comment) }
        /* DWARF debug sections.
           Symbols in the DWARF debugging sections are relative to the beginning
           of the section so we begin them at 0.  */
        /* DWARF 1 */
        .debug          0 : { *(.debug) }
        .line           0 : { *(.line) }
        /* GNU DWARF 1 extensions */
        .debug_srcinfo  0 : { *(.debug_srcinfo) }
        .debug_sfnames  0 : { *(.debug_sfnames) }
        /* DWARF 1.1 and DWARF 2 */
        .debug_aranges  0 : { *(.debug_aranges) }
        .debug_pubnames 0 : { *(.debug_pubnames) }
        /* DWARF 2 */
        .debug_info     0 : { *(.debug_info .gnu.linkonce.wi.*) }
        .debug_abbrev   0 : { *(.debug_abbrev) }
        .debug_line     0 : { *(.debug_line) }
        .debug_frame    0 : { *(.debug_frame) }
        .debug_str      0 : { *(.debug_str) }
        .debug_loc      0 : { *(.debug_loc) }
        .debug_macinfo  0 : { *(.debug_macinfo) }
        /* SGI/MIPS DWARF 2 extensions */
        .debug_weaknames 0 : { *(.debug_weaknames) }
        .debug_funcnames 0 : { *(.debug_funcnames) }
        .debug_typenames 0 : { *(.debug_typenames) }
        .debug_varnames  0 : { *(.debug_varnames) }
}
