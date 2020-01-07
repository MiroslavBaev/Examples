/******************************************************************************

  Copyright (C) 2010 [Hilscher Gesellschaft für Systemautomation mbH]

  This program can be used by everyone according to the netX Open Source
  Software license. The license agreement can be downloaded from
  http://www.industrialNETworX.com

*******************************************************************************

  Last Modification:
    @version $Id: UART.h 333 2010-04-26 09:32:25Z Volker $

  Description:
    netX UART definitions

  Changes:
    Date        Author        Description
  ---------------------------------------------------------------------------
    2010-03-24  NC            File created.

******************************************************************************/


#ifndef _UART_H
#define _UART_H


/*************************************************************************************/


// =====================================================================
//
// Area of uart0, uart1, uart2
//
// =====================================================================

#define NETX_UART0_AREA	0x00100A00U
#define NETX_UART1_AREA	0x00100A40U
#define NETX_UART2_AREA	0x00100A80U


// ---------------------------------------------------------------------
// Register uartdr
// => data read or written from the interface
// => Mode: Mode (r/w)
// ---------------------------------------------------------------------

#define REL_NETX_UART_DATA   0x00000000U
#define NETX_UART0_DATA 0x00100A00U
#define NETX_UART1_DATA 0x00100A40U
#define NETX_UART2_DATA 0x00100A80U

#define MSK_NETX_UART_DATA_DATA 0x000000ffU // [7:0]
#define SRT_NETX_UART_DATA_DATA 0           

enum {
	BFW_NETX_UART_DATA_DATA      = 8,  // [7:0]
	BFW_NETX_UART_DATA_reserved1 = 24  // [31:8]
};

typedef struct UARTDR_BIT_Ttag {
	unsigned int DATA      : BFW_NETX_UART_DATA_DATA;      // data read or written from the interface 
	unsigned int reserved1 : BFW_NETX_UART_DATA_reserved1; // reserved
} UARTDR_BIT_T;

typedef union {
	unsigned int val;
	UARTDR_BIT_T bf;
} UARTDR_T;


// ---------------------------------------------------------------------
// Register uartrsr
// => receive status register (read) / Error Clear Register (write)
// => Mode: Mode (r/w)
// ---------------------------------------------------------------------

#define REL_NETX_UART_STAT   0x00000004U
#define NETX_UART0_STAT 0x00100A04U
#define NETX_UART1_STAT 0x00100A44U
#define NETX_UART2_STAT 0x00100A84U

#define MSK_NETX_UART_STAT_FE 0x00000001U // [0]
#define SRT_NETX_UART_STAT_FE 0           
#define MSK_NETX_UART_STAT_PE 0x00000002U // [1]
#define SRT_NETX_UART_STAT_PE 1           
#define MSK_NETX_UART_STAT_BE 0x00000004U // [2]
#define SRT_NETX_UART_STAT_BE 2           
#define MSK_NETX_UART_STAT_OE 0x00000008U // [3]
#define SRT_NETX_UART_STAT_OE 3           

enum {
	BFW_NETX_UART_STAT_FE        = 1,  // [0]
	BFW_NETX_UART_STAT_PE        = 1,  // [1]
	BFW_NETX_UART_STAT_BE        = 1,  // [2]
	BFW_NETX_UART_STAT_OE        = 1,  // [3]
	BFW_NETX_UART_STAT_reserved1 = 28  // [31:4]
};

typedef struct UARTRSR_BIT_Ttag {
	unsigned int FE        : BFW_NETX_UART_STAT_FE;        // Framing Error 
	unsigned int PE        : BFW_NETX_UART_STAT_PE;        // Parity Error 
	unsigned int BE        : BFW_NETX_UART_STAT_BE;        // Break Error 
	unsigned int OE        : BFW_NETX_UART_STAT_OE;        // Overrun Error 
	unsigned int reserved1 : BFW_NETX_UART_STAT_reserved1; // reserved
} UARTRSR_BIT_T;

typedef union {
	unsigned int  val;
	UARTRSR_BIT_T bf;
} UARTRSR_T;


// ---------------------------------------------------------------------
// Register uartlcr_h
// => Line control Register, high byte
// => Mode: Mode (r/w)
// ---------------------------------------------------------------------

#define REL_NETX_UART_LINE_CTRL   0x00000008U
#define NETX_UART0_LINE_CTRL 0x00100A08U
#define NETX_UART1_LINE_CTRL 0x00100A48U
#define NETX_UART2_LINE_CTRL 0x00100A88U

