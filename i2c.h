#ifndef __I2C_H
#define __I2C_H

#include "stm8l15x.h"
#include "stm8l15x_i2c.h"

#define BUFFERSIZE  		(32)

#pragma pack(1)
struct i2c_dev {
	uint8_t addr;
	uint8_t state;
	uint8_t tx_idx;
	uint8_t rx_idx;
	uint8_t tx_len;
	uint8_t rx_len;
	uint8_t TxBuffer[BUFFERSIZE];
	uint8_t RxBuffer[BUFFERSIZE];
};
#pragma pack()

enum {
	BMP280_I2C_RESET = 0x00,
	BMP280_I2C_WRITE_REG,
	BMP280_I2C_WRITE_REG_END,
	BMP280_I2C_READ_REG1,
  BMP280_I2C_READ_REG2,
	BMP280_I2C_READ_REG_END
};

extern struct i2c_dev _i2c_dev;
int8_t i2c_init(void);
int8_t i2c_reg_read(uint8_t i2c_addr, uint8_t reg_addr, uint8_t *reg_data, uint16_t length);
int8_t i2c_reg_write(uint8_t i2c_addr, uint8_t reg_addr, uint8_t *reg_data, uint16_t length);

#endif