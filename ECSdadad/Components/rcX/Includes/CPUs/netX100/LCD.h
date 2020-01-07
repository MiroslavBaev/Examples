/******************************************************************************

  Copyright (C) 2010 [Hilscher Gesellschaft für Systemautomation mbH]

  This program can be used by everyone according to the netX Open Source
  Software license. The license agreement can be downloaded from
  http://www.industrialNETworX.com

*******************************************************************************

  Last Modification:
    @version $Id: LCD.h 333 2010-04-26 09:32:25Z Volker $

  Description:
    netX LCD definitions

  Changes:
    Date        Author        Description
  ---------------------------------------------------------------------------
    2010-03-24  NC            File created.

******************************************************************************/


#ifndef _LCD_H
#define _LCD_H


/*************************************************************************************/


// =====================================================================
//
// Area of lcd_ctrl
//
// =====================================================================

#define NETX_LCD_AREA	0x00104000U


// ---------------------------------------------------------------------
// Register LCDTiming0
// => LCD Timing 0 Register
//    This register controls the Horizontal Sync width, Horizontal Front porch and Horizontal
//    Back porch period. The data path latency forces some restrictions on the usable minimum
//    values for horizontal porch width in STN mode. The minimum values are HSW = 2 and HBP = 2.
// => Mode: Mode (r/w)
// ---------------------------------------------------------------------

#define REL_NETX_LCD_TIMING0 0x00000000U
#define NETX_LCD_TIMING0     0x00104000U

#define MSK_NETX_LCD_TIMING0_unused 0x00000003U // [1:0]
#define SRT_NETX_LCD_TIMING0_unused 0           
#define MSK_NETX_LCD_TIMING0_PPL    0x000000fcU // [7:2]
#define SRT_NETX_LCD_TIMING0_PPL    2           
#define MSK_NETX_LCD_TIMING0_HSW    0x0000ff00U // [15:8]
#define SRT_NETX_LCD_TIMING0_HSW    8           
#define MSK_NETX_LCD_TIMING0_HFP    0x00ff0000U // [23:16]
#define SRT_NETX_LCD_TIMING0_HFP    16          
#define MSK_NETX_LCD_TIMING0_HBP    0xff000000U // [31:24]
#define SRT_NETX_LCD_TIMING0_HBP    24          

enum {
	BFW_NETX_LCD_TIMING0_unused = 2, // [1:0]
	BFW_NETX_LCD_TIMING0_PPL    = 6, // [7:2]
	BFW_NETX_LCD_TIMING0_HSW    = 8, // [15:8]
	BFW_NETX_LCD_TIMING0_HFP    = 8, // [23:16]
	BFW_NETX_LCD_TIMING0_HBP    = 8  // [31:24]
};

typedef struct LCDTIMING0_BIT_Ttag {
	unsigned int unused : BFW_NETX_LCD_TIMING0_unused; // reserved
	unsigned int PPL    : BFW_NETX_LCD_TIMING0_PPL;    // Pixels per line                                                      
	                                                        // Actual Pixels-per-line = 16 (PPL+1)
	unsigned int HSW    : BFW_NETX_LCD_TIMING0_HSW;    // Horizontal Sync Pulse Width                                          
	                                                        // Width of the LLP signal in CLCP periods. Program with value minus 1.
	unsigned int HFP    : BFW_NETX_LCD_TIMING0_HFP;    // Horizontal Front Porch                                               
	                                                        // Number of CLCP periods between the end of active data and the rising edge of CLCP.
	                                                        // Program with value minus 1.
	unsigned int HBP    : BFW_NETX_LCD_TIMING0_HBP;    // Horizontal Back Porch                                                
	                                                        // Number of CLCP periods between the falling edge of CLCP and the start of active data.
	                                                        // Program with value minus 1.
} LCDTIMING0_BIT_T;

typedef union {
	unsigned int     val;
	LCDTIMING0_BIT_T bf;
} LCDTIMING0_T;


// ---------------------------------------------------------------------
// Register LCDTiming1
// => LCD Timing 1 Register
//    This register controls the Lines per screen, Vertical Sync width, Vertical Front porch and Vertical
//    Back porch period.
// => Mode: Mode (r/w)
// ---------------------------------------------------------------------

#define REL_NETX_LCD_TIMING1 0x00000004U
#define NETX_LCD_TIMING1     0x00104004U

#define MSK_NETX_LCD_TIMING1_LPP 0x000003ffU // [9:0]
#define SRT_NETX_LCD_TIMING1_LPP 0           
#define MSK_NETX_LCD_TIMING1_VSW 0x0000fc00U // [15:10]
#define SRT_NETX_LCD_TIMING1_VSW 10          
#define MSK_NETX_LCD_TIMING1_VFP 0x00ff0000U // [23:16]
#define SRT_NETX_LCD_TIMING1_VFP 16          
#define MSK_NETX_LCD_TIMING1_VBP 0xff000000U // [31:24]
#define SRT_NETX_LCD_TIMING1_VBP 24          

enum {
	BFW_NETX_LCD_TIMING1_LPP = 10, // [9:0]
	BFW_NETX_LCD_TIMING1_VSW = 6,  // [15:10]
	BFW_NETX_LCD_TIMING1_VFP = 8,  // [23:16]
	BFW_NETX_LCD_TIMING1_VBP = 8   // [31:24]
};

typedef struct LCDTIMING1_BIT_Ttag {
	unsigned int LPP : BFW_NETX_LCD_TIMING1_LPP; // Lines per panel                                                      
	                                                        // Number of active lines per screen. Program to number of lines required minus 1.
	unsigned int VSW : BFW_NETX_LCD_TIMING1_VSW; // Vertical Sync Pulse Width                                            
	                                                        // Number of Hsync lines. Should be small (e.g. program to zero) for passive STN LCDs.
	                                                        // Program the number of lines minus one. The higher the value the worse the contrast of STN LCDs.
	unsigned int VFP : BFW_NETX_LCD_TIMING1_VFP; // Vertical Front Porch                                                 
	                                                        // Number of inactive lines at the end of the frame, before Vsync period.
	                                                        // Program to zero on passive displays or reduced contrast will result.
	unsigned int VBP : BFW_NETX_LCD_TIMING1_VBP; // Vertical Back Porch                                                  
	                                                        // Number of inactive lines at the start of the frame, after Vsync period.
	                                                        // Program to zero on passive displays or reduced contrast will result.
} LCDTIMING1_BIT_T;

typedef union {
	unsigned int     val;
	LCDTIMING1_BIT_T bf;
} LCDTIMING1_T;


