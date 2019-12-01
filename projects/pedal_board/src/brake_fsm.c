#include "fsm.h"
#include "events_quere.h"
#include "log.h"

static Fsm brake_fsm;

FSM_DECLARE_STATE(pressed);
FSM_DECLARE_STATE(released);

FSM_STATE_TRANSITION(pressed) {
	FSM_ADD_TRANSITION(RELEASED, released);
};

FSM_STATE_TRANSITION(released) {
	FSM_ADD_TRANSITION(PRESSED, released);
}

static void brake_fsm_init() {
	fsm_state_init(pressed, );
	fsm_state_init(released, );

	fsm_init(&brake_fsm, "Brake_FSM", &released, &brake_fsm);
}

static void brake_fsm_process_event() {

}

static void prv_pressed_output(Fsm *fsm, const Event *e) {
	
}

static void prv_released_output(Fsm *fsm, const Event *e) {

}
