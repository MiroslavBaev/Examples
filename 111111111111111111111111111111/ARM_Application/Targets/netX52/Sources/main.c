#include "Application.h"
#include "xPIC_Loader.h"

void mmio_config_netx52(void);    /* MMIO configuration declaration */


int main(void)
{
  /* Init xPIC */
  xPIC_start();

  /* Configure MMIO pin multiplexer */
  mmio_config_netx52();
  
  return Main_Application();
}