// ---------------------------------------------------------------------
// Register LCDTiming2
// => LCD Timing 2 Register
//    The data path latency forces some restrictions on the usable minimum values for the panel clock
//    divider in STN modes.
//    Single panel colour mode:               PCD =  1 (CLCP = CLCDCLK/3)
//    Dual panel colour mode:                 PCD =  4 (CLCP = CLCDCLK/6)
//    Single panel mono 4-bit interface mode: PCD =  2 (CLCP = CLCDCLK/4)
//    Dual panel mono 4-bit interface mode:   PCD =  6 (CLCP = CLCDCLK/8)
//    Single panel mono 8-bit interface mode: PCD =  6 (CLCP = CLCDCLK/8)
//    Dual panel mono 8-bit interface mode:   PCD = 14 (CLCP = CLCDCLK/16)
// => Mode: Mode (r/w)
// ---------------------------------------------------------------------

#define REL_NETX_LCD_TIMING2 0x00000008U
#define NETX_LCD_TIMING2     0x00104008U

#define MSK_NETX_LCD_TIMING2_PCD_LO 0x0000001fU // [4:0]
#define SRT_NETX_LCD_TIMING2_PCD_LO 0           
#define MSK_NETX_LCD_TIMING2_CLKSEL 0x00000020U // [5]
#define SRT_NETX_LCD_TIMING2_CLKSEL 5           
#define MSK_NETX_LCD_TIMING2_ACB    0x000007c0U // [10:6]
#define SRT_NETX_LCD_TIMING2_ACB    6           
#define MSK_NETX_LCD_TIMING2_IVS    0x00000800U // [11]
#define SRT_NETX_LCD_TIMING2_IVS    11          
#define MSK_NETX_LCD_TIMING2_IHS    0x00001000U // [12]
#define SRT_NETX_LCD_TIMING2_IHS    12          
#define MSK_NETX_LCD_TIMING2_IPC    0x00002000U // [13]
#define SRT_NETX_LCD_TIMING2_IPC    13          
#define MSK_NETX_LCD_TIMING2_IEO    0x00004000U // [14]
#define SRT_NETX_LCD_TIMING2_IEO    14          
#define MSK_NETX_LCD_TIMING2_CPL    0x03ff0000U // [25:16]
#define SRT_NETX_LCD_TIMING2_CPL    16          
#define MSK_NETX_LCD_TIMING2_BCD    0x04000000U // [26]
#define SRT_NETX_LCD_TIMING2_BCD    26          
#define MSK_NETX_LCD_TIMING2_PCD_HI 0xf8000000U // [31:27]
#define SRT_NETX_LCD_TIMING2_PCD_HI 27          

enum {
	BFW_NETX_LCD_TIMING2_PCD_LO    = 5,  // [4:0]
	BFW_NETX_LCD_TIMING2_CLKSEL    = 1,  // [5]
	BFW_NETX_LCD_TIMING2_ACB       = 5,  // [10:6]
	BFW_NETX_LCD_TIMING2_IVS       = 1,  // [11]
	BFW_NETX_LCD_TIMING2_IHS       = 1,  // [12]
	BFW_NETX_LCD_TIMING2_IPC       = 1,  // [13]
	BFW_NETX_LCD_TIMING2_IEO       = 1,  // [14]
	BFW_NETX_LCD_TIMING2_reserved1 = 1,  // [15]
	BFW_NETX_LCD_TIMING2_CPL       = 10, // [25:16]
	BFW_NETX_LCD_TIMING2_BCD       = 1,  // [26]
	BFW_NETX_LCD_TIMING2_PCD_HI    = 5   // [31:27]
};

typedef struct LCDTIMING2_BIT_Ttag {
	unsigned int PCD_LO    : BFW_NETX_LCD_TIMING2_PCD_LO;    // Panel clock divisor - lower 5-bits                                   
	                                                        // Used to specify the frequency of the LCD panel (CLCP) clock based on the LCD clock
	                                                        // (CLCDCLK) frequency. LCD panel clock frequency can range from CLCDCLK/2 toCLCDCLK/33.
	                                                        // Panel clock frequency = CLCDCLK/(PCD+2)
	unsigned int CLKSEL    : BFW_NETX_LCD_TIMING2_CLKSEL;    // This bit drives the CLCDCLKSEL signal, which is used as a select     # default 0                                                
	                                                        // signal for the external LCD clock MUX.
	unsigned int ACB       : BFW_NETX_LCD_TIMING2_ACB;       // AC Bias Pin Frequency                                                
	                                                        // Number of line clocks to count before toggling the AC Bias pin. This pin is used to
	                                                        // periodically invert the polarity of the power supply to prevent DC charge build-up
	                                                        // within STN displays.Program to value required minus 1.
	unsigned int IVS       : BFW_NETX_LCD_TIMING2_IVS;       // Invert Vsync                                                         
	                                                        //  0 : CLFP pin is active HIGH and inactive LOW.
	                                                        //  1 : CLFP pin is active LOW and inactive HIGH.
	unsigned int IHS       : BFW_NETX_LCD_TIMING2_IHS;       // Invert Hsync                                                         
	                                                        //  0 : CLLP pin is active HIGH and inactive LOW.
	                                                        //  1 : CLLP pin is active LOW and inactive HIGH.
	unsigned int IPC       : BFW_NETX_LCD_TIMING2_IPC;       // Invert Panel clock                                                   
	                                                        //  0 : Data is driven on the LCDs data lines on the rising-edge of CLCP.
	                                                        //  1 : Data is driven on the LCDs data lines on the falling-edge of CLCP.
	unsigned int IEO       : BFW_NETX_LCD_TIMING2_IEO;       // Invert Output Enable                                                 
	                                                        //  0 : CLAC pin is active HIGH in TFT mode.
	                                                        //  1 : CLAC pin is active LOW in TFT mode.
	unsigned int reserved1 : BFW_NETX_LCD_TIMING2_reserved1; // reserved
	unsigned int CPL       : BFW_NETX_LCD_TIMING2_CPL;       // Clocks Per Line                                                      
	                                                        // This field specifies the number of actual CLCP clocks to the LCD panel on each line.
	                                                        // This is the number of pixels per line divided by either 1 (TFT), 4 or 8 (for mono passive),
	                                                        // 2 2/3 (for colour passive), minus one. This must be correctly programmed in addition to PPL
	                                                        // for the LCD controller to work correctly.
	unsigned int BCD       : BFW_NETX_LCD_TIMING2_BCD;       // Bypass Pixel Clock Divider                                           
	                                                        // Setting this to 1 bypasses the pixel clock divider logic. This is mainly used for TFT displays.
	unsigned int PCD_HI    : BFW_NETX_LCD_TIMING2_PCD_HI;    // Panel clock divisor - upper 5-bits                                   
	                                                        // Used to specify the frequency of the LCD panel (CLCP) clock based on the LCD clock
	                                                        // (CLCDCLK) frequency. LCD panel clock frequency can range from CLCDCLK/2 toCLCDCLK/33.
	                                                        // Panel clock frequency = CLCDCLK/(PCD+2)
} LCDTIMING2_BIT_T;

typedef union {
	unsigned int     val;
	LCDTIMING2_BIT_T bf;
} LCDTIMING2_T;


// ---------------------------------------------------------------------
// Register LCDTiming3
// => LCD Timing 3 Register
//    This register controls the Line-End signal.
// => Mode: Mode (r/w)
// ---------------------------------------------------------------------

