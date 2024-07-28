#include <stdio.h>
#include "esp_spiffs.h"
#include "esp_log.h"
#include "esp_mac.h"

static const char* TAG = "FileSystem";

void app_main(void)
{
     esp_vfs_spiffs_conf_t config = {
        .base_path = "/storage",
        .partition_label =  NULL,
        .max_files = 5, // max number of files that you can use simultaneously
        .format_if_mount_failed = true
     };

     esp_err_t result = esp_vfs_spiffs_register(&config);// we are using config we made up here and use it in ESP log
     
     if (result != ESP_OK)
     {
        ESP_LOGE(TAG, "Failed to initilize SPIFFS (%s)", esp_err_to_name(result));
        return;
     }

     size_t total = 0, used = 0;
     result = esp_spiffs_info(config.partition_label, &total, &used);
     if (result != ESP_OK){
        ESP_LOGE(TAG, "Failed to initilize SPIFFS (%s)", esp_err_to_name(result));
     }else{
        ESP_LOGI(TAG, "Partition size: %d, used: %d", total, used);
     }

} 