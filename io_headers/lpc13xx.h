#include <stdint.h>

#define __IO                volatile

typedef struct {
  __IO uint32_t DATA;
  uint32_t RESERVEDO[4095]; // the same data appears at 4096 locations
                            // in the GPIO address space, and 12 bits
                            // of the address bus can be used for
                            // bit masking

  __IO uint32_t DIR;        // direction set for output, clear for input
  __IO uint32_t IS;         // interrupt sense (1 = interrupt pending)
  __IO uint32_t IBE;        // interrupt on both falling and rising edges
  __IO uint32_t IEV;        // interrupt event register
  __IO uint32_t IE;         // interrupt enable
  __IO uint32_t RIS;        // raw status register
  __IO uint32_t MIS;        // masked interrupt status register
  __IO uint32_t IC;         // interrupt clear (set bit to clear interrupt)
} LPC_GPIO_TypeDef;

#define PERIPH_BASE         (0x40000000UL)
#define APB2PERIPH_BASE     (PERIPH_BASE + 0x00010000)
#define LPC_GPIO1_BASE      (APB2PERIPH_BASE + 0x2000)
#define LPC_GPIO1           ((LPC_GPIO_TypeDef *) LPC_GPIO1_BASE)
