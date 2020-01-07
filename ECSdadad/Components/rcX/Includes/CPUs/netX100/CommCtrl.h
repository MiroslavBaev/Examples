/******************************************************************************

  Copyright (C) 2010 [Hilscher Gesellschaft für Systemautomation mbH]

  This program can be used by everyone according to the netX Open Source
  Software license. The license agreement can be downloaded from
  http://www.industrialNETworX.com

*******************************************************************************

  Last Modification:
    @version $Id: CommCtrl.h 333 2010-04-26 09:32:25Z Volker $

  Description:
    netX COMMU definitions

  Changes:
    Date        Author        Description
  ---------------------------------------------------------------------------
    2010-03-24  NC            File created.

******************************************************************************/


#ifndef _COMMU_H
#define _COMMU_H


/*************************************************************************************/


// ---------------------------------------------------------------------
// Register phy_control
// => Phy Controll Register
//    This register contains all static connectors of the NEC Ethernet Phy.
//    Usually the Phy read these values only during reset, which can be controlled by Bit31.
//    Changing this register is only possible by the following sequence:
//    1.: read out access key
//    2.: write back access key
//    3.: write desired value to this register
//    In total the programming sequence should be:
//    a: read access key, write access key, write new value with bit phy_reset=1
//    b: wait for synchronization(~16cc) and proper reset of phy(~40cc ? better check NEC document)
//    c: read access key, write access key, write new value with bit phy_reset=0
// => Mode: Mode (r/w)
// ---------------------------------------------------------------------

#define REL_NETX_PHY_CTRL 0x00000010U
#define NETX_PHY_CTRL     0x00100010U

#define MSK_NETX_PHY_CTRL_phy_address      0x0000000fU // [3:0]
#define SRT_NETX_PHY_CTRL_phy_address      0           
#define MSK_NETX_PHY_CTRL_phy1_mode        0x00000070U // [6:4]
#define SRT_NETX_PHY_CTRL_phy1_mode        4           
#define MSK_NETX_PHY_CTRL_phy1_fxmode      0x00000080U // [7]
#define SRT_NETX_PHY_CTRL_phy1_fxmode      7           
#define MSK_NETX_PHY_CTRL_phy1_automdix    0x00000100U // [8]
#define SRT_NETX_PHY_CTRL_phy1_automdix    8           
#define MSK_NETX_PHY_CTRL_phy1_np_msg_code 0x00000e00U // [11:9]
#define SRT_NETX_PHY_CTRL_phy1_np_msg_code 9           
#define MSK_NETX_PHY_CTRL_phy1_enable      0x00001000U // [12]
#define SRT_NETX_PHY_CTRL_phy1_enable      12          
#define MSK_NETX_PHY_CTRL_phy2_mode        0x0000e000U // [15:13]
#define SRT_NETX_PHY_CTRL_phy2_mode        13          
#define MSK_NETX_PHY_CTRL_phy2_fxmode      0x00010000U // [16]
#define SRT_NETX_PHY_CTRL_phy2_fxmode      16          
#define MSK_NETX_PHY_CTRL_phy2_automdix    0x00020000U // [17]
#define SRT_NETX_PHY_CTRL_phy2_automdix    17          
#define MSK_NETX_PHY_CTRL_phy2_np_msg_code 0x001c0000U // [20:18]
#define SRT_NETX_PHY_CTRL_phy2_np_msg_code 18          
#define MSK_NETX_PHY_CTRL_phy2_enable      0x00200000U // [21]
#define SRT_NETX_PHY_CTRL_phy2_enable      21          
#define MSK_NETX_PHY_CTRL_phy_clk_xlatin   0x20000000U // [29]
#define SRT_NETX_PHY_CTRL_phy_clk_xlatin   29          
#define MSK_NETX_PHY_CTRL_phy_sim_byp      0x40000000U // [30]
#define SRT_NETX_PHY_CTRL_phy_sim_byp      30          
#define MSK_NETX_PHY_CTRL_phy_reset        0x80000000U // [31]
#define SRT_NETX_PHY_CTRL_phy_reset        31          

enum {
	BFW_NETX_PHY_CTRL_phy_address      = 4, // [3:0]
	BFW_NETX_PHY_CTRL_phy1_mode        = 3, // [6:4]
	BFW_NETX_PHY_CTRL_phy1_fxmode      = 1, // [7]
	BFW_NETX_PHY_CTRL_phy1_automdix    = 1, // [8]
	BFW_NETX_PHY_CTRL_phy1_np_msg_code = 3, // [11:9]
	BFW_NETX_PHY_CTRL_phy1_enable      = 1, // [12]
	BFW_NETX_PHY_CTRL_phy2_mode        = 3, // [15:13]
	BFW_NETX_PHY_CTRL_phy2_fxmode      = 1, // [16]
	BFW_NETX_PHY_CTRL_phy2_automdix    = 1, // [17]
	BFW_NETX_PHY_CTRL_phy2_np_msg_code = 3, // [20:18]
	BFW_NETX_PHY_CTRL_phy2_enable      = 1, // [21]
	BFW_NETX_PHY_CTRL_reserved1        = 7, // [28:22]
	BFW_NETX_PHY_CTRL_phy_clk_xlatin   = 1, // [29]
	BFW_NETX_PHY_CTRL_phy_sim_byp      = 1, // [30]
	BFW_NETX_PHY_CTRL_phy_reset        = 1  // [31]
};

