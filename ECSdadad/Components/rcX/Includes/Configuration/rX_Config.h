/*******************************************************************************

   Copyright (c) Hilscher GmbH. All Rights Reserved.

 *******************************************************************************

   Filename:
    $Id: rX_Config.h 1698 2014-02-11 12:04:35Z MichaelT $
   Last Modification:
    $Author: MichaelT $
    $Date: 2014-02-11 13:04:35 +0100 (Tue, 11 Feb 2014) $
    $Revision: 1698 $

   Targets:
     rcX      : yes

   Description:
      rcX Kernel / Driver configuration Headerfile

  Functions:

   Changes:

     Version   Date        Author   Description
     ---------------------------------------------------------------------------
      3       06.05.2013   MT       Remove XC Code definitions for CAN, PROFIBUS which are to be supplied 
                                    by fieldbus libraries
      2       10.10.2012   MT       ptScheduler in RX_ENTERKERNEL_PARAM_T discards const qualifier
                                    when passing a scheduler, which is always declared const
      1       20.05.2011   MT       ported from rcX V2

*******************************************************************************/


#ifndef __RX_CONFIG_H
#define __RX_CONFIG_H

#if defined(__cplusplus)
  extern "C" {
#endif

#if !defined(RX_COMPILE_CPU_INDEPENDENT)
  #include "rX_Cpu.h"
#endif

  /*
  ***********************************************************
  *  Definitions
  ***********************************************************
  */

  /* maximum lengths of the USB identification strings */
  #define RX_UART_USB_VENDOR_NAME_LEN    20          /* vendor name string length including NUL-termination */
  #define RX_UART_USB_PRODUCT_NAME_LEN   20          /* product name string length including NUL-termination */
  #define RX_UART_USB_SERIAL_NUMBER_LEN  10          /* serial number string length including NUL-termination */

  /* UART HAL / USB HAL behavior control flags */
  #define RX_UART_FLAG_TX_EMPTY_ONCE     0x00000001  /* prevent re-triggering of Tx empty events if the Tx FIFO is still empty after the event */
  #define RX_UART_FLAG_RX_READY_ONCE     0x00000002  /* prevent re-triggering of Rx ready events if the Rx FIFO is not empty after the event */
  #define RX_UART_FLAG_TX_EMPTY_CTRL     0x00000004  /* reserved */
  #define RX_UART_FLAG_RX_READY_CTRL     0x00000008  /* simplifies use of Drv_UrtRecv(): do not remove the character passed to the "rx ready" callback from the FIFO */
  #define RX_UART_FLAG_NO_SERIAL_NUM     0x00000010  /* disable propagation of the device's serial number on USB */


  /*
  ***********************************************************
  *  Structure of a static Task-Entry in the Tasklist
  ***********************************************************
  */
  typedef struct RX_STATIC_TASK_Ttag {
    STRING            szTskNam[16]; /* Task Name as 15+1 Byte character string */
    UINT32            ulPrio;       /* Task Priority at startup */
    UINT32            ulTok;        /* Task Token to Identify Task */
    UINT32            ulInst;       /* Instance of Task */
    void FAR*         pvStck;       /* Pointer to the starting address of Task Stack Pool Memory */
    UINT32            ulStckSiz;    /* Size of Stack of Task */
    UINT32            ulThrhld;     /* Task preemption threshold */
    UINT32            ulSrtMod;     /* Start mode for task at creation time */
    PFN_RX_TASK_ENTER fnTask;       /* Task Entry for task execution */
    PFN_RX_TASK_LEAVE fnTskLve;     /* Function called when Task is deleted */
    UINT32    ulInp;                /* 32bit value, its Address-Pointer passed to Task when started */
    UINT32    aulRes[8];            /* reserved area */
  } RX_STATIC_TASK_T;


  /*
  ************************************************************************
  * Hardware related Configuration types configured due to Config.c file
  ************************************************************************
  */
  enum RX_PERIPHERAL_TYPEtag {
    RX_PERIPHERAL_TYPE_TIMER,
    RX_PERIPHERAL_TYPE_INTERRUPT,
    RX_PERIPHERAL_TYPE_UART,
    RX_PERIPHERAL_TYPE_WATCHDOG,
    RX_PERIPHERAL_TYPE_LED,
    RX_PERIPHERAL_TYPE_HOST,
    RX_PERIPHERAL_TYPE_XC,
    RX_PERIPHERAL_TYPE_PARFLASH,
    RX_PERIPHERAL_TYPE_PHY,
    RX_PERIPHERAL_TYPE_MEMORY,
    RX_PERIPHERAL_TYPE_FIFOCHANNEL,
    RX_PERIPHERAL_TYPE_MMU,
    RX_PERIPHERAL_TYPE_TRACE,
    RX_PERIPHERAL_TYPE_TCM,
    RX_PERIPHERAL_TYPE_CACHE,
    RX_PERIPHERAL_TYPE_MAILBOX,
    RX_PERIPHERAL_TYPE_VOLUME,
    RX_PERIPHERAL_TYPE_RAMDISK,
    RX_PERIPHERAL_TYPE_EDD,
    RX_PERIPHERAL_TYPE_ICM,
    RX_PERIPHERAL_TYPE_MPU,
    RX_PERIPHERAL_TYPE_USB,
    RX_PERIPHERAL_TYPE_RSRVD1,
    RX_PERIPHERAL_TYPE_RSRVD2,
    RX_PERIPHERAL_TYPE_RSRVD3,
    RX_PERIPHERAL_TYPE_PIO,
    RX_PERIPHERAL_TYPE_GPIO,
    RX_PERIPHERAL_TYPE_EBUS,
    RX_PERIPHERAL_TYPE_SPI,
    RX_PERIPHERAL_TYPE_IIC,
    RX_PERIPHERAL_TYPE_SERFLASH,
    RX_PERIPHERAL_TYPE_FIQ,
    RX_PERIPHERAL_TYPE_HIFPIO,
    RX_PERIPHERAL_TYPE_HIFCHANNEL,
    RX_PERIPHERAL_TYPE_MMC,
    RX_PERIPHERAL_TYPE_SQIROM,
    RX_PERIPHERAL_TYPE_RESIDENTRAMDISK,
    RX_PERIPHERAL_TYPE_I2C,
    RX_PERIPHERAL_TYPE_IO,
    
    RX_PERIPHERAL_TYPE_UNUSED,

    RX_PERIPHERAL_COUNT_TYPES
  };
  typedef UINT8 RX_PERIPHERAL_TYPE;

  /*
  ***********************************************************
  *   Peripheral Configuration Header
  ***********************************************************
  */
  typedef struct RX_PERIPHERAL_HEADER_Ttag {
    STRING szIdn[16]; /* Name of the Peripheral */
    RX_PERIPHERAL_TYPE eTyp; /* Type of Peripheral */
    UINT uInst; /* Instance of the Peripheral */
  } RX_PERIPHERAL_HEADER_T;

  /*
  ***********************************************************
  *   Mailbox Memory table entry
  ***********************************************************
  */
  typedef struct RX_MBXBUFFER_SET_Ttag {
    RX_PERIPHERAL_HEADER_T tCfgHd; /* Peripheral Header */

    UINT8 FAR* pbSrt; /* Pointer to startaddress of Mailbox memory block */
    UINT32 ulSiz; /* Size of the Memory block */
  } RX_MBXBUFFER_SET_T;

  /*
  *****************************************************
  *    Definition of one Trace table entry
  *****************************************************
  */
  typedef struct RX_TRACE_SET_Ttag {
    RX_PERIPHERAL_HEADER_T tCfgHd;

    UINT8 FAR* pbSrt; /* Pointer to startaddress of trace memory block */
    UINT32 ulSiz; /* Size of this trace Block */
    UINT32 ulLmt; /* Limit of remaining system memory when logg data also contains data */
  } RX_TRACE_SET_T;


  /*
  *****************************************************
  *    Definition of a Mass Storage Device
  *****************************************************
  */

  typedef struct RX_PHYSICALDRIVE_HEADER_Ttag {
    STRING                szIdn[16];      /* Name of the Drive to use as media */
    RX_PERIPHERAL_TYPE    eTyp;           /* Type of Drive */
    UINT                  uInst;          /* Instance of the DrivePeripheral */
    BOOLEAN               fPrtn;          /* Drive is MS-DOS partioned or not */
  } RX_PHYSICALDRIVE_HEADER_T;

  typedef struct RX_VOLUME_SET_Ttag {
    RX_PERIPHERAL_HEADER_T      tCfgHd;

    UINT32                      ulCapcty;       /* Total number of bytes physically available in the media */
    UINT32                      ulPrtnAdr;      /* Byte-Startaddress of FAT Partition in Drive */
    UINT32                      ulVolId;        /* Drive Volume serial Number */
    UINT                        uBytPerSec;     /* Bytes per Sector of drive Volume */
    UINT                        uMaxPrc;        /* Maximum number of Tasks allowed to access in parallel */
    RX_RESULT (FAR*             fnMount)(RX_HANDLE hVol); /* Mount function */
    RX_PHYSICALDRIVE_HEADER_T   tPhyDrv;        /* Physical drive to use as media */
  } RX_VOLUME_SET_T;



  /*
  ************************************************************
  *   FLASH translation Layer Configuration
  ************************************************************
  */

  typedef struct RX_TRANSLATIONLAYER_CONFIG_Ttag {
    UINT32 ulSrtOffs;  /* Start-Offset in the physical Media where the FTL Parition begins */
    UINT32 ulSiz;      /* Size of the FTL partition inclusive the Transfer Unit */
    UINT32 ulBlkSiz;   /* Block size of each erase unit */
  } RX_TRANSLATIONLAYER_CONFIG_T;

  /*
  ************************************************************
  *   Parallel FLASH Configuration
  ************************************************************
  */

  #define RX_PARALLELFLASH_MAX_SECTORENTRIES 32 /* Maximum number of FLASH sectors entries */

  enum RX_PARALLELFLASH_WIDTHtag { /* Type of Parallel FLASH */
    RX_PARALLELFLASH_8BIT    = 0,
    RX_PARALLELFLASH_16BIT   = 1,
    RX_PARALLELFLASH_32BIT   = 2,
    RX_PARALLELFLASH_1616BIT = 3
  };
  typedef UINT8 RX_PARALLELFLASH_WIDTH;

  enum RX_PARALLELFLASH_PROTECTtag {
    RX_PARALLELFLASH_NO_PROTECTION   = 0,               /* No protection */
    RX_PARALLELFLASH_WR_PROTECTED    = 1,               /* Write protection */
    RX_PARALLELFLASH_ER_PROTECTED    = 2,               /* Erase protection */
    RX_PARALLELFLASH_WR_ER_PROTECTED = 3                /* Write/Erase protection */
  };
  typedef UINT8 RX_PARALLELFLASH_PROTECT;

  typedef struct RX_PARALLELFLASH_SECTORCONFIG_Ttag {
    UINT32                            ulNumOfSec;       /* Number of Sectors */
    UINT32                            ulSize;           /* # of UINT8s in per sector */
    RX_PARALLELFLASH_PROTECT          eProt;            /* Protection of this sectors */
  } RX_PARALLELFLASH_SECTORCONFIG_T;

  typedef struct RX_PARALLELFLASH_IDENTITY_Ttag {
    UINT32                            ulVendorCode;     /* Vendor specific ID-Code */
    UINT32                            ulDeviceCode;     /* Device specific ID-Code */
  } RX_PARALLELFLASH_IDENTITY_T;

  typedef struct RX_PARALLELFLASH_SET_Ttag {
    RX_PERIPHERAL_HEADER_T          tCfgHd;             /* Peripheral Header */

    RX_PARALLELFLASH_WIDTH          eWidth;             /* Width of the FLASH */
    RX_PARALLELFLASH_IDENTITY_T     tIdentity;          /* FLASH identity */
    RX_TRANSLATIONLAYER_CONFIG_T    tTrnsCfg;           /* Translation configuration */
    UINT32                          ulBaseAddr;         /* Base Address of FLASH as 32Bit absolut linear value */
    RX_RESULT (FAR*                 pfnFlashInitialize)(RX_HANDLE hFls);
    UINT                            uNumSecEnt;         /* Number of FLASH sector configuration entries in the following Table */
    RX_PARALLELFLASH_SECTORCONFIG_T atSecCfgTbl[RX_PARALLELFLASH_MAX_SECTORENTRIES]; /* FLASH Sector Configuration Table */
  } RX_PARALLELFLASH_SET_T;

  RX_RESULT FAR   HalPflsInitialize_INTEL28FXXXJ3(RX_HANDLE hFls);
  RX_RESULT FAR   HalPflsInitialize_AMD29FXXXX(RX_HANDLE hFls);
  RX_RESULT FAR   HalPflsInitialize_CFI(RX_HANDLE hFls);

  /*
  ************************************************************
  *   Serial FLASH Configuration
  ************************************************************
  */
  #define RX_SERIALFLASH_INITSIZE 3
  #define RX_SERIALFLASH_IDSIZE 9

  enum RX_SPI_MODEtag {
    RX_SPI_MODE0 = 0,
    RX_SPI_MODE1 = 1,
    RX_SPI_MODE2 = 2,
    RX_SPI_MODE3 = 3
  };
  typedef UINT8 RX_SPI_MODE;

  enum RX_SPI_CLOCKtag {
    RX_SPI_SPEED_0_05MHz   = 1,
    RX_SPI_SPEED_0_1MHz    = 2,
    RX_SPI_SPEED_0_2MHz    = 3,
    RX_SPI_SPEED_0_5MHz    = 4,
    RX_SPI_SPEED_1_0MHz    = 5,
    RX_SPI_SPEED_1_25MHz   = 6,
    RX_SPI_SPEED_2_0MHz    = 7,
    RX_SPI_SPEED_2_5MHz    = 8,
    RX_SPI_SPEED_3_3MHz    = 9,
    RX_SPI_SPEED_5_0MHz    = 10,
    RX_SPI_SPEED_10_0MHz   = 11,
    RX_SPI_SPEED_12_5MHz   = 12,
    RX_SPI_SPEED_16_6MHz   = 13,
    RX_SPI_SPEED_25_0MHz   = 14,
    RX_SPI_SPEED_50_0MHz   = 15
  };
  typedef UINT8 RX_SPI_CLOCK;

  enum RX_SPI_ADDRESS_MODES {
    RX_SPI_ADDRESS_MODE_DEFAULT    = 0,
    RX_SPI_ADDRESS_MODE_LINEAR     = 1,
    RX_SPI_ADDRESS_MODE_ATMEL_PAGE = 2,
    RX_SPI_ADDRESS_MODE_SECTOR     = 3
  };

  typedef struct RX_SERIALFLASH_ATTRIBUTES_Ttag {
    UINT32 ulSize;                              /* size of the flash memory in bytes */
    RX_SPI_CLOCK  eSpeed;                       /* maximum clock speed */
    UINT uPageSize;                             /* size of one page in bytes */
    UINT uSectorPages;                          /* size of one sector in pages */
    UINT8 bReadOpcode;                            /* opcode for „continuous array read“ command */
    UINT8 bReadOpcodeDCBytes;                     /* don't care bytes after readOpcode and address */
    UINT8 bWriteEnableOpcode;                     /* opcode for „write enable“ command, 0x00 means no write protect mechanism */
    UINT8 bEraseOpcode;                         /* opcode for „erase page“ */
    UINT8 bPageProgOpcode;                      /* opcode for „page program (without buildin erase)“ */
    UINT8 bMemoryPageOpcode;                    /* opcode to transfer the main memory to buffer */
    UINT8 bReadStatusOpcode;                    /* opcode for „read status register“ */
    UINT8 bStatusReadyMask;                     /* the bitmask indicating device busy */
    UINT8 bStatusReadyValue;                    /* eor bitmask for device busy */
    UINT8 bInitCmd0_length;                     /* length of the first init command in bytes */
    UINT8 abInitCmd0[RX_SERIALFLASH_INITSIZE];  /* first command string to init the device */
    UINT8 bInitCmd1_length;                     /* length of the second init command in bytes */
    UINT8 abInitCmd1[RX_SERIALFLASH_INITSIZE];  /* second command string to init the device */
    UINT8 bIdLength;                            /* length in bytes of the id_send, id_mask and id_magic fields */
    UINT8 abIdSend[RX_SERIALFLASH_IDSIZE];      /* command string to request the id */
    UINT8 abIdMask[RX_SERIALFLASH_IDSIZE];      /* mask for the device id. the data received from the id_send command will be anded with this field */
    UINT8 abIdMagic[RX_SERIALFLASH_IDSIZE];     /* magic sequence of this device */
    UINT8 bAddressMode;                         /* addressing mode to identify flash type */
  } RX_SERIALFLASH_ATTRIBUTES_T;


  typedef struct RX_SERIALFLASH_SET_Ttag {
    RX_PERIPHERAL_HEADER_T tCfgHd; /* Peripheral Header */

    RX_PERIPHERAL_HEADER_T tCfgSpi;             /* Destination SPI Bus the device is connected to */
    BOOLEAN fAuto;                              /* detect connected FLASH automatically or not */
    RX_TRANSLATIONLAYER_CONFIG_T tTrnsCfg;      /* Translation configuration */
    RX_SERIALFLASH_ATTRIBUTES_T tFlsAttr;       /* Attributes of the serial FLASH */
  } RX_SERIALFLASH_SET_T;

  /*
  ************************************************************
  *   SPI Configuration
  ************************************************************
  */

  typedef struct RX_SPISLAVE_SET_Ttag {
    RX_PERIPHERAL_HEADER_T tCfgHd;  /* Peripheral Header */

    UINT uPortIdx;       /* index of the slave's spi port */
    UINT uSlaveIdx;      /* index of the slave's chip select */
    RX_SPI_MODE eMode;   /* spi mode for this slave device */
    RX_SPI_CLOCK eSpeed; /* clock speed for this slave */
    UINT uBurstBlk;      /* size of a burst block */
    UINT uBurstDly;      /* delay between 2 burst blocks */
  } RX_SPISLAVE_SET_T;

  /*
  ************************************************************
  *   I2C Configuration
  ************************************************************
  */

  typedef enum RX_I2C_SPEEDtag {
    RX_I2C_SPEED_25_KHZ = 0,
    RX_I2C_SPEED_50_KHZ,
    RX_I2C_SPEED_100_KHZ,
    RX_I2C_SPEED_200_KHZ,
    RX_I2C_SPEED_400_KHZ,
    RX_I2C_SPEED_600_KHZ,
    RX_I2C_SPEED_800_KHZ,
    RX_I2C_SPEED_1000_KHZ,
    RX_I2C_SPEED_1200_KHZ,
    RX_I2C_SPEED_1700_KHZ,
    RX_I2C_SPEED_3400_KHZ,
    RX_I2C_SPEED_DEFAULT,

  } RX_I2C_SPEED;
  
  typedef struct RX_I2C_SET_Ttag {
    RX_PERIPHERAL_HEADER_T tCfgHd;  /* Peripheral Header */

    RX_I2C_SPEED eBusSpeed;       /* index of the slave's spi port */
  } RX_I2C_SET_T;

  /*
  ************************************************************
  *   IO Configuration
  ************************************************************
  */

  typedef struct RX_IO_SET_Ttag 
  {
    RX_PERIPHERAL_HEADER_T tCfgHd;  /* Peripheral Header */
    RX_RESULT (*fnInit)(RX_HANDLE hClass);
  } RX_IO_SET_T;

  /*
  ************************************************************
  *   Fifo Unit Configuration
  ************************************************************
  */
  enum RX_FIFOCHANNELtag { /* FIFO-Channel to be addressed */
    RX_FIFOUNIT_CHANNEL0,
    RX_FIFOUNIT_CHANNEL1,
    RX_FIFOUNIT_CHANNEL2,
    RX_FIFOUNIT_CHANNEL3
  };
  typedef UINT8 RX_FIFOCHANNEL;

  #define RX_FIFO_UNUSED 0

  typedef struct RX_FIFOCHANNEL_SET_Ttag {
    RX_PERIPHERAL_HEADER_T tCfgHd; /* Peripheral Header */

    RX_FIFOCHANNEL eFifChn;        /* FIFO-Channel to be configured */
    UINT uFifo0Dep;                /* depths of 8 FIFOs per Channel */
    UINT uFifo1Dep;
    UINT uFifo2Dep;
    UINT uFifo3Dep;
    UINT uFifo4Dep;
    UINT uFifo5Dep;
    UINT uFifo6Dep;
    UINT uFifo7Dep;
  } RX_FIFOCHANNEL_SET_T;

  /*
  ************************************************************
  *   Interrupt Configuration
  ************************************************************
  */
  enum RX_INTERRUPT_MODEtag {
    RX_INTERRUPT_MODE_INTERRUPT,
    RX_INTERRUPT_MODE_SYSTEM,
    RX_INTERRUPT_MODE_TASK,
  };
  typedef UINT8 RX_INTERRUPT_MODE;

  #define RX_INTERRUPT_MODE_NESTED RX_INTERRUPT_MODE_SYSTEM

  enum RX_INTERRUPT_EOItag {
    RX_INTERRUPT_EOI_AUTO,
    RX_INTERRUPT_EOI_SELF,
    RX_INTERRUPT_EOI_SELF_NESTED_DISABLE,
    RX_INTERRUPT_EOI_SELF_NESTED_ENABLE,
  };
  typedef UINT8 RX_INTERRUPT_EOI;

  enum RX_INTERRUPT_TRIGGERtag {
    RX_INTERRUPT_TRIGGER_RISING_EDGE,
    RX_INTERRUPT_TRIGGER_FALLING_EDGE,
    RX_INTERRUPT_TRIGGER_LEVEL_NULL,
    RX_INTERRUPT_TRIGGER_LEVEL_ONE
  };
  typedef UINT8 RX_INTERRUPT_TRIGGER;

  enum RX_INTERRUPT_PRIORITYtag {
    RX_INTERRUPT_PRIORITY_STANDARD,
    RX_INTERRUPT_PRIORITY_HIGH
  };
  typedef UINT8 RX_INTERRUPT_PRIORITY;

  enum RX_INTERRUPT_REENTRANCYtag {
    RX_INTERRUPT_REENTRANCY_DISABLED,
    RX_INTERRUPT_REENTRANCY_ENABLED
  };
  typedef UINT8 RX_INTERRUPT_REENTRANCY;

  typedef struct RX_INTERRUPT_SET_Ttag {
    RX_PERIPHERAL_HEADER_T  tCfgHd; /* Peripheral Header */

    UINT                      uIntNum; /* Interrupt number */
    UINT                      uPrio; /* Interrupt Priority */
    RX_INTERRUPT_MODE         eMod; /* Interrupt Service Routine Handling */
    RX_INTERRUPT_EOI          eEoi; /* EOI to Interrupt Controller automatically or by ISR itself */
    RX_INTERRUPT_TRIGGER      eTrig; /* Interrupt Trigger mode */
    RX_INTERRUPT_PRIORITY     ePrio; /* Interrupt Hardware Priority Level */
    RX_INTERRUPT_REENTRANCY   eRntr; /* Interrupt reentrant or Not */
    UINT16                    eTaskModePriority;
    UINT16                    eTaskToken;
    UINT                      uTaskStackSize;
  } RX_INTERRUPT_SET_T;

  /*
  ************************************************************
  *   Fast Interrupt Configuration
  ************************************************************
  */
  typedef struct RX_FIQ_SET_Ttag {
    RX_PERIPHERAL_HEADER_T tCfgHd; /* Peripheral Header */

    UINT uIntNum; /* Interrupt number */
  } RX_FIQ_SET_T;

  /*
  ************************************************************
  *   PHY Configuration
  ************************************************************
  */
  #define RX_PHY_MAX_REGISTERS 32

  typedef struct RX_PHY_CONFIGURATION_Ttag {
    UINT uReg; /* Register Offset to write to */
    UINT uVlu; /* Value to write to the specified Register */
  } RX_PHY_CONFIGURATION_T;

  typedef struct RX_PHY_SET_Ttag {
    RX_PERIPHERAL_HEADER_T tCfgHd; /* Peripheral Header */

    UINT   uPhyPrt;   /* Physical port number of PHY */
    UINT32 ulOUI;     /* Organizationally Unique Identifier */
    UINT32 ulManPart; /* Manufacturer specific Part Number */
    UINT32 ulManRev;  /* Manufacturer Revision Number */

    UINT uNumReg;     /* Number of following Registers to write to */
    RX_PHY_CONFIGURATION_T atReg[RX_PHY_MAX_REGISTERS]; /* Register set to write the values to */

    BOOLEAN fPowerDown;  /* power down phy on init */
    BOOLEAN fCustomInit; /* TRUE if custom initialization parameters (below) shall be used */
    UINT32  ulMode;      /* Custom PHY Mode, see program reference guide for values */
    BOOLEAN fAutoMDIX;   /* Auto-Crossover mode */
    BOOLEAN fFXMode;     /* Fiberoptics mode    */

  } RX_PHY_SET_T;





  /*
  ************************************************************
  *   Hardware Timer Configuration
  ************************************************************
  */

  enum RX_HWTIMER_TRIGGERtag {
    RX_HWTIMER_TRIGGER_NONE,
    RX_HWTIMER_TRIGGER_RISING_EDGE,
    RX_HWTIMER_TRIGGER_FALLING_EDGE,
    RX_HWTIMER_TRIGGER_LEVEL_NULL,
    RX_HWTIMER_TRIGGER_LEVEL_ONE,
    RX_HWTIMER_TRIGGER_RISING_FALLING_EDGE,
  };
  typedef UINT8 RX_HWTIMER_TRIGGER;


  typedef struct RX_HWTIMER_SET_Ttag {
    RX_PERIPHERAL_HEADER_T tCfgHd; /* Peripheral Header */

    UINT uTimNum;             /* Number of Timer Unit to use */
    UINT uMax;                /* Maximum Timer/Counter compare value in microseconds */
    BOOLEAN fCont;            /* Continuous or Once Mode on/off */
    BOOLEAN fInt;             /* Interrupt when timer expires on/off */
    BOOLEAN fExt;             /* External clock source */
    RX_HWTIMER_TRIGGER eTrig; /* Trigger method, level or edge in case external trigger usage */
    UINT uExtIoRef;           /* General-purpose I/O reference for external trigger */
    UINT uPscl;               /* Use optional Prescaler if != 0 */
  } RX_HWTIMER_SET_T;

  /*
  ************************************************************
  *   UART Configuration
  ************************************************************
  */

  enum RX_UART_BAUDRATEtag {
    RX_UART_BAUDRATE_300    =    3,
    RX_UART_BAUDRATE_600    =    6,
    RX_UART_BAUDRATE_1200   =   12,
    RX_UART_BAUDRATE_2400   =   24,
    RX_UART_BAUDRATE_4800   =   48,
    RX_UART_BAUDRATE_9600   =   96,
    RX_UART_BAUDRATE_19200  =  192,
    RX_UART_BAUDRATE_38400  =  384,
    RX_UART_BAUDRATE_57600  =  576,
    RX_UART_BAUDRATE_115200 = 1152
  };
  typedef UINT16 RX_UART_BAUDRATE;

  enum RX_UART_PARITYtag {
    RX_UART_PARITY_NONE = 0,
    RX_UART_PARITY_ODD  = 1,
    RX_UART_PARITY_EVEN = 2
  };
  typedef UINT8 RX_UART_PARITY;

  enum RX_UART_STOPBITtag {
    RX_UART_STOPBIT_1 = 0,
    RX_UART_STOPBIT_2 = 1
  };
  typedef UINT8 RX_UART_STOPBIT;

  enum RX_UART_DATABITtag {
    RX_UART_DATABIT_5 = 1,
    RX_UART_DATABIT_6 = 2,
    RX_UART_DATABIT_7 = 3,
    RX_UART_DATABIT_8 = 4,
    RX_UART_DATABIT_9 = 5,
  };
  typedef UINT8 RX_UART_DATABIT;

  enum RX_UART_RTStag {
    RX_UART_RTS_NONE = 0,
    RX_UART_RTS_AUTO_INBITS = 1,
    RX_UART_RTS_AUTO_INCLOCKS = 2,
    RX_UART_RTS_AUTO_INTICKS = 3,
    RX_UART_RTS_SELF = 4
  };
  typedef UINT8 RX_UART_RTS;

  enum RX_UART_RTS_POLARITYtag {
    RX_UART_RTS_DEFAULT = 0,
    RX_UART_RTS_ACTIVE_HIGH = 1,
    RX_UART_RTS_ACTIVE_LOW = 2
  };
  typedef UINT8 RX_UART_RTS_POLARITY;

  enum RX_UART_CTStag {
    RX_UART_CTS_NONE = 0,
    RX_UART_CTS_AUTO = 1,
    RX_UART_CTS_SELF = 2
  };
  typedef UINT8 RX_UART_CTS;

  enum RX_UART_CTS_POLARITYtag {
    RX_UART_CTS_DEFAULT = 0,
    RX_UART_CTS_ACTIVE_HIGH = 1,
    RX_UART_CTS_ACTIVE_LOW = 2
  };
  typedef UINT8 RX_UART_CTS_POLARITY;


  typedef struct RX_UART_SET_Ttag {
    RX_PERIPHERAL_HEADER_T  tCfgHd;              /* peripheral header */
    UINT                    uUrtNum;             /* UART number (0..2) */
    RX_UART_BAUDRATE        eBdRte;              /* baud rate configuration code */
    RX_UART_PARITY          ePrty;               /* parity configuration code */
    RX_UART_STOPBIT         eStp;                /* stop bit configuration code */
    RX_UART_DATABIT         eDat;                /* data bit configuration code */
    UINT                    uRxFifoLvl;          /* receive FIFO trigger level for real UARTs ([0..16], 0: FIFO disabled, recommended value: 12) */
    UINT                    uTxFifoLvl;          /* transmit FIFO trigger level for real UARTs ([0..16], 0: FIFO disabled, recommended value: 4) */
    RX_UART_RTS             eRts;                /* RTS signal handling code */
    RX_UART_RTS_POLARITY    eRtsPol;             /* RTS signal polarity code */
    UINT                    uRtsForrun;          /* RTS signal forerun in AUTO mode */
    UINT                    uRtsTrail;           /* RTS signal trail in AUTO mode */
    RX_UART_CTS             eCts;                /* CTS signal support */
    RX_UART_CTS_POLARITY    eCtsPol;             /* CTS signal polarity */
    /* Compatibility note: Fields at the end of the structure not listed in static initializations are set to zero by the compiler. */
    UINT32                  ulFlags;             /* UART HAL / USB HAL behavior control flags, see RX_UART_FLAG_xxx */
    UINT16                  usUsbVendorID;       /* USB device vendor ID (VID) */
    UINT16                  usUsbProductID;      /* USB device product ID (PID) */
    UINT16                  usUsbProductRelease; /* USB device product release number */
    STRING                  szUsbVendorName[RX_UART_USB_VENDOR_NAME_LEN];
    STRING                  szUsbProductName[RX_UART_USB_PRODUCT_NAME_LEN];
    STRING                  szUsbSerialNumber[RX_UART_USB_SERIAL_NUMBER_LEN];
  } RX_UART_SET_T;


  /*
  ************************************************************
  *   XC Configuration
  ************************************************************
  */
  extern UINT32 XcCode_xpec_eth_std_mac0;
  extern UINT32 XcCode_xpec_eth_std_mac1;
  extern UINT32 XcCode_xpec_eth_std_mac2;
  extern UINT32 XcCode_xpec_eth_std_mac3;
  extern UINT32 XcCode_xpec_eth_std_mac_rpec0;
  extern UINT32 XcCode_xpec_eth_std_mac_rpec1;

  extern UINT32 XcCode_xpec_eth_2port_switch0;
  extern UINT32 XcCode_xpec_eth_2port_switch1;
  extern UINT32 XcCode_xpec_eth_2port_switch2;
  extern UINT32 XcCode_xpec_eth_2port_switch3;
  extern UINT32 XcCode_xpec_eth_2port_switch_rpec0;
  extern UINT32 XcCode_xpec_eth_2port_switch_rpec1;

  extern UINT32 XcCode_rpu_eth_2port_switch0;
  extern UINT32 XcCode_rpu_eth_2port_switch1;
  extern UINT32 XcCode_rpu_eth_2port_switch2;
  extern UINT32 XcCode_rpu_eth_2port_switch3;

  extern UINT32 XcCode_tpu_eth_2port_switch0;
  extern UINT32 XcCode_tpu_eth_2port_switch1;
  extern UINT32 XcCode_tpu_eth_2port_switch2;
  extern UINT32 XcCode_tpu_eth_2port_switch3;

  extern UINT32 XcCode_rpu_eth0;
  extern UINT32 XcCode_rpu_eth1;
  extern UINT32 XcCode_rpu_eth2;
  extern UINT32 XcCode_rpu_eth3;

  extern UINT32 XcCode_tpu_eth0;
  extern UINT32 XcCode_tpu_eth1;
  extern UINT32 XcCode_tpu_eth2;
  extern UINT32 XcCode_tpu_eth3;

  #define XC_CODE_ETH_STD_RPEC0 ((UINT32 FAR*)&XcCode_xpec_eth_std_mac_rpec0)
  #define XC_CODE_ETH_STD_RPEC1 ((UINT32 FAR*)&XcCode_xpec_eth_std_mac_rpec1)
  #define XC_CODE_ETH_STD_XPEC0 ((UINT32 FAR*)&XcCode_xpec_eth_std_mac0)
  #define XC_CODE_ETH_STD_XPEC1 ((UINT32 FAR*)&XcCode_xpec_eth_std_mac1)
  #define XC_CODE_ETH_STD_XPEC2 ((UINT32 FAR*)&XcCode_xpec_eth_std_mac2)
  #define XC_CODE_ETH_STD_XPEC3 ((UINT32 FAR*)&XcCode_xpec_eth_std_mac3)

  #define XC_CODE_ETH_2PORT_SWITCH_RPEC0 ((UINT32 FAR*)&XcCode_xpec_eth_2port_switch_rpec0)
  #define XC_CODE_ETH_2PORT_SWITCH_RPEC1 ((UINT32 FAR*)&XcCode_xpec_eth_2port_switch_rpec1)
  #define XC_CODE_ETH_2PORT_SWITCH_XPEC0 ((UINT32 FAR*)&XcCode_xpec_eth_2port_switch0)
  #define XC_CODE_ETH_2PORT_SWITCH_XPEC1 ((UINT32 FAR*)&XcCode_xpec_eth_2port_switch1)
  #define XC_CODE_ETH_2PORT_SWITCH_XPEC2 ((UINT32 FAR*)&XcCode_xpec_eth_2port_switch2)
  #define XC_CODE_ETH_2PORT_SWITCH_XPEC3 ((UINT32 FAR*)&XcCode_xpec_eth_2port_switch3)

  #define XC_CODE_ETH_STD_RPU0 ((UINT32 FAR*)&XcCode_rpu_eth0)
  #define XC_CODE_ETH_STD_RPU1 ((UINT32 FAR*)&XcCode_rpu_eth1)
  #define XC_CODE_ETH_STD_RPU2 ((UINT32 FAR*)&XcCode_rpu_eth2)
  #define XC_CODE_ETH_STD_RPU3 ((UINT32 FAR*)&XcCode_rpu_eth3)

  #define XC_CODE_ETH_2PORT_SWITCH_RPU0 ((UINT32 FAR*)&XcCode_rpu_eth_2port_switch0)
  #define XC_CODE_ETH_2PORT_SWITCH_RPU1 ((UINT32 FAR*)&XcCode_rpu_eth_2port_switch1)
  #define XC_CODE_ETH_2PORT_SWITCH_RPU2 ((UINT32 FAR*)&XcCode_rpu_eth_2port_switch2)
  #define XC_CODE_ETH_2PORT_SWITCH_RPU3 ((UINT32 FAR*)&XcCode_rpu_eth_2port_switch3)

  #define XC_CODE_ETH_STD_TPU0 ((UINT32 FAR*)&XcCode_tpu_eth0)
  #define XC_CODE_ETH_STD_TPU1 ((UINT32 FAR*)&XcCode_tpu_eth1)
  #define XC_CODE_ETH_STD_TPU2 ((UINT32 FAR*)&XcCode_tpu_eth2)
  #define XC_CODE_ETH_STD_TPU3 ((UINT32 FAR*)&XcCode_tpu_eth3)

  #define XC_CODE_ETH_2PORT_SWITCH_TPU0 ((UINT32 FAR*)&XcCode_tpu_eth_2port_switch0)
  #define XC_CODE_ETH_2PORT_SWITCH_TPU1 ((UINT32 FAR*)&XcCode_tpu_eth_2port_switch1)
  #define XC_CODE_ETH_2PORT_SWITCH_TPU2 ((UINT32 FAR*)&XcCode_tpu_eth_2port_switch2)
  #define XC_CODE_ETH_2PORT_SWITCH_TPU3 ((UINT32 FAR*)&XcCode_tpu_eth_2port_switch3)

  enum RX_XC_TYPEtag {
#if defined(__NETX51)
    RX_XC_TYPE_RPEC       = 0,
#else
    RX_XC_TYPE_XPEC       = 0,
#endif
    RX_XC_TYPE_XMACRPU    = 1,
    RX_XC_TYPE_XMACTPU    = 2,
#if defined(__NETX51)
    RX_XC_TYPE_TPEC       = 3,
#endif
  };
  typedef UINT8 RX_XC_TYPE;

  typedef struct RX_XC_SET_Ttag {
    RX_PERIPHERAL_HEADER_T tCfgHd; /* Peripheral Header */

    RX_XC_TYPE eXcTyp;     /* Specifies the Type of XC */
    UINT uXcId;            /* Specifies which Xc unit to use */
    UINT32 FAR* pulXcCode; /* Specifies the Pointer to the XC code */
  } RX_XC_SET_T;


  /*
  ************************************************************
  *   LED Configuration
  ************************************************************
  */
  
  /* LED low/high active (in tDir) */
  #define RX_LED_HIGH_ACTIVE {0,0,0}
  #define RX_LED_LOW_ACTIVE  {0,1,0}
  
  enum RX_LED_VALUE_TYPEtag {
    RX_LED_VALUE_TYPE_NONE, /* Register does not exists */
    RX_LED_VALUE_TYPE_OR, /* Value has to be "or" knotted to be active */
    RX_LED_VALUE_TYPE_AND, /* Value has to be "and" knotted to be active */
    RX_LED_VALUE_TYPE_ABSOLUTE, /* Value has to be absolutely written */
  };
  typedef UINT8 RX_LED_VALUE_TYPE;


  typedef struct RX_LED_REGISTER_Ttag {
    RX_LED_VALUE_TYPE uTyp;  /* Value Type */
    UINT uReg; /* Address of Register */
    UINT uVlu; /* Value to set */
  } RX_LED_REGISTER_T;

  typedef struct RX_LED_FUNCTION_SET_Ttag RX_LED_FUNCTION_SET_T;

  typedef struct RX_LED_SET_Ttag {
    RX_PERIPHERAL_HEADER_T tCfgHd; /* Peripheral Header */

    RX_PERIPHERAL_HEADER_T tCfgLedReg; /* Register Destination Definition */
    RX_LED_REGISTER_T tMod;  /* Optional Register to make LED Pin to output at startup */
    RX_LED_REGISTER_T tDir;  /* Optional Register to make LED Pin to output at startup */
    RX_LED_REGISTER_T tEnbl; /* LED Enable Register and Value */
    RX_LED_REGISTER_T tDis;  /* LED Disable Register and Value */
    RX_RESULT (FAR* fnSetupLedOperations)(RX_LED_FUNCTION_SET_T FAR* ptSet);    /* Set of led functions */
  } RX_LED_SET_T;


  struct RX_LED_FUNCTION_SET_Ttag
  {
    RX_RESULT (FAR* fnInitialize)(RX_HANDLE hLed);
    RX_RESULT (FAR* fnRelease)(RX_HANDLE hLed);
    RX_RESULT (FAR* fnSetLed)(RX_HANDLE hLed);
    RX_RESULT (FAR* fnClearLed)(RX_HANDLE hLed);
  };

  /* LED configuration modes:

  */


  /*
  ************************************************************
  * SRAM Bus Configuration
  ************************************************************
  */

  enum RX_SRAMBUS_DATAWIDTH_TYPEtag
  {
    RX_SRAMBUS_DATAWIDTH_8BIT,  /* Data width is 8 Bit */
    RX_SRAMBUS_DATAWIDTH_16BIT, /* Data width is 16 Bit */
    RX_SRAMBUS_DATAWIDTH_32BIT  /* Data width is 32 Bit */
  };
  typedef UINT RX_SRAMBUS_DATAWIDTH_TYPE;

  typedef struct RX_SRAMBUS_SET_Ttag
  {
    UINT                          uChipSelect;
    RX_SRAMBUS_DATAWIDTH_TYPE     eDataWidth;
    UINT                          uWaitStates;
    UINT                          uPreAccessWaitStates;
    UINT                          uPostAccessWaitStates;
  } RX_SRAMBUS_SET_T;


  /*
  ************************************************************
  *   HIF Configuration
  ************************************************************
  */

  #define RX_HIF_MAX_SUPPORTED_CHANNELS 8
  #define RX_HIF_MAX_SUPPORTED_BLOCKS 16
  #define RX_HIF_MAX_SUPPORTED_FUNCTIONS 16

  #define RX_HIF_HANDSHAKE_NONE (~0)

  enum RX_HIF_MODE_TYPEtag {
    RX_HIF_MODE_HIGH_IMPEDANCE,      /* Bus drivers are not enabled, bus is floating */
    RX_HIF_MODE_EXTENSIONBUS,        /* Bus is used as extension bus to connect FLASH/RAM devices */
    RX_HIF_MODE_DPM_UP8BIT,          /* Dualport Memory Bus 8 Bit Data interface */
    RX_HIF_MODE_DPM_UP16BIT,         /* Dualport Memory Bus 16 Bit Data interface */
    RX_HIF_MODE_IO,                  /* Peripheral I/O Bus */
    RX_HIF_MODE_RSRVD1,              /* reserved define for internal use */
  };
  typedef UINT8 RX_HIF_MODE_TYPE;

  enum RX_HIF_CHANNEL_LAYOUTtag {
    RX_HIF_CHANNEL_LAYOUT_UNDEFINED,       /* Undefined */
    RX_HIF_CHANNEL_LAYOUT_NOT_AVAILABLE,   /* Not Available */
    RX_HIF_CHANNEL_LAYOUT_RESERVED,        /* Reserved */
    RX_HIF_CHANNEL_LAYOUT_SYSTEM,          /* System Area of new Dualport */
    RX_HIF_CHANNEL_LAYOUT_HANDSHAKE,       /* not settable but used internally */
    RX_HIF_CHANNEL_LAYOUT_COM_CHANNEL,     /* Port Area of new Dualport */
    RX_HIF_CHANNEL_LAYOUT_APPLICATION,     /* Application Area of new Dualport */
    RX_HIF_CHANNEL_LAYOUT_MAX=127,
    RX_HIF_CHANNEL_LAYOUT_USER_START=128   /* User defined Area of new Dualport */
  };
  typedef UINT8 RX_HIF_CHANNEL_LAYOUT;

  enum RX_HIF_CHANNEL_HDSHK_MODEtag {
    RX_HIF_CHANNEL_HDSHK_MODE_NONE,      /* Optional Handshake cells disabled */
    RX_HIF_CHANNEL_HDSHK_MODE_8BIT,      /* Handshake cells 8Bit wise */
    RX_HIF_CHANNEL_HDSHK_MODE_16BIT      /* Handshake cells 16Bit wise */
  };
  typedef UINT8 RX_HIF_CHANNEL_HDSHK_MODE;

  enum RX_HIF_BLOCK_TYPEtag {
    RX_HIF_BLOCK_TYPE_STATUS,
    RX_HIF_BLOCK_TYPE_MAILBOX,
    RX_HIF_BLOCK_TYPE_IO,
    RX_HIF_BLOCK_TYPE_PARAMETER,
    RX_HIF_BLOCK_TYPE_PORT_STATE,
    RX_HIF_BLOCK_TYPE_IO_HI_PRIO,
    RX_HIF_BLOCK_TYPE_USER,
  };
  typedef UINT8 RX_HIF_BLOCK_TYPE;

  enum RX_HIF_BLOCK_DIRECTIONtag {
    RX_HIF_BLOCK_DIR_FROMHOST,
    RX_HIF_BLOCK_DIR_TOHOST,
    RX_HIF_BLOCK_DIR_FROMTOHOST,
  };
  typedef UINT8 RX_HIF_BLOCK_DIRECTION;

  enum RX_HIF_BLOCK_MODEtag {
    RX_HIF_BLOCK_MODE_UNDEFINED,
    RX_HIF_BLOCK_MODE_DEVICE_SYNCHRONOUS,
    RX_HIF_BLOCK_MODE_DEVICE_CONTROL,
    RX_HIF_BLOCK_MODE_NO_CONTROL,
    RX_HIF_BLOCK_MODE_HOST_CONTROL,
    RX_HIF_BLOCK_MODE_HOST_SYNCHRONOUS,
    RX_HIF_BLOCK_MODE_SINGLE_BUFFER,
    RX_HIF_BLOCK_MODE_TRIPLE_BUFFER,
  };
  typedef UINT8 RX_HIF_BLOCK_MODE;

  enum RX_HIF_BITFUNCTION_TYPEtag {
    RX_HIF_BITFUNCTION_TYPE_UNUSED,
    RX_HIF_BITFUNCTION_TYPE_UNCONTROLLED,
    RX_HIF_BITFUNCTION_TYPE_RESET,
  };
  typedef UINT8 RX_HIF_BITFUNCTION_TYPE;

  enum RX_HIF_TRANSMISSION_TYPEtag {
    RX_HIF_BLOCK_TRANS_DPM,
    RX_HIF_BLOCK_TRANS_DMA,
  };
  typedef UINT8 RX_HIF_TRANSMISSION_TYPE;


  typedef struct RX_HIF_CHANNEL_BLOCK_Ttag {
    STRING                              szIdn[16];          /* Name of the Block */
    UINT                                uInst;              /* Index of the Block */
    RX_HIF_BLOCK_TYPE                   eTyp;               /* Type of Block */
    RX_HIF_TRANSMISSION_TYPE            eTrnsTyp;           /* Transmission type for this Block/Area */
    UINT32                              ulOffs;             /* Relative Offset of this Block/Area within the Channel */
    UINT32                              ulSiz;              /* Size of the Block */
    RX_HIF_BLOCK_DIRECTION              eDir;               /* Transfer direction */
    UINT                                uTrnsBitDmaChnl;    /* Bit position in the Handshake register or DMA channel */
    RX_HIF_BLOCK_MODE                   eMod;               /* Handshake Mode */
    UINT16                              eTaskPriority;      /* Priority of mailbox recv/send task */
    UINT16                              eTaskToken;         /* Token of mailbox recv/send task */
  } RX_HIF_CHANNEL_BLOCK_T;

  typedef struct RX_HIF_CHANNEL_Ttag {
    STRING                              szIdn[16];          /* Name of the Area */
    UINT                                uIdx;               /* Index of Area 0-7 */
    RX_HIF_CHANNEL_LAYOUT               eLayOut;            /* Enumeration defining the layout for this memory block */
    RX_HIF_CHANNEL_HDSHK_MODE           eHdshkMod;          /* The handshake mode 8Bit/16Bit */
    UINT                                uSiz;               /* The size in bytes of this area */
    UINT                                uNumBlocks;         /* Number of Blocks following */
    RX_HIF_CHANNEL_BLOCK_T FAR*         patBlks;            /* Table for the Blocks */
    UINT16                              usMirroredHsChannelNo;  /* specifies channel and handshake offset where to mirror the Handshake cell to, if both are 0 it is disabled */
    UINT16                              usMirroredHsOffset;
  } RX_HIF_CHANNEL_T;

  typedef struct RX_HIF_SET_Ttag {
    RX_PERIPHERAL_HEADER_T        tCfgHd;                   /* Peripheral Header */

    /* HIF Total Configuration */
    RX_HIF_MODE_TYPE              eHifMod;                  /* HIF general operation mode */

    /* The 6 settings below are netX50/100/500 specific, but they are kept here for easier migration,
       as the default way of setting up HIF is to not touch any registers, so the default Hilscher 
       configuration with a 2nd Stage Loader can be the same across all current netX chips */
    UINT32                        ulMode0;                  /* Configures Pins to be either IO or not */
    UINT32                        ulMode1;                  /* Configures Pins to be either IO or not */
    UINT32                        ulDrvEn0;                 /* Configures Pins to be either output or input */
    UINT32                        ulDrvEn1;                 /* Configures Pins to be either output or input */
    UINT32                        ulConf0;                  /* Configures the CPU specific configuration settings */
    UINT32                        ulConf1;                  /* Configures the CPU specific configuration settings */

    UINT32                        ulIOMemTotSiz;            /* Total size of the optional Input/Output Memory */
    BOOLEAN                       fAlwaysUseHandshakeBlock; /* select to use handshake block on any interface */
    BOOLEAN                       fKeepHifRegisters;        /* keep HIF registers as set by ROM bootloader */
    UINT32                        uNumOfChannels;           /* Number of following AREAs in this Memory */
    RX_HIF_CHANNEL_T FAR*         patChannelBlk;            /* Channel configuration */
    UINT32                        ulPhysMemoryBase;         /* ptr to a memory block to be used for DPM area (256-byte alignment) */
    UINT32                        ulPhysMemorySize;         /* size of the memory block */
#if defined(__NETX10)
    UINT32                        ulDpmCfg0;                /*!< DPM_CFG_0 register value       */
    UINT32                        ulHifIoCfg;               /*!< HIF_IO_CFG register value      */
    UINT32                        ulDpm_addr_cfg;           /*!< DPM_ADDR_CFG register value    */
    UINT32                        ulDpm_timing_cfg;         /*!< DPM_TIMING_CFG register value  */
    UINT32                        ulDpm_rdy_cfg;            /*!< DPM_RDY_CFG register value     */
    UINT32                        ulDpm_misc_cfg;           /*!< DPM_MISC_CFG register value    */
    UINT32                        ulDpm_io_cfg_misc;        /*!< DPM_IO_CFG_MISC register value */
#elif defined(__NETX51)
    UINT32                        ulHifIoCfg;               /*!< HIF_IO_CFG register value      */
    UINT32                        ulDpmCfg0;                /*!< DPM_CFG_0 register value       */
    UINT32                        ulDpm_if_cfg;             /*!< DPM_IF_CFG register value      */
    UINT32                        ulDpm_pio_cfg0;           /*!< DPM_PIO_CFG0 register value    */
    UINT32                        ulDpm_pio_cfg1;           /*!< DPM_PIO_CFG1 register value    */
    UINT32                        ulDpm_addr_cfg;           /*!< DPM_ADDR_CFG register value    */
    UINT32                        ulDpm_timing_cfg;         /*!< DPM_TIMING_CFG register value  */
    UINT32                        ulDpm_rdy_cfg;            /*!< DPM_RDY_CFG register value     */
    UINT32                        ulDpm_misc_cfg;           /*!< DPM_MISC_CFG register value    */
    UINT32                        ulDpm_io_cfg_misc;        /*!< DPM_IO_CFG_MISC register value */
#endif
  } RX_HIF_SET_T;

  /*
  ************************************************************
  *   HIF PIO Configuration
  ************************************************************
  */

  typedef struct RX_HIFPIO_SET_Ttag {
    RX_PERIPHERAL_HEADER_T tCfgHd; /* Peripheral Header */

    /* HIF PIO Configuration */
    UINT32 ulMode0;           /* Configures Pins to be either IO or not */
    UINT32 ulMode1;           /* Configures Pins to be either IO or not */
    UINT32 ulDrvEn0;          /* Configures Pins to be either output or input */
    UINT32 ulDrvEn1;          /* Configures Pins to be either output or input */
    UINT32 ulConf0;           /* Configures the CPU specific configuration settings */
    UINT32 ulConf1;           /* Configures the CPU specific configuration settings */
  } RX_HIFPIO_SET_T;

  /*
  ************************************************************
  *   PIO Configuration
  ************************************************************
  */
  enum RX_PIO_VALUE_TYPEtag {
    RX_PIO_VALUE_TYPE_NONE, /* Register does not exists */
    RX_PIO_VALUE_TYPE_ACTIVE_HIGH,   /* PIOs are driven active high */
    RX_PIO_VALUE_TYPE_ACTIVE_LOW,  /* PIOs are driven active low */
    RX_PIO_VALUE_TYPE_ABSOLUTE, /* Value has to be absolutely written */
  };
  typedef UINT8 RX_PIO_VALUE_TYPE;


  typedef struct RX_PIO_REGISTER_VALUE_Ttag {
    RX_PIO_VALUE_TYPE eTyp;  /* Value Type */
    UINT uReg; /* Address of Register */
    UINT uVlu; /* Value to set */
  } RX_PIO_REGISTER_VALUE_T;

  typedef struct RX_PIO_REGISTER_ONLY_Ttag {
    RX_PIO_VALUE_TYPE eTyp;  /* Value Type */
    UINT uReg; /* Address of Register */
  } RX_PIO_REGISTER_ONLY_T;


  typedef struct RX_PIO_SET_Ttag {
    RX_PERIPHERAL_HEADER_T tCfgHd; /* Peripheral Header */

    RX_PIO_REGISTER_VALUE_T tMod;  /* Optional Register to make PIO Pin to output at startup */
    RX_PIO_REGISTER_VALUE_T tDir;  /* Optional Register to make PIO Pin to output at startup */
    RX_PIO_REGISTER_ONLY_T tSet; /* PIO Register to set PIOs */
    RX_PIO_REGISTER_ONLY_T tClr;  /* PIO Register to clear PIOs */
    RX_PIO_REGISTER_ONLY_T tInp;  /* Register to get current input value of the PIOs */
  } RX_PIO_SET_T;

  /*
  ************************************************************
  *   GPIO Configuration
  ************************************************************
  */
  enum RX_GPIO_TYPEtag {
    RX_GPIO_TYPE_INPUT,                       /* GPIO shall be an input */
    RX_GPIO_TYPE_OUTPUT,                      /* GPIO shall be an output */
    RX_GPIO_TYPE_EXT0_MODE,                   /* GPIO shall be an external Reference 0 */
    RX_GPIO_TYPE_EXT1_MODE,                   /* GPIO shall be an external Reference 1 */
  };
  typedef UINT8 RX_GPIO_TYPE;

  enum RX_GPIO_POLARITYtag {
    RX_GPIO_POLARITY_NORMAL,                  /* Input/Output equals to physical value of set/get register value  */
    RX_GPIO_POLARITY_INVERTED,                /* Input/Outputs equals to inverted physical value of get/set register value */
  };
  typedef UINT8 RX_GPIO_POLARITY;

  enum RX_GPIO_MODEtag {
    RX_GPIO_INPUTMODE_STANDARD = 0,           /* GPIO works as standard Input */
    RX_GPIO_INPUTMODE_CAPTURED_CONTINUED = 1, /* Captured at each rising edge to increment selected reference counter */
    RX_GPIO_INPUTMODE_CAPTURED_ONCE = 2,      /* Captured once at a rising edge to increment selected reference counter */
    RX_GPIO_INPUTMODE_CAPTURED_LEVEL = 3,     /* Captured each high level to increment selected reference counter */

    RX_GPIO_OUTPUTMODE_STANDARD_0 = 0,          /* GPIO works as standard Output, set to zero at initialization */
    RX_GPIO_OUTPUTMODE_STANDARD_1 = 1,          /* GPIO works as standard Output, set to one at initialization */
    RX_GPIO_OUTPUTMODE_LINED = 2,             /* GPIO Output can be set as a bundle only together with other Output GPIOs */
    RX_GPIO_OUTPUTMODE_PWM = 3,               /* GPIO operates in Puls Width Modulation mode */
  };
  typedef UINT8 RX_GPIO_MODE;


  enum RX_GPIO_COUNTERtag {
    RX_GPIO_COUNTER_0 = 0,                    /* Counter 0 to 4 may be selected */
    RX_GPIO_COUNTER_1 = 1,
    RX_GPIO_COUNTER_2 = 2,
    RX_GPIO_COUNTER_3 = 3,
    RX_GPIO_COUNTER_4 = 4,
    RX_GPIO_COUNTER_SYSTEMTIME = 5,           /* System Time can be selected as counter */
    RX_GPIO_COUNTER_NONE = 0xFFFF,            /* No Counter referenced */
  };
  typedef UINT16 RX_GPIO_COUNTER;


  typedef struct RX_GIO_SET_Ttag {
    RX_PERIPHERAL_HEADER_T tCfgHd; /* Peripheral Header */

    UINT uGpioNum;                 /* GPIO Number */
    RX_GPIO_TYPE eTyp;             /* GPIO Type */
    RX_GPIO_POLARITY ePol;         /* GPIO Polarity */
    RX_GPIO_MODE eMod;             /* GPIO Mode */
    RX_GPIO_COUNTER eCntRef;       /* Counter Reference, needed when edges or levels shall be counted */
    BOOLEAN fIrq;                  /* Enables/Disables IRQ in the case a counter is referenced */
    UINT uThrHldCptr;              /* Threshold / Capture value in PWM mode */
  } RX_GPIO_SET_T;


  /*
  ************************************************************
  *   Ethernet Device Driver Configuration
  ************************************************************
  */

  typedef struct HAL_EDD_OPERATIONS_Ttag HAL_EDD_OPERATIONS_T;

  extern HAL_EDD_OPERATIONS_T trXEddHalNetX;
  extern HAL_EDD_OPERATIONS_T trXEddHalSwitch2PortNetX;
  extern HAL_EDD_OPERATIONS_T trXEddHalBusGenNetX;
  extern HAL_EDD_OPERATIONS_T trXEddHalWinPCap;          /* _CONSOLE_32_ */
  extern HAL_EDD_OPERATIONS_T trXEddHalLars;            /* Lenze SSP_CON/LARS Chip */

  enum RX_EDD_MODEtag {
    RX_EDD_MODE_DEFAULT = 0,
    RX_EDD_MODE_INTERRUPT = 1,
    RX_EDD_MODE_SINGLE_TASK = 2,
    RX_EDD_MODE_MULTIPLE_TASK = 3
  };
  typedef UINT8 RX_EDD_MODE;

  enum RX_EDD_PARAMETER_TYPEtag
  {
    RX_EDD_PARAM_END_OF_LIST            = 0x0000, /* mandatory end of list parameter */
#define RX_EDD_PARAM_MAC_ADDR EDD_PARAM_MAC_ADDR
#define RX_EDD_PARAM_MAX_FIFO_LEVEL EDD_PARAM_MAX_FIFO_LEVEL
#define RX_EDD_PARAM_USED_IND_BORDER EDD_PARAM_USED_IND_BORDER

    RX_EDD_PARAM_IP_ADDR                = 0x4000,  /* pvParam is a static value */

    RX_EDD_PARAM_XPEC_NAME              = 0xC000, /* pvParam is a pointer to a string */
    RX_EDD_PARAM_XMAC_RPU_NAME          = 0xC001, /* pvParam is a pointer to a string */
    RX_EDD_PARAM_XMAC_TPU_NAME          = 0xC002, /* pvParam is a pointer to a string */
    RX_EDD_PARAM_INTERRUPT_NAME         = 0xC003, /* pvParam is a pointer to a string */
    RX_EDD_PARAM_PHY_NAME               = 0xC004, /* pvParam is a pointer to a string */
    RX_EDD_PARAM_FIFO_NAME              = 0xC005, /* pvParam is a pointer to a string */
    RX_EDD_PARAM_XPEC1_NAME             = 0xC006, /* pvParam is a pointer to a string */
    RX_EDD_PARAM_XMAC1_RPU_NAME         = 0xC007, /* pvParam is a pointer to a string */
    RX_EDD_PARAM_XMAC1_TPU_NAME         = 0xC008, /* pvParam is a pointer to a string */
    RX_EDD_PARAM_INTERRUPT1_NAME        = 0xC009, /* pvParam is a pointer to a string */
    RX_EDD_PARAM_FIFO1_NAME             = 0xC00a, /* pvParam is a pointer to a string */
    RX_EDD_PARAM_AGING_TIME             = 0xC00b, /* pvParam is a static value */
    RX_EDD_PARAM_PHY1_NAME              = 0xC00c, /* pvParam is a pointer to a string */
    RX_EDD_PARAM_XPEC2_NAME             = 0xC00d, /* pvParam is a pointer to a string */
    RX_EDD_PARAM_XMAC2_RPU_NAME         = 0xC00e, /* pvParam is a pointer to a string */
    RX_EDD_PARAM_XMAC2_TPU_NAME         = 0xC00f, /* pvParam is a pointer to a string */
    RX_EDD_PARAM_INTERRUPT2_NAME        = 0xC010, /* pvParam is a pointer to a string */
    RX_EDD_PARAM_PHY2_NAME              = 0xC011, /* pvParam is a pointer to a string */
    RX_EDD_PARAM_FIFO2_NAME             = 0xC012, /* pvParam is a pointer to a string */
    RX_EDD_PARAM_XPEC3_NAME             = 0xC013, /* pvParam is a pointer to a string */
    RX_EDD_PARAM_XMAC3_RPU_NAME         = 0xC014, /* pvParam is a pointer to a string */
    RX_EDD_PARAM_XMAC3_TPU_NAME         = 0xC015, /* pvParam is a pointer to a string */
    RX_EDD_PARAM_INTERRUPT3_NAME        = 0xC016, /* pvParam is a pointer to a string */
    RX_EDD_PARAM_PHY3_NAME              = 0xC017, /* pvParam is a pointer to a string */
    RX_EDD_PARAM_FIFO3_NAME             = 0xC018, /* pvParam is a pointer to a string */
#if defined(__NETX51)
    RX_EDD_PARAM_RPEC_NAME              = 0xC019, /* pvParam is a pointer to a string */
    RX_EDD_PARAM_RPEC1_NAME             = 0xC01A, /* pvParam is a pointer to a string */
    RX_EDD_PARAM_TPEC_NAME              = 0xC01B, /* pvParam is a pointer to a string */
    RX_EDD_PARAM_TPEC1_NAME             = 0xC01C, /* pvParam is a pointer to a string */
#endif
    RX_EDD_PARAM_PHY_LED_BLINKMODE      = 0xC01D, /* pvParam is a static value */
    RX_EDD_PARAM_ACT_LED_BLINKFREQUENCY = 0xC01E, /* pvParam is a static value */
  };
  typedef UINT16 RX_EDD_PARAMETER_TYPE;

  /* for reference of EDD_PARAMETERS_T
  typedef struct RX_EDD_PARAMETERS_Ttag
  {
    RX_EDD_PARAMETER_TYPE     eParamType;
    VOID FAR*                 pvParam;
    UINT32                    ulInstance;
  } RX_EDD_PARAMETERS_T;
  */

  typedef struct EDD_PARAMETERS_Ttag RX_EDD_PARAMETERS_T;

  typedef struct RX_EDD_SET_Ttag {
    RX_PERIPHERAL_HEADER_T tCfgHd; /* Peripheral Header */
    UINT uEddNum;             /* Number of Edd Unit to use */
    STRING szNIC[255];        /* Name of Network Interface e.g. \\Device\\NPF_{8AA411AE-2FCA-474D-8C95-45B1BC5E9930} */
    RX_EDD_MODE eEddMode;     /* edd mode */
    BOOLEAN fRsrcControl;     /* resource control enabled? */
    RX_EDD_PARAMETERS_T FAR* patParams; /* pointer to parameter array */
    HAL_EDD_OPERATIONS_T FAR* ptHalOps; /* pointer to hal operations */
  } RX_EDD_SET_T;


  /*
  ************************************************************
  *   ICM configuration for Lenze communication module
  ************************************************************
  */
  typedef struct RX_ICM_SET_Ttag {
    RX_PERIPHERAL_HEADER_T tCfgHd;  /* Peripheral Header */
    UINT uIcmNum;                   /* Number of Icm Unit to use */
    UINT sDummy;                    /* Dummy entry, add more config data if necessary */
  } RX_ICM_SET_T;


  /*
  ************************************************************
  *   USB configuration
  ************************************************************
  */
  typedef struct RX_USB_SET_Ttag {
    RX_PERIPHERAL_HEADER_T tCfgHd;  /* Peripheral Header */
    UINT uPrt; /* Physical Port number */
  } RX_USB_SET_T;


  /*
  ***********************************************************
  *   Peripheral Configuration Table
  ***********************************************************
  */
  typedef struct RX_PERIPHERAL_CONFIG_Ttag {
    RX_PERIPHERAL_TYPE eTyp; /* Type of Peripheral */
    const void FAR* pvPer; /* Pointer to the Peripheral Configuration Table */
    UINT uNum; /* Number of List-Elements */
  } RX_PERIPHERAL_CONFIG_T;

 /*
  ***********************************************************
  *   Peripheral Driver Configuration Table
  ***********************************************************
  */
  typedef struct RX_DRIVER_PERIPHERAL_CONFIG_Ttag {
    RX_FATAL (FAR* pfnDrvInit) (const void FAR* pvCfg,UINT uNum);
    RX_PERIPHERAL_TYPE eTyp; /* Type of Peripheral */
    const void FAR* pvPer; /* Pointer to the Peripheral Configuration Table */
    UINT uNum; /* Number of List-Elements */
  } RX_DRIVER_PERIPHERAL_CONFIG_T;

 /*
  ***********************************************************
  *   Middleware Configuration Table
  ***********************************************************
  */
  typedef struct RX_MIDDLEWARE_CONFIG_Ttag {
    RX_FATAL (FAR* pfnMidInit) (void FAR* pvPar,UINT uPar);
    void FAR* pvPar; /* Pointer being passed to the Middlware function */
    UINT uPar; /* Parameter being passed to the Middleware function */
  } RX_MIDDLEWARE_CONFIG_T;


 /*
  ***********************************************************
  *   Kernel Services Configuration Table
  ***********************************************************
  */
  typedef struct RX_KERNEL_MODULES_Ttag {
    RX_FATAL (FAR* pfnKrnModInit) ();
  } RX_KERNEL_MODULES_T;


  /*
  ************************************************************
  *   Mid_Sys Config Parameters
  ************************************************************
  */

  typedef struct MID_SYS_SET_Ttag
  {
    UINT16              ePriority;
  } MID_SYS_SET_T;

  typedef struct MID_SYS_DPM_SET_Ttag
  {
    struct
    {
      UINT16  eSendMbxPriority;
      UINT16  eSendMbxToken;
      UINT16  eRecvMbxPriority;
      UINT16  eRecvMbxToken;
    } atMbx[RX_HIF_MAX_SUPPORTED_CHANNELS];

    BOOLEAN             fUseNewPrioDefinition;
    UINT                uNumOfDefaultSizedChannels;
    /* Added on 14.10.2008. These will be filled by compilers with 0, if not defined,
        so only if someone wants to create custom channels, this will be evaluated */
    UINT                uNumOfCustomChannels;
    RX_HIF_CHANNEL_T*   patCustomChannels;
  } MID_SYS_DPM_SET_T;


  /*
  ************************************************************
  *   Mid_Sys Config Parameters
  ************************************************************
  */

  typedef struct MID_RTC_SET_Ttag
  {
    RX_FATAL               (FAR* pfnRtcInit) (RX_HANDLE hRtcDevice, RX_PERIPHERAL_HEADER_T* ptLowLevelDrv);
    RX_PERIPHERAL_HEADER_T tLowLevelDrv;
  } MID_RTC_SET_T;


  /*
  ************************************************************
  *   Function Prototypes
  ************************************************************
  */

  typedef struct RX_SCHEDULER_FUNCTIONS_Ttag RX_SCHEDULER_FUNCTIONS_T;

  extern const RX_SCHEDULER_FUNCTIONS_T g_tMLQueueScheduler;
  extern const RX_SCHEDULER_FUNCTIONS_T g_tBitmapScheduler;

  /* Called by Kernel to install further drivers or to install Patches */
  void FAR      FromKernel        (void);

  /* Function used to load Drivers and Peripherals in the ROM-Kernel Call-Back Function */
  RX_FATAL FAR  LoadDrivers       (const FAR RX_DRIVER_PERIPHERAL_CONFIG_T FAR*     ptDrvCfgPost,
                                   UINT                                             uNumOfDrv);

  /* Function used to exit the Call-Back function */
  RX_FATAL FAR  ToKernel          (const RX_STATIC_TASK_T FAR*                      patStatTsk,
                                   UINT                                             uNumOfTsk,
                                   const RX_MIDDLEWARE_CONFIG_T FAR*                ptMidCfgTbl,
                                   UINT                                             uNumOfMid);

  RX_FATAL FAR  rX_SysEnterKernel (UINT32                                           ulCpuClkRate,
                                   const RX_STATIC_TASK_T FAR*                      patStatTsk,           /* Pointer to static Task-List */
                                   UINT                                             uNumOfTsk,            /* Jumber of configured Tasks within the static Task-List */
                                   const RX_PERIPHERAL_CONFIG_T FAR*                patPer,               /* Pointer to the Peripherals-List */
                                   UINT                                             uNumOfPer,            /* Number of configured Peripherals */
                                   void FAR* FAR*                                   ppvJumpTable,         /* Pointer to optional Jump Table */
                                   UINT                                             uSizOfJumpTable,      /* Size of Jump Table in bytes */
                                   void (FAR*                                       pfnCallBack)(void));  /* Boots the RX-Kernel and hand over Task-List and Peripheral-List */

  /* EnterKernel function that integrates all parameters of the former functions */
  typedef struct RX_ENTERKERNEL_PARAM_Ttag
  {
    /* CPU clock rate */
    UINT32                                        ulCpuClkRate;

    struct
    {
      /* Timer interrupt task priority */
      UINT16                                      eTimerIrqTaskPriority;
      /* Timer interrupt task stack size */
      UINT                                        uTimerStackSize;
    } tTimerTaskConfig;

    struct
    {
      /* Pointer to static Task-List */
      const RX_STATIC_TASK_T FAR*                 patStatTsk;
      /* Jumber of configured Tasks within the static Task-List */
      UINT                                        uNumOfTsk;
    } tStaticTasks;

    struct
    {
      /* Pointer to kernel modules */
      const RX_KERNEL_MODULES_T FAR*              patEntries;
      /* number of additional kernel modules */
      UINT                                        uNumOfEntries;
    } tKernelModules;

    struct
    {
      /* Pointer to the Peripherals-List */
      const RX_PERIPHERAL_CONFIG_T FAR*           patPer;
      /* Number of configured Peripherals */
      UINT                                        uNumOfPer;
    } tPeripherals;

    struct
    {
      /* Pointer to the Post Peripherals-List / LoadDrivers included into */
      const RX_DRIVER_PERIPHERAL_CONFIG_T FAR*    patDrvPer;
      /* Number of configured Post Peripherals / */
      UINT                                        uNumOfDrvPer;
    } tDriverPeripherals;

    struct
    {
      /* Pointer to optional Jump Table */
      void FAR* FAR*                              ppvJumpTable;
      /* Size of Jump Table in bytes */
      UINT                                        uSizeOfJumpTable;
    } tJumpTable;

    /* Callback for special initialization */
    void (FAR*                                    pfnCallBack)(void);

    struct
    {
      /* Pointer to the Middleware List */
      const RX_MIDDLEWARE_CONFIG_T FAR*           ptMidCfgTable;
      /* Number of configured Middlewares */
      UINT                                        uNumOfMidCfg;
    } tMiddleware;

    /* Scheduler component (if another scheduler is desired) */
    RX_SCHEDULER_FUNCTIONS_T CONST FAR*           ptScheduler;

    struct
    {
      /* Cache enable flags */
      BOOLEAN                                     fEnableInstructionCache;
      BOOLEAN                                     fEnableDataCache;
    } tCacheConfig;

    struct
    {
      /* Measure idle performance, this parameter is never evaluated (has no effect) */
      BOOLEAN                                     fDisable;
    } tMeasureIdlePerformance;

    /* Early callback initialization
       - this callback is called before the memory allocation capability has been set up */
    void (FAR*                                    pfnEarlyCallback)(void);
    /* MMU Table Start */
    struct
    {
      /* MMU Physical Start Address */
      UINT32                                      ulPhysAddr;
    } tMMU;

  } RX_ENTERKERNEL_PARAM_T;

  RX_FATAL FAR rX_SysEnterKernelExt(const RX_ENTERKERNEL_PARAM_T FAR* ptParam);   /* Extended version of SysEnterKernel */

#if defined(__cplusplus)
  }
#endif

#endif /* __RX_CONFIG_H */
