/******************************************************************************

  Copyright (C) 2010 [Hilscher Gesellschaft für Systemautomation mbH]

  This program can be used by everyone according to the netX Open Source
  Software license. The license agreement can be downloaded from
  http://www.industrialNETworX.com

*******************************************************************************

  Last Modification:
    @version $Id: Mem.h 333 2010-04-26 09:32:25Z Volker $

  Description:
    netX MEM definitions

  Changes:
    Date        Author        Description
  ---------------------------------------------------------------------------
    2010-03-24  NC            File created.

******************************************************************************/


#ifndef _MEM_H
#define _MEM_H


/*************************************************************************************/


// =====================================================================
//
// Area of sram0_ahbls0
//
// =====================================================================

#define NETX_MEM_INTRN_SRAM0_AREA	0x00000000U

// ---------------------------------------------------------------------
// Register intram0_base
// => internal SRAM AHBL slave 0 start address
//    Area size: 32kB
//    Read accesses in this memory area: 0WS, byte accessable
//    Write accesses in this memory area: 0WS, byte accessable
// => Mode: Mode (r/w)
// ---------------------------------------------------------------------

#define REL_NETX_MEM_INTRN_SRAM0_BASE 0x00000000U
#define NETX_MEM_INTRN_SRAM0_BASE     0x00000000U

// ---------------------------------------------------------------------
// Register intram0_end
// => internal SRAM AHBL slave 0 end address
// => Mode: Mode (r/w)
// ---------------------------------------------------------------------

#define REL_NETX_MEM_INTRN_SRAM0_END 0x00007FFCU
#define NETX_MEM_INTRN_SRAM0_END     0x00007FFCU


// =====================================================================
//
// Area of sram1_ahbls1
//
// =====================================================================

#define NETX_MEM_INTRN_SRAM1_AREA	0x00008000U

// ---------------------------------------------------------------------
// Register intram1_base
// => internal SRAM AHBL slave 1 start address
//    Area size: 32kB
//    Read accesses in this memory area: 0WS, byte accessable
//    Write accesses in this memory area: 0WS, byte accessable
// => Mode: Mode (r/w)
// ---------------------------------------------------------------------

#define REL_NETX_MEM_INTRN_SRAM1_BASE 0x00000000U
#define NETX_MEM_INTRN_SRAM1_BASE     0x00008000U

// ---------------------------------------------------------------------
// Register intram1_end
// => internal SRAM AHBL slave 1 end address
// => Mode: Mode (r/w)
// ---------------------------------------------------------------------

#define REL_NETX_MEM_INTRN_SRAM1_END 0x00007FFCU
#define NETX_MEM_INTRN_SRAM1_END     0x0000FFFCU


// =====================================================================
//
// Area of sram2_ahbls2
//
// =====================================================================

#define NETX_MEM_INTRN_SRAM2_AREA	0x00010000U

// ---------------------------------------------------------------------
// Register intram2_base
// => internal SRAM AHBL slave 2 start address
//    Area size: 32kB
//    Read accesses in this memory area: 0WS, byte accessable
//    Write accesses in this memory area: 0WS, byte accessable
// => Mode: Mode (r/w)
// ---------------------------------------------------------------------

#define REL_NETX_MEM_INTRN_SRAM2_BASE 0x00000000U
#define NETX_MEM_INTRN_SRAM2_BASE     0x00010000U

// ---------------------------------------------------------------------
// Register intram2_end
// => internal SRAM AHBL slave 2 end address
// => Mode: Mode (r/w)
// ---------------------------------------------------------------------

#define REL_NETX_MEM_INTRN_SRAM2_END 0x00007FFCU
#define NETX_MEM_INTRN_SRAM2_END     0x00017FFCU


// =====================================================================
//
// Area of sram3_ahbls3
//
// =====================================================================

#define NETX_MEM_INTRN_SRAM3_AREA	0x00018000U

// ---------------------------------------------------------------------
// Register intram3_base
// => internal SRAM AHBL slave 3 start address
//    Area size: 32kB
//    Read accesses in this memory area: 0WS, byte accessable
//    Write accesses in this memory area: 0WS, byte accessable
// => Mode: Mode (r/w)
// ---------------------------------------------------------------------

#define REL_NETX_MEM_INTRN_SRAM3_BASE 0x00000000U
#define NETX_MEM_INTRN_SRAM3_BASE     0x00018000U

// ---------------------------------------------------------------------
// Register intram3_end
// => internal SRAM AHBL slave 3 end address
// => Mode: Mode (r/w)
// ---------------------------------------------------------------------

#define REL_NETX_MEM_INTRN_SRAM3_END 0x00007FFCU
#define NETX_MEM_INTRN_SRAM3_END     0x0001FFFCU


// =====================================================================
//
// Area of boot_rom
//
// =====================================================================

#define NETX_MEM_BOOT_ROM_AREA	0x00200000U

// ---------------------------------------------------------------------
// Register boot_rom_base
// => internal ROM start address
//    Area size: 32kB
//    Read accesses in this memory area: 0WS, byte accessable
//    ROM-content will be mirrored any 32kb between 0x00200000 and 0x002ffffc
// => Mode: Mode (r)
// ---------------------------------------------------------------------

#define REL_NETX_MEM_BOOT_ROM_BASE 0x00000000U
#define NETX_MEM_BOOT_ROM_BASE     0x00200000U

// ---------------------------------------------------------------------
// Register boot_rom_end
// => internal ROM end address
// => Mode: Mode (r)
// ---------------------------------------------------------------------

#define REL_NETX_MEM_BOOT_ROM_END 0x00007FFCU
#define NETX_MEM_BOOT_ROM_END     0x00207FFCU


// =====================================================================
//
// Area of backup_ram
//
// =====================================================================

#define NETX_MEM_BAK_SRAM_AREA	0x00300000U

// ---------------------------------------------------------------------
// Register backup_ram_base
// => internal battery buffered backup SRAM start address
//    Area size: 16kB
//    Read accesses in this memory area: 1WS, byte accessable
//    Write accesses in this memory area: 1WS, byte accessable
//    Power down backup ram will be locked like RTC by if register rtc_isolated signals isolation mode.
//    On accesses in isolation mode, ther will be an abort generated.
//    Power down backup ram-content will be mirrored any 16kb between 0x00300000 and 0x003ffffc
// => Mode: Mode (r/w)
// ---------------------------------------------------------------------

#define REL_NETX_MEM_BAK_SRAM_BASE 0x00000000U
#define NETX_MEM_BAK_SRAM_BASE     0x00300000U

// ---------------------------------------------------------------------
// Register backup_ram_end
// => internal battery buffered backup SRAM end address
// => Mode: Mode (r/w)
// ---------------------------------------------------------------------

#define REL_NETX_MEM_BAK_SRAM_END 0x00003FFCU
#define NETX_MEM_BAK_SRAM_END     0x00303FFCU



// =====================================================================
//
// Area of ext_asyncmem_ctrl
//
// =====================================================================

#define NETX_MEM_SRAM_CTRL_AREA	0x00100100U


// ---------------------------------------------------------------------
// Register extsram0_ctrl
// => Control Register for external bus interface and Waitstates for ExtMem0 chip select area
//    memory width coding like ARM-signals MAS / HSIZE[1:0]:
//    00=8bit
//    01=16bit
//    10=32bit
//    11=reserved
//    external addresses will be alligned (right shifted) according to the selected memory width
//    8 bit  -> no right shift of Aext
//    16 bit -> right shift Aext 1 bit
//    32 bit -> right shift Aext 2 bits
// => Mode: Mode (r/w)
// ---------------------------------------------------------------------

#define REL_NETX_MEM_SRAM0_CTRL 0x00000000U
#define NETX_MEM_SRAM0_CTRL     0x00100100U

#define MSK_NETX_MEM_SRAM0_CTRL_WSExtMem0          0x0000003fU // [5:0]
#define SRT_NETX_MEM_SRAM0_CTRL_WSExtMem0          0           
#define MSK_NETX_MEM_SRAM0_CTRL_WSPrePauseExtMem0  0x00000300U // [9:8]
#define SRT_NETX_MEM_SRAM0_CTRL_WSPrePauseExtMem0  8           
#define MSK_NETX_MEM_SRAM0_CTRL_WSPostPauseExtMem0 0x00030000U // [17:16]
#define SRT_NETX_MEM_SRAM0_CTRL_WSPostPauseExtMem0 16          
#define MSK_NETX_MEM_SRAM0_CTRL_WidthExtMem0       0x03000000U // [25:24]
#define SRT_NETX_MEM_SRAM0_CTRL_WidthExtMem0       24          

