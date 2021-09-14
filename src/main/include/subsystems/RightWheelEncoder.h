/*----------------------------------------------------------------------------*/
/* Copyright (c) 2017-2018 FIRST. All Rights Reserved.                        */
/* Open Source Software - may be modified and shared by FRC teams. The code   */
/* must be accompanied by the FIRST BSD license file in the root directory of */
/* the project.                                                               */
/*----------------------------------------------------------------------------*/

#pragma once

#include <frc2/command/SubsystemBase.h>
#include <frc/controller/PIDController.h>
#include <frc/Encoder.h>
#include "Constants.h"  //contains namespaces
//#include <frc/WPILib.h>
//class RightWheelEncoder : public frc2::SubsystemBase, public frc::PIDOutput, public frc::PIDSource {
class RightWheelEncoder : public frc2::SubsystemBase {
private:
// It's desirable that everything possible under private except
// for methods that implement subsystem capabilities

  frc::Encoder m_rightEncoder;
  frc2::PIDController m_rightEncoderPID;
  
  
// PID parameters
  static double Kp2;
  static double Ki2;
  static double Kd2;

  double m_pidout;
  double m_outRange;
public:
 RightWheelEncoder();

  

  // encoder methods
  void ResetWheelEncoder();
  double GetSpeed();
  double GetEncoderDistance();

// PID controller methods
  void PIDWrite(double);// override;  // absolute virtual method in PIDOutput
  double PIDGet(); //override;  // absolute virtual method in PIDSource
  double PidOut(); // public access to PIDOut
  void EnablePID();
  void DisablePID();
  void SetDistanceSetPt(double);
  bool AtSetPt();
  void SetPID_OutputRange(double);
  void SetPID_InputRange(double);
  void ChangePID_Parm(double p, double i, double d);

};