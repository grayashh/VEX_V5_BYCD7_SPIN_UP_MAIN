#pragma once
#ifndef _BYCD7_HEAD_H_
#define _BYCD7_HEAD_H_

#include "main.h"

// Motor Ports Set
inline pros::Controller master(pros::E_CONTROLLER_MASTER);
inline pros::Motor intake(3, pros::E_MOTOR_GEAR_GREEN, true, pros::E_MOTOR_ENCODER_COUNTS);
inline pros::Motor h_motor(16, pros::E_MOTOR_GEAR_RED, true, pros::E_MOTOR_ENCODER_COUNTS);
inline pros::Motor L_roller(10, pros::E_MOTOR_GEAR_RED, false, pros::E_MOTOR_ENCODER_COUNTS);
inline pros::Motor R_roller(4, pros::E_MOTOR_GEAR_RED, true, pros::E_MOTOR_ENCODER_COUNTS);
inline pros::Motor_Group Roller ({L_roller, R_roller});
inline pros::Motor indexer(1, pros::E_MOTOR_GEAR_GREEN, true, pros::E_MOTOR_ENCODER_COUNTS);
inline pros::Motor U_Shooter (8, pros::E_MOTOR_GEAR_BLUE, true, pros::E_MOTOR_ENCODER_COUNTS);
inline pros::Motor D_Shooter (9, pros::E_MOTOR_GEAR_BLUE, false, pros::E_MOTOR_ENCODER_COUNTS);
inline pros::Motor_Group Shooter ({U_Shooter, D_Shooter});

#endif