enum {
	BFW_NETX_MEM_SRAM0_CTRL_WSExtMem0          = 6, // [5:0]
	BFW_NETX_MEM_SRAM0_CTRL_reserved1          = 2, // [7:6]
	BFW_NETX_MEM_SRAM0_CTRL_WSPrePauseExtMem0  = 2, // [9:8]
	BFW_NETX_MEM_SRAM0_CTRL_reserved2          = 6, // [15:10]
	BFW_NETX_MEM_SRAM0_CTRL_WSPostPauseExtMem0 = 2, // [17:16]
	BFW_NETX_MEM_SRAM0_CTRL_reserved3          = 6, // [23:18]
	BFW_NETX_MEM_SRAM0_CTRL_WidthExtMem0       = 2, // [25:24]
	BFW_NETX_MEM_SRAM0_CTRL_reserved4          = 6  // [31:26]
};

typedef struct EXTSRAM0_CTRL_BIT_Ttag {
	unsigned int WSExtMem0          : BFW_NETX_MEM_SRAM0_CTRL_WSExtMem0;          // Waitstates 0 - 63 cycles 
	unsigned int reserved1          : BFW_NETX_MEM_SRAM0_CTRL_reserved1;          // reserved
	unsigned int WSPrePauseExtMem0  : BFW_NETX_MEM_SRAM0_CTRL_WSPrePauseExtMem0;  // additional Waitstates for setuptime nCS,Aext to nOE,nWE 0 - 3 cycles 
	unsigned int reserved2          : BFW_NETX_MEM_SRAM0_CTRL_reserved2;          // reserved
	unsigned int WSPostPauseExtMem0 : BFW_NETX_MEM_SRAM0_CTRL_WSPostPauseExtMem0; // additional Waitstates after access 0 - 3 cycles 
	unsigned int reserved3          : BFW_NETX_MEM_SRAM0_CTRL_reserved3;          // reserved
	unsigned int WidthExtMem0       : BFW_NETX_MEM_SRAM0_CTRL_WidthExtMem0;       // Datapath width of ExtMem0 area 
	unsigned int reserved4          : BFW_NETX_MEM_SRAM0_CTRL_reserved4;          // reserved
} EXTSRAM0_CTRL_BIT_T;

typedef union {
	unsigned int        val;
	EXTSRAM0_CTRL_BIT_T bf;
} EXTSRAM0_CTRL_T;


// ---------------------------------------------------------------------
// Register extsram1_ctrl
// => Control Register for external bus interface and Waitstates for ExtMem1 chip select area
//    memory width coding like ARM-signals MAS / HSIZE[1:0]:
//    00=8bit
//    01=16bit
//    10=32bit
//    11=reserved
//    external addresses will be alligned (right shifted) according to the selected memory width
//    8 bit  -> no right shift of Aext
//    16 bit -> right shift Aext 1 bit
//    32 bit -> right shift Aext 2 bits
// => Mode: Mode (r/w)
// ---------------------------------------------------------------------

#define REL_NETX_MEM_SRAM1_CTRL 0x00000004U
#define NETX_MEM_SRAM1_CTRL     0x00100104U

#define MSK_NETX_MEM_SRAM1_CTRL_WSExtMem1          0x0000003fU // [5:0]
#define SRT_NETX_MEM_SRAM1_CTRL_WSExtMem1          0           
#define MSK_NETX_MEM_SRAM1_CTRL_WSPrePauseExtMem1  0x00000300U // [9:8]
#define SRT_NETX_MEM_SRAM1_CTRL_WSPrePauseExtMem1  8           
#define MSK_NETX_MEM_SRAM1_CTRL_WSPostPauseExtMem1 0x00030000U // [17:16]
#define SRT_NETX_MEM_SRAM1_CTRL_WSPostPauseExtMem1 16          
#define MSK_NETX_MEM_SRAM1_CTRL_WidthExtMem1       0x03000000U // [25:24]
#define SRT_NETX_MEM_SRAM1_CTRL_WidthExtMem1       24          

enum {
	BFW_NETX_MEM_SRAM1_CTRL_WSExtMem1          = 6, // [5:0]
	BFW_NETX_MEM_SRAM1_CTRL_reserved1          = 2, // [7:6]
	BFW_NETX_MEM_SRAM1_CTRL_WSPrePauseExtMem1  = 2, // [9:8]
	BFW_NETX_MEM_SRAM1_CTRL_reserved2          = 6, // [15:10]
	BFW_NETX_MEM_SRAM1_CTRL_WSPostPauseExtMem1 = 2, // [17:16]
	BFW_NETX_MEM_SRAM1_CTRL_reserved3          = 6, // [23:18]
	BFW_NETX_MEM_SRAM1_CTRL_WidthExtMem1       = 2, // [25:24]
	BFW_NETX_MEM_SRAM1_CTRL_reserved4          = 6  // [31:26]
};

typedef struct EXTSRAM1_CTRL_BIT_Ttag {
	unsigned int WSExtMem1          : BFW_NETX_MEM_SRAM1_CTRL_WSExtMem1;          // Waitstates 0 - 63 cycles 
	unsigned int reserved1          : BFW_NETX_MEM_SRAM1_CTRL_reserved1;          // reserved
	unsigned int WSPrePauseExtMem1  : BFW_NETX_MEM_SRAM1_CTRL_WSPrePauseExtMem1;  // additional Waitstates for setuptime nCS,Aext to nOE,nWE 0 - 3 cycles 
	unsigned int reserved2          : BFW_NETX_MEM_SRAM1_CTRL_reserved2;          // reserved
	unsigned int WSPostPauseExtMem1 : BFW_NETX_MEM_SRAM1_CTRL_WSPostPauseExtMem1; // additional Waitstates after access 0 - 3 cycles 
	unsigned int reserved3          : BFW_NETX_MEM_SRAM1_CTRL_reserved3;          // reserved
	unsigned int WidthExtMem1       : BFW_NETX_MEM_SRAM1_CTRL_WidthExtMem1;       // Datapath width of ExtMem1 area 
	unsigned int reserved4          : BFW_NETX_MEM_SRAM1_CTRL_reserved4;          // reserved
} EXTSRAM1_CTRL_BIT_T;

typedef union {
	unsigned int        val;
	EXTSRAM1_CTRL_BIT_T bf;
} EXTSRAM1_CTRL_T;


// ---------------------------------------------------------------------
// Register extsram2_ctrl
// => Control Register for external bus interface and Waitstates for ExtMem2 chip select area
//    memory width coding like ARM-signals MAS / HSIZE[1:0]:
//    00=8bit
//    01=16bit
//    10=32bit
//    11=reserved
//    external addresses will be alligned (right shifted) according to the selected memory width
//    8 bit  -> no right shift of Aext
//    16 bit -> right shift Aext 1 bit
//    32 bit -> right shift Aext 2 bits
// => Mode: Mode (r/w)
// ---------------------------------------------------------------------

#define REL_NETX_MEM_SRAM2_CTRL 0x00000008U
#define NETX_MEM_SRAM2_CTRL     0x00100108U

#define MSK_NETX_MEM_SRAM2_CTRL_WSExtMem2          0x0000003fU // [5:0]
#define SRT_NETX_MEM_SRAM2_CTRL_WSExtMem2          0           
#define MSK_NETX_MEM_SRAM2_CTRL_WSPrePauseExtMem2  0x00000300U // [9:8]
#define SRT_NETX_MEM_SRAM2_CTRL_WSPrePauseExtMem2  8           
#define MSK_NETX_MEM_SRAM2_CTRL_WSPostPauseExtMem2 0x00030000U // [17:16]
#define SRT_NETX_MEM_SRAM2_CTRL_WSPostPauseExtMem2 16          
#define MSK_NETX_MEM_SRAM2_CTRL_WidthExtMem2       0x03000000U // [25:24]
#define SRT_NETX_MEM_SRAM2_CTRL_WidthExtMem2       24          

