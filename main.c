#include "io_headers/lpc13xx.h"
#include "io_headers/lpc13xx_stdio.h"
#include "io_headers/lpc13xx_mcu_map.h"
#include "stdio.h"

int main(void) {
  GPIO1_DIR->DIR |= (1 << 2); // set pin to output
  GPIO1_DATA->DATA |= (1 << 1); // set to high

  char *data;
  tochar(GPIO1_DATA->DATA, data);

  print_uart0("LPC_GPIO1->DATA = ");
  print_uart0(data);
  print_uart0("\n");

  char* user_input;

  while(1) {
    mcu_layout();

    print_uart0("Enter Command-> ");
    gets(user_input);

    if(strcmp_s(data, "1") == 0) {
      print_uart0("LED On\n");
    } else {
      print_uart0("LED Off\n");
    }
    delay(990000);
  }
  return 0;
}
