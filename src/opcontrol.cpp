#include "main.h"
#include "okapi/api.hpp"
#include "definitions.hpp"

using namespace okapi;

//Better Button Names
ControllerButton RightBumperUP(ControllerDigital::R1);
ControllerButton RightBumperDOWN(ControllerDigital::R2);
ControllerButton LeftBumperUP(ControllerDigital::L1);
ControllerButton LeftBumperDOWN(ControllerDigital::L2);
ControllerButton ButtonA(ControllerDigital::A);
ControllerButton ButtonB(ControllerDigital::B);
ControllerButton ButtonX(ControllerDigital::X);
ControllerButton ButtonY(ControllerDigital::Y);
ControllerButton ButtonUP(ControllerDigital::up);
ControllerButton ButtonDOWN(ControllerDigital::down);
ControllerButton ButtonLEFT(ControllerDigital::left);
ControllerButton ButtonRIGHT(ControllerDigital::right);

////////////////////////////////////OPCONTROL///////////////////////////////////////////////////
void opcontrol() {

  Controller controller;
// n  Motor intakeL(abs(INTAKE_MOTOR_LEFT));         //motor on INTAKE_MOTOR_LEFT port
  Motor intakeR = 9_rmtr;                        //reversed motor on INTAKE_MOTOR_RIGHT port
//  Motor conveyor(CONVEYOR_MOTOR);                //motor on CONVEYOR_MOTOR port
//  Motor puncherR(PUNCHER_MOTOR_RIGHT);           //motor on PUNCHER_MOTOR_1 port
//  Motor rotatorL(ROTATOR_MOTOR_LEFT);            //motor on ROTATOR_MOTOR_LEFT port
  Motor rotatorR = 9_rmtr;                       //reversed motor on ROTATOR_MOTOR_RIGHT port
//  Motor puncherAngle(PUNCHER_ANGLE_MOTOR);       //motor on PUNCHER_ANGLE_MOTOR
	Motor liftR(LIFT_MOTOR_RIGHT);                 //motor on LIFT_MOTOR_RIGHT
	Motor liftL(LIFT_MOTOR_LEFT);
  int CURRENT_HEIGHT = 0;                  //For Lift
  bool STATE = LOW;                        //For Pneumatics //Change to false if this doesn't not work
  bool FLIP_STATE = 0;
  linetrackerL.calibrate();
  linetrackerR.calibrate();
  gyro.calibrate();
  int FLIP_OFF = 0;
  int FLIP_HOLD = -11;
  int FLIP_ON = -81;
  while (true)
	{
     // pros::lcd::initialize();
     // pros::lcd::print(0, "Joystick valY: %d", controller.getAnalog(ControllerAnalog::leftY));
     // pros::lcd::print(0, "Joystick valX: %d", controller.getAnalog(ControllerAnalog::leftX));
		 //////////////////////////////CHASSIS(DRIVE)///////////////////////////////
	 	 //Arcade drive FW-BW on Left Y axis turns on Right X
     // if ( (controller.getAnalog(ControllerAnalog::leftY) < 50) || (controller.getAnalog(ControllerAnalog::rightX) < 50))
     // {
     //     driveController.arcade(controller.getAnalog(ControllerAnalog::leftY)/2, controller.getAnalog(ControllerAnalog::rightX)/2);
     // }
     // else
     // {
     driveController.arcade(controller.getAnalog(ControllerAnalog::leftY), -controller.getAnalog(ControllerAnalog::leftX));
     // }
     //////////////////////////////TRANSMISSION/////////////////////////////////
     if (RightBumperUP.changedToPressed() && RightBumperDOWN.changedToPressed())
     {
         STATE = !STATE;
         piston.set_value(STATE);
     }
     /////////////////////////////INTAKE ROTATOR////////////////////////////////

          if (ButtonDOWN.changedToPressed())      //Press button to flip Intake
         {
            rotatorController.setTarget(FLIP_OFF);
            FLIP_STATE = FLIP_OFF;
          }
         else if (ButtonRIGHT.changedToPressed())
         {
            rotatorController.setTarget(FLIP_HOLD);
            FLIP_STATE = FLIP_HOLD;
          }
         else if (ButtonUP.changedToPressed())
         {
           rotatorController.setTarget(FLIP_ON);
            FLIP_STATE = FLIP_ON;
         }
     // if (ButtonRIGHT.changedToPressed())      //Press button to flip intake
     // {
     //   rotatorController.setTarget(FLIP_TARGET); //90 is 180 degrees apparently
     //     if (FLIP_STATE == false)
     //     {
     //       FLIP_TARGET = 0;
     //     }
     //     else if (FLIP_STATE == true)
     //     {
     //       FLIP_TARGET = -81;
     //     }
     //     FLIP_STATE = !FLIP_STATE;
     // }
     /////////////////////////////////LIFT//////////////////////////////////////
      if (ButtonB.changedToPressed())      //Press button to go to raise lift to height
     {
        liftController.setTarget(STARTING_HEIGHT);
        CURRENT_HEIGHT = STARTING_HEIGHT;
      }
     else if (ButtonA.changedToPressed())
     {
        liftController.setTarget(LOW_GOAL_HEIGHT);
        CURRENT_HEIGHT = LOW_GOAL_HEIGHT;
      }
     else if (ButtonX.changedToPressed())
     {
       liftController.setTarget(HIGH_GOAL_HEIGHT);
        CURRENT_HEIGHT = HIGH_GOAL_HEIGHT;
     }
      else if (ButtonY.changedToPressed() && (CURRENT_HEIGHT >= DROP_HEIGHT))
      {
        liftController.setTarget(CURRENT_HEIGHT-DROP_HEIGHT);      //Drop lift a bit to place cap on post
      }
     // liftR.move_voltage(controller.getAnalog(ControllerAnalog::rightY)*12000);
     // liftL.move_voltage(controller.getAnalog(ControllerAnalog::rightY)*12000);

     /////////////////////////////////INTAKE////////////////////////////////////
     // //using straight up move commands instead of okapilib
     // //how to use target for okapilib velPID? rpm? 0-100? 0-127?
     // if (RightBumperUP.isPressed())          //Hold button to Chupa Intake
     // {
     //     intakeL.move_voltage(12000);
     //     intakeR.move_voltage(12000);
     // }
     // else if (RightBumperDOWN.isPressed())  //Hold button to Bota Intake
     // {
     //     intakeL.move_voltage(-12000);
     //     intakeR.move_voltage(-12000);
     // }
     // else                                   //Intake stops if nothing is pressed
     // {
     //     intakeL.move_voltage(0);
     //     intakeR.move_voltage(0);
     // }
     ///////////////////////////////CONVEYOR////////////////////////////////////
     // //using straight up move commands instead of okapilib
     // //how to use target for okapilib velPID? rpm? 0-100? 0-127?
     // if (LeftBumperUP.isPressed())
     // {
     //     conveyor.move_voltage(12000);
     // }
     // else if (LeftBumperUP.isPressed())
     // {
     //     conveyor.move_voltage(-12000);
     // }
     // else
     // {
     //     conveyor.move_voltage(0);
     // }

     ////////////////////////////////PUNCHER////////////////////////////////////
     // if (ButtonLEFT.isPressed())                //Hold Button to fire puncher
     // {
     //     puncherR.move_voltage(12000);
     // }
     // else
     // {
     //     puncherR.move_voltage(0);
     // }
     /////////////////////////////PUNCHER ANGLLE////////////////////////////////
     // if (ButtonUP.isPressed())
     // {
     //     puncherAngle.move_voltage(6000);
     // }
     // else if (ButtonDOWN.isPressed())
     // {
     //     puncherAngle.move_voltage(-6000);
     // }
     // else
     // {
     //     puncherAngle.move_voltage(0);
     // }

		 pros::Task::delay(20);
	 }
}