enum {
	BFW_NETX_MEM_SRAM2_CTRL_WSExtMem2          = 6, // [5:0]
	BFW_NETX_MEM_SRAM2_CTRL_reserved1          = 2, // [7:6]
	BFW_NETX_MEM_SRAM2_CTRL_WSPrePauseExtMem2  = 2, // [9:8]
	BFW_NETX_MEM_SRAM2_CTRL_reserved2          = 6, // [15:10]
	BFW_NETX_MEM_SRAM2_CTRL_WSPostPauseExtMem2 = 2, // [17:16]
	BFW_NETX_MEM_SRAM2_CTRL_reserved3          = 6, // [23:18]
	BFW_NETX_MEM_SRAM2_CTRL_WidthExtMem2       = 2, // [25:24]
	BFW_NETX_MEM_SRAM2_CTRL_reserved4          = 6  // [31:26]
};

typedef struct EXTSRAM2_CTRL_BIT_Ttag {
	unsigned int WSExtMem2          : BFW_NETX_MEM_SRAM2_CTRL_WSExtMem2;          // Waitstates 0 - 63 cycles 
	unsigned int reserved1          : BFW_NETX_MEM_SRAM2_CTRL_reserved1;          // reserved
	unsigned int WSPrePauseExtMem2  : BFW_NETX_MEM_SRAM2_CTRL_WSPrePauseExtMem2;  // additional Waitstates for setuptime nCS,Aext to nOE,nWE 0 - 3 cycles 
	unsigned int reserved2          : BFW_NETX_MEM_SRAM2_CTRL_reserved2;          // reserved
	unsigned int WSPostPauseExtMem2 : BFW_NETX_MEM_SRAM2_CTRL_WSPostPauseExtMem2; // additional Waitstates after access 0 - 3 cycles 
	unsigned int reserved3          : BFW_NETX_MEM_SRAM2_CTRL_reserved3;          // reserved
	unsigned int WidthExtMem2       : BFW_NETX_MEM_SRAM2_CTRL_WidthExtMem2;       // Datapath width of ExtMem2 area 
	unsigned int reserved4          : BFW_NETX_MEM_SRAM2_CTRL_reserved4;          // reserved
} EXTSRAM2_CTRL_BIT_T;

typedef union {
	unsigned int        val;
	EXTSRAM2_CTRL_BIT_T bf;
} EXTSRAM2_CTRL_T;


// ---------------------------------------------------------------------
// Register extsram3_ctrl
// => Control Register for external bus interface and Waitstates for ExtMem3 chip select area
//    memory width coding like ARM-signals MAS / HSIZE[1:0]:
//    00=8bit
//    01=16bit
//    10=32bit
//    11=reserved
//    external addresses will be alligned (right shifted) according to the selected memory width
//    8 bit  -> no right shift of Aext
//    16 bit -> right shift Aext 1 bit
//    32 bit -> right shift Aext 2 bits
// => Mode: Mode (r/w)
// ---------------------------------------------------------------------

#define REL_NETX_MEM_SRAM3_CTRL 0x0000000CU
#define NETX_MEM_SRAM3_CTRL     0x0010010CU

#define MSK_NETX_MEM_SRAM3_CTRL_WSExtMem3          0x0000003fU // [5:0]
#define SRT_NETX_MEM_SRAM3_CTRL_WSExtMem3          0           
#define MSK_NETX_MEM_SRAM3_CTRL_WSPrePauseExtMem3  0x00000300U // [9:8]
#define SRT_NETX_MEM_SRAM3_CTRL_WSPrePauseExtMem3  8           
#define MSK_NETX_MEM_SRAM3_CTRL_WSPostPauseExtMem3 0x00030000U // [17:16]
#define SRT_NETX_MEM_SRAM3_CTRL_WSPostPauseExtMem3 16          
#define MSK_NETX_MEM_SRAM3_CTRL_WidthExtMem3       0x03000000U // [25:24]
#define SRT_NETX_MEM_SRAM3_CTRL_WidthExtMem3       24          

enum {
	BFW_NETX_MEM_SRAM3_CTRL_WSExtMem3          = 6, // [5:0]
	BFW_NETX_MEM_SRAM3_CTRL_reserved1          = 2, // [7:6]
	BFW_NETX_MEM_SRAM3_CTRL_WSPrePauseExtMem3  = 2, // [9:8]
	BFW_NETX_MEM_SRAM3_CTRL_reserved2          = 6, // [15:10]
	BFW_NETX_MEM_SRAM3_CTRL_WSPostPauseExtMem3 = 2, // [17:16]
	BFW_NETX_MEM_SRAM3_CTRL_reserved3          = 6, // [23:18]
	BFW_NETX_MEM_SRAM3_CTRL_WidthExtMem3       = 2, // [25:24]
	BFW_NETX_MEM_SRAM3_CTRL_reserved4          = 6  // [31:26]
};

typedef struct EXTSRAM3_CTRL_BIT_Ttag {
	unsigned int WSExtMem3          : BFW_NETX_MEM_SRAM3_CTRL_WSExtMem3;          // Waitstates 0 - 63 cycles 
	unsigned int reserved1          : BFW_NETX_MEM_SRAM3_CTRL_reserved1;          // reserved
	unsigned int WSPrePauseExtMem3  : BFW_NETX_MEM_SRAM3_CTRL_WSPrePauseExtMem3;  // additional Waitstates for setuptime nCS,Aext to nOE,nWE 0 - 3 cycles 
	unsigned int reserved2          : BFW_NETX_MEM_SRAM3_CTRL_reserved2;          // reserved
	unsigned int WSPostPauseExtMem3 : BFW_NETX_MEM_SRAM3_CTRL_WSPostPauseExtMem3; // additional Waitstates after access 0 - 3 cycles 
	unsigned int reserved3          : BFW_NETX_MEM_SRAM3_CTRL_reserved3;          // reserved
	unsigned int WidthExtMem3       : BFW_NETX_MEM_SRAM3_CTRL_WidthExtMem3;       // Datapath width of ExtMem3 area 
	unsigned int reserved4          : BFW_NETX_MEM_SRAM3_CTRL_reserved4;          // reserved
} EXTSRAM3_CTRL_BIT_T;

typedef union {
	unsigned int        val;
	EXTSRAM3_CTRL_BIT_T bf;
} EXTSRAM3_CTRL_T;



// =====================================================================
//
// Area of ext_sdram_ctrl
//
// =====================================================================

#define NETX_MEM_SDRAM_CTRL_AREA	0x00100140U


// ---------------------------------------------------------------------
// Register sdram_general_ctrl
// => Control Register for external SDRAM access.
//    ----------------------------------------------------------
//    No DDR/DDR2 support in netX! Don't regard DDR/DDR2 options
//    ----------------------------------------------------------
// => Mode: Mode (r/w)
// ---------------------------------------------------------------------

#define REL_NETX_MEM_SDRAM_CFG_CTRL 0x00000000U
#define NETX_MEM_SDRAM_CFG_CTRL     0x00100140U

#define MSK_NETX_MEM_SDRAM_CFG_CTRL_banks         0x00000003U // [1:0]
#define SRT_NETX_MEM_SDRAM_CFG_CTRL_banks         0           
#define MSK_NETX_MEM_SDRAM_CFG_CTRL_rows          0x00000070U // [6:4]
#define SRT_NETX_MEM_SDRAM_CFG_CTRL_rows          4           
#define MSK_NETX_MEM_SDRAM_CFG_CTRL_columns       0x00000700U // [10:8]
#define SRT_NETX_MEM_SDRAM_CFG_CTRL_columns       8           
#define MSK_NETX_MEM_SDRAM_CFG_CTRL_dbus32        0x00010000U // [16]
#define SRT_NETX_MEM_SDRAM_CFG_CTRL_dbus32        16          
#define MSK_NETX_MEM_SDRAM_CFG_CTRL_sdram_pwdn    0x00020000U // [17]
#define SRT_NETX_MEM_SDRAM_CFG_CTRL_sdram_pwdn    17          
#define MSK_NETX_MEM_SDRAM_CFG_CTRL_extclk_en     0x00040000U // [18]
#define SRT_NETX_MEM_SDRAM_CFG_CTRL_extclk_en     18          
#define MSK_NETX_MEM_SDRAM_CFG_CTRL_ctrl_en       0x00080000U // [19]
#define SRT_NETX_MEM_SDRAM_CFG_CTRL_ctrl_en       19          
#define MSK_NETX_MEM_SDRAM_CFG_CTRL_refresh_mode  0x03000000U // [25:24]
#define SRT_NETX_MEM_SDRAM_CFG_CTRL_refresh_mode  24          
#define MSK_NETX_MEM_SDRAM_CFG_CTRL_sdram_ready   0x40000000U // [30]
#define SRT_NETX_MEM_SDRAM_CFG_CTRL_sdram_ready   30          
#define MSK_NETX_MEM_SDRAM_CFG_CTRL_refresh_error 0x80000000U // [31]
#define SRT_NETX_MEM_SDRAM_CFG_CTRL_refresh_error 31          

