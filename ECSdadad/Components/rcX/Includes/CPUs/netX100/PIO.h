/******************************************************************************

  Copyright (C) 2010 [Hilscher Gesellschaft für Systemautomation mbH]

  This program can be used by everyone according to the netX Open Source
  Software license. The license agreement can be downloaded from
  http://www.industrialNETworX.com

*******************************************************************************

  Last Modification:
    @version $Id: PIO.h 333 2010-04-26 09:32:25Z Volker $

  Description:
    netX PIO definitions

  Changes:
    Date        Author        Description
  ---------------------------------------------------------------------------
    2010-03-24  NC            File created.

******************************************************************************/


#ifndef _PIO_H
#define _PIO_H


/*************************************************************************************/


// =====================================================================
//
// Area of pio
//
// =====================================================================

#define NETX_PIO_AREA	0x00100900U


// ---------------------------------------------------------------------
// Register pio_in
// => PIO input register
// => Mode: Mode (r)
// ---------------------------------------------------------------------

#define REL_NETX_PIO_IN 0x00000000U
#define NETX_PIO_IN     0x00100900U

#define MSK_NETX_PIO_IN_val 0x7fffffffU // [30:0]
#define SRT_NETX_PIO_IN_val 0           

enum {
	BFW_NETX_PIO_IN_val       = 31, // [30:0]
	BFW_NETX_PIO_IN_reserved1 = 1   // [31]
};

typedef struct PIO_IN_BIT_Ttag {
	unsigned int val       : BFW_NETX_PIO_IN_val;       // pio input values 
	unsigned int reserved1 : BFW_NETX_PIO_IN_reserved1; // reserved
} PIO_IN_BIT_T;

typedef union {
	unsigned int val;
	PIO_IN_BIT_T bf;
} PIO_IN_T;


// ---------------------------------------------------------------------
// Register pio_out
// => PIO output register
// => Mode: Mode (r/w)
// ---------------------------------------------------------------------

#define REL_NETX_PIO_OUT 0x00000004U
#define NETX_PIO_OUT     0x00100904U

#define MSK_NETX_PIO_OUT_val 0x7fffffffU // [30:0]
#define SRT_NETX_PIO_OUT_val 0           

enum {
	BFW_NETX_PIO_OUT_val       = 31, // [30:0]
	BFW_NETX_PIO_OUT_reserved1 = 1   // [31]
};

typedef struct PIO_OUT_BIT_Ttag {
	unsigned int val       : BFW_NETX_PIO_OUT_val;       // pio output values 
	unsigned int reserved1 : BFW_NETX_PIO_OUT_reserved1; // reserved
} PIO_OUT_BIT_T;

typedef union {
	unsigned int  val;
	PIO_OUT_BIT_T bf;
} PIO_OUT_T;


// ---------------------------------------------------------------------
// Register pio_oe
// => PIO output enable register
// => Mode: Mode (r/w)
// ---------------------------------------------------------------------

#define REL_NETX_PIO_OUT_EN 0x00000008U
#define NETX_PIO_OUT_EN     0x00100908U

#define MSK_NETX_PIO_OUT_EN_val 0x7fffffffU // [30:0]
#define SRT_NETX_PIO_OUT_EN_val 0           

enum {
	BFW_NETX_PIO_OUT_EN_val       = 31, // [30:0]
	BFW_NETX_PIO_OUT_EN_reserved1 = 1   // [31]
};

typedef struct PIO_OE_BIT_Ttag {
	unsigned int val       : BFW_NETX_PIO_OUT_EN_val;       // pio output enables 
	unsigned int reserved1 : BFW_NETX_PIO_OUT_EN_reserved1; // reserved
} PIO_OE_BIT_T;

typedef union {
	unsigned int val;
	PIO_OE_BIT_T bf;
} PIO_OE_T;


/*************************************************************************************/

#endif /* _PIO_H */