#define REL_NETX_LCD_TIMING3 0x0000000CU
#define NETX_LCD_TIMING3     0x0010400CU

#define MSK_NETX_LCD_TIMING3_LED 0x0000007fU // [6:0]
#define SRT_NETX_LCD_TIMING3_LED 0           
#define MSK_NETX_LCD_TIMING3_LEE 0x00010000U // [16]
#define SRT_NETX_LCD_TIMING3_LEE 16          

enum {
	BFW_NETX_LCD_TIMING3_LED       = 7,  // [6:0]
	BFW_NETX_LCD_TIMING3_reserved1 = 9,  // [15:7]
	BFW_NETX_LCD_TIMING3_LEE       = 1,  // [16]
	BFW_NETX_LCD_TIMING3_reserved2 = 15  // [31:17]
};

typedef struct LCDTIMING3_BIT_Ttag {
	unsigned int LED       : BFW_NETX_LCD_TIMING3_LED;       // Line-End signal delay from the rising edge of the last panel clock (CLCP) 
	unsigned int reserved1 : BFW_NETX_LCD_TIMING3_reserved1; // reserved
	unsigned int LEE       : BFW_NETX_LCD_TIMING3_LEE;       // LCD Line end enable                                                       
	                                                        //  0 : CLLE disabled (held low)
	                                                        //  1 : CLLE signal active
	unsigned int reserved2 : BFW_NETX_LCD_TIMING3_reserved2; // reserved
} LCDTIMING3_BIT_T;

typedef union {
	unsigned int     val;
	LCDTIMING3_BIT_T bf;
} LCDTIMING3_T;


// ---------------------------------------------------------------------
// Register LCDUPBASE
// => LCD Upper panel DMA Channel Base Address
//    This is a register to program the upper base address of the frame buffer. The base address is word aligned, hence only
//    the bits 31:2 are used. LCDUPBASE is used for TFT and single panel STN displays, and also the upper panel of dual panel
//    STN displays.
// => Mode: Mode (r/w)
// ---------------------------------------------------------------------

#define REL_NETX_LCD_UP_PAN_BASE 0x00000010U
#define NETX_LCD_UP_PAN_BASE     0x00104010U


// ---------------------------------------------------------------------
// Register LCDLPBASE
// => LCD Lower panel DMA Channel Base Address
//    This is a register to program the lower base address of the frame buffer. The base address is word aligned, hence only
//    the bits 31:2 are used. LCDLPBASE is used for the lower panel of dual panel STN displays.
// => Mode: Mode (r/w)
// ---------------------------------------------------------------------

#define REL_NETX_LCD_LO_PAN_BASE 0x00000014U
#define NETX_LCD_LO_PAN_BASE     0x00104014U


// ---------------------------------------------------------------------
// Register LCDIMSC
// => LCD Interrupt Mask Set/Clear Register
//    The interrupt enable register contains bits, which corresponds directly to those in the interrupt status register.
//    If a bit is set in this register than the colour LCD interrupt bit in the system interrupt controller will be asserted
//    if the corresponding bit is set in the status register.
// => Mode: Mode (r/w)
// ---------------------------------------------------------------------

#define REL_NETX_LCD_INT_MSK_SET_CLR 0x00000018U
#define NETX_LCD_INT_MSK_SET_CLR     0x00104018U

#define MSK_NETX_LCD_INT_MSK_SET_CLR_Unused          0x00000001U // [0]
#define SRT_NETX_LCD_INT_MSK_SET_CLR_Unused          0           
#define MSK_NETX_LCD_INT_MSK_SET_CLR_CLCDFUFINTREN   0x00000002U // [1]
#define SRT_NETX_LCD_INT_MSK_SET_CLR_CLCDFUFINTREN   1           
#define MSK_NETX_LCD_INT_MSK_SET_CLR_CLCDLNBUINTREN  0x00000004U // [2]
#define SRT_NETX_LCD_INT_MSK_SET_CLR_CLCDLNBUINTREN  2           
#define MSK_NETX_LCD_INT_MSK_SET_CLR_CLCDVCOMPINTREN 0x00000008U // [3]
#define SRT_NETX_LCD_INT_MSK_SET_CLR_CLCDVCOMPINTREN 3           
#define MSK_NETX_LCD_INT_MSK_SET_CLR_CLCDMBEINTREN   0x00000010U // [4]
#define SRT_NETX_LCD_INT_MSK_SET_CLR_CLCDMBEINTREN   4           

enum {
	BFW_NETX_LCD_INT_MSK_SET_CLR_Unused          = 1,  // [0]
	BFW_NETX_LCD_INT_MSK_SET_CLR_CLCDFUFINTREN   = 1,  // [1]
	BFW_NETX_LCD_INT_MSK_SET_CLR_CLCDLNBUINTREN  = 1,  // [2]
	BFW_NETX_LCD_INT_MSK_SET_CLR_CLCDVCOMPINTREN = 1,  // [3]
	BFW_NETX_LCD_INT_MSK_SET_CLR_CLCDMBEINTREN   = 1,  // [4]
	BFW_NETX_LCD_INT_MSK_SET_CLR_reserved1       = 27  // [31:5]
};

typedef struct LCDIMSC_BIT_Ttag {
	unsigned int Unused          : BFW_NETX_LCD_INT_MSK_SET_CLR_Unused;          // Unused                                                            
	unsigned int CLCDFUFINTREN   : BFW_NETX_LCD_INT_MSK_SET_CLR_CLCDFUFINTREN;   // DMA FIFO underflow interrupt enable                               
	unsigned int CLCDLNBUINTREN  : BFW_NETX_LCD_INT_MSK_SET_CLR_CLCDLNBUINTREN;  // LCD next address base update interrupt enable                     
	unsigned int CLCDVCOMPINTREN : BFW_NETX_LCD_INT_MSK_SET_CLR_CLCDVCOMPINTREN; // Vertical compare interrupt enable                                 
	unsigned int CLCDMBEINTREN   : BFW_NETX_LCD_INT_MSK_SET_CLR_CLCDMBEINTREN;   // AHB master error interrupt enable                                 
	unsigned int reserved1       : BFW_NETX_LCD_INT_MSK_SET_CLR_reserved1;       // reserved
} LCDIMSC_BIT_T;

typedef union {
	unsigned int  val;
	LCDIMSC_BIT_T bf;
} LCDIMSC_T;


// ---------------------------------------------------------------------
// Register LCDControl
// => LCD Control Register
//    This register controls the mode in which the LCD controller operates.
// => Mode: Mode (r/w)
// ---------------------------------------------------------------------

#define REL_NETX_LCD_CTRL 0x0000001CU
#define NETX_LCD_CTRL     0x0010401CU