enum {
	BFW_NETX_MEM_SDRAM_CFG_CTRL_banks         = 2, // [1:0]
	BFW_NETX_MEM_SDRAM_CFG_CTRL_reserved1     = 2, // [3:2]
	BFW_NETX_MEM_SDRAM_CFG_CTRL_rows          = 3, // [6:4]
	BFW_NETX_MEM_SDRAM_CFG_CTRL_reserved2     = 1, // [7]
	BFW_NETX_MEM_SDRAM_CFG_CTRL_columns       = 3, // [10:8]
	BFW_NETX_MEM_SDRAM_CFG_CTRL_reserved3     = 5, // [15:11]
	BFW_NETX_MEM_SDRAM_CFG_CTRL_dbus32        = 1, // [16]
	BFW_NETX_MEM_SDRAM_CFG_CTRL_sdram_pwdn    = 1, // [17]
	BFW_NETX_MEM_SDRAM_CFG_CTRL_extclk_en     = 1, // [18]
	BFW_NETX_MEM_SDRAM_CFG_CTRL_ctrl_en       = 1, // [19]
	BFW_NETX_MEM_SDRAM_CFG_CTRL_reserved4     = 4, // [23:20]
	BFW_NETX_MEM_SDRAM_CFG_CTRL_refresh_mode  = 2, // [25:24]
	BFW_NETX_MEM_SDRAM_CFG_CTRL_reserved5     = 4, // [29:26]
	BFW_NETX_MEM_SDRAM_CFG_CTRL_sdram_ready   = 1, // [30]
	BFW_NETX_MEM_SDRAM_CFG_CTRL_refresh_error = 1  // [31]
};

typedef struct SDRAM_GENERAL_CTRL_BIT_Ttag {
	unsigned int banks         : BFW_NETX_MEM_SDRAM_CFG_CTRL_banks;         // bank address coding. 
	                                                        // 00 : 2
	                                                        // 01 : 4 (default)
	                                                        // 10 : 8
	                                                        // 11 : reserved
	                                                        // bank addresses are always mapped on A18 (=BA2), A17 (=BA1) and A16(BA0).
	unsigned int reserved1     : BFW_NETX_MEM_SDRAM_CFG_CTRL_reserved1;     // reserved
	unsigned int rows          : BFW_NETX_MEM_SDRAM_CFG_CTRL_rows;          // row address coding. 
	                                                        // 000 : 2k  (A0..A10) (default)
	                                                        // 001 : 4k  (A0..A11)
	                                                        // 010 : 8k  (A0..A12)
	                                                        // 011 : 16k (A0..A13)
	                                                        // 100 : 32k (A0..A14) (no devices today)
	                                                        // 101 : 64k (A0..A15) (no devices today)
	                                                        // 110 : reserved
	                                                        // 111 : reserved
	unsigned int reserved2     : BFW_NETX_MEM_SDRAM_CFG_CTRL_reserved2;     // reserved
	unsigned int columns       : BFW_NETX_MEM_SDRAM_CFG_CTRL_columns;       // column address coding. 
	                                                        // 000 : 256 (A0..A7) (default)
	                                                        // 001 : 512 (A0..A8)
	                                                        // 010 : 1k  (A0..A9)
	                                                        // 011 : 2k  (A0..A9,A11)
	                                                        // 100 : 4k  (A0..A9,A11,A12)
	                                                        // 101 : 8k  (A0..A9,A11..A13) (no devices today)
	                                                        // 110 : 16k (A0..A9,A11..A14) (no devices today)
	                                                        // 111 : reserved
	unsigned int reserved3     : BFW_NETX_MEM_SDRAM_CFG_CTRL_reserved3;     // reserved
	unsigned int dbus32        : BFW_NETX_MEM_SDRAM_CFG_CTRL_dbus32;        // SDRAM data bus width 
	                                                        // 0: SDRAM Data bus is 16 bit wide.  (default)
	                                                        // 1: SDRAM data bus is 32 bit wide.
	unsigned int sdram_pwdn    : BFW_NETX_MEM_SDRAM_CFG_CTRL_sdram_pwdn;    // SDRAM Power Down 
	                                                        // If this bit is set, the Controller will move SDRAM to power down self refresh mode (no data loss)
	                                                        // and stop the external SDRAM clock. After resetting this bit, for DDR and DDR2 device types
	                                                        // a 200 clk DLLs startup pause will be done.
	unsigned int extclk_en     : BFW_NETX_MEM_SDRAM_CFG_CTRL_extclk_en;     // external SDRAM clock enable 
	unsigned int ctrl_en       : BFW_NETX_MEM_SDRAM_CFG_CTRL_ctrl_en;       // SDRAM controller enable 
	                                                        // The sdram_timing_ctrl-register can only be changed while this bit is 0.
	                                                        // ------------------------------------
	                                                        // After enable, the controller will run the following SDRAM initialisation procedure (100MHz, t_clk = 10ns).
	                                                        //    NOP (200us = 20,000t_clk, running sd_clk (if extclk_en), n_cs low, cke high)
	                                                        //    PRECHARGE ALL
	                                                        //    NOP (160ns = 16t_clk)
	                                                        //    7x (AUTO REFRESH, NOP (310ns = 31t_clk))
	                                                        //    AUTO REFRESH
	                                                        //    NOP (220ns = 22t_clk)
	                                                        //    LOAD MODE REGISTER (with settings done by these config registers)
	                                                        //    NOP (40ns = 4t_clk)
	                                                        //    ACTIVATE (for first access, if requested, sdram_ready will be set to 1 here)
	                                                        // ------------------------------------
	                                                        // Accesses requested before sdram_ready is 1 will be blocked (no ready).
	                                                        // The external SDRAM-clk will not run if the controller is disabled.
	unsigned int reserved4     : BFW_NETX_MEM_SDRAM_CFG_CTRL_reserved4;     // reserved
	unsigned int refresh_mode  : BFW_NETX_MEM_SDRAM_CFG_CTRL_refresh_mode;  // Refresh priortity mode 
	                                                        // If refresh has not highest priority and , it was not possible to generate the Refresh command in cause
	                                                        // of to much data accesses, refresh will become highest priority for no data loss.
	                                                        // In this case, the bit sdram_ctrl_general,refresh_error will be set to 1.
	                                                        // if it was not possible to generate the Refresh command in cause of to much data accesses.
	                                                        // 00 : fix intervall any t_REFI us (refresh has highest priority)
	                                                        // 01 : collect up to 8 refreshes (for DDR, DDR2, data access has higher priority than refresh, default)
	                                                        // 10 : collect up to 16 refreshes (data access has higher priority than refresh)
	                                                        // 11 : collect up to 2047 refreshes (for SDR only, data access has higher priority than refresh)
	unsigned int reserved5     : BFW_NETX_MEM_SDRAM_CFG_CTRL_reserved5;     // reserved
	unsigned int sdram_ready   : BFW_NETX_MEM_SDRAM_CFG_CTRL_sdram_ready;   // SDRAM Ready. 
	                                                        // This bit is set to 1 if SDRAM is ready for access. If sdram_general_ctrl.ctrl_en == 0 or
	                                                        // sdram_general_ctrl.sdram_pwdn == 0, sdram_ready will be low. It will be set to 1 after
	                                                        // SDRAM has been initialized or after power down wake up.
	unsigned int refresh_error : BFW_NETX_MEM_SDRAM_CFG_CTRL_refresh_error; // Refresh not achieved for debug purpose 
	                                                        // If refresh has not highest priority, (sdram_ctrl_timing.refresh_mode), this bit will be set to 1
	                                                        // when it was not possible to generate the Refresh command in cause of to much data accesses.
	                                                        // The SDRAM-Controller will only set this bit. It can be resetted by writing '0' to it.
} SDRAM_GENERAL_CTRL_BIT_T;

