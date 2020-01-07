/******************************************************************************

  Copyright (C) 2010 [Hilscher Gesellschaft für Systemautomation mbH]

  This program can be used by everyone according to the netX Open Source
  Software license. The license agreement can be downloaded from
  http://www.industrialNETworX.com

*******************************************************************************

  Last Modification:
    @version $Id: SPI.h 333 2010-04-26 09:32:25Z Volker $

  Description:
    netX SPI definitions

  Changes:
    Date        Author        Description
  ---------------------------------------------------------------------------
    2010-03-24  NC            File created.

******************************************************************************/


#ifndef _SPI_H
#define _SPI_H


/*************************************************************************************/


// =====================================================================
//
// Area of spi
//
// =====================================================================

#define NETX_SPI_AREA	0x00100C00U


// ---------------------------------------------------------------------
// Register spi_data_register
// => spi data register (DR)
//    2 data bytes with valid bits
// => Mode: Mode (r/w)
// ---------------------------------------------------------------------

#define REL_NETX_SPI_DATA 0x00000000U
#define NETX_SPI_DATA     0x00100C00U

#define MSK_NETX_SPI_DATA_data_byte_0 0x000000ffU // [7:0]
#define SRT_NETX_SPI_DATA_data_byte_0 0           
#define MSK_NETX_SPI_DATA_data_byte_1 0x0000ff00U // [15:8]
#define SRT_NETX_SPI_DATA_data_byte_1 8           
#define MSK_NETX_SPI_DATA_dr_valid0   0x00010000U // [16]
#define SRT_NETX_SPI_DATA_dr_valid0   16          
#define MSK_NETX_SPI_DATA_dr_valid1   0x00020000U // [17]
#define SRT_NETX_SPI_DATA_dr_valid1   17          

enum {
	BFW_NETX_SPI_DATA_data_byte_0 = 8,  // [7:0]
	BFW_NETX_SPI_DATA_data_byte_1 = 8,  // [15:8]
	BFW_NETX_SPI_DATA_dr_valid0   = 1,  // [16]
	BFW_NETX_SPI_DATA_dr_valid1   = 1,  // [17]
	BFW_NETX_SPI_DATA_reserved1   = 14  // [31:18]
};

typedef struct SPI_DATA_REGISTER_BIT_Ttag {
	unsigned int data_byte_0 : BFW_NETX_SPI_DATA_data_byte_0; // data byte                 
	unsigned int data_byte_1 : BFW_NETX_SPI_DATA_data_byte_1; // data byte                 
	unsigned int dr_valid0   : BFW_NETX_SPI_DATA_dr_valid0;   // valid bit for data_byte_0 
	unsigned int dr_valid1   : BFW_NETX_SPI_DATA_dr_valid1;   // valid bit for data_byte_1 
	unsigned int reserved1   : BFW_NETX_SPI_DATA_reserved1;   // reserved
} SPI_DATA_REGISTER_BIT_T;

typedef union {
	unsigned int            val;
	SPI_DATA_REGISTER_BIT_T bf;
} SPI_DATA_REGISTER_T;


// ---------------------------------------------------------------------
// Register spi_status_register
// => spi status register (SR):
//    Shows the actual status of the spi interface.
//    Bits 24..18 show occured interrupts,
//    writing ones into these bits deletes the interrupts.
//    Writing into other bits has no effect
// => Mode: Mode (r/w)
// ---------------------------------------------------------------------

#define REL_NETX_SPI_STAT 0x00000004U
#define NETX_SPI_STAT     0x00100C04U

