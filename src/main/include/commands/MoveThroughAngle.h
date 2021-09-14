/*----------------------------------------------------------------------------*/
/* Copyright (c) 2019 FIRST. All Rights Reserved.                             */
/* Open Source Software - may be modified and shared by FRC teams. The code   */
/* must be accompanied by the FIRST BSD license file in the root directory of */
/* the project.                                                               */
/*----------------------------------------------------------------------------*/

#pragma once


//#include <frc2/command/CommandBase.h>
#include <frc2/command/CommandBase.h>
#include <frc2/command/CommandHelper.h>
#include <frc2/command/WaitCommand.h>
#include "subsystems/DriveTrain.h"
#include <frc/Timer.h>

/**
 * An example command.
 *
 * <p>Note that this extends CommandHelper, rather extending CommandBase
 * directly; this is crucially important, or else the decorator functions in
 * Command will *not* work!
 */

//class ArmMotorOn : public frc2::CommandHelper<frc2::CommandBase, ArmMotorOn> {
class MoveThroughAngle
    //: public frc2::CommandHelper<frc2::WaitCommand, ArmMotorOn>
    : public frc2::CommandHelper<frc2::CommandBase, MoveThroughAngle>
     {

 public:
 
  explicit MoveThroughAngle(double angle,double rate,double time,DriveTrain* drivetrain);
 void Initialize() override;

  void Execute() override;

  void End(bool interrupted) override;

  bool IsFinished() override;

 private:
  DriveTrain * m_drivetrain;
  double m_angle;
  double m_rate;
  double m_time;
  frc::Timer m_timer;
  double m_oldclamp;
  //double m_save_gyro_Kp;
  //double m_set_gyro_Kp;
  //double sgn(double);
  //double oldPidRange;
  //double oldPid_Kp1;


};
