/******************************************************************************

  Copyright (C) 2010 [Hilscher Gesellschaft für Systemautomation mbH]

  This program can be used by everyone according to the netX Open Source
  Software license. The license agreement can be downloaded from
  http://www.industrialNETworX.com

*******************************************************************************

  Last Modification:
    @version $Id: GPIO.h 333 2010-04-26 09:32:25Z Volker $

  Description:
    netX GPIO definitions

  Changes:
    Date        Author        Description
  ---------------------------------------------------------------------------
    2010-03-24  NC            File created.

******************************************************************************/


#ifndef _GPIO_H
#define _GPIO_H


/*************************************************************************************/


// =====================================================================
//
// Area of gpio
//
// =====================================================================

#define NETX_GPIO_AREA	0x00100800U


// ---------------------------------------------------------------------
// Register gpio_cfg0
// => GPIO pin 0 config register
// => Mode: Mode (r/w)
// ---------------------------------------------------------------------

#define REL_NETX_GPIO_CFG0 0x00000000U
#define NETX_GPIO_CFG0     0x00100800U

#define MSK_NETX_GPIO_CFG0_iocfg     0x00000003U // [1:0]
#define SRT_NETX_GPIO_CFG0_iocfg     0           
#define MSK_NETX_GPIO_CFG0_inv       0x00000004U // [2]
#define SRT_NETX_GPIO_CFG0_inv       2           
#define MSK_NETX_GPIO_CFG0_mode      0x00000018U // [4:3]
#define SRT_NETX_GPIO_CFG0_mode      3           
#define MSK_NETX_GPIO_CFG0_count_ref 0x000000e0U // [7:5]
#define SRT_NETX_GPIO_CFG0_count_ref 5           

enum {
	BFW_NETX_GPIO_CFG0_iocfg     = 2,  // [1:0]
	BFW_NETX_GPIO_CFG0_inv       = 1,  // [2]
	BFW_NETX_GPIO_CFG0_mode      = 2,  // [4:3]
	BFW_NETX_GPIO_CFG0_count_ref = 3,  // [7:5]
	BFW_NETX_GPIO_CFG0_reserved1 = 24  // [31:8]
};

typedef struct GPIO_CFG0_BIT_Ttag {
	unsigned int iocfg     : BFW_NETX_GPIO_CFG0_iocfg;     // defines the input/output configuration 
	                                                        // 00 : gp input mode
	                                                        // 01 : gp output mode
	                                                        // 10 : ext0 mode
	                                                        // 11 : ext1 mode
	unsigned int inv       : BFW_NETX_GPIO_CFG0_inv;       // 0 : don't invert, 1 : invert input/output value 
	unsigned int mode      : BFW_NETX_GPIO_CFG0_mode;      // defines the gp input or output mode - depends on iocfg 
	                                                        // gp input modi :
	                                                        //              00 : read mode
	                                                        //              01 : capture mode (continued) at rising edge
	                                                        //              10 : capture mode (once) at rising edge
	                                                        //              11 : capture mode (high level)
	                                                        // gp output modi:
	                                                        //              00 : set to 0
	                                                        //              01 : set to 1
	                                                        //              10 : set to gpio_line[0]
	                                                        //              11 : pwm mode
	unsigned int count_ref : BFW_NETX_GPIO_CFG0_count_ref; // counter reference 
	                                                        // 000 : counter 0
	                                                        // 001 : counter 1
	                                                        // 010 : counter 2
	                                                        // 011 : counter 3
	                                                        // 100 : counter 4
	                                                        // 111 : system time
	unsigned int reserved1 : BFW_NETX_GPIO_CFG0_reserved1; // reserved
} GPIO_CFG0_BIT_T;

typedef union {
	unsigned int    val;
	GPIO_CFG0_BIT_T bf;
} GPIO_CFG0_T;


// ---------------------------------------------------------------------
// Register gpio_cfg1
// => GPIO pin 1 config register
// => Mode: Mode (r/w)
// ---------------------------------------------------------------------

#define REL_NETX_GPIO_CFG1 0x00000004U
#define NETX_GPIO_CFG1     0x00100804U

#define MSK_NETX_GPIO_CFG1_iocfg     0x00000003U // [1:0]
#define SRT_NETX_GPIO_CFG1_iocfg     0           
#define MSK_NETX_GPIO_CFG1_inv       0x00000004U // [2]
#define SRT_NETX_GPIO_CFG1_inv       2           
#define MSK_NETX_GPIO_CFG1_mode      0x00000018U // [4:3]
#define SRT_NETX_GPIO_CFG1_mode      3           
#define MSK_NETX_GPIO_CFG1_count_ref 0x000000e0U // [7:5]
#define SRT_NETX_GPIO_CFG1_count_ref 5           

enum {
	BFW_NETX_GPIO_CFG1_iocfg     = 2,  // [1:0]
	BFW_NETX_GPIO_CFG1_inv       = 1,  // [2]
	BFW_NETX_GPIO_CFG1_mode      = 2,  // [4:3]
	BFW_NETX_GPIO_CFG1_count_ref = 3,  // [7:5]
	BFW_NETX_GPIO_CFG1_reserved1 = 24  // [31:8]
};

typedef struct GPIO_CFG1_BIT_Ttag {
	unsigned int iocfg     : BFW_NETX_GPIO_CFG1_iocfg;     // analog to gpio_cfg0 
	unsigned int inv       : BFW_NETX_GPIO_CFG1_inv;       // analog to gpio_cfg0 
	unsigned int mode      : BFW_NETX_GPIO_CFG1_mode;      // analog to gpio_cfg0 
	unsigned int count_ref : BFW_NETX_GPIO_CFG1_count_ref; // analog to gpio_cfg0 
	unsigned int reserved1 : BFW_NETX_GPIO_CFG1_reserved1; // reserved
} GPIO_CFG1_BIT_T;

typedef union {
	unsigned int    val;
	GPIO_CFG1_BIT_T bf;
} GPIO_CFG1_T;


// ---------------------------------------------------------------------
// Register gpio_cfg2
// => GPIO pin 2 config register
// => Mode: Mode (r/w)
// ---------------------------------------------------------------------

#define REL_NETX_GPIO_CFG2 0x00000008U
#define NETX_GPIO_CFG2     0x00100808U

#define MSK_NETX_GPIO_CFG2_iocfg     0x00000003U // [1:0]
#define SRT_NETX_GPIO_CFG2_iocfg     0           
#define MSK_NETX_GPIO_CFG2_inv       0x00000004U // [2]
#define SRT_NETX_GPIO_CFG2_inv       2           
#define MSK_NETX_GPIO_CFG2_mode      0x00000018U // [4:3]
#define SRT_NETX_GPIO_CFG2_mode      3           
#define MSK_NETX_GPIO_CFG2_count_ref 0x000000e0U // [7:5]
#define SRT_NETX_GPIO_CFG2_count_ref 5           

enum {
	BFW_NETX_GPIO_CFG2_iocfg     = 2,  // [1:0]
	BFW_NETX_GPIO_CFG2_inv       = 1,  // [2]
	BFW_NETX_GPIO_CFG2_mode      = 2,  // [4:3]
	BFW_NETX_GPIO_CFG2_count_ref = 3,  // [7:5]
	BFW_NETX_GPIO_CFG2_reserved1 = 24  // [31:8]
};

typedef struct GPIO_CFG2_BIT_Ttag {
	unsigned int iocfg     : BFW_NETX_GPIO_CFG2_iocfg;     // analog to gpio_cfg0 
	unsigned int inv       : BFW_NETX_GPIO_CFG2_inv;       // analog to gpio_cfg0 
	unsigned int mode      : BFW_NETX_GPIO_CFG2_mode;      // analog to gpio_cfg0 
	unsigned int count_ref : BFW_NETX_GPIO_CFG2_count_ref; // analog to gpio_cfg0 
	unsigned int reserved1 : BFW_NETX_GPIO_CFG2_reserved1; // reserved
} GPIO_CFG2_BIT_T;

typedef union {
	unsigned int    val;
	GPIO_CFG2_BIT_T bf;
} GPIO_CFG2_T;


// ---------------------------------------------------------------------
// Register gpio_cfg3
// => GPIO pin 3 config register
// => Mode: Mode (r/w)
// ---------------------------------------------------------------------

#define REL_NETX_GPIO_CFG3 0x0000000CU
#define NETX_GPIO_CFG3     0x0010080CU

#define MSK_NETX_GPIO_CFG3_iocfg     0x00000003U // [1:0]
#define SRT_NETX_GPIO_CFG3_iocfg     0           
#define MSK_NETX_GPIO_CFG3_inv       0x00000004U // [2]
#define SRT_NETX_GPIO_CFG3_inv       2           
#define MSK_NETX_GPIO_CFG3_mode      0x00000018U // [4:3]
#define SRT_NETX_GPIO_CFG3_mode      3           
#define MSK_NETX_GPIO_CFG3_count_ref 0x000000e0U // [7:5]
#define SRT_NETX_GPIO_CFG3_count_ref 5           

enum {
	BFW_NETX_GPIO_CFG3_iocfg     = 2,  // [1:0]
	BFW_NETX_GPIO_CFG3_inv       = 1,  // [2]
	BFW_NETX_GPIO_CFG3_mode      = 2,  // [4:3]
	BFW_NETX_GPIO_CFG3_count_ref = 3,  // [7:5]
	BFW_NETX_GPIO_CFG3_reserved1 = 24  // [31:8]
};

typedef struct GPIO_CFG3_BIT_Ttag {
	unsigned int iocfg     : BFW_NETX_GPIO_CFG3_iocfg;     // analog to gpio_cfg0 
	unsigned int inv       : BFW_NETX_GPIO_CFG3_inv;       // analog to gpio_cfg0 
	unsigned int mode      : BFW_NETX_GPIO_CFG3_mode;      // analog to gpio_cfg0 
	unsigned int count_ref : BFW_NETX_GPIO_CFG3_count_ref; // analog to gpio_cfg0 
	unsigned int reserved1 : BFW_NETX_GPIO_CFG3_reserved1; // reserved
} GPIO_CFG3_BIT_T;

typedef union {
	unsigned int    val;
	GPIO_CFG3_BIT_T bf;
} GPIO_CFG3_T;


// ---------------------------------------------------------------------
// Register gpio_cfg4
// => GPIO pin 4 config register
// => Mode: Mode (r/w)
// ---------------------------------------------------------------------

#define REL_NETX_GPIO_CFG4 0x00000010U
#define NETX_GPIO_CFG4     0x00100810U

#define MSK_NETX_GPIO_CFG4_iocfg     0x00000003U // [1:0]
#define SRT_NETX_GPIO_CFG4_iocfg     0           
#define MSK_NETX_GPIO_CFG4_inv       0x00000004U // [2]
#define SRT_NETX_GPIO_CFG4_inv       2           
#define MSK_NETX_GPIO_CFG4_mode      0x00000018U // [4:3]
#define SRT_NETX_GPIO_CFG4_mode      3           
#define MSK_NETX_GPIO_CFG4_count_ref 0x000000e0U // [7:5]
#define SRT_NETX_GPIO_CFG4_count_ref 5           

enum {
	BFW_NETX_GPIO_CFG4_iocfg     = 2,  // [1:0]
	BFW_NETX_GPIO_CFG4_inv       = 1,  // [2]
	BFW_NETX_GPIO_CFG4_mode      = 2,  // [4:3]
	BFW_NETX_GPIO_CFG4_count_ref = 3,  // [7:5]
	BFW_NETX_GPIO_CFG4_reserved1 = 24  // [31:8]
};

typedef struct GPIO_CFG4_BIT_Ttag {
	unsigned int iocfg     : BFW_NETX_GPIO_CFG4_iocfg;     // analog to gpio_cfg0 
	unsigned int inv       : BFW_NETX_GPIO_CFG4_inv;       // analog to gpio_cfg0 
	unsigned int mode      : BFW_NETX_GPIO_CFG4_mode;      // analog to gpio_cfg0 
	unsigned int count_ref : BFW_NETX_GPIO_CFG4_count_ref; // analog to gpio_cfg0 
	unsigned int reserved1 : BFW_NETX_GPIO_CFG4_reserved1; // reserved
} GPIO_CFG4_BIT_T;

typedef union {
	unsigned int    val;
	GPIO_CFG4_BIT_T bf;
} GPIO_CFG4_T;


// ---------------------------------------------------------------------
// Register gpio_cfg5
// => GPIO pin 5 config register
// => Mode: Mode (r/w)
// ---------------------------------------------------------------------

