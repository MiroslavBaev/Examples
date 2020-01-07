/******************************************************************************

  Copyright (C) 2010 [Hilscher Gesellschaft für Systemautomation mbH]

  This program can be used by everyone according to the netX Open Source
  Software license. The license agreement can be downloaded from
  http://www.industrialNETworX.com

*******************************************************************************

  Last Modification:
    @version $Id: MotCtrl.h 333 2010-04-26 09:32:25Z Volker $

  Description:
    netX MOTCTRL definitions

  Changes:
    Date        Author        Description
  ---------------------------------------------------------------------------
    2010-03-24  NC            File created.

******************************************************************************/


#ifndef _MOTCTRL_H
#define _MOTCTRL_H


/*************************************************************************************/


// ---------------------------------------------------------------------
// Register xmac_pwm_config
// => PWM config register
//    allows to set and reset outputs manually or via counters
//    (see pwm.doc for details)
// => Mode: Mode (r/w)
// ---------------------------------------------------------------------

#define REL_NETX_XM_PWM_CFG   0x0000095CU
#define NETX_XM0_PWM_CFG 0x0016095CU
#define NETX_XM1_PWM_CFG 0x0016195CU
#define NETX_XM2_PWM_CFG 0x0016295CU
#define NETX_XM3_PWM_CFG 0x0016395CU

#define MSK_NETX_XM_PWM_CFG_val_u     0x00000001U // [0]
#define SRT_NETX_XM_PWM_CFG_val_u     0           
#define MSK_NETX_XM_PWM_CFG_val_un    0x00000002U // [1]
#define SRT_NETX_XM_PWM_CFG_val_un    1           
#define MSK_NETX_XM_PWM_CFG_val_v     0x00000004U // [2]
#define SRT_NETX_XM_PWM_CFG_val_v     2           
#define MSK_NETX_XM_PWM_CFG_val_vn    0x00000008U // [3]
#define SRT_NETX_XM_PWM_CFG_val_vn    3           
#define MSK_NETX_XM_PWM_CFG_val_w     0x00000010U // [4]
#define SRT_NETX_XM_PWM_CFG_val_w     4           
#define MSK_NETX_XM_PWM_CFG_val_wn    0x00000020U // [5]
#define SRT_NETX_XM_PWM_CFG_val_wn    5           
#define MSK_NETX_XM_PWM_CFG_fo_mode   0x00000040U // [6]
#define SRT_NETX_XM_PWM_CFG_fo_mode   6           
#define MSK_NETX_XM_PWM_CFG_mpwm_mode 0x00000080U // [7]
#define SRT_NETX_XM_PWM_CFG_mpwm_mode 7           
#define MSK_NETX_XM_PWM_CFG_auto_u    0x00000100U // [8]
#define SRT_NETX_XM_PWM_CFG_auto_u    8           
#define MSK_NETX_XM_PWM_CFG_auto_v    0x00000200U // [9]
#define SRT_NETX_XM_PWM_CFG_auto_v    9           
#define MSK_NETX_XM_PWM_CFG_auto_w    0x00000400U // [10]
#define SRT_NETX_XM_PWM_CFG_auto_w    10          
#define MSK_NETX_XM_PWM_CFG_run_mp    0x00004000U // [14]
#define SRT_NETX_XM_PWM_CFG_run_mp    14          
#define MSK_NETX_XM_PWM_CFG_run_rp    0x00008000U // [15]
#define SRT_NETX_XM_PWM_CFG_run_rp    15          

enum {
	BFW_NETX_XM_PWM_CFG_val_u     = 1,  // [0]
	BFW_NETX_XM_PWM_CFG_val_un    = 1,  // [1]
	BFW_NETX_XM_PWM_CFG_val_v     = 1,  // [2]
	BFW_NETX_XM_PWM_CFG_val_vn    = 1,  // [3]
	BFW_NETX_XM_PWM_CFG_val_w     = 1,  // [4]
	BFW_NETX_XM_PWM_CFG_val_wn    = 1,  // [5]
	BFW_NETX_XM_PWM_CFG_fo_mode   = 1,  // [6]
	BFW_NETX_XM_PWM_CFG_mpwm_mode = 1,  // [7]
	BFW_NETX_XM_PWM_CFG_auto_u    = 1,  // [8]
	BFW_NETX_XM_PWM_CFG_auto_v    = 1,  // [9]
	BFW_NETX_XM_PWM_CFG_auto_w    = 1,  // [10]
	BFW_NETX_XM_PWM_CFG_reserved1 = 3,  // [13:11]
	BFW_NETX_XM_PWM_CFG_run_mp    = 1,  // [14]
	BFW_NETX_XM_PWM_CFG_run_rp    = 1,  // [15]
	BFW_NETX_XM_PWM_CFG_reserved2 = 16  // [31:16]
};

typedef struct XMAC_PWM_CONFIG_BIT_Ttag {
	unsigned int val_u     : BFW_NETX_XM_PWM_CFG_val_u;     // value of pin U  = gpo_pins[0] if auto_u  = 0 
	unsigned int val_un    : BFW_NETX_XM_PWM_CFG_val_un;    // value of pin Un = gpo_pins[1] if auto_un = 0 
	unsigned int val_v     : BFW_NETX_XM_PWM_CFG_val_v;     // value of pin V  = gpo_pins[2] if auto_v  = 0 
	unsigned int val_vn    : BFW_NETX_XM_PWM_CFG_val_vn;    // value of pin Vn = gpo_pins[3] if auto_vn = 0 
	unsigned int val_w     : BFW_NETX_XM_PWM_CFG_val_w;     // value of pin W  = gpo_pins[4] if auto_w  = 0 
	unsigned int val_wn    : BFW_NETX_XM_PWM_CFG_val_wn;    // value of pin Wn = gpo_pins[5] if auto_wn = 0 
	unsigned int fo_mode   : BFW_NETX_XM_PWM_CFG_fo_mode;   // Fiber Optic Mode: 
	                                                        // sets gpo_pins[5:0] = xmac_pwm_config[5:0] in case that tx_data[0] = 1
	                                                        // and gpo_pins[5:0] = 0 in case that tx_data[0] = 0
	unsigned int mpwm_mode : BFW_NETX_XM_PWM_CFG_mpwm_mode; // Motor PWM Mode 
	                                                        // Motor PWM Mode has higher Priority than Fiber Optic Mode
	unsigned int auto_u    : BFW_NETX_XM_PWM_CFG_auto_u;    // 0: set gpo_pins[1:0] to val_u/n;  1: set gpo_pins[1:0] to output of channel U/n  
	unsigned int auto_v    : BFW_NETX_XM_PWM_CFG_auto_v;    // 0: set gpo_pins[3:2] to val_v/n;  1: set gpo_pins[3:2] to output of channel V/n  
	unsigned int auto_w    : BFW_NETX_XM_PWM_CFG_auto_w;    // 0: set gpo_pins[5/4] to val_w/n;  1: set gpo_pins[5:4] to output of channel W/n  
	unsigned int reserved1 : BFW_NETX_XM_PWM_CFG_reserved1; // reserved
	unsigned int run_mp    : BFW_NETX_XM_PWM_CFG_run_mp;    // 0: stop Motor PWM after the actual cycle;  1: run Motor PWM 
	unsigned int run_rp    : BFW_NETX_XM_PWM_CFG_run_rp;    // 0: reset/stop Resolver PWM immediately;  1: run Resolver PWM 
	unsigned int reserved2 : BFW_NETX_XM_PWM_CFG_reserved2; // reserved
} XMAC_PWM_CONFIG_BIT_T;

typedef union {
	unsigned int          val;
	XMAC_PWM_CONFIG_BIT_T bf;
} XMAC_PWM_CONFIG_T;

// ---------------------------------------------------------------------
// Register xmac_pwm_status
// => Status of PWMs
//    (see PWM_POS.doc for details)
//    This register has a write pipeline delay of 1 clock cycle
// => Mode: Mode (r/w)
// ---------------------------------------------------------------------

#define REL_NETX_XM_PWM_STAT   0x00000960U
#define NETX_XM0_PWM_STAT 0x00160960U
#define NETX_XM1_PWM_STAT 0x00161960U
#define NETX_XM2_PWM_STAT 0x00162960U
#define NETX_XM3_PWM_STAT 0x00163960U

