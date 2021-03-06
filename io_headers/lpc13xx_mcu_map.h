void mcu_layout() {
  print_uart0("                              +-----+\n");
  print_uart0("+----[PWR]--------------------| USB |--+\n");
  print_uart0("|                             +-----+  |\n");
  print_uart0("|          GND/RST2 [ ][ ]             |\n");
  print_uart0("|        MOSI2/SCK2 [ ][ ]   A5/SCL[ ] |\n");
  print_uart0("|                              AREF[ ] |\n");
  print_uart0("|                               GND[ ] |\n");
  print_uart0("| [ ]N/C                     SCK/13[ ] |\n");
  print_uart0("| [ ]v.ref                  MISO/12[ ] |\n");
  print_uart0("| [ ]RST                    MOSI/11[ ] |\n");
  print_uart0("| [ ]3V3      +---+              10[ ] |\n");
  print_uart0("| [ ]5v       | R |               9[ ] |\n");
  print_uart0("| [ ]GND      | I |               8[ ] |\n");
  print_uart0("| [ ]GND      | N |                    |\n");
  print_uart0("| [ ]Vin      | G |               7[ ] |\n");
  print_uart0("|             | U |               6[ ] |\n");
  print_uart0("| [ ]A0       | I |               5[ ] |\n");
  print_uart0("| [ ]A1       | N |               4[ ] |\n");
  print_uart0("| [ ]A2       | 0 |          INT1/3[ ] |\n");
  print_uart0("| [ ]A3       +---+          INT0/2[ ] |\n");
  print_uart0("|                                      |\n");
  print_uart0("| [ ]A4/SDA    RST SCK MISO    TX>1[ ] |\n");
  print_uart0("| [ ]A5/SCL    [ ] [ ] [ ]     RX<0[ ] |\n");
  print_uart0("|              [ ] [ ] [ ]             |\n");
  print_uart0("|               |   |   |             /\n");
  print_uart0("|    LPC13     GND MOSI 5V   --------- \n");
  print_uart0(" \\                         /          \n");
  print_uart0("  ------------------------- \n\n");
}

void mcu_sck_13_high() {
  print_uart0("                              +-----+\n");
  print_uart0("+----[PWR]--------------------| USB |--+\n");
  print_uart0("|                             +-----+  |\n");
  print_uart0("|          GND/RST2 [ ][ ]             |\n");
  print_uart0("|        MOSI2/SCK2 [ ][ ]   A5/SCL[ ] |\n");
  print_uart0("|                              AREF[ ] |\n");
  print_uart0("|                               GND[ ] |\n");
  print_uart0("| [ ]N/C                     SCK/13[H] |\n");
  print_uart0("| [ ]v.ref                  MISO/12[ ] |\n");
  print_uart0("| [ ]RST                    MOSI/11[ ] |\n");
  print_uart0("|               ....                   |\n");
  print_uart0("|                                      |\n");
  print_uart0("| [ ]A4/SDA    RST SCK MISO    TX>1[ ] |\n");
  print_uart0("| [ ]A5/SCL    [ ] [ ] [ ]     RX<0[ ] |\n");
  print_uart0("|              [ ] [ ] [ ]             |\n");
  print_uart0("|               |   |   |             /\n");
  print_uart0("|    LPC13     GND MOSI 5V   --------- \n");
  print_uart0(" \\                         /          \n");
  print_uart0("  ------------------------- \n\n");
}