#define REL_NETX_GPIO_CFG5 0x00000014U
#define NETX_GPIO_CFG5     0x00100814U

#define MSK_NETX_GPIO_CFG5_iocfg     0x00000003U // [1:0]
#define SRT_NETX_GPIO_CFG5_iocfg     0           
#define MSK_NETX_GPIO_CFG5_inv       0x00000004U // [2]
#define SRT_NETX_GPIO_CFG5_inv       2           
#define MSK_NETX_GPIO_CFG5_mode      0x00000018U // [4:3]
#define SRT_NETX_GPIO_CFG5_mode      3           
#define MSK_NETX_GPIO_CFG5_count_ref 0x000000e0U // [7:5]
#define SRT_NETX_GPIO_CFG5_count_ref 5           

enum {
	BFW_NETX_GPIO_CFG5_iocfg     = 2,  // [1:0]
	BFW_NETX_GPIO_CFG5_inv       = 1,  // [2]
	BFW_NETX_GPIO_CFG5_mode      = 2,  // [4:3]
	BFW_NETX_GPIO_CFG5_count_ref = 3,  // [7:5]
	BFW_NETX_GPIO_CFG5_reserved1 = 24  // [31:8]
};

typedef struct GPIO_CFG5_BIT_Ttag {
	unsigned int iocfg     : BFW_NETX_GPIO_CFG5_iocfg;     // analog to gpio_cfg0 
	unsigned int inv       : BFW_NETX_GPIO_CFG5_inv;       // analog to gpio_cfg0 
	unsigned int mode      : BFW_NETX_GPIO_CFG5_mode;      // analog to gpio_cfg0 
	unsigned int count_ref : BFW_NETX_GPIO_CFG5_count_ref; // analog to gpio_cfg0 
	unsigned int reserved1 : BFW_NETX_GPIO_CFG5_reserved1; // reserved
} GPIO_CFG5_BIT_T;

typedef union {
	unsigned int    val;
	GPIO_CFG5_BIT_T bf;
} GPIO_CFG5_T;


// ---------------------------------------------------------------------
// Register gpio_cfg6
// => GPIO pin 6 config register
// => Mode: Mode (r/w)
// ---------------------------------------------------------------------

#define REL_NETX_GPIO_CFG6 0x00000018U
#define NETX_GPIO_CFG6     0x00100818U

#define MSK_NETX_GPIO_CFG6_iocfg     0x00000003U // [1:0]
#define SRT_NETX_GPIO_CFG6_iocfg     0           
#define MSK_NETX_GPIO_CFG6_inv       0x00000004U // [2]
#define SRT_NETX_GPIO_CFG6_inv       2           
#define MSK_NETX_GPIO_CFG6_mode      0x00000018U // [4:3]
#define SRT_NETX_GPIO_CFG6_mode      3           
#define MSK_NETX_GPIO_CFG6_count_ref 0x000000e0U // [7:5]
#define SRT_NETX_GPIO_CFG6_count_ref 5           

enum {
	BFW_NETX_GPIO_CFG6_iocfg     = 2,  // [1:0]
	BFW_NETX_GPIO_CFG6_inv       = 1,  // [2]
	BFW_NETX_GPIO_CFG6_mode      = 2,  // [4:3]
	BFW_NETX_GPIO_CFG6_count_ref = 3,  // [7:5]
	BFW_NETX_GPIO_CFG6_reserved1 = 24  // [31:8]
};

typedef struct GPIO_CFG6_BIT_Ttag {
	unsigned int iocfg     : BFW_NETX_GPIO_CFG6_iocfg;     // analog to gpio_cfg0 
	unsigned int inv       : BFW_NETX_GPIO_CFG6_inv;       // analog to gpio_cfg0 
	unsigned int mode      : BFW_NETX_GPIO_CFG6_mode;      // analog to gpio_cfg0 
	unsigned int count_ref : BFW_NETX_GPIO_CFG6_count_ref; // analog to gpio_cfg0 
	unsigned int reserved1 : BFW_NETX_GPIO_CFG6_reserved1; // reserved
} GPIO_CFG6_BIT_T;

typedef union {
	unsigned int    val;
	GPIO_CFG6_BIT_T bf;
} GPIO_CFG6_T;


// ---------------------------------------------------------------------
// Register gpio_cfg7
// => GPIO pin 7 config register
// => Mode: Mode (r/w)
// ---------------------------------------------------------------------

#define REL_NETX_GPIO_CFG7 0x0000001CU
#define NETX_GPIO_CFG7     0x0010081CU

#define MSK_NETX_GPIO_CFG7_iocfg     0x00000003U // [1:0]
#define SRT_NETX_GPIO_CFG7_iocfg     0           
#define MSK_NETX_GPIO_CFG7_inv       0x00000004U // [2]
#define SRT_NETX_GPIO_CFG7_inv       2           
#define MSK_NETX_GPIO_CFG7_mode      0x00000018U // [4:3]
#define SRT_NETX_GPIO_CFG7_mode      3           
#define MSK_NETX_GPIO_CFG7_count_ref 0x000000e0U // [7:5]
#define SRT_NETX_GPIO_CFG7_count_ref 5           

enum {
	BFW_NETX_GPIO_CFG7_iocfg     = 2,  // [1:0]
	BFW_NETX_GPIO_CFG7_inv       = 1,  // [2]
	BFW_NETX_GPIO_CFG7_mode      = 2,  // [4:3]
	BFW_NETX_GPIO_CFG7_count_ref = 3,  // [7:5]
	BFW_NETX_GPIO_CFG7_reserved1 = 24  // [31:8]
};

typedef struct GPIO_CFG7_BIT_Ttag {
	unsigned int iocfg     : BFW_NETX_GPIO_CFG7_iocfg;     // analog to gpio_cfg0 
	unsigned int inv       : BFW_NETX_GPIO_CFG7_inv;       // analog to gpio_cfg0 
	unsigned int mode      : BFW_NETX_GPIO_CFG7_mode;      // analog to gpio_cfg0 
	unsigned int count_ref : BFW_NETX_GPIO_CFG7_count_ref; // analog to gpio_cfg0 
	unsigned int reserved1 : BFW_NETX_GPIO_CFG7_reserved1; // reserved
} GPIO_CFG7_BIT_T;

typedef union {
	unsigned int    val;
	GPIO_CFG7_BIT_T bf;
} GPIO_CFG7_T;


// ---------------------------------------------------------------------
// Register gpio_cfg8
// => GPIO pin 8 config register
// => Mode: Mode (r/w)
// ---------------------------------------------------------------------

#define REL_NETX_GPIO_CFG8 0x00000020U
#define NETX_GPIO_CFG8     0x00100820U

#define MSK_NETX_GPIO_CFG8_iocfg     0x00000003U // [1:0]
#define SRT_NETX_GPIO_CFG8_iocfg     0           
#define MSK_NETX_GPIO_CFG8_inv       0x00000004U // [2]
#define SRT_NETX_GPIO_CFG8_inv       2           
#define MSK_NETX_GPIO_CFG8_mode      0x00000018U // [4:3]
#define SRT_NETX_GPIO_CFG8_mode      3           
#define MSK_NETX_GPIO_CFG8_count_ref 0x000000e0U // [7:5]
#define SRT_NETX_GPIO_CFG8_count_ref 5           

enum {
	BFW_NETX_GPIO_CFG8_iocfg     = 2,  // [1:0]
	BFW_NETX_GPIO_CFG8_inv       = 1,  // [2]
	BFW_NETX_GPIO_CFG8_mode      = 2,  // [4:3]
	BFW_NETX_GPIO_CFG8_count_ref = 3,  // [7:5]
	BFW_NETX_GPIO_CFG8_reserved1 = 24  // [31:8]
};

typedef struct GPIO_CFG8_BIT_Ttag {
	unsigned int iocfg     : BFW_NETX_GPIO_CFG8_iocfg;     // analog to gpio_cfg0 
	unsigned int inv       : BFW_NETX_GPIO_CFG8_inv;       // analog to gpio_cfg0 
	unsigned int mode      : BFW_NETX_GPIO_CFG8_mode;      // analog to gpio_cfg0 
	unsigned int count_ref : BFW_NETX_GPIO_CFG8_count_ref; // analog to gpio_cfg0 
	unsigned int reserved1 : BFW_NETX_GPIO_CFG8_reserved1; // reserved
} GPIO_CFG8_BIT_T;

typedef union {
	unsigned int    val;
	GPIO_CFG8_BIT_T bf;
} GPIO_CFG8_T;


// ---------------------------------------------------------------------
// Register gpio_cfg9
// => GPIO pin 9 config register
// => Mode: Mode (r/w)
// ---------------------------------------------------------------------

#define REL_NETX_GPIO_CFG9 0x00000024U
#define NETX_GPIO_CFG9     0x00100824U

#define MSK_NETX_GPIO_CFG9_iocfg     0x00000003U // [1:0]
#define SRT_NETX_GPIO_CFG9_iocfg     0           
#define MSK_NETX_GPIO_CFG9_inv       0x00000004U // [2]
#define SRT_NETX_GPIO_CFG9_inv       2           
#define MSK_NETX_GPIO_CFG9_mode      0x00000018U // [4:3]
#define SRT_NETX_GPIO_CFG9_mode      3           
#define MSK_NETX_GPIO_CFG9_count_ref 0x000000e0U // [7:5]
#define SRT_NETX_GPIO_CFG9_count_ref 5           

enum {
	BFW_NETX_GPIO_CFG9_iocfg     = 2,  // [1:0]
	BFW_NETX_GPIO_CFG9_inv       = 1,  // [2]
	BFW_NETX_GPIO_CFG9_mode      = 2,  // [4:3]
	BFW_NETX_GPIO_CFG9_count_ref = 3,  // [7:5]
	BFW_NETX_GPIO_CFG9_reserved1 = 24  // [31:8]
};

typedef struct GPIO_CFG9_BIT_Ttag {
	unsigned int iocfg     : BFW_NETX_GPIO_CFG9_iocfg;     // analog to gpio_cfg0 
	unsigned int inv       : BFW_NETX_GPIO_CFG9_inv;       // analog to gpio_cfg0 
	unsigned int mode      : BFW_NETX_GPIO_CFG9_mode;      // analog to gpio_cfg0 
	unsigned int count_ref : BFW_NETX_GPIO_CFG9_count_ref; // analog to gpio_cfg0 
	unsigned int reserved1 : BFW_NETX_GPIO_CFG9_reserved1; // reserved
} GPIO_CFG9_BIT_T;

typedef union {
	unsigned int    val;
	GPIO_CFG9_BIT_T bf;
} GPIO_CFG9_T;


// ---------------------------------------------------------------------
// Register gpio_cfg10
// => GPIO pin 10 config register
// => Mode: Mode (r/w)
// ---------------------------------------------------------------------

#define REL_NETX_GPIO_CFG10 0x00000028U
#define NETX_GPIO_CFG10     0x00100828U

#define MSK_NETX_GPIO_CFG10_iocfg     0x00000003U // [1:0]
#define SRT_NETX_GPIO_CFG10_iocfg     0           
#define MSK_NETX_GPIO_CFG10_inv       0x00000004U // [2]
#define SRT_NETX_GPIO_CFG10_inv       2           
#define MSK_NETX_GPIO_CFG10_mode      0x00000018U // [4:3]
#define SRT_NETX_GPIO_CFG10_mode      3           
#define MSK_NETX_GPIO_CFG10_count_ref 0x000000e0U // [7:5]
#define SRT_NETX_GPIO_CFG10_count_ref 5           

enum {
	BFW_NETX_GPIO_CFG10_iocfg     = 2,  // [1:0]
	BFW_NETX_GPIO_CFG10_inv       = 1,  // [2]
	BFW_NETX_GPIO_CFG10_mode      = 2,  // [4:3]
	BFW_NETX_GPIO_CFG10_count_ref = 3,  // [7:5]
	BFW_NETX_GPIO_CFG10_reserved1 = 24  // [31:8]
};

typedef struct GPIO_CFG10_BIT_Ttag {
	unsigned int iocfg     : BFW_NETX_GPIO_CFG10_iocfg;     // analog to gpio_cfg0 
	unsigned int inv       : BFW_NETX_GPIO_CFG10_inv;       // analog to gpio_cfg0 
	unsigned int mode      : BFW_NETX_GPIO_CFG10_mode;      // analog to gpio_cfg0 
	unsigned int count_ref : BFW_NETX_GPIO_CFG10_count_ref; // analog to gpio_cfg0 
	unsigned int reserved1 : BFW_NETX_GPIO_CFG10_reserved1; // reserved
} GPIO_CFG10_BIT_T;