typedef union {
	unsigned int             val;
	SDRAM_GENERAL_CTRL_BIT_T bf;
} SDRAM_GENERAL_CTRL_T;


// ---------------------------------------------------------------------
// Register sdram_timing_ctrl
// => Control Register for external SDRAM access.
//    Changes can only be done, if the SDRAM-Controller is disabled (sdram_general_ctrl.ctrl_en == 0)
//    to avoid configuration problems.
//    ----------------------------------------------------------
//    No DDR/DDR2 support in netX! Don't regard DDR/DDR2 options
//    ----------------------------------------------------------
// => Mode: Mode (r/w)
// ---------------------------------------------------------------------

#define REL_NETX_MEM_SDRAM_TIMING_CTRL 0x00000004U
#define NETX_MEM_SDRAM_TIMING_CTRL     0x00100144U

#define MSK_NETX_MEM_SDRAM_TIMING_CTRL_t_RCD             0x00000003U // [1:0]
#define SRT_NETX_MEM_SDRAM_TIMING_CTRL_t_RCD             0           
#define MSK_NETX_MEM_SDRAM_TIMING_CTRL_t_WR              0x00000030U // [5:4]
#define SRT_NETX_MEM_SDRAM_TIMING_CTRL_t_WR              4           
#define MSK_NETX_MEM_SDRAM_TIMING_CTRL_t_RP              0x000000c0U // [7:6]
#define SRT_NETX_MEM_SDRAM_TIMING_CTRL_t_RP              6           
#define MSK_NETX_MEM_SDRAM_TIMING_CTRL_t_RAS             0x00000700U // [10:8]
#define SRT_NETX_MEM_SDRAM_TIMING_CTRL_t_RAS             8           
#define MSK_NETX_MEM_SDRAM_TIMING_CTRL_t_RFC             0x0000f000U // [15:12]
#define SRT_NETX_MEM_SDRAM_TIMING_CTRL_t_RFC             12          
#define MSK_NETX_MEM_SDRAM_TIMING_CTRL_t_REFI            0x00030000U // [17:16]
#define SRT_NETX_MEM_SDRAM_TIMING_CTRL_t_REFI            16          
#define MSK_NETX_MEM_SDRAM_TIMING_CTRL_mem_sdclk_phase   0x00700000U // [22:20]
#define SRT_NETX_MEM_SDRAM_TIMING_CTRL_mem_sdclk_phase   20          
#define MSK_NETX_MEM_SDRAM_TIMING_CTRL_mem_sdclk_ssneg   0x00800000U // [23]
#define SRT_NETX_MEM_SDRAM_TIMING_CTRL_mem_sdclk_ssneg   23          
#define MSK_NETX_MEM_SDRAM_TIMING_CTRL_data_sample_phase 0x07000000U // [26:24]
#define SRT_NETX_MEM_SDRAM_TIMING_CTRL_data_sample_phase 24          
#define MSK_NETX_MEM_SDRAM_TIMING_CTRL_bypass_neg_delay  0x10000000U // [28]
#define SRT_NETX_MEM_SDRAM_TIMING_CTRL_bypass_neg_delay  28          

enum {
	BFW_NETX_MEM_SDRAM_TIMING_CTRL_t_RCD             = 2, // [1:0]
	BFW_NETX_MEM_SDRAM_TIMING_CTRL_reserved1         = 2, // [3:2]
	BFW_NETX_MEM_SDRAM_TIMING_CTRL_t_WR              = 2, // [5:4]
	BFW_NETX_MEM_SDRAM_TIMING_CTRL_t_RP              = 2, // [7:6]
	BFW_NETX_MEM_SDRAM_TIMING_CTRL_t_RAS             = 3, // [10:8]
	BFW_NETX_MEM_SDRAM_TIMING_CTRL_reserved2         = 1, // [11]
	BFW_NETX_MEM_SDRAM_TIMING_CTRL_t_RFC             = 4, // [15:12]
	BFW_NETX_MEM_SDRAM_TIMING_CTRL_t_REFI            = 2, // [17:16]
	BFW_NETX_MEM_SDRAM_TIMING_CTRL_reserved3         = 2, // [19:18]
	BFW_NETX_MEM_SDRAM_TIMING_CTRL_mem_sdclk_phase   = 3, // [22:20]
	BFW_NETX_MEM_SDRAM_TIMING_CTRL_mem_sdclk_ssneg   = 1, // [23]
	BFW_NETX_MEM_SDRAM_TIMING_CTRL_data_sample_phase = 3, // [26:24]
	BFW_NETX_MEM_SDRAM_TIMING_CTRL_reserved4         = 1, // [27]
	BFW_NETX_MEM_SDRAM_TIMING_CTRL_bypass_neg_delay  = 1, // [28]
	BFW_NETX_MEM_SDRAM_TIMING_CTRL_reserved5         = 3  // [31:29]
};

typedef struct SDRAM_TIMING_CTRL_BIT_Ttag {
	unsigned int t_RCD             : BFW_NETX_MEM_SDRAM_TIMING_CTRL_t_RCD;             // Active to Read or Write time (RAS to CAS, clk = t_RCD) 
	                                                        // This value will be also taken as t_RRD (Active bank A to Active bank B time)
	                                                        // 00 : 1 clk
	                                                        // 01 : 2 clks
	                                                        // 10 : 3 clks (default)
	                                                        // 11 : reserved
	unsigned int reserved1         : BFW_NETX_MEM_SDRAM_TIMING_CTRL_reserved1;         // reserved
	unsigned int t_WR              : BFW_NETX_MEM_SDRAM_TIMING_CTRL_t_WR;              // Write recovery time (last write data to Precharge) 
	                                                        // 00 : 1 clk
	                                                        // 01 : 2 clks
	                                                        // 10 : 3 clks (default)
	                                                        // 11 : reserved
	unsigned int t_RP              : BFW_NETX_MEM_SDRAM_TIMING_CTRL_t_RP;              // Precharge command period time (Precharge to command) 
	                                                        // 00 : 1 clk
	                                                        // 01 : 2 clks
	                                                        // 10 : 3 clks (default)
	                                                        // 11 : reserved
	unsigned int t_RAS             : BFW_NETX_MEM_SDRAM_TIMING_CTRL_t_RAS;             // Active to Precharge command time (clk = t_RAS + 3) 
	                                                        // 000 :  3 clks
	                                                        // 001 :  4 clks
	                                                        // and so on
	                                                        // 111 : 10 clks (default)
	unsigned int reserved2         : BFW_NETX_MEM_SDRAM_TIMING_CTRL_reserved2;         // reserved
	unsigned int t_RFC             : BFW_NETX_MEM_SDRAM_TIMING_CTRL_t_RFC;             // Refresh to Command time (clk = tRFC + 4) 
	                                                        // 0000 :  4 clks
	                                                        // 0001 :  5 clks
	                                                        // and so on
	                                                        // 1111 :  19 clks (default)
	unsigned int t_REFI            : BFW_NETX_MEM_SDRAM_TIMING_CTRL_t_REFI;            // Average Periodic refresh interval (3.90 us * 2^t_REFI 
	                                                        // 00 :   3.90 us
	                                                        // 01 :   7.80 us (default)
	                                                        // 10 :  15.60 us
	                                                        // 11 :  31.20 us
	unsigned int reserved3         : BFW_NETX_MEM_SDRAM_TIMING_CTRL_reserved3;         // reserved
	unsigned int mem_sdclk_phase   : BFW_NETX_MEM_SDRAM_TIMING_CTRL_mem_sdclk_phase;   // 0..5: adjustable phase-shift for external SDRAM clock depending on external capacitive 
	                                                        // load on mem_sdclk-signal to match SDRAM ctrl-signal setup times. The phase can be shiftet in 1.25ns steps.
	                                                        // mem_sdlk will internally rise at the mem_sdclk_phase+2nd clk400 edge after internal changes of 
	                                                        // SDRAM ctrl-signals (mem_sd*-signals, driven by clk_memsig), where the 1st egde is defined by the 
	                                                        // mem_sdclk_ssneg-bit.
	                                                        // For correct settings, delays depending on external capacitive have to be respected.
	unsigned int mem_sdclk_ssneg   : BFW_NETX_MEM_SDRAM_TIMING_CTRL_mem_sdclk_ssneg;   // 1: clk_memsig will be sampled for mem_sdclk-generation internally first on negedge of clk400 
	                                                        // 0: clk_memsig will be sampled for mem_sdclk-generation internally first on posedge of clk400
	unsigned int data_sample_phase : BFW_NETX_MEM_SDRAM_TIMING_CTRL_data_sample_phase; // 0..5: adjustable phase-shift for data sampling SDRAM loopback clock (clk_sdloopback) 
	                                                        // depending external capacitive load and SDRAM access time (t_AC). The phase can be shiftet in 1.25ns steps.
	                                                        // clk_sdloopback will internally rise (sample SDRAM read data) at the data_sample_phase+4th clk400 edge 
	                                                        // after rise of external mem_sdclk (including external capacitive load).
	                                                        // For correct settings, the delays depending on external capacitive have to be respected.
	                                                        // Data sampling has to be done at least 8ns after internal changes of SDRAM ctrl-signals (mem_sd*-signals, 
	                                                        // driven by clk_memsig) .
	unsigned int reserved4         : BFW_NETX_MEM_SDRAM_TIMING_CTRL_reserved4;         // reserved
	unsigned int bypass_neg_delay  : BFW_NETX_MEM_SDRAM_TIMING_CTRL_bypass_neg_delay;  // 0: use phase shifted (negative delayed) SDRAM loopback clock for data sampling. 
	                                                        // 1: bypass phase shift logic for SDRAM data sampling use SDRAM loopback clock for data sampling
	unsigned int reserved5         : BFW_NETX_MEM_SDRAM_TIMING_CTRL_reserved5;         // reserved
} SDRAM_TIMING_CTRL_BIT_T;

