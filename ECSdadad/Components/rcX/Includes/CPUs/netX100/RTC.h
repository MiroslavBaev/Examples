/******************************************************************************

  Copyright (C) 2010 [Hilscher Gesellschaft für Systemautomation mbH]

  This program can be used by everyone according to the netX Open Source
  Software license. The license agreement can be downloaded from
  http://www.industrialNETworX.com

*******************************************************************************

  Last Modification:
    @version $Id: RTC.h 333 2010-04-26 09:32:25Z Volker $

  Description:
    netX RTC definitions

  Changes:
    Date        Author        Description
  ---------------------------------------------------------------------------
    2010-03-24  NC            File created.

******************************************************************************/


#ifndef _RTC_H
#define _RTC_H


/*************************************************************************************/


// =====================================================================
//
// Area of rtc
//
// =====================================================================

#define NETX_RTC_AREA	0x00101200U


// ---------------------------------------------------------------------
// Register rtc_val
// => RTC 1Hz based value register
// => Mode: Mode (r/w)
// ---------------------------------------------------------------------

#define REL_NETX_RTC_1HZ_CNTR 0x00000000U
#define NETX_RTC_1HZ_CNTR     0x00101200U

#define MSK_NETX_RTC_1HZ_CNTR_VAL 0xffffffffU // [31:0]
#define SRT_NETX_RTC_1HZ_CNTR_VAL 0           

enum {
	BFW_NETX_RTC_1HZ_CNTR_VAL = 32  // [31:0]
};

typedef struct RTC_VAL_BIT_Ttag {
	unsigned int VAL : BFW_NETX_RTC_1HZ_CNTR_VAL; // 1Hz counter value 
} RTC_VAL_BIT_T;

typedef union {
	unsigned int  val;
	RTC_VAL_BIT_T bf;
} RTC_VAL_T;


// ---------------------------------------------------------------------
// Register rtc_32k
// => RTC 32KHz based value register
// => Mode: Mode (r)
// ---------------------------------------------------------------------

#define REL_NETX_RTC_32KHZ_CNTR_CUR_VAL 0x00000004U
#define NETX_RTC_32KHZ_CNTR_CUR_VAL     0x00101204U

#define MSK_NETX_RTC_32KHZ_CNTR_CUR_VAL_VAL 0xffffffffU // [31:0]
#define SRT_NETX_RTC_32KHZ_CNTR_CUR_VAL_VAL 0           

enum {
	BFW_NETX_RTC_32KHZ_CNTR_CUR_VAL_VAL = 32  // [31:0]
};

typedef struct RTC_32K_BIT_Ttag {
	unsigned int VAL : BFW_NETX_RTC_32KHZ_CNTR_CUR_VAL_VAL; // 32KHz counter value 
} RTC_32K_BIT_T;

typedef union {
	unsigned int  val;
	RTC_32K_BIT_T bf;
} RTC_32K_T;


// ---------------------------------------------------------------------
// Register rtc_32ks
// => RTC 32KHz based value register (sampled on Adr_RTC_VAL read)
// => Mode: Mode (r)
// ---------------------------------------------------------------------

#define REL_NETX_RTC_32KHZ_CNTR_LAT_VAL 0x00000008U
#define NETX_RTC_32KHZ_CNTR_LAT_VAL     0x00101208U

#define MSK_NETX_RTC_32KHZ_CNTR_LAT_VAL_VAL 0xffffffffU // [31:0]
#define SRT_NETX_RTC_32KHZ_CNTR_LAT_VAL_VAL 0           

enum {
	BFW_NETX_RTC_32KHZ_CNTR_LAT_VAL_VAL = 32  // [31:0]
};

typedef struct RTC_32KS_BIT_Ttag {
	unsigned int VAL : BFW_NETX_RTC_32KHZ_CNTR_LAT_VAL_VAL; // 32KHz counter value 
} RTC_32KS_BIT_T;

typedef union {
	unsigned int   val;
	RTC_32KS_BIT_T bf;
} RTC_32KS_T;

