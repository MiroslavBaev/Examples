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
$Id:  $:

Description:
 See doxygen
***********************************************************************************//**
  \file ExampleTask1_SiiProvider.c
  Every Sii handling shall be supported inside this module.
**************************************************************************************/
#include "ExampleTask1_Resources.h"
#include "ExampleTask1_SiiProvider.h"
#include "ExampleTask1_Functions.h" /* for using GenericPacketSending */
#include "ExampleTask1_ObjectDictionary.h" /* for calling ObjectDictionary_OdCreationFsm() first time */

/*************************************************************************************/
static bool State_Finished(EXAMPLETASK1_RSC_T* ptRsc)
{
  ObjectDictionary_OdCreationFsm(ptRsc); /**< Trigger Od creation FSM first time */
  return false;
}

/*************************************************************************************/
static bool State_RegisterForSiiWriteIndication(EXAMPLETASK1_RSC_T* ptRsc)
{
  TLR_RESULT eRslt = TLR_S_OK;
  SII_PROVIDER_T* ptSiiProv = &ptRsc->tLoc.tSiiProv;
  ECAT_ESM_REGISTER_FOR_SIIWRITE_INDICATIONS_REQ_T* ptRegForSiiWriteIndReq = NULL;

  eRslt = TLR_POOL_PACKET_GET(ptRsc->tLoc.hPool, &ptRegForSiiWriteIndReq);

  if ( TLR_S_OK == eRslt )
  {
    memset(ptRegForSiiWriteIndReq, 0x00, sizeof(*ptRegForSiiWriteIndReq));

    ptRegForSiiWriteIndReq->tHead.ulExt = 0;
    ptRegForSiiWriteIndReq->tHead.ulCmd = ECAT_ESM_REGISTER_FOR_SIIWRITE_INDICATIONS_REQ;
    ptRegForSiiWriteIndReq->tHead.ulSrc = (TLR_UINT32)ptRsc->tLoc.hQue;
    ptRegForSiiWriteIndReq->tHead.ulLen = sizeof(ptRegForSiiWriteIndReq->tData);

    ptRegForSiiWriteIndReq->tData.ulIndicationFlags = ECAT_ESM_FILTER_SIIWRITE_INDICATIONS_STATION_ALIAS;

    GenericPacketSending(ptRsc, ptRegForSiiWriteIndReq);
  }else
  {
    TLR_TSK_SET_STATE(eRslt);
  }

  ptSiiProv->pfnCurrenState = &State_Finished;
  return false;
}

/*************************************************************************************/
static bool State_Patch2ndStationAliasIntoEscRegister(EXAMPLETASK1_RSC_T* ptRsc)
{
  TLR_RESULT eRslt = TLR_S_OK;
  SII_PROVIDER_T* ptSiiProv = &ptRsc->tLoc.tSiiProv;
  ECAT_DPM_SET_STATION_ALIAS_REQ_T* ptWriteEscRegReq = NULL;

  eRslt = TLR_POOL_PACKET_GET(ptRsc->tLoc.hPool, &ptWriteEscRegReq);

  if ( TLR_S_OK == eRslt )
  {
    memset(ptWriteEscRegReq, 0x00, sizeof(*ptWriteEscRegReq));

    ptWriteEscRegReq->tHead.ulSrc     = (TLR_UINT32)ptRsc->tLoc.hQue;
    ptWriteEscRegReq->tHead.ulLen     = 2; /* TODO: improve */
    ptWriteEscRegReq->tHead.ulSta     = TLR_S_OK;
    ptWriteEscRegReq->tHead.ulCmd     = ECAT_DPM_SET_STATION_ALIAS_REQ;
    ptWriteEscRegReq->tHead.ulExt     = 0;

    ptWriteEscRegReq->tData.usStationAlias = ptSiiProv->usStationAlias;

    GenericPacketSending(ptRsc, ptWriteEscRegReq);
  }else
  {
    TLR_TSK_SET_STATE(eRslt);
  }

  ptSiiProv->pfnCurrenState = &State_RegisterForSiiWriteIndication;
  return false;
}

/*************************************************************************************/
static bool State_Patch2ndStationAliasIntoSii(EXAMPLETASK1_RSC_T* ptRsc)
{
  TLR_RESULT eRslt = TLR_S_OK;
  SII_PROVIDER_T* ptSiiProv = &ptRsc->tLoc.tSiiProv;
  ECAT_ESM_SII_WRITE_REQ_T* ptSiiWriteReq = NULL;

  eRslt = TLR_POOL_PACKET_GET(ptRsc->tLoc.hPool, &ptSiiWriteReq);

  if ( TLR_S_OK == eRslt )
  {
    memset(ptSiiWriteReq, 0x00, sizeof(*ptSiiWriteReq));

    ptSiiWriteReq->tHead.ulSrc     = (TLR_UINT32)ptRsc->tLoc.hQue;
    ptSiiWriteReq->tHead.ulLen     = 4+2; //sizeof(ptPck->ptWriteSiiReq.tData);
    ptSiiWriteReq->tHead.ulSta     = TLR_S_OK;
    ptSiiWriteReq->tHead.ulCmd     = ECAT_ESM_SII_WRITE_REQ;
    ptSiiWriteReq->tHead.ulExt     = 0;

    ptSiiWriteReq->tData.ulOffset = 0x0004 * sizeof(uint16_t); /* Sii is addressed word wise */
    memcpy( &ptSiiWriteReq->tData.abData, &ptSiiProv->usStationAlias, sizeof(ptSiiProv->usStationAlias) );

    GenericPacketSending(ptRsc, ptSiiWriteReq);
  }else
  {
    TLR_TSK_SET_STATE(eRslt);
  }

  ptSiiProv->pfnCurrenState = &State_Patch2ndStationAliasIntoEscRegister;
  return false;
}


