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

/**
 * An example command.
 *
 * <p>Note that this extends CommandHelper, rather extending CommandBase
 * directly; this is crucially important, or else the decorator functions in
 * Command will *not* work!
 */

//class WinchMotorOn : public frc2::CommandHelper<frc2::CommandBase, WinchMotorOn> {
class WinchMotorOn
    //: public frc2::CommandHelper<frc2::WaitCommand, WinchMotorOn>
    : public frc2::CommandHelper<frc2::CommandBase, WinchMotorOn>
     {
 public:
  explicit WinchMotorOn(double speed, int fwd_rev,int pressedOrheld,WinchMotor* winchmotor);

  void Initialize() override;

  void Execute() override;

  void End(bool interrupted) override;

  bool IsFinished() override;
  
  private:
    WinchMotor* m_winchmotor;
    double m_speed;
    int m_fwd_rev;
    int m_pressedOrheld;
    double m_winchcurrent;
};
