/**********************************************************************************//**
Exclusion of Liability for this demo software:
  The following software is intended for and must only be used for reference and in an
  evaluation laboratory environment. It is provided without charge and is subject to
  alterations. There is no warranty for the software, to the extent permitted by
  applicable law. Except when otherwise stated in writing the copyright holders and/or
  other parties provide the software "as is" without warranty of any kind, either
  expressed or implied.
  Please refer to the Agreement in README_DISCLAIMER.txt, provided  together with this
  project!
  By installing or otherwise using the software, you accept the terms of this Agreement.
  If you do not agree to the terms of this Agreement, then do not install or use the
  Software!
**************************************************************************************/
/**************************************************************************************
Copyright (c) Hilscher Gesellschaft fuer Systemautomation mbH. All Rights Reserved.
***************************************************************************************
$Id: mmio_config_nxhx51etm.c 1862 2016-01-27 10:56:55Z Ricky $:

Description:
 See doxygen
***********************************************************************************//**
  \file mmio_config_nxhx51etm.c
  Contains configuration of netX 51 pin multiplexer
**************************************************************************************/
#include "netX51_regdef.h"
#include "mmio_config.h"

/**********************************************************************************//**
 Please do NOT change this configuration !!!

 \note The used configuration in this example is for a NXHX51-ETM
       board. If you are using a different hardware board,
       please check in the board schematics the used pheripherals.
       If you are using the wrong configuration you could damage
       your netX !

       <b>This example configuration can NOT be used on an own
       layout without any modification.</b>
**************************************************************************************/
static MMIO_CONFIG_T s_atMmioConfig[] =
{
  { 0, MMIO_CONFIG_XM0_RX,              0, 0},                /* XMAC0 Receive Data                                   */
  { 1, MMIO_CONFIG_XM0_TX_OUT,          0, 0},                /* XMAC0 Transmit Data                                  */
  { 2, MMIO_CONFIG_XM0_IO1,             0, 0},                /* XMAC0 Programmable IO 1                              */
  { 3, MMIO_CONFIG_XM0_IO0,             0, 0},                /* XMAC0 Programmable IO 0                              */
  { 4, MMIO_CONFIG_XM1_TX_OUT,          0, 0},                /* XMAC1 Transmit Data                                  */
  { 5, MMIO_CONFIG_XM1_IO1,             0, 0},                /* XMAC1 Programmable IO 1                              */
  { 6, MMIO_CONFIG_XM1_RX,              0, 0},                /* XMAC1 Receive Data                                   */
  { 7, MMIO_CONFIG_XM1_IO0,             0, 0},                /* XMAC1 Programmable IO 0                              */
  { 8, MMIO_CONFIG_PIO,                 0, 0},                /* Unused                                               */
  { 9, MMIO_CONFIG_PIO,                 0, 0},                /* Unused                                               */
  {10, MMIO_CONFIG_PIO,                 0, 0},                /* Unused                                               */
  {11, MMIO_CONFIG_PIO,                 0, 0},                /* Unused                                               */
  {12, MMIO_CONFIG_PHY0_LED0,           0, 1},                /* Status LEDs 0 of internal PHY0, Ethernet link 0      */
  {13, MMIO_CONFIG_PHY0_LED1,           0, 1},                /* Status LEDs 1 of internal PHY0, Ethernet activity 0  */
  {14, MMIO_CONFIG_PHY1_LED0,           0, 1},                /* Status LEDs 0 of internal PHY1, Ethernet link 0      */
  {15, MMIO_CONFIG_PHY1_LED1,           0, 1},                /* Status LEDs 1 of internal PHY1, Ethernet activity 0  */
  {16, MMIO_CONFIG_GPIO15,              0, 0},                /* General Purpose IO 15, MMC card detection            */
  {17, MMIO_CONFIG_PIO,                 0, 0},                /* Unused                                               */
  {18, MMIO_CONFIG_PIO,                 0, 0},                /* Unused                                               */
  {19, MMIO_CONFIG_PIO,                 0, 0},                /* Unused                                               */
  {20, MMIO_CONFIG_PIO,                 0, 0},                /* Unused                                               */
  {21, MMIO_CONFIG_PIO,                 0, 0},                /* Unused                                               */
  {22, MMIO_CONFIG_PIO,                 0, 0},                /* Unused                                               */
  {23, MMIO_CONFIG_PIO,                 0, 0},                /* Unused                                               */
  {24, MMIO_CONFIG_GPIO24,              0, 1},                /* General Purpose IO 24, Inverted LED V12 NXHX51-ETM   */
  {25, MMIO_CONFIG_GPIO25,              0, 1},                /* General Purpose IO 25, Inverted LED V13 NXHX51-ETM   */
  {26, MMIO_CONFIG_GPIO26,              0, 1},                /* General Purpose IO 26, Inverted LED V14 NXHX51-ETM   */
  {27, MMIO_CONFIG_GPIO27,              0, 1},                /* General Purpose IO 27, Inverted LED V15 NXHX51-ETM   */
  {28, MMIO_CONFIG_PIO0,                0, 0},                /* Programmable IO 0, Comm-Status LED0 V30 green        */
  {29, MMIO_CONFIG_PIO1,                0, 0},                /* Programmable IO 1, Comm-Status LED0 V30 red          */
  {30, MMIO_CONFIG_PIO2,                0, 0},                /* Programmable IO 2, Comm-Status LED1 V31 green        */
  {31, MMIO_CONFIG_PIO3,                0, 0},                /* Programmable IO 3, Comm-Status LED1 V31 red          */
  {32, MMIO_CONFIG_UART0_CTS,           0, 0},                /* UART0 Clear To Send                                  */
  {33, MMIO_CONFIG_UART0_RTS,           0, 0},                /* UART0 Request To Send                                */
  {34, MMIO_CONFIG_UART0_RXD,           0, 0},                /* UART0 Receive Data                                   */
  {35, MMIO_CONFIG_UART0_TXD,           0, 0},                /* UART0 Transmit Data                                  */
  {36, MMIO_CONFIG_PIO,                 0, 0},                /* Unused                                               */
  {37, MMIO_CONFIG_PIO,                 0, 0},                /* Unused                                               */
  {38, MMIO_CONFIG_PIO,                 0, 0},                /* Unused                                               */
  {39, MMIO_CONFIG_PIO,                 0, 0},                /* Unused                                               */
};