#define MSK_NETX_LCD_CTRL_LcdEn     0x00000001U // [0]
#define SRT_NETX_LCD_CTRL_LcdEn     0           
#define MSK_NETX_LCD_CTRL_LcdBpp    0x0000000eU // [3:1]
#define SRT_NETX_LCD_CTRL_LcdBpp    1           
#define MSK_NETX_LCD_CTRL_LcdBW     0x00000010U // [4]
#define SRT_NETX_LCD_CTRL_LcdBW     4           
#define MSK_NETX_LCD_CTRL_LcdTFT    0x00000020U // [5]
#define SRT_NETX_LCD_CTRL_LcdTFT    5           
#define MSK_NETX_LCD_CTRL_LcdMono8  0x00000040U // [6]
#define SRT_NETX_LCD_CTRL_LcdMono8  6           
#define MSK_NETX_LCD_CTRL_LcdDual   0x00000080U // [7]
#define SRT_NETX_LCD_CTRL_LcdDual   7           
#define MSK_NETX_LCD_CTRL_BGR       0x00000100U // [8]
#define SRT_NETX_LCD_CTRL_BGR       8           
#define MSK_NETX_LCD_CTRL_BEBO      0x00000200U // [9]
#define SRT_NETX_LCD_CTRL_BEBO      9           
#define MSK_NETX_LCD_CTRL_BEPO      0x00000400U // [10]
#define SRT_NETX_LCD_CTRL_BEPO      10          
#define MSK_NETX_LCD_CTRL_LcdPwr    0x00000800U // [11]
#define SRT_NETX_LCD_CTRL_LcdPwr    11          
#define MSK_NETX_LCD_CTRL_LcdVComp  0x00003000U // [13:12]
#define SRT_NETX_LCD_CTRL_LcdVComp  12          
#define MSK_NETX_LCD_CTRL_WATERMARK 0x00010000U // [16]
#define SRT_NETX_LCD_CTRL_WATERMARK 16          

enum {
	BFW_NETX_LCD_CTRL_LcdEn     = 1,  // [0]
	BFW_NETX_LCD_CTRL_LcdBpp    = 3,  // [3:1]
	BFW_NETX_LCD_CTRL_LcdBW     = 1,  // [4]
	BFW_NETX_LCD_CTRL_LcdTFT    = 1,  // [5]
	BFW_NETX_LCD_CTRL_LcdMono8  = 1,  // [6]
	BFW_NETX_LCD_CTRL_LcdDual   = 1,  // [7]
	BFW_NETX_LCD_CTRL_BGR       = 1,  // [8]
	BFW_NETX_LCD_CTRL_BEBO      = 1,  // [9]
	BFW_NETX_LCD_CTRL_BEPO      = 1,  // [10]
	BFW_NETX_LCD_CTRL_LcdPwr    = 1,  // [11]
	BFW_NETX_LCD_CTRL_LcdVComp  = 2,  // [13:12]
	BFW_NETX_LCD_CTRL_reserved1 = 2,  // [15:14]
	BFW_NETX_LCD_CTRL_WATERMARK = 1,  // [16]
	BFW_NETX_LCD_CTRL_reserved2 = 15  // [31:17]
};

typedef struct LCDCONTROL_BIT_Ttag {
	unsigned int LcdEn     : BFW_NETX_LCD_CTRL_LcdEn;     // LCD Controller Enable                                                
	                                                        //  0 : LCD Controller disabled
	                                                        //  1 : LCD Controller enabled
	unsigned int LcdBpp    : BFW_NETX_LCD_CTRL_LcdBpp;    // LCD Bits Per Pixel                                                   
	                                                        //  000 :  1 bpp
	                                                        //  001 :  2 bpp
	                                                        //  010 :  4 bpp
	                                                        //  011 :  8 bpp
	                                                        //  100 : 16 bpp
	                                                        //  101 : 24 bpp (This should be only used for TFT panel)
	                                                        //  110 : Reserved
	                                                        //  111 : Reserved
	unsigned int LcdBW     : BFW_NETX_LCD_CTRL_LcdBW;     // STN LCD is monochrome (black and white)                              
	                                                        //  0 : STN is colour
	                                                        //  1 : STN is monochrome
	                                                        //  This bit hs no meaning in TFT mode.
	unsigned int LcdTFT    : BFW_NETX_LCD_CTRL_LcdTFT;    // LCD is TFT                                                           
	                                                        //  0 : LCD is an STN display - use greyscaler
	                                                        //  1 : LCD is TFT - do not use greyscaler
	unsigned int LcdMono8  : BFW_NETX_LCD_CTRL_LcdMono8;  // Monochrome LCD has 8 bit interface                                   
	                                                        // This bit controls whether monochrome STN LCD uses a 4 or 8 bit
	                                                        // parallel interface. It has no meaning in other modes and should
	                                                        // be programmed to zero.
	                                                        //  0 : Mono LCD uses 4 bit interface
	                                                        //  1 : Mono LCD uses 8 bit interface
	unsigned int LcdDual   : BFW_NETX_LCD_CTRL_LcdDual;   // LCD interface is dual panel. This should only be used for STN        
	                                                        // panels, when TFT is 0.
	                                                        //  0 : Single panel LCD is in use
	                                                        //  1 : Dual panel LCD is in use
	unsigned int BGR       : BFW_NETX_LCD_CTRL_BGR;       // Swap red and blue output                                             
	                                                        //  0 : RGB normal output
	                                                        //  1 : BGR red and blue swapped
	unsigned int BEBO      : BFW_NETX_LCD_CTRL_BEBO;      // Big Endian Byte Order                                                
	                                                        //  0 : Little endian byte order
	                                                        //  1 : Big endian byte order
	unsigned int BEPO      : BFW_NETX_LCD_CTRL_BEPO;      // Big endian pixel ordering within a byte                              
	                                                        //  0 : Little endian pixel ordering within a byte
	                                                        //  1 : Big endian pixel ordering within a byte
	unsigned int LcdPwr    : BFW_NETX_LCD_CTRL_LcdPwr;    // LCD power enable                                                     
	                                                        //  0 : LCD is off
	                                                        //  1 : LCD is on when LcdEn=1
	unsigned int LcdVComp  : BFW_NETX_LCD_CTRL_LcdVComp;  // Generate Interrupt at:                                               
	                                                        //  00 : start of Vsync
	                                                        //  01 : start of BACK PORCH
	                                                        //  10 : start of ACTIVE VIDEO
	                                                        //  11 : start of FRONT PORCH
	unsigned int reserved1 : BFW_NETX_LCD_CTRL_reserved1; // reserved
	unsigned int WATERMARK : BFW_NETX_LCD_CTRL_WATERMARK; // LCD DMA FIFO Watermark level                                         
	                                                        //  0 : FIFO Watermark level will be set to 4-words
	                                                        //  1 : FIFO Watermark level will be set to 8-words
	unsigned int reserved2 : BFW_NETX_LCD_CTRL_reserved2; // reserved
} LCDCONTROL_BIT_T;

typedef union {
	unsigned int     val;
	LCDCONTROL_BIT_T bf;
} LCDCONTROL_T;


