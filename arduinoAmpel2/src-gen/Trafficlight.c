
#include <stdlib.h>
#include <string.h>
#include "sc_types.h"
#include "Trafficlight.h"
#include "TrafficlightRequired.h"
/*! \file Implementation of the state machine 'Trafficlight'
*/

// prototypes of all internal functions

static void trafficlight_entryaction(Trafficlight* handle);
static void trafficlight_exitaction(Trafficlight* handle);
static void trafficlight_react_main_region_on_r1_StreetGreen(Trafficlight* handle);
static void trafficlight_react_main_region_on_r1_StreetRedYellow(Trafficlight* handle);
static void trafficlight_react_main_region_on_r1_StreetRed(Trafficlight* handle);
static void trafficlight_react_main_region_on_r1_PedestrianGreen(Trafficlight* handle);
static void trafficlight_react_main_region_on_r1_AllRed(Trafficlight* handle);
static void trafficlight_react_main_region_on_r1_StreetAttention(Trafficlight* handle);
static void trafficlight_react_main_region_on_r1_PedestrianRequesting_r2_waitOn(Trafficlight* handle);
static void trafficlight_react_main_region_on_r1_PedestrianRequesting_r2_waitOff(Trafficlight* handle);
static void trafficlight_react_main_region_off_r1_YellowOn(Trafficlight* handle);
static void trafficlight_react_main_region_off_r1_YellowOff(Trafficlight* handle);
static void clearInEvents(Trafficlight* handle);
static void clearOutEvents(Trafficlight* handle);


void trafficlight_init(Trafficlight* handle)
{
	int i;

	for (i = 0; i < TRAFFICLIGHT_MAX_ORTHOGONAL_STATES; ++i)
		handle->stateConfVector[i] = Trafficlight_last_state;
	
	
	handle->stateConfVectorPosition = 0;

clearInEvents(handle);
clearOutEvents(handle);

	// TODO: initialize all events ...

	{
		/* Default init sequence for statechart Trafficlight */
		handle->ifaceTrafficLight.red = bool_false;
		handle->ifaceTrafficLight.yellow = bool_false;
		handle->ifaceTrafficLight.green = bool_false;
		handle->ifacePedestrianLight.red = bool_false;
		handle->ifacePedestrianLight.yellow = bool_false;
		handle->ifacePedestrianLight.green = bool_false;
	}

}

void trafficlight_enter(Trafficlight* handle)
{
	{
		/* Default enter sequence for statechart Trafficlight */
		trafficlight_entryaction(handle);
		{
			/* 'default' enter sequence for region main region */
			{
				/* Default react sequence for initial entry  */
				{
					/* 'default' enter sequence for state off */
					{
						/* 'default' enter sequence for region r1 */
						{
							/* Default react sequence for initial entry  */
							{
								/* 'default' enter sequence for state YellowOn */
								{
									/* Entry action for state 'YellowOn'. */
									trafficlight_setTimer( (sc_eventid) &(handle->timeEvents.Trafficlight_main_region_off_r1_YellowOn_time_event_0_raised) , 500, bool_false);
									handle->ifaceTrafficLight.yellow = bool_true;
									handle->ifacePedestrianLight.yellow = bool_true;
								}
								handle->stateConfVector[0] = Trafficlight_main_region_off_r1_YellowOn;
								handle->stateConfVectorPosition = 0;
							}
						}
					}
				}
			}
		}
	}
}

void trafficlight_exit(Trafficlight* handle)
{
	{
		/* Default exit sequence for statechart Trafficlight */
		{
			/* Default exit sequence for region main region */
			/* Handle exit of all possible states (of main region) at position 0... */
			switch(handle->stateConfVector[ 0 ]) {
				case Trafficlight_main_region_on_r1_StreetGreen : {
					{
						/* Default exit sequence for state StreetGreen */
						handle->stateConfVector[0] = Trafficlight_last_state;
						handle->stateConfVectorPosition = 0;
					}
					break;
				}
				case Trafficlight_main_region_on_r1_StreetRedYellow : {
					{
						/* Default exit sequence for state StreetRedYellow */
						handle->stateConfVector[0] = Trafficlight_last_state;
						handle->stateConfVectorPosition = 0;
						{
							/* Exit action for state 'StreetRedYellow'. */
							trafficlight_unsetTimer( (sc_eventid) &(handle->timeEvents.Trafficlight_main_region_on_r1_StreetRedYellow_time_event_0_raised) );		
							handle->ifaceTrafficLight.red = bool_false;
							handle->ifaceTrafficLight.yellow = bool_false;
						}
					}
					break;
				}
				case Trafficlight_main_region_on_r1_StreetRed : {
					{
						/* Default exit sequence for state StreetRed */
						handle->stateConfVector[0] = Trafficlight_last_state;
						handle->stateConfVectorPosition = 0;
						{
							/* Exit action for state 'StreetRed'. */
							trafficlight_unsetTimer( (sc_eventid) &(handle->timeEvents.Trafficlight_main_region_on_r1_StreetRed_time_event_0_raised) );		
						}
					}
					break;
				}
				case Trafficlight_main_region_on_r1_PedestrianGreen : {
					{
						/* Default exit sequence for state PedestrianGreen */
						handle->stateConfVector[0] = Trafficlight_last_state;
						handle->stateConfVectorPosition = 0;
						{
							/* Exit action for state 'PedestrianGreen'. */
							trafficlight_unsetTimer( (sc_eventid) &(handle->timeEvents.Trafficlight_main_region_on_r1_PedestrianGreen_time_event_0_raised) );		
							handle->ifacePedestrianLight.green = bool_false;
						}
					}
					break;
				}
				case Trafficlight_main_region_on_r1_AllRed : {
					{
						/* Default exit sequence for state AllRed */
						handle->stateConfVector[0] = Trafficlight_last_state;
						handle->stateConfVectorPosition = 0;
						{
							/* Exit action for state 'AllRed'. */
							trafficlight_unsetTimer( (sc_eventid) &(handle->timeEvents.Trafficlight_main_region_on_r1_AllRed_time_event_0_raised) );		
						}
					}
					break;
				}
				case Trafficlight_main_region_on_r1_StreetAttention : {
					{
						/* Default exit sequence for state StreetAttention */
						handle->stateConfVector[0] = Trafficlight_last_state;
						handle->stateConfVectorPosition = 0;
						{
							/* Exit action for state 'StreetAttention'. */
							trafficlight_unsetTimer( (sc_eventid) &(handle->timeEvents.Trafficlight_main_region_on_r1_StreetAttention_time_event_0_raised) );		
							handle->ifaceTrafficLight.yellow = bool_false;
						}
					}
					break;
				}
				case Trafficlight_main_region_on_r1_PedestrianRequesting_r2_waitOn : {
					{
						/* Default exit sequence for state waitOn */
						handle->stateConfVector[0] = Trafficlight_last_state;
						handle->stateConfVectorPosition = 0;
						{
							/* Exit action for state 'waitOn'. */
							trafficlight_unsetTimer( (sc_eventid) &(handle->timeEvents.Trafficlight_main_region_on_r1_PedestrianRequesting_r2_waitOn_time_event_0_raised) );		
							handle->ifacePedestrianLight.yellow = bool_false;
						}
					}
					{
						/* Exit action for state 'PedestrianRequesting'. */
						trafficlight_unsetTimer( (sc_eventid) &(handle->timeEvents.Trafficlight_main_region_on_r1_PedestrianRequesting_time_event_0_raised) );		
					}
					break;
				}
				case Trafficlight_main_region_on_r1_PedestrianRequesting_r2_waitOff : {
					{
						/* Default exit sequence for state waitOff */
						handle->stateConfVector[0] = Trafficlight_last_state;
						handle->stateConfVectorPosition = 0;
						{
							/* Exit action for state 'waitOff'. */
							trafficlight_unsetTimer( (sc_eventid) &(handle->timeEvents.Trafficlight_main_region_on_r1_PedestrianRequesting_r2_waitOff_time_event_0_raised) );		
						}
					}
					{
						/* Exit action for state 'PedestrianRequesting'. */
						trafficlight_unsetTimer( (sc_eventid) &(handle->timeEvents.Trafficlight_main_region_on_r1_PedestrianRequesting_time_event_0_raised) );		
					}
					break;
				}
				case Trafficlight_main_region_off_r1_YellowOn : {
					{
						/* Default exit sequence for state YellowOn */
						handle->stateConfVector[0] = Trafficlight_last_state;
						handle->stateConfVectorPosition = 0;
						{
							/* Exit action for state 'YellowOn'. */
							trafficlight_unsetTimer( (sc_eventid) &(handle->timeEvents.Trafficlight_main_region_off_r1_YellowOn_time_event_0_raised) );		
							handle->ifaceTrafficLight.yellow = bool_false;
							handle->ifacePedestrianLight.yellow = bool_false;
						}
					}
					break;
				}
				case Trafficlight_main_region_off_r1_YellowOff : {
					{
						/* Default exit sequence for state YellowOff */
						handle->stateConfVector[0] = Trafficlight_last_state;
						handle->stateConfVectorPosition = 0;
						{
							/* Exit action for state 'YellowOff'. */
							trafficlight_unsetTimer( (sc_eventid) &(handle->timeEvents.Trafficlight_main_region_off_r1_YellowOff_time_event_0_raised) );		
						}
					}
					break;
				}
				default: break;
			}
		}
		trafficlight_exitaction(handle);
	}
}

static void clearInEvents(Trafficlight* handle) {
	handle->iface.pedestrianRequest_raised = bool_false;
	handle->iface.onOff_raised = bool_false;
	handle->timeEvents.Trafficlight_main_region_on_r1_StreetRedYellow_time_event_0_raised = bool_false; 
	handle->timeEvents.Trafficlight_main_region_on_r1_StreetRed_time_event_0_raised = bool_false; 
	handle->timeEvents.Trafficlight_main_region_on_r1_PedestrianGreen_time_event_0_raised = bool_false; 
	handle->timeEvents.Trafficlight_main_region_on_r1_AllRed_time_event_0_raised = bool_false; 
	handle->timeEvents.Trafficlight_main_region_on_r1_StreetAttention_time_event_0_raised = bool_false; 
	handle->timeEvents.Trafficlight_main_region_on_r1_PedestrianRequesting_time_event_0_raised = bool_false; 
	handle->timeEvents.Trafficlight_main_region_on_r1_PedestrianRequesting_r2_waitOn_time_event_0_raised = bool_false; 
	handle->timeEvents.Trafficlight_main_region_on_r1_PedestrianRequesting_r2_waitOff_time_event_0_raised = bool_false; 
	handle->timeEvents.Trafficlight_main_region_off_r1_YellowOn_time_event_0_raised = bool_false; 
	handle->timeEvents.Trafficlight_main_region_off_r1_YellowOff_time_event_0_raised = bool_false; 
}

