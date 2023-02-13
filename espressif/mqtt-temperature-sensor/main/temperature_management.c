/*
Lib for temperature management
*/
#include "app_priv.h"



static float temperature;


/*
* @brief    set up the temperature sensor peripheral
*/
void temperature_init(){

#ifdef TEMPERATURE_SENSOR_INTERNAL
    temp_sensor_config_t temp_sensor = TSENS_CONFIG_DEFAULT();
    temp_sensor_get_config(&temp_sensor);
    temp_sensor.dac_offset = TSENS_DAC_DEFAULT; // DEFAULT: range:-10℃ ~  80℃, error < 1℃.
    temp_sensor_set_config(temp_sensor);
    temp_sensor_start();
#endif
}

/*
* @brief     Return the temperature from internal or external sensor
* @return    temperature as a float
*/
float get_temperature(){
    temperature = -999;
#ifdef TEMPERATURE_SENSOR_INTERNAL
        temp_sensor_read_celsius(&temperature);
#endif
    return temperature;
}