#define MSK_NETX_UART_LINE_CTRL_BRK  0x00000001U // [0]
#define SRT_NETX_UART_LINE_CTRL_BRK  0           
#define MSK_NETX_UART_LINE_CTRL_PEN  0x00000002U // [1]
#define SRT_NETX_UART_LINE_CTRL_PEN  1           
#define MSK_NETX_UART_LINE_CTRL_EPS  0x00000004U // [2]
#define SRT_NETX_UART_LINE_CTRL_EPS  2           
#define MSK_NETX_UART_LINE_CTRL_STP2 0x00000008U // [3]
#define SRT_NETX_UART_LINE_CTRL_STP2 3           
#define MSK_NETX_UART_LINE_CTRL_FEN  0x00000010U // [4]
#define SRT_NETX_UART_LINE_CTRL_FEN  4           
#define MSK_NETX_UART_LINE_CTRL_WLEN 0x00000060U // [6:5]
#define SRT_NETX_UART_LINE_CTRL_WLEN 5           

enum {
	BFW_NETX_UART_LINE_CTRL_BRK       = 1,  // [0]
	BFW_NETX_UART_LINE_CTRL_PEN       = 1,  // [1]
	BFW_NETX_UART_LINE_CTRL_EPS       = 1,  // [2]
	BFW_NETX_UART_LINE_CTRL_STP2      = 1,  // [3]
	BFW_NETX_UART_LINE_CTRL_FEN       = 1,  // [4]
	BFW_NETX_UART_LINE_CTRL_WLEN      = 2,  // [6:5]
	BFW_NETX_UART_LINE_CTRL_reserved1 = 25  // [31:7]
};

typedef struct UARTLCR_H_BIT_Ttag {
	unsigned int BRK       : BFW_NETX_UART_LINE_CTRL_BRK;       // Send Break 
	unsigned int PEN       : BFW_NETX_UART_LINE_CTRL_PEN;       // Parity Enalble 
	unsigned int EPS       : BFW_NETX_UART_LINE_CTRL_EPS;       // Even Parity Select 
	unsigned int STP2      : BFW_NETX_UART_LINE_CTRL_STP2;      // 2 Stop Bits Select 
	unsigned int FEN       : BFW_NETX_UART_LINE_CTRL_FEN;       // FIFO Enable 
	unsigned int WLEN      : BFW_NETX_UART_LINE_CTRL_WLEN;      // Word Length 
	                                                        //"00" 5 bits
	                                                        //"01" 6 bits
	                                                        //"10" 7 bits
	                                                        //"11" 8 bits
	unsigned int reserved1 : BFW_NETX_UART_LINE_CTRL_reserved1; // reserved
} UARTLCR_H_BIT_T;

typedef union {
	unsigned int    val;
	UARTLCR_H_BIT_T bf;
} UARTLCR_H_T;


// ---------------------------------------------------------------------
// Register uartlcr_m
// => Line control Register, middle byte
// => Mode: Mode (r/w)
// ---------------------------------------------------------------------

#define REL_NETX_UART_BAUD_DIV_MSB   0x0000000CU
#define NETX_UART0_BAUD_DIV_MSB 0x00100A0CU
#define NETX_UART1_BAUD_DIV_MSB 0x00100A4CU
#define NETX_UART2_BAUD_DIV_MSB 0x00100A8CU

#define MSK_NETX_UART_BAUD_DIV_MSB_BAUDDIVMS 0x000000ffU // [7:0]
#define SRT_NETX_UART_BAUD_DIV_MSB_BAUDDIVMS 0           

enum {
	BFW_NETX_UART_BAUD_DIV_MSB_BAUDDIVMS = 8,  // [7:0]
	BFW_NETX_UART_BAUD_DIV_MSB_reserved1 = 24  // [31:8]
};

typedef struct UARTLCR_M_BIT_Ttag {
	unsigned int BAUDDIVMS : BFW_NETX_UART_BAUD_DIV_MSB_BAUDDIVMS; // bauddiv : Baud Divisor Most Significant Byte 
	                                                        // use higher byte of bauddiv = (system clk / (16 * baud rate)) - 1
	                                                        // if not alternative settings by register uartcr_2 are done
	unsigned int reserved1 : BFW_NETX_UART_BAUD_DIV_MSB_reserved1; // reserved
} UARTLCR_M_BIT_T;

