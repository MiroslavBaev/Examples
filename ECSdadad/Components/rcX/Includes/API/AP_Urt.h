/******************************************************************************

  Copyright (C) 2010 [Hilscher Gesellschaft für Systemautomation mbH]

  This program can be used by everyone according to the netX Open Source
  Software license. The license agreement can be downloaded from
  http://www.industrialNETworX.com

*******************************************************************************

  Last Modification:
    @version $Id: AP_Urt.h 903 2012-05-02 12:09:19Z MichaelT $

  Description:
    USER - Headerfile of UART Driver Module

  Changes:
    Date        Author        Description
  ---------------------------------------------------------------------------
    2010-03-23  NC            File created.

******************************************************************************/


#ifdef __cplusplus
extern "C" {
#endif


#ifndef __AP_URT_H
  #define __AP_URT_H
  
  /*
  **************************************************************************
  *   Size of one UART Control Block a Task has to allocate memory for
  **************************************************************************
  */ 
  #define DRV_UART_SIZE (108)
  /*
  **************************************************************************
  *   Definitions 
  **************************************************************************
  */ 
  typedef union RX_URT_HANDLER_UNtag {
     void FAR (CALLBACK FAR* fnIrq)(RX_HANDLE hInt, void FAR* pvPrm); /* Hardware Interrupt Service Routine */
     void FAR (CALLBACK FAR* fnPoll)(void FAR* pvInp); /* Software Timer Routine for polling mode */
  } RX_URT_HANDLER_UN;
 
  typedef void (CALLBACK FAR* APP_URT_RXRDY) (RX_HANDLE hUrt, void FAR* pvPrm, UINT uRxChar); 
  typedef void (CALLBACK FAR* APP_URT_TXEPTY)(RX_HANDLE hUrt, void FAR* pvPrm); 
  typedef void (CALLBACK FAR* APP_URT_ERR)   (RX_HANDLE hUrt, void FAR* pvPrm); 

  /*
  ************************************************************
  *   Function Prototypes
  ************************************************************
  */
  RX_FATAL FAR    DrvUrtInit              (const FAR void FAR*          pvCfg,
                                           UINT                         uNum); 

  RX_RESULT FAR   Drv_UrtCreateUart       (RX_HANDLE                    hUrt,
                                           const RX_UART_SET_T FAR*     ptCfg); 

  RX_RESULT FAR   Drv_UrtInitializeUart   (RX_HANDLE                    hUart,
                                           APP_URT_RXRDY                fnRxRdy,
                                           APP_URT_TXEPTY               fnTxEpty,
                                           APP_URT_ERR                  fnErr,
                                           void FAR*                    pvPrm,
                                           BOOLEAN                      fMod,
                                           RX_URT_HANDLER_UN FAR*       punUartHdl); 

  RX_RESULT FAR   Drv_UrtIdentifyUart     (const STRING FAR*            pszIdn,
                                           UINT                         uInst,
                                           RX_HANDLE FAR*               phUart); 

  RX_RESULT FAR   Drv_UrtEnableUart       (RX_HANDLE                    hUart); 

  RX_RESULT FAR   Drv_UrtDisableUart      (RX_HANDLE                    hUart); 
  
  RX_RESULT FAR   Drv_UrtEnableReceiver   (RX_HANDLE                    hUart,
                                           BOOLEAN                      fEnable);
  
  RX_RESULT FAR   Drv_UrtSetReceiveMode   (RX_HANDLE                    hUart);
  
  RX_RESULT FAR   Drv_UrtSendCharacter    (RX_HANDLE                    hUart,
                                           UINT8                        bChar); 
                                           
  RX_RESULT FAR   Drv_UrtSend             (RX_HANDLE                    hUart,
                                           const UINT8 FAR*             pabChars,
                                           UINT FAR*                    puLength);

  RX_RESULT FAR   Drv_UrtGetCharacter     (RX_HANDLE                    hUart,
                                           UINT8 FAR*                   pbChar);
                                           
  RX_RESULT FAR   Drv_UrtRecv             (RX_HANDLE                    hUart,
                                           UINT8 FAR*                   pabChars,
                                           UINT FAR*                    puLength);

  RX_RESULT FAR   Drv_UrtGetStatus        (RX_HANDLE    hUrt,
                                           BOOLEAN FAR* pfCts,
                                           BOOLEAN FAR* pfDsr,
                                           BOOLEAN FAR* pfDcd);

  RX_RESULT FAR   Drv_UrtReset            (RX_HANDLE                    hUart);

  RX_RESULT FAR   Drv_UrtEnableTransmitter(RX_HANDLE                    hUart,
                                           BOOLEAN                      fEnable); 
  
  RX_RESULT FAR   Drv_UrtSetTransmitMode  (RX_HANDLE                    hUart); 
  
  RX_RESULT FAR   Drv_UrtDeleteUart       (RX_HANDLE                    hUart);
  
  RX_RESULT FAR   Drv_UrtChangeRts        (RX_HANDLE                    hUart,
                                           BOOLEAN                      fRts); 

  RX_RESULT FAR   Drv_UrtGetCts           (RX_HANDLE                    hUart,
                                           BOOLEAN FAR*                 pfCts); 


  #define UART_ERROR_FRAMING_MSK  0x00000001
  #define UART_ERROR_PARITY_MSK   0x00000002
  #define UART_ERROR_BREAK_MSK    0x00000004
  #define UART_ERROR_OVERRUN_MSK  0x00000008

  RX_RESULT FAR   Drv_UrtGetLastError     (RX_HANDLE                    hUart,
                                           UINT8 FAR*                   pbChar,
                                           UINT  FAR*                   puiErrorFlags);


#endif  

#ifdef __cplusplus
}
#endif
