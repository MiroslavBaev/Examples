/******************************************************************************

  Copyright (C) 2010 [Hilscher Gesellschaft für Systemautomation mbH]

  This program can be used by everyone according to the netX Open Source
  Software license. The license agreement can be downloaded from
  http://www.industrialNETworX.com

*******************************************************************************

  Last Modification:
    @version $Id: SysFunc.h 333 2010-04-26 09:32:25Z Volker $

  Description:
    netX SYSFUNC definitions

  Changes:
    Date        Author        Description
  ---------------------------------------------------------------------------
    2010-03-24  NC            File created.

******************************************************************************/


#ifndef _SYSFUNC_H
#define _SYSFUNC_H


/*************************************************************************************/


// =====================================================================
//
// Area of asic_ctrl
//
// =====================================================================

#define NETX_CTRL_AREA	0x00100000U


// ---------------------------------------------------------------------
// Register io_status
// => IO bondout status registers
// => Mode: Mode (r)
// ---------------------------------------------------------------------

#define REL_NETX_BOO_STAT 0x00000000U
#define NETX_BOO_STAT     0x00100000U

#define MSK_NETX_BOO_STAT_bond_option0 0x00000001U // [0]
#define SRT_NETX_BOO_STAT_bond_option0 0           
#define MSK_NETX_BOO_STAT_bond_option1 0x00000002U // [1]
#define SRT_NETX_BOO_STAT_bond_option1 1           
#define MSK_NETX_BOO_STAT_bond_option2 0x00000004U // [2]
#define SRT_NETX_BOO_STAT_bond_option2 2           
#define MSK_NETX_BOO_STAT_quick_count  0x00000008U // [3]
#define SRT_NETX_BOO_STAT_quick_count  3           
#define MSK_NETX_BOO_STAT_arm100       0x00000010U // [4]
#define SRT_NETX_BOO_STAT_arm100       4           
#define MSK_NETX_BOO_STAT_pll_bypass   0x00000020U // [5]
#define SRT_NETX_BOO_STAT_pll_bypass   5           

enum {
	BFW_NETX_BOO_STAT_bond_option0 = 1,  // [0]
	BFW_NETX_BOO_STAT_bond_option1 = 1,  // [1]
	BFW_NETX_BOO_STAT_bond_option2 = 1,  // [2]
	BFW_NETX_BOO_STAT_quick_count  = 1,  // [3]
	BFW_NETX_BOO_STAT_arm100       = 1,  // [4]
	BFW_NETX_BOO_STAT_pll_bypass   = 1,  // [5]
	BFW_NETX_BOO_STAT_reserved1    = 26  // [31:6]
};

typedef struct IO_STATUS_BIT_Ttag {
	unsigned int bond_option0 : BFW_NETX_BOO_STAT_bond_option0; // Value of Bond-Option Pin0
	unsigned int bond_option1 : BFW_NETX_BOO_STAT_bond_option1; // Value of Bond-Option Pin1
	unsigned int bond_option2 : BFW_NETX_BOO_STAT_bond_option2; // Value of Bond-Option Pin2
	unsigned int quick_count  : BFW_NETX_BOO_STAT_quick_count;  // Testmode 'quick_count' is activated by external pins
	                                                        // -> diverse internal counters count faster (RTC-clock-divider, PLL-stby-controller,...)
	unsigned int arm100       : BFW_NETX_BOO_STAT_arm100;       // Testmode 'arm100' is activated by external pins
	                                                        // -> ARM926 runs on system frequency (100MHz) instead of double system frequency (200MHz)
	unsigned int pll_bypass   : BFW_NETX_BOO_STAT_pll_bypass;   // Testmode 'pll_bypass' is activated by external pins
	                                                        // -> 400MHz-PLL is bypassed, PLL output is directly connected to XTALIN
	unsigned int reserved1    : BFW_NETX_BOO_STAT_reserved1;    // reserved
} IO_STATUS_BIT_T;

typedef union {
	unsigned int    val;
	IO_STATUS_BIT_T bf;
} IO_STATUS_T;


// ---------------------------------------------------------------------
// Register io_config
// => IO config registers
//    Selects of output pin multiplexing.
//    See Excel pinning sheet for details.
//    Selects can only be activated, if appropriate bit of io_config_mask is set.
//    Bits will be reset according to the io_config_mask-register register if a new mask is correctly written (netX locking algorithm).
//    Changing this register is only possible by the following sequence:
//    1.: read out access key
//    2.: write back access key
//    3.: write desired value to this register
// => Mode: Mode (r/w)
// ---------------------------------------------------------------------

#define REL_NETX_IO_CFG 0x00000004U
#define NETX_IO_CFG     0x00100004U

#define MSK_NETX_IO_CFG_sel_lcd_bw       0x00000001U // [0]
#define SRT_NETX_IO_CFG_sel_lcd_bw       0           
#define MSK_NETX_IO_CFG_sel_lcd_col      0x00000002U // [1]
#define SRT_NETX_IO_CFG_sel_lcd_col      1           
#define MSK_NETX_IO_CFG_sel_mii2         0x00000004U // [2]
#define SRT_NETX_IO_CFG_sel_mii2         2           
#define MSK_NETX_IO_CFG_sel_mii3         0x00000008U // [3]
#define SRT_NETX_IO_CFG_sel_mii3         3           
#define MSK_NETX_IO_CFG_sel_mii23        0x00000010U // [4]
#define SRT_NETX_IO_CFG_sel_mii23        4           
#define MSK_NETX_IO_CFG_sel_mii3pwm      0x00000020U // [5]
#define SRT_NETX_IO_CFG_sel_mii3pwm      5           
#define MSK_NETX_IO_CFG_sel_fo0          0x00000040U // [6]
#define SRT_NETX_IO_CFG_sel_fo0          6           
#define MSK_NETX_IO_CFG_sel_fo1          0x00000080U // [7]
#define SRT_NETX_IO_CFG_sel_fo1          7           
#define MSK_NETX_IO_CFG_sel_f0_pwm3      0x00000100U // [8]
#define SRT_NETX_IO_CFG_sel_f0_pwm3      8           
#define MSK_NETX_IO_CFG_sel_f0_failure3  0x00000200U // [9]
#define SRT_NETX_IO_CFG_sel_f0_failure3  9           
#define MSK_NETX_IO_CFG_sel_f1_pwm3      0x00000400U // [10]
#define SRT_NETX_IO_CFG_sel_f1_pwm3      10          
#define MSK_NETX_IO_CFG_sel_f1_rpwm3     0x00000800U // [11]
#define SRT_NETX_IO_CFG_sel_f1_rpwm3     11          
#define MSK_NETX_IO_CFG_sel_f2_failure3  0x00001000U // [12]
#define SRT_NETX_IO_CFG_sel_f2_failure3  12          
#define MSK_NETX_IO_CFG_sel_f2_rpwm3     0x00002000U // [13]
#define SRT_NETX_IO_CFG_sel_f2_rpwm3     13          
#define MSK_NETX_IO_CFG_sel_f3_pwm3      0x00004000U // [14]
#define SRT_NETX_IO_CFG_sel_f3_pwm3      14          
#define MSK_NETX_IO_CFG_sel_e_pwm2       0x00008000U // [15]
#define SRT_NETX_IO_CFG_sel_e_pwm2       15          
#define MSK_NETX_IO_CFG_sel_e_failure2   0x00010000U // [16]
#define SRT_NETX_IO_CFG_sel_e_failure2   16          
#define MSK_NETX_IO_CFG_sel_e_rpwm2      0x00020000U // [17]
#define SRT_NETX_IO_CFG_sel_e_rpwm2      17          
#define MSK_NETX_IO_CFG_sel_enc0         0x00040000U // [18]
#define SRT_NETX_IO_CFG_sel_enc0         18          
#define MSK_NETX_IO_CFG_sel_enc1         0x00080000U // [19]
#define SRT_NETX_IO_CFG_sel_enc1         19          
#define MSK_NETX_IO_CFG_sel_mp           0x00100000U // [20]
#define SRT_NETX_IO_CFG_sel_mp           20          
#define MSK_NETX_IO_CFG_sel_led_mii2     0x00200000U // [21]
#define SRT_NETX_IO_CFG_sel_led_mii2     21          
#define MSK_NETX_IO_CFG_sel_led_mii3     0x00400000U // [22]
#define SRT_NETX_IO_CFG_sel_led_mii3     22          
#define MSK_NETX_IO_CFG_sel_etm          0x00800000U // [23]
#define SRT_NETX_IO_CFG_sel_etm          23          
#define MSK_NETX_IO_CFG_sel_wdg          0x01000000U // [24]
#define SRT_NETX_IO_CFG_sel_wdg          24          
#define MSK_NETX_IO_CFG_sel_f0_pwm3_eclk 0x02000000U // [25]
#define SRT_NETX_IO_CFG_sel_f0_pwm3_eclk 25          
#define MSK_NETX_IO_CFG_sel_f1_pwm3_eclk 0x04000000U // [26]
#define SRT_NETX_IO_CFG_sel_f1_pwm3_eclk 26          
#define MSK_NETX_IO_CFG_sel_f3_pwm3_eclk 0x08000000U // [27]
#define SRT_NETX_IO_CFG_sel_f3_pwm3_eclk 27          
#define MSK_NETX_IO_CFG_sel_e_pwm2_eclk  0x10000000U // [28]
#define SRT_NETX_IO_CFG_sel_e_pwm2_eclk  28          
#define MSK_NETX_IO_CFG_if_select_n      0x80000000U // [31]
#define SRT_NETX_IO_CFG_if_select_n      31          

