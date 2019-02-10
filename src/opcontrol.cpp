#include "main.h"

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

///////////////////////////////////OPCONTROL///////////////////////////////////////////////////
void opcontrol() {

  Controller controller;
  int CURRENT_HEIGHT = 0;                  //For Lift
  pros::ADIDigitalOut piston(DRIVE_PNEUMATIC);
  bool STATE = LOW;                        //For Pneumatics //Change to false if this doesn't not work
  bool FLIP_STATE = 0;
  linetrackerL.calibrate();
  linetrackerR.calibrate();
  gyro.calibrate();
  bool complexCompleted = true;
  MotorGroup lift({LIFT_MOTOR_RIGHT, LIFT_MOTOR_LEFT});
  int flipHeight = 50;
  while (true)
	{
    // Chassis control
    driveController.arcade(controller.getAnalog(ControllerAnalog::leftY), -controller.getAnalog(ControllerAnalog::leftX));

    // Transmission
    if ((abs(controller.getAnalog(ControllerAnalog::leftY)) > 0.1 ||
    abs(controller.getAnalog(ControllerAnalog::leftX)) > 0.1) &&
    LeftBumperUP.isPressed() &&
    LeftBumperDOWN.changedToPressed()) {
         STATE = !STATE;
         piston.set_value(STATE);
    }

    // Flipper

    if(RightBumperUP.changedToPressed()) {
      if(FLIP_STATE == FLIP_OFF || FLIP_STATE == FLIP_HOLD) {
        rotatorController.setTarget(FLIP_ON);
        FLIP_STATE = FLIP_ON;
      }
      else {
        rotatorController.setTarget(FLIP_OFF);
        FLIP_STATE = FLIP_OFF;
      }
    }

    // if(RightBumperDOWN.changedToPressed()) {
    //   rotatorController.setTarget(FLIP_HOLD);
    //   FLIP_STATE = FLIP_HOLD;
    // }


    // if (ButtonDOWN.changedToPressed())      //Press button to flip Intake
    // {
    //   rotatorController.setTarget(FLIP_OFF);
    //   FLIP_STATE = FLIP_OFF;
    // } else if (ButtonRIGHT.changedToPressed())
    // {
    //   rotatorController.setTarget(FLIP_HOLD);
    //   FLIP_STATE = FLIP_HOLD;
    // } else if (ButtonUP.changedToPressed())
    // {
    //   rotatorController.setTarget(FLIP_ON);
    //   FLIP_STATE = FLIP_ON;
    // }



    // Lift
    if (ButtonB.changedToPressed())      //Press button to go to raise lift to height
     {
       if(liftController.isDisabled()){
         liftController.flipDisable();
       }
       liftController.setTarget(STARTING_HEIGHT);
       CURRENT_HEIGHT = STARTING_HEIGHT;
     }
     else if (ButtonA.changedToPressed())
     {
        if(liftController.isDisabled()){
          liftController.flipDisable();
        }
        liftController.setTarget(LOW_GOAL_HEIGHT);
        CURRENT_HEIGHT = LOW_GOAL_HEIGHT;
      }
     else if (ButtonX.changedToPressed())
     {
       if(liftController.isDisabled()){
         liftController.flipDisable();
       }
       liftController.setTarget(HIGH_GOAL_HEIGHT);
       CURRENT_HEIGHT = HIGH_GOAL_HEIGHT;
     }
     else if (ButtonY.changedToPressed() && (CURRENT_HEIGHT >= DROP_HEIGHT))
     {
       if(liftController.isDisabled()){
         liftController.flipDisable();
       }
       liftController.setTarget(CURRENT_HEIGHT-DROP_HEIGHT);      //Drop lift a bit to place cap on post
     }
     else if ( abs(controller.getAnalog(ControllerAnalog::rightY)) > 0.1) {
       if(!liftController.isDisabled()){
         liftController.flipDisable();
       }
       lift.moveVoltage(12000*controller.getAnalog(ControllerAnalog::rightY));
     } else if (liftController.isDisabled() && abs(controller.getAnalog(ControllerAnalog::rightY)) <= 0.1) {
       lift.moveVoltage(0);
     }

     // Complex motion
     if(ButtonY.changedToPressed()) {
       if(liftController.isDisabled()){
         liftController.flipDisable();
       }
       liftController.setTarget(CURRENT_HEIGHT + flipHeight);
       liftController.waitUntilSettled();
       rotatorController.setTarget(FLIP_ON);
       FLIP_STATE = FLIP_ON;
       rotatorController.waitUntilSettled();
       liftController.setTarget(CURRENT_HEIGHT);
     }

		 pros::Task::delay(20);
	 }
}
