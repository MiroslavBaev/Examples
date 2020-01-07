/**************************************************************************************
Copyright (c) Hilscher Gesellschaft fuer Systemautomation mbH. All Rights Reserved.
***************************************************************************************
$Id:  $:

Description:
 See doxygen
***********************************************************************************//**
  \file ExampleTask1_SiiProvider.h
  \todo File description missing
**************************************************************************************/
#if INCLUDE_TYPEDEF_ONLY
#include <stdbool.h>

typedef struct SII_PROVIDER_Ttag{
  uint32_t  ulCurrentByte;        /**< postition in Sii where to write from at next */
  uint32_t  ulRemainingBytes;     /**< number of bytes which still need to be set via Sii write request */
  uint8_t*  pabSiiImage;      /**< source array which contains data of Sii image */
  uint32_t  ulSizeOfSiiImage;
  uint16_t  usStationAlias;
  bool (*pfnCurrenState) (EXAMPLETASK1_RSC_T* ptRsc); /**< returns true if statemashine shall be triggered again in current cycle */
}SII_PROVIDER_T;
#else
#ifndef COMPONENTS_EXAMPLETASK1_INCLUDES_EXAMPLETASK1_SIIPROVIDER_H_
#define COMPONENTS_EXAMPLETASK1_INCLUDES_EXAMPLETASK1_SIIPROVIDER_H_

uint32_t SiiProvider_Init(EXAMPLETASK1_RSC_T* ptRsc,
                                     uint8_t* pabSiiImage,
                                     uint32_t ulSizeOfSiiImage);

void SiiProvider_SiiCreationFsm(EXAMPLETASK1_RSC_T* ptRsc);

#endif /* COMPONENTS_EXAMPLETASK1_INCLUDES_EXAMPLETASK1_SIIPROVIDER_H_ */
#endif /* INCLUDE_TYPEDEF_ONLY */