#define MSK_NETX_SPI_STAT_SR_in_fuel_val  0x000001ffU // [8:0]
#define SRT_NETX_SPI_STAT_SR_in_fuel_val  0           
#define MSK_NETX_SPI_STAT_SR_out_fuel_val 0x0003fe00U // [17:9]
#define SRT_NETX_SPI_STAT_SR_out_fuel_val 9           
#define MSK_NETX_SPI_STAT_SR_in_fuel      0x00040000U // [18]
#define SRT_NETX_SPI_STAT_SR_in_fuel      18          
#define MSK_NETX_SPI_STAT_SR_in_recdata   0x00080000U // [19]
#define SRT_NETX_SPI_STAT_SR_in_recdata   19          
#define MSK_NETX_SPI_STAT_SR_in_full      0x00100000U // [20]
#define SRT_NETX_SPI_STAT_SR_in_full      20          
#define MSK_NETX_SPI_STAT_SR_out_fuel     0x00200000U // [21]
#define SRT_NETX_SPI_STAT_SR_out_fuel     21          
#define MSK_NETX_SPI_STAT_SR_out_fw       0x00400000U // [22]
#define SRT_NETX_SPI_STAT_SR_out_fw       22          
#define MSK_NETX_SPI_STAT_SR_out_empty    0x00800000U // [23]
#define SRT_NETX_SPI_STAT_SR_out_empty    23          
#define MSK_NETX_SPI_STAT_SR_out_full     0x01000000U // [24]
#define SRT_NETX_SPI_STAT_SR_out_full     24          
#define MSK_NETX_SPI_STAT_SR_selected     0x02000000U // [25]
#define SRT_NETX_SPI_STAT_SR_selected     25          

enum {
	BFW_NETX_SPI_STAT_SR_in_fuel_val  = 9, // [8:0]
	BFW_NETX_SPI_STAT_SR_out_fuel_val = 9, // [17:9]
	BFW_NETX_SPI_STAT_SR_in_fuel      = 1, // [18]
	BFW_NETX_SPI_STAT_SR_in_recdata   = 1, // [19]
	BFW_NETX_SPI_STAT_SR_in_full      = 1, // [20]
	BFW_NETX_SPI_STAT_SR_out_fuel     = 1, // [21]
	BFW_NETX_SPI_STAT_SR_out_fw       = 1, // [22]
	BFW_NETX_SPI_STAT_SR_out_empty    = 1, // [23]
	BFW_NETX_SPI_STAT_SR_out_full     = 1, // [24]
	BFW_NETX_SPI_STAT_SR_selected     = 1, // [25]
	BFW_NETX_SPI_STAT_reserved1       = 6  // [31:26]
};

typedef struct SPI_STATUS_REGISTER_BIT_Ttag {
	unsigned int SR_in_fuel_val  : BFW_NETX_SPI_STAT_SR_in_fuel_val;  // input FIFO fuel (number of bytes)                
	unsigned int SR_out_fuel_val : BFW_NETX_SPI_STAT_SR_out_fuel_val; // output FIFO fuel (number of bytes)               
	unsigned int SR_in_fuel      : BFW_NETX_SPI_STAT_SR_in_fuel;      // adjustable fuel value of input FIFO reached      
	unsigned int SR_in_recdata   : BFW_NETX_SPI_STAT_SR_in_recdata;   // valid data bytes in input FIFO                   
	unsigned int SR_in_full      : BFW_NETX_SPI_STAT_SR_in_full;      // input FIFO is full                               
	unsigned int SR_out_fuel     : BFW_NETX_SPI_STAT_SR_out_fuel;     // adjustable fuel value of output FIFO reached     
	unsigned int SR_out_fw       : BFW_NETX_SPI_STAT_SR_out_fw;       // ARM is writing data to fast into output FIFO     
	unsigned int SR_out_empty    : BFW_NETX_SPI_STAT_SR_out_empty;    // output FIFO is empty and interface sending data  
	                                                        // (occures only in slave mode)
	unsigned int SR_out_full     : BFW_NETX_SPI_STAT_SR_out_full;     // output FIFO is full                              
	unsigned int SR_selected     : BFW_NETX_SPI_STAT_SR_selected;     // external master has access to spi-interface      
	unsigned int reserved1       : BFW_NETX_SPI_STAT_reserved1;       // reserved
} SPI_STATUS_REGISTER_BIT_T;