typedef union {
	unsigned int    val;
	UARTLCR_M_BIT_T bf;
} UARTLCR_M_T;


// ---------------------------------------------------------------------
// Register uartlcr_l
// => Line control Register, low byte
// => Mode: Mode (r/w)
// ---------------------------------------------------------------------

#define REL_NETX_UART_BAUD_DIV_LSB   0x00000010U
#define NETX_UART0_BAUD_DIV_LSB 0x00100A10U
#define NETX_UART1_BAUD_DIV_LSB 0x00100A50U
#define NETX_UART2_BAUD_DIV_LSB 0x00100A90U

#define MSK_NETX_UART_BAUD_DIV_LSB_BAUDDIVLS 0x000000ffU // [7:0]
#define SRT_NETX_UART_BAUD_DIV_LSB_BAUDDIVLS 0           

enum {
	BFW_NETX_UART_BAUD_DIV_LSB_BAUDDIVLS = 8,  // [7:0]
	BFW_NETX_UART_BAUD_DIV_LSB_reserved1 = 24  // [31:8]
};

typedef struct UARTLCR_L_BIT_Ttag {
	unsigned int BAUDDIVLS : BFW_NETX_UART_BAUD_DIV_LSB_BAUDDIVLS; // Baud Divisor Least Significant Byte 
	                                                        // use lower byte of bauddiv = (system clk / (16 * baud rate)) - 1
	                                                        // if not alternative settings by register uartcr_2 are done
	unsigned int reserved1 : BFW_NETX_UART_BAUD_DIV_LSB_reserved1; // reserved
} UARTLCR_L_BIT_T;

typedef union {
	unsigned int    val;
	UARTLCR_L_BIT_T bf;
} UARTLCR_L_T;


// ---------------------------------------------------------------------
// Register uartcr
// => uart control Register
// => Mode: Mode (r/w)
// ---------------------------------------------------------------------

#define REL_NETX_UART_CTRL   0x00000014U
#define NETX_UART0_CTRL 0x00100A14U
#define NETX_UART1_CTRL 0x00100A54U
#define NETX_UART2_CTRL 0x00100A94U

#define MSK_NETX_UART_CTRL_uartEN 0x00000001U // [0]
#define SRT_NETX_UART_CTRL_uartEN 0           
#define MSK_NETX_UART_CTRL_SIREN  0x00000002U // [1]
#define SRT_NETX_UART_CTRL_SIREN  1           
#define MSK_NETX_UART_CTRL_SIRLP  0x00000004U // [2]
#define SRT_NETX_UART_CTRL_SIRLP  2           
#define MSK_NETX_UART_CTRL_MSIE   0x00000008U // [3]
#define SRT_NETX_UART_CTRL_MSIE   3           
#define MSK_NETX_UART_CTRL_RIE    0x00000010U // [4]
#define SRT_NETX_UART_CTRL_RIE    4           
#define MSK_NETX_UART_CTRL_TIE    0x00000020U // [5]
#define SRT_NETX_UART_CTRL_TIE    5           
#define MSK_NETX_UART_CTRL_RTIE   0x00000040U // [6]
#define SRT_NETX_UART_CTRL_RTIE   6           
#define MSK_NETX_UART_CTRL_LBE    0x00000080U // [7]
#define SRT_NETX_UART_CTRL_LBE    7           

enum {
	BFW_NETX_UART_CTRL_uartEN    = 1,  // [0]
	BFW_NETX_UART_CTRL_SIREN     = 1,  // [1]
	BFW_NETX_UART_CTRL_SIRLP     = 1,  // [2]
	BFW_NETX_UART_CTRL_MSIE      = 1,  // [3]
	BFW_NETX_UART_CTRL_RIE       = 1,  // [4]
	BFW_NETX_UART_CTRL_TIE       = 1,  // [5]
	BFW_NETX_UART_CTRL_RTIE      = 1,  // [6]
	BFW_NETX_UART_CTRL_LBE       = 1,  // [7]
	BFW_NETX_UART_CTRL_reserved1 = 24  // [31:8]
};

