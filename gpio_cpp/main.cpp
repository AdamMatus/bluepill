#include <stm32f1xx.h>

const constexpr auto LED_PIN = 13;

typedef struct {int test;} te; 
te p;

template <te& p>
struct niewiem{
  int pies()
  {
    return p.test;
  }
};

niewiem<p> cos; 

int main()
{
  volatile int i = cos.pies();
  //PC13 clock
  RCC->APB2ENR |= RCC_APB2ENR_IOPCEN;
  //clear PC13
  GPIOC->CRH &= ~(GPIO_CRH_MODE13 + GPIO_CRH_CNF13);
  //push-pull and 10 MHz output
  GPIOC->CRH |= ~(GPIO_CRH_MODE13_0 + GPIO_CRH_CNF13_1); 

  const auto set_bit = [](auto &reg, const auto bit){
    reg ^= 0b1 << bit;
  };

  while(true)
  {
    set_bit(GPIOC->ODR, LED_PIN);
    for(volatile uint32_t i=100000;i>0;--i);
  }
}
