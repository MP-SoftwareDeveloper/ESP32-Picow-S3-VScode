// Link for source: https://www.youtube.com/watch?v=LHCZPkoHGNc
#include <stdio.h>
#include "freertos/FreeRTOS.h"
#include "freertos/task.h" 
#include "driver/gpio.h"

void blink(void)
{
    gpio_set_direction(GPIO_NUM_13,GPIO_MODE_OUTPUT);

    while(1)
    {
        gpio_set_level(GPIO_NUM_13,0);
        vTaskDelay(20);
        gpio_set_level(GPIO_NUM_13,1 );
        vTaskDelay(20);
    }
}
void app_main(void)
{
    xTaskCreate(blink , "LED blink", 2048, NULL , 0, NULL);
  
}