typedef struct PHY_CONTROL_BIT_Ttag {
	unsigned int phy_address      : BFW_NETX_PHY_CTRL_phy_address;      // Bits 4:1 of phy mdio-address. 
	                                                        // Bit0 defines 1st or 2nd internal phy
	unsigned int phy1_mode        : BFW_NETX_PHY_CTRL_phy1_mode;        // Phy1 Mode: 
	                                                        // 000: 10BASE-T Half Duplex, Auto Negotiation disabled.
	                                                        // 001: 10BASE-T Full Duplex. Auto-Negotiation disabled.
	                                                        // 010: 100BASE-TX/FX Half Duplex. Auto-Negotiation disabled. CRS is active during Transmit & Receive.
	                                                        // 011: 100BASE-TX/FX Full Duplex. Auto-Negotiation disabled. CRS is active during Receive.
	                                                        // 100: 100BASE-TX Half Duplex is advertised. Auto-Negotiation enabled. CRS is active during Transmit & Receive.
	                                                        // 101: Repeater mode. Auto-Negotiation enabled. 100BASETX Half Duplex is advertised. CRS is active during Receive.
	                                                        // 110: Power Down mode. In this mode the PHY wake-up in Power-Down mode.
	                                                        // 111: All capable. Auto-Negotiation enabled. AutoMDIX enabled.
	unsigned int phy1_fxmode      : BFW_NETX_PHY_CTRL_phy1_fxmode;      // Phy1 100BASE-FX mode (phy_mode must be 01x) 
	unsigned int phy1_automdix    : BFW_NETX_PHY_CTRL_phy1_automdix;    // Phy1 Enables AutoMDIX state machine 
	unsigned int phy1_np_msg_code : BFW_NETX_PHY_CTRL_phy1_np_msg_code; // Phy1 Next Page Message Code (auto negotiation) 
	unsigned int phy1_enable      : BFW_NETX_PHY_CTRL_phy1_enable;      // Phy1 enable 
	unsigned int phy2_mode        : BFW_NETX_PHY_CTRL_phy2_mode;        // Phy2 Mode: 
	                                                        // 000: 10BASE-T Half Duplex, Auto Negotiation disabled.
	                                                        // 001: 10BASE-T Full Duplex. Auto-Negotiation disabled.
	                                                        // 010: 100BASE-TX/FX Half Duplex. Auto-Negotiation disabled. CRS is active during Transmit & Receive.
	                                                        // 011: 100BASE-TX/FX Full Duplex. Auto-Negotiation disabled. CRS is active during Receive.
	                                                        // 100: 100BASE-TX Half Duplex is advertised. Auto-Negotiation enabled. CRS is active during Transmit & Receive.
	                                                        // 101: Repeater mode. Auto-Negotiation enabled. 100BASETX Half Duplex is advertised. CRS is active during Receive.
	                                                        // 110: Power Down mode. In this mode the PHY wake-up in Power-Down mode.
	                                                        // 111: All capable. Auto-Negotiation enabled. AutoMDIX enabled.
	unsigned int phy2_fxmode      : BFW_NETX_PHY_CTRL_phy2_fxmode;      // Phy2 100BASE-FX mode (phy_mode must be 01x) 
	unsigned int phy2_automdix    : BFW_NETX_PHY_CTRL_phy2_automdix;    // Phy2 Enables AutoMDIX state machine 
	unsigned int phy2_np_msg_code : BFW_NETX_PHY_CTRL_phy2_np_msg_code; // Phy2 Next Page Message Code (auto negotiation) 
	unsigned int phy2_enable      : BFW_NETX_PHY_CTRL_phy2_enable;      // Phy2 enable 
	unsigned int reserved1        : BFW_NETX_PHY_CTRL_reserved1;        // reserved
	unsigned int phy_clk_xlatin   : BFW_NETX_PHY_CTRL_phy_clk_xlatin;   // 1: use the external oscillator input (25MHz) to clock ethernet Phy # defautl 1
	                                                        // 0: use phyclk_rate_mul_add (further down) to clock ethernet Phy 
	unsigned int phy_sim_byp      : BFW_NETX_PHY_CTRL_phy_sim_byp;      // Phy Power up Bypass: 0=normal | 1=bypass, # defautl 0
	                                                        // only used for simulation issues
	unsigned int phy_reset        : BFW_NETX_PHY_CTRL_phy_reset;        // Hardware reset for PHY: 1=reset 
} PHY_CONTROL_BIT_T;

typedef union {
	unsigned int      val;
	PHY_CONTROL_BIT_T bf;
} PHY_CONTROL_T;



// =====================================================================
//
// Area of pointer_fifo
//
// =====================================================================

#define NETX_PTR_FIFO_AREA	0x00164000U


// ---------------------------------------------------------------------
// Register pfifo_base
// => Pointer FIFO table.
//    Each of the following 32 addresses accesses a FIFO
// => Mode: Mode (r/w)
// ---------------------------------------------------------------------

#define REL_NETX_PTR_FIFO_BASE 0x00000000U
#define NETX_PTR_FIFO_BASE     0x00164000U

#define MSK_NETX_PTR_FIFO_BASE_fifo_data 0xffffffffU // [31:0]
#define SRT_NETX_PTR_FIFO_BASE_fifo_data 0           

enum {
	BFW_NETX_PTR_FIFO_BASE_fifo_data = 32  // [31:0]
};

typedef struct PFIFO_BASE_BIT_Ttag {
	unsigned int fifo_data : BFW_NETX_PTR_FIFO_BASE_fifo_data; // write access: write data to FIFO, read access: read data from FIFO 
} PFIFO_BASE_BIT_T;

