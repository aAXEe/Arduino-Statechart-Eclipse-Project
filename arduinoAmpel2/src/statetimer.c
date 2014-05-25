/*
 * Time API for yakindu sct
 *
 * uses Arduinos millis() to check the time
 *
 * author:
 * Axel Utech <axel.utech@gmail.com>
 *
 */
#include <stdio.h>
#include "wiring.h"

#include "sc_types.h"
#include "statetimer.h"
#include "uart.h"

// internal representation for one timer
struct timer {
	// data from statemachines
	sc_eventid evid;
	sc_integer time_ms;
	sc_boolean periodic;
	// pointer to callback function for raising the event
	raiseEventCallback_t callback_fun;

	// internal values
	// current timeout time for the event
	unsigned long timeout_ms;
	// 1 if this timer is currently in use
	uint8_t in_use;
};

#define NUM_MAX_TIMERS 10
static struct timer timers[NUM_MAX_TIMERS];

// must be called before all other timer functions
void initTimers(void) {
	uint8_t i;
	for (i = 0; i < NUM_MAX_TIMERS; ++i) {
		timers[i].in_use = 0;
	}
}

// calculate new timeout for a timer
static void setTimeout(struct timer *tim) {
	tim->timeout_ms = millis() + tim->time_ms;
	tim->in_use = 1;
}

/**
 * Queue a timer event
 *
 * \param evid 		Event-ID for the timer
 * \param time_ms 	timout time for the timer
 * \param periodic	true if the timer should be repeated
 * \param callback	Pointer to a callback functions with is called after each timeout
 *
 */
void setTimer(const sc_eventid evid, const sc_integer time_ms,
		const sc_boolean periodic, raiseEventCallback_t callback) {
	uint8_t i;
	for (i = 0; i < NUM_MAX_TIMERS; ++i) {
		if (timers[i].in_use)
			continue;

		timers[i].evid = evid;
		timers[i].time_ms = time_ms;
		timers[i].periodic = periodic;
		timers[i].callback_fun = callback;
		setTimeout(&timers[i]);
		return;
	}
	//error: no free timer
	printf(
			"ERROR: No free timer! Increase the number of available timers in statetimer.c.");
}

/**
 * Dequeue a timer
 *
 * \param evid 		Event-ID for the timer
 */
void unsetTimer(const sc_eventid evid) {
	int8_t i;
	for (i = 0; i < NUM_MAX_TIMERS; ++i) {
		if (timers[i].evid != evid || !(timers[i].in_use))
			continue;
		timers[i].in_use = 0;
	}
}

// helper: called if the timer timed out
static void dispatchTimerEvent(struct timer *tim) {
	if (tim->callback_fun)
		tim->callback_fun(tim->evid);

	if (tim->periodic)
		setTimeout(tim);
	else
		tim->in_use = 0;
}

/**
 * Checks if a timer has a timeout.
 *
 * \note May be called as often as possible from the main routine to check for new timeouts
 *
 */
void checkTimers(void) {
	unsigned long now = millis();
	uint8_t i;

	for (i = 0; i < NUM_MAX_TIMERS; ++i) {
		if (!timers[i].in_use)
			continue;
		if (timers[i].timeout_ms > now)
			continue;
		dispatchTimerEvent(&timers[i]);
	}
}