static void clearOutEvents(Trafficlight* handle) {
}

void trafficlight_runCycle(Trafficlight* handle) {
	
	clearOutEvents(handle);
	
	for (handle->stateConfVectorPosition = 0;
		handle->stateConfVectorPosition < TRAFFICLIGHT_MAX_ORTHOGONAL_STATES;
		handle->stateConfVectorPosition++) {
			
		switch (handle->stateConfVector[handle->stateConfVectorPosition]) {
		case Trafficlight_main_region_on_r1_StreetGreen : {
			trafficlight_react_main_region_on_r1_StreetGreen(handle);
			break;
		}
		case Trafficlight_main_region_on_r1_StreetRedYellow : {
			trafficlight_react_main_region_on_r1_StreetRedYellow(handle);
			break;
		}
		case Trafficlight_main_region_on_r1_StreetRed : {
			trafficlight_react_main_region_on_r1_StreetRed(handle);
			break;
		}
		case Trafficlight_main_region_on_r1_PedestrianGreen : {
			trafficlight_react_main_region_on_r1_PedestrianGreen(handle);
			break;
		}
		case Trafficlight_main_region_on_r1_AllRed : {
			trafficlight_react_main_region_on_r1_AllRed(handle);
			break;
		}
		case Trafficlight_main_region_on_r1_StreetAttention : {
			trafficlight_react_main_region_on_r1_StreetAttention(handle);
			break;
		}
		case Trafficlight_main_region_on_r1_PedestrianRequesting_r2_waitOn : {
			trafficlight_react_main_region_on_r1_PedestrianRequesting_r2_waitOn(handle);
			break;
		}
		case Trafficlight_main_region_on_r1_PedestrianRequesting_r2_waitOff : {
			trafficlight_react_main_region_on_r1_PedestrianRequesting_r2_waitOff(handle);
			break;
		}
		case Trafficlight_main_region_off_r1_YellowOn : {
			trafficlight_react_main_region_off_r1_YellowOn(handle);
			break;
		}
		case Trafficlight_main_region_off_r1_YellowOff : {
			trafficlight_react_main_region_off_r1_YellowOff(handle);
			break;
		}
		default:
			break;
		}
	}
	
	clearInEvents(handle);
}

void trafficlight_raiseTimeEvent(Trafficlight* handle, sc_eventid evid) {
	if ( ((intptr_t)evid) >= ((intptr_t)&(handle->timeEvents))
		&&  ((intptr_t)evid) < ((intptr_t)&(handle->timeEvents)) + sizeof(TrafficlightTimeEvents)) {
		*(sc_boolean*)evid = bool_true;
	}		
}

sc_boolean trafficlight_isActive(Trafficlight* handle, TrafficlightStates state) {
	switch (state) {
		case Trafficlight_main_region_on : 
			return (sc_boolean) (handle->stateConfVector[0] >= Trafficlight_main_region_on
				&& handle->stateConfVector[0] <= Trafficlight_main_region_on_r1_PedestrianRequesting_r2_waitOff);
		case Trafficlight_main_region_on_r1_StreetGreen : 
			return (sc_boolean) (handle->stateConfVector[0] == Trafficlight_main_region_on_r1_StreetGreen
			);
		case Trafficlight_main_region_on_r1_StreetRedYellow : 
			return (sc_boolean) (handle->stateConfVector[0] == Trafficlight_main_region_on_r1_StreetRedYellow
			);
		case Trafficlight_main_region_on_r1_StreetRed : 
			return (sc_boolean) (handle->stateConfVector[0] == Trafficlight_main_region_on_r1_StreetRed
			);
		case Trafficlight_main_region_on_r1_PedestrianGreen : 
			return (sc_boolean) (handle->stateConfVector[0] == Trafficlight_main_region_on_r1_PedestrianGreen
			);
		case Trafficlight_main_region_on_r1_AllRed : 
			return (sc_boolean) (handle->stateConfVector[0] == Trafficlight_main_region_on_r1_AllRed
			);
		case Trafficlight_main_region_on_r1_StreetAttention : 
			return (sc_boolean) (handle->stateConfVector[0] == Trafficlight_main_region_on_r1_StreetAttention
			);
		case Trafficlight_main_region_on_r1_PedestrianRequesting : 
			return (sc_boolean) (handle->stateConfVector[0] >= Trafficlight_main_region_on_r1_PedestrianRequesting
				&& handle->stateConfVector[0] <= Trafficlight_main_region_on_r1_PedestrianRequesting_r2_waitOff);
		case Trafficlight_main_region_on_r1_PedestrianRequesting_r2_waitOn : 
			return (sc_boolean) (handle->stateConfVector[0] == Trafficlight_main_region_on_r1_PedestrianRequesting_r2_waitOn
			);
		case Trafficlight_main_region_on_r1_PedestrianRequesting_r2_waitOff : 
			return (sc_boolean) (handle->stateConfVector[0] == Trafficlight_main_region_on_r1_PedestrianRequesting_r2_waitOff
			);
		case Trafficlight_main_region_off : 
			return (sc_boolean) (handle->stateConfVector[0] >= Trafficlight_main_region_off
				&& handle->stateConfVector[0] <= Trafficlight_main_region_off_r1_YellowOff);
		case Trafficlight_main_region_off_r1_YellowOn : 
			return (sc_boolean) (handle->stateConfVector[0] == Trafficlight_main_region_off_r1_YellowOn
			);
		case Trafficlight_main_region_off_r1_YellowOff : 
			return (sc_boolean) (handle->stateConfVector[0] == Trafficlight_main_region_off_r1_YellowOff
			);
		default: return bool_false;
	}
}



sc_boolean trafficlightIfaceTrafficLight_get_red(Trafficlight* handle) {
	return handle->ifaceTrafficLight.red;
}
void trafficlightIfaceTrafficLight_set_red(Trafficlight* handle, sc_boolean value) {
	handle->ifaceTrafficLight.red = value;
}
sc_boolean trafficlightIfaceTrafficLight_get_yellow(Trafficlight* handle) {
	return handle->ifaceTrafficLight.yellow;
}
void trafficlightIfaceTrafficLight_set_yellow(Trafficlight* handle, sc_boolean value) {
	handle->ifaceTrafficLight.yellow = value;
}
sc_boolean trafficlightIfaceTrafficLight_get_green(Trafficlight* handle) {
	return handle->ifaceTrafficLight.green;
}
void trafficlightIfaceTrafficLight_set_green(Trafficlight* handle, sc_boolean value) {
	handle->ifaceTrafficLight.green = value;
}


sc_boolean trafficlightIfacePedestrianLight_get_red(Trafficlight* handle) {
	return handle->ifacePedestrianLight.red;
}
void trafficlightIfacePedestrianLight_set_red(Trafficlight* handle, sc_boolean value) {
	handle->ifacePedestrianLight.red = value;
}
sc_boolean trafficlightIfacePedestrianLight_get_yellow(Trafficlight* handle) {
	return handle->ifacePedestrianLight.yellow;
}
void trafficlightIfacePedestrianLight_set_yellow(Trafficlight* handle, sc_boolean value) {
	handle->ifacePedestrianLight.yellow = value;
}
sc_boolean trafficlightIfacePedestrianLight_get_green(Trafficlight* handle) {
	return handle->ifacePedestrianLight.green;
}
void trafficlightIfacePedestrianLight_set_green(Trafficlight* handle, sc_boolean value) {
	handle->ifacePedestrianLight.green = value;
}
void trafficlightIface_raise_pedestrianRequest(Trafficlight* handle) {
	handle->iface.pedestrianRequest_raised = bool_true;
}
void trafficlightIface_raise_onOff(Trafficlight* handle) {
	handle->iface.onOff_raised = bool_true;
}


		
// implementations of all internal functions

/* Entry action for statechart 'Trafficlight'. */
static void trafficlight_entryaction(Trafficlight* handle) {
	{
		/* Entry action for statechart 'Trafficlight'. */
	}
}

/* Exit action for state 'Trafficlight'. */
static void trafficlight_exitaction(Trafficlight* handle) {
	{
		/* Exit action for state 'Trafficlight'. */
	}
}

