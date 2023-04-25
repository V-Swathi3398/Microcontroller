#include "stm32f4xx.h"
#include <stdint.h>
#include <string.h>

#define    GPIOAEN     (1U<<0)
#define    PA9MOD      (7U<<4)
#define    PA9AF       (7U<<4)
#define    APB2EN      (1U<<17)
#define    USART1_TX    (1U<<3)
#define    USART1EN     (1U<<13)
#define    SR_TXE       (1U<<7)

#define SYS_FREQ		16000000
#define APB2_CLK		SYS_FREQ

#define UART_BAUDRATE	115200

volatile uint32_t msTicks = 0; // Variable to store SysTick ticks

void uart1_init(void);
void uart1_write(const char* str);

static void uart_set_baudrate(USART_TypeDef *USARTx, uint32_t PeriphClk,  uint32_t BaudRate);
static uint16_t compute_uart_bd(uint32_t PeriphClk, uint32_t BaudRate);

void SysTick_Handler(void)
{
	msTicks++; // Increment msTicks variable on every SysTick interrupt
}

void Delay_ms(uint32_t ms)
{
	uint32_t startTicks = msTicks;
	while ((msTicks - startTicks) < ms) {} // Wait until desired delay is achieved
}

int main()
{
	SystemCoreClockUpdate();
	SysTick_Config(SystemCoreClock / 1000); // Configure SysTick for 1ms interval
	uart1_init();
	while(1)
	{
		uart1_write("hello world\r\n");
		Delay_ms(500); // Delay using custom Delay_ms function
	}
	return 0;
}

void uart1_init(void)
{

	/*****Configure uart gpio pin******/
	/*Enable clock access to gpioa */
	RCC->AHB1ENR |= GPIOAEN;

	/*Set PA9 mode to alternate function mode*/
	GPIOA->MODER  |= PA9MOD;

	/*Set PA9 alternate function type to UART_TX (AF07)*/
	GPIOA->AFR[1] |= PA9AF;

	/*****Configure uart module ******/
	/*Enable clock access to uart1 */
	RCC->APB2ENR |= APB2EN;

	/*Configure baudrate*/
	uart_set_baudrate(USART1,APB2_CLK,UART_BAUDRATE);

	/*Configure the transfer direction*/
	USART1->CR1 = USART1_TX;

	/*Enable uart module*/
	USART1->CR1 |= USART1EN;
}

static void uart_set_baudrate(USART_TypeDef *USARTx, uint32_t PeriphClk, uint32_t BaudRate)
{
	USARTx->BRR =  compute_uart_bd(PeriphClk,BaudRate);
}

static uint16_t compute_uart_bd(uint32_t PeriphClk, uint32_t BaudRate)
{
	return ((PeriphClk + (BaudRate/2U))/BaudRate);
}

void uart1_write(const char* str)
{
	int len = strlen(str);
	for (int i = 0; i < len; i++) {
		/*Make sure the transmit data register is empty*/
		while(!(USART1->SR & SR_TXE)){}

		/*Write to transmit data register*/
		USART1->DR = str[i];
	}
}
