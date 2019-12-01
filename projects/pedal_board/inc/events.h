typedef enum {
	FAULT,
	NEUTRAL,
	DRIVE,
	NUM_CAR_EVENTS,
} InputCarEvents;

typedef enum {
	PRESSED = NUM_CAN_EVENTS + 1,
	RELEASED,
	NUM_BRAKE_EVENTS,
} BrakeEvents;

typedef enum {
	DATA = NUM_EVENTS_FSM + 1,
	NUM_THROTTLE_EVENTS,
} ThrottleEvents;
