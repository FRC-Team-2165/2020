/*----------------------------------------------------------------------------*/
/* Copyright (c) 2017-2018 FIRST. All Rights Reserved.                        */
/* Open Source Software - may be modified and shared by FRC teams. The code   */
/* must be accompanied by the FIRST BSD license file in the root directory of */
/* the project.                                                               */
/*----------------------------------------------------------------------------*/

#pragma once
#include <frc2/command/SubsystemBase.h>
#include <ctre/Phoenix.h>
#include "Constants.h"  //contains namespaces
#include <math.h>



class ArmMotor : public frc2::SubsystemBase {
 private:
  // It's desirable that everything possible under private except
  // for methods that implement subsystem capabilities
  WPI_TalonSRX  m_armMotor;

const int k_SlotIdx = 0;
const int k_TimeoutMs = 10; // blocks config until success, zero to skip checking

 public:
  ArmMotor();
  void ZeroAtRevLimitSwt();
  void ZeroAtFwdLimitSwt();
  bool IsUpperLimitClosed();
  bool IsLowerLimitClosed();
  void StopMotor();
  void StartMotor(double);
  bool IsPercentOutput();

 void Log();


 };