typedef struct UARTCR_BIT_Ttag {
	unsigned int uartEN    : BFW_NETX_UART_CTRL_uartEN;    // uart Enable 
	unsigned int SIREN     : BFW_NETX_UART_CTRL_SIREN;     // SIR Enable 
	unsigned int SIRLP     : BFW_NETX_UART_CTRL_SIRLP;     // IrDA SIR Low Power Mode 
	unsigned int MSIE      : BFW_NETX_UART_CTRL_MSIE;      // Modem Status Interrupt Enable 
	unsigned int RIE       : BFW_NETX_UART_CTRL_RIE;       // Receive Interrupt Enable 
	unsigned int TIE       : BFW_NETX_UART_CTRL_TIE;       // Transmit Interrupt Enable 
	unsigned int RTIE      : BFW_NETX_UART_CTRL_RTIE;      // Receive Timeout Interrupt Enable 
	unsigned int LBE       : BFW_NETX_UART_CTRL_LBE;       // Loop Back Enable 
	unsigned int reserved1 : BFW_NETX_UART_CTRL_reserved1; // reserved
} UARTCR_BIT_T;

typedef union {
	unsigned int val;
	UARTCR_BIT_T bf;
} UARTCR_T;


// ---------------------------------------------------------------------
// Register uartfr
// => uart Flag Register
// => Mode: Mode (r)
// ---------------------------------------------------------------------

#define REL_NETX_UART_FLAG   0x00000018U
#define NETX_UART0_FLAG 0x00100A18U
#define NETX_UART1_FLAG 0x00100A58U
#define NETX_UART2_FLAG 0x00100A98U

#define MSK_NETX_UART_FLAG_CTS  0x00000001U // [0]
#define SRT_NETX_UART_FLAG_CTS  0           
#define MSK_NETX_UART_FLAG_DSR  0x00000002U // [1]
#define SRT_NETX_UART_FLAG_DSR  1           
#define MSK_NETX_UART_FLAG_DCD  0x00000004U // [2]
#define SRT_NETX_UART_FLAG_DCD  2           
#define MSK_NETX_UART_FLAG_BUSY 0x00000008U // [3]
#define SRT_NETX_UART_FLAG_BUSY 3           
#define MSK_NETX_UART_FLAG_RXFE 0x00000010U // [4]
#define SRT_NETX_UART_FLAG_RXFE 4           
#define MSK_NETX_UART_FLAG_TXFF 0x00000020U // [5]
#define SRT_NETX_UART_FLAG_TXFF 5           
#define MSK_NETX_UART_FLAG_RXFF 0x00000040U // [6]
#define SRT_NETX_UART_FLAG_RXFF 6           
#define MSK_NETX_UART_FLAG_TXFE 0x00000080U // [7]
#define SRT_NETX_UART_FLAG_TXFE 7           

enum {
	BFW_NETX_UART_FLAG_CTS       = 1,  // [0]
	BFW_NETX_UART_FLAG_DSR       = 1,  // [1]
	BFW_NETX_UART_FLAG_DCD       = 1,  // [2]
	BFW_NETX_UART_FLAG_BUSY      = 1,  // [3]
	BFW_NETX_UART_FLAG_RXFE      = 1,  // [4]
	BFW_NETX_UART_FLAG_TXFF      = 1,  // [5]
	BFW_NETX_UART_FLAG_RXFF      = 1,  // [6]
	BFW_NETX_UART_FLAG_TXFE      = 1,  // [7]
	BFW_NETX_UART_FLAG_reserved1 = 24  // [31:8]
};

typedef struct UARTFR_BIT_Ttag {
	unsigned int CTS       : BFW_NETX_UART_FLAG_CTS;       // Clear To Send 
	unsigned int DSR       : BFW_NETX_UART_FLAG_DSR;       // Data Set Ready 
	unsigned int DCD       : BFW_NETX_UART_FLAG_DCD;       // Data Carrier Detect 
	unsigned int BUSY      : BFW_NETX_UART_FLAG_BUSY;      // uart BUSY 
	unsigned int RXFE      : BFW_NETX_UART_FLAG_RXFE;      // Receive FIFO Empty 
	unsigned int TXFF      : BFW_NETX_UART_FLAG_TXFF;      // Transmit FIFO Full 
	unsigned int RXFF      : BFW_NETX_UART_FLAG_RXFF;      // Receive FIFO Full 
	unsigned int TXFE      : BFW_NETX_UART_FLAG_TXFE;      // Transmit FIFO Empty 
	unsigned int reserved1 : BFW_NETX_UART_FLAG_reserved1; // reserved
} UARTFR_BIT_T;

typedef union {
	unsigned int val;
	UARTFR_BIT_T bf;
} UARTFR_T;


