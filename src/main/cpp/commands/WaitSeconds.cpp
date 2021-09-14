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
#include "commands/WaitSeconds.h"
//#include "frc/commands/Command.h"


WaitSeconds::WaitSeconds(double time)
    
 {
    SetName("WaitSeconds");
  // Use addRequirements() here to declare subsystem dependencies.
  
    m_time = time;

}

// Called just before this Command runs the first time
void WaitSeconds::Initialize() {
    //frc::SetTimeout(m_time);
     m_timer.Reset();
     m_timer.Start();
}

// Called repeatedly when this Command is scheduled to run
void WaitSeconds::Execute() {
  
}

// Make this return true when this Command no longer needs to run execute()
bool WaitSeconds::IsFinished() {
       if (m_timer.Get() >= m_time){
       //if(IsTimedOut()) { 
         
          return true;
    }
    else {
       return false;
    }
}
// Called once after isFinished returns true
void WaitSeconds::End(bool interrupted) {
   
}

// Called when another command which requires one or more of the same
// subsystems is scheduled to run
//void WaitSeconds::Interrupted() {
//  End();
//}
