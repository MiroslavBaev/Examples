/**************************************************************************************
Copyright (c) Hilscher Gesellschaft fuer Systemautomation mbH. All Rights Reserved.
***************************************************************************************
$Id: ExampleTask1_ProcessData.h 1617 2015-11-23 14:06:45Z Ricky $:

Description:
 See doxygen
***********************************************************************************//**
  \file ExampleTask1_ProcessData.h
  \note EXAMPLETASK1_RSC_T must be included before with ECS_PROCESS_DATA_T
        defined as ptRsc->tLoc.tEcsPd, in file
        ExampleTask1_Resources.h
**************************************************************************************/
#ifdef INCLUDE_TYPEDEF_ONLY

/**********************************************************************************//**
 * Typedef for ressources of ProcessData* functions
 *************************************************************************************/
typedef struct ECS_PROCESS_DATA_Ttag
{
#define ECS_PROCESS_DATA_MAX_OUTPUT_SIZE  ( 2 )
#define ECS_PROCESS_DATA_MAX_INPUT_SIZE   ( 2 )
  uint32_t ulOutputSize;
  uint32_t ulInputSize;
  uint32_t aulOutData[ECS_PROCESS_DATA_MAX_OUTPUT_SIZE+3 / sizeof(uint32_t)]; /*round up to next aligned data (uint32_t)*/
  uint32_t aulInData[ECS_PROCESS_DATA_MAX_INPUT_SIZE+3 / sizeof(uint32_t)]; /*round up to next aligned data (uint32_t)*/
}ECS_PROCESS_DATA_T;
#else
#ifndef COMPONENTS_EXAMPLETASK1_INCLUDES_EXAMPLETASK1_PROCESSDATA_H_
#define COMPONENTS_EXAMPLETASK1_INCLUDES_EXAMPLETASK1_PROCESSDATA_H_
/**********************************************************************************//**
 Configures process image
 \param ptRsc [in, out]   Task resources containing ECS_PROCESS_DATA_T tEcsPd at tLoc
 \param ulOutputSize [in] Configured size in byte for data received from ECAT master
 \param ulInputSize [in]  Configured size in byte for data send to ECAT master
 \return TLR_S_OK if success
**************************************************************************************/
static inline uint32_t ProcessDataInit(EXAMPLETASK1_RSC_T* ptRsc,
                                                  uint32_t ulOutputSize,
                                                  uint32_t ulInputSize)
{
  uint32_t ulRslt = 0; /* TLR_S_OK */
  ECS_PROCESS_DATA_T* ptPD = &ptRsc->tLoc.tEcsPd;

  if( (ulOutputSize > ECS_PROCESS_DATA_MAX_OUTPUT_SIZE)
      || (ulInputSize > ECS_PROCESS_DATA_MAX_INPUT_SIZE) )
  {
    ulRslt = 0xFFFFFFFF; /** \todo implement own error code */
  }else
  {
    ptPD->ulOutputSize = ulOutputSize;
    ptPD->ulInputSize = ulInputSize;
    memset(ptPD->aulOutData, 0xAA, ulOutputSize);
    memset(ptPD->aulInData, 0xBB, ulInputSize);
  }
  return ulRslt;
}

/**********************************************************************************//**
  Returns configured process data sizes
  \param ptRsc [in]          Task resources containing ECS_PROCESS_DATA_T tEcsPd at tLoc
  \param pulOutputSize [out] Configured size in byte for data received from ECAT master
  \param pulInputSize [out]  Configured size in byte for data send to ECAT master
**************************************************************************************/
static inline void ProcessDataGetPdSizes(EXAMPLETASK1_RSC_T* ptRsc,
                                                   uint32_t* pulOutputSize,
                                                   uint32_t* pulInputSize)
{
  ECS_PROCESS_DATA_T* ptPD = &ptRsc->tLoc.tEcsPd;

  *pulOutputSize = ptPD->ulOutputSize;
  *pulInputSize = ptPD->ulInputSize;
}
#endif /* INCLUDE_TYPEDEF_ONLY */
#endif /* COMPONENTS_EXAMPLETASK1_INCLUDES_EXAMPLETASK1_PROCESSDATA_H_ */
