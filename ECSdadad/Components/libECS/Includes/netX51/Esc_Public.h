#ifndef __ESC_PUBLIC_H__
#define __ESC_PUBLIC_H__

#include <stdint.h>
#include <stdbool.h>

/* Depreciated type definitions, do not use */
typedef void* ESC_SYNCMAN_HANDLE;
typedef void* ESC_INTERFACE_HANDLE;

/*****************************************************************************/
/*! Result Codes for HAL Functions
* \description
*    All EtherCAT slave functions return one of the following
*    values after returning from the function call. Function return
*    values shall always be evaluated by the calling function.               */
/*****************************************************************************/
typedef enum ESC_RESULTtag
{
  ESC_SUCCESS                    = 0,         /**< Successful, any other value is an error code defined by the specific underlying infrastructure */
  ESC_ERR_INVALID_VERSION        = 0x20000,   /**< xC Version mismatch              */
  ESC_ERR_NO_PHYSICAL_MEM_ACCESS = 0x20001,   /**< no physical memory access        */
  ESC_ERR_IRQ_NOT_AVAIL          = 0x20002,   /**< no IRQ available                 */
  ESC_ERR_XC_LOAD_ERROR          = 0x20003,   /**< xC code loading failed           */
  ESC_ERR_NO_MEM_AVAIL           = 0x20004,   /**< Not enough memory                */
  ESC_ERR_NO_OS_TIMER            = 0x20005,   /**< No OS timer available            */
  ESC_ERR_OSAL_INIT_ERROR        = 0x20006,   /**< OS adaptation layer initialization failed  */
  ESC_ERR_INVALID_DEVICE         = 0x20007   /**< Invalid Device                    */
} ESC_RESULT;

/******************************************************************************
 * EtherCAT slave controller initialization
 */
ESC_RESULT Esc_Initialize(uint16_t   usPdiConfig,
                          uint16_t   usImpulseLength,
                          void**     phEsc );

/******************************************************************************
 * Interrupt functions to be called from Interrupt handlers
 */
void Esc_ProcPortInterrupt( void );
void Esc_ProcPortInterrupt2( void );
void Esc_SyncPortInterrupt( void );

/******************************************************************************
 * Sync Manager access
 */

#define ESC_SYNCMAN_QUEUED_FULL 1
#define ESC_SYNCMAN_QUEUED_EMPTY 0

typedef uint8_t* Esc_BufferPointer;

Esc_BufferPointer
Esc_SmRequestBufferForWriting(void* hSyncMan, uint16_t* pusLength);

void
Esc_SmReleaseBufferForWriting(void* hSyncMan);

Esc_BufferPointer
Esc_SmRequestBufferForReading(void* hSyncMan, uint16_t* pusLength);

void
Esc_SmReleaseBufferForReading(void* hSyncMan);

bool
Esc_IsSyncManAccessedByMaster(void* hSyncMan);

bool
Esc_SmWriteTxMailbox(void* hSyncMan, uint8_t* pbData, uint16_t usLength);

bool
Esc_SmReWriteTxMailbox(void* hSyncMan, uint8_t* pbData, uint16_t usLength);

bool
Esc_SmReadRxMailbox(void* hSyncMan, uint8_t* pbData, uint16_t usLength);

void*
Esc_GetSyncManagerHandle(void* hEsc, uint8_t bSyncManChannelId);

bool
Esc_GetSmQueuedState(void* hSyncMan);

uint16_t
Esc_GetSmLength(void* hSyncMan);

bool
Esc_IsSmRetryBitToggled(void* hSyncMan);

void
Esc_ToggleSmRetryAckBit(void* hSyncMan);

void
Esc_SetSyncManDisByAl(void* hSyncMan, bool fSet);


/******************************************************************************
 * DC access
 */

uint32_t
Esc_GetSysTimeOffset(void* hEsc);

uint32_t
Esc_GetSystemTime(void* hEsc);


/******************************************************************************
 * Isochronuous PDI access
 */
uint16_t
Esc_CheckIsoPdiConfig(void* hEsc);

