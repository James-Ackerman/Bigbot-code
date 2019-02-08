#pragma once

#include "main.h"

// Sensor declarations
const int DRIVE_PNEUMATIC = 1;
const int LINE_TRACKER_LEFT = 2;
const int LINE_TRACKER_RIGHT = 3;
const int GYRO_PORT = 4;
const int ULTRASONIC_OUT = 5;
const int ULTRASONIC_IN = 6;

// Chassis declarations
const int DRIVE_MOTOR_LEFT_1 = -1;   //1,2,3 = Front, Middle, Back
const int DRIVE_MOTOR_LEFT_2 = 2;
const int DRIVE_MOTOR_LEFT_3 = -3;
const int DRIVE_MOTOR_RIGHT_1 = 4;   //1,2,3 = Front, Middle, Back
const int DRIVE_MOTOR_RIGHT_2 = -5;
const int DRIVE_MOTOR_RIGHT_3 = 6;

// Lift declaration
const double liftkP = 1.0;
const double liftkI = 0.001;
const double liftkD = 0.1;
const int LIFT_MOTOR_RIGHT = 8;
const int LIFT_MOTOR_LEFT = -7;

// Intake declaration
const double flipkP = 1200.0;
const double flipkI = 0.001;     //default, 1.0, 0.001, 0.1
const double flipkD = 0.1;
const int ROTATOR_MOTOR_RIGHT = 10;

// Controller declarations
inline extern const auto WHEEL_DIAMETER = 4_in;
inline extern const auto CHASSIS_WIDTH = 15_in;

inline auto driveController = ChassisControllerFactory::create(
  {DRIVE_MOTOR_RIGHT_1, DRIVE_MOTOR_RIGHT_2, DRIVE_MOTOR_RIGHT_3},
  {DRIVE_MOTOR_LEFT_1, DRIVE_MOTOR_LEFT_2, DRIVE_MOTOR_LEFT_3},
  AbstractMotor::gearset::green,
  {WHEEL_DIAMETER, CHASSIS_WIDTH}
);

inline auto liftController = AsyncControllerFactory::posIntegrated(
   {LIFT_MOTOR_RIGHT, LIFT_MOTOR_LEFT}
);

inline auto rotatorController = AsyncControllerFactory::posIntegrated(ROTATOR_MOTOR_RIGHT); //{ROTOATOR_MOTOR_RIGHT,ROTATOR_MOTOR_LEFT}

// For Driver Control height buttons
const int STARTING_HEIGHT = 10;
const int LOW_GOAL_HEIGHT = 200;
const int HIGH_GOAL_HEIGHT = 280;
const int DROP_HEIGHT = 20;

// ADI declarations
inline pros::ADIDigitalOut piston(DRIVE_PNEUMATIC);         //Piston on DRIVE_PNEUMATIC port
inline pros::ADILineSensor linetrackerL(LINE_TRACKER_LEFT); //Line tracker on LINE_TRACKER_LEFT port
inline pros::ADILineSensor linetrackerR(LINE_TRACKER_RIGHT); //Line tracker on LINE_TRACKER_LEFT port
inline pros::ADIAnalogIn gyro (GYRO_PORT);
inline pros::ADIUltrasonic ultrasonic1(ULTRASONIC_IN, ULTRASONIC_OUT);
