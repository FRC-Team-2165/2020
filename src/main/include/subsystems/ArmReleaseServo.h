/*----------------------------------------------------------------------------*/
/* Copyright (c) 2017-2018 FIRST. All Rights Reserved.                        */
/* Open Source Software - may be modified and shared by FRC teams. The code   */
/* must be accompanied by the FIRST BSD license file in the root directory of */
/* the project.                                                               */
/*----------------------------------------------------------------------------*/

#pragma once
#include <frc2/command/SubsystemBase.h>
//#include <ctre/Phoenix.h>
#include "Constants.h"  //contains namespaces
#include <math.h>
#include <frc/Servo.h>


class ArmReleaseServo : public frc2::SubsystemBase {
 private:
  // It's desirable that everything possible under private except
  // for methods that implement subsystem capabilities
  frc::Servo  m_armReleaseLeft;
  frc::Servo  m_armReleaseRight;

 public:
  ArmReleaseServo();
  
  
  void SetReleaseAngleLeft(double);
  void SetReleaseValueLeft(double);
  double GetReleaseAngleLeft();
  double GetReleaseValueLeft();
  //void SetReleaseSpeedLeft(double speed);


  void SetReleaseAngleRight(double);
  void SetReleaseValueRight(double);
  double GetReleaseAngleRight();
  double GetReleaseValueRight();
  //void SetReleaseSpeedRight(double speed);

 void Log();


 };