/**********************************************************************************//**
 Configures the MMIO pad with the Multiplexing Matrix unit inside netX51.
**************************************************************************************/
void mmio_config_nxhx51etm( void )
{
  int iIdx;

  /* Configure MMIO pin multiplexer */
  for( iIdx = 0; iIdx < sizeof( s_atMmioConfig ) / sizeof( s_atMmioConfig[0] ); iIdx++ )
  {
    volatile unsigned long* pulMmioConfig = ( volatile unsigned long* )NX51_NETX_MMIO_CTRL_AREA;
    volatile unsigned long* pulAccessKey  = ( volatile unsigned long* )Adr_NX51_asic_ctrl_access_key;

    /* Unlock MMIO Config register */
    *pulAccessKey = *pulAccessKey;

    pulMmioConfig[s_atMmioConfig[iIdx].bMmio] = s_atMmioConfig[iIdx].bFunction <<  SRT_NX51_mmio0_cfg_mmio_sel                |
                                                ( ( s_atMmioConfig[iIdx].fInvertIn )  ? MSK_NX51_mmio0_cfg_mmio_in_inv  : 0 ) |
                                                ( ( s_atMmioConfig[iIdx].fInvertOut ) ? MSK_NX51_mmio0_cfg_mmio_out_inv : 0 );
  }

} /* mmio_config_netx51 */