// ---------------------------------------------------------------------
// Register rtc_irq2isolate_cycles
// => Number of clock_32kHz cycles, between powergood goes low and activation of isolation of RTC and buffered SRAM.
//    During this time, ARM-software must write all data to buffered SRAM and deactivate outputs to isolated area.
//    As this value is stored inside the isolated area (that has no reset), the default value has to be programmed during startup.
//    After powergood goes low, the remaining 32kHz-clock-cycles until enter to isolation-mode can be read out.
// => Mode: Mode (w)
// ---------------------------------------------------------------------

#define REL_NETX_RTC_IRQ2ISOLATE_CYC 0x0000000CU
#define NETX_RTC_IRQ2ISOLATE_CYC     0x0010120CU

#define MSK_NETX_RTC_IRQ2ISOLATE_CYC_irq2iso 0x000000ffU // [7:0]
#define SRT_NETX_RTC_IRQ2ISOLATE_CYC_irq2iso 0           

enum {
	BFW_NETX_RTC_IRQ2ISOLATE_CYC_irq2iso   = 8,  // [7:0]
	BFW_NETX_RTC_IRQ2ISOLATE_CYC_reserved1 = 24  // [31:8]
};

typedef struct RTC_IRQ2ISOLATE_CYCLES_BIT_Ttag {
	unsigned int irq2iso   : BFW_NETX_RTC_IRQ2ISOLATE_CYC_irq2iso;   // number of clock_32kHz cycles 
	unsigned int reserved1 : BFW_NETX_RTC_IRQ2ISOLATE_CYC_reserved1; // reserved
} RTC_IRQ2ISOLATE_CYCLES_BIT_T;

typedef union {
	unsigned int                 val;
	RTC_IRQ2ISOLATE_CYCLES_BIT_T bf;
} RTC_IRQ2ISOLATE_CYCLES_T;

// ---------------------------------------------------------------------
// Register rtc_irq_mask
// => Isolated Area interrupt mask register
// => Mode: Mode (rw)
// ---------------------------------------------------------------------

#define REL_NETX_RTC_INT_MSK 0x00000010U
#define NETX_RTC_INT_MSK     0x00101210U

#define MSK_NETX_RTC_INT_MSK_en_power_down   0x00000001U // [0]
#define SRT_NETX_RTC_INT_MSK_en_power_down   0           
#define MSK_NETX_RTC_INT_MSK_en_clk32_fault1 0x00000002U // [1]
#define SRT_NETX_RTC_INT_MSK_en_clk32_fault1 1           
#define MSK_NETX_RTC_INT_MSK_en_clk32_fault2 0x00000004U // [2]
#define SRT_NETX_RTC_INT_MSK_en_clk32_fault2 2           

enum {
	BFW_NETX_RTC_INT_MSK_en_power_down   = 1,  // [0]
	BFW_NETX_RTC_INT_MSK_en_clk32_fault1 = 1,  // [1]
	BFW_NETX_RTC_INT_MSK_en_clk32_fault2 = 1,  // [2]
	BFW_NETX_RTC_INT_MSK_reserved1       = 29  // [31:3]
};

typedef struct RTC_IRQ_MASK_BIT_Ttag {
	unsigned int en_power_down   : BFW_NETX_RTC_INT_MSK_en_power_down;   // enable power_good interrupt  
	unsigned int en_clk32_fault1 : BFW_NETX_RTC_INT_MSK_en_clk32_fault1; // enable clk32_fault1 interrupt 
	unsigned int en_clk32_fault2 : BFW_NETX_RTC_INT_MSK_en_clk32_fault2; // enable clk32_fault2 interrupt 
	unsigned int reserved1       : BFW_NETX_RTC_INT_MSK_reserved1;       // reserved
} RTC_IRQ_MASK_BIT_T;

typedef union {
	unsigned int       val;
	RTC_IRQ_MASK_BIT_T bf;
} RTC_IRQ_MASK_T;

// ---------------------------------------------------------------------
// Register rtc_irq_stat
// => Isolated Area interrupt status register
//    writing 1 to a bit resets the Interrupt
// => Mode: Mode (rw)
// ---------------------------------------------------------------------