/*************************************************************************************/
static bool State_SendSiiWriteReq(EXAMPLETASK1_RSC_T* ptRsc)
{
#define PACKET_SIZE  ( sizeof(ptSiiWriteReq->tData.abData) - sizeof(ptSiiWriteReq->tData.ulOffset) )
  TLR_RESULT eRslt = TLR_S_OK;
  SII_PROVIDER_T* ptSiiProv = &ptRsc->tLoc.tSiiProv;

  uint32_t ulNumberOfBytesToSend;
  ECAT_ESM_SII_WRITE_REQ_T *ptSiiWriteReq = NULL;

  if( ptSiiProv->ulRemainingBytes > PACKET_SIZE )  /* Remaining bytes does not fit into current packet */
  {
    ulNumberOfBytesToSend = PACKET_SIZE;
  }else
  { /* Remain bytes fit into current packet */
    ulNumberOfBytesToSend = ptSiiProv->ulRemainingBytes;
    ptSiiProv->pfnCurrenState = &State_Patch2ndStationAliasIntoSii;
  }

  eRslt = TLR_POOL_PACKET_GET( ptRsc->tLoc.hPool, &ptSiiWriteReq );
  if(TLR_S_OK == eRslt)
  {
    memset(ptSiiWriteReq, 0x00, sizeof(*ptSiiWriteReq));
    ptSiiWriteReq->tHead.ulSrc    = ( TLR_UINT32 )ptRsc->tLoc.hQue;
    ptSiiWriteReq->tHead.ulLen    = sizeof(ptSiiWriteReq->tData.ulOffset) + ulNumberOfBytesToSend;
    ptSiiWriteReq->tHead.ulCmd    = ECAT_ESM_SII_WRITE_REQ;

    ptSiiWriteReq->tData.ulOffset = ptSiiProv->ulCurrentByte;
    memcpy(&ptSiiWriteReq->tData.abData[0], &ptSiiProv->pabSiiImage[ptSiiWriteReq->tData.ulOffset], ulNumberOfBytesToSend);

    GenericPacketSending(ptRsc, ptSiiWriteReq);
    ptSiiProv->ulCurrentByte += ulNumberOfBytesToSend;
    ptSiiProv->ulRemainingBytes -= ulNumberOfBytesToSend;
  }else
  {
    TLR_TSK_SET_STATE(eRslt);
  }
  return false;
}

/*************************************************************************************/
static bool State_Initialize(EXAMPLETASK1_RSC_T* ptRsc)
{
  SII_PROVIDER_T* ptSiiProv = &ptRsc->tLoc.tSiiProv;

  ptSiiProv->ulCurrentByte = 0x80;/* sections before are set internally by ECS stack therefore we start at 0x80 */
  ptSiiProv->ulRemainingBytes = ptSiiProv->ulSizeOfSiiImage - ptSiiProv->ulCurrentByte;
  ptSiiProv->pfnCurrenState = &State_SendSiiWriteReq;

  return true; /* trigger State_SendSiiWriteReq */
}

/**********************************************************************************//**
 *
 * \param ptRsc
 * \return TLR_S_OK if success
 */
uint32_t SiiProvider_Init(EXAMPLETASK1_RSC_T* ptRsc,
                                     uint8_t* pabSiiImage,
                                     uint32_t ulSizeOfSiiImage)
{
  uint32_t ulRslt = TLR_S_OK;
  SII_PROVIDER_T* ptSiiProv = &ptRsc->tLoc.tSiiProv;
  uint8_t abSecData[32];

  if(    NULL == pabSiiImage
      || ulSizeOfSiiImage <= 0x80 )
  {
    /* don't create Sii Image therefore finish FSM to stimulate ObjectDictionary_OdCreationFsm */
    ptSiiProv->pfnCurrenState = &State_Finished;
  }else
  {
    ulRslt = Drv_SecGetRawArea(abSecData, 2);
  }

  if(TLR_S_OK == ulRslt)
  {
    ptSiiProv->pabSiiImage = pabSiiImage;
    ptSiiProv->ulSizeOfSiiImage = ulSizeOfSiiImage;
    ptSiiProv->usStationAlias = abSecData[0] | (abSecData[1]<<8);
    ptSiiProv->pfnCurrenState = &State_Initialize;
  }
  return ulRslt;
}

void SiiProvider_SiiCreationFsm(EXAMPLETASK1_RSC_T* ptRsc)
{
  SII_PROVIDER_T* ptSiiProv = &ptRsc->tLoc.tSiiProv;

  while( true == ptSiiProv->pfnCurrenState(ptRsc) ); /* trigger current state as long as FSM shall be retriggered */
}
