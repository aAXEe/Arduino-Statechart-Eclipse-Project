
#ifndef TRAFFICLIGHT_H_
#define TRAFFICLIGHT_H_

#include "sc_types.h"

#ifdef __cplusplus
extern "C" { 
#endif 

/*! \file Header of the state machine 'Trafficlight'.
*/

//! enumeration of all states 
typedef enum {
	Trafficlight_main_region_on ,
	Trafficlight_main_region_on_r1_StreetGreen ,
	Trafficlight_main_region_on_r1_StreetRedYellow ,
	Trafficlight_main_region_on_r1_StreetRed ,
	Trafficlight_main_region_on_r1_PedestrianGreen ,
	Trafficlight_main_region_on_r1_AllRed ,
	Trafficlight_main_region_on_r1_StreetAttention ,
	Trafficlight_main_region_on_r1_PedestrianRequesting ,
	Trafficlight_main_region_on_r1_PedestrianRequesting_r2_waitOn ,
	Trafficlight_main_region_on_r1_PedestrianRequesting_r2_waitOff ,
	Trafficlight_main_region_off ,
	Trafficlight_main_region_off_r1_YellowOn ,
	Trafficlight_main_region_off_r1_YellowOff ,
	Trafficlight_last_state
} TrafficlightStates;

//! Type definition of the data structure for the TrafficlightIfaceTrafficLight interface scope.
typedef struct {
	sc_boolean red;
	sc_boolean yellow;
	sc_boolean green;
} TrafficlightIfaceTrafficLight;

//! Type definition of the data structure for the TrafficlightIfacePedestrianLight interface scope.
typedef struct {
	sc_boolean red;
	sc_boolean yellow;
	sc_boolean green;
} TrafficlightIfacePedestrianLight;

//! Type definition of the data structure for the TrafficlightIface interface scope.
typedef struct {
	sc_boolean pedestrianRequest_raised;
	sc_boolean onOff_raised;
} TrafficlightIface;

//! Type definition of the data structure for the TrafficlightTimeEvents interface scope.
typedef struct {
	sc_boolean Trafficlight_main_region_on_r1_StreetRedYellow_time_event_0_raised;
	sc_boolean Trafficlight_main_region_on_r1_StreetRed_time_event_0_raised;
	sc_boolean Trafficlight_main_region_on_r1_PedestrianGreen_time_event_0_raised;
	sc_boolean Trafficlight_main_region_on_r1_AllRed_time_event_0_raised;
	sc_boolean Trafficlight_main_region_on_r1_StreetAttention_time_event_0_raised;
	sc_boolean Trafficlight_main_region_on_r1_PedestrianRequesting_time_event_0_raised;
	sc_boolean Trafficlight_main_region_on_r1_PedestrianRequesting_r2_waitOn_time_event_0_raised;
	sc_boolean Trafficlight_main_region_on_r1_PedestrianRequesting_r2_waitOff_time_event_0_raised;
	sc_boolean Trafficlight_main_region_off_r1_YellowOn_time_event_0_raised;
	sc_boolean Trafficlight_main_region_off_r1_YellowOff_time_event_0_raised;
} TrafficlightTimeEvents;


//! the maximum number of orthogonal states defines the dimension of the state configuration vector.
#define TRAFFICLIGHT_MAX_ORTHOGONAL_STATES 1

/*! Type definition of the data structure for the Trafficlight state machine.
This data structure has to be allocated by the client code. */
typedef struct {
	TrafficlightStates stateConfVector[TRAFFICLIGHT_MAX_ORTHOGONAL_STATES];
	sc_ushort stateConfVectorPosition; 
	
	TrafficlightIfaceTrafficLight ifaceTrafficLight;
	TrafficlightIfacePedestrianLight ifacePedestrianLight;
	TrafficlightIface iface;
	TrafficlightTimeEvents timeEvents;
} Trafficlight;

/*! Initializes the Trafficlight state machine data structures. Must be called before first usage.*/
extern void trafficlight_init(Trafficlight* handle);

/*! Activates the state machine */
extern void trafficlight_enter(Trafficlight* handle);

/*! Deactivates the state machine */
extern void trafficlight_exit(Trafficlight* handle);

/*! Performs a 'run to completion' step. */
extern void trafficlight_runCycle(Trafficlight* handle);

/*! Raises a time event. */
extern void trafficlight_raiseTimeEvent(Trafficlight* handle, sc_eventid evid);

/*! Gets the value of the variable 'red' that is defined in the interface scope 'TrafficLight'. */ 
extern sc_boolean trafficlightIfaceTrafficLight_get_red(Trafficlight* handle);
/*! Sets the value of the variable 'red' that is defined in the interface scope 'TrafficLight'. */ 
extern void trafficlightIfaceTrafficLight_set_red(Trafficlight* handle, sc_boolean value);
/*! Gets the value of the variable 'yellow' that is defined in the interface scope 'TrafficLight'. */ 
extern sc_boolean trafficlightIfaceTrafficLight_get_yellow(Trafficlight* handle);
/*! Sets the value of the variable 'yellow' that is defined in the interface scope 'TrafficLight'. */ 
extern void trafficlightIfaceTrafficLight_set_yellow(Trafficlight* handle, sc_boolean value);
/*! Gets the value of the variable 'green' that is defined in the interface scope 'TrafficLight'. */ 
extern sc_boolean trafficlightIfaceTrafficLight_get_green(Trafficlight* handle);
/*! Sets the value of the variable 'green' that is defined in the interface scope 'TrafficLight'. */ 
extern void trafficlightIfaceTrafficLight_set_green(Trafficlight* handle, sc_boolean value);

/*! Gets the value of the variable 'red' that is defined in the interface scope 'PedestrianLight'. */ 
extern sc_boolean trafficlightIfacePedestrianLight_get_red(Trafficlight* handle);
/*! Sets the value of the variable 'red' that is defined in the interface scope 'PedestrianLight'. */ 
extern void trafficlightIfacePedestrianLight_set_red(Trafficlight* handle, sc_boolean value);
/*! Gets the value of the variable 'yellow' that is defined in the interface scope 'PedestrianLight'. */ 
extern sc_boolean trafficlightIfacePedestrianLight_get_yellow(Trafficlight* handle);
/*! Sets the value of the variable 'yellow' that is defined in the interface scope 'PedestrianLight'. */ 
extern void trafficlightIfacePedestrianLight_set_yellow(Trafficlight* handle, sc_boolean value);
/*! Gets the value of the variable 'green' that is defined in the interface scope 'PedestrianLight'. */ 
extern sc_boolean trafficlightIfacePedestrianLight_get_green(Trafficlight* handle);
/*! Sets the value of the variable 'green' that is defined in the interface scope 'PedestrianLight'. */ 
extern void trafficlightIfacePedestrianLight_set_green(Trafficlight* handle, sc_boolean value);

/*! Raises the in event 'pedestrianRequest' that is defined in the default interface scope. */ 
extern void trafficlightIface_raise_pedestrianRequest(Trafficlight* handle);

/*! Raises the in event 'onOff' that is defined in the default interface scope. */ 
extern void trafficlightIface_raise_onOff(Trafficlight* handle);



/*! Checks if the specified state is active. */
extern sc_boolean trafficlight_isActive(Trafficlight* handle, TrafficlightStates state);

#ifdef __cplusplus
}
#endif 

#endif /* TRAFFICLIGHT_H_ */
