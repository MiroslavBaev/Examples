/**********************************************************************************//**
Exclusion of Liability for this demo software:
  The following software is intended for and must only be used for reference and in an
  evaluation laboratory environment. It is provided without charge and is subject to
  alterations. There is no warranty for the software, to the extent permitted by
  applicable law. Except when otherwise stated in writing the copyright holders and/or
  other parties provide the software "as is" without warranty of any kind, either
  expressed or implied.
  Please refer to the Agreement in README_DISCLAIMER.txt, provided  together with this
  project!
  By installing or otherwise using the software, you accept the terms of this Agreement.
  If you do not agree to the terms of this Agreement, then do not install or use the
  Software!
**************************************************************************************/
/**************************************************************************************
Copyright (c) Hilscher Gesellschaft fuer Systemautomation mbH. All Rights Reserved.
***************************************************************************************
$Id: ExampleTask1_Functions.c 1862 2016-01-27 10:56:55Z Ricky $:

Description:
 See doxygen
***********************************************************************************//**
  \file ExampleTask1_Functions.c
  Contains packet handler
**************************************************************************************/
#include "ExampleTask1_Functions.h"
#include "ExampleTask1_DiagStatus.h"
#include "ExampleTask1_ProcessData.h"
#include "ExampleTask1_ObjectDictionary.h"
#include "ExampleTask1_SiiProvider.h"
#include "TLR_Results.h"

/**************************************************************************************
 Does generic Packet handling by adding diagnosis information via DiagStatus
 \param[in,out] ptRsc Resources of Task
 \param[in]     pvPck packet to send and releas memory if failed
**************************************************************************************/
void GenericPacketSending(EXAMPLETASK1_RSC_T* ptRsc, void* pvPck)
{
  TLR_RESULT eRslt = TLR_S_OK;
  eRslt = TLR_QUE_SENDPACKET_FIFO( ptRsc->tRem.hQueEsm, pvPck, TLR_FINITE );
  if(TLR_S_OK == eRslt)
  {
    DiagStatusIncreaseCounterOfOutstandingPackets(ptRsc);
  }
  else
  {
    DiagStatusSaveInfoOfFailedPacket(ptRsc, ptRsc->tRem.hQueEsm, eRslt);
    eRslt = TLR_POOL_PACKET_RELEASE(ptRsc->tLoc.hPool, pvPck);
    if(TLR_S_OK != eRslt)
    {
      DiagStatusSaveInfoOfFailedPacket(ptRsc, ptRsc->tRem.hQueEsm, eRslt);
    }
  }
}


/**************************************************************************************
 Does generic Packet handling by adding diagnosis information via DiagStatus
 \param[in,out] ptRsc Resources of Task
 \param[in]     pvPck packet to send and releas memory if failed
**************************************************************************************/
static void GenericPacketReceiving(EXAMPLETASK1_RSC_T* ptRsc, void* pvPck)
{
  TLR_RESULT eRslt = TLR_S_OK;
  TLR_PACKET_HEADER_T* ptPckHead = pvPck;
  if(TLR_S_OK == ptPckHead->ulSta)
  {
    DiagStatusIncreaseCounterOfPositiveConfirmations(ptRsc);
  }
  else
  {
    DiagStatusIncreaseCounterOfNegativeConfirmations(ptRsc);
  }

  eRslt = TLR_POOL_PACKET_RELEASE(ptRsc->tLoc.hPool, pvPck);
  if(TLR_S_OK == eRslt)
  {
    DiagStatusDecreaseCounterOfOutstandingPackets(ptRsc);
  }else
  {
    DiagStatusSaveInfoOfFailedPacket(ptRsc, ptRsc->tRem.hQueEsm, eRslt);
  }
}


