#include "fsm.h"
#include "events_quere.h"
#include "log.h"

static Fsm brake_fsm;

FSM_DECLARE_STATE(pressed);
FSM_DECLARE_STATE(released);

FSM_STATE_TRANSITION(pressed) {
	FSM_ADD_TRANSITION(

void brake_fsm_init() {

}

void brake_fsm_process_event() {

}
