/******************************************************************************

  Copyright (C) 2011, Hilscher Gesellschaft für Systemautomation mbH.

 *******************************************************************************

  Filename:
    $Workfile: Hal_I2c.h $

  Last Modification:
    $Author: MichaelT $
    $Modtime: 16.12.2011 17:47 $
    $Revision: 903 $

  Targets:
    rcX : yes

  Description:
    Interface of the I2C HAL for netX 100 / 500

  Changes:
    Date        Author        Description
  ---------------------------------------------------------------------------
    2011-12-16  MS            File created.

*******************************************************************************/


#ifndef __AP_I2C_H
#define __AP_I2C_H



/*****************************************************************************/
/* Symbol Definitions                                                        */
/*****************************************************************************/


/* flag definitions (used with the flags parameter of HalI2cSend / HalI2cReceive) */
#define RX_I2C_FLAG_START_COND      0x00000001  /* send a start condition together with the command */
#define RX_I2C_FLAG_STOP_COND       0x00000002  /* send a stop condition together with the command */


/*****************************************************************************/
/*!  Administrator Structure for a I2c device                                */
/*****************************************************************************/
typedef struct
{
  RX_HANDLE hI2cBus;          /*!< I2c bus handle */
  UINT16    usDeviceID;       /*!< I2c device ID as given in the device manual */
  UINT16    usAckPoll;        /*!< max. number of ACK poll cycles to perform in a regular transfer before reporting a timeout */
  BOOL      fStandardMode;    /*!< Enable standard I2C mode */
  
} RX_I2C_DEVICE_T;

/*****************************************************************************/
/* Functions                                                                 */
/*****************************************************************************/

RX_FATAL  DrvI2cInit         (const void*      pvCfg,
                              UINT             uNum);

RX_RESULT Drv_I2cIdentifyBus (const STRING*    pszIdn,
                              UINT             uInst, 
                              RX_HANDLE*       phI2cBus);
                              
RX_RESULT Drv_I2cLockBus     (RX_HANDLE        hI2cBus);

RX_RESULT Drv_I2cUnlockBus   (RX_HANDLE        hI2cBus);

RX_RESULT Drv_I2cSend        (RX_I2C_DEVICE_T* ptDevice, 
                              UINT             uiDataLength, 
                              const UINT8*     pucData, 
                              INT              iCond);

RX_RESULT Drv_I2cReceive     (RX_I2C_DEVICE_T* ptDevice, 
                              UINT             uiDataLength, 
                              UINT8*           pucData, 
                              INT              iCond);

#endif /* __AP_I2C_H */
