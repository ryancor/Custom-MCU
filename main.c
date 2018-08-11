#include "io_headers/lpc13xx.h"
#include "io_headers/lpc13xx_stdio.h"

int main(void) {
  GPIO1_DIR->DIR |= (1 << 2); // set pin to output
  GPIO1_DATA->DATA |= (1 << 1); // set to high

  char *data;
  tochar(GPIO1_DATA->DATA, data);

  print_uart0("LPC_GPIO1->DATA = ");
  print_uart0(data);
  print_uart0("\n");

  return 0;
}
