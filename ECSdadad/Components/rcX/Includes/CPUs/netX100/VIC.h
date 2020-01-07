/******************************************************************************

  Copyright (C) 2010 [Hilscher Gesellschaft für Systemautomation mbH]

  This program can be used by everyone according to the netX Open Source
  Software license. The license agreement can be downloaded from
  http://www.industrialNETworX.com

*******************************************************************************

  Last Modification:
    @version $Id: VIC.h 333 2010-04-26 09:32:25Z Volker $

  Description:
    netX VIC definitions

  Changes:
    Date        Author        Description
  ---------------------------------------------------------------------------
    2010-03-24  NC            File created.

******************************************************************************/


#ifndef _VIC_H
#define _VIC_H


/*************************************************************************************/


// =====================================================================
//
// Area of vic
//
// =====================================================================

#define NETX_VIC_AREA	0x001FF000U

// ---------------------------------------------------------------------
// Register vic_irq_status
// => VIC IRQ status register
// => Mode: Mode (r)
// ---------------------------------------------------------------------

#define REL_NETX_VIC_IRQ_STAT 0x00000000U
#define NETX_VIC_IRQ_STAT     0x001FF000U

#define MSK_NETX_VIC_IRQ_STAT_sw         0x00000001U // [0]
#define SRT_NETX_VIC_IRQ_STAT_sw         0           
#define MSK_NETX_VIC_IRQ_STAT_timer0     0x00000002U // [1]
#define SRT_NETX_VIC_IRQ_STAT_timer0     1           
#define MSK_NETX_VIC_IRQ_STAT_timer1     0x00000004U // [2]
#define SRT_NETX_VIC_IRQ_STAT_timer1     2           
#define MSK_NETX_VIC_IRQ_STAT_timer2     0x00000008U // [3]
#define SRT_NETX_VIC_IRQ_STAT_timer2     3           
#define MSK_NETX_VIC_IRQ_STAT_systime_ns 0x00000010U // [4]
#define SRT_NETX_VIC_IRQ_STAT_systime_ns 4           
#define MSK_NETX_VIC_IRQ_STAT_systime_s  0x00000020U // [5]
#define SRT_NETX_VIC_IRQ_STAT_systime_s  5           
#define MSK_NETX_VIC_IRQ_STAT_gpio15     0x00000040U // [6]
#define SRT_NETX_VIC_IRQ_STAT_gpio15     6           
#define MSK_NETX_VIC_IRQ_STAT_watchdog   0x00000080U // [7]
#define SRT_NETX_VIC_IRQ_STAT_watchdog   7           
#define MSK_NETX_VIC_IRQ_STAT_uart0      0x00000100U // [8]
#define SRT_NETX_VIC_IRQ_STAT_uart0      8           
#define MSK_NETX_VIC_IRQ_STAT_uart1      0x00000200U // [9]
#define SRT_NETX_VIC_IRQ_STAT_uart1      9           
#define MSK_NETX_VIC_IRQ_STAT_uart2      0x00000400U // [10]
#define SRT_NETX_VIC_IRQ_STAT_uart2      10          
#define MSK_NETX_VIC_IRQ_STAT_usb        0x00000800U // [11]
#define SRT_NETX_VIC_IRQ_STAT_usb        11          
#define MSK_NETX_VIC_IRQ_STAT_spi        0x00001000U // [12]
#define SRT_NETX_VIC_IRQ_STAT_spi        12          
#define MSK_NETX_VIC_IRQ_STAT_i2c        0x00002000U // [13]
#define SRT_NETX_VIC_IRQ_STAT_i2c        13          
#define MSK_NETX_VIC_IRQ_STAT_lcd        0x00004000U // [14]
#define SRT_NETX_VIC_IRQ_STAT_lcd        14          
#define MSK_NETX_VIC_IRQ_STAT_hif        0x00008000U // [15]
#define SRT_NETX_VIC_IRQ_STAT_hif        15          
#define MSK_NETX_VIC_IRQ_STAT_gpio       0x00010000U // [16]
#define SRT_NETX_VIC_IRQ_STAT_gpio       16          
#define MSK_NETX_VIC_IRQ_STAT_com0       0x00020000U // [17]
#define SRT_NETX_VIC_IRQ_STAT_com0       17          
#define MSK_NETX_VIC_IRQ_STAT_com1       0x00040000U // [18]
#define SRT_NETX_VIC_IRQ_STAT_com1       18          
#define MSK_NETX_VIC_IRQ_STAT_com2       0x00080000U // [19]
#define SRT_NETX_VIC_IRQ_STAT_com2       19          
#define MSK_NETX_VIC_IRQ_STAT_com3       0x00100000U // [20]
#define SRT_NETX_VIC_IRQ_STAT_com3       20          
#define MSK_NETX_VIC_IRQ_STAT_msync0     0x00200000U // [21]
#define SRT_NETX_VIC_IRQ_STAT_msync0     21          
#define MSK_NETX_VIC_IRQ_STAT_msync1     0x00400000U // [22]
#define SRT_NETX_VIC_IRQ_STAT_msync1     22          
#define MSK_NETX_VIC_IRQ_STAT_msync2     0x00800000U // [23]
#define SRT_NETX_VIC_IRQ_STAT_msync2     23          
#define MSK_NETX_VIC_IRQ_STAT_msync3     0x01000000U // [24]
#define SRT_NETX_VIC_IRQ_STAT_msync3     24          
#define MSK_NETX_VIC_IRQ_STAT_int_phy    0x02000000U // [25]
#define SRT_NETX_VIC_IRQ_STAT_int_phy    25          
#define MSK_NETX_VIC_IRQ_STAT_iso_area   0x04000000U // [26]
#define SRT_NETX_VIC_IRQ_STAT_iso_area   26          
#define MSK_NETX_VIC_IRQ_STAT_timer3     0x20000000U // [29]
#define SRT_NETX_VIC_IRQ_STAT_timer3     29          
#define MSK_NETX_VIC_IRQ_STAT_timer4     0x40000000U // [30]
#define SRT_NETX_VIC_IRQ_STAT_timer4     30          
#define MSK_NETX_VIC_IRQ_STAT_vfp9       0x80000000U // [31]
#define SRT_NETX_VIC_IRQ_STAT_vfp9       31          

enum {
	BFW_NETX_VIC_IRQ_STAT_sw         = 1, // [0]
	BFW_NETX_VIC_IRQ_STAT_timer0     = 1, // [1]
	BFW_NETX_VIC_IRQ_STAT_timer1     = 1, // [2]
	BFW_NETX_VIC_IRQ_STAT_timer2     = 1, // [3]
	BFW_NETX_VIC_IRQ_STAT_systime_ns = 1, // [4]
	BFW_NETX_VIC_IRQ_STAT_systime_s  = 1, // [5]
	BFW_NETX_VIC_IRQ_STAT_gpio15     = 1, // [6]
	BFW_NETX_VIC_IRQ_STAT_watchdog   = 1, // [7]
	BFW_NETX_VIC_IRQ_STAT_uart0      = 1, // [8]
	BFW_NETX_VIC_IRQ_STAT_uart1      = 1, // [9]
	BFW_NETX_VIC_IRQ_STAT_uart2      = 1, // [10]
	BFW_NETX_VIC_IRQ_STAT_usb        = 1, // [11]
	BFW_NETX_VIC_IRQ_STAT_spi        = 1, // [12]
	BFW_NETX_VIC_IRQ_STAT_i2c        = 1, // [13]
	BFW_NETX_VIC_IRQ_STAT_lcd        = 1, // [14]
	BFW_NETX_VIC_IRQ_STAT_hif        = 1, // [15]
	BFW_NETX_VIC_IRQ_STAT_gpio       = 1, // [16]
	BFW_NETX_VIC_IRQ_STAT_com0       = 1, // [17]
	BFW_NETX_VIC_IRQ_STAT_com1       = 1, // [18]
	BFW_NETX_VIC_IRQ_STAT_com2       = 1, // [19]
	BFW_NETX_VIC_IRQ_STAT_com3       = 1, // [20]
	BFW_NETX_VIC_IRQ_STAT_msync0     = 1, // [21]
	BFW_NETX_VIC_IRQ_STAT_msync1     = 1, // [22]
	BFW_NETX_VIC_IRQ_STAT_msync2     = 1, // [23]
	BFW_NETX_VIC_IRQ_STAT_msync3     = 1, // [24]
	BFW_NETX_VIC_IRQ_STAT_int_phy    = 1, // [25]
	BFW_NETX_VIC_IRQ_STAT_iso_area   = 1, // [26]
	BFW_NETX_VIC_IRQ_STAT_reserved1  = 2, // [28:27]
	BFW_NETX_VIC_IRQ_STAT_timer3     = 1, // [29]
	BFW_NETX_VIC_IRQ_STAT_timer4     = 1, // [30]
	BFW_NETX_VIC_IRQ_STAT_vfp9       = 1  // [31]
};

typedef struct VIC_IRQ_STATUS_BIT_Ttag {
	unsigned int sw         : BFW_NETX_VIC_IRQ_STAT_sw;         // Reserved  for Software Interrupt, ARM standard configuration 
	unsigned int timer0     : BFW_NETX_VIC_IRQ_STAT_timer0;     // Timer0 / Counter0 from GPIO Module -> Real time operating system timer, Windows CE required 
	unsigned int timer1     : BFW_NETX_VIC_IRQ_STAT_timer1;     // Timer1 / Counter1 from GPIO Module 
	unsigned int timer2     : BFW_NETX_VIC_IRQ_STAT_timer2;     // Timer2 / Counter2 from GPIO Module 
	unsigned int systime_ns : BFW_NETX_VIC_IRQ_STAT_systime_ns; // systime ns compare irq from GPIO module 
	unsigned int systime_s  : BFW_NETX_VIC_IRQ_STAT_systime_s;  // systime 1day IRQ from SYSTIME module, Windows CE required 
	unsigned int gpio15     : BFW_NETX_VIC_IRQ_STAT_gpio15;     // external interrupt 15, Windows CE required (NMI) 
	unsigned int watchdog   : BFW_NETX_VIC_IRQ_STAT_watchdog;   // reserved 
	unsigned int uart0      : BFW_NETX_VIC_IRQ_STAT_uart0;      // UART 0 -> Diagnostic channel, Windows CE required 
	unsigned int uart1      : BFW_NETX_VIC_IRQ_STAT_uart1;      // UART 1 
	unsigned int uart2      : BFW_NETX_VIC_IRQ_STAT_uart2;      // UART 2 
	unsigned int usb        : BFW_NETX_VIC_IRQ_STAT_usb;        // USB interrupt 
	unsigned int spi        : BFW_NETX_VIC_IRQ_STAT_spi;        // SPI interrupt 
	unsigned int i2c        : BFW_NETX_VIC_IRQ_STAT_i2c;        // reserved 
	unsigned int lcd        : BFW_NETX_VIC_IRQ_STAT_lcd;        // LCD-Controller interrupt 
	unsigned int hif        : BFW_NETX_VIC_IRQ_STAT_hif;        // HIF interrupt 
	unsigned int gpio       : BFW_NETX_VIC_IRQ_STAT_gpio;       // other external Interrupts from GPIO 0-14 
	unsigned int com0       : BFW_NETX_VIC_IRQ_STAT_com0;       // Communication channel 0 (= |xpec0_irq[11:0]) 
	unsigned int com1       : BFW_NETX_VIC_IRQ_STAT_com1;       // Communication channel 1 (= |xpec1_irq[11:0]) 
	unsigned int com2       : BFW_NETX_VIC_IRQ_STAT_com2;       // Communication channel 2 (= |xpec2_irq[11:0]) 
	unsigned int com3       : BFW_NETX_VIC_IRQ_STAT_com3;       // Communication channel 3 (= |xpec3_irq[11:0]) 
	unsigned int msync0     : BFW_NETX_VIC_IRQ_STAT_msync0;     // Motion synchronization channel 0 (= |xpec0_irq[15:12]) 
	unsigned int msync1     : BFW_NETX_VIC_IRQ_STAT_msync1;     // Motion synchronization channel 1 (= |xpec1_irq[15:12]) 
	unsigned int msync2     : BFW_NETX_VIC_IRQ_STAT_msync2;     // Motion synchronization channel 2 (= |xpec2_irq[15:12]) 
	unsigned int msync3     : BFW_NETX_VIC_IRQ_STAT_msync3;     // Motion synchronization channel 3 (= |xpec3_irq[15:12]) 
	unsigned int int_phy    : BFW_NETX_VIC_IRQ_STAT_int_phy;    // Interrupt from internal Phys 
	unsigned int iso_area   : BFW_NETX_VIC_IRQ_STAT_iso_area;   // Power is going down (see RTC for details) 
	unsigned int reserved1  : BFW_NETX_VIC_IRQ_STAT_reserved1;  // reserved
	unsigned int timer3     : BFW_NETX_VIC_IRQ_STAT_timer3;     // Timer3 / Counter3 from GPIO Module 
	unsigned int timer4     : BFW_NETX_VIC_IRQ_STAT_timer4;     // Timer4 / Counter4 from GPIO Module 
	unsigned int vfp9       : BFW_NETX_VIC_IRQ_STAT_vfp9;       // reserved 
} VIC_IRQ_STATUS_BIT_T;

typedef union {
	unsigned int         val;
	VIC_IRQ_STATUS_BIT_T bf;
} VIC_IRQ_STATUS_T;

// ---------------------------------------------------------------------
// Register vic_fiq_status
// => VIC FIQ status register
// => Mode: Mode (r)
// ---------------------------------------------------------------------

#define REL_NETX_VIC_FIQ_STAT 0x00000004U
#define NETX_VIC_FIQ_STAT     0x001FF004U

#define MSK_NETX_VIC_FIQ_STAT_sw         0x00000001U // [0]
#define SRT_NETX_VIC_FIQ_STAT_sw         0           
#define MSK_NETX_VIC_FIQ_STAT_timer0     0x00000002U // [1]
#define SRT_NETX_VIC_FIQ_STAT_timer0     1           
#define MSK_NETX_VIC_FIQ_STAT_timer1     0x00000004U // [2]
#define SRT_NETX_VIC_FIQ_STAT_timer1     2           
#define MSK_NETX_VIC_FIQ_STAT_timer2     0x00000008U // [3]
#define SRT_NETX_VIC_FIQ_STAT_timer2     3           
#define MSK_NETX_VIC_FIQ_STAT_systime_ns 0x00000010U // [4]
#define SRT_NETX_VIC_FIQ_STAT_systime_ns 4           
#define MSK_NETX_VIC_FIQ_STAT_systime_s  0x00000020U // [5]
#define SRT_NETX_VIC_FIQ_STAT_systime_s  5           
#define MSK_NETX_VIC_FIQ_STAT_gpio15     0x00000040U // [6]
#define SRT_NETX_VIC_FIQ_STAT_gpio15     6           
#define MSK_NETX_VIC_FIQ_STAT_watchdog   0x00000080U // [7]
#define SRT_NETX_VIC_FIQ_STAT_watchdog   7           
#define MSK_NETX_VIC_FIQ_STAT_uart0      0x00000100U // [8]
#define SRT_NETX_VIC_FIQ_STAT_uart0      8           
#define MSK_NETX_VIC_FIQ_STAT_uart1      0x00000200U // [9]
#define SRT_NETX_VIC_FIQ_STAT_uart1      9           
#define MSK_NETX_VIC_FIQ_STAT_uart2      0x00000400U // [10]
#define SRT_NETX_VIC_FIQ_STAT_uart2      10          
#define MSK_NETX_VIC_FIQ_STAT_usb        0x00000800U // [11]
#define SRT_NETX_VIC_FIQ_STAT_usb        11          
#define MSK_NETX_VIC_FIQ_STAT_spi        0x00001000U // [12]
#define SRT_NETX_VIC_FIQ_STAT_spi        12          
#define MSK_NETX_VIC_FIQ_STAT_i2c        0x00002000U // [13]
#define SRT_NETX_VIC_FIQ_STAT_i2c        13          
#define MSK_NETX_VIC_FIQ_STAT_lcd        0x00004000U // [14]
#define SRT_NETX_VIC_FIQ_STAT_lcd        14          
#define MSK_NETX_VIC_FIQ_STAT_hif        0x00008000U // [15]
#define SRT_NETX_VIC_FIQ_STAT_hif        15          
#define MSK_NETX_VIC_FIQ_STAT_gpio       0x00010000U // [16]
#define SRT_NETX_VIC_FIQ_STAT_gpio       16          
#define MSK_NETX_VIC_FIQ_STAT_com0       0x00020000U // [17]
#define SRT_NETX_VIC_FIQ_STAT_com0       17          
#define MSK_NETX_VIC_FIQ_STAT_com1       0x00040000U // [18]
#define SRT_NETX_VIC_FIQ_STAT_com1       18          
#define MSK_NETX_VIC_FIQ_STAT_com2       0x00080000U // [19]
#define SRT_NETX_VIC_FIQ_STAT_com2       19          
#define MSK_NETX_VIC_FIQ_STAT_com3       0x00100000U // [20]
#define SRT_NETX_VIC_FIQ_STAT_com3       20          
#define MSK_NETX_VIC_FIQ_STAT_msync0     0x00200000U // [21]
#define SRT_NETX_VIC_FIQ_STAT_msync0     21          
#define MSK_NETX_VIC_FIQ_STAT_msync1     0x00400000U // [22]
#define SRT_NETX_VIC_FIQ_STAT_msync1     22          
#define MSK_NETX_VIC_FIQ_STAT_msync2     0x00800000U // [23]
#define SRT_NETX_VIC_FIQ_STAT_msync2     23          
#define MSK_NETX_VIC_FIQ_STAT_msync3     0x01000000U // [24]
#define SRT_NETX_VIC_FIQ_STAT_msync3     24          
#define MSK_NETX_VIC_FIQ_STAT_int_phy    0x02000000U // [25]
#define SRT_NETX_VIC_FIQ_STAT_int_phy    25          
#define MSK_NETX_VIC_FIQ_STAT_iso_area   0x04000000U // [26]
#define SRT_NETX_VIC_FIQ_STAT_iso_area   26          
#define MSK_NETX_VIC_FIQ_STAT_timer3     0x20000000U // [29]
#define SRT_NETX_VIC_FIQ_STAT_timer3     29          
#define MSK_NETX_VIC_FIQ_STAT_timer4     0x40000000U // [30]
#define SRT_NETX_VIC_FIQ_STAT_timer4     30          
#define MSK_NETX_VIC_FIQ_STAT_vfp9       0x80000000U // [31]
#define SRT_NETX_VIC_FIQ_STAT_vfp9       31          