#define MSK_NETX_XM_PWM_STAT_systc       0x00000001U // [0]
#define SRT_NETX_XM_PWM_STAT_systc       0           
#define MSK_NETX_XM_PWM_STAT_pwmerr      0x00000040U // [6]
#define SRT_NETX_XM_PWM_STAT_pwmerr      6           
#define MSK_NETX_XM_PWM_STAT_pwmerr_req  0x00000080U // [7]
#define SRT_NETX_XM_PWM_STAT_pwmerr_req  7           
#define MSK_NETX_XM_PWM_STAT_systime_reg 0x00000100U // [8]
#define SRT_NETX_XM_PWM_STAT_systime_reg 8           

enum {
	BFW_NETX_XM_PWM_STAT_systc       = 1,  // [0]
	BFW_NETX_XM_PWM_STAT_reserved1   = 5,  // [5:1]
	BFW_NETX_XM_PWM_STAT_pwmerr      = 1,  // [6]
	BFW_NETX_XM_PWM_STAT_pwmerr_req  = 1,  // [7]
	BFW_NETX_XM_PWM_STAT_systime_reg = 1,  // [8]
	BFW_NETX_XM_PWM_STAT_reserved2   = 23  // [31:9]
};

typedef struct XMAC_PWM_STATUS_BIT_Ttag {
	unsigned int systc       : BFW_NETX_XM_PWM_STAT_systc;       // Systime captured at PWM = 0 
	unsigned int reserved1   : BFW_NETX_XM_PWM_STAT_reserved1;   // reserved
	unsigned int pwmerr      : BFW_NETX_XM_PWM_STAT_pwmerr;      // Actual PWM failure signal 
	unsigned int pwmerr_req  : BFW_NETX_XM_PWM_STAT_pwmerr_req;  // Latched PWM failure signal 
	unsigned int systime_reg : BFW_NETX_XM_PWM_STAT_systime_reg; // Systime captured at RPWM = 0 
	unsigned int reserved2   : BFW_NETX_XM_PWM_STAT_reserved2;   // reserved
} XMAC_PWM_STATUS_BIT_T;

typedef union {
	unsigned int          val;
	XMAC_PWM_STATUS_BIT_T bf;
} XMAC_PWM_STATUS_T;

// ---------------------------------------------------------------------
// Register xmac_pwm_tp
// => PWM Period
//    (see pwm.doc for details)
//    This register has a write pipeline delay of 1 clock cycle
// => Mode: Mode (r/w)
// ---------------------------------------------------------------------

#define REL_NETX_XM_PWM_TP   0x00000964U
#define NETX_XM0_PWM_TP 0x00160964U
#define NETX_XM1_PWM_TP 0x00161964U
#define NETX_XM2_PWM_TP 0x00162964U
#define NETX_XM3_PWM_TP 0x00163964U

#define MSK_NETX_XM_PWM_TP_tp 0x0000ffffU // [15:0]
#define SRT_NETX_XM_PWM_TP_tp 0           

enum {
	BFW_NETX_XM_PWM_TP_tp        = 16, // [15:0]
	BFW_NETX_XM_PWM_TP_reserved1 = 16  // [31:16]
};

typedef struct XMAC_PWM_TP_BIT_Ttag {
	unsigned int tp        : BFW_NETX_XM_PWM_TP_tp;        // Length of PWM Period (bit 0 unused due to triangular counting) in clockcycles 
	unsigned int reserved1 : BFW_NETX_XM_PWM_TP_reserved1; // reserved
} XMAC_PWM_TP_BIT_T;

typedef union {
	unsigned int      val;
	XMAC_PWM_TP_BIT_T bf;
} XMAC_PWM_TP_T;

// ---------------------------------------------------------------------
// Register xmac_pwm_tu
// => PWM channel U low phase width
//    (see pwm.doc for details)
//    This register has a write pipeline delay of 1 clock cycle
// => Mode: Mode (r/w)
// ---------------------------------------------------------------------

#define REL_NETX_XM_PWM_TU   0x00000968U
#define NETX_XM0_PWM_TU 0x00160968U
#define NETX_XM1_PWM_TU 0x00161968U
#define NETX_XM2_PWM_TU 0x00162968U
#define NETX_XM3_PWM_TU 0x00163968U

#define MSK_NETX_XM_PWM_TU_level_u 0x0000ffffU // [15:0]
#define SRT_NETX_XM_PWM_TU_level_u 0           

enum {
	BFW_NETX_XM_PWM_TU_level_u   = 16, // [15:0]
	BFW_NETX_XM_PWM_TU_reserved1 = 16  // [31:16]
};

typedef struct XMAC_PWM_TU_BIT_Ttag {
	unsigned int level_u   : BFW_NETX_XM_PWM_TU_level_u;   // width of cannel U low phase in clockcycles 
	unsigned int reserved1 : BFW_NETX_XM_PWM_TU_reserved1; // reserved
} XMAC_PWM_TU_BIT_T;

typedef union {
	unsigned int      val;
	XMAC_PWM_TU_BIT_T bf;
} XMAC_PWM_TU_T;

// ---------------------------------------------------------------------
// Register xmac_pwm_tv
// => PWM channel V low phase width
//    (see pwm.doc for details)
//    This register has a write pipeline delay of 1 clock cycle
// => Mode: Mode (r/w)
// ---------------------------------------------------------------------

#define REL_NETX_XM_PWM_TV   0x0000096CU
#define NETX_XM0_PWM_TV 0x0016096CU
#define NETX_XM1_PWM_TV 0x0016196CU
#define NETX_XM2_PWM_TV 0x0016296CU
#define NETX_XM3_PWM_TV 0x0016396CU

#define MSK_NETX_XM_PWM_TV_level_u 0x0000ffffU // [15:0]
#define SRT_NETX_XM_PWM_TV_level_u 0           

enum {
	BFW_NETX_XM_PWM_TV_level_u   = 16, // [15:0]
	BFW_NETX_XM_PWM_TV_reserved1 = 16  // [31:16]
};

typedef struct XMAC_PWM_TV_BIT_Ttag {
	unsigned int level_u   : BFW_NETX_XM_PWM_TV_level_u;   // width of cannel U low phase in clockcycles 
	unsigned int reserved1 : BFW_NETX_XM_PWM_TV_reserved1; // reserved
} XMAC_PWM_TV_BIT_T;

typedef union {
	unsigned int      val;
	XMAC_PWM_TV_BIT_T bf;
} XMAC_PWM_TV_T;

// ---------------------------------------------------------------------
// Register xmac_pwm_tw
// => PWM channel W low phase width
//    (see pwm.doc for details)
//    This register has a write pipeline delay of 1 clock cycle
// => Mode: Mode (r/w)
// ---------------------------------------------------------------------

#define REL_NETX_XM_PWM_TW   0x00000970U
#define NETX_XM0_PWM_TW 0x00160970U
#define NETX_XM1_PWM_TW 0x00161970U
#define NETX_XM2_PWM_TW 0x00162970U
#define NETX_XM3_PWM_TW 0x00163970U

#define MSK_NETX_XM_PWM_TW_level_u 0x0000ffffU // [15:0]
#define SRT_NETX_XM_PWM_TW_level_u 0           

enum {
	BFW_NETX_XM_PWM_TW_level_u   = 16, // [15:0]
	BFW_NETX_XM_PWM_TW_reserved1 = 16  // [31:16]
};

typedef struct XMAC_PWM_TW_BIT_Ttag {
	unsigned int level_u   : BFW_NETX_XM_PWM_TW_level_u;   // width of cannel U low phase in clockcycles 
	unsigned int reserved1 : BFW_NETX_XM_PWM_TW_reserved1; // reserved
} XMAC_PWM_TW_BIT_T;

typedef union {
	unsigned int      val;
	XMAC_PWM_TW_BIT_T bf;
} XMAC_PWM_TW_T;

// ---------------------------------------------------------------------
// Register xmac_pwm_td
// => PWM dead time counter preload
//    (see pwm.doc for details)
//    This register has a write pipeline delay of 1 clock cycle
// => Mode: Mode (r/w)
// ---------------------------------------------------------------------

#define REL_NETX_XM_PWM_TD   0x00000974U
#define NETX_XM0_PWM_TD 0x00160974U
#define NETX_XM1_PWM_TD 0x00161974U
#define NETX_XM2_PWM_TD 0x00162974U
#define NETX_XM3_PWM_TD 0x00163974U

#define MSK_NETX_XM_PWM_TD_preload_d 0x0000ffffU // [15:0]
#define SRT_NETX_XM_PWM_TD_preload_d 0           

