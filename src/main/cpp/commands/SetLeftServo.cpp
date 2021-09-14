/*----------------------------------------------------------------------------*/
/* Copyright (c) 2019 FIRST. All Rights Reserved.                             */
/* Open Source Software - may be modified and shared by FRC teams. The code   */
/* must be accompanied by the FIRST BSD license file in the root directory of */
/* the project.                                                               */
/*                                                                            */
/* Uses decorator function to terminate command after 1 second                */                                              
/*----------------------------------------------------------------------------*/

#include "commands/SetLeftServo.h"
#include "Robot.h"
#include "frc/smartdashboard/SmartDashboard.h"


SetLeftServo::SetLeftServo(double angle,double time,ArmReleaseServo* armreleaseservo) 
//: frc2::CommandHelper<frc2::CommandBase, ArmMotorOn>
//ArmMotorOn::ArmMotorOn(double speed,int fwd_rev,ArmMotor* armmotor) 
//  : frc2::CommandHelper<frc2::WaitCommand, ArmMotorOn>(1_s)
    :m_armreleaseservo(armreleaseservo),m_angle(angle),m_time(time)
   {
   //m_armmotor=armmotor;
   //m_speed=speed;
   //m_fwd_rev=fwd_rev;
 
  SetName("SetLeftServo");
  // Use addRequirements() here to declare subsystem dependencies.
  AddRequirements({m_armreleaseservo});
}

// Called when the command is initially scheduled.
void SetLeftServo::Initialize() {
  double cur_angle = m_armreleaseservo->GetReleaseAngleLeft();
  frc::SmartDashboard::PutNumber("Current Left Release  Angle",cur_angle); 
  frc::SmartDashboard::PutNumber("New Left Release Angle",m_angle); 
  m_armreleaseservo->SetReleaseAngleLeft(m_angle);
  m_timer.Reset();
  m_timer.Start();
}

// Called repeatedly when this Command is scheduled to run
//void SetRightServo::Execute() {}

// Called once the command ends or is interrupted.
void SetLeftServo::End(bool interrupted) {

}

// Returns true when the command should end.
bool SetLeftServo::IsFinished() { 
    if (m_timer.Get() >= m_time)
    {
       return true;
    }
    else 
    {
       return false;
    }
 }
