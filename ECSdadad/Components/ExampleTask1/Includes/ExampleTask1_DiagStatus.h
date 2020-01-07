/**************************************************************************************
Copyright (c) Hilscher Gesellschaft fuer Systemautomation mbH. All Rights Reserved.
***************************************************************************************
$Id: ExampleTask1_DiagStatus.h 1617 2015-11-23 14:06:45Z Ricky $:

Description:
 See doxygen
***********************************************************************************//**
  \file ExampleTask1_DiagStatus.h
  \note EXAMPLETASK1_RSC_T must be included before with STATUS_DIAG_T
        defined as ptRsc->tLoc.tECSDemoStatusDiag, in file
        ExampleTask1_Resources.h
**************************************************************************************/
#ifdef INCLUDE_TYPEDEF_ONLY

/** Typedef for ressources of DiagStatus* functions **********************************/
typedef struct STATUS_DIAG_Ttag
{
  uint32_t ulSendPacketFail; /**< Send packet failed counter     */
  uint32_t ulDstQueue;       /**< Destination queue              */
  uint32_t ulSendErrCode;    /**< Send error status code         */
  uint32_t ulDownloadCnfPos; /**< Confirmation positive counter  */
  uint32_t ulDownloadCnfNeg; /**< Confirmation negative counter  */
  uint32_t ulCntPacketOut;   /**< Counter of outstanding packets */
  uint32_t ulReserved0;      /**< Reserved for future used       */
  uint32_t ulReserved1;      /**< Reserved for future used       */
  uint32_t ulReserved2;      /**< Reserved for future used       */
}STATUS_DIAG_T;
#else
#ifndef COMPONENTS_EXAMPLETASK1_INCLUDES_EXAMPLETASK1_DIAGSTATUS_H_
#define COMPONENTS_EXAMPLETASK1_INCLUDES_EXAMPLETASK1_DIAGSTATUS_H_


/**********************************************************************************//**
  Initialize diagnosis funtionality
 \param ptRsc[in,out] uses ::STATUS_DIAG_Ttag for ressources of module
 \return TLR_S_OK if success
**************************************************************************************/
static inline uint32_t DiagStatusInit(EXAMPLETASK1_RSC_T* ptRsc)
{
  return 0; /*TLR_S_OK*/
}

static inline void DiagStatusSaveInfoOfFailedPacket(EXAMPLETASK1_RSC_T* ptRsc,
                                                         TLR_QUE_LINK_T tQueueLink,
                                                               uint32_t ulRslt)
{
  ptRsc->tLoc.tStatusDiag.ulSendPacketFail += 1;
  ptRsc->tLoc.tStatusDiag.ulDstQueue        = (uint32_t) tQueueLink.hQue;
  ptRsc->tLoc.tStatusDiag.ulSendErrCode     = ulRslt;
}

static inline void DiagStatusIncreaseCounterOfOutstandingPackets(EXAMPLETASK1_RSC_T* ptRsc)
{
  ptRsc->tLoc.tStatusDiag.ulCntPacketOut++;
}

static inline void DiagStatusDecreaseCounterOfOutstandingPackets(EXAMPLETASK1_RSC_T* ptRsc)
{
  ptRsc->tLoc.tStatusDiag.ulCntPacketOut--;
}

static inline void DiagStatusIncreaseCounterOfNegativeConfirmations(EXAMPLETASK1_RSC_T* ptRsc)
{
  ptRsc->tLoc.tStatusDiag.ulDownloadCnfNeg++;
}

static inline void DiagStatusIncreaseCounterOfPositiveConfirmations(EXAMPLETASK1_RSC_T* ptRsc)
{
  ptRsc->tLoc.tStatusDiag.ulDownloadCnfPos++;
}

#endif /* INCLUDE_TYPEDEF_ONLY */
#endif /* COMPONENTS_EXAMPLETASK1_INCLUDES_EXAMPLETASK1_DIAGSTATUS_H_ */