/******************************************************************************
 * Register access
 */
#define ESC_REG_ESC_TYPE                           (0x0000)
#define ESC_REG_ESC_REVISION                       (0x0001)
#define ESC_REG_ESC_BUILD                          (0x0002)
#define ESC_REG_ESC_FMMU_NUM_SUPPORTED             (0x0004)
#define ESC_REG_ESC_SYNCMAN_NUM_SUPPORTED          (0x0005)
#define ESC_REG_ESC_RAM_SIZE                       (0x0006)
#define ESC_REG_ESC_PORT_DESCRIPTOR                (0x0007)
#define ESC_REG_ESC_FEATURES_SUPPORTED             (0x0008)

#define ESC_REG_STATION_ADDRESS                    (0x0010)
#define ESC_REG_SCND_STATION_ADDRESS               (0x0012)

#define ESC_REG_DLCONTROL                          (0x0100)
#define ESC_REG_DLSTATUS                           (0x0110)
#define ESC_REG_ALCONTROL                          (0x0120)
#define ESC_REG_ALSTATUS                           (0x0130)
#define ESC_REG_ALSTATUSCODE                       (0x0134)
#define ESC_REG_ALEVENTMASK                        (0x0204)
#define ESC_REG_ALEVENT                            (0x0220)
#define ESC_REG_PDI_CONFIG_SYNC_UNIT               (0x0151)
#define ESC_PDI_CFG_SYNC_UNIT_SYNC0_OPENDRAIN      (0x01)
#define ESC_PDI_CFG_SYNC_UNIT_SYNC0_HIGH_ACTIVE    (0x02)
#define ESC_PDI_CFG_SYNC_UNIT_SYNC0_OUT_ENABLE     (0x04)
#define ESC_PDI_CFG_SYNC_UNIT_SYNC0_IRQ_ENABLE     (0x08)
#define ESC_PDI_CFG_SYNC_UNIT_SYNC1_OPENDRAIN      (0x10)
#define ESC_PDI_CFG_SYNC_UNIT_SYNC1_HIGH_ACTIVE    (0x20)
#define ESC_PDI_CFG_SYNC_UNIT_SYNC1_OUT_ENABLE     (0x40)
#define ESC_PDI_CFG_SYNC_UNIT_SYNC1_IRQ_ENABLE     (0x80)

#define ESC_REG_WATCHDOG_DIVIDER                   (0x0400)
#define ESC_REG_PROCESS_DATA_WATCHDOG_TIME         (0x0420)

/* TSYNCMAN[channel] = { */
#define ESC_REG_SYNCMAN_PHYSSTARTADDR(channel)     (0x0800+(8*channel))
#define ESC_REG_SYNCMAN_LENGTH(channel)            (0x0802+(8*channel))
#define ESC_REG_SYNCMAN_CONTROL(channel)           (0x0804+(8*channel))
#define ESC_SYNCMAN_CONTROL_BUFFER_TYPE_MASK       (0x03)
#define ESC_SYNCMAN_CONTROL_BUFFERED               (0x00)
#define ESC_SYNCMAN_CONTROL_QUEUED                 (0x02)
#define ESC_SYNCMAN_CONTROL_DIRECTION_MASK         (0x0c)
#define ESC_SYNCMAN_CONTROL_READ_FROM_MASTER       (0x00)
#define ESC_SYNCMAN_CONTROL_WRITTEN_FROM_MASTER    (0x04)
#define ESC_SYNCMAN_CONTROL_ALEVENT                (0x20)
#define ESC_SYNCMAN_CONTROL_WATCHDOG_ENABLE        (0x40)

#define ESC_REG_SYNCMAN_STATUS(channel)            (0x0805+(8*channel))
#define ESC_SYNCMAN_STATUS_WRITE_EVENT             (0x01)
#define ESC_SYNCMAN_STATUS_READ_EVENT              (0x02)
#define ESC_SYNCMAN_STATUS_WATCHDOG_TRIGGER        (0x04)
#define ESC_SYNCMAN_STATUS_QUEUED_STATE_MASK       (0x08)
#define ESC_SYNCMAN_STATUS_BUFFERED_STATE_MASK     (0x30)

