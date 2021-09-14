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
#include "subsystems/ArmReleaseServo.h"
#include <frc/Timer.h>
/**
 * An example command.
 *
 * <p>Note that this extends CommandHelper, rather extending CommandBase
 * directly; this is crucially important, or else the decorator functions in
 * Command will *not* work!
 */

//class SetRightServo : public frc2::CommandHelper<frc2::CommandBase, ArmMotorOn> {
class SetLeftServo
    //: public frc2::CommandHelper<frc2::WaitCommand, ArmMotorOn>
    : public frc2::CommandHelper<frc2::CommandBase, SetLeftServo>
     {
 public:
  explicit SetLeftServo(double angle, double time,ArmReleaseServo* armreleaseservo);

  void Initialize() override;

  //void Execute() override;

  void End(bool interrupted) override;

  bool IsFinished() override;
  
  private:
    ArmReleaseServo* m_armreleaseservo;
    double m_angle;
    double m_time;
    frc::Timer m_timer;
};
