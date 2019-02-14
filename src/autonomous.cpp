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
pros::ADIDigitalOut piston (DRIVE_PNEUMATIC);

void autonomous() {
  piston.set_value(LOW);
  liftController.setTarget(50);
  liftController.waitUntilSettled();
  driveController.setMaxVelocity(130);
  driveController.moveDistance(-46_in);
  driveController.turnAngle(-45_deg);
  liftController.setTarget(0);
  driveController.setMaxVelocity(40);
  driveController.moveDistance(27_in);

  liftController.setTarget(40);
  driveController.setMaxVelocity(30);
  driveController.turnAngle(70_deg);
  driveController.setMaxVelocity(80);
  driveController.moveDistance(37_in);
  driveController.setMaxVelocity(50);
  driveController.turnAngle(65_deg);

  // driveController.moveDistance(3_in);
  // driveController.moveDistance(-3_in);
  liftController.setTarget(320);
  liftController.waitUntilSettled();
  rotatorController.setTarget(FLIP_ON);
  rotatorController.waitUntilSettled();
  driveController.moveDistance(6_in);
  pros::delay(500);
  liftController.setTarget(280);
  driveController.moveDistance(-10_in);
  rotatorController.setTarget(FLIP_OFF);
  rotatorController.waitUntilSettled();

  liftController.setTarget(0);
  driveController.setMaxVelocity(130);
  driveController.turnAngle(90_deg);

  driveController.moveDistance(-64_in);
  driveController.moveDistance(2_in);
  driveController.turnAngle(90_deg);
  driveController.moveDistance(-8_in);
  driveController.setMaxVelocity(80);
  driveController.moveDistance(24_in);
  driveController.setMaxVelocity(40);
  driveController.moveDistance(16_in);
  liftController.setTarget(240);
  liftController.waitUntilSettled();
  rotatorController.setTarget(FLIP_ON);
  driveController.moveDistance(-12_in);
  driveController.turnAngle(90_deg);
  liftController.setTarget(197);
  driveController.moveDistance(-10_in);
  rotatorController.setTarget(FLIP_OFF);
  rotatorController.waitUntilSettled();
  liftController.setTarget(0);
  driveController.turnAngle(-110_deg);
}