#define ESC_REG_SYNCMAN_CHANNEL_ENABLE(channel)    (0x0806+(8*channel))
#define ESC_SYNCMAN_CHANNEL_ENABLE_BIT             (0x01)

#define ESC_REG_SYNC_CONTROL                       (0x0980)
#define ESC_SYNC_CTRL_SYNC_WRITE_SELECT            (0x0001)
#define ESC_SYNC_CTRL_LATCH0_WRITE_SELECT          (0x0010)
#define ESC_SYNC_CTRL_LATCH1_WRITE_SELECT          (0x0020)
#define ESC_SYNC_CTRL_SYNC_ENABLE                  (0x0100)
#define ESC_SYNC_CTRL_SYNC0_ACTIVE                 (0x0200)
#define ESC_SYNC_CTRL_SYNC1_ACTIVE                 (0x0400)
#define MSK_ESC_SYNC_CTRL_SYNC_ENABLE              (0x0700)
#define SRT_ESC_SYNC_CTRL_SYNC_ENABLE              (8)
#define ESC_REG_SYNC_IMPULSE_LENGTH                (0x0982)
#define ESC_REG_SYNC0_STATUS                       (0x098E)
#define ESC_REG_SYNC1_STATUS                       (0x098F)
#define ESC_REG_NEXT_SYNC0_PULSE_SYSTEM_TIME       (0x0990)
#define ESC_REG_NEXT_SYNC1_PULSE_SYSTEM_TIME       (0x0998)
#define ESC_REG_SYNC0_CYCLE_TIME                   (0x09A0)
#define ESC_REG_SYNC1_CYCLE_TIME                   (0x09A4)

#define ESC_REG_LATCH0_CONTROL                     (0x09A8)
#define ESC_REG_LATCH1_CONTROL                     (0x09A9)
#define ESC_REG_LATCH0_STATUS                      (0x09AE)
#define ESC_REG_LATCH1_STATUS                      (0x09AF)
#define ESC_REG_LATCH0_TIME_POS_EDGE               (0x09B0)
#define ESC_REG_LATCH0_TIME_NEG_EDGE               (0x09B8)
#define ESC_REG_LATCH1_TIME_POS_EDGE               (0x09C0)
#define ESC_REG_LATCH1_TIME_NEG_EDGE               (0x09C8)

void
Esc_WriteRegByte(void*    hEsc,
                 uint16_t usAddr,
                 uint8_t  bData);

void
Esc_ReadRegByte(void*    hEsc,
                uint16_t usAddr,
                uint8_t* pbData);

void
Esc_WriteRegWord(void*     hEsc,
                 uint16_t  usAddr,
                 uint16_t  usData);

void
Esc_ReadRegWord(void*     hEsc,
                uint16_t  usAddr,
                uint16_t* pusData);

void
Esc_WriteRegDWord(void*     hEsc,
                  uint16_t  usAddr,
                  uint32_t  ulData);

void
Esc_ReadRegDWord(void*     hEsc,
                 uint16_t  usAddr,
                 uint32_t* pulData);

/******************************************************************************
 * Interrupt routing
 */

/*****************************************************************************/
/*! Interrupt types                                                          */
/*****************************************************************************/
typedef enum ESC_INTERRUPT_TYPE_enum
{
  ESC_INT_SYNC0 = 0,              /**< Trigger 0                     */
  ESC_INT_SYNC1,                  /**< Trigger 1                     */
  ESC_INT_AL_CONTROL,             /**< AL Control                    */
  ESC_INT_SII_EVENT,              /**< SII                           */
  ESC_INT_SYNCMAN_CFG_CHANGED,    /**< Sync Manager Configuration changed */
  ESC_INT_SYNCMAN_CH_0,           /**< Sync Manager Channel 0        */
  ESC_INT_SYNCMAN_CH_1,           /**< Sync Manager Channel 1        */
  ESC_INT_SYNCMAN_CH_2,           /**< Sync Manager Channel 2        */
  ESC_INT_SYNCMAN_CH_3,           /**< Sync Manager Channel 3        */
  ESC_INT_SYNCMAN_CH_4,           /**< Sync Manager Channel 4        */
  ESC_INT_SYNCMAN_CH_5,           /**< Sync Manager Channel 5        */
  ESC_INT_SYNCMAN_CH_6,           /**< Sync Manager Channel 6        */
  ESC_INT_SYNCMAN_CH_7,           /**< Sync Manager Channel 7        */
  ESC_INT_SYNCMAN_WDG             /**< Sync Manager WatchDog elapsed */
} ESC_INTERRUPT_TYPE;
#define ESC_INT_NUM (ESC_INT_SYNCMAN_WDG+1)

