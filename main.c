/**
  ******************************************************************************
  * @file    Project/Template/main.c
  * @author  MCD Application Team
  * @version V1.3.0
  * @date    07/14/2010
  * @brief   Main program body
  ******************************************************************************
  * @copy
  *
  * THE PRESENT FIRMWARE WHICH IS FOR GUIDANCE ONLY AIMS AT PROVIDING CUSTOMERS
  * WITH CODING INFORMATION REGARDIN THEIR PRODUCTS IN ORDER FOR THEM TO SAVE
  * TIME. AS A RESULT, STMICROELECTRONICS SHALL NOT BE HELD LIABLE FOR ANY
  * DIRECT, INDIRECT OR CONSEQUENTIAL DAMAGES WITH RESPECT TO ANY CLAIMS ARISING
  * FROM THE CONTENT OF SUCH FIRMWARE AND/OR THE USE MADE BY CUSTOMERS OF THE
  * CODING INFORMATION CONTAINED HEREIN IN CONNECTION WITH THEIR PRODUCTS.
  *
  * <h2><center>&copy; COPYRIGHT 2010 STMicroelectronics</center></h2>
  */ 
	
/* Includes ------------------------------------------------------------------*/
#include "stm8l15x.h"
#include "stm8l15x_clk.h"
#include "stm8l15x_i2c.h"
#include "stm8l15x_gpio.h"
#include "stm8l15x_clk.h"
#include "pressure.h"

@near int32_t pres32 = 0;
@near int32_t temp32 = 0;
@near int32_t pres32_2 = 0;
@near int32_t temp32_2 = 0;

void main(void)
{
	uint8_t ret = 0;

	// system_clock 
  CLK_SYSCLKDivConfig(CLK_SYSCLKDiv_1);
	
	// I2C init
	i2c_init();
			
	// Open enableInterrupts
  enableInterrupts();
	
	// Init bmp280 (two sensor)
  init_press(&bmp, BMP280_I2C_ADDR_PRIM);
	delay_ms(50);
	init_press(&bmp2, BMP280_I2C_ADDR_SEC);
	
	while(1) {
		delay_ms(1000);
		fetch_press(&bmp, &pres32, &temp32);
		delay_ms(1000);
		fetch_press(&bmp2, &pres32, &temp32);
	}
}