typedef union {
	unsigned int     val;
	GPIO_CFG10_BIT_T bf;
} GPIO_CFG10_T;


// ---------------------------------------------------------------------
// Register gpio_cfg11
// => GPIO pin 11 config register
// => Mode: Mode (r/w)
// ---------------------------------------------------------------------

#define REL_NETX_GPIO_CFG11 0x0000002CU
#define NETX_GPIO_CFG11     0x0010082CU

#define MSK_NETX_GPIO_CFG11_iocfg     0x00000003U // [1:0]
#define SRT_NETX_GPIO_CFG11_iocfg     0           
#define MSK_NETX_GPIO_CFG11_inv       0x00000004U // [2]
#define SRT_NETX_GPIO_CFG11_inv       2           
#define MSK_NETX_GPIO_CFG11_mode      0x00000018U // [4:3]
#define SRT_NETX_GPIO_CFG11_mode      3           
#define MSK_NETX_GPIO_CFG11_count_ref 0x000000e0U // [7:5]
#define SRT_NETX_GPIO_CFG11_count_ref 5           

enum {
	BFW_NETX_GPIO_CFG11_iocfg     = 2,  // [1:0]
	BFW_NETX_GPIO_CFG11_inv       = 1,  // [2]
	BFW_NETX_GPIO_CFG11_mode      = 2,  // [4:3]
	BFW_NETX_GPIO_CFG11_count_ref = 3,  // [7:5]
	BFW_NETX_GPIO_CFG11_reserved1 = 24  // [31:8]
};

typedef struct GPIO_CFG11_BIT_Ttag {
	unsigned int iocfg     : BFW_NETX_GPIO_CFG11_iocfg;     // analog to gpio_cfg0 
	unsigned int inv       : BFW_NETX_GPIO_CFG11_inv;       // analog to gpio_cfg0 
	unsigned int mode      : BFW_NETX_GPIO_CFG11_mode;      // analog to gpio_cfg0 
	unsigned int count_ref : BFW_NETX_GPIO_CFG11_count_ref; // analog to gpio_cfg0 
	unsigned int reserved1 : BFW_NETX_GPIO_CFG11_reserved1; // reserved
} GPIO_CFG11_BIT_T;

typedef union {
	unsigned int     val;
	GPIO_CFG11_BIT_T bf;
} GPIO_CFG11_T;


// ---------------------------------------------------------------------
// Register gpio_cfg12
// => GPIO pin 12 config register
// => Mode: Mode (r/w)
// ---------------------------------------------------------------------

#define REL_NETX_GPIO_CFG12 0x00000030U
#define NETX_GPIO_CFG12     0x00100830U

#define MSK_NETX_GPIO_CFG12_iocfg     0x00000003U // [1:0]
#define SRT_NETX_GPIO_CFG12_iocfg     0           
#define MSK_NETX_GPIO_CFG12_inv       0x00000004U // [2]
#define SRT_NETX_GPIO_CFG12_inv       2           
#define MSK_NETX_GPIO_CFG12_mode      0x00000018U // [4:3]
#define SRT_NETX_GPIO_CFG12_mode      3           
#define MSK_NETX_GPIO_CFG12_count_ref 0x000000e0U // [7:5]
#define SRT_NETX_GPIO_CFG12_count_ref 5           

enum {
	BFW_NETX_GPIO_CFG12_iocfg     = 2,  // [1:0]
	BFW_NETX_GPIO_CFG12_inv       = 1,  // [2]
	BFW_NETX_GPIO_CFG12_mode      = 2,  // [4:3]
	BFW_NETX_GPIO_CFG12_count_ref = 3,  // [7:5]
	BFW_NETX_GPIO_CFG12_reserved1 = 24  // [31:8]
};

typedef struct GPIO_CFG12_BIT_Ttag {
	unsigned int iocfg     : BFW_NETX_GPIO_CFG12_iocfg;     // analog to gpio_cfg0 
	unsigned int inv       : BFW_NETX_GPIO_CFG12_inv;       // analog to gpio_cfg0 
	unsigned int mode      : BFW_NETX_GPIO_CFG12_mode;      // analog to gpio_cfg0 
	unsigned int count_ref : BFW_NETX_GPIO_CFG12_count_ref; // analog to gpio_cfg0 
	unsigned int reserved1 : BFW_NETX_GPIO_CFG12_reserved1; // reserved
} GPIO_CFG12_BIT_T;

typedef union {
	unsigned int     val;
	GPIO_CFG12_BIT_T bf;
} GPIO_CFG12_T;


// ---------------------------------------------------------------------
// Register gpio_cfg13
// => GPIO pin 13 config register
// => Mode: Mode (r/w)
// ---------------------------------------------------------------------

#define REL_NETX_GPIO_CFG13 0x00000034U
#define NETX_GPIO_CFG13     0x00100834U

#define MSK_NETX_GPIO_CFG13_iocfg     0x00000003U // [1:0]
#define SRT_NETX_GPIO_CFG13_iocfg     0           
#define MSK_NETX_GPIO_CFG13_inv       0x00000004U // [2]
#define SRT_NETX_GPIO_CFG13_inv       2           
#define MSK_NETX_GPIO_CFG13_mode      0x00000018U // [4:3]
#define SRT_NETX_GPIO_CFG13_mode      3           
#define MSK_NETX_GPIO_CFG13_count_ref 0x000000e0U // [7:5]
#define SRT_NETX_GPIO_CFG13_count_ref 5           

enum {
	BFW_NETX_GPIO_CFG13_iocfg     = 2,  // [1:0]
	BFW_NETX_GPIO_CFG13_inv       = 1,  // [2]
	BFW_NETX_GPIO_CFG13_mode      = 2,  // [4:3]
	BFW_NETX_GPIO_CFG13_count_ref = 3,  // [7:5]
	BFW_NETX_GPIO_CFG13_reserved1 = 24  // [31:8]
};

typedef struct GPIO_CFG13_BIT_Ttag {
	unsigned int iocfg     : BFW_NETX_GPIO_CFG13_iocfg;     // analog to gpio_cfg0 
	unsigned int inv       : BFW_NETX_GPIO_CFG13_inv;       // analog to gpio_cfg0 
	unsigned int mode      : BFW_NETX_GPIO_CFG13_mode;      // analog to gpio_cfg0 
	unsigned int count_ref : BFW_NETX_GPIO_CFG13_count_ref; // analog to gpio_cfg0 
	unsigned int reserved1 : BFW_NETX_GPIO_CFG13_reserved1; // reserved
} GPIO_CFG13_BIT_T;

typedef union {
	unsigned int     val;
	GPIO_CFG13_BIT_T bf;
} GPIO_CFG13_T;


// ---------------------------------------------------------------------
// Register gpio_cfg14
// => GPIO pin 14 config register
// => Mode: Mode (r/w)
// ---------------------------------------------------------------------

#define REL_NETX_GPIO_CFG14 0x00000038U
#define NETX_GPIO_CFG14     0x00100838U

#define MSK_NETX_GPIO_CFG14_iocfg     0x00000003U // [1:0]
#define SRT_NETX_GPIO_CFG14_iocfg     0           
#define MSK_NETX_GPIO_CFG14_inv       0x00000004U // [2]
#define SRT_NETX_GPIO_CFG14_inv       2           
#define MSK_NETX_GPIO_CFG14_mode      0x00000018U // [4:3]
#define SRT_NETX_GPIO_CFG14_mode      3           
#define MSK_NETX_GPIO_CFG14_count_ref 0x000000e0U // [7:5]
#define SRT_NETX_GPIO_CFG14_count_ref 5           

enum {
	BFW_NETX_GPIO_CFG14_iocfg     = 2,  // [1:0]
	BFW_NETX_GPIO_CFG14_inv       = 1,  // [2]
	BFW_NETX_GPIO_CFG14_mode      = 2,  // [4:3]
	BFW_NETX_GPIO_CFG14_count_ref = 3,  // [7:5]
	BFW_NETX_GPIO_CFG14_reserved1 = 24  // [31:8]
};

typedef struct GPIO_CFG14_BIT_Ttag {
	unsigned int iocfg     : BFW_NETX_GPIO_CFG14_iocfg;     // analog to gpio_cfg0 
	unsigned int inv       : BFW_NETX_GPIO_CFG14_inv;       // analog to gpio_cfg0 
	unsigned int mode      : BFW_NETX_GPIO_CFG14_mode;      // analog to gpio_cfg0 
	unsigned int count_ref : BFW_NETX_GPIO_CFG14_count_ref; // analog to gpio_cfg0 
	unsigned int reserved1 : BFW_NETX_GPIO_CFG14_reserved1; // reserved
} GPIO_CFG14_BIT_T;

typedef union {
	unsigned int     val;
	GPIO_CFG14_BIT_T bf;
} GPIO_CFG14_T;


// ---------------------------------------------------------------------
// Register gpio_cfg15
// => GPIO pin 15 config register
// => Mode: Mode (r/w)
// ---------------------------------------------------------------------

#define REL_NETX_GPIO_CFG15 0x0000003CU
#define NETX_GPIO_CFG15     0x0010083CU

#define MSK_NETX_GPIO_CFG15_iocfg     0x00000003U // [1:0]
#define SRT_NETX_GPIO_CFG15_iocfg     0           
#define MSK_NETX_GPIO_CFG15_inv       0x00000004U // [2]
#define SRT_NETX_GPIO_CFG15_inv       2           
#define MSK_NETX_GPIO_CFG15_mode      0x00000018U // [4:3]
#define SRT_NETX_GPIO_CFG15_mode      3           
#define MSK_NETX_GPIO_CFG15_count_ref 0x000000e0U // [7:5]
#define SRT_NETX_GPIO_CFG15_count_ref 5           

enum {
	BFW_NETX_GPIO_CFG15_iocfg     = 2,  // [1:0]
	BFW_NETX_GPIO_CFG15_inv       = 1,  // [2]
	BFW_NETX_GPIO_CFG15_mode      = 2,  // [4:3]
	BFW_NETX_GPIO_CFG15_count_ref = 3,  // [7:5]
	BFW_NETX_GPIO_CFG15_reserved1 = 24  // [31:8]
};

typedef struct GPIO_CFG15_BIT_Ttag {
	unsigned int iocfg     : BFW_NETX_GPIO_CFG15_iocfg;     // analog to gpio_cfg0 
	unsigned int inv       : BFW_NETX_GPIO_CFG15_inv;       // analog to gpio_cfg0 
	unsigned int mode      : BFW_NETX_GPIO_CFG15_mode;      // analog to gpio_cfg0 
	unsigned int count_ref : BFW_NETX_GPIO_CFG15_count_ref; // analog to gpio_cfg0 
	unsigned int reserved1 : BFW_NETX_GPIO_CFG15_reserved1; // reserved
} GPIO_CFG15_BIT_T;

typedef union {
	unsigned int     val;
	GPIO_CFG15_BIT_T bf;
} GPIO_CFG15_T;


// ---------------------------------------------------------------------
// Register gpio_tc0
// => GPIO pin 0 threshold or capture register
// => Mode: Mode (r/w)
// ---------------------------------------------------------------------

#define REL_NETX_GPIO_THRSH_CAPT0 0x00000040U
#define NETX_GPIO_THRSH_CAPT0     0x00100840U

#define MSK_NETX_GPIO_THRSH_CAPT0_val 0xffffffffU // [31:0]
#define SRT_NETX_GPIO_THRSH_CAPT0_val 0           

enum {
	BFW_NETX_GPIO_THRSH_CAPT0_val = 32  // [31:0]
};

typedef struct GPIO_TC0_BIT_Ttag {
	unsigned int val : BFW_NETX_GPIO_THRSH_CAPT0_val; // holds the counter threshold value for the pwm mode 
	                                                        // or the captured value in the capture mode
} GPIO_TC0_BIT_T;

typedef union {
	unsigned int   val;
	GPIO_TC0_BIT_T bf;
} GPIO_TC0_T;


// ---------------------------------------------------------------------
// Register gpio_tc1
// => GPIO pin 1 threshold or capture register
// => Mode: Mode (r/w)
// ---------------------------------------------------------------------

#define REL_NETX_GPIO_THRSH_CAPT1 0x00000044U
#define NETX_GPIO_THRSH_CAPT1     0x00100844U

