/******************************************************************************

  Copyright (C) 2010 [Hilscher Gesellschaft für Systemautomation mbH]

  This program can be used by everyone according to the netX Open Source
  Software license. The license agreement can be downloaded from
  http://www.industrialNETworX.com

*******************************************************************************

  Last Modification:
    @version $Id: mmio_config.h 1538 2013-07-01 10:35:58Z MichaelT $

  Description:
    netX MMIO definitions

  Changes:
    Date        Author        Description
  ---------------------------------------------------------------------------
    2010-03-24  NC            File created.

******************************************************************************/


#ifndef __MMIO_CONFIG__H
#define __MMIO_CONFIG__H

#define MMIO_CONFIG_XM0_IO0            0x00
#define MMIO_CONFIG_XM0_IO1            0x01
#define MMIO_CONFIG_XM0_IO2            0x02
#define MMIO_CONFIG_XM0_IO3            0x03
#define MMIO_CONFIG_XM0_IO4            0x04
#define MMIO_CONFIG_XM0_IO5            0x05
#define MMIO_CONFIG_XM0_RX             0x06
#define MMIO_CONFIG_GPIO0              0x07
#define MMIO_CONFIG_GPIO1              0x08
#define MMIO_CONFIG_GPIO2              0x09
#define MMIO_CONFIG_GPIO3              0x0A
#define MMIO_CONFIG_GPIO4              0x0B
#define MMIO_CONFIG_GPIO5              0x0C
#define MMIO_CONFIG_GPIO6              0x0D
#define MMIO_CONFIG_GPIO7              0x0E
#define MMIO_CONFIG_PHY0_LED0          0x0F
#define MMIO_CONFIG_PHY0_LED1          0x10
#define MMIO_CONFIG_PHY0_LED2          0x11
#define MMIO_CONFIG_PHY0_LED3          0x12
#define MMIO_CONFIG_SPI0_CS1N          0x13
#define MMIO_CONFIG_SPI0_CS2N          0x14
#define MMIO_CONFIG_SPI1_CLK           0x15
#define MMIO_CONFIG_SPI1_CS0N          0x16
#define MMIO_CONFIG_SPI1_CS1N          0x17
#define MMIO_CONFIG_SPI1_CS2N          0x18
#define MMIO_CONFIG_SPI1_MISO          0x19
#define MMIO_CONFIG_SPI1_MOSI          0x1A
#define MMIO_CONFIG_I2C_SCL            0x1B
#define MMIO_CONFIG_I2C_SDA            0x1C
#define MMIO_CONFIG_UART0_CTSn         0x1D
#define MMIO_CONFIG_UART0_RTSn         0x1E
#define MMIO_CONFIG_UART0_RXD          0x1F
#define MMIO_CONFIG_UART0_TXD          0x20
#define MMIO_CONFIG_UART1_CTSn         0x21
#define MMIO_CONFIG_UART1_RTSn         0x22
#define MMIO_CONFIG_UART1_RXD          0x23
#define MMIO_CONFIG_UART1_TXD          0x24
#define MMIO_CONFIG_PWM_FAILURE_N      0x25
#define MMIO_CONFIG_POS_ENC0_A         0x26
#define MMIO_CONFIG_POS_ENC0_B         0x27
#define MMIO_CONFIG_POS_ENC0_N         0x28
#define MMIO_CONFIG_POS_ENC1_A         0x29
#define MMIO_CONFIG_POS_ENC1_B         0x2A
#define MMIO_CONFIG_POS_ENC1_N         0x2B
#define MMIO_CONFIG_POS_MP0            0x2C
#define MMIO_CONFIG_POS_MP1            0x2D
#define MMIO_CONFIG_IO_LINK0_IN        0x2E
#define MMIO_CONFIG_IO_LINK0_OUT       0x2F
#define MMIO_CONFIG_IO_LINK0_OE        0x30
#define MMIO_CONFIG_IO_LINK1_IN        0x31
#define MMIO_CONFIG_IO_LINK1_OUT       0x32
#define MMIO_CONFIG_IO_LINK1_OE        0x33
#define MMIO_CONFIG_IO_LINK2_IN        0x34
#define MMIO_CONFIG_IO_LINK2_OUT       0x35
#define MMIO_CONFIG_IO_LINK2_OE        0x36
#define MMIO_CONFIG_IO_LINK3_IN        0x37
#define MMIO_CONFIG_IO_LINK3_OUT       0x38
#define MMIO_CONFIG_IO_LINK3_OE        0x39

#define MMIO_CONFIG_PIO                0x3F

typedef struct MMIO_CONFIG_Ttag
{
  unsigned char bMmio;
  unsigned char bFunction;
  unsigned char fInvertIn;
  unsigned char fInvertOut;
} MMIO_CONFIG_T;

#endif /* __MMIO_CONFIG__H */