/* The reactions of state StreetGreen. */
static void trafficlight_react_main_region_on_r1_StreetGreen(Trafficlight* handle) {
	{
		/* The reactions of state StreetGreen. */
		if (handle->iface.onOff_raised) { 
			{
				/* Default exit sequence for state on */
				{
					/* Default exit sequence for region r1 */
					/* Handle exit of all possible states (of r1) at position 0... */
					switch(handle->stateConfVector[ 0 ]) {
						case Trafficlight_main_region_on_r1_StreetGreen : {
							{
								/* Default exit sequence for state StreetGreen */
								handle->stateConfVector[0] = Trafficlight_last_state;
								handle->stateConfVectorPosition = 0;
							}
							break;
						}
						case Trafficlight_main_region_on_r1_StreetRedYellow : {
							{
								/* Default exit sequence for state StreetRedYellow */
								handle->stateConfVector[0] = Trafficlight_last_state;
								handle->stateConfVectorPosition = 0;
								{
									/* Exit action for state 'StreetRedYellow'. */
									trafficlight_unsetTimer( (sc_eventid) &(handle->timeEvents.Trafficlight_main_region_on_r1_StreetRedYellow_time_event_0_raised) );		
									handle->ifaceTrafficLight.red = bool_false;
									handle->ifaceTrafficLight.yellow = bool_false;
								}
							}
							break;
						}
						case Trafficlight_main_region_on_r1_StreetRed : {
							{
								/* Default exit sequence for state StreetRed */
								handle->stateConfVector[0] = Trafficlight_last_state;
								handle->stateConfVectorPosition = 0;
								{
									/* Exit action for state 'StreetRed'. */
									trafficlight_unsetTimer( (sc_eventid) &(handle->timeEvents.Trafficlight_main_region_on_r1_StreetRed_time_event_0_raised) );		
								}
							}
							break;
						}
						case Trafficlight_main_region_on_r1_PedestrianGreen : {
							{
								/* Default exit sequence for state PedestrianGreen */
								handle->stateConfVector[0] = Trafficlight_last_state;
								handle->stateConfVectorPosition = 0;
								{
									/* Exit action for state 'PedestrianGreen'. */
									trafficlight_unsetTimer( (sc_eventid) &(handle->timeEvents.Trafficlight_main_region_on_r1_PedestrianGreen_time_event_0_raised) );		
									handle->ifacePedestrianLight.green = bool_false;
								}
							}
							break;
						}
						case Trafficlight_main_region_on_r1_AllRed : {
							{
								/* Default exit sequence for state AllRed */
								handle->stateConfVector[0] = Trafficlight_last_state;
								handle->stateConfVectorPosition = 0;
								{
									/* Exit action for state 'AllRed'. */
									trafficlight_unsetTimer( (sc_eventid) &(handle->timeEvents.Trafficlight_main_region_on_r1_AllRed_time_event_0_raised) );		
								}
							}
							break;
						}
						case Trafficlight_main_region_on_r1_StreetAttention : {
							{
								/* Default exit sequence for state StreetAttention */
								handle->stateConfVector[0] = Trafficlight_last_state;
								handle->stateConfVectorPosition = 0;
								{
									/* Exit action for state 'StreetAttention'. */
									trafficlight_unsetTimer( (sc_eventid) &(handle->timeEvents.Trafficlight_main_region_on_r1_StreetAttention_time_event_0_raised) );		
									handle->ifaceTrafficLight.yellow = bool_false;
								}
							}
							break;
						}
						case Trafficlight_main_region_on_r1_PedestrianRequesting_r2_waitOn : {
							{
								/* Default exit sequence for state waitOn */
								handle->stateConfVector[0] = Trafficlight_last_state;
								handle->stateConfVectorPosition = 0;
								{
									/* Exit action for state 'waitOn'. */
									trafficlight_unsetTimer( (sc_eventid) &(handle->timeEvents.Trafficlight_main_region_on_r1_PedestrianRequesting_r2_waitOn_time_event_0_raised) );		
									handle->ifacePedestrianLight.yellow = bool_false;
								}
							}
							{
								/* Exit action for state 'PedestrianRequesting'. */
								trafficlight_unsetTimer( (sc_eventid) &(handle->timeEvents.Trafficlight_main_region_on_r1_PedestrianRequesting_time_event_0_raised) );		
							}
							break;
						}
						case Trafficlight_main_region_on_r1_PedestrianRequesting_r2_waitOff : {
							{
								/* Default exit sequence for state waitOff */
								handle->stateConfVector[0] = Trafficlight_last_state;
								handle->stateConfVectorPosition = 0;
								{
									/* Exit action for state 'waitOff'. */
									trafficlight_unsetTimer( (sc_eventid) &(handle->timeEvents.Trafficlight_main_region_on_r1_PedestrianRequesting_r2_waitOff_time_event_0_raised) );		
								}
							}
							{
								/* Exit action for state 'PedestrianRequesting'. */
								trafficlight_unsetTimer( (sc_eventid) &(handle->timeEvents.Trafficlight_main_region_on_r1_PedestrianRequesting_time_event_0_raised) );		
							}
							break;
						}
						default: break;
					}
				}
			}
			{
				/* 'default' enter sequence for state off */
				{
					/* 'default' enter sequence for region r1 */
					{
						/* Default react sequence for initial entry  */
						{
							/* 'default' enter sequence for state YellowOn */
							{
								/* Entry action for state 'YellowOn'. */
								trafficlight_setTimer( (sc_eventid) &(handle->timeEvents.Trafficlight_main_region_off_r1_YellowOn_time_event_0_raised) , 500, bool_false);
								handle->ifaceTrafficLight.yellow = bool_true;
								handle->ifacePedestrianLight.yellow = bool_true;
							}
							handle->stateConfVector[0] = Trafficlight_main_region_off_r1_YellowOn;
							handle->stateConfVectorPosition = 0;
						}
					}
				}
			}
		}  else {
			if (handle->iface.pedestrianRequest_raised) { 
				{
					/* Default exit sequence for state StreetGreen */
					handle->stateConfVector[0] = Trafficlight_last_state;
					handle->stateConfVectorPosition = 0;
				}
				{
					/* 'default' enter sequence for state PedestrianRequesting */
					{
						/* Entry action for state 'PedestrianRequesting'. */
						trafficlight_setTimer( (sc_eventid) &(handle->timeEvents.Trafficlight_main_region_on_r1_PedestrianRequesting_time_event_0_raised) , 5 * 1000, bool_false);
					}
					{
						/* 'default' enter sequence for region r2 */
						{
							/* Default react sequence for initial entry  */
							{
								/* 'default' enter sequence for state waitOn */
								{
									/* Entry action for state 'waitOn'. */
									trafficlight_setTimer( (sc_eventid) &(handle->timeEvents.Trafficlight_main_region_on_r1_PedestrianRequesting_r2_waitOn_time_event_0_raised) , 500, bool_false);
									handle->ifacePedestrianLight.yellow = bool_true;
								}
								handle->stateConfVector[0] = Trafficlight_main_region_on_r1_PedestrianRequesting_r2_waitOn;
								handle->stateConfVectorPosition = 0;
							}
						}
					}
				}
			} 
		}
	}
}

/* The reactions of state StreetRedYellow. */
static void trafficlight_react_main_region_on_r1_StreetRedYellow(Trafficlight* handle) {
	{
		/* The reactions of state StreetRedYellow. */
		if (handle->iface.onOff_raised) { 
			{
				/* Default exit sequence for state on */
				{
					/* Default exit sequence for region r1 */
					/* Handle exit of all possible states (of r1) at position 0... */
					switch(handle->stateConfVector[ 0 ]) {
						case Trafficlight_main_region_on_r1_StreetGreen : {
							{
								/* Default exit sequence for state StreetGreen */
								handle->stateConfVector[0] = Trafficlight_last_state;
								handle->stateConfVectorPosition = 0;
							}
							break;
						}
						case Trafficlight_main_region_on_r1_StreetRedYellow : {
							{
								/* Default exit sequence for state StreetRedYellow */
								handle->stateConfVector[0] = Trafficlight_last_state;
								handle->stateConfVectorPosition = 0;
								{
									/* Exit action for state 'StreetRedYellow'. */
									trafficlight_unsetTimer( (sc_eventid) &(handle->timeEvents.Trafficlight_main_region_on_r1_StreetRedYellow_time_event_0_raised) );		
									handle->ifaceTrafficLight.red = bool_false;
									handle->ifaceTrafficLight.yellow = bool_false;
								}
							}
							break;
						}
						case Trafficlight_main_region_on_r1_StreetRed : {
							{
								/* Default exit sequence for state StreetRed */
								handle->stateConfVector[0] = Trafficlight_last_state;
								handle->stateConfVectorPosition = 0;
								{
									/* Exit action for state 'StreetRed'. */
									trafficlight_unsetTimer( (sc_eventid) &(handle->timeEvents.Trafficlight_main_region_on_r1_StreetRed_time_event_0_raised) );		
								}
							}
							break;
						}
						case Trafficlight_main_region_on_r1_PedestrianGreen : {
							{
								/* Default exit sequence for state PedestrianGreen */
								handle->stateConfVector[0] = Trafficlight_last_state;
								handle->stateConfVectorPosition = 0;
								{
									/* Exit action for state 'PedestrianGreen'. */
									trafficlight_unsetTimer( (sc_eventid) &(handle->timeEvents.Trafficlight_main_region_on_r1_PedestrianGreen_time_event_0_raised) );		
									handle->ifacePedestrianLight.green = bool_false;
								}
							}
							break;
						}
						case Trafficlight_main_region_on_r1_AllRed : {
							{
								/* Default exit sequence for state AllRed */
								handle->stateConfVector[0] = Trafficlight_last_state;
								handle->stateConfVectorPosition = 0;
								{
									/* Exit action for state 'AllRed'. */
									trafficlight_unsetTimer( (sc_eventid) &(handle->timeEvents.Trafficlight_main_region_on_r1_AllRed_time_event_0_raised) );		
								}
							}
							break;
						}
						case Trafficlight_main_region_on_r1_StreetAttention : {
							{
								/* Default exit sequence for state StreetAttention */
								handle->stateConfVector[0] = Trafficlight_last_state;
								handle->stateConfVectorPosition = 0;
								{
									/* Exit action for state 'StreetAttention'. */
									trafficlight_unsetTimer( (sc_eventid) &(handle->timeEvents.Trafficlight_main_region_on_r1_StreetAttention_time_event_0_raised) );		
									handle->ifaceTrafficLight.yellow = bool_false;
								}
							}
							break;
						}
						case Trafficlight_main_region_on_r1_PedestrianRequesting_r2_waitOn : {
							{
								/* Default exit sequence for state waitOn */
								handle->stateConfVector[0] = Trafficlight_last_state;
								handle->stateConfVectorPosition = 0;
								{
									/* Exit action for state 'waitOn'. */
									trafficlight_unsetTimer( (sc_eventid) &(handle->timeEvents.Trafficlight_main_region_on_r1_PedestrianRequesting_r2_waitOn_time_event_0_raised) );		
									handle->ifacePedestrianLight.yellow = bool_false;
								}
							}
							{
								/* Exit action for state 'PedestrianRequesting'. */
								trafficlight_unsetTimer( (sc_eventid) &(handle->timeEvents.Trafficlight_main_region_on_r1_PedestrianRequesting_time_event_0_raised) );		
							}
							break;
						}
						case Trafficlight_main_region_on_r1_PedestrianRequesting_r2_waitOff : {
							{
								/* Default exit sequence for state waitOff */
								handle->stateConfVector[0] = Trafficlight_last_state;
								handle->stateConfVectorPosition = 0;
								{
									/* Exit action for state 'waitOff'. */
									trafficlight_unsetTimer( (sc_eventid) &(handle->timeEvents.Trafficlight_main_region_on_r1_PedestrianRequesting_r2_waitOff_time_event_0_raised) );		
								}
							}
							{
								/* Exit action for state 'PedestrianRequesting'. */
								trafficlight_unsetTimer( (sc_eventid) &(handle->timeEvents.Trafficlight_main_region_on_r1_PedestrianRequesting_time_event_0_raised) );		
							}
							break;
						}
						default: break;
					}
				}
			}
			{
				/* 'default' enter sequence for state off */
				{
					/* 'default' enter sequence for region r1 */
					{
						/* Default react sequence for initial entry  */
						{
							/* 'default' enter sequence for state YellowOn */
							{
								/* Entry action for state 'YellowOn'. */
								trafficlight_setTimer( (sc_eventid) &(handle->timeEvents.Trafficlight_main_region_off_r1_YellowOn_time_event_0_raised) , 500, bool_false);
								handle->ifaceTrafficLight.yellow = bool_true;
								handle->ifacePedestrianLight.yellow = bool_true;
							}
							handle->stateConfVector[0] = Trafficlight_main_region_off_r1_YellowOn;
							handle->stateConfVectorPosition = 0;
						}
					}
				}
			}
		}  else {
			if (handle->timeEvents.Trafficlight_main_region_on_r1_StreetRedYellow_time_event_0_raised) { 
				{
					/* Default exit sequence for state StreetRedYellow */
					handle->stateConfVector[0] = Trafficlight_last_state;
					handle->stateConfVectorPosition = 0;
					{
						/* Exit action for state 'StreetRedYellow'. */
						trafficlight_unsetTimer( (sc_eventid) &(handle->timeEvents.Trafficlight_main_region_on_r1_StreetRedYellow_time_event_0_raised) );		
						handle->ifaceTrafficLight.red = bool_false;
						handle->ifaceTrafficLight.yellow = bool_false;
					}
				}
				{
					/* 'default' enter sequence for state StreetGreen */
					{
						/* Entry action for state 'StreetGreen'. */
						handle->ifaceTrafficLight.green = bool_true;
					}
					handle->stateConfVector[0] = Trafficlight_main_region_on_r1_StreetGreen;
					handle->stateConfVectorPosition = 0;
				}
			} 
		}
	}
}

