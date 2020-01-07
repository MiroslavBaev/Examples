/**************************************************************************************
Copyright (c) Hilscher Gesellschaft fuer Systemautomation mbH. All Rights Reserved.
***************************************************************************************
$Id: TcpUdpApTask_DiagStatus.h 1311 2015-09-08 16:08:52Z Ricky $:

Description:
 See doxygen
***********************************************************************************//**
  \file TCPUDPAPTASK_DiagStatus.h
  \note TCPUDPAPTASK_RSC_T must be included before with STATUS_DIAG_T
        defined as ptRsc->tLoc.tStatusDiag, in file
        TCPUDPAPTASK_Resources.h
**************************************************************************************/
#ifdef INCLUDE_TYPEDEF_ONLY

/**********************************************************************************//**
 * Typedef for ressources of DiagStatus* functions
 */
typedef struct
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
#ifndef COMPONENTS_TCPUDPAPTASK_INCLUDES_TCPUDPAPTASK_DIAGSTATUS_H_
#define COMPONENTS_TCPUDPAPTASK_INCLUDES_TCPUDPAPTASK_DIAGSTATUS_H_


/**********************************************************************************//**
 * Initialize diagnosis funtionality
 * \param ptRsc [in,out] uses ::STATUS_DIAG_Ttag for ressources of module
 * \return TLR_S_OK if success
 */
static inline uint32_t DiagStatusInit(TCPUDPAPTASK_RSC_T* ptRsc)
{
  return 0; /*TLR_S_OK*/
}

static inline void DiagStatusSaveInfoOfFailedPacket(TCPUDPAPTASK_RSC_T* ptRsc,
                                                         TLR_QUE_LINK_T tQueueLink,
                                                               uint32_t ulRslt)
{
  ptRsc->tLoc.tStatusDiag.ulSendPacketFail += 1;
  ptRsc->tLoc.tStatusDiag.ulDstQueue        = (uint32_t) tQueueLink.hQue;
  ptRsc->tLoc.tStatusDiag.ulSendErrCode     = ulRslt;
}

static inline void DiagStatusIncreaseCounterOfOutstandingPackets(TCPUDPAPTASK_RSC_T* ptRsc)
{
  ptRsc->tLoc.tStatusDiag.ulCntPacketOut++;
}

static inline void DiagStatusDecreaseCounterOfOutstandingPackets(TCPUDPAPTASK_RSC_T* ptRsc)
{
  ptRsc->tLoc.tStatusDiag.ulCntPacketOut--;
}

static inline void DiagStatusIncreaseCounterOfNegativeConfirmations(TCPUDPAPTASK_RSC_T* ptRsc)
{
  ptRsc->tLoc.tStatusDiag.ulDownloadCnfNeg++;
}

static inline void DiagStatusIncreaseCounterOfPositiveConfirmations(TCPUDPAPTASK_RSC_T* ptRsc)
{
  ptRsc->tLoc.tStatusDiag.ulDownloadCnfPos++;
}

#endif /* INCLUDE_TYPEDEF_ONLY */
#endif /* COMPONENTS_TCPUDPAPTASK_INCLUDES_TCPUDPAPTASK_DIAGSTATUS_H_ */