typedef void (*ESC_INTERRUPT_FN_T)(void* hHandle, void* pvPrm);

void
Esc_SetupInterrupt(void* hEsc,
                   ESC_INTERRUPT_TYPE,
                   ESC_INTERRUPT_FN_T fnInt, void* pvData);

void
Esc_DeleteInterrupt(void* hEsc,
                    ESC_INTERRUPT_TYPE);

/*****************************************************************************/
/*! Interrupt sources                                                        */
/*****************************************************************************/
typedef enum ESC_INT_SOURCE_enum
{
  ESC_INT_SOURCE_AL_EVENT = 0,      /**< AL Control written event      			*/
  ESC_INT_SOURCE_SII_EVENT,         /**< SII access event    				        */
  ESC_INT_SOURCE_SYNCMAN_CH_0,      /**< Mailbox Out event      				    */
  ESC_INT_SOURCE_SYNCMAN_CH_1,      /**< Mailbox In event     				      */
  ESC_INT_SOURCE_SYNCMAN_CH_2,      /**< RxPDO event      				          */
  ESC_INT_SOURCE_SYNCMAN_CH_3,      /**< TxPDO event     				            */
  ESC_INT_SOURCE_SYNCMAN_CH_4,      /**< SyncMan channel 4 event    				*/
  ESC_INT_SOURCE_SYNCMAN_CH_5,      /**< SyncMan channel 5 event    				*/
  ESC_INT_SOURCE_SYNCMAN_CH_6,      /**< SyncMan channel 6 event    				*/
  ESC_INT_SOURCE_SYNCMAN_CH_7,      /**< SyncMan channel 7 event    				*/
  ESC_INT_SOURCE_SYNCMAN_WDG
} ESC_INT_SOURCE;

void
Esc_EnableIntSource(void* hEsc,
                    ESC_INT_SOURCE eSource);

void
Esc_DisableIntSource(void* hEsc,
                     ESC_INT_SOURCE eSource);

/******************************************************************************
 * SII access functions
 */

/*****************************************************************************/
/*! SII operations                                                           */
/*****************************************************************************/
typedef enum ESC_SII_OPERATION_enum
{
  ESC_SII_OP_NONE,    /**< no SII operation    	    		*/
  ESC_SII_OP_READ,    /**< SII read operation     			*/
  ESC_SII_OP_WRITE,   /**< SII write operation    			*/
  ESC_SII_OP_RELOAD   /**< SII reload operation    			*/
} ESC_SII_OPERATION_T;

void
Esc_SiiWriteData(void* hEsc,
                 uint32_t ulData,
                 uint32_t ulData2);

uint32_t
Esc_SiiReadData(void* hEsc);

uint32_t
Esc_SiiReadAddress(void* hEsc);

bool
Esc_IsSiiBusy(void* hEsc);

ESC_SII_OPERATION_T
Esc_SiiGetOperation(void* hEsc);

void
Esc_SiiSetWriteCompleted(void* hEsc);

void
Esc_SiiSetReadCompleted(void* hEsc);

void
Esc_SiiSetReloadCompleted(void* hEsc);

void
Esc_SiiSetWriteFailed(void* hEsc);

void
Esc_SiiSetReadFailed(void* hEsc);

void
Esc_SiiSetReloadFailed(void* hEsc);

#endif