#define MSK_NETX_GPIO_THRSH_CAPT1_val 0xffffffffU // [31:0]
#define SRT_NETX_GPIO_THRSH_CAPT1_val 0           

enum {
	BFW_NETX_GPIO_THRSH_CAPT1_val = 32  // [31:0]
};

typedef struct GPIO_TC1_BIT_Ttag {
	unsigned int val : BFW_NETX_GPIO_THRSH_CAPT1_val; // holds the counter threshold value for the pwm mode 
	                                                        // or the captured value in the capture mode
} GPIO_TC1_BIT_T;

typedef union {
	unsigned int   val;
	GPIO_TC1_BIT_T bf;
} GPIO_TC1_T;


// ---------------------------------------------------------------------
// Register gpio_tc2
// => GPIO pin 2 threshold or capture register
// => Mode: Mode (r/w)
// ---------------------------------------------------------------------

#define REL_NETX_GPIO_THRSH_CAPT2 0x00000048U
#define NETX_GPIO_THRSH_CAPT2     0x00100848U

#define MSK_NETX_GPIO_THRSH_CAPT2_val 0xffffffffU // [31:0]
#define SRT_NETX_GPIO_THRSH_CAPT2_val 0           

enum {
	BFW_NETX_GPIO_THRSH_CAPT2_val = 32  // [31:0]
};

typedef struct GPIO_TC2_BIT_Ttag {
	unsigned int val : BFW_NETX_GPIO_THRSH_CAPT2_val; // holds the counter threshold value for the pwm mode 
	                                                        // or the captured value in the capture mode
} GPIO_TC2_BIT_T;

typedef union {
	unsigned int   val;
	GPIO_TC2_BIT_T bf;
} GPIO_TC2_T;


// ---------------------------------------------------------------------
// Register gpio_tc3
// => GPIO pin 3 threshold or capture register
// => Mode: Mode (r/w)
// ---------------------------------------------------------------------

#define REL_NETX_GPIO_THRSH_CAPT3 0x0000004CU
#define NETX_GPIO_THRSH_CAPT3     0x0010084CU

#define MSK_NETX_GPIO_THRSH_CAPT3_val 0xffffffffU // [31:0]
#define SRT_NETX_GPIO_THRSH_CAPT3_val 0           

enum {
	BFW_NETX_GPIO_THRSH_CAPT3_val = 32  // [31:0]
};

typedef struct GPIO_TC3_BIT_Ttag {
	unsigned int val : BFW_NETX_GPIO_THRSH_CAPT3_val; // holds the counter threshold value for the pwm mode 
	                                                        // or the captured value in the capture mode
} GPIO_TC3_BIT_T;

typedef union {
	unsigned int   val;
	GPIO_TC3_BIT_T bf;
} GPIO_TC3_T;


// ---------------------------------------------------------------------
// Register gpio_tc4
// => GPIO pin 4 threshold or capture register
// => Mode: Mode (r/w)
// ---------------------------------------------------------------------

#define REL_NETX_GPIO_THRSH_CAPT4 0x00000050U
#define NETX_GPIO_THRSH_CAPT4     0x00100850U

#define MSK_NETX_GPIO_THRSH_CAPT4_val 0xffffffffU // [31:0]
#define SRT_NETX_GPIO_THRSH_CAPT4_val 0           

enum {
	BFW_NETX_GPIO_THRSH_CAPT4_val = 32  // [31:0]
};

typedef struct GPIO_TC4_BIT_Ttag {
	unsigned int val : BFW_NETX_GPIO_THRSH_CAPT4_val; // holds the counter threshold value for the pwm mode 
	                                                        // or the captured value in the capture mode
} GPIO_TC4_BIT_T;

typedef union {
	unsigned int   val;
	GPIO_TC4_BIT_T bf;
} GPIO_TC4_T;


// ---------------------------------------------------------------------
// Register gpio_tc5
// => GPIO pin 5 threshold or capture register
// => Mode: Mode (r/w)
// ---------------------------------------------------------------------

#define REL_NETX_GPIO_THRSH_CAPT5 0x00000054U
#define NETX_GPIO_THRSH_CAPT5     0x00100854U

#define MSK_NETX_GPIO_THRSH_CAPT5_val 0xffffffffU // [31:0]
#define SRT_NETX_GPIO_THRSH_CAPT5_val 0           

enum {
	BFW_NETX_GPIO_THRSH_CAPT5_val = 32  // [31:0]
};

typedef struct GPIO_TC5_BIT_Ttag {
	unsigned int val : BFW_NETX_GPIO_THRSH_CAPT5_val; // holds the counter threshold value for the pwm mode 
	                                                        // or the captured value in the capture mode
} GPIO_TC5_BIT_T;

typedef union {
	unsigned int   val;
	GPIO_TC5_BIT_T bf;
} GPIO_TC5_T;


// ---------------------------------------------------------------------
// Register gpio_tc6
// => GPIO pin 6 threshold or capture register
// => Mode: Mode (r/w)
// ---------------------------------------------------------------------

#define REL_NETX_GPIO_THRSH_CAPT6 0x00000058U
#define NETX_GPIO_THRSH_CAPT6     0x00100858U

#define MSK_NETX_GPIO_THRSH_CAPT6_val 0xffffffffU // [31:0]
#define SRT_NETX_GPIO_THRSH_CAPT6_val 0           

enum {
	BFW_NETX_GPIO_THRSH_CAPT6_val = 32  // [31:0]
};

typedef struct GPIO_TC6_BIT_Ttag {
	unsigned int val : BFW_NETX_GPIO_THRSH_CAPT6_val; // holds the counter threshold value for the pwm mode 
	                                                        // or the captured value in the capture mode
} GPIO_TC6_BIT_T;

typedef union {
	unsigned int   val;
	GPIO_TC6_BIT_T bf;
} GPIO_TC6_T;


// ---------------------------------------------------------------------
// Register gpio_tc7
// => GPIO pin 7 threshold or capture register
// => Mode: Mode (r/w)
// ---------------------------------------------------------------------

#define REL_NETX_GPIO_THRSH_CAPT7 0x0000005CU
#define NETX_GPIO_THRSH_CAPT7     0x0010085CU

#define MSK_NETX_GPIO_THRSH_CAPT7_val 0xffffffffU // [31:0]
#define SRT_NETX_GPIO_THRSH_CAPT7_val 0           

enum {
	BFW_NETX_GPIO_THRSH_CAPT7_val = 32  // [31:0]
};

typedef struct GPIO_TC7_BIT_Ttag {
	unsigned int val : BFW_NETX_GPIO_THRSH_CAPT7_val; // holds the counter threshold value for the pwm mode 
	                                                        // or the captured value in the capture mode
} GPIO_TC7_BIT_T;

typedef union {
	unsigned int   val;
	GPIO_TC7_BIT_T bf;
} GPIO_TC7_T;


// ---------------------------------------------------------------------
// Register gpio_tc8
// => GPIO pin 8 threshold or capture register
// => Mode: Mode (r/w)
// ---------------------------------------------------------------------

#define REL_NETX_GPIO_THRSH_CAPT8 0x00000060U
#define NETX_GPIO_THRSH_CAPT8     0x00100860U

#define MSK_NETX_GPIO_THRSH_CAPT8_val 0xffffffffU // [31:0]
#define SRT_NETX_GPIO_THRSH_CAPT8_val 0           

enum {
	BFW_NETX_GPIO_THRSH_CAPT8_val = 32  // [31:0]
};

typedef struct GPIO_TC8_BIT_Ttag {
	unsigned int val : BFW_NETX_GPIO_THRSH_CAPT8_val; // holds the counter threshold value for the pwm mode 
	                                                        // or the captured value in the capture mode
} GPIO_TC8_BIT_T;

typedef union {
	unsigned int   val;
	GPIO_TC8_BIT_T bf;
} GPIO_TC8_T;


// ---------------------------------------------------------------------
// Register gpio_tc9
// => GPIO pin 9 threshold or capture register
// => Mode: Mode (r/w)
// ---------------------------------------------------------------------

#define REL_NETX_GPIO_THRSH_CAPT9 0x00000064U
#define NETX_GPIO_THRSH_CAPT9     0x00100864U

#define MSK_NETX_GPIO_THRSH_CAPT9_val 0xffffffffU // [31:0]
#define SRT_NETX_GPIO_THRSH_CAPT9_val 0           

enum {
	BFW_NETX_GPIO_THRSH_CAPT9_val = 32  // [31:0]
};

typedef struct GPIO_TC9_BIT_Ttag {
	unsigned int val : BFW_NETX_GPIO_THRSH_CAPT9_val; // holds the counter threshold value for the pwm mode 
	                                                        // or the captured value in the capture mode
} GPIO_TC9_BIT_T;

typedef union {
	unsigned int   val;
	GPIO_TC9_BIT_T bf;
} GPIO_TC9_T;


// ---------------------------------------------------------------------
// Register gpio_tc10
// => GPIO pin 10 threshold or capture register
// => Mode: Mode (r/w)
// ---------------------------------------------------------------------

#define REL_NETX_GPIO_THRSH_CAPT10 0x00000068U
#define NETX_GPIO_THRSH_CAPT10     0x00100868U

#define MSK_NETX_GPIO_THRSH_CAPT10_val 0xffffffffU // [31:0]
#define SRT_NETX_GPIO_THRSH_CAPT10_val 0           

enum {
	BFW_NETX_GPIO_THRSH_CAPT10_val = 32  // [31:0]
};

typedef struct GPIO_TC10_BIT_Ttag {
	unsigned int val : BFW_NETX_GPIO_THRSH_CAPT10_val; // holds the counter threshold value for the pwm mode 
	                                                        // or the captured value in the capture mode
} GPIO_TC10_BIT_T;

typedef union {
	unsigned int    val;
	GPIO_TC10_BIT_T bf;
} GPIO_TC10_T;


// ---------------------------------------------------------------------
// Register gpio_tc11
// => GPIO pin 11 threshold or capture register
// => Mode: Mode (r/w)
// ---------------------------------------------------------------------

#define REL_NETX_GPIO_THRSH_CAPT11 0x0000006CU
#define NETX_GPIO_THRSH_CAPT11     0x0010086CU

#define MSK_NETX_GPIO_THRSH_CAPT11_val 0xffffffffU // [31:0]
#define SRT_NETX_GPIO_THRSH_CAPT11_val 0           

enum {
	BFW_NETX_GPIO_THRSH_CAPT11_val = 32  // [31:0]
};

typedef struct GPIO_TC11_BIT_Ttag {
	unsigned int val : BFW_NETX_GPIO_THRSH_CAPT11_val; // holds the counter threshold value for the pwm mode 
	                                                        // or the captured value in the capture mode
} GPIO_TC11_BIT_T;

typedef union {
	unsigned int    val;
	GPIO_TC11_BIT_T bf;
} GPIO_TC11_T;


// ---------------------------------------------------------------------
// Register gpio_tc12
// => GPIO pin 12 threshold or capture register
// => Mode: Mode (r/w)
// ---------------------------------------------------------------------

#define REL_NETX_GPIO_THRSH_CAPT12 0x00000070U
#define NETX_GPIO_THRSH_CAPT12     0x00100870U

#define MSK_NETX_GPIO_THRSH_CAPT12_val 0xffffffffU // [31:0]
#define SRT_NETX_GPIO_THRSH_CAPT12_val 0           

enum {
	BFW_NETX_GPIO_THRSH_CAPT12_val = 32  // [31:0]
};

typedef struct GPIO_TC12_BIT_Ttag {
	unsigned int val : BFW_NETX_GPIO_THRSH_CAPT12_val; // holds the counter threshold value for the pwm mode 
	                                                        // or the captured value in the capture mode
} GPIO_TC12_BIT_T;

typedef union {
	unsigned int    val;
	GPIO_TC12_BIT_T bf;
} GPIO_TC12_T;


// ---------------------------------------------------------------------
// Register gpio_tc13
// => GPIO pin 13 threshold or capture register
// => Mode: Mode (r/w)
// ---------------------------------------------------------------------

#define REL_NETX_GPIO_THRSH_CAPT13 0x00000074U
#define NETX_GPIO_THRSH_CAPT13     0x00100874U

#define MSK_NETX_GPIO_THRSH_CAPT13_val 0xffffffffU // [31:0]
#define SRT_NETX_GPIO_THRSH_CAPT13_val 0           

enum {
	BFW_NETX_GPIO_THRSH_CAPT13_val = 32  // [31:0]
};

