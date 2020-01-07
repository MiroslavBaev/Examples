/******************************************************************************

  Copyright (C) 2010 Hilscher Gesellschaft für Systemautomation mbH.

  This program can be used by everyone according the "industrialNETworX Public License INPL".

  The license can be downloaded under <http://www.industrialNETworX.com>.

*******************************************************************************

  Last Modification:
    @version $Id: TLR_ExtDevStat.h 1554 2013-08-06 06:32:10Z MichaelT $

  Description:
    General Definition for Extended Status Module

  Changes:
    Date        Author        Description
  ---------------------------------------------------------------------------
    2010-03-23  NC            File created.

******************************************************************************/


#ifndef __TLR_EXTDEVSTATUS_H
#define __TLR_EXTDEVSTATUS_H

#ifdef __cplusplus
  extern "C" {
#endif  /* __cplusplus */



#include "TLR_Types.h"
#include "TLR_Results.h"

#define EXTDEVNAME_OUTPUT        "STD_OUTPUT"
#define EXTDEVNAME_INPUT         "STD_INPUT"


#define EXTDEV_STD_OUTPUT_BLK_ID        (8)
#define EXTDEV_HI_OUTPUT_BLK_ID         (9)
#define EXTDEV_STD_INPUT_BLK_ID         (0)
#define EXTDEV_HI_INPUT_BLK_ID          (1)

#define TLR_EXTDEVSTAT_PROJECTED           (1)
#define TLR_EXTDEVSTAT_ACTIVATED           (2)
#define TLR_EXTDEVSTAT_DIAGNOSED           (3)
#define TLR_EXTDEVSTAT_COMMANDS            (4)
#define TLR_EXTDEVSTAT_IO_CHANGED          (5)
#define TLR_EXTDEVSTAT_IOPS_BYTEWISE       (6)
#define TLR_EXTDEVSTAT_IOPS_BITWISE        (7)
#define TLR_EXTDEVSTAT_IOCS_BYTEWISE       (8)
#define TLR_EXTDEVSTAT_IOCS_BITWISE        (9)
#define TLR_EXTDEVSTAT_EIP_ASSEMBLY_STATE (10)
#define TLR_EXTDEVSTAT_COM_PDO_COUNTER    (11)


#define EXTDEVSTATSTRUCTMAX    (24)       /*Maximal number of state structure */

                                        /* Application/Custom channels have *
                                         * no default name. User defined it.
                                         * The name user define is always
                                         * changed at bit 8. I.e. if custom
                                         * channel has defined name "APPCHAN_X
                                         * than the X may be changed as 1 if
                                         * a communication channel 0 is already
                                         * available*/


typedef struct TLR_EXTDEVSTAT_Ttag
{
  TLR_HANDLE hExtStatusChnBlock;
  struct
  {
    TLR_BOOLEAN fActive;
    TLR_UINT32 ulElementBitSize;
    TLR_UINT32 ulElementNum;
  }tElement[EXTDEVSTATSTRUCTMAX];
} TLR_EXTDEVSTAT_T;

typedef __TLR_PACKED_PRE struct NETX_STAT_STRUCTURE_Ttag{

  TLR_UINT8   ubBlockId;
  TLR_UINT8   ubStatType;
  TLR_UINT16  usStateFieldNum;
  TLR_UINT32  ulOffsetAddr;

}__TLR_PACKED_POST NETX_STAT_STRUCTURE_T;

typedef __TLR_PACKED_PRE struct EXTSTATFIELDDEF_Ttag{

  TLR_UINT8 ubReserved[3];        /* 3 Bytes preserved. Not used.             */

  TLR_UINT8 ubStateStructNum;     /* Number of following state structure      */

  NETX_STAT_STRUCTURE_T atStatStruct[EXTDEVSTATSTRUCTMAX];
                                  /* Preserve maximal number of state structure
                                   * Even if we do not use  all of them       */

}__TLR_PACKED_POST EXTSTATFIELDDEF_T;

typedef __TLR_PACKED_PRE union EXTDEVSTAT_STACK_SPECIFIC_INFO_Utag{
  TLR_UINT8             ubReserved[172];

  /*TODO Add stack specific status structure here. Size shouldn't exceed 172 byte */
}__TLR_PACKED_POST EXTDEVSTAT_STACK_SPECIFIC_INFO_U;

typedef __TLR_PACKED_PRE struct EXTDEVSTATUSMEMLAYOUT_Ttag{/*General Memory Layout*/

  EXTDEVSTAT_STACK_SPECIFIC_INFO_U uStackSpecific;/* Compatible  with old stacks*/

  EXTSTATFIELDDEF_T       tExtStatDef;    /* Definition of Extended Status    */

}__TLR_PACKED_POST EXTDEVSTATUSMEMLAYOUT_T;


TLR_UINT32 TLR_ExtDevStatBlockReset (TLR_EXTDEVSTAT_T *ptExtDevStat);

TLR_UINT32 TLR_ExtDevStatInitialize( TLR_EXTDEVSTAT_T *ptExtDevStat,
                                     TLR_HANDLE        hExtStatusChnBlock);

TLR_UINT32 TLR_ExtDevStatEntityCreate(  TLR_EXTDEVSTAT_T *ptExtDevStat,
                                        TLR_HANDLE        hDesChnBlock,
                                        TLR_UINT32        ulStateEntityTypeID,
                                        TLR_UINT32        ulElementBitSize,
                                        TLR_UINT32        ulStateEntityNum,
                                        TLR_UINT32        ulOffsetBase,
                                        TLR_VOID**        pvStartAddr,
                                        TLR_UINT32*       pvStartOffsetAddr);



#ifdef __cplusplus
}
#endif  /* __cplusplus */

#endif  /* __TLR_EXTDEVSTATUS_H */
