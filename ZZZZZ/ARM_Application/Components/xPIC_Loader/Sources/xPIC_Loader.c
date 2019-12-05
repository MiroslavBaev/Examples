/**************************************************************************************

Copyright (c) Hilscher Gesellschaft fuer Systemautomation mbH. All Rights Reserved.

**************************************************************************************/

#define __XPIC_LOADER_C


/*************************************************************************************/
/* Includes */
#include "xPIC_Loader.h"


/*************************************************************************************/
/* Definitions */
#define PPCAT_NX(A, B) A ## B
#define PPCAT(A, B) PPCAT_NX(A, B)

#define PPCAT_NX3(A, B, C) A ## B ## C
#define PPCAT3(A, B, C) PPCAT_NX3(A, B, C)


#if defined(__NETX10)
	#define _CHIP_SIG  NX10
	#define Addr_xpic_regs Addr_NX10_xpic
#elif defined(__NETX51)
	#define _CHIP_SIG  NX51
	#define Addr_xpic_regs Addr_NX51_xpic_regs
#endif

#define XPIC_AREA_T 			PPCAT(_CHIP_SIG, _XPIC_AREA_T)
#define XPIC_DEBUG_AREA_T 		PPCAT(_CHIP_SIG, _XPIC_DEBUG_AREA_T)

#define Addr_xpic_debug 		PPCAT3(Addr_, _CHIP_SIG, _xpic_debug)

#define MSK_xpic_hold_pc_hold	PPCAT3(MSK_, _CHIP_SIG, _xpic_hold_pc_hold)

#define MSK_xpic_break_irq_raw_break0_irq			PPCAT3(MSK_, _CHIP_SIG, _xpic_break_irq_raw_break0_irq)
#define MSK_xpic_break_irq_raw_break1_irq			PPCAT3(MSK_, _CHIP_SIG, _xpic_break_irq_raw_break1_irq)
#define MSK_xpic_break_irq_raw_soft_break_irq		PPCAT3(MSK_, _CHIP_SIG, _xpic_break_irq_raw_soft_break_irq)
#define MSK_xpic_break_irq_raw_single_step_irq		PPCAT3(MSK_, _CHIP_SIG, _xpic_break_irq_raw_single_step_irq)
#define MSK_xpic_break_irq_raw_misalignment_irq		PPCAT3(MSK_, _CHIP_SIG, _xpic_break_irq_raw_misalignment_irq)

#define MSK_xpic_hold_pc_hold						PPCAT3(MSK_, _CHIP_SIG, _xpic_hold_pc_hold)
#define MSK_xpic_hold_pc_bank_control				PPCAT3(MSK_, _CHIP_SIG, _xpic_hold_pc_bank_control)
#define MSK_xpic_hold_pc_bank_select				PPCAT3(MSK_, _CHIP_SIG, _xpic_hold_pc_bank_select)
#define MSK_xpic_hold_pc_reset_xpic					PPCAT3(MSK_, _CHIP_SIG, _xpic_hold_pc_reset_xpic)

#define MSK_xpic_break_status_xpic_reset_status		PPCAT3(MSK_, _CHIP_SIG, _xpic_break_status_xpic_reset_status)

#define MSK_xpic_hold_pc_single_step				PPCAT3(MSK_, _CHIP_SIG, _xpic_hold_pc_single_step)
#define MSK_xpic_break_irq_raw_single_step_irq		PPCAT3(MSK_, _CHIP_SIG, _xpic_break_irq_raw_single_step_irq)

#define Addr_xpic_pram PPCAT3(Addr_, _CHIP_SIG, _xpic_pram)
#define Addr_xpic_dram PPCAT3(Addr_, _CHIP_SIG, _xpic_dram)


extern uint32_t _binary_text_local_bin_start[];
extern uint32_t _binary_text_local_bin_end[];
extern uint32_t _binary_data_local_bin_start[];
extern uint32_t _binary_data_local_bin_end[];
extern uint32_t _binary_text_bin_start[];
extern uint32_t _binary_text_bin_end[];

extern uint32_t _binary_loader_data_bin_start[];
extern uint32_t _binary_loader_data_bin_end[];


