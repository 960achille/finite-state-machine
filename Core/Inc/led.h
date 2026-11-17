#ifndef LED_H
#define LED_H

typedef struct {
    void *port;        // GPIO_TypeDef* on the board, NULL in simulation
    unsigned int pin;  // GPIO_PIN_x on the board
    int state;         // 1 = on, 0 = off
    const char *name;
} Led_t;

// Implemented by led_sim.c (PC) or led_hal.c (STM32)
void Led_set(Led_t *led, int on);

#endif