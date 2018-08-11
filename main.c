#include "io_headers/lpc13xx.h"
#include "io_headers/lpc13xx_stdio.h"

int main(void) {
  LPC_GPIO1->DATA |= (1 << 2);

  char *data;
  tochar(LPC_GPIO1->DATA, data);

  print_uart0("LPC_GPIO1->DATA = ");
  print_uart0(data);
  print_uart0("\n");

  return 0;
}