/* The reactions of state StreetRed. */
static void trafficlight_react_main_region_on_r1_StreetRed(Trafficlight* handle) {
	{
		/* The reactions of state StreetRed. */
		if (handle->iface.onOff_raised) { 
			{
				/* Default exit sequence for state on */
				{
					/* Default exit sequence for region r1 */
					/* Handle exit of all possible states (of r1) at position 0... */
					switch(handle->stateConfVector[ 0 ]) {
						case Trafficlight_main_region_on_r1_StreetGreen : {
							{
								/* Default exit sequence for state StreetGreen */
								handle->stateConfVector[0] = Trafficlight_last_state;
								handle->stateConfVectorPosition = 0;
							}
							break;
						}
						case Trafficlight_main_region_on_r1_StreetRedYellow : {
							{
								/* Default exit sequence for state StreetRedYellow */
								handle->stateConfVector[0] = Trafficlight_last_state;
								handle->stateConfVectorPosition = 0;
								{
									/* Exit action for state 'StreetRedYellow'. */
									trafficlight_unsetTimer( (sc_eventid) &(handle->timeEvents.Trafficlight_main_region_on_r1_StreetRedYellow_time_event_0_raised) );		
									handle->ifaceTrafficLight.red = bool_false;
									handle->ifaceTrafficLight.yellow = bool_false;
								}
							}
							break;
						}
						case Trafficlight_main_region_on_r1_StreetRed : {
							{
								/* Default exit sequence for state StreetRed */
								handle->stateConfVector[0] = Trafficlight_last_state;
								handle->stateConfVectorPosition = 0;
								{
									/* Exit action for state 'StreetRed'. */
									trafficlight_unsetTimer( (sc_eventid) &(handle->timeEvents.Trafficlight_main_region_on_r1_StreetRed_time_event_0_raised) );		
								}
							}
							break;
						}
						case Trafficlight_main_region_on_r1_PedestrianGreen : {
							{
								/* Default exit sequence for state PedestrianGreen */
								handle->stateConfVector[0] = Trafficlight_last_state;
								handle->stateConfVectorPosition = 0;
								{
									/* Exit action for state 'PedestrianGreen'. */
									trafficlight_unsetTimer( (sc_eventid) &(handle->timeEvents.Trafficlight_main_region_on_r1_PedestrianGreen_time_event_0_raised) );		
									handle->ifacePedestrianLight.green = bool_false;
								}
							}
							break;
						}
						case Trafficlight_main_region_on_r1_AllRed : {
							{
								/* Default exit sequence for state AllRed */
								handle->stateConfVector[0] = Trafficlight_last_state;
								handle->stateConfVectorPosition = 0;
								{
									/* Exit action for state 'AllRed'. */
									trafficlight_unsetTimer( (sc_eventid) &(handle->timeEvents.Trafficlight_main_region_on_r1_AllRed_time_event_0_raised) );		
								}
							}
							break;
						}
						case Trafficlight_main_region_on_r1_StreetAttention : {
							{
								/* Default exit sequence for state StreetAttention */
								handle->stateConfVector[0] = Trafficlight_last_state;
								handle->stateConfVectorPosition = 0;
								{
									/* Exit action for state 'StreetAttention'. */
									trafficlight_unsetTimer( (sc_eventid) &(handle->timeEvents.Trafficlight_main_region_on_r1_StreetAttention_time_event_0_raised) );		
									handle->ifaceTrafficLight.yellow = bool_false;
								}
							}
							break;
						}
						case Trafficlight_main_region_on_r1_PedestrianRequesting_r2_waitOn : {
							{
								/* Default exit sequence for state waitOn */
								handle->stateConfVector[0] = Trafficlight_last_state;
								handle->stateConfVectorPosition = 0;
								{
									/* Exit action for state 'waitOn'. */
									trafficlight_unsetTimer( (sc_eventid) &(handle->timeEvents.Trafficlight_main_region_on_r1_PedestrianRequesting_r2_waitOn_time_event_0_raised) );		
									handle->ifacePedestrianLight.yellow = bool_false;
								}
							}
							{
								/* Exit action for state 'PedestrianRequesting'. */
								trafficlight_unsetTimer( (sc_eventid) &(handle->timeEvents.Trafficlight_main_region_on_r1_PedestrianRequesting_time_event_0_raised) );		
							}
							break;
						}
						case Trafficlight_main_region_on_r1_PedestrianRequesting_r2_waitOff : {
							{
								/* Default exit sequence for state waitOff */
								handle->stateConfVector[0] = Trafficlight_last_state;
								handle->stateConfVectorPosition = 0;
								{
									/* Exit action for state 'waitOff'. */
									trafficlight_unsetTimer( (sc_eventid) &(handle->timeEvents.Trafficlight_main_region_on_r1_PedestrianRequesting_r2_waitOff_time_event_0_raised) );		
								}
							}
							{
								/* Exit action for state 'PedestrianRequesting'. */
								trafficlight_unsetTimer( (sc_eventid) &(handle->timeEvents.Trafficlight_main_region_on_r1_PedestrianRequesting_time_event_0_raised) );		
							}
							break;
						}
						default: break;
					}
				}
			}
			{
				/* 'default' enter sequence for state off */
				{
					/* 'default' enter sequence for region r1 */
					{
						/* Default react sequence for initial entry  */
						{
							/* 'default' enter sequence for state YellowOn */
							{
								/* Entry action for state 'YellowOn'. */
								trafficlight_setTimer( (sc_eventid) &(handle->timeEvents.Trafficlight_main_region_off_r1_YellowOn_time_event_0_raised) , 500, bool_false);
								handle->ifaceTrafficLight.yellow = bool_true;
								handle->ifacePedestrianLight.yellow = bool_true;
							}
							handle->stateConfVector[0] = Trafficlight_main_region_off_r1_YellowOn;
							handle->stateConfVectorPosition = 0;
						}
					}
				}
			}
		}  else {
			if (handle->timeEvents.Trafficlight_main_region_on_r1_StreetRed_time_event_0_raised) { 
				{
					/* Default exit sequence for state StreetRed */
					handle->stateConfVector[0] = Trafficlight_last_state;
					handle->stateConfVectorPosition = 0;
					{
						/* Exit action for state 'StreetRed'. */
						trafficlight_unsetTimer( (sc_eventid) &(handle->timeEvents.Trafficlight_main_region_on_r1_StreetRed_time_event_0_raised) );		
					}
				}
				{
					/* 'default' enter sequence for state PedestrianGreen */
					{
						/* Entry action for state 'PedestrianGreen'. */
						trafficlight_setTimer( (sc_eventid) &(handle->timeEvents.Trafficlight_main_region_on_r1_PedestrianGreen_time_event_0_raised) , 7 * 1000, bool_false);
						handle->ifacePedestrianLight.green = bool_true;
						handle->ifacePedestrianLight.red = bool_false;
					}
					handle->stateConfVector[0] = Trafficlight_main_region_on_r1_PedestrianGreen;
					handle->stateConfVectorPosition = 0;
				}
			} 
		}
	}
}