enum {
	BFW_NETX_VIC_FIQ_STAT_sw         = 1, // [0]
	BFW_NETX_VIC_FIQ_STAT_timer0     = 1, // [1]
	BFW_NETX_VIC_FIQ_STAT_timer1     = 1, // [2]
	BFW_NETX_VIC_FIQ_STAT_timer2     = 1, // [3]
	BFW_NETX_VIC_FIQ_STAT_systime_ns = 1, // [4]
	BFW_NETX_VIC_FIQ_STAT_systime_s  = 1, // [5]
	BFW_NETX_VIC_FIQ_STAT_gpio15     = 1, // [6]
	BFW_NETX_VIC_FIQ_STAT_watchdog   = 1, // [7]
	BFW_NETX_VIC_FIQ_STAT_uart0      = 1, // [8]
	BFW_NETX_VIC_FIQ_STAT_uart1      = 1, // [9]
	BFW_NETX_VIC_FIQ_STAT_uart2      = 1, // [10]
	BFW_NETX_VIC_FIQ_STAT_usb        = 1, // [11]
	BFW_NETX_VIC_FIQ_STAT_spi        = 1, // [12]
	BFW_NETX_VIC_FIQ_STAT_i2c        = 1, // [13]
	BFW_NETX_VIC_FIQ_STAT_lcd        = 1, // [14]
	BFW_NETX_VIC_FIQ_STAT_hif        = 1, // [15]
	BFW_NETX_VIC_FIQ_STAT_gpio       = 1, // [16]
	BFW_NETX_VIC_FIQ_STAT_com0       = 1, // [17]
	BFW_NETX_VIC_FIQ_STAT_com1       = 1, // [18]
	BFW_NETX_VIC_FIQ_STAT_com2       = 1, // [19]
	BFW_NETX_VIC_FIQ_STAT_com3       = 1, // [20]
	BFW_NETX_VIC_FIQ_STAT_msync0     = 1, // [21]
	BFW_NETX_VIC_FIQ_STAT_msync1     = 1, // [22]
	BFW_NETX_VIC_FIQ_STAT_msync2     = 1, // [23]
	BFW_NETX_VIC_FIQ_STAT_msync3     = 1, // [24]
	BFW_NETX_VIC_FIQ_STAT_int_phy    = 1, // [25]
	BFW_NETX_VIC_FIQ_STAT_iso_area   = 1, // [26]
	BFW_NETX_VIC_FIQ_STAT_reserved1  = 2, // [28:27]
	BFW_NETX_VIC_FIQ_STAT_timer3     = 1, // [29]
	BFW_NETX_VIC_FIQ_STAT_timer4     = 1, // [30]
	BFW_NETX_VIC_FIQ_STAT_vfp9       = 1  // [31]
};

typedef struct VIC_FIQ_STATUS_BIT_Ttag {
	unsigned int sw         : BFW_NETX_VIC_FIQ_STAT_sw;         // Reserved  for Software Interrupt, ARM standard configuration 
	unsigned int timer0     : BFW_NETX_VIC_FIQ_STAT_timer0;     // Timer0 / Counter0 from GPIO Module -> Real time operating system timer, Windows CE required 
	unsigned int timer1     : BFW_NETX_VIC_FIQ_STAT_timer1;     // Timer1 / Counter1 from GPIO Module 
	unsigned int timer2     : BFW_NETX_VIC_FIQ_STAT_timer2;     // Timer2 / Counter2 from GPIO Module 
	unsigned int systime_ns : BFW_NETX_VIC_FIQ_STAT_systime_ns; // systime ns compare irq from GPIO module 
	unsigned int systime_s  : BFW_NETX_VIC_FIQ_STAT_systime_s;  // systime 1day IRQ from SYSTIME module, Windows CE required 
	unsigned int gpio15     : BFW_NETX_VIC_FIQ_STAT_gpio15;     // external interrupt 15, Windows CE required (NMI) 
	unsigned int watchdog   : BFW_NETX_VIC_FIQ_STAT_watchdog;   // reserved 
	unsigned int uart0      : BFW_NETX_VIC_FIQ_STAT_uart0;      // UART 0 -> Diagnostic channel, Windows CE required 
	unsigned int uart1      : BFW_NETX_VIC_FIQ_STAT_uart1;      // UART 1 
	unsigned int uart2      : BFW_NETX_VIC_FIQ_STAT_uart2;      // UART 2 
	unsigned int usb        : BFW_NETX_VIC_FIQ_STAT_usb;        // USB interrupt 
	unsigned int spi        : BFW_NETX_VIC_FIQ_STAT_spi;        // SPI interrupt 
	unsigned int i2c        : BFW_NETX_VIC_FIQ_STAT_i2c;        // reserved 
	unsigned int lcd        : BFW_NETX_VIC_FIQ_STAT_lcd;        // LCD-Controller interrupt 
	unsigned int hif        : BFW_NETX_VIC_FIQ_STAT_hif;        // HIF interrupt 
	unsigned int gpio       : BFW_NETX_VIC_FIQ_STAT_gpio;       // other external Interrupts from GPIO 0-14 
	unsigned int com0       : BFW_NETX_VIC_FIQ_STAT_com0;       // Communication channel 0 (= |xpec0_irq[11:0]) 
	unsigned int com1       : BFW_NETX_VIC_FIQ_STAT_com1;       // Communication channel 1 (= |xpec1_irq[11:0]) 
	unsigned int com2       : BFW_NETX_VIC_FIQ_STAT_com2;       // Communication channel 2 (= |xpec2_irq[11:0]) 
	unsigned int com3       : BFW_NETX_VIC_FIQ_STAT_com3;       // Communication channel 3 (= |xpec3_irq[11:0]) 
	unsigned int msync0     : BFW_NETX_VIC_FIQ_STAT_msync0;     // Motion synchronization channel 0 (= |xpec0_irq[15:12]) 
	unsigned int msync1     : BFW_NETX_VIC_FIQ_STAT_msync1;     // Motion synchronization channel 1 (= |xpec1_irq[15:12]) 
	unsigned int msync2     : BFW_NETX_VIC_FIQ_STAT_msync2;     // Motion synchronization channel 2 (= |xpec2_irq[15:12]) 
	unsigned int msync3     : BFW_NETX_VIC_FIQ_STAT_msync3;     // Motion synchronization channel 3 (= |xpec3_irq[15:12]) 
	unsigned int int_phy    : BFW_NETX_VIC_FIQ_STAT_int_phy;    // Interrupt from internal Phys 
	unsigned int iso_area   : BFW_NETX_VIC_FIQ_STAT_iso_area;   // Power is going down (see RTC for details) 
	unsigned int reserved1  : BFW_NETX_VIC_FIQ_STAT_reserved1;  // reserved
	unsigned int timer3     : BFW_NETX_VIC_FIQ_STAT_timer3;     // Timer3 / Counter3 from GPIO Module 
	unsigned int timer4     : BFW_NETX_VIC_FIQ_STAT_timer4;     // Timer4 / Counter4 from GPIO Module 
	unsigned int vfp9       : BFW_NETX_VIC_FIQ_STAT_vfp9;       // reserved 
} VIC_FIQ_STATUS_BIT_T;

typedef union {
	unsigned int         val;
	VIC_FIQ_STATUS_BIT_T bf;
} VIC_FIQ_STATUS_T;

// ---------------------------------------------------------------------
// Register vic_raw_intr
// => VIC Raw interrupt status register
// => Mode: Mode (r)
// ---------------------------------------------------------------------

#define REL_NETX_VIC_RAW_INT_STAT 0x00000008U
#define NETX_VIC_RAW_INT_STAT     0x001FF008U

#define MSK_NETX_VIC_RAW_INT_STAT_sw         0x00000001U // [0]
#define SRT_NETX_VIC_RAW_INT_STAT_sw         0           
#define MSK_NETX_VIC_RAW_INT_STAT_timer0     0x00000002U // [1]
#define SRT_NETX_VIC_RAW_INT_STAT_timer0     1           
#define MSK_NETX_VIC_RAW_INT_STAT_timer1     0x00000004U // [2]
#define SRT_NETX_VIC_RAW_INT_STAT_timer1     2           
#define MSK_NETX_VIC_RAW_INT_STAT_timer2     0x00000008U // [3]
#define SRT_NETX_VIC_RAW_INT_STAT_timer2     3           
#define MSK_NETX_VIC_RAW_INT_STAT_systime_ns 0x00000010U // [4]
#define SRT_NETX_VIC_RAW_INT_STAT_systime_ns 4           
#define MSK_NETX_VIC_RAW_INT_STAT_systime_s  0x00000020U // [5]
#define SRT_NETX_VIC_RAW_INT_STAT_systime_s  5           
#define MSK_NETX_VIC_RAW_INT_STAT_gpio15     0x00000040U // [6]
#define SRT_NETX_VIC_RAW_INT_STAT_gpio15     6           
#define MSK_NETX_VIC_RAW_INT_STAT_watchdog   0x00000080U // [7]
#define SRT_NETX_VIC_RAW_INT_STAT_watchdog   7           
#define MSK_NETX_VIC_RAW_INT_STAT_uart0      0x00000100U // [8]
#define SRT_NETX_VIC_RAW_INT_STAT_uart0      8           
#define MSK_NETX_VIC_RAW_INT_STAT_uart1      0x00000200U // [9]
#define SRT_NETX_VIC_RAW_INT_STAT_uart1      9           
#define MSK_NETX_VIC_RAW_INT_STAT_uart2      0x00000400U // [10]
#define SRT_NETX_VIC_RAW_INT_STAT_uart2      10          
#define MSK_NETX_VIC_RAW_INT_STAT_usb        0x00000800U // [11]
#define SRT_NETX_VIC_RAW_INT_STAT_usb        11          
#define MSK_NETX_VIC_RAW_INT_STAT_spi        0x00001000U // [12]
#define SRT_NETX_VIC_RAW_INT_STAT_spi        12          
#define MSK_NETX_VIC_RAW_INT_STAT_i2c        0x00002000U // [13]
#define SRT_NETX_VIC_RAW_INT_STAT_i2c        13          
#define MSK_NETX_VIC_RAW_INT_STAT_lcd        0x00004000U // [14]
#define SRT_NETX_VIC_RAW_INT_STAT_lcd        14          
#define MSK_NETX_VIC_RAW_INT_STAT_hif        0x00008000U // [15]
#define SRT_NETX_VIC_RAW_INT_STAT_hif        15          
#define MSK_NETX_VIC_RAW_INT_STAT_gpio       0x00010000U // [16]
#define SRT_NETX_VIC_RAW_INT_STAT_gpio       16          
#define MSK_NETX_VIC_RAW_INT_STAT_com0       0x00020000U // [17]
#define SRT_NETX_VIC_RAW_INT_STAT_com0       17          
#define MSK_NETX_VIC_RAW_INT_STAT_com1       0x00040000U // [18]
#define SRT_NETX_VIC_RAW_INT_STAT_com1       18          
#define MSK_NETX_VIC_RAW_INT_STAT_com2       0x00080000U // [19]
#define SRT_NETX_VIC_RAW_INT_STAT_com2       19          
#define MSK_NETX_VIC_RAW_INT_STAT_com3       0x00100000U // [20]
#define SRT_NETX_VIC_RAW_INT_STAT_com3       20          
#define MSK_NETX_VIC_RAW_INT_STAT_msync0     0x00200000U // [21]
#define SRT_NETX_VIC_RAW_INT_STAT_msync0     21          
#define MSK_NETX_VIC_RAW_INT_STAT_msync1     0x00400000U // [22]
#define SRT_NETX_VIC_RAW_INT_STAT_msync1     22          
#define MSK_NETX_VIC_RAW_INT_STAT_msync2     0x00800000U // [23]
#define SRT_NETX_VIC_RAW_INT_STAT_msync2     23          
#define MSK_NETX_VIC_RAW_INT_STAT_msync3     0x01000000U // [24]
#define SRT_NETX_VIC_RAW_INT_STAT_msync3     24          
#define MSK_NETX_VIC_RAW_INT_STAT_int_phy    0x02000000U // [25]
#define SRT_NETX_VIC_RAW_INT_STAT_int_phy    25          
#define MSK_NETX_VIC_RAW_INT_STAT_iso_area   0x04000000U // [26]
#define SRT_NETX_VIC_RAW_INT_STAT_iso_area   26          
#define MSK_NETX_VIC_RAW_INT_STAT_timer3     0x20000000U // [29]
#define SRT_NETX_VIC_RAW_INT_STAT_timer3     29          
#define MSK_NETX_VIC_RAW_INT_STAT_timer4     0x40000000U // [30]
#define SRT_NETX_VIC_RAW_INT_STAT_timer4     30          
#define MSK_NETX_VIC_RAW_INT_STAT_vfp9       0x80000000U // [31]
#define SRT_NETX_VIC_RAW_INT_STAT_vfp9       31          

enum {
	BFW_NETX_VIC_RAW_INT_STAT_sw         = 1, // [0]
	BFW_NETX_VIC_RAW_INT_STAT_timer0     = 1, // [1]
	BFW_NETX_VIC_RAW_INT_STAT_timer1     = 1, // [2]
	BFW_NETX_VIC_RAW_INT_STAT_timer2     = 1, // [3]
	BFW_NETX_VIC_RAW_INT_STAT_systime_ns = 1, // [4]
	BFW_NETX_VIC_RAW_INT_STAT_systime_s  = 1, // [5]
	BFW_NETX_VIC_RAW_INT_STAT_gpio15     = 1, // [6]
	BFW_NETX_VIC_RAW_INT_STAT_watchdog   = 1, // [7]
	BFW_NETX_VIC_RAW_INT_STAT_uart0      = 1, // [8]
	BFW_NETX_VIC_RAW_INT_STAT_uart1      = 1, // [9]
	BFW_NETX_VIC_RAW_INT_STAT_uart2      = 1, // [10]
	BFW_NETX_VIC_RAW_INT_STAT_usb        = 1, // [11]
	BFW_NETX_VIC_RAW_INT_STAT_spi        = 1, // [12]
	BFW_NETX_VIC_RAW_INT_STAT_i2c        = 1, // [13]
	BFW_NETX_VIC_RAW_INT_STAT_lcd        = 1, // [14]
	BFW_NETX_VIC_RAW_INT_STAT_hif        = 1, // [15]
	BFW_NETX_VIC_RAW_INT_STAT_gpio       = 1, // [16]
	BFW_NETX_VIC_RAW_INT_STAT_com0       = 1, // [17]
	BFW_NETX_VIC_RAW_INT_STAT_com1       = 1, // [18]
	BFW_NETX_VIC_RAW_INT_STAT_com2       = 1, // [19]
	BFW_NETX_VIC_RAW_INT_STAT_com3       = 1, // [20]
	BFW_NETX_VIC_RAW_INT_STAT_msync0     = 1, // [21]
	BFW_NETX_VIC_RAW_INT_STAT_msync1     = 1, // [22]
	BFW_NETX_VIC_RAW_INT_STAT_msync2     = 1, // [23]
	BFW_NETX_VIC_RAW_INT_STAT_msync3     = 1, // [24]
	BFW_NETX_VIC_RAW_INT_STAT_int_phy    = 1, // [25]
	BFW_NETX_VIC_RAW_INT_STAT_iso_area   = 1, // [26]
	BFW_NETX_VIC_RAW_INT_STAT_reserved1  = 2, // [28:27]
	BFW_NETX_VIC_RAW_INT_STAT_timer3     = 1, // [29]
	BFW_NETX_VIC_RAW_INT_STAT_timer4     = 1, // [30]
	BFW_NETX_VIC_RAW_INT_STAT_vfp9       = 1  // [31]
};

