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
$Id: ExampleTask1_ObjectCreator.c 1862 2016-01-27 10:56:55Z Ricky $:

Description:
 See doxygen
***********************************************************************************//**
  \file ExampleTask1_ObjectCreator.c
  Module which sends an create object/subobject request and does also fragment packet
  (as in DPM-API Manual)
  and fragmenting data of the packet (as in protocol api)
**************************************************************************************/
#include "ExampleTask1_Resources.h"
#include "ExampleTask1_Functions.h"
#include "OdV3_Public.h"
#include "ExampleTask1_ObjectCreator.h"

#define member_size(type, member) sizeof(((type *)0)->member)

EXAMPLETASK1_RSC_T* s_ptRsc;
const COE_INIT_ODV3_T* s_ptOdEntry;
bool* s_pfProcessingFinished;

static void SendCoeCreateObjReqInit(EXAMPLETASK1_RSC_T* ptRsc, const COE_INIT_ODV3_T* ptOdEntry)
{
  OBJECT_DICTIONARY_T* ptObjDict = &ptRsc->tLoc.tObjDict;
  SEND_COE_CREATE_STATES_T* ptEnv = &ptObjDict->tEnvOfSendCoeCreateObjReq;

  ptEnv->ulDestId = 0;
  ptEnv->ulPartState = 0;
  ptEnv->ulPartPos = 0;
  ptEnv->ulTotalDataBytes = 0;
  ptEnv->ulTransferredDataBytes = 0;
  ptEnv->ulNameLength = 0;
  ptEnv->ulFragmentPos = 0;
  ptEnv->pbMinimumValue = (TLR_UINT8 *) ptOdEntry->pvMinimumValue;
  ptEnv->pbMaximumValue = (TLR_UINT8 *) ptOdEntry->pvMaximumValue;
  ptEnv->pbDefaultValue = (TLR_UINT8 *) ptOdEntry->pvDefaultValue;
  ptEnv->pbInitialValue = (TLR_UINT8 *) ptOdEntry->pvInitialValue;
  ptEnv->bValueInfo = ptOdEntry->bValueInfo & COE_ODV3_VALUE_INFO_MASK;

  if(NULL != ptOdEntry->pszName)
  {
    ptEnv->ulNameLength = strlen(ptOdEntry->pszName);
    ptEnv->ulTotalDataBytes += 4;
    ptEnv->pszCreateName = (TLR_STR*) ptOdEntry->pszName;
  }

  if(NULL != ptOdEntry->pulUnit)
  {
    ptEnv->ulTotalDataBytes += 4;
  }

  ptEnv->ulTotalDataBytes += ptEnv->ulNameLength;
  ptEnv->ulTotalDataBytes += ptOdEntry->ulMinimumValueLength;
  ptEnv->ulTotalDataBytes += ptOdEntry->ulMaximumValueLength;
  ptEnv->ulTotalDataBytes += ptOdEntry->ulInitialValueLength;
  ptEnv->ulTotalDataBytes += ptOdEntry->ulDefaultValueLength;

  if(NULL != ptEnv->pbMinimumValue)
  {
    ptEnv->ulTotalDataBytes += 4;
  }

  if(NULL != ptEnv->pbMaximumValue)
  {
    ptEnv->ulTotalDataBytes += 4;
  }

  if(NULL != ptEnv->pbInitialValue)
  {
    ptEnv->ulTotalDataBytes += 4;
  }

  if(NULL != ptEnv->pbDefaultValue)
  {
    ptEnv->ulTotalDataBytes += 4;
  }

  if(0 != ptEnv->pszCreateName)
  {
    ptEnv->bValueInfo |= ODV3_VALUE_INFO_NAME;
  }

  if(0 != ptOdEntry->ulMinimumValueLength)
  {
    ptEnv->bValueInfo |= ODV3_VALUE_INFO_MINIMUM;
  }

  if(0 != ptOdEntry->ulMaximumValueLength)
  {
    ptEnv->bValueInfo |= ODV3_VALUE_INFO_MAXIMUM;
  }

  if(0 != ptOdEntry->ulInitialValueLength)
  {
    ptEnv->bValueInfo |= ODV3_VALUE_INFO_INITIAL_VALUE;
  }

  if(0 != ptOdEntry->ulDefaultValueLength)
  {
    ptEnv->bValueInfo |= ODV3_VALUE_INFO_DEFAULT_VALUE;
  }

  if(NULL != ptOdEntry->pulUnit)
  {
    ptEnv->bValueInfo |= ODV3_VALUE_INFO_ECAT_UNIT;
  }
}

