#include "main.h"
#include "BYCD7.hpp"

/////
// For instalattion, upgrading, documentations and tutorials, check out website!
// https://ez-robotics.github.io/EZ-Template/
/////


// Chassis constructor
Drive chassis (
  // Left Chassis Ports (negative port will reverse it!)
  //   the first port is the sensored port (when trackers are not used!)
  {-20, -10},

  // Right Chassis Ports (negative port will reverse it!)
  //   the first port is the sensored port (when trackers are not used!)
  {11, 18}

  // IMU Port
  ,13

  // Wheel Diameter (Remember, 4" wheels are actually 4.125!)
  //    (or tracking wheel diameter)
  ,4.125

  // Cartridge RPM
  //   (or tick per rotation if using tracking wheels)
  ,200

  // External Gear Ratio (MUST BE DECIMAL)
  //    (or gear ratio of tracking wheel)
  // eg. if your drive is 84:36 where the 36t is powered, your RATIO would be 2.333.
  // eg. if your drive is 36:60 where the 60t is powered, your RATIO would be 0.6.
  // 84: 60 where the 60t is powered, RATIO 1.4
  ,1.4

  // Uncomment if using tracking wheels
  /*
  // Left Tracking Wheel Ports (negative port will reverse it!)
  // ,{1, 2} // 3 wire encoder
  // ,8 // Rotation sensor

  // Right Tracking Wheel Ports (negative port will reverse it!)
  // ,{-3, -4} // 3 wire encoder
  // ,-9 // Rotation sensor
  */

  // Uncomment if tracking wheels are plugged into a 3 wire expander
  // 3 Wire Port Expander Smart Port
  // ,1
);



/**
 * Runs initialization code. This occurs as soon as the program is started.
 *
 * All other competition modes are blocked by initialize; it is recommended
 * to keep execution time for this mode under a few seconds.
 */
void initialize() {
  // Print our branding over your terminal :D
  ez::print_ez_template();
  
  pros::delay(500); // Stop the user from doing anything while legacy ports configure.

  // Configure your chassis controls
  chassis.toggle_modify_curve_with_controller(true); // Enables modifying the controller curve with buttons on the joysticks
  chassis.set_active_brake(0.1); // Sets the active brake kP. We recommend 0.1.
  chassis.set_curve_default(0, 0); // Defaults for curve. If using tank, only the first parameter is used. (Comment this line out if you have an SD card!)  
  default_constants(); // Set the drive to your own constants from autons.cpp!
  exit_condition_defaults(); // Set the exit conditions to your own constants from autons.cpp!

  // These are already defaulted to these buttons, but you can change the left/right curve buttons here!
  // chassis.set_left_curve_buttons (pros::E_CONTROLLER_DIGITAL_LEFT, pros::E_CONTROLLER_DIGITAL_RIGHT); // If using tank, only the left side is used. 
  // chassis.set_right_curve_buttons(pros::E_CONTROLLER_DIGITAL_Y,    pros::E_CONTROLLER_DIGITAL_A);

  // Autonomous Selector using LLEMU
  ez::as::auton_selector.add_autons({
    Auton("Test Drive\n\nBYCD7.", auto_test),
  });

  // Initialize chassis and auton selector
  chassis.initialize();
  ez::as::initialize();
}



/**
 * Runs while the robot is in the disabled state of Field Management System or
 * the VEX Competition Switch, following either autonomous or opcontrol. When
 * the robot is enabled, this task will exit.
 */
void disabled() {
  static int count = 1;
	printf("Disabled called %d\n", count++);

	while (true) {
		printf("Disabled loop");

		pros::delay(1000);
	}

}



/**
 * Runs after initialize(), and before autonomous when connected to the Field
 * Management System or the VEX Competition Switch. This is intended for
 * competition-specific initialization routines, such as an autonomous selector
 * on the LCD.
 *
 * This task will exit when the robot is enabled and autonomous or opcontrol
 * starts.
 */
void competition_initialize() {
  // . . .
}

// 오토 코드
void autonomous() {
  // 오토 세팅
  chassis.reset_pid_targets(); // Resets PID targets to 0
  chassis.reset_gyro(); // Reset gyro position to 0
  chassis.reset_drive_sensor(); // Reset drive sensors to 0
  chassis.set_drive_brake(MOTOR_BRAKE_HOLD); // Set motors to hold.  This helps autonomous consistency.

  ez::as::auton_selector.call_selected_auton(); // Calls selected auton from autonomous selector.
}

// 메뉴얼 코드
void opcontrol() {

  chassis.set_drive_brake(MOTOR_BRAKE_COAST);
  // Port 세팅
  // Intaker flag 선언
  intake.move_velocity(0);
  bool intake_flag = {false};
  bool intake_reverse_flag = {false};

  while (true) {

    chassis.tank(); // Tank control
    // chassis.arcade_standard(ez::SPLIT); // Standard split arcade
    // chassis.arcade_standard(ez::SINGLE); // Standard single arcade
    // chassis.arcade_flipped(ez::SPLIT); // Flipped split arcade
    // chassis.arcade_flipped(ez::SINGLE); // Flipped single arcade

    // Intake를 A버튼과 B버튼으로 토글해서 한번 누르면 계속 되게 flag를 만들어서 작성
        if(master.get_digital_new_press(DIGITAL_L1)) {
          intake_flag = !intake_flag;
          if(intake_flag) {
            intake.move_velocity(600);
          }
          else {
            intake.move_velocity(0);
          }
        }

        if(master.get_digital_new_press(DIGITAL_L2)) {
          intake_reverse_flag = !intake_reverse_flag;
          if(intake_reverse_flag) {
            intake.move_velocity(-600);
          }
          else {
            intake.move_velocity(0);
          }
        }

    // Roller
    if (master.get_digital(DIGITAL_R2)) {
      Roller.move_velocity(600);
    }
    else{
      Roller.move_velocity(0);
    }

  // Shooter Loading
    if (master.get_digital(DIGITAL_R1)) {
      while (Limit_Switch.get_value() == 0) {
      Shooter.move_velocity(600);
      }
      Shooter.move_velocity(0);
    }

    // Shooter Shooting
    if (master.get_digital(DIGITAL_R2)) {
      Shooter.move_relative(100, 600);
    }
    else{
      Shooter.move_velocity(0);
    }
  



    pros::delay(ez::util::DELAY_TIME); // This is used for timer calculations!  Keep this ez::util::DELAY_TIME
  }
}

