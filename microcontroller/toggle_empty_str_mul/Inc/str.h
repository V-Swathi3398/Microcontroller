/*
 * str.h
 *
 *  Created on: 06-Apr-2023
 *      Author: swathi
 */

#ifndef STR_H_
#define STR_H_

#include <stdint.h>

#define PERIPH_BASE 		(0x40000000UL)
#define AHB1PERIPH_OFFSET	(0x00020000UL)

#define AHB1PERIPH_BASE 	(PERIPH_BASE + AHB1PERIPH_OFFSET)
#define GPIOA_OFFSET			(0x0000UL)

#define GPIOA_BASE			(AHB1PERIPH_BASE + GPIOA_OFFSET)

#define RCC_OFFSET			(0x3800UL)
#define RCC_BASE			(AHB1PERIPH_BASE + RCC_OFFSET)

#define AHB1EN_R_OFFSET		(0x30UL)
#define RCC_AHB1EN_R		(*(volatile unsigned int *)(RCC_BASE + AHB1EN_R_OFFSET))

#define MODE_R_OFFSET		(0X00UL)
#define GPIOA_MODE_R		(*(volatile unsigned int *)(GPIOA_BASE + MODE_R_OFFSET))

#define OD_R_OFFSET			(0X14UL)
#define GPIOA_OD_R			(*(volatile unsigned int *)(GPIOA_BASE + OD_R_OFFSET))

#define GPIOAEN				(1U<<0)

#define PIN5				(1U<<5)
#define LED_PIN				 PIN5

#define __IO volatile

typedef struct
{
  __IO uint32_t MODER;    /*!< GPIO port mode register,               Address offset: 0x00      */
  __IO uint32_t DUMMY[4];
  __IO uint32_t ODR;      /*!< GPIO port output data register,        Address offset: 0x14      */

} GPIO_TypeDef;


typedef struct
{
  __IO uint32_t DUMMY[12];
  __IO uint32_t APB1ENR;       /*!< RCC APB1 peripheral clock enable register,                   Address offset: 0x40 */

} RCC_TypeDef;


#define GPIOA 		((GPIO_typedef*)GPIOA_BASE)

#define RCC			((RCC_typedef*)RCC_BASE)

void led_init(void);
void led_tog(void);

#endif /* STR_H_ */
