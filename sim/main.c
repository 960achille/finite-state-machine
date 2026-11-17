#include "fsm.h"

int main(void) {
    Led_t blue = {0, 0, 0, "blue"}, yellow = {0, 0, 0, "yellow"};
    Led_t green = {0, 0, 0, "green"}, red = {0, 0, 0, "red"};
    FSM_t fsm;

    FSM_init(&fsm, &blue, &yellow, &green, &red);
    FSM_change(&fsm, A);
    FSM_change(&fsm, A);
    FSM_change(&fsm, B);
    FSM_change(&fsm, C);
    return 0;
}