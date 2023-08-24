/*
 ==============================================================================================================================================================
 Author       : Ahmed Abd Elgleel
 Date         : 13 August 2023
 File Type    : Function definition file
 ==============================================================================================================================================================
 */
#include "Function_proto.h"
#define ENGINE_TEMP_CONTROLLER 1        /*Challenge*/


/*===========================================================Functions definition=============================================================================*/

       /*---------------------------------- this is the first function appear to user in our car system ---------------------------------------------*/

char check_main_menu_option(void)
{
	char user_first_choise_in_main_menu;                              /*local variable for first user input in the main menu*/
	puts("a. Turn on the vehicle engine");
	puts("b. Turn off the vehicle engine");
	puts("c. Quit the system");
	scanf(" %c",&user_first_choise_in_main_menu);
	switch(user_first_choise_in_main_menu)
	{
	case 'A':
	case 'a':
		puts("-----------------------");
		puts("Car Engine is turned ON");
		puts("-----------------------");
		break;
	case 'B':
	case 'b':
		puts("------------------------");
		puts("Car Engine is turned oFF");
		puts("------------------------");
		break;
	case 'C':
	case 'c':
		puts("Exit");
		break;
	default:
		puts("-------------------------");
		puts("Sorry-_-,InValid input we will restart the system for you"); //In case unexpected behavior restart system via calling the main menu screen
		puts("-------------------------");
	}
return user_first_choise_in_main_menu;
}


			/*-----------This is the second screen appear to user in our car system in case he turned on the vehicle---------*/

char get_the_user_choice_after_turn_on_vehicle(struct car_state *s_ptr)
{
	char user_input_after_turn_on_the_vehile;        //local variable
	puts("a. Turn off the engine");
	puts("b. Set the traffic light color");
	puts("c. Set the room temperature");
	#if ENGINE_TEMP_CONTROLLER
	puts("d. Set the Engine temperature");
	#endif
	scanf(" %c",&user_input_after_turn_on_the_vehile);
	switch(user_input_after_turn_on_the_vehile)
	{
	case 'A':
	case 'a':
		puts("------------------------");
		puts("The Vehicle is turned off");
		puts("------------------------");
		break;
	case 'B':
	case 'b':
		traffic_light(&s_ptr);
		print_all_car_state(&s_ptr);
		break;
	case 'C':
	case 'c':
		room_temperature(&s_ptr);
		print_all_car_state(&s_ptr);
		break;
	case 'D':
	case 'd':
	#if ENGINE_TEMP_CONTROLLER
		engine_temperature(&s_ptr);
		print_all_car_state(&s_ptr);
		break;
	#endif
	default:
		puts("-------------------------");
		puts("Sorry-_-,Invalid inputs we will Restart the System for you");
		puts("-------------------------");
	}
	check_car_speed_reach_30_Special_case(&s_ptr);
	return user_input_after_turn_on_the_vehile;
}

/*--------------------------------- function to determine the speed of the car based on the current traffic light ---------------------------------------*/
void traffic_light(struct car_state  **s_pptr)
{
	puts("required color");
	char traffic_light;  				/*local variable traffic light (sensor)*/
	scanf(" %c",&traffic_light);
	switch(traffic_light)
	{
	case 'G':
	case 'g':
		(*s_pptr)->vehicle_speed=100;
		break;
	case 'Y':
	case 'y':
		(*s_pptr)->vehicle_speed=35;
		break;
	case 'R':
	case 'r':
		(*s_pptr)->vehicle_speed=0;
		break;
	default:
		puts("-------------------------");
		puts("Sorry-_-,Invalid inputs we will Restart the System for you");
		puts("-------------------------");
	}

}


/*------------------------------------- function to determine the room temperature based on temperature sensor----------------------------------------------*/

void room_temperature(struct car_state  **s_pptr)
{
	puts("Enter the required room temperature");
	int input_room_temp;  										/*local variable Room Temperature (Temp.sensor)*/
	scanf(" %d",&input_room_temp);

				/*If temperature less than or equal 10 or temperature is greater than 30, Turn AC ON and set room temp=20*/

	if((input_room_temp<=10)||(input_room_temp>=30)) 	{

		(*s_pptr)->ac_state= ON;       							/*Ac turned ON*/
		(*s_pptr)->room_temp=20;	   							/*Room temp.=20*/
	}
	else        			     /*if temperature is bigger than 10 or less than 30 Turn AC OFF */
	{
		(*s_pptr)->ac_state=OFF;
	}

}

/*------------------------------------------------- function to get the room temperature ----------------------------------------------------------------*/

void engine_temperature(struct car_state  **s_pptr)
{
	puts("Enter the Engine temperature");
		int input_Engine_temp;  										/*local variable for Engine temperature (Temp.sensor)*/
		scanf(" %d",&input_Engine_temp);

	/*If temperature of Engine less than or equal 100 or temperature is greater than 150, Turn Engine temperature controller ON and set Engine temp=120*/

		if((input_Engine_temp<=100)||(input_Engine_temp>=150)) 	{

			(*s_pptr)->temp_controller= ON;       						/*temp Engine controller turned ON*/
			(*s_pptr)->engine_temp=120;	   								/*Room temp.=20*/
		}
		else                       /*---if temperature is otherwise  Turn Engine controller OFF ---*/
		{
			(*s_pptr)->temp_controller=OFF;
		}
}

/*-------------------------------------- function to take some decisions is car speed is 30km/hr -----------------------------------------------------------*/

void check_car_speed_reach_30_Special_case(struct car_state  **s_pptr)
{
	/*------------------- Turn ON AC if it was OFF and set room temperature to:current temperature * (5/4) + 1------------------------------*/

   /* -----------Turn ON “Engine Temperature Controller” if it was OFF and set engine temperature to: current temperature * (5/4) + 1---------------*/
	if(30==(*s_pptr)->vehicle_speed)
		{
			(*s_pptr)->ac_state=ON;
			(*s_pptr)->room_temp*=((float)5)/4+1;
		#if ENGINE_TEMP_CONTROLLER
			(*s_pptr)->temp_controller=ON;
			(*s_pptr)->engine_temp*=((float)5)/4+1;
		#endif
		}
}


/*---------------------------------- function to print all engine states after each sensor value changes -----------------------------------------------------*/


void print_all_car_state(struct car_state  **s_ptr)
{
	printf("\nCurrent vehicle state\n");
	puts("-------------------------------------------------------");
	printf("Engine state : ");
	(*s_ptr)->engine_state == ON ? printf("ON\n"): printf("OFF\n");      /* print the engine state*/

	printf("AC State : ");
	(*s_ptr)->ac_state == ON ? printf("ON\n"): printf("OFF\n");          /*print the AC State*/

	printf("Vehicle Speed: %d Km/Hr\n", (*s_ptr)->vehicle_speed);        /* print the vehicle speed*/

	printf("Room Temperature: %d C\n", (*s_ptr)->room_temp);             /* print the room temperature*/
#if ENGINE_TEMP_CONTROLLER
	printf("Engine Temperature Controller: ");
	(*s_ptr)->temp_controller == ON ? printf("ON\n"): printf("OFF\n");   /* print the Engine temperature controller state*/

	printf("Engine Temperature: %d C\n", (*s_ptr)->engine_temp);         /* print the engine temperature */
#endif
	puts("-------------------------------------------------------");

}

void diable_some_feature_check()
{
	ENGINE_TEMP_CONTROLLER? printf("Engine Temperature Controller is Tuned ON\nSo all Features will Be Valid")
			:printf("Engine Temperature Controller is Tuned OFF\nSo some Features will not Run Probably");
}