typedef union {
	unsigned int     val;
	PFIFO_BASE_BIT_T bf;
} PFIFO_BASE_T;

// ---------------------------------------------------------------------
// Register pfifo_border_base
// => Pointer FIFO Upper Borders table.
//    Each of the following 32 addresses access the upper border of the apropriate FIFO in a 2048x32 bit RAM.
//    All upper borders should be rising with number of FIFO.
//    If a border between two FIFOs is moved, the adjacent FIFOs should be reset first.
// => Mode: Mode (r/w)
// ---------------------------------------------------------------------

#define REL_NETX_PTR_FIFO_BOR_BASE 0x00000080U
#define NETX_PTR_FIFO_BOR_BASE     0x00164080U

#define MSK_NETX_PTR_FIFO_BOR_BASE_border 0x000007ffU // [10:0]
#define SRT_NETX_PTR_FIFO_BOR_BASE_border 0           

enum {
	BFW_NETX_PTR_FIFO_BOR_BASE_border    = 11, // [10:0]
	BFW_NETX_PTR_FIFO_BOR_BASE_reserved1 = 21  // [31:11]
};

typedef struct PFIFO_BORDER_BASE_BIT_Ttag {
	unsigned int border    : BFW_NETX_PTR_FIFO_BOR_BASE_border;    // last address of RAM used by appropriate FIFO, = (first address - 1) of next FIFO 
	                                                        // FIFO 0 default depth     : 1024
	                                                        // FIFO 1..30 default depth : 32
	                                                        // FIFO 31 default depth    : 64
	unsigned int reserved1 : BFW_NETX_PTR_FIFO_BOR_BASE_reserved1; // reserved
} PFIFO_BORDER_BASE_BIT_T;

typedef union {
	unsigned int            val;
	PFIFO_BORDER_BASE_BIT_T bf;
} PFIFO_BORDER_BASE_T;

// ---------------------------------------------------------------------
// Register pfifo_reset
// => Pointer FIFO reset vector.
//    Allows to reset each of 32 FIFOs,
//    i.e. set read and write pointer to lower border of FIFO, reset full, overflow, underrun and set empty flag.
//    Reset flag of adjacent FIFOs should be set before resizing the FIFO.
//    Resetvalue : 0x00000000
// => Mode: Mode (r/w)
// ---------------------------------------------------------------------

#define REL_NETX_PTR_FIFO_RESET 0x00000100U
#define NETX_PTR_FIFO_RESET     0x00164100U

#define MSK_NETX_PTR_FIFO_RESET_reset_fifo 0xffffffffU // [31:0]
#define SRT_NETX_PTR_FIFO_RESET_reset_fifo 0           

enum {
	BFW_NETX_PTR_FIFO_RESET_reset_fifo = 32  // [31:0]
};

typedef struct PFIFO_RESET_BIT_Ttag {
	unsigned int reset_fifo : BFW_NETX_PTR_FIFO_RESET_reset_fifo; // Reset Vector, 1 bit per FIFO: 1: reset FIFO, 0: normal work mode 
} PFIFO_RESET_BIT_T;

typedef union {
	unsigned int      val;
	PFIFO_RESET_BIT_T bf;
} PFIFO_RESET_T;

// ---------------------------------------------------------------------
// Register pfifo_full
// => Pointer FIFO full vector.
//    Shows the fifo_full flag of each FIFO.
//    Resetvalue : 0x00000000
// => Mode: Mode (ro)
// ---------------------------------------------------------------------

#define REL_NETX_PTR_FIFO_FULL 0x00000104U
#define NETX_PTR_FIFO_FULL     0x00164104U

#define MSK_NETX_PTR_FIFO_FULL_fifo_full 0xffffffffU // [31:0]
#define SRT_NETX_PTR_FIFO_FULL_fifo_full 0           

enum {
	BFW_NETX_PTR_FIFO_FULL_fifo_full = 32  // [31:0]
};

typedef struct PFIFO_FULL_BIT_Ttag {
	unsigned int fifo_full : BFW_NETX_PTR_FIFO_FULL_fifo_full; // FIFO full vector, 1 bit per FIFO 
} PFIFO_FULL_BIT_T;

typedef union {
	unsigned int     val;
	PFIFO_FULL_BIT_T bf;
} PFIFO_FULL_T;

// ---------------------------------------------------------------------
// Register pfifo_empty
// => Pointer FIFO empty vector.
//    Shows the fifo_empty flag of each FIFO.
//    Resetvalue : 0xffffffff
// => Mode: Mode (ro)
// ---------------------------------------------------------------------

#define REL_NETX_PTR_FIFO_EMPTY 0x00000108U
#define NETX_PTR_FIFO_EMPTY     0x00164108U

#define MSK_NETX_PTR_FIFO_EMPTY_fifo_empty 0xffffffffU // [31:0]
#define SRT_NETX_PTR_FIFO_EMPTY_fifo_empty 0           

enum {
	BFW_NETX_PTR_FIFO_EMPTY_fifo_empty = 32  // [31:0]
};

typedef struct PFIFO_EMPTY_BIT_Ttag {
	unsigned int fifo_empty : BFW_NETX_PTR_FIFO_EMPTY_fifo_empty; // FIFO empty vector, 1 bit per FIFO 
} PFIFO_EMPTY_BIT_T;

typedef union {
	unsigned int      val;
	PFIFO_EMPTY_BIT_T bf;
} PFIFO_EMPTY_T;

