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

void delay(uint32_t time) {
  for(int i = 0; i < time*100; i++);
}

int strcmp_s(const char* tmp1, const char* tmp2) {
  while(*tmp1 && *tmp2) {
    if(*tmp1 == *tmp2) {
      tmp1++;
      tmp2++;
    } else {
      if(*tmp1 < *tmp2) {
        return -1;
      } else {
        return 1;
      }
    }
  }
  return 0; // strings are the same
}
