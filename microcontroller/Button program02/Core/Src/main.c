#include "stm32f4xx.h"

int main(void) {
    RCC->AHB1ENR |= RCC_AHB1ENR_GPIOCEN; /* enable GPIOC clock */
    RCC->AHB1ENR |= RCC_AHB1ENR_GPIOAEN; /* enable GPIOA clock */

    GPIOA->MODER &= ~GPIO_MODER_MODE5; /* clear pin mode */
    GPIOA->MODER |= GPIO_MODER_MODE5_0; /* set pin to output mode */

    GPIOC->MODER &= ~GPIO_MODER_MODE13; /* clear pin mode to input mode */
    GPIOC->PUPDR |= GPIO_PUPDR_PUPD13_0; /* enable pull-up on PC13 */

    int button_pressed = 0;

    while(1) {
        if ((GPIOC->IDR & GPIO_IDR_ID13) == 0) { /* if PC13 is low (button pressed) */
            button_pressed = 1 - button_pressed; /* toggle button_pressed */
            while ((GPIOC->IDR & GPIO_IDR_ID13) == 0); /* wait for button release */

            if (button_pressed) { /* if button was just pressed */
                GPIOA->BSRR = GPIO_BSRR_BS5; /* turn on green LED */
                delay(1000000); /* delay for 1 second */
                GPIOA->BSRR = GPIO_BSRR_BR5; /* turn off green LED */
            } else { /* if button was pressed before */
            	for(int i=0; i<4; i++){
                GPIOA->BSRR = GPIO_BSRR_BS5; /* turn on green LED */
                delay(500000); /* delay for 0.5 seconds */
                GPIOA->BSRR = GPIO_BSRR_BR5; /* turn off green LED */
                delay(500000); /* delay for another 0.5 seconds */
            	}
            }
        }
    }
}

void delay(int n) {
    for (int i = 0; i < n; i++);
}
