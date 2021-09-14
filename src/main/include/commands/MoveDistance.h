/*----------------------------------------------------------------------------*/
/* Copyright (c) 2017-2018 FIRST. All Rights Reserved.                        */
/* Open Source Software - may be modified and shared by FRC teams. The code   */
/* must be accompanied by the FIRST BSD license file in the root directory of */
/* the project.                                                               */
/*----------------------------------------------------------------------------*/

#pragma once


//#include <frc2/command/CommandBase.h>
#include <frc2/command/CommandBase.h>
#include <frc2/command/CommandHelper.h>
#include <frc2/command/WaitCommand.h>
#include "subsystems/RightWheelEncoder.h"
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
class MoveDistance
    //: public frc2::CommandHelper<frc2::WaitCommand, ArmMotorOn>
    : public frc2::CommandHelper<frc2::CommandBase, MoveDistance>
     {
 public:
  explicit MoveDistance(double distance,double speed,double timeout,DriveTrain* drivetrain,RightWheelEncoder* rightwheelencoder);

  void Initialize() override;

  void Execute() override;

  void End(bool interrupted) override;

  bool IsFinished() override;

  private:
    DriveTrain* m_drivetrain;
    RightWheelEncoder* m_rightwheelencoder;
    double m_distance;
    double m_speed;
    double m_timeout;
    frc::Timer m_timer;
};

