#include "io_headers/lpc13xx.h"
#include "io_headers/lpc13xx_stdio.h"

int main(void) {
  LPC_GPIO1->DIR |= (1 << 3);
  // ldr	r2, [pc, #68] : r2 = 0x40012000
  LPC_GPIO1->DATA |= (1 << 2);
  // orr	r3, r3, #4 : r3 = 0x04
  // str	r3, [r2] : stores with immediate offset 0x40012000 + 0x04

  char *data;
  tochar(LPC_GPIO1->DATA, data);

  print_uart0("LPC_GPIO1->DATA = ");
  print_uart0(data);
  print_uart0("\n");

  return 0;
}
