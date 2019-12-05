/**************************************************************************************

Copyright (c) Hilscher GmbH. All Rights Reserved.

***************************************************************************************

  Filename:
    $Id: mmio_config.c 594 2013-06-05 13:54:48Z gordon $:
  Last Modification:
    $Revision:: 594             $:  Revision of last commit
    $Author:: gordon            $:  Author of last commit
    $Date:: 2013-06-05 15:54:48#$:  Date of last commit

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
    GG      2012-12-06    1.000       created
**************************************************************************************/

/*
************************************************************
*   General Inclusion Area
************************************************************
*/
#include "netX51_regdef.h"                                    /* netX51 register definition */
#include "mmio_config.h"                                      /* Include MMIO configuration */


/*
*********************************************************************
*   MMIO Configuration
*
*   Please do NOT change this configuration !!!
*
*   NOTE:
*         The used configuration in this example is for a NXHX52-JTAG
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
  { 0, MMIO_CONFIG_XM0_RX,              0, 0},                /* XMAC0 Receive Data                                   */
  { 1, MMIO_CONFIG_XM0_TX_OUT,          0, 0},                /* XMAC0 Transmit Data                                  */
  { 2, MMIO_CONFIG_XM0_IO1,             0, 0},                /* XMAC0 Programmable IO 1                              */
  { 3, MMIO_CONFIG_XM0_IO0,             0, 0},                /* XMAC0 Programmable IO 0                              */
  { 4, MMIO_CONFIG_SPI1_MISO,           0, 0},                /* SPI1 Master-In Slave-Out data                        */
  { 5, MMIO_CONFIG_SPI1_CLK,            0, 0},                /* SPI Serial clock                                     */
  { 6, MMIO_CONFIG_SPI1_MOSI,           0, 0},                /* SPI1 Master-Out Slave-In data                        */
  { 7, MMIO_CONFIG_SPI1_CS0N,           0, 0},                /* SPI Slave Select / Chip Select                       */
  { 8, MMIO_CONFIG_PIO,                 0, 0},                /* Unused                                               */
  { 9, MMIO_CONFIG_GPIO9,               0, 0},                /* GPIO9 Chip Select Micro SD Card                      */
  {10, MMIO_CONFIG_CAN_TX,              0, 0},                /* CAN Interface Transmit                               */
  {11, MMIO_CONFIG_CAN_RX,              0, 0},                /* CAN Interface Received                               */
  {12, MMIO_CONFIG_PIO0,                0, 0},                /* Programmable IO 0, Comm-Status LED0 V30 green        */
  {13, MMIO_CONFIG_PIO1,                0, 0},                /* Programmable IO 1, Comm-Status LED0 V30 red          */
  {14, MMIO_CONFIG_PIO2,                0, 0},                /* Programmable IO 2, Comm-Status LED1 V31 green        */
  {15, MMIO_CONFIG_PIO3,                0, 0},                /* Programmable IO 3, Comm-Status LED1 V31 red          */
  {16, MMIO_CONFIG_PHY0_LED0,           0, 1},                /* Status LEDs 0 of internal PHY0, Ethernet link 0      */
  {17, MMIO_CONFIG_PHY0_LED1,           0, 1},                /* Status LEDs 1 of internal PHY0, Ethernet activity 0  */
  {18, MMIO_CONFIG_PHY1_LED0,           0, 1},                /* Status LEDs 0 of internal PHY1, Ethernet link 0      */
  {19, MMIO_CONFIG_PHY1_LED1,           0, 1},                /* Status LEDs 1 of internal PHY1, Ethernet activity 0  */
  {20, MMIO_CONFIG_UART0_RXD,           0, 0},                /* UART0 Receive Data                                   */
  {21, MMIO_CONFIG_UART0_TXD,           0, 0},                /* UART0 Transmit Data                                  */
  {22, MMIO_CONFIG_UART0_CTS,           0, 0},                /* UART0 Clear To Send                                  */
  {23, MMIO_CONFIG_UART0_RTS,           0, 0},                /* UART0 Request To Send                                */
  {24, MMIO_CONFIG_PIO,                 0, 0},                /* Unused                                               */
  {25, MMIO_CONFIG_PIO,                 0, 0},                /* Unused                                               */
  {26, MMIO_CONFIG_PIO,                 0, 0},                /* Unused                                               */
  {27, MMIO_CONFIG_PIO,                 0, 0},                /* Unused                                               */
  {28, MMIO_CONFIG_PIO,                 0, 0},                /* Unused                                               */
  {29, MMIO_CONFIG_PIO,                 0, 0},                /* Unused                                               */
  {30, MMIO_CONFIG_PIO,                 0, 0},                /* Unused                                               */
  {31, MMIO_CONFIG_PIO,                 0, 0},                /* Unused                                               */
  {32, MMIO_CONFIG_PIO,                 0, 0},                /* Unused                                               */
  {33, MMIO_CONFIG_PIO,                 0, 0},                /* Unused                                               */
  {34, MMIO_CONFIG_PIO,                 0, 0},                /* Unused                                               */
  {35, MMIO_CONFIG_PIO,                 0, 0},                /* Unused                                               */
  {36, MMIO_CONFIG_PIO,                 0, 0},                /* Unused                                               */
  {37, MMIO_CONFIG_PIO,                 0, 0},                /* Unused                                               */
  {38, MMIO_CONFIG_PIO,                 0, 0},                /* Unused                                               */
  {39, MMIO_CONFIG_PIO,                 0, 0},                /* Unused                                               */
};


/**************************************************************************************
 function:    mmio_config_netx52
 description: Configured the MMIO pad with the Multiplexing Matrix unit inside netX52.

 global:      none
 input:       none

 output:      none
 return:      none
**************************************************************************************/
void mmio_config_netx52( void )
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

} /* mmio_config_netx52 */