enum {
	BFW_NETX_IO_CFG_sel_lcd_bw       = 1, // [0]
	BFW_NETX_IO_CFG_sel_lcd_col      = 1, // [1]
	BFW_NETX_IO_CFG_sel_mii2         = 1, // [2]
	BFW_NETX_IO_CFG_sel_mii3         = 1, // [3]
	BFW_NETX_IO_CFG_sel_mii23        = 1, // [4]
	BFW_NETX_IO_CFG_sel_mii3pwm      = 1, // [5]
	BFW_NETX_IO_CFG_sel_fo0          = 1, // [6]
	BFW_NETX_IO_CFG_sel_fo1          = 1, // [7]
	BFW_NETX_IO_CFG_sel_f0_pwm3      = 1, // [8]
	BFW_NETX_IO_CFG_sel_f0_failure3  = 1, // [9]
	BFW_NETX_IO_CFG_sel_f1_pwm3      = 1, // [10]
	BFW_NETX_IO_CFG_sel_f1_rpwm3     = 1, // [11]
	BFW_NETX_IO_CFG_sel_f2_failure3  = 1, // [12]
	BFW_NETX_IO_CFG_sel_f2_rpwm3     = 1, // [13]
	BFW_NETX_IO_CFG_sel_f3_pwm3      = 1, // [14]
	BFW_NETX_IO_CFG_sel_e_pwm2       = 1, // [15]
	BFW_NETX_IO_CFG_sel_e_failure2   = 1, // [16]
	BFW_NETX_IO_CFG_sel_e_rpwm2      = 1, // [17]
	BFW_NETX_IO_CFG_sel_enc0         = 1, // [18]
	BFW_NETX_IO_CFG_sel_enc1         = 1, // [19]
	BFW_NETX_IO_CFG_sel_mp           = 1, // [20]
	BFW_NETX_IO_CFG_sel_led_mii2     = 1, // [21]
	BFW_NETX_IO_CFG_sel_led_mii3     = 1, // [22]
	BFW_NETX_IO_CFG_sel_etm          = 1, // [23]
	BFW_NETX_IO_CFG_sel_wdg          = 1, // [24]
	BFW_NETX_IO_CFG_sel_f0_pwm3_eclk = 1, // [25]
	BFW_NETX_IO_CFG_sel_f1_pwm3_eclk = 1, // [26]
	BFW_NETX_IO_CFG_sel_f3_pwm3_eclk = 1, // [27]
	BFW_NETX_IO_CFG_sel_e_pwm2_eclk  = 1, // [28]
	BFW_NETX_IO_CFG_reserved1        = 2, // [30:29]
	BFW_NETX_IO_CFG_if_select_n      = 1  // [31]
};

typedef struct IO_CONFIG_BIT_Ttag {
	unsigned int sel_lcd_bw       : BFW_NETX_IO_CFG_sel_lcd_bw;       // select outputs for Black and White LCD Display 
	unsigned int sel_lcd_col      : BFW_NETX_IO_CFG_sel_lcd_col;      // select outputs for Couloured LCD Display 
	unsigned int sel_mii2         : BFW_NETX_IO_CFG_sel_mii2;         // select outputs for MII interface of xMAC2 
	unsigned int sel_mii3         : BFW_NETX_IO_CFG_sel_mii3;         // select outputs for MII interface of xMAC2 
	unsigned int sel_mii23        : BFW_NETX_IO_CFG_sel_mii23;        // select outputs for MDIO signals 
	unsigned int sel_mii3pwm      : BFW_NETX_IO_CFG_sel_mii3pwm;      // select outputs for PWM output of xMAC3 
	unsigned int sel_fo0          : BFW_NETX_IO_CFG_sel_fo0;          // select outputs for Fiber Optics of Phy0 
	unsigned int sel_fo1          : BFW_NETX_IO_CFG_sel_fo1;          // select outputs for Fiber Optics of Phy1 
	unsigned int sel_f0_pwm3      : BFW_NETX_IO_CFG_sel_f0_pwm3;      // select outputs for PWM-siganls at Fieldbus0 pads 
	unsigned int sel_f0_failure3  : BFW_NETX_IO_CFG_sel_f0_failure3;  // select output  for PWM-failure at Fieldbus0 pads 
	unsigned int sel_f1_pwm3      : BFW_NETX_IO_CFG_sel_f1_pwm3;      // select outputs for PWM-signals at Fieldbus1 pads 
	unsigned int sel_f1_rpwm3     : BFW_NETX_IO_CFG_sel_f1_rpwm3;     // select output  for rpwm signal at Fieldbus1 pads 
	unsigned int sel_f2_failure3  : BFW_NETX_IO_CFG_sel_f2_failure3;  // select output  for PWM-failure at Fieldbus2 pads 
	unsigned int sel_f2_rpwm3     : BFW_NETX_IO_CFG_sel_f2_rpwm3;     // select output  for rpwm signal at Fieldbus2 pads 
	unsigned int sel_f3_pwm3      : BFW_NETX_IO_CFG_sel_f3_pwm3;      // select outputs for PWM-signals at Fieldbus3 pads 
	unsigned int sel_e_pwm2       : BFW_NETX_IO_CFG_sel_e_pwm2;       // select outputs for PWM-signals at PIO pads 
	unsigned int sel_e_failure2   : BFW_NETX_IO_CFG_sel_e_failure2;   // select output  for PWM-failure at PIO pads 
	unsigned int sel_e_rpwm2      : BFW_NETX_IO_CFG_sel_e_rpwm2;      // select output  for rpwm signal at PIO pads 
	unsigned int sel_enc0         : BFW_NETX_IO_CFG_sel_enc0;         // select outputs for enc0 
	unsigned int sel_enc1         : BFW_NETX_IO_CFG_sel_enc1;         // select outputs for enc1 
	unsigned int sel_mp           : BFW_NETX_IO_CFG_sel_mp;           // select outputs for mp 
	unsigned int sel_led_mii2     : BFW_NETX_IO_CFG_sel_led_mii2;     // select inputs for leds of mii2 
	unsigned int sel_led_mii3     : BFW_NETX_IO_CFG_sel_led_mii3;     // select inputs for leds of mii3 
	unsigned int sel_etm          : BFW_NETX_IO_CFG_sel_etm;          // select pins for ETM9 of ARM926 
	unsigned int sel_wdg          : BFW_NETX_IO_CFG_sel_wdg;          // select pins for clk watchdoq / system watchdog 
	unsigned int sel_f0_pwm3_eclk : BFW_NETX_IO_CFG_sel_f0_pwm3_eclk; // select outputs for PWM-siganls clocked by xmac3_eclk_in at Fieldbus0 pads 
	                                                        // usually used for xmac3 fiber-optic mode with low clock jitter
	unsigned int sel_f1_pwm3_eclk : BFW_NETX_IO_CFG_sel_f1_pwm3_eclk; // select outputs for PWM-signals clocked by xmac3_eclk_in at Fieldbus1 pads 
	                                                        // usually used for xmac3 fiber-optic mode with low clock jitter
	unsigned int sel_f3_pwm3_eclk : BFW_NETX_IO_CFG_sel_f3_pwm3_eclk; // select outputs for PWM-signals clocked by xmac3_eclk_in at Fieldbus3 pads 
	                                                        // usually used for xmac3 fiber-optic mode with low clock jitter
	unsigned int sel_e_pwm2_eclk  : BFW_NETX_IO_CFG_sel_e_pwm2_eclk;  // select outputs for PWM-signals clocked by xmac2_eclk_in at PIO pads 
	                                                        // usually used for xmac2 fiber-optic mode with low clock jitter
	unsigned int reserved1        : BFW_NETX_IO_CFG_reserved1;        // reserved
	unsigned int if_select_n      : BFW_NETX_IO_CFG_if_select_n;      // inverted HIF if-select signal: 
	                                                        // 1: HIF-Mode, 0: DPM/PIO-Mode
} IO_CONFIG_BIT_T;

typedef union {
	unsigned int    val;
	IO_CONFIG_BIT_T bf;
} IO_CONFIG_T;


// ---------------------------------------------------------------------
// Register io_config_mask
// => IO config mask registers
//    Masks of output pin multiplexing select signals.
//    This register is lockable by netX locking algorithm. It will be only reset on Power on, not on normal system nres.
//    The io_config-register will change according to this register if a new mask is correctly written (netX locking algorithm).
//    Changing this register is only possible by the following sequence:
//    1.: read out access key
//    2.: write back access key
//    3.: write desired value to this register
// => Mode: Mode (r/w)
// ---------------------------------------------------------------------

#define REL_NETX_IO_CFG_MSK 0x00000008U
#define NETX_IO_CFG_MSK     0x00100008U