typedef struct VIC_RAW_INTR_BIT_Ttag {
	unsigned int sw         : BFW_NETX_VIC_RAW_INT_STAT_sw;         // Reserved  for Software Interrupt, ARM standard configuration 
	unsigned int timer0     : BFW_NETX_VIC_RAW_INT_STAT_timer0;     // Timer0 / Counter0 from GPIO Module -> Real time operating system timer, Windows CE required 
	unsigned int timer1     : BFW_NETX_VIC_RAW_INT_STAT_timer1;     // Timer1 / Counter1 from GPIO Module 
	unsigned int timer2     : BFW_NETX_VIC_RAW_INT_STAT_timer2;     // Timer2 / Counter2 from GPIO Module 
	unsigned int systime_ns : BFW_NETX_VIC_RAW_INT_STAT_systime_ns; // systime ns compare irq from GPIO module 
	unsigned int systime_s  : BFW_NETX_VIC_RAW_INT_STAT_systime_s;  // systime 1day IRQ from SYSTIME module, Windows CE required 
	unsigned int gpio15     : BFW_NETX_VIC_RAW_INT_STAT_gpio15;     // external interrupt 15, Windows CE required (NMI) 
	unsigned int watchdog   : BFW_NETX_VIC_RAW_INT_STAT_watchdog;   // reserved 
	unsigned int uart0      : BFW_NETX_VIC_RAW_INT_STAT_uart0;      // UART 0 -> Diagnostic channel, Windows CE required 
	unsigned int uart1      : BFW_NETX_VIC_RAW_INT_STAT_uart1;      // UART 1 
	unsigned int uart2      : BFW_NETX_VIC_RAW_INT_STAT_uart2;      // UART 2 
	unsigned int usb        : BFW_NETX_VIC_RAW_INT_STAT_usb;        // USB interrupt 
	unsigned int spi        : BFW_NETX_VIC_RAW_INT_STAT_spi;        // SPI interrupt 
	unsigned int i2c        : BFW_NETX_VIC_RAW_INT_STAT_i2c;        // reserved 
	unsigned int lcd        : BFW_NETX_VIC_RAW_INT_STAT_lcd;        // LCD-Controller interrupt 
	unsigned int hif        : BFW_NETX_VIC_RAW_INT_STAT_hif;        // HIF interrupt 
	unsigned int gpio       : BFW_NETX_VIC_RAW_INT_STAT_gpio;       // other external Interrupts from GPIO 0-14 
	unsigned int com0       : BFW_NETX_VIC_RAW_INT_STAT_com0;       // Communication channel 0 (= |xpec0_irq[11:0]) 
	unsigned int com1       : BFW_NETX_VIC_RAW_INT_STAT_com1;       // Communication channel 1 (= |xpec1_irq[11:0]) 
	unsigned int com2       : BFW_NETX_VIC_RAW_INT_STAT_com2;       // Communication channel 2 (= |xpec2_irq[11:0]) 
	unsigned int com3       : BFW_NETX_VIC_RAW_INT_STAT_com3;       // Communication channel 3 (= |xpec3_irq[11:0]) 
	unsigned int msync0     : BFW_NETX_VIC_RAW_INT_STAT_msync0;     // Motion synchronization channel 0 (= |xpec0_irq[15:12]) 
	unsigned int msync1     : BFW_NETX_VIC_RAW_INT_STAT_msync1;     // Motion synchronization channel 1 (= |xpec1_irq[15:12]) 
	unsigned int msync2     : BFW_NETX_VIC_RAW_INT_STAT_msync2;     // Motion synchronization channel 2 (= |xpec2_irq[15:12]) 
	unsigned int msync3     : BFW_NETX_VIC_RAW_INT_STAT_msync3;     // Motion synchronization channel 3 (= |xpec3_irq[15:12]) 
	unsigned int int_phy    : BFW_NETX_VIC_RAW_INT_STAT_int_phy;    // Interrupt from internal Phys 
	unsigned int iso_area   : BFW_NETX_VIC_RAW_INT_STAT_iso_area;   // Power is going down (see RTC for details) 
	unsigned int reserved1  : BFW_NETX_VIC_RAW_INT_STAT_reserved1;  // reserved
	unsigned int timer3     : BFW_NETX_VIC_RAW_INT_STAT_timer3;     // Timer3 / Counter3 from GPIO Module 
	unsigned int timer4     : BFW_NETX_VIC_RAW_INT_STAT_timer4;     // Timer4 / Counter4 from GPIO Module 
	unsigned int vfp9       : BFW_NETX_VIC_RAW_INT_STAT_vfp9;       // reserved 
} VIC_RAW_INTR_BIT_T;

typedef union {
	unsigned int       val;
	VIC_RAW_INTR_BIT_T bf;
} VIC_RAW_INTR_T;

// ---------------------------------------------------------------------
// Register vic_int_select
// => VIC Interrupt select register
//    1 = FIQ interrupt
//    0 = IRQ interrupt
// => Mode: Mode (r/w)
// ---------------------------------------------------------------------

#define REL_NETX_VIC_INT_SEL 0x0000000CU
#define NETX_VIC_INT_SEL     0x001FF00CU

#define MSK_NETX_VIC_INT_SEL_sw         0x00000001U // [0]
#define SRT_NETX_VIC_INT_SEL_sw         0           
#define MSK_NETX_VIC_INT_SEL_timer0     0x00000002U // [1]
#define SRT_NETX_VIC_INT_SEL_timer0     1           
#define MSK_NETX_VIC_INT_SEL_timer1     0x00000004U // [2]
#define SRT_NETX_VIC_INT_SEL_timer1     2           
#define MSK_NETX_VIC_INT_SEL_timer2     0x00000008U // [3]
#define SRT_NETX_VIC_INT_SEL_timer2     3           
#define MSK_NETX_VIC_INT_SEL_systime_ns 0x00000010U // [4]
#define SRT_NETX_VIC_INT_SEL_systime_ns 4           
#define MSK_NETX_VIC_INT_SEL_systime_s  0x00000020U // [5]
#define SRT_NETX_VIC_INT_SEL_systime_s  5           
#define MSK_NETX_VIC_INT_SEL_gpio15     0x00000040U // [6]
#define SRT_NETX_VIC_INT_SEL_gpio15     6           
#define MSK_NETX_VIC_INT_SEL_watchdog   0x00000080U // [7]
#define SRT_NETX_VIC_INT_SEL_watchdog   7           
#define MSK_NETX_VIC_INT_SEL_uart0      0x00000100U // [8]
#define SRT_NETX_VIC_INT_SEL_uart0      8           
#define MSK_NETX_VIC_INT_SEL_uart1      0x00000200U // [9]
#define SRT_NETX_VIC_INT_SEL_uart1      9           
#define MSK_NETX_VIC_INT_SEL_uart2      0x00000400U // [10]
#define SRT_NETX_VIC_INT_SEL_uart2      10          
#define MSK_NETX_VIC_INT_SEL_usb        0x00000800U // [11]
#define SRT_NETX_VIC_INT_SEL_usb        11          
#define MSK_NETX_VIC_INT_SEL_spi        0x00001000U // [12]
#define SRT_NETX_VIC_INT_SEL_spi        12          
#define MSK_NETX_VIC_INT_SEL_i2c        0x00002000U // [13]
#define SRT_NETX_VIC_INT_SEL_i2c        13          
#define MSK_NETX_VIC_INT_SEL_lcd        0x00004000U // [14]
#define SRT_NETX_VIC_INT_SEL_lcd        14          
#define MSK_NETX_VIC_INT_SEL_hif        0x00008000U // [15]
#define SRT_NETX_VIC_INT_SEL_hif        15          
#define MSK_NETX_VIC_INT_SEL_gpio       0x00010000U // [16]
#define SRT_NETX_VIC_INT_SEL_gpio       16          
#define MSK_NETX_VIC_INT_SEL_com0       0x00020000U // [17]
#define SRT_NETX_VIC_INT_SEL_com0       17          
#define MSK_NETX_VIC_INT_SEL_com1       0x00040000U // [18]
#define SRT_NETX_VIC_INT_SEL_com1       18          
#define MSK_NETX_VIC_INT_SEL_com2       0x00080000U // [19]
#define SRT_NETX_VIC_INT_SEL_com2       19          
#define MSK_NETX_VIC_INT_SEL_com3       0x00100000U // [20]
#define SRT_NETX_VIC_INT_SEL_com3       20          
#define MSK_NETX_VIC_INT_SEL_msync0     0x00200000U // [21]
#define SRT_NETX_VIC_INT_SEL_msync0     21          
#define MSK_NETX_VIC_INT_SEL_msync1     0x00400000U // [22]
#define SRT_NETX_VIC_INT_SEL_msync1     22          
#define MSK_NETX_VIC_INT_SEL_msync2     0x00800000U // [23]
#define SRT_NETX_VIC_INT_SEL_msync2     23          
#define MSK_NETX_VIC_INT_SEL_msync3     0x01000000U // [24]
#define SRT_NETX_VIC_INT_SEL_msync3     24          
#define MSK_NETX_VIC_INT_SEL_int_phy    0x02000000U // [25]
#define SRT_NETX_VIC_INT_SEL_int_phy    25          
#define MSK_NETX_VIC_INT_SEL_iso_area   0x04000000U // [26]
#define SRT_NETX_VIC_INT_SEL_iso_area   26          
#define MSK_NETX_VIC_INT_SEL_timer3     0x20000000U // [29]
#define SRT_NETX_VIC_INT_SEL_timer3     29          
#define MSK_NETX_VIC_INT_SEL_timer4     0x40000000U // [30]
#define SRT_NETX_VIC_INT_SEL_timer4     30          
#define MSK_NETX_VIC_INT_SEL_vfp9       0x80000000U // [31]
#define SRT_NETX_VIC_INT_SEL_vfp9       31          

enum {
	BFW_NETX_VIC_INT_SEL_sw         = 1, // [0]
	BFW_NETX_VIC_INT_SEL_timer0     = 1, // [1]
	BFW_NETX_VIC_INT_SEL_timer1     = 1, // [2]
	BFW_NETX_VIC_INT_SEL_timer2     = 1, // [3]
	BFW_NETX_VIC_INT_SEL_systime_ns = 1, // [4]
	BFW_NETX_VIC_INT_SEL_systime_s  = 1, // [5]
	BFW_NETX_VIC_INT_SEL_gpio15     = 1, // [6]
	BFW_NETX_VIC_INT_SEL_watchdog   = 1, // [7]
	BFW_NETX_VIC_INT_SEL_uart0      = 1, // [8]
	BFW_NETX_VIC_INT_SEL_uart1      = 1, // [9]
	BFW_NETX_VIC_INT_SEL_uart2      = 1, // [10]
	BFW_NETX_VIC_INT_SEL_usb        = 1, // [11]
	BFW_NETX_VIC_INT_SEL_spi        = 1, // [12]
	BFW_NETX_VIC_INT_SEL_i2c        = 1, // [13]
	BFW_NETX_VIC_INT_SEL_lcd        = 1, // [14]
	BFW_NETX_VIC_INT_SEL_hif        = 1, // [15]
	BFW_NETX_VIC_INT_SEL_gpio       = 1, // [16]
	BFW_NETX_VIC_INT_SEL_com0       = 1, // [17]
	BFW_NETX_VIC_INT_SEL_com1       = 1, // [18]
	BFW_NETX_VIC_INT_SEL_com2       = 1, // [19]
	BFW_NETX_VIC_INT_SEL_com3       = 1, // [20]
	BFW_NETX_VIC_INT_SEL_msync0     = 1, // [21]
	BFW_NETX_VIC_INT_SEL_msync1     = 1, // [22]
	BFW_NETX_VIC_INT_SEL_msync2     = 1, // [23]
	BFW_NETX_VIC_INT_SEL_msync3     = 1, // [24]
	BFW_NETX_VIC_INT_SEL_int_phy    = 1, // [25]
	BFW_NETX_VIC_INT_SEL_iso_area   = 1, // [26]
	BFW_NETX_VIC_INT_SEL_reserved1  = 2, // [28:27]
	BFW_NETX_VIC_INT_SEL_timer3     = 1, // [29]
	BFW_NETX_VIC_INT_SEL_timer4     = 1, // [30]
	BFW_NETX_VIC_INT_SEL_vfp9       = 1  // [31]
};

typedef struct VIC_INT_SELECT_BIT_Ttag {
	unsigned int sw         : BFW_NETX_VIC_INT_SEL_sw;         // Reserved  for Software Interrupt, ARM standard configuration 
	unsigned int timer0     : BFW_NETX_VIC_INT_SEL_timer0;     // Timer0 / Counter0 from GPIO Module -> Real time operating system timer, Windows CE required 
	unsigned int timer1     : BFW_NETX_VIC_INT_SEL_timer1;     // Timer1 / Counter1 from GPIO Module 
	unsigned int timer2     : BFW_NETX_VIC_INT_SEL_timer2;     // Timer2 / Counter2 from GPIO Module 
	unsigned int systime_ns : BFW_NETX_VIC_INT_SEL_systime_ns; // systime ns compare irq from GPIO module 
	unsigned int systime_s  : BFW_NETX_VIC_INT_SEL_systime_s;  // systime 1day IRQ from SYSTIME module, Windows CE required 
	unsigned int gpio15     : BFW_NETX_VIC_INT_SEL_gpio15;     // external interrupt 15, Windows CE required (NMI) 
	unsigned int watchdog   : BFW_NETX_VIC_INT_SEL_watchdog;   // reserved 
	unsigned int uart0      : BFW_NETX_VIC_INT_SEL_uart0;      // UART 0 -> Diagnostic channel, Windows CE required 
	unsigned int uart1      : BFW_NETX_VIC_INT_SEL_uart1;      // UART 1 
	unsigned int uart2      : BFW_NETX_VIC_INT_SEL_uart2;      // UART 2 
	unsigned int usb        : BFW_NETX_VIC_INT_SEL_usb;        // USB interrupt 
	unsigned int spi        : BFW_NETX_VIC_INT_SEL_spi;        // SPI interrupt 
	unsigned int i2c        : BFW_NETX_VIC_INT_SEL_i2c;        // reserved 
	unsigned int lcd        : BFW_NETX_VIC_INT_SEL_lcd;        // LCD-Controller interrupt 
	unsigned int hif        : BFW_NETX_VIC_INT_SEL_hif;        // HIF interrupt 
	unsigned int gpio       : BFW_NETX_VIC_INT_SEL_gpio;       // other external Interrupts from GPIO 0-14 
	unsigned int com0       : BFW_NETX_VIC_INT_SEL_com0;       // Communication channel 0 (= |xpec0_irq[11:0]) 
	unsigned int com1       : BFW_NETX_VIC_INT_SEL_com1;       // Communication channel 1 (= |xpec1_irq[11:0]) 
	unsigned int com2       : BFW_NETX_VIC_INT_SEL_com2;       // Communication channel 2 (= |xpec2_irq[11:0]) 
	unsigned int com3       : BFW_NETX_VIC_INT_SEL_com3;       // Communication channel 3 (= |xpec3_irq[11:0]) 
	unsigned int msync0     : BFW_NETX_VIC_INT_SEL_msync0;     // Motion synchronization channel 0 (= |xpec0_irq[15:12]) 
	unsigned int msync1     : BFW_NETX_VIC_INT_SEL_msync1;     // Motion synchronization channel 1 (= |xpec1_irq[15:12]) 
	unsigned int msync2     : BFW_NETX_VIC_INT_SEL_msync2;     // Motion synchronization channel 2 (= |xpec2_irq[15:12]) 
	unsigned int msync3     : BFW_NETX_VIC_INT_SEL_msync3;     // Motion synchronization channel 3 (= |xpec3_irq[15:12]) 
	unsigned int int_phy    : BFW_NETX_VIC_INT_SEL_int_phy;    // Interrupt from internal Phys 
	unsigned int iso_area   : BFW_NETX_VIC_INT_SEL_iso_area;   // Power is going down (see RTC for details) 
	unsigned int reserved1  : BFW_NETX_VIC_INT_SEL_reserved1;  // reserved
	unsigned int timer3     : BFW_NETX_VIC_INT_SEL_timer3;     // Timer3 / Counter3 from GPIO Module 
	unsigned int timer4     : BFW_NETX_VIC_INT_SEL_timer4;     // Timer4 / Counter4 from GPIO Module 
	unsigned int vfp9       : BFW_NETX_VIC_INT_SEL_vfp9;       // reserved 
} VIC_INT_SELECT_BIT_T;

typedef union {
	unsigned int         val;
	VIC_INT_SELECT_BIT_T bf;
} VIC_INT_SELECT_T;

// ---------------------------------------------------------------------
// Register vic_int_enable
// => VIC Interrupt enable register
//    1 = Interrupt enabled
//    0 = Interrupt disabled
// => Mode: Mode (r/w)
// ---------------------------------------------------------------------

#define REL_NETX_VIC_INT_EN 0x00000010U
#define NETX_VIC_INT_EN     0x001FF010U

#define MSK_NETX_VIC_INT_EN_sw         0x00000001U // [0]
#define SRT_NETX_VIC_INT_EN_sw         0           
#define MSK_NETX_VIC_INT_EN_timer0     0x00000002U // [1]
#define SRT_NETX_VIC_INT_EN_timer0     1           
#define MSK_NETX_VIC_INT_EN_timer1     0x00000004U // [2]
#define SRT_NETX_VIC_INT_EN_timer1     2           
#define MSK_NETX_VIC_INT_EN_timer2     0x00000008U // [3]
#define SRT_NETX_VIC_INT_EN_timer2     3           
#define MSK_NETX_VIC_INT_EN_systime_ns 0x00000010U // [4]
#define SRT_NETX_VIC_INT_EN_systime_ns 4           
#define MSK_NETX_VIC_INT_EN_systime_s  0x00000020U // [5]
#define SRT_NETX_VIC_INT_EN_systime_s  5           
#define MSK_NETX_VIC_INT_EN_gpio15     0x00000040U // [6]
#define SRT_NETX_VIC_INT_EN_gpio15     6           
#define MSK_NETX_VIC_INT_EN_watchdog   0x00000080U // [7]
#define SRT_NETX_VIC_INT_EN_watchdog   7           
#define MSK_NETX_VIC_INT_EN_uart0      0x00000100U // [8]
#define SRT_NETX_VIC_INT_EN_uart0      8           
#define MSK_NETX_VIC_INT_EN_uart1      0x00000200U // [9]
#define SRT_NETX_VIC_INT_EN_uart1      9           
#define MSK_NETX_VIC_INT_EN_uart2      0x00000400U // [10]
#define SRT_NETX_VIC_INT_EN_uart2      10          
#define MSK_NETX_VIC_INT_EN_usb        0x00000800U // [11]
#define SRT_NETX_VIC_INT_EN_usb        11          
#define MSK_NETX_VIC_INT_EN_spi        0x00001000U // [12]
#define SRT_NETX_VIC_INT_EN_spi        12          
#define MSK_NETX_VIC_INT_EN_i2c        0x00002000U // [13]
#define SRT_NETX_VIC_INT_EN_i2c        13          
#define MSK_NETX_VIC_INT_EN_lcd        0x00004000U // [14]
#define SRT_NETX_VIC_INT_EN_lcd        14          
#define MSK_NETX_VIC_INT_EN_hif        0x00008000U // [15]
#define SRT_NETX_VIC_INT_EN_hif        15          
#define MSK_NETX_VIC_INT_EN_gpio       0x00010000U // [16]
#define SRT_NETX_VIC_INT_EN_gpio       16          
#define MSK_NETX_VIC_INT_EN_com0       0x00020000U // [17]
#define SRT_NETX_VIC_INT_EN_com0       17          
#define MSK_NETX_VIC_INT_EN_com1       0x00040000U // [18]
#define SRT_NETX_VIC_INT_EN_com1       18          
#define MSK_NETX_VIC_INT_EN_com2       0x00080000U // [19]
#define SRT_NETX_VIC_INT_EN_com2       19          
#define MSK_NETX_VIC_INT_EN_com3       0x00100000U // [20]
#define SRT_NETX_VIC_INT_EN_com3       20          
#define MSK_NETX_VIC_INT_EN_msync0     0x00200000U // [21]
#define SRT_NETX_VIC_INT_EN_msync0     21          
#define MSK_NETX_VIC_INT_EN_msync1     0x00400000U // [22]
#define SRT_NETX_VIC_INT_EN_msync1     22          
#define MSK_NETX_VIC_INT_EN_msync2     0x00800000U // [23]
#define SRT_NETX_VIC_INT_EN_msync2     23          
#define MSK_NETX_VIC_INT_EN_msync3     0x01000000U // [24]
#define SRT_NETX_VIC_INT_EN_msync3     24          
#define MSK_NETX_VIC_INT_EN_int_phy    0x02000000U // [25]
#define SRT_NETX_VIC_INT_EN_int_phy    25          
#define MSK_NETX_VIC_INT_EN_iso_area   0x04000000U // [26]
#define SRT_NETX_VIC_INT_EN_iso_area   26          
#define MSK_NETX_VIC_INT_EN_timer3     0x20000000U // [29]
#define SRT_NETX_VIC_INT_EN_timer3     29          
#define MSK_NETX_VIC_INT_EN_timer4     0x40000000U // [30]
#define SRT_NETX_VIC_INT_EN_timer4     30          
#define MSK_NETX_VIC_INT_EN_vfp9       0x80000000U // [31]
#define SRT_NETX_VIC_INT_EN_vfp9       31          