enum {
	BFW_NETX_XM_PWM_TD_preload_d = 16, // [15:0]
	BFW_NETX_XM_PWM_TD_reserved1 = 16  // [31:16]
};

typedef struct XMAC_PWM_TD_BIT_Ttag {
	unsigned int preload_d : BFW_NETX_XM_PWM_TD_preload_d; // counter preload for dead time in clockcycles 
	unsigned int reserved1 : BFW_NETX_XM_PWM_TD_reserved1; // reserved
} XMAC_PWM_TD_BIT_T;

typedef union {
	unsigned int      val;
	XMAC_PWM_TD_BIT_T bf;
} XMAC_PWM_TD_T;

// ---------------------------------------------------------------------
// Register xmac_rpwm_tp
// => Resolver PWM Period
//    (see PWM_POS.doc for details)
//    This register has a write pipeline delay of 1 clock cycle
// => Mode: Mode (r/w)
// ---------------------------------------------------------------------

#define REL_NETX_XM_RPWM_TP   0x00000978U
#define NETX_XM0_RPWM_TP 0x00160978U
#define NETX_XM1_RPWM_TP 0x00161978U
#define NETX_XM2_RPWM_TP 0x00162978U
#define NETX_XM3_RPWM_TP 0x00163978U

#define MSK_NETX_XM_RPWM_TP_res_tp 0x0000ffffU // [15:0]
#define SRT_NETX_XM_RPWM_TP_res_tp 0           

enum {
	BFW_NETX_XM_RPWM_TP_res_tp    = 16, // [15:0]
	BFW_NETX_XM_RPWM_TP_reserved1 = 16  // [31:16]
};

typedef struct XMAC_RPWM_TP_BIT_Ttag {
	unsigned int res_tp    : BFW_NETX_XM_RPWM_TP_res_tp;    // Resolver PWM Period 
	unsigned int reserved1 : BFW_NETX_XM_RPWM_TP_reserved1; // reserved
} XMAC_RPWM_TP_BIT_T;

typedef union {
	unsigned int       val;
	XMAC_RPWM_TP_BIT_T bf;
} XMAC_RPWM_TP_T;

// ---------------------------------------------------------------------
// Register xmac_rpwm_tr
// => Resolver PWM Pulse
//    (see PWM_POS.doc for details)
//    This register has a write pipeline delay of 1 clock cycle
// => Mode: Mode (r/w)
// ---------------------------------------------------------------------

#define REL_NETX_XM_RPWM_TR   0x0000097CU
#define NETX_XM0_RPWM_TR 0x0016097CU
#define NETX_XM1_RPWM_TR 0x0016197CU
#define NETX_XM2_RPWM_TR 0x0016297CU
#define NETX_XM3_RPWM_TR 0x0016397CU

#define MSK_NETX_XM_RPWM_TR_res_tr 0x0000ffffU // [15:0]
#define SRT_NETX_XM_RPWM_TR_res_tr 0           

enum {
	BFW_NETX_XM_RPWM_TR_res_tr    = 16, // [15:0]
	BFW_NETX_XM_RPWM_TR_reserved1 = 16  // [31:16]
};

typedef struct XMAC_RPWM_TR_BIT_Ttag {
	unsigned int res_tr    : BFW_NETX_XM_RPWM_TR_res_tr;    // Resolver PWM Pulse 
	unsigned int reserved1 : BFW_NETX_XM_RPWM_TR_reserved1; // reserved
} XMAC_RPWM_TR_BIT_T;

typedef union {
	unsigned int       val;
	XMAC_RPWM_TR_BIT_T bf;
} XMAC_RPWM_TR_T;

// ---------------------------------------------------------------------
// Register xmac_pwm_cnt
// => Actual counter Motor PWM Periode
//    (see PWM_POS.doc for details)
//    This register has a write pipeline delay of 1 clock cycle
// => Mode: Mode (r)
// ---------------------------------------------------------------------

#define REL_NETX_XM_PWM_CNT   0x00000980U
#define NETX_XM0_PWM_CNT 0x00160980U
#define NETX_XM1_PWM_CNT 0x00161980U
#define NETX_XM2_PWM_CNT 0x00162980U
#define NETX_XM3_PWM_CNT 0x00163980U

#define MSK_NETX_XM_PWM_CNT_pwm_cnt 0x0000ffffU // [15:0]
#define SRT_NETX_XM_PWM_CNT_pwm_cnt 0           

enum {
	BFW_NETX_XM_PWM_CNT_pwm_cnt   = 16, // [15:0]
	BFW_NETX_XM_PWM_CNT_reserved1 = 16  // [31:16]
};

typedef struct XMAC_PWM_CNT_BIT_Ttag {
	unsigned int pwm_cnt   : BFW_NETX_XM_PWM_CNT_pwm_cnt;   // Actual counter Motor PWM Periode 
	unsigned int reserved1 : BFW_NETX_XM_PWM_CNT_reserved1; // reserved
} XMAC_PWM_CNT_BIT_T;

typedef union {
	unsigned int       val;
	XMAC_PWM_CNT_BIT_T bf;
} XMAC_PWM_CNT_T;

// ---------------------------------------------------------------------
// Register xmac_rpwm_cnt
// => Actual counter Resolver PWM Period
//    (see PWM_POS.doc for details)
//    This register has a write pipeline delay of 1 clock cycle
// => Mode: Mode (r)
// ---------------------------------------------------------------------

#define REL_NETX_XM_RPWM_CNT   0x00000984U
#define NETX_XM0_RPWM_CNT 0x00160984U
#define NETX_XM1_RPWM_CNT 0x00161984U
#define NETX_XM2_RPWM_CNT 0x00162984U
#define NETX_XM3_RPWM_CNT 0x00163984U

#define MSK_NETX_XM_RPWM_CNT_rpwm_cnt 0x0000ffffU // [15:0]
#define SRT_NETX_XM_RPWM_CNT_rpwm_cnt 0           

enum {
	BFW_NETX_XM_RPWM_CNT_rpwm_cnt  = 16, // [15:0]
	BFW_NETX_XM_RPWM_CNT_reserved1 = 16  // [31:16]
};

typedef struct XMAC_RPWM_CNT_BIT_Ttag {
	unsigned int rpwm_cnt  : BFW_NETX_XM_RPWM_CNT_rpwm_cnt;  // Actual counter Resolver PWM Period 
	unsigned int reserved1 : BFW_NETX_XM_RPWM_CNT_reserved1; // reserved
} XMAC_RPWM_CNT_BIT_T;

typedef union {
	unsigned int        val;
	XMAC_RPWM_CNT_BIT_T bf;
} XMAC_RPWM_CNT_T;

// ---------------------------------------------------------------------
// Register xmac_pwm_strtime
// => Captured Systime at start point of Motor PWM Period
//    (see PWM_POS.doc for details)
//    This register has a write pipeline delay of 1 clock cycle
// => Mode: Mode (r)
// ---------------------------------------------------------------------

#define REL_NETX_XM_PWM_TD_STRTIME   0x00000988U
#define NETX_XM0_PWM_STRTIME 0x00160988U
#define NETX_XM1_PWM_STRTIME 0x00161988U
#define NETX_XM2_PWM_STRTIME 0x00162988U
#define NETX_XM3_PWM_STRTIME 0x00163988U

#define MSK_NETX_XM_PWM_TD_STRTIME_pwm_strtime 0x0000ffffU // [15:0]
#define SRT_NETX_XM_PWM_TD_STRTIME_pwm_strtime 0           

enum {
	BFW_NETX_XM_PWM_TD_STRTIME_pwm_strtime = 16, // [15:0]
	BFW_NETX_XM_PWM_TD_STRTIME_reserved1   = 16  // [31:16]
};

typedef struct XMAC_PWM_STRTIME_BIT_Ttag {
	unsigned int pwm_strtime : BFW_NETX_XM_PWM_TD_STRTIME_pwm_strtime; // Captured Systime at start point of Motor PWM Period 
	unsigned int reserved1   : BFW_NETX_XM_PWM_TD_STRTIME_reserved1;   // reserved
} XMAC_PWM_STRTIME_BIT_T;

typedef union {
	unsigned int           val;
	XMAC_PWM_STRTIME_BIT_T bf;
} XMAC_PWM_STRTIME_T;

// ---------------------------------------------------------------------
// Register xmac_rpwm_strtime
// => Captured Systime at start point of Resolver PWM Period
//    (see PWM_POS.doc for details)
//    This register has a write pipeline delay of 1 clock cycle
// => Mode: Mode (r)
// ---------------------------------------------------------------------