#define MSK_NETX_IO_CFG_MSK_sel_lcd_bw       0x00000001U // [0]
#define SRT_NETX_IO_CFG_MSK_sel_lcd_bw       0           
#define MSK_NETX_IO_CFG_MSK_sel_lcd_col      0x00000002U // [1]
#define SRT_NETX_IO_CFG_MSK_sel_lcd_col      1           
#define MSK_NETX_IO_CFG_MSK_sel_mii2         0x00000004U // [2]
#define SRT_NETX_IO_CFG_MSK_sel_mii2         2           
#define MSK_NETX_IO_CFG_MSK_sel_mii3         0x00000008U // [3]
#define SRT_NETX_IO_CFG_MSK_sel_mii3         3           
#define MSK_NETX_IO_CFG_MSK_sel_mii23        0x00000010U // [4]
#define SRT_NETX_IO_CFG_MSK_sel_mii23        4           
#define MSK_NETX_IO_CFG_MSK_sel_mii3pwm      0x00000020U // [5]
#define SRT_NETX_IO_CFG_MSK_sel_mii3pwm      5           
#define MSK_NETX_IO_CFG_MSK_sel_fo0          0x00000040U // [6]
#define SRT_NETX_IO_CFG_MSK_sel_fo0          6           
#define MSK_NETX_IO_CFG_MSK_sel_fo1          0x00000080U // [7]
#define SRT_NETX_IO_CFG_MSK_sel_fo1          7           
#define MSK_NETX_IO_CFG_MSK_sel_f0_pwm3      0x00000100U // [8]
#define SRT_NETX_IO_CFG_MSK_sel_f0_pwm3      8           
#define MSK_NETX_IO_CFG_MSK_sel_f0_failure3  0x00000200U // [9]
#define SRT_NETX_IO_CFG_MSK_sel_f0_failure3  9           
#define MSK_NETX_IO_CFG_MSK_sel_f1_pwm3      0x00000400U // [10]
#define SRT_NETX_IO_CFG_MSK_sel_f1_pwm3      10          
#define MSK_NETX_IO_CFG_MSK_sel_f1_rpwm3     0x00000800U // [11]
#define SRT_NETX_IO_CFG_MSK_sel_f1_rpwm3     11          
#define MSK_NETX_IO_CFG_MSK_sel_f2_failure3  0x00001000U // [12]
#define SRT_NETX_IO_CFG_MSK_sel_f2_failure3  12          
#define MSK_NETX_IO_CFG_MSK_sel_f2_rpwm3     0x00002000U // [13]
#define SRT_NETX_IO_CFG_MSK_sel_f2_rpwm3     13          
#define MSK_NETX_IO_CFG_MSK_sel_f3_pwm3      0x00004000U // [14]
#define SRT_NETX_IO_CFG_MSK_sel_f3_pwm3      14          
#define MSK_NETX_IO_CFG_MSK_sel_e_pwm2       0x00008000U // [15]
#define SRT_NETX_IO_CFG_MSK_sel_e_pwm2       15          
#define MSK_NETX_IO_CFG_MSK_sel_e_failure2   0x00010000U // [16]
#define SRT_NETX_IO_CFG_MSK_sel_e_failure2   16          
#define MSK_NETX_IO_CFG_MSK_sel_e_rpwm2      0x00020000U // [17]
#define SRT_NETX_IO_CFG_MSK_sel_e_rpwm2      17          
#define MSK_NETX_IO_CFG_MSK_sel_enc0         0x00040000U // [18]
#define SRT_NETX_IO_CFG_MSK_sel_enc0         18          
#define MSK_NETX_IO_CFG_MSK_sel_enc1         0x00080000U // [19]
#define SRT_NETX_IO_CFG_MSK_sel_enc1         19          
#define MSK_NETX_IO_CFG_MSK_sel_mp           0x00100000U // [20]
#define SRT_NETX_IO_CFG_MSK_sel_mp           20          
#define MSK_NETX_IO_CFG_MSK_sel_led_mii2     0x00200000U // [21]
#define SRT_NETX_IO_CFG_MSK_sel_led_mii2     21          
#define MSK_NETX_IO_CFG_MSK_sel_led_mii3     0x00400000U // [22]
#define SRT_NETX_IO_CFG_MSK_sel_led_mii3     22          
#define MSK_NETX_IO_CFG_MSK_sel_etm          0x00800000U // [23]
#define SRT_NETX_IO_CFG_MSK_sel_etm          23          
#define MSK_NETX_IO_CFG_MSK_sel_wdg          0x01000000U // [24]
#define SRT_NETX_IO_CFG_MSK_sel_wdg          24          
#define MSK_NETX_IO_CFG_MSK_sel_f0_pwm3_eclk 0x02000000U // [25]
#define SRT_NETX_IO_CFG_MSK_sel_f0_pwm3_eclk 25          
#define MSK_NETX_IO_CFG_MSK_sel_f1_pwm3_eclk 0x04000000U // [26]
#define SRT_NETX_IO_CFG_MSK_sel_f1_pwm3_eclk 26          
#define MSK_NETX_IO_CFG_MSK_sel_f3_pwm3_eclk 0x08000000U // [27]
#define SRT_NETX_IO_CFG_MSK_sel_f3_pwm3_eclk 27          
#define MSK_NETX_IO_CFG_MSK_sel_e_pwm2_eclk  0x10000000U // [28]
#define SRT_NETX_IO_CFG_MSK_sel_e_pwm2_eclk  28          
#define MSK_NETX_IO_CFG_MSK_if_select_n      0x80000000U // [31]
#define SRT_NETX_IO_CFG_MSK_if_select_n      31          

enum {
	BFW_NETX_IO_CFG_MSK_sel_lcd_bw       = 1, // [0]
	BFW_NETX_IO_CFG_MSK_sel_lcd_col      = 1, // [1]
	BFW_NETX_IO_CFG_MSK_sel_mii2         = 1, // [2]
	BFW_NETX_IO_CFG_MSK_sel_mii3         = 1, // [3]
	BFW_NETX_IO_CFG_MSK_sel_mii23        = 1, // [4]
	BFW_NETX_IO_CFG_MSK_sel_mii3pwm      = 1, // [5]
	BFW_NETX_IO_CFG_MSK_sel_fo0          = 1, // [6]
	BFW_NETX_IO_CFG_MSK_sel_fo1          = 1, // [7]
	BFW_NETX_IO_CFG_MSK_sel_f0_pwm3      = 1, // [8]
	BFW_NETX_IO_CFG_MSK_sel_f0_failure3  = 1, // [9]
	BFW_NETX_IO_CFG_MSK_sel_f1_pwm3      = 1, // [10]
	BFW_NETX_IO_CFG_MSK_sel_f1_rpwm3     = 1, // [11]
	BFW_NETX_IO_CFG_MSK_sel_f2_failure3  = 1, // [12]
	BFW_NETX_IO_CFG_MSK_sel_f2_rpwm3     = 1, // [13]
	BFW_NETX_IO_CFG_MSK_sel_f3_pwm3      = 1, // [14]
	BFW_NETX_IO_CFG_MSK_sel_e_pwm2       = 1, // [15]
	BFW_NETX_IO_CFG_MSK_sel_e_failure2   = 1, // [16]
	BFW_NETX_IO_CFG_MSK_sel_e_rpwm2      = 1, // [17]
	BFW_NETX_IO_CFG_MSK_sel_enc0         = 1, // [18]
	BFW_NETX_IO_CFG_MSK_sel_enc1         = 1, // [19]
	BFW_NETX_IO_CFG_MSK_sel_mp           = 1, // [20]
	BFW_NETX_IO_CFG_MSK_sel_led_mii2     = 1, // [21]
	BFW_NETX_IO_CFG_MSK_sel_led_mii3     = 1, // [22]
	BFW_NETX_IO_CFG_MSK_sel_etm          = 1, // [23]
	BFW_NETX_IO_CFG_MSK_sel_wdg          = 1, // [24]
	BFW_NETX_IO_CFG_MSK_sel_f0_pwm3_eclk = 1, // [25]
	BFW_NETX_IO_CFG_MSK_sel_f1_pwm3_eclk = 1, // [26]
	BFW_NETX_IO_CFG_MSK_sel_f3_pwm3_eclk = 1, // [27]
	BFW_NETX_IO_CFG_MSK_sel_e_pwm2_eclk  = 1, // [28]
	BFW_NETX_IO_CFG_MSK_reserved1        = 2, // [30:29]
	BFW_NETX_IO_CFG_MSK_if_select_n      = 1  // [31]
};

typedef struct IO_CONFIG_MASK_BIT_Ttag {
	unsigned int sel_lcd_bw       : BFW_NETX_IO_CFG_MSK_sel_lcd_bw;       // mask of select outputs for Black and White LCD Display 
	unsigned int sel_lcd_col      : BFW_NETX_IO_CFG_MSK_sel_lcd_col;      // mask of select outputs for Couloured LCD Display 
	unsigned int sel_mii2         : BFW_NETX_IO_CFG_MSK_sel_mii2;         // mask of select outputs for MII interface of xMAC2 
	unsigned int sel_mii3         : BFW_NETX_IO_CFG_MSK_sel_mii3;         // mask of select outputs for MII interface of xMAC2 
	unsigned int sel_mii23        : BFW_NETX_IO_CFG_MSK_sel_mii23;        // mask of select outputs for MDIO signals 
	unsigned int sel_mii3pwm      : BFW_NETX_IO_CFG_MSK_sel_mii3pwm;      // mask of select outputs for PWM output of xMAC3 
	unsigned int sel_fo0          : BFW_NETX_IO_CFG_MSK_sel_fo0;          // mask of select outputs for Fiber Optics of Phy0 
	unsigned int sel_fo1          : BFW_NETX_IO_CFG_MSK_sel_fo1;          // mask of select outputs for Fiber Optics of Phy1 
	unsigned int sel_f0_pwm3      : BFW_NETX_IO_CFG_MSK_sel_f0_pwm3;      // mask of select outputs for PWM-siganls at Fieldbus0 pads 
	unsigned int sel_f0_failure3  : BFW_NETX_IO_CFG_MSK_sel_f0_failure3;  // mask of select output  for PWM-failure at Fieldbus0 pads 
	unsigned int sel_f1_pwm3      : BFW_NETX_IO_CFG_MSK_sel_f1_pwm3;      // mask of select outputs for PWM-signals at Fieldbus1 pads 
	unsigned int sel_f1_rpwm3     : BFW_NETX_IO_CFG_MSK_sel_f1_rpwm3;     // mask of select output  for rpwm signal at Fieldbus1 pads 
	unsigned int sel_f2_failure3  : BFW_NETX_IO_CFG_MSK_sel_f2_failure3;  // mask of select output  for PWM-failure at Fieldbus2 pads 
	unsigned int sel_f2_rpwm3     : BFW_NETX_IO_CFG_MSK_sel_f2_rpwm3;     // mask of select output  for rpwm signal at Fieldbus2 pads 
	unsigned int sel_f3_pwm3      : BFW_NETX_IO_CFG_MSK_sel_f3_pwm3;      // mask of select outputs for PWM-signals at Fieldbus3 pads 
	unsigned int sel_e_pwm2       : BFW_NETX_IO_CFG_MSK_sel_e_pwm2;       // mask of select outputs for PWM-signals at PIO pads 
	unsigned int sel_e_failure2   : BFW_NETX_IO_CFG_MSK_sel_e_failure2;   // mask of select output  for PWM-failure at PIO pads 
	unsigned int sel_e_rpwm2      : BFW_NETX_IO_CFG_MSK_sel_e_rpwm2;      // mask of select output  for rpwm signal at PIO pads 
	unsigned int sel_enc0         : BFW_NETX_IO_CFG_MSK_sel_enc0;         // mask of select outputs for enc0 
	unsigned int sel_enc1         : BFW_NETX_IO_CFG_MSK_sel_enc1;         // mask of select outputs for enc1 
	unsigned int sel_mp           : BFW_NETX_IO_CFG_MSK_sel_mp;           // mask of select outputs for mp 
	unsigned int sel_led_mii2     : BFW_NETX_IO_CFG_MSK_sel_led_mii2;     // mask of select inputs for leds of mii2 
	unsigned int sel_led_mii3     : BFW_NETX_IO_CFG_MSK_sel_led_mii3;     // mask of select inputs for leds of mii3 
	unsigned int sel_etm          : BFW_NETX_IO_CFG_MSK_sel_etm;          // mask of select pins for ETM9 of ARM926 
	unsigned int sel_wdg          : BFW_NETX_IO_CFG_MSK_sel_wdg;          // mask of select pins for clk watchdoq / system watchdog 
	unsigned int sel_f0_pwm3_eclk : BFW_NETX_IO_CFG_MSK_sel_f0_pwm3_eclk; // mask of select outputs for PWM-siganls clocked by xmac3_eclk_in at Fieldbus0 pads 
	unsigned int sel_f1_pwm3_eclk : BFW_NETX_IO_CFG_MSK_sel_f1_pwm3_eclk; // mask of select outputs for PWM-signals clocked by xmac3_eclk_in at Fieldbus1 pads 
	unsigned int sel_f3_pwm3_eclk : BFW_NETX_IO_CFG_MSK_sel_f3_pwm3_eclk; // mask of select outputs for PWM-signals clocked by xmac3_eclk_in at Fieldbus3 pads 
	unsigned int sel_e_pwm2_eclk  : BFW_NETX_IO_CFG_MSK_sel_e_pwm2_eclk;  // mask of select outputs for PWM-signals clocked by xmac2_eclk_in at PIO pads 
	unsigned int reserved1        : BFW_NETX_IO_CFG_MSK_reserved1;        // reserved
	unsigned int if_select_n      : BFW_NETX_IO_CFG_MSK_if_select_n;      // mask of inverted HIF if-select signal: 
} IO_CONFIG_MASK_BIT_T;

