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
  //liftController.setTarget(50);
  //liftController.waitUntilSettled();
  driveController.moveDistance(5_in);
  driveController.setMaxVelocity(130);
  driveController.moveDistance(-47_in);
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
  driveController.setMaxVelocity(30);
  driveController.moveDistance(4_in);
  driveController.setMaxVelocity(50);
  pros::delay(500);
  liftController.setTarget(278);
  liftController.waitUntilSettled();
  pros::delay(500);
  driveController.moveDistance(-12_in);
  rotatorController.setTarget(FLIP_OFF);
  rotatorController.waitUntilSettled();

  liftController.setTarget(0);
  driveController.setMaxVelocity(130);
  driveController.turnAngle(91.5_deg);

  driveController.moveDistance(-64_in);
  pros::delay(5000);
  driveController.moveDistance(2_in);
  driveController.turnAngle(90_deg);
  //driveController.moveDistance(-12_in);
  driveController.forward(-10000);
  pros::delay(1000);
  driveController.forward(0);
  driveController.setMaxVelocity(60);
  driveController.moveDistance(44_in);
  liftController.setTarget(240);
  liftController.waitUntilSettled();
  driveController.moveDistance(-14_in);
  driveController.turnAngle(90_deg);
  rotatorController.setTarget(FLIP_ON);
  rotatorController.waitUntilSettled();
  liftController.setTarget(197);
  liftController.waitUntilSettled();
  pros::delay(500);
  driveController.moveDistance(-10_in);
  rotatorController.setTarget(FLIP_OFF);
  rotatorController.waitUntilSettled();
  liftController.setTarget(0);
  driveController.turnAngle(-120_deg);
  driveController.moveDistance(24_in);
  liftController.setTarget(40);
  pros::delay(500);
  driveController.moveDistance(-10_in);
  rotatorController.setTarget(FLIP_OFF);
}