// ---------------------------------------------------------------------
// Register uartiir
// => Interrupt Identification (read) / interrupt clear (write)
// => Mode: Mode (r/w)
// ---------------------------------------------------------------------

#define REL_NETX_UART_INT_ID   0x0000001CU
#define NETX_UART0_INT_ID 0x00100A1CU
#define NETX_UART1_INT_ID 0x00100A5CU
#define NETX_UART2_INT_ID 0x00100A9CU

#define MSK_NETX_UART_INT_ID_MIS  0x00000001U // [0]
#define SRT_NETX_UART_INT_ID_MIS  0           
#define MSK_NETX_UART_INT_ID_RIS  0x00000002U // [1]
#define SRT_NETX_UART_INT_ID_RIS  1           
#define MSK_NETX_UART_INT_ID_TIS  0x00000004U // [2]
#define SRT_NETX_UART_INT_ID_TIS  2           
#define MSK_NETX_UART_INT_ID_RTIS 0x00000008U // [3]
#define SRT_NETX_UART_INT_ID_RTIS 3           

enum {
	BFW_NETX_UART_INT_ID_MIS       = 1,  // [0]
	BFW_NETX_UART_INT_ID_RIS       = 1,  // [1]
	BFW_NETX_UART_INT_ID_TIS       = 1,  // [2]
	BFW_NETX_UART_INT_ID_RTIS      = 1,  // [3]
	BFW_NETX_UART_INT_ID_reserved1 = 28  // [31:4]
};

typedef struct UARTIIR_BIT_Ttag {
	unsigned int MIS       : BFW_NETX_UART_INT_ID_MIS;       // Modem Interrupt Status 
	unsigned int RIS       : BFW_NETX_UART_INT_ID_RIS;       // Receive Interrupt Status # defaul0x0
	unsigned int TIS       : BFW_NETX_UART_INT_ID_TIS;       // Transmit Interrupt Status 
	unsigned int RTIS      : BFW_NETX_UART_INT_ID_RTIS;      // Receive Timeout Interrupt Status 
	unsigned int reserved1 : BFW_NETX_UART_INT_ID_reserved1; // reserved
} UARTIIR_BIT_T;

typedef union {
	unsigned int  val;
	UARTIIR_BIT_T bf;
} UARTIIR_T;


// ---------------------------------------------------------------------
// Register uartilpr
// => IrDA Low Power Counter Register
// => Mode: Mode (r/w)
// ---------------------------------------------------------------------

#define REL_NETX_UART_IRDA_LO_PWR_CNTR   0x00000020U
#define NETX_UART0_IRDA_LO_PWR_CNTR 0x00100A20U
#define NETX_UART1_IRDA_LO_PWR_CNTR 0x00100A60U
#define NETX_UART2_IRDA_LO_PWR_CNTR 0x00100AA0U

#define MSK_NETX_UART_IRDA_LO_PWR_CNTR_ILPDVSR 0x000000ffU // [7:0]
#define SRT_NETX_UART_IRDA_LO_PWR_CNTR_ILPDVSR 0           

enum {
	BFW_NETX_UART_IRDA_LO_PWR_CNTR_ILPDVSR   = 8,  // [7:0]
	BFW_NETX_UART_IRDA_LO_PWR_CNTR_reserved1 = 24  // [31:8]
};

typedef struct UARTILPR_BIT_Ttag {
	unsigned int ILPDVSR   : BFW_NETX_UART_IRDA_LO_PWR_CNTR_ILPDVSR;   // IrDA Low Power Divisor 
	unsigned int reserved1 : BFW_NETX_UART_IRDA_LO_PWR_CNTR_reserved1; // reserved
} UARTILPR_BIT_T;

typedef union {
	unsigned int   val;
	UARTILPR_BIT_T bf;
} UARTILPR_T;


// ---------------------------------------------------------------------
// Register uartrts
// => RTS Control Register
// => Mode: Mode (r/w)
// ---------------------------------------------------------------------

#define REL_NETX_UART_RTS_CTRL   0x00000024U
#define NETX_UART0_RTS_CTRL 0x00100A24U
#define NETX_UART1_RTS_CTRL 0x00100A64U
#define NETX_UART2_RTS_CTRL 0x00100AA4U