// ---------------------------------------------------------------------
// Register pfifo_overflow
// => Pointer FIFO overflow vector.
//    Shows the fifo_overflow flag of each FIFO.
//    If the FIFO had an overflow, it should be reset.
//    Resetvalue : 0x00000000
// => Mode: Mode (ro)
// ---------------------------------------------------------------------

#define REL_NETX_PTR_FIFO_OVF 0x0000010CU
#define NETX_PTR_FIFO_OVF     0x0016410CU

#define MSK_NETX_PTR_FIFO_OVF_fifo_overflow 0xffffffffU // [31:0]
#define SRT_NETX_PTR_FIFO_OVF_fifo_overflow 0           

enum {
	BFW_NETX_PTR_FIFO_OVF_fifo_overflow = 32  // [31:0]
};

typedef struct PFIFO_OVERFLOW_BIT_Ttag {
	unsigned int fifo_overflow : BFW_NETX_PTR_FIFO_OVF_fifo_overflow; // FIFO overflow vector, 1 bit per FIFO 
} PFIFO_OVERFLOW_BIT_T;

typedef union {
	unsigned int         val;
	PFIFO_OVERFLOW_BIT_T bf;
} PFIFO_OVERFLOW_T;

// ---------------------------------------------------------------------
// Register pfifo_underrun
// => Pointer FIFO underrun vector.
//    Shows the fifo_underrun flag of each FIFO.
//    If the FIFO had an underrun, it should be reset.
//    Resetvalue : 0x00000000
// => Mode: Mode (ro)
// ---------------------------------------------------------------------

#define REL_NETX_PTR_FIFO_UDR 0x00000110U
#define NETX_PTR_FIFO_UDR     0x00164110U

#define MSK_NETX_PTR_FIFO_UDR_fifo_underrun 0xffffffffU // [31:0]
#define SRT_NETX_PTR_FIFO_UDR_fifo_underrun 0           

enum {
	BFW_NETX_PTR_FIFO_UDR_fifo_underrun = 32  // [31:0]
};

typedef struct PFIFO_UNDERRUN_BIT_Ttag {
	unsigned int fifo_underrun : BFW_NETX_PTR_FIFO_UDR_fifo_underrun; // FIFO underrun vector, 1 bit per FIFO 
} PFIFO_UNDERRUN_BIT_T;

typedef union {
	unsigned int         val;
	PFIFO_UNDERRUN_BIT_T bf;
} PFIFO_UNDERRUN_T;

// ---------------------------------------------------------------------
// Register pfifo_fill_level_base
// => Pointer FIFO fill-level table.
//    Each of the following 32 addresses reads the fill-level of the appropriate FIFO.
// => Mode: Mode (r)
// ---------------------------------------------------------------------

#define REL_NETX_PTR_FIFO_FILL_LVL_BASE 0x00000180U
#define NETX_PTR_FIFO_FILL_LVL_BASE     0x00164180U

#define MSK_NETX_PTR_FIFO_FILL_LVL_BASE_fill_level 0x000007ffU // [10:0]
#define SRT_NETX_PTR_FIFO_FILL_LVL_BASE_fill_level 0           

enum {
	BFW_NETX_PTR_FIFO_FILL_LVL_BASE_fill_level = 11, // [10:0]
	BFW_NETX_PTR_FIFO_FILL_LVL_BASE_reserved1  = 21  // [31:11]
};

typedef struct PFIFO_FILL_LEVEL_BASE_BIT_Ttag {
	unsigned int fill_level : BFW_NETX_PTR_FIFO_FILL_LVL_BASE_fill_level; // actual number of words in appropriate FIFO (not valid, if FIFO had an overflow or underflow) 
	unsigned int reserved1  : BFW_NETX_PTR_FIFO_FILL_LVL_BASE_reserved1;  // reserved
} PFIFO_FILL_LEVEL_BASE_BIT_T;

typedef union {
	unsigned int                val;
	PFIFO_FILL_LEVEL_BASE_BIT_T bf;
} PFIFO_FILL_LEVEL_BASE_T;



// =====================================================================
//
// Area of crc
//
// =====================================================================

#define NETX_CRC_AREA	0x00101000U


// ---------------------------------------------------------------------
// Register crc_crc
// => CRC Register
// => Mode: Mode (r/w)
// ---------------------------------------------------------------------

#define REL_NETX_CRC_VAL 0x00000000U
#define NETX_CRC_VAL     0x00101000U

#define MSK_NETX_CRC_VAL_crc_val 0xffffffffU // [31:0]
#define SRT_NETX_CRC_VAL_crc_val 0           

enum {
	BFW_NETX_CRC_VAL_crc_val = 32  // [31:0]
};

typedef struct CRC_CRC_BIT_Ttag {
	unsigned int crc_val : BFW_NETX_CRC_VAL_crc_val; // CRC value 
	                                                        // Upper bits should be masked, if crc_len smaller 31
} CRC_CRC_BIT_T;

typedef union {
	unsigned int  val;
	CRC_CRC_BIT_T bf;
} CRC_CRC_T;

// ---------------------------------------------------------------------
// Register crc_data_in
// => CRC data in Register
// => Mode: Mode (r/w)
// ---------------------------------------------------------------------

#define REL_NETX_CRC_IN_DATA 0x00000004U
#define NETX_CRC_IN_DATA     0x00101004U

#define MSK_NETX_CRC_IN_DATA_in 0x000000ffU // [7:0]
#define SRT_NETX_CRC_IN_DATA_in 0           