typedef union {
	unsigned int         val;
	IO_CONFIG_MASK_BIT_T bf;
} IO_CONFIG_MASK_T;


// ---------------------------------------------------------------------
// Register reset_ctrl
// => Reset Control Register
//    register for reading the reset state of all resets, and to set two different Software Resets
//    Changing this register is only possible by the following sequence:
//    1.: read out access key
//    2.: write back access key
//    3.: write desired value to this register
// => Mode: Mode (r/w)
// ---------------------------------------------------------------------

#define REL_NETX_RESET_CTRL 0x0000000CU
#define NETX_RESET_CTRL     0x0010000CU

#define MSK_NETX_RESET_CTRL_RES_IN           0x00000001U // [0]
#define SRT_NETX_RESET_CTRL_RES_IN           0           
#define MSK_NETX_RESET_CTRL_RES_WDOG         0x00000002U // [1]
#define SRT_NETX_RESET_CTRL_RES_WDOG         1           
#define MSK_NETX_RESET_CTRL_RES_HOST         0x00000004U // [2]
#define SRT_NETX_RESET_CTRL_RES_HOST         2           
#define MSK_NETX_RESET_CTRL_RES_FIRMWARE     0x00000008U // [3]
#define SRT_NETX_RESET_CTRL_RES_FIRMWARE     3           
#define MSK_NETX_RESET_CTRL_RES_XPEC0        0x00000010U // [4]
#define SRT_NETX_RESET_CTRL_RES_XPEC0        4           
#define MSK_NETX_RESET_CTRL_RES_XPEC1        0x00000020U // [5]
#define SRT_NETX_RESET_CTRL_RES_XPEC1        5           
#define MSK_NETX_RESET_CTRL_RES_XPEC2        0x00000040U // [6]
#define SRT_NETX_RESET_CTRL_RES_XPEC2        6           
#define MSK_NETX_RESET_CTRL_RES_XPEC3        0x00000080U // [7]
#define SRT_NETX_RESET_CTRL_RES_XPEC3        7           
#define MSK_NETX_RESET_CTRL_DIS_RES_XPEC0    0x00010000U // [16]
#define SRT_NETX_RESET_CTRL_DIS_RES_XPEC0    16          
#define MSK_NETX_RESET_CTRL_DIS_RES_XPEC1    0x00020000U // [17]
#define SRT_NETX_RESET_CTRL_DIS_RES_XPEC1    17          
#define MSK_NETX_RESET_CTRL_DIS_RES_XPEC2    0x00040000U // [18]
#define SRT_NETX_RESET_CTRL_DIS_RES_XPEC2    18          
#define MSK_NETX_RESET_CTRL_DIS_RES_XPEC3    0x00080000U // [19]
#define SRT_NETX_RESET_CTRL_DIS_RES_XPEC3    19          
#define MSK_NETX_RESET_CTRL_FIRMWARE_STATUS0 0x00100000U // [20]
#define SRT_NETX_RESET_CTRL_FIRMWARE_STATUS0 20          
#define MSK_NETX_RESET_CTRL_FIRMWARE_STATUS1 0x00200000U // [21]
#define SRT_NETX_RESET_CTRL_FIRMWARE_STATUS1 21          
#define MSK_NETX_RESET_CTRL_FIRMWARE_STATUS2 0x00400000U // [22]
#define SRT_NETX_RESET_CTRL_FIRMWARE_STATUS2 22          
#define MSK_NETX_RESET_CTRL_FIRMWARE_STATUS3 0x00800000U // [23]
#define SRT_NETX_RESET_CTRL_FIRMWARE_STATUS3 23          
#define MSK_NETX_RESET_CTRL_RES_REQ_FIRMWARE 0x01000000U // [24]
#define SRT_NETX_RESET_CTRL_RES_REQ_FIRMWARE 24          
#define MSK_NETX_RESET_CTRL_RES_REQ_OUT      0x02000000U // [25]
#define SRT_NETX_RESET_CTRL_RES_REQ_OUT      25          
#define MSK_NETX_RESET_CTRL_EN_RES_REQ_OUT   0x04000000U // [26]
#define SRT_NETX_RESET_CTRL_EN_RES_REQ_OUT   26          

enum {
	BFW_NETX_RESET_CTRL_RES_IN           = 1, // [0]
	BFW_NETX_RESET_CTRL_RES_WDOG         = 1, // [1]
	BFW_NETX_RESET_CTRL_RES_HOST         = 1, // [2]
	BFW_NETX_RESET_CTRL_RES_FIRMWARE     = 1, // [3]
	BFW_NETX_RESET_CTRL_RES_XPEC0        = 1, // [4]
	BFW_NETX_RESET_CTRL_RES_XPEC1        = 1, // [5]
	BFW_NETX_RESET_CTRL_RES_XPEC2        = 1, // [6]
	BFW_NETX_RESET_CTRL_RES_XPEC3        = 1, // [7]
	BFW_NETX_RESET_CTRL_reserved1        = 8, // [15:8]
	BFW_NETX_RESET_CTRL_DIS_RES_XPEC0    = 1, // [16]
	BFW_NETX_RESET_CTRL_DIS_RES_XPEC1    = 1, // [17]
	BFW_NETX_RESET_CTRL_DIS_RES_XPEC2    = 1, // [18]
	BFW_NETX_RESET_CTRL_DIS_RES_XPEC3    = 1, // [19]
	BFW_NETX_RESET_CTRL_FIRMWARE_STATUS0 = 1, // [20]
	BFW_NETX_RESET_CTRL_FIRMWARE_STATUS1 = 1, // [21]
	BFW_NETX_RESET_CTRL_FIRMWARE_STATUS2 = 1, // [22]
	BFW_NETX_RESET_CTRL_FIRMWARE_STATUS3 = 1, // [23]
	BFW_NETX_RESET_CTRL_RES_REQ_FIRMWARE = 1, // [24]
	BFW_NETX_RESET_CTRL_RES_REQ_OUT      = 1, // [25]
	BFW_NETX_RESET_CTRL_EN_RES_REQ_OUT   = 1, // [26]
	BFW_NETX_RESET_CTRL_reserved2        = 5  // [31:27]
};

