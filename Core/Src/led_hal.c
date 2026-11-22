#include "led.h"
#include "stm32l4xx_hal.h"

void Led_set(Led_t *led, int on) {
    if (led == NULL) {
        return;
    }
    led->state = on ? 1 : 0;
    if (led->port != NULL) {
        HAL_GPIO_WritePin((GPIO_TypeDef *)led->port, (uint16_t)led->pin,
                          on ? GPIO_PIN_SET : GPIO_PIN_RESET);
    }
}
