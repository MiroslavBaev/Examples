/******************************************************************************

  Copyright (C) 2010 Hilscher Gesellschaft für Systemautomation mbH.

  This program can be used by everyone according the "industrialNETworX Public License INPL".

  The license can be downloaded under <http://www.industrialNETworX.com>.

*******************************************************************************

  Last Modification:
    @version $Id: TLS_Wrapper.h 569 2010-11-19 08:47:54Z MichaelT $

  Description:
    TLS Wrapper for non operating system functions (TLR Support - prefix TLS_)

  Changes:
    Date        Author        Description
  ---------------------------------------------------------------------------
    2010-04-14  NC            Changed Parameter names corresponding to the
                              manual

    2010-04-07  NC            Added CPU_FRMT_MOTOROLA, CPU_FRMT_INTEL

    2010-03-23  NC            File created.

******************************************************************************/


#ifndef __TLS_WRAPPER_H
#define __TLS_WRAPPER_H

#ifdef __cplusplus
  extern "C" {
#endif  /* __cplusplus */



/*****************************************************************************/
/* Include Files Required                                                    */
/*****************************************************************************/

#include "TLR_INX_Includes.h"



/****************************************************************************************
 * processor dependency *
 *
 * DEFINE              VALUE       DESCRIPTION
 *  CPU_FRMT_INTEL      1           CPU uses little endian == INTEL format using CPU
 *  CPU_FRMT_MOTOROLA   0           CPU uses big endian    == MOTOROLA format
 */
 
#define CPU_FRMT_MOTOROLA  0
#define CPU_FRMT_INTEL     1
 
#if !defined( __TLS_CPU_BIG_ENDIAN__ )    /* INTEL */
#define CPU_FRMT  CPU_FRMT_INTEL
#else
#define CPU_FRMT  CPU_FRMT_MOTOROLA
#endif



/*************************************************************************************/
/* system independend definition */

#define TLS_MAKE_USED(param)      (param = param)
#define TLS_MAX_CNT(t)            (sizeof(t)/sizeof(t[0]))
#define TLS_MIN(a,b)              ((a < b) ? a : b)
#define TLS_MAX(a,b)              ((a > b) ? a : b)


/*************************************************************************************/
/* double linked list, not synchronized */

/* types */
typedef struct TLS_DBLY_LST_Ttag      TLS_DBLY_LST_T;

struct TLS_DBLY_LST_Ttag              /* double linked list */
{
  TLS_DBLY_LST_T*  ptNxt;
  TLS_DBLY_LST_T*  ptPrv;
};

/* macros */

/* reset the base of list */
#define TLS_DBLY_RESET(ptBase)              (ptBase)->ptNxt = (TLS_DBLY_LST_T*)(ptBase);\
                                            (ptBase)->ptPrv = (TLS_DBLY_LST_T*)(ptBase);

/* insert element to the top of list */
#define TLS_DBLY_INSERT_TOP(ptBase, ptNew)  (ptNew)->ptPrv         = (TLS_DBLY_LST_T*)(ptBase);\
                                            (ptNew)->ptNxt         = (TLS_DBLY_LST_T*)(ptBase)->ptNxt;\
                                            (ptBase)->ptNxt->ptPrv = (TLS_DBLY_LST_T*)(ptNew);\
                                            (ptBase)->ptNxt        = (TLS_DBLY_LST_T*)(ptNew);

/* insert element to the end of list */
#define TLS_DBLY_INSERT_END(ptBase, ptNew)  (ptNew)->ptNxt         = (TLS_DBLY_LST_T*)(ptBase);\
                                            (ptNew)->ptPrv         = (TLS_DBLY_LST_T*)(ptBase)->ptPrv;\
                                            (ptBase)->ptPrv->ptNxt = (TLS_DBLY_LST_T*)(ptNew);\
                                            (ptBase)->ptPrv        = (TLS_DBLY_LST_T*)(ptNew);

/* remove element from list */
#define TLS_DBLY_REMOVE(ptElement)          (ptElement)->ptPrv->ptNxt = (ptElement)->ptNxt;\
                                            (ptElement)->ptNxt->ptPrv = (ptElement)->ptPrv;



/*************************************************************************************/
/* constant static array, macros */

/*
 * definition
 *  use only for constant and global defined arrays
 *  it is only for precompiler
 */
#if !defined(__TLS_CPU_BIG_ENDIAN__)                       /* INTEL */

/* split 16bit/32bit value into 2/4 8bit values */
#define TLS_CONST_16_TO_08(v)             (v)&0xFF, (v)>>8
#define TLS_CONST_32_TO_08(v)             (v)&0xFF, ((v)>>8)&0xFF, ((v)>>16)&0xFF, ((v)>>24)&0xFF

/* combine 2/4 8bit values into 16bit/32bit value */
#define TLS_CONST_08_TO_16(b1, b2)        ((b2 << 8) + b1)
#define TLS_CONST_08_TO_32(b1, b2, b3, b4)((b4 << 24) + (b3 << 16) + (b2 << 8) + b1)

#else                     /* MOTOROLA */

/* split 16bit/32bit value into 2/4 8bit values */
#define TLS_CONST_16_TO_08(v)             (v)>>8, (v)&0xFF
#define TLS_CONST_32_TO_08(v)             ((v)>>24)&0xFF, ((v)>>16)&0xFF, ((v)>>8)&0xFF, (v)&0xFF

/* combine 2/4 8bit values into 16bit/32bit value */
#define TLS_CONST_08_TO_16(b1, b2)        ((b1 << 8) + b2)
#define TLS_CONST_08_TO_32(b1, b2, b3, b4)((b1 << 24) + (b2 << 16) + (b3 << 8) + b4)

#endif /* #if !defined(__TLS_CPU_BIG_ENDIAN__) */

/*
 * example
 * STATIC CONST TLS_UINT8 g_abExample[] =
 * {
 *    0x01, 0x23, 0x45, 0x67,                   8bit values
 *    TLS_SET_16(0x0123), TLS_SET_16(0x4567),   16bit values
 *    TLS_SET_32(0x01234567),                   32bit value
 * };
*/


/*************************************************************************************/
/* Swap Wrapper */

#define TLS_SWAP_16(n) (TLR_UINT16)((((n)<<8)&0xFF00)|(((n)>>8)&0x00FF)) /* ((((TLR_UINT8*)&n)[0] << 8) | ((TLR_UINT8*)&n)[1]) */
#define TLS_SWAP_32(n) (TLR_UINT32)SWAP_UINT32(n)

#if !defined(__TLS_CPU_BIG_ENDIAN__)
  /* Little Endian (Intel) */
  #define TLS_HTON16(n)     TLS_SWAP_16(n)
  #define TLS_NTOH16(n)     TLS_SWAP_16(n)
  #define TLS_HTON32(n)     TLS_SWAP_32(n)
  #define TLS_NTOH32(n)     TLS_SWAP_32(n)
#else
  /* Big Endian (Motorola) */
  #define TLS_HTON16(n)     (TLR_UINT16)(n)
  #define TLS_NTOH16(n)     (TLR_UINT16)(n)
  #define TLS_HTON32(n)     (TLR_UINT32)(n)
  #define TLS_NTOH32(n)     (TLR_UINT32)(n)
#endif

/*************************************************************************************/
/* fully-qualified addressed queue functions */

INLINE TLR_RESULT TLS_QUE_RETURNPACKET(TLR_VOID* pvPck)
{
  (((TLR_PACKET_HEADER_T*)pvPck)->ulCmd)|=1; /* make confirmation/response */
  return TLR_QUE_SENDPACKET_FIFO_INTERN(((TLR_PACKET_HEADER_T*)pvPck)->ulSrc, pvPck, TLR_INFINITE);
}

INLINE TLR_RESULT TLS_QUE_RETURNPACKET_TIMEOUT(TLR_VOID* pvPck, TLR_UINT uTimeout)
{
  (((TLR_PACKET_HEADER_T*)pvPck)->ulCmd)|=1; /* make confirmation/response */
  return TLR_QUE_SENDPACKET_FIFO_INTERN(((TLR_PACKET_HEADER_T*)pvPck)->ulSrc, pvPck, uTimeout);
}

#define TLS_QUE_RETURNPACKET_CMD_UNCHANGED(pvPck) \
  TLR_QUE_SENDPACKET_FIFO_INTERN(((TLR_PACKET_HEADER_T*)pvPck)->ulSrc, pvPck, TLR_INFINITE);

#define TLS_QUE_LINK_GET_MTU(tQueLink, ulMtu) { ulMtu = (tQueLink).ulMTU; }

#ifdef _MID_SYS_ENABLE_
TLR_RESULT MidSysQueIdentify(TLR_STR FAR* pszQueueName, TLR_UINT32 ulInstance, TLR_QUE_LINK_T FAR* ptQueLink);
#define TLS_QUE_IDENTIFY(pszQueueName, uInstance, ptQueLink) \
          MidSysQueIdentify(pszQueueName, uInstance, ptQueLink)
#else
#define TLS_QUE_IDENTIFY(pszQueueName, uInstance, ptQueLink) \
  TLR_QUE_IDENTIFY_INTERN(pszQueueName, uInstance, &(ptQueLink)->hQue)
#endif

INLINE TLR_RESULT TLS_QUE_SENDPACKET_FIFO(TLR_QUE_LINK_T FAR tQueLink, TLR_VOID FAR* pvPck, TLR_UINT uTimeout)
{
  ((TLR_PACKET_HEADER_T*)pvPck)->ulDest = tQueLink.ulDest;
  ((TLR_PACKET_HEADER_T*)pvPck)->ulDestId = tQueLink.ulDestId;
  return TLR_QUE_SENDPACKET_FIFO_INTERN(tQueLink.hQue, pvPck, uTimeout);
}

INLINE TLR_RESULT TLS_QUE_SENDPACKET_LIFO(TLR_QUE_LINK_T tQueLink, TLR_VOID* pvPck, TLR_UINT uTimeout)
{
  ((TLR_PACKET_HEADER_T*)pvPck)->ulDest = tQueLink.ulDest;
  ((TLR_PACKET_HEADER_T*)pvPck)->ulDestId = tQueLink.ulDestId;
  return TLR_QUE_SENDPACKET_LIFO_INTERN(tQueLink.hQue, pvPck, uTimeout);
}

INLINE TLR_RESULT TLS_QUE_POSTPACKET(TLR_QUE_LINK_T tQueLink, TLR_VOID* pvPck)
{
  ((TLR_PACKET_HEADER_T*)pvPck)->ulDest = tQueLink.ulDest;
  ((TLR_PACKET_HEADER_T*)pvPck)->ulDestId = tQueLink.ulDestId;
  return TLR_QUE_POSTPACKET_INTERN(tQueLink.hQue, pvPck);
}

#define TLS_QUE_LINK_FROM_PACKET(pvPck, ptQueLink) \
    { \
      (ptQueLink)->hQue=(TLR_HANDLE)((TLR_PACKET_HEADER_T*)pvPck)->ulSrc; \
      (ptQueLink)->ulDestId=((TLR_PACKET_HEADER_T*)pvPck)->ulSrcId; \
      (ptQueLink)->ulDest=((TLR_PACKET_HEADER_T*)pvPck)->ulRout; \
      (ptQueLink)->ulMTU=0; \
    }

#define TLS_QUE_LINK_SET_PACKET_DEST(pvPck, tQueLink) \
  { \
    ((TLR_PACKET_HEADER_T*)pvPck)->ulDest=(tQueLink).ulDest; \
    ((TLR_PACKET_HEADER_T*)pvPck)->ulDestId=(tQueLink).ulDestId; \
  }

#define TLS_QUE_LINK_VALID(tQueLink) \
  (0!=(tQueLink).hQue)

#define TLS_QUE_LINK_INVALID(tQueLink) \
  (0==(tQueLink).hQue)

#define TLS_QUE_LINK_INVALIDATE(tQueLink) \
    { \
      (tQueLink).hQue=0; \
      (tQueLink).ulDest=0; \
    }

#define TLS_QUE_LINK_SET_PACKET_SRC(pvPck, tQueSrc) \
  { \
    ((TLR_PACKET_HEADER_T*)pvPck)->ulSrc=(tQueSrc).ulSrc; \
    ((TLR_PACKET_HEADER_T*)pvPck)->ulSrcId=(tQueSrc).ulSrcId; \
  }

#define TLS_QUE_LINK_SOURCE_SET(tQueSrc,hQueue,_ulSrcId) \
  { \
    (tQueSrc).ulSrc=(TLR_UINT32)(hQueue); \
    (tQueSrc).ulSrcId=(TLR_UINT32)(_ulSrcId); \
  }

INLINE TLR_RESULT TLS_QUE_PACKETDONE(TLR_HANDLE hPool, TLR_HANDLE hQueue, TLR_VOID* pvPck)
{
  if(((TLR_PACKET_HEADER_T*)pvPck)->ulSrc!=(TLR_UINT32)hQueue)
    return TLS_QUE_RETURNPACKET(pvPck);
  else if(!(((TLR_PACKET_HEADER_T*)pvPck)->ulExt & TLR_PACKET_NOT_DELETE))
    return TLR_POOL_PACKET_RELEASE(hPool, pvPck);
  else
    return TLR_S_OK;
}

INLINE TLR_RESULT TLS_QUE_PACKETDONE_TIMEOUT(TLR_HANDLE hPool, TLR_HANDLE hQueue, TLR_VOID* pvPck, TLR_UINT uTimeout)
{
  if(((TLR_PACKET_HEADER_T*)pvPck)->ulSrc!=(TLR_UINT32)hQueue)
    return TLS_QUE_RETURNPACKET_TIMEOUT(pvPck, uTimeout);
  else if(!(((TLR_PACKET_HEADER_T*)pvPck)->ulExt & TLR_PACKET_NOT_DELETE))
    return TLR_POOL_PACKET_RELEASE(hPool, pvPck);
  else
    return TLR_S_OK;
}

#define TLS_QUE_LINK_IS_PACKET_FROM_SOURCE(pvPck, tQueLink) \
    ( ((TLR_PACKET_HEADER_T*)pvPck)->ulSrc==(TLR_UINT32)(tQueLink).hQue && \
      ((TLR_PACKET_HEADER_T*)pvPck)->ulSrcId==(TLR_UINT32)(tQueLink).ulDestId && \
      ((TLR_PACKET_HEADER_T*)pvPck)->ulRout == (tQueLink).ulDest \
    )

/* this one requires that ulRout is set to zero on packet creation */
#define TLS_QUE_LINK_IS_SAME(tQueLink1, tQueLink2) \
  ((tQueLink1).hQue==(tQueLink2).hQue && \
   (tQueLink1).ulDest==(tQueLink2).ulDest && \
   (tQueLink1).ulDestId==(tQueLink2).ulDestId)

#define TLS_QUE_LINK_SET_NEW_DESTID(tQueLink, _ulDestId) \
  ((tQueLink).ulDestId = (_ulDestId))

/************************ prepared indication packet functions ***************************/

#define TLS_QUE_IND_PACKET_SET_DEST(pvPck, tQueLink) \
  { \
    ((TLR_PACKET_HEADER_T*)pvPck)->ulDest=(TLR_UINT32)(tQueLink).ulDest; \
    ((TLR_PACKET_HEADER_T*)pvPck)->ulDestId=(TLR_UINT32)(tQueLink).ulDestId; \
    ((TLR_PACKET_HEADER_T*)pvPck)->ulRout=(TLR_UINT32)(tQueLink).hQue; \
  }

#define TLS_QUE_IND_SENDPACKET_FIFO(pvPck, uTim) \
  TLR_QUE_SENDPACKET_FIFO_INTERN((TLR_HANDLE)((TLR_PACKET_HEADER_T*)pvPck)->ulRout, pvPck, uTim)

#define TLS_QUE_IND_SENDPACKET_LIFO(pvPck, uTim) \
  TLR_QUE_SENDPACKET_LIFO_INTERN((TLR_HANDLE)((TLR_PACKET_HEADER_T*)pvPck)->ulRout, pvPck, uTim)

/************************ Further functions ***************************/

#define TLS_TSK_CREATE_INFO_FIELD(ptTskNfo, uLen, pvStr)  \
  TLR_TSK_CREATE_INFO_FIELD_STRUCTURED(ptTskNfo, uLen, pvStr, 0, 0)   /* TLS_!!!!!!!ToDo!!!!!!?? */



#ifdef __cplusplus
}
#endif  /* __cplusplus */

#endif  /* __TLS_WRAPPER_H */