typedef struct RESET_CTRL_BIT_Ttag {
	unsigned int RES_IN           : BFW_NETX_RESET_CTRL_RES_IN;           // reset from external pin, after reading write back a "1" to clear the status bit               
	unsigned int RES_WDOG         : BFW_NETX_RESET_CTRL_RES_WDOG;         // reset from System WDG, after reading write back a "1" to clear the status bit                 
	unsigned int RES_HOST         : BFW_NETX_RESET_CTRL_RES_HOST;         // reset from Hostinterface, after reading write back a "1" to clear the status bit              
	unsigned int RES_FIRMWARE     : BFW_NETX_RESET_CTRL_RES_FIRMWARE;     // reset from FIRMWARE (software reset), after reading write back a "1" to clear the status bit  
	unsigned int RES_XPEC0        : BFW_NETX_RESET_CTRL_RES_XPEC0;        // reset from RES_XPEC0, after reading write back a "1" to clear the status bit                  
	unsigned int RES_XPEC1        : BFW_NETX_RESET_CTRL_RES_XPEC1;        // reset from RES_XPEC1, after reading write back a "1" to clear the status bit                  
	unsigned int RES_XPEC2        : BFW_NETX_RESET_CTRL_RES_XPEC2;        // reset from RES_XPEC2, after reading write back a "1" to clear the status bit                  
	unsigned int RES_XPEC3        : BFW_NETX_RESET_CTRL_RES_XPEC3;        // reset from RES_XPEC3, after reading write back a "1" to clear the status bit                  
	unsigned int reserved1        : BFW_NETX_RESET_CTRL_reserved1;        // reserved
	unsigned int DIS_RES_XPEC0    : BFW_NETX_RESET_CTRL_DIS_RES_XPEC0;    // reset from RES_XPEC0 is disabled (read only)     
	unsigned int DIS_RES_XPEC1    : BFW_NETX_RESET_CTRL_DIS_RES_XPEC1;    // reset from RES_XPEC1 is disabled (read only)     
	unsigned int DIS_RES_XPEC2    : BFW_NETX_RESET_CTRL_DIS_RES_XPEC2;    // reset from RES_XPEC2 is disabled (read only)     
	unsigned int DIS_RES_XPEC3    : BFW_NETX_RESET_CTRL_DIS_RES_XPEC3;    // reset from RES_XPEC3 is disabled (read only)     
	unsigned int FIRMWARE_STATUS0 : BFW_NETX_RESET_CTRL_FIRMWARE_STATUS0; // readable and writable bit to save the firmware status; only a PowerOn Reset will clear this bit 
	unsigned int FIRMWARE_STATUS1 : BFW_NETX_RESET_CTRL_FIRMWARE_STATUS1; // readable and writable bit to save the firmware status; only a PowerOn Reset will clear this bit 
	unsigned int FIRMWARE_STATUS2 : BFW_NETX_RESET_CTRL_FIRMWARE_STATUS2; // readable and writable bit to save the firmware status; only a PowerOn Reset will clear this bit 
	unsigned int FIRMWARE_STATUS3 : BFW_NETX_RESET_CTRL_FIRMWARE_STATUS3; // readable and writable bit to save the firmware status; only a PowerOn Reset will clear this bit 
	unsigned int RES_REQ_FIRMWARE : BFW_NETX_RESET_CTRL_RES_REQ_FIRMWARE; // (software reset) writing a "1" sets the reset request to reset the hole system (write only)   
	unsigned int RES_REQ_OUT      : BFW_NETX_RESET_CTRL_RES_REQ_OUT;      // (software reset) programmable reset sets the reset on the external pin                        
	unsigned int EN_RES_REQ_OUT   : BFW_NETX_RESET_CTRL_EN_RES_REQ_OUT;   // this bit enables the programmable reset       
	unsigned int reserved2        : BFW_NETX_RESET_CTRL_reserved2;        // reserved
} RESET_CTRL_BIT_T;

typedef union {
	unsigned int     val;
	RESET_CTRL_BIT_T bf;
} RESET_CTRL_T;


// ---------------------------------------------------------------------
// Register netx_version
// => netX Version register
//    lockable by netX locking algorithm
//    1.: read out access key
//    2.: write back access key
//    3.: write desired value to this register
// => Mode: Mode (r/w)
// ---------------------------------------------------------------------

#define REL_NETX_NETX_REV 0x00000034U
#define NETX_NETX_REV     0x00100034U

#define MSK_NETX_NETX_REV_netx_version 0xffffffffU // [31:0]
#define SRT_NETX_NETX_REV_netx_version 0           

enum {
	BFW_NETX_NETX_REV_netx_version = 32  // [31:0]
};

typedef struct NETX_VERSION_BIT_Ttag {
	unsigned int netx_version : BFW_NETX_NETX_REV_netx_version; // netX Version number 
} NETX_VERSION_BIT_T;

typedef union {
	unsigned int       val;
	NETX_VERSION_BIT_T bf;
} NETX_VERSION_T;


// ---------------------------------------------------------------------
// Register asic_ctrl_access_key
// => ASIC Controll Access Key Register
//    Writing to any register in the asic_ctrl - address area is only possible after
//    setting the correct key here to avoid unmeant changes eg. by crashed software.
//    ----
//    Changing a controll register in the asic_ctrl - address area is only possible by the following sequence:
//    1.: Read out the access key from this register.
//    2.: Write back this access key to this register.
//    3.: Write desired value to the controll register.
//    ----
//    The access key will become unvalid after each access to any register in the asic_ctrl - address area
//    and has to be read out and set again for sequent accesses.
// => Mode: Mode (r/w)
// ---------------------------------------------------------------------

#define REL_NETX_IO_CFG_ACCESS_KEY 0x00000070U
#define NETX_IO_CFG_ACCESS_KEY     0x00100070U

#define MSK_NETX_IO_CFG_ACCESS_KEY_access_key 0x0000ffffU // [15:0]
#define SRT_NETX_IO_CFG_ACCESS_KEY_access_key 0           

enum {
	BFW_NETX_IO_CFG_ACCESS_KEY_access_key = 16, // [15:0]
	BFW_NETX_IO_CFG_ACCESS_KEY_reserved1  = 16  // [31:16]
};

typedef struct ASIC_CTRL_ACCESS_KEY_BIT_Ttag {
	unsigned int access_key : BFW_NETX_IO_CFG_ACCESS_KEY_access_key; // access key for next write access. 
	unsigned int reserved1  : BFW_NETX_IO_CFG_ACCESS_KEY_reserved1;  // reserved
} ASIC_CTRL_ACCESS_KEY_BIT_T;

typedef union {
	unsigned int               val;
	ASIC_CTRL_ACCESS_KEY_BIT_T bf;
} ASIC_CTRL_ACCESS_KEY_T;


// ---------------------------------------------------------------------
// Register armclk_rate_mul_add
// => Rate Multiplier Add Value
//    This register is lockable by netX locking algorithm. It will be only reset on Power on, not on normal system nres.
//    Changing this register is only possible by the following sequence:
//    1.: read out access key
//    2.: write back access key
//    3.: write desired value to this register
// => Mode: Mode (r/w)
// ---------------------------------------------------------------------

#define REL_NETX_ARM_CLK_RATE_MUL_ADD 0x00000014U
#define NETX_ARM_CLK_RATE_MUL_ADD     0x00100014U

#define MSK_NETX_ARM_CLK_RATE_MUL_ADD_armclk_rate_mul_add 0x000001ffU // [8:0]
#define SRT_NETX_ARM_CLK_RATE_MUL_ADD_armclk_rate_mul_add 0           

enum {
	BFW_NETX_ARM_CLK_RATE_MUL_ADD_armclk_rate_mul_add = 9,  // [8:0]
	BFW_NETX_ARM_CLK_RATE_MUL_ADD_reserved1           = 23  // [31:9]
};

typedef struct ARMCLK_RATE_MUL_ADD_BIT_Ttag {
	unsigned int armclk_rate_mul_add : BFW_NETX_ARM_CLK_RATE_MUL_ADD_armclk_rate_mul_add; // This value is added each clk400 cycle to armclk_rate_mul to generate armclk. 
	                                                        // Change value according to formula: armclk_rate_mul_add = [freq in MHz] / 400 * 2^9
	unsigned int reserved1           : BFW_NETX_ARM_CLK_RATE_MUL_ADD_reserved1;           // reserved
} ARMCLK_RATE_MUL_ADD_BIT_T;

typedef union {
	unsigned int              val;
	ARMCLK_RATE_MUL_ADD_BIT_T bf;
} ARMCLK_RATE_MUL_ADD_T;


// ---------------------------------------------------------------------
// Register usbclk_rate_mul_add
// => Rate Multiplier Add Value
//    Changing this register is only possible by the following sequence:
//    1.: read out access key
//    2.: write back access key
//    3.: write desired value to this register
// => Mode: Mode (r/w)
// ---------------------------------------------------------------------

#define REL_NETX_USB_CLK_RATE_MUL_ADD 0x00000018U
#define NETX_USB_CLK_RATE_MUL_ADD     0x00100018U

#define MSK_NETX_USB_CLK_RATE_MUL_ADD_unused              0x0000ffffU // [15:0]
#define SRT_NETX_USB_CLK_RATE_MUL_ADD_unused              0           
#define MSK_NETX_USB_CLK_RATE_MUL_ADD_usbclk_rate_mul_add 0xffff0000U // [31:16]
#define SRT_NETX_USB_CLK_RATE_MUL_ADD_usbclk_rate_mul_add 16          

enum {
	BFW_NETX_USB_CLK_RATE_MUL_ADD_unused              = 16, // [15:0]
	BFW_NETX_USB_CLK_RATE_MUL_ADD_usbclk_rate_mul_add = 16  // [31:16]
};

typedef struct USBCLK_RATE_MUL_ADD_BIT_Ttag {
	unsigned int unused              : BFW_NETX_USB_CLK_RATE_MUL_ADD_unused;              // unused 
	unsigned int usbclk_rate_mul_add : BFW_NETX_USB_CLK_RATE_MUL_ADD_usbclk_rate_mul_add; // This value is added each clk400 cycle to usbclk_rate_mul to generate usbclk. 
	                                                        // Change value according to formula: usbclk_rate_mul_add = [freq in MHz] / 400 * 2^16
} USBCLK_RATE_MUL_ADD_BIT_T;

typedef union {
	unsigned int              val;
	USBCLK_RATE_MUL_ADD_BIT_T bf;
} USBCLK_RATE_MUL_ADD_T;


// ---------------------------------------------------------------------
// Register adcclk_rate_mul_add
// => Rate Multiplier Add Value
//    Changing this register is only possible by the following sequence:
//    1.: read out access key
//    2.: write back access key
//    3.: write desired value to this register
// => Mode: Mode (r/w)
// ---------------------------------------------------------------------

#define REL_NETX_ADC_CLK_RATE_MUL_ADD 0x0000001CU
#define NETX_ADC_CLK_RATE_MUL_ADD     0x0010001CU

#define MSK_NETX_ADC_CLK_RATE_MUL_ADD_adcclk_rate_mul_add 0x7fffffffU // [30:0]
#define SRT_NETX_ADC_CLK_RATE_MUL_ADD_adcclk_rate_mul_add 0           

enum {
	BFW_NETX_ADC_CLK_RATE_MUL_ADD_adcclk_rate_mul_add = 31, // [30:0]
	BFW_NETX_ADC_CLK_RATE_MUL_ADD_reserved1           = 1   // [31]
};

