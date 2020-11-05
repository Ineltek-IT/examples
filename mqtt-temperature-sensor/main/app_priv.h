
#include <stdio.h>
#include "esp_sntp.h"
#include "driver/temp_sensor.h"
#include "mqtt_client.h"
#include "esp_log.h"
#include "esp_tls.h"

#include "configuration.h"

void start_sntp_synch(void *);
void temperature_init();
float get_temperature();
void mqtt_init();
int mqtt_publish(char *,char *);