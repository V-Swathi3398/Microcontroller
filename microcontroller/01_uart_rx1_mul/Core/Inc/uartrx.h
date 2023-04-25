/*
 * uartrx.h
 *
 *  Created on: Apr 11, 2023
 *      Author: swathi
 */

#ifndef INC_UARTRX_H_
#define INC_UARTRX_H_

#include"stm32f4xx.h"

void USART2_init(void);
char USART2_read(void);
void LED_blink(int value);
void delayMs(int);

void USART2_init (void);
void LED_blink(int value);


#endif /* INC_UARTRX_H_ */