enum {
	BFW_NETX_CRC_IN_DATA_in        = 8,  // [7:0]
	BFW_NETX_CRC_IN_DATA_reserved1 = 24  // [31:8]
};

typedef struct CRC_DATA_IN_BIT_Ttag {
	unsigned int in        : BFW_NETX_CRC_IN_DATA_in;        // CRC input bits
	unsigned int reserved1 : BFW_NETX_CRC_IN_DATA_reserved1; // reserved
} CRC_DATA_IN_BIT_T;

typedef union {
	unsigned int      val;
	CRC_DATA_IN_BIT_T bf;
} CRC_DATA_IN_T;

// ---------------------------------------------------------------------
// Register crc_polynomial
// => CRC Polynomial Register
// => Mode: Mode (r/w)
// ---------------------------------------------------------------------

#define REL_NETX_CRC_POLYNOMIAL 0x00000008U
#define NETX_CRC_POLYNOMIAL     0x00101008U

#define MSK_NETX_CRC_POLYNOMIAL_crc_polynomial 0xffffffffU // [31:0]
#define SRT_NETX_CRC_POLYNOMIAL_crc_polynomial 0           

enum {
	BFW_NETX_CRC_POLYNOMIAL_crc_polynomial = 32  // [31:0]
};

typedef struct CRC_POLYNOMIAL_BIT_Ttag {
	unsigned int crc_polynomial : BFW_NETX_CRC_POLYNOMIAL_crc_polynomial; // crc polynomial (default:Ethenet CRC32)
	                                                        // Most significant bit of polynome is always one, thus not considered.
} CRC_POLYNOMIAL_BIT_T;

typedef union {
	unsigned int         val;
	CRC_POLYNOMIAL_BIT_T bf;
} CRC_POLYNOMIAL_T;

// ---------------------------------------------------------------------
// Register crc_config
// => CRC config Register
// => Mode: Mode (r/w)
// ---------------------------------------------------------------------

#define REL_NETX_CRC_CFG 0x0000000CU
#define NETX_CRC_CFG     0x0010100CU

#define MSK_NETX_CRC_CFG_crc_len         0x0000003fU // [5:0]
#define SRT_NETX_CRC_CFG_crc_len         0           
#define MSK_NETX_CRC_CFG_crc_shift_right 0x00000040U // [6]
#define SRT_NETX_CRC_CFG_crc_shift_right 6           
#define MSK_NETX_CRC_CFG_crc_direct_div  0x00000080U // [7]
#define SRT_NETX_CRC_CFG_crc_direct_div  7           
#define MSK_NETX_CRC_CFG_crc_nof_bits    0x00000300U // [9:8]
#define SRT_NETX_CRC_CFG_crc_nof_bits    8           
#define MSK_NETX_CRC_CFG_crc_in_msb_low  0x00000400U // [10]
#define SRT_NETX_CRC_CFG_crc_in_msb_low  10          

enum {
	BFW_NETX_CRC_CFG_crc_len         = 6,  // [5:0]
	BFW_NETX_CRC_CFG_crc_shift_right = 1,  // [6]
	BFW_NETX_CRC_CFG_crc_direct_div  = 1,  // [7]
	BFW_NETX_CRC_CFG_crc_nof_bits    = 2,  // [9:8]
	BFW_NETX_CRC_CFG_crc_in_msb_low  = 1,  // [10]
	BFW_NETX_CRC_CFG_reserved1       = 21  // [31:11]
};

typedef struct CRC_CONFIG_BIT_Ttag {
	unsigned int crc_len         : BFW_NETX_CRC_CFG_crc_len;         // Length of CRC - 1 
	unsigned int crc_shift_right : BFW_NETX_CRC_CFG_crc_shift_right; // 1: shift crc right 
	unsigned int crc_direct_div  : BFW_NETX_CRC_CFG_crc_direct_div;  // 1: calculate direct polynolial division without n zeros after frame, usefull for parity calculation 
	unsigned int crc_nof_bits    : BFW_NETX_CRC_CFG_crc_nof_bits;    // number of bits to be calculated in parallel (00: 1, 01: 2, 10; 4, 11: 8) 
	unsigned int crc_in_msb_low  : BFW_NETX_CRC_CFG_crc_in_msb_low;  // swap crc_data_in, only usefull when calculating multiple bits in parallel (crc_nof_bits > 0): 
	                                                        // 1: msb of incoming bits is data_in[0],
	                                                        // 0: msb is data_in[crc_nof_bits_m1]
	                                                        // (msb=first bit in data-stream)
	unsigned int reserved1       : BFW_NETX_CRC_CFG_reserved1;       // reserved
} CRC_CONFIG_BIT_T;

typedef union {
	unsigned int     val;
	CRC_CONFIG_BIT_T bf;
} CRC_CONFIG_T;



// =====================================================================
//
// Area of xpec_irq_registers
//
// =====================================================================

#define NETX_XP_IRQ_AREA	0x00164400U


// ---------------------------------------------------------------------
// Register irq_xpec0
// => IRQ_XPEC 0
//    Resetvalue : 0x00000000
// => Mode: Mode (r/w)
// ---------------------------------------------------------------------

#define REL_NETX_IRQ_XP0 0x00000000U
#define NETX_IRQ_XP0     0x00164400U

