/**
  ******************************************************************************
  * @file    GPIO/GPIO_Toggle/stm8l15x_it.c
  * @author  MCD Application Team
  * @version V1.3.0
  * @date    07/14/2010
  * @brief   Main Interrupt Service Routines.
  *          This file provides template for all peripherals interrupt service routine.
  ******************************************************************************
  * @copy
  *
  * THE PRESENT FIRMWARE WHICH IS FOR GUIDANCE ONLY AIMS AT PROVIDING CUSTOMERS
  * WITH CODING INFORMATION REGARDING THEIR PRODUCTS IN ORDER FOR THEM TO SAVE
  * TIME. AS A RESULT, STMICROELECTRONICS SHALL NOT BE HELD LIABLE FOR ANY
  * DIRECT, INDIRECT OR CONSEQUENTIAL DAMAGES WITH RESPECT TO ANY CLAIMS ARISING
  * FROM THE CONTENT OF SUCH FIRMWARE AND/OR THE USE MADE BY CUSTOMERS OF THE
  * CODING INFORMATION CONTAINED HEREIN IN CONNECTION WITH THEIR PRODUCTS.
  *
  * <h2><center>&copy; COPYRIGHT 2010 STMicroelectronics</center></h2>
  */

/* Includes ------------------------------------------------------------------*/
#include "stm8l15x_it.h"
#include "stm8l15x_i2c.h"
#include "stm8l15x_gpio.h"
#include "i2c.h"

/** @addtogroup STM8L15x_StdPeriph_Examples
  * @{
  */

/** @addtogroup GPIO_Toggle
  * @{
  */

/* Private typedef -----------------------------------------------------------*/
/* Private define ------------------------------------------------------------*/
/* Private macro -------------------------------------------------------------*/
/* Private variables ---------------------------------------------------------*/
/* Private function prototypes -----------------------------------------------*/
/* Private functions ---------------------------------------------------------*/
/* Public functions ----------------------------------------------------------*/

#ifdef _COSMIC_
/**
  * @brief  Dummy interrupt routine
  * @param  None
  * @retval None
*/
INTERRUPT_HANDLER(NonHandledInterrupt, 0)
{
  /* In order to detect unexpected events during development,
     it is recommended to set a breakpoint on the following instruction.
  */
}
#endif

/**
  * @brief  TRAP interrupt routine
  * @param  None
  * @retval None
*/
INTERRUPT_HANDLER_TRAP(TRAP_IRQHandler)
{
  /* In order to detect unexpected events during development,
     it is recommended to set a breakpoint on the following instruction.
  */
}
/**
  * @brief  FLASH Interrupt routine.
  * @param  None
  * @retval None
  */
INTERRUPT_HANDLER(FLASH_IRQHandler, 1)
{
  /* In order to detect unexpected events during development,
     it is recommended to set a breakpoint on the following instruction.
  */
}
/**
  * @brief  DMA1 channel0 and channel1 Interrupt routine.
  * @param  None
  * @retval None
  */
INTERRUPT_HANDLER(DMA1_CHANNEL0_1_IRQHandler, 2)
{
  /* In order to detect unexpected events during development,
     it is recommended to set a breakpoint on the following instruction.
  */
}
/**
  * @brief  DMA1 channel2 and channel3 Interrupt routine.
  * @param  None
  * @retval None
  */
INTERRUPT_HANDLER(DMA1_CHANNEL2_3_IRQHandler, 3)
{
  /* In order to detect unexpected events during development,
     it is recommended to set a breakpoint on the following instruction.
  */
}
/**
  * @brief  RTC Interrupt routine.
  * @param  None
  * @retval None
  */
INTERRUPT_HANDLER(RTC_IRQHandler, 4)
{
  /* In order to detect unexpected events during development,
     it is recommended to set a breakpoint on the following instruction.
  */
}
/**
  * @brief  External IT PORTE/F and PVD Interrupt routine.
  * @param  None
  * @retval None
  */
INTERRUPT_HANDLER(EXTIE_F_PVD_IRQHandler, 5)
{
  /* In order to detect unexpected events during development,
     it is recommended to set a breakpoint on the following instruction.
  */
}