typedef struct GPIO_TC13_BIT_Ttag {
	unsigned int val : BFW_NETX_GPIO_THRSH_CAPT13_val; // holds the counter threshold value for the pwm mode 
	                                                        // or the captured value in the capture mode
} GPIO_TC13_BIT_T;

typedef union {
	unsigned int    val;
	GPIO_TC13_BIT_T bf;
} GPIO_TC13_T;


// ---------------------------------------------------------------------
// Register gpio_tc14
// => GPIO pin 14 threshold or capture register
// => Mode: Mode (r/w)
// ---------------------------------------------------------------------

#define REL_NETX_GPIO_THRSH_CAPT14 0x00000078U
#define NETX_GPIO_THRSH_CAPT14     0x00100878U

#define MSK_NETX_GPIO_THRSH_CAPT14_val 0xffffffffU // [31:0]
#define SRT_NETX_GPIO_THRSH_CAPT14_val 0           

enum {
	BFW_NETX_GPIO_THRSH_CAPT14_val = 32  // [31:0]
};

typedef struct GPIO_TC14_BIT_Ttag {
	unsigned int val : BFW_NETX_GPIO_THRSH_CAPT14_val; // holds the counter threshold value for the pwm mode 
	                                                        // or the captured value in the capture mode
} GPIO_TC14_BIT_T;

typedef union {
	unsigned int    val;
	GPIO_TC14_BIT_T bf;
} GPIO_TC14_T;


// ---------------------------------------------------------------------
// Register gpio_tc15
// => GPIO pin 15 threshold or capture register
// => Mode: Mode (r/w)
// ---------------------------------------------------------------------

#define REL_NETX_GPIO_THRSH_CAPT15 0x0000007CU
#define NETX_GPIO_THRSH_CAPT15     0x0010087CU

#define MSK_NETX_GPIO_THRSH_CAPT15_val 0xffffffffU // [31:0]
#define SRT_NETX_GPIO_THRSH_CAPT15_val 0           

enum {
	BFW_NETX_GPIO_THRSH_CAPT15_val = 32  // [31:0]
};

typedef struct GPIO_TC15_BIT_Ttag {
	unsigned int val : BFW_NETX_GPIO_THRSH_CAPT15_val; // holds the counter threshold value for the pwm mode 
	                                                        // or the captured value in the capture mode
} GPIO_TC15_BIT_T;

typedef union {
	unsigned int    val;
	GPIO_TC15_BIT_T bf;
} GPIO_TC15_T;


// ---------------------------------------------------------------------
// Register gpio_counter0_ctrl
// => GPIO counter0 control register
// => Mode: Mode (r/w)
// ---------------------------------------------------------------------

#define REL_NETX_GPIO_CNTR0_CTRL 0x00000080U
#define NETX_GPIO_CNTR0_CTRL     0x00100880U

#define MSK_NETX_GPIO_CNTR0_CTRL_run       0x00000001U // [0]
#define SRT_NETX_GPIO_CNTR0_CTRL_run       0           
#define MSK_NETX_GPIO_CNTR0_CTRL_sym_nasym 0x00000002U // [1]
#define SRT_NETX_GPIO_CNTR0_CTRL_sym_nasym 1           
#define MSK_NETX_GPIO_CNTR0_CTRL_once      0x00000004U // [2]
#define SRT_NETX_GPIO_CNTR0_CTRL_once      2           
#define MSK_NETX_GPIO_CNTR0_CTRL_irq_en    0x00000008U // [3]
#define SRT_NETX_GPIO_CNTR0_CTRL_irq_en    3           
#define MSK_NETX_GPIO_CNTR0_CTRL_cnt_event 0x00000010U // [4]
#define SRT_NETX_GPIO_CNTR0_CTRL_cnt_event 4           
#define MSK_NETX_GPIO_CNTR0_CTRL_rst_en    0x00000020U // [5]
#define SRT_NETX_GPIO_CNTR0_CTRL_rst_en    5           
#define MSK_NETX_GPIO_CNTR0_CTRL_sel_event 0x00000040U // [6]
#define SRT_NETX_GPIO_CNTR0_CTRL_sel_event 6           
#define MSK_NETX_GPIO_CNTR0_CTRL_gpio_ref  0x00000780U // [10:7]
#define SRT_NETX_GPIO_CNTR0_CTRL_gpio_ref  7           

enum {
	BFW_NETX_GPIO_CNTR0_CTRL_run       = 1,  // [0]
	BFW_NETX_GPIO_CNTR0_CTRL_sym_nasym = 1,  // [1]
	BFW_NETX_GPIO_CNTR0_CTRL_once      = 1,  // [2]
	BFW_NETX_GPIO_CNTR0_CTRL_irq_en    = 1,  // [3]
	BFW_NETX_GPIO_CNTR0_CTRL_cnt_event = 1,  // [4]
	BFW_NETX_GPIO_CNTR0_CTRL_rst_en    = 1,  // [5]
	BFW_NETX_GPIO_CNTR0_CTRL_sel_event = 1,  // [6]
	BFW_NETX_GPIO_CNTR0_CTRL_gpio_ref  = 4,  // [10:7]
	BFW_NETX_GPIO_CNTR0_CTRL_reserved1 = 21  // [31:11]
};

typedef struct GPIO_COUNTER0_CTRL_BIT_Ttag {
	unsigned int run       : BFW_NETX_GPIO_CNTR0_CTRL_run;       // 1 .. start counter; 0 .. stop counter 
	unsigned int sym_nasym : BFW_NETX_GPIO_CNTR0_CTRL_sym_nasym; // 1 .. symmetric mode (triangle); 0 .. asymmetric mode (sawtooth) 
	unsigned int once      : BFW_NETX_GPIO_CNTR0_CTRL_once;      // 1 .. count once; 0 .. count continue 
	unsigned int irq_en    : BFW_NETX_GPIO_CNTR0_CTRL_irq_en;    // 1 .. enable interrupt request; 0 .. disable interrupt request 
	unsigned int cnt_event : BFW_NETX_GPIO_CNTR0_CTRL_cnt_event; // 1 .. count external event (edge, level); 0 .. count every clock cycle 
	unsigned int rst_en    : BFW_NETX_GPIO_CNTR0_CTRL_rst_en;    // 1 .. enable automatic reset; 0 .. disable automatic reset 
	unsigned int sel_event : BFW_NETX_GPIO_CNTR0_CTRL_sel_event; // select external event 
	                                                        // 0 .. (high) level
	                                                        // 1 .. (pos.) edge
	unsigned int gpio_ref  : BFW_NETX_GPIO_CNTR0_CTRL_gpio_ref;  // gpio reference (0 - 15) 
	unsigned int reserved1 : BFW_NETX_GPIO_CNTR0_CTRL_reserved1; // reserved
} GPIO_COUNTER0_CTRL_BIT_T;

typedef union {
	unsigned int             val;
	GPIO_COUNTER0_CTRL_BIT_T bf;
} GPIO_COUNTER0_CTRL_T;


// ---------------------------------------------------------------------
// Register gpio_counter1_ctrl
// => GPIO counter1 control register
// => Mode: Mode (r/w)
// ---------------------------------------------------------------------

#define REL_NETX_GPIO_CNTR1_CTRL 0x00000084U
#define NETX_GPIO_CNTR1_CTRL     0x00100884U

#define MSK_NETX_GPIO_CNTR1_CTRL_run       0x00000001U // [0]
#define SRT_NETX_GPIO_CNTR1_CTRL_run       0           
#define MSK_NETX_GPIO_CNTR1_CTRL_sym_nasym 0x00000002U // [1]
#define SRT_NETX_GPIO_CNTR1_CTRL_sym_nasym 1           
#define MSK_NETX_GPIO_CNTR1_CTRL_once      0x00000004U // [2]
#define SRT_NETX_GPIO_CNTR1_CTRL_once      2           
#define MSK_NETX_GPIO_CNTR1_CTRL_irq_en    0x00000008U // [3]
#define SRT_NETX_GPIO_CNTR1_CTRL_irq_en    3           
#define MSK_NETX_GPIO_CNTR1_CTRL_cnt_event 0x00000010U // [4]
#define SRT_NETX_GPIO_CNTR1_CTRL_cnt_event 4           
#define MSK_NETX_GPIO_CNTR1_CTRL_rst_en    0x00000020U // [5]
#define SRT_NETX_GPIO_CNTR1_CTRL_rst_en    5           
#define MSK_NETX_GPIO_CNTR1_CTRL_sel_event 0x00000040U // [6]
#define SRT_NETX_GPIO_CNTR1_CTRL_sel_event 6           
#define MSK_NETX_GPIO_CNTR1_CTRL_gpio_ref  0x00000780U // [10:7]
#define SRT_NETX_GPIO_CNTR1_CTRL_gpio_ref  7           

enum {
	BFW_NETX_GPIO_CNTR1_CTRL_run       = 1,  // [0]
	BFW_NETX_GPIO_CNTR1_CTRL_sym_nasym = 1,  // [1]
	BFW_NETX_GPIO_CNTR1_CTRL_once      = 1,  // [2]
	BFW_NETX_GPIO_CNTR1_CTRL_irq_en    = 1,  // [3]
	BFW_NETX_GPIO_CNTR1_CTRL_cnt_event = 1,  // [4]
	BFW_NETX_GPIO_CNTR1_CTRL_rst_en    = 1,  // [5]
	BFW_NETX_GPIO_CNTR1_CTRL_sel_event = 1,  // [6]
	BFW_NETX_GPIO_CNTR1_CTRL_gpio_ref  = 4,  // [10:7]
	BFW_NETX_GPIO_CNTR1_CTRL_reserved1 = 21  // [31:11]
};

typedef struct GPIO_COUNTER1_CTRL_BIT_Ttag {
	unsigned int run       : BFW_NETX_GPIO_CNTR1_CTRL_run;       // 1 .. start counter; 0 .. stop counter 
	unsigned int sym_nasym : BFW_NETX_GPIO_CNTR1_CTRL_sym_nasym; // 1 .. symmetric mode (triangle); 0 .. asymmetric mode (sawtooth) 
	unsigned int once      : BFW_NETX_GPIO_CNTR1_CTRL_once;      // 1 .. count once; 0 .. count continue 
	unsigned int irq_en    : BFW_NETX_GPIO_CNTR1_CTRL_irq_en;    // 1 .. enable interrupt request; 0 .. disable interrupt request 
	unsigned int cnt_event : BFW_NETX_GPIO_CNTR1_CTRL_cnt_event; // 1 .. count external event (edge, level); 0 .. count every clock cycle 
	unsigned int rst_en    : BFW_NETX_GPIO_CNTR1_CTRL_rst_en;    // 1 .. enable automatic reset; 0 .. disable automatic reset 
	unsigned int sel_event : BFW_NETX_GPIO_CNTR1_CTRL_sel_event; // select external event 
	                                                        // 0 .. (high) level
	                                                        // 1 .. (pos.) edge
	unsigned int gpio_ref  : BFW_NETX_GPIO_CNTR1_CTRL_gpio_ref;  // gpio reference (0 - 15) 
	unsigned int reserved1 : BFW_NETX_GPIO_CNTR1_CTRL_reserved1; // reserved
} GPIO_COUNTER1_CTRL_BIT_T;

typedef union {
	unsigned int             val;
	GPIO_COUNTER1_CTRL_BIT_T bf;
} GPIO_COUNTER1_CTRL_T;


// ---------------------------------------------------------------------
// Register gpio_counter2_ctrl
// => GPIO counter2 control register
// => Mode: Mode (r/w)
// ---------------------------------------------------------------------

#define REL_NETX_GPIO_CNTR2_CTRL 0x00000088U
#define NETX_GPIO_CNTR2_CTRL     0x00100888U