// ---------------------------------------------------------------------
// Register LCDRIS
// => LCD Raw Interrupt Status Register
//    On a read the register returns five bits that may generate interrupts when set. Write to this register of a
//    bit value of '1' will clear the interrupt corresponding to that bit. Writing a '0' will have no effect.
// => Mode: Mode (r)
// ---------------------------------------------------------------------

#define REL_NETX_LCD_RAW_INT_STAT 0x00000020U
#define NETX_LCD_RAW_INT_STAT     0x00104020U

#define MSK_NETX_LCD_RAW_INT_STAT_Unused      0x00000001U // [0]
#define SRT_NETX_LCD_RAW_INT_STAT_Unused      0           
#define MSK_NETX_LCD_RAW_INT_STAT_FUFSTAT     0x00000002U // [1]
#define SRT_NETX_LCD_RAW_INT_STAT_FUFSTAT     1           
#define MSK_NETX_LCD_RAW_INT_STAT_LNBUSTAT    0x00000004U // [2]
#define SRT_NETX_LCD_RAW_INT_STAT_LNBUSTAT    2           
#define MSK_NETX_LCD_RAW_INT_STAT_VCOMPSTAT   0x00000008U // [3]
#define SRT_NETX_LCD_RAW_INT_STAT_VCOMPSTAT   3           
#define MSK_NETX_LCD_RAW_INT_STAT_MBERRORSTAT 0x00000010U // [4]
#define SRT_NETX_LCD_RAW_INT_STAT_MBERRORSTAT 4           

enum {
	BFW_NETX_LCD_RAW_INT_STAT_Unused      = 1,  // [0]
	BFW_NETX_LCD_RAW_INT_STAT_FUFSTAT     = 1,  // [1]
	BFW_NETX_LCD_RAW_INT_STAT_LNBUSTAT    = 1,  // [2]
	BFW_NETX_LCD_RAW_INT_STAT_VCOMPSTAT   = 1,  // [3]
	BFW_NETX_LCD_RAW_INT_STAT_MBERRORSTAT = 1,  // [4]
	BFW_NETX_LCD_RAW_INT_STAT_reserved1   = 27  // [31:5]
};

typedef struct LCDRIS_BIT_Ttag {
	unsigned int Unused      : BFW_NETX_LCD_RAW_INT_STAT_Unused;      // Unused                                                               
	unsigned int FUFSTAT     : BFW_NETX_LCD_RAW_INT_STAT_FUFSTAT;     // DMA FIFO underflow                                                   
	unsigned int LNBUSTAT    : BFW_NETX_LCD_RAW_INT_STAT_LNBUSTAT;    // LCD next address base update                                         
	unsigned int VCOMPSTAT   : BFW_NETX_LCD_RAW_INT_STAT_VCOMPSTAT;   // Vertical compare                                                     
	unsigned int MBERRORSTAT : BFW_NETX_LCD_RAW_INT_STAT_MBERRORSTAT; // AHB master error status, set to 1 when the AHB master encounters an  
	                                                        // error response from the slave
	unsigned int reserved1   : BFW_NETX_LCD_RAW_INT_STAT_reserved1;   // reserved
} LCDRIS_BIT_T;

typedef union {
	unsigned int val;
	LCDRIS_BIT_T bf;
} LCDRIS_T;


// ---------------------------------------------------------------------
// Register LCDMIS
// => LCD Masked Interrupt Status Register
//    This register is a bit-by-bit logical AND of the LCDStatus register. Interrupt lines corresponding to each
//    interrupt addition to the logical OR of all interrupts are provided to the system interrupt controller.
// => Mode: Mode (r)
// ---------------------------------------------------------------------

#define REL_NETX_LCD_MSK_INT_STAT 0x00000024U
#define NETX_LCD_MSK_INT_STAT     0x00104024U

#define MSK_NETX_LCD_MSK_INT_STAT_Unused          0x00000001U // [0]
#define SRT_NETX_LCD_MSK_INT_STAT_Unused          0           
#define MSK_NETX_LCD_MSK_INT_STAT_CLCDFUFINTR     0x00000002U // [1]
#define SRT_NETX_LCD_MSK_INT_STAT_CLCDFUFINTR     1           
#define MSK_NETX_LCD_MSK_INT_STAT_CLCDLNBUINTR    0x00000004U // [2]
#define SRT_NETX_LCD_MSK_INT_STAT_CLCDLNBUINTR    2           
#define MSK_NETX_LCD_MSK_INT_STAT_CLCDVCOMPINTR   0x00000008U // [3]
#define SRT_NETX_LCD_MSK_INT_STAT_CLCDVCOMPINTR   3           
#define MSK_NETX_LCD_MSK_INT_STAT_CLCDMBERRORINTR 0x00000010U // [4]
#define SRT_NETX_LCD_MSK_INT_STAT_CLCDMBERRORINTR 4           

enum {
	BFW_NETX_LCD_MSK_INT_STAT_Unused          = 1,  // [0]
	BFW_NETX_LCD_MSK_INT_STAT_CLCDFUFINTR     = 1,  // [1]
	BFW_NETX_LCD_MSK_INT_STAT_CLCDLNBUINTR    = 1,  // [2]
	BFW_NETX_LCD_MSK_INT_STAT_CLCDVCOMPINTR   = 1,  // [3]
	BFW_NETX_LCD_MSK_INT_STAT_CLCDMBERRORINTR = 1,  // [4]
	BFW_NETX_LCD_MSK_INT_STAT_reserved1       = 27  // [31:5]
};

typedef struct LCDMIS_BIT_Ttag {
	unsigned int Unused          : BFW_NETX_LCD_MSK_INT_STAT_Unused;          // Unused                                                            
	unsigned int CLCDFUFINTR     : BFW_NETX_LCD_MSK_INT_STAT_CLCDFUFINTR;     // DMA FIFO underflow interrupt                                      
	unsigned int CLCDLNBUINTR    : BFW_NETX_LCD_MSK_INT_STAT_CLCDLNBUINTR;    // LCD next address base update interrupt                            
	unsigned int CLCDVCOMPINTR   : BFW_NETX_LCD_MSK_INT_STAT_CLCDVCOMPINTR;   // Vertical compare interrupt                                        
	unsigned int CLCDMBERRORINTR : BFW_NETX_LCD_MSK_INT_STAT_CLCDMBERRORINTR; // AHB master error interrupt                                        
	unsigned int reserved1       : BFW_NETX_LCD_MSK_INT_STAT_reserved1;       // reserved
} LCDMIS_BIT_T;

typedef union {
	unsigned int val;
	LCDMIS_BIT_T bf;
} LCDMIS_T;


// ---------------------------------------------------------------------
// Register LCDICR
// => LCD Interrupt Clear Register
//    The LCDICR is a write only register. Writing logic 1 to the relevant bit clears the corresponding interrupt.
// => Mode: Mode (w)
// ---------------------------------------------------------------------

#define REL_NETX_LCD_INT_CLR 0x00000028U
#define NETX_LCD_INT_CLR     0x00104028U

