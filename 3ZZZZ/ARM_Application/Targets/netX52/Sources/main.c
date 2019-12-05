#include "Application.h"


void mmio_config_netx52(void);    /* MMIO configuration declaration */


int main(void)
{
  /* Configure MMIO pin multiplexer */
  mmio_config_netx52();
  
  return Main_Application();
}