#define MSK_NETX_GPIO_CNTR2_CTRL_run       0x00000001U // [0]
#define SRT_NETX_GPIO_CNTR2_CTRL_run       0           
#define MSK_NETX_GPIO_CNTR2_CTRL_sym_nasym 0x00000002U // [1]
#define SRT_NETX_GPIO_CNTR2_CTRL_sym_nasym 1           
#define MSK_NETX_GPIO_CNTR2_CTRL_once      0x00000004U // [2]
#define SRT_NETX_GPIO_CNTR2_CTRL_once      2           
#define MSK_NETX_GPIO_CNTR2_CTRL_irq_en    0x00000008U // [3]
#define SRT_NETX_GPIO_CNTR2_CTRL_irq_en    3           
#define MSK_NETX_GPIO_CNTR2_CTRL_cnt_event 0x00000010U // [4]
#define SRT_NETX_GPIO_CNTR2_CTRL_cnt_event 4           
#define MSK_NETX_GPIO_CNTR2_CTRL_rst_en    0x00000020U // [5]
#define SRT_NETX_GPIO_CNTR2_CTRL_rst_en    5           
#define MSK_NETX_GPIO_CNTR2_CTRL_sel_event 0x00000040U // [6]
#define SRT_NETX_GPIO_CNTR2_CTRL_sel_event 6           
#define MSK_NETX_GPIO_CNTR2_CTRL_gpio_ref  0x00000780U // [10:7]
#define SRT_NETX_GPIO_CNTR2_CTRL_gpio_ref  7           

enum {
	BFW_NETX_GPIO_CNTR2_CTRL_run       = 1,  // [0]
	BFW_NETX_GPIO_CNTR2_CTRL_sym_nasym = 1,  // [1]
	BFW_NETX_GPIO_CNTR2_CTRL_once      = 1,  // [2]
	BFW_NETX_GPIO_CNTR2_CTRL_irq_en    = 1,  // [3]
	BFW_NETX_GPIO_CNTR2_CTRL_cnt_event = 1,  // [4]
	BFW_NETX_GPIO_CNTR2_CTRL_rst_en    = 1,  // [5]
	BFW_NETX_GPIO_CNTR2_CTRL_sel_event = 1,  // [6]
	BFW_NETX_GPIO_CNTR2_CTRL_gpio_ref  = 4,  // [10:7]
	BFW_NETX_GPIO_CNTR2_CTRL_reserved1 = 21  // [31:11]
};

typedef struct GPIO_COUNTER2_CTRL_BIT_Ttag {
	unsigned int run       : BFW_NETX_GPIO_CNTR2_CTRL_run;       // 1 .. start counter; 0 .. stop counter 
	unsigned int sym_nasym : BFW_NETX_GPIO_CNTR2_CTRL_sym_nasym; // 1 .. symmetric mode (triangle); 0 .. asymmetric mode (sawtooth) 
	unsigned int once      : BFW_NETX_GPIO_CNTR2_CTRL_once;      // 1 .. count once; 0 .. count continue 
	unsigned int irq_en    : BFW_NETX_GPIO_CNTR2_CTRL_irq_en;    // 1 .. enable interrupt request; 0 .. disable interrupt request 
	unsigned int cnt_event : BFW_NETX_GPIO_CNTR2_CTRL_cnt_event; // 1 .. count external event (edge, level); 0 .. count every clock cycle 
	unsigned int rst_en    : BFW_NETX_GPIO_CNTR2_CTRL_rst_en;    // 1 .. enable automatic reset; 0 .. disable automatic reset 
	unsigned int sel_event : BFW_NETX_GPIO_CNTR2_CTRL_sel_event; // select external event 
	                                                        // 0 .. (high) level
	                                                        // 1 .. (pos.) edge
	unsigned int gpio_ref  : BFW_NETX_GPIO_CNTR2_CTRL_gpio_ref;  // gpio reference (0 - 15) 
	unsigned int reserved1 : BFW_NETX_GPIO_CNTR2_CTRL_reserved1; // reserved
} GPIO_COUNTER2_CTRL_BIT_T;

typedef union {
	unsigned int             val;
	GPIO_COUNTER2_CTRL_BIT_T bf;
} GPIO_COUNTER2_CTRL_T;


// ---------------------------------------------------------------------
// Register gpio_counter3_ctrl
// => GPIO counter3 control register
// => Mode: Mode (r/w)
// ---------------------------------------------------------------------

#define REL_NETX_GPIO_CNTR3_CTRL 0x0000008CU
#define NETX_GPIO_CNTR3_CTRL     0x0010088CU

#define MSK_NETX_GPIO_CNTR3_CTRL_run       0x00000001U // [0]
#define SRT_NETX_GPIO_CNTR3_CTRL_run       0           
#define MSK_NETX_GPIO_CNTR3_CTRL_sym_nasym 0x00000002U // [1]
#define SRT_NETX_GPIO_CNTR3_CTRL_sym_nasym 1           
#define MSK_NETX_GPIO_CNTR3_CTRL_once      0x00000004U // [2]
#define SRT_NETX_GPIO_CNTR3_CTRL_once      2           
#define MSK_NETX_GPIO_CNTR3_CTRL_irq_en    0x00000008U // [3]
#define SRT_NETX_GPIO_CNTR3_CTRL_irq_en    3           
#define MSK_NETX_GPIO_CNTR3_CTRL_cnt_event 0x00000010U // [4]
#define SRT_NETX_GPIO_CNTR3_CTRL_cnt_event 4           
#define MSK_NETX_GPIO_CNTR3_CTRL_rst_en    0x00000020U // [5]
#define SRT_NETX_GPIO_CNTR3_CTRL_rst_en    5           
#define MSK_NETX_GPIO_CNTR3_CTRL_sel_event 0x00000040U // [6]
#define SRT_NETX_GPIO_CNTR3_CTRL_sel_event 6           
#define MSK_NETX_GPIO_CNTR3_CTRL_gpio_ref  0x00000780U // [10:7]
#define SRT_NETX_GPIO_CNTR3_CTRL_gpio_ref  7           

enum {
	BFW_NETX_GPIO_CNTR3_CTRL_run       = 1,  // [0]
	BFW_NETX_GPIO_CNTR3_CTRL_sym_nasym = 1,  // [1]
	BFW_NETX_GPIO_CNTR3_CTRL_once      = 1,  // [2]
	BFW_NETX_GPIO_CNTR3_CTRL_irq_en    = 1,  // [3]
	BFW_NETX_GPIO_CNTR3_CTRL_cnt_event = 1,  // [4]
	BFW_NETX_GPIO_CNTR3_CTRL_rst_en    = 1,  // [5]
	BFW_NETX_GPIO_CNTR3_CTRL_sel_event = 1,  // [6]
	BFW_NETX_GPIO_CNTR3_CTRL_gpio_ref  = 4,  // [10:7]
	BFW_NETX_GPIO_CNTR3_CTRL_reserved1 = 21  // [31:11]
};

typedef struct GPIO_COUNTER3_CTRL_BIT_Ttag {
	unsigned int run       : BFW_NETX_GPIO_CNTR3_CTRL_run;       // 1 .. start counter; 0 .. stop counter 
	unsigned int sym_nasym : BFW_NETX_GPIO_CNTR3_CTRL_sym_nasym; // 1 .. symmetric mode (triangle); 0 .. asymmetric mode (sawtooth) 
	unsigned int once      : BFW_NETX_GPIO_CNTR3_CTRL_once;      // 1 .. count once; 0 .. count continue 
	unsigned int irq_en    : BFW_NETX_GPIO_CNTR3_CTRL_irq_en;    // 1 .. enable interrupt request; 0 .. disable interrupt request 
	unsigned int cnt_event : BFW_NETX_GPIO_CNTR3_CTRL_cnt_event; // 1 .. count external event (edge, level); 0 .. count every clock cycle 
	unsigned int rst_en    : BFW_NETX_GPIO_CNTR3_CTRL_rst_en;    // 1 .. enable automatic reset; 0 .. disable automatic reset 
	unsigned int sel_event : BFW_NETX_GPIO_CNTR3_CTRL_sel_event; // select external event 
	                                                        // 0 .. (high) level
	                                                        // 1 .. (pos.) edge
	unsigned int gpio_ref  : BFW_NETX_GPIO_CNTR3_CTRL_gpio_ref;  // gpio reference (0 - 15) 
	unsigned int reserved1 : BFW_NETX_GPIO_CNTR3_CTRL_reserved1; // reserved
} GPIO_COUNTER3_CTRL_BIT_T;

typedef union {
	unsigned int             val;
	GPIO_COUNTER3_CTRL_BIT_T bf;
} GPIO_COUNTER3_CTRL_T;


// ---------------------------------------------------------------------
// Register gpio_counter4_ctrl
// => GPIO counter4 control register
// => Mode: Mode (r/w)
// ---------------------------------------------------------------------

#define REL_NETX_GPIO_CNTR4_CTRL 0x00000090U
#define NETX_GPIO_CNTR4_CTRL     0x00100890U

#define MSK_NETX_GPIO_CNTR4_CTRL_run       0x00000001U // [0]
#define SRT_NETX_GPIO_CNTR4_CTRL_run       0           
#define MSK_NETX_GPIO_CNTR4_CTRL_sym_nasym 0x00000002U // [1]
#define SRT_NETX_GPIO_CNTR4_CTRL_sym_nasym 1           
#define MSK_NETX_GPIO_CNTR4_CTRL_once      0x00000004U // [2]
#define SRT_NETX_GPIO_CNTR4_CTRL_once      2           
#define MSK_NETX_GPIO_CNTR4_CTRL_irq_en    0x00000008U // [3]
#define SRT_NETX_GPIO_CNTR4_CTRL_irq_en    3           
#define MSK_NETX_GPIO_CNTR4_CTRL_cnt_event 0x00000010U // [4]
#define SRT_NETX_GPIO_CNTR4_CTRL_cnt_event 4           
#define MSK_NETX_GPIO_CNTR4_CTRL_rst_en    0x00000020U // [5]
#define SRT_NETX_GPIO_CNTR4_CTRL_rst_en    5           
#define MSK_NETX_GPIO_CNTR4_CTRL_sel_event 0x00000040U // [6]
#define SRT_NETX_GPIO_CNTR4_CTRL_sel_event 6           
#define MSK_NETX_GPIO_CNTR4_CTRL_gpio_ref  0x00000780U // [10:7]
#define SRT_NETX_GPIO_CNTR4_CTRL_gpio_ref  7           

enum {
	BFW_NETX_GPIO_CNTR4_CTRL_run       = 1,  // [0]
	BFW_NETX_GPIO_CNTR4_CTRL_sym_nasym = 1,  // [1]
	BFW_NETX_GPIO_CNTR4_CTRL_once      = 1,  // [2]
	BFW_NETX_GPIO_CNTR4_CTRL_irq_en    = 1,  // [3]
	BFW_NETX_GPIO_CNTR4_CTRL_cnt_event = 1,  // [4]
	BFW_NETX_GPIO_CNTR4_CTRL_rst_en    = 1,  // [5]
	BFW_NETX_GPIO_CNTR4_CTRL_sel_event = 1,  // [6]
	BFW_NETX_GPIO_CNTR4_CTRL_gpio_ref  = 4,  // [10:7]
	BFW_NETX_GPIO_CNTR4_CTRL_reserved1 = 21  // [31:11]
};

typedef struct GPIO_COUNTER4_CTRL_BIT_Ttag {
	unsigned int run       : BFW_NETX_GPIO_CNTR4_CTRL_run;       // 1 .. start counter; 0 .. stop counter 
	unsigned int sym_nasym : BFW_NETX_GPIO_CNTR4_CTRL_sym_nasym; // 1 .. symmetric mode (triangle); 0 .. asymmetric mode (sawtooth) 
	unsigned int once      : BFW_NETX_GPIO_CNTR4_CTRL_once;      // 1 .. count once; 0 .. count continue 
	unsigned int irq_en    : BFW_NETX_GPIO_CNTR4_CTRL_irq_en;    // 1 .. enable interrupt request; 0 .. disable interrupt request 
	unsigned int cnt_event : BFW_NETX_GPIO_CNTR4_CTRL_cnt_event; // 1 .. count external event (edge, level); 0 .. count every clock cycle 
	unsigned int rst_en    : BFW_NETX_GPIO_CNTR4_CTRL_rst_en;    // 1 .. enable automatic reset; 0 .. disable automatic reset 
	unsigned int sel_event : BFW_NETX_GPIO_CNTR4_CTRL_sel_event; // select external event 
	                                                        // 0 .. (high) level
	                                                        // 1 .. (pos.) edge
	unsigned int gpio_ref  : BFW_NETX_GPIO_CNTR4_CTRL_gpio_ref;  // gpio reference (0 - 15) 
	unsigned int reserved1 : BFW_NETX_GPIO_CNTR4_CTRL_reserved1; // reserved
} GPIO_COUNTER4_CTRL_BIT_T;

typedef union {
	unsigned int             val;
	GPIO_COUNTER4_CTRL_BIT_T bf;
} GPIO_COUNTER4_CTRL_T;