/**********************************************************************************//**
 Builds a RCX_REGISTER_APP_REQ packet and sends it to EtherCAT stack
 \param[in,out] ptRsc  Resources of Task
**************************************************************************************/
void ExampleTask1_SendRcxRegisterAppReq(EXAMPLETASK1_RSC_T* ptRsc)
{
  TLR_RESULT eRslt = TLR_S_OK;
  EXAMPLETASK1_PACKET_T *ptPck = NULL;

  eRslt = TLR_POOL_PACKET_GET(ptRsc->tLoc.hPool, &ptPck);
  if(TLR_S_OK == eRslt)
  {
    memset(ptPck, 0x00, sizeof(ptPck->tRcxRegisterAppReq));
    ptPck->tHead.ulSrc    = ( TLR_UINT32 )ptRsc->tLoc.hQue; /* Source of packet, process queue      */
    ptPck->tHead.ulCmd    = RCX_REGISTER_APP_REQ;           /* Packet command                       */

    GenericPacketSending(ptRsc, ptPck);
  }else
  {
    TLR_TSK_SET_STATE( eRslt );
  }
}


/**********************************************************************************//**
 \param[in,out] ptRsc   Resources of Task
 \param[in]     pvPck   Received packet
**************************************************************************************/
void ExampleTask1_HandleRcxRegisterAppCnf(EXAMPLETASK1_RSC_T* ptRsc,
                                                        void* pvPck)
{
  GenericPacketReceiving(ptRsc, pvPck);
  ExampleTask1_SendEcatSetConfigReq(ptRsc);
}


/**************************************************************************************
 Builds a ECAT_SET_CONFIG_REQ packet and sends it to EtherCAT stack
 \param[in,out] ptRsc Resources of Task
**************************************************************************************/
void ExampleTask1_SendEcatSetConfigReq(EXAMPLETASK1_RSC_T* ptRsc)
{
  TLR_RESULT eRslt = TLR_S_OK;
  ECAT_SET_CONFIG_REQ_T *ptSetConfigReq = NULL;

  eRslt = TLR_POOL_PACKET_GET( ptRsc->tLoc.hPool, &ptSetConfigReq );
  if(TLR_S_OK == eRslt)
  {
    memset(ptSetConfigReq, 0x00, sizeof(*ptSetConfigReq));
    ptSetConfigReq->tHead.ulSrc    = ( TLR_UINT32 )ptRsc->tLoc.hQue;
    ptSetConfigReq->tHead.ulLen    = sizeof(ptSetConfigReq->tData);
    ptSetConfigReq->tHead.ulCmd    = ECAT_SET_CONFIG_REQ;

    ptSetConfigReq->tData.tBasicCfg.ulSystemFlags  = ECAT_SET_CONFIG_SYSTEMFLAGS_APP_CONTROLLED;
    ptSetConfigReq->tData.tBasicCfg.ulWatchdogTime = 1000;
    ptSetConfigReq->tData.tBasicCfg.ulSerialNumber = 0x12345679;

    ProcessDataGetPdSizes(ptRsc,
                          &ptSetConfigReq->tData.tBasicCfg.ulProcessDataOutputSize,
                          &ptSetConfigReq->tData.tBasicCfg.ulProcessDataInputSize);

    ptSetConfigReq->tData.tBasicCfg.ulComponentInitialization = ECAT_SET_CONFIG_COE
                                                              | ECAT_SET_CONFIG_FOE;
    if(TLR_FALSE != ptRsc->tLoc.ptStartup->fUseEoe)
    {
      ptSetConfigReq->tData.tBasicCfg.ulComponentInitialization |= ECAT_SET_CONFIG_EOE;
    }

    ptSetConfigReq->tData.tBasicCfg.ulExtensionNumber          = 0;

    /* Check validation of startup parameter */
    if(NULL != ptRsc->tLoc.ptStartup)
    {
      ptSetConfigReq->tData.tBasicCfg.ulVendorId       = ptRsc->tLoc.ptStartup->ulVendorId;        /* Vendor Id                        */
      ptSetConfigReq->tData.tBasicCfg.ulRevisionNumber = ptRsc->tLoc.ptStartup->ulRevisionNumber;  /* Revision number                  */
      ptSetConfigReq->tData.tBasicCfg.ulProductCode    = ptRsc->tLoc.ptStartup->ulProductCode;     /* Revision Number: Device ID netX  */
    }
    /* Set default parameter */
    else
    {
      ptSetConfigReq->tData.tBasicCfg.ulVendorId       = 0xE0000044;             /* Vendor Id                          */
      ptSetConfigReq->tData.tBasicCfg.ulRevisionNumber = 0x00020004;             /* Revision number                    */
      ptSetConfigReq->tData.tBasicCfg.ulProductCode    = 0x00000009;             /* Revision Number: Device ID netX500 */
    }

    /*CoE configuration data*/
    ptSetConfigReq->tData.tComponentsCfg.tCoECfg.bCoeFlags              = ECAT_SET_CONFIG_COEFLAGS_USE_CUSTOM_OD;  // custom OD is used instead of automatically create default OD
    ptSetConfigReq->tData.tComponentsCfg.tCoECfg.bCoeDetails            = ECAT_SET_CONFIG_COEDETAILS_ENABLE_SDO | ECAT_SET_CONFIG_COEDETAILS_ENABLE_SDOINFO | ECAT_SET_CONFIG_COEDETAILS_ENABLE_PDOASSIGN;
    ptSetConfigReq->tData.tComponentsCfg.tCoECfg.ulOdIndicationTimeout  = 1000;
    ptSetConfigReq->tData.tComponentsCfg.tCoECfg.ulDeviceType           = 0;

    ptSetConfigReq->tData.tComponentsCfg.tFoECfg.ulTimeout = 1000  /* Milliseconds */;

    GenericPacketSending(ptRsc, ptSetConfigReq);
  }
  else
  {
    TLR_TSK_SET_STATE(eRslt);
  }
}