typedef struct ADCCLK_RATE_MUL_ADD_BIT_Ttag {
	unsigned int adcclk_rate_mul_add : BFW_NETX_ADC_CLK_RATE_MUL_ADD_adcclk_rate_mul_add; // This value is added each clk200 cycle to adcclk_rate_mul to generate adcclk. 
	                                                        // Change value according to formula: adcclk_rate_mul_add = [freq in MHz] / 200 * 2^31
	unsigned int reserved1           : BFW_NETX_ADC_CLK_RATE_MUL_ADD_reserved1;           // reserved
} ADCCLK_RATE_MUL_ADD_BIT_T;

typedef union {
	unsigned int              val;
	ADCCLK_RATE_MUL_ADD_BIT_T bf;
} ADCCLK_RATE_MUL_ADD_T;


// ---------------------------------------------------------------------
// Register phyclk_rate_mul_add
// => Rate Multiplier Add Value
//    Changing this register is only possible by the following sequence:
//    1.: read out access key
//    2.: write back access key
//    3.: write desired value to this register
// => Mode: Mode (r/w)
// ---------------------------------------------------------------------

#define REL_NETX_PHY_CLK_RATE_MUL_ADD 0x00000020U
#define NETX_PHY_CLK_RATE_MUL_ADD     0x00100020U

#define MSK_NETX_PHY_CLK_RATE_MUL_ADD_phyclk_rate_mul_add 0x7fffffffU // [30:0]
#define SRT_NETX_PHY_CLK_RATE_MUL_ADD_phyclk_rate_mul_add 0           

enum {
	BFW_NETX_PHY_CLK_RATE_MUL_ADD_phyclk_rate_mul_add = 31, // [30:0]
	BFW_NETX_PHY_CLK_RATE_MUL_ADD_reserved1           = 1   // [31]
};

typedef struct PHYCLK_RATE_MUL_ADD_BIT_Ttag {
	unsigned int phyclk_rate_mul_add : BFW_NETX_PHY_CLK_RATE_MUL_ADD_phyclk_rate_mul_add; // This value is added each clk200 cycle to phyclk_rate_mul to generate phyclk. 
	                                                        // Change value according to formula: phyclk_rate_mul_add = [freq in MHz] / 200 * 2^31
	unsigned int reserved1           : BFW_NETX_PHY_CLK_RATE_MUL_ADD_reserved1;           // reserved
} PHYCLK_RATE_MUL_ADD_BIT_T;

typedef union {
	unsigned int              val;
	PHYCLK_RATE_MUL_ADD_BIT_T bf;
} PHYCLK_RATE_MUL_ADD_T;


// ---------------------------------------------------------------------
// Register clock_enable
// => Global Clock Enable register
//    Allows to disable modules completely for power saving purpose.
//    Changes will only have effect if according bit in clock_enable_mask-register is set.
//    Bits will be reset according to the clock_enable_mask-register register if a new mask is correctly written (netX locking algorithm).
//    Changing this register is only possible by the following sequence:
//    1.: read out access key
//    2.: write back access key
//    3.: write desired value to this register
// => Mode: Mode (r/w)
// ---------------------------------------------------------------------

#define REL_NETX_CLK_EN 0x00000024U
#define NETX_CLK_EN     0x00100024U

#define MSK_NETX_CLK_EN_xpec0 0x00000001U // [0]
#define SRT_NETX_CLK_EN_xpec0 0           
#define MSK_NETX_CLK_EN_xpec1 0x00000002U // [1]
#define SRT_NETX_CLK_EN_xpec1 1           
#define MSK_NETX_CLK_EN_xpec2 0x00000004U // [2]
#define SRT_NETX_CLK_EN_xpec2 2           
#define MSK_NETX_CLK_EN_xpec3 0x00000008U // [3]
#define SRT_NETX_CLK_EN_xpec3 3           
#define MSK_NETX_CLK_EN_xmac0 0x00000010U // [4]
#define SRT_NETX_CLK_EN_xmac0 4           
#define MSK_NETX_CLK_EN_xmac1 0x00000020U // [5]
#define SRT_NETX_CLK_EN_xmac1 5           
#define MSK_NETX_CLK_EN_xmac2 0x00000040U // [6]
#define SRT_NETX_CLK_EN_xmac2 6           
#define MSK_NETX_CLK_EN_xmac3 0x00000080U // [7]
#define SRT_NETX_CLK_EN_xmac3 7           
#define MSK_NETX_CLK_EN_lcd   0x00000100U // [8]
#define SRT_NETX_CLK_EN_lcd   8           
#define MSK_NETX_CLK_EN_hif   0x00000200U // [9]
#define SRT_NETX_CLK_EN_hif   9           

enum {
	BFW_NETX_CLK_EN_xpec0     = 1,  // [0]
	BFW_NETX_CLK_EN_xpec1     = 1,  // [1]
	BFW_NETX_CLK_EN_xpec2     = 1,  // [2]
	BFW_NETX_CLK_EN_xpec3     = 1,  // [3]
	BFW_NETX_CLK_EN_xmac0     = 1,  // [4]
	BFW_NETX_CLK_EN_xmac1     = 1,  // [5]
	BFW_NETX_CLK_EN_xmac2     = 1,  // [6]
	BFW_NETX_CLK_EN_xmac3     = 1,  // [7]
	BFW_NETX_CLK_EN_lcd       = 1,  // [8]
	BFW_NETX_CLK_EN_hif       = 1,  // [9]
	BFW_NETX_CLK_EN_reserved1 = 22  // [31:10]
};

typedef struct CLOCK_ENABLE_BIT_Ttag {
	unsigned int xpec0     : BFW_NETX_CLK_EN_xpec0;     // enables clock for xPEC0 
	unsigned int xpec1     : BFW_NETX_CLK_EN_xpec1;     // enables clock for xPEC1 
	unsigned int xpec2     : BFW_NETX_CLK_EN_xpec2;     // enables clock for xPEC2 
	unsigned int xpec3     : BFW_NETX_CLK_EN_xpec3;     // enables clock for xPEC3 
	unsigned int xmac0     : BFW_NETX_CLK_EN_xmac0;     // enables clock for xMAC0 
	unsigned int xmac1     : BFW_NETX_CLK_EN_xmac1;     // enables clock for xMAC1 
	unsigned int xmac2     : BFW_NETX_CLK_EN_xmac2;     // enables clock for xMAC2 
	unsigned int xmac3     : BFW_NETX_CLK_EN_xmac3;     // enables clock for xMAC3 
	unsigned int lcd       : BFW_NETX_CLK_EN_lcd;       // enables clock for LCD Ctrl 
	unsigned int hif       : BFW_NETX_CLK_EN_hif;       // enables clock for HIF 
	unsigned int reserved1 : BFW_NETX_CLK_EN_reserved1; // reserved
} CLOCK_ENABLE_BIT_T;

typedef union {
	unsigned int       val;
	CLOCK_ENABLE_BIT_T bf;
} CLOCK_ENABLE_T;


// ---------------------------------------------------------------------
// Register clock_enable_mask
// => Global Clock Enable register
//    allows to disable modules for different netX-versions 
//    This register is lockable by netX locking algorithm. It will be only reset on Power on, not on normal system nres.
//    The clock_enable-register will change according to this register if a new mask is correctly written (netX locking algorithm).
//    Changing this register is only possible by the following sequence:
//    1.: read out access key
//    2.: write back access key
//    3.: write desired value to this register
// => Mode: Mode (r/w)
// ---------------------------------------------------------------------

#define REL_NETX_CLK_EN_MSK 0x00000028U
#define NETX_CLK_EN_MSK     0x00100028U

#define MSK_NETX_CLK_EN_MSK_xpec0 0x00000001U // [0]
#define SRT_NETX_CLK_EN_MSK_xpec0 0           
#define MSK_NETX_CLK_EN_MSK_xpec1 0x00000002U // [1]
#define SRT_NETX_CLK_EN_MSK_xpec1 1           
#define MSK_NETX_CLK_EN_MSK_xpec2 0x00000004U // [2]
#define SRT_NETX_CLK_EN_MSK_xpec2 2           
#define MSK_NETX_CLK_EN_MSK_xpec3 0x00000008U // [3]
#define SRT_NETX_CLK_EN_MSK_xpec3 3           
#define MSK_NETX_CLK_EN_MSK_xmac0 0x00000010U // [4]
#define SRT_NETX_CLK_EN_MSK_xmac0 4           
#define MSK_NETX_CLK_EN_MSK_xmac1 0x00000020U // [5]
#define SRT_NETX_CLK_EN_MSK_xmac1 5           
#define MSK_NETX_CLK_EN_MSK_xmac2 0x00000040U // [6]
#define SRT_NETX_CLK_EN_MSK_xmac2 6           
#define MSK_NETX_CLK_EN_MSK_xmac3 0x00000080U // [7]
#define SRT_NETX_CLK_EN_MSK_xmac3 7           
#define MSK_NETX_CLK_EN_MSK_lcd   0x00000100U // [8]
#define SRT_NETX_CLK_EN_MSK_lcd   8           
#define MSK_NETX_CLK_EN_MSK_hif   0x00000200U // [9]
#define SRT_NETX_CLK_EN_MSK_hif   9           

enum {
	BFW_NETX_CLK_EN_MSK_xpec0     = 1,  // [0]
	BFW_NETX_CLK_EN_MSK_xpec1     = 1,  // [1]
	BFW_NETX_CLK_EN_MSK_xpec2     = 1,  // [2]
	BFW_NETX_CLK_EN_MSK_xpec3     = 1,  // [3]
	BFW_NETX_CLK_EN_MSK_xmac0     = 1,  // [4]
	BFW_NETX_CLK_EN_MSK_xmac1     = 1,  // [5]
	BFW_NETX_CLK_EN_MSK_xmac2     = 1,  // [6]
	BFW_NETX_CLK_EN_MSK_xmac3     = 1,  // [7]
	BFW_NETX_CLK_EN_MSK_lcd       = 1,  // [8]
	BFW_NETX_CLK_EN_MSK_hif       = 1,  // [9]
	BFW_NETX_CLK_EN_MSK_reserved1 = 22  // [31:10]
};

