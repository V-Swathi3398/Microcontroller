#include "stm32f4xx.h"

void delayMs(int ms);
void USART1_init(void);
void USART1_write(char c);
void USART6_init(void);
char USART6_read(void);

int main(void)
{
    char received_char ;
    char message = 'A';

    RCC->AHB1ENR |= RCC_AHB1ENR_GPIOAEN; // enable GPIOA clock
    GPIOA->MODER |= GPIO_MODER_MODE5_0; // set PA5 to output mode

    USART1_init(); // initialize USART1 for transmitting
    USART6_init(); // initialize USART6 for receiving

    while(1)
    { // loop forever
        received_char = USART6_read(); // read character from serial port


        if (received_char == 'A')
        { // if received character is 'A'
            GPIOA->ODR |= 0x00000030; /* turn on LED */ delayMs(500);
                        GPIOA->ODR &= ~0x00000020; /* turn off LED */
            USART1_write(message); // send message over serial port
        }
    }
}

/* Initialize USART1 for transmitting data */
void USART1_init(void)
{
    RCC->APB2ENR |= RCC_APB2ENR_USART1EN; // enable USART1 clock

    // Configure PA9 as alternate function mode for USART TX
    GPIOA->MODER &= ~(GPIO_MODER_MODE9_0 | GPIO_MODER_MODE9_1); // clear bits to input mode
    GPIOA->MODER |= GPIO_MODER_MODE9_1; // set to alternate function mode
    GPIOA->AFR[1] |= (7 << ((9 - 8) * 4)); // AF7 for USART

    // Set baud rate to 115200 @16MHz
    USART1->BRR = 0x008B;

    // Enable transmitter and set data size to 8 bits
    USART1->CR1 |= (USART_CR1_TE | USART_CR1_UE);
    USART1->CR2 &= ~USART_CR2_STOP;
    USART1->CR3 &= ~(USART_CR3_CTSE | USART_CR3_RTSE);
}

/* Initialize USART6 for receiving data */
void USART6_init(void)
{
    RCC->APB2ENR |= RCC_APB2ENR_USART6EN; // enable USART6 clock

    // Configure PA12 as alternate function mode for USART RX
    GPIOA->MODER &= ~(GPIO_MODER_MODE12_0 | GPIO_MODER_MODE12_1); // clear bits to input mode
    GPIOA->MODER |= GPIO_MODER_MODE12_1; // set to alternate function mode
    GPIOA->AFR[1] |= (8 << ((12 - 8) * 4)); // AF8 for USART

    // Set baud rate to 115200 @16MHz
    USART6->BRR = 0x008B;

    // Enable receiver and set data size to 8 bits
    USART6->CR1 |= (USART_CR1_RE | USART_CR1_RXNEIE | USART_CR1_UE);
    USART6->CR2 &= ~USART_CR2_STOP;
    USART6->CR3 &= ~(USART_CR3_CTSE | USART_CR3_RTSE);

    //NVIC_EnableIRQ(USART6_IRQn); // enable interrupt for USART6
}

/* Write a character to the serial port */
void USART1_write(char c) {
	while (!(USART1->SR & USART_SR_TXE)) {} // wait until transmit buffer is empty
	USART1->DR = c; // load the data into the data register
}

/* Read a character from the serial port */
char USART6_read(void) {
	while (!(USART6->SR & USART_SR_RXNE)) {} // wait until data is available
	return USART6->DR; // read the received data
}

/* Delay for a specified number of milliseconds */
void delayMs(int ms) {
	for (volatile int i = 0; i < ms * 1600; ++i) {} // delay for ms milliseconds at 16MHz
}
