/*!
 *  @brief Example shows basic application of configuring and reading pressure.
 */

#include <string.h>
#include "i2c.h"

struct i2c_dev _i2c_dev;

static void reset_dev(struct i2c_dev* dev)
{
	dev->addr = 0x0;
	dev->state = 0x0;
	dev->tx_idx = 0x0;
	dev->rx_idx = 0x0;
	dev->tx_len = 0x0;
	dev->rx_len = 0x0;
	
	memset(dev->TxBuffer, 0x0, sizeof(dev->TxBuffer));
	memset(dev->RxBuffer, 0x0, sizeof(dev->RxBuffer));
}

int8_t i2c_init(void)
{
	/* I2C clock Enable*/
  CLK_PeripheralClockConfig(CLK_Peripheral_I2C1, ENABLE);
	
	/* Deinit I2C */
	I2C_DeInit(I2C1);
	
	GPIO_Init(GPIOE, GPIO_Pin_6, GPIO_Mode_Out_PP_High_Slow);
	GPIO_SetBits(GPIOE, GPIO_Pin_6);
	
  /* Initialize I2C peripheral */
  I2C_Init(I2C1, 100000, 0xA1,
           I2C_Mode_I2C, I2C_DutyCycle_2,
           I2C_Ack_Enable, I2C_AcknowledgedAddress_7bit);
					 
  /* Enable Buffer and Event Interrupt*/
  I2C_ITConfig(I2C1, (I2C_IT_TypeDef)(I2C_IT_ERR | I2C_IT_EVT | I2C_IT_BUF) , ENABLE);

  /* Enable I2C */
  I2C_Cmd(I2C1, ENABLE);
}

int8_t i2c_reg_write(uint8_t i2c_addr, uint8_t reg_addr, uint8_t *reg_data, uint16_t length)
{
	  uint8_t count = 0;
		
		// Init global i2c data
		reset_dev(&_i2c_dev);
		
    /* Implement the I2C write routine according to the target machine. */
		_i2c_dev.addr = i2c_addr;
		_i2c_dev.state = BMP280_I2C_WRITE_REG;
		
		/* TXBuffer initialization */
		_i2c_dev.TxBuffer[0] = reg_addr;
		memcpy(_i2c_dev.TxBuffer+1, reg_data, length);
		_i2c_dev.tx_len = length + 1;
		_i2c_dev.tx_idx = 0;

		// Open ack and IT
		I2C_AcknowledgeConfig(I2C1, ENABLE);
		I2C_ITConfig(I2C1, (I2C_IT_TypeDef)(I2C_IT_ERR | I2C_IT_EVT | I2C_IT_BUF) , ENABLE);
	
		/* Send START condition */
		I2C_GenerateSTART(I2C1, ENABLE);
		
		while (_i2c_dev.state != BMP280_I2C_WRITE_REG_END){
			delay_ms(1);
			if ( count++ >= 300 ) {
				break;
			}
		}
		
		// 300ms Timeout failed?
		if( count >= 300 ) {
			return 1;
		}
		
		return 0;
}

/*!
 *  @brief Function for reading the sensor's registers through I2C bus.
 *
 *  @param[in] i2c_addr : Sensor I2C address.
 *  @param[in] reg_addr : Register address.
 *  @param[out] reg_data    : Pointer to the data buffer to store the read data.
 *  @param[in] length   : No of bytes to read.
 *
 *  @return Status of execution
 *  @retval 0 -> Success
 *  @retval >0 -> Failure Info
 *
 */
int8_t i2c_reg_read(uint8_t i2c_addr, uint8_t reg_addr, uint8_t *reg_data, uint16_t length)
{
		uint8_t count = 0;
		
		// Init global i2c data
		reset_dev(&_i2c_dev);
		
    /* Implement the I2C read routine according to the target machine. */
		_i2c_dev.addr = i2c_addr;
		_i2c_dev.state = BMP280_I2C_READ_REG1;
		
		/* TXBuffer initialization */
		_i2c_dev.TxBuffer[0] = reg_addr;
		_i2c_dev.tx_len = 1;
		_i2c_dev.tx_idx = 0;
		
		/* RXBuffer initialization */
		memcpy(_i2c_dev.RxBuffer, 0, sizeof(_i2c_dev.RxBuffer));
		_i2c_dev.rx_len = length;
		_i2c_dev.rx_idx = 0;
		
		// Reopen ack and IT
		I2C_AcknowledgeConfig(I2C1, ENABLE);
		I2C_ITConfig(I2C1, (I2C_IT_TypeDef)(I2C_IT_ERR | I2C_IT_EVT | I2C_IT_BUF) , ENABLE);
		
		/* first start for write address */
		I2C_GenerateSTART(I2C1, ENABLE);
		
		while (_i2c_dev.state != BMP280_I2C_READ_REG_END){
			
			delay_ms(1);
			if ( count++ >= 300 ) {
				break;
			}
		}
		
		// 300ms Timeout failed?
		if( count >= 300 ) {
			return 1;
		}
		
		memcpy(reg_data, _i2c_dev.RxBuffer, length);
		return 0;
}