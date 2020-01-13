typedef enum {
	CAN_BRAKE_PRESSED = 0,
	CAN_BRAKE_RELEASED,
	NUM_BRAKE_CAN_EVENTS,
} BrakeCanEvents;

typedef enum {
	CAN_RX = NUM_BRAKE_CAN_EVENTS + 1,
	CAN_TX,
	CAN_FAULT,
	NUM_CAN_EVENTS,
} CanEvents;

typedef enum {
	CAR_INPUT_FAULT = NUM_CAN_EVENTS + 1,
	CAR_INPUT_NEUTRAL,
	CAR_INPUT_DRIVE,
	NUM_CAR_EVENTS,
} InputCarEvents;

typedef enum {
	BRAKE_PRESSED = NUM_CAR_EVENTS + 1,
	BRAKE_RELEASED,
	NUM_BRAKE_EVENTS,
} BrakeEvents;

typedef enum {
	THROTTLE_DATA = NUM_BRAKE_EVENTS + 1,
	NUM_THROTTLE_EVENTS,
} ThrottleEvents;
