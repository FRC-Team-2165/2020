/*----------------------------------------------------------------------------*/
/* Copyright (c) 2019 FIRST. All Rights Reserved.                             */
/* Open Source Software - may be modified and shared by FRC teams. The code   */
/* must be accompanied by the FIRST BSD license file in the root directory of */
/* the project.                                                               */
/*                                                                            */
/* Uses decorator function to terminate command after 1 second                */                                              
/*----------------------------------------------------------------------------*/

#include "commands/ArmMotorOn.h"
#include "Robot.h"
#include "frc/smartdashboard/SmartDashboard.h"

ArmMotorOn::ArmMotorOn(double speed,int fwd_rev,int pressedOrheld,ArmMotor* armmotor) 
//: frc2::CommandHelper<frc2::CommandBase, ArmMotorOn>
//ArmMotorOn::ArmMotorOn(double speed,int fwd_rev,ArmMotor* armmotor) 
//  : frc2::CommandHelper<frc2::WaitCommand, ArmMotorOn>(1_s)
    :m_armmotor(armmotor),m_speed(speed),m_fwd_rev(fwd_rev),m_pressedOrheld(pressedOrheld)
   {
   //m_armmotor=armmotor;
   //m_speed=speed;
   //m_fwd_rev=fwd_rev;
 
  SetName("ArmMotorOn");
  // Use addRequirements() here to declare subsystem dependencies.
  AddRequirements({m_armmotor});
}

// Called when the command is initially scheduled.
void ArmMotorOn::Initialize() {
  if(m_fwd_rev == 0)// forward
  {
     if(m_speed  < 0.0)
       m_speed = -m_speed;
  }
  if(m_fwd_rev > 0)// reverse
  {
     if(m_speed  > 0.0)
       m_speed = -m_speed;
  }
  m_armmotor->StartMotor(m_speed);
  frc::SmartDashboard::PutString("ArmMotorOn", "true");
}

// Called repeatedly when this Command is scheduled to run
//void ExtendRetriever::Execute() {}

// Called once the command ends or is interrupted.
void ArmMotorOn::End(bool interrupted) {
   if(m_pressedOrheld > 0)
      m_armmotor->StopMotor();
 }

// Returns true when the command should end.
bool ArmMotorOn::IsFinished() { 
  if(m_pressedOrheld == 0)
      return true;
   else   
      return false; 
}
