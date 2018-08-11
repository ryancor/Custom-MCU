volatile unsigned int * const UART0DR = (unsigned int *)0x101f1000;

void print_uart0(const char *s) {
  // Loop until end of string
  while(*s != '\0') {
    *UART0DR = (unsigned int)(*s); // Transmit char
    s++; // Next char
  }
}

char *tochar(int i, char *p) {
  if (i / 10 == 0) {
    // No more digits.
    *p++ = i + '0';
    *p = '\0';
    return p;
  }

  p = tochar(i / 10, p);
  *p++ = i % 10 + '0';
  *p = '\0';

  return p;
}
