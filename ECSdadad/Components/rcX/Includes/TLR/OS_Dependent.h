/******************************************************************************

  Copyright (C) 2010 Hilscher Gesellschaft für Systemautomation mbH.

  This program can be used by everyone according the "industrialNETworX Public License INPL".

  The license can be downloaded under <http://www.industrialNETworX.com>.

*******************************************************************************

  Last Modification:
    @version $Id: OS_Dependent.h 569 2010-11-19 08:47:54Z MichaelT $

  Description:
    Operating system abstraction

  Changes:
    Date        Author        Description
  ---------------------------------------------------------------------------
    2010-03-23  NC            File created.

******************************************************************************/


#ifndef __OS_DEPENDENT__H
#define __OS_DEPENDENT__H

#ifdef __cplusplus
  extern "C" {
#endif  /* __cplusplus */



/*****************************************************************************/
/* Include Files Required                                                    */
/*****************************************************************************/

#include <stdint.h>
#include <OS_Includes.h>


/*****************************************************************************/
/* Symbol Definitions                                                        */
/*****************************************************************************/

/* none */


/*****************************************************************************/
/* Class, Type, and Structure Definitions                                    */
/*****************************************************************************/
  
/* none */
  
  
/*****************************************************************************/
/* Global Variables                                                          */
/*****************************************************************************/
  
  /* none */
  
  
/*****************************************************************************/
/* Macros                                                                    */
/*****************************************************************************/
  
  /* none */


/*****************************************************************************/
/* Functions                                                                 */
/*****************************************************************************/

void* OS_Memalloc(int iSize);
void  OS_Memfree(void* pvMem);

void  OS_Memset(void* pvBuffer, int iFill, int iSize);
void  OS_Memcpy(void* pvDest, const void* pvSource, int iSize);
int   OS_Memcmp(void* pvBuf1, void* pvBuf2, int iSize);

char* OS_Strncpy(char* destination, const char* source, int num );
int   OS_Strncmp(const char* szBuf1, const char* szBuf2, int iSize);
int   OS_Strlen(const char* szBuffer);

void* OS_CreateSemaphore(const char* szName, uint32_t ulInitialCount, uint32_t ulMaxCount);
int   OS_WaitSemaphore(void* hSemaphore, uint32_t ulTimeout);
int   OS_ReleaseSemaphore(void* hSemaphore, uint32_t ulReleaseCount);
void  OS_DeleteSemaphore(void* hSemaphore);

void* OS_CreateLock(void);
void  OS_DeleteLock(void* hLock);
int   OS_EnterLock(void* hLock);
void  OS_LeaveLock(void* hLock);

typedef uint32_t(*PFN_THREAD_FUNC)(void* pvUser);

void* OS_CreateThread(PFN_THREAD_FUNC pfnThread, void* pvUser, uint32_t ulStackSize, int iPriority, int fSuspended, void** ppvThreadId);
void  OS_ResumeThread(void* pvThread);
void  OS_EndThread(void* pvThread);

void* OS_GetCurrentThread(void);
void  OS_Sleep(uint32_t ulTimeMs);

void* OS_MapPhysicalMemory(uint64_t ullAddress, uint32_t ulSize, void** ppvMemory);
void  OS_UnmapPhysicalMemory(void* hMapping, uint32_t ulSize);

typedef void(*PFN_INTERRUPT_HANDLER)(void* pvUser);

void* OS_ConnectInterrupt(void* pvOSSpecific,
                          PFN_INTERRUPT_HANDLER pfnInterrupt,
                          void* pvUser);
void  OS_DisconnectInterrupt(void* pvIrq);
void  OS_EnableInterrupt(void* pvIrq);
void  OS_DisableInterrupt(void* pvIrq);

typedef void(*PFN_TIMER_CALLBACK)(void* pvTimer, void* pvUser);

void* OS_CreateTimer(uint32_t ulInterval, PFN_TIMER_CALLBACK pfnCallback, void* pvUser);
void OS_DeleteTimer(void* pvTimer);

uint32_t OS_GetSystemTicks(void);
uint32_t OS_GetSystemCycleTime(void);



#ifdef __cplusplus
}
#endif  /* __cplusplus */

#endif /* __OS_DEPENDENT__H */
