/*
 * xPIC_Loader.h
 */

#ifndef XPIC_LOADER_H_
#define XPIC_LOADER_H_

#include <stdint.h>

#ifndef __RCX__
// NETX10
#ifdef __NETX10

typedef struct NX10_XPIC_AREA_Ttag
{
  volatile unsigned long aulXpic_r[8];
  volatile unsigned long aulXpic_usr[5];
  volatile unsigned long  ulXpic_pc;
  volatile unsigned long  ulXpic_stat;
  volatile unsigned long  ulXpic_zero;
  volatile unsigned long aulReserved0[4080];
  volatile unsigned long  ulXpic_pram_start;
  volatile unsigned long aulReserved1[2047];
  volatile unsigned long  ulXpic_dram_start;
} NX10_XPIC_AREA_T;

typedef struct NX10_XPIC_DEBUG_AREA_Ttag
{
  volatile unsigned long  ulXpic_hold_pc;
  struct
  {
    volatile unsigned long  ulAddr;
    volatile unsigned long  ulAddr_mask;
    volatile unsigned long  ulData;
    volatile unsigned long  ulData_mask;
    volatile unsigned long  ulContr;
    volatile unsigned long  ulContr_mask;
  } asXpic_break[2];
  volatile unsigned long  ulXpic_break_last_pc;
  volatile unsigned long  ulXpic_break_status;
  volatile unsigned long  ulXpic_break_irq_raw;
  volatile unsigned long  ulXpic_break_irq_masked;
  volatile unsigned long  ulXpic_break_irq_msk_set;
  volatile unsigned long  ulXpic_break_irq_msk_reset;
  volatile unsigned long  ulXpic_break_own_irq_masked;
  volatile unsigned long  ulXpic_break_own_irq_msk_set;
  volatile unsigned long  ulXpic_break_own_irq_msk_reset;
  volatile unsigned long  ulXpic_break_return_fiq_pc;
  volatile unsigned long  ulXpic_break_return_irq_pc;
} NX10_XPIC_DEBUG_AREA_T;

#define Addr_NX10_xpic                                  0x10188000U
#define Addr_NX10_xpic_debug                            0x10188100U
#define MSK_NX10_xpic_hold_pc_hold                      0x00000001U
#define MSK_NX10_xpic_break_irq_raw_break0_irq          0x00000001U
#define MSK_NX10_xpic_break_irq_raw_break1_irq          0x00000002U
#define MSK_NX10_xpic_break_irq_raw_soft_break_irq      0x00000004U
#define MSK_NX10_xpic_break_irq_raw_single_step_irq     0x00000008U
#define MSK_NX10_xpic_break_irq_raw_misalignment_irq    0x00000010U
#define MSK_NX10_xpic_hold_pc_reset_xpic            	0x00000080U
#define MSK_NX10_xpic_break_status_xpic_reset_status    0x00000200U
#define MSK_NX10_xpic_hold_pc_bank_control              0x00000040U
#define MSK_NX10_xpic_hold_pc_bank_select               0x00000020U
#define MSK_NX10_xpic_hold_pc_single_step               0x00000002U


#endif // END NETX10

// NETX51
#ifdef __NETX51

typedef struct NX51_XPIC_AREA_Ttag
{
  volatile unsigned long aulXpic_r[8];
  volatile unsigned long aulXpic_usr[5];
  volatile unsigned long  ulXpic_pc;
  volatile unsigned long  ulXpic_stat;
  volatile unsigned long  ulXpic_zero;
} NX51_XPIC_AREA_T;

typedef struct NX51_XPIC_DEBUG_AREA_Ttag
{
  volatile unsigned long  ulXpic_hold_pc;
  struct
  {
    volatile unsigned long  ulAddr;
    volatile unsigned long  ulAddr_mask;
    volatile unsigned long  ulData;
    volatile unsigned long  ulData_mask;
    volatile unsigned long  ulContr;
    volatile unsigned long  ulContr_mask;
  } asXpic_break[2];
  volatile unsigned long  ulXpic_break_last_pc;
  volatile unsigned long  ulXpic_break_status;
  volatile unsigned long  ulXpic_break_irq_raw;
  volatile unsigned long  ulXpic_break_irq_masked;
  volatile unsigned long  ulXpic_break_irq_msk_set;
  volatile unsigned long  ulXpic_break_irq_msk_reset;
  volatile unsigned long  ulXpic_break_own_irq_masked;
  volatile unsigned long  ulXpic_break_own_irq_msk_set;
  volatile unsigned long  ulXpic_break_own_irq_msk_reset;
  volatile unsigned long  ulXpic_break_return_fiq_pc;
  volatile unsigned long  ulXpic_break_return_irq_pc;
  volatile unsigned long  ulXpic_irq_status;
} NX51_XPIC_DEBUG_AREA_T;

#define Addr_NX51_xpic_regs                             0x1018C400U
#define Addr_NX51_xpic_debug                            0x1018C480U
#define MSK_NX51_xpic_hold_pc_hold						0x00000001U
#define MSK_NX51_xpic_break_irq_raw_break0_irq          0x00000001U
#define MSK_NX51_xpic_break_irq_raw_break1_irq          0x00000002U
#define MSK_NX51_xpic_break_irq_raw_soft_break_irq      0x00000004U
#define MSK_NX51_xpic_break_irq_raw_single_step_irq     0x00000008U
#define MSK_NX51_xpic_break_irq_raw_misalignment_irq    0x00000010U
#define MSK_NX51_xpic_hold_pc_reset_xpic                0x00000080U
#define MSK_NX51_xpic_break_status_xpic_reset_status    0x00000200U
#define MSK_NX51_xpic_hold_pc_bank_control              0x00000040U
#define MSK_NX51_xpic_hold_pc_bank_select               0x00000020U
#define MSK_NX51_xpic_hold_pc_single_step               0x00000002U

#endif // END NETX51

#endif // __RCX__

/* END */

void xPIC_start();

void xPIC_init_registers(uint32_t ulExecuteAddress, uint32_t ulStackPointer);
void xPIC_start_single_step(uint32_t ulExecuteAddress, uint32_t ulStackPointer);
void xPIC_load(void);
void xPIC_reset(void);


#endif /* XPIC_LOADER_H_ */