// ---------------------------------------------------------------------
// Register gpio_counter0_max
// => GPIO counter0 max value
// => Mode: Mode (r/w)
// ---------------------------------------------------------------------

#define REL_NETX_GPIO_CNTR0_MAX 0x00000094U
#define NETX_GPIO_CNTR0_MAX     0x00100894U

#define MSK_NETX_GPIO_CNTR0_MAX_val 0xffffffffU // [31:0]
#define SRT_NETX_GPIO_CNTR0_MAX_val 0           

enum {
	BFW_NETX_GPIO_CNTR0_MAX_val = 32  // [31:0]
};

typedef struct GPIO_COUNTER0_MAX_BIT_Ttag {
	unsigned int val : BFW_NETX_GPIO_CNTR0_MAX_val; // max. counter value where the counter switches from upcounting to 
	                                                        // downcounting (symmetric mode) or jumps to zero (asymmetric mode)
} GPIO_COUNTER0_MAX_BIT_T;

typedef union {
	unsigned int            val;
	GPIO_COUNTER0_MAX_BIT_T bf;
} GPIO_COUNTER0_MAX_T;


// ---------------------------------------------------------------------
// Register gpio_counter1_max
// => GPIO counter1 max value
// => Mode: Mode (r/w)
// ---------------------------------------------------------------------

#define REL_NETX_GPIO_CNTR1_MAX 0x00000098U
#define NETX_GPIO_CNTR1_MAX     0x00100898U

#define MSK_NETX_GPIO_CNTR1_MAX_val 0xffffffffU // [31:0]
#define SRT_NETX_GPIO_CNTR1_MAX_val 0           

enum {
	BFW_NETX_GPIO_CNTR1_MAX_val = 32  // [31:0]
};

typedef struct GPIO_COUNTER1_MAX_BIT_Ttag {
	unsigned int val : BFW_NETX_GPIO_CNTR1_MAX_val; // max. counter value where the counter switches from upcounting to 
	                                                        // downcounting (symmetric mode) or jumps to zero (asymmetric mode)
} GPIO_COUNTER1_MAX_BIT_T;

typedef union {
	unsigned int            val;
	GPIO_COUNTER1_MAX_BIT_T bf;
} GPIO_COUNTER1_MAX_T;


// ---------------------------------------------------------------------
// Register gpio_counter2_max
// => GPIO counter2 max value
// => Mode: Mode (r/w)
// ---------------------------------------------------------------------

#define REL_NETX_GPIO_CNTR2_MAX 0x0000009CU
#define NETX_GPIO_CNTR2_MAX     0x0010089CU

#define MSK_NETX_GPIO_CNTR2_MAX_val 0xffffffffU // [31:0]
#define SRT_NETX_GPIO_CNTR2_MAX_val 0           

enum {
	BFW_NETX_GPIO_CNTR2_MAX_val = 32  // [31:0]
};

typedef struct GPIO_COUNTER2_MAX_BIT_Ttag {
	unsigned int val : BFW_NETX_GPIO_CNTR2_MAX_val; // max. counter value where the counter switches from upcounting to 
	                                                        // downcounting (symmetric mode) or jumps to zero (asymmetric mode)
} GPIO_COUNTER2_MAX_BIT_T;

typedef union {
	unsigned int            val;
	GPIO_COUNTER2_MAX_BIT_T bf;
} GPIO_COUNTER2_MAX_T;


// ---------------------------------------------------------------------
// Register gpio_counter3_max
// => GPIO counter3 max value
// => Mode: Mode (r/w)
// ---------------------------------------------------------------------

#define REL_NETX_GPIO_CNTR3_MAX 0x000000A0U
#define NETX_GPIO_CNTR3_MAX     0x001008A0U

#define MSK_NETX_GPIO_CNTR3_MAX_val 0xffffffffU // [31:0]
#define SRT_NETX_GPIO_CNTR3_MAX_val 0           

enum {
	BFW_NETX_GPIO_CNTR3_MAX_val = 32  // [31:0]
};

typedef struct GPIO_COUNTER3_MAX_BIT_Ttag {
	unsigned int val : BFW_NETX_GPIO_CNTR3_MAX_val; // max. counter value where the counter switches from upcounting to 
	                                                        // downcounting (symmetric mode) or jumps to zero (asymmetric mode)
} GPIO_COUNTER3_MAX_BIT_T;

typedef union {
	unsigned int            val;
	GPIO_COUNTER3_MAX_BIT_T bf;
} GPIO_COUNTER3_MAX_T;


// ---------------------------------------------------------------------
// Register gpio_counter4_max
// => GPIO counter4 max value
// => Mode: Mode (r/w)
// ---------------------------------------------------------------------

#define REL_NETX_GPIO_CNTR4_MAX 0x000000A4U
#define NETX_GPIO_CNTR4_MAX     0x001008A4U

#define MSK_NETX_GPIO_CNTR4_MAX_val 0xffffffffU // [31:0]
#define SRT_NETX_GPIO_CNTR4_MAX_val 0           

enum {
	BFW_NETX_GPIO_CNTR4_MAX_val = 32  // [31:0]
};

typedef struct GPIO_COUNTER4_MAX_BIT_Ttag {
	unsigned int val : BFW_NETX_GPIO_CNTR4_MAX_val; // max. counter value where the counter switches from upcounting to 
	                                                        // downcounting (symmetric mode) or jumps to zero (asymmetric mode)
} GPIO_COUNTER4_MAX_BIT_T;

typedef union {
	unsigned int            val;
	GPIO_COUNTER4_MAX_BIT_T bf;
} GPIO_COUNTER4_MAX_T;


// ---------------------------------------------------------------------
// Register gpio_counter0_cnt
// => GPIO counter0 current value
// => Mode: Mode (r/w)
// ---------------------------------------------------------------------

#define REL_NETX_GPIO_CNTR0_CNT 0x000000A8U
#define NETX_GPIO_CNTR0_CNT     0x001008A8U

#define MSK_NETX_GPIO_CNTR0_CNT_val 0xffffffffU // [31:0]
#define SRT_NETX_GPIO_CNTR0_CNT_val 0           

enum {
	BFW_NETX_GPIO_CNTR0_CNT_val = 32  // [31:0]
};

typedef struct GPIO_COUNTER0_CNT_BIT_Ttag {
	unsigned int val : BFW_NETX_GPIO_CNTR0_CNT_val; // curent counter value  
} GPIO_COUNTER0_CNT_BIT_T;

typedef union {
	unsigned int            val;
	GPIO_COUNTER0_CNT_BIT_T bf;
} GPIO_COUNTER0_CNT_T;


// ---------------------------------------------------------------------
// Register gpio_counter1_cnt
// => GPIO counter1 current value
// => Mode: Mode (r/w)
// ---------------------------------------------------------------------

#define REL_NETX_GPIO_CNTR1_CNT 0x000000ACU
#define NETX_GPIO_CNTR1_CNT     0x001008ACU

#define MSK_NETX_GPIO_CNTR1_CNT_val 0xffffffffU // [31:0]
#define SRT_NETX_GPIO_CNTR1_CNT_val 0           

enum {
	BFW_NETX_GPIO_CNTR1_CNT_val = 32  // [31:0]
};

typedef struct GPIO_COUNTER1_CNT_BIT_Ttag {
	unsigned int val : BFW_NETX_GPIO_CNTR1_CNT_val; // curent counter value  
} GPIO_COUNTER1_CNT_BIT_T;

typedef union {
	unsigned int            val;
	GPIO_COUNTER1_CNT_BIT_T bf;
} GPIO_COUNTER1_CNT_T;


// ---------------------------------------------------------------------
// Register gpio_counter2_cnt
// => GPIO counter2 current value
// => Mode: Mode (r/w)
// ---------------------------------------------------------------------

#define REL_NETX_GPIO_CNTR2_CNT 0x000000B0U
#define NETX_GPIO_CNTR2_CNT     0x001008B0U

#define MSK_NETX_GPIO_CNTR2_CNT_val 0xffffffffU // [31:0]
#define SRT_NETX_GPIO_CNTR2_CNT_val 0           

enum {
	BFW_NETX_GPIO_CNTR2_CNT_val = 32  // [31:0]
};

typedef struct GPIO_COUNTER2_CNT_BIT_Ttag {
	unsigned int val : BFW_NETX_GPIO_CNTR2_CNT_val; // curent counter value  
} GPIO_COUNTER2_CNT_BIT_T;

typedef union {
	unsigned int            val;
	GPIO_COUNTER2_CNT_BIT_T bf;
} GPIO_COUNTER2_CNT_T;


// ---------------------------------------------------------------------
// Register gpio_counter3_cnt
// => GPIO counter3 current value
// => Mode: Mode (r/w)
// ---------------------------------------------------------------------

#define REL_NETX_GPIO_CNTR3_CNT 0x000000B4U
#define NETX_GPIO_CNTR3_CNT     0x001008B4U

#define MSK_NETX_GPIO_CNTR3_CNT_val 0xffffffffU // [31:0]
#define SRT_NETX_GPIO_CNTR3_CNT_val 0           

enum {
	BFW_NETX_GPIO_CNTR3_CNT_val = 32  // [31:0]
};

typedef struct GPIO_COUNTER3_CNT_BIT_Ttag {
	unsigned int val : BFW_NETX_GPIO_CNTR3_CNT_val; // curent counter value  
} GPIO_COUNTER3_CNT_BIT_T;

typedef union {
	unsigned int            val;
	GPIO_COUNTER3_CNT_BIT_T bf;
} GPIO_COUNTER3_CNT_T;


// ---------------------------------------------------------------------
// Register gpio_counter4_cnt
// => GPIO counter4 current value
// => Mode: Mode (r/w)
// ---------------------------------------------------------------------

#define REL_NETX_GPIO_CNTR4_CNT 0x000000B8U
#define NETX_GPIO_CNTR4_CNT     0x001008B8U

#define MSK_NETX_GPIO_CNTR4_CNT_val 0xffffffffU // [31:0]
#define SRT_NETX_GPIO_CNTR4_CNT_val 0           

enum {
	BFW_NETX_GPIO_CNTR4_CNT_val = 32  // [31:0]
};

typedef struct GPIO_COUNTER4_CNT_BIT_Ttag {
	unsigned int val : BFW_NETX_GPIO_CNTR4_CNT_val; // curent counter value  
} GPIO_COUNTER4_CNT_BIT_T;

typedef union {
	unsigned int            val;
	GPIO_COUNTER4_CNT_BIT_T bf;
} GPIO_COUNTER4_CNT_T;


// ---------------------------------------------------------------------
// Register gpio_irq_mask_set
// => GPIO interrupt enable
// => Mode: Mode (r/w)
// ---------------------------------------------------------------------

#define REL_NETX_GPIO_IRQ_MSK_SET 0x000000BCU
#define NETX_GPIO_IRQ_MSK_SET     0x001008BCU

#define MSK_NETX_GPIO_IRQ_MSK_SET_gpio    0x0000ffffU // [15:0]
#define SRT_NETX_GPIO_IRQ_MSK_SET_gpio    0           
#define MSK_NETX_GPIO_IRQ_MSK_SET_cnt0    0x00010000U // [16]
#define SRT_NETX_GPIO_IRQ_MSK_SET_cnt0    16          
#define MSK_NETX_GPIO_IRQ_MSK_SET_cnt1    0x00020000U // [17]
#define SRT_NETX_GPIO_IRQ_MSK_SET_cnt1    17          
#define MSK_NETX_GPIO_IRQ_MSK_SET_cnt2    0x00040000U // [18]
#define SRT_NETX_GPIO_IRQ_MSK_SET_cnt2    18          
#define MSK_NETX_GPIO_IRQ_MSK_SET_cnt3    0x00080000U // [19]
#define SRT_NETX_GPIO_IRQ_MSK_SET_cnt3    19          
#define MSK_NETX_GPIO_IRQ_MSK_SET_cnt4    0x00100000U // [20]
#define SRT_NETX_GPIO_IRQ_MSK_SET_cnt4    20          
#define MSK_NETX_GPIO_IRQ_MSK_SET_systime 0x00200000U // [21]
#define SRT_NETX_GPIO_IRQ_MSK_SET_systime 21          

