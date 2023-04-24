#pragma once
#ifndef _BYCD7_HEAD_H_
#define _BYCD7_HEAD_H_

#include "main.h"

// Motor Ports Set
inline pros::Controller master(pros::E_CONTROLLER_MASTER);
inline pros::Motor intake(5, pros::E_MOTOR_GEAR_GREEN, true, pros::E_MOTOR_ENCODER_COUNTS);
inline pros::Motor L_roller(1, pros::E_MOTOR_GEAR_RED, false, pros::E_MOTOR_ENCODER_COUNTS);
inline pros::Motor R_roller(12, pros::E_MOTOR_GEAR_RED, true, pros::E_MOTOR_ENCODER_COUNTS);
inline pros::Motor_Group Roller ({L_roller, R_roller});
inline pros::Motor L_Shooter (16, pros::E_MOTOR_GEAR_RED, true, pros::E_MOTOR_ENCODER_COUNTS);
inline pros::Motor R_Shooter (2, pros::E_MOTOR_GEAR_RED, false, pros::E_MOTOR_ENCODER_COUNTS);
inline pros::Motor_Group Shooter ({L_Shooter, R_Shooter});
inline pros::Motor L_Endgame (3, pros::E_MOTOR_GEAR_GREEN, true, pros::E_MOTOR_ENCODER_COUNTS);
inline pros::Motor R_Endgame (15, pros::E_MOTOR_GEAR_GREEN, false, pros::E_MOTOR_ENCODER_COUNTS);
inline pros::Motor_Group EndGame ({L_Endgame, R_Endgame});

inline pros::Rotation S_Lotation(14);

#endif