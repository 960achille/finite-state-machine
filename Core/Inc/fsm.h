#ifndef FSM_H
#define FSM_H

#include "led.h"

typedef enum { S0, S1, S2, S3, S4 /* error */ } State_t;
typedef enum { UNKNOWN = 0, A = 1, B = 2, C = 3 } Input_t;

typedef struct {
    State_t state;
    Led_t *blue;
    Led_t *yellow;
    Led_t *green;
    Led_t *red;
} FSM_t;

void FSM_init(FSM_t *fsm, Led_t *blue, Led_t *yellow, Led_t *green, Led_t *red);
void FSM_change(FSM_t *fsm, Input_t input);

#endif