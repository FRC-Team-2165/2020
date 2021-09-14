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
#include "subsystems/HopperMotor.h"
#include <frc/Timer.h>


using namespace PneumaticsConstants;


/**
 * An example command.
 *
 * <p>Note that this extends CommandHelper, rather extending CommandBase
 * directly; this is crucially important, or else the decorator functions in
 * Command will *not* work!
 */

//class ArmMotorOn : public frc2::CommandHelper<frc2::CommandBase, ArmMotorOn> {
class HopperMotorOn
    //: public frc2::CommandHelper<frc2::WaitCommand, HopperMotorOn>
    : public frc2::CommandHelper<frc2::CommandBase, HopperMotorOn>
     {
 public:
  explicit HopperMotorOn(double speed, int fwd_rev,int pressedOrheld,HopperMotor* hoppermotor);

  void Initialize() override;

  void Execute() override;

  void End(bool interrupted) override;

  bool IsFinished() override;
  
  private:
    HopperMotor* m_hoppermotor;
    double m_speed;
    int m_fwd_rev;
    int m_pressedOrheld;
    
    frc::Timer m_FlipperUptimer;
    frc::Timer m_FlipperDowntimer;
    bool m_IsFlipperUp;
    bool m_IsFlipperDown;
    bool m_downwait;

};