#define REL_NETX_XM_RPWM_TD_STRTIME   0x0000098CU
#define NETX_XM0_RPWM_STRTIME 0x0016098CU
#define NETX_XM1_RPWM_STRTIME 0x0016198CU
#define NETX_XM2_RPWM_STRTIME 0x0016298CU
#define NETX_XM3_RPWM_STRTIME 0x0016398CU

#define MSK_NETX_XM_RPWM_TD_STRTIME_rpwm_strtime 0x0000ffffU // [15:0]
#define SRT_NETX_XM_RPWM_TD_STRTIME_rpwm_strtime 0           

enum {
	BFW_NETX_XM_RPWM_TD_STRTIME_rpwm_strtime = 16, // [15:0]
	BFW_NETX_XM_RPWM_TD_STRTIME_reserved1    = 16  // [31:16]
};

typedef struct XMAC_RPWM_STRTIME_BIT_Ttag {
	unsigned int rpwm_strtime : BFW_NETX_XM_RPWM_TD_STRTIME_rpwm_strtime; // Captured Systime at start point of Resolver PWM Period 
	unsigned int reserved1    : BFW_NETX_XM_RPWM_TD_STRTIME_reserved1;    // reserved
} XMAC_RPWM_STRTIME_BIT_T;

typedef union {
	unsigned int            val;
	XMAC_RPWM_STRTIME_BIT_T bf;
} XMAC_RPWM_STRTIME_T;

// ---------------------------------------------------------------------
// Register xmac_pos_config_encoder
// => Configuration encoder register
//    (see PWM_POS.doc for details)
//    This register has a write pipeline delay of 1 clock cycle
// => Mode: Mode(r/w)
// ---------------------------------------------------------------------

#define REL_NETX_XM_ENC_CFG   0x00000990U
#define NETX_XM0_ENC_CFG 0x00160990U
#define NETX_XM1_ENC_CFG 0x00161990U
#define NETX_XM2_ENC_CFG 0x00162990U
#define NETX_XM3_ENC_CFG 0x00163990U

#define MSK_NETX_XM_ENC_CFG_enc0_filter_sample_rate 0x00000007U // [2:0]
#define SRT_NETX_XM_ENC_CFG_enc0_filter_sample_rate 0           
#define MSK_NETX_XM_ENC_CFG_enc0_count_dir          0x00000008U // [3]
#define SRT_NETX_XM_ENC_CFG_enc0_count_dir          3           
#define MSK_NETX_XM_ENC_CFG_enc0_n_quant            0x00000030U // [5:4]
#define SRT_NETX_XM_ENC_CFG_enc0_n_quant            4           
#define MSK_NETX_XM_ENC_CFG_enc1_filter_sample_rate 0x00000700U // [10:8]
#define SRT_NETX_XM_ENC_CFG_enc1_filter_sample_rate 8           
#define MSK_NETX_XM_ENC_CFG_enc1_count_dir          0x00000800U // [11]
#define SRT_NETX_XM_ENC_CFG_enc1_count_dir          11          
#define MSK_NETX_XM_ENC_CFG_enc1_n_quant            0x00003000U // [13:12]
#define SRT_NETX_XM_ENC_CFG_enc1_n_quant            12          

enum {
	BFW_NETX_XM_ENC_CFG_enc0_filter_sample_rate = 3,  // [2:0]
	BFW_NETX_XM_ENC_CFG_enc0_count_dir          = 1,  // [3]
	BFW_NETX_XM_ENC_CFG_enc0_n_quant            = 2,  // [5:4]
	BFW_NETX_XM_ENC_CFG_reserved1               = 2,  // [7:6]
	BFW_NETX_XM_ENC_CFG_enc1_filter_sample_rate = 3,  // [10:8]
	BFW_NETX_XM_ENC_CFG_enc1_count_dir          = 1,  // [11]
	BFW_NETX_XM_ENC_CFG_enc1_n_quant            = 2,  // [13:12]
	BFW_NETX_XM_ENC_CFG_reserved2               = 18  // [31:14]
};

typedef struct XMAC_POS_CONFIG_ENCODER_BIT_Ttag {
	unsigned int enc0_filter_sample_rate : BFW_NETX_XM_ENC_CFG_enc0_filter_sample_rate; // Encoder 0 filter sample rate 
	                                                        // 0: none
	                                                        // 1: 10 ns
	                                                        // 2: 20 ns
	                                                        // 3: 50 ns
	                                                        // 4: 100 ns
	                                                        // 5: 200 ns
	                                                        // 6: 500 ns
	                                                        // 7: 1 us
	unsigned int enc0_count_dir          : BFW_NETX_XM_ENC_CFG_enc0_count_dir;          // Encoder 0 count direction # 0
	                                                        // 0: up, 1: down
	unsigned int enc0_n_quant            : BFW_NETX_XM_ENC_CFG_enc0_n_quant;            // Encoder 0 N-qualifier
	                                                        // 0: none, sampled with every N pulse
	                                                        // 1: N-Signal channel 1 = 1
	                                                        // 2: MP0 = 1
	                                                        // 3: MP1 = 1
	unsigned int reserved1               : BFW_NETX_XM_ENC_CFG_reserved1;               // reserved
	unsigned int enc1_filter_sample_rate : BFW_NETX_XM_ENC_CFG_enc1_filter_sample_rate; // Encoder 1 filter sample rate 
	                                                        // 0: none
	                                                        // 1: 10 ns
	                                                        // 2: 20 ns
	                                                        // 3: 50 ns
	                                                        // 4: 100 ns
	                                                        // 5: 200 ns
	                                                        // 6: 500 ns
	                                                        // 7: 1 us
	unsigned int enc1_count_dir          : BFW_NETX_XM_ENC_CFG_enc1_count_dir;          // Encoder 1 count direction # 0
	                                                        // 0: up, 1: down
	unsigned int enc1_n_quant            : BFW_NETX_XM_ENC_CFG_enc1_n_quant;            // Encoder 1 N-qualifier
	                                                        // 0: none, sampled with every N pulse
	                                                        // 1: N-Signal channel 1 = 1
	                                                        // 2: MP0 = 1
	                                                        // 3: MP1 = 1
	unsigned int reserved2               : BFW_NETX_XM_ENC_CFG_reserved2;               // reserved
} XMAC_POS_CONFIG_ENCODER_BIT_T;

typedef union {
	unsigned int                  val;
	XMAC_POS_CONFIG_ENCODER_BIT_T bf;
} XMAC_POS_CONFIG_ENCODER_T;

// ---------------------------------------------------------------------
// Register xmac_pos_config_capture
// => Configuration capture register
//    (see PWM_POS.doc for details)
//    This register has a write pipeline delay of 1 clock cycle
// => Mode: Mode(r/w)
// ---------------------------------------------------------------------

#define REL_NETX_XM_ENC_CFG_CAPT   0x00000994U
#define NETX_XM0_ENC_CFG_CAPT 0x00160994U
#define NETX_XM1_ENC_CFG_CAPT 0x00161994U
#define NETX_XM2_ENC_CFG_CAPT 0x00162994U
#define NETX_XM3_ENC_CFG_CAPT 0x00163994U

#define MSK_NETX_XM_ENC_CFG_CAPT_creg0_cw  0x00000003U // [1:0]
#define SRT_NETX_XM_ENC_CFG_CAPT_creg0_cw  0           
#define MSK_NETX_XM_ENC_CFG_CAPT_creg0_src 0x0000000cU // [3:2]
#define SRT_NETX_XM_ENC_CFG_CAPT_creg0_src 2           
#define MSK_NETX_XM_ENC_CFG_CAPT_creg1_cw  0x00000030U // [5:4]
#define SRT_NETX_XM_ENC_CFG_CAPT_creg1_cw  4           
#define MSK_NETX_XM_ENC_CFG_CAPT_creg1_src 0x000000c0U // [7:6]
#define SRT_NETX_XM_ENC_CFG_CAPT_creg1_src 6           
#define MSK_NETX_XM_ENC_CFG_CAPT_creg2_cw  0x00000300U // [9:8]
#define SRT_NETX_XM_ENC_CFG_CAPT_creg2_cw  8           
#define MSK_NETX_XM_ENC_CFG_CAPT_creg2_src 0x00000c00U // [11:10]
#define SRT_NETX_XM_ENC_CFG_CAPT_creg2_src 10          
#define MSK_NETX_XM_ENC_CFG_CAPT_creg3_cw  0x00003000U // [13:12]
#define SRT_NETX_XM_ENC_CFG_CAPT_creg3_cw  12          
#define MSK_NETX_XM_ENC_CFG_CAPT_creg3_src 0x0000c000U // [15:14]
#define SRT_NETX_XM_ENC_CFG_CAPT_creg3_src 14          

