/*----------------------------------------------------------------------------*/
/* Copyright (c) 2019 FIRST. All Rights Reserved.                             */
/* Open Source Software - may be modified and shared by FRC teams. The code   */
/* must be accompanied by the FIRST BSD license file in the root directory of */
/* the project.                                                               */
/*                                                                            */
/* Uses decorator function to terminate command after 1 second                */                                              
/*----------------------------------------------------------------------------*/

#include "Robot.h"
#include "frc/smartdashboard/SmartDashboard.h"
#include "commands/MoveTimed.h"
//#include "frc/commands/Command.h"


MoveTimed::MoveTimed(double speed,double time,bool dir,DriveTrain* drivetrain)
    :m_drivetrain(drivetrain),m_speed(speed),m_time(time),m_dir(dir)
 {
    SetName("MoveTimed");
  // Use addRequirements() here to declare subsystem dependencies.
  AddRequirements({m_drivetrain});
  
  m_speed = speed;
  m_dir = dir;
  m_time = time;
    if(m_dir == true)
     m_speed = -m_speed;

}

// Called just before this Command runs the first time
void MoveTimed::Initialize() {
    //frc::SetTimeout(m_time);
     m_timer.Reset();
     m_timer.Start();
    // m_drivetrain->ApplyWheelBrakes();  // 
	  m_drivetrain->ReleaseWheelBrakes();
}

// Called repeatedly when this Command is scheduled to run
void MoveTimed::Execute() {
  m_drivetrain->NoGyroArcadeDrive(m_speed,0.0);
}

// Make this return true when this Command no longer needs to run execute()
bool MoveTimed::IsFinished() {
       if (m_timer.Get() >= m_time){
       //if(IsTimedOut()) { 
          m_drivetrain->NoGyroArcadeDrive(0.0, 0.0);
          return true;
    }
    else {
       return false;
    }
}
// Called once after isFinished returns true
void MoveTimed::End(bool interrupted) {
   m_drivetrain->NoGyroArcadeDrive(0.0, 0.0);
   m_drivetrain->ApplyWheelBrakes();  //
   //m_drivetrain->ReleaseWheelBrakes();
}

// Called when another command which requires one or more of the same
// subsystems is scheduled to run
//void MoveTimed::Interrupted() {
//  End();
//}
