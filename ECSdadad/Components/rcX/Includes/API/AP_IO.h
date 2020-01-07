/******************************************************************************

  Copyright (C) 2010 [Hilscher Gesellschaft für Systemautomation mbH]

  This program can be used by everyone according to the netX Open Source
  Software license. The license agreement can be downloaded from
  http://www.industrialNETworX.com

*******************************************************************************

  Last Modification:
    @version $Id: AP_IO.h 1338 2013-03-08 11:21:59Z stephans $

  Description:
    Standardized definitions of RX IOs 

  Changes:
    Date        Author        Description
  ---------------------------------------------------------------------------
    2010-03-23  NC            File created.

******************************************************************************/


#ifdef __cplusplus
extern "C" {
#endif


#ifndef __AP_IO_H
  #define __AP_IO_H
  
  /*****************************************************************************/
  /*!  Type defintions                                                         */
  /*****************************************************************************/

  typedef enum RX_IO_DIRECTION_T
  {
    RX_IO_INPUT = 0,
    RX_IO_OUTPUT
  } RX_IO_DIRECTION;

  typedef enum RX_IO_LEVEL_T
  {
    RX_IO_LOW = 0,
    RX_IO_HIGH
  } RX_IO_LEVEL;

  typedef struct RX_IO_INFO_Ttag 
  {
    UINT uInstances; /*!< Number of pin instances handled by the IO Layer */
    UINT uBanks;     /*!< Number of banks. Banks are groups of i/o pins which
                          can be addressed simultaneously */
  
  } RX_IO_INFO_T;

  typedef struct RX_IO_LAYER_Ttag 
  {
    UINT uInstances; /*!< Number of pin instances handled by the IO Layer */
    UINT uBanks;     /*!< Number of banks. Banks are groups of i/o pins which
                          can be addressed simultaneously */

    /* Low level access functions of the IO layer */
    RX_RESULT   (*fnSetDirection) (UINT uInstance, RX_IO_DIRECTION  eDirection);
    RX_RESULT   (*fnGetDirection) (UINT uInstance, RX_IO_DIRECTION* peDirection);
    RX_RESULT   (*fnSetLevel)     (UINT uInstance, RX_IO_LEVEL  eLevel);
    RX_RESULT   (*fnGetLevel)     (UINT uInstance, RX_IO_LEVEL* peLevel);
    RX_RESULT   (*fnSetBank)      (UINT uBank, UINT32 ulValue, UINT32 ulMask);
    RX_RESULT   (*fnGetBank)      (UINT uBank, UINT32* pulValue);
    RX_RESULT   (*fnIOCtrl)       (UINT8 uCmd, UINT8* pbIn, UINT8* pbOut);
  
  } RX_IO_LAYER_T;

  typedef RX_RESULT (* PFN_IOLAYER_INIT)(RX_HANDLE hIOLayer);
  
  /*****************************************************************************/
  /*!  IO Controls                                                             */
  /*****************************************************************************/
  #define RX_IO_IOCTRL_BANKINFO           0
  #define RX_IO_IOCTRL_MODE_IO            1
  #define RX_IO_IOCTRL_MODE_PWM           2
  #define RX_IO_IOCTRL_MODE_CAPTURE_LEVEL 3
  #define RX_IO_IOCTRL_MODE_CAPTURE_EDGE  4
  #define RX_IO_IOCTRL_INVERT             5
  #define RX_IO_IOCTRL_IRQ                6
  #define RX_IO_IOCTRL_IRQ_CONFIRM        7
  
  /* IO Control input structure for RX_IO_IOCTRL_BANKINFO */
  typedef struct RX_IO_BANKINFO_IN_Ttag 
  {
    UINT uBank;      /*!< Number of bank to get information about */
  
  } RX_IO_BANKINFO_IN_T;
  
  /* IO Control output structure for RX_IO_IOCTRL_BANKINFO */
  typedef struct RX_IO_BANKINFO_OUT_Ttag 
  {
    UINT uSize;      /*!< Number of pins covered by the addressed bank */
  
  } RX_IO_BANKINFO_OUT_T;

  /* IO Control input structure for RX_IO_IOCTRL_MODE_PWM */
  typedef struct RX_IO_PWM_IN_Ttag 
  {
    UINT            uInstance;      /*!< IO instance */
    RX_GPIO_COUNTER eCntRef;        /*!< Reference counter to use for the PWM */
    UINT32          ulActiveTime;   /*!< Time in 10ns increments that the IO pin spends in active state */
    UINT32          ulInactiveTime; /*!< Time in 10ns increments that the IO pin spends in inactive state */
  
  } RX_IO_PWM_IN_T;

  /* IO Control input structure for: RX_IO_IOCTRL_MODE_IO */
  typedef struct RX_IO_DEFAULT_IN_Ttag 
  {
    UINT  uInstance;  /*!< IO instance    */
  
  } RX_IO_DEFAULT_IN_T;
  
  /* IO Control input structure for: 
       RX_IO_IOCTRL_MODE_CAPTURE_LEVEL, 
       RX_IO_IOCTRL_MODE_CAPTURE_EDGE   */
  typedef struct RX_IO_CAPTURE_IN_Ttag 
  {
    UINT  uInstance;  /*!< IO instance    */
  
  } RX_IO_CAPTURE_IN_T;
  
  /* IO Control input structure for:
     RX_IO_IOCTRL_IRQ,
     RX_IO_IOCTRL_IRQ_CONFIRM */
  typedef struct RX_IO_IRQ_IN_Ttag 
  {
    UINT  uInstance;  /*!< IO instance              */
    UINT8 fEnable;    /*!< Enable/disable interrupt */
  
  } RX_IO_IRQ_IN_T;

  /* IO Control input structure for: RX_IO_IOCTRL_INVERTED */
  typedef struct RX_IO_INVERT_IN_Ttag 
  {
    UINT  uInstance;  /*!< IO instance                  */
    UINT8 fEnable;    /*!< Enable/disable pin inversion */
  
  } RX_IO_INVERT_IN_T;
  
  /*****************************************************************************/
  /*!  Size of one IO Control Block a Task has to allocate memory for          */
  /*****************************************************************************/  
  #define DRV_IO_SIZE (84)

  /*****************************************************************************/
  /*!  Function Prototypes                                                     */
  /*****************************************************************************/  
  RX_FATAL FAR    DrvIOInit               (const FAR void FAR*      pvCfg,
                                           UINT                     uNum); 

  RX_RESULT FAR   Drv_IOCreate            (RX_HANDLE                hClass,
                                           const RX_IO_SET_T FAR*   ptCfg); 

  RX_RESULT FAR   Drv_IOIdentify          (const STRING FAR*        pszIdn,
                                           RX_HANDLE FAR*           phClass);
  
  RX_RESULT FAR   Drv_IOSetDirection      (RX_HANDLE                hClass,
                                           UINT                     uInstance, 
                                           RX_IO_DIRECTION          eDirection);
  
  RX_RESULT FAR   Drv_IOGetDirection      (RX_HANDLE                hClass,
                                           UINT                     uInstance, 
                                           RX_IO_DIRECTION*         peDirection);
  
  RX_RESULT FAR   Drv_IOSetLevel          (RX_HANDLE                hClass, 
                                           UINT                     uInstance, 
                                           RX_IO_LEVEL              eLevel);
  
  RX_RESULT FAR   Drv_IOGetLevel          (RX_HANDLE                hClass,
                                           UINT                     uInstance, 
                                           RX_IO_LEVEL*             peLevel);                                                              
  
  RX_RESULT FAR   Drv_IOSetBank           (RX_HANDLE                hClass,
                                           UINT                     ulBank, 
                                           UINT32                   ulValue, 
                                           UINT32                   ulMask); 

  RX_RESULT FAR   Drv_IOGetBank           (RX_HANDLE                hClass,
                                           UINT                     ulBank, 
                                           UINT32*                  pulValue); 

  RX_RESULT FAR   Drv_IOGetInfo           (RX_HANDLE                hClass,
                                           RX_IO_INFO_T*            ptInfo);

  RX_RESULT FAR   Drv_IOCtrl              (RX_HANDLE                hClass,
                                           UINT8                    bCmd, 
                                           UINT8*                   pbIn, 
                                           UINT8*                   pbOut);

  /*****************************************************************************/
  /* IO Module initialization routines                                         */
  /*****************************************************************************/
  RX_RESULT GpioInit                      (RX_HANDLE                hIOLayer);
  RX_RESULT HifPioInit                    (RX_HANDLE                hIOLayer);

#if !defined(__NETX10)
  RX_RESULT PioInit                       (RX_HANDLE                hIOLayer);
#endif

#if defined(__NETX10) || defined(__NETX51)
  RX_RESULT MMIOPioInit                   (RX_HANDLE                hIOLayer);
#endif 

#endif

#ifdef __cplusplus
}
#endif
