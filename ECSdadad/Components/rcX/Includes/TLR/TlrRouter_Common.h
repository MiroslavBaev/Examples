/******************************************************************************

  Copyright (C) 2010 Hilscher Gesellschaft für Systemautomation mbH.

  This program can be used by everyone according the "industrialNETworX Public License INPL".

  The license can be downloaded under <http://www.industrialNETworX.com>.

*******************************************************************************

  Last Modification:
    @version $Id: TlrRouter_Common.h 569 2010-11-19 08:47:54Z MichaelT $

  Description:
    TLR router commons

  Changes:
    Date        Author        Description
  ---------------------------------------------------------------------------
    2010-03-23  NC            File created.

******************************************************************************/


#ifndef __TLRROUTER_COMMON_H
#define __TLRROUTER_COMMON_H

#ifdef __cplusplus
  extern "C" {
#endif  /* __cplusplus */



#include "TLR_Types.h"
#include "TLR_Commands.h"

/****************************************************************************************
 function:    TlrRouter_PacketReceived
 description: handles the incoming packets i.e. packets that come into the system from outside
              will come back directly if the queue is full

 global:      none
 input:       TLR_PACKET_HEADER_T FAR*  ptPck   - packet
                TLR_HANDLE hQue                 - queue of the router itself
                TLR_UINT uChannelId             - channel id of the router that handles the link
 output:      none
 return:      TLR_RESULT (TLR_S_OK == succeeded)
****************************************************************************************/
TLR_RESULT TlrRouter_PacketReceived(TLR_PACKET_HEADER_T FAR* ptPck, TLR_HANDLE hSrcQue, TLR_UINT uChannelId, TLR_HANDLE FAR* phQue);

/****************************************************************************************
 function:    TlrRouter_PacketReceivedPost
 description: handles the incoming packets i.e. packets that come into the system from outside
              will come back immediately

 global:      none
 input:       TLR_PACKET_HEADER_T FAR*  ptPck   - packet
                TLR_HANDLE hQue                 - queue of the router itself
                TLR_UINT uChannelId             - channel id that handles the link
 output:      none
 return:      TLR_RESULT (TLR_S_OK == succeeded)
****************************************************************************************/
TLR_RESULT TlrRouter_PacketReceivedPost(TLR_PACKET_HEADER_T FAR* ptPck, TLR_HANDLE hSrcQue, TLR_UINT uChannelId, TLR_HANDLE FAR* phQue);

/****************************************************************************************
 function:    TlrRouter_PacketReceivedTooLong
 description: handles the incoming packets i.e. packets that come into the system from outside
              will come back directly if the queue is full

 global:      none
 input:       TLR_PACKET_HEADER_T FAR*  ptPck   - packet
                TLR_HANDLE hQue                 - queue of the router itself
                TLR_UINT uChannelId             - channel id of the router that handles the link
 output:      none
 return:      TLR_RESULT (TLR_S_OK == succeeded)
****************************************************************************************/
TLR_RESULT TlrRouter_PacketReceivedTooLong(TLR_PACKET_HEADER_T FAR* ptPck, TLR_HANDLE hSrcQue, TLR_UINT uChannelId);

/****************************************************************************************
 function:    TlrRouter_PacketReceivedPostTooLong
 description: handles the incoming packets i.e. packets that come into the system from outside
              will come back immediately

 global:      none
 input:       TLR_PACKET_HEADER_T FAR*  ptPck   - packet
                TLR_HANDLE hQue                 - queue of the router itself
                TLR_UINT uChannelId             - channel id that handles the link
 output:      none
 return:      TLR_RESULT (TLR_S_OK == succeeded)
****************************************************************************************/
TLR_RESULT TlrRouter_PacketReceivedPostTooLong(TLR_PACKET_HEADER_T FAR* ptPck, TLR_HANDLE hSrcQue, TLR_UINT uChannelId);

/****************************************************************************************
 function:    TlrRouter_PacketReceivedWithError
 description: handles the incoming packets i.e. packets that come into the system from outside
              will come back directly if the queue is full

 global:      none
 input:       TLR_PACKET_HEADER_T FAR*  ptPck   - packet
                TLR_HANDLE hQue                 - queue of the router itself
                TLR_UINT uChannelId             - channel id of the router that handles the link
 output:      none
 return:      TLR_RESULT (TLR_S_OK == succeeded)
****************************************************************************************/
TLR_RESULT TlrRouter_PacketReceivedWithError(TLR_PACKET_HEADER_T FAR* ptPck, TLR_HANDLE hSrcQue, TLR_UINT uChannelId);

/****************************************************************************************
 function:    TlrRouter_PacketReceivedPostWithError
 description: handles the incoming packets i.e. packets that come into the system from outside
              will come back immediately

 global:      none
 input:       TLR_PACKET_HEADER_T FAR*  ptPck   - packet
                TLR_HANDLE hQue                 - queue of the router itself
                TLR_UINT uChannelId             - channel id that handles the link
 output:      none
 return:      TLR_RESULT (TLR_S_OK == succeeded)
****************************************************************************************/
TLR_RESULT TlrRouter_PacketReceivedPostWithError(TLR_PACKET_HEADER_T FAR* ptPck, TLR_HANDLE hSrcQue, TLR_UINT uChannelId);

/****************************************************************************************
 function:    TlrRouter_PacketReceived
 description: handles the out-going router flow i.e. packets that will leave the system
              CAUTION! only to be called on packets marked with ulSrc = router queue

 global:      none
 input:       TLR_PACKET_HEADER_T FAR*  ptPck   - packet
 output:      none
 return:      TLR_BOOLEAN (TLR_TRUE if the packet can be send through the link)
****************************************************************************************/
TLR_BOOLEAN TlrRouter_PacketSendable(TLR_PACKET_HEADER_T FAR* ptPck);



#ifdef __cplusplus
}
#endif  /* __cplusplus */

#endif  /* __TLRROUTER_COMMON_H */