enum {
	BFW_NETX_VIC_INT_EN_sw         = 1, // [0]
	BFW_NETX_VIC_INT_EN_timer0     = 1, // [1]
	BFW_NETX_VIC_INT_EN_timer1     = 1, // [2]
	BFW_NETX_VIC_INT_EN_timer2     = 1, // [3]
	BFW_NETX_VIC_INT_EN_systime_ns = 1, // [4]
	BFW_NETX_VIC_INT_EN_systime_s  = 1, // [5]
	BFW_NETX_VIC_INT_EN_gpio15     = 1, // [6]
	BFW_NETX_VIC_INT_EN_watchdog   = 1, // [7]
	BFW_NETX_VIC_INT_EN_uart0      = 1, // [8]
	BFW_NETX_VIC_INT_EN_uart1      = 1, // [9]
	BFW_NETX_VIC_INT_EN_uart2      = 1, // [10]
	BFW_NETX_VIC_INT_EN_usb        = 1, // [11]
	BFW_NETX_VIC_INT_EN_spi        = 1, // [12]
	BFW_NETX_VIC_INT_EN_i2c        = 1, // [13]
	BFW_NETX_VIC_INT_EN_lcd        = 1, // [14]
	BFW_NETX_VIC_INT_EN_hif        = 1, // [15]
	BFW_NETX_VIC_INT_EN_gpio       = 1, // [16]
	BFW_NETX_VIC_INT_EN_com0       = 1, // [17]
	BFW_NETX_VIC_INT_EN_com1       = 1, // [18]
	BFW_NETX_VIC_INT_EN_com2       = 1, // [19]
	BFW_NETX_VIC_INT_EN_com3       = 1, // [20]
	BFW_NETX_VIC_INT_EN_msync0     = 1, // [21]
	BFW_NETX_VIC_INT_EN_msync1     = 1, // [22]
	BFW_NETX_VIC_INT_EN_msync2     = 1, // [23]
	BFW_NETX_VIC_INT_EN_msync3     = 1, // [24]
	BFW_NETX_VIC_INT_EN_int_phy    = 1, // [25]
	BFW_NETX_VIC_INT_EN_iso_area   = 1, // [26]
	BFW_NETX_VIC_INT_EN_reserved1  = 2, // [28:27]
	BFW_NETX_VIC_INT_EN_timer3     = 1, // [29]
	BFW_NETX_VIC_INT_EN_timer4     = 1, // [30]
	BFW_NETX_VIC_INT_EN_vfp9       = 1  // [31]
};

typedef struct VIC_INT_ENABLE_BIT_Ttag {
	unsigned int sw         : BFW_NETX_VIC_INT_EN_sw;         // Reserved  for Software Interrupt, ARM standard configuration 
	unsigned int timer0     : BFW_NETX_VIC_INT_EN_timer0;     // Timer0 / Counter0 from GPIO Module -> Real time operating system timer, Windows CE required 
	unsigned int timer1     : BFW_NETX_VIC_INT_EN_timer1;     // Timer1 / Counter1 from GPIO Module 
	unsigned int timer2     : BFW_NETX_VIC_INT_EN_timer2;     // Timer2 / Counter2 from GPIO Module 
	unsigned int systime_ns : BFW_NETX_VIC_INT_EN_systime_ns; // systime ns compare irq from GPIO module 
	unsigned int systime_s  : BFW_NETX_VIC_INT_EN_systime_s;  // systime 1day IRQ from SYSTIME module, Windows CE required 
	unsigned int gpio15     : BFW_NETX_VIC_INT_EN_gpio15;     // external interrupt 15, Windows CE required (NMI) 
	unsigned int watchdog   : BFW_NETX_VIC_INT_EN_watchdog;   // reserved 
	unsigned int uart0      : BFW_NETX_VIC_INT_EN_uart0;      // UART 0 -> Diagnostic channel, Windows CE required 
	unsigned int uart1      : BFW_NETX_VIC_INT_EN_uart1;      // UART 1 
	unsigned int uart2      : BFW_NETX_VIC_INT_EN_uart2;      // UART 2 
	unsigned int usb        : BFW_NETX_VIC_INT_EN_usb;        // USB interrupt 
	unsigned int spi        : BFW_NETX_VIC_INT_EN_spi;        // SPI interrupt 
	unsigned int i2c        : BFW_NETX_VIC_INT_EN_i2c;        // reserved 
	unsigned int lcd        : BFW_NETX_VIC_INT_EN_lcd;        // LCD-Controller interrupt 
	unsigned int hif        : BFW_NETX_VIC_INT_EN_hif;        // HIF interrupt 
	unsigned int gpio       : BFW_NETX_VIC_INT_EN_gpio;       // other external Interrupts from GPIO 0-14 
	unsigned int com0       : BFW_NETX_VIC_INT_EN_com0;       // Communication channel 0 (= |xpec0_irq[11:0]) 
	unsigned int com1       : BFW_NETX_VIC_INT_EN_com1;       // Communication channel 1 (= |xpec1_irq[11:0]) 
	unsigned int com2       : BFW_NETX_VIC_INT_EN_com2;       // Communication channel 2 (= |xpec2_irq[11:0]) 
	unsigned int com3       : BFW_NETX_VIC_INT_EN_com3;       // Communication channel 3 (= |xpec3_irq[11:0]) 
	unsigned int msync0     : BFW_NETX_VIC_INT_EN_msync0;     // Motion synchronization channel 0 (= |xpec0_irq[15:12]) 
	unsigned int msync1     : BFW_NETX_VIC_INT_EN_msync1;     // Motion synchronization channel 1 (= |xpec1_irq[15:12]) 
	unsigned int msync2     : BFW_NETX_VIC_INT_EN_msync2;     // Motion synchronization channel 2 (= |xpec2_irq[15:12]) 
	unsigned int msync3     : BFW_NETX_VIC_INT_EN_msync3;     // Motion synchronization channel 3 (= |xpec3_irq[15:12]) 
	unsigned int int_phy    : BFW_NETX_VIC_INT_EN_int_phy;    // Interrupt from internal Phys 
	unsigned int iso_area   : BFW_NETX_VIC_INT_EN_iso_area;   // Power is going down (see RTC for details) 
	unsigned int reserved1  : BFW_NETX_VIC_INT_EN_reserved1;  // reserved
	unsigned int timer3     : BFW_NETX_VIC_INT_EN_timer3;     // Timer3 / Counter3 from GPIO Module 
	unsigned int timer4     : BFW_NETX_VIC_INT_EN_timer4;     // Timer4 / Counter4 from GPIO Module 
	unsigned int vfp9       : BFW_NETX_VIC_INT_EN_vfp9;       // reserved 
} VIC_INT_ENABLE_BIT_T;

typedef union {
	unsigned int         val;
	VIC_INT_ENABLE_BIT_T bf;
} VIC_INT_ENABLE_T;

// ---------------------------------------------------------------------
// Register vic_int_enclear
// => VIC Interrupt enable clear register:
//    clear interrupt enable bits
// => Mode: Mode (w)
// ---------------------------------------------------------------------

#define REL_NETX_VIC_INT_EN_CLR 0x00000014U
#define NETX_VIC_INT_EN_CLR     0x001FF014U

#define MSK_NETX_VIC_INT_EN_CLR_sw         0x00000001U // [0]
#define SRT_NETX_VIC_INT_EN_CLR_sw         0           
#define MSK_NETX_VIC_INT_EN_CLR_timer0     0x00000002U // [1]
#define SRT_NETX_VIC_INT_EN_CLR_timer0     1           
#define MSK_NETX_VIC_INT_EN_CLR_timer1     0x00000004U // [2]
#define SRT_NETX_VIC_INT_EN_CLR_timer1     2           
#define MSK_NETX_VIC_INT_EN_CLR_timer2     0x00000008U // [3]
#define SRT_NETX_VIC_INT_EN_CLR_timer2     3           
#define MSK_NETX_VIC_INT_EN_CLR_systime_ns 0x00000010U // [4]
#define SRT_NETX_VIC_INT_EN_CLR_systime_ns 4           
#define MSK_NETX_VIC_INT_EN_CLR_systime_s  0x00000020U // [5]
#define SRT_NETX_VIC_INT_EN_CLR_systime_s  5           
#define MSK_NETX_VIC_INT_EN_CLR_gpio15     0x00000040U // [6]
#define SRT_NETX_VIC_INT_EN_CLR_gpio15     6           
#define MSK_NETX_VIC_INT_EN_CLR_watchdog   0x00000080U // [7]
#define SRT_NETX_VIC_INT_EN_CLR_watchdog   7           
#define MSK_NETX_VIC_INT_EN_CLR_uart0      0x00000100U // [8]
#define SRT_NETX_VIC_INT_EN_CLR_uart0      8           
#define MSK_NETX_VIC_INT_EN_CLR_uart1      0x00000200U // [9]
#define SRT_NETX_VIC_INT_EN_CLR_uart1      9           
#define MSK_NETX_VIC_INT_EN_CLR_uart2      0x00000400U // [10]
#define SRT_NETX_VIC_INT_EN_CLR_uart2      10          
#define MSK_NETX_VIC_INT_EN_CLR_usb        0x00000800U // [11]
#define SRT_NETX_VIC_INT_EN_CLR_usb        11          
#define MSK_NETX_VIC_INT_EN_CLR_spi        0x00001000U // [12]
#define SRT_NETX_VIC_INT_EN_CLR_spi        12          
#define MSK_NETX_VIC_INT_EN_CLR_i2c        0x00002000U // [13]
#define SRT_NETX_VIC_INT_EN_CLR_i2c        13          
#define MSK_NETX_VIC_INT_EN_CLR_lcd        0x00004000U // [14]
#define SRT_NETX_VIC_INT_EN_CLR_lcd        14          
#define MSK_NETX_VIC_INT_EN_CLR_hif        0x00008000U // [15]
#define SRT_NETX_VIC_INT_EN_CLR_hif        15          
#define MSK_NETX_VIC_INT_EN_CLR_gpio       0x00010000U // [16]
#define SRT_NETX_VIC_INT_EN_CLR_gpio       16          
#define MSK_NETX_VIC_INT_EN_CLR_com0       0x00020000U // [17]
#define SRT_NETX_VIC_INT_EN_CLR_com0       17          
#define MSK_NETX_VIC_INT_EN_CLR_com1       0x00040000U // [18]
#define SRT_NETX_VIC_INT_EN_CLR_com1       18          
#define MSK_NETX_VIC_INT_EN_CLR_com2       0x00080000U // [19]
#define SRT_NETX_VIC_INT_EN_CLR_com2       19          
#define MSK_NETX_VIC_INT_EN_CLR_com3       0x00100000U // [20]
#define SRT_NETX_VIC_INT_EN_CLR_com3       20          
#define MSK_NETX_VIC_INT_EN_CLR_msync0     0x00200000U // [21]
#define SRT_NETX_VIC_INT_EN_CLR_msync0     21          
#define MSK_NETX_VIC_INT_EN_CLR_msync1     0x00400000U // [22]
#define SRT_NETX_VIC_INT_EN_CLR_msync1     22          
#define MSK_NETX_VIC_INT_EN_CLR_msync2     0x00800000U // [23]
#define SRT_NETX_VIC_INT_EN_CLR_msync2     23          
#define MSK_NETX_VIC_INT_EN_CLR_msync3     0x01000000U // [24]
#define SRT_NETX_VIC_INT_EN_CLR_msync3     24          
#define MSK_NETX_VIC_INT_EN_CLR_int_phy    0x02000000U // [25]
#define SRT_NETX_VIC_INT_EN_CLR_int_phy    25          
#define MSK_NETX_VIC_INT_EN_CLR_iso_area   0x04000000U // [26]
#define SRT_NETX_VIC_INT_EN_CLR_iso_area   26          
#define MSK_NETX_VIC_INT_EN_CLR_timer3     0x20000000U // [29]
#define SRT_NETX_VIC_INT_EN_CLR_timer3     29          
#define MSK_NETX_VIC_INT_EN_CLR_timer4     0x40000000U // [30]
#define SRT_NETX_VIC_INT_EN_CLR_timer4     30          
#define MSK_NETX_VIC_INT_EN_CLR_vfp9       0x80000000U // [31]
#define SRT_NETX_VIC_INT_EN_CLR_vfp9       31          

enum {
	BFW_NETX_VIC_INT_EN_CLR_sw         = 1, // [0]
	BFW_NETX_VIC_INT_EN_CLR_timer0     = 1, // [1]
	BFW_NETX_VIC_INT_EN_CLR_timer1     = 1, // [2]
	BFW_NETX_VIC_INT_EN_CLR_timer2     = 1, // [3]
	BFW_NETX_VIC_INT_EN_CLR_systime_ns = 1, // [4]
	BFW_NETX_VIC_INT_EN_CLR_systime_s  = 1, // [5]
	BFW_NETX_VIC_INT_EN_CLR_gpio15     = 1, // [6]
	BFW_NETX_VIC_INT_EN_CLR_watchdog   = 1, // [7]
	BFW_NETX_VIC_INT_EN_CLR_uart0      = 1, // [8]
	BFW_NETX_VIC_INT_EN_CLR_uart1      = 1, // [9]
	BFW_NETX_VIC_INT_EN_CLR_uart2      = 1, // [10]
	BFW_NETX_VIC_INT_EN_CLR_usb        = 1, // [11]
	BFW_NETX_VIC_INT_EN_CLR_spi        = 1, // [12]
	BFW_NETX_VIC_INT_EN_CLR_i2c        = 1, // [13]
	BFW_NETX_VIC_INT_EN_CLR_lcd        = 1, // [14]
	BFW_NETX_VIC_INT_EN_CLR_hif        = 1, // [15]
	BFW_NETX_VIC_INT_EN_CLR_gpio       = 1, // [16]
	BFW_NETX_VIC_INT_EN_CLR_com0       = 1, // [17]
	BFW_NETX_VIC_INT_EN_CLR_com1       = 1, // [18]
	BFW_NETX_VIC_INT_EN_CLR_com2       = 1, // [19]
	BFW_NETX_VIC_INT_EN_CLR_com3       = 1, // [20]
	BFW_NETX_VIC_INT_EN_CLR_msync0     = 1, // [21]
	BFW_NETX_VIC_INT_EN_CLR_msync1     = 1, // [22]
	BFW_NETX_VIC_INT_EN_CLR_msync2     = 1, // [23]
	BFW_NETX_VIC_INT_EN_CLR_msync3     = 1, // [24]
	BFW_NETX_VIC_INT_EN_CLR_int_phy    = 1, // [25]
	BFW_NETX_VIC_INT_EN_CLR_iso_area   = 1, // [26]
	BFW_NETX_VIC_INT_EN_CLR_reserved1  = 2, // [28:27]
	BFW_NETX_VIC_INT_EN_CLR_timer3     = 1, // [29]
	BFW_NETX_VIC_INT_EN_CLR_timer4     = 1, // [30]
	BFW_NETX_VIC_INT_EN_CLR_vfp9       = 1  // [31]
};

