/*******************************************************************************

   Copyright (c) Hilscher GmbH. All Rights Reserved.

 *******************************************************************************

   Filename:
    $Workfile: init_netx50.s $
   Last Modification:
    $Author: mtrensch $
    $Modtime: 14.10.08 18:10 $
    $Revision: 614 $

   Targets:
    rcX/netX50      : yes

   Description:
      netX CPU initialization for rcX assembler module

   Changes:

     Version    Date        Author   Description
     ---------------------------------------------------------------------------
      1         07.07.2011  MT       ported from rcX V2

*******************************************************************************/

/* --- Standard definitions of ARM9 PSR bits ---------------------------------*/
  .equ    CPSR_IRQ, 0xD2
  .equ    CPSR_FIQ, 0xD1
  .equ    CPSR_SVC, 0xD3
  .equ    CPSR_ABT, 0xD7
  .equ    CPSR_UND, 0xDB
  .equ    CPSR_SYS, 0xDF

  .equ    BOOTOPTION_2NDSTAGELOADER_FLASH, 7
  .equ    BOOTOPTION_2NDSTAGELOADER_RAM,   8

/*******************************************************************************
* Externals
*******************************************************************************/
  .extern main

/*******************************************************************************
* Local data. We need to place these variables in .data, even if they are
* zero-initialized. If the reside in .bss they will be reset in $LoopZI when
* BSS is zero-initialized
*******************************************************************************/
  .data
  
  .align 4
  .global g_pvFWParam
  .global ulBootOption
  .global tBootblock
g_pvFWParam:  .long 0
ulBootOption: .long 0
tBootblock:   .space 64

/*******************************************************************************
* The startup code is placed in a special section ".init_code", so it can be
* easily relocated
*******************************************************************************/
  .section .init_code, "ax"
  .arm

/*******************************************************************************
* This is the entry point of any application
*
* If it was called by the ROM loader r0 contains a pointer to the bootblock and
* r1 contains the boot medium
*******************************************************************************/
  .global start
  .type   start,function
start:
/* --- Copy ROM / 2nd Stage Loader data --------------------------------------*/
        
        /* Store tokenlist passed by 2nd stage loader */
        ldr     r3, =g_pvFWParam
        str     r2, [r3]

        /* Store boot medium passed by ROM / 2nd stage loader */
        ldr     r3, =ulBootOption
        str     r1, [r3]

        /* Store bootblock (64 bytes) in global variable tBootblock */
        mov     r4, r0
        ldr     r5, =tBootblock
        ldr     r6, =tBootblock + 64
.L_LoopBoot:
        cmp     r5, r6
        ldrlo   r3, [r4], #4
        strlo   r3, [r5], #4
        blo     .L_LoopBoot

        /* Drain write buffers */
        mcr     p15, 0, r3, c7, c10, 4

        /* set the ctrl register to ... */
        /* TBIT enable (#15 = 0) */
        /* enable ITCM (#12 = 0) */
        /* little endianess (#7 = 0) */
        /* enable buffered writes in bufferable areas (#3 = 1) */
        /* enable DTCM (#2 = 1) */
        /* disable alignment check (#1 = 0) */
        ldr     r3, =0x1f7c
        mcr     p15, 0, r3, c1, c0, 0

/* --- Initialize the different stack types  ---------------------------------*/
        msr     CPSR_c, #CPSR_FIQ
        ldr     sp, =_FIQ_STACK_TOP
        msr     CPSR_c, #CPSR_IRQ
        ldr     sp, =_IRQ_STACK_TOP
        msr     CPSR_c, #CPSR_SVC
        ldr     sp, =_SVC_STACK_TOP
        msr     CPSR_c, #CPSR_UND
        ldr     sp, =_UND_STACK_TOP
        msr     CPSR_c, #CPSR_ABT
        ldr     sp, =_ABT_STACK_TOP
        msr     CPSR_c, #CPSR_SYS
        ldr     sp, =_SYS_STACK_TOP

/* ---------------------------------------------------------------------------
*
* __RX_INIT_ENABLE_TOKENCALLBACK__ is used to enable BootTokenParsing before any
* relocation is done. The user needs to implement a function 
*
* void rXParseBootTokens(void* pvTokens, UINT32 ulBootType)
*
* which will be called if a 2nd Stage Loader has been detected
*
 --------------------------------------------------------------------------- */