enum {
	BFW_NETX_XM_ENC_CFG_CAPT_creg0_cw  = 2,  // [1:0]
	BFW_NETX_XM_ENC_CFG_CAPT_creg0_src = 2,  // [3:2]
	BFW_NETX_XM_ENC_CFG_CAPT_creg1_cw  = 2,  // [5:4]
	BFW_NETX_XM_ENC_CFG_CAPT_creg1_src = 2,  // [7:6]
	BFW_NETX_XM_ENC_CFG_CAPT_creg2_cw  = 2,  // [9:8]
	BFW_NETX_XM_ENC_CFG_CAPT_creg2_src = 2,  // [11:10]
	BFW_NETX_XM_ENC_CFG_CAPT_creg3_cw  = 2,  // [13:12]
	BFW_NETX_XM_ENC_CFG_CAPT_creg3_src = 2,  // [15:14]
	BFW_NETX_XM_ENC_CFG_CAPT_reserved1 = 16  // [31:16]
};

typedef struct XMAC_POS_CONFIG_CAPTURE_BIT_Ttag {
	unsigned int creg0_cw  : BFW_NETX_XM_ENC_CFG_CAPT_creg0_cw;  // Capture register0, capture with 
	                                                        // 0: mp0 positive edge
	                                                        // 1: mp0 negative edge
	                                                        // 2: mp1 positive edge
	                                                        // 3: mp1 negative edge
	unsigned int creg0_src : BFW_NETX_XM_ENC_CFG_CAPT_creg0_src; // Capture register0, source 
	                                                        // 0: none
	                                                        // 1: system time ns
	                                                        // 2: position channel 0
	                                                        // 3: position channel 1
	unsigned int creg1_cw  : BFW_NETX_XM_ENC_CFG_CAPT_creg1_cw;  // Capture register1, capture with 
	                                                        // 0: mp0 positive edge
	                                                        // 1: mp0 negative edge
	                                                        // 2: mp1 positive edge
	                                                        // 3: mp1 negative edge
	unsigned int creg1_src : BFW_NETX_XM_ENC_CFG_CAPT_creg1_src; // Capture register1, source 
	                                                        // 0: none
	                                                        // 1: system time ns
	                                                        // 2: position channel 0
	                                                        // 3: position channel 1
	unsigned int creg2_cw  : BFW_NETX_XM_ENC_CFG_CAPT_creg2_cw;  // Capture register2, capture with 
	                                                        // 0: mp0 positive edge
	                                                        // 1: mp0 negative edge
	                                                        // 2: mp1 positive edge
	                                                        // 3: mp1 negative edge
	unsigned int creg2_src : BFW_NETX_XM_ENC_CFG_CAPT_creg2_src; // Capture register2, source 
	                                                        // 0: none
	                                                        // 1: system time ns
	                                                        // 2: position channel 0
	                                                        // 3: position channel 1
	unsigned int creg3_cw  : BFW_NETX_XM_ENC_CFG_CAPT_creg3_cw;  // Capture register3, capture with 
	                                                        // 0: mp0 positive edge
	                                                        // 1: mp0 negative edge
	                                                        // 2: mp1 positive edge
	                                                        // 3: mp1 negative edge
	unsigned int creg3_src : BFW_NETX_XM_ENC_CFG_CAPT_creg3_src; // Capture register3, source 
	                                                        // 0: none
	                                                        // 1: system time ns
	                                                        // 2: position channel 0
	                                                        // 3: position channel 1
	unsigned int reserved1 : BFW_NETX_XM_ENC_CFG_CAPT_reserved1; // reserved
} XMAC_POS_CONFIG_CAPTURE_BIT_T;

typedef union {
	unsigned int                  val;
	XMAC_POS_CONFIG_CAPTURE_BIT_T bf;
} XMAC_POS_CONFIG_CAPTURE_T;

// ---------------------------------------------------------------------
// Register xmac_pos_command
// => Command register
//    (see PWM_POS.doc for details)
// => Mode: Mode(r/w)
// ---------------------------------------------------------------------

#define REL_NETX_XM_ENC_CMD   0x00000998U
#define NETX_XM0_ENC_CMD 0x00160998U
#define NETX_XM1_ENC_CMD 0x00161998U
#define NETX_XM2_ENC_CMD 0x00162998U
#define NETX_XM3_ENC_CMD 0x00163998U

#define MSK_NETX_XM_ENC_CMD_enc0_en       0x00000001U // [0]
#define SRT_NETX_XM_ENC_CMD_enc0_en       0           
#define MSK_NETX_XM_ENC_CMD_enc0_res_pos  0x00000002U // [1]
#define SRT_NETX_XM_ENC_CMD_enc0_res_pos  1           
#define MSK_NETX_XM_ENC_CMD_enc0_res_zpos 0x00000004U // [2]
#define SRT_NETX_XM_ENC_CMD_enc0_res_zpos 2           
#define MSK_NETX_XM_ENC_CMD_enc1_en       0x00000100U // [8]
#define SRT_NETX_XM_ENC_CMD_enc1_en       8           
#define MSK_NETX_XM_ENC_CMD_enc1_res_pos  0x00000200U // [9]
#define SRT_NETX_XM_ENC_CMD_enc1_res_pos  9           
#define MSK_NETX_XM_ENC_CMD_enc1_res_zpos 0x00000400U // [10]
#define SRT_NETX_XM_ENC_CMD_enc1_res_zpos 10          

enum {
	BFW_NETX_XM_ENC_CMD_enc0_en       = 1,  // [0]
	BFW_NETX_XM_ENC_CMD_enc0_res_pos  = 1,  // [1]
	BFW_NETX_XM_ENC_CMD_enc0_res_zpos = 1,  // [2]
	BFW_NETX_XM_ENC_CMD_reserved1     = 5,  // [7:3]
	BFW_NETX_XM_ENC_CMD_enc1_en       = 1,  // [8]
	BFW_NETX_XM_ENC_CMD_enc1_res_pos  = 1,  // [9]
	BFW_NETX_XM_ENC_CMD_enc1_res_zpos = 1,  // [10]
	BFW_NETX_XM_ENC_CMD_reserved2     = 21  // [31:11]
};

typedef struct XMAC_POS_COMMAND_BIT_Ttag {
	unsigned int enc0_en       : BFW_NETX_XM_ENC_CMD_enc0_en;       // Encoder0 enable 
	unsigned int enc0_res_pos  : BFW_NETX_XM_ENC_CMD_enc0_res_pos;  // Encoder0 reset position 
	unsigned int enc0_res_zpos : BFW_NETX_XM_ENC_CMD_enc0_res_zpos; // Encoder0 reset null position 
	unsigned int reserved1     : BFW_NETX_XM_ENC_CMD_reserved1;     // reserved
	unsigned int enc1_en       : BFW_NETX_XM_ENC_CMD_enc1_en;       // Encoder1 enable 
	unsigned int enc1_res_pos  : BFW_NETX_XM_ENC_CMD_enc1_res_pos;  // Encoder1 reset position 
	unsigned int enc1_res_zpos : BFW_NETX_XM_ENC_CMD_enc1_res_zpos; // Encoder1 reset null position 
	unsigned int reserved2     : BFW_NETX_XM_ENC_CMD_reserved2;     // reserved
} XMAC_POS_COMMAND_BIT_T;

typedef union {
	unsigned int           val;
	XMAC_POS_COMMAND_BIT_T bf;
} XMAC_POS_COMMAND_T;

// ---------------------------------------------------------------------
// Register xmac_pos_status
// => Position and capture status, Bit  0: Encoder 0 overflow positive, Bit  1: Encoder 1 overflow negativ
//    (see PWM_POS.doc for details)
//    This register has a write pipeline delay of 1 clock cycle
// => Mode: Mode(r/w)
// ---------------------------------------------------------------------

#define REL_NETX_XM_ENC_STAT   0x0000099CU
#define NETX_XM0_ENC_STAT 0x0016099CU
#define NETX_XM1_ENC_STAT 0x0016199CU
#define NETX_XM2_ENC_STAT 0x0016299CU
#define NETX_XM3_ENC_STAT 0x0016399CU