#define MSK_NETX_UART_RTS_CTRL_AUTO    0x00000001U // [0]
#define SRT_NETX_UART_RTS_CTRL_AUTO    0           
#define MSK_NETX_UART_RTS_CTRL_RTS     0x00000002U // [1]
#define SRT_NETX_UART_RTS_CTRL_RTS     1           
#define MSK_NETX_UART_RTS_CTRL_COUNT   0x00000004U // [2]
#define SRT_NETX_UART_RTS_CTRL_COUNT   2           
#define MSK_NETX_UART_RTS_CTRL_MOD2    0x00000008U // [3]
#define SRT_NETX_UART_RTS_CTRL_MOD2    3           
#define MSK_NETX_UART_RTS_CTRL_RTS_pol 0x00000010U // [4]
#define SRT_NETX_UART_RTS_CTRL_RTS_pol 4           
#define MSK_NETX_UART_RTS_CTRL_CTS_ctr 0x00000020U // [5]
#define SRT_NETX_UART_RTS_CTRL_CTS_ctr 5           
#define MSK_NETX_UART_RTS_CTRL_CTS_pol 0x00000040U // [6]
#define SRT_NETX_UART_RTS_CTRL_CTS_pol 6           
#define MSK_NETX_UART_RTS_CTRL_STICK   0x00000080U // [7]
#define SRT_NETX_UART_RTS_CTRL_STICK   7           

enum {
	BFW_NETX_UART_RTS_CTRL_AUTO      = 1,  // [0]
	BFW_NETX_UART_RTS_CTRL_RTS       = 1,  // [1]
	BFW_NETX_UART_RTS_CTRL_COUNT     = 1,  // [2]
	BFW_NETX_UART_RTS_CTRL_MOD2      = 1,  // [3]
	BFW_NETX_UART_RTS_CTRL_RTS_pol   = 1,  // [4]
	BFW_NETX_UART_RTS_CTRL_CTS_ctr   = 1,  // [5]
	BFW_NETX_UART_RTS_CTRL_CTS_pol   = 1,  // [6]
	BFW_NETX_UART_RTS_CTRL_STICK     = 1,  // [7]
	BFW_NETX_UART_RTS_CTRL_reserved1 = 24  // [31:8]
};

typedef struct UARTRTS_BIT_Ttag {
	unsigned int AUTO      : BFW_NETX_UART_RTS_CTRL_AUTO;      // automatic or controlled by the next bit (RTS) 
	unsigned int RTS       : BFW_NETX_UART_RTS_CTRL_RTS;       // if AUTO=0: controlled by this bit 
	unsigned int COUNT     : BFW_NETX_UART_RTS_CTRL_COUNT;     // count base: 1=system clocks, 0=time in bauds 
	unsigned int MOD2      : BFW_NETX_UART_RTS_CTRL_MOD2;      // mode1/mode2 
	unsigned int RTS_pol   : BFW_NETX_UART_RTS_CTRL_RTS_pol;   // RTS polarity: 1=active high 
	unsigned int CTS_ctr   : BFW_NETX_UART_RTS_CTRL_CTS_ctr;   // nUARTCTS control 
	unsigned int CTS_pol   : BFW_NETX_UART_RTS_CTRL_CTS_pol;   // nUARTCTS polarity: 1=active high 
	unsigned int STICK     : BFW_NETX_UART_RTS_CTRL_STICK;     // stick parity 
	unsigned int reserved1 : BFW_NETX_UART_RTS_CTRL_reserved1; // reserved
} UARTRTS_BIT_T;

typedef union {
	unsigned int  val;
	UARTRTS_BIT_T bf;
} UARTRTS_T;


// ---------------------------------------------------------------------
// Register uartforerun
// => RTS forerun cycles
// => Mode: Mode (r/w)
// ---------------------------------------------------------------------

#define REL_NETX_UART_RTS_LEAD_CYC   0x00000028U
#define NETX_UART0_RTS_LEAD_CYC 0x00100A28U
#define NETX_UART1_RTS_LEAD_CYC 0x00100A68U
#define NETX_UART2_RTS_LEAD_CYC 0x00100AA8U

#define MSK_NETX_UART_RTS_LEAD_CYC_FORERUN 0x000000ffU // [7:0]
#define SRT_NETX_UART_RTS_LEAD_CYC_FORERUN 0           

enum {
	BFW_NETX_UART_RTS_LEAD_CYC_FORERUN   = 8,  // [7:0]
	BFW_NETX_UART_RTS_LEAD_CYC_reserved1 = 24  // [31:8]
};

