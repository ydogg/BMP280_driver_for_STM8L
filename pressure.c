/*!
 *  @brief Example shows basic application of configuring and reading pressure.
 */

#include <stdio.h>
#include <string.h>

#include "bmp280.h"
#include "pressure.h"

//void delay_ms(uint32_t period_ms);

struct bmp280_dev bmp;
struct bmp280_dev bmp2;

void print_rslt(const char api_name[], int8_t rslt);
int init_press(struct bmp280_dev* bmp, uint8_t addr)
{
	  int8_t rslt;
    struct bmp280_config conf;

    /* Map the delay function pointer with the function responsible for implementing the delay */
    bmp->delay_ms = delay_ms;

    /* Assign device I2C address based on the status of SDO pin (GND for PRIMARY(0x76) & VDD for SECONDARY(0x77)) */
    bmp->dev_id = addr; /*BMP280_I2C_ADDR_PRIM*/

    /* Select the interface mode as I2C */
    bmp->intf = BMP280_I2C_INTF;

    /* Map the I2C read & write function pointer with the functions responsible for I2C bus transfer */
    bmp->read = i2c_reg_read;
    bmp->write = i2c_reg_write;

    /* To enable SPI interface: comment the above 4 lines and uncomment the below 4 lines */

    /*
     * bmp.dev_id = 0;
     * bmp.read = spi_reg_read;
     * bmp.write = spi_reg_write;
     * bmp.intf = BMP280_SPI_INTF;
     */
    rslt = bmp280_init(bmp);
    print_rslt(" bmp280_init status", rslt);

    /* Always read the current settings before writing, especially when
     * all the configuration is not modified
     */
    rslt = bmp280_get_config(&conf, bmp);
    print_rslt(" bmp280_get_config status", rslt);

    /* configuring the temperature oversampling, filter coefficient and output data rate */
    /* Overwrite the desired settings */
    conf.filter = BMP280_FILTER_COEFF_2;

    /* Temperature oversampling set at 4x */
    conf.os_temp = BMP280_OS_4X;
		
    /* Pressure oversampling set at 4x */
    conf.os_pres = BMP280_OS_4X;

    /* Setting the output data rate as 1HZ(1000ms) */
    conf.odr = BMP280_ODR_1000_MS;
    rslt = bmp280_set_config(&conf, bmp);
    print_rslt(" bmp280_set_config status", rslt);

    /* Always set the power mode after setting the configuration */
    rslt = bmp280_set_power_mode(BMP280_NORMAL_MODE, bmp);
    print_rslt(" bmp280_set_power_mode status", rslt);
}

int fetch_press(struct bmp280_dev* bmp, int32_t* out_pres32, int32_t* out_temp32)
{
	int8_t rslt;
	struct bmp280_uncomp_data ucomp_data;
	uint32_t pres32, pres64;
	double pres;

	int32_t temp32 = 0;
	double temp = 0.0;
		
	/* Reading the raw data from sensor */
	rslt = bmp280_get_uncomp_data(&ucomp_data, bmp);

	/* Getting the compensated pressure using 32 bit precision */
	rslt = bmp280_get_comp_pres_32bit(&pres32, ucomp_data.uncomp_press, bmp);
	if( rslt == BMP280_OK ) {
		*out_pres32 = pres32;
	}

	/* Getting the compensated pressure as floating point value */
	rslt = bmp280_get_comp_pres_double(&pres, ucomp_data.uncomp_press, bmp);
		
	/* Getting the 32 bit compensated temperature */
	rslt = bmp280_get_comp_temp_32bit(&temp32, ucomp_data.uncomp_temp, bmp);
	if( rslt == BMP280_OK ) {
		*out_temp32 = temp32;
	}
	
	/* Getting the compensated temperature as floating point value */
	rslt = bmp280_get_comp_temp_double(&temp, ucomp_data.uncomp_temp, bmp);
	return 0;
}

/*!
 *  @brief Function that creates a mandatory delay required in some of the APIs such as "bmg250_soft_reset",
 *      "bmg250_set_foc", "bmg250_perform_self_test"  and so on.
 *
 *  @param[in] period_ms  : the required wait time in milliseconds.
 *  @return void.
 *
 */
/*
void delay_ms(uint32_t period_ms)
{
}
*/

/*!
 *  @brief Prints the execution status of the APIs.
 *
 *  @param[in] api_name : name of the API whose execution status has to be printed.
 *  @param[in] rslt     : error code returned by the API whose execution status has to be printed.
 *
 *  @return void.
 */
void print_rslt(const char api_name[], int8_t rslt)
{
    if (rslt != BMP280_OK)
    {
        printf("%s\t", api_name);
        if (rslt == BMP280_E_NULL_PTR)
        {
            printf("Error [%d] : Null pointer error\r\n", rslt);
        }
        else if (rslt == BMP280_E_COMM_FAIL)
        {
            printf("Error [%d] : Bus communication failed\r\n", rslt);
        }
        else if (rslt == BMP280_E_IMPLAUS_TEMP)
        {
            printf("Error [%d] : Invalid Temperature\r\n", rslt);
        }
        else if (rslt == BMP280_E_DEV_NOT_FOUND)
        {
            printf("Error [%d] : Device not found\r\n", rslt);
        }
        else
        {
            /* For more error codes refer "*_defs.h" */
            printf("Error [%d] : Unknown error code\r\n", rslt);
        }
    }
}
