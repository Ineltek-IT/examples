#include <stdio.h>
#include <stdint.h>
#include <string.h>
#include "esp_log.h"
#include "esp_system.h"
#include "freertos/FreeRTOS.h"
#include "freertos/task.h"
#include "app_peripherals.h"
#include "quirc.h"
#include "esp_code_scanner.h"

static const char *TAG = "APP_CODE_SCANNER";

// esp_err_t rgb565_to_grayscale(uint8_t * grayscale_pixels, uint16_t * rgb565_pixels, size_t size){
    
//     uint16_t red = 0;
//     uint16_t green = 0;
//     uint16_t blue = 0;

//     for(uint16_t k = 0;k<size/2;k=k+2){
//         printf("%d] RGB: %d::%04X\n",k,rgb565_pixels[k],rgb565_pixels[k]);
//         red   = (rgb565_pixels[k] & 0xF800)>>11;
//         green = (rgb565_pixels[k] & 0x07E0)>>5;
//         blue  = (rgb565_pixels[k] & 0x001F);
//         grayscale_pixels[k/2]=(uint8_t)(red/4+3*green/8+blue/16); // approximation of (0.2126 * red) + (0.7152 * green / 2.0) + (0.0722 * blue);
//         printf("Grayscale: %d::%02X\n",grayscale_pixels[k],grayscale_pixels[k]);
//     }
//     return ESP_OK;
// }


static void decode_task()
{
    if(ESP_OK != app_camera_init()) {
        vTaskDelete(NULL);
        return;
    }

    
    camera_fb_t *fb = NULL;

    // Initializing the quirc handle
    struct quirc *q = quirc_new();
    if (!q) {
        ESP_LOGE(TAG,"Failed to allocate memory\n");
        exit(1);
    }


    // Get image size through fb parameters
    fb = esp_camera_fb_get();
    if(fb == NULL){
        ESP_LOGI(TAG, "camera get failed\n");
    }

    uint16_t p_width = fb->width;
    uint16_t p_height = fb->height;
    uint32_t p_len = fb->len;
    // printf("w:%d\t, h:%d\t, len:%d\n",p_width,p_height,p_len);
    // uint8_t nr_bytes = p_len/(p_width*p_height);

    // Buffer where the grayscale picture will be stored
    //uint8_t * grayscale_buffer = (uint8_t *)malloc(p_len/nr_bytes*sizeof(uint8_t));

    if (quirc_resize(q, p_width,p_height) < 0) {
        ESP_LOGE(TAG,"Failed to allocate video  memory\n");
        exit(1);
    }   

    while (1)
    {
        fb = esp_camera_fb_get();
        if(fb == NULL){
            ESP_LOGI(TAG, "camera get failed\n");
            continue;
        }
        //printf("Picture Format:%d\nPicture w:%d\th:%d\tlen:%d",fb->format,fb->width,fb->height,fb->len);
        // Decode Progress
        //rgb565_to_grayscale(grayscale_buffer, fb->buf,fb->len);

        esp_image_scanner_t *esp_scn = esp_code_scanner_create();
        esp_code_scanner_config_t config = {ESP_CODE_SCANNER_MODE_FAST, ESP_CODE_SCANNER_IMAGE_GRAY, fb->width, fb->height};
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

    quirc_destroy(q);
}


void app_main()
{
    xTaskCreatePinnedToCore(decode_task, TAG, 4 * 1024, NULL, 6, NULL, 0);
}