typedef struct VIC_INT_ENCLEAR_BIT_Ttag {
	unsigned int sw         : BFW_NETX_VIC_INT_EN_CLR_sw;         // Reserved  for Software Interrupt, ARM standard configuration 
	unsigned int timer0     : BFW_NETX_VIC_INT_EN_CLR_timer0;     // Timer0 / Counter0 from GPIO Module -> Real time operating system timer, Windows CE required 
	unsigned int timer1     : BFW_NETX_VIC_INT_EN_CLR_timer1;     // Timer1 / Counter1 from GPIO Module 
	unsigned int timer2     : BFW_NETX_VIC_INT_EN_CLR_timer2;     // Timer2 / Counter2 from GPIO Module 
	unsigned int systime_ns : BFW_NETX_VIC_INT_EN_CLR_systime_ns; // systime ns compare irq from GPIO module 
	unsigned int systime_s  : BFW_NETX_VIC_INT_EN_CLR_systime_s;  // systime 1day IRQ from SYSTIME module, Windows CE required 
	unsigned int gpio15     : BFW_NETX_VIC_INT_EN_CLR_gpio15;     // external interrupt 15, Windows CE required (NMI) 
	unsigned int watchdog   : BFW_NETX_VIC_INT_EN_CLR_watchdog;   // reserved 
	unsigned int uart0      : BFW_NETX_VIC_INT_EN_CLR_uart0;      // UART 0 -> Diagnostic channel, Windows CE required 
	unsigned int uart1      : BFW_NETX_VIC_INT_EN_CLR_uart1;      // UART 1 
	unsigned int uart2      : BFW_NETX_VIC_INT_EN_CLR_uart2;      // UART 2 
	unsigned int usb        : BFW_NETX_VIC_INT_EN_CLR_usb;        // USB interrupt 
	unsigned int spi        : BFW_NETX_VIC_INT_EN_CLR_spi;        // SPI interrupt 
	unsigned int i2c        : BFW_NETX_VIC_INT_EN_CLR_i2c;        // reserved 
	unsigned int lcd        : BFW_NETX_VIC_INT_EN_CLR_lcd;        // LCD-Controller interrupt 
	unsigned int hif        : BFW_NETX_VIC_INT_EN_CLR_hif;        // HIF interrupt 
	unsigned int gpio       : BFW_NETX_VIC_INT_EN_CLR_gpio;       // other external Interrupts from GPIO 0-14 
	unsigned int com0       : BFW_NETX_VIC_INT_EN_CLR_com0;       // Communication channel 0 (= |xpec0_irq[11:0]) 
	unsigned int com1       : BFW_NETX_VIC_INT_EN_CLR_com1;       // Communication channel 1 (= |xpec1_irq[11:0]) 
	unsigned int com2       : BFW_NETX_VIC_INT_EN_CLR_com2;       // Communication channel 2 (= |xpec2_irq[11:0]) 
	unsigned int com3       : BFW_NETX_VIC_INT_EN_CLR_com3;       // Communication channel 3 (= |xpec3_irq[11:0]) 
	unsigned int msync0     : BFW_NETX_VIC_INT_EN_CLR_msync0;     // Motion synchronization channel 0 (= |xpec0_irq[15:12]) 
	unsigned int msync1     : BFW_NETX_VIC_INT_EN_CLR_msync1;     // Motion synchronization channel 1 (= |xpec1_irq[15:12]) 
	unsigned int msync2     : BFW_NETX_VIC_INT_EN_CLR_msync2;     // Motion synchronization channel 2 (= |xpec2_irq[15:12]) 
	unsigned int msync3     : BFW_NETX_VIC_INT_EN_CLR_msync3;     // Motion synchronization channel 3 (= |xpec3_irq[15:12]) 
	unsigned int int_phy    : BFW_NETX_VIC_INT_EN_CLR_int_phy;    // Interrupt from internal Phys 
	unsigned int iso_area   : BFW_NETX_VIC_INT_EN_CLR_iso_area;   // Power is going down (see RTC for details) 
	unsigned int reserved1  : BFW_NETX_VIC_INT_EN_CLR_reserved1;  // reserved
	unsigned int timer3     : BFW_NETX_VIC_INT_EN_CLR_timer3;     // Timer3 / Counter3 from GPIO Module 
	unsigned int timer4     : BFW_NETX_VIC_INT_EN_CLR_timer4;     // Timer4 / Counter4 from GPIO Module 
	unsigned int vfp9       : BFW_NETX_VIC_INT_EN_CLR_vfp9;       // reserved 
} VIC_INT_ENCLEAR_BIT_T;

typedef union {
	unsigned int          val;
	VIC_INT_ENCLEAR_BIT_T bf;
} VIC_INT_ENCLEAR_T;

// ---------------------------------------------------------------------
// Register vic_softint
// => VIC Software interrupt register
// => Mode: Mode (r/w)
// ---------------------------------------------------------------------

#define REL_NETX_VIC_SWI 0x00000018U
#define NETX_VIC_SWI     0x001FF018U

#define MSK_NETX_VIC_SWI_sw         0x00000001U // [0]
#define SRT_NETX_VIC_SWI_sw         0           
#define MSK_NETX_VIC_SWI_timer0     0x00000002U // [1]
#define SRT_NETX_VIC_SWI_timer0     1           
#define MSK_NETX_VIC_SWI_timer1     0x00000004U // [2]
#define SRT_NETX_VIC_SWI_timer1     2           
#define MSK_NETX_VIC_SWI_timer2     0x00000008U // [3]
#define SRT_NETX_VIC_SWI_timer2     3           
#define MSK_NETX_VIC_SWI_systime_ns 0x00000010U // [4]
#define SRT_NETX_VIC_SWI_systime_ns 4           
#define MSK_NETX_VIC_SWI_systime_s  0x00000020U // [5]
#define SRT_NETX_VIC_SWI_systime_s  5           
#define MSK_NETX_VIC_SWI_gpio15     0x00000040U // [6]
#define SRT_NETX_VIC_SWI_gpio15     6           
#define MSK_NETX_VIC_SWI_watchdog   0x00000080U // [7]
#define SRT_NETX_VIC_SWI_watchdog   7           
#define MSK_NETX_VIC_SWI_uart0      0x00000100U // [8]
#define SRT_NETX_VIC_SWI_uart0      8           
#define MSK_NETX_VIC_SWI_uart1      0x00000200U // [9]
#define SRT_NETX_VIC_SWI_uart1      9           
#define MSK_NETX_VIC_SWI_uart2      0x00000400U // [10]
#define SRT_NETX_VIC_SWI_uart2      10          
#define MSK_NETX_VIC_SWI_usb        0x00000800U // [11]
#define SRT_NETX_VIC_SWI_usb        11          
#define MSK_NETX_VIC_SWI_spi        0x00001000U // [12]
#define SRT_NETX_VIC_SWI_spi        12          
#define MSK_NETX_VIC_SWI_i2c        0x00002000U // [13]
#define SRT_NETX_VIC_SWI_i2c        13          
#define MSK_NETX_VIC_SWI_lcd        0x00004000U // [14]
#define SRT_NETX_VIC_SWI_lcd        14          
#define MSK_NETX_VIC_SWI_hif        0x00008000U // [15]
#define SRT_NETX_VIC_SWI_hif        15          
#define MSK_NETX_VIC_SWI_gpio       0x00010000U // [16]
#define SRT_NETX_VIC_SWI_gpio       16          
#define MSK_NETX_VIC_SWI_com0       0x00020000U // [17]
#define SRT_NETX_VIC_SWI_com0       17          
#define MSK_NETX_VIC_SWI_com1       0x00040000U // [18]
#define SRT_NETX_VIC_SWI_com1       18          
#define MSK_NETX_VIC_SWI_com2       0x00080000U // [19]
#define SRT_NETX_VIC_SWI_com2       19          
#define MSK_NETX_VIC_SWI_com3       0x00100000U // [20]
#define SRT_NETX_VIC_SWI_com3       20          
#define MSK_NETX_VIC_SWI_msync0     0x00200000U // [21]
#define SRT_NETX_VIC_SWI_msync0     21          
#define MSK_NETX_VIC_SWI_msync1     0x00400000U // [22]
#define SRT_NETX_VIC_SWI_msync1     22          
#define MSK_NETX_VIC_SWI_msync2     0x00800000U // [23]
#define SRT_NETX_VIC_SWI_msync2     23          
#define MSK_NETX_VIC_SWI_msync3     0x01000000U // [24]
#define SRT_NETX_VIC_SWI_msync3     24          
#define MSK_NETX_VIC_SWI_int_phy    0x02000000U // [25]
#define SRT_NETX_VIC_SWI_int_phy    25          
#define MSK_NETX_VIC_SWI_iso_area   0x04000000U // [26]
#define SRT_NETX_VIC_SWI_iso_area   26          
#define MSK_NETX_VIC_SWI_timer3     0x20000000U // [29]
#define SRT_NETX_VIC_SWI_timer3     29          
#define MSK_NETX_VIC_SWI_timer4     0x40000000U // [30]
#define SRT_NETX_VIC_SWI_timer4     30          
#define MSK_NETX_VIC_SWI_vfp9       0x80000000U // [31]
#define SRT_NETX_VIC_SWI_vfp9       31          

enum {
	BFW_NETX_VIC_SWI_sw         = 1, // [0]
	BFW_NETX_VIC_SWI_timer0     = 1, // [1]
	BFW_NETX_VIC_SWI_timer1     = 1, // [2]
	BFW_NETX_VIC_SWI_timer2     = 1, // [3]
	BFW_NETX_VIC_SWI_systime_ns = 1, // [4]
	BFW_NETX_VIC_SWI_systime_s  = 1, // [5]
	BFW_NETX_VIC_SWI_gpio15     = 1, // [6]
	BFW_NETX_VIC_SWI_watchdog   = 1, // [7]
	BFW_NETX_VIC_SWI_uart0      = 1, // [8]
	BFW_NETX_VIC_SWI_uart1      = 1, // [9]
	BFW_NETX_VIC_SWI_uart2      = 1, // [10]
	BFW_NETX_VIC_SWI_usb        = 1, // [11]
	BFW_NETX_VIC_SWI_spi        = 1, // [12]
	BFW_NETX_VIC_SWI_i2c        = 1, // [13]
	BFW_NETX_VIC_SWI_lcd        = 1, // [14]
	BFW_NETX_VIC_SWI_hif        = 1, // [15]
	BFW_NETX_VIC_SWI_gpio       = 1, // [16]
	BFW_NETX_VIC_SWI_com0       = 1, // [17]
	BFW_NETX_VIC_SWI_com1       = 1, // [18]
	BFW_NETX_VIC_SWI_com2       = 1, // [19]
	BFW_NETX_VIC_SWI_com3       = 1, // [20]
	BFW_NETX_VIC_SWI_msync0     = 1, // [21]
	BFW_NETX_VIC_SWI_msync1     = 1, // [22]
	BFW_NETX_VIC_SWI_msync2     = 1, // [23]
	BFW_NETX_VIC_SWI_msync3     = 1, // [24]
	BFW_NETX_VIC_SWI_int_phy    = 1, // [25]
	BFW_NETX_VIC_SWI_iso_area   = 1, // [26]
	BFW_NETX_VIC_SWI_reserved1  = 2, // [28:27]
	BFW_NETX_VIC_SWI_timer3     = 1, // [29]
	BFW_NETX_VIC_SWI_timer4     = 1, // [30]
	BFW_NETX_VIC_SWI_vfp9       = 1  // [31]
};

typedef struct VIC_SOFTINT_BIT_Ttag {
	unsigned int sw         : BFW_NETX_VIC_SWI_sw;         // Reserved  for Software Interrupt, ARM standard configuration 
	unsigned int timer0     : BFW_NETX_VIC_SWI_timer0;     // Timer0 / Counter0 from GPIO Module -> Real time operating system timer, Windows CE required 
	unsigned int timer1     : BFW_NETX_VIC_SWI_timer1;     // Timer1 / Counter1 from GPIO Module 
	unsigned int timer2     : BFW_NETX_VIC_SWI_timer2;     // Timer2 / Counter2 from GPIO Module 
	unsigned int systime_ns : BFW_NETX_VIC_SWI_systime_ns; // systime ns compare irq from GPIO module 
	unsigned int systime_s  : BFW_NETX_VIC_SWI_systime_s;  // systime 1day IRQ from SYSTIME module, Windows CE required 
	unsigned int gpio15     : BFW_NETX_VIC_SWI_gpio15;     // external interrupt 15, Windows CE required (NMI) 
	unsigned int watchdog   : BFW_NETX_VIC_SWI_watchdog;   // reserved 
	unsigned int uart0      : BFW_NETX_VIC_SWI_uart0;      // UART 0 -> Diagnostic channel, Windows CE required 
	unsigned int uart1      : BFW_NETX_VIC_SWI_uart1;      // UART 1 
	unsigned int uart2      : BFW_NETX_VIC_SWI_uart2;      // UART 2 
	unsigned int usb        : BFW_NETX_VIC_SWI_usb;        // USB interrupt 
	unsigned int spi        : BFW_NETX_VIC_SWI_spi;        // SPI interrupt 
	unsigned int i2c        : BFW_NETX_VIC_SWI_i2c;        // reserved 
	unsigned int lcd        : BFW_NETX_VIC_SWI_lcd;        // LCD-Controller interrupt 
	unsigned int hif        : BFW_NETX_VIC_SWI_hif;        // HIF interrupt 
	unsigned int gpio       : BFW_NETX_VIC_SWI_gpio;       // other external Interrupts from GPIO 0-14 
	unsigned int com0       : BFW_NETX_VIC_SWI_com0;       // Communication channel 0 (= |xpec0_irq[11:0]) 
	unsigned int com1       : BFW_NETX_VIC_SWI_com1;       // Communication channel 1 (= |xpec1_irq[11:0]) 
	unsigned int com2       : BFW_NETX_VIC_SWI_com2;       // Communication channel 2 (= |xpec2_irq[11:0]) 
	unsigned int com3       : BFW_NETX_VIC_SWI_com3;       // Communication channel 3 (= |xpec3_irq[11:0]) 
	unsigned int msync0     : BFW_NETX_VIC_SWI_msync0;     // Motion synchronization channel 0 (= |xpec0_irq[15:12]) 
	unsigned int msync1     : BFW_NETX_VIC_SWI_msync1;     // Motion synchronization channel 1 (= |xpec1_irq[15:12]) 
	unsigned int msync2     : BFW_NETX_VIC_SWI_msync2;     // Motion synchronization channel 2 (= |xpec2_irq[15:12]) 
	unsigned int msync3     : BFW_NETX_VIC_SWI_msync3;     // Motion synchronization channel 3 (= |xpec3_irq[15:12]) 
	unsigned int int_phy    : BFW_NETX_VIC_SWI_int_phy;    // Interrupt from internal Phys 
	unsigned int iso_area   : BFW_NETX_VIC_SWI_iso_area;   // Power is going down (see RTC for details) 
	unsigned int reserved1  : BFW_NETX_VIC_SWI_reserved1;  // reserved
	unsigned int timer3     : BFW_NETX_VIC_SWI_timer3;     // Timer3 / Counter3 from GPIO Module 
	unsigned int timer4     : BFW_NETX_VIC_SWI_timer4;     // Timer4 / Counter4 from GPIO Module 
	unsigned int vfp9       : BFW_NETX_VIC_SWI_vfp9;       // reserved 
} VIC_SOFTINT_BIT_T;

typedef union {
	unsigned int      val;
	VIC_SOFTINT_BIT_T bf;
} VIC_SOFTINT_T;

// ---------------------------------------------------------------------
// Register vic_softint_clear
// => VIC Software interrupt clear register:
//    clear software interrupt bits
// => Mode: Mode (w)
// ---------------------------------------------------------------------

#define REL_NETX_VIC_SWI_CLR 0x0000001CU
#define NETX_VIC_SWI_CLR     0x001FF01CU

#define MSK_NETX_VIC_SWI_CLR_sw         0x00000001U // [0]
#define SRT_NETX_VIC_SWI_CLR_sw         0           
#define MSK_NETX_VIC_SWI_CLR_timer0     0x00000002U // [1]
#define SRT_NETX_VIC_SWI_CLR_timer0     1           
#define MSK_NETX_VIC_SWI_CLR_timer1     0x00000004U // [2]
#define SRT_NETX_VIC_SWI_CLR_timer1     2           
#define MSK_NETX_VIC_SWI_CLR_timer2     0x00000008U // [3]
#define SRT_NETX_VIC_SWI_CLR_timer2     3           
#define MSK_NETX_VIC_SWI_CLR_systime_ns 0x00000010U // [4]
#define SRT_NETX_VIC_SWI_CLR_systime_ns 4           
#define MSK_NETX_VIC_SWI_CLR_systime_s  0x00000020U // [5]
#define SRT_NETX_VIC_SWI_CLR_systime_s  5           
#define MSK_NETX_VIC_SWI_CLR_gpio15     0x00000040U // [6]
#define SRT_NETX_VIC_SWI_CLR_gpio15     6           
#define MSK_NETX_VIC_SWI_CLR_watchdog   0x00000080U // [7]
#define SRT_NETX_VIC_SWI_CLR_watchdog   7           
#define MSK_NETX_VIC_SWI_CLR_uart0      0x00000100U // [8]
#define SRT_NETX_VIC_SWI_CLR_uart0      8           
#define MSK_NETX_VIC_SWI_CLR_uart1      0x00000200U // [9]
#define SRT_NETX_VIC_SWI_CLR_uart1      9           
#define MSK_NETX_VIC_SWI_CLR_uart2      0x00000400U // [10]
#define SRT_NETX_VIC_SWI_CLR_uart2      10          
#define MSK_NETX_VIC_SWI_CLR_usb        0x00000800U // [11]
#define SRT_NETX_VIC_SWI_CLR_usb        11          
#define MSK_NETX_VIC_SWI_CLR_spi        0x00001000U // [12]
#define SRT_NETX_VIC_SWI_CLR_spi        12          
#define MSK_NETX_VIC_SWI_CLR_i2c        0x00002000U // [13]
#define SRT_NETX_VIC_SWI_CLR_i2c        13          
#define MSK_NETX_VIC_SWI_CLR_lcd        0x00004000U // [14]
#define SRT_NETX_VIC_SWI_CLR_lcd        14          
#define MSK_NETX_VIC_SWI_CLR_hif        0x00008000U // [15]
#define SRT_NETX_VIC_SWI_CLR_hif        15          
#define MSK_NETX_VIC_SWI_CLR_gpio       0x00010000U // [16]
#define SRT_NETX_VIC_SWI_CLR_gpio       16          
#define MSK_NETX_VIC_SWI_CLR_com0       0x00020000U // [17]
#define SRT_NETX_VIC_SWI_CLR_com0       17          
#define MSK_NETX_VIC_SWI_CLR_com1       0x00040000U // [18]
#define SRT_NETX_VIC_SWI_CLR_com1       18          
#define MSK_NETX_VIC_SWI_CLR_com2       0x00080000U // [19]
#define SRT_NETX_VIC_SWI_CLR_com2       19          
#define MSK_NETX_VIC_SWI_CLR_com3       0x00100000U // [20]
#define SRT_NETX_VIC_SWI_CLR_com3       20          
#define MSK_NETX_VIC_SWI_CLR_msync0     0x00200000U // [21]
#define SRT_NETX_VIC_SWI_CLR_msync0     21          
#define MSK_NETX_VIC_SWI_CLR_msync1     0x00400000U // [22]
#define SRT_NETX_VIC_SWI_CLR_msync1     22          
#define MSK_NETX_VIC_SWI_CLR_msync2     0x00800000U // [23]
#define SRT_NETX_VIC_SWI_CLR_msync2     23          
#define MSK_NETX_VIC_SWI_CLR_msync3     0x01000000U // [24]
#define SRT_NETX_VIC_SWI_CLR_msync3     24          
#define MSK_NETX_VIC_SWI_CLR_int_phy    0x02000000U // [25]
#define SRT_NETX_VIC_SWI_CLR_int_phy    25          
#define MSK_NETX_VIC_SWI_CLR_iso_area   0x04000000U // [26]
#define SRT_NETX_VIC_SWI_CLR_iso_area   26          
#define MSK_NETX_VIC_SWI_CLR_timer3     0x20000000U // [29]
#define SRT_NETX_VIC_SWI_CLR_timer3     29          
#define MSK_NETX_VIC_SWI_CLR_timer4     0x40000000U // [30]
#define SRT_NETX_VIC_SWI_CLR_timer4     30          
#define MSK_NETX_VIC_SWI_CLR_vfp9       0x80000000U // [31]
#define SRT_NETX_VIC_SWI_CLR_vfp9       31          