#define MSK_NETX_IRQ_XP0_xpec_irq 0x0000ffffU // [15:0]
#define SRT_NETX_IRQ_XP0_xpec_irq 0           
#define MSK_NETX_IRQ_XP0_arm_irq  0xffff0000U // [31:16]
#define SRT_NETX_IRQ_XP0_arm_irq  16          

enum {
	BFW_NETX_IRQ_XP0_xpec_irq = 16, // [15:0]
	BFW_NETX_IRQ_XP0_arm_irq  = 16  // [31:16]
};

typedef struct IRQ_XPEC0_BIT_Ttag {
	unsigned int xpec_irq : BFW_NETX_IRQ_XP0_xpec_irq; // set by xpec ; reset by arm  
	unsigned int arm_irq  : BFW_NETX_IRQ_XP0_arm_irq;  // set by arm  ; reset by xpec 
} IRQ_XPEC0_BIT_T;

typedef union {
	unsigned int    val;
	IRQ_XPEC0_BIT_T bf;
} IRQ_XPEC0_T;

// ---------------------------------------------------------------------
// Register irq_xpec1
// => IRQ_XPEC 1
//    Resetvalue : 0x00000000
// => Mode: Mode (r/w)
// ---------------------------------------------------------------------

#define REL_NETX_IRQ_XP1 0x00000004U
#define NETX_IRQ_XP1     0x00164404U

#define MSK_NETX_IRQ_XP1_xpec_irq 0x0000ffffU // [15:0]
#define SRT_NETX_IRQ_XP1_xpec_irq 0           
#define MSK_NETX_IRQ_XP1_arm_irq  0xffff0000U // [31:16]
#define SRT_NETX_IRQ_XP1_arm_irq  16          

enum {
	BFW_NETX_IRQ_XP1_xpec_irq = 16, // [15:0]
	BFW_NETX_IRQ_XP1_arm_irq  = 16  // [31:16]
};

typedef struct IRQ_XPEC1_BIT_Ttag {
	unsigned int xpec_irq : BFW_NETX_IRQ_XP1_xpec_irq; // set by xpec ; reset by arm  
	unsigned int arm_irq  : BFW_NETX_IRQ_XP1_arm_irq;  // set by arm  ; reset by xpec 
} IRQ_XPEC1_BIT_T;

typedef union {
	unsigned int    val;
	IRQ_XPEC1_BIT_T bf;
} IRQ_XPEC1_T;

// ---------------------------------------------------------------------
// Register irq_xpec2
// => IRQ_XPEC 2
//    Resetvalue : 0x00000000
// => Mode: Mode (r/w)
// ---------------------------------------------------------------------

#define REL_NETX_IRQ_XP2 0x00000008U
#define NETX_IRQ_XP2     0x00164408U

#define MSK_NETX_IRQ_XP2_xpec_irq 0x0000ffffU // [15:0]
#define SRT_NETX_IRQ_XP2_xpec_irq 0           
#define MSK_NETX_IRQ_XP2_arm_irq  0xffff0000U // [31:16]
#define SRT_NETX_IRQ_XP2_arm_irq  16          

enum {
	BFW_NETX_IRQ_XP2_xpec_irq = 16, // [15:0]
	BFW_NETX_IRQ_XP2_arm_irq  = 16  // [31:16]
};

typedef struct IRQ_XPEC2_BIT_Ttag {
	unsigned int xpec_irq : BFW_NETX_IRQ_XP2_xpec_irq; // set by xpec ; reset by arm  
	unsigned int arm_irq  : BFW_NETX_IRQ_XP2_arm_irq;  // set by arm  ; reset by xpec 
} IRQ_XPEC2_BIT_T;

typedef union {
	unsigned int    val;
	IRQ_XPEC2_BIT_T bf;
} IRQ_XPEC2_T;

// ---------------------------------------------------------------------
// Register irq_xpec3
// => IRQ_XPEC 3
//    Resetvalue : 0x00000000
// => Mode: Mode (r/w)
// ---------------------------------------------------------------------

#define REL_NETX_IRQ_XP3 0x0000000CU
#define NETX_IRQ_XP3     0x0016440CU

#define MSK_NETX_IRQ_XP3_xpec_irq 0x0000ffffU // [15:0]
#define SRT_NETX_IRQ_XP3_xpec_irq 0           
#define MSK_NETX_IRQ_XP3_arm_irq  0xffff0000U // [31:16]
#define SRT_NETX_IRQ_XP3_arm_irq  16          

enum {
	BFW_NETX_IRQ_XP3_xpec_irq = 16, // [15:0]
	BFW_NETX_IRQ_XP3_arm_irq  = 16  // [31:16]
};

typedef struct IRQ_XPEC3_BIT_Ttag {
	unsigned int xpec_irq : BFW_NETX_IRQ_XP3_xpec_irq; // set by xpec ; reset by arm  
	unsigned int arm_irq  : BFW_NETX_IRQ_XP3_arm_irq;  // set by arm  ; reset by xpec 
} IRQ_XPEC3_BIT_T;

typedef union {
	unsigned int    val;
	IRQ_XPEC3_BIT_T bf;
} IRQ_XPEC3_T;



// =====================================================================
//
// Area of miimu
//
// =====================================================================

#define NETX_MIIMU_AREA	0x00100B00U

// ---------------------------------------------------------------------
// Register miimu_reg
// => MIIMU receive/transmit register
// => Mode: Mode (r/w)
// ---------------------------------------------------------------------

#define REL_NETX_MIIMU_RXTX 0x00000000U
#define NETX_MIIMU_RXTX     0x00100B00U

