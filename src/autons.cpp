#include "main.h"
#include "BYCD7.hpp"

/////
// For instalattion, upgrading, documentations and tutorials, check out website!
// https://ez-robotics.github.io/EZ-Template/
/////


const int DRIVE_SPEED = 110; // This is 110/127 (around 87% of max speed).  We don't suggest making this 127.
                             // If this is 127 and the robot tries to heading correct, it's only correcting by
                             // making one side slower.  When this is 87%, it's correcting by making one side
                             // faster and one side slower, giving better heading correction.
const int TURN_SPEED  = 90;
const int SWING_SPEED = 90;



///
// Constants
///

// It's best practice to tune constants when the robot is empty and with heavier game objects, or with lifts up vs down.
// If the objects are light or the cog doesn't change much, then there isn't a concern here.

void default_constants() {
  chassis.set_slew_min_power(80, 80);
  chassis.set_slew_distance(7, 7);
  chassis.set_pid_constants(&chassis.headingPID, 11, 0, 20, 0);
  chassis.set_pid_constants(&chassis.forward_drivePID, 0.45, 0, 5, 0);
  chassis.set_pid_constants(&chassis.backward_drivePID, 0.45, 0, 5, 0);
  chassis.set_pid_constants(&chassis.turnPID, 5, 0.003, 35, 15);
  chassis.set_pid_constants(&chassis.swingPID, 7, 0, 45, 0);
}

void one_mogo_constants() {
  chassis.set_slew_min_power(80, 80);
  chassis.set_slew_distance(7, 7);
  chassis.set_pid_constants(&chassis.headingPID, 11, 0, 20, 0);
  chassis.set_pid_constants(&chassis.forward_drivePID, 0.45, 0, 5, 0);
  chassis.set_pid_constants(&chassis.backward_drivePID, 0.45, 0, 5, 0);
  chassis.set_pid_constants(&chassis.turnPID, 5, 0.003, 35, 15);
  chassis.set_pid_constants(&chassis.swingPID, 7, 0, 45, 0);
}

void two_mogo_constants() {
  chassis.set_slew_min_power(80, 80);
  chassis.set_slew_distance(7, 7);
  chassis.set_pid_constants(&chassis.headingPID, 11, 0, 20, 0);
  chassis.set_pid_constants(&chassis.forward_drivePID, 0.45, 0, 5, 0);
  chassis.set_pid_constants(&chassis.backward_drivePID, 0.45, 0, 5, 0);
  chassis.set_pid_constants(&chassis.turnPID, 5, 0.003, 35, 15);
  chassis.set_pid_constants(&chassis.swingPID, 7, 0, 45, 0);
}

void exit_condition_defaults() {
  chassis.set_exit_condition(chassis.turn_exit, 100, 3, 500, 7, 500, 500);
  chassis.set_exit_condition(chassis.swing_exit, 100, 3, 500, 7, 500, 500);
  chassis.set_exit_condition(chassis.drive_exit, 80, 50, 300, 150, 500, 500);
}

void modified_exit_condition() {
  chassis.set_exit_condition(chassis.turn_exit, 100, 3, 500, 7, 500, 500);
  chassis.set_exit_condition(chassis.swing_exit, 100, 3, 500, 7, 500, 500);
  chassis.set_exit_condition(chassis.drive_exit, 80, 50, 300, 150, 500, 500);
}

void fire(){
  indexer.move_absolute(180,100);
  pros::Task::delay(500);
  indexer.move_absolute(-20,100);
}


///
// Drive Example
///
void auto_test() {

  indexer.set_zero_position(0);
  indexer.tare_position();
  // The first parameter is target inches
  // The second parameter is max speed the robot will drive at
  // The third parameter is a boolean (true or false) for enabling/disabling a slew at the start of drive motions
  // for slew, only enable it when the drive distance is greater then the slew distance + a few inches

  intake.move_velocity(500);
  chassis.set_drive_pid(-48, 30, true);
  chassis.wait_drive();

  chassis.set_swing_pid(ez::RIGHT_SWING, 130, 90);
  chassis.wait_drive();

  intake.move_velocity(0);

  chassis.set_drive_pid(-10, 100, true);
  chassis.wait_drive();

  Shooter.move_velocity(400);
  pros::Task::delay(6000);
  fire();
  pros::Task::delay(400);
  fire();
  pros::Task::delay(400);
  fire();
  Shooter.move_velocity(0);

  intake.move_velocity(600);

  chassis.set_drive_pid(25, 100, true);
  chassis.wait_drive();

  chassis.set_swing_pid(ez::LEFT_SWING, 45, 90);
  chassis.wait_drive();

  chassis.set_drive_pid(-44, DRIVE_SPEED);
  chassis.wait_drive();

  chassis.set_swing_pid(ez::RIGHT_SWING, 110, 90);
  chassis.wait_drive();

  intake.move_velocity(0);

  Shooter.move_velocity(400);
  pros::Task::delay(6000);
  fire();
  pros::Task::delay(400);
  fire();
  pros::Task::delay(1000);
  fire();
  Shooter.move_velocity(0);

  chassis.set_swing_pid(ez::RIGHT_SWING, 90, 90);
  chassis.wait_drive();

  chassis.set_drive_pid(-8, DRIVE_SPEED, true);
  chassis.wait_drive();

  Roller.move_relative(300, 100);


  // chassis.set_turn_pid(90, TURN_SPEED);
  // chassis.wait_drive();

  // chassis.set_swing_pid(ez::LEFT_SWING, 45, SWING_SPEED);
  // chassis.wait_drive();

  // chassis.set_drive_pid(24, DRIVE_SPEED, true);
  // chassis.wait_until(12);

  // chassis.set_swing_pid(ez::RIGHT_SWING, 0, SWING_SPEED);
  // chassis.wait_drive();

}



///
// Interference example
///
void tug (int attempts) {
  for (int i=0; i<attempts-1; i++) {
    // Attempt to drive backwards
    printf("i - %i", i);
    chassis.set_drive_pid(-12, 127);
    chassis.wait_drive();

    // If failsafed...
    if (chassis.interfered) {
      chassis.reset_drive_sensor();
      chassis.set_drive_pid(-2, 20);
      pros::delay(1000);
    }
    // If robot successfully drove back, return
    else {
      return;
    }
  }
}

// If there is no interference, robot will drive forward and turn 90 degrees. 
// If interfered, robot will drive forward and then attempt to drive backwards. 
void interfered_example() {
 chassis.set_drive_pid(24, DRIVE_SPEED, true);
 chassis.wait_drive();

 if (chassis.interfered) {
   tug(3);
   return;
 }

 chassis.set_turn_pid(90, TURN_SPEED);
 chassis.wait_drive();
}



// . . .
// Make your own autonomous functions here!
// . . .