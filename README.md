# BMP280_driver_for_STM8L

Forked from BoschSensortec/BMP280_driver, with STM8L's StdPeriph Library API reflected.
Supports two BMP280 sensor running at the same with I2C,
Works well on STM8L152C6T6 and STML8 Discovry DevKit.

## 1. Pin Connect ##
SCL: PC1
SDA: PC0
CSB: VCC (I2C)
BMP280 1 senosr : 0x76 (SDO->VCC)
BMP280 2 sersor : 0x77 (SDO->GND)

## 2. Functions required for Bosch BMP280_driver's migration ##
delay.h -> 
 void delay_ms(u16 n_ms);

i2c.h -> 
 int8_t i2c_reg_read(uint8_t i2c_addr, uint8_t reg_addr, uint8_t *reg_data, uint16_t length);
 int8_t i2c_reg_write(uint8_t i2c_addr, uint8_t reg_addr, uint8_t *reg_data, uint16_t length);
 
##  3. Usage Example ##
 
    int main(void)
    {
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
    	delay_ms(50);
      
    	while(1) {
    		delay_ms(1000);
    		fetch_press(&bmp, &pres32, &temp32);
    		delay_ms(1000);
    		fetch_press(&bmp2, &pres32, &temp32);
    	}
    }

