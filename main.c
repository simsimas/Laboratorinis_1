#include "main.h"

void SystemClock_Config(void);

void delay(int time_cycle)		//Void funkcija sukurianti delay
{
	for(time_cycle; time_cycle>0; time_cycle--);
}

int main(void)
{

  RCC->AHBENR |=RCC_AHBENR_GPIOEEN;		//Įjungiama MCU periferija per RCC registrus
  RCC->AHBENR |=RCC_AHBENR_GPIOAEN;

  GPIOE->MODER |= GPIO_MODER_MODER9_0;		//Nustatomi GPIO registrai LED3 įjungimui
  GPIOE->MODER &= ~GPIO_MODER_MODER9_1;		//Nustatomi GPIO registrai LED3 išjungimui

  GPIOE->MODER |= GPIO_MODER_MODER12_0;		//Nustatomi GPIO registrai LED9 įjungimui
    GPIOE->MODER &= ~GPIO_MODER_MODER12_1;	//Nustatomi GPIO registrai LED9 išjungimui

    GPIOA->MODER &= ~GPIO_MODER_MODER0_0;	//Nustatomi GPIO registrai mygtuko veikimui
      GPIOA->MODER &= ~GPIO_MODER_MODER0_1;


    while(1)
    {
    if((GPIOA->IDR & 0x01)==1)		// if salyga klausianti ar mygtukas nuspaustas
    {
    	GPIOE->BSRR |= GPIO_BSRR_BR_9;		//išjungia LED
    	GPIOE->BSRR |= GPIO_BSRR_BR_12;
    	delay(10);
    }
    else
    {
    	GPIOE->BSRR |= GPIO_BSRR_BR_9;		//Išjungia LED3
    	  GPIOE->BSRR |= GPIO_BSRR_BS_12;	//Įjungia LED9

    	 delay(100000);

    	  GPIOE->BSRR |= GPIO_BSRR_BS_9;	//Įjungia LED9
    	  GPIOE->BSRR |= GPIO_BSRR_BR_12;	//Išjungia LED3

    	 delay(100000);
    }
    }


}

