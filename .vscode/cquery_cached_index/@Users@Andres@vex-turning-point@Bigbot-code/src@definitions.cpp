#include "main.h"
#include "aon/definitions.h"

 //Sensor definitions
 const int DRIVE_PNEUMATIC = 1;     //port A //change to A if this doesn't work
 const int LINE_TRACKER_LEFT = 2;   // use "#define SENSOR_NAME_HERE portnumber" if const int doesnt work
 const int LINE_TRACKER_RIGHT = 3;
 const int GYRO_PORT = 4;
 const int ULTRASONIC_OUT = 5;
 const int ULTRASONIC_IN = 6;

 // Chassis definition
 // Assume this is correct for now
 // TODO: Update with the real robot values
 const int DRIVE_MOTOR_LEFT_1 = -1;   //1,2,3 = Front, Middle, Back
 const int DRIVE_MOTOR_LEFT_2 = 2;
 const int DRIVE_MOTOR_LEFT_3 = -3;
 const int DRIVE_MOTOR_RIGHT_1 = 4;   //1,2,3 = Front, Middle, Back
 const int DRIVE_MOTOR_RIGHT_2 = -5;
 const int DRIVE_MOTOR_RIGHT_3 = 6;

 // Lift definition
 // Assume this is correct for now
 // TODO: Update with the real robot values
 const double liftkP = 1.0;
 const double liftkI = 0.001;
 const double liftkD = 0.1;
 const int LIFT_MOTOR_RIGHT = 8; //actually 8
 const int LIFT_MOTOR_LEFT = -7;   //actually 7

 // Intake definition
 // Assume this is correct for now
 // TODO: Update with the real robot values
 const double flipkP = 1200.0;
 const double flipkI = 0.001;     //default, 1.0, 0.001, 0.1
 const double flipkD = 0.1;
 // const int INTAKE_MOTOR_RIGHT = 9;
 const int ROTATOR_MOTOR_RIGHT = 10;
 // const int INTAKE_MOTOR_LEFT = 11;
 // const int ROTATOR_MOTOR_LEFT = -12;

 // Puncher definition
 // Assume this is correct for now
 // TODO: Update with the real robot values
 //const int PUNCHER_MOTOR_RIGHT = 13;

 // Conveyor definition
 // Assume this is correct for now
 // TODO: Update with the real robot values
 //const int CONVEYOR_MOTOR = 14;


 //For Driver Control height buttons
 //TODO: Find actual low and high goal values in degrees (TUNING)
 const int STARTING_HEIGHT = 10;
 const int LOW_GOAL_HEIGHT = 200;   //low goal is 69% of high goal more or less but this is in degrees so idk
 const int HIGH_GOAL_HEIGHT = 280;
 const int DROP_HEIGHT = 20;
