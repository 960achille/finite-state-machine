#include "led.h"
#include <stdio.h>

void Led_set(Led_t *led, int on) {
    led->state = on;
    printf("[SIM] Led %s -> %d\n", led->name, on);
}