/**********************************************************************************//**
 \param[in,out] ptRsc   Resources of Task
 \param[in]     pvPck   Received packet
**************************************************************************************/
void ExampleTask1_HandleEcatSetConfigCnf(EXAMPLETASK1_RSC_T* ptRsc, void* pvPck)
{
  GenericPacketReceiving(ptRsc, pvPck);
  ExampleTask1_SendRcxChannelInitReq(ptRsc);
}


/**********************************************************************************//**
 \param[in,out] ptRsc   Resources of Task
**************************************************************************************/
void ExampleTask1_SendRcxChannelInitReq(EXAMPLETASK1_RSC_T* ptRsc)
{
  TLR_RESULT eRslt = TLR_S_OK;                                                        /* Return value for common error codes */
  EXAMPLETASK1_PACKET_T *ptPck = NULL;

  eRslt = TLR_POOL_PACKET_GET(ptRsc->tLoc.hPool, &ptPck);
  if(TLR_S_OK == eRslt)
  {
    memset(ptPck, 0x00, sizeof(ptPck->tRcxChannelInitReq));
    ptPck->tHead.ulSrc    = ( TLR_UINT32 )ptRsc->tLoc.hQue;                           /* Source of packet, process queue      */
    ptPck->tHead.ulCmd    = RCX_CHANNEL_INIT_REQ;                                     /* Packet command                       */

    GenericPacketSending(ptRsc, ptPck);
  }
  else
  {
    TLR_TSK_SET_STATE(eRslt);
  }
}


/**********************************************************************************//**
 \param[in,out] ptRsc   Resources of Task
 \param[in]     pvPck   Received packet
**************************************************************************************/
void ExampleTask1_HandleRcxChannelInitCnf(EXAMPLETASK1_RSC_T* ptRsc, void* pvPck)
{
  GenericPacketReceiving(ptRsc, pvPck);
  SiiProvider_SiiCreationFsm(ptRsc);
}


/**********************************************************************************//**
 \param[in,out] ptRsc   Resources of Task
 \param[in]     pvPck   Received packet
**************************************************************************************/
void ExampleTask1_HandleEcatEsmSiiWriteCnf(EXAMPLETASK1_RSC_T* ptRsc, void* pvPck)
{
  GenericPacketReceiving(ptRsc, pvPck);
  SiiProvider_SiiCreationFsm(ptRsc);
}


/**********************************************************************************//**
 \param[in,out] ptRsc   Resources of Task
 \param[in]     pvPck   Received packet
**************************************************************************************/
void ExampleTask1_HandleEcatDpmSetStationAliasCnf(EXAMPLETASK1_RSC_T* ptRsc, void* pvPck)
{
  GenericPacketReceiving(ptRsc, pvPck);
  SiiProvider_SiiCreationFsm(ptRsc);
}


