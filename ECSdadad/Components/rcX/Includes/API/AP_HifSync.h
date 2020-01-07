/******************************************************************************

  Copyright (C) 2010 [Hilscher Gesellschaft für Systemautomation mbH]

  This program can be used by everyone according to the netX Open Source
  Software license. The license agreement can be downloaded from
  http://www.industrialNETworX.com

*******************************************************************************

  Last Modification:
    @version $Id: AP_HifSync.h 497 2011-08-16 07:44:44Z sspies $

  Description:
    Standardized definitions of RX HIFSync

  Changes:
    Date        Author        Description
  ---------------------------------------------------------------------------
    2010-03-23  NC            File created.

******************************************************************************/


#ifndef _AP_HIFSYNC_H
#define _AP_HIFSYNC_H

#ifdef __cplusplus
extern "C" {
#endif

typedef enum DRV_HIF_SYNC_TYPE_Etag
{
  DRV_HIF_SYNC_TYPE_IRQ,
  DRV_HIF_SYNC_TYPE_FIQ       /* FIQ mode enables to call DrvHifSync_ToggleSyncHandshake from FIQ */
} DRV_HIF_SYNC_TYPE_E;

typedef enum DRV_HIF_SYNC_MODE_Etag
{
  DRV_HIF_SYNC_MODE_HOST_CONTROLLED,
  DRV_HIF_SYNC_MODE_DEVICE_CONTROLLED
} DRV_HIF_SYNC_MODE_E;

typedef struct DRV_HIF_SYNC_SET_Ttag
{
  DRV_HIF_SYNC_TYPE_E   eHifSyncMode;
  STRING*               pszHifIrqName;    /* Drv_Hif Irq instance */
  UINT                  uiHifIrqInstance;
  STRING*               pszHifName;       /* Drv_Hif instance */
  UINT                  uiHifInstance;
} DRV_HIF_SYNC_SET_T;

typedef void (*HIF_SYNC_CALLBACK_FN)(UINT uiSyncIdx, void* pvUserData);

/* initialize HifSync driver */
RX_FATAL DrvHifSyncInit(const void* pvParams, UINT uiNumParams);

/* Configure Sync handshake */
RX_RESULT Drv_HifSyncConfigureSyncHandshake(UINT uiSyncIdx, DRV_HIF_SYNC_MODE_E eSyncMode);

/* Enable Sync interrupt */
RX_RESULT Drv_HifSyncEnableSyncInterrupt(UINT uiSyncIdx, HIF_SYNC_CALLBACK_FN pfnFunc, void* pvUserData);

/* Disable Sync interrupt */
RX_RESULT Drv_HifSyncDisableSyncInterrupt(UINT uiSyncIdx);

/* Toggle Sync handshake, TRUE if successful */
BOOLEAN Drv_HifSyncToggleSyncHandshake(UINT uiSyncIdx);

#ifdef __cplusplus
}
#endif

#endif