#define MSK_NETX_MIIMU_RXTX_miimu_snrdy      0x00000001U // [0]
#define SRT_NETX_MIIMU_RXTX_miimu_snrdy      0           
#define MSK_NETX_MIIMU_RXTX_miimu_preamble   0x00000002U // [1]
#define SRT_NETX_MIIMU_RXTX_miimu_preamble   1           
#define MSK_NETX_MIIMU_RXTX_miimu_opmode     0x00000004U // [2]
#define SRT_NETX_MIIMU_RXTX_miimu_opmode     2           
#define MSK_NETX_MIIMU_RXTX_miimu_mdc_period 0x00000008U // [3]
#define SRT_NETX_MIIMU_RXTX_miimu_mdc_period 3           
#define MSK_NETX_MIIMU_RXTX_phy_nres         0x00000010U // [4]
#define SRT_NETX_MIIMU_RXTX_phy_nres         4           
#define MSK_NETX_MIIMU_RXTX_miimu_rta        0x00000020U // [5]
#define SRT_NETX_MIIMU_RXTX_miimu_rta        5           
#define MSK_NETX_MIIMU_RXTX_miimu_regaddr    0x000007c0U // [10:6]
#define SRT_NETX_MIIMU_RXTX_miimu_regaddr    6           
#define MSK_NETX_MIIMU_RXTX_miimu_phyaddr    0x0000f800U // [15:11]
#define SRT_NETX_MIIMU_RXTX_miimu_phyaddr    11          
#define MSK_NETX_MIIMU_RXTX_miimu_data       0xffff0000U // [31:16]
#define SRT_NETX_MIIMU_RXTX_miimu_data       16          

enum {
	BFW_NETX_MIIMU_RXTX_miimu_snrdy      = 1,  // [0]
	BFW_NETX_MIIMU_RXTX_miimu_preamble   = 1,  // [1]
	BFW_NETX_MIIMU_RXTX_miimu_opmode     = 1,  // [2]
	BFW_NETX_MIIMU_RXTX_miimu_mdc_period = 1,  // [3]
	BFW_NETX_MIIMU_RXTX_phy_nres         = 1,  // [4]
	BFW_NETX_MIIMU_RXTX_miimu_rta        = 1,  // [5]
	BFW_NETX_MIIMU_RXTX_miimu_regaddr    = 5,  // [10:6]
	BFW_NETX_MIIMU_RXTX_miimu_phyaddr    = 5,  // [15:11]
	BFW_NETX_MIIMU_RXTX_miimu_data       = 16  // [31:16]
};

typedef struct MIIMU_REG_BIT_Ttag {
	unsigned int miimu_snrdy      : BFW_NETX_MIIMU_RXTX_miimu_snrdy;      // start not ready 
	unsigned int miimu_preamble   : BFW_NETX_MIIMU_RXTX_miimu_preamble;   // send preamble 
	unsigned int miimu_opmode     : BFW_NETX_MIIMU_RXTX_miimu_opmode;     // operation mode 
	                                                        // 1..write					  
	                                                        // 0..read					  
	unsigned int miimu_mdc_period : BFW_NETX_MIIMU_RXTX_miimu_mdc_period; // mdc period 
	                                                        // 1..800ns  																		 
	                                                        // 0..400ns  																		 
	unsigned int phy_nres         : BFW_NETX_MIIMU_RXTX_phy_nres;         // phy hardware nReset (activ low!) 
	                                                        // If this bit and the miimu_snrdy-bit ist set, the phys will be hardware-reseted.	 
	                                                        // No data will be transmitted in this case. 										 
	                                                        // After reset the miimu-controller will set this bit to 1 again.					 
	unsigned int miimu_rta        : BFW_NETX_MIIMU_RXTX_miimu_rta;        // read turn around field 
	                                                        // 0.. one bit																		 
	                                                        // 1.. two bits  																	 
	unsigned int miimu_regaddr    : BFW_NETX_MIIMU_RXTX_miimu_regaddr;    // register address 
	unsigned int miimu_phyaddr    : BFW_NETX_MIIMU_RXTX_miimu_phyaddr;    // phy address 
	unsigned int miimu_data       : BFW_NETX_MIIMU_RXTX_miimu_data;       // data to or from phy register 
} MIIMU_REG_BIT_T;

typedef union {
	unsigned int    val;
	MIIMU_REG_BIT_T bf;
} MIIMU_REG_T;

// ---------------------------------------------------------------------
// Register miimu_sw_en
// => MIIMU software mode enable register
// => Mode: Mode (r/w)
// ---------------------------------------------------------------------

#define REL_NETX_MIIMU_MODE_EN 0x00000004U
#define NETX_MIIMU_MODE_EN     0x00100B04U

#define MSK_NETX_MIIMU_MODE_EN_miimu_sw_en 0x00000001U // [0]
#define SRT_NETX_MIIMU_MODE_EN_miimu_sw_en 0           

enum {
	BFW_NETX_MIIMU_MODE_EN_miimu_sw_en = 1,  // [0]
	BFW_NETX_MIIMU_MODE_EN_reserved1   = 31  // [31:1]
};

typedef struct MIIMU_SW_EN_BIT_Ttag {
	unsigned int miimu_sw_en : BFW_NETX_MIIMU_MODE_EN_miimu_sw_en; // enables software mode 
	                                                        // mdc, mdo and mdoe have to set by software
	                                                        // the current md_in value can read from miimu_sw_mdi 
	unsigned int reserved1   : BFW_NETX_MIIMU_MODE_EN_reserved1;   // reserved
} MIIMU_SW_EN_BIT_T;