/**
  * @brief  External IT PORTB Interrupt routine.
  * @param  None
  * @retval None
  */
INTERRUPT_HANDLER(EXTIB_IRQHandler, 6)
{
  /* In order to detect unexpected events during development,
     it is recommended to set a breakpoint on the following instruction.
  */
}

/**
  * @brief  External IT PORTD Interrupt routine.
  * @param  None
  * @retval None
  */
INTERRUPT_HANDLER(EXTID_IRQHandler, 7)
{
  /* In order to detect unexpected events during development,
     it is recommended to set a breakpoint on the following instruction.
  */
}

/**
  * @brief  External IT PIN0 Interrupt routine.
  * @param  None
  * @retval None
  */
INTERRUPT_HANDLER(EXTI0_IRQHandler, 8)
{
  /* In order to detect unexpected events during development,
     it is recommended to set a breakpoint on the following instruction.
  */
}

/**
  * @brief  External IT PIN1 Interrupt routine.
  * @param  None
  * @retval None
  */
INTERRUPT_HANDLER(EXTI1_IRQHandler, 9)
{
  /* In order to detect unexpected events during development,
     it is recommended to set a breakpoint on the following instruction.
  */
}

/**
  * @brief  External IT PIN2 Interrupt routine.
  * @param  None
  * @retval None
  */
INTERRUPT_HANDLER(EXTI2_IRQHandler, 10)
{
  /* In order to detect unexpected events during development,
     it is recommended to set a breakpoint on the following instruction.
  */
}

/**
  * @brief  External IT PIN3 Interrupt routine.
  * @param  None
  * @retval None
  */
INTERRUPT_HANDLER(EXTI3_IRQHandler, 11)
{
  /* In order to detect unexpected events during development,
     it is recommended to set a breakpoint on the following instruction.
  */
}

/**
  * @brief  External IT PIN4 Interrupt routine.
  * @param  None
  * @retval None
  */
INTERRUPT_HANDLER(EXTI4_IRQHandler, 12)
{
  /* In order to detect unexpected events during development,
     it is recommended to set a breakpoint on the following instruction.
  */
}

/**
  * @brief  External IT PIN5 Interrupt routine.
  * @param  None
  * @retval None
  */
INTERRUPT_HANDLER(EXTI5_IRQHandler, 13)
{
  /* In order to detect unexpected events during development,
     it is recommended to set a breakpoint on the following instruction.
  */
}

/**
  * @brief  External IT PIN6 Interrupt routine.
  * @param  None
  * @retval None
  */
INTERRUPT_HANDLER(EXTI6_IRQHandler, 14)
{
  /* In order to detect unexpected events during development,
     it is recommended to set a breakpoint on the following instruction.
  */
}

/**
  * @brief  External IT PIN7 Interrupt routine.
  * @param  None
  * @retval None
  */
INTERRUPT_HANDLER(EXTI7_IRQHandler, 15)
{
  /* In order to detect unexpected events during development,
     it is recommended to set a breakpoint on the following instruction.
  */
}
/**
  * @brief  LCD start of new frame Interrupt routine.
  * @param  None
  * @retval None
  */
INTERRUPT_HANDLER(LCD_IRQHandler, 16)
{
  /* In order to detect unexpected events during development,
     it is recommended to set a breakpoint on the following instruction.
  */
}
/**
  * @brief  CLK switch/CSS/TIM1 break Interrupt routine.
  * @param  None
  * @retval None
  */
INTERRUPT_HANDLER(SWITCH_CSS_BREAK_DAC_IRQHandler, 17)
{
  /* In order to detect unexpected events during development,
     it is recommended to set a breakpoint on the following instruction.
  */
}

/**
  * @brief  ADC1/Comparator Interrupt routine.
  * @param  None
  * @retval None
  */
INTERRUPT_HANDLER(ADC1_COMP_IRQHandler, 18)
{
  /* In order to detect unexpected events during development,
     it is recommended to set a breakpoint on the following instruction.
  */
}

/**
  * @brief  TIM2 Update/Overflow/Trigger/Break Interrupt routine.
  * @param  None
  * @retval None
  */