enum {
	BFW_NETX_VIC_SWI_CLR_sw         = 1, // [0]
	BFW_NETX_VIC_SWI_CLR_timer0     = 1, // [1]
	BFW_NETX_VIC_SWI_CLR_timer1     = 1, // [2]
	BFW_NETX_VIC_SWI_CLR_timer2     = 1, // [3]
	BFW_NETX_VIC_SWI_CLR_systime_ns = 1, // [4]
	BFW_NETX_VIC_SWI_CLR_systime_s  = 1, // [5]
	BFW_NETX_VIC_SWI_CLR_gpio15     = 1, // [6]
	BFW_NETX_VIC_SWI_CLR_watchdog   = 1, // [7]
	BFW_NETX_VIC_SWI_CLR_uart0      = 1, // [8]
	BFW_NETX_VIC_SWI_CLR_uart1      = 1, // [9]
	BFW_NETX_VIC_SWI_CLR_uart2      = 1, // [10]
	BFW_NETX_VIC_SWI_CLR_usb        = 1, // [11]
	BFW_NETX_VIC_SWI_CLR_spi        = 1, // [12]
	BFW_NETX_VIC_SWI_CLR_i2c        = 1, // [13]
	BFW_NETX_VIC_SWI_CLR_lcd        = 1, // [14]
	BFW_NETX_VIC_SWI_CLR_hif        = 1, // [15]
	BFW_NETX_VIC_SWI_CLR_gpio       = 1, // [16]
	BFW_NETX_VIC_SWI_CLR_com0       = 1, // [17]
	BFW_NETX_VIC_SWI_CLR_com1       = 1, // [18]
	BFW_NETX_VIC_SWI_CLR_com2       = 1, // [19]
	BFW_NETX_VIC_SWI_CLR_com3       = 1, // [20]
	BFW_NETX_VIC_SWI_CLR_msync0     = 1, // [21]
	BFW_NETX_VIC_SWI_CLR_msync1     = 1, // [22]
	BFW_NETX_VIC_SWI_CLR_msync2     = 1, // [23]
	BFW_NETX_VIC_SWI_CLR_msync3     = 1, // [24]
	BFW_NETX_VIC_SWI_CLR_int_phy    = 1, // [25]
	BFW_NETX_VIC_SWI_CLR_iso_area   = 1, // [26]
	BFW_NETX_VIC_SWI_CLR_reserved1  = 2, // [28:27]
	BFW_NETX_VIC_SWI_CLR_timer3     = 1, // [29]
	BFW_NETX_VIC_SWI_CLR_timer4     = 1, // [30]
	BFW_NETX_VIC_SWI_CLR_vfp9       = 1  // [31]
};

typedef struct VIC_SOFTINT_CLEAR_BIT_Ttag {
	unsigned int sw         : BFW_NETX_VIC_SWI_CLR_sw;         // Reserved  for Software Interrupt, ARM standard configuration 
	unsigned int timer0     : BFW_NETX_VIC_SWI_CLR_timer0;     // Timer0 / Counter0 from GPIO Module -> Real time operating system timer, Windows CE required 
	unsigned int timer1     : BFW_NETX_VIC_SWI_CLR_timer1;     // Timer1 / Counter1 from GPIO Module 
	unsigned int timer2     : BFW_NETX_VIC_SWI_CLR_timer2;     // Timer2 / Counter2 from GPIO Module 
	unsigned int systime_ns : BFW_NETX_VIC_SWI_CLR_systime_ns; // systime ns compare irq from GPIO module 
	unsigned int systime_s  : BFW_NETX_VIC_SWI_CLR_systime_s;  // systime 1day IRQ from SYSTIME module, Windows CE required 
	unsigned int gpio15     : BFW_NETX_VIC_SWI_CLR_gpio15;     // external interrupt 15, Windows CE required (NMI) 
	unsigned int watchdog   : BFW_NETX_VIC_SWI_CLR_watchdog;   // reserved 
	unsigned int uart0      : BFW_NETX_VIC_SWI_CLR_uart0;      // UART 0 -> Diagnostic channel, Windows CE required 
	unsigned int uart1      : BFW_NETX_VIC_SWI_CLR_uart1;      // UART 1 
	unsigned int uart2      : BFW_NETX_VIC_SWI_CLR_uart2;      // UART 2 
	unsigned int usb        : BFW_NETX_VIC_SWI_CLR_usb;        // USB interrupt 
	unsigned int spi        : BFW_NETX_VIC_SWI_CLR_spi;        // SPI interrupt 
	unsigned int i2c        : BFW_NETX_VIC_SWI_CLR_i2c;        // reserved 
	unsigned int lcd        : BFW_NETX_VIC_SWI_CLR_lcd;        // LCD-Controller interrupt 
	unsigned int hif        : BFW_NETX_VIC_SWI_CLR_hif;        // HIF interrupt 
	unsigned int gpio       : BFW_NETX_VIC_SWI_CLR_gpio;       // other external Interrupts from GPIO 0-14 
	unsigned int com0       : BFW_NETX_VIC_SWI_CLR_com0;       // Communication channel 0 (= |xpec0_irq[11:0]) 
	unsigned int com1       : BFW_NETX_VIC_SWI_CLR_com1;       // Communication channel 1 (= |xpec1_irq[11:0]) 
	unsigned int com2       : BFW_NETX_VIC_SWI_CLR_com2;       // Communication channel 2 (= |xpec2_irq[11:0]) 
	unsigned int com3       : BFW_NETX_VIC_SWI_CLR_com3;       // Communication channel 3 (= |xpec3_irq[11:0]) 
	unsigned int msync0     : BFW_NETX_VIC_SWI_CLR_msync0;     // Motion synchronization channel 0 (= |xpec0_irq[15:12]) 
	unsigned int msync1     : BFW_NETX_VIC_SWI_CLR_msync1;     // Motion synchronization channel 1 (= |xpec1_irq[15:12]) 
	unsigned int msync2     : BFW_NETX_VIC_SWI_CLR_msync2;     // Motion synchronization channel 2 (= |xpec2_irq[15:12]) 
	unsigned int msync3     : BFW_NETX_VIC_SWI_CLR_msync3;     // Motion synchronization channel 3 (= |xpec3_irq[15:12]) 
	unsigned int int_phy    : BFW_NETX_VIC_SWI_CLR_int_phy;    // Interrupt from internal Phys 
	unsigned int iso_area   : BFW_NETX_VIC_SWI_CLR_iso_area;   // Power is going down (see RTC for details) 
	unsigned int reserved1  : BFW_NETX_VIC_SWI_CLR_reserved1;  // reserved
	unsigned int timer3     : BFW_NETX_VIC_SWI_CLR_timer3;     // Timer3 / Counter3 from GPIO Module 
	unsigned int timer4     : BFW_NETX_VIC_SWI_CLR_timer4;     // Timer4 / Counter4 from GPIO Module 
	unsigned int vfp9       : BFW_NETX_VIC_SWI_CLR_vfp9;       // reserved 
} VIC_SOFTINT_CLEAR_BIT_T;

typedef union {
	unsigned int            val;
	VIC_SOFTINT_CLEAR_BIT_T bf;
} VIC_SOFTINT_CLEAR_T;

// ---------------------------------------------------------------------
// Register vic_protection
// => VIC Protection enable register
// => Mode: Mode (r/w)
// ---------------------------------------------------------------------

#define REL_NETX_VIC_PROT_EN 0x00000020U
#define NETX_VIC_PROT_EN     0x001FF020U

#define MSK_NETX_VIC_PROT_EN_PROTECTION 0x00000001U // [0]
#define SRT_NETX_VIC_PROT_EN_PROTECTION 0           

enum {
	BFW_NETX_VIC_PROT_EN_PROTECTION = 1,  // [0]
	BFW_NETX_VIC_PROT_EN_reserved1  = 31  // [31:1]
};

typedef struct VIC_PROTECTION_BIT_Ttag {
	unsigned int PROTECTION : BFW_NETX_VIC_PROT_EN_PROTECTION; // enables or disables protected register access 
	unsigned int reserved1  : BFW_NETX_VIC_PROT_EN_reserved1;  // reserved
} VIC_PROTECTION_BIT_T;

typedef union {
	unsigned int         val;
	VIC_PROTECTION_BIT_T bf;
} VIC_PROTECTION_T;

// ---------------------------------------------------------------------
// Register vic_vect_addr
// => VIC Vector address register
//    Any writes to this register clear the interrupt.
// => Mode: Mode (r/w)
// ---------------------------------------------------------------------

#define REL_NETX_VIC_VECT_ADDR 0x00000030U
#define NETX_VIC_VECT_ADDR     0x001FF030U

#define MSK_NETX_VIC_VECT_ADDR_VECT_ADDR 0xffffffffU // [31:0]
#define SRT_NETX_VIC_VECT_ADDR_VECT_ADDR 0           

enum {
	BFW_NETX_VIC_VECT_ADDR_VECT_ADDR = 32  // [31:0]
};

typedef struct VIC_VECT_ADDR_BIT_Ttag {
	unsigned int VECT_ADDR : BFW_NETX_VIC_VECT_ADDR_VECT_ADDR; // address of the currently active ISR handler 
} VIC_VECT_ADDR_BIT_T;

typedef union {
	unsigned int        val;
	VIC_VECT_ADDR_BIT_T bf;
} VIC_VECT_ADDR_T;

// ---------------------------------------------------------------------
// Register vic_def_vect_addr
// => VIC Default vector address register
// => Mode: Mode (r/w)
// ---------------------------------------------------------------------

#define REL_NETX_VIC_DFLT_VECT_ADDR 0x00000034U
#define NETX_VIC_DFLT_VECT_ADDR     0x001FF034U

#define MSK_NETX_VIC_DFLT_VECT_ADDR_DEF_VECT_ADDR 0xffffffffU // [31:0]
#define SRT_NETX_VIC_DFLT_VECT_ADDR_DEF_VECT_ADDR 0           

enum {
	BFW_NETX_VIC_DFLT_VECT_ADDR_DEF_VECT_ADDR = 32  // [31:0]
};

typedef struct VIC_DEF_VECT_ADDR_BIT_Ttag {
	unsigned int DEF_VECT_ADDR : BFW_NETX_VIC_DFLT_VECT_ADDR_DEF_VECT_ADDR; // address of the default ISR handler 
} VIC_DEF_VECT_ADDR_BIT_T;

typedef union {
	unsigned int            val;
	VIC_DEF_VECT_ADDR_BIT_T bf;
} VIC_DEF_VECT_ADDR_T;

// ---------------------------------------------------------------------
// Register vic_vect_addr0
// => VIC Vector address 0 register
// => Mode: Mode (r/w)
// ---------------------------------------------------------------------

#define REL_NETX_VIC_VECT_ADDR0 0x00000100U
#define NETX_VIC_VECT_ADDR0     0x001FF100U

#define MSK_NETX_VIC_VECT_ADDR0_VECT_ADDR0 0xffffffffU // [31:0]
#define SRT_NETX_VIC_VECT_ADDR0_VECT_ADDR0 0           

enum {
	BFW_NETX_VIC_VECT_ADDR0_VECT_ADDR0 = 32  // [31:0]
};

typedef struct VIC_VECT_ADDR0_BIT_Ttag {
	unsigned int VECT_ADDR0 : BFW_NETX_VIC_VECT_ADDR0_VECT_ADDR0; // ISR vector addresses 
} VIC_VECT_ADDR0_BIT_T;

typedef union {
	unsigned int         val;
	VIC_VECT_ADDR0_BIT_T bf;
} VIC_VECT_ADDR0_T;

// ---------------------------------------------------------------------
// Register vic_vect_addr1
// => VIC Vector address 1 register
// => Mode: Mode (r/w)
// ---------------------------------------------------------------------

#define REL_NETX_VIC_VECT_ADDR1 0x00000104U
#define NETX_VIC_VECT_ADDR1     0x001FF104U

#define MSK_NETX_VIC_VECT_ADDR1_VECT_ADDR1 0xffffffffU // [31:0]
#define SRT_NETX_VIC_VECT_ADDR1_VECT_ADDR1 0           

enum {
	BFW_NETX_VIC_VECT_ADDR1_VECT_ADDR1 = 32  // [31:0]
};

typedef struct VIC_VECT_ADDR1_BIT_Ttag {
	unsigned int VECT_ADDR1 : BFW_NETX_VIC_VECT_ADDR1_VECT_ADDR1; // ISR vector addresses 
} VIC_VECT_ADDR1_BIT_T;

typedef union {
	unsigned int         val;
	VIC_VECT_ADDR1_BIT_T bf;
} VIC_VECT_ADDR1_T;

// ---------------------------------------------------------------------
// Register vic_vect_addr2
// => VIC Vector address 2 register
// => Mode: Mode (r/w)
// ---------------------------------------------------------------------

#define REL_NETX_VIC_VECT_ADDR2 0x00000108U
#define NETX_VIC_VECT_ADDR2     0x001FF108U

#define MSK_NETX_VIC_VECT_ADDR2_VECT_ADDR2 0xffffffffU // [31:0]
#define SRT_NETX_VIC_VECT_ADDR2_VECT_ADDR2 0           

enum {
	BFW_NETX_VIC_VECT_ADDR2_VECT_ADDR2 = 32  // [31:0]
};

typedef struct VIC_VECT_ADDR2_BIT_Ttag {
	unsigned int VECT_ADDR2 : BFW_NETX_VIC_VECT_ADDR2_VECT_ADDR2; // ISR vector addresses 
} VIC_VECT_ADDR2_BIT_T;

typedef union {
	unsigned int         val;
	VIC_VECT_ADDR2_BIT_T bf;
} VIC_VECT_ADDR2_T;

// ---------------------------------------------------------------------
// Register vic_vect_addr3
// => VIC Vector address 3 register
// => Mode: Mode (r/w)
// ---------------------------------------------------------------------

#define REL_NETX_VIC_VECT_ADDR3 0x0000010CU
#define NETX_VIC_VECT_ADDR3     0x001FF10CU

#define MSK_NETX_VIC_VECT_ADDR3_VECT_ADDR3 0xffffffffU // [31:0]
#define SRT_NETX_VIC_VECT_ADDR3_VECT_ADDR3 0           

enum {
	BFW_NETX_VIC_VECT_ADDR3_VECT_ADDR3 = 32  // [31:0]
};

typedef struct VIC_VECT_ADDR3_BIT_Ttag {
	unsigned int VECT_ADDR3 : BFW_NETX_VIC_VECT_ADDR3_VECT_ADDR3; // ISR vector addresses 
} VIC_VECT_ADDR3_BIT_T;

typedef union {
	unsigned int         val;
	VIC_VECT_ADDR3_BIT_T bf;
} VIC_VECT_ADDR3_T;

// ---------------------------------------------------------------------
// Register vic_vect_addr4
// => VIC Vector address 4 register
// => Mode: Mode (r/w)
// ---------------------------------------------------------------------

#define REL_NETX_VIC_VECT_ADDR4 0x00000110U
#define NETX_VIC_VECT_ADDR4     0x001FF110U

#define MSK_NETX_VIC_VECT_ADDR4_VECT_ADDR4 0xffffffffU // [31:0]
#define SRT_NETX_VIC_VECT_ADDR4_VECT_ADDR4 0           

enum {
	BFW_NETX_VIC_VECT_ADDR4_VECT_ADDR4 = 32  // [31:0]
};

typedef struct VIC_VECT_ADDR4_BIT_Ttag {
	unsigned int VECT_ADDR4 : BFW_NETX_VIC_VECT_ADDR4_VECT_ADDR4; // ISR vector addresses 
} VIC_VECT_ADDR4_BIT_T;

typedef union {
	unsigned int         val;
	VIC_VECT_ADDR4_BIT_T bf;
} VIC_VECT_ADDR4_T;

// ---------------------------------------------------------------------
// Register vic_vect_addr5
// => VIC Vector address 5 register
// => Mode: Mode (r/w)
// ---------------------------------------------------------------------

#define REL_NETX_VIC_VECT_ADDR5 0x00000114U
#define NETX_VIC_VECT_ADDR5     0x001FF114U

#define MSK_NETX_VIC_VECT_ADDR5_VECT_ADDR5 0xffffffffU // [31:0]
#define SRT_NETX_VIC_VECT_ADDR5_VECT_ADDR5 0           

enum {
	BFW_NETX_VIC_VECT_ADDR5_VECT_ADDR5 = 32  // [31:0]
};

typedef struct VIC_VECT_ADDR5_BIT_Ttag {
	unsigned int VECT_ADDR5 : BFW_NETX_VIC_VECT_ADDR5_VECT_ADDR5; // ISR vector addresses 
} VIC_VECT_ADDR5_BIT_T;

typedef union {
	unsigned int         val;
	VIC_VECT_ADDR5_BIT_T bf;
} VIC_VECT_ADDR5_T;

// ---------------------------------------------------------------------
// Register vic_vect_addr6
// => VIC Vector address 6 register
// => Mode: Mode (r/w)
// ---------------------------------------------------------------------

#define REL_NETX_VIC_VECT_ADDR6 0x00000118U
#define NETX_VIC_VECT_ADDR6     0x001FF118U

#define MSK_NETX_VIC_VECT_ADDR6_VECT_ADDR6 0xffffffffU // [31:0]
#define SRT_NETX_VIC_VECT_ADDR6_VECT_ADDR6 0           

enum {
	BFW_NETX_VIC_VECT_ADDR6_VECT_ADDR6 = 32  // [31:0]
};

typedef struct VIC_VECT_ADDR6_BIT_Ttag {
	unsigned int VECT_ADDR6 : BFW_NETX_VIC_VECT_ADDR6_VECT_ADDR6; // ISR vector addresses 
} VIC_VECT_ADDR6_BIT_T;