typedef struct CLOCK_ENABLE_MASK_BIT_Ttag {
	unsigned int xpec0     : BFW_NETX_CLK_EN_MSK_xpec0;     // 0: xPEC0 is disabled  1: clock can be enabled/disabled by clock_enable-register for xPEC0 
	unsigned int xpec1     : BFW_NETX_CLK_EN_MSK_xpec1;     // 0: xPEC1 is disabled  1: clock can be enabled/disabled by clock_enable-register for xPEC1 
	unsigned int xpec2     : BFW_NETX_CLK_EN_MSK_xpec2;     // 0: xPEC2 is disabled  1: clock can be enabled/disabled by clock_enable-register for xPEC2 
	unsigned int xpec3     : BFW_NETX_CLK_EN_MSK_xpec3;     // 0: xPEC3 is disabled  1: clock can be enabled/disabled by clock_enable-register for xPEC3 
	unsigned int xmac0     : BFW_NETX_CLK_EN_MSK_xmac0;     // 0: xMAC0 is disabled  1: clock can be enabled/disabled by clock_enable-register for xMAC0 
	unsigned int xmac1     : BFW_NETX_CLK_EN_MSK_xmac1;     // 0: xMAC1 is disabled  1: clock can be enabled/disabled by clock_enable-register for xMAC1 
	unsigned int xmac2     : BFW_NETX_CLK_EN_MSK_xmac2;     // 0: xMAC2 is disabled  1: clock can be enabled/disabled by clock_enable-register for xMAC2 
	unsigned int xmac3     : BFW_NETX_CLK_EN_MSK_xmac3;     // 0: xMAC3 is disabled  1: clock can be enabled/disabled by clock_enable-register for xMAC3 
	unsigned int lcd       : BFW_NETX_CLK_EN_MSK_lcd;       // 0: LCD Ctrl is disabled  1: clock can be enabled/disabled by clock_enable-register for LCD Ctrl 
	unsigned int hif       : BFW_NETX_CLK_EN_MSK_hif;       // 0: HIF is disabled  1: clock can be enabled/disabled by clock_enable-register for HIF 
	unsigned int reserved1 : BFW_NETX_CLK_EN_MSK_reserved1; // reserved
} CLOCK_ENABLE_MASK_BIT_T;

typedef union {
	unsigned int            val;
	CLOCK_ENABLE_MASK_BIT_T bf;
} CLOCK_ENABLE_MASK_T;


// ---------------------------------------------------------------------
// Register misc_asic_ctrl
// => miscellaneous ASIC controll register
//    This register is lockable by netX locking algorithm. It will be only reset on Power on, not on normal system nres.
//    Changing this register is only possible by the following sequence:
//    1.: read out access key
//    2.: write back access key
//    3.: write desired value to this register
// => Mode: Mode (r/w)
// ---------------------------------------------------------------------

#define REL_NETX_MISC_CTRL 0x0000002CU
#define NETX_MISC_CTRL     0x0010002CU

#define MSK_NETX_MISC_CTRL_arm_dbgen     0x00000001U // [0]
#define SRT_NETX_MISC_CTRL_arm_dbgen     0           
#define MSK_NETX_MISC_CTRL_arm_dtcm_ws   0x00000002U // [1]
#define SRT_NETX_MISC_CTRL_arm_dtcm_ws   1           
#define MSK_NETX_MISC_CTRL_arm_extmem_ws 0x00000004U // [2]
#define SRT_NETX_MISC_CTRL_arm_extmem_ws 2           

enum {
	BFW_NETX_MISC_CTRL_arm_dbgen     = 1,  // [0]
	BFW_NETX_MISC_CTRL_arm_dtcm_ws   = 1,  // [1]
	BFW_NETX_MISC_CTRL_arm_extmem_ws = 1,  // [2]
	BFW_NETX_MISC_CTRL_reserved1     = 29  // [31:3]
};

typedef struct MISC_ASIC_CTRL_BIT_Ttag {
	unsigned int arm_dbgen     : BFW_NETX_MISC_CTRL_arm_dbgen;     // 1: ARM debug features are enabled 
	                                                        // 0: ARM debug features are disabled
	unsigned int arm_dtcm_ws   : BFW_NETX_MISC_CTRL_arm_dtcm_ws;   // 1: ARM data TCM runs with 1 ARM-clock Waitstate  
	                                                        // 0: ARM data TCM runs with 0 ARM-clock Waitstate
	unsigned int arm_extmem_ws : BFW_NETX_MISC_CTRL_arm_extmem_ws; // 1: 1 additional arbiter Waitstate for ARM (instr. and data) accesses to addr_extmemory_ahbls7 - chipselect area 
	                                                        // 0: 0 additional arbiter Waitstate for ARM (instr. and data) accesses to addr_extmemory_ahbls7 - chipselect area # default 10: ARM data TCM runs with 0 ARM-clock Waitstate
	unsigned int reserved1     : BFW_NETX_MISC_CTRL_reserved1;     // reserved
} MISC_ASIC_CTRL_BIT_T;

typedef union {
	unsigned int         val;
	MISC_ASIC_CTRL_BIT_T bf;
} MISC_ASIC_CTRL_T;


// ---------------------------------------------------------------------
// Register exmem_priority_lock
// => Global exmemory priority controlling mask register
//    Set bits to lock the registers extmem_prio_timslot_ctrl and extmem_prio_accesstime_ctrl
//    in address area extmem_priority_ctrl.
//    allows to disable modules completely for power saving reasons
//    This register is lockable by netX locking algorithm. It will be only reset on Power on, not on normal system nres.
//    Changing this register is only possible by the following sequence:
//    1.: read out access key
//    2.: write back access key
//    3.: write desired value to this register
// => Mode: Mode (r/w)
// ---------------------------------------------------------------------

#define REL_NETX_LOCK_MEM_PRIO_CTRL 0x00000030U
#define NETX_LOCK_MEM_PRIO_CTRL     0x00100030U

#define MSK_NETX_LOCK_MEM_PRIO_CTRL_lock_HIF_priority  0x00000001U // [0]
#define SRT_NETX_LOCK_MEM_PRIO_CTRL_lock_HIF_priority  0           
#define MSK_NETX_LOCK_MEM_PRIO_CTRL_lock_XC_priority   0x00000002U // [1]
#define SRT_NETX_LOCK_MEM_PRIO_CTRL_lock_XC_priority   1           
#define MSK_NETX_LOCK_MEM_PRIO_CTRL_lock_LCD_priority  0x00000004U // [2]
#define SRT_NETX_LOCK_MEM_PRIO_CTRL_lock_LCD_priority  2           
#define MSK_NETX_LOCK_MEM_PRIO_CTRL_lock_ARMI_priority 0x00000008U // [3]
#define SRT_NETX_LOCK_MEM_PRIO_CTRL_lock_ARMI_priority 3           
#define MSK_NETX_LOCK_MEM_PRIO_CTRL_lock_ARMD_priority 0x00000010U // [4]
#define SRT_NETX_LOCK_MEM_PRIO_CTRL_lock_ARMD_priority 4           

enum {
	BFW_NETX_LOCK_MEM_PRIO_CTRL_lock_HIF_priority  = 1,  // [0]
	BFW_NETX_LOCK_MEM_PRIO_CTRL_lock_XC_priority   = 1,  // [1]
	BFW_NETX_LOCK_MEM_PRIO_CTRL_lock_LCD_priority  = 1,  // [2]
	BFW_NETX_LOCK_MEM_PRIO_CTRL_lock_ARMI_priority = 1,  // [3]
	BFW_NETX_LOCK_MEM_PRIO_CTRL_lock_ARMD_priority = 1,  // [4]
	BFW_NETX_LOCK_MEM_PRIO_CTRL_reserved1          = 27  // [31:5]
};

typedef struct EXMEM_PRIORITY_LOCK_BIT_Ttag {
	unsigned int lock_HIF_priority  : BFW_NETX_LOCK_MEM_PRIO_CTRL_lock_HIF_priority;  // 1 HIF settings in registers extmem_prio_timslot_ctrl and extmem_prio_accesstime_ctrl will be locked 
	unsigned int lock_XC_priority   : BFW_NETX_LOCK_MEM_PRIO_CTRL_lock_XC_priority;   // 1 XC settings in registers extmem_prio_timslot_ctrl and extmem_prio_accesstime_ctrl will be locked 
	unsigned int lock_LCD_priority  : BFW_NETX_LOCK_MEM_PRIO_CTRL_lock_LCD_priority;  // 1 LCD settings in registers extmem_prio_timslot_ctrl and extmem_prio_accesstime_ctrl will be locked 
	unsigned int lock_ARMI_priority : BFW_NETX_LOCK_MEM_PRIO_CTRL_lock_ARMI_priority; // 1 ARMI settings in registers extmem_prio_timslot_ctrl and extmem_prio_accesstime_ctrl will be locked 
	unsigned int lock_ARMD_priority : BFW_NETX_LOCK_MEM_PRIO_CTRL_lock_ARMD_priority; // 1 ARMD settings in registers extmem_prio_timslot_ctrl and extmem_prio_accesstime_ctrl will be locked 
	unsigned int reserved1          : BFW_NETX_LOCK_MEM_PRIO_CTRL_reserved1;          // reserved
} EXMEM_PRIORITY_LOCK_BIT_T;

typedef union {
	unsigned int              val;
	EXMEM_PRIORITY_LOCK_BIT_T bf;
} EXMEM_PRIORITY_LOCK_T;


// ---------------------------------------------------------------------
// Register netx_lock_reserved00
// => reserved address for netX locking purpose
// => Mode: Mode (r)
// ---------------------------------------------------------------------

#define REL_NETX_LOCK_RESERVED_00 0x00000074U
#define NETX_LOCK_RESERVED_00     0x00100074U

