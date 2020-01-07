/**************************************************************************//**
 * @file     system_netx.h
 * @brief    CMSIS Cortex-M4 Device Peripheral Access Layer Header File for
 *           Device netx90_app
 * @version V0.0.1.0-$Revision: 3468 $
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

/**
 * \addtogroup CMSIS_core_register
 * \ingroup CMSIS
 * \addtogroup CMSIS_Core_InstructionInterface
 * \ingroup CMSIS
 * \addtogroup CMSIS_SIMD_intrinsics
 * \ingroup CMSIS
 * \addtogroup CMSIS_glob_defs
 * \ingroup CMSIS
 * \addtogroup CMSIS_Core_FunctionInterface
 * \ingroup CMSIS
 * \addtogroup netX_header
 * \ingroup CMSIS
 * \addtogroup CMSIS The CMSIS Package
 */


#ifndef __SYSTEM_NETX90_APP_H
#define __SYSTEM_NETX90_APP_H

#ifdef __cplusplus
extern "C"
{
#endif

#include <stdint.h>

#define NETX_CPU_BOOTBLOCK_MAGIC        0xf3beaf00U
#define NETX_CPU_BOOTBLOCK_SIGNATURE    0x41505041U

/* Define a structure for all CM4 vectors. */
typedef struct NETX_CPU_BOOTBLOCK_STRUCT
{
  unsigned long ulMagic; /* The magic value NETX_CPU_BOOTBLOCK_MAGIC. */
  unsigned long aulReserved01[3]; /* Reserved, should be 0. */
  unsigned long ulImageSizeInDwords; /* The size of the image starting after this header, counted in DWORDS. */
  unsigned long ulReserved05; /* Reserved, should be 0. */
  unsigned long ulSignature; /* The signature NETX_CPU_BOOTBLOCK_SIGNATURE. */
  unsigned long ulParameter; /* A pointer to the parameter block. */
  unsigned long aulHash[7]; /* A SHA384 hash over the CM4 header and the complete image. */
  unsigned long ulChecksum; /* A simple checksum over this header. */
} NETX_CPU_BOOTBLOCK_T;

extern uint32_t SystemCoreClock; /*!< System Clock Frequency (Core Clock)  */

/**
 \brief Setup the microcontroller system.

 Initialize the System and update the SystemCoreClock variable.
 */
void SystemInit(void);

typedef struct NETX_TEMP_CALIBRATION_Ttag
{
  unsigned long aulCalDate[2];
  unsigned short ulADCValue;
  unsigned char sRefTemperature;
  unsigned char saucReserved[9];
  unsigned long ulCrc32;
} NETX_TEMP_CALIBRATION_T;

extern NETX_TEMP_CALIBRATION_T g_atTemperatureCalibrationData[2];

/*!
 * Structure defined to contain the informations of the page extraction ping pong code.
 */
typedef struct DRV_TRAMPOLINE_Ttag
{
  void* target;/*!< Pointer to where the function is copied to. */
  void const * source;/*!< Pointer from where the function is copied. */
  unsigned long length;/*!< Length of the function to copy. */
  void (*entry)(void);/*!< Entry point of the function. */
} DRV_TRAMPOLINE_T;

extern DRV_TRAMPOLINE_T tPageReaderFunction, tPageFlasherFunction;
/*!
 * Pointer to the backup reset vector in the system header.
 */
extern void* g_apvVector[16];

/*!
 * Pointer to the original reset vector.
 */
extern void const * const __Vectors[];

/**
 \brief  Update SystemCoreClock variable.

 Updates the SystemCoreClock with current core Clock retrieved from cpu registers.
 */
void SystemCoreClockUpdate(void);

#ifdef __cplusplus
}
#endif

#endif /* __SYSTEM_NETX90_APP_H */
