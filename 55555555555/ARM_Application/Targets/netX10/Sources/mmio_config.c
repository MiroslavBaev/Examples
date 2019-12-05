/**************************************************************************************

Copyright (c) Hilscher GmbH. All Rights Reserved.

***************************************************************************************

  Filename:
    $Id: mmio_config.c 623 2013-06-12 14:09:45Z Maher $:
  Last Modification:
    $Revision:: 623             $:  Revision of last commit
    $Author:: Maher             $:  Author of last commit
    $Date:: 2013-06-12 16:09:45#$:  Date of last commit

  Targets:
    Win32/ANSI   : no
    Win32/Unicode: no (define _UNICODE)
    WinCE        : no
    rcX          : yes

  Description:
    MMIO – Multiplex Matrix IOs Configuration

  Changes:
    Name    Date          Version     Description
    -----------------------------------------------------------------------------------
    MA      2013-06-12    1.000       created
**************************************************************************************/

/*
************************************************************
*   General Inclusion Area
************************************************************
*/
#include "netX10_regdef.h"                                    /* netX10 register definition */
#include "mmio_config.h"                                      /* Include MMIO configuration */


/*
*********************************************************************
*   MMIO Configuration
*
*   Please do NOT change this configuration !!!
*
*   NOTE:
*         The used configuration in this example is for a NXHX10-ETM
*         board. If you are using a different hardware board, 
*         please check in the board schematics the used phereperals.
*         If you are using the wrong configuration you could damage 
*         your netX !
*
*         This example configuration can NOT be used on an own
*         layout without any modification.
*
*********************************************************************
*/
static MMIO_CONFIG_T s_atMmioConfig[] =
{
  { 0, MMIO_CONFIG_GPIO4,               0, 1},                /* LED Inverted V50  Green NXHX10-ETM                   */
  { 1, MMIO_CONFIG_GPIO5,               0, 1},                /* LED Inverted V50  Red   NXHX10-ETM                   */
  { 2, MMIO_CONFIG_GPIO6,               0, 1},                /* LED Inverted V51  Green NXHX10-ETM                   */
  { 3, MMIO_CONFIG_GPIO7,               0, 1},                /* LED Inverted V51  Red   NXHX10-ETM                   */
  { 4, MMIO_CONFIG_GPIO0,               0, 0},                /* SW30-1 NXHX10-ETM                                    */
  { 5, MMIO_CONFIG_GPIO1,               0, 0},                /* SW30-2 NXHX10-ETM                                    */
  { 6, MMIO_CONFIG_GPIO2,               0, 0},                /* SW30-3 NXHX10-ETM                                    */
  { 7, MMIO_CONFIG_GPIO3,               0, 0},                /* SW30-4 NXHX10-ETM                                    */
  { 8, MMIO_CONFIG_PIO,                 0, 0},                /* Unused                                               */
  { 9, MMIO_CONFIG_PIO,                 0, 0},                /* Unused                                               */
  {10, MMIO_CONFIG_PIO,                 0, 0},                /* Unused                                               */
  {11, MMIO_CONFIG_PIO,                 0, 0},                /* Unused                                               */
  {12, MMIO_CONFIG_PIO,                 0, 0},                /* Unused                                               */
  {13, MMIO_CONFIG_PIO,                 0, 0},                /* Unused                                               */
  {14, MMIO_CONFIG_PIO,                 0, 0},                /* Unused                                               */
  {15, MMIO_CONFIG_PIO,                 0, 0},                /* Unused                                               */
  {16, MMIO_CONFIG_PIO,                 0, 0},                /* Unused                                               */
  {17, MMIO_CONFIG_PIO,                 0, 0},                /* Unused                                               */
  {18, MMIO_CONFIG_PIO,                 0, 0},                /* Unused                                               */
  {19, MMIO_CONFIG_PIO,                 0, 0},                /* Unused                                               */
  {20, MMIO_CONFIG_PIO,                 0, 0},                /* Unused                                               */
  {21, MMIO_CONFIG_PIO,                 0, 0},                /* Unused                                               */
  {22, MMIO_CONFIG_PIO,                 0, 0},                /* Unused                                               */
  {23, MMIO_CONFIG_PIO,                 0, 0},                /* Unused                                               */
};


/**************************************************************************************
 function:    mmio_config_netx10
 description: Configured the MMIO pad with the Multiplexing Matrix unit inside netX10.

 global:      none
 input:       none

 output:      none
 return:      none
**************************************************************************************/
void mmio_config_netx10( void )
{
  int iIdx;

  /* Configure MMIO pin multiplexer */
  for( iIdx = 0; iIdx < sizeof( s_atMmioConfig ) / sizeof( s_atMmioConfig[0] ); iIdx++ )
  {
    volatile unsigned long* pulMmioConfig = ( volatile unsigned long* )NX10_NETX_MMIO_CTRL_AREA;
    volatile unsigned long* pulAccessKey  = ( volatile unsigned long* )Adr_NX10_asic_ctrl_access_key;

    /* Unlock MMIO Config register */
    *pulAccessKey = *pulAccessKey;

    pulMmioConfig[s_atMmioConfig[iIdx].bMmio] = s_atMmioConfig[iIdx].bFunction <<  SRT_NX10_mmio0_cfg_mmio_sel                |
                                                ( ( s_atMmioConfig[iIdx].fInvertIn )  ? MSK_NX10_mmio0_cfg_mmio_in_inv  : 0 ) |
                                                ( ( s_atMmioConfig[iIdx].fInvertOut ) ? MSK_NX10_mmio0_cfg_mmio_out_inv : 0 );
  }

} /* mmio_config_netx10 */
