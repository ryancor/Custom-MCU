#include "io_headers/lpc13xx.h"
#include "io_headers/lpc13xx_stdio.h"
#include "io_headers/lpc13xx_mcu_map.h"
#include "io_headers/lpc13xx_gpio.h"
#include "stdio.h"

int main(void) {
  GPIOE->DIR |= GPIO_MODE_OUTPUT_PP; // set pin to output
  GPIOE->DATA = GPIO_PIN_SET; // set to high

  char *data;
  tochar(GPIOE->DATA, data);

  //char* user_input;

  while(1) {
    //print_uart0("Enter Command-> ");
    //gets(user_input);

    HAL_Setup_Pin(GPIOC, Pin_SCK_13);
    GPIOC->MODER |= GPIO_MODE_OUTPUT_PP;
    HAL_GPIO_WritePin(GPIOC, Pin_SCK_13, GPIO_PIN_SET);

    if(HAL_GPIO_ReadPin(GPIOC, Pin_SCK_13) == 0) {
      mcu_layout();
      print_uart0("SCK/13 is LOW\n");
    } else {
      mcu_sck_13_high();
      print_uart0("SCK/13 is HIGH\n");
      data = "1";
    }

    if(strcmp_s(data, "1") == 0) {
      print_uart0("LED On\n");
    } else {
      print_uart0("LED Off\n");
    }
    delay(990000);
  }
  return 0;
}