INTERRUPT_HANDLER(TIM2_UPD_OVF_TRG_BRK_IRQHandler, 19)
{
  /* In order to detect unexpected events during development,
     it is recommended to set a breakpoint on the following instruction.
  */
}

/**
  * @brief  Timer2 Capture/Compare Interrupt routine.
  * @param  None
  * @retval None
  */
INTERRUPT_HANDLER(TIM2_CAP_IRQHandler, 20)
{
  /* In order to detect unexpected events during development,
     it is recommended to set a breakpoint on the following instruction.
  */
}


/**
  * @brief  Timer3 Update/Overflow/Trigger/Break Interrupt routine.
  * @param  None
  * @retval None
  */
INTERRUPT_HANDLER(TIM3_UPD_OVF_TRG_BRK_IRQHandler, 21)
{
  /* In order to detect unexpected events during development,
     it is recommended to set a breakpoint on the following instruction.
  */
}
/**
  * @brief  Timer3 Capture/Compare Interrupt routine.
  * @param  None
  * @retval None
  */
INTERRUPT_HANDLER(TIM3_CAP_IRQHandler, 22)
{
  /* In order to detect unexpected events during development,
     it is recommended to set a breakpoint on the following instruction.
  */
}
/**
  * @brief  TIM1 Update/Overflow/Trigger/Commutation Interrupt routine.
  * @param  None
  * @retval None
  */
INTERRUPT_HANDLER(TIM1_UPD_OVF_TRG_COM_IRQHandler, 23)
{
  /* In order to detect unexpected events during development,
     it is recommended to set a breakpoint on the following instruction.
  */
}
/**
  * @brief  TIM1 Capture/Compare Interrupt routine.
  * @param  None
  * @retval None
  */
INTERRUPT_HANDLER(TIM1_CAP_IRQHandler, 24)
{
  /* In order to detect unexpected events during development,
     it is recommended to set a breakpoint on the following instruction.
  */
}

/**
  * @brief  TIM4 Update/Overflow/Trigger Interrupt routine.
  * @param  None
  * @retval None
  */
INTERRUPT_HANDLER(TIM4_UPD_OVF_TRG_IRQHandler, 25)
{
  /* In order to detect unexpected events during development,
     it is recommended to set a breakpoint on the following instruction.
  */
}
/**
  * @brief  SPI1 Interrupt routine.
  * @param  None
  * @retval None
  */
INTERRUPT_HANDLER(SPI1_IRQHandler, 26)
{
  /* In order to detect unexpected events during development,
     it is recommended to set a breakpoint on the following instruction.
  */
}

/**
  * @brief  USART1 TX Interrupt routine.
  * @param  None
  * @retval None
  */
INTERRUPT_HANDLER(USART1_TX_IRQHandler, 27)
{
  /* In order to detect unexpected events during development,
     it is recommended to set a breakpoint on the following instruction.
  */
}

/**
  * @brief  USART1 RX Interrupt routine.
  * @param  None
  * @retval None
  */
INTERRUPT_HANDLER(USART1_RX_IRQHandler, 28)
{
  /* In order to detect unexpected events during development,
     it is recommended to set a breakpoint on the following instruction.
  */
}

/**
  * @brief  I2C1 Interrupt routine.
  * @param  None
  * @retval None
  */