/* The reactions of state PedestrianGreen. */
static void trafficlight_react_main_region_on_r1_PedestrianGreen(Trafficlight* handle) {
	{
		/* The reactions of state PedestrianGreen. */
		if (handle->iface.onOff_raised) { 
			{
				/* Default exit sequence for state on */
				{
					/* Default exit sequence for region r1 */
					/* Handle exit of all possible states (of r1) at position 0... */
					switch(handle->stateConfVector[ 0 ]) {
						case Trafficlight_main_region_on_r1_StreetGreen : {
							{
								/* Default exit sequence for state StreetGreen */
								handle->stateConfVector[0] = Trafficlight_last_state;
								handle->stateConfVectorPosition = 0;
							}
							break;
						}
						case Trafficlight_main_region_on_r1_StreetRedYellow : {
							{
								/* Default exit sequence for state StreetRedYellow */
								handle->stateConfVector[0] = Trafficlight_last_state;
								handle->stateConfVectorPosition = 0;
								{
									/* Exit action for state 'StreetRedYellow'. */
									trafficlight_unsetTimer( (sc_eventid) &(handle->timeEvents.Trafficlight_main_region_on_r1_StreetRedYellow_time_event_0_raised) );		
									handle->ifaceTrafficLight.red = bool_false;
									handle->ifaceTrafficLight.yellow = bool_false;
								}
							}
							break;
						}
						case Trafficlight_main_region_on_r1_StreetRed : {
							{
								/* Default exit sequence for state StreetRed */
								handle->stateConfVector[0] = Trafficlight_last_state;
								handle->stateConfVectorPosition = 0;
								{
									/* Exit action for state 'StreetRed'. */
									trafficlight_unsetTimer( (sc_eventid) &(handle->timeEvents.Trafficlight_main_region_on_r1_StreetRed_time_event_0_raised) );		
								}
							}
							break;
						}
						case Trafficlight_main_region_on_r1_PedestrianGreen : {
							{
								/* Default exit sequence for state PedestrianGreen */
								handle->stateConfVector[0] = Trafficlight_last_state;
								handle->stateConfVectorPosition = 0;
								{
									/* Exit action for state 'PedestrianGreen'. */
									trafficlight_unsetTimer( (sc_eventid) &(handle->timeEvents.Trafficlight_main_region_on_r1_PedestrianGreen_time_event_0_raised) );		
									handle->ifacePedestrianLight.green = bool_false;
								}
							}
							break;
						}
						case Trafficlight_main_region_on_r1_AllRed : {
							{
								/* Default exit sequence for state AllRed */
								handle->stateConfVector[0] = Trafficlight_last_state;
								handle->stateConfVectorPosition = 0;
								{
									/* Exit action for state 'AllRed'. */
									trafficlight_unsetTimer( (sc_eventid) &(handle->timeEvents.Trafficlight_main_region_on_r1_AllRed_time_event_0_raised) );		
								}
							}
							break;
						}
						case Trafficlight_main_region_on_r1_StreetAttention : {
							{
								/* Default exit sequence for state StreetAttention */
								handle->stateConfVector[0] = Trafficlight_last_state;
								handle->stateConfVectorPosition = 0;
								{
									/* Exit action for state 'StreetAttention'. */
									trafficlight_unsetTimer( (sc_eventid) &(handle->timeEvents.Trafficlight_main_region_on_r1_StreetAttention_time_event_0_raised) );		
									handle->ifaceTrafficLight.yellow = bool_false;
								}
							}
							break;
						}
						case Trafficlight_main_region_on_r1_PedestrianRequesting_r2_waitOn : {
							{
								/* Default exit sequence for state waitOn */
								handle->stateConfVector[0] = Trafficlight_last_state;
								handle->stateConfVectorPosition = 0;
								{
									/* Exit action for state 'waitOn'. */
									trafficlight_unsetTimer( (sc_eventid) &(handle->timeEvents.Trafficlight_main_region_on_r1_PedestrianRequesting_r2_waitOn_time_event_0_raised) );		
									handle->ifacePedestrianLight.yellow = bool_false;
								}
							}
							{
								/* Exit action for state 'PedestrianRequesting'. */
								trafficlight_unsetTimer( (sc_eventid) &(handle->timeEvents.Trafficlight_main_region_on_r1_PedestrianRequesting_time_event_0_raised) );		
							}
							break;
						}
						case Trafficlight_main_region_on_r1_PedestrianRequesting_r2_waitOff : {
							{
								/* Default exit sequence for state waitOff */
								handle->stateConfVector[0] = Trafficlight_last_state;
								handle->stateConfVectorPosition = 0;
								{
									/* Exit action for state 'waitOff'. */
									trafficlight_unsetTimer( (sc_eventid) &(handle->timeEvents.Trafficlight_main_region_on_r1_PedestrianRequesting_r2_waitOff_time_event_0_raised) );		
								}
							}
							{
								/* Exit action for state 'PedestrianRequesting'. */
								trafficlight_unsetTimer( (sc_eventid) &(handle->timeEvents.Trafficlight_main_region_on_r1_PedestrianRequesting_time_event_0_raised) );		
							}
							break;
						}
						default: break;
					}
				}
			}
			{
				/* 'default' enter sequence for state off */
				{
					/* 'default' enter sequence for region r1 */
					{
						/* Default react sequence for initial entry  */
						{
							/* 'default' enter sequence for state YellowOn */
							{
								/* Entry action for state 'YellowOn'. */
								trafficlight_setTimer( (sc_eventid) &(handle->timeEvents.Trafficlight_main_region_off_r1_YellowOn_time_event_0_raised) , 500, bool_false);
								handle->ifaceTrafficLight.yellow = bool_true;
								handle->ifacePedestrianLight.yellow = bool_true;
							}
							handle->stateConfVector[0] = Trafficlight_main_region_off_r1_YellowOn;
							handle->stateConfVectorPosition = 0;
						}
					}
				}
			}
		}  else {
			if (handle->timeEvents.Trafficlight_main_region_on_r1_PedestrianGreen_time_event_0_raised) { 
				{
					/* Default exit sequence for state PedestrianGreen */
					handle->stateConfVector[0] = Trafficlight_last_state;
					handle->stateConfVectorPosition = 0;
					{
						/* Exit action for state 'PedestrianGreen'. */
						trafficlight_unsetTimer( (sc_eventid) &(handle->timeEvents.Trafficlight_main_region_on_r1_PedestrianGreen_time_event_0_raised) );		
						handle->ifacePedestrianLight.green = bool_false;
					}
				}
				{
					/* 'default' enter sequence for state AllRed */
					{
						/* Entry action for state 'AllRed'. */
						trafficlight_setTimer( (sc_eventid) &(handle->timeEvents.Trafficlight_main_region_on_r1_AllRed_time_event_0_raised) , 500, bool_false);
						handle->ifacePedestrianLight.red = bool_true;
						handle->ifaceTrafficLight.red = bool_true;
					}
					handle->stateConfVector[0] = Trafficlight_main_region_on_r1_AllRed;
					handle->stateConfVectorPosition = 0;
				}
			} 
		}
	}
}

/* The reactions of state AllRed. */
static void trafficlight_react_main_region_on_r1_AllRed(Trafficlight* handle) {
	{
		/* The reactions of state AllRed. */
		if (handle->iface.onOff_raised) { 
			{
				/* Default exit sequence for state on */
				{
					/* Default exit sequence for region r1 */
					/* Handle exit of all possible states (of r1) at position 0... */
					switch(handle->stateConfVector[ 0 ]) {
						case Trafficlight_main_region_on_r1_StreetGreen : {
							{
								/* Default exit sequence for state StreetGreen */
								handle->stateConfVector[0] = Trafficlight_last_state;
								handle->stateConfVectorPosition = 0;
							}
							break;
						}
						case Trafficlight_main_region_on_r1_StreetRedYellow : {
							{
								/* Default exit sequence for state StreetRedYellow */
								handle->stateConfVector[0] = Trafficlight_last_state;
								handle->stateConfVectorPosition = 0;
								{
									/* Exit action for state 'StreetRedYellow'. */
									trafficlight_unsetTimer( (sc_eventid) &(handle->timeEvents.Trafficlight_main_region_on_r1_StreetRedYellow_time_event_0_raised) );		
									handle->ifaceTrafficLight.red = bool_false;
									handle->ifaceTrafficLight.yellow = bool_false;
								}
							}
							break;
						}
						case Trafficlight_main_region_on_r1_StreetRed : {
							{
								/* Default exit sequence for state StreetRed */
								handle->stateConfVector[0] = Trafficlight_last_state;
								handle->stateConfVectorPosition = 0;
								{
									/* Exit action for state 'StreetRed'. */
									trafficlight_unsetTimer( (sc_eventid) &(handle->timeEvents.Trafficlight_main_region_on_r1_StreetRed_time_event_0_raised) );		
								}
							}
							break;
						}
						case Trafficlight_main_region_on_r1_PedestrianGreen : {
							{
								/* Default exit sequence for state PedestrianGreen */
								handle->stateConfVector[0] = Trafficlight_last_state;
								handle->stateConfVectorPosition = 0;
								{
									/* Exit action for state 'PedestrianGreen'. */
									trafficlight_unsetTimer( (sc_eventid) &(handle->timeEvents.Trafficlight_main_region_on_r1_PedestrianGreen_time_event_0_raised) );		
									handle->ifacePedestrianLight.green = bool_false;
								}
							}
							break;
						}
						case Trafficlight_main_region_on_r1_AllRed : {
							{
								/* Default exit sequence for state AllRed */
								handle->stateConfVector[0] = Trafficlight_last_state;
								handle->stateConfVectorPosition = 0;
								{
									/* Exit action for state 'AllRed'. */
									trafficlight_unsetTimer( (sc_eventid) &(handle->timeEvents.Trafficlight_main_region_on_r1_AllRed_time_event_0_raised) );		
								}
							}
							break;
						}
						case Trafficlight_main_region_on_r1_StreetAttention : {
							{
								/* Default exit sequence for state StreetAttention */
								handle->stateConfVector[0] = Trafficlight_last_state;
								handle->stateConfVectorPosition = 0;
								{
									/* Exit action for state 'StreetAttention'. */
									trafficlight_unsetTimer( (sc_eventid) &(handle->timeEvents.Trafficlight_main_region_on_r1_StreetAttention_time_event_0_raised) );		
									handle->ifaceTrafficLight.yellow = bool_false;
								}
							}
							break;
						}
						case Trafficlight_main_region_on_r1_PedestrianRequesting_r2_waitOn : {
							{
								/* Default exit sequence for state waitOn */
								handle->stateConfVector[0] = Trafficlight_last_state;
								handle->stateConfVectorPosition = 0;
								{
									/* Exit action for state 'waitOn'. */
									trafficlight_unsetTimer( (sc_eventid) &(handle->timeEvents.Trafficlight_main_region_on_r1_PedestrianRequesting_r2_waitOn_time_event_0_raised) );		
									handle->ifacePedestrianLight.yellow = bool_false;
								}
							}
							{
								/* Exit action for state 'PedestrianRequesting'. */
								trafficlight_unsetTimer( (sc_eventid) &(handle->timeEvents.Trafficlight_main_region_on_r1_PedestrianRequesting_time_event_0_raised) );		
							}
							break;
						}
						case Trafficlight_main_region_on_r1_PedestrianRequesting_r2_waitOff : {
							{
								/* Default exit sequence for state waitOff */
								handle->stateConfVector[0] = Trafficlight_last_state;
								handle->stateConfVectorPosition = 0;
								{
									/* Exit action for state 'waitOff'. */
									trafficlight_unsetTimer( (sc_eventid) &(handle->timeEvents.Trafficlight_main_region_on_r1_PedestrianRequesting_r2_waitOff_time_event_0_raised) );		
								}
							}
							{
								/* Exit action for state 'PedestrianRequesting'. */
								trafficlight_unsetTimer( (sc_eventid) &(handle->timeEvents.Trafficlight_main_region_on_r1_PedestrianRequesting_time_event_0_raised) );		
							}
							break;
						}
						default: break;
					}
				}
			}
			{
				/* 'default' enter sequence for state off */
				{
					/* 'default' enter sequence for region r1 */
					{
						/* Default react sequence for initial entry  */
						{
							/* 'default' enter sequence for state YellowOn */
							{
								/* Entry action for state 'YellowOn'. */
								trafficlight_setTimer( (sc_eventid) &(handle->timeEvents.Trafficlight_main_region_off_r1_YellowOn_time_event_0_raised) , 500, bool_false);
								handle->ifaceTrafficLight.yellow = bool_true;
								handle->ifacePedestrianLight.yellow = bool_true;
							}
							handle->stateConfVector[0] = Trafficlight_main_region_off_r1_YellowOn;
							handle->stateConfVectorPosition = 0;
						}
					}
				}
			}
		}  else {
			if (handle->timeEvents.Trafficlight_main_region_on_r1_AllRed_time_event_0_raised) { 
				{
					/* Default exit sequence for state AllRed */
					handle->stateConfVector[0] = Trafficlight_last_state;
					handle->stateConfVectorPosition = 0;
					{
						/* Exit action for state 'AllRed'. */
						trafficlight_unsetTimer( (sc_eventid) &(handle->timeEvents.Trafficlight_main_region_on_r1_AllRed_time_event_0_raised) );		
					}
				}
				{
					/* 'default' enter sequence for state StreetRedYellow */
					{
						/* Entry action for state 'StreetRedYellow'. */
						trafficlight_setTimer( (sc_eventid) &(handle->timeEvents.Trafficlight_main_region_on_r1_StreetRedYellow_time_event_0_raised) , 2 * 1000, bool_false);
						handle->ifaceTrafficLight.red = bool_true;
						handle->ifaceTrafficLight.yellow = bool_true;
					}
					handle->stateConfVector[0] = Trafficlight_main_region_on_r1_StreetRedYellow;
					handle->stateConfVectorPosition = 0;
				}
			} 
		}
	}
}