#ifndef __RX_INIT_ENABLE_TOKENCALLBACK__
  /* This line ensures that this initialization source can be compiled either by
     using the prepocessor (cpp) or the assembler (as) only. */
  .ifdef __RX_INIT_ENABLE_TOKENCALLBACK__
#else
/* --- Call boottoken evaluation  --------------------------------------------*/
        /* r1 still contains boottype, so we can verify if we came from 2nd 
           Stage loader */
        cmp     r1, #BOOTOPTION_2NDSTAGELOADER_FLASH
        cmpne   r1, #BOOTOPTION_2NDSTAGELOADER_RAM
        bne     .L_InitNo2ndStageLoader
        
        /* Call boot token parsing function if available */
        ldr     r3, =rXParseBootTokens
        cmp     r3, #0
        movne   r0, r2
        blxne   r3

.L_InitNo2ndStageLoader:
#endif /* #else __RX_INIT_ENABLE_TOKENCALLBACK__ */

/* This line ensures that this initialization source can be compiled either by
   using the prepocessor (cpp) or the assembler (as) only. */
#ifndef __RX_INIT_ENABLE_TOKENCALLBACK__
  .endif /* .ifdef __RX_INIT_ENABLE_TOKENCALLBACK__ */
#endif


/* ---------------------------------------------------------------------------
*
* __RX_INIT_ENABLE_RELOCATION__ is used to enable function / data relocation.
* This can either be used to copy data from flash to RAM or to copy special 
* functions / data to faster memory
*
* For this to work the LD File needs to contain a copy dictionary 
*
 ---------------------------------------------------------------------------*/
#ifndef __RX_INIT_ENABLE_RELOCATION__
  /* This line ensures that this initialization source can be compiled either by
     using the prepocessor (cpp) or the assembler (as) only. */
  .ifdef __RX_INIT_ENABLE_RELOCATION__
#else       
/* --- Perform data relocation  ----------------------------------------------*/
        /* Start relocating sections, if necessary 
           Relocation is done via an array of a structure in the following
           format:           
            UINT32 dest
            UINT32 source
            UINT32 length
        */
        ldr     r0, =_rx_relocation_table_start
        ldr     r1, =_rx_relocation_table_end
        
.L_InitRelocation:
        cmp     r0, r1
        bge     .L_InitRelocationDone
        ldr     r2, [r0], #4  /* r2 = destination address */
        ldr     r3, [r0], #4  /* r3 = source address      */
        ldr     r4, [r0], #4  /* r4 = length              */

.L_RelocateSection:      /* Copy section */
        cmp     r4, #0
        ldrne   r5, [r3], #4
        strne   r5, [r2], #4
        subnes  r4, r4, #4
        bne     .L_RelocateSection

        b       .L_InitRelocation

.L_InitRelocationDone:
#endif /* #else __RX_INIT_ENABLE_RELOCATION__ */

/* This line ensures that this initialization source can be compiled either by
   using the prepocessor (cpp) or the assembler (as) only. */
#ifndef __RX_INIT_ENABLE_RELOCATION__
  .endif /* .ifdef __RX_INIT_ENABLE_RELOCATION__ */
#endif


/* --- Clear .bss section (Zero init) ----------------------------------------*/
        mov     r0, #0
        ldr     r1, =__bss_start__      /* Load start address of BSS section  */
        ldr     r2, =__bss_end__        /* Load end address of BSS section    */
.L_LoopZI:
        cmp     r1, r2
        strlo   r0, [r1], #4            /* fill .bss with zero                */
        blo     .L_LoopZI

        ldr     r0, =main
        bx      r0                      /* Jump to main entry point           */
        
/*******************************************************************************
* rcX may need to access the boot medium / bootblock, so we need to provide
* access functions
*******************************************************************************/
        .global rX_DevGetBoottype
        .type   rX_DevGetBoottype, function
rX_DevGetBoottype:
        ldr    r0, =ulBootOption
        ldr    r0, [r0]
        bx     lr

        .global rX_DevGetBootblock
        .type   rX_DevGetBootblock, function
rX_DevGetBootblock:
        ldr    r0, =tBootblock
        bx     lr

  .end