typedef union {
	unsigned int              val;
	SPI_STATUS_REGISTER_BIT_T bf;
} SPI_STATUS_REGISTER_T;


// ---------------------------------------------------------------------
// Register spi_control_register
// => spi control register (CR)
// => Mode: Mode (r/w)
// ---------------------------------------------------------------------

#define REL_NETX_SPI_CTRL 0x00000008U
#define NETX_SPI_CTRL     0x00100C08U

#define MSK_NETX_SPI_CTRL_CR_softreset   0x00000001U // [0]
#define SRT_NETX_SPI_CTRL_CR_softreset   0           
#define MSK_NETX_SPI_CTRL_CR_speed       0x0000001eU // [4:1]
#define SRT_NETX_SPI_CTRL_CR_speed       1           
#define MSK_NETX_SPI_CTRL_CR_read        0x00000040U // [6]
#define SRT_NETX_SPI_CTRL_CR_read        6           
#define MSK_NETX_SPI_CTRL_CR_write       0x00000080U // [7]
#define SRT_NETX_SPI_CTRL_CR_write       7           
#define MSK_NETX_SPI_CTRL_CR_ss          0x00000700U // [10:8]
#define SRT_NETX_SPI_CTRL_CR_ss          8           
#define MSK_NETX_SPI_CTRL_CR_clr_infifo  0x00100000U // [20]
#define SRT_NETX_SPI_CTRL_CR_clr_infifo  20          
#define MSK_NETX_SPI_CTRL_CR_clr_outfifo 0x00200000U // [21]
#define SRT_NETX_SPI_CTRL_CR_clr_outfifo 21          
#define MSK_NETX_SPI_CTRL_CR_burstdelay  0x01c00000U // [24:22]
#define SRT_NETX_SPI_CTRL_CR_burstdelay  22          
#define MSK_NETX_SPI_CTRL_CR_burst       0x0e000000U // [27:25]
#define SRT_NETX_SPI_CTRL_CR_burst       25          
#define MSK_NETX_SPI_CTRL_CR_ncpha       0x10000000U // [28]
#define SRT_NETX_SPI_CTRL_CR_ncpha       28          
#define MSK_NETX_SPI_CTRL_CR_cpol        0x20000000U // [29]
#define SRT_NETX_SPI_CTRL_CR_cpol        29          
#define MSK_NETX_SPI_CTRL_CR_ms          0x40000000U // [30]
#define SRT_NETX_SPI_CTRL_CR_ms          30          
#define MSK_NETX_SPI_CTRL_CR_en          0x80000000U // [31]
#define SRT_NETX_SPI_CTRL_CR_en          31          

enum {
	BFW_NETX_SPI_CTRL_CR_softreset   = 1, // [0]
	BFW_NETX_SPI_CTRL_CR_speed       = 4, // [4:1]
	BFW_NETX_SPI_CTRL_reserved1      = 1, // [5]
	BFW_NETX_SPI_CTRL_CR_read        = 1, // [6]
	BFW_NETX_SPI_CTRL_CR_write       = 1, // [7]
	BFW_NETX_SPI_CTRL_CR_ss          = 3, // [10:8]
	BFW_NETX_SPI_CTRL_reserved2      = 9, // [19:11]
	BFW_NETX_SPI_CTRL_CR_clr_infifo  = 1, // [20]
	BFW_NETX_SPI_CTRL_CR_clr_outfifo = 1, // [21]
	BFW_NETX_SPI_CTRL_CR_burstdelay  = 3, // [24:22]
	BFW_NETX_SPI_CTRL_CR_burst       = 3, // [27:25]
	BFW_NETX_SPI_CTRL_CR_ncpha       = 1, // [28]
	BFW_NETX_SPI_CTRL_CR_cpol        = 1, // [29]
	BFW_NETX_SPI_CTRL_CR_ms          = 1, // [30]
	BFW_NETX_SPI_CTRL_CR_en          = 1  // [31]
};