typedef union {
	unsigned int         val;
	VIC_VECT_ADDR6_BIT_T bf;
} VIC_VECT_ADDR6_T;

// ---------------------------------------------------------------------
// Register vic_vect_addr7
// => VIC Vector address 7 register
// => Mode: Mode (r/w)
// ---------------------------------------------------------------------

#define REL_NETX_VIC_VECT_ADDR7 0x0000011CU
#define NETX_VIC_VECT_ADDR7     0x001FF11CU

#define MSK_NETX_VIC_VECT_ADDR7_VECT_ADDR7 0xffffffffU // [31:0]
#define SRT_NETX_VIC_VECT_ADDR7_VECT_ADDR7 0           

enum {
	BFW_NETX_VIC_VECT_ADDR7_VECT_ADDR7 = 32  // [31:0]
};

typedef struct VIC_VECT_ADDR7_BIT_Ttag {
	unsigned int VECT_ADDR7 : BFW_NETX_VIC_VECT_ADDR7_VECT_ADDR7; // ISR vector addresses 
} VIC_VECT_ADDR7_BIT_T;

typedef union {
	unsigned int         val;
	VIC_VECT_ADDR7_BIT_T bf;
} VIC_VECT_ADDR7_T;

// ---------------------------------------------------------------------
// Register vic_vect_addr8
// => VIC Vector address 8 register
// => Mode: Mode (r/w)
// ---------------------------------------------------------------------

#define REL_NETX_VIC_VECT_ADDR8 0x00000120U
#define NETX_VIC_VECT_ADDR8     0x001FF120U

#define MSK_NETX_VIC_VECT_ADDR8_VECT_ADDR8 0xffffffffU // [31:0]
#define SRT_NETX_VIC_VECT_ADDR8_VECT_ADDR8 0           

enum {
	BFW_NETX_VIC_VECT_ADDR8_VECT_ADDR8 = 32  // [31:0]
};

typedef struct VIC_VECT_ADDR8_BIT_Ttag {
	unsigned int VECT_ADDR8 : BFW_NETX_VIC_VECT_ADDR8_VECT_ADDR8; // ISR vector addresses 
} VIC_VECT_ADDR8_BIT_T;

typedef union {
	unsigned int         val;
	VIC_VECT_ADDR8_BIT_T bf;
} VIC_VECT_ADDR8_T;

// ---------------------------------------------------------------------
// Register vic_vect_addr9
// => VIC Vector address 9 register
// => Mode: Mode (r/w)
// ---------------------------------------------------------------------

#define REL_NETX_VIC_VECT_ADDR9 0x00000124U
#define NETX_VIC_VECT_ADDR9     0x001FF124U

#define MSK_NETX_VIC_VECT_ADDR9_VECT_ADDR9 0xffffffffU // [31:0]
#define SRT_NETX_VIC_VECT_ADDR9_VECT_ADDR9 0           

enum {
	BFW_NETX_VIC_VECT_ADDR9_VECT_ADDR9 = 32  // [31:0]
};

typedef struct VIC_VECT_ADDR9_BIT_Ttag {
	unsigned int VECT_ADDR9 : BFW_NETX_VIC_VECT_ADDR9_VECT_ADDR9; // ISR vector addresses 
} VIC_VECT_ADDR9_BIT_T;

typedef union {
	unsigned int         val;
	VIC_VECT_ADDR9_BIT_T bf;
} VIC_VECT_ADDR9_T;

// ---------------------------------------------------------------------
// Register vic_vect_addr10
// => VIC Vector address 10 register
// => Mode: Mode (r/w)
// ---------------------------------------------------------------------

#define REL_NETX_VIC_VECT_ADDR10 0x00000128U
#define NETX_VIC_VECT_ADDR10     0x001FF128U

#define MSK_NETX_VIC_VECT_ADDR10_VECT_ADDR10 0xffffffffU // [31:0]
#define SRT_NETX_VIC_VECT_ADDR10_VECT_ADDR10 0           

enum {
	BFW_NETX_VIC_VECT_ADDR10_VECT_ADDR10 = 32  // [31:0]
};

typedef struct VIC_VECT_ADDR10_BIT_Ttag {
	unsigned int VECT_ADDR10 : BFW_NETX_VIC_VECT_ADDR10_VECT_ADDR10; // ISR vector addresses 
} VIC_VECT_ADDR10_BIT_T;

typedef union {
	unsigned int          val;
	VIC_VECT_ADDR10_BIT_T bf;
} VIC_VECT_ADDR10_T;

// ---------------------------------------------------------------------
// Register vic_vect_addr11
// => VIC Vector address 11 register
// => Mode: Mode (r/w)
// ---------------------------------------------------------------------

#define REL_NETX_VIC_VECT_ADDR11 0x0000012CU
#define NETX_VIC_VECT_ADDR11     0x001FF12CU

#define MSK_NETX_VIC_VECT_ADDR11_VECT_ADDR11 0xffffffffU // [31:0]
#define SRT_NETX_VIC_VECT_ADDR11_VECT_ADDR11 0           

enum {
	BFW_NETX_VIC_VECT_ADDR11_VECT_ADDR11 = 32  // [31:0]
};

typedef struct VIC_VECT_ADDR11_BIT_Ttag {
	unsigned int VECT_ADDR11 : BFW_NETX_VIC_VECT_ADDR11_VECT_ADDR11; // ISR vector addresses 
} VIC_VECT_ADDR11_BIT_T;

typedef union {
	unsigned int          val;
	VIC_VECT_ADDR11_BIT_T bf;
} VIC_VECT_ADDR11_T;

// ---------------------------------------------------------------------
// Register vic_vect_addr12
// => VIC Vector address 12 register
// => Mode: Mode (r/w)
// ---------------------------------------------------------------------

#define REL_NETX_VIC_VECT_ADDR12 0x00000130U
#define NETX_VIC_VECT_ADDR12     0x001FF130U

#define MSK_NETX_VIC_VECT_ADDR12_VECT_ADDR12 0xffffffffU // [31:0]
#define SRT_NETX_VIC_VECT_ADDR12_VECT_ADDR12 0           

enum {
	BFW_NETX_VIC_VECT_ADDR12_VECT_ADDR12 = 32  // [31:0]
};

typedef struct VIC_VECT_ADDR12_BIT_Ttag {
	unsigned int VECT_ADDR12 : BFW_NETX_VIC_VECT_ADDR12_VECT_ADDR12; // ISR vector addresses 
} VIC_VECT_ADDR12_BIT_T;

typedef union {
	unsigned int          val;
	VIC_VECT_ADDR12_BIT_T bf;
} VIC_VECT_ADDR12_T;

// ---------------------------------------------------------------------
// Register vic_vect_addr13
// => VIC Vector address 13 register
// => Mode: Mode (r/w)
// ---------------------------------------------------------------------

#define REL_NETX_VIC_VECT_ADDR13 0x00000134U
#define NETX_VIC_VECT_ADDR13     0x001FF134U

#define MSK_NETX_VIC_VECT_ADDR13_VECT_ADDR13 0xffffffffU // [31:0]
#define SRT_NETX_VIC_VECT_ADDR13_VECT_ADDR13 0           

enum {
	BFW_NETX_VIC_VECT_ADDR13_VECT_ADDR13 = 32  // [31:0]
};

typedef struct VIC_VECT_ADDR13_BIT_Ttag {
	unsigned int VECT_ADDR13 : BFW_NETX_VIC_VECT_ADDR13_VECT_ADDR13; // ISR vector addresses 
} VIC_VECT_ADDR13_BIT_T;

typedef union {
	unsigned int          val;
	VIC_VECT_ADDR13_BIT_T bf;
} VIC_VECT_ADDR13_T;

// ---------------------------------------------------------------------
// Register vic_vect_addr14
// => VIC Vector address 14 register
// => Mode: Mode (r/w)
// ---------------------------------------------------------------------

#define REL_NETX_VIC_VECT_ADDR14 0x00000138U
#define NETX_VIC_VECT_ADDR14     0x001FF138U

#define MSK_NETX_VIC_VECT_ADDR14_VECT_ADDR14 0xffffffffU // [31:0]
#define SRT_NETX_VIC_VECT_ADDR14_VECT_ADDR14 0           

enum {
	BFW_NETX_VIC_VECT_ADDR14_VECT_ADDR14 = 32  // [31:0]
};

typedef struct VIC_VECT_ADDR14_BIT_Ttag {
	unsigned int VECT_ADDR14 : BFW_NETX_VIC_VECT_ADDR14_VECT_ADDR14; // ISR vector addresses 
} VIC_VECT_ADDR14_BIT_T;

typedef union {
	unsigned int          val;
	VIC_VECT_ADDR14_BIT_T bf;
} VIC_VECT_ADDR14_T;

// ---------------------------------------------------------------------
// Register vic_vect_addr15
// => VIC Vector address 15 register
// => Mode: Mode (r/w)
// ---------------------------------------------------------------------

#define REL_NETX_VIC_VECT_ADDR15 0x0000013CU
#define NETX_VIC_VECT_ADDR15     0x001FF13CU

#define MSK_NETX_VIC_VECT_ADDR15_VECT_ADDR15 0xffffffffU // [31:0]
#define SRT_NETX_VIC_VECT_ADDR15_VECT_ADDR15 0           

enum {
	BFW_NETX_VIC_VECT_ADDR15_VECT_ADDR15 = 32  // [31:0]
};

typedef struct VIC_VECT_ADDR15_BIT_Ttag {
	unsigned int VECT_ADDR15 : BFW_NETX_VIC_VECT_ADDR15_VECT_ADDR15; // ISR vector addresses 
} VIC_VECT_ADDR15_BIT_T;

typedef union {
	unsigned int          val;
	VIC_VECT_ADDR15_BIT_T bf;
} VIC_VECT_ADDR15_T;

// ---------------------------------------------------------------------
// Register vic_vect_cntl0
// => VIC Vector control 0 register
// => Mode: Mode (r/w)
// ---------------------------------------------------------------------

#define REL_NETX_VIC_VECT_CTRL0 0x00000200U
#define NETX_VIC_VECT_CTRL0     0x001FF200U

#define MSK_NETX_VIC_VECT_CTRL0_INT_SOURCE 0x0000001fU // [4:0]
#define SRT_NETX_VIC_VECT_CTRL0_INT_SOURCE 0           
#define MSK_NETX_VIC_VECT_CTRL0_ENABLE     0x00000020U // [5]
#define SRT_NETX_VIC_VECT_CTRL0_ENABLE     5           

enum {
	BFW_NETX_VIC_VECT_CTRL0_INT_SOURCE = 5,  // [4:0]
	BFW_NETX_VIC_VECT_CTRL0_ENABLE     = 1,  // [5]
	BFW_NETX_VIC_VECT_CTRL0_reserved1  = 26  // [31:6]
};

typedef struct VIC_VECT_CNTL0_BIT_Ttag {
	unsigned int INT_SOURCE : BFW_NETX_VIC_VECT_CTRL0_INT_SOURCE; // interrupt source select 
	unsigned int ENABLE     : BFW_NETX_VIC_VECT_CTRL0_ENABLE;     // vector interrupt enable 
	unsigned int reserved1  : BFW_NETX_VIC_VECT_CTRL0_reserved1;  // reserved
} VIC_VECT_CNTL0_BIT_T;

typedef union {
	unsigned int         val;
	VIC_VECT_CNTL0_BIT_T bf;
} VIC_VECT_CNTL0_T;

// ---------------------------------------------------------------------
// Register vic_vect_cntl1
// => VIC Vector control 1 register
// => Mode: Mode (r/w)
// ---------------------------------------------------------------------

#define REL_NETX_VIC_VECT_CTRL1 0x00000204U
#define NETX_VIC_VECT_CTRL1     0x001FF204U

#define MSK_NETX_VIC_VECT_CTRL1_INT_SOURCE 0x0000001fU // [4:0]
#define SRT_NETX_VIC_VECT_CTRL1_INT_SOURCE 0           
#define MSK_NETX_VIC_VECT_CTRL1_ENABLE     0x00000020U // [5]
#define SRT_NETX_VIC_VECT_CTRL1_ENABLE     5           

enum {
	BFW_NETX_VIC_VECT_CTRL1_INT_SOURCE = 5,  // [4:0]
	BFW_NETX_VIC_VECT_CTRL1_ENABLE     = 1,  // [5]
	BFW_NETX_VIC_VECT_CTRL1_reserved1  = 26  // [31:6]
};

typedef struct VIC_VECT_CNTL1_BIT_Ttag {
	unsigned int INT_SOURCE : BFW_NETX_VIC_VECT_CTRL1_INT_SOURCE; // interrupt source select 
	unsigned int ENABLE     : BFW_NETX_VIC_VECT_CTRL1_ENABLE;     // vector interrupt enable 
	unsigned int reserved1  : BFW_NETX_VIC_VECT_CTRL1_reserved1;  // reserved
} VIC_VECT_CNTL1_BIT_T;

typedef union {
	unsigned int         val;
	VIC_VECT_CNTL1_BIT_T bf;
} VIC_VECT_CNTL1_T;

// ---------------------------------------------------------------------
// Register vic_vect_cntl2
// => VIC Vector control 2 register
// => Mode: Mode (r/w)
// ---------------------------------------------------------------------

#define REL_NETX_VIC_VECT_CTRL2 0x00000208U
#define NETX_VIC_VECT_CTRL2     0x001FF208U

#define MSK_NETX_VIC_VECT_CTRL2_INT_SOURCE 0x0000001fU // [4:0]
#define SRT_NETX_VIC_VECT_CTRL2_INT_SOURCE 0           
#define MSK_NETX_VIC_VECT_CTRL2_ENABLE     0x00000020U // [5]
#define SRT_NETX_VIC_VECT_CTRL2_ENABLE     5           

enum {
	BFW_NETX_VIC_VECT_CTRL2_INT_SOURCE = 5,  // [4:0]
	BFW_NETX_VIC_VECT_CTRL2_ENABLE     = 1,  // [5]
	BFW_NETX_VIC_VECT_CTRL2_reserved1  = 26  // [31:6]
};

typedef struct VIC_VECT_CNTL2_BIT_Ttag {
	unsigned int INT_SOURCE : BFW_NETX_VIC_VECT_CTRL2_INT_SOURCE; // interrupt source select 
	unsigned int ENABLE     : BFW_NETX_VIC_VECT_CTRL2_ENABLE;     // vector interrupt enable 
	unsigned int reserved1  : BFW_NETX_VIC_VECT_CTRL2_reserved1;  // reserved
} VIC_VECT_CNTL2_BIT_T;

typedef union {
	unsigned int         val;
	VIC_VECT_CNTL2_BIT_T bf;
} VIC_VECT_CNTL2_T;

// ---------------------------------------------------------------------
// Register vic_vect_cntl3
// => VIC Vector control 3 register
// => Mode: Mode (r/w)
// ---------------------------------------------------------------------

#define REL_NETX_VIC_VECT_CTRL3 0x0000020CU
#define NETX_VIC_VECT_CTRL3     0x001FF20CU

#define MSK_NETX_VIC_VECT_CTRL3_INT_SOURCE 0x0000001fU // [4:0]
#define SRT_NETX_VIC_VECT_CTRL3_INT_SOURCE 0           
#define MSK_NETX_VIC_VECT_CTRL3_ENABLE     0x00000020U // [5]
#define SRT_NETX_VIC_VECT_CTRL3_ENABLE     5           

enum {
	BFW_NETX_VIC_VECT_CTRL3_INT_SOURCE = 5,  // [4:0]
	BFW_NETX_VIC_VECT_CTRL3_ENABLE     = 1,  // [5]
	BFW_NETX_VIC_VECT_CTRL3_reserved1  = 26  // [31:6]
};

typedef struct VIC_VECT_CNTL3_BIT_Ttag {
	unsigned int INT_SOURCE : BFW_NETX_VIC_VECT_CTRL3_INT_SOURCE; // interrupt source select 
	unsigned int ENABLE     : BFW_NETX_VIC_VECT_CTRL3_ENABLE;     // vector interrupt enable 
	unsigned int reserved1  : BFW_NETX_VIC_VECT_CTRL3_reserved1;  // reserved
} VIC_VECT_CNTL3_BIT_T;

typedef union {
	unsigned int         val;
	VIC_VECT_CNTL3_BIT_T bf;
} VIC_VECT_CNTL3_T;

// ---------------------------------------------------------------------
// Register vic_vect_cntl4
// => VIC Vector control 4 register
// => Mode: Mode (r/w)
// ---------------------------------------------------------------------

#define REL_NETX_VIC_VECT_CTRL4 0x00000210U
#define NETX_VIC_VECT_CTRL4     0x001FF210U

#define MSK_NETX_VIC_VECT_CTRL4_INT_SOURCE 0x0000001fU // [4:0]
#define SRT_NETX_VIC_VECT_CTRL4_INT_SOURCE 0           
#define MSK_NETX_VIC_VECT_CTRL4_ENABLE     0x00000020U // [5]
#define SRT_NETX_VIC_VECT_CTRL4_ENABLE     5           

enum {
	BFW_NETX_VIC_VECT_CTRL4_INT_SOURCE = 5,  // [4:0]
	BFW_NETX_VIC_VECT_CTRL4_ENABLE     = 1,  // [5]
	BFW_NETX_VIC_VECT_CTRL4_reserved1  = 26  // [31:6]
};

typedef struct VIC_VECT_CNTL4_BIT_Ttag {
	unsigned int INT_SOURCE : BFW_NETX_VIC_VECT_CTRL4_INT_SOURCE; // interrupt source select 
	unsigned int ENABLE     : BFW_NETX_VIC_VECT_CTRL4_ENABLE;     // vector interrupt enable 
	unsigned int reserved1  : BFW_NETX_VIC_VECT_CTRL4_reserved1;  // reserved
} VIC_VECT_CNTL4_BIT_T;

typedef union {
	unsigned int         val;
	VIC_VECT_CNTL4_BIT_T bf;
} VIC_VECT_CNTL4_T;

// ---------------------------------------------------------------------
// Register vic_vect_cntl5
// => VIC Vector control 5 register
// => Mode: Mode (r/w)
// ---------------------------------------------------------------------

