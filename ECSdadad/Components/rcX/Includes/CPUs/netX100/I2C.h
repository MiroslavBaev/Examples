/******************************************************************************

  Copyright (C) 2010 [Hilscher Gesellschaft für Systemautomation mbH]

  This program can be used by everyone according to the netX Open Source
  Software license. The license agreement can be downloaded from
  http://www.industrialNETworX.com

*******************************************************************************

  Last Modification:
    @version $Id: I2C.h 333 2010-04-26 09:32:25Z Volker $

  Description:
    netX I2C definitions

  Changes:
    Date        Author        Description
  ---------------------------------------------------------------------------
    2010-03-24  NC            File created.

******************************************************************************/


#ifndef _I2C_H
#define _I2C_H


/*************************************************************************************/


// =====================================================================
//
// Area of i2c
//
// =====================================================================

#define NETX_I2C_AREA	0x00100D00U


// ---------------------------------------------------------------------
// Register i2c_ctrl
// => I2C Control Register
// => Mode: Mode (r/w)
// ---------------------------------------------------------------------

#define REL_NETX_I2C_CTRL 0x00000000U
#define NETX_I2C_CTRL     0x00100D00U

#define MSK_NETX_I2C_CTRL_ENABLE 0x00000001U // [0]
#define SRT_NETX_I2C_CTRL_ENABLE 0           
#define MSK_NETX_I2C_CTRL_SPEED  0x0000000eU // [3:1]
#define SRT_NETX_I2C_CTRL_SPEED  1           
#define MSK_NETX_I2C_CTRL_ID     0x000007f0U // [10:4]
#define SRT_NETX_I2C_CTRL_ID     4           

enum {
	BFW_NETX_I2C_CTRL_ENABLE    = 1,  // [0]
	BFW_NETX_I2C_CTRL_SPEED     = 3,  // [3:1]
	BFW_NETX_I2C_CTRL_ID        = 7,  // [10:4]
	BFW_NETX_I2C_CTRL_reserved1 = 21  // [31:11]
};

typedef struct I2C_CTRL_BIT_Ttag {
	unsigned int ENABLE    : BFW_NETX_I2C_CTRL_ENABLE;    // 0: interface disable          
	                                                        // 1: interface enable
	unsigned int SPEED     : BFW_NETX_I2C_CTRL_SPEED;     // speed select                  
	                                                        // when 100 MHz system clock:
	                                                        // 000 -   25 kHz
	                                                        // 001 -   50 kHz
	                                                        // 010 -  100 kHz (normal mode)
	                                                        // 011 -  200 kHz
	                                                        // 100 -  400 kHz (fast mode)
	                                                        // 101 -  600 kHz
	                                                        // 110 -  800 kHz
	                                                        // 111 - 1000 kHz
	unsigned int ID        : BFW_NETX_I2C_CTRL_ID;        // slave device id               
	unsigned int reserved1 : BFW_NETX_I2C_CTRL_reserved1; // reserved
} I2C_CTRL_BIT_T;

typedef union {
	unsigned int   val;
	I2C_CTRL_BIT_T bf;
} I2C_CTRL_T;


// ---------------------------------------------------------------------
// Register i2c_data
// => I2c data register
// => Mode: Mode (r/w)
// ---------------------------------------------------------------------

#define REL_NETX_I2C_DATA 0x00000004U
#define NETX_I2C_DATA     0x00100D04U

#define MSK_NETX_I2C_DATA_DATA 0x000000ffU // [7:0]
#define SRT_NETX_I2C_DATA_DATA 0           
#define MSK_NETX_I2C_DATA_CMD0 0x00000100U // [8]
#define SRT_NETX_I2C_DATA_CMD0 8           
#define MSK_NETX_I2C_DATA_CMD1 0x00000200U // [9]
#define SRT_NETX_I2C_DATA_CMD1 9           
#define MSK_NETX_I2C_DATA_CMD2 0x00000400U // [10]
#define SRT_NETX_I2C_DATA_CMD2 10          
#define MSK_NETX_I2C_DATA_CMD3 0x00000800U // [11]
#define SRT_NETX_I2C_DATA_CMD3 11          
#define MSK_NETX_I2C_DATA_RDF  0x00001000U // [12]
#define SRT_NETX_I2C_DATA_RDF  12          
#define MSK_NETX_I2C_DATA_ACK  0x00006000U // [14:13]
#define SRT_NETX_I2C_DATA_ACK  13          

enum {
	BFW_NETX_I2C_DATA_DATA      = 8,  // [7:0]
	BFW_NETX_I2C_DATA_CMD0      = 1,  // [8]
	BFW_NETX_I2C_DATA_CMD1      = 1,  // [9]
	BFW_NETX_I2C_DATA_CMD2      = 1,  // [10]
	BFW_NETX_I2C_DATA_CMD3      = 1,  // [11]
	BFW_NETX_I2C_DATA_RDF       = 1,  // [12]
	BFW_NETX_I2C_DATA_ACK       = 2,  // [14:13]
	BFW_NETX_I2C_DATA_reserved1 = 17  // [31:15]
};

typedef struct I2C_DATA_BIT_Ttag {
	unsigned int DATA      : BFW_NETX_I2C_DATA_DATA;      // transmit and receive data byte
	unsigned int CMD0      : BFW_NETX_I2C_DATA_CMD0;      // Command Bit 0: stop
	                                                        //  0 : nothing
	                                                        //  1 : send Stop Condition
	unsigned int CMD1      : BFW_NETX_I2C_DATA_CMD1;      // Command Bit 1: readwrite
	                                                        //  0 : write Byte
	                                                        //  1 : read Byte
	unsigned int CMD2      : BFW_NETX_I2C_DATA_CMD2;      // Command Bit 2: start
	                                                        //  0 : nothing
	                                                        //  1 : send Start Condition + ID
	unsigned int CMD3      : BFW_NETX_I2C_DATA_CMD3;      // Command Bit 3: execute
	                                                        //  0 : no operation, ready, next command can be programmed by CPU
	                                                        //  1 : execute command, interface busy
	unsigned int RDF       : BFW_NETX_I2C_DATA_RDF;       // 1: Read Data Finished:
	                                                        // reading data word from slave is finished
	unsigned int ACK       : BFW_NETX_I2C_DATA_ACK;       // Number of acknowledge bits sended by slave in actual command.
	                                                        // Allows software to detect abnormalities of slaves.
	unsigned int reserved1 : BFW_NETX_I2C_DATA_reserved1; // reserved
} I2C_DATA_BIT_T;

typedef union {
	unsigned int   val;
	I2C_DATA_BIT_T bf;
} I2C_DATA_T;


/*************************************************************************************/

#endif /* _I2C_H */
