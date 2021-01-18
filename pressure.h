#ifndef __PRESSURE_H
#define __PRESSURE_H

#include "stm8l15x.h"
#include "bmp280_defs.h"
#include "i2c.h"

extern struct bmp280_dev bmp;
extern struct bmp280_dev bmp2;
int init_press(struct bmp280_dev* bmp, uint8_t addr);
int fetch_press(struct bmp280_dev* bmp, int32_t* out_pres32, int32_t* out_temp32);

#endif