enum {
	BFW_NETX_GPIO_IRQ_MSK_SET_gpio      = 16, // [15:0]
	BFW_NETX_GPIO_IRQ_MSK_SET_cnt0      = 1,  // [16]
	BFW_NETX_GPIO_IRQ_MSK_SET_cnt1      = 1,  // [17]
	BFW_NETX_GPIO_IRQ_MSK_SET_cnt2      = 1,  // [18]
	BFW_NETX_GPIO_IRQ_MSK_SET_cnt3      = 1,  // [19]
	BFW_NETX_GPIO_IRQ_MSK_SET_cnt4      = 1,  // [20]
	BFW_NETX_GPIO_IRQ_MSK_SET_systime   = 1,  // [21]
	BFW_NETX_GPIO_IRQ_MSK_SET_reserved1 = 10  // [31:22]
};

typedef struct GPIO_IRQ_MASK_SET_BIT_Ttag {
	unsigned int gpio      : BFW_NETX_GPIO_IRQ_MSK_SET_gpio;      // enable interrupt request for every gpio 
	unsigned int cnt0      : BFW_NETX_GPIO_IRQ_MSK_SET_cnt0;      // enable interrupt request for counter0 
	unsigned int cnt1      : BFW_NETX_GPIO_IRQ_MSK_SET_cnt1;      // enable interrupt request for counter1 
	unsigned int cnt2      : BFW_NETX_GPIO_IRQ_MSK_SET_cnt2;      // enable interrupt request for counter2 
	unsigned int cnt3      : BFW_NETX_GPIO_IRQ_MSK_SET_cnt3;      // enable interrupt request for counter3 
	unsigned int cnt4      : BFW_NETX_GPIO_IRQ_MSK_SET_cnt4;      // enable interrupt request for counter4 
	unsigned int systime   : BFW_NETX_GPIO_IRQ_MSK_SET_systime;   // enable interrupt request if sys_time = gpio_systime_cmp 
	unsigned int reserved1 : BFW_NETX_GPIO_IRQ_MSK_SET_reserved1; // reserved
} GPIO_IRQ_MASK_SET_BIT_T;

typedef union {
	unsigned int            val;
	GPIO_IRQ_MASK_SET_BIT_T bf;
} GPIO_IRQ_MASK_SET_T;


// ---------------------------------------------------------------------
// Register gpio_irq_mask_rst
// => GPIO interrupt disable
// => Mode: Mode (cow)
// ---------------------------------------------------------------------

#define REL_NETX_GPIO_IRQ_MSK_RESET 0x000000C0U
#define NETX_GPIO_IRQ_MSK_RESET     0x001008C0U

#define MSK_NETX_GPIO_IRQ_MSK_RESET_gpio    0x0000ffffU // [15:0]
#define SRT_NETX_GPIO_IRQ_MSK_RESET_gpio    0           
#define MSK_NETX_GPIO_IRQ_MSK_RESET_cnt0    0x00010000U // [16]
#define SRT_NETX_GPIO_IRQ_MSK_RESET_cnt0    16          
#define MSK_NETX_GPIO_IRQ_MSK_RESET_cnt1    0x00020000U // [17]
#define SRT_NETX_GPIO_IRQ_MSK_RESET_cnt1    17          
#define MSK_NETX_GPIO_IRQ_MSK_RESET_cnt2    0x00040000U // [18]
#define SRT_NETX_GPIO_IRQ_MSK_RESET_cnt2    18          
#define MSK_NETX_GPIO_IRQ_MSK_RESET_cnt3    0x00080000U // [19]
#define SRT_NETX_GPIO_IRQ_MSK_RESET_cnt3    19          
#define MSK_NETX_GPIO_IRQ_MSK_RESET_cnt4    0x00100000U // [20]
#define SRT_NETX_GPIO_IRQ_MSK_RESET_cnt4    20          
#define MSK_NETX_GPIO_IRQ_MSK_RESET_systime 0x00200000U // [21]
#define SRT_NETX_GPIO_IRQ_MSK_RESET_systime 21          

enum {
	BFW_NETX_GPIO_IRQ_MSK_RESET_gpio      = 16, // [15:0]
	BFW_NETX_GPIO_IRQ_MSK_RESET_cnt0      = 1,  // [16]
	BFW_NETX_GPIO_IRQ_MSK_RESET_cnt1      = 1,  // [17]
	BFW_NETX_GPIO_IRQ_MSK_RESET_cnt2      = 1,  // [18]
	BFW_NETX_GPIO_IRQ_MSK_RESET_cnt3      = 1,  // [19]
	BFW_NETX_GPIO_IRQ_MSK_RESET_cnt4      = 1,  // [20]
	BFW_NETX_GPIO_IRQ_MSK_RESET_systime   = 1,  // [21]
	BFW_NETX_GPIO_IRQ_MSK_RESET_reserved1 = 10  // [31:22]
};

typedef struct GPIO_IRQ_MASK_RST_BIT_Ttag {
	unsigned int gpio      : BFW_NETX_GPIO_IRQ_MSK_RESET_gpio;      // write access with '1' disables interrupt request for corresponding gpio 
	unsigned int cnt0      : BFW_NETX_GPIO_IRQ_MSK_RESET_cnt0;      // write access with '1' disables interrupt request for counter0 
	unsigned int cnt1      : BFW_NETX_GPIO_IRQ_MSK_RESET_cnt1;      // write access with '1' disables interrupt request for counter1 
	unsigned int cnt2      : BFW_NETX_GPIO_IRQ_MSK_RESET_cnt2;      // write access with '1' disables interrupt request for counter2 
	unsigned int cnt3      : BFW_NETX_GPIO_IRQ_MSK_RESET_cnt3;      // write access with '1' disables interrupt request for counter3 
	unsigned int cnt4      : BFW_NETX_GPIO_IRQ_MSK_RESET_cnt4;      // write access with '1' disables interrupt request for counter4 
	unsigned int systime   : BFW_NETX_GPIO_IRQ_MSK_RESET_systime;   // write access with '1' disables interrupt request for sys_time 
	unsigned int reserved1 : BFW_NETX_GPIO_IRQ_MSK_RESET_reserved1; // reserved
} GPIO_IRQ_MASK_RST_BIT_T;

typedef union {
	unsigned int            val;
	GPIO_IRQ_MASK_RST_BIT_T bf;
} GPIO_IRQ_MASK_RST_T;


// ---------------------------------------------------------------------
// Register gpio_systime_cmp
// => GPIO sys_time compare value
//    compares this value with systime_ns considering incontinous behaviour of systime_ns
// => Mode: Mode (r/w)
// ---------------------------------------------------------------------

#define REL_NETX_GPIO_SYSTIME_NS_CMP 0x000000C4U
#define NETX_GPIO_SYSTIME_NS_CMP     0x001008C4U

#define MSK_NETX_GPIO_SYSTIME_NS_CMP_val 0xffffffffU // [31:0]
#define SRT_NETX_GPIO_SYSTIME_NS_CMP_val 0           

enum {
	BFW_NETX_GPIO_SYSTIME_NS_CMP_val = 32  // [31:0]
};

typedef struct GPIO_SYSTIME_CMP_BIT_Ttag {
	unsigned int val : BFW_NETX_GPIO_SYSTIME_NS_CMP_val; // compare value for systime  
} GPIO_SYSTIME_CMP_BIT_T;

typedef union {
	unsigned int           val;
	GPIO_SYSTIME_CMP_BIT_T bf;
} GPIO_SYSTIME_CMP_T;


// ---------------------------------------------------------------------
// Register gpio_line
// => GPIO line register
// => Mode: Mode (r/w)
// ---------------------------------------------------------------------

#define REL_NETX_GPIO_OUT 0x000000C8U
#define NETX_GPIO_OUT     0x001008C8U

#define MSK_NETX_GPIO_OUT_val 0x0000ffffU // [15:0]
#define SRT_NETX_GPIO_OUT_val 0           

enum {
	BFW_NETX_GPIO_OUT_val       = 16, // [15:0]
	BFW_NETX_GPIO_OUT_reserved1 = 16  // [31:16]
};

typedef struct GPIO_LINE_BIT_Ttag {
	unsigned int val       : BFW_NETX_GPIO_OUT_val;       // gpio output values 
	unsigned int reserved1 : BFW_NETX_GPIO_OUT_reserved1; // reserved
} GPIO_LINE_BIT_T;

typedef union {
	unsigned int    val;
	GPIO_LINE_BIT_T bf;
} GPIO_LINE_T;


// ---------------------------------------------------------------------
// Register gpio_irq
// => GPIO irq register
// => Mode: Mode (r/w)
// ---------------------------------------------------------------------

#define REL_NETX_GPIO_IRQ 0x000000D0U
#define NETX_GPIO_IRQ     0x001008D0U

#define MSK_NETX_GPIO_IRQ_gpio     0x0000ffffU // [15:0]
#define SRT_NETX_GPIO_IRQ_gpio     0           
#define MSK_NETX_GPIO_IRQ_cnt0     0x00010000U // [16]
#define SRT_NETX_GPIO_IRQ_cnt0     16          
#define MSK_NETX_GPIO_IRQ_cnt1     0x00020000U // [17]
#define SRT_NETX_GPIO_IRQ_cnt1     17          
#define MSK_NETX_GPIO_IRQ_cnt2     0x00040000U // [18]
#define SRT_NETX_GPIO_IRQ_cnt2     18          
#define MSK_NETX_GPIO_IRQ_cnt3     0x00080000U // [19]
#define SRT_NETX_GPIO_IRQ_cnt3     19          
#define MSK_NETX_GPIO_IRQ_cnt4     0x00100000U // [20]
#define SRT_NETX_GPIO_IRQ_cnt4     20          
#define MSK_NETX_GPIO_IRQ_sys_time 0x00200000U // [21]
#define SRT_NETX_GPIO_IRQ_sys_time 21          

enum {
	BFW_NETX_GPIO_IRQ_gpio      = 16, // [15:0]
	BFW_NETX_GPIO_IRQ_cnt0      = 1,  // [16]
	BFW_NETX_GPIO_IRQ_cnt1      = 1,  // [17]
	BFW_NETX_GPIO_IRQ_cnt2      = 1,  // [18]
	BFW_NETX_GPIO_IRQ_cnt3      = 1,  // [19]
	BFW_NETX_GPIO_IRQ_cnt4      = 1,  // [20]
	BFW_NETX_GPIO_IRQ_sys_time  = 1,  // [21]
	BFW_NETX_GPIO_IRQ_reserved1 = 10  // [31:22]
};

typedef struct GPIO_IRQ_BIT_Ttag {
	unsigned int gpio      : BFW_NETX_GPIO_IRQ_gpio;      // holds the interrupt bits for every GPIO 
	                                                        // write access with '1' resets the appropriate irq
	unsigned int cnt0      : BFW_NETX_GPIO_IRQ_cnt0;      // hold the interrupt bit for counter0 
	unsigned int cnt1      : BFW_NETX_GPIO_IRQ_cnt1;      // hold the interrupt bit for counter1 
	unsigned int cnt2      : BFW_NETX_GPIO_IRQ_cnt2;      // hold the interrupt bit for counter2 
	unsigned int cnt3      : BFW_NETX_GPIO_IRQ_cnt3;      // hold the interrupt bit for counter3 
	unsigned int cnt4      : BFW_NETX_GPIO_IRQ_cnt4;      // hold the interrupt bit for counter4 
	unsigned int sys_time  : BFW_NETX_GPIO_IRQ_sys_time;  // hold the interrupt bit for sys_time 
	unsigned int reserved1 : BFW_NETX_GPIO_IRQ_reserved1; // reserved
} GPIO_IRQ_BIT_T;

typedef union {
	unsigned int   val;
	GPIO_IRQ_BIT_T bf;
} GPIO_IRQ_T;


// ---------------------------------------------------------------------
// Register gpio_in
// => GPIO latched register
// => Mode: Mode (r)
// ---------------------------------------------------------------------

#define REL_NETX_GPIO_IN 0x000000CCU
#define NETX_GPIO_IN     0x001008CCU

#define MSK_NETX_GPIO_IN 0x0000ffffU // [15:0]
#define SRT_NETX_GPIO_IN 0           

enum {
	BFW_NETX_GPIO_IN_val       = 16, // [15:0]
	BFW_NETX_GPIO_IN_reserved1 = 16  // [31:16]
};

typedef struct GPIO_IN_BIT_Ttag {
	unsigned int val       : BFW_NETX_GPIO_IN_val;       // gpio input values 
	unsigned int reserved1 : BFW_NETX_GPIO_IN_reserved1; // reserved
} GPIO_IN_BIT_T;

typedef union {
	unsigned int  val;
	GPIO_IN_BIT_T bf;
} GPIO_IN_T;


/*************************************************************************************/

#endif /* _GPIO_H */