typedef struct SPI_CONTROL_REGISTER_BIT_Ttag {
	unsigned int CR_softreset   : BFW_NETX_SPI_CTRL_CR_softreset;   // TBD                                             
	unsigned int CR_speed       : BFW_NETX_SPI_CTRL_CR_speed;       // clock devider for SPI clock (2 - 2^16)          
	unsigned int reserved1      : BFW_NETX_SPI_CTRL_reserved1;      // reserved
	unsigned int CR_read        : BFW_NETX_SPI_CTRL_CR_read;        // 1:spi interface read data                       
	unsigned int CR_write       : BFW_NETX_SPI_CTRL_CR_write;       // 1:spi interface write data                      
	unsigned int CR_ss          : BFW_NETX_SPI_CTRL_CR_ss;          // external slave select                           
	unsigned int reserved2      : BFW_NETX_SPI_CTRL_reserved2;      // reserved
	unsigned int CR_clr_infifo  : BFW_NETX_SPI_CTRL_CR_clr_infifo;  // clear input FIFO                                
	unsigned int CR_clr_outfifo : BFW_NETX_SPI_CTRL_CR_clr_outfifo; // clear output FIFO                               
	unsigned int CR_burstdelay  : BFW_NETX_SPI_CTRL_CR_burstdelay;  // delay between transmittion of 2 data bytes      
	                                                        // (0 to 7 SCK cycles)
	unsigned int CR_burst       : BFW_NETX_SPI_CTRL_CR_burst;       // burst lenght = 2^CR_burst                       
	unsigned int CR_ncpha       : BFW_NETX_SPI_CTRL_CR_ncpha;       // relativ to CR_cpol                              
	                                                        // 1:change data to primary spi_sck edge
	                                                        //   data are activ to secondary spi_sck edge
	                                                        // 1:change data to secondary spi_sck edge
	                                                        //   data are activ to primary spi_sck edge
	unsigned int CR_cpol        : BFW_NETX_SPI_CTRL_CR_cpol;        // 1:falling edge of spi_sck is primary
	                                                        // 0:rising edge of spi_sck is primary
	unsigned int CR_ms          : BFW_NETX_SPI_CTRL_CR_ms;          // 1:master mode 0:slave mode                      
	unsigned int CR_en          : BFW_NETX_SPI_CTRL_CR_en;          // 1:enable 0:disable spi interface                
} SPI_CONTROL_REGISTER_BIT_T;

typedef union {
	unsigned int               val;
	SPI_CONTROL_REGISTER_BIT_T bf;
} SPI_CONTROL_REGISTER_T;


// ---------------------------------------------------------------------
// Register spi_interrupt_control_register
// => spi interrupt control register (IR)
// => Mode: Mode (r/w)
// ---------------------------------------------------------------------

#define REL_NETX_SPI_INT_CTRL 0x0000000CU
#define NETX_SPI_INT_CTRL     0x00100C0CU

#define MSK_NETX_SPI_INT_CTRL_IR_in_fuel       0x000001ffU // [8:0]
#define SRT_NETX_SPI_INT_CTRL_IR_in_fuel       0           
#define MSK_NETX_SPI_INT_CTRL_IR_out_fuel      0x0003fe00U // [17:9]
#define SRT_NETX_SPI_INT_CTRL_IR_out_fuel      9           
#define MSK_NETX_SPI_INT_CTRL_IR_in_fuel_en    0x00040000U // [18]
#define SRT_NETX_SPI_INT_CTRL_IR_in_fuel_en    18          
#define MSK_NETX_SPI_INT_CTRL_IR_in_recdata_en 0x00080000U // [19]
#define SRT_NETX_SPI_INT_CTRL_IR_in_recdata_en 19          
#define MSK_NETX_SPI_INT_CTRL_IR_in_full_en    0x00100000U // [20]
#define SRT_NETX_SPI_INT_CTRL_IR_in_full_en    20          
#define MSK_NETX_SPI_INT_CTRL_IR_out_fuel_en   0x00200000U // [21]
#define SRT_NETX_SPI_INT_CTRL_IR_out_fuel_en   21          
#define MSK_NETX_SPI_INT_CTRL_IR_out_fw_en     0x00400000U // [22]
#define SRT_NETX_SPI_INT_CTRL_IR_out_fw_en     22          
#define MSK_NETX_SPI_INT_CTRL_IR_out_empty_en  0x00800000U // [23]
#define SRT_NETX_SPI_INT_CTRL_IR_out_empty_en  23          
#define MSK_NETX_SPI_INT_CTRL_IR_out_full_en   0x01000000U // [24]
#define SRT_NETX_SPI_INT_CTRL_IR_out_full_en   24          