/**********************************************************************************//**
 \param[in,out] ptRsc   Resources of Task
 \param[in]     pvPck   Received packet
**************************************************************************************/
void ExampleTask1_HandleEcatEsmRegisterForSiiWriteIndicationsCnf(EXAMPLETASK1_RSC_T* ptRsc, void* pvPck)
{
  GenericPacketReceiving(ptRsc, pvPck);
  SiiProvider_SiiCreationFsm(ptRsc);
}


/**********************************************************************************//**
 \param[in,out] ptRsc   Resources of Task
 \param[in]     pvPck   Received packet
**************************************************************************************/
void ExampleTask1_HandleOdv3CreateObjectCnf(EXAMPLETASK1_RSC_T* ptRsc, void* pvPck)
{
  GenericPacketReceiving(ptRsc, pvPck);
  ObjectDictionary_OdCreationFsm(ptRsc);
}


/**********************************************************************************//**
 \param[in,out] ptRsc   Resources of Task
 \param[in]     pvPck   Received packet
**************************************************************************************/
void ExampleTask1_HandleOdv3CreateSubObjectCnf(EXAMPLETASK1_RSC_T* ptRsc, void* pvPck)
{
  GenericPacketReceiving(ptRsc, pvPck);
  ObjectDictionary_OdCreationFsm(ptRsc);
}


/**********************************************************************************//**
 \param[in,out] ptRsc   Resources of Task
**************************************************************************************/
void ExampleTask1_SendRcxStartStopCommReq(EXAMPLETASK1_RSC_T* ptRsc)
{
  TLR_RESULT eRslt = TLR_S_OK;
  EXAMPLETASK1_PACKET_T *ptPck = NULL;

  eRslt = TLR_POOL_PACKET_GET(ptRsc->tLoc.hPool, &ptPck);
  if(TLR_S_OK == eRslt)
  {
    memset(ptPck, 0x00, sizeof(ptPck->tRcXStartStopCommReq));
    ptPck->tHead.ulSrc     = ( TLR_UINT32 )ptRsc->tLoc.hQue;
    ptPck->tHead.ulCmd     = RCX_START_STOP_COMM_REQ;
    ptPck->tHead.ulLen     = sizeof(ptPck->tRcXStartStopCommReq.tData);
    ptPck->tRcXStartStopCommReq.tData.ulParam = 1;   /* Parameter communication: 1 = start / 0 = stop  */

    GenericPacketSending(ptRsc, ptPck);
  }else
  {
    TLR_TSK_SET_STATE(eRslt);
  }
}


/**********************************************************************************//**
 \param[in,out] ptRsc   Resources of Task
 \param[in]     pvPck   Received packet
**************************************************************************************/
void ExampleTask1_HandleRcxStartStopCommCnf(EXAMPLETASK1_RSC_T* ptRsc, void* pvPck)
{
  GenericPacketReceiving(ptRsc, pvPck);
  /** startup sequence finished, sends no requests anymore */
}


/**********************************************************************************//**
 Answeres to a SII write indication
 \param[in,out] ptRsc  Resources of Task
 \param[in] pvPck      Incoming ECAT_ESM_SII_WRITE_IND
**************************************************************************************/
void ExampleTask1_HandleEcatEsmSiiWriteInd(EXAMPLETASK1_RSC_T* ptRsc, void* pvPck)
{
  ECAT_ESM_SII_WRITE_IND_T* ptPck = pvPck;
  TLR_UINT8 abSecData[32];
  TLR_BOOLEAN8 fChanged = 0;
  TLR_UINT32 ulIdx;

  if(sizeof(TLR_UINT32) > ptPck->tHead.ulLen)
  {
    ptPck->tHead.ulSta = TLR_E_FAIL;
  }
  else
  {
    ptPck->tHead.ulSta = Drv_SecGetRawArea(abSecData, 2);
    if(TLR_S_OK == ptPck->tHead.ulSta)
    {
      for(ulIdx = 0; ulIdx < ptPck->tHead.ulLen - sizeof(TLR_UINT32); ++ulIdx)
      {
        if(ptPck->tData.ulSiiWriteStartAddress + ulIdx >= 0x08 && ptPck->tData.ulSiiWriteStartAddress + ulIdx <= 0x09)
        {
          abSecData[ptPck->tData.ulSiiWriteStartAddress + ulIdx - 0x08] = ptPck->tData.abData[ulIdx];
          fChanged = TLR_TRUE;
        }
      }

      if(fChanged)
      {
        ptPck->tHead.ulSta = Drv_SecSetRawArea(abSecData, 2);
      }
    }
  }

  ptPck->tHead.ulLen = 0;
  TLR_QUE_RETURNPACKET(ptPck);
}


