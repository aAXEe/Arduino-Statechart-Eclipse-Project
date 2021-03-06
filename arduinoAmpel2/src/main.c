/*
 * TrafficLight example for yakindu sct
 *
 * based on official example: org.yakindu.sct.examples.c.arduinoTrafficLight
 *
 * changes:
 * - use the Arduino core library for pin and time handling
 * - enable debugging with printf() (see uart.c; it uses the Arduino HardwareSerial)
 * - new implementation for timers based on Arduinos millis() function -> no extra timer is used
 * - provide the runCycle event with the new timer api -> handle all timed events in one place
 *
 * author:
 * Axel Utech <axel.utech@gmail.com>
 *
 * notes:
 * Arduino Core library is from https://github.com/allgood38/Arduino-Blink-Eclipse-Project
 * notes about the original example:
 * 	http://scholtyssek.blogspot.de/2013/10/yakindu-statechart-tools-arduino.html
 */

#include <stdio.h>
#include <wiring.h>

#include "sc_types.h"
#include "statetimer.h"
#include "uart.h"

#include "TrafficlightRequired.h"
#include "Trafficlight.h"

const uint8_t ledPinTrafficRed = 13;      	// the number of the red LED pin
const uint8_t ledPinTrafficYellow = 12;		// the number of the yellow LED pin
const uint8_t ledPinTrafficGreen = 11;		// the number of the green LED pin

const uint8_t ledPinPedestrianRed = 10;		// the number of the red LED pin
const uint8_t ledPinPedestrianYellow = 9;
const uint8_t ledPinPedestrianGreen = 8;	// the number of the green LED pin

const uint8_t btnOnOff = 3;
/*
 * Interrupt ID for the pin
 * see http://arduino.cc/en/Reference/AttachInterrupt
 */
const uint8_t btnOnOffIsrID = 1;

const uint8_t btnPedestrian = 2;
const uint8_t btnPedestrianIsrId = 0;

volatile uint8_t raiseOnOffEventFlag = 0;
volatile uint8_t raisePedestrianRequestFlag = 0;

Trafficlight handle;

static void raiseEventCallback(sc_eventid evid) {
	printf("raise timer event id: %p\n", evid);
	trafficlight_raiseTimeEvent(&handle, evid);
}

void trafficlight_setTimer(const sc_eventid evid, int32_t time_ms,
		const sc_boolean periodic) {
	printf("set timer id: %p timeout: %i periodic: %i\n", evid, time_ms, periodic);

	setTimer(evid, time_ms, periodic, raiseEventCallback);
}

void trafficlight_unsetTimer(const sc_eventid evid) {
	printf("unset timer id: %p\n", evid);
	unsetTimer(evid);
}

static void runCycle(sc_eventid evid) {
	printf("run cycle\n");
	trafficlight_runCycle(&handle);
}

static void setTrafficLights() {

	/**
	 * Pedestrian light
	 */
	digitalWrite(ledPinPedestrianGreen,
			trafficlightIfacePedestrianLight_get_green(&handle));
	digitalWrite(ledPinPedestrianYellow,
			trafficlightIfacePedestrianLight_get_yellow(&handle));
	digitalWrite(ledPinPedestrianRed,
			trafficlightIfacePedestrianLight_get_red(&handle));

	/*
	 *  traffic light
	 */
	digitalWrite(ledPinTrafficRed,
			trafficlightIfaceTrafficLight_get_red(&handle));
	digitalWrite(ledPinTrafficYellow,
			trafficlightIfaceTrafficLight_get_yellow(&handle));
	digitalWrite(ledPinTrafficGreen,
			trafficlightIfaceTrafficLight_get_green(&handle));
}

static void btnOnOffISR(void) {
	raiseOnOffEventFlag = 1;
}

static void btnPedestrianISR(void) {
	raisePedestrianRequestFlag = 1;
}

int main(void) {
	init();

	setup();

	for (;;)
		loop();

	return 0;
}


void setup() {
	uartInit(9600);
	printf("Setup begin!\n");

	pinMode(ledPinPedestrianYellow, OUTPUT);
	pinMode(ledPinPedestrianGreen, OUTPUT);
	pinMode(ledPinPedestrianRed, OUTPUT);
	pinMode(ledPinTrafficRed, OUTPUT);
	pinMode(ledPinTrafficYellow, OUTPUT);
	pinMode(ledPinTrafficGreen, OUTPUT);

	pinMode(btnOnOff, INPUT);
	digitalWrite(btnOnOff, HIGH);
	attachInterrupt(btnOnOffIsrID, btnOnOffISR, FALLING);

	pinMode(btnPedestrian, INPUT);
	digitalWrite(btnPedestrian, HIGH);
	attachInterrupt(btnPedestrianIsrId, btnPedestrianISR, FALLING);

	initTimers();

	//init runCylce timer
	setTimer(&handle, 1000, 1, runCycle);

	trafficlight_init(&handle);
	trafficlight_enter(&handle);

	printf("Setup ready!\n");
}

void loop() {
	if(raiseOnOffEventFlag){
		raiseOnOffEventFlag = 0;
		printf("Raise onOff\n");
		trafficlightIface_raise_onOff(&handle);
	}
	if(raisePedestrianRequestFlag){
		raisePedestrianRequestFlag = 0;
		printf("raise pedestrian request\n");
		trafficlightIface_raise_pedestrianRequest(&handle);
	}

	checkTimers(); // dispatches all active timers
	setTrafficLights();
}

