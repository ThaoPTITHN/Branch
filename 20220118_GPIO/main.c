#include "stm32f10x.h"

void delay(int time)
{
	while(time){
	  SysTick -> LOAD = 72000 - 1;
	  SysTick -> VAL  = 0;
	  SysTick -> CTRL = 5;
	  while(!(SysTick -> CTRL & ( 1 << 16))){
		}
	  --time;
	}
}

void GPIOC_Configure()
{
	RCC -> APB2ENR |= 0x10;
	GPIOC -> CRH   &= 0xFF0FFFFF;
	GPIOC -> CRH   |= 0x00300000;
}
void GPIOA_Configure()
{
	RCC -> APB2ENR |= 0x04;
	GPIOA -> CRL   &= 0xFF0FFFFF;
	GPIOA -> CRL   |= 0x00300000;
}
int main()
{
	GPIOC_Configure();
	GPIOA_Configure();
	while(1){
		GPIOA -> ODR |= 0x0020;
		delay(1000);
		GPIOA -> ODR &=~(0x0020);
		delay(1000);
	}
}