INTERRUPT_HANDLER(I2C1_IRQHandler, 29)
{
	uint8_t sr1 = 0x00;
	uint8_t sr2 = 0x00;
	uint16_t state = 0;
	uint16_t test = 0;
	uint8_t direct = 0;
	
	  /* Read SR2 register to get I2C error */
	sr2 = I2C_ReadRegister(I2C1, I2C_Register_SR2);
  if (sr2) {
    //I2C1->SR2 = 0;
  }
	
	state = I2C_GetLastEvent(I2C1);
	
	if( _i2c_dev.state == BMP280_I2C_WRITE_REG ) {
		
		  switch (state) {
					/* EV5 */
				case I2C_EVENT_MASTER_MODE_SELECT :
					/* Send slave Address for write */
					I2C_Send7bitAddress(I2C1, _i2c_dev.addr << 1, I2C_Direction_Transmitter);
					break;
					/* EV6 */
				case I2C_EVENT_MASTER_TRANSMITTER_MODE_SELECTED:
					/* EV8 */
				case I2C_EVENT_MASTER_BYTE_TRANSMITTING:
					if (_i2c_dev.tx_len - _i2c_dev.tx_idx > 0) {
						/* Send the first Data */
						I2C_SendData(I2C1, _i2c_dev.TxBuffer[_i2c_dev.tx_idx]);
						_i2c_dev.tx_idx++;
					} else {
						I2C_ITConfig(I2C1, I2C_IT_BUF, DISABLE);
					}
					break;		
					/* EV8_2 */
				case I2C_EVENT_MASTER_BYTE_TRANSMITTED:
					/* Send STOP condition */
					I2C_GenerateSTOP(I2C1, ENABLE);
					I2C_ITConfig(I2C1, (I2C_IT_TypeDef)(I2C_IT_ERR | I2C_IT_EVT | I2C_IT_BUF) , DISABLE);
					_i2c_dev.state = BMP280_I2C_WRITE_REG_END;
					break;
		
				default:
					break;
			}
	} else if( _i2c_dev.state == BMP280_I2C_READ_REG1 || _i2c_dev.state == BMP280_I2C_READ_REG2 ) {
	
		  switch (state)	{
					/* EV5 */
				case I2C_EVENT_MASTER_MODE_SELECT :
					/* Send slave Address for write */
					direct = (_i2c_dev.state == BMP280_I2C_READ_REG1 ? I2C_Direction_Transmitter : I2C_Direction_Receiver);
					I2C_Send7bitAddress(I2C1, (_i2c_dev.addr << 1), direct);
					break;
					
					/* EV6 */
				case I2C_EVENT_MASTER_TRANSMITTER_MODE_SELECTED:
					/* EV8 */
				case I2C_EVENT_MASTER_BYTE_TRANSMITTING:
					if (_i2c_dev.tx_len - _i2c_dev.tx_idx > 0) {
						/* Send the first Data */
						I2C_SendData(I2C1, _i2c_dev.TxBuffer[_i2c_dev.tx_idx]);
						_i2c_dev.tx_idx++;
						
						if( _i2c_dev.tx_len == _i2c_dev.tx_idx ) {
							_i2c_dev.state = BMP280_I2C_READ_REG2;
						}
					}
					break;
					/* EV8_2 */
				case I2C_EVENT_MASTER_BYTE_TRANSMITTED:
					/* Send RESTART condition */
					I2C_GenerateSTART(I2C1, ENABLE);
					break;
					
				/* EV6 */
				case I2C_EVENT_MASTER_RECEIVER_MODE_SELECTED:
					if( _i2c_dev.rx_len == 1 ) {
						I2C_AcknowledgeConfig(I2C1, DISABLE);
						I2C_GenerateSTOP(I2C1, ENABLE);
					}
					break;
					
				/* EV7 */
				case I2C_EVENT_MASTER_BYTE_RECEIVED:
					_i2c_dev.RxBuffer[_i2c_dev.rx_idx++] = I2C_ReceiveData(I2C1);
					
					if( _i2c_dev.rx_len - _i2c_dev.rx_idx == 1 ) {
						I2C_AcknowledgeConfig(I2C1, DISABLE);
						I2C_GenerateSTOP(I2C1, ENABLE);
					}
					
					if(_i2c_dev.rx_len - _i2c_dev.rx_idx <= 0 ) {
						I2C_ITConfig(I2C1, (I2C_IT_TypeDef)(I2C_IT_ERR | I2C_IT_EVT | I2C_IT_BUF) , DISABLE);
						_i2c_dev.state = BMP280_I2C_READ_REG_END;
					}
					break;
					
				case 0x344:
					sr1 = I2C1->SR1;
					break;
					
				default:
					test = state;
					break;
			}
	}
}

/**
  * @}
  */

/**
  * @}
  */

/******************* (C) COPYRIGHT 2010 STMicroelectronics *****END OF FILE****/

