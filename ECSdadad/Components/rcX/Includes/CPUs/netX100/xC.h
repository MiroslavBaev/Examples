/******************************************************************************

  Copyright (C) 2010 [Hilscher Gesellschaft für Systemautomation mbH]

  This program can be used by everyone according to the netX Open Source
  Software license. The license agreement can be downloaded from
  http://www.industrialNETworX.com

*******************************************************************************

  Last Modification:
    @version $Id: xC.h 333 2010-04-26 09:32:25Z Volker $

  Description:
    netX communication channel definitions

  Changes:
    Date        Author        Description
  ---------------------------------------------------------------------------
    2010-03-24  NC            File created.

******************************************************************************/


#ifndef _XC_H
#define _XC_H


/*************************************************************************************/


// =====================================================================
//
// Area of xc
//
// =====================================================================

#define NETX_XC_AREA	0x00140000U

// ---------------------------------------------------------------------
// Register xc_base
// => 
// => Mode: 
// ---------------------------------------------------------------------

#define REL_NETX_XC_BASE 0x00000000U
#define NETX_XC_BASE     0x00140000U


// =====================================================================
//
// Area of xmac0, xmac1, xmac2, xmac3
//
// =====================================================================

#define NETX_XM0_BASE	0x00160000U
#define NETX_XM1_BASE	0x00161000U
#define NETX_XM2_BASE	0x00162000U
#define NETX_XM3_BASE	0x00163000U

// ---------------------------------------------------------------------
// Register xmac_rpu_program_start
// => xMAC RPU program-RAM start address.
//    The Program-RAM is not addressable for xMAC RPU and TPU !
// => Mode: 
// ---------------------------------------------------------------------

#define REL_NETX_XM_RPU_PROG_START   0x00000000U
#define NETX_XM0_RPU_PROG_START 0x00160000U
#define NETX_XM1_RPU_PROG_START 0x00161000U
#define NETX_XM2_RPU_PROG_START 0x00162000U
#define NETX_XM3_RPU_PROG_START 0x00163000U

// ---------------------------------------------------------------------
// Register xmac_rpu_program_end
// => xMAC RPU program-RAM end address.
//    This value is not used by design flow, only for documentation
// => Mode: 
// ---------------------------------------------------------------------

#define REL_NETX_XM_RPU_PROG_END   0x000003FFU
#define NETX_XM0_RPU_PROG_END 0x001603FFU
#define NETX_XM1_RPU_PROG_END 0x001613FFU
#define NETX_XM2_RPU_PROG_END 0x001623FFU
#define NETX_XM3_RPU_PROG_END 0x001633FFU

// ---------------------------------------------------------------------
// Register xmac_tpu_program_start
// => xMAC TPU program-RAM start address.
//    The Program-RAM is not addressable for xMAC RPU and TPU !
// => Mode: 
// ---------------------------------------------------------------------

#define REL_NETX_XM_TPU_PROG_START   0x00000400U
#define NETX_XM0_TPU_PROG_START 0x00160400U
#define NETX_XM1_TPU_PROG_START 0x00161400U
#define NETX_XM2_TPU_PROG_START 0x00162400U
#define NETX_XM3_TPU_PROG_START 0x00163400U

// ---------------------------------------------------------------------
// Register xmac_tpu_program_end
// => xMAC TPU program-RAM end address.
//    This value is not used by design flow, only for documentation
// => Mode: 
// ---------------------------------------------------------------------

#define REL_NETX_XM_TPU_PROG_END   0x000007FFU
#define NETX_XM0_TPU_PROG_END 0x001607FFU
#define NETX_XM1_TPU_PROG_END 0x001617FFU
#define NETX_XM2_TPU_PROG_END 0x001627FFU
#define NETX_XM3_TPU_PROG_END 0x001637FFU

// ---------------------------------------------------------------------
// Register xmac_rpu_hold_pc
// => xMAC RPU hold_pc register:
//    rpu_hold_pc and tpu_hold_pc are the only registers accessible by ARM-CPU,
//    while RPU or TPU are running (hold=0).
//    To access other registers of xMAC, first hold RPU and TPU.
//    This register is not visible for xMAC RPU and TPU.
// => Mode: Mode (r/w)
// ---------------------------------------------------------------------

#define REL_NETX_XM_RPU_HOLD_PC   0x00000A00U
#define NETX_XM0_RPU_HOLD_PC 0x00160A00U
#define NETX_XM1_RPU_HOLD_PC 0x00161A00U
#define NETX_XM2_RPU_HOLD_PC 0x00162A00U
#define NETX_XM3_RPU_HOLD_PC 0x00163A00U

#define MSK_NETX_XM_RPU_HOLD_PC_rpu_pc   0x0000007fU // [6:0]
#define SRT_NETX_XM_RPU_HOLD_PC_rpu_pc   0           
#define MSK_NETX_XM_RPU_HOLD_PC_rpu_hold 0x00008000U // [15]
#define SRT_NETX_XM_RPU_HOLD_PC_rpu_hold 15          

enum {
	BFW_NETX_XM_RPU_HOLD_PC_rpu_pc    = 7,  // [6:0]
	BFW_NETX_XM_RPU_HOLD_PC_reserved1 = 8,  // [14:7]
	BFW_NETX_XM_RPU_HOLD_PC_rpu_hold  = 1,  // [15]
	BFW_NETX_XM_RPU_HOLD_PC_reserved2 = 16  // [31:16]
};

typedef struct XMAC_RPU_HOLD_PC_BIT_Ttag {
	unsigned int rpu_pc    : BFW_NETX_XM_RPU_HOLD_PC_rpu_pc;    // Program counter (read only, write can happen via adr_xmac_rpu_pc) 
	unsigned int reserved1 : BFW_NETX_XM_RPU_HOLD_PC_reserved1; // reserved
	unsigned int rpu_hold  : BFW_NETX_XM_RPU_HOLD_PC_rpu_hold;  // to hold RPU 
	unsigned int reserved2 : BFW_NETX_XM_RPU_HOLD_PC_reserved2; // reserved
} XMAC_RPU_HOLD_PC_BIT_T;

typedef union {
	unsigned int           val;
	XMAC_RPU_HOLD_PC_BIT_T bf;
} XMAC_RPU_HOLD_PC_T;

// ---------------------------------------------------------------------
// Register xmac_tpu_hold_pc
// => xMAC TPU hold_pc register:
//    rpu_hold_pc and tpu_hold_pc are the only registers accessible by ARM-CPU,
//    while RPU or TPU are running (hold=0).
//    To access other registers of xMAC, first hold RPU and TPU.
//    This register is not visible for xMAC RPU and TPU.
// => Mode: Mode (r/w)
// ---------------------------------------------------------------------

#define REL_NETX_XM_TPU_HOLD_PC   0x00000A04U
#define NETX_XM0_TPU_HOLD_PC 0x00160A04U
#define NETX_XM1_TPU_HOLD_PC 0x00161A04U
#define NETX_XM2_TPU_HOLD_PC 0x00162A04U
#define NETX_XM3_TPU_HOLD_PC 0x00163A04U

#define MSK_NETX_XM_TPU_HOLD_PC_tpu_pc   0x0000007fU // [6:0]
#define SRT_NETX_XM_TPU_HOLD_PC_tpu_pc   0           
#define MSK_NETX_XM_TPU_HOLD_PC_tpu_hold 0x00008000U // [15]
#define SRT_NETX_XM_TPU_HOLD_PC_tpu_hold 15          

enum {
	BFW_NETX_XM_TPU_HOLD_PC_tpu_pc    = 7,  // [6:0]
	BFW_NETX_XM_TPU_HOLD_PC_reserved1 = 8,  // [14:7]
	BFW_NETX_XM_TPU_HOLD_PC_tpu_hold  = 1,  // [15]
	BFW_NETX_XM_TPU_HOLD_PC_reserved2 = 16  // [31:16]
};

typedef struct XMAC_TPU_HOLD_PC_BIT_Ttag {
	unsigned int tpu_pc    : BFW_NETX_XM_TPU_HOLD_PC_tpu_pc;    // Program counter (read only, write can happen via adr_xmac_tpu_pc) 
	unsigned int reserved1 : BFW_NETX_XM_TPU_HOLD_PC_reserved1; // reserved
	unsigned int tpu_hold  : BFW_NETX_XM_TPU_HOLD_PC_tpu_hold;  // to hold TPU 
	unsigned int reserved2 : BFW_NETX_XM_TPU_HOLD_PC_reserved2; // reserved
} XMAC_TPU_HOLD_PC_BIT_T;

typedef union {
	unsigned int           val;
	XMAC_TPU_HOLD_PC_BIT_T bf;
} XMAC_TPU_HOLD_PC_T;

// ---------------------------------------------------------------------
// Register xmac_sr0
// => Shared Work Register 0 accessible by all xMACs and xPECs
//    This register has a write pipeline delay of 1 clock cycle
//    Resetvalue : 0x00000000
// => Mode: Mode (r/w)
// ---------------------------------------------------------------------

#define REL_NETX_XM_SHAR_WRK0   0x00000800U
#define NETX_XM0_SHAR_WRK0 0x00160800U
#define NETX_XM1_SHAR_WRK0 0x00161800U
#define NETX_XM2_SHAR_WRK0 0x00162800U
#define NETX_XM3_SHAR_WRK0 0x00163800U

#define MSK_NETX_XM_SHAR_WRK0_SR0 0x0000ffffU // [15:0]
#define SRT_NETX_XM_SHAR_WRK0_SR0 0           

enum {
	BFW_NETX_XM_SHAR_WRK0_SR0       = 16, // [15:0]
	BFW_NETX_XM_SHAR_WRK0_reserved1 = 16  // [31:16]
};

typedef struct XMAC_SR0_BIT_Ttag {
	unsigned int SR0       : BFW_NETX_XM_SHAR_WRK0_SR0;       // Shared Register 
	unsigned int reserved1 : BFW_NETX_XM_SHAR_WRK0_reserved1; // reserved
} XMAC_SR0_BIT_T;

typedef union {
	unsigned int   val;
	XMAC_SR0_BIT_T bf;
} XMAC_SR0_T;

// ---------------------------------------------------------------------
// Register xmac_sr1
// => Shared Work Register 1 accessible by all xMACs and xPECs
//    This register has a write pipeline delay of 1 clock cycle
//    Resetvalue : 0x00000000
// => Mode: Mode (r/w)
// ---------------------------------------------------------------------

#define REL_NETX_XM_SHAR_WRK1   0x00000804U
#define NETX_XM0_SHAR_WRK1 0x00160804U
#define NETX_XM1_SHAR_WRK1 0x00161804U
#define NETX_XM2_SHAR_WRK1 0x00162804U
#define NETX_XM3_SHAR_WRK1 0x00163804U

#define MSK_NETX_XM_SHAR_WRK1_SR1 0x0000ffffU // [15:0]
#define SRT_NETX_XM_SHAR_WRK1_SR1 0           

enum {
	BFW_NETX_XM_SHAR_WRK1_SR1       = 16, // [15:0]
	BFW_NETX_XM_SHAR_WRK1_reserved1 = 16  // [31:16]
};

typedef struct XMAC_SR1_BIT_Ttag {
	unsigned int SR1       : BFW_NETX_XM_SHAR_WRK1_SR1;       // Shared Register 
	unsigned int reserved1 : BFW_NETX_XM_SHAR_WRK1_reserved1; // reserved
} XMAC_SR1_BIT_T;

typedef union {
	unsigned int   val;
	XMAC_SR1_BIT_T bf;
} XMAC_SR1_T;

// ---------------------------------------------------------------------
// Register xmac_sr2
// => Shared Work Register 2 accessible by all xMACs and xPECs
//    This register has a write pipeline delay of 1 clock cycle
//    Resetvalue : 0x00000000
// => Mode: Mode (r/w)
// ---------------------------------------------------------------------

#define REL_NETX_XM_SHAR_WRK2   0x00000808U
#define NETX_XM0_SHAR_WRK2 0x00160808U
#define NETX_XM1_SHAR_WRK2 0x00161808U
#define NETX_XM2_SHAR_WRK2 0x00162808U
#define NETX_XM3_SHAR_WRK2 0x00163808U

#define MSK_NETX_XM_SHAR_WRK2_SR2 0x0000ffffU // [15:0]
#define SRT_NETX_XM_SHAR_WRK2_SR2 0           

enum {
	BFW_NETX_XM_SHAR_WRK2_SR2       = 16, // [15:0]
	BFW_NETX_XM_SHAR_WRK2_reserved1 = 16  // [31:16]
};

typedef struct XMAC_SR2_BIT_Ttag {
	unsigned int SR2       : BFW_NETX_XM_SHAR_WRK2_SR2;       // Shared Register 
	unsigned int reserved1 : BFW_NETX_XM_SHAR_WRK2_reserved1; // reserved
} XMAC_SR2_BIT_T;

typedef union {
	unsigned int   val;
	XMAC_SR2_BIT_T bf;
} XMAC_SR2_T;

// ---------------------------------------------------------------------
// Register xmac_sr3
// => Shared Work Register 3 accessible by all xMACs and xPECs
//    This register has a write pipeline delay of 1 clock cycle
//    Resetvalue : 0x00000000
// => Mode: Mode (r/w)
// ---------------------------------------------------------------------

#define REL_NETX_XM_SHAR_WRK3   0x0000080CU
#define NETX_XM0_SHAR_WRK3 0x0016080CU
#define NETX_XM1_SHAR_WRK3 0x0016180CU
#define NETX_XM2_SHAR_WRK3 0x0016280CU
#define NETX_XM3_SHAR_WRK3 0x0016380CU

#define MSK_NETX_XM_SHAR_WRK3_SR3 0x0000ffffU // [15:0]
#define SRT_NETX_XM_SHAR_WRK3_SR3 0           

enum {
	BFW_NETX_XM_SHAR_WRK3_SR3       = 16, // [15:0]
	BFW_NETX_XM_SHAR_WRK3_reserved1 = 16  // [31:16]
};

typedef struct XMAC_SR3_BIT_Ttag {
	unsigned int SR3       : BFW_NETX_XM_SHAR_WRK3_SR3;       // Shared Register 
	unsigned int reserved1 : BFW_NETX_XM_SHAR_WRK3_reserved1; // reserved
} XMAC_SR3_BIT_T;

typedef union {
	unsigned int   val;
	XMAC_SR3_BIT_T bf;
} XMAC_SR3_T;

// ---------------------------------------------------------------------
// Register xmac_sr4
// => Shared Work Register 4 accessible by all xMACs and xPECs
//    This register has a write pipeline delay of 1 clock cycle
//    Resetvalue : 0x00000000
// => Mode: Mode (r/w)
// ---------------------------------------------------------------------

#define REL_NETX_XM_SHAR_WRK4   0x00000810U
#define NETX_XM0_SHAR_WRK4 0x00160810U
#define NETX_XM1_SHAR_WRK4 0x00161810U
#define NETX_XM2_SHAR_WRK4 0x00162810U
#define NETX_XM3_SHAR_WRK4 0x00163810U

#define MSK_NETX_XM_SHAR_WRK4_SR4 0x0000ffffU // [15:0]
#define SRT_NETX_XM_SHAR_WRK4_SR4 0           

enum {
	BFW_NETX_XM_SHAR_WRK4_SR4       = 16, // [15:0]
	BFW_NETX_XM_SHAR_WRK4_reserved1 = 16  // [31:16]
};

typedef struct XMAC_SR4_BIT_Ttag {
	unsigned int SR4       : BFW_NETX_XM_SHAR_WRK4_SR4;       // Shared Register 
	unsigned int reserved1 : BFW_NETX_XM_SHAR_WRK4_reserved1; // reserved
} XMAC_SR4_BIT_T;

typedef union {
	unsigned int   val;
	XMAC_SR4_BIT_T bf;
} XMAC_SR4_T;

// ---------------------------------------------------------------------
// Register xmac_sr5
// => Shared Work Register 5 accessible by all xMACs and xPECs
//    This register has a write pipeline delay of 1 clock cycle
//    Resetvalue : 0x00000000
// => Mode: Mode (r/w)
// ---------------------------------------------------------------------

#define REL_NETX_XM_SHAR_WRK5   0x00000814U
#define NETX_XM0_SHAR_WRK5 0x00160814U
#define NETX_XM1_SHAR_WRK5 0x00161814U
#define NETX_XM2_SHAR_WRK5 0x00162814U
#define NETX_XM3_SHAR_WRK5 0x00163814U

#define MSK_NETX_XM_SHAR_WRK5_SR5 0x0000ffffU // [15:0]
#define SRT_NETX_XM_SHAR_WRK5_SR5 0           

enum {
	BFW_NETX_XM_SHAR_WRK5_SR5       = 16, // [15:0]
	BFW_NETX_XM_SHAR_WRK5_reserved1 = 16  // [31:16]
};

typedef struct XMAC_SR5_BIT_Ttag {
	unsigned int SR5       : BFW_NETX_XM_SHAR_WRK5_SR5;       // Shared Register 
	unsigned int reserved1 : BFW_NETX_XM_SHAR_WRK5_reserved1; // reserved
} XMAC_SR5_BIT_T;

typedef union {
	unsigned int   val;
	XMAC_SR5_BIT_T bf;
} XMAC_SR5_T;

// ---------------------------------------------------------------------
// Register xmac_sr6
// => Shared Work Register 6 accessible by all xMACs and xPECs
//    This register has a write pipeline delay of 1 clock cycle
//    Resetvalue : 0x00000000
// => Mode: Mode (r/w)
// ---------------------------------------------------------------------

#define REL_NETX_XM_SHAR_WRK6   0x00000818U
#define NETX_XM0_SHAR_WRK6 0x00160818U
#define NETX_XM1_SHAR_WRK6 0x00161818U
#define NETX_XM2_SHAR_WRK6 0x00162818U
#define NETX_XM3_SHAR_WRK6 0x00163818U

#define MSK_NETX_XM_SHAR_WRK6_SR6 0x0000ffffU // [15:0]
#define SRT_NETX_XM_SHAR_WRK6_SR6 0           

enum {
	BFW_NETX_XM_SHAR_WRK6_SR6       = 16, // [15:0]
	BFW_NETX_XM_SHAR_WRK6_reserved1 = 16  // [31:16]
};

typedef struct XMAC_SR6_BIT_Ttag {
	unsigned int SR6       : BFW_NETX_XM_SHAR_WRK6_SR6;       // Shared Register 
	unsigned int reserved1 : BFW_NETX_XM_SHAR_WRK6_reserved1; // reserved
} XMAC_SR6_BIT_T;

typedef union {
	unsigned int   val;
	XMAC_SR6_BIT_T bf;
} XMAC_SR6_T;

// ---------------------------------------------------------------------
// Register xmac_sr7
// => Shared Work Register 7 accessible by all xMACs and xPECs
//    This register has a write pipeline delay of 1 clock cycle
//    Resetvalue : 0x00000000
// => Mode: Mode (r/w)
// ---------------------------------------------------------------------

#define REL_NETX_XM_SHAR_WRK7   0x0000081CU
#define NETX_XM0_SHAR_WRK7 0x0016081CU
#define NETX_XM1_SHAR_WRK7 0x0016181CU
#define NETX_XM2_SHAR_WRK7 0x0016281CU
#define NETX_XM3_SHAR_WRK7 0x0016381CU

#define MSK_NETX_XM_SHAR_WRK7_SR7 0x0000ffffU // [15:0]
#define SRT_NETX_XM_SHAR_WRK7_SR7 0           

enum {
	BFW_NETX_XM_SHAR_WRK7_SR7       = 16, // [15:0]
	BFW_NETX_XM_SHAR_WRK7_reserved1 = 16  // [31:16]
};

typedef struct XMAC_SR7_BIT_Ttag {
	unsigned int SR7       : BFW_NETX_XM_SHAR_WRK7_SR7;       // Shared Register 
	unsigned int reserved1 : BFW_NETX_XM_SHAR_WRK7_reserved1; // reserved
} XMAC_SR7_BIT_T;

typedef union {
	unsigned int   val;
	XMAC_SR7_BIT_T bf;
} XMAC_SR7_T;

// ---------------------------------------------------------------------
// Register xmac_sr8
// => Shared Work Register 8 accessible by all xMACs and xPECs
//    This register has a write pipeline delay of 1 clock cycle
//    Resetvalue : 0x00000000
// => Mode: Mode (r/w)
// ---------------------------------------------------------------------

#define REL_NETX_XM_SHAR_WRK8   0x00000820U
#define NETX_XM0_SHAR_WRK8 0x00160820U
#define NETX_XM1_SHAR_WRK8 0x00161820U
#define NETX_XM2_SHAR_WRK8 0x00162820U
#define NETX_XM3_SHAR_WRK8 0x00163820U

#define MSK_NETX_XM_SHAR_WRK8_SR8 0x0000ffffU // [15:0]
#define SRT_NETX_XM_SHAR_WRK8_SR8 0           

enum {
	BFW_NETX_XM_SHAR_WRK8_SR8       = 16, // [15:0]
	BFW_NETX_XM_SHAR_WRK8_reserved1 = 16  // [31:16]
};

typedef struct XMAC_SR8_BIT_Ttag {
	unsigned int SR8       : BFW_NETX_XM_SHAR_WRK8_SR8;       // Shared Register 
	unsigned int reserved1 : BFW_NETX_XM_SHAR_WRK8_reserved1; // reserved
} XMAC_SR8_BIT_T;

typedef union {
	unsigned int   val;
	XMAC_SR8_BIT_T bf;
} XMAC_SR8_T;

// ---------------------------------------------------------------------
// Register xmac_sr9
// => Shared Work Register 9 accessible by all xMACs and xPECs
//    This register has a write pipeline delay of 1 clock cycle
//    Resetvalue : 0x00000000
// => Mode: Mode (r/w)
// ---------------------------------------------------------------------

#define REL_NETX_XM_SHAR_WRK9   0x00000824U
#define NETX_XM0_SHAR_WRK9 0x00160824U
#define NETX_XM1_SHAR_WRK9 0x00161824U
#define NETX_XM2_SHAR_WRK9 0x00162824U
#define NETX_XM3_SHAR_WRK9 0x00163824U

#define MSK_NETX_XM_SHAR_WRK9_SR9 0x0000ffffU // [15:0]
#define SRT_NETX_XM_SHAR_WRK9_SR9 0           

enum {
	BFW_NETX_XM_SHAR_WRK9_SR9       = 16, // [15:0]
	BFW_NETX_XM_SHAR_WRK9_reserved1 = 16  // [31:16]
};

typedef struct XMAC_SR9_BIT_Ttag {
	unsigned int SR9       : BFW_NETX_XM_SHAR_WRK9_SR9;       // Shared Register 
	unsigned int reserved1 : BFW_NETX_XM_SHAR_WRK9_reserved1; // reserved
} XMAC_SR9_BIT_T;

typedef union {
	unsigned int   val;
	XMAC_SR9_BIT_T bf;
} XMAC_SR9_T;

// ---------------------------------------------------------------------
// Register xmac_sr10
// => Shared Work Register 10 accessible by all xMACs and xPECs
//    This register has a write pipeline delay of 1 clock cycle
//    Resetvalue : 0x00000000
// => Mode: Mode (r/w)
// ---------------------------------------------------------------------

#define REL_NETX_XM_SHAR_WRK10   0x00000828U
#define NETX_XM0_SHAR_WRK10 0x00160828U
#define NETX_XM1_SHAR_WRK10 0x00161828U
#define NETX_XM2_SHAR_WRK10 0x00162828U
#define NETX_XM3_SHAR_WRK10 0x00163828U

#define MSK_NETX_XM_SHAR_WRK10_SR10 0x0000ffffU // [15:0]
#define SRT_NETX_XM_SHAR_WRK10_SR10 0           

enum {
	BFW_NETX_XM_SHAR_WRK10_SR10      = 16, // [15:0]
	BFW_NETX_XM_SHAR_WRK10_reserved1 = 16  // [31:16]
};

typedef struct XMAC_SR10_BIT_Ttag {
	unsigned int SR10      : BFW_NETX_XM_SHAR_WRK10_SR10;      // Shared Register 
	unsigned int reserved1 : BFW_NETX_XM_SHAR_WRK10_reserved1; // reserved
} XMAC_SR10_BIT_T;

typedef union {
	unsigned int    val;
	XMAC_SR10_BIT_T bf;
} XMAC_SR10_T;

// ---------------------------------------------------------------------
// Register xmac_sr11
// => Shared Work Register 11 accessible by all xMACs and xPECs
//    This register has a write pipeline delay of 1 clock cycle
//    Resetvalue : 0x00000000
// => Mode: Mode (r/w)
// ---------------------------------------------------------------------

#define REL_NETX_XM_SHAR_WRK11   0x0000082CU
#define NETX_XM0_SHAR_WRK11 0x0016082CU
#define NETX_XM1_SHAR_WRK11 0x0016182CU
#define NETX_XM2_SHAR_WRK11 0x0016282CU
#define NETX_XM3_SHAR_WRK11 0x0016382CU

#define MSK_NETX_XM_SHAR_WRK11_SR11 0x0000ffffU // [15:0]
#define SRT_NETX_XM_SHAR_WRK11_SR11 0           

enum {
	BFW_NETX_XM_SHAR_WRK11_SR11      = 16, // [15:0]
	BFW_NETX_XM_SHAR_WRK11_reserved1 = 16  // [31:16]
};

typedef struct XMAC_SR11_BIT_Ttag {
	unsigned int SR11      : BFW_NETX_XM_SHAR_WRK11_SR11;      // Shared Register 
	unsigned int reserved1 : BFW_NETX_XM_SHAR_WRK11_reserved1; // reserved
} XMAC_SR11_BIT_T;

typedef union {
	unsigned int    val;
	XMAC_SR11_BIT_T bf;
} XMAC_SR11_T;

// ---------------------------------------------------------------------
// Register xmac_sr12
// => Shared Work Register 12 accessible by all xMACs and xPECs
//    This register has a write pipeline delay of 1 clock cycle
//    Resetvalue : 0x00000000
// => Mode: Mode (r/w)
// ---------------------------------------------------------------------

#define REL_NETX_XM_SHAR_WRK12   0x00000830U
#define NETX_XM0_SHAR_WRK12 0x00160830U
#define NETX_XM1_SHAR_WRK12 0x00161830U
#define NETX_XM2_SHAR_WRK12 0x00162830U
#define NETX_XM3_SHAR_WRK12 0x00163830U

#define MSK_NETX_XM_SHAR_WRK12_SR12 0x0000ffffU // [15:0]
#define SRT_NETX_XM_SHAR_WRK12_SR12 0           

enum {
	BFW_NETX_XM_SHAR_WRK12_SR12      = 16, // [15:0]
	BFW_NETX_XM_SHAR_WRK12_reserved1 = 16  // [31:16]
};

typedef struct XMAC_SR12_BIT_Ttag {
	unsigned int SR12      : BFW_NETX_XM_SHAR_WRK12_SR12;      // Shared Register 
	unsigned int reserved1 : BFW_NETX_XM_SHAR_WRK12_reserved1; // reserved
} XMAC_SR12_BIT_T;

typedef union {
	unsigned int    val;
	XMAC_SR12_BIT_T bf;
} XMAC_SR12_T;

// ---------------------------------------------------------------------
// Register xmac_sr13
// => Shared Work Register 13 accessible by all xMACs and xPECs
//    This register has a write pipeline delay of 1 clock cycle
//    Resetvalue : 0x00000000
// => Mode: Mode (r/w)
// ---------------------------------------------------------------------

#define REL_NETX_XM_SHAR_WRK13   0x00000834U
#define NETX_XM0_SHAR_WRK13 0x00160834U
#define NETX_XM1_SHAR_WRK13 0x00161834U
#define NETX_XM2_SHAR_WRK13 0x00162834U
#define NETX_XM3_SHAR_WRK13 0x00163834U

#define MSK_NETX_XM_SHAR_WRK13_SR13 0x0000ffffU // [15:0]
#define SRT_NETX_XM_SHAR_WRK13_SR13 0           

enum {
	BFW_NETX_XM_SHAR_WRK13_SR13      = 16, // [15:0]
	BFW_NETX_XM_SHAR_WRK13_reserved1 = 16  // [31:16]
};

typedef struct XMAC_SR13_BIT_Ttag {
	unsigned int SR13      : BFW_NETX_XM_SHAR_WRK13_SR13;      // Shared Register 
	unsigned int reserved1 : BFW_NETX_XM_SHAR_WRK13_reserved1; // reserved
} XMAC_SR13_BIT_T;

typedef union {
	unsigned int    val;
	XMAC_SR13_BIT_T bf;
} XMAC_SR13_T;

// ---------------------------------------------------------------------
// Register xmac_sr14
// => Shared Work Register 14 accessible by all xMACs and xPECs
//    This register has a write pipeline delay of 1 clock cycle
//    Resetvalue : 0x00000000
// => Mode: Mode (r/w)
// ---------------------------------------------------------------------

#define REL_NETX_XM_SHAR_WRK14   0x00000838U
#define NETX_XM0_SHAR_WRK14 0x00160838U
#define NETX_XM1_SHAR_WRK14 0x00161838U
#define NETX_XM2_SHAR_WRK14 0x00162838U
#define NETX_XM3_SHAR_WRK14 0x00163838U

#define MSK_NETX_XM_SHAR_WRK14_SR14 0x0000ffffU // [15:0]
#define SRT_NETX_XM_SHAR_WRK14_SR14 0           

enum {
	BFW_NETX_XM_SHAR_WRK14_SR14      = 16, // [15:0]
	BFW_NETX_XM_SHAR_WRK14_reserved1 = 16  // [31:16]
};

typedef struct XMAC_SR14_BIT_Ttag {
	unsigned int SR14      : BFW_NETX_XM_SHAR_WRK14_SR14;      // Shared Register 
	unsigned int reserved1 : BFW_NETX_XM_SHAR_WRK14_reserved1; // reserved
} XMAC_SR14_BIT_T;

typedef union {
	unsigned int    val;
	XMAC_SR14_BIT_T bf;
} XMAC_SR14_T;

// ---------------------------------------------------------------------
// Register xmac_sr15
// => Shared Work Register 15 accessible by all xMACs and xPECs
//    This register has a write pipeline delay of 1 clock cycle
//    Resetvalue : 0x00000000
// => Mode: Mode (r/w)
// ---------------------------------------------------------------------

#define REL_NETX_XM_SHAR_WRK15   0x0000083CU
#define NETX_XM0_SHAR_WRK15 0x0016083CU
#define NETX_XM1_SHAR_WRK15 0x0016183CU
#define NETX_XM2_SHAR_WRK15 0x0016283CU
#define NETX_XM3_SHAR_WRK15 0x0016383CU

#define MSK_NETX_XM_SHAR_WRK15_SR15 0x0000ffffU // [15:0]
#define SRT_NETX_XM_SHAR_WRK15_SR15 0           

enum {
	BFW_NETX_XM_SHAR_WRK15_SR15      = 16, // [15:0]
	BFW_NETX_XM_SHAR_WRK15_reserved1 = 16  // [31:16]
};

typedef struct XMAC_SR15_BIT_Ttag {
	unsigned int SR15      : BFW_NETX_XM_SHAR_WRK15_SR15;      // Shared Register 
	unsigned int reserved1 : BFW_NETX_XM_SHAR_WRK15_reserved1; // reserved
} XMAC_SR15_BIT_T;

typedef union {
	unsigned int    val;
	XMAC_SR15_BIT_T bf;
} XMAC_SR15_T;

// ---------------------------------------------------------------------
// Register xmac_status_shared0
// => xMAC0 Shared Status Register
// => Mode: Mode (r)
// ---------------------------------------------------------------------

#define REL_NETX_XM_STAT_SHAR0   0x00000840U
#define NETX_XM0_STAT_SHAR0 0x00160840U
#define NETX_XM1_STAT_SHAR0 0x00161840U
#define NETX_XM2_STAT_SHAR0 0x00162840U
#define NETX_XM3_STAT_SHAR0 0x00163840U

#define MSK_NETX_XM_STAT_SHAR0_gpio0_in  0x00000001U // [0]
#define SRT_NETX_XM_STAT_SHAR0_gpio0_in  0           
#define MSK_NETX_XM_STAT_SHAR0_gpio1_in  0x00000002U // [1]
#define SRT_NETX_XM_STAT_SHAR0_gpio1_in  1           
#define MSK_NETX_XM_STAT_SHAR0_rx_rdy    0x00000004U // [2]
#define SRT_NETX_XM_STAT_SHAR0_rx_rdy    2           
#define MSK_NETX_XM_STAT_SHAR0_rx_ovf    0x00000008U // [3]
#define SRT_NETX_XM_STAT_SHAR0_rx_ovf    3           
#define MSK_NETX_XM_STAT_SHAR0_tx_nxt    0x00000010U // [4]
#define SRT_NETX_XM_STAT_SHAR0_tx_nxt    4           
#define MSK_NETX_XM_STAT_SHAR0_tx_ufl    0x00000020U // [5]
#define SRT_NETX_XM_STAT_SHAR0_tx_ufl    5           
#define MSK_NETX_XM_STAT_SHAR0_utx_empty 0x00000040U // [6]
#define SRT_NETX_XM_STAT_SHAR0_utx_empty 6           
#define MSK_NETX_XM_STAT_SHAR0_brec      0x00000080U // [7]
#define SRT_NETX_XM_STAT_SHAR0_brec      7           
#define MSK_NETX_XM_STAT_SHAR0_btran     0x00000100U // [8]
#define SRT_NETX_XM_STAT_SHAR0_btran     8           
#define MSK_NETX_XM_STAT_SHAR0_stat_rpu  0x00000200U // [9]
#define SRT_NETX_XM_STAT_SHAR0_stat_rpu  9           
#define MSK_NETX_XM_STAT_SHAR0_stat_tpu  0x00000400U // [10]
#define SRT_NETX_XM_STAT_SHAR0_stat_tpu  10          
#define MSK_NETX_XM_STAT_SHAR0_phy_led0  0x00001000U // [12]
#define SRT_NETX_XM_STAT_SHAR0_phy_led0  12          
#define MSK_NETX_XM_STAT_SHAR0_phy_led1  0x00002000U // [13]
#define SRT_NETX_XM_STAT_SHAR0_phy_led1  13          
#define MSK_NETX_XM_STAT_SHAR0_phy_led2  0x00004000U // [14]
#define SRT_NETX_XM_STAT_SHAR0_phy_led2  14          
#define MSK_NETX_XM_STAT_SHAR0_phy_led3  0x00008000U // [15]
#define SRT_NETX_XM_STAT_SHAR0_phy_led3  15          

enum {
	BFW_NETX_XM_STAT_SHAR0_gpio0_in  = 1,  // [0]
	BFW_NETX_XM_STAT_SHAR0_gpio1_in  = 1,  // [1]
	BFW_NETX_XM_STAT_SHAR0_rx_rdy    = 1,  // [2]
	BFW_NETX_XM_STAT_SHAR0_rx_ovf    = 1,  // [3]
	BFW_NETX_XM_STAT_SHAR0_tx_nxt    = 1,  // [4]
	BFW_NETX_XM_STAT_SHAR0_tx_ufl    = 1,  // [5]
	BFW_NETX_XM_STAT_SHAR0_utx_empty = 1,  // [6]
	BFW_NETX_XM_STAT_SHAR0_brec      = 1,  // [7]
	BFW_NETX_XM_STAT_SHAR0_btran     = 1,  // [8]
	BFW_NETX_XM_STAT_SHAR0_stat_rpu  = 1,  // [9]
	BFW_NETX_XM_STAT_SHAR0_stat_tpu  = 1,  // [10]
	BFW_NETX_XM_STAT_SHAR0_reserved1 = 1,  // [11]
	BFW_NETX_XM_STAT_SHAR0_phy_led0  = 1,  // [12]
	BFW_NETX_XM_STAT_SHAR0_phy_led1  = 1,  // [13]
	BFW_NETX_XM_STAT_SHAR0_phy_led2  = 1,  // [14]
	BFW_NETX_XM_STAT_SHAR0_phy_led3  = 1,  // [15]
	BFW_NETX_XM_STAT_SHAR0_reserved2 = 16  // [31:16]
};

typedef struct XMAC_STATUS_SHARED0_BIT_Ttag {
	unsigned int gpio0_in  : BFW_NETX_XM_STAT_SHAR0_gpio0_in;  // value at external gpio1 pin
	unsigned int gpio1_in  : BFW_NETX_XM_STAT_SHAR0_gpio1_in;  // value at external gpio2 pin
	unsigned int rx_rdy    : BFW_NETX_XM_STAT_SHAR0_rx_rdy;    // received bytes are valid at output of URX_FIFO
	unsigned int rx_ovf    : BFW_NETX_XM_STAT_SHAR0_rx_ovf;    // receive overflow (too much data in URX_FIFO)
	unsigned int tx_nxt    : BFW_NETX_XM_STAT_SHAR0_tx_nxt;    // put next tx_word to UTX_FIFO: at least one entry of UTX_FIFO is empty
	unsigned int tx_ufl    : BFW_NETX_XM_STAT_SHAR0_tx_ufl;    // transmit underflow (not enough data in UTX_FIFO)
	unsigned int utx_empty : BFW_NETX_XM_STAT_SHAR0_utx_empty; // UTX_FIFO is empty
	unsigned int brec      : BFW_NETX_XM_STAT_SHAR0_brec;      // bit_received (active for 1 cc)
	unsigned int btran     : BFW_NETX_XM_STAT_SHAR0_btran;     // bit_transmitted (active for 1 cc)
	unsigned int stat_rpu  : BFW_NETX_XM_STAT_SHAR0_stat_rpu;  // set and reset by RPU command bits
	unsigned int stat_tpu  : BFW_NETX_XM_STAT_SHAR0_stat_tpu;  // set and reset by TPU command bits
	unsigned int reserved1 : BFW_NETX_XM_STAT_SHAR0_reserved1; // reserved
	unsigned int phy_led0  : BFW_NETX_XM_STAT_SHAR0_phy_led0;  // Internal Phy0 LED0, usually link_status
	unsigned int phy_led1  : BFW_NETX_XM_STAT_SHAR0_phy_led1;  // Internal Phy0 LED1, usually activity
	unsigned int phy_led2  : BFW_NETX_XM_STAT_SHAR0_phy_led2;  // Internal Phy0 LED2, usually speed100
	unsigned int phy_led3  : BFW_NETX_XM_STAT_SHAR0_phy_led3;  // Internal Phy0 LED3, usually full_duplex
	unsigned int reserved2 : BFW_NETX_XM_STAT_SHAR0_reserved2; // reserved
} XMAC_STATUS_SHARED0_BIT_T;

typedef union {
	unsigned int              val;
	XMAC_STATUS_SHARED0_BIT_T bf;
} XMAC_STATUS_SHARED0_T;

// ---------------------------------------------------------------------
// Register xmac_config_shared0
// => xMAC0 Shared Config Register
//    This register has a write pipeline delay of 1 clock cycle
// => Mode: Mode (r/w)
// ---------------------------------------------------------------------

#define REL_NETX_XM_CFG_SHAR0   0x00000844U
#define NETX_XM0_CFG_SHAR0 0x00160844U
#define NETX_XM1_CFG_SHAR0 0x00161844U
#define NETX_XM2_CFG_SHAR0 0x00162844U
#define NETX_XM3_CFG_SHAR0 0x00163844U

#define MSK_NETX_XM_CFG_SHAR0_rx_nof_bits   0x0000000fU // [3:0]
#define SRT_NETX_XM_CFG_SHAR0_rx_nof_bits   0           
#define MSK_NETX_XM_CFG_SHAR0_tx_nof_bits   0x000000f0U // [7:4]
#define SRT_NETX_XM_CFG_SHAR0_tx_nof_bits   4           
#define MSK_NETX_XM_CFG_SHAR0_rx_shift_lr   0x00000100U // [8]
#define SRT_NETX_XM_CFG_SHAR0_rx_shift_lr   8           
#define MSK_NETX_XM_CFG_SHAR0_tx_shift_lr   0x00000200U // [9]
#define SRT_NETX_XM_CFG_SHAR0_tx_shift_lr   9           
#define MSK_NETX_XM_CFG_SHAR0_reset_rx_fifo 0x00000400U // [10]
#define SRT_NETX_XM_CFG_SHAR0_reset_rx_fifo 10          
#define MSK_NETX_XM_CFG_SHAR0_reset_tx_fifo 0x00000800U // [11]
#define SRT_NETX_XM_CFG_SHAR0_reset_tx_fifo 11          
#define MSK_NETX_XM_CFG_SHAR0_gpio0_out     0x00001000U // [12]
#define SRT_NETX_XM_CFG_SHAR0_gpio0_out     12          
#define MSK_NETX_XM_CFG_SHAR0_gpio0_oe      0x00002000U // [13]
#define SRT_NETX_XM_CFG_SHAR0_gpio0_oe      13          
#define MSK_NETX_XM_CFG_SHAR0_gpio1_out     0x00004000U // [14]
#define SRT_NETX_XM_CFG_SHAR0_gpio1_out     14          
#define MSK_NETX_XM_CFG_SHAR0_gpio1_oe      0x00008000U // [15]
#define SRT_NETX_XM_CFG_SHAR0_gpio1_oe      15          

enum {
	BFW_NETX_XM_CFG_SHAR0_rx_nof_bits   = 4,  // [3:0]
	BFW_NETX_XM_CFG_SHAR0_tx_nof_bits   = 4,  // [7:4]
	BFW_NETX_XM_CFG_SHAR0_rx_shift_lr   = 1,  // [8]
	BFW_NETX_XM_CFG_SHAR0_tx_shift_lr   = 1,  // [9]
	BFW_NETX_XM_CFG_SHAR0_reset_rx_fifo = 1,  // [10]
	BFW_NETX_XM_CFG_SHAR0_reset_tx_fifo = 1,  // [11]
	BFW_NETX_XM_CFG_SHAR0_gpio0_out     = 1,  // [12]
	BFW_NETX_XM_CFG_SHAR0_gpio0_oe      = 1,  // [13]
	BFW_NETX_XM_CFG_SHAR0_gpio1_out     = 1,  // [14]
	BFW_NETX_XM_CFG_SHAR0_gpio1_oe      = 1,  // [15]
	BFW_NETX_XM_CFG_SHAR0_reserved1     = 16  // [31:16]
};

typedef struct XMAC_CONFIG_SHARED0_BIT_Ttag {
	unsigned int rx_nof_bits   : BFW_NETX_XM_CFG_SHAR0_rx_nof_bits;   // Number of bits written by SBU to rx-register, only used for rx_hw_count 
	unsigned int tx_nof_bits   : BFW_NETX_XM_CFG_SHAR0_tx_nof_bits;   // Number of bits read by OBU from tx-register 
	unsigned int rx_shift_lr   : BFW_NETX_XM_CFG_SHAR0_rx_shift_lr;   // 1: SBU reads incoming bits to position 0 of register rx and shifts rx left, 
	                                                        // 0: SBU reads incoming bits to position 15 of register rx and shifts rx right
	unsigned int tx_shift_lr   : BFW_NETX_XM_CFG_SHAR0_tx_shift_lr;   // 1: OBU reads outgoing bits from position 15 of register tx and shifts tx left, 
	                                                        // 0: OBU reads outgoing bits from position 0 of register tx and shifts tx right
	unsigned int reset_rx_fifo : BFW_NETX_XM_CFG_SHAR0_reset_rx_fifo; // reset URX_FIFO and rx_ovf bit inside status_shared register 
	unsigned int reset_tx_fifo : BFW_NETX_XM_CFG_SHAR0_reset_tx_fifo; // reset UTX_FIFO and tx_ufl bit inside status_shared register 
	unsigned int gpio0_out     : BFW_NETX_XM_CFG_SHAR0_gpio0_out;     // General Purpose IO 0 output 
	unsigned int gpio0_oe      : BFW_NETX_XM_CFG_SHAR0_gpio0_oe;      // General Purpose IO 0 output enable 
	unsigned int gpio1_out     : BFW_NETX_XM_CFG_SHAR0_gpio1_out;     // General Purpose IO 1 output 
	unsigned int gpio1_oe      : BFW_NETX_XM_CFG_SHAR0_gpio1_oe;      // General Purpose IO 1 output enable 
	unsigned int reserved1     : BFW_NETX_XM_CFG_SHAR0_reserved1;     // reserved
} XMAC_CONFIG_SHARED0_BIT_T;

typedef union {
	unsigned int              val;
	XMAC_CONFIG_SHARED0_BIT_T bf;
} XMAC_CONFIG_SHARED0_T;

// ---------------------------------------------------------------------
// Register xmac_status_shared1
// => xMAC1 Shared Status Register
// => Mode: Mode (r)
// ---------------------------------------------------------------------

#define REL_NETX_XM_STAT_SHAR1   0x00000848U
#define NETX_XM0_STAT_SHAR1 0x00160848U
#define NETX_XM1_STAT_SHAR1 0x00161848U
#define NETX_XM2_STAT_SHAR1 0x00162848U
#define NETX_XM3_STAT_SHAR1 0x00163848U

#define MSK_NETX_XM_STAT_SHAR1_gpio0_in  0x00000001U // [0]
#define SRT_NETX_XM_STAT_SHAR1_gpio0_in  0           
#define MSK_NETX_XM_STAT_SHAR1_gpio1_in  0x00000002U // [1]
#define SRT_NETX_XM_STAT_SHAR1_gpio1_in  1           
#define MSK_NETX_XM_STAT_SHAR1_rx_rdy    0x00000004U // [2]
#define SRT_NETX_XM_STAT_SHAR1_rx_rdy    2           
#define MSK_NETX_XM_STAT_SHAR1_rx_ovf    0x00000008U // [3]
#define SRT_NETX_XM_STAT_SHAR1_rx_ovf    3           
#define MSK_NETX_XM_STAT_SHAR1_tx_nxt    0x00000010U // [4]
#define SRT_NETX_XM_STAT_SHAR1_tx_nxt    4           
#define MSK_NETX_XM_STAT_SHAR1_tx_ufl    0x00000020U // [5]
#define SRT_NETX_XM_STAT_SHAR1_tx_ufl    5           
#define MSK_NETX_XM_STAT_SHAR1_utx_empty 0x00000040U // [6]
#define SRT_NETX_XM_STAT_SHAR1_utx_empty 6           
#define MSK_NETX_XM_STAT_SHAR1_brec      0x00000080U // [7]
#define SRT_NETX_XM_STAT_SHAR1_brec      7           
#define MSK_NETX_XM_STAT_SHAR1_btran     0x00000100U // [8]
#define SRT_NETX_XM_STAT_SHAR1_btran     8           
#define MSK_NETX_XM_STAT_SHAR1_stat_rpu  0x00000200U // [9]
#define SRT_NETX_XM_STAT_SHAR1_stat_rpu  9           
#define MSK_NETX_XM_STAT_SHAR1_stat_tpu  0x00000400U // [10]
#define SRT_NETX_XM_STAT_SHAR1_stat_tpu  10          
#define MSK_NETX_XM_STAT_SHAR1_phy_led0  0x00001000U // [12]
#define SRT_NETX_XM_STAT_SHAR1_phy_led0  12          
#define MSK_NETX_XM_STAT_SHAR1_phy_led1  0x00002000U // [13]
#define SRT_NETX_XM_STAT_SHAR1_phy_led1  13          
#define MSK_NETX_XM_STAT_SHAR1_phy_led2  0x00004000U // [14]
#define SRT_NETX_XM_STAT_SHAR1_phy_led2  14          
#define MSK_NETX_XM_STAT_SHAR1_phy_led3  0x00008000U // [15]
#define SRT_NETX_XM_STAT_SHAR1_phy_led3  15          

enum {
	BFW_NETX_XM_STAT_SHAR1_gpio0_in  = 1,  // [0]
	BFW_NETX_XM_STAT_SHAR1_gpio1_in  = 1,  // [1]
	BFW_NETX_XM_STAT_SHAR1_rx_rdy    = 1,  // [2]
	BFW_NETX_XM_STAT_SHAR1_rx_ovf    = 1,  // [3]
	BFW_NETX_XM_STAT_SHAR1_tx_nxt    = 1,  // [4]
	BFW_NETX_XM_STAT_SHAR1_tx_ufl    = 1,  // [5]
	BFW_NETX_XM_STAT_SHAR1_utx_empty = 1,  // [6]
	BFW_NETX_XM_STAT_SHAR1_brec      = 1,  // [7]
	BFW_NETX_XM_STAT_SHAR1_btran     = 1,  // [8]
	BFW_NETX_XM_STAT_SHAR1_stat_rpu  = 1,  // [9]
	BFW_NETX_XM_STAT_SHAR1_stat_tpu  = 1,  // [10]
	BFW_NETX_XM_STAT_SHAR1_reserved1 = 1,  // [11]
	BFW_NETX_XM_STAT_SHAR1_phy_led0  = 1,  // [12]
	BFW_NETX_XM_STAT_SHAR1_phy_led1  = 1,  // [13]
	BFW_NETX_XM_STAT_SHAR1_phy_led2  = 1,  // [14]
	BFW_NETX_XM_STAT_SHAR1_phy_led3  = 1,  // [15]
	BFW_NETX_XM_STAT_SHAR1_reserved2 = 16  // [31:16]
};

typedef struct XMAC_STATUS_SHARED1_BIT_Ttag {
	unsigned int gpio0_in  : BFW_NETX_XM_STAT_SHAR1_gpio0_in;  // value at external gpio1 pin
	unsigned int gpio1_in  : BFW_NETX_XM_STAT_SHAR1_gpio1_in;  // value at external gpio2 pin
	unsigned int rx_rdy    : BFW_NETX_XM_STAT_SHAR1_rx_rdy;    // received bytes are valid at output of URX_FIFO
	unsigned int rx_ovf    : BFW_NETX_XM_STAT_SHAR1_rx_ovf;    // receive overflow (too much data in URX_FIFO)
	unsigned int tx_nxt    : BFW_NETX_XM_STAT_SHAR1_tx_nxt;    // put next tx_word to UTX_FIFO: at least one entry of UTX_FIFO is empty
	unsigned int tx_ufl    : BFW_NETX_XM_STAT_SHAR1_tx_ufl;    // transmit underflow (not enough data in UTX_FIFO)
	unsigned int utx_empty : BFW_NETX_XM_STAT_SHAR1_utx_empty; // UTX_FIFO is empty
	unsigned int brec      : BFW_NETX_XM_STAT_SHAR1_brec;      // bit_received (active for 1 cc)
	unsigned int btran     : BFW_NETX_XM_STAT_SHAR1_btran;     // bit_transmitted (active for 1 cc)
	unsigned int stat_rpu  : BFW_NETX_XM_STAT_SHAR1_stat_rpu;  // set and reset by RPU command bits
	unsigned int stat_tpu  : BFW_NETX_XM_STAT_SHAR1_stat_tpu;  // set and reset by TPU command bits
	unsigned int reserved1 : BFW_NETX_XM_STAT_SHAR1_reserved1; // reserved
	unsigned int phy_led0  : BFW_NETX_XM_STAT_SHAR1_phy_led0;  // Internal Phy1 LED0, usually link_status
	unsigned int phy_led1  : BFW_NETX_XM_STAT_SHAR1_phy_led1;  // Internal Phy1 LED1, usually activity
	unsigned int phy_led2  : BFW_NETX_XM_STAT_SHAR1_phy_led2;  // Internal Phy1 LED2, usually speed100
	unsigned int phy_led3  : BFW_NETX_XM_STAT_SHAR1_phy_led3;  // Internal Phy1 LED3, usually full_duplex
	unsigned int reserved2 : BFW_NETX_XM_STAT_SHAR1_reserved2; // reserved
} XMAC_STATUS_SHARED1_BIT_T;

typedef union {
	unsigned int              val;
	XMAC_STATUS_SHARED1_BIT_T bf;
} XMAC_STATUS_SHARED1_T;

// ---------------------------------------------------------------------
// Register xmac_config_shared1
// => xMAC1 Shared Config Register
//    This register has a write pipeline delay of 1 clock cycle
// => Mode: Mode (r/w)
// ---------------------------------------------------------------------

#define REL_NETX_XM_CFG_SHAR1   0x0000084CU
#define NETX_XM0_CFG_SHAR1 0x0016084CU
#define NETX_XM1_CFG_SHAR1 0x0016184CU
#define NETX_XM2_CFG_SHAR1 0x0016284CU
#define NETX_XM3_CFG_SHAR1 0x0016384CU

#define MSK_NETX_XM_CFG_SHAR1_rx_nof_bits   0x0000000fU // [3:0]
#define SRT_NETX_XM_CFG_SHAR1_rx_nof_bits   0           
#define MSK_NETX_XM_CFG_SHAR1_tx_nof_bits   0x000000f0U // [7:4]
#define SRT_NETX_XM_CFG_SHAR1_tx_nof_bits   4           
#define MSK_NETX_XM_CFG_SHAR1_rx_shift_lr   0x00000100U // [8]
#define SRT_NETX_XM_CFG_SHAR1_rx_shift_lr   8           
#define MSK_NETX_XM_CFG_SHAR1_tx_shift_lr   0x00000200U // [9]
#define SRT_NETX_XM_CFG_SHAR1_tx_shift_lr   9           
#define MSK_NETX_XM_CFG_SHAR1_reset_rx_fifo 0x00000400U // [10]
#define SRT_NETX_XM_CFG_SHAR1_reset_rx_fifo 10          
#define MSK_NETX_XM_CFG_SHAR1_reset_tx_fifo 0x00000800U // [11]
#define SRT_NETX_XM_CFG_SHAR1_reset_tx_fifo 11          
#define MSK_NETX_XM_CFG_SHAR1_gpio0_out     0x00001000U // [12]
#define SRT_NETX_XM_CFG_SHAR1_gpio0_out     12          
#define MSK_NETX_XM_CFG_SHAR1_gpio0_oe      0x00002000U // [13]
#define SRT_NETX_XM_CFG_SHAR1_gpio0_oe      13          
#define MSK_NETX_XM_CFG_SHAR1_gpio1_out     0x00004000U // [14]
#define SRT_NETX_XM_CFG_SHAR1_gpio1_out     14          
#define MSK_NETX_XM_CFG_SHAR1_gpio1_oe      0x00008000U // [15]
#define SRT_NETX_XM_CFG_SHAR1_gpio1_oe      15          

enum {
	BFW_NETX_XM_CFG_SHAR1_rx_nof_bits   = 4,  // [3:0]
	BFW_NETX_XM_CFG_SHAR1_tx_nof_bits   = 4,  // [7:4]
	BFW_NETX_XM_CFG_SHAR1_rx_shift_lr   = 1,  // [8]
	BFW_NETX_XM_CFG_SHAR1_tx_shift_lr   = 1,  // [9]
	BFW_NETX_XM_CFG_SHAR1_reset_rx_fifo = 1,  // [10]
	BFW_NETX_XM_CFG_SHAR1_reset_tx_fifo = 1,  // [11]
	BFW_NETX_XM_CFG_SHAR1_gpio0_out     = 1,  // [12]
	BFW_NETX_XM_CFG_SHAR1_gpio0_oe      = 1,  // [13]
	BFW_NETX_XM_CFG_SHAR1_gpio1_out     = 1,  // [14]
	BFW_NETX_XM_CFG_SHAR1_gpio1_oe      = 1,  // [15]
	BFW_NETX_XM_CFG_SHAR1_reserved1     = 16  // [31:16]
};

typedef struct XMAC_CONFIG_SHARED1_BIT_Ttag {
	unsigned int rx_nof_bits   : BFW_NETX_XM_CFG_SHAR1_rx_nof_bits;   // Number of bits written by SBU to rx-register, only used for rx_hw_count 
	unsigned int tx_nof_bits   : BFW_NETX_XM_CFG_SHAR1_tx_nof_bits;   // Number of bits read by OBU from tx-register 
	unsigned int rx_shift_lr   : BFW_NETX_XM_CFG_SHAR1_rx_shift_lr;   // 1: SBU reads incoming bits to position 0 of register rx and shifts rx left, 
	                                                        // 0: SBU reads incoming bits to position 15 of register rx and shifts rx right
	unsigned int tx_shift_lr   : BFW_NETX_XM_CFG_SHAR1_tx_shift_lr;   // 1: OBU reads outgoing bits from position 15 of register tx and shifts tx left, 
	                                                        // 0: OBU reads outgoing bits from position 0 of register tx and shifts tx right
	unsigned int reset_rx_fifo : BFW_NETX_XM_CFG_SHAR1_reset_rx_fifo; // reset URX_FIFO and rx_ovf bit inside status_shared register 
	unsigned int reset_tx_fifo : BFW_NETX_XM_CFG_SHAR1_reset_tx_fifo; // reset UTX_FIFO and tx_ufl bit inside status_shared register 
	unsigned int gpio0_out     : BFW_NETX_XM_CFG_SHAR1_gpio0_out;     // General Purpose IO 0 output 
	unsigned int gpio0_oe      : BFW_NETX_XM_CFG_SHAR1_gpio0_oe;      // General Purpose IO 0 output enable 
	unsigned int gpio1_out     : BFW_NETX_XM_CFG_SHAR1_gpio1_out;     // General Purpose IO 1 output 
	unsigned int gpio1_oe      : BFW_NETX_XM_CFG_SHAR1_gpio1_oe;      // General Purpose IO 1 output enable 
	unsigned int reserved1     : BFW_NETX_XM_CFG_SHAR1_reserved1;     // reserved
} XMAC_CONFIG_SHARED1_BIT_T;

typedef union {
	unsigned int              val;
	XMAC_CONFIG_SHARED1_BIT_T bf;
} XMAC_CONFIG_SHARED1_T;

// ---------------------------------------------------------------------
// Register xmac_status_shared2
// => xMAC2 Shared Status Register
// => Mode: Mode (r)
// ---------------------------------------------------------------------

#define REL_NETX_XM_STAT_SHAR2   0x00000850U
#define NETX_XM0_STAT_SHAR2 0x00160850U
#define NETX_XM1_STAT_SHAR2 0x00161850U
#define NETX_XM2_STAT_SHAR2 0x00162850U
#define NETX_XM3_STAT_SHAR2 0x00163850U

#define MSK_NETX_XM_STAT_SHAR2_gpio0_in  0x00000001U // [0]
#define SRT_NETX_XM_STAT_SHAR2_gpio0_in  0           
#define MSK_NETX_XM_STAT_SHAR2_gpio1_in  0x00000002U // [1]
#define SRT_NETX_XM_STAT_SHAR2_gpio1_in  1           
#define MSK_NETX_XM_STAT_SHAR2_rx_rdy    0x00000004U // [2]
#define SRT_NETX_XM_STAT_SHAR2_rx_rdy    2           
#define MSK_NETX_XM_STAT_SHAR2_rx_ovf    0x00000008U // [3]
#define SRT_NETX_XM_STAT_SHAR2_rx_ovf    3           
#define MSK_NETX_XM_STAT_SHAR2_tx_nxt    0x00000010U // [4]
#define SRT_NETX_XM_STAT_SHAR2_tx_nxt    4           
#define MSK_NETX_XM_STAT_SHAR2_tx_ufl    0x00000020U // [5]
#define SRT_NETX_XM_STAT_SHAR2_tx_ufl    5           
#define MSK_NETX_XM_STAT_SHAR2_utx_empty 0x00000040U // [6]
#define SRT_NETX_XM_STAT_SHAR2_utx_empty 6           
#define MSK_NETX_XM_STAT_SHAR2_brec      0x00000080U // [7]
#define SRT_NETX_XM_STAT_SHAR2_brec      7           
#define MSK_NETX_XM_STAT_SHAR2_btran     0x00000100U // [8]
#define SRT_NETX_XM_STAT_SHAR2_btran     8           
#define MSK_NETX_XM_STAT_SHAR2_stat_rpu  0x00000200U // [9]
#define SRT_NETX_XM_STAT_SHAR2_stat_rpu  9           
#define MSK_NETX_XM_STAT_SHAR2_stat_tpu  0x00000400U // [10]
#define SRT_NETX_XM_STAT_SHAR2_stat_tpu  10          
#define MSK_NETX_XM_STAT_SHAR2_phy_led0  0x00001000U // [12]
#define SRT_NETX_XM_STAT_SHAR2_phy_led0  12          
#define MSK_NETX_XM_STAT_SHAR2_phy_led1  0x00002000U // [13]
#define SRT_NETX_XM_STAT_SHAR2_phy_led1  13          
#define MSK_NETX_XM_STAT_SHAR2_phy_led2  0x00004000U // [14]
#define SRT_NETX_XM_STAT_SHAR2_phy_led2  14          
#define MSK_NETX_XM_STAT_SHAR2_phy_led3  0x00008000U // [15]
#define SRT_NETX_XM_STAT_SHAR2_phy_led3  15          

enum {
	BFW_NETX_XM_STAT_SHAR2_gpio0_in  = 1,  // [0]
	BFW_NETX_XM_STAT_SHAR2_gpio1_in  = 1,  // [1]
	BFW_NETX_XM_STAT_SHAR2_rx_rdy    = 1,  // [2]
	BFW_NETX_XM_STAT_SHAR2_rx_ovf    = 1,  // [3]
	BFW_NETX_XM_STAT_SHAR2_tx_nxt    = 1,  // [4]
	BFW_NETX_XM_STAT_SHAR2_tx_ufl    = 1,  // [5]
	BFW_NETX_XM_STAT_SHAR2_utx_empty = 1,  // [6]
	BFW_NETX_XM_STAT_SHAR2_brec      = 1,  // [7]
	BFW_NETX_XM_STAT_SHAR2_btran     = 1,  // [8]
	BFW_NETX_XM_STAT_SHAR2_stat_rpu  = 1,  // [9]
	BFW_NETX_XM_STAT_SHAR2_stat_tpu  = 1,  // [10]
	BFW_NETX_XM_STAT_SHAR2_reserved1 = 1,  // [11]
	BFW_NETX_XM_STAT_SHAR2_phy_led0  = 1,  // [12]
	BFW_NETX_XM_STAT_SHAR2_phy_led1  = 1,  // [13]
	BFW_NETX_XM_STAT_SHAR2_phy_led2  = 1,  // [14]
	BFW_NETX_XM_STAT_SHAR2_phy_led3  = 1,  // [15]
	BFW_NETX_XM_STAT_SHAR2_reserved2 = 16  // [31:16]
};

typedef struct XMAC_STATUS_SHARED2_BIT_Ttag {
	unsigned int gpio0_in  : BFW_NETX_XM_STAT_SHAR2_gpio0_in;  // value at external gpio1 pin
	unsigned int gpio1_in  : BFW_NETX_XM_STAT_SHAR2_gpio1_in;  // value at external gpio2 pin
	unsigned int rx_rdy    : BFW_NETX_XM_STAT_SHAR2_rx_rdy;    // received bytes are valid at output of URX_FIFO
	unsigned int rx_ovf    : BFW_NETX_XM_STAT_SHAR2_rx_ovf;    // receive overflow (too much data in URX_FIFO)
	unsigned int tx_nxt    : BFW_NETX_XM_STAT_SHAR2_tx_nxt;    // put next tx_word to UTX_FIFO: at least one entry of UTX_FIFO is empty
	unsigned int tx_ufl    : BFW_NETX_XM_STAT_SHAR2_tx_ufl;    // transmit underflow (not enough data in UTX_FIFO)
	unsigned int utx_empty : BFW_NETX_XM_STAT_SHAR2_utx_empty; // UTX_FIFO is empty
	unsigned int brec      : BFW_NETX_XM_STAT_SHAR2_brec;      // bit_received (active for 1 cc)
	unsigned int btran     : BFW_NETX_XM_STAT_SHAR2_btran;     // bit_transmitted (active for 1 cc)
	unsigned int stat_rpu  : BFW_NETX_XM_STAT_SHAR2_stat_rpu;  // set and reset by RPU command bits
	unsigned int stat_tpu  : BFW_NETX_XM_STAT_SHAR2_stat_tpu;  // set and reset by TPU command bits
	unsigned int reserved1 : BFW_NETX_XM_STAT_SHAR2_reserved1; // reserved
	unsigned int phy_led0  : BFW_NETX_XM_STAT_SHAR2_phy_led0;  // not connected (zero)
	unsigned int phy_led1  : BFW_NETX_XM_STAT_SHAR2_phy_led1;  // not connected (zero)
	unsigned int phy_led2  : BFW_NETX_XM_STAT_SHAR2_phy_led2;  // not connected (zero)
	unsigned int phy_led3  : BFW_NETX_XM_STAT_SHAR2_phy_led3;  // not connected (zero)
	unsigned int reserved2 : BFW_NETX_XM_STAT_SHAR2_reserved2; // reserved
} XMAC_STATUS_SHARED2_BIT_T;

typedef union {
	unsigned int              val;
	XMAC_STATUS_SHARED2_BIT_T bf;
} XMAC_STATUS_SHARED2_T;

// ---------------------------------------------------------------------
// Register xmac_config_shared2
// => xMAC2 Shared Config Register
//    This register has a write pipeline delay of 1 clock cycle
// => Mode: Mode (r/w)
// ---------------------------------------------------------------------

#define REL_NETX_XM_CFG_SHAR2   0x00000854U
#define NETX_XM0_CFG_SHAR2 0x00160854U
#define NETX_XM1_CFG_SHAR2 0x00161854U
#define NETX_XM2_CFG_SHAR2 0x00162854U
#define NETX_XM3_CFG_SHAR2 0x00163854U

#define MSK_NETX_XM_CFG_SHAR2_rx_nof_bits   0x0000000fU // [3:0]
#define SRT_NETX_XM_CFG_SHAR2_rx_nof_bits   0           
#define MSK_NETX_XM_CFG_SHAR2_tx_nof_bits   0x000000f0U // [7:4]
#define SRT_NETX_XM_CFG_SHAR2_tx_nof_bits   4           
#define MSK_NETX_XM_CFG_SHAR2_rx_shift_lr   0x00000100U // [8]
#define SRT_NETX_XM_CFG_SHAR2_rx_shift_lr   8           
#define MSK_NETX_XM_CFG_SHAR2_tx_shift_lr   0x00000200U // [9]
#define SRT_NETX_XM_CFG_SHAR2_tx_shift_lr   9           
#define MSK_NETX_XM_CFG_SHAR2_reset_rx_fifo 0x00000400U // [10]
#define SRT_NETX_XM_CFG_SHAR2_reset_rx_fifo 10          
#define MSK_NETX_XM_CFG_SHAR2_reset_tx_fifo 0x00000800U // [11]
#define SRT_NETX_XM_CFG_SHAR2_reset_tx_fifo 11          
#define MSK_NETX_XM_CFG_SHAR2_gpio0_out     0x00001000U // [12]
#define SRT_NETX_XM_CFG_SHAR2_gpio0_out     12          
#define MSK_NETX_XM_CFG_SHAR2_gpio0_oe      0x00002000U // [13]
#define SRT_NETX_XM_CFG_SHAR2_gpio0_oe      13          
#define MSK_NETX_XM_CFG_SHAR2_gpio1_out     0x00004000U // [14]
#define SRT_NETX_XM_CFG_SHAR2_gpio1_out     14          
#define MSK_NETX_XM_CFG_SHAR2_gpio1_oe      0x00008000U // [15]
#define SRT_NETX_XM_CFG_SHAR2_gpio1_oe      15          

enum {
	BFW_NETX_XM_CFG_SHAR2_rx_nof_bits   = 4,  // [3:0]
	BFW_NETX_XM_CFG_SHAR2_tx_nof_bits   = 4,  // [7:4]
	BFW_NETX_XM_CFG_SHAR2_rx_shift_lr   = 1,  // [8]
	BFW_NETX_XM_CFG_SHAR2_tx_shift_lr   = 1,  // [9]
	BFW_NETX_XM_CFG_SHAR2_reset_rx_fifo = 1,  // [10]
	BFW_NETX_XM_CFG_SHAR2_reset_tx_fifo = 1,  // [11]
	BFW_NETX_XM_CFG_SHAR2_gpio0_out     = 1,  // [12]
	BFW_NETX_XM_CFG_SHAR2_gpio0_oe      = 1,  // [13]
	BFW_NETX_XM_CFG_SHAR2_gpio1_out     = 1,  // [14]
	BFW_NETX_XM_CFG_SHAR2_gpio1_oe      = 1,  // [15]
	BFW_NETX_XM_CFG_SHAR2_reserved1     = 16  // [31:16]
};

typedef struct XMAC_CONFIG_SHARED2_BIT_Ttag {
	unsigned int rx_nof_bits   : BFW_NETX_XM_CFG_SHAR2_rx_nof_bits;   // Number of bits written by SBU to rx-register, only used for rx_hw_count 
	unsigned int tx_nof_bits   : BFW_NETX_XM_CFG_SHAR2_tx_nof_bits;   // Number of bits read by OBU from tx-register 
	unsigned int rx_shift_lr   : BFW_NETX_XM_CFG_SHAR2_rx_shift_lr;   // 1: SBU reads incoming bits to position 0 of register rx and shifts rx left, 
	                                                        // 0: SBU reads incoming bits to position 15 of register rx and shifts rx right
	unsigned int tx_shift_lr   : BFW_NETX_XM_CFG_SHAR2_tx_shift_lr;   // 1: OBU reads outgoing bits from position 15 of register tx and shifts tx left, 
	                                                        // 0: OBU reads outgoing bits from position 0 of register tx and shifts tx right
	unsigned int reset_rx_fifo : BFW_NETX_XM_CFG_SHAR2_reset_rx_fifo; // reset URX_FIFO and rx_ovf bit inside status_shared register 
	unsigned int reset_tx_fifo : BFW_NETX_XM_CFG_SHAR2_reset_tx_fifo; // reset UTX_FIFO and tx_ufl bit inside status_shared register 
	unsigned int gpio0_out     : BFW_NETX_XM_CFG_SHAR2_gpio0_out;     // General Purpose IO 0 output 
	unsigned int gpio0_oe      : BFW_NETX_XM_CFG_SHAR2_gpio0_oe;      // General Purpose IO 0 output enable 
	unsigned int gpio1_out     : BFW_NETX_XM_CFG_SHAR2_gpio1_out;     // General Purpose IO 1 output 
	unsigned int gpio1_oe      : BFW_NETX_XM_CFG_SHAR2_gpio1_oe;      // General Purpose IO 1 output enable 
	unsigned int reserved1     : BFW_NETX_XM_CFG_SHAR2_reserved1;     // reserved
} XMAC_CONFIG_SHARED2_BIT_T;

typedef union {
	unsigned int              val;
	XMAC_CONFIG_SHARED2_BIT_T bf;
} XMAC_CONFIG_SHARED2_T;

// ---------------------------------------------------------------------
// Register xmac_status_shared3
// => xMAC3 Shared Status Register
// => Mode: Mode (r)
// ---------------------------------------------------------------------

#define REL_NETX_XM_STAT_SHAR3   0x00000858U
#define NETX_XM0_STAT_SHAR3 0x00160858U
#define NETX_XM1_STAT_SHAR3 0x00161858U
#define NETX_XM2_STAT_SHAR3 0x00162858U
#define NETX_XM3_STAT_SHAR3 0x00163858U

#define MSK_NETX_XM_STAT_SHAR3_gpio0_in  0x00000001U // [0]
#define SRT_NETX_XM_STAT_SHAR3_gpio0_in  0           
#define MSK_NETX_XM_STAT_SHAR3_gpio1_in  0x00000002U // [1]
#define SRT_NETX_XM_STAT_SHAR3_gpio1_in  1           
#define MSK_NETX_XM_STAT_SHAR3_rx_rdy    0x00000004U // [2]
#define SRT_NETX_XM_STAT_SHAR3_rx_rdy    2           
#define MSK_NETX_XM_STAT_SHAR3_rx_ovf    0x00000008U // [3]
#define SRT_NETX_XM_STAT_SHAR3_rx_ovf    3           
#define MSK_NETX_XM_STAT_SHAR3_tx_nxt    0x00000010U // [4]
#define SRT_NETX_XM_STAT_SHAR3_tx_nxt    4           
#define MSK_NETX_XM_STAT_SHAR3_tx_ufl    0x00000020U // [5]
#define SRT_NETX_XM_STAT_SHAR3_tx_ufl    5           
#define MSK_NETX_XM_STAT_SHAR3_utx_empty 0x00000040U // [6]
#define SRT_NETX_XM_STAT_SHAR3_utx_empty 6           
#define MSK_NETX_XM_STAT_SHAR3_brec      0x00000080U // [7]
#define SRT_NETX_XM_STAT_SHAR3_brec      7           
#define MSK_NETX_XM_STAT_SHAR3_btran     0x00000100U // [8]
#define SRT_NETX_XM_STAT_SHAR3_btran     8           
#define MSK_NETX_XM_STAT_SHAR3_stat_rpu  0x00000200U // [9]
#define SRT_NETX_XM_STAT_SHAR3_stat_rpu  9           
#define MSK_NETX_XM_STAT_SHAR3_stat_tpu  0x00000400U // [10]
#define SRT_NETX_XM_STAT_SHAR3_stat_tpu  10          
#define MSK_NETX_XM_STAT_SHAR3_phy_led0  0x00001000U // [12]
#define SRT_NETX_XM_STAT_SHAR3_phy_led0  12          
#define MSK_NETX_XM_STAT_SHAR3_phy_led1  0x00002000U // [13]
#define SRT_NETX_XM_STAT_SHAR3_phy_led1  13          
#define MSK_NETX_XM_STAT_SHAR3_phy_led2  0x00004000U // [14]
#define SRT_NETX_XM_STAT_SHAR3_phy_led2  14          
#define MSK_NETX_XM_STAT_SHAR3_phy_led3  0x00008000U // [15]
#define SRT_NETX_XM_STAT_SHAR3_phy_led3  15          

enum {
	BFW_NETX_XM_STAT_SHAR3_gpio0_in  = 1,  // [0]
	BFW_NETX_XM_STAT_SHAR3_gpio1_in  = 1,  // [1]
	BFW_NETX_XM_STAT_SHAR3_rx_rdy    = 1,  // [2]
	BFW_NETX_XM_STAT_SHAR3_rx_ovf    = 1,  // [3]
	BFW_NETX_XM_STAT_SHAR3_tx_nxt    = 1,  // [4]
	BFW_NETX_XM_STAT_SHAR3_tx_ufl    = 1,  // [5]
	BFW_NETX_XM_STAT_SHAR3_utx_empty = 1,  // [6]
	BFW_NETX_XM_STAT_SHAR3_brec      = 1,  // [7]
	BFW_NETX_XM_STAT_SHAR3_btran     = 1,  // [8]
	BFW_NETX_XM_STAT_SHAR3_stat_rpu  = 1,  // [9]
	BFW_NETX_XM_STAT_SHAR3_stat_tpu  = 1,  // [10]
	BFW_NETX_XM_STAT_SHAR3_reserved1 = 1,  // [11]
	BFW_NETX_XM_STAT_SHAR3_phy_led0  = 1,  // [12]
	BFW_NETX_XM_STAT_SHAR3_phy_led1  = 1,  // [13]
	BFW_NETX_XM_STAT_SHAR3_phy_led2  = 1,  // [14]
	BFW_NETX_XM_STAT_SHAR3_phy_led3  = 1,  // [15]
	BFW_NETX_XM_STAT_SHAR3_reserved2 = 16  // [31:16]
};

typedef struct XMAC_STATUS_SHARED3_BIT_Ttag {
	unsigned int gpio0_in  : BFW_NETX_XM_STAT_SHAR3_gpio0_in;  // value at external gpio1 pin
	unsigned int gpio1_in  : BFW_NETX_XM_STAT_SHAR3_gpio1_in;  // value at external gpio2 pin
	unsigned int rx_rdy    : BFW_NETX_XM_STAT_SHAR3_rx_rdy;    // received bytes are valid at output of URX_FIFO
	unsigned int rx_ovf    : BFW_NETX_XM_STAT_SHAR3_rx_ovf;    // receive overflow (too much data in URX_FIFO)
	unsigned int tx_nxt    : BFW_NETX_XM_STAT_SHAR3_tx_nxt;    // put next tx_word to UTX_FIFO: at least one entry of UTX_FIFO is empty
	unsigned int tx_ufl    : BFW_NETX_XM_STAT_SHAR3_tx_ufl;    // transmit underflow (not enough data in UTX_FIFO)
	unsigned int utx_empty : BFW_NETX_XM_STAT_SHAR3_utx_empty; // UTX_FIFO is empty
	unsigned int brec      : BFW_NETX_XM_STAT_SHAR3_brec;      // bit_received (active for 1 cc)
	unsigned int btran     : BFW_NETX_XM_STAT_SHAR3_btran;     // bit_transmitted (active for 1 cc)
	unsigned int stat_rpu  : BFW_NETX_XM_STAT_SHAR3_stat_rpu;  // set and reset by RPU command bits
	unsigned int stat_tpu  : BFW_NETX_XM_STAT_SHAR3_stat_tpu;  // set and reset by TPU command bits
	unsigned int reserved1 : BFW_NETX_XM_STAT_SHAR3_reserved1; // reserved
	unsigned int phy_led0  : BFW_NETX_XM_STAT_SHAR3_phy_led0;  // not connected (zero)
	unsigned int phy_led1  : BFW_NETX_XM_STAT_SHAR3_phy_led1;  // not connected (zero)
	unsigned int phy_led2  : BFW_NETX_XM_STAT_SHAR3_phy_led2;  // not connected (zero)
	unsigned int phy_led3  : BFW_NETX_XM_STAT_SHAR3_phy_led3;  // not connected (zero)
	unsigned int reserved2 : BFW_NETX_XM_STAT_SHAR3_reserved2; // reserved
} XMAC_STATUS_SHARED3_BIT_T;

typedef union {
	unsigned int              val;
	XMAC_STATUS_SHARED3_BIT_T bf;
} XMAC_STATUS_SHARED3_T;

// ---------------------------------------------------------------------
// Register xmac_config_shared3
// => xMAC3 Shared Config Register
//    This register has a write pipeline delay of 1 clock cycle
// => Mode: Mode (r/w)
// ---------------------------------------------------------------------

#define REL_NETX_XM_CFG_SHAR3   0x0000085CU
#define NETX_XM0_CFG_SHAR3 0x0016085CU
#define NETX_XM1_CFG_SHAR3 0x0016185CU
#define NETX_XM2_CFG_SHAR3 0x0016285CU
#define NETX_XM3_CFG_SHAR3 0x0016385CU

#define MSK_NETX_XM_CFG_SHAR3_rx_nof_bits   0x0000000fU // [3:0]
#define SRT_NETX_XM_CFG_SHAR3_rx_nof_bits   0           
#define MSK_NETX_XM_CFG_SHAR3_tx_nof_bits   0x000000f0U // [7:4]
#define SRT_NETX_XM_CFG_SHAR3_tx_nof_bits   4           
#define MSK_NETX_XM_CFG_SHAR3_rx_shift_lr   0x00000100U // [8]
#define SRT_NETX_XM_CFG_SHAR3_rx_shift_lr   8           
#define MSK_NETX_XM_CFG_SHAR3_tx_shift_lr   0x00000200U // [9]
#define SRT_NETX_XM_CFG_SHAR3_tx_shift_lr   9           
#define MSK_NETX_XM_CFG_SHAR3_reset_rx_fifo 0x00000400U // [10]
#define SRT_NETX_XM_CFG_SHAR3_reset_rx_fifo 10          
#define MSK_NETX_XM_CFG_SHAR3_reset_tx_fifo 0x00000800U // [11]
#define SRT_NETX_XM_CFG_SHAR3_reset_tx_fifo 11          
#define MSK_NETX_XM_CFG_SHAR3_gpio0_out     0x00001000U // [12]
#define SRT_NETX_XM_CFG_SHAR3_gpio0_out     12          
#define MSK_NETX_XM_CFG_SHAR3_gpio0_oe      0x00002000U // [13]
#define SRT_NETX_XM_CFG_SHAR3_gpio0_oe      13          
#define MSK_NETX_XM_CFG_SHAR3_gpio1_out     0x00004000U // [14]
#define SRT_NETX_XM_CFG_SHAR3_gpio1_out     14          
#define MSK_NETX_XM_CFG_SHAR3_gpio1_oe      0x00008000U // [15]
#define SRT_NETX_XM_CFG_SHAR3_gpio1_oe      15          

enum {
	BFW_NETX_XM_CFG_SHAR3_rx_nof_bits   = 4,  // [3:0]
	BFW_NETX_XM_CFG_SHAR3_tx_nof_bits   = 4,  // [7:4]
	BFW_NETX_XM_CFG_SHAR3_rx_shift_lr   = 1,  // [8]
	BFW_NETX_XM_CFG_SHAR3_tx_shift_lr   = 1,  // [9]
	BFW_NETX_XM_CFG_SHAR3_reset_rx_fifo = 1,  // [10]
	BFW_NETX_XM_CFG_SHAR3_reset_tx_fifo = 1,  // [11]
	BFW_NETX_XM_CFG_SHAR3_gpio0_out     = 1,  // [12]
	BFW_NETX_XM_CFG_SHAR3_gpio0_oe      = 1,  // [13]
	BFW_NETX_XM_CFG_SHAR3_gpio1_out     = 1,  // [14]
	BFW_NETX_XM_CFG_SHAR3_gpio1_oe      = 1,  // [15]
	BFW_NETX_XM_CFG_SHAR3_reserved1     = 16  // [31:16]
};

typedef struct XMAC_CONFIG_SHARED3_BIT_Ttag {
	unsigned int rx_nof_bits   : BFW_NETX_XM_CFG_SHAR3_rx_nof_bits;   // Number of bits written by SBU to rx-register, only used for rx_hw_count 
	unsigned int tx_nof_bits   : BFW_NETX_XM_CFG_SHAR3_tx_nof_bits;   // Number of bits read by OBU from tx-register 
	unsigned int rx_shift_lr   : BFW_NETX_XM_CFG_SHAR3_rx_shift_lr;   // 1: SBU reads incoming bits to position 0 of register rx and shifts rx left, 
	                                                        // 0: SBU reads incoming bits to position 15 of register rx and shifts rx right
	unsigned int tx_shift_lr   : BFW_NETX_XM_CFG_SHAR3_tx_shift_lr;   // 1: OBU reads outgoing bits from position 15 of register tx and shifts tx left, 
	                                                        // 0: OBU reads outgoing bits from position 0 of register tx and shifts tx right
	unsigned int reset_rx_fifo : BFW_NETX_XM_CFG_SHAR3_reset_rx_fifo; // reset URX_FIFO and rx_ovf bit inside status_shared register 
	unsigned int reset_tx_fifo : BFW_NETX_XM_CFG_SHAR3_reset_tx_fifo; // reset UTX_FIFO and tx_ufl bit inside status_shared register 
	unsigned int gpio0_out     : BFW_NETX_XM_CFG_SHAR3_gpio0_out;     // General Purpose IO 0 output 
	unsigned int gpio0_oe      : BFW_NETX_XM_CFG_SHAR3_gpio0_oe;      // General Purpose IO 0 output enable 
	unsigned int gpio1_out     : BFW_NETX_XM_CFG_SHAR3_gpio1_out;     // General Purpose IO 1 output 
	unsigned int gpio1_oe      : BFW_NETX_XM_CFG_SHAR3_gpio1_oe;      // General Purpose IO 1 output enable 
	unsigned int reserved1     : BFW_NETX_XM_CFG_SHAR3_reserved1;     // reserved
} XMAC_CONFIG_SHARED3_BIT_T;

typedef union {
	unsigned int              val;
	XMAC_CONFIG_SHARED3_BIT_T bf;
} XMAC_CONFIG_SHARED3_T;

// ---------------------------------------------------------------------
// Register xmac_urx_utx0
// => xMAC0 URX/UTX Shared Register FIFO
//    This register has a write pipeline delay of 1 clock cycle
//    Resetvalue : 0x00000000
// => Mode: Mode (r/w)
// ---------------------------------------------------------------------

#define REL_NETX_XM_URX_UTX0   0x00000860U
#define NETX_XM0_URX_UTX0 0x00160860U
#define NETX_XM1_URX_UTX0 0x00161860U
#define NETX_XM2_URX_UTX0 0x00162860U
#define NETX_XM3_URX_UTX0 0x00163860U

#define MSK_NETX_XM_URX_UTX0_UTX_XMAC0  0x000000ffU // [7:0]
#define SRT_NETX_XM_URX_UTX0_UTX_XMAC0  0           
#define MSK_NETX_XM_URX_UTX0_upper_bits 0x0000ff00U // [15:8]
#define SRT_NETX_XM_URX_UTX0_upper_bits 8           

enum {
	BFW_NETX_XM_URX_UTX0_UTX_XMAC0  = 8,  // [7:0]
	BFW_NETX_XM_URX_UTX0_upper_bits = 8,  // [15:8]
	BFW_NETX_XM_URX_UTX0_reserved1  = 16  // [31:16]
};

typedef struct XMAC_URX_UTX0_BIT_Ttag {
	unsigned int UTX_XMAC0  : BFW_NETX_XM_URX_UTX0_UTX_XMAC0;  // read access:  Lastly received bits (output of URX_FIFO) 
	                                                        // write access: Bits to be transmitted next (input of UTX_FIFO)
	unsigned int upper_bits : BFW_NETX_XM_URX_UTX0_upper_bits; // FIFO is 8 bits wide only, thus the upper bits are always ignored (zero in case of read)
	unsigned int reserved1  : BFW_NETX_XM_URX_UTX0_reserved1;  // reserved
} XMAC_URX_UTX0_BIT_T;

typedef union {
	unsigned int        val;
	XMAC_URX_UTX0_BIT_T bf;
} XMAC_URX_UTX0_T;

// ---------------------------------------------------------------------
// Register xmac_urx_utx1
// => xMAC1 URX/UTX Shared Register FIFO
//    This register has a write pipeline delay of 1 clock cycle
//    Resetvalue : 0x00000000
// => Mode: Mode (r/w)
// ---------------------------------------------------------------------

#define REL_NETX_XM_URX_UTX1   0x00000864U
#define NETX_XM0_URX_UTX1 0x00160864U
#define NETX_XM1_URX_UTX1 0x00161864U
#define NETX_XM2_URX_UTX1 0x00162864U
#define NETX_XM3_URX_UTX1 0x00163864U

#define MSK_NETX_XM_URX_UTX1_UTX_XMAC1  0x000000ffU // [7:0]
#define SRT_NETX_XM_URX_UTX1_UTX_XMAC1  0           
#define MSK_NETX_XM_URX_UTX1_upper_bits 0x0000ff00U // [15:8]
#define SRT_NETX_XM_URX_UTX1_upper_bits 8           

enum {
	BFW_NETX_XM_URX_UTX1_UTX_XMAC1  = 8,  // [7:0]
	BFW_NETX_XM_URX_UTX1_upper_bits = 8,  // [15:8]
	BFW_NETX_XM_URX_UTX1_reserved1  = 16  // [31:16]
};

typedef struct XMAC_URX_UTX1_BIT_Ttag {
	unsigned int UTX_XMAC1  : BFW_NETX_XM_URX_UTX1_UTX_XMAC1;  // read access:  Lastly received bits (output of URX_FIFO) 
	                                                        // write access: Bits to be transmitted next (input of UTX_FIFO)
	unsigned int upper_bits : BFW_NETX_XM_URX_UTX1_upper_bits; // FIFO is 8 bits wide only, thus the upper bits are always ignored (zero in case of read)
	unsigned int reserved1  : BFW_NETX_XM_URX_UTX1_reserved1;  // reserved
} XMAC_URX_UTX1_BIT_T;

typedef union {
	unsigned int        val;
	XMAC_URX_UTX1_BIT_T bf;
} XMAC_URX_UTX1_T;

// ---------------------------------------------------------------------
// Register xmac_urx_utx2
// => xMAC2 URX/UTX Shared Register FIFO
//    This register has a write pipeline delay of 1 clock cycle
//    Resetvalue : 0x00000000
// => Mode: Mode (r/w)
// ---------------------------------------------------------------------

#define REL_NETX_XM_URX_UTX2   0x00000868U
#define NETX_XM0_URX_UTX2 0x00160868U
#define NETX_XM1_URX_UTX2 0x00161868U
#define NETX_XM2_URX_UTX2 0x00162868U
#define NETX_XM3_URX_UTX2 0x00163868U

#define MSK_NETX_XM_URX_UTX2_UTX_XMAC2  0x000000ffU // [7:0]
#define SRT_NETX_XM_URX_UTX2_UTX_XMAC2  0           
#define MSK_NETX_XM_URX_UTX2_upper_bits 0x0000ff00U // [15:8]
#define SRT_NETX_XM_URX_UTX2_upper_bits 8           

enum {
	BFW_NETX_XM_URX_UTX2_UTX_XMAC2  = 8,  // [7:0]
	BFW_NETX_XM_URX_UTX2_upper_bits = 8,  // [15:8]
	BFW_NETX_XM_URX_UTX2_reserved1  = 16  // [31:16]
};

typedef struct XMAC_URX_UTX2_BIT_Ttag {
	unsigned int UTX_XMAC2  : BFW_NETX_XM_URX_UTX2_UTX_XMAC2;  // read access:  Lastly received bits (output of URX_FIFO) 
	                                                        // write access: Bits to be transmitted next (input of UTX_FIFO)
	unsigned int upper_bits : BFW_NETX_XM_URX_UTX2_upper_bits; // FIFO is 8 bits wide only, thus the upper bits are always ignored (zero in case of read)
	unsigned int reserved1  : BFW_NETX_XM_URX_UTX2_reserved1;  // reserved
} XMAC_URX_UTX2_BIT_T;

typedef union {
	unsigned int        val;
	XMAC_URX_UTX2_BIT_T bf;
} XMAC_URX_UTX2_T;

// ---------------------------------------------------------------------
// Register xmac_urx_utx3
// => xMAC3 URX/UTX Shared Register FIFO
//    This register has a write pipeline delay of 1 clock cycle
//    Resetvalue : 0x00000000
// => Mode: Mode (r/w)
// ---------------------------------------------------------------------

#define REL_NETX_XM_URX_UTX3   0x0000086CU
#define NETX_XM0_URX_UTX3 0x0016086CU
#define NETX_XM1_URX_UTX3 0x0016186CU
#define NETX_XM2_URX_UTX3 0x0016286CU
#define NETX_XM3_URX_UTX3 0x0016386CU

#define MSK_NETX_XM_URX_UTX3_UTX_XMAC3  0x000000ffU // [7:0]
#define SRT_NETX_XM_URX_UTX3_UTX_XMAC3  0           
#define MSK_NETX_XM_URX_UTX3_upper_bits 0x0000ff00U // [15:8]
#define SRT_NETX_XM_URX_UTX3_upper_bits 8           

enum {
	BFW_NETX_XM_URX_UTX3_UTX_XMAC3  = 8,  // [7:0]
	BFW_NETX_XM_URX_UTX3_upper_bits = 8,  // [15:8]
	BFW_NETX_XM_URX_UTX3_reserved1  = 16  // [31:16]
};

typedef struct XMAC_URX_UTX3_BIT_Ttag {
	unsigned int UTX_XMAC3  : BFW_NETX_XM_URX_UTX3_UTX_XMAC3;  // read access:  Lastly received bits (output of URX_FIFO) 
	                                                        // write access: Bits to be transmitted next (input of UTX_FIFO)
	unsigned int upper_bits : BFW_NETX_XM_URX_UTX3_upper_bits; // FIFO is 8 bits wide only, thus the upper bits are always ignored (zero in case of read)
	unsigned int reserved1  : BFW_NETX_XM_URX_UTX3_reserved1;  // reserved
} XMAC_URX_UTX3_BIT_T;

typedef union {
	unsigned int        val;
	XMAC_URX_UTX3_BIT_T bf;
} XMAC_URX_UTX3_T;

// ---------------------------------------------------------------------
// Register xmac_urx
// => xMAC URX FIFO input
//    URX FIFO is part of xMAC. It can be read (output) by all xMACs and xPECs, but only written (input) by the xMAC it belongs to.
//    This register has a write pipeline delay of 1 clock cycle
//    Resetvalue : 0x00000000
// => Mode: Mode (w)
// ---------------------------------------------------------------------

#define REL_NETX_XM_URX   0x00000870U
#define NETX_XM0_URX 0x00160870U
#define NETX_XM1_URX 0x00161870U
#define NETX_XM2_URX 0x00162870U
#define NETX_XM3_URX 0x00163870U

#define MSK_NETX_XM_URX_urx        0x000000ffU // [7:0]
#define SRT_NETX_XM_URX_urx        0           
#define MSK_NETX_XM_URX_upper_bits 0x0000ff00U // [15:8]
#define SRT_NETX_XM_URX_upper_bits 8           

enum {
	BFW_NETX_XM_URX_urx        = 8,  // [7:0]
	BFW_NETX_XM_URX_upper_bits = 8,  // [15:8]
	BFW_NETX_XM_URX_reserved1  = 16  // [31:16]
};

typedef struct XMAC_URX_BIT_Ttag {
	unsigned int urx        : BFW_NETX_XM_URX_urx;        // Lastly received bits to be transmitted to xPEC (input of URX_FIFO)
	unsigned int upper_bits : BFW_NETX_XM_URX_upper_bits; // FIFO is 8 bits wide only, thus the upper bits are always ignored
	unsigned int reserved1  : BFW_NETX_XM_URX_reserved1;  // reserved
} XMAC_URX_BIT_T;

typedef union {
	unsigned int   val;
	XMAC_URX_BIT_T bf;
} XMAC_URX_T;

// ---------------------------------------------------------------------
// Register xmac_utx
// => xMAC UTX FIFO output
//    UTX FIFO is part of xMAC. It can be written (input) by all xMACs and xPECs, but only read (output) by the xMAC it belongs to.
// => Mode: Mode (r)
// ---------------------------------------------------------------------

#define REL_NETX_XM_UTX   0x00000874U
#define NETX_XM0_UTX 0x00160874U
#define NETX_XM1_UTX 0x00161874U
#define NETX_XM2_UTX 0x00162874U
#define NETX_XM3_UTX 0x00163874U

#define MSK_NETX_XM_UTX_utx        0x000000ffU // [7:0]
#define SRT_NETX_XM_UTX_utx        0           
#define MSK_NETX_XM_UTX_upper_bits 0x0000ff00U // [15:8]
#define SRT_NETX_XM_UTX_upper_bits 8           

enum {
	BFW_NETX_XM_UTX_utx        = 8,  // [7:0]
	BFW_NETX_XM_UTX_upper_bits = 8,  // [15:8]
	BFW_NETX_XM_UTX_reserved1  = 16  // [31:16]
};

typedef struct XMAC_UTX_BIT_Ttag {
	unsigned int utx        : BFW_NETX_XM_UTX_utx;        // Bits to be transmitted next (output of UTX_FIFO) 
	                                                        // read as src2 allows multiple reads, only read as src1 will change FIFO state
	unsigned int upper_bits : BFW_NETX_XM_UTX_upper_bits; // FIFO is 8 bits wide only, thus the upper bits are always zero 
	unsigned int reserved1  : BFW_NETX_XM_UTX_reserved1;  // reserved
} XMAC_UTX_BIT_T;

typedef union {
	unsigned int   val;
	XMAC_UTX_BIT_T bf;
} XMAC_UTX_T;

// ---------------------------------------------------------------------
// Register xmac_rx
// => xMAC RX Register
//    Sampled bits from SBU are collected in this register,
//    i.e. if a new bit arrives from SBU (sync), other bits are shifted (direction programmable).
//    Same behavior in MII-Modes (4 bits arrive in parallel and the other bits are shifted by 4).
// => Mode: Mode (r)
// ---------------------------------------------------------------------

#define REL_NETX_XM_RX   0x00000878U
#define NETX_XM0_RX 0x00160878U
#define NETX_XM1_RX 0x00161878U
#define NETX_XM2_RX 0x00162878U
#define NETX_XM3_RX 0x00163878U

#define MSK_NETX_XM_RX_rx 0x0000ffffU // [15:0]
#define SRT_NETX_XM_RX_rx 0           

enum {
	BFW_NETX_XM_RX_rx        = 16, // [15:0]
	BFW_NETX_XM_RX_reserved1 = 16  // [31:16]
};

typedef struct XMAC_RX_BIT_Ttag {
	unsigned int rx        : BFW_NETX_XM_RX_rx;        // 16 previously received bits
	unsigned int reserved1 : BFW_NETX_XM_RX_reserved1; // reserved
} XMAC_RX_BIT_T;

typedef union {
	unsigned int  val;
	XMAC_RX_BIT_T bf;
} XMAC_RX_T;

// ---------------------------------------------------------------------
// Register xmac_rx_hw
// => xMAC RX_HW Register
//    rx_hw bit in RPU-code writes actually received bit from rx to this register.
//    Useful in case of bitwise format, to collect source bits from raw input bitstream (e.g. in HDLC-coding).
//    Resetvalue : 0x00000000
// => Mode: Mode (r/w)
// ---------------------------------------------------------------------

#define REL_NETX_XM_RX_HW   0x0000087CU
#define NETX_XM0_RX_HW 0x0016087CU
#define NETX_XM1_RX_HW 0x0016187CU
#define NETX_XM2_RX_HW 0x0016287CU
#define NETX_XM3_RX_HW 0x0016387CU

#define MSK_NETX_XM_RX_HW_rx_hw 0x0000ffffU // [15:0]
#define SRT_NETX_XM_RX_HW_rx_hw 0           

enum {
	BFW_NETX_XM_RX_HW_rx_hw     = 16, // [15:0]
	BFW_NETX_XM_RX_HW_reserved1 = 16  // [31:16]
};

typedef struct XMAC_RX_HW_BIT_Ttag {
	unsigned int rx_hw     : BFW_NETX_XM_RX_HW_rx_hw;     // collected source bits from raw input bitstream 
	                                                        // same orientation of bits as in rx register (depending on rx_shift_lr)
	unsigned int reserved1 : BFW_NETX_XM_RX_HW_reserved1; // reserved
} XMAC_RX_HW_BIT_T;

typedef union {
	unsigned int     val;
	XMAC_RX_HW_BIT_T bf;
} XMAC_RX_HW_T;

// ---------------------------------------------------------------------
// Register xmac_rx_hw_count
// => xMAC RX_HW_COUNT Register
//    Counts bits collected by rx_hw bit RPU-code.
//    Resetvalue : 0x00000000
// => Mode: Mode (r/w)
// ---------------------------------------------------------------------

#define REL_NETX_XM_RX_HW_CNT   0x00000880U
#define NETX_XM0_RX_HW_CNT 0x00160880U
#define NETX_XM1_RX_HW_CNT 0x00161880U
#define NETX_XM2_RX_HW_CNT 0x00162880U
#define NETX_XM3_RX_HW_CNT 0x00163880U

#define MSK_NETX_XM_RX_HW_CNT_rx_hw_count 0x0000ffffU // [15:0]
#define SRT_NETX_XM_RX_HW_CNT_rx_hw_count 0           

enum {
	BFW_NETX_XM_RX_HW_CNT_rx_hw_count = 16, // [15:0]
	BFW_NETX_XM_RX_HW_CNT_reserved1   = 16  // [31:16]
};

typedef struct XMAC_RX_HW_COUNT_BIT_Ttag {
	unsigned int rx_hw_count : BFW_NETX_XM_RX_HW_CNT_rx_hw_count; // counts down with rx_hw in RPU-code 
	                                                        // (from rx_nof_bits-1 to 0, 16-bit downcounter if rx_nof_bits = 0)
	unsigned int reserved1   : BFW_NETX_XM_RX_HW_CNT_reserved1;   // reserved
} XMAC_RX_HW_COUNT_BIT_T;

typedef union {
	unsigned int           val;
	XMAC_RX_HW_COUNT_BIT_T bf;
} XMAC_RX_HW_COUNT_T;

// ---------------------------------------------------------------------
// Register xmac_tx
// => xMAC TX Register
//    Transmitted bits read automatically by OBU from this register,
//    i.e. if a bit is send (sync), other bits are rotated accordingly (direction programmable).
//    Same behavior in MII-Modes (4 bits arrive in parallel and the other bits are rotated by 4).
//    Resetvalue : 0x00000000
// => Mode: Mode (r/w)
// ---------------------------------------------------------------------

#define REL_NETX_XM_TX   0x00000884U
#define NETX_XM0_TX 0x00160884U
#define NETX_XM1_TX 0x00161884U
#define NETX_XM2_TX 0x00162884U
#define NETX_XM3_TX 0x00163884U

#define MSK_NETX_XM_TX_tx0  0x00000001U // [0]
#define SRT_NETX_XM_TX_tx0  0           
#define MSK_NETX_XM_TX_tx   0x00007ffeU // [14:1]
#define SRT_NETX_XM_TX_tx   1           
#define MSK_NETX_XM_TX_tx15 0x00008000U // [15]
#define SRT_NETX_XM_TX_tx15 15          

enum {
	BFW_NETX_XM_TX_tx0       = 1,  // [0]
	BFW_NETX_XM_TX_tx        = 14, // [14:1]
	BFW_NETX_XM_TX_tx15      = 1,  // [15]
	BFW_NETX_XM_TX_reserved1 = 16  // [31:16]
};

typedef struct XMAC_TX_BIT_Ttag {
	unsigned int tx0       : BFW_NETX_XM_TX_tx0;       // bit to be transmitted next in case of tx_shift_lr = 0 
	unsigned int tx        : BFW_NETX_XM_TX_tx;        // to be transmitted bits                                
	unsigned int tx15      : BFW_NETX_XM_TX_tx15;      // bit to be transmitted next in case of tx_shift_lr = 1 
	unsigned int reserved1 : BFW_NETX_XM_TX_reserved1; // reserved
} XMAC_TX_BIT_T;

typedef union {
	unsigned int  val;
	XMAC_TX_BIT_T bf;
} XMAC_TX_T;

// ---------------------------------------------------------------------
// Register xmac_tx_hw
// => xMAC TX_HW Register
//    tx_hw bit in TPU-code writes to be transmitted bit in tx register from this register
//    Useful in case of bitwise format, to insert source bits into output bitstream.
//    Resetvalue : 0x00000000
// => Mode: Mode (r/w)
// ---------------------------------------------------------------------

#define REL_NETX_XM_TX_HW   0x00000888U
#define NETX_XM0_TX_HW 0x00160888U
#define NETX_XM1_TX_HW 0x00161888U
#define NETX_XM2_TX_HW 0x00162888U
#define NETX_XM3_TX_HW 0x00163888U

#define MSK_NETX_XM_TX_HW_tx_hw 0x0000ffffU // [15:0]
#define SRT_NETX_XM_TX_HW_tx_hw 0           

enum {
	BFW_NETX_XM_TX_HW_tx_hw     = 16, // [15:0]
	BFW_NETX_XM_TX_HW_reserved1 = 16  // [31:16]
};

typedef struct XMAC_TX_HW_BIT_Ttag {
	unsigned int tx_hw     : BFW_NETX_XM_TX_HW_tx_hw;     // bits to be inserted into output bitstream 
	                                                        // same orientation of bits as in tx register (depending on tx_shift_lr)
	unsigned int reserved1 : BFW_NETX_XM_TX_HW_reserved1; // reserved
} XMAC_TX_HW_BIT_T;

typedef union {
	unsigned int     val;
	XMAC_TX_HW_BIT_T bf;
} XMAC_TX_HW_T;

// ---------------------------------------------------------------------
// Register xmac_tx_hw_count
// => xMAC TX_HW_COUNT Register
//    Counts bits collected by tx_hw bit TPU-code.
//    Resetvalue : 0x00000000
// => Mode: Mode (r/w)
// ---------------------------------------------------------------------

#define REL_NETX_XM_TX_HW_CNT   0x0000088CU
#define NETX_XM0_TX_HW_CNT 0x0016088CU
#define NETX_XM1_TX_HW_CNT 0x0016188CU
#define NETX_XM2_TX_HW_CNT 0x0016288CU
#define NETX_XM3_TX_HW_CNT 0x0016388CU

#define MSK_NETX_XM_TX_HW_CNT_tx_hw_count 0x0000ffffU // [15:0]
#define SRT_NETX_XM_TX_HW_CNT_tx_hw_count 0           

enum {
	BFW_NETX_XM_TX_HW_CNT_tx_hw_count = 16, // [15:0]
	BFW_NETX_XM_TX_HW_CNT_reserved1   = 16  // [31:16]
};

typedef struct XMAC_TX_HW_COUNT_BIT_Ttag {
	unsigned int tx_hw_count : BFW_NETX_XM_TX_HW_CNT_tx_hw_count; // counts down with tx_hw in TPU-code 
	                                                        // (from tx_nof_bits-1 to 0, 16-bit downcounter if tx_nof_bits = 0)
	unsigned int reserved1   : BFW_NETX_XM_TX_HW_CNT_reserved1;   // reserved
} XMAC_TX_HW_COUNT_BIT_T;

typedef union {
	unsigned int           val;
	XMAC_TX_HW_COUNT_BIT_T bf;
} XMAC_TX_HW_COUNT_T;

// ---------------------------------------------------------------------
// Register xmac_tx_sent
// => xMAC TX Sent Register
//    Collects already transmitted bits.
//    Useful for pattern match.
//    Resetvalue : 0x00000000
// => Mode: Mode (r/w)
// ---------------------------------------------------------------------

#define REL_NETX_XM_TX_SENT   0x00000890U
#define NETX_XM0_TX_SENT 0x00160890U
#define NETX_XM1_TX_SENT 0x00161890U
#define NETX_XM2_TX_SENT 0x00162890U
#define NETX_XM3_TX_SENT 0x00163890U

#define MSK_NETX_XM_TX_SENT_tx_sent 0x0000ffffU // [15:0]
#define SRT_NETX_XM_TX_SENT_tx_sent 0           

enum {
	BFW_NETX_XM_TX_SENT_tx_sent   = 16, // [15:0]
	BFW_NETX_XM_TX_SENT_reserved1 = 16  // [31:16]
};

typedef struct XMAC_TX_SENT_BIT_Ttag {
	unsigned int tx_sent   : BFW_NETX_XM_TX_SENT_tx_sent;   // already transmitted bits, 
	                                                        // bit 15 is always the oldest bit (shift direction not programmable)
	unsigned int reserved1 : BFW_NETX_XM_TX_SENT_reserved1; // reserved
} XMAC_TX_SENT_BIT_T;

typedef union {
	unsigned int       val;
	XMAC_TX_SENT_BIT_T bf;
} XMAC_TX_SENT_T;

// ---------------------------------------------------------------------
// Register xmac_rpu_pc
// => RPU Progamm counter
//    Resetvalue : 00
// => Mode: Mode (r/w)
// ---------------------------------------------------------------------

#define REL_NETX_XM_RPU_PC   0x00000894U
#define NETX_XM0_RPU_PC 0x00160894U
#define NETX_XM1_RPU_PC 0x00161894U
#define NETX_XM2_RPU_PC 0x00162894U
#define NETX_XM3_RPU_PC 0x00163894U

#define MSK_NETX_XM_RPU_PC_rpu_pc 0x0000007fU // [6:0]
#define SRT_NETX_XM_RPU_PC_rpu_pc 0           

enum {
	BFW_NETX_XM_RPU_PC_rpu_pc    = 7,  // [6:0]
	BFW_NETX_XM_RPU_PC_reserved1 = 25  // [31:7]
};

typedef struct XMAC_RPU_PC_BIT_Ttag {
	unsigned int rpu_pc    : BFW_NETX_XM_RPU_PC_rpu_pc;    // Program Counter of RPU 
	unsigned int reserved1 : BFW_NETX_XM_RPU_PC_reserved1; // reserved
} XMAC_RPU_PC_BIT_T;

typedef union {
	unsigned int      val;
	XMAC_RPU_PC_BIT_T bf;
} XMAC_RPU_PC_T;

// ---------------------------------------------------------------------
// Register xmac_tpu_pc
// => TPU Progamm counter
//    Resetvalue : 00
// => Mode: Mode (r/w)
// ---------------------------------------------------------------------

#define REL_NETX_XM_TPU_PC   0x00000898U
#define NETX_XM0_TPU_PC 0x00160898U
#define NETX_XM1_TPU_PC 0x00161898U
#define NETX_XM2_TPU_PC 0x00162898U
#define NETX_XM3_TPU_PC 0x00163898U

#define MSK_NETX_XM_TPU_PC_tpu_pc 0x0000007fU // [6:0]
#define SRT_NETX_XM_TPU_PC_tpu_pc 0           

enum {
	BFW_NETX_XM_TPU_PC_tpu_pc    = 7,  // [6:0]
	BFW_NETX_XM_TPU_PC_reserved1 = 25  // [31:7]
};

typedef struct XMAC_TPU_PC_BIT_Ttag {
	unsigned int tpu_pc    : BFW_NETX_XM_TPU_PC_tpu_pc;    // Program Counter of TPU 
	unsigned int reserved1 : BFW_NETX_XM_TPU_PC_reserved1; // reserved
} XMAC_TPU_PC_BIT_T;

typedef union {
	unsigned int      val;
	XMAC_TPU_PC_BIT_T bf;
} XMAC_TPU_PC_T;

// ---------------------------------------------------------------------
// Register xmac_wr0
// => xMAC internal Work Register 0
//    Resetvalue : 0x00000000
// => Mode: Mode (r/w)
// ---------------------------------------------------------------------

#define REL_NETX_XM_WRK0   0x0000089CU
#define NETX_XM0_WRK0 0x0016089CU
#define NETX_XM1_WRK0 0x0016189CU
#define NETX_XM2_WRK0 0x0016289CU
#define NETX_XM3_WRK0 0x0016389CU

#define MSK_NETX_XM_WRK0_WR0 0x0000ffffU // [15:0]
#define SRT_NETX_XM_WRK0_WR0 0           

enum {
	BFW_NETX_XM_WRK0_WR0       = 16, // [15:0]
	BFW_NETX_XM_WRK0_reserved1 = 16  // [31:16]
};

typedef struct XMAC_WR0_BIT_Ttag {
	unsigned int WR0       : BFW_NETX_XM_WRK0_WR0;       // Work Register 
	unsigned int reserved1 : BFW_NETX_XM_WRK0_reserved1; // reserved
} XMAC_WR0_BIT_T;

typedef union {
	unsigned int   val;
	XMAC_WR0_BIT_T bf;
} XMAC_WR0_T;

// ---------------------------------------------------------------------
// Register xmac_wr1
// => xMAC internal Work Register 1
//    Resetvalue : 0x00000000
// => Mode: Mode (r/w)
// ---------------------------------------------------------------------

#define REL_NETX_XM_WRK1   0x000008A0U
#define NETX_XM0_WRK1 0x001608A0U
#define NETX_XM1_WRK1 0x001618A0U
#define NETX_XM2_WRK1 0x001628A0U
#define NETX_XM3_WRK1 0x001638A0U

#define MSK_NETX_XM_WRK1_WR1 0x0000ffffU // [15:0]
#define SRT_NETX_XM_WRK1_WR1 0           

enum {
	BFW_NETX_XM_WRK1_WR1       = 16, // [15:0]
	BFW_NETX_XM_WRK1_reserved1 = 16  // [31:16]
};

typedef struct XMAC_WR1_BIT_Ttag {
	unsigned int WR1       : BFW_NETX_XM_WRK1_WR1;       // Work Register 
	unsigned int reserved1 : BFW_NETX_XM_WRK1_reserved1; // reserved
} XMAC_WR1_BIT_T;

typedef union {
	unsigned int   val;
	XMAC_WR1_BIT_T bf;
} XMAC_WR1_T;

// ---------------------------------------------------------------------
// Register xmac_wr2
// => xMAC internal Work Register 2
//    Resetvalue : 0x00000000
// => Mode: Mode (r/w)
// ---------------------------------------------------------------------

#define REL_NETX_XM_WRK2   0x000008A4U
#define NETX_XM0_WRK2 0x001608A4U
#define NETX_XM1_WRK2 0x001618A4U
#define NETX_XM2_WRK2 0x001628A4U
#define NETX_XM3_WRK2 0x001638A4U

#define MSK_NETX_XM_WRK2_WR2 0x0000ffffU // [15:0]
#define SRT_NETX_XM_WRK2_WR2 0           

enum {
	BFW_NETX_XM_WRK2_WR2       = 16, // [15:0]
	BFW_NETX_XM_WRK2_reserved1 = 16  // [31:16]
};

typedef struct XMAC_WR2_BIT_Ttag {
	unsigned int WR2       : BFW_NETX_XM_WRK2_WR2;       // Work Register 
	unsigned int reserved1 : BFW_NETX_XM_WRK2_reserved1; // reserved
} XMAC_WR2_BIT_T;

typedef union {
	unsigned int   val;
	XMAC_WR2_BIT_T bf;
} XMAC_WR2_T;

// ---------------------------------------------------------------------
// Register xmac_wr3
// => xMAC internal Work Register 3
//    Resetvalue : 0x00000000
// => Mode: Mode (r/w)
// ---------------------------------------------------------------------

#define REL_NETX_XM_WRK3   0x000008A8U
#define NETX_XM0_WRK3 0x001608A8U
#define NETX_XM1_WRK3 0x001618A8U
#define NETX_XM2_WRK3 0x001628A8U
#define NETX_XM3_WRK3 0x001638A8U

#define MSK_NETX_XM_WRK3_WR3 0x0000ffffU // [15:0]
#define SRT_NETX_XM_WRK3_WR3 0           

enum {
	BFW_NETX_XM_WRK3_WR3       = 16, // [15:0]
	BFW_NETX_XM_WRK3_reserved1 = 16  // [31:16]
};

typedef struct XMAC_WR3_BIT_Ttag {
	unsigned int WR3       : BFW_NETX_XM_WRK3_WR3;       // Work Register 
	unsigned int reserved1 : BFW_NETX_XM_WRK3_reserved1; // reserved
} XMAC_WR3_BIT_T;

typedef union {
	unsigned int   val;
	XMAC_WR3_BIT_T bf;
} XMAC_WR3_T;

// ---------------------------------------------------------------------
// Register xmac_wr4
// => xMAC internal Work Register 4
//    Resetvalue : 0x00000000
// => Mode: Mode (r/w)
// ---------------------------------------------------------------------

#define REL_NETX_XM_WRK4   0x000008ACU
#define NETX_XM0_WRK4 0x001608ACU
#define NETX_XM1_WRK4 0x001618ACU
#define NETX_XM2_WRK4 0x001628ACU
#define NETX_XM3_WRK4 0x001638ACU

#define MSK_NETX_XM_WRK4_WR4 0x0000ffffU // [15:0]
#define SRT_NETX_XM_WRK4_WR4 0           

enum {
	BFW_NETX_XM_WRK4_WR4       = 16, // [15:0]
	BFW_NETX_XM_WRK4_reserved1 = 16  // [31:16]
};

typedef struct XMAC_WR4_BIT_Ttag {
	unsigned int WR4       : BFW_NETX_XM_WRK4_WR4;       // Work Register 
	unsigned int reserved1 : BFW_NETX_XM_WRK4_reserved1; // reserved
} XMAC_WR4_BIT_T;

typedef union {
	unsigned int   val;
	XMAC_WR4_BIT_T bf;
} XMAC_WR4_T;

// ---------------------------------------------------------------------
// Register xmac_wr5
// => xMAC internal Work Register 5
//    Resetvalue : 0x00000000
// => Mode: Mode (r/w)
// ---------------------------------------------------------------------

#define REL_NETX_XM_WRK5   0x000008B0U
#define NETX_XM0_WRK5 0x001608B0U
#define NETX_XM1_WRK5 0x001618B0U
#define NETX_XM2_WRK5 0x001628B0U
#define NETX_XM3_WRK5 0x001638B0U

#define MSK_NETX_XM_WRK5_WR5 0x0000ffffU // [15:0]
#define SRT_NETX_XM_WRK5_WR5 0           

enum {
	BFW_NETX_XM_WRK5_WR5       = 16, // [15:0]
	BFW_NETX_XM_WRK5_reserved1 = 16  // [31:16]
};

typedef struct XMAC_WR5_BIT_Ttag {
	unsigned int WR5       : BFW_NETX_XM_WRK5_WR5;       // Work Register 
	unsigned int reserved1 : BFW_NETX_XM_WRK5_reserved1; // reserved
} XMAC_WR5_BIT_T;

typedef union {
	unsigned int   val;
	XMAC_WR5_BIT_T bf;
} XMAC_WR5_T;

// ---------------------------------------------------------------------
// Register xmac_wr6
// => xMAC internal Work Register 6
//    Resetvalue : 0x00000000
// => Mode: Mode (r/w)
// ---------------------------------------------------------------------

#define REL_NETX_XM_WRK6   0x000008B4U
#define NETX_XM0_WRK6 0x001608B4U
#define NETX_XM1_WRK6 0x001618B4U
#define NETX_XM2_WRK6 0x001628B4U
#define NETX_XM3_WRK6 0x001638B4U

#define MSK_NETX_XM_WRK6_WR6 0x0000ffffU // [15:0]
#define SRT_NETX_XM_WRK6_WR6 0           

enum {
	BFW_NETX_XM_WRK6_WR6       = 16, // [15:0]
	BFW_NETX_XM_WRK6_reserved1 = 16  // [31:16]
};

typedef struct XMAC_WR6_BIT_Ttag {
	unsigned int WR6       : BFW_NETX_XM_WRK6_WR6;       // Work Register 
	unsigned int reserved1 : BFW_NETX_XM_WRK6_reserved1; // reserved
} XMAC_WR6_BIT_T;

typedef union {
	unsigned int   val;
	XMAC_WR6_BIT_T bf;
} XMAC_WR6_T;

// ---------------------------------------------------------------------
// Register xmac_wr7
// => xMAC internal Work Register 7
//    Resetvalue : 0x00000000
// => Mode: Mode (r/w)
// ---------------------------------------------------------------------

#define REL_NETX_XM_WRK7   0x000008B8U
#define NETX_XM0_WRK7 0x001608B8U
#define NETX_XM1_WRK7 0x001618B8U
#define NETX_XM2_WRK7 0x001628B8U
#define NETX_XM3_WRK7 0x001638B8U

#define MSK_NETX_XM_WRK7_WR7 0x0000ffffU // [15:0]
#define SRT_NETX_XM_WRK7_WR7 0           

enum {
	BFW_NETX_XM_WRK7_WR7       = 16, // [15:0]
	BFW_NETX_XM_WRK7_reserved1 = 16  // [31:16]
};

typedef struct XMAC_WR7_BIT_Ttag {
	unsigned int WR7       : BFW_NETX_XM_WRK7_WR7;       // Work Register 
	unsigned int reserved1 : BFW_NETX_XM_WRK7_reserved1; // reserved
} XMAC_WR7_BIT_T;

typedef union {
	unsigned int   val;
	XMAC_WR7_BIT_T bf;
} XMAC_WR7_T;

// ---------------------------------------------------------------------
// Register xmac_wr8
// => xMAC internal Work Register 7
//    Resetvalue : 0x00000000
// => Mode: Mode (r/w)
// ---------------------------------------------------------------------

#define REL_NETX_XM_WRK8   0x000008BCU
#define NETX_XM0_WRK8 0x001608BCU
#define NETX_XM1_WRK8 0x001618BCU
#define NETX_XM2_WRK8 0x001628BCU
#define NETX_XM3_WRK8 0x001638BCU

#define MSK_NETX_XM_WRK8_WR7 0x0000ffffU // [15:0]
#define SRT_NETX_XM_WRK8_WR7 0           

enum {
	BFW_NETX_XM_WRK8_WR7       = 16, // [15:0]
	BFW_NETX_XM_WRK8_reserved1 = 16  // [31:16]
};

typedef struct XMAC_WR8_BIT_Ttag {
	unsigned int WR7       : BFW_NETX_XM_WRK8_WR7;       // Work Register 
	unsigned int reserved1 : BFW_NETX_XM_WRK8_reserved1; // reserved
} XMAC_WR8_BIT_T;

typedef union {
	unsigned int   val;
	XMAC_WR8_BIT_T bf;
} XMAC_WR8_T;

// ---------------------------------------------------------------------
// Register xmac_wr9
// => xMAC internal Work Register 7
//    Resetvalue : 0x00000000
// => Mode: Mode (r/w)
// ---------------------------------------------------------------------

#define REL_NETX_XM_WRK9   0x000008C0U
#define NETX_XM0_WRK9 0x001608C0U
#define NETX_XM1_WRK9 0x001618C0U
#define NETX_XM2_WRK9 0x001628C0U
#define NETX_XM3_WRK9 0x001638C0U

#define MSK_NETX_XM_WRK9_WR7 0x0000ffffU // [15:0]
#define SRT_NETX_XM_WRK9_WR7 0           

enum {
	BFW_NETX_XM_WRK9_WR7       = 16, // [15:0]
	BFW_NETX_XM_WRK9_reserved1 = 16  // [31:16]
};

typedef struct XMAC_WR9_BIT_Ttag {
	unsigned int WR7       : BFW_NETX_XM_WRK9_WR7;       // Work Register 
	unsigned int reserved1 : BFW_NETX_XM_WRK9_reserved1; // reserved
} XMAC_WR9_BIT_T;

typedef union {
	unsigned int   val;
	XMAC_WR9_BIT_T bf;
} XMAC_WR9_T;

// ---------------------------------------------------------------------
// Register xmac_sys_time
// => xMAC System Time
// => Mode: Mode (r)
// ---------------------------------------------------------------------

#define REL_NETX_XM_SYS_TIME   0x000008C4U
#define NETX_XM0_SYS_TIME 0x001608C4U
#define NETX_XM1_SYS_TIME 0x001618C4U
#define NETX_XM2_SYS_TIME 0x001628C4U
#define NETX_XM3_SYS_TIME 0x001638C4U

#define MSK_NETX_XM_SYS_TIME_sys_time 0x0000ffffU // [15:0]
#define SRT_NETX_XM_SYS_TIME_sys_time 0           

enum {
	BFW_NETX_XM_SYS_TIME_sys_time  = 16, // [15:0]
	BFW_NETX_XM_SYS_TIME_reserved1 = 16  // [31:16]
};

typedef struct XMAC_SYS_TIME_BIT_Ttag {
	unsigned int sys_time  : BFW_NETX_XM_SYS_TIME_sys_time;  // 16 lower bits of 32 bit system time running on system clock 
	unsigned int reserved1 : BFW_NETX_XM_SYS_TIME_reserved1; // reserved
} XMAC_SYS_TIME_BIT_T;

typedef union {
	unsigned int        val;
	XMAC_SYS_TIME_BIT_T bf;
} XMAC_SYS_TIME_T;

// ---------------------------------------------------------------------
// Register xmac_cmp0_status
// => xMAC Compare0 Status Register
// => Mode: Mode (r)
// ---------------------------------------------------------------------

#define REL_NETX_XM_CMP0_STAT   0x000008C8U
#define NETX_XM0_CMP0_STAT 0x001608C8U
#define NETX_XM1_CMP0_STAT 0x001618C8U
#define NETX_XM2_CMP0_STAT 0x001628C8U
#define NETX_XM3_CMP0_STAT 0x001638C8U

#define MSK_NETX_XM_CMP0_STAT_sr0_z       0x00000001U // [0]
#define SRT_NETX_XM_CMP0_STAT_sr0_z       0           
#define MSK_NETX_XM_CMP0_STAT_sr1_z       0x00000002U // [1]
#define SRT_NETX_XM_CMP0_STAT_sr1_z       1           
#define MSK_NETX_XM_CMP0_STAT_sr2_z       0x00000004U // [2]
#define SRT_NETX_XM_CMP0_STAT_sr2_z       2           
#define MSK_NETX_XM_CMP0_STAT_sr3_z       0x00000008U // [3]
#define SRT_NETX_XM_CMP0_STAT_sr3_z       3           
#define MSK_NETX_XM_CMP0_STAT_sr4_z       0x00000010U // [4]
#define SRT_NETX_XM_CMP0_STAT_sr4_z       4           
#define MSK_NETX_XM_CMP0_STAT_sr5_z       0x00000020U // [5]
#define SRT_NETX_XM_CMP0_STAT_sr5_z       5           
#define MSK_NETX_XM_CMP0_STAT_sr6_z       0x00000040U // [6]
#define SRT_NETX_XM_CMP0_STAT_sr6_z       6           
#define MSK_NETX_XM_CMP0_STAT_sr7_z       0x00000080U // [7]
#define SRT_NETX_XM_CMP0_STAT_sr7_z       7           
#define MSK_NETX_XM_CMP0_STAT_cnt_rx_z    0x00000100U // [8]
#define SRT_NETX_XM_CMP0_STAT_cnt_rx_z    8           
#define MSK_NETX_XM_CMP0_STAT_cnt_tx_z    0x00000200U // [9]
#define SRT_NETX_XM_CMP0_STAT_cnt_tx_z    9           
#define MSK_NETX_XM_CMP0_STAT_cnt_rx_hw_z 0x00000400U // [10]
#define SRT_NETX_XM_CMP0_STAT_cnt_rx_hw_z 10          
#define MSK_NETX_XM_CMP0_STAT_cnt_tx_hw_z 0x00000800U // [11]
#define SRT_NETX_XM_CMP0_STAT_cnt_tx_hw_z 11          
#define MSK_NETX_XM_CMP0_STAT_cnt1_rpu_z  0x00001000U // [12]
#define SRT_NETX_XM_CMP0_STAT_cnt1_rpu_z  12          
#define MSK_NETX_XM_CMP0_STAT_cnt2_rpu_z  0x00002000U // [13]
#define SRT_NETX_XM_CMP0_STAT_cnt2_rpu_z  13          
#define MSK_NETX_XM_CMP0_STAT_cnt1_tpu_z  0x00004000U // [14]
#define SRT_NETX_XM_CMP0_STAT_cnt1_tpu_z  14          
#define MSK_NETX_XM_CMP0_STAT_cnt2_tpu_z  0x00008000U // [15]
#define SRT_NETX_XM_CMP0_STAT_cnt2_tpu_z  15          

enum {
	BFW_NETX_XM_CMP0_STAT_sr0_z       = 1,  // [0]
	BFW_NETX_XM_CMP0_STAT_sr1_z       = 1,  // [1]
	BFW_NETX_XM_CMP0_STAT_sr2_z       = 1,  // [2]
	BFW_NETX_XM_CMP0_STAT_sr3_z       = 1,  // [3]
	BFW_NETX_XM_CMP0_STAT_sr4_z       = 1,  // [4]
	BFW_NETX_XM_CMP0_STAT_sr5_z       = 1,  // [5]
	BFW_NETX_XM_CMP0_STAT_sr6_z       = 1,  // [6]
	BFW_NETX_XM_CMP0_STAT_sr7_z       = 1,  // [7]
	BFW_NETX_XM_CMP0_STAT_cnt_rx_z    = 1,  // [8]
	BFW_NETX_XM_CMP0_STAT_cnt_tx_z    = 1,  // [9]
	BFW_NETX_XM_CMP0_STAT_cnt_rx_hw_z = 1,  // [10]
	BFW_NETX_XM_CMP0_STAT_cnt_tx_hw_z = 1,  // [11]
	BFW_NETX_XM_CMP0_STAT_cnt1_rpu_z  = 1,  // [12]
	BFW_NETX_XM_CMP0_STAT_cnt2_rpu_z  = 1,  // [13]
	BFW_NETX_XM_CMP0_STAT_cnt1_tpu_z  = 1,  // [14]
	BFW_NETX_XM_CMP0_STAT_cnt2_tpu_z  = 1,  // [15]
	BFW_NETX_XM_CMP0_STAT_reserved1   = 16  // [31:16]
};

typedef struct XMAC_CMP0_STATUS_BIT_Ttag {
	unsigned int sr0_z       : BFW_NETX_XM_CMP0_STAT_sr0_z;       // sr0 = 0
	unsigned int sr1_z       : BFW_NETX_XM_CMP0_STAT_sr1_z;       // sr1 = 0
	unsigned int sr2_z       : BFW_NETX_XM_CMP0_STAT_sr2_z;       // sr2 = 0
	unsigned int sr3_z       : BFW_NETX_XM_CMP0_STAT_sr3_z;       // sr3 = 0
	unsigned int sr4_z       : BFW_NETX_XM_CMP0_STAT_sr4_z;       // sr4 = 0
	unsigned int sr5_z       : BFW_NETX_XM_CMP0_STAT_sr5_z;       // sr5 = 0
	unsigned int sr6_z       : BFW_NETX_XM_CMP0_STAT_sr6_z;       // sr6 = 0
	unsigned int sr7_z       : BFW_NETX_XM_CMP0_STAT_sr7_z;       // sr7 = 0
	unsigned int cnt_rx_z    : BFW_NETX_XM_CMP0_STAT_cnt_rx_z;    // count_rx = 0
	unsigned int cnt_tx_z    : BFW_NETX_XM_CMP0_STAT_cnt_tx_z;    // count_tx = 0
	unsigned int cnt_rx_hw_z : BFW_NETX_XM_CMP0_STAT_cnt_rx_hw_z; // rx_hw_count = 0
	unsigned int cnt_tx_hw_z : BFW_NETX_XM_CMP0_STAT_cnt_tx_hw_z; // tx_hw_count = 0
	unsigned int cnt1_rpu_z  : BFW_NETX_XM_CMP0_STAT_cnt1_rpu_z;  // rpu_count1 = 0
	unsigned int cnt2_rpu_z  : BFW_NETX_XM_CMP0_STAT_cnt2_rpu_z;  // rpu_count2 = 0
	unsigned int cnt1_tpu_z  : BFW_NETX_XM_CMP0_STAT_cnt1_tpu_z;  // tpu_count1 = 0
	unsigned int cnt2_tpu_z  : BFW_NETX_XM_CMP0_STAT_cnt2_tpu_z;  // tpu_count2 = 0
	unsigned int reserved1   : BFW_NETX_XM_CMP0_STAT_reserved1;   // reserved
} XMAC_CMP0_STATUS_BIT_T;

typedef union {
	unsigned int           val;
	XMAC_CMP0_STATUS_BIT_T bf;
} XMAC_CMP0_STATUS_T;

// ---------------------------------------------------------------------
// Register xmac_cmp1_status
// => xMAC Compare1 Status Register
// => Mode: Mode (r)
// ---------------------------------------------------------------------

#define REL_NETX_XM_CMP1_STAT   0x000008CCU
#define NETX_XM0_CMP1_STAT 0x001608CCU
#define NETX_XM1_CMP1_STAT 0x001618CCU
#define NETX_XM2_CMP1_STAT 0x001628CCU
#define NETX_XM3_CMP1_STAT 0x001638CCU

#define MSK_NETX_XM_CMP1_STAT_wr0_z    0x00000001U // [0]
#define SRT_NETX_XM_CMP1_STAT_wr0_z    0           
#define MSK_NETX_XM_CMP1_STAT_wr1_z    0x00000002U // [1]
#define SRT_NETX_XM_CMP1_STAT_wr1_z    1           
#define MSK_NETX_XM_CMP1_STAT_wr2_z    0x00000004U // [2]
#define SRT_NETX_XM_CMP1_STAT_wr2_z    2           
#define MSK_NETX_XM_CMP1_STAT_wr3_z    0x00000008U // [3]
#define SRT_NETX_XM_CMP1_STAT_wr3_z    3           
#define MSK_NETX_XM_CMP1_STAT_wr4_z    0x00000010U // [4]
#define SRT_NETX_XM_CMP1_STAT_wr4_z    4           
#define MSK_NETX_XM_CMP1_STAT_wr5_z    0x00000020U // [5]
#define SRT_NETX_XM_CMP1_STAT_wr5_z    5           
#define MSK_NETX_XM_CMP1_STAT_wr6_z    0x00000040U // [6]
#define SRT_NETX_XM_CMP1_STAT_wr6_z    6           
#define MSK_NETX_XM_CMP1_STAT_wr7_z    0x00000080U // [7]
#define SRT_NETX_XM_CMP1_STAT_wr7_z    7           
#define MSK_NETX_XM_CMP1_STAT_wr8_z    0x00000100U // [8]
#define SRT_NETX_XM_CMP1_STAT_wr8_z    8           
#define MSK_NETX_XM_CMP1_STAT_wr9_z    0x00000200U // [9]
#define SRT_NETX_XM_CMP1_STAT_wr9_z    9           
#define MSK_NETX_XM_CMP1_STAT_wr0_wr1  0x00000400U // [10]
#define SRT_NETX_XM_CMP1_STAT_wr0_wr1  10          
#define MSK_NETX_XM_CMP1_STAT_wr2_wr3  0x00000800U // [11]
#define SRT_NETX_XM_CMP1_STAT_wr2_wr3  11          
#define MSK_NETX_XM_CMP1_STAT_wr4_wr5  0x00001000U // [12]
#define SRT_NETX_XM_CMP1_STAT_wr4_wr5  12          
#define MSK_NETX_XM_CMP1_STAT_wr6_wr7  0x00002000U // [13]
#define SRT_NETX_XM_CMP1_STAT_wr6_wr7  13          
#define MSK_NETX_XM_CMP1_STAT_wr8_wr9  0x00004000U // [14]
#define SRT_NETX_XM_CMP1_STAT_wr8_wr9  14          
#define MSK_NETX_XM_CMP1_STAT_sys_time 0x00008000U // [15]
#define SRT_NETX_XM_CMP1_STAT_sys_time 15          

enum {
	BFW_NETX_XM_CMP1_STAT_wr0_z     = 1,  // [0]
	BFW_NETX_XM_CMP1_STAT_wr1_z     = 1,  // [1]
	BFW_NETX_XM_CMP1_STAT_wr2_z     = 1,  // [2]
	BFW_NETX_XM_CMP1_STAT_wr3_z     = 1,  // [3]
	BFW_NETX_XM_CMP1_STAT_wr4_z     = 1,  // [4]
	BFW_NETX_XM_CMP1_STAT_wr5_z     = 1,  // [5]
	BFW_NETX_XM_CMP1_STAT_wr6_z     = 1,  // [6]
	BFW_NETX_XM_CMP1_STAT_wr7_z     = 1,  // [7]
	BFW_NETX_XM_CMP1_STAT_wr8_z     = 1,  // [8]
	BFW_NETX_XM_CMP1_STAT_wr9_z     = 1,  // [9]
	BFW_NETX_XM_CMP1_STAT_wr0_wr1   = 1,  // [10]
	BFW_NETX_XM_CMP1_STAT_wr2_wr3   = 1,  // [11]
	BFW_NETX_XM_CMP1_STAT_wr4_wr5   = 1,  // [12]
	BFW_NETX_XM_CMP1_STAT_wr6_wr7   = 1,  // [13]
	BFW_NETX_XM_CMP1_STAT_wr8_wr9   = 1,  // [14]
	BFW_NETX_XM_CMP1_STAT_sys_time  = 1,  // [15]
	BFW_NETX_XM_CMP1_STAT_reserved1 = 16  // [31:16]
};

typedef struct XMAC_CMP1_STATUS_BIT_Ttag {
	unsigned int wr0_z     : BFW_NETX_XM_CMP1_STAT_wr0_z;     // 1: work register 0 equals 0
	unsigned int wr1_z     : BFW_NETX_XM_CMP1_STAT_wr1_z;     // 1: work register 1 equals 0
	unsigned int wr2_z     : BFW_NETX_XM_CMP1_STAT_wr2_z;     // 1: work register 2 equals 0
	unsigned int wr3_z     : BFW_NETX_XM_CMP1_STAT_wr3_z;     // 1: work register 3 equals 0
	unsigned int wr4_z     : BFW_NETX_XM_CMP1_STAT_wr4_z;     // 1: work register 4 equals 0
	unsigned int wr5_z     : BFW_NETX_XM_CMP1_STAT_wr5_z;     // 1: work register 5 equals 0
	unsigned int wr6_z     : BFW_NETX_XM_CMP1_STAT_wr6_z;     // 1: work register 6 equals 0
	unsigned int wr7_z     : BFW_NETX_XM_CMP1_STAT_wr7_z;     // 1: work register 7 equals 0
	unsigned int wr8_z     : BFW_NETX_XM_CMP1_STAT_wr8_z;     // 1: work register 8 equals 0
	unsigned int wr9_z     : BFW_NETX_XM_CMP1_STAT_wr9_z;     // 1: work register 9 equals 0
	unsigned int wr0_wr1   : BFW_NETX_XM_CMP1_STAT_wr0_wr1;   // 1: wr0 equals wr1
	unsigned int wr2_wr3   : BFW_NETX_XM_CMP1_STAT_wr2_wr3;   // 1: wr2 equals wr3
	unsigned int wr4_wr5   : BFW_NETX_XM_CMP1_STAT_wr4_wr5;   // 1: wr4 equals wr5
	unsigned int wr6_wr7   : BFW_NETX_XM_CMP1_STAT_wr6_wr7;   // 1: wr6 equals wr7
	unsigned int wr8_wr9   : BFW_NETX_XM_CMP1_STAT_wr8_wr9;   // 1: wr8 equals wr9
	unsigned int sys_time  : BFW_NETX_XM_CMP1_STAT_sys_time;  // compare of sys_time with wr2(value) and wr3(mask):
	                                                        // wr3 defines, which bits of sys_time and wr2 are to be compared
	                                                        // (1: compare this bit position, 0: ignore this bit position)
	unsigned int reserved1 : BFW_NETX_XM_CMP1_STAT_reserved1; // reserved
} XMAC_CMP1_STATUS_BIT_T;

typedef union {
	unsigned int           val;
	XMAC_CMP1_STATUS_BIT_T bf;
} XMAC_CMP1_STATUS_T;

// ---------------------------------------------------------------------
// Register xmac_cmp2_status
// => xMAC Compare2 Status Register
// => Mode: Mode (r)
// ---------------------------------------------------------------------

#define REL_NETX_XM_CMP2_STAT   0x000008D0U
#define NETX_XM0_CMP2_STAT 0x001608D0U
#define NETX_XM1_CMP2_STAT 0x001618D0U
#define NETX_XM2_CMP2_STAT 0x001628D0U
#define NETX_XM3_CMP2_STAT 0x001638D0U

#define MSK_NETX_XM_CMP2_STAT_wr0_sr0  0x00000001U // [0]
#define SRT_NETX_XM_CMP2_STAT_wr0_sr0  0           
#define MSK_NETX_XM_CMP2_STAT_wr1_sr1  0x00000002U // [1]
#define SRT_NETX_XM_CMP2_STAT_wr1_sr1  1           
#define MSK_NETX_XM_CMP2_STAT_wr2_sr2  0x00000004U // [2]
#define SRT_NETX_XM_CMP2_STAT_wr2_sr2  2           
#define MSK_NETX_XM_CMP2_STAT_wr3_sr3  0x00000008U // [3]
#define SRT_NETX_XM_CMP2_STAT_wr3_sr3  3           
#define MSK_NETX_XM_CMP2_STAT_wr4_sr4  0x00000010U // [4]
#define SRT_NETX_XM_CMP2_STAT_wr4_sr4  4           
#define MSK_NETX_XM_CMP2_STAT_wr5_sr5  0x00000020U // [5]
#define SRT_NETX_XM_CMP2_STAT_wr5_sr5  5           
#define MSK_NETX_XM_CMP2_STAT_wr6_sr6  0x00000040U // [6]
#define SRT_NETX_XM_CMP2_STAT_wr6_sr6  6           
#define MSK_NETX_XM_CMP2_STAT_wr7_sr7  0x00000080U // [7]
#define SRT_NETX_XM_CMP2_STAT_wr7_sr7  7           
#define MSK_NETX_XM_CMP2_STAT_wr8_sr8  0x00000100U // [8]
#define SRT_NETX_XM_CMP2_STAT_wr8_sr8  8           
#define MSK_NETX_XM_CMP2_STAT_wr9_sr9  0x00000200U // [9]
#define SRT_NETX_XM_CMP2_STAT_wr9_sr9  9           
#define MSK_NETX_XM_CMP2_STAT_wr5_sr10 0x00000400U // [10]
#define SRT_NETX_XM_CMP2_STAT_wr5_sr10 10          
#define MSK_NETX_XM_CMP2_STAT_wr6_sr11 0x00000800U // [11]
#define SRT_NETX_XM_CMP2_STAT_wr6_sr11 11          
#define MSK_NETX_XM_CMP2_STAT_wr5_sr12 0x00001000U // [12]
#define SRT_NETX_XM_CMP2_STAT_wr5_sr12 12          
#define MSK_NETX_XM_CMP2_STAT_wr6_sr13 0x00002000U // [13]
#define SRT_NETX_XM_CMP2_STAT_wr6_sr13 13          
#define MSK_NETX_XM_CMP2_STAT_wr5_sr14 0x00004000U // [14]
#define SRT_NETX_XM_CMP2_STAT_wr5_sr14 14          
#define MSK_NETX_XM_CMP2_STAT_wr6_sr15 0x00008000U // [15]
#define SRT_NETX_XM_CMP2_STAT_wr6_sr15 15          

enum {
	BFW_NETX_XM_CMP2_STAT_wr0_sr0   = 1,  // [0]
	BFW_NETX_XM_CMP2_STAT_wr1_sr1   = 1,  // [1]
	BFW_NETX_XM_CMP2_STAT_wr2_sr2   = 1,  // [2]
	BFW_NETX_XM_CMP2_STAT_wr3_sr3   = 1,  // [3]
	BFW_NETX_XM_CMP2_STAT_wr4_sr4   = 1,  // [4]
	BFW_NETX_XM_CMP2_STAT_wr5_sr5   = 1,  // [5]
	BFW_NETX_XM_CMP2_STAT_wr6_sr6   = 1,  // [6]
	BFW_NETX_XM_CMP2_STAT_wr7_sr7   = 1,  // [7]
	BFW_NETX_XM_CMP2_STAT_wr8_sr8   = 1,  // [8]
	BFW_NETX_XM_CMP2_STAT_wr9_sr9   = 1,  // [9]
	BFW_NETX_XM_CMP2_STAT_wr5_sr10  = 1,  // [10]
	BFW_NETX_XM_CMP2_STAT_wr6_sr11  = 1,  // [11]
	BFW_NETX_XM_CMP2_STAT_wr5_sr12  = 1,  // [12]
	BFW_NETX_XM_CMP2_STAT_wr6_sr13  = 1,  // [13]
	BFW_NETX_XM_CMP2_STAT_wr5_sr14  = 1,  // [14]
	BFW_NETX_XM_CMP2_STAT_wr6_sr15  = 1,  // [15]
	BFW_NETX_XM_CMP2_STAT_reserved1 = 16  // [31:16]
};

typedef struct XMAC_CMP2_STATUS_BIT_Ttag {
	unsigned int wr0_sr0   : BFW_NETX_XM_CMP2_STAT_wr0_sr0;   // 1: wr0 equals sr0
	unsigned int wr1_sr1   : BFW_NETX_XM_CMP2_STAT_wr1_sr1;   // 1: wr1 equals sr1
	unsigned int wr2_sr2   : BFW_NETX_XM_CMP2_STAT_wr2_sr2;   // 1: wr2 equals sr2
	unsigned int wr3_sr3   : BFW_NETX_XM_CMP2_STAT_wr3_sr3;   // 1: wr3 equals sr3
	unsigned int wr4_sr4   : BFW_NETX_XM_CMP2_STAT_wr4_sr4;   // 1: wr4 equals sr4
	unsigned int wr5_sr5   : BFW_NETX_XM_CMP2_STAT_wr5_sr5;   // 1: wr5 equals sr5
	unsigned int wr6_sr6   : BFW_NETX_XM_CMP2_STAT_wr6_sr6;   // 1: wr6 equals sr6
	unsigned int wr7_sr7   : BFW_NETX_XM_CMP2_STAT_wr7_sr7;   // 1: wr7 equals sr7
	unsigned int wr8_sr8   : BFW_NETX_XM_CMP2_STAT_wr8_sr8;   // 1: wr8 equals sr8
	unsigned int wr9_sr9   : BFW_NETX_XM_CMP2_STAT_wr9_sr9;   // 1: wr9 equals sr9
	unsigned int wr5_sr10  : BFW_NETX_XM_CMP2_STAT_wr5_sr10;  // 1: wr5 equals sr10
	unsigned int wr6_sr11  : BFW_NETX_XM_CMP2_STAT_wr6_sr11;  // 1: wr6 equals sr11
	unsigned int wr5_sr12  : BFW_NETX_XM_CMP2_STAT_wr5_sr12;  // 1: wr5 equals sr12
	unsigned int wr6_sr13  : BFW_NETX_XM_CMP2_STAT_wr6_sr13;  // 1: wr6 equals sr13
	unsigned int wr5_sr14  : BFW_NETX_XM_CMP2_STAT_wr5_sr14;  // 1: wr5 equals sr14
	unsigned int wr6_sr15  : BFW_NETX_XM_CMP2_STAT_wr6_sr15;  // 1: wr6 equals sr15
	unsigned int reserved1 : BFW_NETX_XM_CMP2_STAT_reserved1; // reserved
} XMAC_CMP2_STATUS_BIT_T;

typedef union {
	unsigned int           val;
	XMAC_CMP2_STATUS_BIT_T bf;
} XMAC_CMP2_STATUS_T;

// ---------------------------------------------------------------------
// Register xmac_cmp3_status
// => xMAC Compare3 Status Register
// => Mode: Mode (r)
// ---------------------------------------------------------------------

#define REL_NETX_XM_CMP3_STAT   0x000008D4U
#define NETX_XM0_CMP3_STAT 0x001608D4U
#define NETX_XM1_CMP3_STAT 0x001618D4U
#define NETX_XM2_CMP3_STAT 0x001628D4U
#define NETX_XM3_CMP3_STAT 0x001638D4U

#define MSK_NETX_XM_CMP3_STAT_rpucnt1_wr0 0x00000001U // [0]
#define SRT_NETX_XM_CMP3_STAT_rpucnt1_wr0 0           
#define MSK_NETX_XM_CMP3_STAT_rpucnt1_wr1 0x00000002U // [1]
#define SRT_NETX_XM_CMP3_STAT_rpucnt1_wr1 1           
#define MSK_NETX_XM_CMP3_STAT_rpucnt1_wr2 0x00000004U // [2]
#define SRT_NETX_XM_CMP3_STAT_rpucnt1_wr2 2           
#define MSK_NETX_XM_CMP3_STAT_rpucnt1_wr3 0x00000008U // [3]
#define SRT_NETX_XM_CMP3_STAT_rpucnt1_wr3 3           
#define MSK_NETX_XM_CMP3_STAT_rpucnt1_wr4 0x00000010U // [4]
#define SRT_NETX_XM_CMP3_STAT_rpucnt1_wr4 4           
#define MSK_NETX_XM_CMP3_STAT_rpucnt1_wr5 0x00000020U // [5]
#define SRT_NETX_XM_CMP3_STAT_rpucnt1_wr5 5           
#define MSK_NETX_XM_CMP3_STAT_rpucnt1_wr6 0x00000040U // [6]
#define SRT_NETX_XM_CMP3_STAT_rpucnt1_wr6 6           
#define MSK_NETX_XM_CMP3_STAT_rpucnt1_wr7 0x00000080U // [7]
#define SRT_NETX_XM_CMP3_STAT_rpucnt1_wr7 7           
#define MSK_NETX_XM_CMP3_STAT_tpucnt1_wr0 0x00000100U // [8]
#define SRT_NETX_XM_CMP3_STAT_tpucnt1_wr0 8           
#define MSK_NETX_XM_CMP3_STAT_tpucnt1_wr1 0x00000200U // [9]
#define SRT_NETX_XM_CMP3_STAT_tpucnt1_wr1 9           
#define MSK_NETX_XM_CMP3_STAT_tpucnt1_wr2 0x00000400U // [10]
#define SRT_NETX_XM_CMP3_STAT_tpucnt1_wr2 10          
#define MSK_NETX_XM_CMP3_STAT_tpucnt1_wr3 0x00000800U // [11]
#define SRT_NETX_XM_CMP3_STAT_tpucnt1_wr3 11          
#define MSK_NETX_XM_CMP3_STAT_tpucnt1_wr4 0x00001000U // [12]
#define SRT_NETX_XM_CMP3_STAT_tpucnt1_wr4 12          
#define MSK_NETX_XM_CMP3_STAT_tpucnt1_wr5 0x00002000U // [13]
#define SRT_NETX_XM_CMP3_STAT_tpucnt1_wr5 13          
#define MSK_NETX_XM_CMP3_STAT_tpucnt1_wr6 0x00004000U // [14]
#define SRT_NETX_XM_CMP3_STAT_tpucnt1_wr6 14          
#define MSK_NETX_XM_CMP3_STAT_tpucnt1_wr7 0x00008000U // [15]
#define SRT_NETX_XM_CMP3_STAT_tpucnt1_wr7 15          

enum {
	BFW_NETX_XM_CMP3_STAT_rpucnt1_wr0 = 1,  // [0]
	BFW_NETX_XM_CMP3_STAT_rpucnt1_wr1 = 1,  // [1]
	BFW_NETX_XM_CMP3_STAT_rpucnt1_wr2 = 1,  // [2]
	BFW_NETX_XM_CMP3_STAT_rpucnt1_wr3 = 1,  // [3]
	BFW_NETX_XM_CMP3_STAT_rpucnt1_wr4 = 1,  // [4]
	BFW_NETX_XM_CMP3_STAT_rpucnt1_wr5 = 1,  // [5]
	BFW_NETX_XM_CMP3_STAT_rpucnt1_wr6 = 1,  // [6]
	BFW_NETX_XM_CMP3_STAT_rpucnt1_wr7 = 1,  // [7]
	BFW_NETX_XM_CMP3_STAT_tpucnt1_wr0 = 1,  // [8]
	BFW_NETX_XM_CMP3_STAT_tpucnt1_wr1 = 1,  // [9]
	BFW_NETX_XM_CMP3_STAT_tpucnt1_wr2 = 1,  // [10]
	BFW_NETX_XM_CMP3_STAT_tpucnt1_wr3 = 1,  // [11]
	BFW_NETX_XM_CMP3_STAT_tpucnt1_wr4 = 1,  // [12]
	BFW_NETX_XM_CMP3_STAT_tpucnt1_wr5 = 1,  // [13]
	BFW_NETX_XM_CMP3_STAT_tpucnt1_wr6 = 1,  // [14]
	BFW_NETX_XM_CMP3_STAT_tpucnt1_wr7 = 1,  // [15]
	BFW_NETX_XM_CMP3_STAT_reserved1   = 16  // [31:16]
};

typedef struct XMAC_CMP3_STATUS_BIT_Ttag {
	unsigned int rpucnt1_wr0 : BFW_NETX_XM_CMP3_STAT_rpucnt1_wr0; // 1: rpu_count1 equals wr0
	unsigned int rpucnt1_wr1 : BFW_NETX_XM_CMP3_STAT_rpucnt1_wr1; // 1: rpu_count1 equals wr1
	unsigned int rpucnt1_wr2 : BFW_NETX_XM_CMP3_STAT_rpucnt1_wr2; // 1: rpu_count1 equals wr2
	unsigned int rpucnt1_wr3 : BFW_NETX_XM_CMP3_STAT_rpucnt1_wr3; // 1: rpu_count1 equals wr3
	unsigned int rpucnt1_wr4 : BFW_NETX_XM_CMP3_STAT_rpucnt1_wr4; // 1: rpu_count1 equals wr4
	unsigned int rpucnt1_wr5 : BFW_NETX_XM_CMP3_STAT_rpucnt1_wr5; // 1: rpu_count1 equals wr5
	unsigned int rpucnt1_wr6 : BFW_NETX_XM_CMP3_STAT_rpucnt1_wr6; // 1: rpu_count1 equals wr6
	unsigned int rpucnt1_wr7 : BFW_NETX_XM_CMP3_STAT_rpucnt1_wr7; // 1: rpu_count1 equals wr7
	unsigned int tpucnt1_wr0 : BFW_NETX_XM_CMP3_STAT_tpucnt1_wr0; // 1: tpu_count1 equals wr0
	unsigned int tpucnt1_wr1 : BFW_NETX_XM_CMP3_STAT_tpucnt1_wr1; // 1: tpu_count1 equals wr1
	unsigned int tpucnt1_wr2 : BFW_NETX_XM_CMP3_STAT_tpucnt1_wr2; // 1: tpu_count1 equals wr2
	unsigned int tpucnt1_wr3 : BFW_NETX_XM_CMP3_STAT_tpucnt1_wr3; // 1: tpu_count1 equals wr3
	unsigned int tpucnt1_wr4 : BFW_NETX_XM_CMP3_STAT_tpucnt1_wr4; // 1: tpu_count1 equals wr4
	unsigned int tpucnt1_wr5 : BFW_NETX_XM_CMP3_STAT_tpucnt1_wr5; // 1: tpu_count1 equals wr5
	unsigned int tpucnt1_wr6 : BFW_NETX_XM_CMP3_STAT_tpucnt1_wr6; // 1: tpu_count1 equals wr6
	unsigned int tpucnt1_wr7 : BFW_NETX_XM_CMP3_STAT_tpucnt1_wr7; // 1: tpu_count1 equals wr7
	unsigned int reserved1   : BFW_NETX_XM_CMP3_STAT_reserved1;   // reserved
} XMAC_CMP3_STATUS_BIT_T;

typedef union {
	unsigned int           val;
	XMAC_CMP3_STATUS_BIT_T bf;
} XMAC_CMP3_STATUS_T;

// ---------------------------------------------------------------------
// Register xmac_alu_flags
// => xMAC RPU and TPU ALU Flags
// => Mode: Mode (r)
// ---------------------------------------------------------------------

#define REL_NETX_XM_ALU_FLAG   0x000008D8U
#define NETX_XM0_ALU_FLAG 0x001608D8U
#define NETX_XM1_ALU_FLAG 0x001618D8U
#define NETX_XM2_ALU_FLAG 0x001628D8U
#define NETX_XM3_ALU_FLAG 0x001638D8U

#define MSK_NETX_XM_ALU_FLAG_rpu_carry 0x00000001U // [0]
#define SRT_NETX_XM_ALU_FLAG_rpu_carry 0           
#define MSK_NETX_XM_ALU_FLAG_rpu_zero  0x00000002U // [1]
#define SRT_NETX_XM_ALU_FLAG_rpu_zero  1           
#define MSK_NETX_XM_ALU_FLAG_rpu_neg   0x00000004U // [2]
#define SRT_NETX_XM_ALU_FLAG_rpu_neg   2           
#define MSK_NETX_XM_ALU_FLAG_rpu_ovf   0x00000008U // [3]
#define SRT_NETX_XM_ALU_FLAG_rpu_ovf   3           
#define MSK_NETX_XM_ALU_FLAG_tpu_carry 0x00000010U // [4]
#define SRT_NETX_XM_ALU_FLAG_tpu_carry 4           
#define MSK_NETX_XM_ALU_FLAG_tpu_zero  0x00000020U // [5]
#define SRT_NETX_XM_ALU_FLAG_tpu_zero  5           
#define MSK_NETX_XM_ALU_FLAG_tpu_neg   0x00000040U // [6]
#define SRT_NETX_XM_ALU_FLAG_tpu_neg   6           
#define MSK_NETX_XM_ALU_FLAG_tpu_ovf   0x00000080U // [7]
#define SRT_NETX_XM_ALU_FLAG_tpu_ovf   7           
#define MSK_NETX_XM_ALU_FLAG_rxcnt_wr2 0x00004000U // [14]
#define SRT_NETX_XM_ALU_FLAG_rxcnt_wr2 14          
#define MSK_NETX_XM_ALU_FLAG_txcnt_wr7 0x00008000U // [15]
#define SRT_NETX_XM_ALU_FLAG_txcnt_wr7 15          

enum {
	BFW_NETX_XM_ALU_FLAG_rpu_carry = 1,  // [0]
	BFW_NETX_XM_ALU_FLAG_rpu_zero  = 1,  // [1]
	BFW_NETX_XM_ALU_FLAG_rpu_neg   = 1,  // [2]
	BFW_NETX_XM_ALU_FLAG_rpu_ovf   = 1,  // [3]
	BFW_NETX_XM_ALU_FLAG_tpu_carry = 1,  // [4]
	BFW_NETX_XM_ALU_FLAG_tpu_zero  = 1,  // [5]
	BFW_NETX_XM_ALU_FLAG_tpu_neg   = 1,  // [6]
	BFW_NETX_XM_ALU_FLAG_tpu_ovf   = 1,  // [7]
	BFW_NETX_XM_ALU_FLAG_reserved1 = 6,  // [13:8]
	BFW_NETX_XM_ALU_FLAG_rxcnt_wr2 = 1,  // [14]
	BFW_NETX_XM_ALU_FLAG_txcnt_wr7 = 1,  // [15]
	BFW_NETX_XM_ALU_FLAG_reserved2 = 16  // [31:16]
};

typedef struct XMAC_ALU_FLAGS_BIT_Ttag {
	unsigned int rpu_carry : BFW_NETX_XM_ALU_FLAG_rpu_carry; // RPU carry flag
	unsigned int rpu_zero  : BFW_NETX_XM_ALU_FLAG_rpu_zero;  // RPU zero flag
	unsigned int rpu_neg   : BFW_NETX_XM_ALU_FLAG_rpu_neg;   // RPU neg flag
	unsigned int rpu_ovf   : BFW_NETX_XM_ALU_FLAG_rpu_ovf;   // RPU ovf flag
	unsigned int tpu_carry : BFW_NETX_XM_ALU_FLAG_tpu_carry; // TPU carry flag
	unsigned int tpu_zero  : BFW_NETX_XM_ALU_FLAG_tpu_zero;  // TPU zero flag
	unsigned int tpu_neg   : BFW_NETX_XM_ALU_FLAG_tpu_neg;   // TPU neg flag
	unsigned int tpu_ovf   : BFW_NETX_XM_ALU_FLAG_tpu_ovf;   // TPU ovf flag
	unsigned int reserved1 : BFW_NETX_XM_ALU_FLAG_reserved1; // reserved
	unsigned int rxcnt_wr2 : BFW_NETX_XM_ALU_FLAG_rxcnt_wr2; // 1: rx_count equals wr2
	unsigned int txcnt_wr7 : BFW_NETX_XM_ALU_FLAG_txcnt_wr7; // 1: tx_count equals wr7
	unsigned int reserved2 : BFW_NETX_XM_ALU_FLAG_reserved2; // reserved
} XMAC_ALU_FLAGS_BIT_T;

typedef union {
	unsigned int         val;
	XMAC_ALU_FLAGS_BIT_T bf;
} XMAC_ALU_FLAGS_T;

// ---------------------------------------------------------------------
// Register xmac_status_int
// => xMAC Status Internal Register
// => Mode: Mode (r)
// ---------------------------------------------------------------------

#define REL_NETX_XM_INTRN_STAT   0x000008DCU
#define NETX_XM0_INTRN_STAT 0x001608DCU
#define NETX_XM1_INTRN_STAT 0x001618DCU
#define NETX_XM2_INTRN_STAT 0x001628DCU
#define NETX_XM3_INTRN_STAT 0x001638DCU

#define MSK_NETX_XM_INTRN_STAT_rpm_hit0    0x00000001U // [0]
#define SRT_NETX_XM_INTRN_STAT_rpm_hit0    0           
#define MSK_NETX_XM_INTRN_STAT_rpm_hit1    0x00000002U // [1]
#define SRT_NETX_XM_INTRN_STAT_rpm_hit1    1           
#define MSK_NETX_XM_INTRN_STAT_rpm_hit0or1 0x00000004U // [2]
#define SRT_NETX_XM_INTRN_STAT_rpm_hit0or1 2           
#define MSK_NETX_XM_INTRN_STAT_tpm_hit0    0x00000008U // [3]
#define SRT_NETX_XM_INTRN_STAT_tpm_hit0    3           
#define MSK_NETX_XM_INTRN_STAT_tpm_hit1    0x00000010U // [4]
#define SRT_NETX_XM_INTRN_STAT_tpm_hit1    4           
#define MSK_NETX_XM_INTRN_STAT_tpm_hit0or1 0x00000020U // [5]
#define SRT_NETX_XM_INTRN_STAT_tpm_hit0or1 5           
#define MSK_NETX_XM_INTRN_STAT_lbit_eq_bit 0x00000040U // [6]
#define SRT_NETX_XM_INTRN_STAT_lbit_eq_bit 6           
#define MSK_NETX_XM_INTRN_STAT_tx_eq_wr45  0x00000080U // [7]
#define SRT_NETX_XM_INTRN_STAT_tx_eq_wr45  7           
#define MSK_NETX_XM_INTRN_STAT_rx_crc_ok   0x00000100U // [8]
#define SRT_NETX_XM_INTRN_STAT_rx_crc_ok   8           
#define MSK_NETX_XM_INTRN_STAT_tx_crc_ok   0x00000200U // [9]
#define SRT_NETX_XM_INTRN_STAT_tx_crc_ok   9           
#define MSK_NETX_XM_INTRN_STAT_recbit      0x00000800U // [11]
#define SRT_NETX_XM_INTRN_STAT_recbit      11          
#define MSK_NETX_XM_INTRN_STAT_brec        0x00001000U // [12]
#define SRT_NETX_XM_INTRN_STAT_brec        12          
#define MSK_NETX_XM_INTRN_STAT_btran       0x00002000U // [13]
#define SRT_NETX_XM_INTRN_STAT_btran       13          
#define MSK_NETX_XM_INTRN_STAT_arb_lost    0x00004000U // [14]
#define SRT_NETX_XM_INTRN_STAT_arb_lost    14          
#define MSK_NETX_XM_INTRN_STAT_zero        0x00008000U // [15]
#define SRT_NETX_XM_INTRN_STAT_zero        15          

enum {
	BFW_NETX_XM_INTRN_STAT_rpm_hit0    = 1,  // [0]
	BFW_NETX_XM_INTRN_STAT_rpm_hit1    = 1,  // [1]
	BFW_NETX_XM_INTRN_STAT_rpm_hit0or1 = 1,  // [2]
	BFW_NETX_XM_INTRN_STAT_tpm_hit0    = 1,  // [3]
	BFW_NETX_XM_INTRN_STAT_tpm_hit1    = 1,  // [4]
	BFW_NETX_XM_INTRN_STAT_tpm_hit0or1 = 1,  // [5]
	BFW_NETX_XM_INTRN_STAT_lbit_eq_bit = 1,  // [6]
	BFW_NETX_XM_INTRN_STAT_tx_eq_wr45  = 1,  // [7]
	BFW_NETX_XM_INTRN_STAT_rx_crc_ok   = 1,  // [8]
	BFW_NETX_XM_INTRN_STAT_tx_crc_ok   = 1,  // [9]
	BFW_NETX_XM_INTRN_STAT_reserved1   = 1,  // [10]
	BFW_NETX_XM_INTRN_STAT_recbit      = 1,  // [11]
	BFW_NETX_XM_INTRN_STAT_brec        = 1,  // [12]
	BFW_NETX_XM_INTRN_STAT_btran       = 1,  // [13]
	BFW_NETX_XM_INTRN_STAT_arb_lost    = 1,  // [14]
	BFW_NETX_XM_INTRN_STAT_zero        = 1,  // [15]
	BFW_NETX_XM_INTRN_STAT_reserved2   = 16  // [31:16]
};

typedef struct XMAC_STATUS_INT_BIT_Ttag {
	unsigned int rpm_hit0    : BFW_NETX_XM_INTRN_STAT_rpm_hit0;    // receive pattern 0 matches
	unsigned int rpm_hit1    : BFW_NETX_XM_INTRN_STAT_rpm_hit1;    // receive pattern 1 matches
	unsigned int rpm_hit0or1 : BFW_NETX_XM_INTRN_STAT_rpm_hit0or1; // receive pattern 0 or pattern 1 matches
	unsigned int tpm_hit0    : BFW_NETX_XM_INTRN_STAT_tpm_hit0;    // transmit pattern 0 matches
	unsigned int tpm_hit1    : BFW_NETX_XM_INTRN_STAT_tpm_hit1;    // transmit pattern 1 matches
	unsigned int tpm_hit0or1 : BFW_NETX_XM_INTRN_STAT_tpm_hit0or1; // transmit pattern 0 or pattern 1 matches
	unsigned int lbit_eq_bit : BFW_NETX_XM_INTRN_STAT_lbit_eq_bit; // last received bit = actually received bit
	unsigned int tx_eq_wr45  : BFW_NETX_XM_INTRN_STAT_tx_eq_wr45;  // compare of tx with wr4(value) and wr5(mask):
	                                                        // wr5 defines, which bits of tx and wr4 are to be compared
	                                                        // (1: compare this bit position, 0: ignore this bit position)
	unsigned int rx_crc_ok   : BFW_NETX_XM_INTRN_STAT_rx_crc_ok;   // compare of rx_crc_l/_h with wr0/1:
	unsigned int tx_crc_ok   : BFW_NETX_XM_INTRN_STAT_tx_crc_ok;   // compare of tx_crc_l/_h with wr8/9:
	unsigned int reserved1   : BFW_NETX_XM_INTRN_STAT_reserved1;   // reserved
	unsigned int recbit      : BFW_NETX_XM_INTRN_STAT_recbit;      // acutally received bit
	unsigned int brec        : BFW_NETX_XM_INTRN_STAT_brec;        // bit received (active for 1 cc)
	unsigned int btran       : BFW_NETX_XM_INTRN_STAT_btran;       // bit transmitted (active for 1 cc)
	unsigned int arb_lost    : BFW_NETX_XM_INTRN_STAT_arb_lost;    // Arbitration Lost: transmitted bit <> received bit
	unsigned int zero        : BFW_NETX_XM_INTRN_STAT_zero;        // always 0
	unsigned int reserved2   : BFW_NETX_XM_INTRN_STAT_reserved2;   // reserved
} XMAC_STATUS_INT_BIT_T;

typedef union {
	unsigned int          val;
	XMAC_STATUS_INT_BIT_T bf;
} XMAC_STATUS_INT_T;

// ---------------------------------------------------------------------
// Register xmac_stat_bits
// => xMAC stat_bits:
//    set and reset by hw_support bits (set_stat and reset_stat) and selected by src1_adr,
//    accessible by all RPUs and TPUs with higher set than reset priority
// => Mode: Mode (r)
// ---------------------------------------------------------------------

#define REL_NETX_XM_STAT_BIT   0x000008E0U
#define NETX_XM0_STAT_BIT 0x001608E0U
#define NETX_XM1_STAT_BIT 0x001618E0U
#define NETX_XM2_STAT_BIT 0x001628E0U
#define NETX_XM3_STAT_BIT 0x001638E0U

#define MSK_NETX_XM_STAT_BIT_stat_bits 0x0000ffffU // [15:0]
#define SRT_NETX_XM_STAT_BIT_stat_bits 0           

enum {
	BFW_NETX_XM_STAT_BIT_stat_bits = 16, // [15:0]
	BFW_NETX_XM_STAT_BIT_reserved1 = 16  // [31:16]
};

typedef struct XMAC_STAT_BITS_BIT_Ttag {
	unsigned int stat_bits : BFW_NETX_XM_STAT_BIT_stat_bits; // seperate bits selected by lower bits of src1_adr, if set_stat/reset_stat are active 
	unsigned int reserved1 : BFW_NETX_XM_STAT_BIT_reserved1; // reserved
} XMAC_STAT_BITS_BIT_T;

typedef union {
	unsigned int         val;
	XMAC_STAT_BITS_BIT_T bf;
} XMAC_STAT_BITS_T;

// ---------------------------------------------------------------------
// Register xmac_status_mii
// => xMAC MII receive status register
// => Mode: Mode (r)
// ---------------------------------------------------------------------

#define REL_NETX_XM_STAT_MII   0x000008E4U
#define NETX_XM0_STAT_MII 0x001608E4U
#define NETX_XM1_STAT_MII 0x001618E4U
#define NETX_XM2_STAT_MII 0x001628E4U
#define NETX_XM3_STAT_MII 0x001638E4U

#define MSK_NETX_XM_STAT_MII_rx_dv       0x00000001U // [0]
#define SRT_NETX_XM_STAT_MII_rx_dv       0           
#define MSK_NETX_XM_STAT_MII_rx_err      0x00000002U // [1]
#define SRT_NETX_XM_STAT_MII_rx_err      1           
#define MSK_NETX_XM_STAT_MII_crs         0x00000004U // [2]
#define SRT_NETX_XM_STAT_MII_crs         2           
#define MSK_NETX_XM_STAT_MII_col         0x00000008U // [3]
#define SRT_NETX_XM_STAT_MII_col         3           
#define MSK_NETX_XM_STAT_MII_s_nc        0x00000010U // [4]
#define SRT_NETX_XM_STAT_MII_s_nc        4           
#define MSK_NETX_XM_STAT_MII_v_ne_ns_nc  0x00000020U // [5]
#define SRT_NETX_XM_STAT_MII_v_ne_ns_nc  5           
#define MSK_NETX_XM_STAT_MII_v_ne_nc     0x00000040U // [6]
#define SRT_NETX_XM_STAT_MII_v_ne_nc     6           
#define MSK_NETX_XM_STAT_MII_v_ne_ns     0x00000080U // [7]
#define SRT_NETX_XM_STAT_MII_v_ne_ns     7           
#define MSK_NETX_XM_STAT_MII_v_ne        0x00000100U // [8]
#define SRT_NETX_XM_STAT_MII_v_ne        8           
#define MSK_NETX_XM_STAT_MII_v_ne_s_nc   0x00000200U // [9]
#define SRT_NETX_XM_STAT_MII_v_ne_s_nc   9           
#define MSK_NETX_XM_STAT_MII_v_ne_s      0x00000400U // [10]
#define SRT_NETX_XM_STAT_MII_v_ne_s      10          
#define MSK_NETX_XM_STAT_MII_v_ne_nc_p0  0x00000800U // [11]
#define SRT_NETX_XM_STAT_MII_v_ne_nc_p0  11          
#define MSK_NETX_XM_STAT_MII_v_ne_nc_p1  0x00001000U // [12]
#define SRT_NETX_XM_STAT_MII_v_ne_nc_p1  12          
#define MSK_NETX_XM_STAT_MII_v_ne_nc_p01 0x00002000U // [13]
#define SRT_NETX_XM_STAT_MII_v_ne_nc_p01 13          

enum {
	BFW_NETX_XM_STAT_MII_rx_dv       = 1,  // [0]
	BFW_NETX_XM_STAT_MII_rx_err      = 1,  // [1]
	BFW_NETX_XM_STAT_MII_crs         = 1,  // [2]
	BFW_NETX_XM_STAT_MII_col         = 1,  // [3]
	BFW_NETX_XM_STAT_MII_s_nc        = 1,  // [4]
	BFW_NETX_XM_STAT_MII_v_ne_ns_nc  = 1,  // [5]
	BFW_NETX_XM_STAT_MII_v_ne_nc     = 1,  // [6]
	BFW_NETX_XM_STAT_MII_v_ne_ns     = 1,  // [7]
	BFW_NETX_XM_STAT_MII_v_ne        = 1,  // [8]
	BFW_NETX_XM_STAT_MII_v_ne_s_nc   = 1,  // [9]
	BFW_NETX_XM_STAT_MII_v_ne_s      = 1,  // [10]
	BFW_NETX_XM_STAT_MII_v_ne_nc_p0  = 1,  // [11]
	BFW_NETX_XM_STAT_MII_v_ne_nc_p1  = 1,  // [12]
	BFW_NETX_XM_STAT_MII_v_ne_nc_p01 = 1,  // [13]
	BFW_NETX_XM_STAT_MII_reserved1   = 18  // [31:14]
};

typedef struct XMAC_STATUS_MII_BIT_Ttag {
	unsigned int rx_dv       : BFW_NETX_XM_STAT_MII_rx_dv;       // mii or rmii receive data valid
	unsigned int rx_err      : BFW_NETX_XM_STAT_MII_rx_err;      // mii rx_err
	unsigned int crs         : BFW_NETX_XM_STAT_MII_crs;         // mii crs
	unsigned int col         : BFW_NETX_XM_STAT_MII_col;         // mii col
	unsigned int s_nc        : BFW_NETX_XM_STAT_MII_s_nc;        // crs & !col
	unsigned int v_ne_ns_nc  : BFW_NETX_XM_STAT_MII_v_ne_ns_nc;  // rx_dv & !rx_err & !crs & !col
	unsigned int v_ne_nc     : BFW_NETX_XM_STAT_MII_v_ne_nc;     // rx_dv & !rx_err &        !col
	unsigned int v_ne_ns     : BFW_NETX_XM_STAT_MII_v_ne_ns;     // rx_dv & !rx_err & !crs
	unsigned int v_ne        : BFW_NETX_XM_STAT_MII_v_ne;        // rx_dv & !rx_err
	unsigned int v_ne_s_nc   : BFW_NETX_XM_STAT_MII_v_ne_s_nc;   // rx_dv & !rx_err &  crs & !col
	unsigned int v_ne_s      : BFW_NETX_XM_STAT_MII_v_ne_s;      // rx_dv & !rx_err &  crs
	unsigned int v_ne_nc_p0  : BFW_NETX_XM_STAT_MII_v_ne_nc_p0;  // rx_dv & !rx_err &        !col &  rpm_hit0
	unsigned int v_ne_nc_p1  : BFW_NETX_XM_STAT_MII_v_ne_nc_p1;  // rx_dv & !rx_err &        !col &              rpm_hit1
	unsigned int v_ne_nc_p01 : BFW_NETX_XM_STAT_MII_v_ne_nc_p01; // rx_dv & !rx_err &        !col & (rpm_hit0 |  rpm_hit1)
	unsigned int reserved1   : BFW_NETX_XM_STAT_MII_reserved1;   // reserved
} XMAC_STATUS_MII_BIT_T;

typedef union {
	unsigned int          val;
	XMAC_STATUS_MII_BIT_T bf;
} XMAC_STATUS_MII_T;

// ---------------------------------------------------------------------
// Register xmac_status_mii2
// => xMAC 2nd MII receive status register
// => Mode: Mode (r)
// ---------------------------------------------------------------------

#define REL_NETX_XM_STAT_MII2   0x000008E8U
#define NETX_XM0_STAT_MII2 0x001608E8U
#define NETX_XM1_STAT_MII2 0x001618E8U
#define NETX_XM2_STAT_MII2 0x001628E8U
#define NETX_XM3_STAT_MII2 0x001638E8U

#define MSK_NETX_XM_STAT_MII2_dv                   0x00000001U // [0]
#define SRT_NETX_XM_STAT_MII2_dv                   0           
#define MSK_NETX_XM_STAT_MII2_miif_error           0x00000002U // [1]
#define SRT_NETX_XM_STAT_MII2_miif_error           1           
#define MSK_NETX_XM_STAT_MII2_miif_ovfl            0x00000004U // [2]
#define SRT_NETX_XM_STAT_MII2_miif_ovfl            2           
#define MSK_NETX_XM_STAT_MII2_miif_unfl            0x00000008U // [3]
#define SRT_NETX_XM_STAT_MII2_miif_unfl            3           
#define MSK_NETX_XM_STAT_MII2_miif_error_short_dv  0x00000010U // [4]
#define SRT_NETX_XM_STAT_MII2_miif_error_short_dv  4           
#define MSK_NETX_XM_STAT_MII2_miif_error_short_ifg 0x00000020U // [5]
#define SRT_NETX_XM_STAT_MII2_miif_error_short_ifg 5           
#define MSK_NETX_XM_STAT_MII2_v_ne_nc              0x00000040U // [6]
#define SRT_NETX_XM_STAT_MII2_v_ne_nc              6           
#define MSK_NETX_XM_STAT_MII2_v_ne                 0x00000080U // [7]
#define SRT_NETX_XM_STAT_MII2_v_ne                 7           
#define MSK_NETX_XM_STAT_MII2_v_ne_nc_p0           0x00000100U // [8]
#define SRT_NETX_XM_STAT_MII2_v_ne_nc_p0           8           
#define MSK_NETX_XM_STAT_MII2_v_ne_nc_p1           0x00000200U // [9]
#define SRT_NETX_XM_STAT_MII2_v_ne_nc_p1           9           
#define MSK_NETX_XM_STAT_MII2_v_ne_nc_p01          0x00000400U // [10]
#define SRT_NETX_XM_STAT_MII2_v_ne_nc_p01          10          
#define MSK_NETX_XM_STAT_MII2_rx_err_was_here      0x00002000U // [13]
#define SRT_NETX_XM_STAT_MII2_rx_err_was_here      13          
#define MSK_NETX_XM_STAT_MII2_col_was_here         0x00004000U // [14]
#define SRT_NETX_XM_STAT_MII2_col_was_here         14          
#define MSK_NETX_XM_STAT_MII2_crs_was_here         0x00008000U // [15]
#define SRT_NETX_XM_STAT_MII2_crs_was_here         15          

enum {
	BFW_NETX_XM_STAT_MII2_dv                   = 1,  // [0]
	BFW_NETX_XM_STAT_MII2_miif_error           = 1,  // [1]
	BFW_NETX_XM_STAT_MII2_miif_ovfl            = 1,  // [2]
	BFW_NETX_XM_STAT_MII2_miif_unfl            = 1,  // [3]
	BFW_NETX_XM_STAT_MII2_miif_error_short_dv  = 1,  // [4]
	BFW_NETX_XM_STAT_MII2_miif_error_short_ifg = 1,  // [5]
	BFW_NETX_XM_STAT_MII2_v_ne_nc              = 1,  // [6]
	BFW_NETX_XM_STAT_MII2_v_ne                 = 1,  // [7]
	BFW_NETX_XM_STAT_MII2_v_ne_nc_p0           = 1,  // [8]
	BFW_NETX_XM_STAT_MII2_v_ne_nc_p1           = 1,  // [9]
	BFW_NETX_XM_STAT_MII2_v_ne_nc_p01          = 1,  // [10]
	BFW_NETX_XM_STAT_MII2_reserved1            = 2,  // [12:11]
	BFW_NETX_XM_STAT_MII2_rx_err_was_here      = 1,  // [13]
	BFW_NETX_XM_STAT_MII2_col_was_here         = 1,  // [14]
	BFW_NETX_XM_STAT_MII2_crs_was_here         = 1,  // [15]
	BFW_NETX_XM_STAT_MII2_reserved2            = 16  // [31:16]
};

typedef struct XMAC_STATUS_MII2_BIT_Ttag {
	unsigned int dv                   : BFW_NETX_XM_STAT_MII2_dv;                   // MII-nibble-fifo data valid
	unsigned int miif_error           : BFW_NETX_XM_STAT_MII2_miif_error;           // any error at the MII-nibble-fifo occured,
	                                                        // reset by setting xmac_config_nibble_fifo-fifo_depth=0
	unsigned int miif_ovfl            : BFW_NETX_XM_STAT_MII2_miif_ovfl;            // MII-nibble-fifo overflow,
	                                                        // reset by setting xmac_config_nibble_fifo-fifo_depth=0
	unsigned int miif_unfl            : BFW_NETX_XM_STAT_MII2_miif_unfl;            // MII-nibble-fifo underflow,
	                                                        // reset by setting xmac_config_nibble_fifo-fifo_depth=0
	unsigned int miif_error_short_dv  : BFW_NETX_XM_STAT_MII2_miif_error_short_dv;  // rx_dv was active for very short time,
	                                                        // reset by setting xmac_config_nibble_fifo-fifo_depth=0
	unsigned int miif_error_short_ifg : BFW_NETX_XM_STAT_MII2_miif_error_short_ifg; // rx_dv was inactive for very short time,
	                                                        // reset by setting xmac_config_nibble_fifo-fifo_depth=0
	unsigned int v_ne_nc              : BFW_NETX_XM_STAT_MII2_v_ne_nc;              // dv & !rx_err & !col
	unsigned int v_ne                 : BFW_NETX_XM_STAT_MII2_v_ne;                 // dv & !rx_err
	unsigned int v_ne_nc_p0           : BFW_NETX_XM_STAT_MII2_v_ne_nc_p0;           // dv & !rx_err & !col &  rpm_hit0
	unsigned int v_ne_nc_p1           : BFW_NETX_XM_STAT_MII2_v_ne_nc_p1;           // dv & !rx_err & !col &             rpm_hit1
	unsigned int v_ne_nc_p01          : BFW_NETX_XM_STAT_MII2_v_ne_nc_p01;          // dv & !rx_err & !col & (rpm_hit0 |  rpm_hit1)
	unsigned int reserved1            : BFW_NETX_XM_STAT_MII2_reserved1;            // reserved
	unsigned int rx_err_was_here      : BFW_NETX_XM_STAT_MII2_rx_err_was_here;      // rx_err was here:
	                                                        // reset with rx_err_reset of xmac_config_sbu
	                                                        // set with rx_err xor rx_err_low_active of xmac_config_sbu
	unsigned int col_was_here         : BFW_NETX_XM_STAT_MII2_col_was_here;         // col was here:
	                                                        // reset with col_reset of xmac_config_sbu
	                                                        // set with col xor col_low_active of xmac_config_sbu
	unsigned int crs_was_here         : BFW_NETX_XM_STAT_MII2_crs_was_here;         // crs was here:
	                                                        // reset with crs_reset of xmac_config_sbu
	                                                        // set with crs xor crs_low_active of xmac_config_sbu
	unsigned int reserved2            : BFW_NETX_XM_STAT_MII2_reserved2;            // reserved
} XMAC_STATUS_MII2_BIT_T;

typedef union {
	unsigned int           val;
	XMAC_STATUS_MII2_BIT_T bf;
} XMAC_STATUS_MII2_T;

// ---------------------------------------------------------------------
// Register xmac_config_mii
// => xMAC MII transmit config register
//    Resetvalue : 0x00000000
// => Mode: Mode (r/w)
// ---------------------------------------------------------------------

#define REL_NETX_XM_CFG_MII   0x000008ECU
#define NETX_XM0_CFG_MII 0x001608ECU
#define NETX_XM1_CFG_MII 0x001618ECU
#define NETX_XM2_CFG_MII 0x001628ECU
#define NETX_XM3_CFG_MII 0x001638ECU

#define MSK_NETX_XM_CFG_MII_tx_en  0x00000001U // [0]
#define SRT_NETX_XM_CFG_MII_tx_en  0           
#define MSK_NETX_XM_CFG_MII_tx_err 0x00000002U // [1]
#define SRT_NETX_XM_CFG_MII_tx_err 1           

enum {
	BFW_NETX_XM_CFG_MII_tx_en     = 1,  // [0]
	BFW_NETX_XM_CFG_MII_tx_err    = 1,  // [1]
	BFW_NETX_XM_CFG_MII_reserved1 = 30  // [31:2]
};

typedef struct XMAC_CONFIG_MII_BIT_Ttag {
	unsigned int tx_en     : BFW_NETX_XM_CFG_MII_tx_en;     // mii tx_en 
	                                                        // Synchronized to mii tx_clk
	unsigned int tx_err    : BFW_NETX_XM_CFG_MII_tx_err;    // mii tx_err 
	                                                        // Synchronized to mii tx_clk
	unsigned int reserved1 : BFW_NETX_XM_CFG_MII_reserved1; // reserved
} XMAC_CONFIG_MII_BIT_T;

typedef union {
	unsigned int          val;
	XMAC_CONFIG_MII_BIT_T bf;
} XMAC_CONFIG_MII_T;

// ---------------------------------------------------------------------
// Register xmac_config_nibble_fifo
// => xMAC mii nibble fifo config register
//    This register has a write pipeline delay of 1 clock cycle
//    Resetvalue : 0x00000000
// => Mode: Mode (r/w)
// ---------------------------------------------------------------------

#define REL_NETX_XM_CFG_NIBBLE_FIFO   0x000008F0U
#define NETX_XM0_CFG_NIBBLE_FIFO 0x001608F0U
#define NETX_XM1_CFG_NIBBLE_FIFO 0x001618F0U
#define NETX_XM2_CFG_NIBBLE_FIFO 0x001628F0U
#define NETX_XM3_CFG_NIBBLE_FIFO 0x001638F0U

#define MSK_NETX_XM_CFG_NIBBLE_FIFO_fifo_depth   0x0000000fU // [3:0]
#define SRT_NETX_XM_CFG_NIBBLE_FIFO_fifo_depth   0           
#define MSK_NETX_XM_CFG_NIBBLE_FIFO_read_phase   0x00000030U // [5:4]
#define SRT_NETX_XM_CFG_NIBBLE_FIFO_read_phase   4           
#define MSK_NETX_XM_CFG_NIBBLE_FIFO_sample_phase 0x000000c0U // [7:6]
#define SRT_NETX_XM_CFG_NIBBLE_FIFO_sample_phase 6           
#define MSK_NETX_XM_CFG_NIBBLE_FIFO_output_phase 0x00000300U // [9:8]
#define SRT_NETX_XM_CFG_NIBBLE_FIFO_output_phase 8           

enum {
	BFW_NETX_XM_CFG_NIBBLE_FIFO_fifo_depth   = 4,  // [3:0]
	BFW_NETX_XM_CFG_NIBBLE_FIFO_read_phase   = 2,  // [5:4]
	BFW_NETX_XM_CFG_NIBBLE_FIFO_sample_phase = 2,  // [7:6]
	BFW_NETX_XM_CFG_NIBBLE_FIFO_output_phase = 2,  // [9:8]
	BFW_NETX_XM_CFG_NIBBLE_FIFO_reserved1    = 22  // [31:10]
};

typedef struct XMAC_CONFIG_NIBBLE_FIFO_BIT_Ttag {
	unsigned int fifo_depth   : BFW_NETX_XM_CFG_NIBBLE_FIFO_fifo_depth;   // Fill level (= number of nibbles) up to which mii-nibble-fifo is filled, before reading to rx register starts. 
	                                                        // 0 means, mii-nibble-fifo is turned off, data is sampled directly to rx register (with jitter), fifo is reset.
	unsigned int read_phase   : BFW_NETX_XM_CFG_NIBBLE_FIFO_read_phase;   // Phases, in which nibbles from MII-nibble-fifo are read to rx register: 
	                                                        // If mii-nibble-fifo is enabled (fifo_depth!=0), the sync-signal (copies data to rx register) is generated by a counter (instead of rx_clk),
	                                                        // that activates the sync-signal every 4 clock-cycles. 'read_phase' defines the phase of that counter, in which sync-signal is active.
	                                                        // If mii_tx_clk is derived from system_clk (e.g. sercos), this allows to synchronize RPU and TPU program flow on mii_tx_clk.
	unsigned int sample_phase : BFW_NETX_XM_CFG_NIBBLE_FIFO_sample_phase; // Phase of mii_rx_clk, where mii_rx_d, rx_dv, rx_err, crs, col are sampled: 
	                                                        // 0: sample at posedge rx_clk + 2cc ~ negedge rx_clk
	                                                        // 1: sample at posedge rx_clk + 1cc
	                                                        // 2: sample at negedge rx_clk + 2cc ~ posedge rx_clk
	                                                        // 3: sample at negedge rx_clk + 1cc
	unsigned int output_phase : BFW_NETX_XM_CFG_NIBBLE_FIFO_output_phase; // Phase of mii_tx_clk, where mii_tx_d, tx_en, tx_err outputs are changed: 
	                                                        // 0: change output at posedge tx_clk + 3cc ~ negedge tx_clk + 1cc
	                                                        // 1: change output at posedge tx_clk + 2cc
	                                                        // 2: change output at negedge tx_clk + 3cc ~ posedge tx_clk + 1cc
	                                                        // 3: change output at negedge tx_clk + 2cc
	unsigned int reserved1    : BFW_NETX_XM_CFG_NIBBLE_FIFO_reserved1;    // reserved
} XMAC_CONFIG_NIBBLE_FIFO_BIT_T;

typedef union {
	unsigned int                  val;
	XMAC_CONFIG_NIBBLE_FIFO_BIT_T bf;
} XMAC_CONFIG_NIBBLE_FIFO_T;

// ---------------------------------------------------------------------
// Register xmac_config_sbu
// => xMAC Config Register for SBU
// => Mode: Mode (r/w)
// ---------------------------------------------------------------------

#define REL_NETX_XM_CFG_SBU   0x000008F4U
#define NETX_XM0_CFG_SBU 0x001608F4U
#define NETX_XM1_CFG_SBU 0x001618F4U
#define NETX_XM2_CFG_SBU 0x001628F4U
#define NETX_XM3_CFG_SBU 0x001638F4U

#define MSK_NETX_XM_CFG_SBU_sync_to_eclk      0x00000001U // [0]
#define SRT_NETX_XM_CFG_SBU_sync_to_eclk      0           
#define MSK_NETX_XM_CFG_SBU_sync_to_bitstream 0x00000002U // [1]
#define SRT_NETX_XM_CFG_SBU_sync_to_bitstream 1           
#define MSK_NETX_XM_CFG_SBU_sync_to_posedge   0x00000004U // [2]
#define SRT_NETX_XM_CFG_SBU_sync_to_posedge   2           
#define MSK_NETX_XM_CFG_SBU_sync_to_negedge   0x00000008U // [3]
#define SRT_NETX_XM_CFG_SBU_sync_to_negedge   3           
#define MSK_NETX_XM_CFG_SBU_count_modulo      0x00000010U // [4]
#define SRT_NETX_XM_CFG_SBU_count_modulo      4           
#define MSK_NETX_XM_CFG_SBU_invert_bit        0x00000020U // [5]
#define SRT_NETX_XM_CFG_SBU_invert_bit        5           
#define MSK_NETX_XM_CFG_SBU_predivide_clk     0x00000040U // [6]
#define SRT_NETX_XM_CFG_SBU_predivide_clk     6           
#define MSK_NETX_XM_CFG_SBU_ext_mode          0x00000300U // [9:8]
#define SRT_NETX_XM_CFG_SBU_ext_mode          8           
#define MSK_NETX_XM_CFG_SBU_rx_err_low_active 0x00000400U // [10]
#define SRT_NETX_XM_CFG_SBU_rx_err_low_active 10          
#define MSK_NETX_XM_CFG_SBU_rx_err_reset      0x00000800U // [11]
#define SRT_NETX_XM_CFG_SBU_rx_err_reset      11          
#define MSK_NETX_XM_CFG_SBU_col_low_active    0x00001000U // [12]
#define SRT_NETX_XM_CFG_SBU_col_low_active    12          
#define MSK_NETX_XM_CFG_SBU_col_reset         0x00002000U // [13]
#define SRT_NETX_XM_CFG_SBU_col_reset         13          
#define MSK_NETX_XM_CFG_SBU_crs_low_active    0x00004000U // [14]
#define SRT_NETX_XM_CFG_SBU_crs_low_active    14          
#define MSK_NETX_XM_CFG_SBU_crs_reset         0x00008000U // [15]
#define SRT_NETX_XM_CFG_SBU_crs_reset         15          

enum {
	BFW_NETX_XM_CFG_SBU_sync_to_eclk      = 1,  // [0]
	BFW_NETX_XM_CFG_SBU_sync_to_bitstream = 1,  // [1]
	BFW_NETX_XM_CFG_SBU_sync_to_posedge   = 1,  // [2]
	BFW_NETX_XM_CFG_SBU_sync_to_negedge   = 1,  // [3]
	BFW_NETX_XM_CFG_SBU_count_modulo      = 1,  // [4]
	BFW_NETX_XM_CFG_SBU_invert_bit        = 1,  // [5]
	BFW_NETX_XM_CFG_SBU_predivide_clk     = 1,  // [6]
	BFW_NETX_XM_CFG_SBU_reserved1         = 1,  // [7]
	BFW_NETX_XM_CFG_SBU_ext_mode          = 2,  // [9:8]
	BFW_NETX_XM_CFG_SBU_rx_err_low_active = 1,  // [10]
	BFW_NETX_XM_CFG_SBU_rx_err_reset      = 1,  // [11]
	BFW_NETX_XM_CFG_SBU_col_low_active    = 1,  // [12]
	BFW_NETX_XM_CFG_SBU_col_reset         = 1,  // [13]
	BFW_NETX_XM_CFG_SBU_crs_low_active    = 1,  // [14]
	BFW_NETX_XM_CFG_SBU_crs_reset         = 1,  // [15]
	BFW_NETX_XM_CFG_SBU_reserved2         = 16  // [31:16]
};

typedef struct XMAC_CONFIG_SBU_BIT_Ttag {
	unsigned int sync_to_eclk      : BFW_NETX_XM_CFG_SBU_sync_to_eclk;      // Synchronize rate_multiplier to external clock, 
	                                                        // rate_mul is set to rate_mul_start at pos/negedge of eclk
	unsigned int sync_to_bitstream : BFW_NETX_XM_CFG_SBU_sync_to_bitstream; // Synchronize rate_multiplier to data_in, 
	                                                        // rate_mul is set to rate_mul_start at pos/negedge of data_in
	unsigned int sync_to_posedge   : BFW_NETX_XM_CFG_SBU_sync_to_posedge;   // Synchronization of rate_multiplier works on positive edges of data_in/eclk 
	unsigned int sync_to_negedge   : BFW_NETX_XM_CFG_SBU_sync_to_negedge;   // Synchronization of rate_multiplier works on negative edges of data_in/eclk 
	unsigned int count_modulo      : BFW_NETX_XM_CFG_SBU_count_modulo;      // rate_multiplier continues counting after maximum value is reached 
	unsigned int invert_bit        : BFW_NETX_XM_CFG_SBU_invert_bit;        // invert incoming bit 
	unsigned int predivide_clk     : BFW_NETX_XM_CFG_SBU_predivide_clk;     // use a clock frequency divided by 256 
	unsigned int reserved1         : BFW_NETX_XM_CFG_SBU_reserved1;         // reserved
	unsigned int ext_mode          : BFW_NETX_XM_CFG_SBU_ext_mode;          // 00 single bit, 01 mii, 10,11 reserved  
	unsigned int rx_err_low_active : BFW_NETX_XM_CFG_SBU_rx_err_low_active; // to generate rx_err_was_here signal: 
	                                                        // 0: activate rx_err_was_here if rx_err=1,
	                                                        // 1: activate rx_err_was_here if rx_err=0,
	unsigned int rx_err_reset      : BFW_NETX_XM_CFG_SBU_rx_err_reset;      // to reset rx_err_was_here signal 
	unsigned int col_low_active    : BFW_NETX_XM_CFG_SBU_col_low_active;    // to generate col_was_here signal: 
	                                                        // 0: activate col_was_here if col=1,
	                                                        // 1: activate col_was_here if col=0,
	unsigned int col_reset         : BFW_NETX_XM_CFG_SBU_col_reset;         // to reset col_was_here signal 
	unsigned int crs_low_active    : BFW_NETX_XM_CFG_SBU_crs_low_active;    // to generate crs_was_here signal: 
	                                                        // 0: activate crs_was_here if crs=1,
	                                                        // 1: activate crs_was_here if crs=0,
	unsigned int crs_reset         : BFW_NETX_XM_CFG_SBU_crs_reset;         // to reset crs_was_here signal 
	unsigned int reserved2         : BFW_NETX_XM_CFG_SBU_reserved2;         // reserved
} XMAC_CONFIG_SBU_BIT_T;

typedef union {
	unsigned int          val;
	XMAC_CONFIG_SBU_BIT_T bf;
} XMAC_CONFIG_SBU_T;

// ---------------------------------------------------------------------
// Register xmac_sbu_rate_mul_add
// => xMAC SBU rate_mul_add:
//    Value added each cc to Rate Multiplier.
//    rate_mul_add = eclk / clk * 65536
//    This register has a write pipeline delay of 1 clock cycle
//    Resetvalue : 0x00000001
// => Mode: Mode (r/w)
// ---------------------------------------------------------------------

#define REL_NETX_XM_SBU_RATE_MUL_ADD   0x000008F8U
#define NETX_XM0_SBU_RATE_MUL_ADD 0x001608F8U
#define NETX_XM1_SBU_RATE_MUL_ADD 0x001618F8U
#define NETX_XM2_SBU_RATE_MUL_ADD 0x001628F8U
#define NETX_XM3_SBU_RATE_MUL_ADD 0x001638F8U

#define MSK_NETX_XM_SBU_RATE_MUL_ADD_rate_mul_add 0x0000ffffU // [15:0]
#define SRT_NETX_XM_SBU_RATE_MUL_ADD_rate_mul_add 0           

enum {
	BFW_NETX_XM_SBU_RATE_MUL_ADD_rate_mul_add = 16, // [15:0]
	BFW_NETX_XM_SBU_RATE_MUL_ADD_reserved1    = 16  // [31:16]
};

typedef struct XMAC_SBU_RATE_MUL_ADD_BIT_Ttag {
	unsigned int rate_mul_add : BFW_NETX_XM_SBU_RATE_MUL_ADD_rate_mul_add; // Value added each cc to Rate Multiplier. 
	                                                        // If rate_mul_add=1:      rate_mul counts from [rate_mul_start:65535]
	                                                        // else (rate_mul_add!=1): rate_mul counts from [0:65535]
	unsigned int reserved1    : BFW_NETX_XM_SBU_RATE_MUL_ADD_reserved1;    // reserved
} XMAC_SBU_RATE_MUL_ADD_BIT_T;

typedef union {
	unsigned int                val;
	XMAC_SBU_RATE_MUL_ADD_BIT_T bf;
} XMAC_SBU_RATE_MUL_ADD_T;

// ---------------------------------------------------------------------
// Register xmac_sbu_rate_mul_start
// => xMAC SBU rate_mul_start
//    This register has a write pipeline delay of 1 clock cycle
//    Resetvalue : 0x00000000
// => Mode: Mode (r/w)
// ---------------------------------------------------------------------

#define REL_NETX_XM_SBU_RATE_MUL_START   0x000008FCU
#define NETX_XM0_SBU_RATE_MUL_START 0x001608FCU
#define NETX_XM1_SBU_RATE_MUL_START 0x001618FCU
#define NETX_XM2_SBU_RATE_MUL_START 0x001628FCU
#define NETX_XM3_SBU_RATE_MUL_START 0x001638FCU

#define MSK_NETX_XM_SBU_RATE_MUL_START_rate_mul_start 0x0000ffffU // [15:0]
#define SRT_NETX_XM_SBU_RATE_MUL_START_rate_mul_start 0           

enum {
	BFW_NETX_XM_SBU_RATE_MUL_START_rate_mul_start = 16, // [15:0]
	BFW_NETX_XM_SBU_RATE_MUL_START_reserved1      = 16  // [31:16]
};

typedef struct XMAC_SBU_RATE_MUL_START_BIT_Ttag {
	unsigned int rate_mul_start : BFW_NETX_XM_SBU_RATE_MUL_START_rate_mul_start; // Value, the Rate Multiplier is set to at sync 
	unsigned int reserved1      : BFW_NETX_XM_SBU_RATE_MUL_START_reserved1;      // reserved
} XMAC_SBU_RATE_MUL_START_BIT_T;

typedef union {
	unsigned int                  val;
	XMAC_SBU_RATE_MUL_START_BIT_T bf;
} XMAC_SBU_RATE_MUL_START_T;

// ---------------------------------------------------------------------
// Register xmac_sbu_rate_mul
// => xMAC SBU rate_mul
// => Mode: Mode (r)
// ---------------------------------------------------------------------

#define REL_NETX_XM_SBU_RATE_MUL   0x00000900U
#define NETX_XM0_SBU_RATE_MUL 0x00160900U
#define NETX_XM1_SBU_RATE_MUL 0x00161900U
#define NETX_XM2_SBU_RATE_MUL 0x00162900U
#define NETX_XM3_SBU_RATE_MUL 0x00163900U

#define MSK_NETX_XM_SBU_RATE_MUL_rate_mul 0x0000ffffU // [15:0]
#define SRT_NETX_XM_SBU_RATE_MUL_rate_mul 0           

enum {
	BFW_NETX_XM_SBU_RATE_MUL_rate_mul  = 16, // [15:0]
	BFW_NETX_XM_SBU_RATE_MUL_reserved1 = 16  // [31:16]
};

typedef struct XMAC_SBU_RATE_MUL_BIT_Ttag {
	unsigned int rate_mul  : BFW_NETX_XM_SBU_RATE_MUL_rate_mul;  // current value of Rate Multiplier
	unsigned int reserved1 : BFW_NETX_XM_SBU_RATE_MUL_reserved1; // reserved
} XMAC_SBU_RATE_MUL_BIT_T;

typedef union {
	unsigned int            val;
	XMAC_SBU_RATE_MUL_BIT_T bf;
} XMAC_SBU_RATE_MUL_T;

// ---------------------------------------------------------------------
// Register xmac_start_sample_pos
// => xMAC SBU start_sample_pos
//    This register has a write pipeline delay of 1 clock cycle
//    Resetvalue : 0x00000000
// => Mode: Mode (r/w)
// ---------------------------------------------------------------------

#define REL_NETX_XM_START_SAMPLE_POS   0x00000904U
#define NETX_XM0_START_SAMPLE_POS 0x00160904U
#define NETX_XM1_START_SAMPLE_POS 0x00161904U
#define NETX_XM2_START_SAMPLE_POS 0x00162904U
#define NETX_XM3_START_SAMPLE_POS 0x00163904U

#define MSK_NETX_XM_START_SAMPLE_POS_start_sample_pos 0x0000ffffU // [15:0]
#define SRT_NETX_XM_START_SAMPLE_POS_start_sample_pos 0           

enum {
	BFW_NETX_XM_START_SAMPLE_POS_start_sample_pos = 16, // [15:0]
	BFW_NETX_XM_START_SAMPLE_POS_reserved1        = 16  // [31:16]
};

typedef struct XMAC_START_SAMPLE_POS_BIT_Ttag {
	unsigned int start_sample_pos : BFW_NETX_XM_START_SAMPLE_POS_start_sample_pos; // data is sampled and averaged if start_sample_pos <= rate_mul < stop_sample_pos 
	unsigned int reserved1        : BFW_NETX_XM_START_SAMPLE_POS_reserved1;        // reserved
} XMAC_START_SAMPLE_POS_BIT_T;

typedef union {
	unsigned int                val;
	XMAC_START_SAMPLE_POS_BIT_T bf;
} XMAC_START_SAMPLE_POS_T;

// ---------------------------------------------------------------------
// Register xmac_stop_sample_pos
// => xMAC SBU stop_sample_pos
//    This register has a write pipeline delay of 1 clock cycle
//    Resetvalue : 0x00000000
// => Mode: Mode (r/w)
// ---------------------------------------------------------------------

#define REL_NETX_XM_STOP_SAMPLE_POS   0x00000908U
#define NETX_XM0_STOP_SAMPLE_POS 0x00160908U
#define NETX_XM1_STOP_SAMPLE_POS 0x00161908U
#define NETX_XM2_STOP_SAMPLE_POS 0x00162908U
#define NETX_XM3_STOP_SAMPLE_POS 0x00163908U

#define MSK_NETX_XM_STOP_SAMPLE_POS_stop_sample_pos 0x0000ffffU // [15:0]
#define SRT_NETX_XM_STOP_SAMPLE_POS_stop_sample_pos 0           

enum {
	BFW_NETX_XM_STOP_SAMPLE_POS_stop_sample_pos = 16, // [15:0]
	BFW_NETX_XM_STOP_SAMPLE_POS_reserved1       = 16  // [31:16]
};

typedef struct XMAC_STOP_SAMPLE_POS_BIT_Ttag {
	unsigned int stop_sample_pos : BFW_NETX_XM_STOP_SAMPLE_POS_stop_sample_pos; // data is sampled and averaged if start_sample_pos <= rate_mul < stop_sample_pos 
	unsigned int reserved1       : BFW_NETX_XM_STOP_SAMPLE_POS_reserved1;       // reserved
} XMAC_STOP_SAMPLE_POS_BIT_T;

typedef union {
	unsigned int               val;
	XMAC_STOP_SAMPLE_POS_BIT_T bf;
} XMAC_STOP_SAMPLE_POS_T;

// ---------------------------------------------------------------------
// Register xmac_config_obu
// => xMAC Config Register for OBU
// => Mode: Mode (r/w)
// ---------------------------------------------------------------------

#define REL_NETX_XM_CFG_OBU   0x0000090CU
#define NETX_XM0_CFG_OBU 0x0016090CU
#define NETX_XM1_CFG_OBU 0x0016190CU
#define NETX_XM2_CFG_OBU 0x0016290CU
#define NETX_XM3_CFG_OBU 0x0016390CU

#define MSK_NETX_XM_CFG_OBU_sync_to_eclk          0x00000001U // [0]
#define SRT_NETX_XM_CFG_OBU_sync_to_eclk          0           
#define MSK_NETX_XM_CFG_OBU_sync_to_bitstream     0x00000002U // [1]
#define SRT_NETX_XM_CFG_OBU_sync_to_bitstream     1           
#define MSK_NETX_XM_CFG_OBU_sync_to_posedge       0x00000004U // [2]
#define SRT_NETX_XM_CFG_OBU_sync_to_posedge       2           
#define MSK_NETX_XM_CFG_OBU_sync_to_negedge       0x00000008U // [3]
#define SRT_NETX_XM_CFG_OBU_sync_to_negedge       3           
#define MSK_NETX_XM_CFG_OBU_count_modulo          0x00000010U // [4]
#define SRT_NETX_XM_CFG_OBU_count_modulo          4           
#define MSK_NETX_XM_CFG_OBU_invert_bit            0x00000020U // [5]
#define SRT_NETX_XM_CFG_OBU_invert_bit            5           
#define MSK_NETX_XM_CFG_OBU_predivide_clk         0x00000040U // [6]
#define SRT_NETX_XM_CFG_OBU_predivide_clk         6           
#define MSK_NETX_XM_CFG_OBU_tx_three_state        0x00000080U // [7]
#define SRT_NETX_XM_CFG_OBU_tx_three_state        7           
#define MSK_NETX_XM_CFG_OBU_eclk_noe              0x00000100U // [8]
#define SRT_NETX_XM_CFG_OBU_eclk_noe              8           
#define MSK_NETX_XM_CFG_OBU_sample_bitstream_eclk 0x00000200U // [9]
#define SRT_NETX_XM_CFG_OBU_sample_bitstream_eclk 9           
#define MSK_NETX_XM_CFG_OBU_arb_lost_delay        0x0000fc00U // [15:10]
#define SRT_NETX_XM_CFG_OBU_arb_lost_delay        10          

enum {
	BFW_NETX_XM_CFG_OBU_sync_to_eclk          = 1,  // [0]
	BFW_NETX_XM_CFG_OBU_sync_to_bitstream     = 1,  // [1]
	BFW_NETX_XM_CFG_OBU_sync_to_posedge       = 1,  // [2]
	BFW_NETX_XM_CFG_OBU_sync_to_negedge       = 1,  // [3]
	BFW_NETX_XM_CFG_OBU_count_modulo          = 1,  // [4]
	BFW_NETX_XM_CFG_OBU_invert_bit            = 1,  // [5]
	BFW_NETX_XM_CFG_OBU_predivide_clk         = 1,  // [6]
	BFW_NETX_XM_CFG_OBU_tx_three_state        = 1,  // [7]
	BFW_NETX_XM_CFG_OBU_eclk_noe              = 1,  // [8]
	BFW_NETX_XM_CFG_OBU_sample_bitstream_eclk = 1,  // [9]
	BFW_NETX_XM_CFG_OBU_arb_lost_delay        = 6,  // [15:10]
	BFW_NETX_XM_CFG_OBU_reserved1             = 16  // [31:16]
};

typedef struct XMAC_CONFIG_OBU_BIT_Ttag {
	unsigned int sync_to_eclk          : BFW_NETX_XM_CFG_OBU_sync_to_eclk;          // Synchronize rate_multiplier to external clock, 
	                                                        // rate_mul is set to rate_mul_start at pos/negedge of eclk
	unsigned int sync_to_bitstream     : BFW_NETX_XM_CFG_OBU_sync_to_bitstream;     // Synchronize rate_multiplier to data_in, 
	                                                        // rate_mul is set to rate_mul_start at pos/negedge of data_in
	unsigned int sync_to_posedge       : BFW_NETX_XM_CFG_OBU_sync_to_posedge;       // Synchronization of rate_multiplier works on positive edges of data_in/eclk 
	unsigned int sync_to_negedge       : BFW_NETX_XM_CFG_OBU_sync_to_negedge;       // Synchronization of rate_multiplier works on negative edges of data_in/eclk 
	unsigned int count_modulo          : BFW_NETX_XM_CFG_OBU_count_modulo;          // rate_multiplier continues counting after maximum value is reached 
	unsigned int invert_bit            : BFW_NETX_XM_CFG_OBU_invert_bit;            // invert incoming bit 
	unsigned int predivide_clk         : BFW_NETX_XM_CFG_OBU_predivide_clk;         // use a clock frequency divided by 256 
	unsigned int tx_three_state        : BFW_NETX_XM_CFG_OBU_tx_three_state;        // deactivates output enable of actually transmitted bit (or nibble in mii-mode) 
	unsigned int eclk_noe              : BFW_NETX_XM_CFG_OBU_eclk_noe;              // inv. output enable of eclk: 0: eclk generated by xMAC, 1: eclk coming from external 
	unsigned int sample_bitstream_eclk : BFW_NETX_XM_CFG_OBU_sample_bitstream_eclk; // 1: sample outgoing bitstream and its oe with eclk. 
	                                                        // In MII-Mode outgoing tx_d, tx_en and tx_err are sampled with tx_clk.
	unsigned int arb_lost_delay        : BFW_NETX_XM_CFG_OBU_arb_lost_delay;        // nof cc after start_trans_pos, before data_in is sampled for arb_lost 
	unsigned int reserved1             : BFW_NETX_XM_CFG_OBU_reserved1;             // reserved
} XMAC_CONFIG_OBU_BIT_T;

typedef union {
	unsigned int          val;
	XMAC_CONFIG_OBU_BIT_T bf;
} XMAC_CONFIG_OBU_T;

// ---------------------------------------------------------------------
// Register xmac_obu_rate_mul_add
// => xMAC OBU rate_mul_add:
//    Value added each cc to Rate Multiplier.
//    rate_mul_add = eclk / clk * 65536
//    This register has a write pipeline delay of 1 clock cycle
//    Resetvalue : 0x00000001
// => Mode: Mode (r/w)
// ---------------------------------------------------------------------

#define REL_NETX_XM_OBU_RATE_MUL_ADD   0x00000910U
#define NETX_XM0_OBU_RATE_MUL_ADD 0x00160910U
#define NETX_XM1_OBU_RATE_MUL_ADD 0x00161910U
#define NETX_XM2_OBU_RATE_MUL_ADD 0x00162910U
#define NETX_XM3_OBU_RATE_MUL_ADD 0x00163910U

#define MSK_NETX_XM_OBU_RATE_MUL_ADD_rate_mul_add 0x0000ffffU // [15:0]
#define SRT_NETX_XM_OBU_RATE_MUL_ADD_rate_mul_add 0           

enum {
	BFW_NETX_XM_OBU_RATE_MUL_ADD_rate_mul_add = 16, // [15:0]
	BFW_NETX_XM_OBU_RATE_MUL_ADD_reserved1    = 16  // [31:16]
};

typedef struct XMAC_OBU_RATE_MUL_ADD_BIT_Ttag {
	unsigned int rate_mul_add : BFW_NETX_XM_OBU_RATE_MUL_ADD_rate_mul_add; // Value added each cc to Rate Multiplier. 
	                                                        // If rate_mul_add=1:      rate_mul counts from [rate_mul_start:65535]
	                                                        // else (rate_mul_add!=1): rate_mul counts from [0:65535]
	unsigned int reserved1    : BFW_NETX_XM_OBU_RATE_MUL_ADD_reserved1;    // reserved
} XMAC_OBU_RATE_MUL_ADD_BIT_T;

typedef union {
	unsigned int                val;
	XMAC_OBU_RATE_MUL_ADD_BIT_T bf;
} XMAC_OBU_RATE_MUL_ADD_T;

// ---------------------------------------------------------------------
// Register xmac_obu_rate_mul_start
// => xMAC OBU rate_mul_start
//    This register has a write pipeline delay of 1 clock cycle
//    Resetvalue : 0x00000000
// => Mode: Mode (r/w)
// ---------------------------------------------------------------------

#define REL_NETX_XM_OBU_RATE_MUL_START   0x00000914U
#define NETX_XM0_OBU_RATE_MUL_START 0x00160914U
#define NETX_XM1_OBU_RATE_MUL_START 0x00161914U
#define NETX_XM2_OBU_RATE_MUL_START 0x00162914U
#define NETX_XM3_OBU_RATE_MUL_START 0x00163914U

#define MSK_NETX_XM_OBU_RATE_MUL_START_rate_mul_start 0x0000ffffU // [15:0]
#define SRT_NETX_XM_OBU_RATE_MUL_START_rate_mul_start 0           

enum {
	BFW_NETX_XM_OBU_RATE_MUL_START_rate_mul_start = 16, // [15:0]
	BFW_NETX_XM_OBU_RATE_MUL_START_reserved1      = 16  // [31:16]
};

typedef struct XMAC_OBU_RATE_MUL_START_BIT_Ttag {
	unsigned int rate_mul_start : BFW_NETX_XM_OBU_RATE_MUL_START_rate_mul_start; // Value, the Rate Multiplier is set to at sync 
	unsigned int reserved1      : BFW_NETX_XM_OBU_RATE_MUL_START_reserved1;      // reserved
} XMAC_OBU_RATE_MUL_START_BIT_T;

typedef union {
	unsigned int                  val;
	XMAC_OBU_RATE_MUL_START_BIT_T bf;
} XMAC_OBU_RATE_MUL_START_T;

// ---------------------------------------------------------------------
// Register xmac_obu_rate_mul
// => xMAC OBU rate_mul
// => Mode: Mode (r)
// ---------------------------------------------------------------------

#define REL_NETX_XM_OBU_RATE_MUL   0x00000918U
#define NETX_XM0_OBU_RATE_MUL 0x00160918U
#define NETX_XM1_OBU_RATE_MUL 0x00161918U
#define NETX_XM2_OBU_RATE_MUL 0x00162918U
#define NETX_XM3_OBU_RATE_MUL 0x00163918U

#define MSK_NETX_XM_OBU_RATE_MUL_rate_mul 0x0000ffffU // [15:0]
#define SRT_NETX_XM_OBU_RATE_MUL_rate_mul 0           

enum {
	BFW_NETX_XM_OBU_RATE_MUL_rate_mul  = 16, // [15:0]
	BFW_NETX_XM_OBU_RATE_MUL_reserved1 = 16  // [31:16]
};

typedef struct XMAC_OBU_RATE_MUL_BIT_Ttag {
	unsigned int rate_mul  : BFW_NETX_XM_OBU_RATE_MUL_rate_mul;  // current value of Rate Multiplier
	unsigned int reserved1 : BFW_NETX_XM_OBU_RATE_MUL_reserved1; // reserved
} XMAC_OBU_RATE_MUL_BIT_T;

typedef union {
	unsigned int            val;
	XMAC_OBU_RATE_MUL_BIT_T bf;
} XMAC_OBU_RATE_MUL_T;

// ---------------------------------------------------------------------
// Register xmac_start_trans_pos
// => xMAC SBU start_trans_pos
//    This register has a write pipeline delay of 1 clock cycle
//    Resetvalue : 0x00000000
// => Mode: Mode (r/w)
// ---------------------------------------------------------------------

#define REL_NETX_XM_START_TRANS_POS   0x0000091CU
#define NETX_XM0_START_TRANS_POS 0x0016091CU
#define NETX_XM1_START_TRANS_POS 0x0016191CU
#define NETX_XM2_START_TRANS_POS 0x0016291CU
#define NETX_XM3_START_TRANS_POS 0x0016391CU

#define MSK_NETX_XM_START_TRANS_POS_start_trans_pos 0x0000ffffU // [15:0]
#define SRT_NETX_XM_START_TRANS_POS_start_trans_pos 0           

enum {
	BFW_NETX_XM_START_TRANS_POS_start_trans_pos = 16, // [15:0]
	BFW_NETX_XM_START_TRANS_POS_reserved1       = 16  // [31:16]
};

typedef struct XMAC_START_TRANS_POS_BIT_Ttag {
	unsigned int start_trans_pos : BFW_NETX_XM_START_TRANS_POS_start_trans_pos; // bitstream_out and bitstream_oe change their value at start_trans_pos = rate_mul 
	unsigned int reserved1       : BFW_NETX_XM_START_TRANS_POS_reserved1;       // reserved
} XMAC_START_TRANS_POS_BIT_T;

typedef union {
	unsigned int               val;
	XMAC_START_TRANS_POS_BIT_T bf;
} XMAC_START_TRANS_POS_T;

// ---------------------------------------------------------------------
// Register xmac_stop_trans_pos
// => xMAC SBU stop_trans_pos
//    This register has a write pipeline delay of 1 clock cycle
//    Resetvalue : 0x00000000
// => Mode: Mode (r/w)
// ---------------------------------------------------------------------

#define REL_NETX_XM_STOP_TRANS_POS   0x00000920U
#define NETX_XM0_STOP_TRANS_POS 0x00160920U
#define NETX_XM1_STOP_TRANS_POS 0x00161920U
#define NETX_XM2_STOP_TRANS_POS 0x00162920U
#define NETX_XM3_STOP_TRANS_POS 0x00163920U

#define MSK_NETX_XM_STOP_TRANS_POS_stop_trans_pos 0x0000ffffU // [15:0]
#define SRT_NETX_XM_STOP_TRANS_POS_stop_trans_pos 0           

enum {
	BFW_NETX_XM_STOP_TRANS_POS_stop_trans_pos = 16, // [15:0]
	BFW_NETX_XM_STOP_TRANS_POS_reserved1      = 16  // [31:16]
};

typedef struct XMAC_STOP_TRANS_POS_BIT_Ttag {
	unsigned int stop_trans_pos : BFW_NETX_XM_STOP_TRANS_POS_stop_trans_pos; // bitstream_oe becomes 0 if rate_mul >= stop_trans_pos 
	unsigned int reserved1      : BFW_NETX_XM_STOP_TRANS_POS_reserved1;      // reserved
} XMAC_STOP_TRANS_POS_BIT_T;

typedef union {
	unsigned int              val;
	XMAC_STOP_TRANS_POS_BIT_T bf;
} XMAC_STOP_TRANS_POS_T;

// ---------------------------------------------------------------------
// Register xmac_rpu_count1
// => xMAC RPU Counter 1
//    Resetvalue : 0x00000000
// => Mode: Mode (r/w)
// ---------------------------------------------------------------------

#define REL_NETX_XM_RPU_CNT1   0x00000924U
#define NETX_XM0_RPU_CNT1 0x00160924U
#define NETX_XM1_RPU_CNT1 0x00161924U
#define NETX_XM2_RPU_CNT1 0x00162924U
#define NETX_XM3_RPU_CNT1 0x00163924U

#define MSK_NETX_XM_RPU_CNT1_rpu_count1 0x0000ffffU // [15:0]
#define SRT_NETX_XM_RPU_CNT1_rpu_count1 0           

enum {
	BFW_NETX_XM_RPU_CNT1_rpu_count1 = 16, // [15:0]
	BFW_NETX_XM_RPU_CNT1_reserved1  = 16  // [31:16]
};

typedef struct XMAC_RPU_COUNT1_BIT_Ttag {
	unsigned int rpu_count1 : BFW_NETX_XM_RPU_CNT1_rpu_count1; // Counter incremented by rpu-hw_support bit cnt1 
	unsigned int reserved1  : BFW_NETX_XM_RPU_CNT1_reserved1;  // reserved
} XMAC_RPU_COUNT1_BIT_T;

typedef union {
	unsigned int          val;
	XMAC_RPU_COUNT1_BIT_T bf;
} XMAC_RPU_COUNT1_T;

// ---------------------------------------------------------------------
// Register xmac_rpu_count2
// => xMAC RPU Counter 2
//    Resetvalue : 0x00000000
// => Mode: Mode (r/w)
// ---------------------------------------------------------------------

#define REL_NETX_XM_RPU_CNT2   0x00000928U
#define NETX_XM0_RPU_CNT2 0x00160928U
#define NETX_XM1_RPU_CNT2 0x00161928U
#define NETX_XM2_RPU_CNT2 0x00162928U
#define NETX_XM3_RPU_CNT2 0x00163928U

#define MSK_NETX_XM_RPU_CNT2_rpu_count2 0x0000ffffU // [15:0]
#define SRT_NETX_XM_RPU_CNT2_rpu_count2 0           

enum {
	BFW_NETX_XM_RPU_CNT2_rpu_count2 = 16, // [15:0]
	BFW_NETX_XM_RPU_CNT2_reserved1  = 16  // [31:16]
};

typedef struct XMAC_RPU_COUNT2_BIT_Ttag {
	unsigned int rpu_count2 : BFW_NETX_XM_RPU_CNT2_rpu_count2; // Counter incremented by rpu-hw_support bit cnt2 
	unsigned int reserved1  : BFW_NETX_XM_RPU_CNT2_reserved1;  // reserved
} XMAC_RPU_COUNT2_BIT_T;

typedef union {
	unsigned int          val;
	XMAC_RPU_COUNT2_BIT_T bf;
} XMAC_RPU_COUNT2_T;

// ---------------------------------------------------------------------
// Register xmac_tpu_count1
// => xMAC TPU Counter 1
//    Resetvalue : 0x00000000
// => Mode: Mode (r/w)
// ---------------------------------------------------------------------

#define REL_NETX_XM_TPU_CNT1   0x0000092CU
#define NETX_XM0_TPU_CNT1 0x0016092CU
#define NETX_XM1_TPU_CNT1 0x0016192CU
#define NETX_XM2_TPU_CNT1 0x0016292CU
#define NETX_XM3_TPU_CNT1 0x0016392CU

#define MSK_NETX_XM_TPU_CNT1_tpu_count1 0x0000ffffU // [15:0]
#define SRT_NETX_XM_TPU_CNT1_tpu_count1 0           

enum {
	BFW_NETX_XM_TPU_CNT1_tpu_count1 = 16, // [15:0]
	BFW_NETX_XM_TPU_CNT1_reserved1  = 16  // [31:16]
};

typedef struct XMAC_TPU_COUNT1_BIT_Ttag {
	unsigned int tpu_count1 : BFW_NETX_XM_TPU_CNT1_tpu_count1; // Counter incremented by tpu-hw_support bit cnt1 
	unsigned int reserved1  : BFW_NETX_XM_TPU_CNT1_reserved1;  // reserved
} XMAC_TPU_COUNT1_BIT_T;

typedef union {
	unsigned int          val;
	XMAC_TPU_COUNT1_BIT_T bf;
} XMAC_TPU_COUNT1_T;

// ---------------------------------------------------------------------
// Register xmac_tpu_count2
// => xMAC TPU Counter 2
//    Resetvalue : 0x00000000
// => Mode: Mode (r/w)
// ---------------------------------------------------------------------

#define REL_NETX_XM_TPU_CNT2   0x00000930U
#define NETX_XM0_TPU_CNT2 0x00160930U
#define NETX_XM1_TPU_CNT2 0x00161930U
#define NETX_XM2_TPU_CNT2 0x00162930U
#define NETX_XM3_TPU_CNT2 0x00163930U

#define MSK_NETX_XM_TPU_CNT2_tpu_count2 0x0000ffffU // [15:0]
#define SRT_NETX_XM_TPU_CNT2_tpu_count2 0           

enum {
	BFW_NETX_XM_TPU_CNT2_tpu_count2 = 16, // [15:0]
	BFW_NETX_XM_TPU_CNT2_reserved1  = 16  // [31:16]
};

typedef struct XMAC_TPU_COUNT2_BIT_Ttag {
	unsigned int tpu_count2 : BFW_NETX_XM_TPU_CNT2_tpu_count2; // Counter incremented by tpu-hw_support bit cnt2 
	unsigned int reserved1  : BFW_NETX_XM_TPU_CNT2_reserved1;  // reserved
} XMAC_TPU_COUNT2_BIT_T;

typedef union {
	unsigned int          val;
	XMAC_TPU_COUNT2_BIT_T bf;
} XMAC_TPU_COUNT2_T;

// ---------------------------------------------------------------------
// Register xmac_rx_count
// => xMAC RX Counter
//    Resetvalue : 0x00000000
// => Mode: Mode (r/w)
// ---------------------------------------------------------------------

#define REL_NETX_XM_RX_CNT   0x00000934U
#define NETX_XM0_RX_CNT 0x00160934U
#define NETX_XM1_RX_CNT 0x00161934U
#define NETX_XM2_RX_CNT 0x00162934U
#define NETX_XM3_RX_CNT 0x00163934U

#define MSK_NETX_XM_RX_CNT_rx_count 0x0000ffffU // [15:0]
#define SRT_NETX_XM_RX_CNT_rx_count 0           

enum {
	BFW_NETX_XM_RX_CNT_rx_count  = 16, // [15:0]
	BFW_NETX_XM_RX_CNT_reserved1 = 16  // [31:16]
};

typedef struct XMAC_RX_COUNT_BIT_Ttag {
	unsigned int rx_count  : BFW_NETX_XM_RX_CNT_rx_count;  // Counter running on eclk 
	unsigned int reserved1 : BFW_NETX_XM_RX_CNT_reserved1; // reserved
} XMAC_RX_COUNT_BIT_T;

typedef union {
	unsigned int        val;
	XMAC_RX_COUNT_BIT_T bf;
} XMAC_RX_COUNT_T;

// ---------------------------------------------------------------------
// Register xmac_tx_count
// => xMAC TX Counter
//    Resetvalue : 0x00000000
// => Mode: Mode (r/w)
// ---------------------------------------------------------------------

#define REL_NETX_XM_TX_CNT   0x00000938U
#define NETX_XM0_TX_CNT 0x00160938U
#define NETX_XM1_TX_CNT 0x00161938U
#define NETX_XM2_TX_CNT 0x00162938U
#define NETX_XM3_TX_CNT 0x00163938U

#define MSK_NETX_XM_TX_CNT_tx_count 0x0000ffffU // [15:0]
#define SRT_NETX_XM_TX_CNT_tx_count 0           

enum {
	BFW_NETX_XM_TX_CNT_tx_count  = 16, // [15:0]
	BFW_NETX_XM_TX_CNT_reserved1 = 16  // [31:16]
};

typedef struct XMAC_TX_COUNT_BIT_Ttag {
	unsigned int tx_count  : BFW_NETX_XM_TX_CNT_tx_count;  // Counter running on eclk 
	unsigned int reserved1 : BFW_NETX_XM_TX_CNT_reserved1; // reserved
} XMAC_TX_COUNT_BIT_T;

typedef union {
	unsigned int        val;
	XMAC_TX_COUNT_BIT_T bf;
} XMAC_TX_COUNT_T;

// ---------------------------------------------------------------------
// Register xmac_rpm_mask0
// => xMAC Receive Pattern Match Mask 0 Register:
//    Defines, which bits are compared between xmac_rpm_val0 and xmac_rx.
//    Resetvalue : 0x00000000
// => Mode: Mode (r/w)
// ---------------------------------------------------------------------

#define REL_NETX_XM_RPM_MSK0   0x0000093CU
#define NETX_XM0_RPM_MSK0 0x0016093CU
#define NETX_XM1_RPM_MSK0 0x0016193CU
#define NETX_XM2_RPM_MSK0 0x0016293CU
#define NETX_XM3_RPM_MSK0 0x0016393CU

#define MSK_NETX_XM_RPM_MSK0_PM_MASK0 0x0000ffffU // [15:0]
#define SRT_NETX_XM_RPM_MSK0_PM_MASK0 0           

enum {
	BFW_NETX_XM_RPM_MSK0_PM_MASK0  = 16, // [15:0]
	BFW_NETX_XM_RPM_MSK0_reserved1 = 16  // [31:16]
};

typedef struct XMAC_RPM_MASK0_BIT_Ttag {
	unsigned int PM_MASK0  : BFW_NETX_XM_RPM_MSK0_PM_MASK0;  // Pattern Match Mask: 
	                                                        // 1: compare this position of xmac_rpm_val0 and xmac_rx
	                                                        // 0: ignore  this position of xmac_rpm_val0 and xmac_rx
	unsigned int reserved1 : BFW_NETX_XM_RPM_MSK0_reserved1; // reserved
} XMAC_RPM_MASK0_BIT_T;

typedef union {
	unsigned int         val;
	XMAC_RPM_MASK0_BIT_T bf;
} XMAC_RPM_MASK0_T;

// ---------------------------------------------------------------------
// Register xmac_rpm_val0
// => xMAC Receive Pattern Match Value 0 Register:
//    Defines value of bits to be compared with xmac_rx.
//    Resetvalue : 0x00000000
// => Mode: Mode (r/w)
// ---------------------------------------------------------------------

#define REL_NETX_XM_RPM_VAL0   0x00000940U
#define NETX_XM0_RPM_VAL0 0x00160940U
#define NETX_XM1_RPM_VAL0 0x00161940U
#define NETX_XM2_RPM_VAL0 0x00162940U
#define NETX_XM3_RPM_VAL0 0x00163940U

#define MSK_NETX_XM_RPM_VAL0_PM_VAL0 0x0000ffffU // [15:0]
#define SRT_NETX_XM_RPM_VAL0_PM_VAL0 0           

enum {
	BFW_NETX_XM_RPM_VAL0_PM_VAL0   = 16, // [15:0]
	BFW_NETX_XM_RPM_VAL0_reserved1 = 16  // [31:16]
};

typedef struct XMAC_RPM_VAL0_BIT_Ttag {
	unsigned int PM_VAL0   : BFW_NETX_XM_RPM_VAL0_PM_VAL0;   // Pattern Match Value 
	unsigned int reserved1 : BFW_NETX_XM_RPM_VAL0_reserved1; // reserved
} XMAC_RPM_VAL0_BIT_T;

typedef union {
	unsigned int        val;
	XMAC_RPM_VAL0_BIT_T bf;
} XMAC_RPM_VAL0_T;

// ---------------------------------------------------------------------
// Register xmac_rpm_mask1
// => xMAC Receive Pattern Match Mask 1 Register:
//    Defines, which bits are compared between xmac_rpm_val1 and xmac_rx
//    Resetvalue : 0x0000
// => Mode: Mode (r/w)
// ---------------------------------------------------------------------

#define REL_NETX_XM_RPM_MSK1   0x00000944U
#define NETX_XM0_RPM_MSK1 0x00160944U
#define NETX_XM1_RPM_MSK1 0x00161944U
#define NETX_XM2_RPM_MSK1 0x00162944U
#define NETX_XM3_RPM_MSK1 0x00163944U

#define MSK_NETX_XM_RPM_MSK1_PM_MASK1 0x0000ffffU // [15:0]
#define SRT_NETX_XM_RPM_MSK1_PM_MASK1 0           

enum {
	BFW_NETX_XM_RPM_MSK1_PM_MASK1  = 16, // [15:0]
	BFW_NETX_XM_RPM_MSK1_reserved1 = 16  // [31:16]
};

typedef struct XMAC_RPM_MASK1_BIT_Ttag {
	unsigned int PM_MASK1  : BFW_NETX_XM_RPM_MSK1_PM_MASK1;  // Pattern Match Mask: 
	                                                        // 1: compare this position of xmac_rpm_val1 and xmac_rx
	                                                        // 0: ignore  this position of xmac_rpm_val1 and xmac_rx
	unsigned int reserved1 : BFW_NETX_XM_RPM_MSK1_reserved1; // reserved
} XMAC_RPM_MASK1_BIT_T;

typedef union {
	unsigned int         val;
	XMAC_RPM_MASK1_BIT_T bf;
} XMAC_RPM_MASK1_T;

// ---------------------------------------------------------------------
// Register xmac_rpm_val1
// => xMAC Receive Pattern Match Value 1 Register:
//    Defines value of bits to be compared with xmac_rx.
//    Resetvalue : 0x00000000
// => Mode: Mode (r/w)
// ---------------------------------------------------------------------

#define REL_NETX_XM_RPM_VAL1   0x00000948U
#define NETX_XM0_RPM_VAL1 0x00160948U
#define NETX_XM1_RPM_VAL1 0x00161948U
#define NETX_XM2_RPM_VAL1 0x00162948U
#define NETX_XM3_RPM_VAL1 0x00163948U

#define MSK_NETX_XM_RPM_VAL1_PM_VAL1 0x0000ffffU // [15:0]
#define SRT_NETX_XM_RPM_VAL1_PM_VAL1 0           

enum {
	BFW_NETX_XM_RPM_VAL1_PM_VAL1   = 16, // [15:0]
	BFW_NETX_XM_RPM_VAL1_reserved1 = 16  // [31:16]
};

typedef struct XMAC_RPM_VAL1_BIT_Ttag {
	unsigned int PM_VAL1   : BFW_NETX_XM_RPM_VAL1_PM_VAL1;   // Pattern Match Value 
	unsigned int reserved1 : BFW_NETX_XM_RPM_VAL1_reserved1; // reserved
} XMAC_RPM_VAL1_BIT_T;

typedef union {
	unsigned int        val;
	XMAC_RPM_VAL1_BIT_T bf;
} XMAC_RPM_VAL1_T;

// ---------------------------------------------------------------------
// Register xmac_tpm_mask0
// => xMAC Transmit Pattern Match Mask 0 Register:
//    Defines, which bits are compared between xmac_tpm_val0 and xmac_tx_sent.
//    Resetvalue : 0x00000000
// => Mode: Mode (r/w)
// ---------------------------------------------------------------------

#define REL_NETX_XM_TPM_MSK0   0x0000094CU
#define NETX_XM0_TPM_MSK0 0x0016094CU
#define NETX_XM1_TPM_MSK0 0x0016194CU
#define NETX_XM2_TPM_MSK0 0x0016294CU
#define NETX_XM3_TPM_MSK0 0x0016394CU

#define MSK_NETX_XM_TPM_MSK0_PM_MASK0 0x0000ffffU // [15:0]
#define SRT_NETX_XM_TPM_MSK0_PM_MASK0 0           

enum {
	BFW_NETX_XM_TPM_MSK0_PM_MASK0  = 16, // [15:0]
	BFW_NETX_XM_TPM_MSK0_reserved1 = 16  // [31:16]
};

typedef struct XMAC_TPM_MASK0_BIT_Ttag {
	unsigned int PM_MASK0  : BFW_NETX_XM_TPM_MSK0_PM_MASK0;  // Pattern Match Mask: 
	                                                        // 1: compare this position of xmac_tpm_val0 and xmac_tx_sent
	                                                        // 0: ignore  this position of xmac_tpm_val0 and xmac_tx_sent
	unsigned int reserved1 : BFW_NETX_XM_TPM_MSK0_reserved1; // reserved
} XMAC_TPM_MASK0_BIT_T;

typedef union {
	unsigned int         val;
	XMAC_TPM_MASK0_BIT_T bf;
} XMAC_TPM_MASK0_T;

// ---------------------------------------------------------------------
// Register xmac_tpm_val0
// => xMAC Transmit Pattern Match Value 0 Register:
//    Defines value of bits to be compared with xmac_tx_sent.
//    Resetvalue : 0x00000000
// => Mode: Mode (r/w)
// ---------------------------------------------------------------------

#define REL_NETX_XM_TPM_VAL0   0x00000950U
#define NETX_XM0_TPM_VAL0 0x00160950U
#define NETX_XM1_TPM_VAL0 0x00161950U
#define NETX_XM2_TPM_VAL0 0x00162950U
#define NETX_XM3_TPM_VAL0 0x00163950U

#define MSK_NETX_XM_TPM_VAL0_PM_VAL0 0x0000ffffU // [15:0]
#define SRT_NETX_XM_TPM_VAL0_PM_VAL0 0           

enum {
	BFW_NETX_XM_TPM_VAL0_PM_VAL0   = 16, // [15:0]
	BFW_NETX_XM_TPM_VAL0_reserved1 = 16  // [31:16]
};

typedef struct XMAC_TPM_VAL0_BIT_Ttag {
	unsigned int PM_VAL0   : BFW_NETX_XM_TPM_VAL0_PM_VAL0;   // Pattern Match Value 
	unsigned int reserved1 : BFW_NETX_XM_TPM_VAL0_reserved1; // reserved
} XMAC_TPM_VAL0_BIT_T;

typedef union {
	unsigned int        val;
	XMAC_TPM_VAL0_BIT_T bf;
} XMAC_TPM_VAL0_T;

// ---------------------------------------------------------------------
// Register xmac_tpm_mask1
// => xMAC Transmit Pattern Match Mask 1 Register:
//    Defines, which bits are compared between xmac_tpm_val1 and xmac_tx_sent.
//    Resetvalue : 0x0000
// => Mode: Mode (r/w)
// ---------------------------------------------------------------------

#define REL_NETX_XM_TPM_MSK1   0x00000954U
#define NETX_XM0_TPM_MSK1 0x00160954U
#define NETX_XM1_TPM_MSK1 0x00161954U
#define NETX_XM2_TPM_MSK1 0x00162954U
#define NETX_XM3_TPM_MSK1 0x00163954U

#define MSK_NETX_XM_TPM_MSK1_PM_MASK1 0x0000ffffU // [15:0]
#define SRT_NETX_XM_TPM_MSK1_PM_MASK1 0           

enum {
	BFW_NETX_XM_TPM_MSK1_PM_MASK1  = 16, // [15:0]
	BFW_NETX_XM_TPM_MSK1_reserved1 = 16  // [31:16]
};

typedef struct XMAC_TPM_MASK1_BIT_Ttag {
	unsigned int PM_MASK1  : BFW_NETX_XM_TPM_MSK1_PM_MASK1;  // Pattern Match Mask: 
	                                                        // 1: compare this position of xmac_tpm_val1 and xmac_tx_sent
	                                                        // 0: ignore  this position of xmac_tpm_val1 and xmac_tx_sent
	unsigned int reserved1 : BFW_NETX_XM_TPM_MSK1_reserved1; // reserved
} XMAC_TPM_MASK1_BIT_T;

typedef union {
	unsigned int         val;
	XMAC_TPM_MASK1_BIT_T bf;
} XMAC_TPM_MASK1_T;

// ---------------------------------------------------------------------
// Register xmac_tpm_val1
// => xMAC Transmit Pattern Match Value 1 Register:
//    Defines value of bits to be compared with xmac_tx_sent.
//    Resetvalue : 0x00000000
// => Mode: Mode (r/w)
// ---------------------------------------------------------------------

#define REL_NETX_XM_TPM_VAL1   0x00000958U
#define NETX_XM0_TPM_VAL1 0x00160958U
#define NETX_XM1_TPM_VAL1 0x00161958U
#define NETX_XM2_TPM_VAL1 0x00162958U
#define NETX_XM3_TPM_VAL1 0x00163958U

#define MSK_NETX_XM_TPM_VAL1_PM_VAL1 0x0000ffffU // [15:0]
#define SRT_NETX_XM_TPM_VAL1_PM_VAL1 0           

enum {
	BFW_NETX_XM_TPM_VAL1_PM_VAL1   = 16, // [15:0]
	BFW_NETX_XM_TPM_VAL1_reserved1 = 16  // [31:16]
};

typedef struct XMAC_TPM_VAL1_BIT_Ttag {
	unsigned int PM_VAL1   : BFW_NETX_XM_TPM_VAL1_PM_VAL1;   // Pattern Match Value 
	unsigned int reserved1 : BFW_NETX_XM_TPM_VAL1_reserved1; // reserved
} XMAC_TPM_VAL1_BIT_T;

typedef union {
	unsigned int        val;
	XMAC_TPM_VAL1_BIT_T bf;
} XMAC_TPM_VAL1_T;

// ---------------------------------------------------------------------
// Register xmac_rx_crc_polynomial_l
// => xMAC RX CRC Polynomial lower part
//    This register has a write pipeline delay of 1 clock cycle
//    Resetvalue : 0x00000000
// => Mode: Mode (r/w)
// ---------------------------------------------------------------------

#define REL_NETX_XM_RX_CRC_POLYNOMIAL_LO   0x000009D8U
#define NETX_XM0_RX_CRC_POLYNOMIAL_LO 0x001609D8U
#define NETX_XM1_RX_CRC_POLYNOMIAL_LO 0x001619D8U
#define NETX_XM2_RX_CRC_POLYNOMIAL_LO 0x001629D8U
#define NETX_XM3_RX_CRC_POLYNOMIAL_LO 0x001639D8U

#define MSK_NETX_XM_RX_CRC_POLYNOMIAL_LO_RX_POL_L 0x0000ffffU // [15:0]
#define SRT_NETX_XM_RX_CRC_POLYNOMIAL_LO_RX_POL_L 0           

enum {
	BFW_NETX_XM_RX_CRC_POLYNOMIAL_LO_RX_POL_L  = 16, // [15:0]
	BFW_NETX_XM_RX_CRC_POLYNOMIAL_LO_reserved1 = 16  // [31:16]
};

typedef struct XMAC_RX_CRC_POLYNOMIAL_L_BIT_Ttag {
	unsigned int RX_POL_L  : BFW_NETX_XM_RX_CRC_POLYNOMIAL_LO_RX_POL_L;  // lower bits of RX-CRC Polynomial 
	unsigned int reserved1 : BFW_NETX_XM_RX_CRC_POLYNOMIAL_LO_reserved1; // reserved
} XMAC_RX_CRC_POLYNOMIAL_L_BIT_T;

typedef union {
	unsigned int                   val;
	XMAC_RX_CRC_POLYNOMIAL_L_BIT_T bf;
} XMAC_RX_CRC_POLYNOMIAL_L_T;

// ---------------------------------------------------------------------
// Register xmac_rx_crc_polynomial_h
// => xMAC RX CRC Polynomial lower part
//    This register has a write pipeline delay of 1 clock cycle
//    Resetvalue : 0x00000000
// => Mode: Mode (r/w)
// ---------------------------------------------------------------------

#define REL_NETX_XM_RX_CRC_POLYNOMIAL_HI   0x000009DCU
#define NETX_XM0_RX_CRC_POLYNOMIAL_HI 0x001609DCU
#define NETX_XM1_RX_CRC_POLYNOMIAL_HI 0x001619DCU
#define NETX_XM2_RX_CRC_POLYNOMIAL_HI 0x001629DCU
#define NETX_XM3_RX_CRC_POLYNOMIAL_HI 0x001639DCU

#define MSK_NETX_XM_RX_CRC_POLYNOMIAL_HI_RX_POL_H 0x0000ffffU // [15:0]
#define SRT_NETX_XM_RX_CRC_POLYNOMIAL_HI_RX_POL_H 0           

enum {
	BFW_NETX_XM_RX_CRC_POLYNOMIAL_HI_RX_POL_H  = 16, // [15:0]
	BFW_NETX_XM_RX_CRC_POLYNOMIAL_HI_reserved1 = 16  // [31:16]
};

typedef struct XMAC_RX_CRC_POLYNOMIAL_H_BIT_Ttag {
	unsigned int RX_POL_H  : BFW_NETX_XM_RX_CRC_POLYNOMIAL_HI_RX_POL_H;  // upper bits of RX-CRC Polynomial 
	unsigned int reserved1 : BFW_NETX_XM_RX_CRC_POLYNOMIAL_HI_reserved1; // reserved
} XMAC_RX_CRC_POLYNOMIAL_H_BIT_T;

typedef union {
	unsigned int                   val;
	XMAC_RX_CRC_POLYNOMIAL_H_BIT_T bf;
} XMAC_RX_CRC_POLYNOMIAL_H_T;

// ---------------------------------------------------------------------
// Register xmac_rx_crc_l
// => xMAC RX CRC lower part
//    This register has a write pipeline delay of 1 clock cycle
//    Resetvalue : 0x00000000
// => Mode: Mode (r/w)
// ---------------------------------------------------------------------

#define REL_NETX_XM_RX_CRC_LO   0x000009E0U
#define NETX_XM0_RX_CRC_LO 0x001609E0U
#define NETX_XM1_RX_CRC_LO 0x001619E0U
#define NETX_XM2_RX_CRC_LO 0x001629E0U
#define NETX_XM3_RX_CRC_LO 0x001639E0U

#define MSK_NETX_XM_RX_CRC_LO_RX_CRC_L 0x0000ffffU // [15:0]
#define SRT_NETX_XM_RX_CRC_LO_RX_CRC_L 0           

enum {
	BFW_NETX_XM_RX_CRC_LO_RX_CRC_L  = 16, // [15:0]
	BFW_NETX_XM_RX_CRC_LO_reserved1 = 16  // [31:16]
};

typedef struct XMAC_RX_CRC_L_BIT_Ttag {
	unsigned int RX_CRC_L  : BFW_NETX_XM_RX_CRC_LO_RX_CRC_L;  // lower bits of RX-CRC 
	unsigned int reserved1 : BFW_NETX_XM_RX_CRC_LO_reserved1; // reserved
} XMAC_RX_CRC_L_BIT_T;

typedef union {
	unsigned int        val;
	XMAC_RX_CRC_L_BIT_T bf;
} XMAC_RX_CRC_L_T;

// ---------------------------------------------------------------------
// Register xmac_rx_crc_h
// => xMAC RX CRC upper part
//    This register has a write pipeline delay of 1 clock cycle
//    Resetvalue : 0x00000000
// => Mode: Mode (r/w)
// ---------------------------------------------------------------------

#define REL_NETX_XM_RX_CRC_HI   0x000009E4U
#define NETX_XM0_RX_CRC_HI 0x001609E4U
#define NETX_XM1_RX_CRC_HI 0x001619E4U
#define NETX_XM2_RX_CRC_HI 0x001629E4U
#define NETX_XM3_RX_CRC_HI 0x001639E4U

#define MSK_NETX_XM_RX_CRC_HI_RX_CRC_H 0x0000ffffU // [15:0]
#define SRT_NETX_XM_RX_CRC_HI_RX_CRC_H 0           

enum {
	BFW_NETX_XM_RX_CRC_HI_RX_CRC_H  = 16, // [15:0]
	BFW_NETX_XM_RX_CRC_HI_reserved1 = 16  // [31:16]
};

typedef struct XMAC_RX_CRC_H_BIT_Ttag {
	unsigned int RX_CRC_H  : BFW_NETX_XM_RX_CRC_HI_RX_CRC_H;  // upper bits of RX-CRC 
	unsigned int reserved1 : BFW_NETX_XM_RX_CRC_HI_reserved1; // reserved
} XMAC_RX_CRC_H_BIT_T;

typedef union {
	unsigned int        val;
	XMAC_RX_CRC_H_BIT_T bf;
} XMAC_RX_CRC_H_T;

// ---------------------------------------------------------------------
// Register xmac_rx_crc_cfg
// => xMAC RX CRC Config Register
//    Resetvalue : 0x00000000
// => Mode: Mode (r/w)
// ---------------------------------------------------------------------

#define REL_NETX_XM_RX_CRC_CFG   0x000009E8U
#define NETX_XM0_RX_CRC_CFG 0x001609E8U
#define NETX_XM1_RX_CRC_CFG 0x001619E8U
#define NETX_XM2_RX_CRC_CFG 0x001629E8U
#define NETX_XM3_RX_CRC_CFG 0x001639E8U

#define MSK_NETX_XM_RX_CRC_CFG_rx_crc_shift_right 0x00000001U // [0]
#define SRT_NETX_XM_RX_CRC_CFG_rx_crc_shift_right 0           
#define MSK_NETX_XM_RX_CRC_CFG_rx_crc_zero        0x00000002U // [1]
#define SRT_NETX_XM_RX_CRC_CFG_rx_crc_zero        1           
#define MSK_NETX_XM_RX_CRC_CFG_rx_crc_invert      0x00000004U // [2]
#define SRT_NETX_XM_RX_CRC_CFG_rx_crc_invert      2           
#define MSK_NETX_XM_RX_CRC_CFG_rx_crc_len         0x000000f8U // [7:3]
#define SRT_NETX_XM_RX_CRC_CFG_rx_crc_len         3           
#define MSK_NETX_XM_RX_CRC_CFG_rx_crc_nof_bits    0x00000300U // [9:8]
#define SRT_NETX_XM_RX_CRC_CFG_rx_crc_nof_bits    8           
#define MSK_NETX_XM_RX_CRC_CFG_rx_crc_direct_div  0x00000400U // [10]
#define SRT_NETX_XM_RX_CRC_CFG_rx_crc_direct_div  10          

enum {
	BFW_NETX_XM_RX_CRC_CFG_rx_crc_shift_right = 1,  // [0]
	BFW_NETX_XM_RX_CRC_CFG_rx_crc_zero        = 1,  // [1]
	BFW_NETX_XM_RX_CRC_CFG_rx_crc_invert      = 1,  // [2]
	BFW_NETX_XM_RX_CRC_CFG_rx_crc_len         = 5,  // [7:3]
	BFW_NETX_XM_RX_CRC_CFG_rx_crc_nof_bits    = 2,  // [9:8]
	BFW_NETX_XM_RX_CRC_CFG_rx_crc_direct_div  = 1,  // [10]
	BFW_NETX_XM_RX_CRC_CFG_reserved1          = 21  // [31:11]
};

typedef struct XMAC_RX_CRC_CFG_BIT_Ttag {
	unsigned int rx_crc_shift_right : BFW_NETX_XM_RX_CRC_CFG_rx_crc_shift_right; // Shift RX CRC from left to right 
	unsigned int rx_crc_zero        : BFW_NETX_XM_RX_CRC_CFG_rx_crc_zero;        // Set input of RX CRC to zero (before invert) 
	unsigned int rx_crc_invert      : BFW_NETX_XM_RX_CRC_CFG_rx_crc_invert;      // Invert input of RX CRC 
	unsigned int rx_crc_len         : BFW_NETX_XM_RX_CRC_CFG_rx_crc_len;         // Length of RX_CRC minus 1 (0-31) 
	unsigned int rx_crc_nof_bits    : BFW_NETX_XM_RX_CRC_CFG_rx_crc_nof_bits;    // 1(0),2(1),4(2),8(3) Bits from rx register to be executed in parallel 
	unsigned int rx_crc_direct_div  : BFW_NETX_XM_RX_CRC_CFG_rx_crc_direct_div;  // calculate direct polynolial division without n zeros after frame 
	unsigned int reserved1          : BFW_NETX_XM_RX_CRC_CFG_reserved1;          // reserved
} XMAC_RX_CRC_CFG_BIT_T;

typedef union {
	unsigned int          val;
	XMAC_RX_CRC_CFG_BIT_T bf;
} XMAC_RX_CRC_CFG_T;

// ---------------------------------------------------------------------
// Register xmac_tx_crc_polynomial_l
// => xMAC TX CRC Polynomial lower part
//    This register has a write pipeline delay of 1 clock cycle
//    Resetvalue : 0x00000000
// => Mode: Mode (r/w)
// ---------------------------------------------------------------------

#define REL_NETX_XM_TX_CRC_POLYNOMIAL_LO   0x000009ECU
#define NETX_XM0_TX_CRC_POLYNOMIAL_LO 0x001609ECU
#define NETX_XM1_TX_CRC_POLYNOMIAL_LO 0x001619ECU
#define NETX_XM2_TX_CRC_POLYNOMIAL_LO 0x001629ECU
#define NETX_XM3_TX_CRC_POLYNOMIAL_LO 0x001639ECU

#define MSK_NETX_XM_TX_CRC_POLYNOMIAL_LO_TX_POL_L 0x0000ffffU // [15:0]
#define SRT_NETX_XM_TX_CRC_POLYNOMIAL_LO_TX_POL_L 0           

enum {
	BFW_NETX_XM_TX_CRC_POLYNOMIAL_LO_TX_POL_L  = 16, // [15:0]
	BFW_NETX_XM_TX_CRC_POLYNOMIAL_LO_reserved1 = 16  // [31:16]
};

typedef struct XMAC_TX_CRC_POLYNOMIAL_L_BIT_Ttag {
	unsigned int TX_POL_L  : BFW_NETX_XM_TX_CRC_POLYNOMIAL_LO_TX_POL_L;  // lower bits of TX-CRC Polynomial 
	unsigned int reserved1 : BFW_NETX_XM_TX_CRC_POLYNOMIAL_LO_reserved1; // reserved
} XMAC_TX_CRC_POLYNOMIAL_L_BIT_T;

typedef union {
	unsigned int                   val;
	XMAC_TX_CRC_POLYNOMIAL_L_BIT_T bf;
} XMAC_TX_CRC_POLYNOMIAL_L_T;

// ---------------------------------------------------------------------
// Register xmac_tx_crc_polynomial_h
// => xMAC TX CRC Polynomial lower part
//    This register has a write pipeline delay of 1 clock cycle
//    Resetvalue : 0x00000000
// => Mode: Mode (r/w)
// ---------------------------------------------------------------------

#define REL_NETX_XM_TX_CRC_POLYNOMIAL_HI   0x000009F0U
#define NETX_XM0_TX_CRC_POLYNOMIAL_HI 0x001609F0U
#define NETX_XM1_TX_CRC_POLYNOMIAL_HI 0x001619F0U
#define NETX_XM2_TX_CRC_POLYNOMIAL_HI 0x001629F0U
#define NETX_XM3_TX_CRC_POLYNOMIAL_HI 0x001639F0U

#define MSK_NETX_XM_TX_CRC_POLYNOMIAL_HI_TX_POL_H 0x0000ffffU // [15:0]
#define SRT_NETX_XM_TX_CRC_POLYNOMIAL_HI_TX_POL_H 0           

enum {
	BFW_NETX_XM_TX_CRC_POLYNOMIAL_HI_TX_POL_H  = 16, // [15:0]
	BFW_NETX_XM_TX_CRC_POLYNOMIAL_HI_reserved1 = 16  // [31:16]
};

typedef struct XMAC_TX_CRC_POLYNOMIAL_H_BIT_Ttag {
	unsigned int TX_POL_H  : BFW_NETX_XM_TX_CRC_POLYNOMIAL_HI_TX_POL_H;  // upper bits of TX-CRC Polynomial 
	unsigned int reserved1 : BFW_NETX_XM_TX_CRC_POLYNOMIAL_HI_reserved1; // reserved
} XMAC_TX_CRC_POLYNOMIAL_H_BIT_T;

typedef union {
	unsigned int                   val;
	XMAC_TX_CRC_POLYNOMIAL_H_BIT_T bf;
} XMAC_TX_CRC_POLYNOMIAL_H_T;

// ---------------------------------------------------------------------
// Register xmac_tx_crc_l
// => xMAC TX CRC lower part
//    This register has a write pipeline delay of 1 clock cycle
//    Resetvalue : 0x00000000
// => Mode: Mode (r/w)
// ---------------------------------------------------------------------

#define REL_NETX_XM_TX_CRC_LO   0x000009F4U
#define NETX_XM0_TX_CRC_LO 0x001609F4U
#define NETX_XM1_TX_CRC_LO 0x001619F4U
#define NETX_XM2_TX_CRC_LO 0x001629F4U
#define NETX_XM3_TX_CRC_LO 0x001639F4U

#define MSK_NETX_XM_TX_CRC_LO_TX_CRC_L 0x0000ffffU // [15:0]
#define SRT_NETX_XM_TX_CRC_LO_TX_CRC_L 0           

enum {
	BFW_NETX_XM_TX_CRC_LO_TX_CRC_L  = 16, // [15:0]
	BFW_NETX_XM_TX_CRC_LO_reserved1 = 16  // [31:16]
};

typedef struct XMAC_TX_CRC_L_BIT_Ttag {
	unsigned int TX_CRC_L  : BFW_NETX_XM_TX_CRC_LO_TX_CRC_L;  // lower bits of TX-CRC 
	unsigned int reserved1 : BFW_NETX_XM_TX_CRC_LO_reserved1; // reserved
} XMAC_TX_CRC_L_BIT_T;

typedef union {
	unsigned int        val;
	XMAC_TX_CRC_L_BIT_T bf;
} XMAC_TX_CRC_L_T;

// ---------------------------------------------------------------------
// Register xmac_tx_crc_h
// => xMAC TX CRC upper part
//    This register has a write pipeline delay of 1 clock cycle
//    Resetvalue : 0x00000000
// => Mode: Mode (r/w)
// ---------------------------------------------------------------------

#define REL_NETX_XM_TX_CRC_HI   0x000009F8U
#define NETX_XM0_TX_CRC_HI 0x001609F8U
#define NETX_XM1_TX_CRC_HI 0x001619F8U
#define NETX_XM2_TX_CRC_HI 0x001629F8U
#define NETX_XM3_TX_CRC_HI 0x001639F8U

#define MSK_NETX_XM_TX_CRC_HI_TX_CRC_H 0x0000ffffU // [15:0]
#define SRT_NETX_XM_TX_CRC_HI_TX_CRC_H 0           

enum {
	BFW_NETX_XM_TX_CRC_HI_TX_CRC_H  = 16, // [15:0]
	BFW_NETX_XM_TX_CRC_HI_reserved1 = 16  // [31:16]
};

typedef struct XMAC_TX_CRC_H_BIT_Ttag {
	unsigned int TX_CRC_H  : BFW_NETX_XM_TX_CRC_HI_TX_CRC_H;  // upper bits of TX-CRC 
	unsigned int reserved1 : BFW_NETX_XM_TX_CRC_HI_reserved1; // reserved
} XMAC_TX_CRC_H_BIT_T;

typedef union {
	unsigned int        val;
	XMAC_TX_CRC_H_BIT_T bf;
} XMAC_TX_CRC_H_T;

// ---------------------------------------------------------------------
// Register xmac_tx_crc_cfg
// => xMAC TX CRC Config Register
//    Resetvalue : 0x00000000
// => Mode: Mode (r/w)
// ---------------------------------------------------------------------

#define REL_NETX_XM_TX_CRC_CFG   0x000009FCU
#define NETX_XM0_TX_CRC_CFG 0x001609FCU
#define NETX_XM1_TX_CRC_CFG 0x001619FCU
#define NETX_XM2_TX_CRC_CFG 0x001629FCU
#define NETX_XM3_TX_CRC_CFG 0x001639FCU

#define MSK_NETX_XM_TX_CRC_CFG_tx_crc_shift_right 0x00000001U // [0]
#define SRT_NETX_XM_TX_CRC_CFG_tx_crc_shift_right 0           
#define MSK_NETX_XM_TX_CRC_CFG_tx_crc_zero        0x00000002U // [1]
#define SRT_NETX_XM_TX_CRC_CFG_tx_crc_zero        1           
#define MSK_NETX_XM_TX_CRC_CFG_tx_crc_invert      0x00000004U // [2]
#define SRT_NETX_XM_TX_CRC_CFG_tx_crc_invert      2           
#define MSK_NETX_XM_TX_CRC_CFG_tx_crc_len         0x000000f8U // [7:3]
#define SRT_NETX_XM_TX_CRC_CFG_tx_crc_len         3           
#define MSK_NETX_XM_TX_CRC_CFG_tx_crc_nof_bits    0x00000300U // [9:8]
#define SRT_NETX_XM_TX_CRC_CFG_tx_crc_nof_bits    8           
#define MSK_NETX_XM_TX_CRC_CFG_rx_crc_direct_div  0x00000400U // [10]
#define SRT_NETX_XM_TX_CRC_CFG_rx_crc_direct_div  10          

enum {
	BFW_NETX_XM_TX_CRC_CFG_tx_crc_shift_right = 1,  // [0]
	BFW_NETX_XM_TX_CRC_CFG_tx_crc_zero        = 1,  // [1]
	BFW_NETX_XM_TX_CRC_CFG_tx_crc_invert      = 1,  // [2]
	BFW_NETX_XM_TX_CRC_CFG_tx_crc_len         = 5,  // [7:3]
	BFW_NETX_XM_TX_CRC_CFG_tx_crc_nof_bits    = 2,  // [9:8]
	BFW_NETX_XM_TX_CRC_CFG_rx_crc_direct_div  = 1,  // [10]
	BFW_NETX_XM_TX_CRC_CFG_reserved1          = 21  // [31:11]
};

typedef struct XMAC_TX_CRC_CFG_BIT_Ttag {
	unsigned int tx_crc_shift_right : BFW_NETX_XM_TX_CRC_CFG_tx_crc_shift_right; // Shift TX CRC from left to right 
	unsigned int tx_crc_zero        : BFW_NETX_XM_TX_CRC_CFG_tx_crc_zero;        // Set input of TX CRC to zero (before invert) 
	unsigned int tx_crc_invert      : BFW_NETX_XM_TX_CRC_CFG_tx_crc_invert;      // Invert input of TX CRC 
	unsigned int tx_crc_len         : BFW_NETX_XM_TX_CRC_CFG_tx_crc_len;         // Length of TX_CRC minus 1 (0-31) 
	unsigned int tx_crc_nof_bits    : BFW_NETX_XM_TX_CRC_CFG_tx_crc_nof_bits;    // 1(0),2(1),4(2),8(3) Bits from tx_register to be executed in parallel 
	unsigned int rx_crc_direct_div  : BFW_NETX_XM_TX_CRC_CFG_rx_crc_direct_div;  // calculate direct polynolial division without n zeros after frame 
	unsigned int reserved1          : BFW_NETX_XM_TX_CRC_CFG_reserved1;          // reserved
} XMAC_TX_CRC_CFG_BIT_T;

typedef union {
	unsigned int          val;
	XMAC_TX_CRC_CFG_BIT_T bf;
} XMAC_TX_CRC_CFG_T;


// =====================================================================
//
// Area of xc_mem_prot
//
// =====================================================================

#define NETX_XC_MEM_PROT	0x00164800U

// ---------------------------------------------------------------------
// Register xpec0_ram_low
// => not protected memory area (lower border)
//    Resetvalue : 0x00000000
// => Mode: Mode (r/w)
// ---------------------------------------------------------------------

#define REL_NETX_XP0_RAM_LO 0x00000000U
#define NETX_XP0_RAM_LO     0x00164800U

#define MSK_NETX_XP0_RAM_LO_xpec0_ram_low 0x00001fffU // [12:0]
#define SRT_NETX_XP0_RAM_LO_xpec0_ram_low 0           

enum {
	BFW_NETX_XP0_RAM_LO_xpec0_ram_low = 13, // [12:0]
	BFW_NETX_XP0_RAM_LO_reserved1     = 19  // [31:13]
};

typedef struct XPEC0_RAM_LOW_BIT_Ttag {
	unsigned int xpec0_ram_low : BFW_NETX_XP0_RAM_LO_xpec0_ram_low; //  lower border (include) of not protected memory area 
	unsigned int reserved1     : BFW_NETX_XP0_RAM_LO_reserved1;     // reserved
} XPEC0_RAM_LOW_BIT_T;

typedef union {
	unsigned int        val;
	XPEC0_RAM_LOW_BIT_T bf;
} XPEC0_RAM_LOW_T;

// ---------------------------------------------------------------------
// Register xpec1_ram_low
// => not protected memory area (lower border)
//    Resetvalue : 0x00000000
// => Mode: Mode (r/w)
// ---------------------------------------------------------------------

#define REL_NETX_XP1_RAM_LO 0x00000004U
#define NETX_XP1_RAM_LO     0x00164804U

#define MSK_NETX_XP1_RAM_LO_xpec1_ram_low 0x00001fffU // [12:0]
#define SRT_NETX_XP1_RAM_LO_xpec1_ram_low 0           

enum {
	BFW_NETX_XP1_RAM_LO_xpec1_ram_low = 13, // [12:0]
	BFW_NETX_XP1_RAM_LO_reserved1     = 19  // [31:13]
};

typedef struct XPEC1_RAM_LOW_BIT_Ttag {
	unsigned int xpec1_ram_low : BFW_NETX_XP1_RAM_LO_xpec1_ram_low; //  lower border (include) of not protected memory area 
	unsigned int reserved1     : BFW_NETX_XP1_RAM_LO_reserved1;     // reserved
} XPEC1_RAM_LOW_BIT_T;

typedef union {
	unsigned int        val;
	XPEC1_RAM_LOW_BIT_T bf;
} XPEC1_RAM_LOW_T;

// ---------------------------------------------------------------------
// Register xpec2_ram_low
// => not protected memory area (lower border)
//    Resetvalue : 0x00000000
// => Mode: Mode (r/w)
// ---------------------------------------------------------------------

#define REL_NETX_XP2_RAM_LO 0x00000008U
#define NETX_XP2_RAM_LO     0x00164808U

#define MSK_NETX_XP2_RAM_LO_xpec2_ram_low 0x00001fffU // [12:0]
#define SRT_NETX_XP2_RAM_LO_xpec2_ram_low 0           

enum {
	BFW_NETX_XP2_RAM_LO_xpec2_ram_low = 13, // [12:0]
	BFW_NETX_XP2_RAM_LO_reserved1     = 19  // [31:13]
};

typedef struct XPEC2_RAM_LOW_BIT_Ttag {
	unsigned int xpec2_ram_low : BFW_NETX_XP2_RAM_LO_xpec2_ram_low; //  lower border (include) of not protected memory area 
	unsigned int reserved1     : BFW_NETX_XP2_RAM_LO_reserved1;     // reserved
} XPEC2_RAM_LOW_BIT_T;

typedef union {
	unsigned int        val;
	XPEC2_RAM_LOW_BIT_T bf;
} XPEC2_RAM_LOW_T;

// ---------------------------------------------------------------------
// Register xpec3_ram_low
// => not protected memory area (lower border)
//    Resetvalue : 0x00000000
// => Mode: Mode (r/w)
// ---------------------------------------------------------------------

#define REL_NETX_XP3_RAM_LO 0x0000000CU
#define NETX_XP3_RAM_LO     0x0016480CU

#define MSK_NETX_XP3_RAM_LO_xpec3_ram_low 0x00001fffU // [12:0]
#define SRT_NETX_XP3_RAM_LO_xpec3_ram_low 0           

enum {
	BFW_NETX_XP3_RAM_LO_xpec3_ram_low = 13, // [12:0]
	BFW_NETX_XP3_RAM_LO_reserved1     = 19  // [31:13]
};

typedef struct XPEC3_RAM_LOW_BIT_Ttag {
	unsigned int xpec3_ram_low : BFW_NETX_XP3_RAM_LO_xpec3_ram_low; //  lower border (include) of not protected memory area 
	unsigned int reserved1     : BFW_NETX_XP3_RAM_LO_reserved1;     // reserved
} XPEC3_RAM_LOW_BIT_T;

typedef union {
	unsigned int        val;
	XPEC3_RAM_LOW_BIT_T bf;
} XPEC3_RAM_LOW_T;

// ---------------------------------------------------------------------
// Register xpec0_ram_high
// => not protected memory area (higher border)
//    Resetvalue : 0x00000000
// => Mode: Mode (r/w)
// ---------------------------------------------------------------------

#define REL_NETX_XP0_RAM_HI 0x00000010U
#define NETX_XP0_RAM_HI     0x00164810U

#define MSK_NETX_XP0_RAM_HI_xpec0_ram_high 0x00001fffU // [12:0]
#define SRT_NETX_XP0_RAM_HI_xpec0_ram_high 0           

enum {
	BFW_NETX_XP0_RAM_HI_xpec0_ram_high = 13, // [12:0]
	BFW_NETX_XP0_RAM_HI_reserved1      = 19  // [31:13]
};

typedef struct XPEC0_RAM_HIGH_BIT_Ttag {
	unsigned int xpec0_ram_high : BFW_NETX_XP0_RAM_HI_xpec0_ram_high; //  higher border(include) of not protected memory area 
	unsigned int reserved1      : BFW_NETX_XP0_RAM_HI_reserved1;      // reserved
} XPEC0_RAM_HIGH_BIT_T;

typedef union {
	unsigned int         val;
	XPEC0_RAM_HIGH_BIT_T bf;
} XPEC0_RAM_HIGH_T;

// ---------------------------------------------------------------------
// Register xpec1_ram_high
// => not protected memory area (higher border)
//    Resetvalue : 0x00000000
// => Mode: Mode (r/w)
// ---------------------------------------------------------------------

#define REL_NETX_XP1_RAM_HI 0x00000014U
#define NETX_XP1_RAM_HI     0x00164814U

#define MSK_NETX_XP1_RAM_HI_xpec1_ram_high 0x00001fffU // [12:0]
#define SRT_NETX_XP1_RAM_HI_xpec1_ram_high 0           

enum {
	BFW_NETX_XP1_RAM_HI_xpec1_ram_high = 13, // [12:0]
	BFW_NETX_XP1_RAM_HI_reserved1      = 19  // [31:13]
};

typedef struct XPEC1_RAM_HIGH_BIT_Ttag {
	unsigned int xpec1_ram_high : BFW_NETX_XP1_RAM_HI_xpec1_ram_high; //  higher border(include) of not protected memory area 
	unsigned int reserved1      : BFW_NETX_XP1_RAM_HI_reserved1;      // reserved
} XPEC1_RAM_HIGH_BIT_T;

typedef union {
	unsigned int         val;
	XPEC1_RAM_HIGH_BIT_T bf;
} XPEC1_RAM_HIGH_T;

// ---------------------------------------------------------------------
// Register xpec2_ram_high
// => not protected memory area (higher border)
//    Resetvalue : 0x00000000
// => Mode: Mode (r/w)
// ---------------------------------------------------------------------

#define REL_NETX_XP2_RAM_HI 0x00000018U
#define NETX_XP2_RAM_HI     0x00164818U

#define MSK_NETX_XP2_RAM_HI_xpec2_ram_high 0x00001fffU // [12:0]
#define SRT_NETX_XP2_RAM_HI_xpec2_ram_high 0           

enum {
	BFW_NETX_XP2_RAM_HI_xpec2_ram_high = 13, // [12:0]
	BFW_NETX_XP2_RAM_HI_reserved1      = 19  // [31:13]
};

typedef struct XPEC2_RAM_HIGH_BIT_Ttag {
	unsigned int xpec2_ram_high : BFW_NETX_XP2_RAM_HI_xpec2_ram_high; //  higher border(include) of not protected memory area 
	unsigned int reserved1      : BFW_NETX_XP2_RAM_HI_reserved1;      // reserved
} XPEC2_RAM_HIGH_BIT_T;

typedef union {
	unsigned int         val;
	XPEC2_RAM_HIGH_BIT_T bf;
} XPEC2_RAM_HIGH_T;

// ---------------------------------------------------------------------
// Register xpec3_ram_high
// => not protected memory area (higher border)
//    Resetvalue : 0x00000000
// => Mode: Mode (r/w)
// ---------------------------------------------------------------------

#define REL_NETX_XP3_RAM_HI 0x0000001CU
#define NETX_XP3_RAM_HI     0x0016481CU

#define MSK_NETX_XP3_RAM_HI_xpec3_ram_high 0x00001fffU // [12:0]
#define SRT_NETX_XP3_RAM_HI_xpec3_ram_high 0           

enum {
	BFW_NETX_XP3_RAM_HI_xpec3_ram_high = 13, // [12:0]
	BFW_NETX_XP3_RAM_HI_reserved1      = 19  // [31:13]
};

typedef struct XPEC3_RAM_HIGH_BIT_Ttag {
	unsigned int xpec3_ram_high : BFW_NETX_XP3_RAM_HI_xpec3_ram_high; //  higher border(include) of not protected memory area 
	unsigned int reserved1      : BFW_NETX_XP3_RAM_HI_reserved1;      // reserved
} XPEC3_RAM_HIGH_BIT_T;

typedef union {
	unsigned int         val;
	XPEC3_RAM_HIGH_BIT_T bf;
} XPEC3_RAM_HIGH_T;

// ---------------------------------------------------------------------
// Register prot_key_enable
// => protection key enable
//    Resetvalue : 0x00000000
// => Mode: Mode (r/w)
// ---------------------------------------------------------------------

#define REL_NETX_XC_PROT_KEY_EN 0x00000100U
#define NETX_XC_PROT_KEY_EN     0x00164900U

#define MSK_NETX_XC_PROT_KEY_EN_prot_key_enable 0xffffffffU // [31:0]
#define SRT_NETX_XC_PROT_KEY_EN_prot_key_enable 0           

enum {
	BFW_NETX_XC_PROT_KEY_EN_prot_key_enable = 32  // [31:0]
};

typedef struct PROT_KEY_ENABLE_BIT_Ttag {
	unsigned int prot_key_enable : BFW_NETX_XC_PROT_KEY_EN_prot_key_enable; //  1. Read out the access key from this register. 2. Write back this access key to this register. 3. Memory protection is enable. 
} PROT_KEY_ENABLE_BIT_T;

typedef union {
	unsigned int          val;
	PROT_KEY_ENABLE_BIT_T bf;
} PROT_KEY_ENABLE_T;

// ---------------------------------------------------------------------
// Register prot_key_disable
// => protection key disable
//    Resetvalue : 0x00000000
// => Mode: Mode (r/w)
// ---------------------------------------------------------------------

#define REL_NETX_XC_PROT_KEY_DIS 0x00000104U
#define NETX_XC_PROT_KEY_DIS     0x00164904U

#define MSK_NETX_XC_PROT_KEY_DIS_prot_key_disable 0xffffffffU // [31:0]
#define SRT_NETX_XC_PROT_KEY_DIS_prot_key_disable 0           

enum {
	BFW_NETX_XC_PROT_KEY_DIS_prot_key_disable = 32  // [31:0]
};

typedef struct PROT_KEY_DISABLE_BIT_Ttag {
	unsigned int prot_key_disable : BFW_NETX_XC_PROT_KEY_DIS_prot_key_disable; //  1. Read out the access key from this register. 2. Write back this access key to this register. 3. Memory protection is disable. 
} PROT_KEY_DISABLE_BIT_T;

typedef union {
	unsigned int           val;
	PROT_KEY_DISABLE_BIT_T bf;
} PROT_KEY_DISABLE_T;

// ---------------------------------------------------------------------
// Register prot_status
// => protection status
//    Resetvalue : 0x00000000
// => Mode: Mode (r)
// ---------------------------------------------------------------------

#define REL_NETX_XC_PROT_STAT 0x00000108U
#define NETX_XC_PROT_STAT     0x00164908U

#define MSK_NETX_XC_PROT_STAT_prot_stauts 0x00000001U // [0]
#define SRT_NETX_XC_PROT_STAT_prot_stauts 0           

enum {
	BFW_NETX_XC_PROT_STAT_prot_stauts = 1,  // [0]
	BFW_NETX_XC_PROT_STAT_reserved1   = 31  // [31:1]
};

typedef struct PROT_STATUS_BIT_Ttag {
	unsigned int prot_stauts : BFW_NETX_XC_PROT_STAT_prot_stauts; //  Protection Status (read only) 1: protection mode 0: not protected 
	unsigned int reserved1   : BFW_NETX_XC_PROT_STAT_reserved1;   // reserved
} PROT_STATUS_BIT_T;

typedef union {
	unsigned int      val;
	PROT_STATUS_BIT_T bf;
} PROT_STATUS_T;


// =====================================================================
//
// Area of xc_debug
//
// =====================================================================

#define NETX_XC_DBG	0x00164C00U

// ---------------------------------------------------------------------
// Register xc_debug_config
// => config XC debug module
//    Resetvalue : 0x00000000
// => Mode: Mode (r/w)
// ---------------------------------------------------------------------

#define REL_NETX_XC_DBG_CFG 0x00000000U
#define NETX_XC_DBG_CFG     0x00164C00U

#define MSK_NETX_XC_DBG_CFG_select_xpec  0x00000003U // [1:0]
#define SRT_NETX_XC_DBG_CFG_select_xpec  0           
#define MSK_NETX_XC_DBG_CFG_debug_enable 0x80000000U // [31]
#define SRT_NETX_XC_DBG_CFG_debug_enable 31          

enum {
	BFW_NETX_XC_DBG_CFG_select_xpec  = 2,  // [1:0]
	BFW_NETX_XC_DBG_CFG_reserved1    = 29, // [30:2]
	BFW_NETX_XC_DBG_CFG_debug_enable = 1   // [31]
};

typedef struct XC_DEBUG_CONFIG_BIT_Ttag {
	unsigned int select_xpec  : BFW_NETX_XC_DBG_CFG_select_xpec;  //  (00 = xpec0, 01 = xpec1, 10 = xpec2, 11 = xpec3) default 0x0
	unsigned int reserved1    : BFW_NETX_XC_DBG_CFG_reserved1;    // reserved
	unsigned int debug_enable : BFW_NETX_XC_DBG_CFG_debug_enable; // default 0x0
} XC_DEBUG_CONFIG_BIT_T;

typedef union {
	unsigned int          val;
	XC_DEBUG_CONFIG_BIT_T bf;
} XC_DEBUG_CONFIG_T;


// =====================================================================
//
// Area of xpec0, xpec1, xpec2, xpec3
//
// =====================================================================

#define NETX_XP0_BASE	0x00170000U
#define NETX_XP1_BASE	0x00174000U
#define NETX_XP2_BASE	0x00178000U
#define NETX_XP3_BASE	0x0017C000U

// ---------------------------------------------------------------------
// Register ram_start
// => 
// => Mode: 
// ---------------------------------------------------------------------

#define REL_NETX_XP_RAM_START   0x00002000U
#define NETX_XP0_RAM_START 0x00172000U
#define NETX_XP1_RAM_START 0x00176000U
#define NETX_XP2_RAM_START 0x0017A000U
#define NETX_XP3_RAM_START 0x0017E000U

// ---------------------------------------------------------------------
// Register xpu_hold_pc
// => xPEC hold_pc register
//    Resetvalue : 0x00000001
// => Mode: Mode (r/w)
// ---------------------------------------------------------------------

#define REL_NETX_XP_HOLD_PC   0x00000100U
#define NETX_XP0_HOLD_PC 0x00170100U
#define NETX_XP1_HOLD_PC 0x00174100U
#define NETX_XP2_HOLD_PC 0x00178100U
#define NETX_XP3_HOLD_PC 0x0017C100U

#define MSK_NETX_XP_HOLD_PC_hold 0x00000001U // [0]
#define SRT_NETX_XP_HOLD_PC_hold 0           

enum {
	BFW_NETX_XP_HOLD_PC_hold      = 1,  // [0]
	BFW_NETX_XP_HOLD_PC_reserved1 = 31  // [31:1]
};

typedef struct XPU_HOLD_PC_BIT_Ttag {
	unsigned int hold      : BFW_NETX_XP_HOLD_PC_hold;      // 0: start XPU, 1: hold XPU 
	                                                        // only accessible by the ARM
	unsigned int reserved1 : BFW_NETX_XP_HOLD_PC_reserved1; // reserved
} XPU_HOLD_PC_BIT_T;

typedef union {
	unsigned int      val;
	XPU_HOLD_PC_BIT_T bf;
} XPU_HOLD_PC_T;

// ---------------------------------------------------------------------
// Register xpec_r0
// => xPEC work register for indirect addressing
//    Resetvalue : 0x00000000
// => Mode: Mode (r/w)
// ---------------------------------------------------------------------

#define REL_NETX_XP_R0   0x00000000U
#define NETX_XP0_R0 0x00170000U
#define NETX_XP1_R0 0x00174000U
#define NETX_XP2_R0 0x00178000U
#define NETX_XP3_R0 0x0017C000U

#define MSK_NETX_XP_R0_r0 0xffffffffU // [31:0]
#define SRT_NETX_XP_R0_r0 0           

enum {
	BFW_NETX_XP_R0_r0 = 32  // [31:0]
};

typedef struct XPEC_R0_BIT_Ttag {
	unsigned int r0 : BFW_NETX_XP_R0_r0; // Work Register 0 
} XPEC_R0_BIT_T;

typedef union {
	unsigned int  val;
	XPEC_R0_BIT_T bf;
} XPEC_R0_T;

// ---------------------------------------------------------------------
// Register xpec_r1
// => xPEC work register for indirect addressing
//    Resetvalue : 0x00000000
// => Mode: Mode (r/w)
// ---------------------------------------------------------------------

#define REL_NETX_XP_R1   0x00000004U
#define NETX_XP0_R1 0x00170004U
#define NETX_XP1_R1 0x00174004U
#define NETX_XP2_R1 0x00178004U
#define NETX_XP3_R1 0x0017C004U

#define MSK_NETX_XP_R1_r1 0xffffffffU // [31:0]
#define SRT_NETX_XP_R1_r1 0           

enum {
	BFW_NETX_XP_R1_r1 = 32  // [31:0]
};

typedef struct XPEC_R1_BIT_Ttag {
	unsigned int r1 : BFW_NETX_XP_R1_r1; // Work Register 1 
} XPEC_R1_BIT_T;

typedef union {
	unsigned int  val;
	XPEC_R1_BIT_T bf;
} XPEC_R1_T;

// ---------------------------------------------------------------------
// Register xpec_r2
// => xPEC work register for indirect addressing
//    Resetvalue : 0x00000000
// => Mode: Mode (r/w)
// ---------------------------------------------------------------------

#define REL_NETX_XP_R2   0x00000008U
#define NETX_XP0_R2 0x00170008U
#define NETX_XP1_R2 0x00174008U
#define NETX_XP2_R2 0x00178008U
#define NETX_XP3_R2 0x0017C008U

#define MSK_NETX_XP_R2_r2 0xffffffffU // [31:0]
#define SRT_NETX_XP_R2_r2 0           

enum {
	BFW_NETX_XP_R2_r2 = 32  // [31:0]
};

typedef struct XPEC_R2_BIT_Ttag {
	unsigned int r2 : BFW_NETX_XP_R2_r2; // Work Register 2 
} XPEC_R2_BIT_T;

typedef union {
	unsigned int  val;
	XPEC_R2_BIT_T bf;
} XPEC_R2_T;

// ---------------------------------------------------------------------
// Register xpec_r3
// => xPEC work register for indirect addressing
//    Resetvalue : 0x00000000
// => Mode: Mode (r/w)
// ---------------------------------------------------------------------

#define REL_NETX_XP_R3   0x0000000CU
#define NETX_XP0_R3 0x0017000CU
#define NETX_XP1_R3 0x0017400CU
#define NETX_XP2_R3 0x0017800CU
#define NETX_XP3_R3 0x0017C00CU

#define MSK_NETX_XP_R3_r3 0xffffffffU // [31:0]
#define SRT_NETX_XP_R3_r3 0           

enum {
	BFW_NETX_XP_R3_r3 = 32  // [31:0]
};

typedef struct XPEC_R3_BIT_Ttag {
	unsigned int r3 : BFW_NETX_XP_R3_r3; // Work Register 3 
} XPEC_R3_BIT_T;

typedef union {
	unsigned int  val;
	XPEC_R3_BIT_T bf;
} XPEC_R3_T;

// ---------------------------------------------------------------------
// Register xpec_r4
// => xPEC work register for indirect addressing
//    Resetvalue : 0x00000000
// => Mode: Mode (r/w)
// ---------------------------------------------------------------------

#define REL_NETX_XP_R4   0x00000010U
#define NETX_XP0_R4 0x00170010U
#define NETX_XP1_R4 0x00174010U
#define NETX_XP2_R4 0x00178010U
#define NETX_XP3_R4 0x0017C010U

#define MSK_NETX_XP_R4_r4 0xffffffffU // [31:0]
#define SRT_NETX_XP_R4_r4 0           

enum {
	BFW_NETX_XP_R4_r4 = 32  // [31:0]
};

typedef struct XPEC_R4_BIT_Ttag {
	unsigned int r4 : BFW_NETX_XP_R4_r4; // Work Register 4 
} XPEC_R4_BIT_T;

typedef union {
	unsigned int  val;
	XPEC_R4_BIT_T bf;
} XPEC_R4_T;

// ---------------------------------------------------------------------
// Register xpec_r5
// => xPEC work register for indirect addressing
//    Resetvalue : 0x00000000
// => Mode: Mode (r/w)
// ---------------------------------------------------------------------

#define REL_NETX_XP_R5   0x00000014U
#define NETX_XP0_R5 0x00170014U
#define NETX_XP1_R5 0x00174014U
#define NETX_XP2_R5 0x00178014U
#define NETX_XP3_R5 0x0017C014U

#define MSK_NETX_XP_R5_r5 0xffffffffU // [31:0]
#define SRT_NETX_XP_R5_r5 0           

enum {
	BFW_NETX_XP_R5_r5 = 32  // [31:0]
};

typedef struct XPEC_R5_BIT_Ttag {
	unsigned int r5 : BFW_NETX_XP_R5_r5; // Work Register 5 
} XPEC_R5_BIT_T;

typedef union {
	unsigned int  val;
	XPEC_R5_BIT_T bf;
} XPEC_R5_T;

// ---------------------------------------------------------------------
// Register xpec_r6
// => xPEC work register for indirect addressing
//    Resetvalue : 0x00000000
// => Mode: Mode (r/w)
// ---------------------------------------------------------------------

#define REL_NETX_XP_R6   0x00000018U
#define NETX_XP0_R6 0x00170018U
#define NETX_XP1_R6 0x00174018U
#define NETX_XP2_R6 0x00178018U
#define NETX_XP3_R6 0x0017C018U

#define MSK_NETX_XP_R6_r6 0xffffffffU // [31:0]
#define SRT_NETX_XP_R6_r6 0           

enum {
	BFW_NETX_XP_R6_r6 = 32  // [31:0]
};

typedef struct XPEC_R6_BIT_Ttag {
	unsigned int r6 : BFW_NETX_XP_R6_r6; // Work Register 6 
} XPEC_R6_BIT_T;

typedef union {
	unsigned int  val;
	XPEC_R6_BIT_T bf;
} XPEC_R6_T;

// ---------------------------------------------------------------------
// Register xpec_r7
// => xPEC work register for indirect addressing
//    Resetvalue : 0x00000000
// => Mode: Mode (r/w)
// ---------------------------------------------------------------------

#define REL_NETX_XP_R7   0x0000001CU
#define NETX_XP0_R7 0x0017001CU
#define NETX_XP1_R7 0x0017401CU
#define NETX_XP2_R7 0x0017801CU
#define NETX_XP3_R7 0x0017C01CU

#define MSK_NETX_XP_R7_r7 0xffffffffU // [31:0]
#define SRT_NETX_XP_R7_r7 0           

enum {
	BFW_NETX_XP_R7_r7 = 32  // [31:0]
};

typedef struct XPEC_R7_BIT_Ttag {
	unsigned int r7 : BFW_NETX_XP_R7_r7; // Work Register 7 
} XPEC_R7_BIT_T;

typedef union {
	unsigned int  val;
	XPEC_R7_BIT_T bf;
} XPEC_R7_T;

// ---------------------------------------------------------------------
// Register range01
// => xPEC Overflow Underflow register to limit stack and fifo buffer.
//    Generates range bits inside xPEC status register
//    Resetvalue : 0x00000000
// => Mode: Mode (r/w)
// ---------------------------------------------------------------------

#define REL_NETX_XP_RANGE_01   0x00000020U
#define NETX_XP0_RANGE_01 0x00170020U
#define NETX_XP1_RANGE_01 0x00174020U
#define NETX_XP2_RANGE_01 0x00178020U
#define NETX_XP3_RANGE_01 0x0017C020U

#define MSK_NETX_XP_RANGE_01_range0  0x00001fffU // [12:0]
#define SRT_NETX_XP_RANGE_01_range0  0           
#define MSK_NETX_XP_RANGE_01_bigger0 0x00002000U // [13]
#define SRT_NETX_XP_RANGE_01_bigger0 13          
#define MSK_NETX_XP_RANGE_01_range1  0x1fff0000U // [28:16]
#define SRT_NETX_XP_RANGE_01_range1  16          
#define MSK_NETX_XP_RANGE_01_bigger1 0x20000000U // [29]
#define SRT_NETX_XP_RANGE_01_bigger1 29          

enum {
	BFW_NETX_XP_RANGE_01_range0    = 13, // [12:0]
	BFW_NETX_XP_RANGE_01_bigger0   = 1,  // [13]
	BFW_NETX_XP_RANGE_01_reserved1 = 2,  // [15:14]
	BFW_NETX_XP_RANGE_01_range1    = 13, // [28:16]
	BFW_NETX_XP_RANGE_01_bigger1   = 1,  // [29]
	BFW_NETX_XP_RANGE_01_reserved2 = 2   // [31:30]
};

typedef struct RANGE01_BIT_Ttag {
	unsigned int range0    : BFW_NETX_XP_RANGE_01_range0;    // border for xpec_r0 
	unsigned int bigger0   : BFW_NETX_XP_RANGE_01_bigger0;   // 0: generate range status bit, if r0 < range0; 1: generate range status bit, if r0 >= range0 
	unsigned int reserved1 : BFW_NETX_XP_RANGE_01_reserved1; // reserved
	unsigned int range1    : BFW_NETX_XP_RANGE_01_range1;    // border for xpec_r1 
	unsigned int bigger1   : BFW_NETX_XP_RANGE_01_bigger1;   // 0: generate range status bit, if r1 < range1; 1: generate range status bit, if r1 >= range1 
	unsigned int reserved2 : BFW_NETX_XP_RANGE_01_reserved2; // reserved
} RANGE01_BIT_T;

typedef union {
	unsigned int  val;
	RANGE01_BIT_T bf;
} RANGE01_T;

// ---------------------------------------------------------------------
// Register range23
// => xPEC Overflow Underflow register to limit stack and fifo buffer.
//    Generates range bits inside xPEC status register
//    Resetvalue : 0x00000000
// => Mode: Mode (r/w)
// ---------------------------------------------------------------------

#define REL_NETX_XP_RANGE_23   0x00000024U
#define NETX_XP0_RANGE_23 0x00170024U
#define NETX_XP1_RANGE_23 0x00174024U
#define NETX_XP2_RANGE_23 0x00178024U
#define NETX_XP3_RANGE_23 0x0017C024U

#define MSK_NETX_XP_RANGE_23_range2  0x00001fffU // [12:0]
#define SRT_NETX_XP_RANGE_23_range2  0           
#define MSK_NETX_XP_RANGE_23_bigger2 0x00002000U // [13]
#define SRT_NETX_XP_RANGE_23_bigger2 13          
#define MSK_NETX_XP_RANGE_23_range3  0x1fff0000U // [28:16]
#define SRT_NETX_XP_RANGE_23_range3  16          
#define MSK_NETX_XP_RANGE_23_bigger3 0x20000000U // [29]
#define SRT_NETX_XP_RANGE_23_bigger3 29          

enum {
	BFW_NETX_XP_RANGE_23_range2    = 13, // [12:0]
	BFW_NETX_XP_RANGE_23_bigger2   = 1,  // [13]
	BFW_NETX_XP_RANGE_23_reserved1 = 2,  // [15:14]
	BFW_NETX_XP_RANGE_23_range3    = 13, // [28:16]
	BFW_NETX_XP_RANGE_23_bigger3   = 1,  // [29]
	BFW_NETX_XP_RANGE_23_reserved2 = 2   // [31:30]
};

typedef struct RANGE23_BIT_Ttag {
	unsigned int range2    : BFW_NETX_XP_RANGE_23_range2;    // border for xpec_r2 
	unsigned int bigger2   : BFW_NETX_XP_RANGE_23_bigger2;   // 0: generate range status bit, if r2 < range2; 1: generate range status bit, if r2 >= range2 
	unsigned int reserved1 : BFW_NETX_XP_RANGE_23_reserved1; // reserved
	unsigned int range3    : BFW_NETX_XP_RANGE_23_range3;    // border for xpec_r3 
	unsigned int bigger3   : BFW_NETX_XP_RANGE_23_bigger3;   // 0: generate range status bit, if r3 < range3; 1: generate range status bit, if r3 >= range3 
	unsigned int reserved2 : BFW_NETX_XP_RANGE_23_reserved2; // reserved
} RANGE23_BIT_T;

typedef union {
	unsigned int  val;
	RANGE23_BIT_T bf;
} RANGE23_T;

// ---------------------------------------------------------------------
// Register range45
// => xPEC Overflow Underflow register to limit stack and fifo buffer.
//    Generates range bits inside xPEC status register
//    Resetvalue : 0x00000000
// => Mode: Mode (r/w)
// ---------------------------------------------------------------------

#define REL_NETX_XP_RANGE_45   0x00000028U
#define NETX_XP0_RANGE_45 0x00170028U
#define NETX_XP1_RANGE_45 0x00174028U
#define NETX_XP2_RANGE_45 0x00178028U
#define NETX_XP3_RANGE_45 0x0017C028U

#define MSK_NETX_XP_RANGE_45_range4  0x00001fffU // [12:0]
#define SRT_NETX_XP_RANGE_45_range4  0           
#define MSK_NETX_XP_RANGE_45_bigger4 0x00002000U // [13]
#define SRT_NETX_XP_RANGE_45_bigger4 13          
#define MSK_NETX_XP_RANGE_45_range5  0x1fff0000U // [28:16]
#define SRT_NETX_XP_RANGE_45_range5  16          
#define MSK_NETX_XP_RANGE_45_bigger5 0x20000000U // [29]
#define SRT_NETX_XP_RANGE_45_bigger5 29          

enum {
	BFW_NETX_XP_RANGE_45_range4    = 13, // [12:0]
	BFW_NETX_XP_RANGE_45_bigger4   = 1,  // [13]
	BFW_NETX_XP_RANGE_45_reserved1 = 2,  // [15:14]
	BFW_NETX_XP_RANGE_45_range5    = 13, // [28:16]
	BFW_NETX_XP_RANGE_45_bigger5   = 1,  // [29]
	BFW_NETX_XP_RANGE_45_reserved2 = 2   // [31:30]
};

typedef struct RANGE45_BIT_Ttag {
	unsigned int range4    : BFW_NETX_XP_RANGE_45_range4;    // border for xpec_r4 
	unsigned int bigger4   : BFW_NETX_XP_RANGE_45_bigger4;   // 0: generate range status bit, if r4 < range4; 1: generate range status bit, if r4 >= range4 
	unsigned int reserved1 : BFW_NETX_XP_RANGE_45_reserved1; // reserved
	unsigned int range5    : BFW_NETX_XP_RANGE_45_range5;    // border for xpec_r5 
	unsigned int bigger5   : BFW_NETX_XP_RANGE_45_bigger5;   // 0: generate range status bit, if r5 < range5; 1: generate range status bit, if r5 >= range5 
	unsigned int reserved2 : BFW_NETX_XP_RANGE_45_reserved2; // reserved
} RANGE45_BIT_T;

typedef union {
	unsigned int  val;
	RANGE45_BIT_T bf;
} RANGE45_T;

// ---------------------------------------------------------------------
// Register range67
// => xPEC Overflow Underflow register to limit stack and fifo buffer.
//    Generates range bits inside xPEC status register
//    Resetvalue : 0x00000000
// => Mode: Mode (r/w)
// ---------------------------------------------------------------------

#define REL_NETX_XP_RANGE_67   0x0000002CU
#define NETX_XP0_RANGE_67 0x0017002CU
#define NETX_XP1_RANGE_67 0x0017402CU
#define NETX_XP2_RANGE_67 0x0017802CU
#define NETX_XP3_RANGE_67 0x0017C02CU

#define MSK_NETX_XP_RANGE_67_range6  0x00001fffU // [12:0]
#define SRT_NETX_XP_RANGE_67_range6  0           
#define MSK_NETX_XP_RANGE_67_bigger6 0x00002000U // [13]
#define SRT_NETX_XP_RANGE_67_bigger6 13          
#define MSK_NETX_XP_RANGE_67_range7  0x1fff0000U // [28:16]
#define SRT_NETX_XP_RANGE_67_range7  16          
#define MSK_NETX_XP_RANGE_67_bigger7 0x20000000U // [29]
#define SRT_NETX_XP_RANGE_67_bigger7 29          

enum {
	BFW_NETX_XP_RANGE_67_range6    = 13, // [12:0]
	BFW_NETX_XP_RANGE_67_bigger6   = 1,  // [13]
	BFW_NETX_XP_RANGE_67_reserved1 = 2,  // [15:14]
	BFW_NETX_XP_RANGE_67_range7    = 13, // [28:16]
	BFW_NETX_XP_RANGE_67_bigger7   = 1,  // [29]
	BFW_NETX_XP_RANGE_67_reserved2 = 2   // [31:30]
};

typedef struct RANGE67_BIT_Ttag {
	unsigned int range6    : BFW_NETX_XP_RANGE_67_range6;    // border for xpec_r6 
	unsigned int bigger6   : BFW_NETX_XP_RANGE_67_bigger6;   // 0: generate range status bit, if r6 < range6; 1: generate range status bit, if r6 >= range6 
	unsigned int reserved1 : BFW_NETX_XP_RANGE_67_reserved1; // reserved
	unsigned int range7    : BFW_NETX_XP_RANGE_67_range7;    // border for xpec_r7 
	unsigned int bigger7   : BFW_NETX_XP_RANGE_67_bigger7;   // 0: generate range status bit, if r7 < range7; 1: generate range status bit, if r7 >= range7 
	unsigned int reserved2 : BFW_NETX_XP_RANGE_67_reserved2; // reserved
} RANGE67_BIT_T;

typedef union {
	unsigned int  val;
	RANGE67_BIT_T bf;
} RANGE67_T;

// ---------------------------------------------------------------------
// Register timer0
// => xPEC Timer 0
//    Resetvalue : 0x00000000
// => Mode: Mode (r/w)
// ---------------------------------------------------------------------

#define REL_NETX_XP_TMR0   0x00000030U
#define NETX_XP0_TMR0 0x00170030U
#define NETX_XP1_TMR0 0x00174030U
#define NETX_XP2_TMR0 0x00178030U
#define NETX_XP3_TMR0 0x0017C030U

#define MSK_NETX_XP_TMR0_preload0 0xffffffffU // [31:0]
#define SRT_NETX_XP_TMR0_preload0 0           

enum {
	BFW_NETX_XP_TMR0_preload0 = 32  // [31:0]
};

typedef struct TIMER0_BIT_Ttag {
	unsigned int preload0 : BFW_NETX_XP_TMR0_preload0; // read: actual value of timer, write: timer and preload value 
} TIMER0_BIT_T;

typedef union {
	unsigned int val;
	TIMER0_BIT_T bf;
} TIMER0_T;

// ---------------------------------------------------------------------
// Register timer1
// => xPEC Timer 1
//    Resetvalue : 0x00000000
// => Mode: Mode (r/w)
// ---------------------------------------------------------------------

#define REL_NETX_XP_TMR1   0x00000034U
#define NETX_XP0_TMR1 0x00170034U
#define NETX_XP1_TMR1 0x00174034U
#define NETX_XP2_TMR1 0x00178034U
#define NETX_XP3_TMR1 0x0017C034U

#define MSK_NETX_XP_TMR1_preload1 0xffffffffU // [31:0]
#define SRT_NETX_XP_TMR1_preload1 0           

enum {
	BFW_NETX_XP_TMR1_preload1 = 32  // [31:0]
};

typedef struct TIMER1_BIT_Ttag {
	unsigned int preload1 : BFW_NETX_XP_TMR1_preload1; // read: actual value of timer, write: timer and preload value 
} TIMER1_BIT_T;

typedef union {
	unsigned int val;
	TIMER1_BIT_T bf;
} TIMER1_T;

// ---------------------------------------------------------------------
// Register timer2
// => xPEC Timer 2
//    Resetvalue : 0x00000000
// => Mode: Mode (r/w)
// ---------------------------------------------------------------------

#define REL_NETX_XP_TMR2   0x00000038U
#define NETX_XP0_TMR2 0x00170038U
#define NETX_XP1_TMR2 0x00174038U
#define NETX_XP2_TMR2 0x00178038U
#define NETX_XP3_TMR2 0x0017C038U

#define MSK_NETX_XP_TMR2_preload2 0xffffffffU // [31:0]
#define SRT_NETX_XP_TMR2_preload2 0           

enum {
	BFW_NETX_XP_TMR2_preload2 = 32  // [31:0]
};

typedef struct TIMER2_BIT_Ttag {
	unsigned int preload2 : BFW_NETX_XP_TMR2_preload2; // read: actual value of timer, write: timer and preload value 
} TIMER2_BIT_T;

typedef union {
	unsigned int val;
	TIMER2_BIT_T bf;
} TIMER2_T;

// ---------------------------------------------------------------------
// Register timer3
// => xPEC Timer 3
//    Resetvalue : 0x00000000
// => Mode: Mode (r/w)
// ---------------------------------------------------------------------

#define REL_NETX_XP_TMR3   0x0000003CU
#define NETX_XP0_TMR3 0x0017003CU
#define NETX_XP1_TMR3 0x0017403CU
#define NETX_XP2_TMR3 0x0017803CU
#define NETX_XP3_TMR3 0x0017C03CU

#define MSK_NETX_XP_TMR3_preload3 0xffffffffU // [31:0]
#define SRT_NETX_XP_TMR3_preload3 0           

enum {
	BFW_NETX_XP_TMR3_preload3 = 32  // [31:0]
};

typedef struct TIMER3_BIT_Ttag {
	unsigned int preload3 : BFW_NETX_XP_TMR3_preload3; // read: actual value of timer, write: timer and preload value 
} TIMER3_BIT_T;

typedef union {
	unsigned int val;
	TIMER3_BIT_T bf;
} TIMER3_T;

// ---------------------------------------------------------------------
// Register timer4
// => xPEC Timer 4
//    Resetvalue : 0x00000000
// => Mode: Mode (r/w)
// ---------------------------------------------------------------------

#define REL_NETX_XP_TMR4   0x00000084U
#define NETX_XP0_TMR4 0x00170084U
#define NETX_XP1_TMR4 0x00174084U
#define NETX_XP2_TMR4 0x00178084U
#define NETX_XP3_TMR4 0x0017C084U

#define MSK_NETX_XP_TMR4_preload2 0xffffffffU // [31:0]
#define SRT_NETX_XP_TMR4_preload2 0           

enum {
	BFW_NETX_XP_TMR4_preload2 = 32  // [31:0]
};

typedef struct TIMER4_BIT_Ttag {
	unsigned int preload2 : BFW_NETX_XP_TMR4_preload2; // read: actual value of timer, write: timer and preload value 
} TIMER4_BIT_T;

typedef union {
	unsigned int val;
	TIMER4_BIT_T bf;
} TIMER4_T;

// ---------------------------------------------------------------------
// Register timer5
// => xPEC Timer 5
//    Resetvalue : 0x00000000
// => Mode: Mode (r/w)
// ---------------------------------------------------------------------

#define REL_NETX_XP_TMR5   0x00000088U
#define NETX_XP0_TMR5 0x00170088U
#define NETX_XP1_TMR5 0x00174088U
#define NETX_XP2_TMR5 0x00178088U
#define NETX_XP3_TMR5 0x0017C088U

#define MSK_NETX_XP_TMR5_preload3 0xffffffffU // [31:0]
#define SRT_NETX_XP_TMR5_preload3 0           

enum {
	BFW_NETX_XP_TMR5_preload3 = 32  // [31:0]
};

typedef struct TIMER5_BIT_Ttag {
	unsigned int preload3 : BFW_NETX_XP_TMR5_preload3; // read: actual value of timer, write: timer and preload value 
} TIMER5_BIT_T;

typedef union {
	unsigned int val;
	TIMER5_BIT_T bf;
} TIMER5_T;

// ---------------------------------------------------------------------
// Register irq
// => xPEC IRQ Register
//    Resetvalue : 0x00000000
// => Mode: Mode (r/w)
// ---------------------------------------------------------------------

#define REL_NETX_XP_IRQ   0x0000008CU
#define NETX_XP0_IRQ 0x0017008CU
#define NETX_XP1_IRQ 0x0017408CU
#define NETX_XP2_IRQ 0x0017808CU
#define NETX_XP3_IRQ 0x0017C08CU

#define MSK_NETX_XP_IRQ_xpec_irq 0x0000ffffU // [15:0]
#define SRT_NETX_XP_IRQ_xpec_irq 0           
#define MSK_NETX_XP_IRQ_arm_irq  0xffff0000U // [31:16]
#define SRT_NETX_XP_IRQ_arm_irq  16          

enum {
	BFW_NETX_XP_IRQ_xpec_irq = 16, // [15:0]
	BFW_NETX_XP_IRQ_arm_irq  = 16  // [31:16]
};

typedef struct IRQ_BIT_Ttag {
	unsigned int xpec_irq : BFW_NETX_XP_IRQ_xpec_irq; // set by xpec ; reset by arm  
	unsigned int arm_irq  : BFW_NETX_XP_IRQ_arm_irq;  // set by arm  ; reset by xpec 
} IRQ_BIT_T;

typedef union {
	unsigned int val;
	IRQ_BIT_T    bf;
} IRQ_T;

// ---------------------------------------------------------------------
// Register xpec_systime_ns
// => xPEC System time
//    Resetvalue : 0x00000000
// => Mode: Mode (r)
// ---------------------------------------------------------------------

#define REL_NETX_XP_SYS_TIME_NS   0x00000090U
#define NETX_XP0_SYS_TIME_NS 0x00170090U
#define NETX_XP1_SYS_TIME_NS 0x00174090U
#define NETX_XP2_SYS_TIME_NS 0x00178090U
#define NETX_XP3_SYS_TIME_NS 0x0017C090U

#define MSK_NETX_XP_SYS_TIME_NS_systime_ns 0xffffffffU // [31:0]
#define SRT_NETX_XP_SYS_TIME_NS_systime_ns 0           

enum {
	BFW_NETX_XP_SYS_TIME_NS_systime_ns = 32  // [31:0]
};

typedef struct XPEC_SYSTIME_NS_BIT_Ttag {
	unsigned int systime_ns : BFW_NETX_XP_SYS_TIME_NS_systime_ns; // read: 32 - Bit System Time (ns)
} XPEC_SYSTIME_NS_BIT_T;

typedef union {
	unsigned int          val;
	XPEC_SYSTIME_NS_BIT_T bf;
} XPEC_SYSTIME_NS_T;

// ---------------------------------------------------------------------
// Register fifo_data
// => xPEC fifo_data
//    Resetvalue : 0x00000000
// => Mode: Mode (r/w)
// ---------------------------------------------------------------------

#define REL_NETX_XP_FIFO_DATA   0x00000094U
#define NETX_XP0_FIFO_DATA 0x00170094U
#define NETX_XP1_FIFO_DATA 0x00174094U
#define NETX_XP2_FIFO_DATA 0x00178094U
#define NETX_XP3_FIFO_DATA 0x0017C094U

#define MSK_NETX_XP_FIFO_DATA_fifo_data 0xffffffffU // [31:0]
#define SRT_NETX_XP_FIFO_DATA_fifo_data 0           

enum {
	BFW_NETX_XP_FIFO_DATA_fifo_data = 32  // [31:0]
};

typedef struct FIFO_DATA_BIT_Ttag {
	unsigned int fifo_data : BFW_NETX_XP_FIFO_DATA_fifo_data; // default 0x0000
} FIFO_DATA_BIT_T;

typedef union {
	unsigned int    val;
	FIFO_DATA_BIT_T bf;
} FIFO_DATA_T;

// ---------------------------------------------------------------------
// Register xpec_systime_s
// => xPEC System time
//    Resetvalue : 0x00000000
// => Mode: Mode (r)
// ---------------------------------------------------------------------

#define REL_NETX_XP_SYS_TIME_S   0x00000098U
#define NETX_XP0_SYS_TIME_S 0x00170098U
#define NETX_XP1_SYS_TIME_S 0x00174098U
#define NETX_XP2_SYS_TIME_S 0x00178098U
#define NETX_XP3_SYS_TIME_S 0x0017C098U

#define MSK_NETX_XP_SYS_TIME_S_systime_s 0xffffffffU // [31:0]
#define SRT_NETX_XP_SYS_TIME_S_systime_s 0           

enum {
	BFW_NETX_XP_SYS_TIME_S_systime_s = 32  // [31:0]
};

typedef struct XPEC_SYSTIME_S_BIT_Ttag {
	unsigned int systime_s : BFW_NETX_XP_SYS_TIME_S_systime_s; // read: 32 - Bit System Time (s)
} XPEC_SYSTIME_S_BIT_T;

typedef union {
	unsigned int         val;
	XPEC_SYSTIME_S_BIT_T bf;
} XPEC_SYSTIME_S_T;

// ---------------------------------------------------------------------
// Register urx_count
// => xPEC urx counter
//    Resetvalue : 0x00000000
// => Mode: Mode (r/w)
// ---------------------------------------------------------------------

#define REL_NETX_XP_URX_CNT   0x00000040U
#define NETX_XP0_URX_CNT 0x00170040U
#define NETX_XP1_URX_CNT 0x00174040U
#define NETX_XP2_URX_CNT 0x00178040U
#define NETX_XP3_URX_CNT 0x0017C040U

#define MSK_NETX_XP_URX_CNT_urx_count 0xffffffffU // [31:0]
#define SRT_NETX_XP_URX_CNT_urx_count 0           

enum {
	BFW_NETX_XP_URX_CNT_urx_count = 32  // [31:0]
};

typedef struct URX_COUNT_BIT_Ttag {
	unsigned int urx_count : BFW_NETX_XP_URX_CNT_urx_count; // counts up received bytes (accesses of xPEC to any URX FIFO) 
} URX_COUNT_BIT_T;

typedef union {
	unsigned int    val;
	URX_COUNT_BIT_T bf;
} URX_COUNT_T;

// ---------------------------------------------------------------------
// Register utx_count
// => xPEC utx counter
//    Resetvalue : 0x00000000
// => Mode: Mode (r/w)
// ---------------------------------------------------------------------

#define REL_NETX_XP_UTX_CNT   0x00000044U
#define NETX_XP0_UTX_CNT 0x00170044U
#define NETX_XP1_UTX_CNT 0x00174044U
#define NETX_XP2_UTX_CNT 0x00178044U
#define NETX_XP3_UTX_CNT 0x0017C044U

#define MSK_NETX_XP_UTX_CNT_utx_count 0xffffffffU // [31:0]
#define SRT_NETX_XP_UTX_CNT_utx_count 0           

enum {
	BFW_NETX_XP_UTX_CNT_utx_count = 32  // [31:0]
};

typedef struct UTX_COUNT_BIT_Ttag {
	unsigned int utx_count : BFW_NETX_XP_UTX_CNT_utx_count; // counts up transmitted bytes (accesses of xPEC to any UTX FIFO) 
} UTX_COUNT_BIT_T;

typedef union {
	unsigned int    val;
	UTX_COUNT_BIT_T bf;
} UTX_COUNT_T;

// ---------------------------------------------------------------------
// Register xpec_pc
// => xPEC Program Counter
//    Resetvalue : 0x000007ff
// => Mode: Mode (r/w)
// ---------------------------------------------------------------------

#define REL_NETX_XP_PC   0x00000048U
#define NETX_XP0_PC 0x00170048U
#define NETX_XP1_PC 0x00174048U
#define NETX_XP2_PC 0x00178048U
#define NETX_XP3_PC 0x0017C048U

#define MSK_NETX_XP_PC_pc 0x000007ffU // [10:0]
#define SRT_NETX_XP_PC_pc 0           

enum {
	BFW_NETX_XP_PC_pc        = 11, // [10:0]
	BFW_NETX_XP_PC_reserved1 = 21  // [31:11]
};

typedef struct XPEC_PC_BIT_Ttag {
	unsigned int pc        : BFW_NETX_XP_PC_pc;        // Program Counter (dword address inside DPRAM) 
	unsigned int reserved1 : BFW_NETX_XP_PC_reserved1; // reserved
} XPEC_PC_BIT_T;

typedef union {
	unsigned int  val;
	XPEC_PC_BIT_T bf;
} XPEC_PC_T;

// ---------------------------------------------------------------------
// Register zero
// => Zero Register
//    Resetvalue : 0x00000000
// => Mode: Mode (r/w)
// ---------------------------------------------------------------------

#define REL_NETX_XP_ZERO   0x0000004CU
#define NETX_XP0_ZERO 0x0017004CU
#define NETX_XP1_ZERO 0x0017404CU
#define NETX_XP2_ZERO 0x0017804CU
#define NETX_XP3_ZERO 0x0017C04CU

#define MSK_NETX_XP_ZERO_zero 0xffffffffU // [31:0]
#define SRT_NETX_XP_ZERO_zero 0           

enum {
	BFW_NETX_XP_ZERO_zero = 32  // [31:0]
};

typedef struct ZERO_BIT_Ttag {
	unsigned int zero : BFW_NETX_XP_ZERO_zero; // Always Zero 
} ZERO_BIT_T;

typedef union {
	unsigned int val;
	ZERO_BIT_T   bf;
} ZERO_T;

// ---------------------------------------------------------------------
// Register xpec_statcfg
// => xPEC Config register
//    Resetvalue : 0x00000000
// => Mode: Mode (r/w)
// ---------------------------------------------------------------------

#define REL_NETX_XP_STAT_CFG   0x00000050U
#define NETX_XP0_STAT_CFG 0x00170050U
#define NETX_XP1_STAT_CFG 0x00174050U
#define NETX_XP2_STAT_CFG 0x00178050U
#define NETX_XP3_STAT_CFG 0x0017C050U

#define MSK_NETX_XP_STAT_CFG_timer0             0x00000003U // [1:0]
#define SRT_NETX_XP_STAT_CFG_timer0             0           
#define MSK_NETX_XP_STAT_CFG_timer1             0x0000000cU // [3:2]
#define SRT_NETX_XP_STAT_CFG_timer1             2           
#define MSK_NETX_XP_STAT_CFG_timer2             0x00000030U // [5:4]
#define SRT_NETX_XP_STAT_CFG_timer2             4           
#define MSK_NETX_XP_STAT_CFG_timer3             0x000000c0U // [7:6]
#define SRT_NETX_XP_STAT_CFG_timer3             6           
#define MSK_NETX_XP_STAT_CFG_timer4             0x00000300U // [9:8]
#define SRT_NETX_XP_STAT_CFG_timer4             8           
#define MSK_NETX_XP_STAT_CFG_timer5             0x00000c00U // [11:10]
#define SRT_NETX_XP_STAT_CFG_timer5             10          
#define MSK_NETX_XP_STAT_CFG_reset_req          0x00001000U // [12]
#define SRT_NETX_XP_STAT_CFG_reset_req          12          
#define MSK_NETX_XP_STAT_CFG_reset_dis          0x00002000U // [13]
#define SRT_NETX_XP_STAT_CFG_reset_dis          13          
#define MSK_NETX_XP_STAT_CFG_debug_mode         0x00004000U // [14]
#define SRT_NETX_XP_STAT_CFG_debug_mode         14          
#define MSK_NETX_XP_STAT_CFG_run_dma_controller 0x80000000U // [31]
#define SRT_NETX_XP_STAT_CFG_run_dma_controller 31          

enum {
	BFW_NETX_XP_STAT_CFG_timer0             = 2,  // [1:0]
	BFW_NETX_XP_STAT_CFG_timer1             = 2,  // [3:2]
	BFW_NETX_XP_STAT_CFG_timer2             = 2,  // [5:4]
	BFW_NETX_XP_STAT_CFG_timer3             = 2,  // [7:6]
	BFW_NETX_XP_STAT_CFG_timer4             = 2,  // [9:8]
	BFW_NETX_XP_STAT_CFG_timer5             = 2,  // [11:10]
	BFW_NETX_XP_STAT_CFG_reset_req          = 1,  // [12]
	BFW_NETX_XP_STAT_CFG_reset_dis          = 1,  // [13]
	BFW_NETX_XP_STAT_CFG_debug_mode         = 1,  // [14]
	BFW_NETX_XP_STAT_CFG_reserved1          = 16, // [30:15]
	BFW_NETX_XP_STAT_CFG_run_dma_controller = 1   // [31]
};

typedef struct XPEC_STATCFG_BIT_Ttag {
	unsigned int timer0             : BFW_NETX_XP_STAT_CFG_timer0;             // Timer0
	                                                        //       2'b00 : Timer stops at 0
	                                                        //       2'b01 : Timer is preload with value from preload register at 0
	                                                        //       2'b10 : Timer (value) compare with systime
	                                                        //       2'b11 : Timer is workregister
	unsigned int timer1             : BFW_NETX_XP_STAT_CFG_timer1;             // Timer1
	unsigned int timer2             : BFW_NETX_XP_STAT_CFG_timer2;             // Timer2
	unsigned int timer3             : BFW_NETX_XP_STAT_CFG_timer3;             // Timer3
	unsigned int timer4             : BFW_NETX_XP_STAT_CFG_timer4;             // Timer4
	unsigned int timer5             : BFW_NETX_XP_STAT_CFG_timer5;             // Timer5
	unsigned int reset_req          : BFW_NETX_XP_STAT_CFG_reset_req;          // System Reset
	unsigned int reset_dis          : BFW_NETX_XP_STAT_CFG_reset_dis;          // disable own Reset
	unsigned int debug_mode         : BFW_NETX_XP_STAT_CFG_debug_mode;         // in this mode XPEC gets debug data form sr14 and sr15
	unsigned int reserved1          : BFW_NETX_XP_STAT_CFG_reserved1;          // reserved
	unsigned int run_dma_controller : BFW_NETX_XP_STAT_CFG_run_dma_controller; // 0: stop dma_controller, 1: start dma_controller
	                                                        // stop / start the polling
} XPEC_STATCFG_BIT_T;

typedef union {
	unsigned int       val;
	XPEC_STATCFG_BIT_T bf;
} XPEC_STATCFG_T;

// ---------------------------------------------------------------------
// Register ec_maska
// => JMP-Mask a
//    Resetvalue : 0x0000ffff
// => Mode: Mode (r/w)
// ---------------------------------------------------------------------

#define REL_NETX_XP_EV_CTRL_MSKA   0x00000054U
#define NETX_XP0_EV_CTRL_MSKA 0x00170054U
#define NETX_XP1_EV_CTRL_MSKA 0x00174054U
#define NETX_XP2_EV_CTRL_MSKA 0x00178054U
#define NETX_XP3_EV_CTRL_MSKA 0x0017C054U

#define MSK_NETX_XP_EV_CTRL_MSKA_sel0              0x000000ffU // [7:0]
#define SRT_NETX_XP_EV_CTRL_MSKA_sel0              0           
#define MSK_NETX_XP_EV_CTRL_MSKA_sel1              0x0000ff00U // [15:8]
#define SRT_NETX_XP_EV_CTRL_MSKA_sel1              8           
#define MSK_NETX_XP_EV_CTRL_MSKA_jmp_adr           0x07ff0000U // [26:16]
#define SRT_NETX_XP_EV_CTRL_MSKA_jmp_adr           16          
#define MSK_NETX_XP_EV_CTRL_MSKA_level_edge_event0 0x18000000U // [28:27]
#define SRT_NETX_XP_EV_CTRL_MSKA_level_edge_event0 27          
#define MSK_NETX_XP_EV_CTRL_MSKA_level_edge_event1 0x60000000U // [30:29]
#define SRT_NETX_XP_EV_CTRL_MSKA_level_edge_event1 29          
#define MSK_NETX_XP_EV_CTRL_MSKA_and_or            0x80000000U // [31]
#define SRT_NETX_XP_EV_CTRL_MSKA_and_or            31          

enum {
	BFW_NETX_XP_EV_CTRL_MSKA_sel0              = 8,  // [7:0]
	BFW_NETX_XP_EV_CTRL_MSKA_sel1              = 8,  // [15:8]
	BFW_NETX_XP_EV_CTRL_MSKA_jmp_adr           = 11, // [26:16]
	BFW_NETX_XP_EV_CTRL_MSKA_level_edge_event0 = 2,  // [28:27]
	BFW_NETX_XP_EV_CTRL_MSKA_level_edge_event1 = 2,  // [30:29]
	BFW_NETX_XP_EV_CTRL_MSKA_and_or            = 1   // [31]
};

typedef struct EC_MASKA_BIT_Ttag {
	unsigned int sel0              : BFW_NETX_XP_EV_CTRL_MSKA_sel0;              // Select of event 0: 
	                                                        //     0-15    : XMAC status reg 0 (statcfg0 16:31)
	                                                        //     16-31   : XMAC status reg 1 (statcfg1 16:31)
	                                                        //     32-47   : XMAC status reg 2 (statcfg2 16:31)
	                                                        //     48-63   : XMAC status reg 3 (statcfg3 16:31)
	                                                        //     64-67   : Timer interrupt 0:3
	                                                        //     68-71   : Shared Register sr_0[12:15]
	                                                        //     72-75   : Shared Register sr_1[12:15]
	                                                        //     76-79   : Shared Register sr_2[12:15]
	                                                        //     80-83   : Shared Register sr_3[12:15]
	                                                        //     84-87   : Shared Register sr_4[12:15]
	                                                        //     88-91   : Shared Register sr_5[12:15]
	                                                        //     92-95   : Shared Register sr_6[12:15]
	                                                        //     96-99   : Shared Register sr_7[12:15]
	                                                        //     100-103 : Shared Register sr_8[12:15]
	                                                        //     104-107 : Shared Register sr_9[12:15]
	                                                        //     108-111 : Shared Register sr_10[12:15]
	                                                        //     112-115 : Shared Register sr_11[12:15]
	                                                        //     116-119 : Shared Register sr_12[12:15]
	                                                        //     120-123 : Shared Register sr_13[12:15]
	                                                        //     124-127 : Shared Register sr_14[12:15]
	                                                        //     128-131 : Shared Register sr_15[12:15]
	                                                        //     132-139 : xPEC_0(DMA_finish[0:7])
	                                                        //               132 : DMA_finish_0
	                                                        //               133 : DMA_finish_1
	                                                        //               134 : DMA_finish_2
	                                                        //               135 : DMA_finish_3
	                                                        //               136 : DMA_finish_4
	                                                        //               137 : DMA_finish_5
	                                                        //               138 : DMA_finish_6
	                                                        //               139 : DMA_finish_7
	                                                        //     140-147 : xPEC_1(DMA_finish[0:7])
	                                                        //               140 : DMA_finish_0
	                                                        //               141 : DMA_finish_1
	                                                        //               142 : DMA_finish_2
	                                                        //               143 : DMA_finish_3
	                                                        //               144 : DMA_finish_4
	                                                        //               145 : DMA_finish_5
	                                                        //               146 : DMA_finish_6
	                                                        //               147 : DMA_finish_7
	                                                        //     148-155 : xPEC_2(DMA_finish[0:7])
	                                                        //               148 : DMA_finish_0
	                                                        //               149 : DMA_finish_1
	                                                        //               150 : DMA_finish_2
	                                                        //               151 : DMA_finish_3
	                                                        //               152 : DMA_finish_4
	                                                        //               153 : DMA_finish_5
	                                                        //               154 : DMA_finish_6
	                                                        //               155 : DMA_finish_7
	                                                        //     156-163 : xPEC_1(DMA_finish[0:7])
	                                                        //               156 : DMA_finish_0
	                                                        //               157 : DMA_finish_1
	                                                        //               158 : DMA_finish_2
	                                                        //               159 : DMA_finish_3
	                                                        //               160 : DMA_finish_4
	                                                        //               161 : DMA_finish_5
	                                                        //               162 : DMA_finish_6
	                                                        //               163 : DMA_finish_7
	                                                        //     164-165   : Timer interrupt 4:5
	                                                        //     166-173 : range_w0 - range_w7 smaller as w0 - w7
	                                                        //               166 : range_w0 < w0
	                                                        //               167 : range_w1 < w1
	                                                        //               168 : range_w2 < w2
	                                                        //               169 : range_w3 < w3
	                                                        //               170 : range_w4 < w4
	                                                        //               171 : range_w5 < w5
	                                                        //               172 : range_w6 < w6
	                                                        //               173 : range_w7 < w7
	                                                        //     174-181 : range_w0 - range_w7 2 smaller as w0 - w7
	                                                        //               174 : range_w0 2< w0
	                                                        //               175 : range_w1 2< w1
	                                                        //               176 : range_w2 2< w2
	                                                        //               177 : range_w3 2< w3
	                                                        //               178 : range_w4 2< w4
	                                                        //               179 : range_w5 2< w5
	                                                        //               180 : range_w6 2< w6
	                                                        //               181 : range_w7 2< w7
	                                                        //         182 : rx_rdy_asyn_xmac0
	                                                        //         183 : rx_rdy_asyn_xmac1
	                                                        //         184 : rx_rdy_asyn_xmac2
	                                                        //         185 : rx_rdy_asyn_xmac3
	                                                        //         186 : tx_nxt2_asyn_xmac0
	                                                        //         187 : tx_nxt2_asyn_xmac1
	                                                        //         188 : tx_nxt2_asyn_xmac2
	                                                        //         189 : tx_nxt2_asyn_xmac3
	                                                        //     190-221 : fifo_empty [0:31]
	                                                        //         222 : adc0_data_busy
	                                                        //         223 : adc1_data_busy
	                                                        //     224-239 : arm_irq [0:15] (from irq_reg[16:31])
	                                                        //         240 : debug_event
	                                                        //       255 : reserved # default value
	unsigned int sel1              : BFW_NETX_XP_EV_CTRL_MSKA_sel1;              // Select of event 1 
	unsigned int jmp_adr           : BFW_NETX_XP_EV_CTRL_MSKA_jmp_adr;           // jmp address (0-2047) 
	unsigned int level_edge_event0 : BFW_NETX_XP_EV_CTRL_MSKA_level_edge_event0; // for event 0 : level / edge sensitive:
	                                                        //               2'b00 sensitve to 1 level
	                                                        //               2'b01 sensitve to 0 level
	                                                        //               2'b10 sensitve to positive edge (low to high)
	                                                        //               2'b11 sensitve to negative edge (high to low)
	unsigned int level_edge_event1 : BFW_NETX_XP_EV_CTRL_MSKA_level_edge_event1; // for event 1 : level / edge sensitive:
	                                                        //               2'b00 sensitve to 1 level
	                                                        //               2'b01 sensitve to 0 level
	                                                        //               2'b10 sensitve to positive edge (low to high)
	                                                        //               2'b11 sensitve to negative edge (high to low)
	unsigned int and_or            : BFW_NETX_XP_EV_CTRL_MSKA_and_or;            // and/or bit:
	                                                        // 0 - All bits of mask must fit with events,
	                                                        // 1 - Only one bit of mask must fit with events # default 0
} EC_MASKA_BIT_T;

typedef union {
	unsigned int   val;
	EC_MASKA_BIT_T bf;
} EC_MASKA_T;

// ---------------------------------------------------------------------
// Register ec_maskb
// => JMP-Mask b
//    Resetvalue : 0x0000ffff
// => Mode: Mode (r/w)
// ---------------------------------------------------------------------

#define REL_NETX_XP_EV_CTRL_MSKB   0x00000058U
#define NETX_XP0_EV_CTRL_MSKB 0x00170058U
#define NETX_XP1_EV_CTRL_MSKB 0x00174058U
#define NETX_XP2_EV_CTRL_MSKB 0x00178058U
#define NETX_XP3_EV_CTRL_MSKB 0x0017C058U

#define MSK_NETX_XP_EV_CTRL_MSKB_sel0              0x000000ffU // [7:0]
#define SRT_NETX_XP_EV_CTRL_MSKB_sel0              0           
#define MSK_NETX_XP_EV_CTRL_MSKB_sel1              0x0000ff00U // [15:8]
#define SRT_NETX_XP_EV_CTRL_MSKB_sel1              8           
#define MSK_NETX_XP_EV_CTRL_MSKB_jmp_adr           0x07ff0000U // [26:16]
#define SRT_NETX_XP_EV_CTRL_MSKB_jmp_adr           16          
#define MSK_NETX_XP_EV_CTRL_MSKB_level_edge_event0 0x18000000U // [28:27]
#define SRT_NETX_XP_EV_CTRL_MSKB_level_edge_event0 27          
#define MSK_NETX_XP_EV_CTRL_MSKB_level_edge_event1 0x60000000U // [30:29]
#define SRT_NETX_XP_EV_CTRL_MSKB_level_edge_event1 29          
#define MSK_NETX_XP_EV_CTRL_MSKB_and_or            0x80000000U // [31]
#define SRT_NETX_XP_EV_CTRL_MSKB_and_or            31          

enum {
	BFW_NETX_XP_EV_CTRL_MSKB_sel0              = 8,  // [7:0]
	BFW_NETX_XP_EV_CTRL_MSKB_sel1              = 8,  // [15:8]
	BFW_NETX_XP_EV_CTRL_MSKB_jmp_adr           = 11, // [26:16]
	BFW_NETX_XP_EV_CTRL_MSKB_level_edge_event0 = 2,  // [28:27]
	BFW_NETX_XP_EV_CTRL_MSKB_level_edge_event1 = 2,  // [30:29]
	BFW_NETX_XP_EV_CTRL_MSKB_and_or            = 1   // [31]
};

typedef struct EC_MASKB_BIT_Ttag {
	unsigned int sel0              : BFW_NETX_XP_EV_CTRL_MSKB_sel0;              // Select of event 0 
	unsigned int sel1              : BFW_NETX_XP_EV_CTRL_MSKB_sel1;              // Select of event 1 
	unsigned int jmp_adr           : BFW_NETX_XP_EV_CTRL_MSKB_jmp_adr;           // jmp address (0-2047) 
	unsigned int level_edge_event0 : BFW_NETX_XP_EV_CTRL_MSKB_level_edge_event0; // for event 0 : level / edge sensitive:
	                                                        //               2'b00 sensitve to 1 level
	                                                        //               2'b01 sensitve to 0 level
	                                                        //               2'b10 sensitve to positive edge (low to high)
	                                                        //               2'b11 sensitve to negative edge (high to low)
	unsigned int level_edge_event1 : BFW_NETX_XP_EV_CTRL_MSKB_level_edge_event1; // for event 1 : level / edge sensitive:
	                                                        //               2'b00 sensitve to 1 level
	                                                        //               2'b01 sensitve to 0 level
	                                                        //               2'b10 sensitve to positive edge (low to high)
	                                                        //               2'b11 sensitve to negative edge (high to low)
	unsigned int and_or            : BFW_NETX_XP_EV_CTRL_MSKB_and_or;            // and/or bit:
	                                                        // 0 - All bits of mask must fit with events,
	                                                        // 1 - Only one bit of mask must fit with events # default 0
} EC_MASKB_BIT_T;

typedef union {
	unsigned int   val;
	EC_MASKB_BIT_T bf;
} EC_MASKB_T;

// ---------------------------------------------------------------------
// Register ec_mask8
// => JMP-Mask 8
//    Resetvalue : 0x0000ffff
// => Mode: Mode (r/w)
// ---------------------------------------------------------------------

#define REL_NETX_XP_EV_CTRL_MSK8   0x0000007CU
#define NETX_XP0_EV_CTRL_MSK8 0x0017007CU
#define NETX_XP1_EV_CTRL_MSK8 0x0017407CU
#define NETX_XP2_EV_CTRL_MSK8 0x0017807CU
#define NETX_XP3_EV_CTRL_MSK8 0x0017C07CU

#define MSK_NETX_XP_EV_CTRL_MSK8_sel0              0x000000ffU // [7:0]
#define SRT_NETX_XP_EV_CTRL_MSK8_sel0              0           
#define MSK_NETX_XP_EV_CTRL_MSK8_sel1              0x0000ff00U // [15:8]
#define SRT_NETX_XP_EV_CTRL_MSK8_sel1              8           
#define MSK_NETX_XP_EV_CTRL_MSK8_jmp_adr           0x07ff0000U // [26:16]
#define SRT_NETX_XP_EV_CTRL_MSK8_jmp_adr           16          
#define MSK_NETX_XP_EV_CTRL_MSK8_level_edge_event0 0x18000000U // [28:27]
#define SRT_NETX_XP_EV_CTRL_MSK8_level_edge_event0 27          
#define MSK_NETX_XP_EV_CTRL_MSK8_level_edge_event1 0x60000000U // [30:29]
#define SRT_NETX_XP_EV_CTRL_MSK8_level_edge_event1 29          
#define MSK_NETX_XP_EV_CTRL_MSK8_and_or            0x80000000U // [31]
#define SRT_NETX_XP_EV_CTRL_MSK8_and_or            31          

enum {
	BFW_NETX_XP_EV_CTRL_MSK8_sel0              = 8,  // [7:0]
	BFW_NETX_XP_EV_CTRL_MSK8_sel1              = 8,  // [15:8]
	BFW_NETX_XP_EV_CTRL_MSK8_jmp_adr           = 11, // [26:16]
	BFW_NETX_XP_EV_CTRL_MSK8_level_edge_event0 = 2,  // [28:27]
	BFW_NETX_XP_EV_CTRL_MSK8_level_edge_event1 = 2,  // [30:29]
	BFW_NETX_XP_EV_CTRL_MSK8_and_or            = 1   // [31]
};

typedef struct EC_MASK8_BIT_Ttag {
	unsigned int sel0              : BFW_NETX_XP_EV_CTRL_MSK8_sel0;              // Select of event 0 
	unsigned int sel1              : BFW_NETX_XP_EV_CTRL_MSK8_sel1;              // Select of event 1 
	unsigned int jmp_adr           : BFW_NETX_XP_EV_CTRL_MSK8_jmp_adr;           // jmp address (0-2047) 
	unsigned int level_edge_event0 : BFW_NETX_XP_EV_CTRL_MSK8_level_edge_event0; // for event 0 : level / edge sensitive:
	                                                        //               2'b00 sensitve to 1 level
	                                                        //               2'b01 sensitve to 0 level
	                                                        //               2'b10 sensitve to positive edge (low to high)
	                                                        //               2'b11 sensitve to negative edge (high to low)
	unsigned int level_edge_event1 : BFW_NETX_XP_EV_CTRL_MSK8_level_edge_event1; // for event 1 : level / edge sensitive:
	                                                        //               2'b00 sensitve to 1 level
	                                                        //               2'b01 sensitve to 0 level
	                                                        //               2'b10 sensitve to positive edge (low to high)
	                                                        //               2'b11 sensitve to negative edge (high to low)
	unsigned int and_or            : BFW_NETX_XP_EV_CTRL_MSK8_and_or;            // and/or bit:
	                                                        // 0 - All bits of mask must fit with events,
	                                                        // 1 - Only one bit of mask must fit with events # default 0
} EC_MASK8_BIT_T;

typedef union {
	unsigned int   val;
	EC_MASK8_BIT_T bf;
} EC_MASK8_T;

// ---------------------------------------------------------------------
// Register ec_mask9
// => JMP-Mask 9
//    Resetvalue : 0x0000ffff
// => Mode: Mode (r/w)
// ---------------------------------------------------------------------

#define REL_NETX_XP_EV_CTRL_MSK9   0x00000080U
#define NETX_XP0_EV_CTRL_MSK9 0x00170080U
#define NETX_XP1_EV_CTRL_MSK9 0x00174080U
#define NETX_XP2_EV_CTRL_MSK9 0x00178080U
#define NETX_XP3_EV_CTRL_MSK9 0x0017C080U

#define MSK_NETX_XP_EV_CTRL_MSK9_sel0              0x000000ffU // [7:0]
#define SRT_NETX_XP_EV_CTRL_MSK9_sel0              0           
#define MSK_NETX_XP_EV_CTRL_MSK9_sel1              0x0000ff00U // [15:8]
#define SRT_NETX_XP_EV_CTRL_MSK9_sel1              8           
#define MSK_NETX_XP_EV_CTRL_MSK9_jmp_adr           0x07ff0000U // [26:16]
#define SRT_NETX_XP_EV_CTRL_MSK9_jmp_adr           16          
#define MSK_NETX_XP_EV_CTRL_MSK9_level_edge_event0 0x18000000U // [28:27]
#define SRT_NETX_XP_EV_CTRL_MSK9_level_edge_event0 27          
#define MSK_NETX_XP_EV_CTRL_MSK9_level_edge_event1 0x60000000U // [30:29]
#define SRT_NETX_XP_EV_CTRL_MSK9_level_edge_event1 29          
#define MSK_NETX_XP_EV_CTRL_MSK9_and_or            0x80000000U // [31]
#define SRT_NETX_XP_EV_CTRL_MSK9_and_or            31          

enum {
	BFW_NETX_XP_EV_CTRL_MSK9_sel0              = 8,  // [7:0]
	BFW_NETX_XP_EV_CTRL_MSK9_sel1              = 8,  // [15:8]
	BFW_NETX_XP_EV_CTRL_MSK9_jmp_adr           = 11, // [26:16]
	BFW_NETX_XP_EV_CTRL_MSK9_level_edge_event0 = 2,  // [28:27]
	BFW_NETX_XP_EV_CTRL_MSK9_level_edge_event1 = 2,  // [30:29]
	BFW_NETX_XP_EV_CTRL_MSK9_and_or            = 1   // [31]
};

typedef struct EC_MASK9_BIT_Ttag {
	unsigned int sel0              : BFW_NETX_XP_EV_CTRL_MSK9_sel0;              // Select of event 0 
	unsigned int sel1              : BFW_NETX_XP_EV_CTRL_MSK9_sel1;              // Select of event 1 
	unsigned int jmp_adr           : BFW_NETX_XP_EV_CTRL_MSK9_jmp_adr;           // jmp address (0-2047) 
	unsigned int level_edge_event0 : BFW_NETX_XP_EV_CTRL_MSK9_level_edge_event0; // for event 0 : level / edge sensitive:
	                                                        //               2'b00 sensitve to 1 level
	                                                        //               2'b01 sensitve to 0 level
	                                                        //               2'b10 sensitve to positive edge (low to high)
	                                                        //               2'b11 sensitve to negative edge (high to low)
	unsigned int level_edge_event1 : BFW_NETX_XP_EV_CTRL_MSK9_level_edge_event1; // for event 1 : level / edge sensitive:
	                                                        //               2'b00 sensitve to 1 level
	                                                        //               2'b01 sensitve to 0 level
	                                                        //               2'b10 sensitve to positive edge (low to high)
	                                                        //               2'b11 sensitve to negative edge (high to low)
	unsigned int and_or            : BFW_NETX_XP_EV_CTRL_MSK9_and_or;            // and/or bit:
	                                                        // 0 - All bits of mask must fit with events,
	                                                        // 1 - Only one bit of mask must fit with events # default 0
} EC_MASK9_BIT_T;

typedef union {
	unsigned int   val;
	EC_MASK9_BIT_T bf;
} EC_MASK9_T;

// ---------------------------------------------------------------------
// Register ec_mask0
// => JMP-Mask 0
//    Resetvalue : 0x0000ffff
// => Mode: Mode (r/w)
// ---------------------------------------------------------------------

#define REL_NETX_XP_EV_CTRL_MSK0   0x0000005CU
#define NETX_XP0_EV_CTRL_MSK0 0x0017005CU
#define NETX_XP1_EV_CTRL_MSK0 0x0017405CU
#define NETX_XP2_EV_CTRL_MSK0 0x0017805CU
#define NETX_XP3_EV_CTRL_MSK0 0x0017C05CU

#define MSK_NETX_XP_EV_CTRL_MSK0_sel0              0x000000ffU // [7:0]
#define SRT_NETX_XP_EV_CTRL_MSK0_sel0              0           
#define MSK_NETX_XP_EV_CTRL_MSK0_sel1              0x0000ff00U // [15:8]
#define SRT_NETX_XP_EV_CTRL_MSK0_sel1              8           
#define MSK_NETX_XP_EV_CTRL_MSK0_jmp_adr           0x07ff0000U // [26:16]
#define SRT_NETX_XP_EV_CTRL_MSK0_jmp_adr           16          
#define MSK_NETX_XP_EV_CTRL_MSK0_level_edge_event0 0x18000000U // [28:27]
#define SRT_NETX_XP_EV_CTRL_MSK0_level_edge_event0 27          
#define MSK_NETX_XP_EV_CTRL_MSK0_level_edge_event1 0x60000000U // [30:29]
#define SRT_NETX_XP_EV_CTRL_MSK0_level_edge_event1 29          
#define MSK_NETX_XP_EV_CTRL_MSK0_and_or            0x80000000U // [31]
#define SRT_NETX_XP_EV_CTRL_MSK0_and_or            31          

enum {
	BFW_NETX_XP_EV_CTRL_MSK0_sel0              = 8,  // [7:0]
	BFW_NETX_XP_EV_CTRL_MSK0_sel1              = 8,  // [15:8]
	BFW_NETX_XP_EV_CTRL_MSK0_jmp_adr           = 11, // [26:16]
	BFW_NETX_XP_EV_CTRL_MSK0_level_edge_event0 = 2,  // [28:27]
	BFW_NETX_XP_EV_CTRL_MSK0_level_edge_event1 = 2,  // [30:29]
	BFW_NETX_XP_EV_CTRL_MSK0_and_or            = 1   // [31]
};

typedef struct EC_MASK0_BIT_Ttag {
	unsigned int sel0              : BFW_NETX_XP_EV_CTRL_MSK0_sel0;              // Select of event 0 
	unsigned int sel1              : BFW_NETX_XP_EV_CTRL_MSK0_sel1;              // Select of event 1 
	unsigned int jmp_adr           : BFW_NETX_XP_EV_CTRL_MSK0_jmp_adr;           // jmp address (0-2047) 
	unsigned int level_edge_event0 : BFW_NETX_XP_EV_CTRL_MSK0_level_edge_event0; // for event 0 : level / edge sensitive:
	                                                        //               2'b00 sensitve to 1 level
	                                                        //               2'b01 sensitve to 0 level
	                                                        //               2'b10 sensitve to positive edge (low to high)
	                                                        //               2'b11 sensitve to negative edge (high to low)
	unsigned int level_edge_event1 : BFW_NETX_XP_EV_CTRL_MSK0_level_edge_event1; // for event 1 : level / edge sensitive:
	                                                        //               2'b00 sensitve to 1 level
	                                                        //               2'b01 sensitve to 0 level
	                                                        //               2'b10 sensitve to positive edge (low to high)
	                                                        //               2'b11 sensitve to negative edge (high to low)
	unsigned int and_or            : BFW_NETX_XP_EV_CTRL_MSK0_and_or;            // and/or bit:
	                                                        // 0 - All bits of mask must fit with events,
	                                                        // 1 - Only one bit of mask must fit with events # default 0
} EC_MASK0_BIT_T;

typedef union {
	unsigned int   val;
	EC_MASK0_BIT_T bf;
} EC_MASK0_T;

// ---------------------------------------------------------------------
// Register ec_mask1
// => JMP-Mask 1
//    Resetvalue : 0x0000ffff
// => Mode: Mode (r/w)
// ---------------------------------------------------------------------

#define REL_NETX_XP_EV_CTRL_MSK1   0x00000060U
#define NETX_XP0_EV_CTRL_MSK1 0x00170060U
#define NETX_XP1_EV_CTRL_MSK1 0x00174060U
#define NETX_XP2_EV_CTRL_MSK1 0x00178060U
#define NETX_XP3_EV_CTRL_MSK1 0x0017C060U

#define MSK_NETX_XP_EV_CTRL_MSK1_sel0              0x000000ffU // [7:0]
#define SRT_NETX_XP_EV_CTRL_MSK1_sel0              0           
#define MSK_NETX_XP_EV_CTRL_MSK1_sel1              0x0000ff00U // [15:8]
#define SRT_NETX_XP_EV_CTRL_MSK1_sel1              8           
#define MSK_NETX_XP_EV_CTRL_MSK1_jmp_adr           0x07ff0000U // [26:16]
#define SRT_NETX_XP_EV_CTRL_MSK1_jmp_adr           16          
#define MSK_NETX_XP_EV_CTRL_MSK1_level_edge_event0 0x18000000U // [28:27]
#define SRT_NETX_XP_EV_CTRL_MSK1_level_edge_event0 27          
#define MSK_NETX_XP_EV_CTRL_MSK1_level_edge_event1 0x60000000U // [30:29]
#define SRT_NETX_XP_EV_CTRL_MSK1_level_edge_event1 29          
#define MSK_NETX_XP_EV_CTRL_MSK1_and_or            0x80000000U // [31]
#define SRT_NETX_XP_EV_CTRL_MSK1_and_or            31          

enum {
	BFW_NETX_XP_EV_CTRL_MSK1_sel0              = 8,  // [7:0]
	BFW_NETX_XP_EV_CTRL_MSK1_sel1              = 8,  // [15:8]
	BFW_NETX_XP_EV_CTRL_MSK1_jmp_adr           = 11, // [26:16]
	BFW_NETX_XP_EV_CTRL_MSK1_level_edge_event0 = 2,  // [28:27]
	BFW_NETX_XP_EV_CTRL_MSK1_level_edge_event1 = 2,  // [30:29]
	BFW_NETX_XP_EV_CTRL_MSK1_and_or            = 1   // [31]
};

typedef struct EC_MASK1_BIT_Ttag {
	unsigned int sel0              : BFW_NETX_XP_EV_CTRL_MSK1_sel0;              // Select of event 0 
	unsigned int sel1              : BFW_NETX_XP_EV_CTRL_MSK1_sel1;              // Select of event 1 
	unsigned int jmp_adr           : BFW_NETX_XP_EV_CTRL_MSK1_jmp_adr;           // jmp address (0-2047) 
	unsigned int level_edge_event0 : BFW_NETX_XP_EV_CTRL_MSK1_level_edge_event0; // for event 0 : level / edge sensitive:
	                                                        //               2'b00 sensitve to 1 level
	                                                        //               2'b01 sensitve to 0 level
	                                                        //               2'b10 sensitve to positive edge (low to high)
	                                                        //               2'b11 sensitve to negative edge (high to low)
	unsigned int level_edge_event1 : BFW_NETX_XP_EV_CTRL_MSK1_level_edge_event1; // for event 1 : level / edge sensitive:
	                                                        //               2'b00 sensitve to 1 level
	                                                        //               2'b01 sensitve to 0 level
	                                                        //               2'b10 sensitve to positive edge (low to high)
	                                                        //               2'b11 sensitve to negative edge (high to low)
	unsigned int and_or            : BFW_NETX_XP_EV_CTRL_MSK1_and_or;            // and/or bit:
	                                                        // 0 - All bits of mask must fit with events,
	                                                        // 1 - Only one bit of mask must fit with events # default 0
} EC_MASK1_BIT_T;

typedef union {
	unsigned int   val;
	EC_MASK1_BIT_T bf;
} EC_MASK1_T;

// ---------------------------------------------------------------------
// Register ec_mask2
// => JMP-Mask 2
//    Resetvalue : 0x0000ffff
// => Mode: Mode (r/w)
// ---------------------------------------------------------------------

#define REL_NETX_XP_EV_CTRL_MSK2   0x00000064U
#define NETX_XP0_EV_CTRL_MSK2 0x00170064U
#define NETX_XP1_EV_CTRL_MSK2 0x00174064U
#define NETX_XP2_EV_CTRL_MSK2 0x00178064U
#define NETX_XP3_EV_CTRL_MSK2 0x0017C064U

#define MSK_NETX_XP_EV_CTRL_MSK2_sel0              0x000000ffU // [7:0]
#define SRT_NETX_XP_EV_CTRL_MSK2_sel0              0           
#define MSK_NETX_XP_EV_CTRL_MSK2_sel1              0x0000ff00U // [15:8]
#define SRT_NETX_XP_EV_CTRL_MSK2_sel1              8           
#define MSK_NETX_XP_EV_CTRL_MSK2_jmp_adr           0x07ff0000U // [26:16]
#define SRT_NETX_XP_EV_CTRL_MSK2_jmp_adr           16          
#define MSK_NETX_XP_EV_CTRL_MSK2_level_edge_event0 0x18000000U // [28:27]
#define SRT_NETX_XP_EV_CTRL_MSK2_level_edge_event0 27          
#define MSK_NETX_XP_EV_CTRL_MSK2_level_edge_event1 0x60000000U // [30:29]
#define SRT_NETX_XP_EV_CTRL_MSK2_level_edge_event1 29          
#define MSK_NETX_XP_EV_CTRL_MSK2_and_or            0x80000000U // [31]
#define SRT_NETX_XP_EV_CTRL_MSK2_and_or            31          

enum {
	BFW_NETX_XP_EV_CTRL_MSK2_sel0              = 8,  // [7:0]
	BFW_NETX_XP_EV_CTRL_MSK2_sel1              = 8,  // [15:8]
	BFW_NETX_XP_EV_CTRL_MSK2_jmp_adr           = 11, // [26:16]
	BFW_NETX_XP_EV_CTRL_MSK2_level_edge_event0 = 2,  // [28:27]
	BFW_NETX_XP_EV_CTRL_MSK2_level_edge_event1 = 2,  // [30:29]
	BFW_NETX_XP_EV_CTRL_MSK2_and_or            = 1   // [31]
};

typedef struct EC_MASK2_BIT_Ttag {
	unsigned int sel0              : BFW_NETX_XP_EV_CTRL_MSK2_sel0;              // Select of event 0 
	unsigned int sel1              : BFW_NETX_XP_EV_CTRL_MSK2_sel1;              // Select of event 1 
	unsigned int jmp_adr           : BFW_NETX_XP_EV_CTRL_MSK2_jmp_adr;           // jmp address (0-2047) 
	unsigned int level_edge_event0 : BFW_NETX_XP_EV_CTRL_MSK2_level_edge_event0; // for event 0 : level / edge sensitive:
	                                                        //               2'b00 sensitve to 1 level
	                                                        //               2'b01 sensitve to 0 level
	                                                        //               2'b10 sensitve to positive edge (low to high)
	                                                        //               2'b11 sensitve to negative edge (high to low)
	unsigned int level_edge_event1 : BFW_NETX_XP_EV_CTRL_MSK2_level_edge_event1; // for event 1 : level / edge sensitive:
	                                                        //               2'b00 sensitve to 1 level
	                                                        //               2'b01 sensitve to 0 level
	                                                        //               2'b10 sensitve to positive edge (low to high)
	                                                        //               2'b11 sensitve to negative edge (high to low)
	unsigned int and_or            : BFW_NETX_XP_EV_CTRL_MSK2_and_or;            // and/or bit:
	                                                        // 0 - All bits of mask must fit with events,
	                                                        // 1 - Only one bit of mask must fit with events # default 0
} EC_MASK2_BIT_T;

typedef union {
	unsigned int   val;
	EC_MASK2_BIT_T bf;
} EC_MASK2_T;

// ---------------------------------------------------------------------
// Register ec_mask3
// => JMP-Mask 3
//    Resetvalue : 0x0000ffff
// => Mode: Mode (r/w)
// ---------------------------------------------------------------------

#define REL_NETX_XP_EV_CTRL_MSK3   0x00000068U
#define NETX_XP0_EV_CTRL_MSK3 0x00170068U
#define NETX_XP1_EV_CTRL_MSK3 0x00174068U
#define NETX_XP2_EV_CTRL_MSK3 0x00178068U
#define NETX_XP3_EV_CTRL_MSK3 0x0017C068U

#define MSK_NETX_XP_EV_CTRL_MSK3_sel0              0x000000ffU // [7:0]
#define SRT_NETX_XP_EV_CTRL_MSK3_sel0              0           
#define MSK_NETX_XP_EV_CTRL_MSK3_sel1              0x0000ff00U // [15:8]
#define SRT_NETX_XP_EV_CTRL_MSK3_sel1              8           
#define MSK_NETX_XP_EV_CTRL_MSK3_jmp_adr           0x07ff0000U // [26:16]
#define SRT_NETX_XP_EV_CTRL_MSK3_jmp_adr           16          
#define MSK_NETX_XP_EV_CTRL_MSK3_level_edge_event0 0x18000000U // [28:27]
#define SRT_NETX_XP_EV_CTRL_MSK3_level_edge_event0 27          
#define MSK_NETX_XP_EV_CTRL_MSK3_level_edge_event1 0x60000000U // [30:29]
#define SRT_NETX_XP_EV_CTRL_MSK3_level_edge_event1 29          
#define MSK_NETX_XP_EV_CTRL_MSK3_and_or            0x80000000U // [31]
#define SRT_NETX_XP_EV_CTRL_MSK3_and_or            31          

enum {
	BFW_NETX_XP_EV_CTRL_MSK3_sel0              = 8,  // [7:0]
	BFW_NETX_XP_EV_CTRL_MSK3_sel1              = 8,  // [15:8]
	BFW_NETX_XP_EV_CTRL_MSK3_jmp_adr           = 11, // [26:16]
	BFW_NETX_XP_EV_CTRL_MSK3_level_edge_event0 = 2,  // [28:27]
	BFW_NETX_XP_EV_CTRL_MSK3_level_edge_event1 = 2,  // [30:29]
	BFW_NETX_XP_EV_CTRL_MSK3_and_or            = 1   // [31]
};

typedef struct EC_MASK3_BIT_Ttag {
	unsigned int sel0              : BFW_NETX_XP_EV_CTRL_MSK3_sel0;              // Select of event 0 
	unsigned int sel1              : BFW_NETX_XP_EV_CTRL_MSK3_sel1;              // Select of event 1 
	unsigned int jmp_adr           : BFW_NETX_XP_EV_CTRL_MSK3_jmp_adr;           // jmp address (0-2047) 
	unsigned int level_edge_event0 : BFW_NETX_XP_EV_CTRL_MSK3_level_edge_event0; // for event 0 : level / edge sensitive:
	                                                        //               2'b00 sensitve to 1 level
	                                                        //               2'b01 sensitve to 0 level
	                                                        //               2'b10 sensitve to positive edge (low to high)
	                                                        //               2'b11 sensitve to negative edge (high to low)
	unsigned int level_edge_event1 : BFW_NETX_XP_EV_CTRL_MSK3_level_edge_event1; // for event 1 : level / edge sensitive:
	                                                        //               2'b00 sensitve to 1 level
	                                                        //               2'b01 sensitve to 0 level
	                                                        //               2'b10 sensitve to positive edge (low to high)
	                                                        //               2'b11 sensitve to negative edge (high to low)
	unsigned int and_or            : BFW_NETX_XP_EV_CTRL_MSK3_and_or;            // and/or bit:
	                                                        // 0 - All bits of mask must fit with events,
	                                                        // 1 - Only one bit of mask must fit with events # default 0
} EC_MASK3_BIT_T;

typedef union {
	unsigned int   val;
	EC_MASK3_BIT_T bf;
} EC_MASK3_T;

// ---------------------------------------------------------------------
// Register ec_mask4
// => JMP-Mask 4
//    Resetvalue : 0x0000ffff
// => Mode: Mode (r/w)
// ---------------------------------------------------------------------

#define REL_NETX_XP_EV_CTRL_MSK4   0x0000006CU
#define NETX_XP0_EV_CTRL_MSK4 0x0017006CU
#define NETX_XP1_EV_CTRL_MSK4 0x0017406CU
#define NETX_XP2_EV_CTRL_MSK4 0x0017806CU
#define NETX_XP3_EV_CTRL_MSK4 0x0017C06CU

#define MSK_NETX_XP_EV_CTRL_MSK4_sel0              0x000000ffU // [7:0]
#define SRT_NETX_XP_EV_CTRL_MSK4_sel0              0           
#define MSK_NETX_XP_EV_CTRL_MSK4_sel1              0x0000ff00U // [15:8]
#define SRT_NETX_XP_EV_CTRL_MSK4_sel1              8           
#define MSK_NETX_XP_EV_CTRL_MSK4_jmp_adr           0x07ff0000U // [26:16]
#define SRT_NETX_XP_EV_CTRL_MSK4_jmp_adr           16          
#define MSK_NETX_XP_EV_CTRL_MSK4_level_edge_event0 0x18000000U // [28:27]
#define SRT_NETX_XP_EV_CTRL_MSK4_level_edge_event0 27          
#define MSK_NETX_XP_EV_CTRL_MSK4_level_edge_event1 0x60000000U // [30:29]
#define SRT_NETX_XP_EV_CTRL_MSK4_level_edge_event1 29          
#define MSK_NETX_XP_EV_CTRL_MSK4_and_or            0x80000000U // [31]
#define SRT_NETX_XP_EV_CTRL_MSK4_and_or            31          

enum {
	BFW_NETX_XP_EV_CTRL_MSK4_sel0              = 8,  // [7:0]
	BFW_NETX_XP_EV_CTRL_MSK4_sel1              = 8,  // [15:8]
	BFW_NETX_XP_EV_CTRL_MSK4_jmp_adr           = 11, // [26:16]
	BFW_NETX_XP_EV_CTRL_MSK4_level_edge_event0 = 2,  // [28:27]
	BFW_NETX_XP_EV_CTRL_MSK4_level_edge_event1 = 2,  // [30:29]
	BFW_NETX_XP_EV_CTRL_MSK4_and_or            = 1   // [31]
};

typedef struct EC_MASK4_BIT_Ttag {
	unsigned int sel0              : BFW_NETX_XP_EV_CTRL_MSK4_sel0;              // Select of event 0 
	unsigned int sel1              : BFW_NETX_XP_EV_CTRL_MSK4_sel1;              // Select of event 1 
	unsigned int jmp_adr           : BFW_NETX_XP_EV_CTRL_MSK4_jmp_adr;           // jmp address (0-2047) 
	unsigned int level_edge_event0 : BFW_NETX_XP_EV_CTRL_MSK4_level_edge_event0; // for event 0 : level / edge sensitive:
	                                                        //               2'b00 sensitve to 1 level
	                                                        //               2'b01 sensitve to 0 level
	                                                        //               2'b10 sensitve to positive edge (low to high)
	                                                        //               2'b11 sensitve to negative edge (high to low)
	unsigned int level_edge_event1 : BFW_NETX_XP_EV_CTRL_MSK4_level_edge_event1; // for event 1 : level / edge sensitive:
	                                                        //               2'b00 sensitve to 1 level
	                                                        //               2'b01 sensitve to 0 level
	                                                        //               2'b10 sensitve to positive edge (low to high)
	                                                        //               2'b11 sensitve to negative edge (high to low)
	unsigned int and_or            : BFW_NETX_XP_EV_CTRL_MSK4_and_or;            // and/or bit:
	                                                        // 0 - All bits of mask must fit with events,
	                                                        // 1 - Only one bit of mask must fit with events # default 0
} EC_MASK4_BIT_T;

typedef union {
	unsigned int   val;
	EC_MASK4_BIT_T bf;
} EC_MASK4_T;

// ---------------------------------------------------------------------
// Register ec_mask5
// => JMP-Mask 5
//    Resetvalue : 0x0000ffff
// => Mode: Mode (r/w)
// ---------------------------------------------------------------------

#define REL_NETX_XP_EV_CTRL_MSK5   0x00000070U
#define NETX_XP0_EV_CTRL_MSK5 0x00170070U
#define NETX_XP1_EV_CTRL_MSK5 0x00174070U
#define NETX_XP2_EV_CTRL_MSK5 0x00178070U
#define NETX_XP3_EV_CTRL_MSK5 0x0017C070U

#define MSK_NETX_XP_EV_CTRL_MSK5_sel0              0x000000ffU // [7:0]
#define SRT_NETX_XP_EV_CTRL_MSK5_sel0              0           
#define MSK_NETX_XP_EV_CTRL_MSK5_sel1              0x0000ff00U // [15:8]
#define SRT_NETX_XP_EV_CTRL_MSK5_sel1              8           
#define MSK_NETX_XP_EV_CTRL_MSK5_jmp_adr           0x07ff0000U // [26:16]
#define SRT_NETX_XP_EV_CTRL_MSK5_jmp_adr           16          
#define MSK_NETX_XP_EV_CTRL_MSK5_level_edge_event0 0x18000000U // [28:27]
#define SRT_NETX_XP_EV_CTRL_MSK5_level_edge_event0 27          
#define MSK_NETX_XP_EV_CTRL_MSK5_level_edge_event1 0x60000000U // [30:29]
#define SRT_NETX_XP_EV_CTRL_MSK5_level_edge_event1 29          
#define MSK_NETX_XP_EV_CTRL_MSK5_and_or            0x80000000U // [31]
#define SRT_NETX_XP_EV_CTRL_MSK5_and_or            31          

enum {
	BFW_NETX_XP_EV_CTRL_MSK5_sel0              = 8,  // [7:0]
	BFW_NETX_XP_EV_CTRL_MSK5_sel1              = 8,  // [15:8]
	BFW_NETX_XP_EV_CTRL_MSK5_jmp_adr           = 11, // [26:16]
	BFW_NETX_XP_EV_CTRL_MSK5_level_edge_event0 = 2,  // [28:27]
	BFW_NETX_XP_EV_CTRL_MSK5_level_edge_event1 = 2,  // [30:29]
	BFW_NETX_XP_EV_CTRL_MSK5_and_or            = 1   // [31]
};

typedef struct EC_MASK5_BIT_Ttag {
	unsigned int sel0              : BFW_NETX_XP_EV_CTRL_MSK5_sel0;              // Select of event 0 
	unsigned int sel1              : BFW_NETX_XP_EV_CTRL_MSK5_sel1;              // Select of event 1 
	unsigned int jmp_adr           : BFW_NETX_XP_EV_CTRL_MSK5_jmp_adr;           // jmp address (0-2047) 
	unsigned int level_edge_event0 : BFW_NETX_XP_EV_CTRL_MSK5_level_edge_event0; // for event 0 : level / edge sensitive:
	                                                        //               2'b00 sensitve to 1 level
	                                                        //               2'b01 sensitve to 0 level
	                                                        //               2'b10 sensitve to positive edge (low to high)
	                                                        //               2'b11 sensitve to negative edge (high to low)
	unsigned int level_edge_event1 : BFW_NETX_XP_EV_CTRL_MSK5_level_edge_event1; // for event 1 : level / edge sensitive:
	                                                        //               2'b00 sensitve to 1 level
	                                                        //               2'b01 sensitve to 0 level
	                                                        //               2'b10 sensitve to positive edge (low to high)
	                                                        //               2'b11 sensitve to negative edge (high to low)
	unsigned int and_or            : BFW_NETX_XP_EV_CTRL_MSK5_and_or;            // and/or bit:
	                                                        // 0 - All bits of mask must fit with events,
	                                                        // 1 - Only one bit of mask must fit with events # default 0
} EC_MASK5_BIT_T;

typedef union {
	unsigned int   val;
	EC_MASK5_BIT_T bf;
} EC_MASK5_T;

// ---------------------------------------------------------------------
// Register ec_mask6
// => JMP-Mask 6
//    Resetvalue : 0x0000ffff
// => Mode: Mode (r/w)
// ---------------------------------------------------------------------

#define REL_NETX_XP_EV_CTRL_MSK6   0x00000074U
#define NETX_XP0_EV_CTRL_MSK6 0x00170074U
#define NETX_XP1_EV_CTRL_MSK6 0x00174074U
#define NETX_XP2_EV_CTRL_MSK6 0x00178074U
#define NETX_XP3_EV_CTRL_MSK6 0x0017C074U

#define MSK_NETX_XP_EV_CTRL_MSK6_sel0              0x000000ffU // [7:0]
#define SRT_NETX_XP_EV_CTRL_MSK6_sel0              0           
#define MSK_NETX_XP_EV_CTRL_MSK6_sel1              0x0000ff00U // [15:8]
#define SRT_NETX_XP_EV_CTRL_MSK6_sel1              8           
#define MSK_NETX_XP_EV_CTRL_MSK6_jmp_adr           0x07ff0000U // [26:16]
#define SRT_NETX_XP_EV_CTRL_MSK6_jmp_adr           16          
#define MSK_NETX_XP_EV_CTRL_MSK6_level_edge_event0 0x18000000U // [28:27]
#define SRT_NETX_XP_EV_CTRL_MSK6_level_edge_event0 27          
#define MSK_NETX_XP_EV_CTRL_MSK6_level_edge_event1 0x60000000U // [30:29]
#define SRT_NETX_XP_EV_CTRL_MSK6_level_edge_event1 29          
#define MSK_NETX_XP_EV_CTRL_MSK6_and_or            0x80000000U // [31]
#define SRT_NETX_XP_EV_CTRL_MSK6_and_or            31          

enum {
	BFW_NETX_XP_EV_CTRL_MSK6_sel0              = 8,  // [7:0]
	BFW_NETX_XP_EV_CTRL_MSK6_sel1              = 8,  // [15:8]
	BFW_NETX_XP_EV_CTRL_MSK6_jmp_adr           = 11, // [26:16]
	BFW_NETX_XP_EV_CTRL_MSK6_level_edge_event0 = 2,  // [28:27]
	BFW_NETX_XP_EV_CTRL_MSK6_level_edge_event1 = 2,  // [30:29]
	BFW_NETX_XP_EV_CTRL_MSK6_and_or            = 1   // [31]
};

typedef struct EC_MASK6_BIT_Ttag {
	unsigned int sel0              : BFW_NETX_XP_EV_CTRL_MSK6_sel0;              // Select of event 0 
	unsigned int sel1              : BFW_NETX_XP_EV_CTRL_MSK6_sel1;              // Select of event 1 
	unsigned int jmp_adr           : BFW_NETX_XP_EV_CTRL_MSK6_jmp_adr;           // jmp address (0-2047) 
	unsigned int level_edge_event0 : BFW_NETX_XP_EV_CTRL_MSK6_level_edge_event0; // for event 0 : level / edge sensitive:
	                                                        //               2'b00 sensitve to 1 level
	                                                        //               2'b01 sensitve to 0 level
	                                                        //               2'b10 sensitve to positive edge (low to high)
	                                                        //               2'b11 sensitve to negative edge (high to low)
	unsigned int level_edge_event1 : BFW_NETX_XP_EV_CTRL_MSK6_level_edge_event1; // for event 1 : level / edge sensitive:
	                                                        //               2'b00 sensitve to 1 level
	                                                        //               2'b01 sensitve to 0 level
	                                                        //               2'b10 sensitve to positive edge (low to high)
	                                                        //               2'b11 sensitve to negative edge (high to low)
	unsigned int and_or            : BFW_NETX_XP_EV_CTRL_MSK6_and_or;            // and/or bit:
	                                                        // 0 - All bits of mask must fit with events,
	                                                        // 1 - Only one bit of mask must fit with events # default 0
} EC_MASK6_BIT_T;

typedef union {
	unsigned int   val;
	EC_MASK6_BIT_T bf;
} EC_MASK6_T;

// ---------------------------------------------------------------------
// Register ec_mask7
// => JMP-Mask 7
//    Resetvalue : 0x0000ffff
// => Mode: Mode (r/w)
// ---------------------------------------------------------------------

#define REL_NETX_XP_EV_CTRL_MSK7   0x00000078U
#define NETX_XP0_EV_CTRL_MSK7 0x00170078U
#define NETX_XP1_EV_CTRL_MSK7 0x00174078U
#define NETX_XP2_EV_CTRL_MSK7 0x00178078U
#define NETX_XP3_EV_CTRL_MSK7 0x0017C078U

#define MSK_NETX_XP_EV_CTRL_MSK7_sel0              0x000000ffU // [7:0]
#define SRT_NETX_XP_EV_CTRL_MSK7_sel0              0           
#define MSK_NETX_XP_EV_CTRL_MSK7_sel1              0x0000ff00U // [15:8]
#define SRT_NETX_XP_EV_CTRL_MSK7_sel1              8           
#define MSK_NETX_XP_EV_CTRL_MSK7_jmp_adr           0x07ff0000U // [26:16]
#define SRT_NETX_XP_EV_CTRL_MSK7_jmp_adr           16          
#define MSK_NETX_XP_EV_CTRL_MSK7_level_edge_event0 0x18000000U // [28:27]
#define SRT_NETX_XP_EV_CTRL_MSK7_level_edge_event0 27          
#define MSK_NETX_XP_EV_CTRL_MSK7_level_edge_event1 0x60000000U // [30:29]
#define SRT_NETX_XP_EV_CTRL_MSK7_level_edge_event1 29          
#define MSK_NETX_XP_EV_CTRL_MSK7_and_or            0x80000000U // [31]
#define SRT_NETX_XP_EV_CTRL_MSK7_and_or            31          

enum {
	BFW_NETX_XP_EV_CTRL_MSK7_sel0              = 8,  // [7:0]
	BFW_NETX_XP_EV_CTRL_MSK7_sel1              = 8,  // [15:8]
	BFW_NETX_XP_EV_CTRL_MSK7_jmp_adr           = 11, // [26:16]
	BFW_NETX_XP_EV_CTRL_MSK7_level_edge_event0 = 2,  // [28:27]
	BFW_NETX_XP_EV_CTRL_MSK7_level_edge_event1 = 2,  // [30:29]
	BFW_NETX_XP_EV_CTRL_MSK7_and_or            = 1   // [31]
};

typedef struct EC_MASK7_BIT_Ttag {
	unsigned int sel0              : BFW_NETX_XP_EV_CTRL_MSK7_sel0;              // Select of event 0 
	unsigned int sel1              : BFW_NETX_XP_EV_CTRL_MSK7_sel1;              // Select of event 1 
	unsigned int jmp_adr           : BFW_NETX_XP_EV_CTRL_MSK7_jmp_adr;           // jmp address (0-2047) 
	unsigned int level_edge_event0 : BFW_NETX_XP_EV_CTRL_MSK7_level_edge_event0; // for event 0 : level / edge sensitive:
	                                                        //               2'b00 sensitve to 1 level
	                                                        //               2'b01 sensitve to 0 level
	                                                        //               2'b10 sensitve to positive edge (low to high)
	                                                        //               2'b11 sensitve to negative edge (high to low)
	unsigned int level_edge_event1 : BFW_NETX_XP_EV_CTRL_MSK7_level_edge_event1; // for event 1 : level / edge sensitive:
	                                                        //               2'b00 sensitve to 1 level
	                                                        //               2'b01 sensitve to 0 level
	                                                        //               2'b10 sensitve to positive edge (low to high)
	                                                        //               2'b11 sensitve to negative edge (high to low)
	unsigned int and_or            : BFW_NETX_XP_EV_CTRL_MSK7_and_or;            // and/or bit:
	                                                        // 0 - All bits of mask must fit with events,
	                                                        // 1 - Only one bit of mask must fit with events # default 0
} EC_MASK7_BIT_T;

typedef union {
	unsigned int   val;
	EC_MASK7_BIT_T bf;
} EC_MASK7_T;

// ---------------------------------------------------------------------
// Register xpec_sr0
// => Shared Work Register 0 accessed by xPEC
//    Resetvalue : 0x00000000
// => Mode: Mode (r/w)
// ---------------------------------------------------------------------

#define REL_NETX_XP_SHAR_WRK0   0x000000A0U
#define NETX_XP0_SHAR_WRK0 0x001700A0U
#define NETX_XP1_SHAR_WRK0 0x001740A0U
#define NETX_XP2_SHAR_WRK0 0x001780A0U
#define NETX_XP3_SHAR_WRK0 0x0017C0A0U

#define MSK_NETX_XP_SHAR_WRK0_SR0    0x0000ffffU // [15:0]
#define SRT_NETX_XP_SHAR_WRK0_SR0    0           
#define MSK_NETX_XP_SHAR_WRK0_SR0_15 0xffff0000U // [31:16]
#define SRT_NETX_XP_SHAR_WRK0_SR0_15 16          

enum {
	BFW_NETX_XP_SHAR_WRK0_SR0    = 16, // [15:0]
	BFW_NETX_XP_SHAR_WRK0_SR0_15 = 16  // [31:16]
};

typedef struct XPEC_SR0_BIT_Ttag {
	unsigned int SR0    : BFW_NETX_XP_SHAR_WRK0_SR0;    // Shared Register 
	unsigned int SR0_15 : BFW_NETX_XP_SHAR_WRK0_SR0_15; // Sign extension 
} XPEC_SR0_BIT_T;

typedef union {
	unsigned int   val;
	XPEC_SR0_BIT_T bf;
} XPEC_SR0_T;

// ---------------------------------------------------------------------
// Register xpec_sr1
// => Shared Work Register 1 accessed by xPEC
//    Resetvalue : 0x00000000
// => Mode: Mode (r/w)
// ---------------------------------------------------------------------

#define REL_NETX_XP_SHAR_WRK1   0x000000A4U
#define NETX_XP0_SHAR_WRK1 0x001700A4U
#define NETX_XP1_SHAR_WRK1 0x001740A4U
#define NETX_XP2_SHAR_WRK1 0x001780A4U
#define NETX_XP3_SHAR_WRK1 0x0017C0A4U

#define MSK_NETX_XP_SHAR_WRK1_SR1    0x0000ffffU // [15:0]
#define SRT_NETX_XP_SHAR_WRK1_SR1    0           
#define MSK_NETX_XP_SHAR_WRK1_SR1_15 0xffff0000U // [31:16]
#define SRT_NETX_XP_SHAR_WRK1_SR1_15 16          

enum {
	BFW_NETX_XP_SHAR_WRK1_SR1    = 16, // [15:0]
	BFW_NETX_XP_SHAR_WRK1_SR1_15 = 16  // [31:16]
};

typedef struct XPEC_SR1_BIT_Ttag {
	unsigned int SR1    : BFW_NETX_XP_SHAR_WRK1_SR1;    // Shared Register 
	unsigned int SR1_15 : BFW_NETX_XP_SHAR_WRK1_SR1_15; // Sign extension 
} XPEC_SR1_BIT_T;

typedef union {
	unsigned int   val;
	XPEC_SR1_BIT_T bf;
} XPEC_SR1_T;

// ---------------------------------------------------------------------
// Register xpec_sr2
// => Shared Work Register 2 accessed by xPEC
//    Resetvalue : 0x00000000
// => Mode: Mode (r/w)
// ---------------------------------------------------------------------

#define REL_NETX_XP_SHAR_WRK2   0x000000A8U
#define NETX_XP0_SHAR_WRK2 0x001700A8U
#define NETX_XP1_SHAR_WRK2 0x001740A8U
#define NETX_XP2_SHAR_WRK2 0x001780A8U
#define NETX_XP3_SHAR_WRK2 0x0017C0A8U

#define MSK_NETX_XP_SHAR_WRK2_SR2    0x0000ffffU // [15:0]
#define SRT_NETX_XP_SHAR_WRK2_SR2    0           
#define MSK_NETX_XP_SHAR_WRK2_SR2_15 0xffff0000U // [31:16]
#define SRT_NETX_XP_SHAR_WRK2_SR2_15 16          

enum {
	BFW_NETX_XP_SHAR_WRK2_SR2    = 16, // [15:0]
	BFW_NETX_XP_SHAR_WRK2_SR2_15 = 16  // [31:16]
};

typedef struct XPEC_SR2_BIT_Ttag {
	unsigned int SR2    : BFW_NETX_XP_SHAR_WRK2_SR2;    // Shared Register 
	unsigned int SR2_15 : BFW_NETX_XP_SHAR_WRK2_SR2_15; // Sign extension 
} XPEC_SR2_BIT_T;

typedef union {
	unsigned int   val;
	XPEC_SR2_BIT_T bf;
} XPEC_SR2_T;

// ---------------------------------------------------------------------
// Register xpec_sr3
// => Shared Work Register 3 accessed by xPEC
//    Resetvalue : 0x00000000
// => Mode: Mode (r/w)
// ---------------------------------------------------------------------

#define REL_NETX_XP_SHAR_WRK3   0x000000ACU
#define NETX_XP0_SHAR_WRK3 0x001700ACU
#define NETX_XP1_SHAR_WRK3 0x001740ACU
#define NETX_XP2_SHAR_WRK3 0x001780ACU
#define NETX_XP3_SHAR_WRK3 0x0017C0ACU

#define MSK_NETX_XP_SHAR_WRK3_SR3    0x0000ffffU // [15:0]
#define SRT_NETX_XP_SHAR_WRK3_SR3    0           
#define MSK_NETX_XP_SHAR_WRK3_SR3_15 0xffff0000U // [31:16]
#define SRT_NETX_XP_SHAR_WRK3_SR3_15 16          

enum {
	BFW_NETX_XP_SHAR_WRK3_SR3    = 16, // [15:0]
	BFW_NETX_XP_SHAR_WRK3_SR3_15 = 16  // [31:16]
};

typedef struct XPEC_SR3_BIT_Ttag {
	unsigned int SR3    : BFW_NETX_XP_SHAR_WRK3_SR3;    // Shared Register 
	unsigned int SR3_15 : BFW_NETX_XP_SHAR_WRK3_SR3_15; // Sign extension 
} XPEC_SR3_BIT_T;

typedef union {
	unsigned int   val;
	XPEC_SR3_BIT_T bf;
} XPEC_SR3_T;

// ---------------------------------------------------------------------
// Register xpec_sr4
// => Shared Work Register 4 accessed by xPEC
//    Resetvalue : 0x00000000
// => Mode: Mode (r/w)
// ---------------------------------------------------------------------

#define REL_NETX_XP_SHAR_WRK4   0x000000B0U
#define NETX_XP0_SHAR_WRK4 0x001700B0U
#define NETX_XP1_SHAR_WRK4 0x001740B0U
#define NETX_XP2_SHAR_WRK4 0x001780B0U
#define NETX_XP3_SHAR_WRK4 0x0017C0B0U

#define MSK_NETX_XP_SHAR_WRK4_SR4    0x0000ffffU // [15:0]
#define SRT_NETX_XP_SHAR_WRK4_SR4    0           
#define MSK_NETX_XP_SHAR_WRK4_SR4_15 0xffff0000U // [31:16]
#define SRT_NETX_XP_SHAR_WRK4_SR4_15 16          

enum {
	BFW_NETX_XP_SHAR_WRK4_SR4    = 16, // [15:0]
	BFW_NETX_XP_SHAR_WRK4_SR4_15 = 16  // [31:16]
};

typedef struct XPEC_SR4_BIT_Ttag {
	unsigned int SR4    : BFW_NETX_XP_SHAR_WRK4_SR4;    // Shared Register 
	unsigned int SR4_15 : BFW_NETX_XP_SHAR_WRK4_SR4_15; // Sign extension 
} XPEC_SR4_BIT_T;

typedef union {
	unsigned int   val;
	XPEC_SR4_BIT_T bf;
} XPEC_SR4_T;

// ---------------------------------------------------------------------
// Register xpec_sr5
// => Shared Work Register 5 accessed by xPEC
//    Resetvalue : 0x00000000
// => Mode: Mode (r/w)
// ---------------------------------------------------------------------

#define REL_NETX_XP_SHAR_WRK5   0x000000B4U
#define NETX_XP0_SHAR_WRK5 0x001700B4U
#define NETX_XP1_SHAR_WRK5 0x001740B4U
#define NETX_XP2_SHAR_WRK5 0x001780B4U
#define NETX_XP3_SHAR_WRK5 0x0017C0B4U

#define MSK_NETX_XP_SHAR_WRK5_SR5    0x0000ffffU // [15:0]
#define SRT_NETX_XP_SHAR_WRK5_SR5    0           
#define MSK_NETX_XP_SHAR_WRK5_SR5_15 0xffff0000U // [31:16]
#define SRT_NETX_XP_SHAR_WRK5_SR5_15 16          

enum {
	BFW_NETX_XP_SHAR_WRK5_SR5    = 16, // [15:0]
	BFW_NETX_XP_SHAR_WRK5_SR5_15 = 16  // [31:16]
};

typedef struct XPEC_SR5_BIT_Ttag {
	unsigned int SR5    : BFW_NETX_XP_SHAR_WRK5_SR5;    // Shared Register 
	unsigned int SR5_15 : BFW_NETX_XP_SHAR_WRK5_SR5_15; // Sign extension 
} XPEC_SR5_BIT_T;

typedef union {
	unsigned int   val;
	XPEC_SR5_BIT_T bf;
} XPEC_SR5_T;

// ---------------------------------------------------------------------
// Register xpec_sr6
// => Shared Work Register 6 accessed by xPEC
//    Resetvalue : 0x00000000
// => Mode: Mode (r/w)
// ---------------------------------------------------------------------

#define REL_NETX_XP_SHAR_WRK6   0x000000B8U
#define NETX_XP0_SHAR_WRK6 0x001700B8U
#define NETX_XP1_SHAR_WRK6 0x001740B8U
#define NETX_XP2_SHAR_WRK6 0x001780B8U
#define NETX_XP3_SHAR_WRK6 0x0017C0B8U

#define MSK_NETX_XP_SHAR_WRK6_SR6    0x0000ffffU // [15:0]
#define SRT_NETX_XP_SHAR_WRK6_SR6    0           
#define MSK_NETX_XP_SHAR_WRK6_SR6_15 0xffff0000U // [31:16]
#define SRT_NETX_XP_SHAR_WRK6_SR6_15 16          

enum {
	BFW_NETX_XP_SHAR_WRK6_SR6    = 16, // [15:0]
	BFW_NETX_XP_SHAR_WRK6_SR6_15 = 16  // [31:16]
};

typedef struct XPEC_SR6_BIT_Ttag {
	unsigned int SR6    : BFW_NETX_XP_SHAR_WRK6_SR6;    // Shared Register 
	unsigned int SR6_15 : BFW_NETX_XP_SHAR_WRK6_SR6_15; // Sign extension 
} XPEC_SR6_BIT_T;

typedef union {
	unsigned int   val;
	XPEC_SR6_BIT_T bf;
} XPEC_SR6_T;

// ---------------------------------------------------------------------
// Register xpec_sr7
// => Shared Work Register 7 accessed by xPEC
//    Resetvalue : 0x00000000
// => Mode: Mode (r/w)
// ---------------------------------------------------------------------

#define REL_NETX_XP_SHAR_WRK7   0x000000BCU
#define NETX_XP0_SHAR_WRK7 0x001700BCU
#define NETX_XP1_SHAR_WRK7 0x001740BCU
#define NETX_XP2_SHAR_WRK7 0x001780BCU
#define NETX_XP3_SHAR_WRK7 0x0017C0BCU

#define MSK_NETX_XP_SHAR_WRK7_SR7    0x0000ffffU // [15:0]
#define SRT_NETX_XP_SHAR_WRK7_SR7    0           
#define MSK_NETX_XP_SHAR_WRK7_SR7_15 0xffff0000U // [31:16]
#define SRT_NETX_XP_SHAR_WRK7_SR7_15 16          

enum {
	BFW_NETX_XP_SHAR_WRK7_SR7    = 16, // [15:0]
	BFW_NETX_XP_SHAR_WRK7_SR7_15 = 16  // [31:16]
};

typedef struct XPEC_SR7_BIT_Ttag {
	unsigned int SR7    : BFW_NETX_XP_SHAR_WRK7_SR7;    // Shared Register 
	unsigned int SR7_15 : BFW_NETX_XP_SHAR_WRK7_SR7_15; // Sign extension 
} XPEC_SR7_BIT_T;

typedef union {
	unsigned int   val;
	XPEC_SR7_BIT_T bf;
} XPEC_SR7_T;

// ---------------------------------------------------------------------
// Register xpec_sr8
// => Shared Work Register 8 accessed by xPEC
//    Resetvalue : 0x00000000
// => Mode: Mode (r/w)
// ---------------------------------------------------------------------

#define REL_NETX_XP_SHAR_WRK8   0x000000C0U
#define NETX_XP0_SHAR_WRK8 0x001700C0U
#define NETX_XP1_SHAR_WRK8 0x001740C0U
#define NETX_XP2_SHAR_WRK8 0x001780C0U
#define NETX_XP3_SHAR_WRK8 0x0017C0C0U

#define MSK_NETX_XP_SHAR_WRK8_SR8    0x0000ffffU // [15:0]
#define SRT_NETX_XP_SHAR_WRK8_SR8    0           
#define MSK_NETX_XP_SHAR_WRK8_SR8_15 0xffff0000U // [31:16]
#define SRT_NETX_XP_SHAR_WRK8_SR8_15 16          

enum {
	BFW_NETX_XP_SHAR_WRK8_SR8    = 16, // [15:0]
	BFW_NETX_XP_SHAR_WRK8_SR8_15 = 16  // [31:16]
};

typedef struct XPEC_SR8_BIT_Ttag {
	unsigned int SR8    : BFW_NETX_XP_SHAR_WRK8_SR8;    // Shared Register 
	unsigned int SR8_15 : BFW_NETX_XP_SHAR_WRK8_SR8_15; // Sign extension 
} XPEC_SR8_BIT_T;

typedef union {
	unsigned int   val;
	XPEC_SR8_BIT_T bf;
} XPEC_SR8_T;

// ---------------------------------------------------------------------
// Register xpec_sr9
// => Shared Work Register 9 accessed by xPEC
//    Resetvalue : 0x00000000
// => Mode: Mode (r/w)
// ---------------------------------------------------------------------

#define REL_NETX_XP_SHAR_WRK9   0x000000C4U
#define NETX_XP0_SHAR_WRK9 0x001700C4U
#define NETX_XP1_SHAR_WRK9 0x001740C4U
#define NETX_XP2_SHAR_WRK9 0x001780C4U
#define NETX_XP3_SHAR_WRK9 0x0017C0C4U

#define MSK_NETX_XP_SHAR_WRK9_SR9    0x0000ffffU // [15:0]
#define SRT_NETX_XP_SHAR_WRK9_SR9    0           
#define MSK_NETX_XP_SHAR_WRK9_SR9_15 0xffff0000U // [31:16]
#define SRT_NETX_XP_SHAR_WRK9_SR9_15 16          

enum {
	BFW_NETX_XP_SHAR_WRK9_SR9    = 16, // [15:0]
	BFW_NETX_XP_SHAR_WRK9_SR9_15 = 16  // [31:16]
};

typedef struct XPEC_SR9_BIT_Ttag {
	unsigned int SR9    : BFW_NETX_XP_SHAR_WRK9_SR9;    // Shared Register 
	unsigned int SR9_15 : BFW_NETX_XP_SHAR_WRK9_SR9_15; // Sign extension 
} XPEC_SR9_BIT_T;

typedef union {
	unsigned int   val;
	XPEC_SR9_BIT_T bf;
} XPEC_SR9_T;

// ---------------------------------------------------------------------
// Register xpec_sr10
// => Shared Work Register 10 accessed by xPEC
//    Resetvalue : 0x00000000
// => Mode: Mode (r/w)
// ---------------------------------------------------------------------

#define REL_NETX_XP_SHAR_WRK10   0x000000C8U
#define NETX_XP0_SHAR_WRK10 0x001700C8U
#define NETX_XP1_SHAR_WRK10 0x001740C8U
#define NETX_XP2_SHAR_WRK10 0x001780C8U
#define NETX_XP3_SHAR_WRK10 0x0017C0C8U

#define MSK_NETX_XP_SHAR_WRK10_SR10    0x0000ffffU // [15:0]
#define SRT_NETX_XP_SHAR_WRK10_SR10    0           
#define MSK_NETX_XP_SHAR_WRK10_SR10_15 0xffff0000U // [31:16]
#define SRT_NETX_XP_SHAR_WRK10_SR10_15 16          

enum {
	BFW_NETX_XP_SHAR_WRK10_SR10    = 16, // [15:0]
	BFW_NETX_XP_SHAR_WRK10_SR10_15 = 16  // [31:16]
};

typedef struct XPEC_SR10_BIT_Ttag {
	unsigned int SR10    : BFW_NETX_XP_SHAR_WRK10_SR10;    // Shared Register 
	unsigned int SR10_15 : BFW_NETX_XP_SHAR_WRK10_SR10_15; // Sign extension 
} XPEC_SR10_BIT_T;

typedef union {
	unsigned int    val;
	XPEC_SR10_BIT_T bf;
} XPEC_SR10_T;

// ---------------------------------------------------------------------
// Register xpec_sr11
// => Shared Work Register 11 accessed by xPEC
//    Resetvalue : 0x00000000
// => Mode: Mode (r/w)
// ---------------------------------------------------------------------

#define REL_NETX_XP_SHAR_WRK11   0x000000CCU
#define NETX_XP0_SHAR_WRK11 0x001700CCU
#define NETX_XP1_SHAR_WRK11 0x001740CCU
#define NETX_XP2_SHAR_WRK11 0x001780CCU
#define NETX_XP3_SHAR_WRK11 0x0017C0CCU

#define MSK_NETX_XP_SHAR_WRK11_SR11    0x0000ffffU // [15:0]
#define SRT_NETX_XP_SHAR_WRK11_SR11    0           
#define MSK_NETX_XP_SHAR_WRK11_SR11_15 0xffff0000U // [31:16]
#define SRT_NETX_XP_SHAR_WRK11_SR11_15 16          

enum {
	BFW_NETX_XP_SHAR_WRK11_SR11    = 16, // [15:0]
	BFW_NETX_XP_SHAR_WRK11_SR11_15 = 16  // [31:16]
};

typedef struct XPEC_SR11_BIT_Ttag {
	unsigned int SR11    : BFW_NETX_XP_SHAR_WRK11_SR11;    // Shared Register 
	unsigned int SR11_15 : BFW_NETX_XP_SHAR_WRK11_SR11_15; // Sign extension 
} XPEC_SR11_BIT_T;

typedef union {
	unsigned int    val;
	XPEC_SR11_BIT_T bf;
} XPEC_SR11_T;

// ---------------------------------------------------------------------
// Register xpec_sr12
// => Shared Work Register 12 accessed by xPEC
//    Resetvalue : 0x00000000
// => Mode: Mode (r/w)
// ---------------------------------------------------------------------

#define REL_NETX_XP_SHAR_WRK12   0x000000D0U
#define NETX_XP0_SHAR_WRK12 0x001700D0U
#define NETX_XP1_SHAR_WRK12 0x001740D0U
#define NETX_XP2_SHAR_WRK12 0x001780D0U
#define NETX_XP3_SHAR_WRK12 0x0017C0D0U

#define MSK_NETX_XP_SHAR_WRK12_SR12    0x0000ffffU // [15:0]
#define SRT_NETX_XP_SHAR_WRK12_SR12    0           
#define MSK_NETX_XP_SHAR_WRK12_SR12_15 0xffff0000U // [31:16]
#define SRT_NETX_XP_SHAR_WRK12_SR12_15 16          

enum {
	BFW_NETX_XP_SHAR_WRK12_SR12    = 16, // [15:0]
	BFW_NETX_XP_SHAR_WRK12_SR12_15 = 16  // [31:16]
};

typedef struct XPEC_SR12_BIT_Ttag {
	unsigned int SR12    : BFW_NETX_XP_SHAR_WRK12_SR12;    // Shared Register 
	unsigned int SR12_15 : BFW_NETX_XP_SHAR_WRK12_SR12_15; // Sign extension 
} XPEC_SR12_BIT_T;

typedef union {
	unsigned int    val;
	XPEC_SR12_BIT_T bf;
} XPEC_SR12_T;

// ---------------------------------------------------------------------
// Register xpec_sr13
// => Shared Work Register 13 accessed by xPEC
//    Resetvalue : 0x00000000
// => Mode: Mode (r/w)
// ---------------------------------------------------------------------

#define REL_NETX_XP_SHAR_WRK13   0x000000D4U
#define NETX_XP0_SHAR_WRK13 0x001700D4U
#define NETX_XP1_SHAR_WRK13 0x001740D4U
#define NETX_XP2_SHAR_WRK13 0x001780D4U
#define NETX_XP3_SHAR_WRK13 0x0017C0D4U

#define MSK_NETX_XP_SHAR_WRK13_SR13    0x0000ffffU // [15:0]
#define SRT_NETX_XP_SHAR_WRK13_SR13    0           
#define MSK_NETX_XP_SHAR_WRK13_SR13_15 0xffff0000U // [31:16]
#define SRT_NETX_XP_SHAR_WRK13_SR13_15 16          

enum {
	BFW_NETX_XP_SHAR_WRK13_SR13    = 16, // [15:0]
	BFW_NETX_XP_SHAR_WRK13_SR13_15 = 16  // [31:16]
};

typedef struct XPEC_SR13_BIT_Ttag {
	unsigned int SR13    : BFW_NETX_XP_SHAR_WRK13_SR13;    // Shared Register 
	unsigned int SR13_15 : BFW_NETX_XP_SHAR_WRK13_SR13_15; // Sign extension 
} XPEC_SR13_BIT_T;

typedef union {
	unsigned int    val;
	XPEC_SR13_BIT_T bf;
} XPEC_SR13_T;

// ---------------------------------------------------------------------
// Register xpec_sr14
// => Shared Work Register 14 accessed by xPEC
//    Resetvalue : 0x00000000
// => Mode: Mode (r/w)
// ---------------------------------------------------------------------

#define REL_NETX_XP_SHAR_WRK14   0x000000D8U
#define NETX_XP0_SHAR_WRK14 0x001700D8U
#define NETX_XP1_SHAR_WRK14 0x001740D8U
#define NETX_XP2_SHAR_WRK14 0x001780D8U
#define NETX_XP3_SHAR_WRK14 0x0017C0D8U

#define MSK_NETX_XP_SHAR_WRK14_SR14    0x0000ffffU // [15:0]
#define SRT_NETX_XP_SHAR_WRK14_SR14    0           
#define MSK_NETX_XP_SHAR_WRK14_SR14_15 0xffff0000U // [31:16]
#define SRT_NETX_XP_SHAR_WRK14_SR14_15 16          

enum {
	BFW_NETX_XP_SHAR_WRK14_SR14    = 16, // [15:0]
	BFW_NETX_XP_SHAR_WRK14_SR14_15 = 16  // [31:16]
};

typedef struct XPEC_SR14_BIT_Ttag {
	unsigned int SR14    : BFW_NETX_XP_SHAR_WRK14_SR14;    // Shared Register -- in debug mode (statcfg[14]) read 32 Bit xpec_debug_code 
	unsigned int SR14_15 : BFW_NETX_XP_SHAR_WRK14_SR14_15; // Sign extension 
} XPEC_SR14_BIT_T;

typedef union {
	unsigned int    val;
	XPEC_SR14_BIT_T bf;
} XPEC_SR14_T;

// ---------------------------------------------------------------------
// Register xpec_sr15
// => Shared Work Register 15 accessed by xPEC
//    Resetvalue : 0x00000000
// => Mode: Mode (r/w)
// ---------------------------------------------------------------------

#define REL_NETX_XP_SHAR_WRK15   0x000000DCU
#define NETX_XP0_SHAR_WRK15 0x001700DCU
#define NETX_XP1_SHAR_WRK15 0x001740DCU
#define NETX_XP2_SHAR_WRK15 0x001780DCU
#define NETX_XP3_SHAR_WRK15 0x0017C0DCU

#define MSK_NETX_XP_SHAR_WRK15_SR15    0x0000ffffU // [15:0]
#define SRT_NETX_XP_SHAR_WRK15_SR15    0           
#define MSK_NETX_XP_SHAR_WRK15_SR15_15 0xffff0000U // [31:16]
#define SRT_NETX_XP_SHAR_WRK15_SR15_15 16          

enum {
	BFW_NETX_XP_SHAR_WRK15_SR15    = 16, // [15:0]
	BFW_NETX_XP_SHAR_WRK15_SR15_15 = 16  // [31:16]
};

typedef struct XPEC_SR15_BIT_Ttag {
	unsigned int SR15    : BFW_NETX_XP_SHAR_WRK15_SR15;    // Shared Register -- in debug mode (statcfg[14]) read 11 Bit xpec_debug_pc  
	unsigned int SR15_15 : BFW_NETX_XP_SHAR_WRK15_SR15_15; // Sign extension 
} XPEC_SR15_BIT_T;

typedef union {
	unsigned int    val;
	XPEC_SR15_BIT_T bf;
} XPEC_SR15_T;

// ---------------------------------------------------------------------
// Register statcfg0
// => xMAC0 Shared Config/Status Register
//    Resetvalue : 0x00000088
// => Mode: Mode (r/w)
// ---------------------------------------------------------------------

#define REL_NETX_XP_SHAR_XM_STAT_CFG0   0x000000E0U
#define NETX_XP0_SHAR_XM_STAT_CFG0 0x001700E0U
#define NETX_XP1_SHAR_XM_STAT_CFG0 0x001740E0U
#define NETX_XP2_SHAR_XM_STAT_CFG0 0x001780E0U
#define NETX_XP3_SHAR_XM_STAT_CFG0 0x0017C0E0U

#define MSK_NETX_XP_SHAR_XM_STAT_CFG0_rx_nof_bits   0x0000000fU // [3:0]
#define SRT_NETX_XP_SHAR_XM_STAT_CFG0_rx_nof_bits   0           
#define MSK_NETX_XP_SHAR_XM_STAT_CFG0_tx_nof_bits   0x000000f0U // [7:4]
#define SRT_NETX_XP_SHAR_XM_STAT_CFG0_tx_nof_bits   4           
#define MSK_NETX_XP_SHAR_XM_STAT_CFG0_rx_shift_lr   0x00000100U // [8]
#define SRT_NETX_XP_SHAR_XM_STAT_CFG0_rx_shift_lr   8           
#define MSK_NETX_XP_SHAR_XM_STAT_CFG0_tx_shift_lr   0x00000200U // [9]
#define SRT_NETX_XP_SHAR_XM_STAT_CFG0_tx_shift_lr   9           
#define MSK_NETX_XP_SHAR_XM_STAT_CFG0_reset_rx_fifo 0x00000400U // [10]
#define SRT_NETX_XP_SHAR_XM_STAT_CFG0_reset_rx_fifo 10          
#define MSK_NETX_XP_SHAR_XM_STAT_CFG0_reset_tx_fifo 0x00000800U // [11]
#define SRT_NETX_XP_SHAR_XM_STAT_CFG0_reset_tx_fifo 11          
#define MSK_NETX_XP_SHAR_XM_STAT_CFG0_gpio0_out     0x00001000U // [12]
#define SRT_NETX_XP_SHAR_XM_STAT_CFG0_gpio0_out     12          
#define MSK_NETX_XP_SHAR_XM_STAT_CFG0_gpio0_oe      0x00002000U // [13]
#define SRT_NETX_XP_SHAR_XM_STAT_CFG0_gpio0_oe      13          
#define MSK_NETX_XP_SHAR_XM_STAT_CFG0_gpio1_out     0x00004000U // [14]
#define SRT_NETX_XP_SHAR_XM_STAT_CFG0_gpio1_out     14          
#define MSK_NETX_XP_SHAR_XM_STAT_CFG0_gpio1_oe      0x00008000U // [15]
#define SRT_NETX_XP_SHAR_XM_STAT_CFG0_gpio1_oe      15          
#define MSK_NETX_XP_SHAR_XM_STAT_CFG0_gpio0_in      0x00010000U // [16]
#define SRT_NETX_XP_SHAR_XM_STAT_CFG0_gpio0_in      16          
#define MSK_NETX_XP_SHAR_XM_STAT_CFG0_gpio1_in      0x00020000U // [17]
#define SRT_NETX_XP_SHAR_XM_STAT_CFG0_gpio1_in      17          
#define MSK_NETX_XP_SHAR_XM_STAT_CFG0_rx_rdy        0x00040000U // [18]
#define SRT_NETX_XP_SHAR_XM_STAT_CFG0_rx_rdy        18          
#define MSK_NETX_XP_SHAR_XM_STAT_CFG0_rx_ovf        0x00080000U // [19]
#define SRT_NETX_XP_SHAR_XM_STAT_CFG0_rx_ovf        19          
#define MSK_NETX_XP_SHAR_XM_STAT_CFG0_tx_nxt        0x00100000U // [20]
#define SRT_NETX_XP_SHAR_XM_STAT_CFG0_tx_nxt        20          
#define MSK_NETX_XP_SHAR_XM_STAT_CFG0_tx_ufl        0x00200000U // [21]
#define SRT_NETX_XP_SHAR_XM_STAT_CFG0_tx_ufl        21          
#define MSK_NETX_XP_SHAR_XM_STAT_CFG0_utx_empty     0x00400000U // [22]
#define SRT_NETX_XP_SHAR_XM_STAT_CFG0_utx_empty     22          
#define MSK_NETX_XP_SHAR_XM_STAT_CFG0_brec          0x00800000U // [23]
#define SRT_NETX_XP_SHAR_XM_STAT_CFG0_brec          23          
#define MSK_NETX_XP_SHAR_XM_STAT_CFG0_btran         0x01000000U // [24]
#define SRT_NETX_XP_SHAR_XM_STAT_CFG0_btran         24          
#define MSK_NETX_XP_SHAR_XM_STAT_CFG0_stat_rpu      0x02000000U // [25]
#define SRT_NETX_XP_SHAR_XM_STAT_CFG0_stat_rpu      25          
#define MSK_NETX_XP_SHAR_XM_STAT_CFG0_stat_tpu      0x04000000U // [26]
#define SRT_NETX_XP_SHAR_XM_STAT_CFG0_stat_tpu      26          
#define MSK_NETX_XP_SHAR_XM_STAT_CFG0_phy_led0      0x10000000U // [28]
#define SRT_NETX_XP_SHAR_XM_STAT_CFG0_phy_led0      28          
#define MSK_NETX_XP_SHAR_XM_STAT_CFG0_phy_led1      0x20000000U // [29]
#define SRT_NETX_XP_SHAR_XM_STAT_CFG0_phy_led1      29          
#define MSK_NETX_XP_SHAR_XM_STAT_CFG0_phy_led2      0x40000000U // [30]
#define SRT_NETX_XP_SHAR_XM_STAT_CFG0_phy_led2      30          
#define MSK_NETX_XP_SHAR_XM_STAT_CFG0_phy_led3      0x80000000U // [31]
#define SRT_NETX_XP_SHAR_XM_STAT_CFG0_phy_led3      31          

enum {
	BFW_NETX_XP_SHAR_XM_STAT_CFG0_rx_nof_bits   = 4, // [3:0]
	BFW_NETX_XP_SHAR_XM_STAT_CFG0_tx_nof_bits   = 4, // [7:4]
	BFW_NETX_XP_SHAR_XM_STAT_CFG0_rx_shift_lr   = 1, // [8]
	BFW_NETX_XP_SHAR_XM_STAT_CFG0_tx_shift_lr   = 1, // [9]
	BFW_NETX_XP_SHAR_XM_STAT_CFG0_reset_rx_fifo = 1, // [10]
	BFW_NETX_XP_SHAR_XM_STAT_CFG0_reset_tx_fifo = 1, // [11]
	BFW_NETX_XP_SHAR_XM_STAT_CFG0_gpio0_out     = 1, // [12]
	BFW_NETX_XP_SHAR_XM_STAT_CFG0_gpio0_oe      = 1, // [13]
	BFW_NETX_XP_SHAR_XM_STAT_CFG0_gpio1_out     = 1, // [14]
	BFW_NETX_XP_SHAR_XM_STAT_CFG0_gpio1_oe      = 1, // [15]
	BFW_NETX_XP_SHAR_XM_STAT_CFG0_gpio0_in      = 1, // [16]
	BFW_NETX_XP_SHAR_XM_STAT_CFG0_gpio1_in      = 1, // [17]
	BFW_NETX_XP_SHAR_XM_STAT_CFG0_rx_rdy        = 1, // [18]
	BFW_NETX_XP_SHAR_XM_STAT_CFG0_rx_ovf        = 1, // [19]
	BFW_NETX_XP_SHAR_XM_STAT_CFG0_tx_nxt        = 1, // [20]
	BFW_NETX_XP_SHAR_XM_STAT_CFG0_tx_ufl        = 1, // [21]
	BFW_NETX_XP_SHAR_XM_STAT_CFG0_utx_empty     = 1, // [22]
	BFW_NETX_XP_SHAR_XM_STAT_CFG0_brec          = 1, // [23]
	BFW_NETX_XP_SHAR_XM_STAT_CFG0_btran         = 1, // [24]
	BFW_NETX_XP_SHAR_XM_STAT_CFG0_stat_rpu      = 1, // [25]
	BFW_NETX_XP_SHAR_XM_STAT_CFG0_stat_tpu      = 1, // [26]
	BFW_NETX_XP_SHAR_XM_STAT_CFG0_reserved1     = 1, // [27]
	BFW_NETX_XP_SHAR_XM_STAT_CFG0_phy_led0      = 1, // [28]
	BFW_NETX_XP_SHAR_XM_STAT_CFG0_phy_led1      = 1, // [29]
	BFW_NETX_XP_SHAR_XM_STAT_CFG0_phy_led2      = 1, // [30]
	BFW_NETX_XP_SHAR_XM_STAT_CFG0_phy_led3      = 1  // [31]
};

typedef struct STATCFG0_BIT_Ttag {
	unsigned int rx_nof_bits   : BFW_NETX_XP_SHAR_XM_STAT_CFG0_rx_nof_bits;   // Number of bits written by SBU to rx-register, only used for rx_hw_count 
	unsigned int tx_nof_bits   : BFW_NETX_XP_SHAR_XM_STAT_CFG0_tx_nof_bits;   // Number of bits read by OBU from tx-register 
	unsigned int rx_shift_lr   : BFW_NETX_XP_SHAR_XM_STAT_CFG0_rx_shift_lr;   // 1: SBU reads incoming bits to position 0 of register rx and shifts rx left, 
	                                                        // 0: SBU reads incoming bits to position 15 of register rx and shifts rx right
	unsigned int tx_shift_lr   : BFW_NETX_XP_SHAR_XM_STAT_CFG0_tx_shift_lr;   // 1: OBU reads outgoing bits from position 15 of register tx and shifts tx left, 
	                                                        // 0: OBU reads outgoing bits from position 0 of register tx and shifts tx right
	unsigned int reset_rx_fifo : BFW_NETX_XP_SHAR_XM_STAT_CFG0_reset_rx_fifo; // reset URX_FIFO and rx_ovf bit inside status_shared register 
	unsigned int reset_tx_fifo : BFW_NETX_XP_SHAR_XM_STAT_CFG0_reset_tx_fifo; // reset UTX_FIFO and tx_ufl bit inside status_shared register 
	unsigned int gpio0_out     : BFW_NETX_XP_SHAR_XM_STAT_CFG0_gpio0_out;     // General Purpose IO 0 output 
	unsigned int gpio0_oe      : BFW_NETX_XP_SHAR_XM_STAT_CFG0_gpio0_oe;      // General Purpose IO 0 output enable 
	unsigned int gpio1_out     : BFW_NETX_XP_SHAR_XM_STAT_CFG0_gpio1_out;     // General Purpose IO 1 output 
	unsigned int gpio1_oe      : BFW_NETX_XP_SHAR_XM_STAT_CFG0_gpio1_oe;      // General Purpose IO 1 output enable 
	unsigned int gpio0_in      : BFW_NETX_XP_SHAR_XM_STAT_CFG0_gpio0_in;      // value at external gpio1 pin
	unsigned int gpio1_in      : BFW_NETX_XP_SHAR_XM_STAT_CFG0_gpio1_in;      // value at external gpio2 pin
	unsigned int rx_rdy        : BFW_NETX_XP_SHAR_XM_STAT_CFG0_rx_rdy;        // received bytes are valid at output of URX_FIFO
	unsigned int rx_ovf        : BFW_NETX_XP_SHAR_XM_STAT_CFG0_rx_ovf;        // receive overflow (too much data in URX_FIFO)
	unsigned int tx_nxt        : BFW_NETX_XP_SHAR_XM_STAT_CFG0_tx_nxt;        // put next tx_word to UTX_FIFO: at least one entry of UTX_FIFO is empty
	unsigned int tx_ufl        : BFW_NETX_XP_SHAR_XM_STAT_CFG0_tx_ufl;        // transmit underflow (not enough data in UTX_FIFO)
	unsigned int utx_empty     : BFW_NETX_XP_SHAR_XM_STAT_CFG0_utx_empty;     // UTX_FIFO is empty
	unsigned int brec          : BFW_NETX_XP_SHAR_XM_STAT_CFG0_brec;          // bit_received (active for 1 cc)
	unsigned int btran         : BFW_NETX_XP_SHAR_XM_STAT_CFG0_btran;         // bit_transmitted (active for 1 cc)
	unsigned int stat_rpu      : BFW_NETX_XP_SHAR_XM_STAT_CFG0_stat_rpu;      // set and reset by RPU command bits
	unsigned int stat_tpu      : BFW_NETX_XP_SHAR_XM_STAT_CFG0_stat_tpu;      // set and reset by TPU command bits
	unsigned int reserved1     : BFW_NETX_XP_SHAR_XM_STAT_CFG0_reserved1;     // reserved
	unsigned int phy_led0      : BFW_NETX_XP_SHAR_XM_STAT_CFG0_phy_led0;      // Internal Phy0 LED0, usually link_status
	unsigned int phy_led1      : BFW_NETX_XP_SHAR_XM_STAT_CFG0_phy_led1;      // Internal Phy0 LED1, usually activity
	unsigned int phy_led2      : BFW_NETX_XP_SHAR_XM_STAT_CFG0_phy_led2;      // Internal Phy0 LED2, usually speed100
	unsigned int phy_led3      : BFW_NETX_XP_SHAR_XM_STAT_CFG0_phy_led3;      // Internal Phy0 LED3, usually full_duplex
} STATCFG0_BIT_T;

typedef union {
	unsigned int   val;
	STATCFG0_BIT_T bf;
} STATCFG0_T;

// ---------------------------------------------------------------------
// Register statcfg1
// => xMAC1 Shared Config/Status Register
//    Resetvalue : 0x00000088
// => Mode: Mode (r/w)
// ---------------------------------------------------------------------

#define REL_NETX_XP_SHAR_XM_STAT_CFG1   0x000000E4U
#define NETX_XP0_SHAR_XM_STAT_CFG1 0x001700E4U
#define NETX_XP1_SHAR_XM_STAT_CFG1 0x001740E4U
#define NETX_XP2_SHAR_XM_STAT_CFG1 0x001780E4U
#define NETX_XP3_SHAR_XM_STAT_CFG1 0x0017C0E4U

#define MSK_NETX_XP_SHAR_XM_STAT_CFG1_rx_nof_bits   0x0000000fU // [3:0]
#define SRT_NETX_XP_SHAR_XM_STAT_CFG1_rx_nof_bits   0           
#define MSK_NETX_XP_SHAR_XM_STAT_CFG1_tx_nof_bits   0x000000f0U // [7:4]
#define SRT_NETX_XP_SHAR_XM_STAT_CFG1_tx_nof_bits   4           
#define MSK_NETX_XP_SHAR_XM_STAT_CFG1_rx_shift_lr   0x00000100U // [8]
#define SRT_NETX_XP_SHAR_XM_STAT_CFG1_rx_shift_lr   8           
#define MSK_NETX_XP_SHAR_XM_STAT_CFG1_tx_shift_lr   0x00000200U // [9]
#define SRT_NETX_XP_SHAR_XM_STAT_CFG1_tx_shift_lr   9           
#define MSK_NETX_XP_SHAR_XM_STAT_CFG1_reset_rx_fifo 0x00000400U // [10]
#define SRT_NETX_XP_SHAR_XM_STAT_CFG1_reset_rx_fifo 10          
#define MSK_NETX_XP_SHAR_XM_STAT_CFG1_reset_tx_fifo 0x00000800U // [11]
#define SRT_NETX_XP_SHAR_XM_STAT_CFG1_reset_tx_fifo 11          
#define MSK_NETX_XP_SHAR_XM_STAT_CFG1_gpio0_out     0x00001000U // [12]
#define SRT_NETX_XP_SHAR_XM_STAT_CFG1_gpio0_out     12          
#define MSK_NETX_XP_SHAR_XM_STAT_CFG1_gpio0_oe      0x00002000U // [13]
#define SRT_NETX_XP_SHAR_XM_STAT_CFG1_gpio0_oe      13          
#define MSK_NETX_XP_SHAR_XM_STAT_CFG1_gpio1_out     0x00004000U // [14]
#define SRT_NETX_XP_SHAR_XM_STAT_CFG1_gpio1_out     14          
#define MSK_NETX_XP_SHAR_XM_STAT_CFG1_gpio1_oe      0x00008000U // [15]
#define SRT_NETX_XP_SHAR_XM_STAT_CFG1_gpio1_oe      15          
#define MSK_NETX_XP_SHAR_XM_STAT_CFG1_gpio0_in      0x00010000U // [16]
#define SRT_NETX_XP_SHAR_XM_STAT_CFG1_gpio0_in      16          
#define MSK_NETX_XP_SHAR_XM_STAT_CFG1_gpio1_in      0x00020000U // [17]
#define SRT_NETX_XP_SHAR_XM_STAT_CFG1_gpio1_in      17          
#define MSK_NETX_XP_SHAR_XM_STAT_CFG1_rx_rdy        0x00040000U // [18]
#define SRT_NETX_XP_SHAR_XM_STAT_CFG1_rx_rdy        18          
#define MSK_NETX_XP_SHAR_XM_STAT_CFG1_rx_ovf        0x00080000U // [19]
#define SRT_NETX_XP_SHAR_XM_STAT_CFG1_rx_ovf        19          
#define MSK_NETX_XP_SHAR_XM_STAT_CFG1_tx_nxt        0x00100000U // [20]
#define SRT_NETX_XP_SHAR_XM_STAT_CFG1_tx_nxt        20          
#define MSK_NETX_XP_SHAR_XM_STAT_CFG1_tx_ufl        0x00200000U // [21]
#define SRT_NETX_XP_SHAR_XM_STAT_CFG1_tx_ufl        21          
#define MSK_NETX_XP_SHAR_XM_STAT_CFG1_utx_empty     0x00400000U // [22]
#define SRT_NETX_XP_SHAR_XM_STAT_CFG1_utx_empty     22          
#define MSK_NETX_XP_SHAR_XM_STAT_CFG1_brec          0x00800000U // [23]
#define SRT_NETX_XP_SHAR_XM_STAT_CFG1_brec          23          
#define MSK_NETX_XP_SHAR_XM_STAT_CFG1_btran         0x01000000U // [24]
#define SRT_NETX_XP_SHAR_XM_STAT_CFG1_btran         24          
#define MSK_NETX_XP_SHAR_XM_STAT_CFG1_stat_rpu      0x02000000U // [25]
#define SRT_NETX_XP_SHAR_XM_STAT_CFG1_stat_rpu      25          
#define MSK_NETX_XP_SHAR_XM_STAT_CFG1_stat_tpu      0x04000000U // [26]
#define SRT_NETX_XP_SHAR_XM_STAT_CFG1_stat_tpu      26          
#define MSK_NETX_XP_SHAR_XM_STAT_CFG1_phy_led0      0x10000000U // [28]
#define SRT_NETX_XP_SHAR_XM_STAT_CFG1_phy_led0      28          
#define MSK_NETX_XP_SHAR_XM_STAT_CFG1_phy_led1      0x20000000U // [29]
#define SRT_NETX_XP_SHAR_XM_STAT_CFG1_phy_led1      29          
#define MSK_NETX_XP_SHAR_XM_STAT_CFG1_phy_led2      0x40000000U // [30]
#define SRT_NETX_XP_SHAR_XM_STAT_CFG1_phy_led2      30          
#define MSK_NETX_XP_SHAR_XM_STAT_CFG1_phy_led3      0x80000000U // [31]
#define SRT_NETX_XP_SHAR_XM_STAT_CFG1_phy_led3      31          

enum {
	BFW_NETX_XP_SHAR_XM_STAT_CFG1_rx_nof_bits   = 4, // [3:0]
	BFW_NETX_XP_SHAR_XM_STAT_CFG1_tx_nof_bits   = 4, // [7:4]
	BFW_NETX_XP_SHAR_XM_STAT_CFG1_rx_shift_lr   = 1, // [8]
	BFW_NETX_XP_SHAR_XM_STAT_CFG1_tx_shift_lr   = 1, // [9]
	BFW_NETX_XP_SHAR_XM_STAT_CFG1_reset_rx_fifo = 1, // [10]
	BFW_NETX_XP_SHAR_XM_STAT_CFG1_reset_tx_fifo = 1, // [11]
	BFW_NETX_XP_SHAR_XM_STAT_CFG1_gpio0_out     = 1, // [12]
	BFW_NETX_XP_SHAR_XM_STAT_CFG1_gpio0_oe      = 1, // [13]
	BFW_NETX_XP_SHAR_XM_STAT_CFG1_gpio1_out     = 1, // [14]
	BFW_NETX_XP_SHAR_XM_STAT_CFG1_gpio1_oe      = 1, // [15]
	BFW_NETX_XP_SHAR_XM_STAT_CFG1_gpio0_in      = 1, // [16]
	BFW_NETX_XP_SHAR_XM_STAT_CFG1_gpio1_in      = 1, // [17]
	BFW_NETX_XP_SHAR_XM_STAT_CFG1_rx_rdy        = 1, // [18]
	BFW_NETX_XP_SHAR_XM_STAT_CFG1_rx_ovf        = 1, // [19]
	BFW_NETX_XP_SHAR_XM_STAT_CFG1_tx_nxt        = 1, // [20]
	BFW_NETX_XP_SHAR_XM_STAT_CFG1_tx_ufl        = 1, // [21]
	BFW_NETX_XP_SHAR_XM_STAT_CFG1_utx_empty     = 1, // [22]
	BFW_NETX_XP_SHAR_XM_STAT_CFG1_brec          = 1, // [23]
	BFW_NETX_XP_SHAR_XM_STAT_CFG1_btran         = 1, // [24]
	BFW_NETX_XP_SHAR_XM_STAT_CFG1_stat_rpu      = 1, // [25]
	BFW_NETX_XP_SHAR_XM_STAT_CFG1_stat_tpu      = 1, // [26]
	BFW_NETX_XP_SHAR_XM_STAT_CFG1_reserved1     = 1, // [27]
	BFW_NETX_XP_SHAR_XM_STAT_CFG1_phy_led0      = 1, // [28]
	BFW_NETX_XP_SHAR_XM_STAT_CFG1_phy_led1      = 1, // [29]
	BFW_NETX_XP_SHAR_XM_STAT_CFG1_phy_led2      = 1, // [30]
	BFW_NETX_XP_SHAR_XM_STAT_CFG1_phy_led3      = 1  // [31]
};

typedef struct STATCFG1_BIT_Ttag {
	unsigned int rx_nof_bits   : BFW_NETX_XP_SHAR_XM_STAT_CFG1_rx_nof_bits;   // Number of bits written by SBU to rx-register, only used for rx_hw_count 
	unsigned int tx_nof_bits   : BFW_NETX_XP_SHAR_XM_STAT_CFG1_tx_nof_bits;   // Number of bits read by OBU from tx-register 
	unsigned int rx_shift_lr   : BFW_NETX_XP_SHAR_XM_STAT_CFG1_rx_shift_lr;   // 1: SBU reads incoming bits to position 0 of register rx and shifts rx left, 
	                                                        // 0: SBU reads incoming bits to position 15 of register rx and shifts rx right
	unsigned int tx_shift_lr   : BFW_NETX_XP_SHAR_XM_STAT_CFG1_tx_shift_lr;   // 1: OBU reads outgoing bits from position 15 of register tx and shifts tx left, 
	                                                        // 0: OBU reads outgoing bits from position 0 of register tx and shifts tx right
	unsigned int reset_rx_fifo : BFW_NETX_XP_SHAR_XM_STAT_CFG1_reset_rx_fifo; // reset URX_FIFO and rx_ovf bit inside status_shared register 
	unsigned int reset_tx_fifo : BFW_NETX_XP_SHAR_XM_STAT_CFG1_reset_tx_fifo; // reset UTX_FIFO and tx_ufl bit inside status_shared register 
	unsigned int gpio0_out     : BFW_NETX_XP_SHAR_XM_STAT_CFG1_gpio0_out;     // General Purpose IO 0 output 
	unsigned int gpio0_oe      : BFW_NETX_XP_SHAR_XM_STAT_CFG1_gpio0_oe;      // General Purpose IO 0 output enable 
	unsigned int gpio1_out     : BFW_NETX_XP_SHAR_XM_STAT_CFG1_gpio1_out;     // General Purpose IO 1 output 
	unsigned int gpio1_oe      : BFW_NETX_XP_SHAR_XM_STAT_CFG1_gpio1_oe;      // General Purpose IO 1 output enable 
	unsigned int gpio0_in      : BFW_NETX_XP_SHAR_XM_STAT_CFG1_gpio0_in;      // value at external gpio1 pin
	unsigned int gpio1_in      : BFW_NETX_XP_SHAR_XM_STAT_CFG1_gpio1_in;      // value at external gpio2 pin
	unsigned int rx_rdy        : BFW_NETX_XP_SHAR_XM_STAT_CFG1_rx_rdy;        // received bytes are valid at output of URX_FIFO
	unsigned int rx_ovf        : BFW_NETX_XP_SHAR_XM_STAT_CFG1_rx_ovf;        // receive overflow (too much data in URX_FIFO)
	unsigned int tx_nxt        : BFW_NETX_XP_SHAR_XM_STAT_CFG1_tx_nxt;        // put next tx_word to UTX_FIFO: at least one entry of UTX_FIFO is empty
	unsigned int tx_ufl        : BFW_NETX_XP_SHAR_XM_STAT_CFG1_tx_ufl;        // transmit underflow (not enough data in UTX_FIFO)
	unsigned int utx_empty     : BFW_NETX_XP_SHAR_XM_STAT_CFG1_utx_empty;     // UTX_FIFO is empty
	unsigned int brec          : BFW_NETX_XP_SHAR_XM_STAT_CFG1_brec;          // bit_received (active for 1 cc)
	unsigned int btran         : BFW_NETX_XP_SHAR_XM_STAT_CFG1_btran;         // bit_transmitted (active for 1 cc)
	unsigned int stat_rpu      : BFW_NETX_XP_SHAR_XM_STAT_CFG1_stat_rpu;      // set and reset by RPU command bits
	unsigned int stat_tpu      : BFW_NETX_XP_SHAR_XM_STAT_CFG1_stat_tpu;      // set and reset by TPU command bits
	unsigned int reserved1     : BFW_NETX_XP_SHAR_XM_STAT_CFG1_reserved1;     // reserved
	unsigned int phy_led0      : BFW_NETX_XP_SHAR_XM_STAT_CFG1_phy_led0;      // Internal Phy1 LED0, usually link_status
	unsigned int phy_led1      : BFW_NETX_XP_SHAR_XM_STAT_CFG1_phy_led1;      // Internal Phy1 LED1, usually activity
	unsigned int phy_led2      : BFW_NETX_XP_SHAR_XM_STAT_CFG1_phy_led2;      // Internal Phy1 LED2, usually speed100
	unsigned int phy_led3      : BFW_NETX_XP_SHAR_XM_STAT_CFG1_phy_led3;      // Internal Phy1 LED3, usually full_duplex
} STATCFG1_BIT_T;

typedef union {
	unsigned int   val;
	STATCFG1_BIT_T bf;
} STATCFG1_T;

// ---------------------------------------------------------------------
// Register statcfg2
// => xMAC2 Shared Config/Status Register
//    Resetvalue : 0x00000088
// => Mode: Mode (r/w)
// ---------------------------------------------------------------------

#define REL_NETX_XP_SHAR_XM_STAT_CFG2   0x000000E8U
#define NETX_XP0_SHAR_XM_STAT_CFG2 0x001700E8U
#define NETX_XP1_SHAR_XM_STAT_CFG2 0x001740E8U
#define NETX_XP2_SHAR_XM_STAT_CFG2 0x001780E8U
#define NETX_XP3_SHAR_XM_STAT_CFG2 0x0017C0E8U

#define MSK_NETX_XP_SHAR_XM_STAT_CFG2_rx_nof_bits   0x0000000fU // [3:0]
#define SRT_NETX_XP_SHAR_XM_STAT_CFG2_rx_nof_bits   0           
#define MSK_NETX_XP_SHAR_XM_STAT_CFG2_tx_nof_bits   0x000000f0U // [7:4]
#define SRT_NETX_XP_SHAR_XM_STAT_CFG2_tx_nof_bits   4           
#define MSK_NETX_XP_SHAR_XM_STAT_CFG2_rx_shift_lr   0x00000100U // [8]
#define SRT_NETX_XP_SHAR_XM_STAT_CFG2_rx_shift_lr   8           
#define MSK_NETX_XP_SHAR_XM_STAT_CFG2_tx_shift_lr   0x00000200U // [9]
#define SRT_NETX_XP_SHAR_XM_STAT_CFG2_tx_shift_lr   9           
#define MSK_NETX_XP_SHAR_XM_STAT_CFG2_reset_rx_fifo 0x00000400U // [10]
#define SRT_NETX_XP_SHAR_XM_STAT_CFG2_reset_rx_fifo 10          
#define MSK_NETX_XP_SHAR_XM_STAT_CFG2_reset_tx_fifo 0x00000800U // [11]
#define SRT_NETX_XP_SHAR_XM_STAT_CFG2_reset_tx_fifo 11          
#define MSK_NETX_XP_SHAR_XM_STAT_CFG2_gpio0_out     0x00001000U // [12]
#define SRT_NETX_XP_SHAR_XM_STAT_CFG2_gpio0_out     12          
#define MSK_NETX_XP_SHAR_XM_STAT_CFG2_gpio0_oe      0x00002000U // [13]
#define SRT_NETX_XP_SHAR_XM_STAT_CFG2_gpio0_oe      13          
#define MSK_NETX_XP_SHAR_XM_STAT_CFG2_gpio1_out     0x00004000U // [14]
#define SRT_NETX_XP_SHAR_XM_STAT_CFG2_gpio1_out     14          
#define MSK_NETX_XP_SHAR_XM_STAT_CFG2_gpio1_oe      0x00008000U // [15]
#define SRT_NETX_XP_SHAR_XM_STAT_CFG2_gpio1_oe      15          
#define MSK_NETX_XP_SHAR_XM_STAT_CFG2_gpio0_in      0x00010000U // [16]
#define SRT_NETX_XP_SHAR_XM_STAT_CFG2_gpio0_in      16          
#define MSK_NETX_XP_SHAR_XM_STAT_CFG2_gpio1_in      0x00020000U // [17]
#define SRT_NETX_XP_SHAR_XM_STAT_CFG2_gpio1_in      17          
#define MSK_NETX_XP_SHAR_XM_STAT_CFG2_rx_rdy        0x00040000U // [18]
#define SRT_NETX_XP_SHAR_XM_STAT_CFG2_rx_rdy        18          
#define MSK_NETX_XP_SHAR_XM_STAT_CFG2_rx_ovf        0x00080000U // [19]
#define SRT_NETX_XP_SHAR_XM_STAT_CFG2_rx_ovf        19          
#define MSK_NETX_XP_SHAR_XM_STAT_CFG2_tx_nxt        0x00100000U // [20]
#define SRT_NETX_XP_SHAR_XM_STAT_CFG2_tx_nxt        20          
#define MSK_NETX_XP_SHAR_XM_STAT_CFG2_tx_ufl        0x00200000U // [21]
#define SRT_NETX_XP_SHAR_XM_STAT_CFG2_tx_ufl        21          
#define MSK_NETX_XP_SHAR_XM_STAT_CFG2_utx_empty     0x00400000U // [22]
#define SRT_NETX_XP_SHAR_XM_STAT_CFG2_utx_empty     22          
#define MSK_NETX_XP_SHAR_XM_STAT_CFG2_brec          0x00800000U // [23]
#define SRT_NETX_XP_SHAR_XM_STAT_CFG2_brec          23          
#define MSK_NETX_XP_SHAR_XM_STAT_CFG2_btran         0x01000000U // [24]
#define SRT_NETX_XP_SHAR_XM_STAT_CFG2_btran         24          
#define MSK_NETX_XP_SHAR_XM_STAT_CFG2_stat_rpu      0x02000000U // [25]
#define SRT_NETX_XP_SHAR_XM_STAT_CFG2_stat_rpu      25          
#define MSK_NETX_XP_SHAR_XM_STAT_CFG2_stat_tpu      0x04000000U // [26]
#define SRT_NETX_XP_SHAR_XM_STAT_CFG2_stat_tpu      26          
#define MSK_NETX_XP_SHAR_XM_STAT_CFG2_phy_led0      0x10000000U // [28]
#define SRT_NETX_XP_SHAR_XM_STAT_CFG2_phy_led0      28          
#define MSK_NETX_XP_SHAR_XM_STAT_CFG2_phy_led1      0x20000000U // [29]
#define SRT_NETX_XP_SHAR_XM_STAT_CFG2_phy_led1      29          
#define MSK_NETX_XP_SHAR_XM_STAT_CFG2_phy_led2      0x40000000U // [30]
#define SRT_NETX_XP_SHAR_XM_STAT_CFG2_phy_led2      30          
#define MSK_NETX_XP_SHAR_XM_STAT_CFG2_phy_led3      0x80000000U // [31]
#define SRT_NETX_XP_SHAR_XM_STAT_CFG2_phy_led3      31          

enum {
	BFW_NETX_XP_SHAR_XM_STAT_CFG2_rx_nof_bits   = 4, // [3:0]
	BFW_NETX_XP_SHAR_XM_STAT_CFG2_tx_nof_bits   = 4, // [7:4]
	BFW_NETX_XP_SHAR_XM_STAT_CFG2_rx_shift_lr   = 1, // [8]
	BFW_NETX_XP_SHAR_XM_STAT_CFG2_tx_shift_lr   = 1, // [9]
	BFW_NETX_XP_SHAR_XM_STAT_CFG2_reset_rx_fifo = 1, // [10]
	BFW_NETX_XP_SHAR_XM_STAT_CFG2_reset_tx_fifo = 1, // [11]
	BFW_NETX_XP_SHAR_XM_STAT_CFG2_gpio0_out     = 1, // [12]
	BFW_NETX_XP_SHAR_XM_STAT_CFG2_gpio0_oe      = 1, // [13]
	BFW_NETX_XP_SHAR_XM_STAT_CFG2_gpio1_out     = 1, // [14]
	BFW_NETX_XP_SHAR_XM_STAT_CFG2_gpio1_oe      = 1, // [15]
	BFW_NETX_XP_SHAR_XM_STAT_CFG2_gpio0_in      = 1, // [16]
	BFW_NETX_XP_SHAR_XM_STAT_CFG2_gpio1_in      = 1, // [17]
	BFW_NETX_XP_SHAR_XM_STAT_CFG2_rx_rdy        = 1, // [18]
	BFW_NETX_XP_SHAR_XM_STAT_CFG2_rx_ovf        = 1, // [19]
	BFW_NETX_XP_SHAR_XM_STAT_CFG2_tx_nxt        = 1, // [20]
	BFW_NETX_XP_SHAR_XM_STAT_CFG2_tx_ufl        = 1, // [21]
	BFW_NETX_XP_SHAR_XM_STAT_CFG2_utx_empty     = 1, // [22]
	BFW_NETX_XP_SHAR_XM_STAT_CFG2_brec          = 1, // [23]
	BFW_NETX_XP_SHAR_XM_STAT_CFG2_btran         = 1, // [24]
	BFW_NETX_XP_SHAR_XM_STAT_CFG2_stat_rpu      = 1, // [25]
	BFW_NETX_XP_SHAR_XM_STAT_CFG2_stat_tpu      = 1, // [26]
	BFW_NETX_XP_SHAR_XM_STAT_CFG2_reserved1     = 1, // [27]
	BFW_NETX_XP_SHAR_XM_STAT_CFG2_phy_led0      = 1, // [28]
	BFW_NETX_XP_SHAR_XM_STAT_CFG2_phy_led1      = 1, // [29]
	BFW_NETX_XP_SHAR_XM_STAT_CFG2_phy_led2      = 1, // [30]
	BFW_NETX_XP_SHAR_XM_STAT_CFG2_phy_led3      = 1  // [31]
};

typedef struct STATCFG2_BIT_Ttag {
	unsigned int rx_nof_bits   : BFW_NETX_XP_SHAR_XM_STAT_CFG2_rx_nof_bits;   // Number of bits written by SBU to rx-register, only used for rx_hw_count 
	unsigned int tx_nof_bits   : BFW_NETX_XP_SHAR_XM_STAT_CFG2_tx_nof_bits;   // Number of bits read by OBU from tx-register 
	unsigned int rx_shift_lr   : BFW_NETX_XP_SHAR_XM_STAT_CFG2_rx_shift_lr;   // 1: SBU reads incoming bits to position 0 of register rx and shifts rx left, 
	                                                        // 0: SBU reads incoming bits to position 15 of register rx and shifts rx right
	unsigned int tx_shift_lr   : BFW_NETX_XP_SHAR_XM_STAT_CFG2_tx_shift_lr;   // 1: OBU reads outgoing bits from position 15 of register tx and shifts tx left, 
	                                                        // 0: OBU reads outgoing bits from position 0 of register tx and shifts tx right
	unsigned int reset_rx_fifo : BFW_NETX_XP_SHAR_XM_STAT_CFG2_reset_rx_fifo; // reset URX_FIFO and rx_ovf bit inside status_shared register 
	unsigned int reset_tx_fifo : BFW_NETX_XP_SHAR_XM_STAT_CFG2_reset_tx_fifo; // reset UTX_FIFO and tx_ufl bit inside status_shared register 
	unsigned int gpio0_out     : BFW_NETX_XP_SHAR_XM_STAT_CFG2_gpio0_out;     // General Purpose IO 0 output 
	unsigned int gpio0_oe      : BFW_NETX_XP_SHAR_XM_STAT_CFG2_gpio0_oe;      // General Purpose IO 0 output enable 
	unsigned int gpio1_out     : BFW_NETX_XP_SHAR_XM_STAT_CFG2_gpio1_out;     // General Purpose IO 1 output 
	unsigned int gpio1_oe      : BFW_NETX_XP_SHAR_XM_STAT_CFG2_gpio1_oe;      // General Purpose IO 1 output enable 
	unsigned int gpio0_in      : BFW_NETX_XP_SHAR_XM_STAT_CFG2_gpio0_in;      // value at external gpio1 pin
	unsigned int gpio1_in      : BFW_NETX_XP_SHAR_XM_STAT_CFG2_gpio1_in;      // value at external gpio2 pin
	unsigned int rx_rdy        : BFW_NETX_XP_SHAR_XM_STAT_CFG2_rx_rdy;        // received bytes are valid at output of URX_FIFO
	unsigned int rx_ovf        : BFW_NETX_XP_SHAR_XM_STAT_CFG2_rx_ovf;        // receive overflow (too much data in URX_FIFO)
	unsigned int tx_nxt        : BFW_NETX_XP_SHAR_XM_STAT_CFG2_tx_nxt;        // put next tx_word to UTX_FIFO: at least one entry of UTX_FIFO is empty
	unsigned int tx_ufl        : BFW_NETX_XP_SHAR_XM_STAT_CFG2_tx_ufl;        // transmit underflow (not enough data in UTX_FIFO)
	unsigned int utx_empty     : BFW_NETX_XP_SHAR_XM_STAT_CFG2_utx_empty;     // UTX_FIFO is empty
	unsigned int brec          : BFW_NETX_XP_SHAR_XM_STAT_CFG2_brec;          // bit_received (active for 1 cc)
	unsigned int btran         : BFW_NETX_XP_SHAR_XM_STAT_CFG2_btran;         // bit_transmitted (active for 1 cc)
	unsigned int stat_rpu      : BFW_NETX_XP_SHAR_XM_STAT_CFG2_stat_rpu;      // set and reset by RPU command bits
	unsigned int stat_tpu      : BFW_NETX_XP_SHAR_XM_STAT_CFG2_stat_tpu;      // set and reset by TPU command bits
	unsigned int reserved1     : BFW_NETX_XP_SHAR_XM_STAT_CFG2_reserved1;     // reserved
	unsigned int phy_led0      : BFW_NETX_XP_SHAR_XM_STAT_CFG2_phy_led0;      // not connected (zero)
	unsigned int phy_led1      : BFW_NETX_XP_SHAR_XM_STAT_CFG2_phy_led1;      // not connected (zero)
	unsigned int phy_led2      : BFW_NETX_XP_SHAR_XM_STAT_CFG2_phy_led2;      // not connected (zero)
	unsigned int phy_led3      : BFW_NETX_XP_SHAR_XM_STAT_CFG2_phy_led3;      // not connected (zero)
} STATCFG2_BIT_T;

typedef union {
	unsigned int   val;
	STATCFG2_BIT_T bf;
} STATCFG2_T;

// ---------------------------------------------------------------------
// Register statcfg3
// => xMAC3 Shared Config/Status Register
//    Resetvalue : 0x00000088
// => Mode: Mode (r/w)
// ---------------------------------------------------------------------

#define REL_NETX_XP_SHAR_XM_STAT_CFG3   0x000000ECU
#define NETX_XP0_SHAR_XM_STAT_CFG3 0x001700ECU
#define NETX_XP1_SHAR_XM_STAT_CFG3 0x001740ECU
#define NETX_XP2_SHAR_XM_STAT_CFG3 0x001780ECU
#define NETX_XP3_SHAR_XM_STAT_CFG3 0x0017C0ECU

#define MSK_NETX_XP_SHAR_XM_STAT_CFG3_rx_nof_bits   0x0000000fU // [3:0]
#define SRT_NETX_XP_SHAR_XM_STAT_CFG3_rx_nof_bits   0           
#define MSK_NETX_XP_SHAR_XM_STAT_CFG3_tx_nof_bits   0x000000f0U // [7:4]
#define SRT_NETX_XP_SHAR_XM_STAT_CFG3_tx_nof_bits   4           
#define MSK_NETX_XP_SHAR_XM_STAT_CFG3_rx_shift_lr   0x00000100U // [8]
#define SRT_NETX_XP_SHAR_XM_STAT_CFG3_rx_shift_lr   8           
#define MSK_NETX_XP_SHAR_XM_STAT_CFG3_tx_shift_lr   0x00000200U // [9]
#define SRT_NETX_XP_SHAR_XM_STAT_CFG3_tx_shift_lr   9           
#define MSK_NETX_XP_SHAR_XM_STAT_CFG3_reset_rx_fifo 0x00000400U // [10]
#define SRT_NETX_XP_SHAR_XM_STAT_CFG3_reset_rx_fifo 10          
#define MSK_NETX_XP_SHAR_XM_STAT_CFG3_reset_tx_fifo 0x00000800U // [11]
#define SRT_NETX_XP_SHAR_XM_STAT_CFG3_reset_tx_fifo 11          
#define MSK_NETX_XP_SHAR_XM_STAT_CFG3_gpio0_out     0x00001000U // [12]
#define SRT_NETX_XP_SHAR_XM_STAT_CFG3_gpio0_out     12          
#define MSK_NETX_XP_SHAR_XM_STAT_CFG3_gpio0_oe      0x00002000U // [13]
#define SRT_NETX_XP_SHAR_XM_STAT_CFG3_gpio0_oe      13          
#define MSK_NETX_XP_SHAR_XM_STAT_CFG3_gpio1_out     0x00004000U // [14]
#define SRT_NETX_XP_SHAR_XM_STAT_CFG3_gpio1_out     14          
#define MSK_NETX_XP_SHAR_XM_STAT_CFG3_gpio1_oe      0x00008000U // [15]
#define SRT_NETX_XP_SHAR_XM_STAT_CFG3_gpio1_oe      15          
#define MSK_NETX_XP_SHAR_XM_STAT_CFG3_gpio0_in      0x00010000U // [16]
#define SRT_NETX_XP_SHAR_XM_STAT_CFG3_gpio0_in      16          
#define MSK_NETX_XP_SHAR_XM_STAT_CFG3_gpio1_in      0x00020000U // [17]
#define SRT_NETX_XP_SHAR_XM_STAT_CFG3_gpio1_in      17          
#define MSK_NETX_XP_SHAR_XM_STAT_CFG3_rx_rdy        0x00040000U // [18]
#define SRT_NETX_XP_SHAR_XM_STAT_CFG3_rx_rdy        18          
#define MSK_NETX_XP_SHAR_XM_STAT_CFG3_rx_ovf        0x00080000U // [19]
#define SRT_NETX_XP_SHAR_XM_STAT_CFG3_rx_ovf        19          
#define MSK_NETX_XP_SHAR_XM_STAT_CFG3_tx_nxt        0x00100000U // [20]
#define SRT_NETX_XP_SHAR_XM_STAT_CFG3_tx_nxt        20          
#define MSK_NETX_XP_SHAR_XM_STAT_CFG3_tx_ufl        0x00200000U // [21]
#define SRT_NETX_XP_SHAR_XM_STAT_CFG3_tx_ufl        21          
#define MSK_NETX_XP_SHAR_XM_STAT_CFG3_utx_empty     0x00400000U // [22]
#define SRT_NETX_XP_SHAR_XM_STAT_CFG3_utx_empty     22          
#define MSK_NETX_XP_SHAR_XM_STAT_CFG3_brec          0x00800000U // [23]
#define SRT_NETX_XP_SHAR_XM_STAT_CFG3_brec          23          
#define MSK_NETX_XP_SHAR_XM_STAT_CFG3_btran         0x01000000U // [24]
#define SRT_NETX_XP_SHAR_XM_STAT_CFG3_btran         24          
#define MSK_NETX_XP_SHAR_XM_STAT_CFG3_stat_rpu      0x02000000U // [25]
#define SRT_NETX_XP_SHAR_XM_STAT_CFG3_stat_rpu      25          
#define MSK_NETX_XP_SHAR_XM_STAT_CFG3_stat_tpu      0x04000000U // [26]
#define SRT_NETX_XP_SHAR_XM_STAT_CFG3_stat_tpu      26          
#define MSK_NETX_XP_SHAR_XM_STAT_CFG3_phy_led0      0x10000000U // [28]
#define SRT_NETX_XP_SHAR_XM_STAT_CFG3_phy_led0      28          
#define MSK_NETX_XP_SHAR_XM_STAT_CFG3_phy_led1      0x20000000U // [29]
#define SRT_NETX_XP_SHAR_XM_STAT_CFG3_phy_led1      29          
#define MSK_NETX_XP_SHAR_XM_STAT_CFG3_phy_led2      0x40000000U // [30]
#define SRT_NETX_XP_SHAR_XM_STAT_CFG3_phy_led2      30          
#define MSK_NETX_XP_SHAR_XM_STAT_CFG3_phy_led3      0x80000000U // [31]
#define SRT_NETX_XP_SHAR_XM_STAT_CFG3_phy_led3      31          

enum {
	BFW_NETX_XP_SHAR_XM_STAT_CFG3_rx_nof_bits   = 4, // [3:0]
	BFW_NETX_XP_SHAR_XM_STAT_CFG3_tx_nof_bits   = 4, // [7:4]
	BFW_NETX_XP_SHAR_XM_STAT_CFG3_rx_shift_lr   = 1, // [8]
	BFW_NETX_XP_SHAR_XM_STAT_CFG3_tx_shift_lr   = 1, // [9]
	BFW_NETX_XP_SHAR_XM_STAT_CFG3_reset_rx_fifo = 1, // [10]
	BFW_NETX_XP_SHAR_XM_STAT_CFG3_reset_tx_fifo = 1, // [11]
	BFW_NETX_XP_SHAR_XM_STAT_CFG3_gpio0_out     = 1, // [12]
	BFW_NETX_XP_SHAR_XM_STAT_CFG3_gpio0_oe      = 1, // [13]
	BFW_NETX_XP_SHAR_XM_STAT_CFG3_gpio1_out     = 1, // [14]
	BFW_NETX_XP_SHAR_XM_STAT_CFG3_gpio1_oe      = 1, // [15]
	BFW_NETX_XP_SHAR_XM_STAT_CFG3_gpio0_in      = 1, // [16]
	BFW_NETX_XP_SHAR_XM_STAT_CFG3_gpio1_in      = 1, // [17]
	BFW_NETX_XP_SHAR_XM_STAT_CFG3_rx_rdy        = 1, // [18]
	BFW_NETX_XP_SHAR_XM_STAT_CFG3_rx_ovf        = 1, // [19]
	BFW_NETX_XP_SHAR_XM_STAT_CFG3_tx_nxt        = 1, // [20]
	BFW_NETX_XP_SHAR_XM_STAT_CFG3_tx_ufl        = 1, // [21]
	BFW_NETX_XP_SHAR_XM_STAT_CFG3_utx_empty     = 1, // [22]
	BFW_NETX_XP_SHAR_XM_STAT_CFG3_brec          = 1, // [23]
	BFW_NETX_XP_SHAR_XM_STAT_CFG3_btran         = 1, // [24]
	BFW_NETX_XP_SHAR_XM_STAT_CFG3_stat_rpu      = 1, // [25]
	BFW_NETX_XP_SHAR_XM_STAT_CFG3_stat_tpu      = 1, // [26]
	BFW_NETX_XP_SHAR_XM_STAT_CFG3_reserved1     = 1, // [27]
	BFW_NETX_XP_SHAR_XM_STAT_CFG3_phy_led0      = 1, // [28]
	BFW_NETX_XP_SHAR_XM_STAT_CFG3_phy_led1      = 1, // [29]
	BFW_NETX_XP_SHAR_XM_STAT_CFG3_phy_led2      = 1, // [30]
	BFW_NETX_XP_SHAR_XM_STAT_CFG3_phy_led3      = 1  // [31]
};

typedef struct STATCFG3_BIT_Ttag {
	unsigned int rx_nof_bits   : BFW_NETX_XP_SHAR_XM_STAT_CFG3_rx_nof_bits;   // Number of bits written by SBU to rx-register, only used for rx_hw_count 
	unsigned int tx_nof_bits   : BFW_NETX_XP_SHAR_XM_STAT_CFG3_tx_nof_bits;   // Number of bits read by OBU from tx-register 
	unsigned int rx_shift_lr   : BFW_NETX_XP_SHAR_XM_STAT_CFG3_rx_shift_lr;   // 1: SBU reads incoming bits to position 0 of register rx and shifts rx left, 
	                                                        // 0: SBU reads incoming bits to position 15 of register rx and shifts rx right
	unsigned int tx_shift_lr   : BFW_NETX_XP_SHAR_XM_STAT_CFG3_tx_shift_lr;   // 1: OBU reads outgoing bits from position 15 of register tx and shifts tx left, 
	                                                        // 0: OBU reads outgoing bits from position 0 of register tx and shifts tx right
	unsigned int reset_rx_fifo : BFW_NETX_XP_SHAR_XM_STAT_CFG3_reset_rx_fifo; // reset URX_FIFO and rx_ovf bit inside status_shared register 
	unsigned int reset_tx_fifo : BFW_NETX_XP_SHAR_XM_STAT_CFG3_reset_tx_fifo; // reset UTX_FIFO and tx_ufl bit inside status_shared register 
	unsigned int gpio0_out     : BFW_NETX_XP_SHAR_XM_STAT_CFG3_gpio0_out;     // General Purpose IO 0 output 
	unsigned int gpio0_oe      : BFW_NETX_XP_SHAR_XM_STAT_CFG3_gpio0_oe;      // General Purpose IO 0 output enable 
	unsigned int gpio1_out     : BFW_NETX_XP_SHAR_XM_STAT_CFG3_gpio1_out;     // General Purpose IO 1 output 
	unsigned int gpio1_oe      : BFW_NETX_XP_SHAR_XM_STAT_CFG3_gpio1_oe;      // General Purpose IO 1 output enable 
	unsigned int gpio0_in      : BFW_NETX_XP_SHAR_XM_STAT_CFG3_gpio0_in;      // value at external gpio1 pin
	unsigned int gpio1_in      : BFW_NETX_XP_SHAR_XM_STAT_CFG3_gpio1_in;      // value at external gpio2 pin
	unsigned int rx_rdy        : BFW_NETX_XP_SHAR_XM_STAT_CFG3_rx_rdy;        // received bytes are valid at output of URX_FIFO
	unsigned int rx_ovf        : BFW_NETX_XP_SHAR_XM_STAT_CFG3_rx_ovf;        // receive overflow (too much data in URX_FIFO)
	unsigned int tx_nxt        : BFW_NETX_XP_SHAR_XM_STAT_CFG3_tx_nxt;        // put next tx_word to UTX_FIFO: at least one entry of UTX_FIFO is empty
	unsigned int tx_ufl        : BFW_NETX_XP_SHAR_XM_STAT_CFG3_tx_ufl;        // transmit underflow (not enough data in UTX_FIFO)
	unsigned int utx_empty     : BFW_NETX_XP_SHAR_XM_STAT_CFG3_utx_empty;     // UTX_FIFO is empty
	unsigned int brec          : BFW_NETX_XP_SHAR_XM_STAT_CFG3_brec;          // bit_received (active for 1 cc)
	unsigned int btran         : BFW_NETX_XP_SHAR_XM_STAT_CFG3_btran;         // bit_transmitted (active for 1 cc)
	unsigned int stat_rpu      : BFW_NETX_XP_SHAR_XM_STAT_CFG3_stat_rpu;      // set and reset by RPU command bits
	unsigned int stat_tpu      : BFW_NETX_XP_SHAR_XM_STAT_CFG3_stat_tpu;      // set and reset by TPU command bits
	unsigned int reserved1     : BFW_NETX_XP_SHAR_XM_STAT_CFG3_reserved1;     // reserved
	unsigned int phy_led0      : BFW_NETX_XP_SHAR_XM_STAT_CFG3_phy_led0;      // not connected (zero)
	unsigned int phy_led1      : BFW_NETX_XP_SHAR_XM_STAT_CFG3_phy_led1;      // not connected (zero)
	unsigned int phy_led2      : BFW_NETX_XP_SHAR_XM_STAT_CFG3_phy_led2;      // not connected (zero)
	unsigned int phy_led3      : BFW_NETX_XP_SHAR_XM_STAT_CFG3_phy_led3;      // not connected (zero)
} STATCFG3_BIT_T;

typedef union {
	unsigned int   val;
	STATCFG3_BIT_T bf;
} STATCFG3_T;

// ---------------------------------------------------------------------
// Register urtx0
// => xMAC0 URX Shared Register
// => Mode: Mode (r/w)
// ---------------------------------------------------------------------

#define REL_NETX_XP_URTX0   0x000000F0U
#define NETX_XP0_URTX0 0x001700F0U
#define NETX_XP1_URTX0 0x001740F0U
#define NETX_XP2_URTX0 0x001780F0U
#define NETX_XP3_URTX0 0x0017C0F0U

#define MSK_NETX_XP_URTX0_urtx_xmac0 0x0000ffffU // [15:0]
#define SRT_NETX_XP_URTX0_urtx_xmac0 0           

enum {
	BFW_NETX_XP_URTX0_urtx_xmac0 = 16, // [15:0]
	BFW_NETX_XP_URTX0_reserved1  = 16  // [31:16]
};

typedef struct URTX0_BIT_Ttag {
	unsigned int urtx_xmac0 : BFW_NETX_XP_URTX0_urtx_xmac0; // read access:  Lastly received bits (output of URX_FIFO) 
	                                                        // write access: Bits to be transmitted next (input of UTX_FIFO)
	unsigned int reserved1  : BFW_NETX_XP_URTX0_reserved1;  // reserved
} URTX0_BIT_T;

typedef union {
	unsigned int val;
	URTX0_BIT_T  bf;
} URTX0_T;

// ---------------------------------------------------------------------
// Register urtx1
// => xMAC1 URX Shared Register
// => Mode: Mode (r/w)
// ---------------------------------------------------------------------

#define REL_NETX_XP_URTX1   0x000000F4U
#define NETX_XP0_URTX1 0x001700F4U
#define NETX_XP1_URTX1 0x001740F4U
#define NETX_XP2_URTX1 0x001780F4U
#define NETX_XP3_URTX1 0x0017C0F4U

#define MSK_NETX_XP_URTX1_urtx_xmac1 0x0000ffffU // [15:0]
#define SRT_NETX_XP_URTX1_urtx_xmac1 0           

enum {
	BFW_NETX_XP_URTX1_urtx_xmac1 = 16, // [15:0]
	BFW_NETX_XP_URTX1_reserved1  = 16  // [31:16]
};

typedef struct URTX1_BIT_Ttag {
	unsigned int urtx_xmac1 : BFW_NETX_XP_URTX1_urtx_xmac1; // read access:  Lastly received bits (output of URX_FIFO) 
	                                                        // write access: Bits to be transmitted next (input of UTX_FIFO)
	unsigned int reserved1  : BFW_NETX_XP_URTX1_reserved1;  // reserved
} URTX1_BIT_T;

typedef union {
	unsigned int val;
	URTX1_BIT_T  bf;
} URTX1_T;

// ---------------------------------------------------------------------
// Register urtx2
// => xMAC2 URX Shared Register
// => Mode: Mode (r/w)
// ---------------------------------------------------------------------

#define REL_NETX_XP_URTX2   0x000000F8U
#define NETX_XP0_URTX2 0x001700F8U
#define NETX_XP1_URTX2 0x001740F8U
#define NETX_XP2_URTX2 0x001780F8U
#define NETX_XP3_URTX2 0x0017C0F8U

#define MSK_NETX_XP_URTX2_urtx_xmac2 0x0000ffffU // [15:0]
#define SRT_NETX_XP_URTX2_urtx_xmac2 0           

enum {
	BFW_NETX_XP_URTX2_urtx_xmac2 = 16, // [15:0]
	BFW_NETX_XP_URTX2_reserved1  = 16  // [31:16]
};

typedef struct URTX2_BIT_Ttag {
	unsigned int urtx_xmac2 : BFW_NETX_XP_URTX2_urtx_xmac2; // read access:  Lastly received bits (output of URX_FIFO) 
	                                                        // write access: Bits to be transmitted next (input of UTX_FIFO)
	unsigned int reserved1  : BFW_NETX_XP_URTX2_reserved1;  // reserved
} URTX2_BIT_T;

typedef union {
	unsigned int val;
	URTX2_BIT_T  bf;
} URTX2_T;

// ---------------------------------------------------------------------
// Register urtx3
// => xMAC3 URX Shared Register
// => Mode: Mode (r/w)
// ---------------------------------------------------------------------

#define REL_NETX_XP_URTX3   0x000000FCU
#define NETX_XP0_URTX3 0x001700FCU
#define NETX_XP1_URTX3 0x001740FCU
#define NETX_XP2_URTX3 0x001780FCU
#define NETX_XP3_URTX3 0x0017C0FCU

#define MSK_NETX_XP_URTX3_urtx_xmac3 0x0000ffffU // [15:0]
#define SRT_NETX_XP_URTX3_urtx_xmac3 0           

enum {
	BFW_NETX_XP_URTX3_urtx_xmac3 = 16, // [15:0]
	BFW_NETX_XP_URTX3_reserved1  = 16  // [31:16]
};

typedef struct URTX3_BIT_Ttag {
	unsigned int urtx_xmac3 : BFW_NETX_XP_URTX3_urtx_xmac3; // read access:  Lastly received bits (output of URX_FIFO) 
	                                                        // write access: Bits to be transmitted next (input of UTX_FIFO)
	unsigned int reserved1  : BFW_NETX_XP_URTX3_reserved1;  // reserved
} URTX3_BIT_T;

typedef union {
	unsigned int val;
	URTX3_BIT_T  bf;
} URTX3_T;


/*************************************************************************************/

#endif /* _XC_H */