/**
 *
 */
typedef struct XPIC_LOADER_DATA_Ttag
{
	uint32_t ulStructVersion;
	uint32_t ulEntryPointAddr;
	uint32_t ulStackTopStdAddr;
	uint32_t ulStackTopFiqAddr;
	uint32_t ulTextLocalLoadAddr;
	uint32_t ulDataLocalLoadAddr;
	uint32_t ulTextLoadAddr;
} XPIC_LOADER_DATA_T;



/*************************************************************************************/
/* Functions */


/**
 *
 */
void xPIC_reset(void)
{
  XPIC_AREA_T* ptXpicArea = (XPIC_AREA_T*)Addr_xpic_regs;
  XPIC_DEBUG_AREA_T* ptXpicDebugArea = (XPIC_DEBUG_AREA_T*)Addr_xpic_debug;

  uint32_t ulValue;
  volatile uint32_t *pulCnt;
  volatile uint32_t *pulEnd;

  /* hold xPIC */
  ptXpicDebugArea->ulXpic_hold_pc = MSK_xpic_hold_pc_hold;

  /* clear all hold reasons */
  ulValue  = MSK_xpic_break_irq_raw_break0_irq;
  ulValue |= MSK_xpic_break_irq_raw_break1_irq;
  ulValue |= MSK_xpic_break_irq_raw_soft_break_irq;
  ulValue |= MSK_xpic_break_irq_raw_single_step_irq;
  ulValue |= MSK_xpic_break_irq_raw_misalignment_irq;
  ptXpicDebugArea->ulXpic_break_irq_raw = ulValue;

  /* hold xPIC and request reset */
  ulValue  = MSK_xpic_hold_pc_hold;
  ulValue |= MSK_xpic_hold_pc_reset_xpic;
  ptXpicDebugArea->ulXpic_hold_pc = ulValue;

  /* wait for reset to be finished */
  do
  {
    ulValue  = ptXpicDebugArea->ulXpic_break_status;
    ulValue &= MSK_xpic_break_status_xpic_reset_status;
  } while( ulValue==0 );

  /* Release reset request, engage bank control, select bank 1 */
  ulValue  = MSK_xpic_hold_pc_hold;
  ulValue |= MSK_xpic_hold_pc_bank_control;
  ulValue |= MSK_xpic_hold_pc_bank_select;
  ptXpicDebugArea->ulXpic_hold_pc = ulValue;

  /* Reset the xPIC user registers. */
  pulCnt = ptXpicArea->aulXpic_usr;
  pulEnd = ptXpicArea->aulXpic_usr + (sizeof(ptXpicArea->aulXpic_usr)/sizeof(ptXpicArea->aulXpic_usr[0]));

  while (pulCnt < pulEnd)
  {
    *(pulCnt++) = 0;
  }

  /* Reset xPIC work registers (bank 1). */
  pulCnt = ptXpicArea->aulXpic_r;
  pulEnd = ptXpicArea->aulXpic_r + (sizeof(ptXpicArea->aulXpic_r)/sizeof(ptXpicArea->aulXpic_r[0]));

  while (pulCnt < pulEnd)
  {
    *(pulCnt++) = 0;
  }

  /* Select bank 0. */
  ulValue  = MSK_xpic_hold_pc_hold;
  ulValue |= MSK_xpic_hold_pc_bank_control;
  ptXpicDebugArea->ulXpic_hold_pc = ulValue;

  /* Reset xPIC work registers (bank 0). */
  pulCnt = ptXpicArea->aulXpic_r;
  pulEnd = ptXpicArea->aulXpic_r + (sizeof(ptXpicArea->aulXpic_r)/sizeof(ptXpicArea->aulXpic_r[0]));

  while (pulCnt < pulEnd)
  {
    *(pulCnt++) = 0;
  }

  /* Release bank control. */
  ptXpicDebugArea->ulXpic_hold_pc = MSK_xpic_hold_pc_hold;
}


/**
 *
 */