typedef struct UARTFORERUN_BIT_Ttag {
	unsigned int FORERUN   : BFW_NETX_UART_RTS_LEAD_CYC_FORERUN;   // number of forerun cycles in system clocks or bauds 
	unsigned int reserved1 : BFW_NETX_UART_RTS_LEAD_CYC_reserved1; // reserved
} UARTFORERUN_BIT_T;

typedef union {
	unsigned int      val;
	UARTFORERUN_BIT_T bf;
} UARTFORERUN_T;


// ---------------------------------------------------------------------
// Register uarttrail
// => RTS trail cycles
// => Mode: Mode (r/w)
// ---------------------------------------------------------------------

#define REL_NETX_UART_RTS_TRAIL_CYC   0x0000002CU
#define NETX_UART0_RTS_TRAIL_CYC 0x00100A2CU
#define NETX_UART1_RTS_TRAIL_CYC 0x00100A6CU
#define NETX_UART2_RTS_TRAIL_CYC 0x00100AACU

#define MSK_NETX_UART_RTS_TRAIL_CYC_TRAIL 0x000000ffU // [7:0]
#define SRT_NETX_UART_RTS_TRAIL_CYC_TRAIL 0           

enum {
	BFW_NETX_UART_RTS_TRAIL_CYC_TRAIL     = 8,  // [7:0]
	BFW_NETX_UART_RTS_TRAIL_CYC_reserved1 = 24  // [31:8]
};

typedef struct UARTTRAIL_BIT_Ttag {
	unsigned int TRAIL     : BFW_NETX_UART_RTS_TRAIL_CYC_TRAIL;     // number of trail cycles in system clocks or bauds 
	unsigned int reserved1 : BFW_NETX_UART_RTS_TRAIL_CYC_reserved1; // reserved
} UARTTRAIL_BIT_T;

typedef union {
	unsigned int    val;
	UARTTRAIL_BIT_T bf;
} UARTTRAIL_T;


// ---------------------------------------------------------------------
// Register uartdrvout
// => Drive Output
// => Mode: Mode (r/w)
// ---------------------------------------------------------------------

#define REL_NETX_UART_OUT_DRV_EN   0x00000030U
#define NETX_UART0_OUT_DRV_EN 0x00100A30U
#define NETX_UART1_OUT_DRV_EN 0x00100A70U
#define NETX_UART2_OUT_DRV_EN 0x00100AB0U

#define MSK_NETX_UART_OUT_DRV_EN_DRVTX  0x00000001U // [0]
#define SRT_NETX_UART_OUT_DRV_EN_DRVTX  0           
#define MSK_NETX_UART_OUT_DRV_EN_DRVRTS 0x00000002U // [1]
#define SRT_NETX_UART_OUT_DRV_EN_DRVRTS 1           

enum {
	BFW_NETX_UART_OUT_DRV_EN_DRVTX     = 1,  // [0]
	BFW_NETX_UART_OUT_DRV_EN_DRVRTS    = 1,  // [1]
	BFW_NETX_UART_OUT_DRV_EN_reserved1 = 30  // [31:2]
};

typedef struct UARTDRVOUT_BIT_Ttag {
	unsigned int DRVTX     : BFW_NETX_UART_OUT_DRV_EN_DRVTX;     // enable driver for TX 
	unsigned int DRVRTS    : BFW_NETX_UART_OUT_DRV_EN_DRVRTS;    // enable driver for RTS 
	unsigned int reserved1 : BFW_NETX_UART_OUT_DRV_EN_reserved1; // reserved
} UARTDRVOUT_BIT_T;

typedef union {
	unsigned int     val;
	UARTDRVOUT_BIT_T bf;
} UARTDRVOUT_T;


// ---------------------------------------------------------------------
// Register uartcr_2
// => Control Register 2
// => Mode: Mode (r/w)
// ---------------------------------------------------------------------

#define REL_NETX_UART_BAUD_MODE_CTRL   0x00000034U
#define NETX_UART0_BAUD_MODE_CTRL 0x00100A34U
#define NETX_UART1_BAUD_MODE_CTRL 0x00100A74U
#define NETX_UART2_BAUD_MODE_CTRL 0x00100AB4U

#define MSK_NETX_UART_BAUD_MODE_CTRL_Baud_Rate_Mode 0x00000001U // [0]
#define SRT_NETX_UART_BAUD_MODE_CTRL_Baud_Rate_Mode 0           

enum {
	BFW_NETX_UART_BAUD_MODE_CTRL_Baud_Rate_Mode = 1,  // [0]
	BFW_NETX_UART_BAUD_MODE_CTRL_reserved1      = 31  // [31:1]
};

