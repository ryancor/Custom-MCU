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
} LPC_TypeDef;

typedef struct {
  __IO uint32_t MODER;        /*!< GPIO port mode register,  Address offset: 0x00 */
  __IO uint16_t OTYPER;       /*!< GPIO port output type register, Address offset: 0x04 */
  uint16_t RESERVED0;         /*!< Reserved,   0x06 */
  __IO uint32_t OSPEEDR;      /*!< GPIO port output speed register, Address offset: 0x08 */
  __IO uint32_t PUPDR;        /*!< GPIO port pull-up/pull-down register, Address offset: 0x0C */
  __IO uint16_t IDR;          /*!< GPIO port input data register, Address offset: 0x10 */
  uint16_t RESERVED1;         /*!< Reserved, 0x12 */
  __IO uint16_t ODR;          /*!< GPIO port output data register, Address offset: 0x14 */
  uint16_t RESERVED2;         /*!< Reserved, 0x16 */
  __IO uint32_t BSRR;         /*!< GPIO port bit set/reset registerBSRR, Address offset: 0x18 */
  __IO uint32_t LCKR;         /*!< GPIO port configuration lock register, Address offset: 0x1C */
  __IO uint32_t AFR[2];       /*!< GPIO alternate function low register,  Address offset: 0x20-0x24 */
  __IO uint16_t BRR;          /*!< GPIO bit reset register, Address offset: 0x28 */
  uint16_t RESERVED3;         /*!< Reserved,  0x2A */
} GPIO_TypeDef;

typedef struct {
  uint32_t Pin;
  uint32_t Mode;
  uint32_t Speed;
  uint32_t OType;
  uint32_t PuPd;
  uint32_t Pull;
  uint32_t Alternate;
} GPIO_InitTypeDef;

#define PERIPH_BASE                       (0x40000000UL)
#define APB2PERIPH_BASE                   (PERIPH_BASE + 0x00010000)

#define GPIOA_BASE                             (APB2PERIPH_BASE + 0x00000000)
#define GPIOB_BASE                             (APB2PERIPH_BASE + 0x00000400)
#define GPIOC_BASE                             (APB2PERIPH_BASE + 0x00000800)
#define GPIOD_BASE                             (APB2PERIPH_BASE + 0x00000C00)
#define GPIOF_BASE                             (APB2PERIPH_BASE + 0x00001400)
#define LPC_BASE                               (APB2PERIPH_BASE + 0x00002800)

#define GPIOA                                  ((GPIO_TypeDef *) GPIOA_BASE)
#define GPIOB                                  ((GPIO_TypeDef *) GPIOB_BASE)
#define GPIOC                                  ((GPIO_TypeDef *) GPIOC_BASE)
#define GPIOD                                  ((GPIO_TypeDef *) GPIOD_BASE)
#define GPIOF                                  ((GPIO_TypeDef *) GPIOF_BASE)
#define GPIOE                                  ((LPC_TypeDef *)  LPC_BASE)

#define GPIO_MODE_INPUT                        ((uint32_t)0x00000000)   /*!< Input Floating Mode                   */
#define GPIO_MODE_OUTPUT_PP                    ((uint32_t)0x00000001)   /*!< Output Push Pull Mode                 */
#define GPIO_MODE_OUTPUT_OD                    ((uint32_t)0x00000011)   /*!< Output Open Drain Mode                */
#define GPIO_MODE_AF_PP                        ((uint32_t)    1 << 1)   /*!< Alternate Function Push Pull Mode     */
#define GPIO_MODE_AF_OD                        ((uint32_t)0x00000012)   /*!< Alternate Function Open Drain Mode    */
#define GPIO_MODE_ANALOG                       ((uint32_t)0x00000003)   /*!< Analog Mode  */
#define GPIO_MODE_ANALOG_ADC_CONTROL           ((uint32_t)0x0000000B)   /*!< Analog Mode for ADC conversion */
#define GPIO_MODE_IT_RISING                    ((uint32_t)0x10110000)   /*!< External Interrupt Mode with Rising edge trigger detection          */
#define GPIO_MODE_IT_FALLING                   ((uint32_t)0x10210000)   /*!< External Interrupt Mode with Falling edge trigger detection         */
#define GPIO_MODE_IT_RISING_FALLING            ((uint32_t)0x10310000)   /*!< External Interrupt Mode with Rising/Falling edge trigger detection  */
#define GPIO_MODE_EVT_RISING                   ((uint32_t)0x10120000)   /*!< External Event Mode with Rising edge trigger detection               */
#define GPIO_MODE_EVT_FALLING                  ((uint32_t)0x10220000)   /*!< External Event Mode with Falling edge trigger detection              */
#define GPIO_MODE_EVT_RISING_FALLING           ((uint32_t)0x10320000)   /*!< External Event Mode with Rising/Falling edge trigger detection       */
#define GPIO_MODE_SPEED_HIGH                   ((uint32_t)0x10470400)

#define Pin_SCK_13                             ((uint16_t)0x0100)  /* Pin 13 selected */
#define Pin_MISO_12                            ((uint32_t)0x0001)  /* Pin 12 selected */