static TLR_RESULT SendCoeCreateObjReqFrag(EXAMPLETASK1_RSC_T* ptRsc, const COE_INIT_ODV3_T* ptOdEntry)
{
  TLR_RESULT eRslt = TLR_S_OK;
  OBJECT_DICTIONARY_T* ptObjDict = &ptRsc->tLoc.tObjDict;
  SEND_COE_CREATE_STATES_T* ptEnv = &ptObjDict->tEnvOfSendCoeCreateObjReq;

  TLR_UINT8* pabData;
  TLR_UINT8* pabSrcData;
  TLR_UINT32 ulFragmentLength = member_size(ODV3_CREATE_SUBOBJECT_REQ_DATA_T, abData);

  EXAMPLETASK1_PACKET_T* ptPck;

  eRslt = TLR_POOL_PACKET_GET(ptRsc->tLoc.hPool, &ptPck);
  if(TLR_S_OK != eRslt)
  {
    TLR_TSK_SET_STATE(eRslt);
  }


  ptPck->tHead.ulCmd = ptOdEntry->ulCmd;
  ptPck->tHead.ulSrc = (TLR_UINT32) ptRsc->tLoc.hQue;
  if(ulFragmentLength >= ptEnv->ulTotalDataBytes)
  {
    ptPck->tHead.ulExt = TLR_PACKET_SEQ_NONE;
    ptEnv->eCallType = ECS_DEMO_CT_INIT; /* Next call af this function happens, if new object shall be created */
  }
  else if(0 == ptEnv->ulTransferredDataBytes)
  {
    ptPck->tHead.ulExt = TLR_PACKET_SEQ_FIRST;
    ptEnv->eCallType = ECS_DEMO_CT_FRAG; /* next time this function is called init sequence is skipped */
  }
  else if(ulFragmentLength >= ptEnv->ulTotalDataBytes - ptEnv->ulTransferredDataBytes)
  {
    ptPck->tHead.ulExt = TLR_PACKET_SEQ_LAST;
    ptEnv->eCallType = ECS_DEMO_CT_INIT; /* Next call af this function happens, if new object shall be created */
  }
  else
  {
    ptPck->tHead.ulExt = TLR_PACKET_SEQ_MIDDLE;
    ptEnv->eCallType = ECS_DEMO_CT_FRAG; /* next time this function is called init sequence is skipped */
  }
  ptPck->tHead.ulDestId = ptEnv->ulDestId;
  ptPck->tHead.ulSta = TLR_S_OK;
  ptPck->tHead.ulSrcId = (TLR_UINT32) ptRsc->tLoc.hPool;
  ptPck->tHead.ulRout = 0;
  ptPck->tHead.ulId = 0;
  ptPck->tHead.ulDest = 0;

  switch(ptOdEntry->ulCmd)
  {
    case ODV3_CREATE_OBJECT_REQ:
      ptPck->tOdv3CreateObjectReq.tData.bIndicationFlags = ptOdEntry->bIndicationFlags;

      ptPck->tOdv3CreateObjectReq.tData.bMaxNumOfSubObjs = ptOdEntry->bMaxNumOfSubObjs;
      ptPck->tOdv3CreateObjectReq.tData.bObjectCode = ptOdEntry->bObjectCode;
      ptPck->tOdv3CreateObjectReq.tData.bValueInfo = ptEnv->bValueInfo;
      ptPck->tOdv3CreateObjectReq.tData.ulMaxFieldUnits = ptOdEntry->ulMaxFieldUnits;
      ptPck->tOdv3CreateObjectReq.tData.ulTotalDataBytes = ptEnv->ulTotalDataBytes;
      ptPck->tOdv3CreateObjectReq.tData.usAccessFlags = ptOdEntry->usAccessFlags;
      ptPck->tOdv3CreateObjectReq.tData.usDatatype = ptOdEntry->usDatatype;
      ptPck->tOdv3CreateObjectReq.tData.usIndex = ptOdEntry->usIndex;
      ptPck->tOdv3CreateObjectReq.tData.usAccessRights = ptOdEntry->usAccessRights;
      ptPck->tHead.ulLen = offsetof(ODV3_CREATE_OBJECT_REQ_DATA_T, abData);
      pabData = ptPck->tOdv3CreateObjectReq.tData.abData;
      break;

    case ODV3_CREATE_SUBOBJECT_REQ:
      ptPck->tOdv3CreateSubobjectReq.tData.bIndicationFlags = ptOdEntry->bIndicationFlags;

      ptPck->tOdv3CreateSubobjectReq.tData.bSubIndex = ptOdEntry->bSubIndex;
      ptPck->tOdv3CreateSubobjectReq.tData.bValueInfo = ptEnv->bValueInfo;
      ptPck->tOdv3CreateSubobjectReq.tData.ulMaxFieldUnits = ptOdEntry->ulMaxFieldUnits;
      ptPck->tOdv3CreateSubobjectReq.tData.ulTotalDataBytes = ptEnv->ulTotalDataBytes;
      ptPck->tOdv3CreateSubobjectReq.tData.usAccessRights = ptOdEntry->usAccessRights;
      ptPck->tOdv3CreateSubobjectReq.tData.usDatatype = ptOdEntry->usDatatype;
      ptPck->tOdv3CreateSubobjectReq.tData.usIndex = ptOdEntry->usIndex;
      ptPck->tHead.ulLen = offsetof(ODV3_CREATE_SUBOBJECT_REQ_DATA_T, abData);
      pabData = ptPck->tOdv3CreateSubobjectReq.tData.abData;
      break;

    default:
      TLS_QUE_PACKETDONE(ptRsc->tLoc.hPool, ptRsc->tLoc.hQue, ptPck);
      eRslt = TLR_E_FAIL;
      break;
  }

  if(TLR_S_OK == eRslt)
  {
    ptEnv->ulFragmentPos = 0;
    while(ptEnv->ulFragmentPos < ulFragmentLength && ptEnv->ulTransferredDataBytes < ptEnv->ulTotalDataBytes)
    {
      switch(ptEnv->ulPartState)
      {
        case 0:  /* unit */
          if(ptEnv->bValueInfo & ODV3_VALUE_INFO_ECAT_UNIT)
          {
            pabSrcData = (TLR_UINT8*) ptOdEntry->pulUnit;
            pabData[ptEnv->ulFragmentPos++] = pabSrcData[ptEnv->ulPartPos++];

            ++ptEnv->ulTransferredDataBytes;
            if(ptEnv->ulPartPos < 4)
            {
              break;
            }
          }

          ptEnv->ulPartPos = 0;
          ++ptEnv->ulPartState;
          /* fall-through */

        case 1: /* name */
          if(ptEnv->bValueInfo & ODV3_VALUE_INFO_NAME)
          {
            if(ptEnv->ulPartPos < 4)
            {
              pabData[ptEnv->ulFragmentPos++] = (ptEnv->ulNameLength >> ((ptEnv->ulPartPos++) * 8)) & 0xFF;
            }
            else
            {
              pabSrcData = (TLR_UINT8*) ptEnv->pszCreateName;
              pabData[ptEnv->ulFragmentPos++] = pabSrcData[(ptEnv->ulPartPos++) - 4];
            }

            ++ptEnv->ulTransferredDataBytes;
            if(ptEnv->ulPartPos < ptEnv->ulNameLength + 4)
            {
              break;
            }
          }

          ptEnv->ulPartPos = 0;
          ++ptEnv->ulPartState;
          /* fall-through */

        case 2: /* min */
          if(ptEnv->bValueInfo & ODV3_VALUE_INFO_MINIMUM)
          {
            if(ptEnv->ulPartPos < 4)
            {
              pabData[ptEnv->ulFragmentPos++] = (ptOdEntry->ulMinimumValueLength >> ((ptEnv->ulPartPos++) * 8)) & 0xFF;
            }
            else
            {
              pabSrcData = ptEnv->pbMinimumValue;
              pabData[ptEnv->ulFragmentPos++] = pabSrcData[(ptEnv->ulPartPos++) - 4];
            }

            ++ptEnv->ulTransferredDataBytes;
            if(ptEnv->ulPartPos < ptOdEntry->ulMinimumValueLength + 4)
            {
              break;
            }
          }

          ptEnv->ulPartPos = 0;
          ++ptEnv->ulPartState;
          /* fall-through */

        case 3: /* max */
          if(ptEnv->bValueInfo & ODV3_VALUE_INFO_MAXIMUM)
          {
            if(ptEnv->ulPartPos < 4)
            {
              pabData[ptEnv->ulFragmentPos++] = (ptOdEntry->ulMaximumValueLength >> ((ptEnv->ulPartPos++) * 8)) & 0xFF;
            }
            else
            {
              pabSrcData = ptEnv->pbMaximumValue;
              pabData[ptEnv->ulFragmentPos++] = pabSrcData[(ptEnv->ulPartPos++) - 4];
            }

            ++ptEnv->ulTransferredDataBytes;
            if(ptEnv->ulPartPos < ptOdEntry->ulMaximumValueLength + 4)
            {
              break;
            }
          }

          ptEnv->ulPartPos = 0;
          ++ptEnv->ulPartState;
          /* fall-through */

        case 4: /* init */
          if(ptEnv->bValueInfo & ODV3_VALUE_INFO_INITIAL_VALUE)
          {
            if(ptEnv->ulPartPos < 4)
            {
              pabData[ptEnv->ulFragmentPos++] = (ptOdEntry->ulInitialValueLength >> ((ptEnv->ulPartPos++) * 8)) & 0xFF;
            }
            else
            {
              pabSrcData = ptEnv->pbInitialValue;
              pabData[ptEnv->ulFragmentPos++] = pabSrcData[(ptEnv->ulPartPos++) - 4];
            }

            ++ptEnv->ulTransferredDataBytes;
            if(ptEnv->ulPartPos < ptOdEntry->ulInitialValueLength + 4)
            {
              break;
            }
          }

          ptEnv->ulPartPos = 0;
          ++ptEnv->ulPartState;
          /* fall-through */

        case 5: /* def */
          if(ptEnv->bValueInfo & ODV3_VALUE_INFO_DEFAULT_VALUE)
          {
            if(ptEnv->ulPartPos < 4)
            {
              pabData[ptEnv->ulFragmentPos++] = (ptOdEntry->ulDefaultValueLength >> ((ptEnv->ulPartPos++) * 8)) & 0xFF;
            }
            else
            {
              pabSrcData = ptEnv->pbDefaultValue;
              pabData[ptEnv->ulFragmentPos++] = pabSrcData[(ptEnv->ulPartPos++) - 4];
            }

            ++ptEnv->ulTransferredDataBytes;
            if(ptEnv->ulPartPos < ptOdEntry->ulDefaultValueLength + 4)
            {
              break;
            }
          }

          ptEnv->ulPartPos = 0;
          ++ptEnv->ulPartState;
          /* fall-through */
      }
    }
    ptPck->tHead.ulLen += ptEnv->ulFragmentPos;


    /////////////////////////

    /* update ulDestId field of TLR_QUE_LINK_T, needed for fragmented packets*/
    TLR_QUE_LINK_SET_NEW_DESTID(ptRsc->tRem.hQueEsm, ptPck->tHead.ulDestId);
    ptEnv->ulDestId++; /* assumption ODV3 stack increases its ulDestId, too */
    GenericPacketSending(ptRsc, ptPck);
  }
  return eRslt;
}

