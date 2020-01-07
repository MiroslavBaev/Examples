/**************************************************************************//**
 * @file     system_netx90_app.c
 * @brief    CMSIS Cortex-M4 Device Peripheral Access Layer Source File for
 *           Device netx90_app
 * @version  V1.0.0
 * @date     14. August 2017
 ******************************************************************************/
/*
 * Copyright (c) 2009-2016 ARM Limited. All rights reserved.
 *
 * SPDX-License-Identifier: Apache-2.0
 *
 * Licensed under the Apache License, Version 2.0 (the License); you may
 * not use this file except in compliance with the License.
 * You may obtain a copy of the License at
 *
 * www.apache.org/licenses/LICENSE-2.0
 *
 * Unless required by applicable law or agreed to in writing, software
 * distributed under the License is distributed on an AS IS BASIS, WITHOUT
 * WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
 * See the License for the specific language governing permissions and
 * limitations under the License.
 */

#include <stdint.h>
#include <string.h>
#include "cmsis_gcc.h"
#include "system_netx.h"
#include "netx90_app.h"

/*!---------------------------------------------------------------------------
 Define for system clock speed
 *----------------------------------------------------------------------------*/
#define SYSTEM_CLOCK    (100000000UL)

/*!---------------------------------------------------------------------------
 System Core Clock Variable
 *----------------------------------------------------------------------------*/
uint32_t SystemCoreClock = SYSTEM_CLOCK; /* System Clock Frequency (Core Clock)*/

/*---------------------------------------------------------------------------
 Clock functions
 *----------------------------------------------------------------------------*/

/*!
 * Function for setting the system core clock variable to default
 */
void SystemCoreClockUpdate(void) /* Get Core Clock Frequency      */
{
  SystemCoreClock = SYSTEM_CLOCK;
}

/*!
 * Fault handler for system init reset vector
 */
void SystemInitFault(void)
{
  while(1)
    ;
}

/*!
 * Global used as reset vector for system init.
 */
void* g_apvVector[16] = { 0, 0, (void *) SystemInitFault, (void *) SystemInitFault, (void *) SystemInitFault, (void *) SystemInitFault,
  (void *) SystemInitFault, (void *) SystemInitFault, (void *) SystemInitFault, (void *) SystemInitFault, (void *) SystemInitFault,
  (void *) SystemInitFault, (void *) SystemInitFault, (void *) SystemInitFault, (void *) SystemInitFault, (void *) SystemInitFault };

/*!
 * Contains the pointer to the vector table offset register of an arm cortex m.
 */
uint32_t * * const SCB_VTOR = (uint32_t * * const ) 0xe000ed08;

/*!
 * Global array where the extracted calibration data is written to.
 */
NETX_TEMP_CALIBRATION_T g_atTemperatureCalibrationData[2];

/*!
 * Globals for the trampoline structure of the intflash access functions.
 */
//extern DRV_TRAMPOLINE_T tPageReaderFunction;
//extern DRV_TRAMPOLINE_T tPageFlasherFunction;
volatile uint32_t ulRead = 0;

/*!
 * Function for extracting the calibration data from the info page
 */
void PageReader(void)
{
  volatile NETX_TEMP_CALIBRATION_T * const ptCalibrationDataPosition = (void * const ) 0x00000800;
  __disable_irq();
  iflash_cfg2->iflash_reset = 1u; // reset flash for cache reset
  ulRead = iflash_cfg2->iflash_reset;
  iflash_cfg2->iflash_reset = 0u; // enable it again with an empty cache
  ulRead = iflash_cfg2->iflash_reset;
  iflash_cfg2->iflash_ifren_cfg = 1u; // show info page
  ulRead = iflash_cfg2->iflash_ifren_cfg;
  __DSB();
  g_atTemperatureCalibrationData[0] = ptCalibrationDataPosition[0];
  g_atTemperatureCalibrationData[1] = ptCalibrationDataPosition[1];
  __DSB();
  iflash_cfg2->iflash_ifren_cfg = 0u; // hide info page
  ulRead = iflash_cfg2->iflash_ifren_cfg;
  iflash_cfg2->iflash_reset = 1u; // reset flash for cache reset
  ulRead = iflash_cfg2->iflash_reset;
  iflash_cfg2->iflash_reset = 0u; // enable it again with an empty cache
  ulRead = iflash_cfg2->iflash_reset;
  __DSB();
  __ISB();
  __enable_irq();
}

/*!
 *
 */
typedef enum DRV_FLASHER_JOB_Etag
{
  DRV_FLASHER_JOB_ERASE, /*!< */
  DRV_FLASHER_JOB_COPY, /*!< */
  DRV_FLASHER_JOB_ERASE_COPY, /*!< */
} DRV_FLASHER_JOB_E;

#define intflash2 ((uint32_t*)0x00200000)

/*!
 * Function for extracting the calibration data from the info page
 */
void PageFlasher(DRV_FLASHER_JOB_E eJob, void * pvDestination, void * pvSource, size_t size)
{
  __disable_irq();
  iflash_cfg2->iflash_reset = 1u; // reset flash
  ulRead = iflash_cfg2->iflash_reset;
  iflash_cfg2->iflash_reset = 0u; // enable it again with an empty cache
  ulRead = iflash_cfg2->iflash_reset;
  __DSB();
  // Keep in mind, that there are redundancy pages.
  // Keep in mind, that the xpic/other masters might read from flash.
  // Keep in mind, that the flash is located in a different data switch as the
  // iflash control logic.
  // Erase Page
  // Copy Page
  iflash_cfg2->iflash_reset = 1u; // reset flash for cache reset
  ulRead = iflash_cfg2->iflash_reset;
  iflash_cfg2->iflash_reset = 0u; // enable it again with an empty cache
  ulRead = iflash_cfg2->iflash_reset;
  __DSB();
  __ISB();
  __enable_irq();
}

/*!
 * Pointer to the Page extraction function for linker purposes.
 */
void (* const pPageReader)(void) = PageReader;

/*!
 * Pointer to the Page flasher function for linker purposes.
 */
void (* const pPageFlasher)(DRV_FLASHER_JOB_E, void *, void *, size_t) = PageFlasher;

/*!---------------------------------------------------------------------------
 System initialization function
 *----------------------------------------------------------------------------*/
void SystemInit(void)
{
  SystemCoreClockUpdate();
    if(tPageReaderFunction.entry != 0)
    {
      *SCB_VTOR = (void *) g_apvVector;
      memcpy(tPageReaderFunction.target, tPageReaderFunction.source, tPageReaderFunction.length);
      __DSB();
      __ISB();
      tPageReaderFunction.entry();
      ulRead = ulRead;
      *SCB_VTOR = (uint32_t *) __Vectors;
    }
}

