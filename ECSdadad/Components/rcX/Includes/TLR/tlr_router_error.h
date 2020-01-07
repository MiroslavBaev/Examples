/******************************************************************************

  Copyright (C) 2010-2011 Hilscher Gesellschaft für Systemautomation mbH.

  This program can be used by everyone according the "industrialNETworX Public License INPL".

  The license can be downloaded under <http://www.industrialNETworX.com>.

*******************************************************************************

  Last Modification:
    @version $Id: tlr_router_error.h 715 2011-08-18 08:37:49Z michaelst $

  Description:
    TLR router error definitions

  Changes:
    Date        Author        Description
  ---------------------------------------------------------------------------
    2011-08-18  NC            File updated after rebuild from latest MC files.
    2010-04-27  NC            File created.

******************************************************************************/


#ifndef __TLR_ROUTER_ERROR_H
#define __TLR_ROUTER_ERROR_H



/*****************************************************************************/
/*  TLR router error/status codes */
/*****************************************************************************/
/*  */
/*  MessageId: TLR_E_ROUTER_PACKET_TOO_BIG */
/*  */
/*  MessageText: */
/*  */
/*   Router: Packet is too big (maximum overall size is 2048 Bytes). */
/*  */
#define TLR_E_ROUTER_PACKET_TOO_BIG      ((TLR_RESULT)0xC02F0001L)

/*  */
/*  MessageId: TLR_E_ROUTER_LINK_INACTIVE */
/*  */
/*  MessageText: */
/*  */
/*   Router: Link inactive. */
/*  */
#define TLR_E_ROUTER_LINK_INACTIVE       ((TLR_RESULT)0xC02F0002L)

/*  */
/*  MessageId: TLR_E_ROUTER_FRAGMENT_MISSING */
/*  */
/*  MessageText: */
/*  */
/*   Router: Fragment Missing. */
/*  */
#define TLR_E_ROUTER_FRAGMENT_MISSING    ((TLR_RESULT)0xC02F0003L)

/*  */
/*  MessageId: TLR_E_ROUTER_SEND_TIMEOUT */
/*  */
/*  MessageText: */
/*  */
/*   Router: Packet Send Timeout reached. */
/*  */
#define TLR_E_ROUTER_SEND_TIMEOUT        ((TLR_RESULT)0xC02F0004L)

/*  */
/*  MessageId: TLR_E_ROUTER_LOGICAL_QUEUE_UNDEFINED */
/*  */
/*  MessageText: */
/*  */
/*   Router: Logical queue handle is undefined. */
/*  */
#define TLR_E_ROUTER_LOGICAL_QUEUE_UNDEFINED ((TLR_RESULT)0xC02F0005L)



#endif  /* __TLR_ROUTER_ERROR_H */

