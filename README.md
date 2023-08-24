# Vehicle Control System

This project implements a Vehicle Control System with the following specifications. The system allows the user to interactively control various aspects of the vehicle based on simulated sensor readings.

## Specifications

1. The program provides the user with the following options:
   a. Turn on the vehicle engine
   b. Turn off the vehicle engine
   c. Quit the system

2. If the user chooses to "Quit the system," the program exits.

3. If the user chooses to "Turn off the vehicle engine," the program prompts the user again with the options from Requirement 1.

4. After each user choice, the program displays the current system state.

5. If the user chooses to "Turn on the vehicle engine," the program displays the "Sensors set menu," which simulates sensor readings:
   a. Turn off the engine
   b. Set the traffic light color
   c. Set the room temperature (Temperature Sensor)
   d. Set the engine temperature (Engine Temperature Sensor)

6. While the engine is ON, the "Sensors set menu" is always displayed, waiting for user input.

7. Based on the user's input from the "Sensors set menu":
   a. If the traffic light is 'G', set the vehicle speed to 100 km/hr.
   b. If the traffic light is 'O', set the vehicle speed to 30 km/hr.
   c. If the traffic light is 'R', set the vehicle speed to 0 km/hr.
   d. Based on room temperature data:
      - If temperature is less than 10, turn the AC ON and set the temperature to 20.
      - If temperature is greater than 30, turn the AC ON and set the temperature to 20.
      - Otherwise, turn the AC OFF.
   e. Based on engine temperature data:
      - If temperature is less than 100, turn the "Engine Temperature Controller" ON and set temperature to 125.
      - If temperature is greater than 150, turn the "Engine Temperature Controller" ON and set temperature to 125.
      - Otherwise, turn the "Engine Temperature Controller" OFF.

8. If the vehicle speed is 30 km/hr:
   a. Turn ON the AC if it was OFF and set room temperature to: current temperature * (5/4) + 1.
   b. Turn ON the "Engine Temperature Controller" if it was OFF and set engine temperature to: current temperature * (5/4) + 1.

9. After applying the actions from 7 and 8, display the current vehicle state:
   a. Engine state: ON/OFF.
   b. AC: ON/OFF.
   c. Vehicle Speed.
   d. Room Temperature.
   e. Engine Temperature Controller State.
   f. Engine Temperature.

10. If the user chooses to "Turn off the engine" from the "Sensors set menu," the program displays the options from Requirement 1.

## Bonus Requirement

To enable or disable the compilation and execution of code related to the "Engine Temperature Controller," use the preprocessor directive `#if`:
```c
#define WITH_ENGINE_TEMP_CONTROLLER 1  // Set to 1 to enable, 0 to disable

#if WITH_ENGINE_TEMP_CONTROLLER
    // Code related to Engine Temperature Controller
#endif
```

## Video Reference

For a visual understanding of the project, you can refer to this video: [Project Demo Video](https://youtu.be/i89M2azHeWM)

## How to Run

1. Compile the program using a C compiler (e.g., gcc).
2. Run the compiled executable.
3. Follow the on-screen instructions to interact with the Vehicle Control System.

## Notes

- When taking character input from the user, make sure to include a space before `%c` in the `scanf` function to prevent it from capturing newline characters.

- The bonus requirement demonstrates the usage of preprocessor directives in C to conditionally include or exclude code based on defined conditions. This concept is further discussed in the C For Embedded Systems (Embedded C) Course.
