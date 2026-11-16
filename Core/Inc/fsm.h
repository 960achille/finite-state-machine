#ifndef __FINITE_STATE_MACHINE_H__
#define __FINITE_STATE_MACHINE_H__

#define NULL ((void*)0)
typedef void GPIO_t;

#define MAX_WAIT_TIME 1000

typedef enum {
    S0 = 0,
    S1 = 1,
    S2 = 2,
    S3 = 3,
    S4 = 4 //error
} State_t;

typedef enum {
    UNKNOWN = 0,
    A = 1,
    B = 2,
    C = 3
} Input_t;

typedef struct {
    GPIO_t* port;
    unsigned int pin;
    int state; // 1 = on      2 = off
    char* name;
} Led_t;

typedef struct {
    state_t state;
    LedPin_t blue;
    LedPin_t yellow;
    LedPin_t green;
    LedPin_t red; //error led
} FSM_t;

void FSM_init(FSM_t* fsm, LedPin_t blue_led, LedPin_t yellow_led, LedPin_t green_led, LedPin_t red_led);

void FSM_change(FSM_t* fsm, Input_t input);

#endif