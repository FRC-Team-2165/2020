/*----------------------------------------------------------------------------*/
/* Copyright (c) 2019 FIRST. All Rights Reserved.                             */
/* Open Source Software - may be modified and shared by FRC teams. The code   */
/* must be accompanied by the FIRST BSD license file in the root directory of */
/* the project.                                                               */
/*                                                                            */
/* Uses decorator function to terminate command after 1 second                */                                              
/*----------------------------------------------------------------------------*/

#include "commands/SetRightServo.h"
#include "Robot.h"
#include "frc/smartdashboard/SmartDashboard.h"


SetRightServo::SetRightServo(double angle,double time,ArmReleaseServo* armreleaseservo) 
//: frc2::CommandHelper<frc2::CommandBase, ArmMotorOn>
//ArmMotorOn::ArmMotorOn(double speed,int fwd_rev,ArmMotor* armmotor) 
//  : frc2::CommandHelper<frc2::WaitCommand, ArmMotorOn>(1_s)
    :m_armreleaseservo(armreleaseservo),m_angle(angle),m_time(time)
   {
   //m_armmotor=armmotor;
   //m_speed=speed;
   //m_fwd_rev=fwd_rev;
 
  SetName("SetRightServo");
  // Use addRequirements() here to declare subsystem dependencies.
  AddRequirements({m_armreleaseservo});
}

// Called when the command is initially scheduled.
void SetRightServo::Initialize() {
  double cur_angle = m_armreleaseservo->GetReleaseAngleRight();
  frc::SmartDashboard::PutNumber("Current Right Release  Angle",cur_angle); 
  frc::SmartDashboard::PutNumber("New Right Release Angle",m_angle); 
  m_armreleaseservo->SetReleaseAngleRight(m_angle);
  m_timer.Reset();
  m_timer.Start();
}

// Called repeatedly when this Command is scheduled to run
//void SetRightServo::Execute() {}

// Called once the command ends or is interrupted.
void SetRightServo::End(bool interrupted) {

}

// Returns true when the command should end.
bool SetRightServo::IsFinished() { 
    if (m_timer.Get() >= m_time)
    {
       return true;
    }
    else 
    {
       return false;
    }
 }
