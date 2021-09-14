/*----------------------------------------------------------------------------*/
/* Copyright (c) 2019 FIRST. All Rights Reserved.                             */
/* Open Source Software - may be modified and shared by FRC teams. The code   */
/* must be accompanied by the FIRST BSD license file in the root directory of */
/* the project.                                                               */
/*                                                                            */
/* Uses decorator function to terminate command after 1 second                */                                              
/*----------------------------------------------------------------------------*/

#include "commands/ShiftToHigh.h"
#include "Robot.h"
#include "frc/smartdashboard/SmartDashboard.h"

ShiftToHigh::ShiftToHigh(PneumaticShift_2* pneumatic_2) 
  : frc2::CommandHelper<frc2::WaitCommand, ShiftToHigh>(1_s),
  m_pneumaticshift_2(pneumatic_2) {
  
  SetName("ShiftToHigh");
  // Use addRequirements() here to declare subsystem dependencies.
  AddRequirements({m_pneumaticshift_2});
}

// Called when the command is initially scheduled.
void ShiftToHigh::Initialize() {
  m_pneumaticshift_2->HighGearRatio();
  frc2::WaitCommand::Initialize();
  frc::SmartDashboard::PutString("ShiftToHigh", "true");
}

// Called repeatedly when this Command is scheduled to run
//void ShiftToHigh::Execute() {}

// Called once the command ends or is interrupted.
void ShiftToHigh::End(bool interrupted) {
  m_pneumaticshift_2->ShiftOff();
}

// Returns true when the command should end.
//bool ShiftToHigh::IsFinished() { return false; }
