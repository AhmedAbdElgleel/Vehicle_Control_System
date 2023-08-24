/*
 ===========================================================================================================================================================
 Author       : Ahmed Abd Elgleel
 Date         : 13 August 2023
 File Type    : Function Prototype file
 ===========================================================================================================================================================
 */

/*============================================== car_state enum definition and structure definition =======================================================*/
#ifndef __CARS_STATS_
#define __CARS_STATS_ 1
enum state
{
	OFF, ON
};
struct car_state
{
enum state engine_state ;   												/* Variable of type enum for engine current state*/
enum state ac_state ;       												/* Variable of type enum for AC current state*/
int vehicle_speed ;         												/* integer Variable for the vehicle speed*/
int room_temp ;        	    												/* integer Variable for the room temperature*/
enum state temp_controller ;    											/* integer variable of type enum for the ETC state*/
int engine_temp ;             												/* integer Variable for the engine temperature*/
};

/*============================================================== Functions Prototypes ===========================================================================*/

char check_main_menu_option(void);  										/* check which option at the beginning the user choose */

char get_the_user_choice_after_turn_on_vehicle(struct car_state *s_pptr);    /*Function to  get the the user input in case Engine on when needed */

void traffic_light(struct car_state  **s_pptr);						        /*function to get the traffic light data to decide what to do */

void room_temperature(struct car_state  **s_pptr);							/*function to get the room temperature data to decide what to do */

void engine_temperature(struct car_state  **s_pptr);						/*function to get the Engine temperature data to decide what to do */

void check_car_speed_reach_30_Special_case(struct car_state **s_pptr);		/*function to handle the special case when speed reach 30km/hr*/

void print_all_car_state(struct car_state **s_pptr);    					/* print the state of the vehicle*/

/*===============================================================================================================================================================*/
