#pragma once

#include "main.h"

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
const auto WHEEL_DIAMETER = 4_in;
const auto CHASSIS_WIDTH = 15.24_in;

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
const int ROTATOR_MOTOR_RIGHT = 10;

//const int PUNCHER_ANGLE_MOTOR = 15;
// Controller object creation
//TODO: Reverse motors that need to be reversed
auto driveController = ChassisControllerFactory::create(
   {DRIVE_MOTOR_RIGHT_1, DRIVE_MOTOR_RIGHT_2, DRIVE_MOTOR_RIGHT_3},
   {DRIVE_MOTOR_LEFT_1, DRIVE_MOTOR_LEFT_2, DRIVE_MOTOR_LEFT_3},
   AbstractMotor::gearset::green,
   {WHEEL_DIAMETER, CHASSIS_WIDTH}
);

auto liftController = AsyncControllerFactory::posIntegrated(
   {LIFT_MOTOR_RIGHT, LIFT_MOTOR_LEFT}
);

//For Driver Control height buttons
//TODO: Find actual low and high goal values in degrees (TUNING)
const int STARTING_HEIGHT = 10;
const int LOW_GOAL_HEIGHT = 200;   //low goal is 69% of high goal more or less but this is in degrees so idk
const int HIGH_GOAL_HEIGHT = 280;
const int DROP_HEIGHT = 20;
auto rotatorController = AsyncControllerFactory::posIntegrated(ROTATOR_MOTOR_RIGHT); //{ROTOATOR_MOTOR_RIGHT,ROTATOR_MOTOR_LEFT}

pros::ADIDigitalOut piston(DRIVE_PNEUMATIC);         //Piston on DRIVE_PNEUMATIC port
pros::ADILineSensor linetrackerL(LINE_TRACKER_LEFT); //Line tracker on LINE_TRACKER_LEFT port
pros::ADILineSensor linetrackerR(LINE_TRACKER_RIGHT); //Line tracker on LINE_TRACKER_LEFT port
pros::ADIAnalogIn gyro (GYRO_PORT);
pros::ADIUltrasonic ultrasonic1(ULTRASONIC_IN, ULTRASONIC_OUT);
