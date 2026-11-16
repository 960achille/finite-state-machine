#include "fsm.h"
#include "stm32l4xx_hal.h"
#include <stdio.h>

void setLed(Led_t led, int state) {
    led.state = state;
    if (led.port == NULL) {
        printf("[SIMULAZIONE] Led %s -> %d\n", led.name, led.state)
    } else {
        if(led.state == 1)
            HAL_GPIO_WritePin(led.port, led.pin, GPIO_PIN_SET);
        else
            HAL_GPIO_WritePin(led.port, led.pin, GPIO_PIN_RESET);
    }
}

void updateFSM(FSM_t* fsm) {
    // Turn all off and turn on the right one
    Set_Led(fsm->led_blue, fsm->state == S0);
    Set_Led(fsm->led_yellow, fsm->state == S1);
    Set_Led(fsm->led_yellow, fsm->state == S2);
    Set_Led(fsm->led_green, fsm->state == S3);
    Set_Led(fsm->led_red, fsm->state == S4);
    printf("FSM State = %s", fsm->state);
}

void FSM_init(FSM_t *fsm, LedPin_t blue_led, LedPin_t yellow_led, LedPin_t green_led, LedPin_t red_led) {
    fsm->state = S0;
    fsm->blue = blue_led;
    fsm->yellow = yellow_led;
    fsm->green = green_led;
    fsm->red = red_led;

    updateFSM(fsm);
}

void FSM_change(FSM_t *fsm, Input_t input) {
    switch (fsm->state) {
        case S0:
            if (input == A) {
                fsm->state = S2;
            } else if (input == B) {
                fsm->state = S1;
            } else if (input == C) {
                fsm->state = S3;
            }
            break;
        case S1:
            if (input == B) {
                fsm->state = S1;
            } else if (input == C) {
                fsm->state = S3;
            }
            break;
        case S2:
            if (input == A) {
                fsm->state = S0;
            }
            break;
        case S3:
            // Stay in S3?????
            break;
    }
    updateFSM(fsm);
}