#define REL_NETX_VIC_VECT_CTRL5 0x00000214U
#define NETX_VIC_VECT_CTRL5     0x001FF214U

#define MSK_NETX_VIC_VECT_CTRL5_INT_SOURCE 0x0000001fU // [4:0]
#define SRT_NETX_VIC_VECT_CTRL5_INT_SOURCE 0           
#define MSK_NETX_VIC_VECT_CTRL5_ENABLE     0x00000020U // [5]
#define SRT_NETX_VIC_VECT_CTRL5_ENABLE     5           

enum {
	BFW_NETX_VIC_VECT_CTRL5_INT_SOURCE = 5,  // [4:0]
	BFW_NETX_VIC_VECT_CTRL5_ENABLE     = 1,  // [5]
	BFW_NETX_VIC_VECT_CTRL5_reserved1  = 26  // [31:6]
};

typedef struct VIC_VECT_CNTL5_BIT_Ttag {
	unsigned int INT_SOURCE : BFW_NETX_VIC_VECT_CTRL5_INT_SOURCE; // interrupt source select 
	unsigned int ENABLE     : BFW_NETX_VIC_VECT_CTRL5_ENABLE;     // vector interrupt enable 
	unsigned int reserved1  : BFW_NETX_VIC_VECT_CTRL5_reserved1;  // reserved
} VIC_VECT_CNTL5_BIT_T;

typedef union {
	unsigned int         val;
	VIC_VECT_CNTL5_BIT_T bf;
} VIC_VECT_CNTL5_T;

// ---------------------------------------------------------------------
// Register vic_vect_cntl6
// => VIC Vector control 6 register
// => Mode: Mode (r/w)
// ---------------------------------------------------------------------

#define REL_NETX_VIC_VECT_CTRL6 0x00000218U
#define NETX_VIC_VECT_CTRL6     0x001FF218U

#define MSK_NETX_VIC_VECT_CTRL6_INT_SOURCE 0x0000001fU // [4:0]
#define SRT_NETX_VIC_VECT_CTRL6_INT_SOURCE 0           
#define MSK_NETX_VIC_VECT_CTRL6_ENABLE     0x00000020U // [5]
#define SRT_NETX_VIC_VECT_CTRL6_ENABLE     5           

enum {
	BFW_NETX_VIC_VECT_CTRL6_INT_SOURCE = 5,  // [4:0]
	BFW_NETX_VIC_VECT_CTRL6_ENABLE     = 1,  // [5]
	BFW_NETX_VIC_VECT_CTRL6_reserved1  = 26  // [31:6]
};

typedef struct VIC_VECT_CNTL6_BIT_Ttag {
	unsigned int INT_SOURCE : BFW_NETX_VIC_VECT_CTRL6_INT_SOURCE; // interrupt source select 
	unsigned int ENABLE     : BFW_NETX_VIC_VECT_CTRL6_ENABLE;     // vector interrupt enable 
	unsigned int reserved1  : BFW_NETX_VIC_VECT_CTRL6_reserved1;  // reserved
} VIC_VECT_CNTL6_BIT_T;

typedef union {
	unsigned int         val;
	VIC_VECT_CNTL6_BIT_T bf;
} VIC_VECT_CNTL6_T;

// ---------------------------------------------------------------------
// Register vic_vect_cntl7
// => VIC Vector control 7 register
// => Mode: Mode (r/w)
// ---------------------------------------------------------------------

#define REL_NETX_VIC_VECT_CTRL7 0x0000021CU
#define NETX_VIC_VECT_CTRL7     0x001FF21CU

#define MSK_NETX_VIC_VECT_CTRL7_INT_SOURCE 0x0000001fU // [4:0]
#define SRT_NETX_VIC_VECT_CTRL7_INT_SOURCE 0           
#define MSK_NETX_VIC_VECT_CTRL7_ENABLE     0x00000020U // [5]
#define SRT_NETX_VIC_VECT_CTRL7_ENABLE     5           

enum {
	BFW_NETX_VIC_VECT_CTRL7_INT_SOURCE = 5,  // [4:0]
	BFW_NETX_VIC_VECT_CTRL7_ENABLE     = 1,  // [5]
	BFW_NETX_VIC_VECT_CTRL7_reserved1  = 26  // [31:6]
};

typedef struct VIC_VECT_CNTL7_BIT_Ttag {
	unsigned int INT_SOURCE : BFW_NETX_VIC_VECT_CTRL7_INT_SOURCE; // interrupt source select 
	unsigned int ENABLE     : BFW_NETX_VIC_VECT_CTRL7_ENABLE;     // vector interrupt enable 
	unsigned int reserved1  : BFW_NETX_VIC_VECT_CTRL7_reserved1;  // reserved
} VIC_VECT_CNTL7_BIT_T;

typedef union {
	unsigned int         val;
	VIC_VECT_CNTL7_BIT_T bf;
} VIC_VECT_CNTL7_T;

// ---------------------------------------------------------------------
// Register vic_vect_cntl8
// => VIC Vector control 8 register
// => Mode: Mode (r/w)
// ---------------------------------------------------------------------

#define REL_NETX_VIC_VECT_CTRL8 0x00000220U
#define NETX_VIC_VECT_CTRL8     0x001FF220U

#define MSK_NETX_VIC_VECT_CTRL8_INT_SOURCE 0x0000001fU // [4:0]
#define SRT_NETX_VIC_VECT_CTRL8_INT_SOURCE 0           
#define MSK_NETX_VIC_VECT_CTRL8_ENABLE     0x00000020U // [5]
#define SRT_NETX_VIC_VECT_CTRL8_ENABLE     5           

enum {
	BFW_NETX_VIC_VECT_CTRL8_INT_SOURCE = 5,  // [4:0]
	BFW_NETX_VIC_VECT_CTRL8_ENABLE     = 1,  // [5]
	BFW_NETX_VIC_VECT_CTRL8_reserved1  = 26  // [31:6]
};

typedef struct VIC_VECT_CNTL8_BIT_Ttag {
	unsigned int INT_SOURCE : BFW_NETX_VIC_VECT_CTRL8_INT_SOURCE; // interrupt source select 
	unsigned int ENABLE     : BFW_NETX_VIC_VECT_CTRL8_ENABLE;     // vector interrupt enable 
	unsigned int reserved1  : BFW_NETX_VIC_VECT_CTRL8_reserved1;  // reserved
} VIC_VECT_CNTL8_BIT_T;

typedef union {
	unsigned int         val;
	VIC_VECT_CNTL8_BIT_T bf;
} VIC_VECT_CNTL8_T;

// ---------------------------------------------------------------------
// Register vic_vect_cntl9
// => VIC Vector control 9 register
// => Mode: Mode (r/w)
// ---------------------------------------------------------------------

#define REL_NETX_VIC_VECT_CTRL9 0x00000224U
#define NETX_VIC_VECT_CTRL9     0x001FF224U

#define MSK_NETX_VIC_VECT_CTRL9_INT_SOURCE 0x0000001fU // [4:0]
#define SRT_NETX_VIC_VECT_CTRL9_INT_SOURCE 0           
#define MSK_NETX_VIC_VECT_CTRL9_ENABLE     0x00000020U // [5]
#define SRT_NETX_VIC_VECT_CTRL9_ENABLE     5           

enum {
	BFW_NETX_VIC_VECT_CTRL9_INT_SOURCE = 5,  // [4:0]
	BFW_NETX_VIC_VECT_CTRL9_ENABLE     = 1,  // [5]
	BFW_NETX_VIC_VECT_CTRL9_reserved1  = 26  // [31:6]
};

typedef struct VIC_VECT_CNTL9_BIT_Ttag {
	unsigned int INT_SOURCE : BFW_NETX_VIC_VECT_CTRL9_INT_SOURCE; // interrupt source select 
	unsigned int ENABLE     : BFW_NETX_VIC_VECT_CTRL9_ENABLE;     // vector interrupt enable 
	unsigned int reserved1  : BFW_NETX_VIC_VECT_CTRL9_reserved1;  // reserved
} VIC_VECT_CNTL9_BIT_T;

typedef union {
	unsigned int         val;
	VIC_VECT_CNTL9_BIT_T bf;
} VIC_VECT_CNTL9_T;

// ---------------------------------------------------------------------
// Register vic_vect_cntl10
// => VIC Vector control 10 register
// => Mode: Mode (r/w)
// ---------------------------------------------------------------------

#define REL_NETX_VIC_VECT_CTRL10 0x00000228U
#define NETX_VIC_VECT_CTRL10     0x001FF228U

#define MSK_NETX_VIC_VECT_CTRL10_INT_SOURCE 0x0000001fU // [4:0]
#define SRT_NETX_VIC_VECT_CTRL10_INT_SOURCE 0           
#define MSK_NETX_VIC_VECT_CTRL10_ENABLE     0x00000020U // [5]
#define SRT_NETX_VIC_VECT_CTRL10_ENABLE     5           

enum {
	BFW_NETX_VIC_VECT_CTRL10_INT_SOURCE = 5,  // [4:0]
	BFW_NETX_VIC_VECT_CTRL10_ENABLE     = 1,  // [5]
	BFW_NETX_VIC_VECT_CTRL10_reserved1  = 26  // [31:6]
};

typedef struct VIC_VECT_CNTL10_BIT_Ttag {
	unsigned int INT_SOURCE : BFW_NETX_VIC_VECT_CTRL10_INT_SOURCE; // interrupt source select 
	unsigned int ENABLE     : BFW_NETX_VIC_VECT_CTRL10_ENABLE;     // vector interrupt enable 
	unsigned int reserved1  : BFW_NETX_VIC_VECT_CTRL10_reserved1;  // reserved
} VIC_VECT_CNTL10_BIT_T;

typedef union {
	unsigned int          val;
	VIC_VECT_CNTL10_BIT_T bf;
} VIC_VECT_CNTL10_T;

// ---------------------------------------------------------------------
// Register vic_vect_cntl11
// => VIC Vector control 11 register
// => Mode: Mode (r/w)
// ---------------------------------------------------------------------

#define REL_NETX_VIC_VECT_CTRL11 0x0000022CU
#define NETX_VIC_VECT_CTRL11     0x001FF22CU

#define MSK_NETX_VIC_VECT_CTRL11_INT_SOURCE 0x0000001fU // [4:0]
#define SRT_NETX_VIC_VECT_CTRL11_INT_SOURCE 0           
#define MSK_NETX_VIC_VECT_CTRL11_ENABLE     0x00000020U // [5]
#define SRT_NETX_VIC_VECT_CTRL11_ENABLE     5           

enum {
	BFW_NETX_VIC_VECT_CTRL11_INT_SOURCE = 5,  // [4:0]
	BFW_NETX_VIC_VECT_CTRL11_ENABLE     = 1,  // [5]
	BFW_NETX_VIC_VECT_CTRL11_reserved1  = 26  // [31:6]
};

typedef struct VIC_VECT_CNTL11_BIT_Ttag {
	unsigned int INT_SOURCE : BFW_NETX_VIC_VECT_CTRL11_INT_SOURCE; // interrupt source select 
	unsigned int ENABLE     : BFW_NETX_VIC_VECT_CTRL11_ENABLE;     // vector interrupt enable 
	unsigned int reserved1  : BFW_NETX_VIC_VECT_CTRL11_reserved1;  // reserved
} VIC_VECT_CNTL11_BIT_T;

typedef union {
	unsigned int          val;
	VIC_VECT_CNTL11_BIT_T bf;
} VIC_VECT_CNTL11_T;

// ---------------------------------------------------------------------
// Register vic_vect_cntl12
// => VIC Vector control 12 register
// => Mode: Mode (r/w)
// ---------------------------------------------------------------------

#define REL_NETX_VIC_VECT_CTRL12 0x00000230U
#define NETX_VIC_VECT_CTRL12     0x001FF230U

#define MSK_NETX_VIC_VECT_CTRL12_INT_SOURCE 0x0000001fU // [4:0]
#define SRT_NETX_VIC_VECT_CTRL12_INT_SOURCE 0           
#define MSK_NETX_VIC_VECT_CTRL12_ENABLE     0x00000020U // [5]
#define SRT_NETX_VIC_VECT_CTRL12_ENABLE     5           

enum {
	BFW_NETX_VIC_VECT_CTRL12_INT_SOURCE = 5,  // [4:0]
	BFW_NETX_VIC_VECT_CTRL12_ENABLE     = 1,  // [5]
	BFW_NETX_VIC_VECT_CTRL12_reserved1  = 26  // [31:6]
};

typedef struct VIC_VECT_CNTL12_BIT_Ttag {
	unsigned int INT_SOURCE : BFW_NETX_VIC_VECT_CTRL12_INT_SOURCE; // interrupt source select 
	unsigned int ENABLE     : BFW_NETX_VIC_VECT_CTRL12_ENABLE;     // vector interrupt enable 
	unsigned int reserved1  : BFW_NETX_VIC_VECT_CTRL12_reserved1;  // reserved
} VIC_VECT_CNTL12_BIT_T;

typedef union {
	unsigned int          val;
	VIC_VECT_CNTL12_BIT_T bf;
} VIC_VECT_CNTL12_T;

// ---------------------------------------------------------------------
// Register vic_vect_cntl13
// => VIC Vector control 13 register
// => Mode: Mode (r/w)
// ---------------------------------------------------------------------

#define REL_NETX_VIC_VECT_CTRL13 0x00000234U
#define NETX_VIC_VECT_CTRL13     0x001FF234U

#define MSK_NETX_VIC_VECT_CTRL13_INT_SOURCE 0x0000001fU // [4:0]
#define SRT_NETX_VIC_VECT_CTRL13_INT_SOURCE 0           
#define MSK_NETX_VIC_VECT_CTRL13_ENABLE     0x00000020U // [5]
#define SRT_NETX_VIC_VECT_CTRL13_ENABLE     5           

enum {
	BFW_NETX_VIC_VECT_CTRL13_INT_SOURCE = 5,  // [4:0]
	BFW_NETX_VIC_VECT_CTRL13_ENABLE     = 1,  // [5]
	BFW_NETX_VIC_VECT_CTRL13_reserved1  = 26  // [31:6]
};

typedef struct VIC_VECT_CNTL13_BIT_Ttag {
	unsigned int INT_SOURCE : BFW_NETX_VIC_VECT_CTRL13_INT_SOURCE; // interrupt source select 
	unsigned int ENABLE     : BFW_NETX_VIC_VECT_CTRL13_ENABLE;     // vector interrupt enable 
	unsigned int reserved1  : BFW_NETX_VIC_VECT_CTRL13_reserved1;  // reserved
} VIC_VECT_CNTL13_BIT_T;

typedef union {
	unsigned int          val;
	VIC_VECT_CNTL13_BIT_T bf;
} VIC_VECT_CNTL13_T;

// ---------------------------------------------------------------------
// Register vic_vect_cntl14
// => VIC Vector control 14 register
// => Mode: Mode (r/w)
// ---------------------------------------------------------------------

#define REL_NETX_VIC_VECT_CTRL14 0x00000238U
#define NETX_VIC_VECT_CTRL14     0x001FF238U

#define MSK_NETX_VIC_VECT_CTRL14_INT_SOURCE 0x0000001fU // [4:0]
#define SRT_NETX_VIC_VECT_CTRL14_INT_SOURCE 0           
#define MSK_NETX_VIC_VECT_CTRL14_ENABLE     0x00000020U // [5]
#define SRT_NETX_VIC_VECT_CTRL14_ENABLE     5           

enum {
	BFW_NETX_VIC_VECT_CTRL14_INT_SOURCE = 5,  // [4:0]
	BFW_NETX_VIC_VECT_CTRL14_ENABLE     = 1,  // [5]
	BFW_NETX_VIC_VECT_CTRL14_reserved1  = 26  // [31:6]
};

typedef struct VIC_VECT_CNTL14_BIT_Ttag {
	unsigned int INT_SOURCE : BFW_NETX_VIC_VECT_CTRL14_INT_SOURCE; // interrupt source select 
	unsigned int ENABLE     : BFW_NETX_VIC_VECT_CTRL14_ENABLE;     // vector interrupt enable 
	unsigned int reserved1  : BFW_NETX_VIC_VECT_CTRL14_reserved1;  // reserved
} VIC_VECT_CNTL14_BIT_T;

typedef union {
	unsigned int          val;
	VIC_VECT_CNTL14_BIT_T bf;
} VIC_VECT_CNTL14_T;

// ---------------------------------------------------------------------
// Register vic_vect_cntl15
// => VIC Vector control 15 register
// => Mode: Mode (r/w)
// ---------------------------------------------------------------------

#define REL_NETX_VIC_VECT_CTRL15 0x0000023CU
#define NETX_VIC_VECT_CTRL15     0x001FF23CU

#define MSK_NETX_VIC_VECT_CTRL15_INT_SOURCE 0x0000001fU // [4:0]
#define SRT_NETX_VIC_VECT_CTRL15_INT_SOURCE 0           
#define MSK_NETX_VIC_VECT_CTRL15_ENABLE     0x00000020U // [5]
#define SRT_NETX_VIC_VECT_CTRL15_ENABLE     5           

enum {
	BFW_NETX_VIC_VECT_CTRL15_INT_SOURCE = 5,  // [4:0]
	BFW_NETX_VIC_VECT_CTRL15_ENABLE     = 1,  // [5]
	BFW_NETX_VIC_VECT_CTRL15_reserved1  = 26  // [31:6]
};

typedef struct VIC_VECT_CNTL15_BIT_Ttag {
	unsigned int INT_SOURCE : BFW_NETX_VIC_VECT_CTRL15_INT_SOURCE; // interrupt source select 
	unsigned int ENABLE     : BFW_NETX_VIC_VECT_CTRL15_ENABLE;     // vector interrupt enable 
	unsigned int reserved1  : BFW_NETX_VIC_VECT_CTRL15_reserved1;  // reserved
} VIC_VECT_CNTL15_BIT_T;

typedef union {
	unsigned int          val;
	VIC_VECT_CNTL15_BIT_T bf;
} VIC_VECT_CNTL15_T;


/*************************************************************************************/

#endif /* _VIC_H */
