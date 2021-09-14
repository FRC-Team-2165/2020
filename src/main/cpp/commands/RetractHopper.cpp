/*----------------------------------------------------------------------------*/
/* Copyright (c) 2019 FIRST. All Rights Reserved.                             */
/* Open Source Software - may be modified and shared by FRC teams. The code   */
/* must be accompanied by the FIRST BSD license file in the root directory of */
/* the project.                                                               */
/*                                                                            */
/* Uses decorator function to terminate command after 1 second                */                                              
/*----------------------------------------------------------------------------*/

#include "commands/RetractHopper.h"
#include "Robot.h"
#include "frc/smartdashboard/SmartDashboard.h"

RetractHopper::RetractHopper(HopperPneumatic* hopperpneumatic) 
  : frc2::CommandHelper<frc2::WaitCommand, RetractHopper>(1_s),
  m_hopperpneumatic(hopperpneumatic) {
  
  SetName("RetractHopper");
  // Use addRequirements() here to declare subsystem dependencies.
  AddRequirements({m_hopperpneumatic});
}

// Called when the command is initially scheduled.
void RetractHopper::Initialize() {
  m_hopperpneumatic->HopperRetract();
  frc2::WaitCommand::Initialize();
  frc::SmartDashboard::PutString("RetractHopper", "true");
}

// Called repeatedly when this Command is scheduled to run
//void RetractHopper::Execute() {}

// Called once the command ends or is interrupted.
void RetractHopper::End(bool interrupted) {
  m_hopperpneumatic->HopperOff();
}

// Returns true when the command should end.
//bool RetractHopper::IsFinished() { return false; }