void xPIC_load(void)
{
  XPIC_DEBUG_AREA_T* ptXpicDebugArea = (XPIC_DEBUG_AREA_T*)Addr_xpic_debug;
  XPIC_LOADER_DATA_T* loaderData = (XPIC_LOADER_DATA_T*)_binary_loader_data_bin_start;

  /* hold xPIC */
  ptXpicDebugArea->ulXpic_hold_pc = MSK_xpic_hold_pc_hold;

  uint32_t *pulSrcCnt;
  uint32_t *pulSrcEnd;
  uint32_t *pulDstCnt;


  /* Copy the text local part. */
  pulSrcCnt = _binary_text_local_bin_start;
  pulSrcEnd = _binary_text_local_bin_end;
  pulDstCnt = (uint32_t*)loaderData->ulTextLocalLoadAddr;

  while (pulSrcCnt < pulSrcEnd)
  {
	*(pulDstCnt++) = *(pulSrcCnt++);
  }

  /* Copy the data local part. */
  pulSrcCnt = _binary_data_local_bin_start;
  pulSrcEnd = _binary_data_local_bin_end;
  pulDstCnt = (uint32_t*)loaderData->ulDataLocalLoadAddr;

  while (pulSrcCnt < pulSrcEnd)
  {
    *(pulDstCnt++) = *(pulSrcCnt++);
  }

  /* Copy the text part. */
  pulSrcCnt = _binary_text_bin_start;
  pulSrcEnd = _binary_text_bin_end;
  pulDstCnt = (uint32_t*)loaderData->ulTextLoadAddr;

  while (pulSrcCnt < pulSrcEnd)
  {
    *(pulDstCnt++) = *(pulSrcCnt++);
  }
}


/**
 *
 */
void xPIC_start_single_step(uint32_t ulExecuteAddress, uint32_t ulStackPointer)
{
  XPIC_DEBUG_AREA_T* ptXpicDebugArea = (XPIC_DEBUG_AREA_T*)Addr_xpic_debug;
  uint32_t ulValue;

  xPIC_init_registers(ulExecuteAddress, ulStackPointer);

  ulValue  = MSK_xpic_hold_pc_single_step;
  ptXpicDebugArea->ulXpic_hold_pc = ulValue;

  while(1)
  {
    do
    {
      ulValue  = ptXpicDebugArea->ulXpic_break_irq_raw;
      ulValue &= MSK_xpic_break_irq_raw_single_step_irq;
    } while (ulValue == 0);

    ulValue = MSK_xpic_break_irq_raw_single_step_irq;
    ptXpicDebugArea->ulXpic_break_irq_raw = ulValue;
  }
}


/**
 *
 */
void xPIC_init_registers(uint32_t ulExecuteAddress, uint32_t ulStackPointer)
{
  XPIC_AREA_T* ptXpicArea = (XPIC_AREA_T*)Addr_xpic_regs;
  uint32_t ulValue;


  /* Set the stack pointer to something similar to the ROM code.
   * The stack pointer is located in R7.
   */
  ulValue = ulStackPointer;
  ptXpicArea->aulXpic_r[7] = ulValue;

  /* The execute address is the real start of the code. It is the
   * of the first instruction. The PC register must be set to the
   * DWORD before the first instruction.
   *
   * Examples:
   *  1) The first instruction is at 0x08008000.
   *     -> Set the PC register to 0x08007ffc.
   *
   *  2) The first instruction is at 0x00000000.
   *     -> Set the PC register to 0xfffffffc.
   */
  ulValue = ulExecuteAddress - 4U;
  ptXpicArea->ulXpic_pc = ulValue;
}


/**
 *
 */
void xPIC_start()
{
  xPIC_reset();
  xPIC_load();

  XPIC_DEBUG_AREA_T* ptXpicDebugArea = (XPIC_DEBUG_AREA_T*)Addr_xpic_debug;
  XPIC_LOADER_DATA_T* loaderData = (XPIC_LOADER_DATA_T*)_binary_loader_data_bin_start;

  xPIC_init_registers(loaderData->ulEntryPointAddr, loaderData->ulStackTopStdAddr);
  ptXpicDebugArea->ulXpic_hold_pc = 0;
}


