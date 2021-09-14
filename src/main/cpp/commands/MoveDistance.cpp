
/*----------------------------------------------------------------------------*/
/* Copyright (c) 2019 FIRST. All Rights Reserved.                             */
/* Open Source Software - may be modified and shared by FRC teams. The code   */
/* must be accompanied by the FIRST BSD license file in the root directory of */
/* the project.                                                               */
/*                                                                            */
/* Uses decorator function to terminate command after 1 second                */
/*----------------------------------------------------------------------------*/

#include "commands/MoveDistance.h"
#include "Robot.h"
#include "frc/smartdashboard/SmartDashboard.h"

MoveDistance::MoveDistance(double distance, double speed,double timeout,DriveTrain* drivetrain,RightWheelEncoder* rightwheelencoder)
    :m_drivetrain(drivetrain),m_rightwheelencoder(rightwheelencoder),m_distance(distance),m_speed(speed),m_timeout(timeout)
   {

  SetName("MoveDistance");
  // Use addRequirements() here to declare subsystem dependencies.
  AddRequirements({m_drivetrain});
  AddRequirements({m_rightwheelencoder});
}

// Called when the command is initially scheduled.
void MoveDistance::Initialize() {
  m_timer.Reset();
  m_timer.Start();
  m_rightwheelencoder->SetPID_OutputRange(m_speed);
  m_rightwheelencoder->ResetWheelEncoder();

  m_rightwheelencoder->SetDistanceSetPt(m_distance); // distance to travel

  m_rightwheelencoder->EnablePID();

  //m_drivetrain->EnableGyroPID();
  m_drivetrain->ZeroAngle();
  m_drivetrain->ApplyWheelBrakes();
}

 //Called repeatedly when this Command is scheduled to run
void MoveDistance::Execute() {


  double encoderDist = m_rightwheelencoder->GetEncoderDistance();
  double fabs_encoderDist = fabs(encoderDist);

  frc::SmartDashboard::PutNumber("encoderDist_MoveDist",encoderDist );

  if((fabs_encoderDist <= 12.0) || (fabs_encoderDist >= (fabs(m_distance) -12.0))){
    m_rightwheelencoder->SetPID_OutputRange(0.8*m_speed);
}
  else{
    m_rightwheelencoder->SetPID_OutputRange(m_speed);
  }

  double m_pidout = m_rightwheelencoder->PidOut();
    frc::SmartDashboard::PutNumber("Rwencoder m_pidout",m_pidout );
  m_drivetrain->GyroArcadeDrive(-m_pidout); // negative input to move forward
}


bool MoveDistance::IsFinished() {
  
       if ((m_timer.Get() >= m_timeout)||(m_rightwheelencoder->AtSetPt())){
       //if(IsTimedOut()) {
          m_drivetrain->NoGyroArcadeDrive(0.0, 0.0);
          return true;
    }
    else {
      
       return false;
    }
}

// Called once the command ends or is interrupted.
void MoveDistance::End(bool interrupted) {
  m_drivetrain->NoGyroArcadeDrive(0.0, 0.0);
  m_rightwheelencoder->DisablePID();
  m_drivetrain->ZeroAngle();
}

