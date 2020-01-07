/******************************************************************************

  Copyright (C) 2010 [Hilscher Gesellschaft für Systemautomation mbH]

  This program can be used by everyone according to the netX Open Source
  Software license. The license agreement can be downloaded from
  http://www.industrialNETworX.com

*******************************************************************************

  Last Modification:
    @version $Id: SysTime.h 333 2010-04-26 09:32:25Z Volker $

  Description:
    netX SYSTIME definitions

  Changes:
    Date        Author        Description
  ---------------------------------------------------------------------------
    2010-03-24  NC            File created.

******************************************************************************/


#ifndef _SYSTIME_H
#define _SYSTIME_H


/*************************************************************************************/


// =====================================================================
//
// Area of systime
//
// =====================================================================

#define NETX_SYS_TIME_AREA	0x00101100U


// ---------------------------------------------------------------------
// Register systime_ns
// => lower SYSTIME register
// => Mode: Mode (r/w)
// ---------------------------------------------------------------------

#define REL_NETX_SYS_TIME_NS 0x00000000U
#define NETX_SYS_TIME_NS     0x00101100U

#define MSK_NETX_SYS_TIME_NS_systime_ns 0xffffffffU // [31:0]
#define SRT_NETX_SYS_TIME_NS_systime_ns 0           

enum {
	BFW_NETX_SYS_TIME_NS_systime_ns = 32  // [31:0]
};

typedef struct SYSTIME_NS_BIT_Ttag {
	unsigned int systime_ns : BFW_NETX_SYS_TIME_NS_systime_ns; // Systime low (used for counting nanoseconds in IEEE15888)
} SYSTIME_NS_BIT_T;

typedef union {
	unsigned int     val;
	SYSTIME_NS_BIT_T bf;
} SYSTIME_NS_T;


// ---------------------------------------------------------------------
// Register systime_s
// => upper SYSTIME register
// => Mode: Mode (r/w)
// ---------------------------------------------------------------------

#define REL_NETX_SYS_TIME_S 0x00000004U
#define NETX_SYS_TIME_S     0x00101104U

#define MSK_NETX_SYS_TIME_S_systime_s 0xffffffffU // [31:0]
#define SRT_NETX_SYS_TIME_S_systime_s 0           

enum {
	BFW_NETX_SYS_TIME_S_systime_s = 32  // [31:0]
};

typedef struct SYSTIME_S_BIT_Ttag {
	unsigned int systime_s : BFW_NETX_SYS_TIME_S_systime_s; // systime high (used for counting seconds in IEEE 1588)
	                                                        // value is incremented, if systime_ns reaches systime_border
} SYSTIME_S_BIT_T;

typedef union {
	unsigned int    val;
	SYSTIME_S_BIT_T bf;
} SYSTIME_S_T;


// ---------------------------------------------------------------------
// Register systime_border
// => SYSTIME border register
// => Mode: Mode (r/w)
// ---------------------------------------------------------------------

#define REL_NETX_SYS_TIME_NS_BOR 0x00000008U
#define NETX_SYS_TIME_NS_BOR     0x00101108U

#define MSK_NETX_SYS_TIME_NS_BOR_systime_border 0xffffffffU // [31:0]
#define SRT_NETX_SYS_TIME_NS_BOR_systime_border 0           

enum {
	BFW_NETX_SYS_TIME_NS_BOR_systime_border = 32  // [31:0]
};

typedef struct SYSTIME_BORDER_BIT_Ttag {
	unsigned int systime_border : BFW_NETX_SYS_TIME_NS_BOR_systime_border; // Systime border for lower systime: 
	                                                        // systime_ns counts from 0 to this value (inlcuded),
	                                                        // i.e. systime_ns counts modulo (systime_border + 1)
} SYSTIME_BORDER_BIT_T;

typedef union {
	unsigned int         val;
	SYSTIME_BORDER_BIT_T bf;
} SYSTIME_BORDER_T;


// ---------------------------------------------------------------------
// Register systime_count_value
// => SYSTIME count register
// => Mode: Mode (r/w)
// ---------------------------------------------------------------------

#define REL_NETX_SYS_TIME_NS_ADD_UP 0x0000000CU
#define NETX_SYS_TIME_NS_ADD_UP     0x0010110CU

#define MSK_NETX_SYS_TIME_NS_ADD_UP_systime_count_value 0xffffffffU // [31:0]
#define SRT_NETX_SYS_TIME_NS_ADD_UP_systime_count_value 0           

enum {
	BFW_NETX_SYS_TIME_NS_ADD_UP_systime_count_value = 32  // [31:0]
};

