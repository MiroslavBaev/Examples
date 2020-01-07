/******************************************************************************

  Copyright (C) 2010 [Hilscher Gesellschaft für Systemautomation mbH]

  This program can be used by everyone according to the netX Open Source
  Software license. The license agreement can be downloaded from
  http://www.industrialNETworX.com

*******************************************************************************

  Last Modification:
    @version $Id: rX_StatusCodes.h 903 2012-05-02 12:09:19Z MichaelT $

  Description:
    Return Codes of RX-Functions

  Changes:
    Date        Author        Description
  ---------------------------------------------------------------------------
    2010-03-23  NC            File created.

******************************************************************************/


#ifndef __RX_STATUSCODES_H
#define __RX_STATUSCODES_H

  /*
  ***************************************************************
  *  Common Error codes or Status information reported by RX    *
  ***************************************************************
  */

  enum RX_STATUSCODEtag {
    RX_STA_RESET                      = 0xF0,
    RX_STA_SELF_TEST                  = 0xEF,
    RX_STA_RAM_TEST                   = 0xEE,
    RX_STA_FAULT_INIT                 = 0xED,
    RX_STA_DEVICE_INIT                = 0xEC,
    RX_STA_MAILBOX_INIT               = 0xEB,
    RX_STA_SERIAL_INIT                = 0xEA,
    RX_STA_SEMAPHORE_INIT             = 0xE9,
    RX_STA_QUEUE_INIT                 = 0xE8,
    RX_STA_MUTEX_INIT                 = 0xE7,
    RX_STA_EVENT_INIT                 = 0xE6,
    RX_STA_SIGNAL_INIT                = 0xE5,
    RX_STA_TIMER_INIT                 = 0xE4,
    RX_STA_BARRIER_INIT               = 0xE3,
    RX_STA_DIAGNOSTIC_INIT            = 0xE2,
    RX_STA_FINITE_STATE_INIT          = 0xE1,
    RX_STA_DRV_INTERRUPT_INIT         = 0xE0,
    RX_STA_DRV_LED_INIT               = 0xDF,
    RX_STA_DRV_TIMER_INIT             = 0xDE,
    RX_STA_DRV_PAR_FLASH_INIT         = 0xDD,
    RX_STA_DRV_XC_INIT                = 0xDC,
    RX_STA_DRV_PHY_INIT               = 0xDB,
    RX_STA_DRV_UART_INIT              = 0xDA,
    RX_STA_DRV_VOL_INIT               = 0xD9,
    RX_STA_DRV_EDD_INIT               = 0xD8,
    RX_STA_DRV_ICM_INIT               = 0xD7,
    RX_STA_DRV_USB_INIT               = 0xD6,
    RX_STA_DRV_FIFO_INIT              = 0xD5,
    RX_STA_DRV_EBUS_INIT              = 0xD4,
    RX_STA_DRV_MMU_INIT               = 0xD3,
    RX_STA_DRV_TCM_INIT               = 0xD2,
    RX_STA_DRV_CCH_INIT               = 0xD1,
    RX_STA_MID_SYS_INIT               = 0xD0,
    RX_STA_MID_DBM_INIT               = 0xCF,
    RX_STA_DRV_HIF_INIT               = 0xCE,
    RX_STA_DRV_HIFPIO_INIT            = 0xCD,
    RX_STA_DRV_SPI_INIT               = 0xCC,
    RX_STA_DRV_FIQ_INIT               = 0xCB,
    RX_STA_DRV_SEC_INIT               = 0xCA,
    RX_STA_CRC_INIT                   = 0xC9,
    RX_STA_MEMORY_INIT                = 0xC8,
    RX_STA_DRV_SER_FLASH_INIT         = 0xC7,
    RX_STA_TASKS_INIT                 = 0xC6,
    RX_STA_MID_STA_INIT               = 0xC5,
    RX_STA_MULTITASK_INIT             = 0xC4,
    RX_STA_IDLE_TASK_INIT             = 0xC3,
    RX_STA_DRV_GPIO_INIT              = 0xC2,
    RX_STA_DRV_PIO_INIT               = 0xC1,
    RX_STA_SCHED_INIT                 = 0xC0,

    RX_STA_SYSTEMSTART                = 0xAA, /*!< System start is pending/running */

    RX_STA_HAL_UNDEFINED_INSTR        = 0x7F,
    RX_STA_HAL_SWI                    = 0x7E,
    RX_STA_HAL_DATA_ABORT             = 0x7D,
    RX_STA_HAL_PREFETCH_ABORT         = 0x7C,
    RS_STA_SCHEDULER_FAIL             = 0x7B,

    RX_STA_SELF_TEST_ERROR            = 0x6F,
    RX_STA_RAM_TEST_ERROR             = 0x6E,
    RX_STA_FAULT_INIT_ERROR           = 0x6D,
    RX_STA_DEVICE_INIT_ERROR          = 0x6C,
    RX_STA_MAILBOX_INIT_ERROR         = 0x6B,
    RX_STA_SERIAL_INIT_ERROR          = 0x6A,
    RX_STA_SEMAPHORE_INIT_ERROR       = 0x69,
    RX_STA_QUEUE_INIT_ERROR           = 0x68,
    RX_STA_MUTEX_INIT_ERROR           = 0x67,
    RX_STA_EVENT_INIT_ERROR           = 0x66,
    RX_STA_SIGNAL_INIT_ERROR          = 0x65,
    RX_STA_TIMER_INIT_ERROR           = 0x64,
    RX_STA_BARRIER_INIT_ERROR         = 0x63,
    RX_STA_DIAGNOSTIC_INIT_ERROR      = 0x62,
    RX_STA_FINITE_STATE_INIT_ERROR    = 0x61,
    RX_STA_DRV_INTERRUPT_INIT_ERROR   = 0x60,
    RX_STA_DRV_LED_INIT_ERROR         = 0x5F,
    RX_STA_DRV_TIMER_INIT_ERROR       = 0x5E,
    RX_STA_DRV_PAR_FLASH_INIT_ERROR   = 0x5D,
    RX_STA_DRV_XC_INIT_ERROR          = 0x5C,
    RX_STA_DRV_PHY_INIT_ERROR         = 0x5B,
    RX_STA_DRV_UART_INIT_ERROR        = 0x5A,
    RX_STA_DRV_VOL_INIT_ERROR         = 0x59,
    RX_STA_DRV_EDD_INIT_ERROR         = 0x58,
    RX_STA_DRV_ICM_INIT_ERROR         = 0x57,
    RX_STA_DRV_USB_INIT_ERROR         = 0x56,
    RX_STA_DRV_FIFO_INIT_ERROR        = 0x55,
    RX_STA_DRV_EBUS_INIT_ERROR        = 0x54,
    RX_STA_DRV_MMU_INIT_ERROR         = 0x53,
    RX_STA_DRV_TCM_INIT_ERROR         = 0x52,
    RX_STA_DRV_CCH_INIT_ERROR         = 0x51,
    RX_STA_MID_SYS_INIT_ERROR         = 0x50,
    RX_STA_MID_DBM_INIT_ERROR         = 0x4F,
    RX_STA_DRV_HIF_INIT_ERROR         = 0x4E,
    RX_STA_DRV_HIFPIO_INIT_ERROR      = 0x4D,
    RX_STA_DRV_SPI_INIT_ERROR         = 0x4C,
    RX_STA_DRV_FIQ_INIT_ERROR         = 0x4B,
    RX_STA_DRV_SEC_INIT_ERROR         = 0x4A,
    RX_STA_CRC_INIT_ERROR             = 0x49,
    RX_STA_MEMORY_INIT_ERROR          = 0x48,
    RX_STA_DRV_SER_FLASH_ERROR        = 0x47,
    RX_STA_TASKS_INIT_ERROR           = 0x46,
    RX_STA_MID_STA_INIT_ERROR         = 0x45,
    RX_STA_MULTITASK_INIT_ERROR       = 0x44,
    RX_STA_IDLE_TASK_INIT_ERROR       = 0x43,
    RX_STA_DRV_GPIO_INIT_ERROR        = 0x42,
    RX_STA_DRV_PIO_INIT_ERROR         = 0x41,
    RX_STA_SCHED_INIT_ERROR           = 0x40,

    RX_STA_START_OK                   = 0x00,

  };
  typedef int RX_STATUSCODE;

#endif