/* The reactions of state StreetAttention. */
static void trafficlight_react_main_region_on_r1_StreetAttention(Trafficlight* handle) {
	{
		/* The reactions of state StreetAttention. */
		if (handle->iface.onOff_raised) { 
			{
				/* Default exit sequence for state on */
				{
					/* Default exit sequence for region r1 */
					/* Handle exit of all possible states (of r1) at position 0... */
					switch(handle->stateConfVector[ 0 ]) {
						case Trafficlight_main_region_on_r1_StreetGreen : {
							{
								/* Default exit sequence for state StreetGreen */
								handle->stateConfVector[0] = Trafficlight_last_state;
								handle->stateConfVectorPosition = 0;
							}
							break;
						}
						case Trafficlight_main_region_on_r1_StreetRedYellow : {
							{
								/* Default exit sequence for state StreetRedYellow */
								handle->stateConfVector[0] = Trafficlight_last_state;
								handle->stateConfVectorPosition = 0;
								{
									/* Exit action for state 'StreetRedYellow'. */
									trafficlight_unsetTimer( (sc_eventid) &(handle->timeEvents.Trafficlight_main_region_on_r1_StreetRedYellow_time_event_0_raised) );		
									handle->ifaceTrafficLight.red = bool_false;
									handle->ifaceTrafficLight.yellow = bool_false;
								}
							}
							break;
						}
						case Trafficlight_main_region_on_r1_StreetRed : {
							{
								/* Default exit sequence for state StreetRed */
								handle->stateConfVector[0] = Trafficlight_last_state;
								handle->stateConfVectorPosition = 0;
								{
									/* Exit action for state 'StreetRed'. */
									trafficlight_unsetTimer( (sc_eventid) &(handle->timeEvents.Trafficlight_main_region_on_r1_StreetRed_time_event_0_raised) );		
								}
							}
							break;
						}
						case Trafficlight_main_region_on_r1_PedestrianGreen : {
							{
								/* Default exit sequence for state PedestrianGreen */
								handle->stateConfVector[0] = Trafficlight_last_state;
								handle->stateConfVectorPosition = 0;
								{
									/* Exit action for state 'PedestrianGreen'. */
									trafficlight_unsetTimer( (sc_eventid) &(handle->timeEvents.Trafficlight_main_region_on_r1_PedestrianGreen_time_event_0_raised) );		
									handle->ifacePedestrianLight.green = bool_false;
								}
							}
							break;
						}
						case Trafficlight_main_region_on_r1_AllRed : {
							{
								/* Default exit sequence for state AllRed */
								handle->stateConfVector[0] = Trafficlight_last_state;
								handle->stateConfVectorPosition = 0;
								{
									/* Exit action for state 'AllRed'. */
									trafficlight_unsetTimer( (sc_eventid) &(handle->timeEvents.Trafficlight_main_region_on_r1_AllRed_time_event_0_raised) );		
								}
							}
							break;
						}
						case Trafficlight_main_region_on_r1_StreetAttention : {
							{
								/* Default exit sequence for state StreetAttention */
								handle->stateConfVector[0] = Trafficlight_last_state;
								handle->stateConfVectorPosition = 0;
								{
									/* Exit action for state 'StreetAttention'. */
									trafficlight_unsetTimer( (sc_eventid) &(handle->timeEvents.Trafficlight_main_region_on_r1_StreetAttention_time_event_0_raised) );		
									handle->ifaceTrafficLight.yellow = bool_false;
								}
							}
							break;
						}
						case Trafficlight_main_region_on_r1_PedestrianRequesting_r2_waitOn : {
							{
								/* Default exit sequence for state waitOn */
								handle->stateConfVector[0] = Trafficlight_last_state;
								handle->stateConfVectorPosition = 0;
								{
									/* Exit action for state 'waitOn'. */
									trafficlight_unsetTimer( (sc_eventid) &(handle->timeEvents.Trafficlight_main_region_on_r1_PedestrianRequesting_r2_waitOn_time_event_0_raised) );		
									handle->ifacePedestrianLight.yellow = bool_false;
								}
							}
							{
								/* Exit action for state 'PedestrianRequesting'. */
								trafficlight_unsetTimer( (sc_eventid) &(handle->timeEvents.Trafficlight_main_region_on_r1_PedestrianRequesting_time_event_0_raised) );		
							}
							break;
						}
						case Trafficlight_main_region_on_r1_PedestrianRequesting_r2_waitOff : {
							{
								/* Default exit sequence for state waitOff */
								handle->stateConfVector[0] = Trafficlight_last_state;
								handle->stateConfVectorPosition = 0;
								{
									/* Exit action for state 'waitOff'. */
									trafficlight_unsetTimer( (sc_eventid) &(handle->timeEvents.Trafficlight_main_region_on_r1_PedestrianRequesting_r2_waitOff_time_event_0_raised) );		
								}
							}
							{
								/* Exit action for state 'PedestrianRequesting'. */
								trafficlight_unsetTimer( (sc_eventid) &(handle->timeEvents.Trafficlight_main_region_on_r1_PedestrianRequesting_time_event_0_raised) );		
							}
							break;
						}
						default: break;
					}
				}
			}
			{
				/* 'default' enter sequence for state off */
				{
					/* 'default' enter sequence for region r1 */
					{
						/* Default react sequence for initial entry  */
						{
							/* 'default' enter sequence for state YellowOn */
							{
								/* Entry action for state 'YellowOn'. */
								trafficlight_setTimer( (sc_eventid) &(handle->timeEvents.Trafficlight_main_region_off_r1_YellowOn_time_event_0_raised) , 500, bool_false);
								handle->ifaceTrafficLight.yellow = bool_true;
								handle->ifacePedestrianLight.yellow = bool_true;
							}
							handle->stateConfVector[0] = Trafficlight_main_region_off_r1_YellowOn;
							handle->stateConfVectorPosition = 0;
						}
					}
				}
			}
		}  else {
			if (handle->timeEvents.Trafficlight_main_region_on_r1_StreetAttention_time_event_0_raised) { 
				{
					/* Default exit sequence for state StreetAttention */
					handle->stateConfVector[0] = Trafficlight_last_state;
					handle->stateConfVectorPosition = 0;
					{
						/* Exit action for state 'StreetAttention'. */
						trafficlight_unsetTimer( (sc_eventid) &(handle->timeEvents.Trafficlight_main_region_on_r1_StreetAttention_time_event_0_raised) );		
						handle->ifaceTrafficLight.yellow = bool_false;
					}
				}
				{
					/* 'default' enter sequence for state StreetRed */
					{
						/* Entry action for state 'StreetRed'. */
						trafficlight_setTimer( (sc_eventid) &(handle->timeEvents.Trafficlight_main_region_on_r1_StreetRed_time_event_0_raised) , 2 * 1000, bool_false);
						handle->ifaceTrafficLight.red = bool_true;
					}
					handle->stateConfVector[0] = Trafficlight_main_region_on_r1_StreetRed;
					handle->stateConfVectorPosition = 0;
				}
			} 
		}
	}
}

