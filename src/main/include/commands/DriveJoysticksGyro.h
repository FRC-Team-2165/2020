/*----------------------------------------------------------------------------*/
/* Copyright (c) 2019 FIRST. All Rights Reserved.                             */
/* Open Source Software - may be modified and shared by FRC teams. The code   */
/* must be accompanied by the FIRST BSD license file in the root directory of */
/* the project.                                                               */
/*----------------------------------------------------------------------------*/

#pragma once

#include <frc2/command/CommandBase.h>
#include <frc2/command/CommandHelper.h>
#include "subsystems/DriveTrain.h"

/**
 * Using gyro 1/23/2020.
 *
 * <p>Note that this extends CommandHelper, rather extending CommandBase
 * directly; this is crucially important, or else the decorator functions in
 * Command will *not* work!
 */
class DriveJoysticksGyro
    : public frc2::CommandHelper<frc2::CommandBase, DriveJoysticksGyro> {
 public:
  // DriveJoysticksGyro(double move, double rotate, DriveTrain* drivetrain);
  DriveJoysticksGyro(std::function<double()> move, std::function<double()> rotate,
   DriveTrain* drivetrain);

  void Initialize() override;

  void Execute() override;

  void End(bool interrupted) override;

  bool IsFinished() override;

  

 private:
  std::function<double()> m_move;
  std::function<double()> m_rotate;
  DriveTrain* m_drivetrain;
  
  

  const double STRAIGHT_TOL = 0.35;  // this value was originally set at 0.5
	//const double MAXGYRORATE = 0.5;
  const double MAXGYRORATE = 0.25;
	bool curTransState;
	bool prevTransState;
	bool noGyroReset;
  double m_setZ_Gain;

	

};