/**************************************************************************************
 *
 * @param ptRsc [in,out] only tEnvOfSendCoeCreateObjReq will be written
 * @param ptOdEntry [in] OD entry which shall be created
 * @param pfProcessingFinished [out] true if processing finished, false if processing
 *        not finished, function has to be triggered again to create the object
 * @return TLR_S_OK if success
 *************************************************************************************/
uint32_t ObjectCreator_SendCoeCreateObjReq(EXAMPLETASK1_RSC_T* ptRsc,
                                        const COE_INIT_ODV3_T* ptOdEntry,
                                                         bool* pfProcessingFinished)
{
  uint32_t ulRslt = TLR_S_OK;
  bool fProcessingFinished = false;
  OBJECT_DICTIONARY_T* ptObjDict = &ptRsc->tLoc.tObjDict;
  SEND_COE_CREATE_STATES_T* ptEnv = &ptObjDict->tEnvOfSendCoeCreateObjReq;

  switch(ptEnv->eCallType)
  {
  case ECS_DEMO_CT_INIT:
    SendCoeCreateObjReqInit(ptRsc, ptOdEntry);
    ulRslt = SendCoeCreateObjReqFrag(ptRsc, ptOdEntry);
    break;
  case ECS_DEMO_CT_FRAG:
    ulRslt = SendCoeCreateObjReqFrag(ptRsc, ptOdEntry);
    break;
  default:
    ulRslt = TLR_E_UNEXPECTED;
    break;
  }

  switch(ptEnv->eCallType) /* changed before in SendCoeCreateObjReqFrag() */
  {
    case ECS_DEMO_CT_INIT:
      fProcessingFinished = true;
      break;
    case ECS_DEMO_CT_FRAG:
      fProcessingFinished = false;
      break;
  }
  *pfProcessingFinished = fProcessingFinished;
  return ulRslt;
}