#define MSK_NETX_XM_ENC_STAT_enc0_ovfl_pos  0x00000001U // [0]
#define SRT_NETX_XM_ENC_STAT_enc0_ovfl_pos  0           
#define MSK_NETX_XM_ENC_STAT_enc0_ovfl_neg  0x00000002U // [1]
#define SRT_NETX_XM_ENC_STAT_enc0_ovfl_neg  1           
#define MSK_NETX_XM_ENC_STAT_enc0_cap_zpos  0x00000004U // [2]
#define SRT_NETX_XM_ENC_STAT_enc0_cap_zpos  2           
#define MSK_NETX_XM_ENC_STAT_enc0_cap_etime 0x00000008U // [3]
#define SRT_NETX_XM_ENC_STAT_enc0_cap_etime 3           
#define MSK_NETX_XM_ENC_STAT_enc1_ovfl_pos  0x00000010U // [4]
#define SRT_NETX_XM_ENC_STAT_enc1_ovfl_pos  4           
#define MSK_NETX_XM_ENC_STAT_enc1_ovfl_neg  0x00000020U // [5]
#define SRT_NETX_XM_ENC_STAT_enc1_ovfl_neg  5           
#define MSK_NETX_XM_ENC_STAT_enc1_cap_zpos  0x00000040U // [6]
#define SRT_NETX_XM_ENC_STAT_enc1_cap_zpos  6           
#define MSK_NETX_XM_ENC_STAT_enc1_cap_etime 0x00000080U // [7]
#define SRT_NETX_XM_ENC_STAT_enc1_cap_etime 7           
#define MSK_NETX_XM_ENC_STAT_cap0           0x00000100U // [8]
#define SRT_NETX_XM_ENC_STAT_cap0           8           
#define MSK_NETX_XM_ENC_STAT_cap1           0x00000200U // [9]
#define SRT_NETX_XM_ENC_STAT_cap1           9           
#define MSK_NETX_XM_ENC_STAT_cap2           0x00000400U // [10]
#define SRT_NETX_XM_ENC_STAT_cap2           10          
#define MSK_NETX_XM_ENC_STAT_cap3           0x00000800U // [11]
#define SRT_NETX_XM_ENC_STAT_cap3           11          
#define MSK_NETX_XM_ENC_STAT_enc0_sign      0x00001000U // [12]
#define SRT_NETX_XM_ENC_STAT_enc0_sign      12          
#define MSK_NETX_XM_ENC_STAT_enc1_sign      0x00002000U // [13]
#define SRT_NETX_XM_ENC_STAT_enc1_sign      13          
#define MSK_NETX_XM_ENC_STAT_mp0            0x00004000U // [14]
#define SRT_NETX_XM_ENC_STAT_mp0            14          
#define MSK_NETX_XM_ENC_STAT_mp1            0x00008000U // [15]
#define SRT_NETX_XM_ENC_STAT_mp1            15          

enum {
	BFW_NETX_XM_ENC_STAT_enc0_ovfl_pos  = 1,  // [0]
	BFW_NETX_XM_ENC_STAT_enc0_ovfl_neg  = 1,  // [1]
	BFW_NETX_XM_ENC_STAT_enc0_cap_zpos  = 1,  // [2]
	BFW_NETX_XM_ENC_STAT_enc0_cap_etime = 1,  // [3]
	BFW_NETX_XM_ENC_STAT_enc1_ovfl_pos  = 1,  // [4]
	BFW_NETX_XM_ENC_STAT_enc1_ovfl_neg  = 1,  // [5]
	BFW_NETX_XM_ENC_STAT_enc1_cap_zpos  = 1,  // [6]
	BFW_NETX_XM_ENC_STAT_enc1_cap_etime = 1,  // [7]
	BFW_NETX_XM_ENC_STAT_cap0           = 1,  // [8]
	BFW_NETX_XM_ENC_STAT_cap1           = 1,  // [9]
	BFW_NETX_XM_ENC_STAT_cap2           = 1,  // [10]
	BFW_NETX_XM_ENC_STAT_cap3           = 1,  // [11]
	BFW_NETX_XM_ENC_STAT_enc0_sign      = 1,  // [12]
	BFW_NETX_XM_ENC_STAT_enc1_sign      = 1,  // [13]
	BFW_NETX_XM_ENC_STAT_mp0            = 1,  // [14]
	BFW_NETX_XM_ENC_STAT_mp1            = 1,  // [15]
	BFW_NETX_XM_ENC_STAT_reserved1      = 16  // [31:16]
};

typedef struct XMAC_POS_STATUS_BIT_Ttag {
	unsigned int enc0_ovfl_pos  : BFW_NETX_XM_ENC_STAT_enc0_ovfl_pos;  // Encoder0 overflow positive 
	unsigned int enc0_ovfl_neg  : BFW_NETX_XM_ENC_STAT_enc0_ovfl_neg;  // Encoder0 overflow negative 
	unsigned int enc0_cap_zpos  : BFW_NETX_XM_ENC_STAT_enc0_cap_zpos;  // Encoder0 captured null position 
	unsigned int enc0_cap_etime : BFW_NETX_XM_ENC_STAT_enc0_cap_etime; // Encoder0 captured edge time 
	unsigned int enc1_ovfl_pos  : BFW_NETX_XM_ENC_STAT_enc1_ovfl_pos;  // Encoder1 overflow positive 
	unsigned int enc1_ovfl_neg  : BFW_NETX_XM_ENC_STAT_enc1_ovfl_neg;  // Encoder1 overflow negative 
	unsigned int enc1_cap_zpos  : BFW_NETX_XM_ENC_STAT_enc1_cap_zpos;  // Encoder1 captured null position 
	unsigned int enc1_cap_etime : BFW_NETX_XM_ENC_STAT_enc1_cap_etime; // Encoder1 captured edge time 
	unsigned int cap0           : BFW_NETX_XM_ENC_STAT_cap0;           // Captured register 0 
	unsigned int cap1           : BFW_NETX_XM_ENC_STAT_cap1;           // Captured register 1 
	unsigned int cap2           : BFW_NETX_XM_ENC_STAT_cap2;           // Captured register 2 
	unsigned int cap3           : BFW_NETX_XM_ENC_STAT_cap3;           // Captured register 3 
	unsigned int enc0_sign      : BFW_NETX_XM_ENC_STAT_enc0_sign;      // Encoder 0 signal N 
	unsigned int enc1_sign      : BFW_NETX_XM_ENC_STAT_enc1_sign;      // Encoder 1 signal N 
	unsigned int mp0            : BFW_NETX_XM_ENC_STAT_mp0;            // Measurement Point 0 
	unsigned int mp1            : BFW_NETX_XM_ENC_STAT_mp1;            // Measurement Point 1 
	unsigned int reserved1      : BFW_NETX_XM_ENC_STAT_reserved1;      // reserved
} XMAC_POS_STATUS_BIT_T;

typedef union {
	unsigned int          val;
	XMAC_POS_STATUS_BIT_T bf;
} XMAC_POS_STATUS_T;

// ---------------------------------------------------------------------
// Register xmac_pos_enc0_position
// => Actual position encoder 0
//    (see PWM_POS.doc for details)
//    This register has a write pipeline delay of 1 clock cycle
// => Mode: Mode(r)
// ---------------------------------------------------------------------

#define REL_NETX_XM_ENC0_POS   0x000009A0U
#define NETX_XM0_ENC0_POS 0x001609A0U
#define NETX_XM1_ENC0_POS 0x001619A0U
#define NETX_XM2_ENC0_POS 0x001629A0U
#define NETX_XM3_ENC0_POS 0x001639A0U

#define MSK_NETX_XM_ENC0_POS_pos_enc0_position 0x0000ffffU // [15:0]
#define SRT_NETX_XM_ENC0_POS_pos_enc0_position 0           

enum {
	BFW_NETX_XM_ENC0_POS_pos_enc0_position = 16, // [15:0]
	BFW_NETX_XM_ENC0_POS_reserved1         = 16  // [31:16]
};

typedef struct XMAC_POS_ENC0_POSITION_BIT_Ttag {
	unsigned int pos_enc0_position : BFW_NETX_XM_ENC0_POS_pos_enc0_position; // Actual position encoder 0 
	unsigned int reserved1         : BFW_NETX_XM_ENC0_POS_reserved1;         // reserved
} XMAC_POS_ENC0_POSITION_BIT_T;

typedef union {
	unsigned int                 val;
	XMAC_POS_ENC0_POSITION_BIT_T bf;
} XMAC_POS_ENC0_POSITION_T;