typedef struct SYSTIME_COUNT_VALUE_BIT_Ttag {
	unsigned int systime_count_value : BFW_NETX_SYS_TIME_NS_ADD_UP_systime_count_value; // Each clock cycle (systime_count_value >> 28) 
	                                                        // will be added to systime (rate multiplier for IEEE1588).
	                                                        // Value 0x10000000 can be used for counting in 10ns (ethernet clock) steps.
} SYSTIME_COUNT_VALUE_BIT_T;

typedef union {
	unsigned int              val;
	SYSTIME_COUNT_VALUE_BIT_T bf;
} SYSTIME_COUNT_VALUE_T;


// ---------------------------------------------------------------------
// Register systime_s_compare_value
// => SYSTIME sec compare register
// => Mode: Mode (r/w)
// ---------------------------------------------------------------------

#define REL_NETX_SYS_TIME_S_CMP 0x00000010U
#define NETX_SYS_TIME_S_CMP     0x00101110U

#define MSK_NETX_SYS_TIME_S_CMP_systime_s_compare_value 0xffffffffU // [31:0]
#define SRT_NETX_SYS_TIME_S_CMP_systime_s_compare_value 0           

enum {
	BFW_NETX_SYS_TIME_S_CMP_systime_s_compare_value = 32  // [31:0]
};

typedef struct SYSTIME_S_COMPARE_VALUE_BIT_Ttag {
	unsigned int systime_s_compare_value : BFW_NETX_SYS_TIME_S_CMP_systime_s_compare_value; // compare value with systime_s (seconds) 
	                                                        // set systime_s_compare_irq register if systime_s_compare_enable is set
} SYSTIME_S_COMPARE_VALUE_BIT_T;

typedef union {
	unsigned int                  val;
	SYSTIME_S_COMPARE_VALUE_BIT_T bf;
} SYSTIME_S_COMPARE_VALUE_T;


// ---------------------------------------------------------------------
// Register systime_s_compare_enable
// => SYSTIME sec compare enable register
// => Mode: Mode (r/w)
// ---------------------------------------------------------------------

#define REL_NETX_SYS_TIME_S_CMP_EN 0x00000014U
#define NETX_SYS_TIME_S_CMP_EN     0x00101114U

#define MSK_NETX_SYS_TIME_S_CMP_EN_systime_s_compare_enable 0x00000001U // [0]
#define SRT_NETX_SYS_TIME_S_CMP_EN_systime_s_compare_enable 0           

enum {
	BFW_NETX_SYS_TIME_S_CMP_EN_systime_s_compare_enable = 1,  // [0]
	BFW_NETX_SYS_TIME_S_CMP_EN_reserved1                = 31  // [31:1]
};

typedef struct SYSTIME_S_COMPARE_ENABLE_BIT_Ttag {
	unsigned int systime_s_compare_enable : BFW_NETX_SYS_TIME_S_CMP_EN_systime_s_compare_enable; // enable compare with systime_s (seconds) 
	                                                        // automatic set with set systime_s_compare_value
	                                                        // automatic reset after irq
	unsigned int reserved1                : BFW_NETX_SYS_TIME_S_CMP_EN_reserved1;                // reserved
} SYSTIME_S_COMPARE_ENABLE_BIT_T;

typedef union {
	unsigned int                   val;
	SYSTIME_S_COMPARE_ENABLE_BIT_T bf;
} SYSTIME_S_COMPARE_ENABLE_T;


// ---------------------------------------------------------------------
// Register systime_s_compare_irq
// => SYSTIME sec compare irq register
// => Mode: Mode (r/w)
// ---------------------------------------------------------------------

#define REL_NETX_SYS_TIME_S_CMP_INT 0x00000018U
#define NETX_SYS_TIME_S_CMP_INT     0x00101118U

#define MSK_NETX_SYS_TIME_S_CMP_INT_systime_s_compare_irq 0x00000001U // [0]
#define SRT_NETX_SYS_TIME_S_CMP_INT_systime_s_compare_irq 0           

enum {
	BFW_NETX_SYS_TIME_S_CMP_INT_systime_s_compare_irq = 1,  // [0]
	BFW_NETX_SYS_TIME_S_CMP_INT_reserved1             = 31  // [31:1]
};

typedef struct SYSTIME_S_COMPARE_IRQ_BIT_Ttag {
	unsigned int systime_s_compare_irq : BFW_NETX_SYS_TIME_S_CMP_INT_systime_s_compare_irq; // compare with systime_s (seconds) irq 
	                                                        // set if systime_s equal systime_s_compare_value
	                                                        // reset by arm (arm writes 1 to reset)
	unsigned int reserved1             : BFW_NETX_SYS_TIME_S_CMP_INT_reserved1;             // reserved
} SYSTIME_S_COMPARE_IRQ_BIT_T;

typedef union {
	unsigned int                val;
	SYSTIME_S_COMPARE_IRQ_BIT_T bf;
} SYSTIME_S_COMPARE_IRQ_T;


/*************************************************************************************/

#endif /* _SYSTIME_H */
