/*
 * main.c
 *
 * author: Furkan Cayci
 *
 * description: Blinks 1 on-board LED at roughly 1 second intervals. system 
 *   clock is running from HSI which is 16 Mhz. Delay function is just a simple 
 *   counter so is not accurate and the delay time will change based on the 
 *   optimization flags.
 */

#include "stm32g0xx.h"

#define LEDDELAY    1600000

void delay(volatile uint32_t);

int main(void) {

    /* Enable GPIOC clock */
    RCC->IOPENR |= (1U << 1);

    /* Setup PC6 as output */
    GPIOB->MODER &= ~(3U << 2*4);
    GPIOB->MODER |= (1U << 2*4);

    /* Turn on LED */
    GPIOB->ODR |= (1U << 4);

    while(1) {
        delay(LEDDELAY);
        /* Toggle LED */
        GPIOB->ODR ^= (1U << 4);
    }

    return 0;
}

void delay(volatile uint32_t s) {
    for(; s>0; s--);
}