#define MSK_NETX_LOCK_RESERVED_00_lock 0xffffffffU // [31:0]
#define SRT_NETX_LOCK_RESERVED_00_lock 0           

enum {
	BFW_NETX_LOCK_RESERVED_00_lock = 32  // [31:0]
};

typedef struct NETX_LOCK_RESERVED00_BIT_Ttag {
	unsigned int lock : BFW_NETX_LOCK_RESERVED_00_lock; // locking purpose 
} NETX_LOCK_RESERVED00_BIT_T;

typedef union {
	unsigned int               val;
	NETX_LOCK_RESERVED00_BIT_T bf;
} NETX_LOCK_RESERVED00_T;


// ---------------------------------------------------------------------
// Register netx_lock_reserved01
// => reserved address for netX locking purpose
// => Mode: Mode (r)
// ---------------------------------------------------------------------

#define REL_NETX_LOCK_RESERVED_01 0x00000078U
#define NETX_LOCK_RESERVED_01     0x00100078U

#define MSK_NETX_LOCK_RESERVED_01_lock 0xffffffffU // [31:0]
#define SRT_NETX_LOCK_RESERVED_01_lock 0           

enum {
	BFW_NETX_LOCK_RESERVED_01_lock = 32  // [31:0]
};

typedef struct NETX_LOCK_RESERVED01_BIT_Ttag {
	unsigned int lock : BFW_NETX_LOCK_RESERVED_01_lock; // locking purpose 
} NETX_LOCK_RESERVED01_BIT_T;

typedef union {
	unsigned int               val;
	NETX_LOCK_RESERVED01_BIT_T bf;
} NETX_LOCK_RESERVED01_T;


// ---------------------------------------------------------------------
// Register netx_lock_reserved_start
// => reserved start address for netX locking purpose address area - don't implement other registers at 0x80 .. 0xfc! 
// => Mode: Mode (r)
// ---------------------------------------------------------------------

#define REL_NETX_LOCK_RESERVED_BASE 0x00000080U
#define NETX_LOCK_RESERVED_BASE     0x00100080U

#define MSK_NETX_LOCK_RESERVED_BASE_lock 0xffffffffU // [31:0]
#define SRT_NETX_LOCK_RESERVED_BASE_lock 0           

enum {
	BFW_NETX_LOCK_RESERVED_BASE_lock = 32  // [31:0]
};

typedef struct NETX_LOCK_RESERVED_START_BIT_Ttag {
	unsigned int lock : BFW_NETX_LOCK_RESERVED_BASE_lock; // locking purpose 
} NETX_LOCK_RESERVED_START_BIT_T;

typedef union {
	unsigned int                   val;
	NETX_LOCK_RESERVED_START_BIT_T bf;
} NETX_LOCK_RESERVED_START_T;


// ---------------------------------------------------------------------
// Register netx_lock_reserved_end
// => reserved end address for netX locking purpose address area - don't implement other registers at 0x80 .. 0xfc! 
// => Mode: Mode (r)
// ---------------------------------------------------------------------

#define REL_NETX_LOCK_RESERVED_END 0x000000FCU
#define NETX_LOCK_RESERVED_END     0x001000FCU

#define MSK_NETX_LOCK_RESERVED_END_lock 0xffffffffU // [31:0]
#define SRT_NETX_LOCK_RESERVED_END_lock 0           

enum {
	BFW_NETX_LOCK_RESERVED_END_lock = 32  // [31:0]
};

typedef struct NETX_LOCK_RESERVED_END_BIT_Ttag {
	unsigned int lock : BFW_NETX_LOCK_RESERVED_END_lock; // locking purpose 
} NETX_LOCK_RESERVED_END_BIT_T;

typedef union {
	unsigned int                 val;
	NETX_LOCK_RESERVED_END_BIT_T bf;
} NETX_LOCK_RESERVED_END_T;



// =====================================================================
//
// Area of watchdog
//
// =====================================================================

#define NETX_WDG_AREA	0x00100200U


// ---------------------------------------------------------------------
// Register netx_sys_wdg_ctrl
// => netX System Watchdog Trigger Register
//    The watchdog access code is generated by a pseudo random generator.
// => Mode: Mode (r/w)
// ---------------------------------------------------------------------

#define REL_NETX_WDG_TRIG 0x00000000U
#define NETX_WDG_TRIG     0x00100200U

#define MSK_NETX_WDG_TRIG_WDG_ACCESS_CODE 0x0000ffffU // [15:0]
#define SRT_NETX_WDG_TRIG_WDG_ACCESS_CODE 0           

enum {
	BFW_NETX_WDG_TRIG_WDG_ACCESS_CODE = 16, // [15:0]
	BFW_NETX_WDG_TRIG_reserved1       = 16  // [31:16]
};

typedef struct NETX_SYS_WDG_CTRL_BIT_Ttag {
	unsigned int WDG_ACCESS_CODE : BFW_NETX_WDG_TRIG_WDG_ACCESS_CODE; // Watchdog access code for triggering. A read access gives the next 16 bit code for trigger. 
	                                                        // A write access with correct access code will trigger the watchdog counter.
	unsigned int reserved1       : BFW_NETX_WDG_TRIG_reserved1;       // reserved
} NETX_SYS_WDG_CTRL_BIT_T;

typedef union {
	unsigned int            val;
	NETX_SYS_WDG_CTRL_BIT_T bf;
} NETX_SYS_WDG_CTRL_T;


// ---------------------------------------------------------------------
// Register netx_sys_wdg
// => netX System Watchdog Register
// => Mode: Mode (r)
// ---------------------------------------------------------------------

#define REL_NETX_WDG_CNTR 0x00000004U
#define NETX_WDG_CNTR     0x00100204U

#define MSK_NETX_WDG_CNTR_WDG_COUNTER 0x0001ffffU // [16:0]
#define SRT_NETX_WDG_CNTR_WDG_COUNTER 0           

enum {
	BFW_NETX_WDG_CNTR_WDG_COUNTER = 17, // [16:0]
	BFW_NETX_WDG_CNTR_reserved1   = 15  // [31:17]
};

typedef struct NETX_SYS_WDG_BIT_Ttag {
	unsigned int WDG_COUNTER : BFW_NETX_WDG_CNTR_WDG_COUNTER; // Actual watchdog counter value 
	unsigned int reserved1   : BFW_NETX_WDG_CNTR_reserved1;   // reserved
} NETX_SYS_WDG_BIT_T;

typedef union {
	unsigned int       val;
	NETX_SYS_WDG_BIT_T bf;
} NETX_SYS_WDG_T;


// ---------------------------------------------------------------------
// Register netx_sys_wdg_irq_timeout
// => netX System Wachtdog Interrupt Timout Register
// => Mode: Mode (r/w)
// ---------------------------------------------------------------------

#define REL_NETX_WDG_IRQ_TIMEOUT 0x00000008U
#define NETX_WDG_IRQ_TIMEOUT     0x00100208U

#define MSK_NETX_WDG_IRQ_TIMEOUT_WDG_IRQ_TIMEOUT 0x0000ffffU // [15:0]
#define SRT_NETX_WDG_IRQ_TIMEOUT_WDG_IRQ_TIMEOUT 0           

enum {
	BFW_NETX_WDG_IRQ_TIMEOUT_WDG_IRQ_TIMEOUT = 16, // [15:0]
	BFW_NETX_WDG_IRQ_TIMEOUT_reserved1       = 16  // [31:16]
};

typedef struct NETX_SYS_WDG_IRQ_TIMEOUT_BIT_Ttag {
	unsigned int WDG_IRQ_TIMEOUT : BFW_NETX_WDG_IRQ_TIMEOUT_WDG_IRQ_TIMEOUT; // Watchdog interrupt timeout 
	unsigned int reserved1       : BFW_NETX_WDG_IRQ_TIMEOUT_reserved1;       // reserved
} NETX_SYS_WDG_IRQ_TIMEOUT_BIT_T;

typedef union {
	unsigned int                   val;
	NETX_SYS_WDG_IRQ_TIMEOUT_BIT_T bf;
} NETX_SYS_WDG_IRQ_TIMEOUT_T;


// ---------------------------------------------------------------------
// Register netx_sys_wdg_res_timeout
// => netX System Watchdog Reset Timeout Register
// => Mode: Mode (r/w)
// ---------------------------------------------------------------------

#define REL_NETX_WDG_RESET_TIMEOUT 0x0000000CU
#define NETX_WDG_RESET_TIMEOUT     0x0010020CU

#define MSK_NETX_WDG_RESET_TIMEOUT_WDG_RES_TIMEOUT 0x0000ffffU // [15:0]
#define SRT_NETX_WDG_RESET_TIMEOUT_WDG_RES_TIMEOUT 0           

enum {
	BFW_NETX_WDG_RESET_TIMEOUT_WDG_RES_TIMEOUT = 16, // [15:0]
	BFW_NETX_WDG_RESET_TIMEOUT_reserved1       = 16  // [31:16]
};

typedef struct NETX_SYS_WDG_RES_TIMEOUT_BIT_Ttag {
	unsigned int WDG_RES_TIMEOUT : BFW_NETX_WDG_RESET_TIMEOUT_WDG_RES_TIMEOUT; // Watchdog Reset Request Timeout 
	unsigned int reserved1       : BFW_NETX_WDG_RESET_TIMEOUT_reserved1;       // reserved
} NETX_SYS_WDG_RES_TIMEOUT_BIT_T;

typedef union {
	unsigned int                   val;
	NETX_SYS_WDG_RES_TIMEOUT_BIT_T bf;
} NETX_SYS_WDG_RES_TIMEOUT_T;


// ---------------------------------------------------------------------
// Register sta_netx
// => 
// => Mode: 
// ---------------------------------------------------------------------

#define REL_NETX_SYS_STAT 0x000000D8U
#define NETX_SYS_STAT     0x001034D8U


/*************************************************************************************/

#endif /* _SYSFUNC_H */