#define MSK_NETX_LCD_INT_CLR_Unused  0x00000001U // [0]
#define SRT_NETX_LCD_INT_CLR_Unused  0           
#define MSK_NETX_LCD_INT_CLR_FUF     0x00000002U // [1]
#define SRT_NETX_LCD_INT_CLR_FUF     1           
#define MSK_NETX_LCD_INT_CLR_LNBU    0x00000004U // [2]
#define SRT_NETX_LCD_INT_CLR_LNBU    2           
#define MSK_NETX_LCD_INT_CLR_VCOMP   0x00000008U // [3]
#define SRT_NETX_LCD_INT_CLR_VCOMP   3           
#define MSK_NETX_LCD_INT_CLR_MBERROR 0x00000010U // [4]
#define SRT_NETX_LCD_INT_CLR_MBERROR 4           

enum {
	BFW_NETX_LCD_INT_CLR_Unused    = 1,  // [0]
	BFW_NETX_LCD_INT_CLR_FUF       = 1,  // [1]
	BFW_NETX_LCD_INT_CLR_LNBU      = 1,  // [2]
	BFW_NETX_LCD_INT_CLR_VCOMP     = 1,  // [3]
	BFW_NETX_LCD_INT_CLR_MBERROR   = 1,  // [4]
	BFW_NETX_LCD_INT_CLR_reserved1 = 27  // [31:5]
};

typedef struct LCDICR_BIT_Ttag {
	unsigned int Unused    : BFW_NETX_LCD_INT_CLR_Unused;    // Unused                                                              
	unsigned int FUF       : BFW_NETX_LCD_INT_CLR_FUF;       // Clear DMA FIFO underflow interrupt                                  
	unsigned int LNBU      : BFW_NETX_LCD_INT_CLR_LNBU;      // Clear LCD next address base update interrupt                        
	unsigned int VCOMP     : BFW_NETX_LCD_INT_CLR_VCOMP;     // Clear Vertical compare interrupt                                    
	unsigned int MBERROR   : BFW_NETX_LCD_INT_CLR_MBERROR;   // Clear AHB master error interrupt                                    
	unsigned int reserved1 : BFW_NETX_LCD_INT_CLR_reserved1; // reserved
} LCDICR_BIT_T;

typedef union {
	unsigned int val;
	LCDICR_BIT_T bf;
} LCDICR_T;


// ---------------------------------------------------------------------
// Register LCDUPCURR
// => LCD Upper panel DMA Channel Current Address
//    This register contains the current DMA address for display data read of TFT, single panel STN and upper panel
//    of dual STN displays.
//    This register's value may change at any moment, and is not normally read from, but can be read to determine
//    the approximate position within the buffer, or for test.
// => Mode: Mode (r)
// ---------------------------------------------------------------------

#define REL_NETX_LCD_UP_PAN_CUR 0x0000002CU
#define NETX_LCD_UP_PAN_CUR     0x0010402CU

#define MSK_NETX_LCD_UP_PAN_CUR_LCDUPCURR 0xffffffffU // [31:0]
#define SRT_NETX_LCD_UP_PAN_CUR_LCDUPCURR 0           

enum {
	BFW_NETX_LCD_UP_PAN_CUR_LCDUPCURR = 32  // [31:0]
};

typedef struct LCDUPCURR_BIT_Ttag {
	unsigned int LCDUPCURR : BFW_NETX_LCD_UP_PAN_CUR_LCDUPCURR; // Upper panel address                                                  
} LCDUPCURR_BIT_T;

typedef union {
	unsigned int    val;
	LCDUPCURR_BIT_T bf;
} LCDUPCURR_T;


// ---------------------------------------------------------------------
// Register LCDLPCURR
// => LCD Lower panel DMA Channel Current Address
//    This register contains the current DMA address for display data read of the lower panel of dual STN displays.
//    This register's value may change at any moment, and is not normally read from, but can be read to determine
//    the approximate position within the buffer, or for test.
// => Mode: Mode (r)
// ---------------------------------------------------------------------

#define REL_NETX_LCD_LO_PAN_CUR 0x00000030U
#define NETX_LCD_LO_PAN_CUR     0x00104030U

#define MSK_NETX_LCD_LO_PAN_CUR_LCDLPCURR 0xffffffffU // [31:0]
#define SRT_NETX_LCD_LO_PAN_CUR_LCDLPCURR 0           

enum {
	BFW_NETX_LCD_LO_PAN_CUR_LCDLPCURR = 32  // [31:0]
};

typedef struct LCDLPCURR_BIT_Ttag {
	unsigned int LCDLPCURR : BFW_NETX_LCD_LO_PAN_CUR_LCDLPCURR; // Lower panel address                                                  
} LCDLPCURR_BIT_T;

typedef union {
	unsigned int    val;
	LCDLPCURR_BIT_T bf;
} LCDLPCURR_T;


// ---------------------------------------------------------------------
// Register LCDPaletteStart
// => 256 main palette entries organised as 128 locations x two entries per word
// => Mode: Mode (r/w)
// ---------------------------------------------------------------------

#define REL_NETX_LCD_PALETTE_BASE 0x00000200U
#define NETX_LCD_PALETTE_BASE     0x00104200U

#define MSK_NETX_LCD_PALETTE_BASE_LCDPalette 0xffffffffU // [31:0]
#define SRT_NETX_LCD_PALETTE_BASE_LCDPalette 0           

enum {
	BFW_NETX_LCD_PALETTE_BASE_LCDPalette = 32  // [31:0]
};

typedef struct LCDPALETTESTART_BIT_Ttag {
	unsigned int LCDPalette : BFW_NETX_LCD_PALETTE_BASE_LCDPalette; // 256 main palette entries organised as 128 locations x two           
	                                                        // entries per word
} LCDPALETTESTART_BIT_T;

typedef union {
	unsigned int          val;
	LCDPALETTESTART_BIT_T bf;
} LCDPALETTESTART_T;


// ---------------------------------------------------------------------
// Register LCDPaletteEnd
// => 
// => Mode: Mode (r/w)
// ---------------------------------------------------------------------

#define REL_NETX_LCD_PALETTE_END 0x000003FCU
#define NETX_LCD_PALETTE_END     0x001043FCU

#define MSK_NETX_LCD_PALETTE_END_LCDPalette 0xffffffffU // [31:0]
#define SRT_NETX_LCD_PALETTE_END_LCDPalette 0           

enum {
	BFW_NETX_LCD_PALETTE_END_LCDPalette = 32  // [31:0]
};

typedef struct LCDPALETTEEND_BIT_Ttag {
	unsigned int LCDPalette : BFW_NETX_LCD_PALETTE_END_LCDPalette; //                                                                     
} LCDPALETTEEND_BIT_T;

typedef union {
	unsigned int        val;
	LCDPALETTEEND_BIT_T bf;
} LCDPALETTEEND_T;


// ---------------------------------------------------------------------
// Register DMAFIFOStart
// => Test mode. LCD DMA FIFO Access path. Upper and lower FIFOs cascaded.
// => Mode: Mode (r/w)
// ---------------------------------------------------------------------

