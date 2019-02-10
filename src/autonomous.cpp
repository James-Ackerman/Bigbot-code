#include "main.h"

/**
 * Runs the user autonomous code. This function will be started in its own task
 * with the default priority and stack size whenever the robot is enabled via
 * the Field Management System or the VEX Competition Switch in the autonomous
 * mode. Alternatively, this function may be called in initialize or opcontrol
 * for non-competition testing purposes.
 *
 * If the robot is disabled or communications is lost, the autonomous task
 * will be stopped. Re-enabling the robot will restart the task, not re-start it
 * from where it left off.
 */
void autonomous() {
  //if(liftController.isDisabled()){
  //  liftController.flipDisable();
  //}
  liftController.setTarget(50);
  liftController.waitUntilSettled();
  driveController.setMaxVelocity(130);
  driveController.moveDistance(-46_in);
  driveController.turnAngle(-45_deg);
  liftController.setTarget(0);
  driveController.setMaxVelocity(80);
  driveController.moveDistance(27_in);

  liftController.setTarget(40);
  driveController.setMaxVelocity(30);
  driveController.turnAngle(60_deg);
  driveController.setMaxVelocity(80);
  driveController.moveDistance(36_in);
  driveController.setMaxVelocity(50);
  driveController.turnAngle(75_deg);

  liftController.setTarget(320);
  liftController.waitUntilSettled();
  rotatorController.setTarget(FLIP_ON);
  driveController.moveDistance(13_in);
  liftController.setTarget(280);
  driveController.moveDistance(-13_in);

  liftController.setTarget(0);
  driveController.setMaxVelocity(130);
  driveController.turnAngle(95_deg);
  driveController.moveDistance(-58_in);
}
