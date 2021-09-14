/*----------------------------------------------------------------------------*/
/* Copyright (c) 2019 FIRST. All Rights Reserved.                             */
/* Open Source Software - may be modified and shared by FRC teams. The code   */
/* must be accompanied by the FIRST BSD license file in the root directory of */
/* the project.                                                               */
/*----------------------------------------------------------------------------*/

#include "commands/ShiftToLow.h"
//#include "frc2/WaitCommand.h"
#include "Robot.h"


ShiftToLow::ShiftToLow(PneumaticShift_2* pneumatic_2) 
  : frc2::CommandHelper<frc2::WaitCommand, ShiftToLow>(1_s),
  m_pneumaticshift_2(pneumatic_2) {

  SetName("ShiftToLow");
  // Use addRequirements() here to declare subsystem dependencies.
  AddRequirements({m_pneumaticshift_2});
}

// Called when the command is initially scheduled.
void ShiftToLow::Initialize() {
  m_pneumaticshift_2->LowGearRatio();
  frc2::WaitCommand::Initialize();
}

// Called repeatedly when this Command is scheduled to run
//void ShiftToLow::Execute() {}

// Called once the command ends or is interrupted.
void ShiftToLow::End(bool interrupted) {
   m_pneumaticshift_2->ShiftOff(); 
}

// Returns true when the command should end.
//bool ShiftToLow::IsFinished() { return false; }