typedef union {
	unsigned int            val;
	SDRAM_TIMING_CTRL_BIT_T bf;
} SDRAM_TIMING_CTRL_T;


// ---------------------------------------------------------------------
// Register sdram_mr
// => Moder Register for all SDRAM-devicetypes and Extended Mode Register for DDR/DDR2-SDRAM-devices.
//    Changes can only be done, if the SDRAM-Controller is disabled (sdram_general_ctrl.ctrl_en == 0)
//    to avoid configuration problems.
//    The SDRAM Mode Registers will be set after enabling the SDRAM Controller in the 200us
//    SDRAM memory initialisation procedure.
//    ----------------------------------------------------------
//    No DDR/DDR2 support in netX! Don't regard DDR/DDR2 options
//    ----------------------------------------------------------
// => Mode: Mode (r/w)
// ---------------------------------------------------------------------

#define REL_NETX_MEM_SDRAM_MODE 0x00000008U
#define NETX_MEM_SDRAM_MODE     0x00100148U

#define MSK_NETX_MEM_SDRAM_MODE_MR  0x00003fffU // [13:0]
#define SRT_NETX_MEM_SDRAM_MODE_MR  0           
#define MSK_NETX_MEM_SDRAM_MODE_EMR 0x3fff0000U // [29:16]
#define SRT_NETX_MEM_SDRAM_MODE_EMR 16          

enum {
	BFW_NETX_MEM_SDRAM_MODE_MR        = 14, // [13:0]
	BFW_NETX_MEM_SDRAM_MODE_reserved1 = 2,  // [15:14]
	BFW_NETX_MEM_SDRAM_MODE_EMR       = 14, // [29:16]
	BFW_NETX_MEM_SDRAM_MODE_reserved2 = 2   // [31:30]
};

typedef struct SDRAM_MR_BIT_Ttag {
	unsigned int MR        : BFW_NETX_MEM_SDRAM_MODE_MR;        // SDRAM Mode Register. 
	                                                        // CAS latency bits in modereg[6:4]; default CL3
	                                                        // The controller supports only Burst Length 8 on dq16 an 4 on dq32 (default)
	                                                        // SDRAM DLL reset on initiaisation procedure is done by modereg[8]
	unsigned int reserved1 : BFW_NETX_MEM_SDRAM_MODE_reserved1; // reserved
	unsigned int EMR       : BFW_NETX_MEM_SDRAM_MODE_EMR;       // Extended Mode Register for DDR/DDR2 - SDRAM devices 
	                                                        // The following settings must not be changed because tey are not supported by the Controller:
	                                                        // Additive Latency (EMR[5:3]) - fix to AL 0
	                                                        // nDQS (EMR[10]) - always disabled
	                                                        // RDQS (EMR[12]) - always disabled
	unsigned int reserved2 : BFW_NETX_MEM_SDRAM_MODE_reserved2; // reserved
} SDRAM_MR_BIT_T;

typedef union {
	unsigned int   val;
	SDRAM_MR_BIT_T bf;
} SDRAM_MR_T;


// ---------------------------------------------------------------------
// Register sdram_emr2
// => Extended Mode Registers EMR2 and EMR3 for DDR2 - SDRAM devices.
//    Changes can only be done, if the SDRAM-Controller is disabled (sdram_general_ctrl.ctrl_en == 0)
//    to avoid configuration problems.
//    The SDRAM Mode Registers will be set after enabling the SDRAM Controller in the 200us
//    SDRAM memory initialisation procedure.
//    ----------------------------------------------------------
//    No DDR/DDR2 support in netX! Don't regard DDR/DDR2 options
//    ----------------------------------------------------------
// => Mode: Mode (r/w)
// ---------------------------------------------------------------------

#define REL_NETX_MEM_SDRAM_EXT_MODE 0x0000000CU
#define NETX_MEM_SDRAM_EXT_MODE     0x0010014CU

#define MSK_NETX_MEM_SDRAM_EXT_MODE_EMR2 0x00003fffU // [13:0]
#define SRT_NETX_MEM_SDRAM_EXT_MODE_EMR2 0           
#define MSK_NETX_MEM_SDRAM_EXT_MODE_EMR3 0x3fff0000U // [29:16]
#define SRT_NETX_MEM_SDRAM_EXT_MODE_EMR3 16          

enum {
	BFW_NETX_MEM_SDRAM_EXT_MODE_EMR2      = 14, // [13:0]
	BFW_NETX_MEM_SDRAM_EXT_MODE_reserved1 = 2,  // [15:14]
	BFW_NETX_MEM_SDRAM_EXT_MODE_EMR3      = 14, // [29:16]
	BFW_NETX_MEM_SDRAM_EXT_MODE_reserved2 = 2   // [31:30]
};

typedef struct SDRAM_EMR2_BIT_Ttag {
	unsigned int EMR2      : BFW_NETX_MEM_SDRAM_EXT_MODE_EMR2;      // Extended Mode Register 2 for DDR2 - SDRAM devices 
	                                                        // For further extensions. No Settings must be done, which affect non supported
	                                                        // SDRAM-Controller features.
	unsigned int reserved1 : BFW_NETX_MEM_SDRAM_EXT_MODE_reserved1; // reserved
	unsigned int EMR3      : BFW_NETX_MEM_SDRAM_EXT_MODE_EMR3;      // Extended Mode Register 3 for DDR2 - SDRAM devices 
	                                                        // For further extensions. No Settings must be done, which affect non supported
	                                                        // SDRAM-Controller features.
	unsigned int reserved2 : BFW_NETX_MEM_SDRAM_EXT_MODE_reserved2; // reserved
} SDRAM_EMR2_BIT_T;

typedef union {
	unsigned int     val;
	SDRAM_EMR2_BIT_T bf;
} SDRAM_EMR2_T;



// =====================================================================
//
// Area of extmem_priority_ctrl
//
// =====================================================================

#define NETX_MEM_PRIO_CTRL_AREA	0x00100180U


