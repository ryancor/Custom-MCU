#include <stdint.h>

typedef enum {
  GPIO_PIN_RESET = 0,
  GPIO_PIN_SET
} GPIO_PinState;

static void HAL_GPIO_Init(GPIO_TypeDef *GPIOx, GPIO_InitTypeDef *GPIO_Init) {
  uint32_t position = 0x00;
  uint32_t iocurrent = 0x00;
  uint32_t temp = 0x00;

  while (((GPIO_Init->Pin) >> position) != GPIO_PIN_RESET) {
    /* Get current io position */
    iocurrent = (GPIO_Init->Pin) & (1U << position);

    if(iocurrent) {
      if((GPIO_Init->Mode == GPIO_MODE_AF_PP) || (GPIO_Init->Mode == GPIO_MODE_AF_OD)) {
        /* Configure Alternate function mapped with the current IO */
        temp = GPIOx->AFR[position >> 3];
        temp &= ~((uint32_t)0xF << ((uint32_t)(position & (uint32_t)0x07) * 4)) ;
        temp |= ((uint32_t)(GPIO_Init->Alternate) << (((uint32_t)position & (uint32_t)0x07) * 4));
        GPIOx->AFR[position >> 3] = temp;
      }
    }
    /* Configure IO Direction mode (Input, Output, Alternate or Analog) */
    temp = GPIOx->MODER;
    temp &= ~(GPIO_MODE_INPUT << (position * 2));
    temp |= ((GPIO_Init->Mode & GPIO_MODE_ANALOG) << (position * 2));
    GPIOx->MODER = temp;

    position++;
  }
}

GPIO_PinState HAL_GPIO_ReadPin(GPIO_TypeDef* GPIOx, uint16_t GPIO_Pin) {
  GPIO_PinState bitstatus;

  if((GPIOx->IDR & GPIO_Pin) != (uint32_t)GPIO_PIN_RESET) {
    bitstatus = GPIO_PIN_SET;
  }
  else {
    bitstatus = GPIO_PIN_RESET;
  }
  return bitstatus;
}

void HAL_GPIO_WritePin(GPIO_TypeDef* GPIOx, uint16_t GPIO_Pin, GPIO_PinState PinState) {
  if(PinState != GPIO_PIN_RESET) {
    GPIOx->BSRR = (uint32_t)GPIO_Pin;
  }
  else
  {
    GPIOx->BRR = (uint32_t)GPIO_Pin;
  }
}

void HAL_Setup_Pin(GPIO_TypeDef* GPIOx, uint16_t GPIO_Pin) {
  GPIO_InitTypeDef gpioInitStructure;

  gpioInitStructure.Pin = GPIO_Pin;
  gpioInitStructure.Mode = GPIO_MODE_OUTPUT_PP;
  gpioInitStructure.Pull = GPIO_MODE_AF_PP;
  gpioInitStructure.Speed = GPIO_MODE_SPEED_HIGH;
  HAL_GPIO_Init(GPIOx, &gpioInitStructure);
}
