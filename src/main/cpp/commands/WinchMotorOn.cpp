/*----------------------------------------------------------------------------*/
/* Copyright (c) 2019 FIRST. All Rights Reserved.                             */
/* Open Source Software - may be modified and shared by FRC teams. The code   */
/* must be accompanied by the FIRST BSD license file in the root directory of */
/* the project.                                                               */
/*                                                                            */
/* Uses decorator function to terminate command after 1 second                */                                              
/*----------------------------------------------------------------------------*/

#include "commands/WinchMotorOn.h"
#include "Robot.h"
#include "frc/smartdashboard/SmartDashboard.h"

WinchMotorOn::WinchMotorOn(double speed,int fwd_rev,int pressedOrheld,WinchMotor* winchmotor) 
//: frc2::CommandHelper<frc2::CommandBase, WinchMotorOn>
//ArmMotorOn::WinchMotorOn(double speed,int fwd_rev,ArmMotor* armmotor) 
//  : frc2::CommandHelper<frc2::WaitCommand, WinchMotorOn>(1_s)
    :m_winchmotor(winchmotor),m_speed(speed),m_fwd_rev(fwd_rev),m_pressedOrheld(pressedOrheld)
   {
   //m_winchmotor=winchmotor;
   //m_speed=speed;
   //m_fwd_rev=fwd_rev;
 
  SetName("WinchMotorOn");
  // Use addRequirements() here to declare subsystem dependencies.
  AddRequirements({m_winchmotor});
}

// Called when the command is initially scheduled.
void WinchMotorOn::Initialize() {
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
  m_winchmotor->StartMotor(m_speed);
  frc::SmartDashboard::PutString("WinchMotorOn", "true");
  frc::SmartDashboard::PutNumber("Winch Speed",m_speed); 
}

// Called repeatedly when this Command is scheduled to run
void WinchMotorOn::Execute() {

    m_winchcurrent = m_winchmotor->GetOutPutCurrent();
    frc::SmartDashboard::PutNumber("Winch Current",m_winchcurrent);
}


// Called once the command ends or is interrupted.
void WinchMotorOn::End(bool interrupted) {
   if(m_pressedOrheld > 0)
      m_winchmotor->StopMotor();
 }

// Returns true when the command should end.
bool WinchMotorOn::IsFinished() { 
  if(m_pressedOrheld == 0)
      return true;
   else   
      return false; 
}
