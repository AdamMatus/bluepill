#include <stm32f1xx.h>

int main()
{
  //PC13 clock
  RCC->APB2ENR |= RCC_APB2ENR_IOPCEN;
  //clear PC13
  GPIOC->CRH &= ~(GPIO_CRH_MODE13 + GPIO_CRH_CNF13);
  //push-pull and 10 MHz output
  GPIOC->CRH |= ~(GPIO_CRH_MODE13_0 + GPIO_CRH_CNF13_1); 
  for(;;)
  {
    GPIOC->BSRR = GPIO_BSRR_BS13;
    for(uint32_t i=100000;i>0;--i);
    GPIOC->BSRR = GPIO_BSRR_BR13;
    for(uint32_t i=100000;i>0;--i);
  }

  return 0;
}