/* The reactions of state waitOn. */
static void trafficlight_react_main_region_on_r1_PedestrianRequesting_r2_waitOn(Trafficlight* handle) {
	{
		/* The reactions of state waitOn. */
		if (handle->iface.onOff_raised) { 
			{
				/* Default exit sequence for state on */
				{
					/* Default exit sequence for region r1 */
					/* Handle exit of all possible states (of r1) at position 0... */
					switch(handle->stateConfVector[ 0 ]) {
						case Trafficlight_main_region_on_r1_StreetGreen : {
							{
								/* Default exit sequence for state StreetGreen */
								handle->stateConfVector[0] = Trafficlight_last_state;
								handle->stateConfVectorPosition = 0;
							}
							break;
						}
						case Trafficlight_main_region_on_r1_StreetRedYellow : {
							{
								/* Default exit sequence for state StreetRedYellow */
								handle->stateConfVector[0] = Trafficlight_last_state;
								handle->stateConfVectorPosition = 0;
								{
									/* Exit action for state 'StreetRedYellow'. */
									trafficlight_unsetTimer( (sc_eventid) &(handle->timeEvents.Trafficlight_main_region_on_r1_StreetRedYellow_time_event_0_raised) );		
									handle->ifaceTrafficLight.red = bool_false;
									handle->ifaceTrafficLight.yellow = bool_false;
								}
							}
							break;
						}
						case Trafficlight_main_region_on_r1_StreetRed : {
							{
								/* Default exit sequence for state StreetRed */
								handle->stateConfVector[0] = Trafficlight_last_state;
								handle->stateConfVectorPosition = 0;
								{
									/* Exit action for state 'StreetRed'. */
									trafficlight_unsetTimer( (sc_eventid) &(handle->timeEvents.Trafficlight_main_region_on_r1_StreetRed_time_event_0_raised) );		
								}
							}
							break;
						}
						case Trafficlight_main_region_on_r1_PedestrianGreen : {
							{
								/* Default exit sequence for state PedestrianGreen */
								handle->stateConfVector[0] = Trafficlight_last_state;
								handle->stateConfVectorPosition = 0;
								{
									/* Exit action for state 'PedestrianGreen'. */
									trafficlight_unsetTimer( (sc_eventid) &(handle->timeEvents.Trafficlight_main_region_on_r1_PedestrianGreen_time_event_0_raised) );		
									handle->ifacePedestrianLight.green = bool_false;
								}
							}
							break;
						}
						case Trafficlight_main_region_on_r1_AllRed : {
							{
								/* Default exit sequence for state AllRed */
								handle->stateConfVector[0] = Trafficlight_last_state;
								handle->stateConfVectorPosition = 0;
								{
									/* Exit action for state 'AllRed'. */
									trafficlight_unsetTimer( (sc_eventid) &(handle->timeEvents.Trafficlight_main_region_on_r1_AllRed_time_event_0_raised) );		
								}
							}
							break;
						}
						case Trafficlight_main_region_on_r1_StreetAttention : {
							{
								/* Default exit sequence for state StreetAttention */
								handle->stateConfVector[0] = Trafficlight_last_state;
								handle->stateConfVectorPosition = 0;
								{
									/* Exit action for state 'StreetAttention'. */
									trafficlight_unsetTimer( (sc_eventid) &(handle->timeEvents.Trafficlight_main_region_on_r1_StreetAttention_time_event_0_raised) );		
									handle->ifaceTrafficLight.yellow = bool_false;
								}
							}
							break;
						}
						case Trafficlight_main_region_on_r1_PedestrianRequesting_r2_waitOn : {
							{
								/* Default exit sequence for state waitOn */
								handle->stateConfVector[0] = Trafficlight_last_state;
								handle->stateConfVectorPosition = 0;
								{
									/* Exit action for state 'waitOn'. */
									trafficlight_unsetTimer( (sc_eventid) &(handle->timeEvents.Trafficlight_main_region_on_r1_PedestrianRequesting_r2_waitOn_time_event_0_raised) );		
									handle->ifacePedestrianLight.yellow = bool_false;
								}
							}
							{
								/* Exit action for state 'PedestrianRequesting'. */
								trafficlight_unsetTimer( (sc_eventid) &(handle->timeEvents.Trafficlight_main_region_on_r1_PedestrianRequesting_time_event_0_raised) );		
							}
							break;
						}
						case Trafficlight_main_region_on_r1_PedestrianRequesting_r2_waitOff : {
							{
								/* Default exit sequence for state waitOff */
								handle->stateConfVector[0] = Trafficlight_last_state;
								handle->stateConfVectorPosition = 0;
								{
									/* Exit action for state 'waitOff'. */
									trafficlight_unsetTimer( (sc_eventid) &(handle->timeEvents.Trafficlight_main_region_on_r1_PedestrianRequesting_r2_waitOff_time_event_0_raised) );		
								}
							}
							{
								/* Exit action for state 'PedestrianRequesting'. */
								trafficlight_unsetTimer( (sc_eventid) &(handle->timeEvents.Trafficlight_main_region_on_r1_PedestrianRequesting_time_event_0_raised) );		
							}
							break;
						}
						default: break;
					}
				}
			}
			{
				/* 'default' enter sequence for state off */
				{
					/* 'default' enter sequence for region r1 */
					{
						/* Default react sequence for initial entry  */
						{
							/* 'default' enter sequence for state YellowOn */
							{
								/* Entry action for state 'YellowOn'. */
								trafficlight_setTimer( (sc_eventid) &(handle->timeEvents.Trafficlight_main_region_off_r1_YellowOn_time_event_0_raised) , 500, bool_false);
								handle->ifaceTrafficLight.yellow = bool_true;
								handle->ifacePedestrianLight.yellow = bool_true;
							}
							handle->stateConfVector[0] = Trafficlight_main_region_off_r1_YellowOn;
							handle->stateConfVectorPosition = 0;
						}
					}
				}
			}
		}  else {
			if (handle->timeEvents.Trafficlight_main_region_on_r1_PedestrianRequesting_time_event_0_raised) { 
				{
					/* Default exit sequence for state PedestrianRequesting */
					{
						/* Default exit sequence for region r2 */
						/* Handle exit of all possible states (of r2) at position 0... */
						switch(handle->stateConfVector[ 0 ]) {
							case Trafficlight_main_region_on_r1_PedestrianRequesting_r2_waitOn : {
								{
									/* Default exit sequence for state waitOn */
									handle->stateConfVector[0] = Trafficlight_last_state;
									handle->stateConfVectorPosition = 0;
									{
										/* Exit action for state 'waitOn'. */
										trafficlight_unsetTimer( (sc_eventid) &(handle->timeEvents.Trafficlight_main_region_on_r1_PedestrianRequesting_r2_waitOn_time_event_0_raised) );		
										handle->ifacePedestrianLight.yellow = bool_false;
									}
								}
								break;
							}
							case Trafficlight_main_region_on_r1_PedestrianRequesting_r2_waitOff : {
								{
									/* Default exit sequence for state waitOff */
									handle->stateConfVector[0] = Trafficlight_last_state;
									handle->stateConfVectorPosition = 0;
									{
										/* Exit action for state 'waitOff'. */
										trafficlight_unsetTimer( (sc_eventid) &(handle->timeEvents.Trafficlight_main_region_on_r1_PedestrianRequesting_r2_waitOff_time_event_0_raised) );		
									}
								}
								break;
							}
							default: break;
						}
					}
					{
						/* Exit action for state 'PedestrianRequesting'. */
						trafficlight_unsetTimer( (sc_eventid) &(handle->timeEvents.Trafficlight_main_region_on_r1_PedestrianRequesting_time_event_0_raised) );		
					}
				}
				{
					/* 'default' enter sequence for state StreetAttention */
					{
						/* Entry action for state 'StreetAttention'. */
						trafficlight_setTimer( (sc_eventid) &(handle->timeEvents.Trafficlight_main_region_on_r1_StreetAttention_time_event_0_raised) , 2 * 1000, bool_false);
						handle->ifaceTrafficLight.yellow = bool_true;
						handle->ifaceTrafficLight.green = bool_false;
					}
					handle->stateConfVector[0] = Trafficlight_main_region_on_r1_StreetAttention;
					handle->stateConfVectorPosition = 0;
				}
			}  else {
				if (handle->timeEvents.Trafficlight_main_region_on_r1_PedestrianRequesting_r2_waitOn_time_event_0_raised) { 
					{
						/* Default exit sequence for state waitOn */
						handle->stateConfVector[0] = Trafficlight_last_state;
						handle->stateConfVectorPosition = 0;
						{
							/* Exit action for state 'waitOn'. */
							trafficlight_unsetTimer( (sc_eventid) &(handle->timeEvents.Trafficlight_main_region_on_r1_PedestrianRequesting_r2_waitOn_time_event_0_raised) );		
							handle->ifacePedestrianLight.yellow = bool_false;
						}
					}
					{
						/* 'default' enter sequence for state waitOff */
						{
							/* Entry action for state 'waitOff'. */
							trafficlight_setTimer( (sc_eventid) &(handle->timeEvents.Trafficlight_main_region_on_r1_PedestrianRequesting_r2_waitOff_time_event_0_raised) , 500, bool_false);
						}
						handle->stateConfVector[0] = Trafficlight_main_region_on_r1_PedestrianRequesting_r2_waitOff;
						handle->stateConfVectorPosition = 0;
					}
				} 
			}
		}
	}
}

/* The reactions of state waitOff. */
static void trafficlight_react_main_region_on_r1_PedestrianRequesting_r2_waitOff(Trafficlight* handle) {
	{
		/* The reactions of state waitOff. */
		if (handle->iface.onOff_raised) { 
			{
				/* Default exit sequence for state on */
				{
					/* Default exit sequence for region r1 */
					/* Handle exit of all possible states (of r1) at position 0... */
					switch(handle->stateConfVector[ 0 ]) {
						case Trafficlight_main_region_on_r1_StreetGreen : {
							{
								/* Default exit sequence for state StreetGreen */
								handle->stateConfVector[0] = Trafficlight_last_state;
								handle->stateConfVectorPosition = 0;
							}
							break;
						}
						case Trafficlight_main_region_on_r1_StreetRedYellow : {
							{
								/* Default exit sequence for state StreetRedYellow */
								handle->stateConfVector[0] = Trafficlight_last_state;
								handle->stateConfVectorPosition = 0;
								{
									/* Exit action for state 'StreetRedYellow'. */
									trafficlight_unsetTimer( (sc_eventid) &(handle->timeEvents.Trafficlight_main_region_on_r1_StreetRedYellow_time_event_0_raised) );		
									handle->ifaceTrafficLight.red = bool_false;
									handle->ifaceTrafficLight.yellow = bool_false;
								}
							}
							break;
						}
						case Trafficlight_main_region_on_r1_StreetRed : {
							{
								/* Default exit sequence for state StreetRed */
								handle->stateConfVector[0] = Trafficlight_last_state;
								handle->stateConfVectorPosition = 0;
								{
									/* Exit action for state 'StreetRed'. */
									trafficlight_unsetTimer( (sc_eventid) &(handle->timeEvents.Trafficlight_main_region_on_r1_StreetRed_time_event_0_raised) );		
								}
							}
							break;
						}
						case Trafficlight_main_region_on_r1_PedestrianGreen : {
							{
								/* Default exit sequence for state PedestrianGreen */
								handle->stateConfVector[0] = Trafficlight_last_state;
								handle->stateConfVectorPosition = 0;
								{
									/* Exit action for state 'PedestrianGreen'. */
									trafficlight_unsetTimer( (sc_eventid) &(handle->timeEvents.Trafficlight_main_region_on_r1_PedestrianGreen_time_event_0_raised) );		
									handle->ifacePedestrianLight.green = bool_false;
								}
							}
							break;
						}
						case Trafficlight_main_region_on_r1_AllRed : {
							{
								/* Default exit sequence for state AllRed */
								handle->stateConfVector[0] = Trafficlight_last_state;
								handle->stateConfVectorPosition = 0;
								{
									/* Exit action for state 'AllRed'. */
									trafficlight_unsetTimer( (sc_eventid) &(handle->timeEvents.Trafficlight_main_region_on_r1_AllRed_time_event_0_raised) );		
								}
							}
							break;
						}
						case Trafficlight_main_region_on_r1_StreetAttention : {
							{
								/* Default exit sequence for state StreetAttention */
								handle->stateConfVector[0] = Trafficlight_last_state;
								handle->stateConfVectorPosition = 0;
								{
									/* Exit action for state 'StreetAttention'. */
									trafficlight_unsetTimer( (sc_eventid) &(handle->timeEvents.Trafficlight_main_region_on_r1_StreetAttention_time_event_0_raised) );		
									handle->ifaceTrafficLight.yellow = bool_false;
								}
							}
							break;
						}
						case Trafficlight_main_region_on_r1_PedestrianRequesting_r2_waitOn : {
							{
								/* Default exit sequence for state waitOn */
								handle->stateConfVector[0] = Trafficlight_last_state;
								handle->stateConfVectorPosition = 0;
								{
									/* Exit action for state 'waitOn'. */
									trafficlight_unsetTimer( (sc_eventid) &(handle->timeEvents.Trafficlight_main_region_on_r1_PedestrianRequesting_r2_waitOn_time_event_0_raised) );		
									handle->ifacePedestrianLight.yellow = bool_false;
								}
							}
							{
								/* Exit action for state 'PedestrianRequesting'. */
								trafficlight_unsetTimer( (sc_eventid) &(handle->timeEvents.Trafficlight_main_region_on_r1_PedestrianRequesting_time_event_0_raised) );		
							}
							break;
						}
						case Trafficlight_main_region_on_r1_PedestrianRequesting_r2_waitOff : {
							{
								/* Default exit sequence for state waitOff */
								handle->stateConfVector[0] = Trafficlight_last_state;
								handle->stateConfVectorPosition = 0;
								{
									/* Exit action for state 'waitOff'. */
									trafficlight_unsetTimer( (sc_eventid) &(handle->timeEvents.Trafficlight_main_region_on_r1_PedestrianRequesting_r2_waitOff_time_event_0_raised) );		
								}
							}
							{
								/* Exit action for state 'PedestrianRequesting'. */
								trafficlight_unsetTimer( (sc_eventid) &(handle->timeEvents.Trafficlight_main_region_on_r1_PedestrianRequesting_time_event_0_raised) );		
							}
							break;
						}
						default: break;
					}
				}
			}
			{
				/* 'default' enter sequence for state off */
				{
					/* 'default' enter sequence for region r1 */
					{
						/* Default react sequence for initial entry  */
						{
							/* 'default' enter sequence for state YellowOn */
							{
								/* Entry action for state 'YellowOn'. */
								trafficlight_setTimer( (sc_eventid) &(handle->timeEvents.Trafficlight_main_region_off_r1_YellowOn_time_event_0_raised) , 500, bool_false);
								handle->ifaceTrafficLight.yellow = bool_true;
								handle->ifacePedestrianLight.yellow = bool_true;
							}
							handle->stateConfVector[0] = Trafficlight_main_region_off_r1_YellowOn;
							handle->stateConfVectorPosition = 0;
						}
					}
				}
			}
		}  else {
			if (handle->timeEvents.Trafficlight_main_region_on_r1_PedestrianRequesting_time_event_0_raised) { 
				{
					/* Default exit sequence for state PedestrianRequesting */
					{
						/* Default exit sequence for region r2 */
						/* Handle exit of all possible states (of r2) at position 0... */
						switch(handle->stateConfVector[ 0 ]) {
							case Trafficlight_main_region_on_r1_PedestrianRequesting_r2_waitOn : {
								{
									/* Default exit sequence for state waitOn */
									handle->stateConfVector[0] = Trafficlight_last_state;
									handle->stateConfVectorPosition = 0;
									{
										/* Exit action for state 'waitOn'. */
										trafficlight_unsetTimer( (sc_eventid) &(handle->timeEvents.Trafficlight_main_region_on_r1_PedestrianRequesting_r2_waitOn_time_event_0_raised) );		
										handle->ifacePedestrianLight.yellow = bool_false;
									}
								}
								break;
							}
							case Trafficlight_main_region_on_r1_PedestrianRequesting_r2_waitOff : {
								{
									/* Default exit sequence for state waitOff */
									handle->stateConfVector[0] = Trafficlight_last_state;
									handle->stateConfVectorPosition = 0;
									{
										/* Exit action for state 'waitOff'. */
										trafficlight_unsetTimer( (sc_eventid) &(handle->timeEvents.Trafficlight_main_region_on_r1_PedestrianRequesting_r2_waitOff_time_event_0_raised) );		
									}
								}
								break;
							}
							default: break;
						}
					}
					{
						/* Exit action for state 'PedestrianRequesting'. */
						trafficlight_unsetTimer( (sc_eventid) &(handle->timeEvents.Trafficlight_main_region_on_r1_PedestrianRequesting_time_event_0_raised) );		
					}
				}
				{
					/* 'default' enter sequence for state StreetAttention */
					{
						/* Entry action for state 'StreetAttention'. */
						trafficlight_setTimer( (sc_eventid) &(handle->timeEvents.Trafficlight_main_region_on_r1_StreetAttention_time_event_0_raised) , 2 * 1000, bool_false);
						handle->ifaceTrafficLight.yellow = bool_true;
						handle->ifaceTrafficLight.green = bool_false;
					}
					handle->stateConfVector[0] = Trafficlight_main_region_on_r1_StreetAttention;
					handle->stateConfVectorPosition = 0;
				}
			}  else {
				if (handle->timeEvents.Trafficlight_main_region_on_r1_PedestrianRequesting_r2_waitOff_time_event_0_raised) { 
					{
						/* Default exit sequence for state waitOff */
						handle->stateConfVector[0] = Trafficlight_last_state;
						handle->stateConfVectorPosition = 0;
						{
							/* Exit action for state 'waitOff'. */
							trafficlight_unsetTimer( (sc_eventid) &(handle->timeEvents.Trafficlight_main_region_on_r1_PedestrianRequesting_r2_waitOff_time_event_0_raised) );		
						}
					}
					{
						/* 'default' enter sequence for state waitOn */
						{
							/* Entry action for state 'waitOn'. */
							trafficlight_setTimer( (sc_eventid) &(handle->timeEvents.Trafficlight_main_region_on_r1_PedestrianRequesting_r2_waitOn_time_event_0_raised) , 500, bool_false);
							handle->ifacePedestrianLight.yellow = bool_true;
						}
						handle->stateConfVector[0] = Trafficlight_main_region_on_r1_PedestrianRequesting_r2_waitOn;
						handle->stateConfVectorPosition = 0;
					}
				} 
			}
		}
	}
}

