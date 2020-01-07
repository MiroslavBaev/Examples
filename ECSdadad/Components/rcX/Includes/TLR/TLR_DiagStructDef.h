/******************************************************************************

  Copyright (C) 2010 Hilscher Gesellschaft für Systemautomation mbH.

  This program can be used by everyone according the "industrialNETworX Public License INPL".

  The license can be downloaded under <http://www.industrialNETworX.com>.

*******************************************************************************

  Last Modification:
    @version $Id: TLR_DiagStructDef.h 569 2010-11-19 08:47:54Z MichaelT $

  Description:
    TLR diagnostic structure definitions

  Changes:
    Date        Author        Description
  ---------------------------------------------------------------------------
    2010-03-23  NC            File created.

******************************************************************************/


#ifdef __cplusplus
  extern "C" {
#endif  /* __cplusplus */

#ifndef __STRUCT_TLR_DIAG_TASK_INFO_T__
#define __STRUCT_TLR_DIAG_TASK_INFO_T__

#include "TLR_Types.h"

/* Enable Byte packing */
#ifdef PRAGMA_PACK_ENABLE
#pragma PRAGMA_PACK_1(TLR_DIAGSTRUCTDEF)
#endif

typedef __TLR_PACKED_PRE struct TLR_DIAG_TASK_INFO_Ttag 
{
  TLR_UINT32 ulTskIdentifier;
  TLR_UINT32 usTskMajorVersion;
  TLR_UINT32 usTskMinorVersion;
  TLR_UINT32 ulMaximumPacketSize;
  TLR_UINT32 ulDefaultQue;
  TLR_UINT32 ulProtocolType;
  TLR_UINT16 usMajorVersion;
  TLR_UINT16 usTaskType;
  TLR_UINT32 ulLayerLevel;
  TLR_UINT32 ulLayerSubTask;
  TLR_UINT32 eInitRslt;
  TLR_UINT32 pvRsc;
} __TLR_PACKED_POST TLR_DIAG_TASK_INFO_T;
#endif

#ifndef __STRUCT_TLR_DIAG_COMMON_STATUS_BLOCK_T__
#define __STRUCT_TLR_DIAG_COMMON_STATUS_BLOCK_T__

typedef __TLR_PACKED_PRE struct TLR_DIAG_COMMON_STATUS_BLOCK_Ttag 
{
  TLR_UINT32 ulCommunicationCOS;
  TLR_UINT32 ulCommunicationState;
  TLR_UINT32 ulCommunicationError;
  TLR_UINT16 usVersion;
  TLR_UINT16 usWatchdogTime;
  TLR_UINT16 ausProtocolClass[2];
  TLR_UINT32 ulHostWatchdog;
  TLR_UINT32 ulErrorLogInd;
  TLR_UINT32 ulHostWatchdog1;
  TLR_UINT32 ulReserved0;
  TLR_UINT32 ulReserved1;
  TLR_UINT32 ulStackDepended0;
  TLR_UINT32 ulStackDepended1;
  TLR_UINT32 ulStackDepended2;
  TLR_UINT32 ulStackDepended3;
  TLR_UINT32 ulStackDepended4;
  TLR_UINT32 ulStackDepended5;
} __TLR_PACKED_POST TLR_DIAG_COMMON_STATUS_BLOCK_T;
#endif

#ifndef __STRUCT_INIBATCH_DIAG_DATA_T__
#define __STRUCT_INIBATCH_DIAG_DATA_T__

typedef __TLR_PACKED_PRE struct INIBATCH_DIAG_DATA_Ttag 
{
  TLR_UINT32 ulChannelNo;
  TLR_UINT32 ulCurrentState;
  TLR_UINT32 ulIniBatchResult;
  TLR_UINT32 ulOpenDbmResult;
  TLR_UINT32 ulSendPacketResult;
  TLR_UINT32 ulConfPacketResult;
  TLR_UINT32 ulLastPacketNo;
  TLR_UINT32 ulLastPacketCmd;
  TLR_UINT32 ulLastPacketLen;
  TLR_UINT32 ulLastPacketDest;
} __TLR_PACKED_POST INIBATCH_DIAG_DATA_T;
#endif

/* Restore old packing */
#ifdef PRAGMA_PACK_ENABLE
#pragma PRAGMA_UNPACK_1(TLR_DIAGSTRUCTDEF)
#endif



#ifdef __cplusplus
}
#endif  /* __cplusplus */
