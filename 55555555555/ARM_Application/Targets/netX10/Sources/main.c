#include "Application.h"


void mmio_config_netx10(void);    /* MMIO configuration declaration */


int main(void)
{
  /* Configure MMIO pin multiplexer */
  mmio_config_netx10();
  
  return Main_Application();
}