#define REL_NETX_LCD_DMA_FIFO_BASE 0x00000400U
#define NETX_LCD_DMA_FIFO_BASE     0x00104400U

#define MSK_NETX_LCD_DMA_FIFO_BASE 0xffffffffU // [31:0]
#define SRT_NETX_LCD_DMA_FIFO_BASE 0           

enum {
	BFW_NETX_LCD_DMA_FIFO_BASE = 32  // [31:0]
};

typedef struct DMAFIFOSTART_BIT_Ttag {
	unsigned int LCDDMAFIFO : BFW_NETX_LCD_DMA_FIFO_BASE; // LCD DMA FIFO Access path. Upper and lower FIFOs cascaded.           
} DMAFIFOSTART_BIT_T;

typedef union {
	unsigned int       val;
	DMAFIFOSTART_BIT_T bf;
} DMAFIFOSTART_T;


// ---------------------------------------------------------------------
// Register DMAFIFOEnd
// => 
// => Mode: Mode (r/w)
// ---------------------------------------------------------------------

#define REL_NETX_LCD_DMA_FIFO_END 0x000007FCU
#define NETX_LCD_DMA_FIFO_END     0x001047FCU

#define MSK_NETX_LCD_DMA_FIFO_END 0xffffffffU // [31:0]
#define SRT_NETX_LCD_DMA_FIFO_END 0           

enum {
	BFW_NETX_LCD_DMA_FIFO_END = 32  // [31:0]
};

typedef struct DMAFIFOEND_BIT_Ttag {
	unsigned int LCDDMAFIFO : BFW_NETX_LCD_DMA_FIFO_END; //                                                                     
} DMAFIFOEND_BIT_T;

typedef union {
	unsigned int     val;
	DMAFIFOEND_BIT_T bf;
} DMAFIFOEND_T;


// ---------------------------------------------------------------------
// Register CLCDPERIPHID0
// => Peripheral Identification register 0
//    The CLCDPERIPHID0 Register is hard-coded and the fields in the register determine the reset value.
// => Mode: Mode (r)
// ---------------------------------------------------------------------

#define REL_NETX_CLCD_PERIPH_ID0 0x00000FE0U
#define NETX_CLCD_PERIPH_ID0     0x00104FE0U

#define MSK_NETX_CLCD_PERIPH_ID0_PartNumber0 0x000000ffU // [7:0]
#define SRT_NETX_CLCD_PERIPH_ID0_PartNumber0 0           

enum {
	BFW_NETX_CLCD_PERIPH_ID0_PartNumber0 = 8,  // [7:0]
	BFW_NETX_CLCD_PERIPH_ID0_reserved1   = 24  // [31:8]
};

typedef struct CLCDPERIPHID0_BIT_Ttag {
	unsigned int PartNumber0 : BFW_NETX_CLCD_PERIPH_ID0_PartNumber0; // These bits read back as 0x10                                         
	unsigned int reserved1   : BFW_NETX_CLCD_PERIPH_ID0_reserved1;   // reserved
} CLCDPERIPHID0_BIT_T;

typedef union {
	unsigned int        val;
	CLCDPERIPHID0_BIT_T bf;
} CLCDPERIPHID0_T;


// ---------------------------------------------------------------------
// Register CLCDPERIPHID1
// => Peripheral Identification register 1
//    The CLCDPERIPHID1 Register is hard-coded and the fields in the register determine the reset value.
// => Mode: Mode (r)
// ---------------------------------------------------------------------

#define REL_NETX_CLCD_PERIPH_ID1 0x00000FE4U
#define NETX_CLCD_PERIPH_ID1     0x00104FE4U

#define MSK_NETX_CLCD_PERIPH_ID1_PartNumber1 0x0000000fU // [3:0]
#define SRT_NETX_CLCD_PERIPH_ID1_PartNumber1 0           
#define MSK_NETX_CLCD_PERIPH_ID1_Designer0   0x000000f0U // [7:4]
#define SRT_NETX_CLCD_PERIPH_ID1_Designer0   4           

enum {
	BFW_NETX_CLCD_PERIPH_ID1_PartNumber1 = 4,  // [3:0]
	BFW_NETX_CLCD_PERIPH_ID1_Designer0   = 4,  // [7:4]
	BFW_NETX_CLCD_PERIPH_ID1_reserved1   = 24  // [31:8]
};

typedef struct CLCDPERIPHID1_BIT_Ttag {
	unsigned int PartNumber1 : BFW_NETX_CLCD_PERIPH_ID1_PartNumber1; // These bits read back as 0x1                                          
	unsigned int Designer0   : BFW_NETX_CLCD_PERIPH_ID1_Designer0;   // These bits read back as 0x1                                          
	unsigned int reserved1   : BFW_NETX_CLCD_PERIPH_ID1_reserved1;   // reserved
} CLCDPERIPHID1_BIT_T;

typedef union {
	unsigned int        val;
	CLCDPERIPHID1_BIT_T bf;
} CLCDPERIPHID1_T;


// ---------------------------------------------------------------------
// Register CLCDPERIPHID2
// => Peripheral Identification register 2
//    The CLCDPERIPHID2 Register is hard-coded and the fields in the register determine the reset value.
// => Mode: Mode (r)
// ---------------------------------------------------------------------

#define REL_NETX_CLCD_PERIPH_ID2 0x00000FE8U
#define NETX_CLCD_PERIPH_ID2     0x00104FE8U

#define MSK_NETX_CLCD_PERIPH_ID2_Designer1 0x0000000fU // [3:0]
#define SRT_NETX_CLCD_PERIPH_ID2_Designer1 0           
#define MSK_NETX_CLCD_PERIPH_ID2_Revision  0x000000f0U // [7:4]
#define SRT_NETX_CLCD_PERIPH_ID2_Revision  4           

enum {
	BFW_NETX_CLCD_PERIPH_ID2_Designer1 = 4,  // [3:0]
	BFW_NETX_CLCD_PERIPH_ID2_Revision  = 4,  // [7:4]
	BFW_NETX_CLCD_PERIPH_ID2_reserved1 = 24  // [31:8]
};

typedef struct CLCDPERIPHID2_BIT_Ttag {
	unsigned int Designer1 : BFW_NETX_CLCD_PERIPH_ID2_Designer1; // These bits read back as 0x4                                          
	unsigned int Revision  : BFW_NETX_CLCD_PERIPH_ID2_Revision;  // These bits read back as 0x0                                          
	unsigned int reserved1 : BFW_NETX_CLCD_PERIPH_ID2_reserved1; // reserved
} CLCDPERIPHID2_BIT_T;

typedef union {
	unsigned int        val;
	CLCDPERIPHID2_BIT_T bf;
} CLCDPERIPHID2_T;


// ---------------------------------------------------------------------
// Register CLCDPERIPHID3
// => Peripheral Identification register 3
//    The CLCDPERIPHID3 Register is hard-coded and the fields in the register determine the reset value.
// => Mode: Mode (r)
// ---------------------------------------------------------------------

