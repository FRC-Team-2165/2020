/*----------------------------------------------------------------------------*/
/* Copyright (c) 2019 FIRST. All Rights Reserved.                             */
/* Open Source Software - may be modified and shared by FRC teams. The code   */
/* must be accompanied by the FIRST BSD license file in the root directory of */
/* the project.                                                               */
/*----------------------------------------------------------------------------*/

#pragma once

#include <frc2/command/WaitCommand.h>
#include <frc2/command/CommandHelper.h>
#include "subsystems/PneumaticShift_2.h"
//#include <frc2/command/CommandBase.h>

/**
 * An example command.
 *
 * <p>Note that this extends CommandHelper, rather extending CommandBase
 * directly; this is crucially important, or else the decorator functions in
 * Command will *not* work!
 */
class ShiftToLow
    : public frc2::CommandHelper<frc2::WaitCommand, ShiftToLow> {
 public:
  explicit ShiftToLow(PneumaticShift_2* pneumatic_2);

  void Initialize() override;

  //void Execute() override;

  void End(bool interrupted) override;

  //bool IsFinished() override;

  private:
    PneumaticShift_2* m_pneumaticshift_2;
};