typedef struct UARTCR_2_BIT_Ttag {
	unsigned int Baud_Rate_Mode : BFW_NETX_UART_BAUD_MODE_CTRL_Baud_Rate_Mode; // If this bit is set the baud rate is generated more exactly by the following formula:      
	                                                        // value = ( (Baud Rate * 16) / System Frequency ) * 2^16  .
	                                                        // You have to write this 16-bit value in register uartlcr_l and uartlcr_m.
	unsigned int reserved1      : BFW_NETX_UART_BAUD_MODE_CTRL_reserved1;      // reserved
} UARTCR_2_BIT_T;

typedef union {
	unsigned int   val;
	UARTCR_2_BIT_T bf;
} UARTCR_2_T;


// ---------------------------------------------------------------------
// Register uartrxiflsel
// => RX FIFO trigger level
// => Mode: Mode (r/w)
// ---------------------------------------------------------------------

#define REL_NETX_UART_RX_FIFO_IRQ_LVL   0x00000038U
#define NETX_UART0_RX_FIFO_IRQ_LVL 0x00100A38U
#define NETX_UART1_RX_FIFO_IRQ_LVL 0x00100A78U
#define NETX_UART2_RX_FIFO_IRQ_LVL 0x00100AB8U

#define MSK_NETX_UART_RX_FIFO_IRQ_LVL_RXIFLSEL 0x0000001fU // [4:0]
#define SRT_NETX_UART_RX_FIFO_IRQ_LVL_RXIFLSEL 0           

enum {
	BFW_NETX_UART_RX_FIFO_IRQ_LVL_RXIFLSEL  = 5,  // [4:0]
	BFW_NETX_UART_RX_FIFO_IRQ_LVL_reserved1 = 27  // [31:5]
};

typedef struct UARTRXIFLSEL_BIT_Ttag {
	unsigned int RXIFLSEL  : BFW_NETX_UART_RX_FIFO_IRQ_LVL_RXIFLSEL;  //  	Choose a number between 1 and 16. It defines the IRQ trigger level of the receive fifo. 
	                                                        //   The IRQ (UARTRXINTR) will be set if the number of received bytes in the receive fifo are greater than or equal RXIFLSEL. 	
	unsigned int reserved1 : BFW_NETX_UART_RX_FIFO_IRQ_LVL_reserved1; // reserved
} UARTRXIFLSEL_BIT_T;

typedef union {
	unsigned int       val;
	UARTRXIFLSEL_BIT_T bf;
} UARTRXIFLSEL_T;


// ---------------------------------------------------------------------
// Register uarttxiflsel
// => TX FIFO trigger level
// => Mode: Mode (r/w)
// ---------------------------------------------------------------------

#define REL_NETX_UART_TX_FIFO_IRQ_LVL   0x0000003CU
#define NETX_UART0_TX_FIFO_IRQ_LVL 0x00100A3CU
#define NETX_UART1_TX_FIFO_IRQ_LVL 0x00100A7CU
#define NETX_UART2_TX_FIFO_IRQ_LVL 0x00100ABCU

#define MSK_NETX_UART_TX_FIFO_IRQ_LVL_TXIFLSEL 0x0000001fU // [4:0]
#define SRT_NETX_UART_TX_FIFO_IRQ_LVL_TXIFLSEL 0           

enum {
	BFW_NETX_UART_TX_FIFO_IRQ_LVL_TXIFLSEL  = 5,  // [4:0]
	BFW_NETX_UART_TX_FIFO_IRQ_LVL_reserved1 = 27  // [31:5]
};

typedef struct UARTTXIFLSEL_BIT_Ttag {
	unsigned int TXIFLSEL  : BFW_NETX_UART_TX_FIFO_IRQ_LVL_TXIFLSEL;  //  	Choose a number between 1 and 16. It defines the IRQ trigger level of the transmit fifo. 
	                                                        //   The IRQ (UARTTXINTR) will be set if the number of transmitted bytes in the transmit fifo are less than TXIFLSEL.	
	unsigned int reserved1 : BFW_NETX_UART_TX_FIFO_IRQ_LVL_reserved1; // reserved
} UARTTXIFLSEL_BIT_T;

typedef union {
	unsigned int       val;
	UARTTXIFLSEL_BIT_T bf;
} UARTTXIFLSEL_T;



/*************************************************************************************/

#endif /* _UART_H */