#define REL_NETX_CLCD_PERIPH_ID3 0x00000FECU
#define NETX_CLCD_PERIPH_ID3     0x00104FECU

#define MSK_NETX_CLCD_PERIPH_ID3_Configuration 0x000000ffU // [7:0]
#define SRT_NETX_CLCD_PERIPH_ID3_Configuration 0           

enum {
	BFW_NETX_CLCD_PERIPH_ID3_Configuration = 8,  // [7:0]
	BFW_NETX_CLCD_PERIPH_ID3_reserved1     = 24  // [31:8]
};

typedef struct CLCDPERIPHID3_BIT_Ttag {
	unsigned int Configuration : BFW_NETX_CLCD_PERIPH_ID3_Configuration; // These bits read back as 0x0                                         
	unsigned int reserved1     : BFW_NETX_CLCD_PERIPH_ID3_reserved1;     // reserved
} CLCDPERIPHID3_BIT_T;

typedef union {
	unsigned int        val;
	CLCDPERIPHID3_BIT_T bf;
} CLCDPERIPHID3_T;


// ---------------------------------------------------------------------
// Register CLCDPCELLID0
// => Primecell Identification register 0
//    The CLCDPCELLID0 Register is hard-coded and the fields in the register determine the reset value.
// => Mode: Mode (r)
// ---------------------------------------------------------------------

#define REL_NETX_CLCD_PRIME_CELL_ID0 0x00000FF0U
#define NETX_CLCD_PRIME_CELL_ID0     0x00104FF0U

#define MSK_NETX_CLCD_PRIME_CELL_ID0_PCELLIDID0 0x000000ffU // [7:0]
#define SRT_NETX_CLCD_PRIME_CELL_ID0_PCELLIDID0 0           

enum {
	BFW_NETX_CLCD_PRIME_CELL_ID0_PCELLIDID0 = 8,  // [7:0]
	BFW_NETX_CLCD_PRIME_CELL_ID0_reserved1  = 24  // [31:8]
};

typedef struct CLCDPCELLID0_BIT_Ttag {
	unsigned int PCELLIDID0 : BFW_NETX_CLCD_PRIME_CELL_ID0_PCELLIDID0; // These bits read back as 0x0D                                        
	unsigned int reserved1  : BFW_NETX_CLCD_PRIME_CELL_ID0_reserved1;  // reserved
} CLCDPCELLID0_BIT_T;

typedef union {
	unsigned int       val;
	CLCDPCELLID0_BIT_T bf;
} CLCDPCELLID0_T;


// ---------------------------------------------------------------------
// Register CLCDPCELLID1
// => Primecell Identification register 1
//    The CLCDPCELLID1 Register is hard-coded and the fields in the register determine the reset value.
// => Mode: Mode (r)
// ---------------------------------------------------------------------

#define REL_NETX_CLCD_PRIME_CELL_ID1 0x00000FF4U
#define NETX_CLCD_PRIME_CELL_ID1     0x00104FF4U

#define MSK_NETX_CLCD_PRIME_CELL_ID1_PCELLIDID1 0x000000ffU // [7:0]
#define SRT_NETX_CLCD_PRIME_CELL_ID1_PCELLIDID1 0           

enum {
	BFW_NETX_CLCD_PRIME_CELL_ID1_PCELLIDID1 = 8,  // [7:0]
	BFW_NETX_CLCD_PRIME_CELL_ID1_reserved1  = 24  // [31:8]
};

typedef struct CLCDPCELLID1_BIT_Ttag {
	unsigned int PCELLIDID1 : BFW_NETX_CLCD_PRIME_CELL_ID1_PCELLIDID1; // These bits read back as 0xF0                                        
	unsigned int reserved1  : BFW_NETX_CLCD_PRIME_CELL_ID1_reserved1;  // reserved
} CLCDPCELLID1_BIT_T;

typedef union {
	unsigned int       val;
	CLCDPCELLID1_BIT_T bf;
} CLCDPCELLID1_T;


// ---------------------------------------------------------------------
// Register CLCDPCELLID2
// => Primecell Identification register 2
//    The CLCDPCELLID2 Register is hard-coded and the fields in the register determine the reset value.
// => Mode: Mode (r)
// ---------------------------------------------------------------------

#define REL_NETX_CLCD_PRIME_CELL_ID2 0x00000FF8U
#define NETX_CLCD_PRIME_CELL_ID2     0x00104FF8U

#define MSK_NETX_CLCD_PRIME_CELL_ID2_PCELLIDID2 0x000000ffU // [7:0]
#define SRT_NETX_CLCD_PRIME_CELL_ID2_PCELLIDID2 0           

enum {
	BFW_NETX_CLCD_PRIME_CELL_ID2_PCELLIDID2 = 8,  // [7:0]
	BFW_NETX_CLCD_PRIME_CELL_ID2_reserved1  = 24  // [31:8]
};

typedef struct CLCDPCELLID2_BIT_Ttag {
	unsigned int PCELLIDID2 : BFW_NETX_CLCD_PRIME_CELL_ID2_PCELLIDID2; // These bits read back as 0x05                                        
	unsigned int reserved1  : BFW_NETX_CLCD_PRIME_CELL_ID2_reserved1;  // reserved
} CLCDPCELLID2_BIT_T;

typedef union {
	unsigned int       val;
	CLCDPCELLID2_BIT_T bf;
} CLCDPCELLID2_T;


// ---------------------------------------------------------------------
// Register CLCDPCELLID3
// => Primecell Identification register 3
//    The CLCDPCELLID3 Register is hard-coded and the fields in the register determine the reset value.
// => Mode: Mode (r)
// ---------------------------------------------------------------------

#define REL_NETX_CLCD_PRIME_CELL_ID3 0x00000FFCU
#define NETX_CLCD_PRIME_CELL_ID3     0x00104FFCU

#define MSK_NETX_CLCD_PRIME_CELL_ID3_PCELLIDID3 0x000000ffU // [7:0]
#define SRT_NETX_CLCD_PRIME_CELL_ID3_PCELLIDID3 0           

enum {
	BFW_NETX_CLCD_PRIME_CELL_ID3_PCELLIDID3 = 8,  // [7:0]
	BFW_NETX_CLCD_PRIME_CELL_ID3_reserved1  = 24  // [31:8]
};

typedef struct CLCDPCELLID3_BIT_Ttag {
	unsigned int PCELLIDID3 : BFW_NETX_CLCD_PRIME_CELL_ID3_PCELLIDID3; // These bits read back as 0xb1                                        
	unsigned int reserved1  : BFW_NETX_CLCD_PRIME_CELL_ID3_reserved1;  // reserved
} CLCDPCELLID3_BIT_T;

typedef union {
	unsigned int       val;
	CLCDPCELLID3_BIT_T bf;
} CLCDPCELLID3_T;


/*************************************************************************************/

#endif /* _LCD_H */
