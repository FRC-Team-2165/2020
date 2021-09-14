/*----------------------------------------------------------------------------*/
/* Copyright (c) 2019 FIRST. All Rights Reserved.                             */
/* Open Source Software - may be modified and shared by FRC teams. The code   */
/* must be accompanied by the FIRST BSD license file in the root directory of */
/* the project.                                                               */
/*                                                                            */
/* Uses decorator function to terminate command after 1 second                */                                              
/*----------------------------------------------------------------------------*/

#include "commands/RetrieverMotorOn.h"
#include "Robot.h"
#include "frc/smartdashboard/SmartDashboard.h"

RetrieverMotorOn::RetrieverMotorOn(double speed,int fwd_rev,int pressedOrheld,RetrieverMotor* retrievermotor) 
//: frc2::CommandHelper<frc2::CommandBase, RetrieverMotorOn>
//RetrieverMotorOn::RetrieverMotorOn(double speed,int fwd_rev,RetrieverMotor* retrievermotor) 
//  : frc2::CommandHelper<frc2::WaitCommand, RetrieverMotorOn>(1_s)
    :m_retrievermotor(retrievermotor),m_speed(speed),m_fwd_rev(fwd_rev),m_pressedOrheld(pressedOrheld)
   {
   //m_retrievermotor=retrievermotor;
   //m_speed=speed;
   //m_fwd_rev=fwd_rev;
 
  SetName("RetrieverMotorOn");
  // Use addRequirements() here to declare subsystem dependencies.
  AddRequirements({m_retrievermotor});
}

// Called when the command is initially scheduled.
void RetrieverMotorOn::Initialize() {
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
  m_retrievermotor->StartMotor(m_speed);
  frc::SmartDashboard::PutString("RetrieverMotorOn", "true");
}

// Called repeatedly when this Command is scheduled to run
//void RetrieverMotorOn::Execute() {}



 //Called once the command ends or is interrupted.
void RetrieverMotorOn::End(bool interrupted) {
   if(m_pressedOrheld > 0)
     m_retrievermotor->StopMotor();
 }

// Returns true when the command should end.
bool RetrieverMotorOn::IsFinished() { 
  if(m_pressedOrheld == 0)
      return true;
   else   
      return false; 
}