#define REL_NETX_RTC_INT_STAT 0x00000014U
#define NETX_RTC_INT_STAT     0x00101214U

#define MSK_NETX_RTC_INT_STAT_power_down   0x00000001U // [0]
#define SRT_NETX_RTC_INT_STAT_power_down   0           
#define MSK_NETX_RTC_INT_STAT_clk32_fault1 0x00000002U // [1]
#define SRT_NETX_RTC_INT_STAT_clk32_fault1 1           
#define MSK_NETX_RTC_INT_STAT_clk32_fault2 0x00000004U // [2]
#define SRT_NETX_RTC_INT_STAT_clk32_fault2 2           

enum {
	BFW_NETX_RTC_INT_STAT_power_down   = 1,  // [0]
	BFW_NETX_RTC_INT_STAT_clk32_fault1 = 1,  // [1]
	BFW_NETX_RTC_INT_STAT_clk32_fault2 = 1,  // [2]
	BFW_NETX_RTC_INT_STAT_reserved1    = 29  // [31:3]
};

typedef struct RTC_IRQ_STAT_BIT_Ttag {
	unsigned int power_down   : BFW_NETX_RTC_INT_STAT_power_down;   // power_good signal from external became 0, 
	unsigned int clk32_fault1 : BFW_NETX_RTC_INT_STAT_clk32_fault1; // if clk32 is not running, this bit will be set all 4096 system clock cycles (100MHz: 40,96us) 
	                                                        // After resetting this bit, the next interrupt will be generated not befor 4096 system clk cycles passed.
	unsigned int clk32_fault2 : BFW_NETX_RTC_INT_STAT_clk32_fault2; // if clk32 is not running, this bit will be set all 131072 (128k) system clock cycles (100MHz: 1.31ms) 
	                                                        // After resetting this bit, the next interrupt will be generated not befor 128k system clk cycles passed.
	unsigned int reserved1    : BFW_NETX_RTC_INT_STAT_reserved1;    // reserved
} RTC_IRQ_STAT_BIT_T;

typedef union {
	unsigned int       val;
	RTC_IRQ_STAT_BIT_T bf;
} RTC_IRQ_STAT_T;

// ---------------------------------------------------------------------
// Register rtc_isolated
// => Isolated Area is currently isolated:
//    write accesses to registers of RTC or BACKUP_RAM have no effect,
//    read accesses to registers of RTC will deliver 0, to BACKUP_RAM an abort
// => Mode: Mode (r)
// ---------------------------------------------------------------------

#define REL_NETX_RTC_ISOLATED 0x00000018U
#define NETX_RTC_ISOLATED     0x00101218U

#define MSK_NETX_RTC_ISOLATED_not_isolated 0x00000001U // [0]
#define SRT_NETX_RTC_ISOLATED_not_isolated 0           

enum {
	BFW_NETX_RTC_ISOLATED_not_isolated = 1,  // [0]
	BFW_NETX_RTC_ISOLATED_reserved1    = 31  // [31:1]
};

typedef struct RTC_ISOLATED_BIT_Ttag {
	unsigned int not_isolated : BFW_NETX_RTC_ISOLATED_not_isolated; // 0 : Isolated Area is currently isolated 
	                                                        // 1 : Isolated Area is currently not isolated
	                                                        // This bit will be set asynchronous by powergood (powergood must be stable at power on reset).
	                                                        // It will be set to zero rtc_irq2isolate_cycles 32khz clocks plus 2 (for synchronisation) after 
	                                                        // powergood-pin goes down. If this bit is 0, any access to backup SRAM will generate an abort (HRESP=1).
	                                                        // The ARM-CPU will switch to instruction or data abort mode!!! 
	                                                        // No valid access to backup SRAM and RTC-registers can be done in isolation mode!!!
	unsigned int reserved1    : BFW_NETX_RTC_ISOLATED_reserved1;    // reserved
} RTC_ISOLATED_BIT_T;

typedef union {
	unsigned int       val;
	RTC_ISOLATED_BIT_T bf;
} RTC_ISOLATED_T;


/*************************************************************************************/

#endif /* _RTC_H */
