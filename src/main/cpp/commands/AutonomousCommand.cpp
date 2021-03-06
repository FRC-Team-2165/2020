/*----------------------------------------------------------------------------*/
/* Copyright (c) 2019 FIRST. All Rights Reserved.                             */
/* Open Source Software - may be modified and shared by FRC teams. The code   */
/* must be accompanied by the FIRST BSD license file in the root directory of */
/* the project.                                                               */
/*----------------------------------------------------------------------------*/

#include "commands/AutonomousCommand.h"

AutonomousCommand::AutonomousCommand(DriveTrain* drivetrain,
  PneumaticShift_2* pneumatic_2) : 
    m_drivetrain(drivetrain), m_pneumaticshift_2(pneumatic_2) {
      
  SetName("AutonomousCommand");

// Use addRequirements() here to declare subsystem dependencies.
  AddRequirements({m_drivetrain, m_pneumaticshift_2});
}

// Called when the command is initially scheduled.
void AutonomousCommand::Initialize() {}

// Called repeatedly when this Command is scheduled to run
void AutonomousCommand::Execute() {}

// Called once the command ends or is interrupted.
void AutonomousCommand::End(bool interrupted) {}

// Returns true when the command should end.
bool AutonomousCommand::IsFinished() { return false; }