// ---------------------------------------------------------------------
// Register xmac_pos_enc0_nullposition
// => Last position encoder 0 sampled by enc0_n
//    (see PWM_POS.doc for details)
//    This register has a write pipeline delay of 1 clock cycle
// => Mode: Mode(r)
// ---------------------------------------------------------------------

#define REL_NETX_XM_ENC0_NULL_POS   0x000009A4U
#define NETX_XM0_ENC0_NULL_POS 0x001609A4U
#define NETX_XM1_ENC0_NULL_POS 0x001619A4U
#define NETX_XM2_ENC0_NULL_POS 0x001629A4U
#define NETX_XM3_ENC0_NULL_POS 0x001639A4U

#define MSK_NETX_XM_ENC0_NULL_POS_pos_enc0_nullposition 0x0000ffffU // [15:0]
#define SRT_NETX_XM_ENC0_NULL_POS_pos_enc0_nullposition 0           

enum {
	BFW_NETX_XM_ENC0_NULL_POS_pos_enc0_nullposition = 16, // [15:0]
	BFW_NETX_XM_ENC0_NULL_POS_reserved1             = 16  // [31:16]
};

typedef struct XMAC_POS_ENC0_NULLPOSITION_BIT_Ttag {
	unsigned int pos_enc0_nullposition : BFW_NETX_XM_ENC0_NULL_POS_pos_enc0_nullposition; // Last position encoder 0 sampled by enc0_n 
	unsigned int reserved1             : BFW_NETX_XM_ENC0_NULL_POS_reserved1;             // reserved
} XMAC_POS_ENC0_NULLPOSITION_BIT_T;

typedef union {
	unsigned int                     val;
	XMAC_POS_ENC0_NULLPOSITION_BIT_T bf;
} XMAC_POS_ENC0_NULLPOSITION_T;

// ---------------------------------------------------------------------
// Register xmac_pos_enc1_position
// => Actual position encoder 1
//    (see PWM_POS.doc for details)
//    This register has a write pipeline delay of 1 clock cycle
// => Mode: Mode(r)
// ---------------------------------------------------------------------

#define REL_NETX_XM_ENC1_POS   0x000009A8U
#define NETX_XM0_ENC1_POS 0x001609A8U
#define NETX_XM1_ENC1_POS 0x001619A8U
#define NETX_XM2_ENC1_POS 0x001629A8U
#define NETX_XM3_ENC1_POS 0x001639A8U

#define MSK_NETX_XM_ENC1_POS_pos_enc1_position 0x0000ffffU // [15:0]
#define SRT_NETX_XM_ENC1_POS_pos_enc1_position 0           

enum {
	BFW_NETX_XM_ENC1_POS_pos_enc1_position = 16, // [15:0]
	BFW_NETX_XM_ENC1_POS_reserved1         = 16  // [31:16]
};

typedef struct XMAC_POS_ENC1_POSITION_BIT_Ttag {
	unsigned int pos_enc1_position : BFW_NETX_XM_ENC1_POS_pos_enc1_position; // Actual position encoder 1 
	unsigned int reserved1         : BFW_NETX_XM_ENC1_POS_reserved1;         // reserved
} XMAC_POS_ENC1_POSITION_BIT_T;

typedef union {
	unsigned int                 val;
	XMAC_POS_ENC1_POSITION_BIT_T bf;
} XMAC_POS_ENC1_POSITION_T;

// ---------------------------------------------------------------------
// Register xmac_pos_enc1_nullposition
// => Last position encoder 1 sampled by enc1_n
//    (see PWM_POS.doc for details)
//    This register has a write pipeline delay of 1 clock cycle
// => Mode: Mode(r)
// ---------------------------------------------------------------------

#define REL_NETX_XM_ENC1_NULL_POS   0x000009ACU
#define NETX_XM0_ENC1_NULL_POS 0x001609ACU
#define NETX_XM1_ENC1_NULL_POS 0x001619ACU
#define NETX_XM2_ENC1_NULL_POS 0x001629ACU
#define NETX_XM3_ENC1_NULL_POS 0x001639ACU

#define MSK_NETX_XM_ENC1_NULL_POS_pos_enc1_nullposition 0x0000ffffU // [15:0]
#define SRT_NETX_XM_ENC1_NULL_POS_pos_enc1_nullposition 0           

enum {
	BFW_NETX_XM_ENC1_NULL_POS_pos_enc1_nullposition = 16, // [15:0]
	BFW_NETX_XM_ENC1_NULL_POS_reserved1             = 16  // [31:16]
};

typedef struct XMAC_POS_ENC1_NULLPOSITION_BIT_Ttag {
	unsigned int pos_enc1_nullposition : BFW_NETX_XM_ENC1_NULL_POS_pos_enc1_nullposition; // Last position encoder 1 sampled by enc1_n 
	unsigned int reserved1             : BFW_NETX_XM_ENC1_NULL_POS_reserved1;             // reserved
} XMAC_POS_ENC1_NULLPOSITION_BIT_T;

typedef union {
	unsigned int                     val;
	XMAC_POS_ENC1_NULLPOSITION_BIT_T bf;
} XMAC_POS_ENC1_NULLPOSITION_T;

// ---------------------------------------------------------------------
// Register xmac_pos_enc0_edgetime
// => System time at last edge of encoder 0
//    (see PWM_POS.doc for details)
//    This register has a write pipeline delay of 1 clock cycle
// => Mode: Mode(r)
// ---------------------------------------------------------------------

#define REL_NETX_XM_ENC0_EDGE_TIME   0x000009B0U
#define NETX_XM0_ENC0_EDGE_TIME 0x001609B0U
#define NETX_XM1_ENC0_EDGE_TIME 0x001619B0U
#define NETX_XM2_ENC0_EDGE_TIME 0x001629B0U
#define NETX_XM3_ENC0_EDGE_TIME 0x001639B0U

#define MSK_NETX_XM_ENC0_EDGE_TIME_pos_enc0_edgetime 0x0000ffffU // [15:0]
#define SRT_NETX_XM_ENC0_EDGE_TIME_pos_enc0_edgetime 0           

enum {
	BFW_NETX_XM_ENC0_EDGE_TIME_pos_enc0_edgetime = 16, // [15:0]
	BFW_NETX_XM_ENC0_EDGE_TIME_reserved1         = 16  // [31:16]
};

typedef struct XMAC_POS_ENC0_EDGETIME_BIT_Ttag {
	unsigned int pos_enc0_edgetime : BFW_NETX_XM_ENC0_EDGE_TIME_pos_enc0_edgetime; // System time at last edge of encoder 0 
	unsigned int reserved1         : BFW_NETX_XM_ENC0_EDGE_TIME_reserved1;         // reserved
} XMAC_POS_ENC0_EDGETIME_BIT_T;

typedef union {
	unsigned int                 val;
	XMAC_POS_ENC0_EDGETIME_BIT_T bf;
} XMAC_POS_ENC0_EDGETIME_T;

// ---------------------------------------------------------------------
// Register xmac_pos_enc1_edgetime
// => System time at last edge of encoder 0
//    (see PWM_POS.doc for details)
//    This register has a write pipeline delay of 1 clock cycle
// => Mode: Mode(r)
// ---------------------------------------------------------------------

#define REL_NETX_XM_ENC1_EDGE_TIME   0x000009B4U
#define NETX_XM0_ENC1_EDGE_TIME 0x001609B4U
#define NETX_XM1_ENC1_EDGE_TIME 0x001619B4U
#define NETX_XM2_ENC1_EDGE_TIME 0x001629B4U
#define NETX_XM3_ENC1_EDGE_TIME 0x001639B4U

#define MSK_NETX_XM_ENC1_EDGE_TIME_pos_enc1_edgetime 0x0000ffffU // [15:0]
#define SRT_NETX_XM_ENC1_EDGE_TIME_pos_enc1_edgetime 0           

enum {
	BFW_NETX_XM_ENC1_EDGE_TIME_pos_enc1_edgetime = 16, // [15:0]
	BFW_NETX_XM_ENC1_EDGE_TIME_reserved1         = 16  // [31:16]
};

typedef struct XMAC_POS_ENC1_EDGETIME_BIT_Ttag {
	unsigned int pos_enc1_edgetime : BFW_NETX_XM_ENC1_EDGE_TIME_pos_enc1_edgetime; // System time at last edge of encoder 0 
	unsigned int reserved1         : BFW_NETX_XM_ENC1_EDGE_TIME_reserved1;         // reserved
} XMAC_POS_ENC1_EDGETIME_BIT_T;

