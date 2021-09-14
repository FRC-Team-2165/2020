/*----------------------------------------------------------------------------*/
/* Copyright (c) 2019 FIRST. All Rights Reserved.                             */
/* Open Source Software - may be modified and shared by FRC teams. The code   */
/* must be accompanied by the FIRST BSD license file in the root directory of */
/* the project.                                                               */
/*                                                                            */
/* Uses decorator function to terminate command after 1 second                */                                              
/*----------------------------------------------------------------------------*/

#include "commands/RetractRetriever.h"
#include "Robot.h"
#include "frc/smartdashboard/SmartDashboard.h"

RetractRetriever::RetractRetriever(RetrieverPneumatic* retrieverpneumatic) 
  : frc2::CommandHelper<frc2::WaitCommand, RetractRetriever>(1_s),
  m_retrieverpneumatic(retrieverpneumatic) {
  
  SetName("RetractRetriever");
  // Use addRequirements() here to declare subsystem dependencies.
  AddRequirements({m_retrieverpneumatic});
}

// Called when the command is initially scheduled.
void RetractRetriever::Initialize() {
  m_retrieverpneumatic->RetrieverRetract();
  frc2::WaitCommand::Initialize();
  frc::SmartDashboard::PutString("RetractRetriever", "true");
}

// Called repeatedly when this Command is scheduled to run
//void RetractRetriever::Execute() {}

// Called once the command ends or is interrupted.
void RetractRetriever::End(bool interrupted) {
  m_retrieverpneumatic->RetrieverOff();
}

// Returns true when the command should end.
//bool RetractRetriever::IsFinished() { return false; }
