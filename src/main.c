/*
 ============================================================================
 project Name : Vehicle Control System // C //  M.T.Diploma 79
 Author       : Ahmed Abd Elgleel
 Date         : 13 August 2023
 File Type    : Main File
 ============================================================================
 */
#include <stdio.h>

#include "Function_proto.h"

int main(void) {
	setvbuf(stdout, NULL, _IONBF, 0);
	setvbuf(stderr, NULL, _IONBF, 0);
	struct car_state car1 = { ON, OFF, 0, 35, OFF, 90 };

	char user_main_menu_choise, user_input_after_turn_on_engine;
	/*------------------------ Loop to ReGenerate the user main_menu_screen -----------------*/
	while (1) {
		user_main_menu_choise = check_main_menu_option();
		if (('A' == user_main_menu_choise) || ('a' == user_main_menu_choise)) {
	    /*------------- Loop to ReGenerate the user get the user choice after turn on vehicle_menu_screen ----------*/
			while (1) {
				user_input_after_turn_on_engine =
						get_the_user_choice_after_turn_on_vehicle(&car1);
			/*----- In case user choice option A turn off the Engine and break to return to outer while looping on user main menu choice screen ----*/
				if (('A' == user_input_after_turn_on_engine)|| ('a' == user_input_after_turn_on_engine))
				{
					break;
				}
			}
		}
			/*------------In case user choice c lets exit from our smart system (return 0) ---------*/
		 else if (('C' == user_main_menu_choise) || ('c' == user_main_menu_choise)) {
			break;
		}
		/*--------- this mean that user input B or b or invalid input so loop again----------*/
		else {
			continue;
		}

	}
	return 0;
}
