#include <stdio.h>
#include <stdint.h>
#include <string.h>
#include "esp_log.h"
#include "esp_system.h"
#include "freertos/FreeRTOS.h"
#include "freertos/task.h"
#include "app_peripherals.h"

#include "esp_code_scanner.h"

static const char *TAG = "APP_CODE_SCANNER";

static void decode_task()
{
    if(ESP_OK != app_camera_init()) {
        vTaskDelete(NULL);
        return;
    }
    
    camera_fb_t *fb = NULL;
    while (1)
    {
        fb = esp_camera_fb_get();
        if(fb == NULL){
            ESP_LOGI(TAG, "camera get failed\n");
            continue;
        }

        // Decode Progress
        esp_image_scanner_t *esp_scn = esp_code_scanner_create();
        esp_code_scanner_config_t config = {ESP_CODE_SCANNER_MODE_FAST, ESP_CODE_SCANNER_IMAGE_RGB565, fb->width, fb->height};
        esp_code_scanner_set_config(esp_scn, config);
        int decoded_num = esp_code_scanner_scan_image(esp_scn, fb->buf);

        if(decoded_num){
            esp_code_scanner_symbol_t result = esp_code_scanner_result(esp_scn);
            printf("{%s}\n",result.data);
        }
        esp_code_scanner_destroy(esp_scn);


        esp_camera_fb_return(fb);
        vTaskDelay(10 / portTICK_PERIOD_MS);
    }
}


void app_main()
{
    xTaskCreatePinnedToCore(decode_task, TAG, 4 * 1024, NULL, 6, NULL, 0);
}