/**********************************************************************************//**
 Answeres to a read object indication
 \param[in,out] ptRsc Resources of Task
 \param[in] pvPck      Incoming ODV3_READ_OBJECT_IND
**************************************************************************************/
void ExampleTask1_HandleOdv3ReadObjectInd(EXAMPLETASK1_RSC_T* ptRsc, void* pvPck)
{
  ODV3_READ_OBJECT_RES_T* ptPck = pvPck; /** Cast indication to response */
  uint8_t* ptTmp; /* temporary pointer for casting reasons */
  if(TLR_S_OK == ptPck->tHead.ulSta)
  {
    ptPck->tHead.ulLen = sizeof(ptPck->tData) - sizeof(ptPck->tData.abData); /* fragmantable part will be added depening on object to read */
    ptPck->tHead.ulCmd |= 1; /** Changes command Ind to Res */
    ptPck->tData.ulTotalDataBytes = 0;

    switch(ptPck->tData.usIndex)
    {
      case 0x2000: /** Reads process data object 2000 points to */
        ptTmp = (uint8_t*) &ptRsc->tLoc.tEcsPd.aulOutData[0];
        switch(ptPck->tData.bSubIndex)
        {
        case 0x01:
          ptPck->tHead.ulLen += sizeof(uint8_t); /* assumes 2000:01 is one byte */
          ptPck->tData.ulTotalDataBytes += sizeof(uint8_t);
          memcpy( &ptPck->tData.abData[0], &ptTmp[0], sizeof(uint8_t) );
          break;
        case 0x02:
          ptPck->tHead.ulLen += sizeof(uint8_t); /* assumes 2000:02 is one byte */
          ptPck->tData.ulTotalDataBytes += sizeof(uint8_t);
          memcpy( &ptPck->tData.abData[0], &ptTmp[1], sizeof(uint8_t) );
          break;
        default:
          ptPck->tHead.ulSta = TLR_E_UNEXPECTED;
          break;
        }
      break;

      case 0x3000: /** Reads process data object 3000 points to */
        ptTmp = (uint8_t*) &ptRsc->tLoc.tEcsPd.aulInData[0];
        switch(ptPck->tData.bSubIndex)
        {
        case 0x01:
          ptPck->tHead.ulLen += sizeof(uint8_t); /* assumes 3000:01 is one byte */
          ptPck->tData.ulTotalDataBytes += sizeof(uint8_t);
          memcpy( &ptPck->tData.abData[0], &ptTmp[0], sizeof(uint8_t) );
          break;
        case 0x02:
          ptPck->tHead.ulLen += sizeof(uint8_t); /* assumes 3000:02 is one byte */
          ptPck->tData.ulTotalDataBytes += sizeof(uint8_t);
          memcpy( &ptPck->tData.abData[0], &ptTmp[1], sizeof(uint8_t) );
          break;
        default:
          ptPck->tHead.ulSta = TLR_E_UNEXPECTED;
          break;
        }
      break;

      default:
        ptPck->tHead.ulSta = TLR_E_UNEXPECTED;
        break;
    }
    TLR_QUE_RETURNPACKET(ptPck);
  }
}


/**********************************************************************************//**
 Handles an unknown packet
 \param[in,out] ptRsc  task resources
 \param[in]     ptPck  packet
 \return TLR_S_OK if succeeded
**************************************************************************************/
TLR_RESULT TaskCommand_ExampleTask1_Unknown(EXAMPLETASK1_RSC_T* ptRsc, EXAMPLETASK1_PACKET_T* ptPck)
{
  /* return packet */
  if((ptPck->tHead.ulCmd & 0x00000001) == 0x00000000)
	  ptPck->tHead.ulSta = TLR_E_EXAMPLETASK1_INVALID_COMMAND;
  TLR_QUE_PACKETDONE(ptRsc->tLoc.hPool, ptRsc->tLoc.hQue, ptPck);
  return TLR_E_EXAMPLETASK1_INVALID_COMMAND;
}
