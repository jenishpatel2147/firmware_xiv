typedef enum {
	CAR_INPUT_FAULT,
	CAR_INPUT_NEUTRAL,
	CAR_INPUT_DRIVE,
	NUM_CAR_EVENTS,
} InputCarEvents;

typedef enum {
	BRAKE_PRESSED = CAR_INPUT_NUM_CAR_EVENTS + 1,
	BRAKE_RELEASED,
	NUM_BRAKE_EVENTS,
} BrakeEvents;

typedef enum {
	THROTTLE_DATA = NUM_BRAKE_EVENTS + 1,
	NUM_THROTTLE_EVENTS,
} ThrottleEvents;