typedef union {
	unsigned int      val;
	MIIMU_SW_EN_BIT_T bf;
} MIIMU_SW_EN_T;

// ---------------------------------------------------------------------
// Register miimu_sw_mdc
// => MIIMU software mode MDC register
// => Mode: Mode (r/w)
// ---------------------------------------------------------------------

#define REL_NETX_MIIMU_MODE_MDC 0x00000008U
#define NETX_MIIMU_MODE_MDC     0x00100B08U

#define MSK_NETX_MIIMU_MODE_MDC_miimu_sw_mdc 0x00000001U // [0]
#define SRT_NETX_MIIMU_MODE_MDC_miimu_sw_mdc 0           

enum {
	BFW_NETX_MIIMU_MODE_MDC_miimu_sw_mdc = 1,  // [0]
	BFW_NETX_MIIMU_MODE_MDC_reserved1    = 31  // [31:1]
};

typedef struct MIIMU_SW_MDC_BIT_Ttag {
	unsigned int miimu_sw_mdc : BFW_NETX_MIIMU_MODE_MDC_miimu_sw_mdc; // MDC value for software mode  
	unsigned int reserved1    : BFW_NETX_MIIMU_MODE_MDC_reserved1;    // reserved
} MIIMU_SW_MDC_BIT_T;

typedef union {
	unsigned int       val;
	MIIMU_SW_MDC_BIT_T bf;
} MIIMU_SW_MDC_T;

// ---------------------------------------------------------------------
// Register miimu_sw_mdo
// => MIIMU software mode MDO register
// => Mode: Mode (r/w)
// ---------------------------------------------------------------------

#define REL_NETX_MIIMU_MODE_MDO 0x0000000CU
#define NETX_MIIMU_MODE_MDO     0x00100B0CU

#define MSK_NETX_MIIMU_MODE_MDO_miimu_sw_mdo 0x00000001U // [0]
#define SRT_NETX_MIIMU_MODE_MDO_miimu_sw_mdo 0           

enum {
	BFW_NETX_MIIMU_MODE_MDO_miimu_sw_mdo = 1,  // [0]
	BFW_NETX_MIIMU_MODE_MDO_reserved1    = 31  // [31:1]
};

typedef struct MIIMU_SW_MDO_BIT_Ttag {
	unsigned int miimu_sw_mdo : BFW_NETX_MIIMU_MODE_MDO_miimu_sw_mdo; // MDO value for software mode  
	unsigned int reserved1    : BFW_NETX_MIIMU_MODE_MDO_reserved1;    // reserved
} MIIMU_SW_MDO_BIT_T;

typedef union {
	unsigned int       val;
	MIIMU_SW_MDO_BIT_T bf;
} MIIMU_SW_MDO_T;

// ---------------------------------------------------------------------
// Register miimu_sw_mdoe
// => MIIMU software mode MDOE register
// => Mode: Mode (r/w)
// ---------------------------------------------------------------------

#define REL_NETX_MIIMU_MODE_MDOE 0x00000010U
#define NETX_MIIMU_MODE_MDOE     0x00100B10U

#define MSK_NETX_MIIMU_MODE_MDOE_miimu_sw_mdoe 0x00000001U // [0]
#define SRT_NETX_MIIMU_MODE_MDOE_miimu_sw_mdoe 0           

enum {
	BFW_NETX_MIIMU_MODE_MDOE_miimu_sw_mdoe = 1,  // [0]
	BFW_NETX_MIIMU_MODE_MDOE_reserved1     = 31  // [31:1]
};

typedef struct MIIMU_SW_MDOE_BIT_Ttag {
	unsigned int miimu_sw_mdoe : BFW_NETX_MIIMU_MODE_MDOE_miimu_sw_mdoe; // MDOE value for software mode  
	unsigned int reserved1     : BFW_NETX_MIIMU_MODE_MDOE_reserved1;     // reserved
} MIIMU_SW_MDOE_BIT_T;

typedef union {
	unsigned int        val;
	MIIMU_SW_MDOE_BIT_T bf;
} MIIMU_SW_MDOE_T;

// ---------------------------------------------------------------------
// Register miimu_sw_mdi
// => MIIMU software mode MDI register
// => Mode: Mode (ro)
// ---------------------------------------------------------------------

#define REL_NETX_MIIMU_MODE_MDI 0x00000014U
#define NETX_MIIMU_MODE_MDI     0x00100B14U

#define MSK_NETX_MIIMU_MODE_MDI_miimu_sw_mdi 0x00000001U // [0]
#define SRT_NETX_MIIMU_MODE_MDI_miimu_sw_mdi 0           

enum {
	BFW_NETX_MIIMU_MODE_MDI_miimu_sw_mdi = 1,  // [0]
	BFW_NETX_MIIMU_MODE_MDI_reserved1    = 31  // [31:1]
};

typedef struct MIIMU_SW_MDI_BIT_Ttag {
	unsigned int miimu_sw_mdi : BFW_NETX_MIIMU_MODE_MDI_miimu_sw_mdi; // current MDI value 
	unsigned int reserved1    : BFW_NETX_MIIMU_MODE_MDI_reserved1;    // reserved
} MIIMU_SW_MDI_BIT_T;

typedef union {
	unsigned int       val;
	MIIMU_SW_MDI_BIT_T bf;
} MIIMU_SW_MDI_T;



/*************************************************************************************/

#endif /* _COMMU_H */