typedef union {
	unsigned int                 val;
	XMAC_POS_ENC1_EDGETIME_BIT_T bf;
} XMAC_POS_ENC1_EDGETIME_T;

// ---------------------------------------------------------------------
// Register xmac_pos_capture0
// => Capture register 0
//    (see PWM_POS.doc for details)
//    This register has a write pipeline delay of 1 clock cycle
// => Mode: Mode(r)
// ---------------------------------------------------------------------

#define REL_NETX_XM_ENC_CAPT0   0x000009B8U
#define NETX_XM0_ENC_CAPT0 0x001609B8U
#define NETX_XM1_ENC_CAPT0 0x001619B8U
#define NETX_XM2_ENC_CAPT0 0x001629B8U
#define NETX_XM3_ENC_CAPT0 0x001639B8U

#define MSK_NETX_XM_ENC_CAPT0_pos_capture0 0x0000ffffU // [15:0]
#define SRT_NETX_XM_ENC_CAPT0_pos_capture0 0           

enum {
	BFW_NETX_XM_ENC_CAPT0_pos_capture0 = 16, // [15:0]
	BFW_NETX_XM_ENC_CAPT0_reserved1    = 16  // [31:16]
};

typedef struct XMAC_POS_CAPTURE0_BIT_Ttag {
	unsigned int pos_capture0 : BFW_NETX_XM_ENC_CAPT0_pos_capture0; // Capture register 0 
	unsigned int reserved1    : BFW_NETX_XM_ENC_CAPT0_reserved1;    // reserved
} XMAC_POS_CAPTURE0_BIT_T;

typedef union {
	unsigned int            val;
	XMAC_POS_CAPTURE0_BIT_T bf;
} XMAC_POS_CAPTURE0_T;

// ---------------------------------------------------------------------
// Register xmac_pos_capture1
// => Capture register 1
//    (see PWM_POS.doc for details)
//    This register has a write pipeline delay of 1 clock cycle
// => Mode: Mode(r)
// ---------------------------------------------------------------------

#define REL_NETX_XM_ENC_CAPT1   0x000009BCU
#define NETX_XM0_ENC_CAPT1 0x001609BCU
#define NETX_XM1_ENC_CAPT1 0x001619BCU
#define NETX_XM2_ENC_CAPT1 0x001629BCU
#define NETX_XM3_ENC_CAPT1 0x001639BCU

#define MSK_NETX_XM_ENC_CAPT1_pos_capture1 0x0000ffffU // [15:0]
#define SRT_NETX_XM_ENC_CAPT1_pos_capture1 0           

enum {
	BFW_NETX_XM_ENC_CAPT1_pos_capture1 = 16, // [15:0]
	BFW_NETX_XM_ENC_CAPT1_reserved1    = 16  // [31:16]
};

typedef struct XMAC_POS_CAPTURE1_BIT_Ttag {
	unsigned int pos_capture1 : BFW_NETX_XM_ENC_CAPT1_pos_capture1; // Capture register 1 
	unsigned int reserved1    : BFW_NETX_XM_ENC_CAPT1_reserved1;    // reserved
} XMAC_POS_CAPTURE1_BIT_T;

typedef union {
	unsigned int            val;
	XMAC_POS_CAPTURE1_BIT_T bf;
} XMAC_POS_CAPTURE1_T;

// ---------------------------------------------------------------------
// Register xmac_pos_capture2
// => Capture register 2
//    (see PWM_POS.doc for details)
//    This register has a write pipeline delay of 1 clock cycle
// => Mode: Mode(r)
// ---------------------------------------------------------------------

#define REL_NETX_XM_ENC_CAPT2   0x000009C0U
#define NETX_XM0_ENC_CAPT2 0x001609C0U
#define NETX_XM1_ENC_CAPT2 0x001619C0U
#define NETX_XM2_ENC_CAPT2 0x001629C0U
#define NETX_XM3_ENC_CAPT2 0x001639C0U

#define MSK_NETX_XM_ENC_CAPT2_pos_capture2 0x0000ffffU // [15:0]
#define SRT_NETX_XM_ENC_CAPT2_pos_capture2 0           

enum {
	BFW_NETX_XM_ENC_CAPT2_pos_capture2 = 16, // [15:0]
	BFW_NETX_XM_ENC_CAPT2_reserved1    = 16  // [31:16]
};

typedef struct XMAC_POS_CAPTURE2_BIT_Ttag {
	unsigned int pos_capture2 : BFW_NETX_XM_ENC_CAPT2_pos_capture2; // Capture register 2 
	unsigned int reserved1    : BFW_NETX_XM_ENC_CAPT2_reserved1;    // reserved
} XMAC_POS_CAPTURE2_BIT_T;

typedef union {
	unsigned int            val;
	XMAC_POS_CAPTURE2_BIT_T bf;
} XMAC_POS_CAPTURE2_T;

// ---------------------------------------------------------------------
// Register xmac_pos_capture3
// => Capture register 3
//    (see PWM_POS.doc for details)
//    This register has a write pipeline delay of 1 clock cycle
// => Mode: Mode(r)
// ---------------------------------------------------------------------

#define REL_NETX_XM_ENC_CAPT3   0x000009C4U
#define NETX_XM0_ENC_CAPT3 0x001609C4U
#define NETX_XM1_ENC_CAPT3 0x001619C4U
#define NETX_XM2_ENC_CAPT3 0x001629C4U
#define NETX_XM3_ENC_CAPT3 0x001639C4U

#define MSK_NETX_XM_ENC_CAPT3_pos_capture3 0x0000ffffU // [15:0]
#define SRT_NETX_XM_ENC_CAPT3_pos_capture3 0           

enum {
	BFW_NETX_XM_ENC_CAPT3_pos_capture3 = 16, // [15:0]
	BFW_NETX_XM_ENC_CAPT3_reserved1    = 16  // [31:16]
};

typedef struct XMAC_POS_CAPTURE3_BIT_Ttag {
	unsigned int pos_capture3 : BFW_NETX_XM_ENC_CAPT3_pos_capture3; // Capture register 3 
	unsigned int reserved1    : BFW_NETX_XM_ENC_CAPT3_reserved1;    // reserved
} XMAC_POS_CAPTURE3_BIT_T;

typedef union {
	unsigned int            val;
	XMAC_POS_CAPTURE3_BIT_T bf;
} XMAC_POS_CAPTURE3_T;


// ---------------------------------------------------------------------
// Register xpec_adc
// => ADC Register
//    Resetvalue : 0x00000000
// => Mode: Mode (r/w)
// ---------------------------------------------------------------------

#define REL_NETX_XP_ADC   0x0000009CU
#define NETX_XP0_ADC 0x0017009CU
#define NETX_XP1_ADC 0x0017409CU
#define NETX_XP2_ADC 0x0017809CU
#define NETX_XP3_ADC 0x0017C09CU

#define MSK_NETX_XP_ADC_bits 0xffffffffU // [31:0]
#define SRT_NETX_XP_ADC_bits 0           

enum {
	BFW_NETX_XP_ADC_bits = 32  // [31:0]
};

typedef struct XPEC_ADC_BIT_Ttag {
	unsigned int bits : BFW_NETX_XP_ADC_bits; // config - status ADC 
	                                                        // see ADC Specification
	                                                        //------------------------------------------
	                                                        //  read 9 - 0: adc0_D[9:0]
	                                                        //  read 10: adc0_data_busy
	                                                        //  read 15 - 11: reserved
	                                                        //  read 25 - 16: adc1_D[9:0]
	                                                        //  read 26: adc1_data_busy
	                                                        //  read 31 - 27: reserved
	                                                        //------------------------------------------
	                                                        //  write 0: adc0_pdb
	                                                        //  write 1: adc0_start
	                                                        //  write 4 - 2: adc0_sel[2:0]
	                                                        //  write 14 - 5: reserved
	                                                        //  write 15: dont write adc0
	                                                        //  write 16: adc1_pdb
	                                                        //  write 17:adc1_start
	                                                        //  write 20 - 18: adc1_sel[2:0]
	                                                        //  write 30 - 21: reserved
	                                                        //  write 31: dont write adc1
} XPEC_ADC_BIT_T;

typedef union {
	unsigned int   val;
	XPEC_ADC_BIT_T bf;
} XPEC_ADC_T;


/*************************************************************************************/

#endif /* _MOTCTRL_H */
