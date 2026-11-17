#include "fsm.h"
#include <stdio.h>

static void updateFSM(FSM_t *fsm) {
    printf("\n\nSTATE: %d\n", fsm->state);
    Led_set(fsm->blue, fsm->state == S0);
    Led_set(fsm->yellow, fsm->state == S1 || fsm->state == S2);
    Led_set(fsm->green, fsm->state == S3);
    Led_set(fsm->red, fsm->state == S4);
}

void FSM_init(FSM_t *fsm, Led_t *blue, Led_t *yellow, Led_t *green, Led_t *red) {
    fsm->state = S0;
    fsm->blue = blue;
    fsm->yellow = yellow;
    fsm->green = green;
    fsm->red = red;
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