enum {
	BFW_NETX_SPI_INT_CTRL_IR_in_fuel       = 9, // [8:0]
	BFW_NETX_SPI_INT_CTRL_IR_out_fuel      = 9, // [17:9]
	BFW_NETX_SPI_INT_CTRL_IR_in_fuel_en    = 1, // [18]
	BFW_NETX_SPI_INT_CTRL_IR_in_recdata_en = 1, // [19]
	BFW_NETX_SPI_INT_CTRL_IR_in_full_en    = 1, // [20]
	BFW_NETX_SPI_INT_CTRL_IR_out_fuel_en   = 1, // [21]
	BFW_NETX_SPI_INT_CTRL_IR_out_fw_en     = 1, // [22]
	BFW_NETX_SPI_INT_CTRL_IR_out_empty_en  = 1, // [23]
	BFW_NETX_SPI_INT_CTRL_IR_out_full_en   = 1, // [24]
	BFW_NETX_SPI_INT_CTRL_reserved1        = 7  // [31:25]
};

typedef struct SPI_INTERRUPT_CONTROL_REGISTER_BIT_Ttag {
	unsigned int IR_in_fuel       : BFW_NETX_SPI_INT_CTRL_IR_in_fuel;       // adjustable fuel value of input FIFO           
	unsigned int IR_out_fuel      : BFW_NETX_SPI_INT_CTRL_IR_out_fuel;      // adjustable fuel value of output FIFO          
	unsigned int IR_in_fuel_en    : BFW_NETX_SPI_INT_CTRL_IR_in_fuel_en;    // IRQ enable for irq_spi(0)		             
	unsigned int IR_in_recdata_en : BFW_NETX_SPI_INT_CTRL_IR_in_recdata_en; // IRQ enable for irq_spi(1)		             
	unsigned int IR_in_full_en    : BFW_NETX_SPI_INT_CTRL_IR_in_full_en;    // IRQ enable for irq_spi(2)		             
	unsigned int IR_out_fuel_en   : BFW_NETX_SPI_INT_CTRL_IR_out_fuel_en;   // IRQ enable for irq_spi(3)		             
	unsigned int IR_out_fw_en     : BFW_NETX_SPI_INT_CTRL_IR_out_fw_en;     // IRQ enable for irq_spi(4)		             
	unsigned int IR_out_empty_en  : BFW_NETX_SPI_INT_CTRL_IR_out_empty_en;  // IRQ enable for irq_spi(5)		             
	unsigned int IR_out_full_en   : BFW_NETX_SPI_INT_CTRL_IR_out_full_en;   // IRQ enable for irq_spi(6)		             
	unsigned int reserved1        : BFW_NETX_SPI_INT_CTRL_reserved1;        // reserved
} SPI_INTERRUPT_CONTROL_REGISTER_BIT_T;

typedef union {
	unsigned int                         val;
	SPI_INTERRUPT_CONTROL_REGISTER_BIT_T bf;
} SPI_INTERRUPT_CONTROL_REGISTER_T;


/*************************************************************************************/

#endif /* _SPI_H */