// ---------------------------------------------------------------------
// Register extmem_prio_timslot_ctrl
// => Memory interface master timeslot priority control register.
//    This register may be partially locked by the exmem_priority_lock-register in asic_ctrl-address area.
//    Note:
//    Any master can access in one timeslot ((ts_accessrate_mX*ts_length_mX)/64) + 1 times (i.e. at 
//    maximum (ts_accessrate_mX)/64 bandwidth on external memory bus, ts_accessrate_mX is programmed 
//    by extmem_prio_accesstime_ctrl-register).
//    Priority control will watch data accesses on external memory data bus (SDRAM and non SDRAM), 
//    including pauses on non SDRAM-accesses, not including control commands to SDRAM.
//    Any master requesting more accesses will be forced to wait for the remaining timeslot.
//    --------------------------------------------------------
//    Programmable timeslots are:
//    ts_length =  0 :             64 systen clock cycles (i.e  0.64us at 100MHz)
//    ts_length =  1 :            128 systen clock cycles (i.e  1.28us at 100MHz)
//    ts_length =  2 :            256 systen clock cycles (i.e  2.56us at 100MHz)
//    ts_length =  3 :            512 systen clock cycles (i.e  5.12us at 100MHz)
//    ts_length =  4 :           1024 systen clock cycles (i.e 10.24us at 100MHz)
//    ts_length =  5 :           2048 systen clock cycles (i.e 20.48us at 100MHz)
//    ts_length =  6 :           4096 systen clock cycles (i.e 40.96us at 100MHz)
//    ts_length =  7 :           8192 systen clock cycles (i.e 81.92us at 100MHz)
//    --------------------------------------------------------
//    master channel m0: Host Bus Interface  (highest priority)
//    master channel m1: XC
//    master channel m2: LCD-Controller
//    master channel m3: ARM instruction channel
//    master channel m4: ARM data channel  (lowest priority)
// => Mode: Mode (r/w)
// ---------------------------------------------------------------------

#define REL_NETX_MEM_PRIO_TIMESLOT_CTRL 0x00000000U
#define NETX_MEM_PRIO_TIMESLOT_CTRL     0x00100180U

#define MSK_NETX_MEM_PRIO_TIMESLOT_CTRL_ts_length_HIF_mi  0x00000007U // [2:0]
#define SRT_NETX_MEM_PRIO_TIMESLOT_CTRL_ts_length_HIF_mi  0           
#define MSK_NETX_MEM_PRIO_TIMESLOT_CTRL_ts_length_XC_mi   0x00000070U // [6:4]
#define SRT_NETX_MEM_PRIO_TIMESLOT_CTRL_ts_length_XC_mi   4           
#define MSK_NETX_MEM_PRIO_TIMESLOT_CTRL_ts_length_LCD_mi  0x00000700U // [10:8]
#define SRT_NETX_MEM_PRIO_TIMESLOT_CTRL_ts_length_LCD_mi  8           
#define MSK_NETX_MEM_PRIO_TIMESLOT_CTRL_ts_length_ARMI_mi 0x00007000U // [14:12]
#define SRT_NETX_MEM_PRIO_TIMESLOT_CTRL_ts_length_ARMI_mi 12          
#define MSK_NETX_MEM_PRIO_TIMESLOT_CTRL_ts_length_ARMD_mi 0x00070000U // [18:16]
#define SRT_NETX_MEM_PRIO_TIMESLOT_CTRL_ts_length_ARMD_mi 16          

enum {
	BFW_NETX_MEM_PRIO_TIMESLOT_CTRL_ts_length_HIF_mi  = 3,  // [2:0]
	BFW_NETX_MEM_PRIO_TIMESLOT_CTRL_reserved1         = 1,  // [3]
	BFW_NETX_MEM_PRIO_TIMESLOT_CTRL_ts_length_XC_mi   = 3,  // [6:4]
	BFW_NETX_MEM_PRIO_TIMESLOT_CTRL_reserved2         = 1,  // [7]
	BFW_NETX_MEM_PRIO_TIMESLOT_CTRL_ts_length_LCD_mi  = 3,  // [10:8]
	BFW_NETX_MEM_PRIO_TIMESLOT_CTRL_reserved3         = 1,  // [11]
	BFW_NETX_MEM_PRIO_TIMESLOT_CTRL_ts_length_ARMI_mi = 3,  // [14:12]
	BFW_NETX_MEM_PRIO_TIMESLOT_CTRL_reserved4         = 1,  // [15]
	BFW_NETX_MEM_PRIO_TIMESLOT_CTRL_ts_length_ARMD_mi = 3,  // [18:16]
	BFW_NETX_MEM_PRIO_TIMESLOT_CTRL_reserved5         = 13  // [31:19]
};

typedef struct EXTMEM_PRIO_TIMSLOT_CTRL_BIT_Ttag {
	unsigned int ts_length_HIF_mi  : BFW_NETX_MEM_PRIO_TIMESLOT_CTRL_ts_length_HIF_mi;  // 0..7: the timeslot of master m0 is on external memory interface 64*2^ts_length_HIF_mi systen clock cycles  
	unsigned int reserved1         : BFW_NETX_MEM_PRIO_TIMESLOT_CTRL_reserved1;         // reserved
	unsigned int ts_length_XC_mi   : BFW_NETX_MEM_PRIO_TIMESLOT_CTRL_ts_length_XC_mi;   // 0..7: the timeslot of master m1 is on external memory interface 64*2^ts_length_XC_mi systen clock cycles  
	unsigned int reserved2         : BFW_NETX_MEM_PRIO_TIMESLOT_CTRL_reserved2;         // reserved
	unsigned int ts_length_LCD_mi  : BFW_NETX_MEM_PRIO_TIMESLOT_CTRL_ts_length_LCD_mi;  // 0..7: the timeslot of master m2 is on external memory interface 64*2^ts_length_LCD_mi systen clock cycles  
	unsigned int reserved3         : BFW_NETX_MEM_PRIO_TIMESLOT_CTRL_reserved3;         // reserved
	unsigned int ts_length_ARMI_mi : BFW_NETX_MEM_PRIO_TIMESLOT_CTRL_ts_length_ARMI_mi; // 0..7: the timeslot of master m3 is on external memory interface 64*2^ts_length_ARMI_mi systen clock cycles  
	unsigned int reserved4         : BFW_NETX_MEM_PRIO_TIMESLOT_CTRL_reserved4;         // reserved
	unsigned int ts_length_ARMD_mi : BFW_NETX_MEM_PRIO_TIMESLOT_CTRL_ts_length_ARMD_mi; // 0..7: the timeslot of master m4 is on external memory interface 64*2^ts_length_ARMD_mi systen clock cycles  
	unsigned int reserved5         : BFW_NETX_MEM_PRIO_TIMESLOT_CTRL_reserved5;         // reserved
} EXTMEM_PRIO_TIMSLOT_CTRL_BIT_T;

typedef union {
	unsigned int                   val;
	EXTMEM_PRIO_TIMSLOT_CTRL_BIT_T bf;
} EXTMEM_PRIO_TIMSLOT_CTRL_T;


// ---------------------------------------------------------------------
// Register extmem_prio_accesstime_ctrl
// => Control Register for master channel accesses per timeslot on external meory interface.
//    This register may be partially locked by the exmem_priority_lock-register in asic_ctrl-address area.
//    For detailed priority controlling read note at extmem_prio_timslot_ctrl-register description.
//    --------------------------------------------------------
//    master channel m0: Host Bus Interface  (highest priority)
//    master channel m1: XC
//    master channel m2: LCD-Controller
//    master channel m3: ARM instruction channel
//    master channel m4: ARM data channel  (lowest priority)
// => Mode: Mode (r/w)
// ---------------------------------------------------------------------

#define REL_NETX_MEM_PRIO_ACCESS_CTRL 0x00000004U
#define NETX_MEM_PRIO_ACCESS_CTRL     0x00100184U

