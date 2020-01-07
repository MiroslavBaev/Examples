/******************************************************************************

  Copyright (C) 2010 [Hilscher Gesellschaft für Systemautomation mbH]

  This program can be used by everyone according to the netX Open Source
  Software license. The license agreement can be downloaded from
  http://www.industrialNETworX.com

*******************************************************************************

  Last Modification:
    @version $Id: ExtBus.h 333 2010-04-26 09:32:25Z Volker $

  Description:
    netX EXT definitions

  Changes:
    Date        Author        Description
  ---------------------------------------------------------------------------
    2010-03-24  NC            File created.

******************************************************************************/


#ifndef _EXT_H
#define _EXT_H


/**************************************************************************************/

// ---------------------------------------------------------------------
// Register exp_bus_reg
// => 
// => Mode: 
// ---------------------------------------------------------------------

#define REL_NETX_EXT_CFG_CS0 0x00000010U

#define NETX_EXT_CFG_CS0     0x00103610U /* Extension Bus Configuration Chip Select 0 */
#define NETX_EXT_CFG_CS1     0x00103614U /* Extension Bus Configuration Chip Select 1 */
#define NETX_EXT_CFG_CS2     0x00103618U /* Extension Bus Configuration Chip Select 2 */
#define NETX_EXT_CFG_CS3     0x0010361cU /* Extension Bus Configuration Chip Select 3 */


/**************************************************************************************/

#endif /* _EXT_H */
