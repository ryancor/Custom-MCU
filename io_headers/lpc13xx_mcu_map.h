void mcu_layout() {
  print_uart0("                              +-----+\n");
  print_uart0("+----[PWR]--------------------| USB |--+\n");
  print_uart0("|                             +-----+  |\n");
  print_uart0("|          GND/RST2 [ ][ ]             |\n");
  print_uart0("|        MOSI2/SCK2 [ ][ ]   A5/SCL[ ] |\n");
  print_uart0("|                                      |\n");
  print_uart0("|                                      |\n");
  print_uart0("|                                      |\n");
  print_uart0("|                                      |\n");
  print_uart0("|                                      |\n");
  print_uart0("|                                      |\n");
  print_uart0("|                                      |\n");
  print_uart0("|                                      |\n");
  print_uart0("|                                      |\n");
  print_uart0("|                                      |\n");
  print_uart0("|                                      |\n");
  print_uart0("|                                      |\n");
  print_uart0("|                                      |\n");
  print_uart0("|                                     /\n");
  print_uart0("|    LPC13      GND MOSI 5V  --------- \n");
  print_uart0(" \\                         /          \n");
  print_uart0("  ------------------------- \n\n");
}