#define MSK_NETX_MEM_PRIO_ACCESS_CTRL_ts_accessrate_HIF_mi  0x0000003fU // [5:0]
#define SRT_NETX_MEM_PRIO_ACCESS_CTRL_ts_accessrate_HIF_mi  0           
#define MSK_NETX_MEM_PRIO_ACCESS_CTRL_ts_accessrate_XC_mi   0x00000fc0U // [11:6]
#define SRT_NETX_MEM_PRIO_ACCESS_CTRL_ts_accessrate_XC_mi   6           
#define MSK_NETX_MEM_PRIO_ACCESS_CTRL_ts_accessrate_LCD_mi  0x0003f000U // [17:12]
#define SRT_NETX_MEM_PRIO_ACCESS_CTRL_ts_accessrate_LCD_mi  12          
#define MSK_NETX_MEM_PRIO_ACCESS_CTRL_ts_accessrate_ARMI_mi 0x00fc0000U // [23:18]
#define SRT_NETX_MEM_PRIO_ACCESS_CTRL_ts_accessrate_ARMI_mi 18          
#define MSK_NETX_MEM_PRIO_ACCESS_CTRL_ts_accessrate_ARMD_mi 0x3f000000U // [29:24]
#define SRT_NETX_MEM_PRIO_ACCESS_CTRL_ts_accessrate_ARMD_mi 24          

enum {
	BFW_NETX_MEM_PRIO_ACCESS_CTRL_ts_accessrate_HIF_mi  = 6, // [5:0]
	BFW_NETX_MEM_PRIO_ACCESS_CTRL_ts_accessrate_XC_mi   = 6, // [11:6]
	BFW_NETX_MEM_PRIO_ACCESS_CTRL_ts_accessrate_LCD_mi  = 6, // [17:12]
	BFW_NETX_MEM_PRIO_ACCESS_CTRL_ts_accessrate_ARMI_mi = 6, // [23:18]
	BFW_NETX_MEM_PRIO_ACCESS_CTRL_ts_accessrate_ARMD_mi = 6, // [29:24]
	BFW_NETX_MEM_PRIO_ACCESS_CTRL_reserved1             = 2  // [31:30]
};

typedef struct EXTMEM_PRIO_ACCESSTIME_CTRL_BIT_Ttag {
	unsigned int ts_accessrate_HIF_mi  : BFW_NETX_MEM_PRIO_ACCESS_CTRL_ts_accessrate_HIF_mi;  // 0..63: master m0 is alowed to request ((ts_accessrate_HIF_mi*ts_length_HIF_mi)/64) + 1 accesses on external memory  
	unsigned int ts_accessrate_XC_mi   : BFW_NETX_MEM_PRIO_ACCESS_CTRL_ts_accessrate_XC_mi;   // 0..63: master m1 is alowed to request ((ts_accessrate_XC_mi*ts_length_XC_mi)/64) + 1 accesses on external memory  
	unsigned int ts_accessrate_LCD_mi  : BFW_NETX_MEM_PRIO_ACCESS_CTRL_ts_accessrate_LCD_mi;  // 0..63: master m2 is alowed to request ((ts_accessrate_LCD_mi*ts_length_LCD_mi)/64) + 1 accesses on external memory  
	unsigned int ts_accessrate_ARMI_mi : BFW_NETX_MEM_PRIO_ACCESS_CTRL_ts_accessrate_ARMI_mi; // 0..63: master m3 is alowed to request ((ts_accessrate_ARMI_mi*ts_length_ARMI_mi)/64) + 1 accesses on external memory  
	unsigned int ts_accessrate_ARMD_mi : BFW_NETX_MEM_PRIO_ACCESS_CTRL_ts_accessrate_ARMD_mi; // 0..63: master m4 is alowed to request ((ts_accessrate_ARMD_mi*ts_length_ARMD_mi)/64) + 1 accesses on external memory  
	unsigned int reserved1             : BFW_NETX_MEM_PRIO_ACCESS_CTRL_reserved1;             // reserved
} EXTMEM_PRIO_ACCESSTIME_CTRL_BIT_T;

typedef union {
	unsigned int                      val;
	EXTMEM_PRIO_ACCESSTIME_CTRL_BIT_T bf;
} EXTMEM_PRIO_ACCESSTIME_CTRL_T;



// =====================================================================
//
// Area of dTCM
//
// =====================================================================

#define NETX_MEM_DATA_TCM_AREA	0x10000000U

// ---------------------------------------------------------------------
// Register dTCM_base
// => ARM data Tightly Coupled Memory start address
//    Area size: 8kB
// => Mode: Mode (r/w)
// ---------------------------------------------------------------------

#define REL_NETX_MEM_DATA_TCM_BASE 0x00000000U
#define NETX_MEM_DATA_TCM_BASE     0x10000000U

// ---------------------------------------------------------------------
// Register dTCM_end
// => ARM data Tightly Coupled Memory end address
// => Mode: Mode (r)
// ---------------------------------------------------------------------

#define REL_NETX_MEM_DATA_TCM_END 0x00001FFCU
#define NETX_MEM_DATA_TCM_END     0x10001FFCU



// =====================================================================
//
// Area of sdram
//
// =====================================================================

#define NETX_MEM_SDRAM_AREA	0x80000000U

// ---------------------------------------------------------------------
// Register sdram_base
// => external SDRAM chipselect start address
//    Area size: 1024MB
// => Mode: Mode (r/w)
// ---------------------------------------------------------------------

#define REL_NETX_MEM_SDRAM_BASE 0x00000000U
#define NETX_MEM_SDRAM_BASE     0x80000000U

// ---------------------------------------------------------------------
// Register sdram_end
// => external SDRAM chipselect end address
// => Mode: Mode (r)
// ---------------------------------------------------------------------

#define REL_NETX_MEM_SDRAM_END 0x3FFFFFFCU
#define NETX_MEM_SDRAM_END     0xBFFFFFFCU



// =====================================================================
//
// Area of extsram0
//
// =====================================================================

#define NETX_MEM_SRAM0_AREA	0xC0000000U

// ---------------------------------------------------------------------
// Register extsram0_base
// => external SRAM/Flash/NVRAM,... chipselect start address
//    Area size: 128MB
// => Mode: Mode (r/w)
// ---------------------------------------------------------------------

#define REL_NETX_MEM_SRAM0_BASE 0x00000000U
#define NETX_MEM_SRAM0_BASE     0xC0000000U

// ---------------------------------------------------------------------
// Register extsram0_end
// => external SRAM/Flash/NVRAM,... chipselect end address
// => Mode: Mode (r)
// ---------------------------------------------------------------------

#define REL_NETX_MEM_SRAM0_END 0x07FFFFFCU
#define NETX_MEM_SRAM0_END     0xC7FFFFFCU



// =====================================================================
//
// Area of extsram1
//
// =====================================================================

#define NETX_MEM_SRAM1_AREA	0xC8000000U

// ---------------------------------------------------------------------
// Register extsram1_base
// => external SRAM/Flash/NVRAM,... chipselect start address
//    Area size: 128MB
// => Mode: Mode (r/w)
// ---------------------------------------------------------------------

#define REL_NETX_MEM_SRAM1_BASE 0x00000000U
#define NETX_MEM_SRAM1_BASE     0xC8000000U


// ---------------------------------------------------------------------
// Register extsram1_end
// => external SRAM/Flash/NVRAM,... chipselect end address
// => Mode: Mode (r)
// ---------------------------------------------------------------------

#define REL_NETX_MEM_SRAM1_END 0x07FFFFFCU
#define NETX_MEM_SRAM1_END     0xCFFFFFFCU



// =====================================================================
//
// Area of extsram2
//
// =====================================================================

#define NETX_MEM_SRAM2_AREA	0xD0000000U

// ---------------------------------------------------------------------
// Register extsram2_base
// => external SRAM/Flash/NVRAM,... chipselect start address
//    Area size: 128MB
// => Mode: Mode (r/w)
// ---------------------------------------------------------------------

#define REL_NETX_MEM_SRAM2_BASE 0x00000000U
#define NETX_MEM_SRAM2_BASE     0xD0000000U

// ---------------------------------------------------------------------
// Register extsram2_end
// => external SRAM/Flash/NVRAM,... chipselect end address
// => Mode: Mode (r)
// ---------------------------------------------------------------------

#define REL_NETX_MEM_SRAM2_END 0x07FFFFFCU
#define NETX_MEM_SRAM2_END     0xD7FFFFFCU


/*************************************************************************************/

#endif /* _MEM_H */