/* The reactions of state YellowOn. */
static void trafficlight_react_main_region_off_r1_YellowOn(Trafficlight* handle) {
	{
		/* The reactions of state YellowOn. */
		if (handle->iface.onOff_raised) { 
			{
				/* Default exit sequence for state off */
				{
					/* Default exit sequence for region r1 */
					/* Handle exit of all possible states (of r1) at position 0... */
					switch(handle->stateConfVector[ 0 ]) {
						case Trafficlight_main_region_off_r1_YellowOn : {
							{
								/* Default exit sequence for state YellowOn */
								handle->stateConfVector[0] = Trafficlight_last_state;
								handle->stateConfVectorPosition = 0;
								{
									/* Exit action for state 'YellowOn'. */
									trafficlight_unsetTimer( (sc_eventid) &(handle->timeEvents.Trafficlight_main_region_off_r1_YellowOn_time_event_0_raised) );		
									handle->ifaceTrafficLight.yellow = bool_false;
									handle->ifacePedestrianLight.yellow = bool_false;
								}
							}
							break;
						}
						case Trafficlight_main_region_off_r1_YellowOff : {
							{
								/* Default exit sequence for state YellowOff */
								handle->stateConfVector[0] = Trafficlight_last_state;
								handle->stateConfVectorPosition = 0;
								{
									/* Exit action for state 'YellowOff'. */
									trafficlight_unsetTimer( (sc_eventid) &(handle->timeEvents.Trafficlight_main_region_off_r1_YellowOff_time_event_0_raised) );		
								}
							}
							break;
						}
						default: break;
					}
				}
			}
			{
				/* 'default' enter sequence for state on */
				{
					/* 'default' enter sequence for region r1 */
					{
						/* Default react sequence for initial entry  */
						{
							/* 'default' enter sequence for state AllRed */
							{
								/* Entry action for state 'AllRed'. */
								trafficlight_setTimer( (sc_eventid) &(handle->timeEvents.Trafficlight_main_region_on_r1_AllRed_time_event_0_raised) , 500, bool_false);
								handle->ifacePedestrianLight.red = bool_true;
								handle->ifaceTrafficLight.red = bool_true;
							}
							handle->stateConfVector[0] = Trafficlight_main_region_on_r1_AllRed;
							handle->stateConfVectorPosition = 0;
						}
					}
				}
			}
		}  else {
			if (handle->timeEvents.Trafficlight_main_region_off_r1_YellowOn_time_event_0_raised) { 
				{
					/* Default exit sequence for state YellowOn */
					handle->stateConfVector[0] = Trafficlight_last_state;
					handle->stateConfVectorPosition = 0;
					{
						/* Exit action for state 'YellowOn'. */
						trafficlight_unsetTimer( (sc_eventid) &(handle->timeEvents.Trafficlight_main_region_off_r1_YellowOn_time_event_0_raised) );		
						handle->ifaceTrafficLight.yellow = bool_false;
						handle->ifacePedestrianLight.yellow = bool_false;
					}
				}
				{
					/* 'default' enter sequence for state YellowOff */
					{
						/* Entry action for state 'YellowOff'. */
						trafficlight_setTimer( (sc_eventid) &(handle->timeEvents.Trafficlight_main_region_off_r1_YellowOff_time_event_0_raised) , 500, bool_false);
					}
					handle->stateConfVector[0] = Trafficlight_main_region_off_r1_YellowOff;
					handle->stateConfVectorPosition = 0;
				}
			} 
		}
	}
}

/* The reactions of state YellowOff. */
static void trafficlight_react_main_region_off_r1_YellowOff(Trafficlight* handle) {
	{
		/* The reactions of state YellowOff. */
		if (handle->iface.onOff_raised) { 
			{
				/* Default exit sequence for state off */
				{
					/* Default exit sequence for region r1 */
					/* Handle exit of all possible states (of r1) at position 0... */
					switch(handle->stateConfVector[ 0 ]) {
						case Trafficlight_main_region_off_r1_YellowOn : {
							{
								/* Default exit sequence for state YellowOn */
								handle->stateConfVector[0] = Trafficlight_last_state;
								handle->stateConfVectorPosition = 0;
								{
									/* Exit action for state 'YellowOn'. */
									trafficlight_unsetTimer( (sc_eventid) &(handle->timeEvents.Trafficlight_main_region_off_r1_YellowOn_time_event_0_raised) );		
									handle->ifaceTrafficLight.yellow = bool_false;
									handle->ifacePedestrianLight.yellow = bool_false;
								}
							}
							break;
						}
						case Trafficlight_main_region_off_r1_YellowOff : {
							{
								/* Default exit sequence for state YellowOff */
								handle->stateConfVector[0] = Trafficlight_last_state;
								handle->stateConfVectorPosition = 0;
								{
									/* Exit action for state 'YellowOff'. */
									trafficlight_unsetTimer( (sc_eventid) &(handle->timeEvents.Trafficlight_main_region_off_r1_YellowOff_time_event_0_raised) );		
								}
							}
							break;
						}
						default: break;
					}
				}
			}
			{
				/* 'default' enter sequence for state on */
				{
					/* 'default' enter sequence for region r1 */
					{
						/* Default react sequence for initial entry  */
						{
							/* 'default' enter sequence for state AllRed */
							{
								/* Entry action for state 'AllRed'. */
								trafficlight_setTimer( (sc_eventid) &(handle->timeEvents.Trafficlight_main_region_on_r1_AllRed_time_event_0_raised) , 500, bool_false);
								handle->ifacePedestrianLight.red = bool_true;
								handle->ifaceTrafficLight.red = bool_true;
							}
							handle->stateConfVector[0] = Trafficlight_main_region_on_r1_AllRed;
							handle->stateConfVectorPosition = 0;
						}
					}
				}
			}
		}  else {
			if (handle->timeEvents.Trafficlight_main_region_off_r1_YellowOff_time_event_0_raised) { 
				{
					/* Default exit sequence for state YellowOff */
					handle->stateConfVector[0] = Trafficlight_last_state;
					handle->stateConfVectorPosition = 0;
					{
						/* Exit action for state 'YellowOff'. */
						trafficlight_unsetTimer( (sc_eventid) &(handle->timeEvents.Trafficlight_main_region_off_r1_YellowOff_time_event_0_raised) );		
					}
				}
				{
					/* 'default' enter sequence for state YellowOn */
					{
						/* Entry action for state 'YellowOn'. */
						trafficlight_setTimer( (sc_eventid) &(handle->timeEvents.Trafficlight_main_region_off_r1_YellowOn_time_event_0_raised) , 500, bool_false);
						handle->ifaceTrafficLight.yellow = bool_true;
						handle->ifacePedestrianLight.yellow = bool_true;
					}
					handle->stateConfVector[0] = Trafficlight_main_region_off_r1_YellowOn;
					handle->stateConfVectorPosition = 0;
				}
			} 
		}
	}
}


