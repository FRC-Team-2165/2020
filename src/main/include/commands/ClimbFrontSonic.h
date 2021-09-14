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
#include "subsystems/WinchMotor.h"
#include "subsystems/UltraSonic.h"
#include <frc/Timer.h>

/**
 * An example command.
 *
 * <p>Note that this extends CommandHelper, rather extending CommandBase
 * directly; this is crucially important, or else the decorator functions in
 * Command will *not* work!
 */

//class ArmMotorOn : public frc2::CommandHelper<frc2::CommandBase, ArmMotorOn> {
class ClimbFrontSonic
    //: public frc2::CommandHelper<frc2::WaitCommand, ArmMotorOn>
    : public frc2::CommandHelper<frc2::CommandBase, ClimbFrontSonic>
     {
 public:
  explicit ClimbFrontSonic( double distance,double speed, double time,WinchMotor* winchmotor,UltraSonic*ultrasonic);

  void Initialize() override;

  void Execute() override;

  //void Interrupted() override;

  void End(bool interrupted) override;

  bool IsFinished() override;

  private:
    WinchMotor * m_winchmotor;
    UltraSonic* m_ultrasonic;
    double m_speed;
    double m_time;
    frc::Timer m_timer;
    double m_distance;
	double m_tolerance;
	bool m_quit;

};
