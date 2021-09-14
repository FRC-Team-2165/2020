#include "Robot.h"
#include "frc/smartdashboard/SmartDashboard.h"
#include "commands/MoveThroughAngle.h"
#include <math.h>

MoveThroughAngle::MoveThroughAngle(double angle, double rate,double time,DriveTrain* drivetrain)
 :m_drivetrain(drivetrain),m_angle(angle),m_rate(rate),m_time(time)
 {
    SetName("MoveThroughAngle");
  // Use addRequirements() here to declare subsystem dependencies.
  AddRequirements({m_drivetrain});


 // m_set_gyro_Kp = 0.1;
}



// Called just before this Command runs the first time
void MoveThroughAngle::Initialize() {
    static int m_counter = 0;
    m_counter++;
    frc::SmartDashboard::PutNumber("m_counter", m_counter);
    m_timer.Reset();
    m_timer.Start();
    m_oldclamp = m_drivetrain->GetPidClamp();
    m_drivetrain->SetPidClamp(0.4);

  //oldPid_Kp1 = m_drivetrain->GetPID_Parm_Kp();
  //m_drivetrain->SetPID_Parm_Kp(m_set_gyro_Kp);

 // m_drivetrain->EnableGyroPID();
  m_drivetrain->ZeroAngle();
  m_drivetrain->SetAngleSetPt(m_angle);
  double myangle = m_angle;
  frc::SmartDashboard::PutNumber("Rotate Angle", myangle);
}

// Called repeatedly when this Command is scheduled to run
void MoveThroughAngle::Execute() {
  double robot_angle = m_drivetrain->GetGyroAngle();
  frc::SmartDashboard::PutNumber("Robot Angle", robot_angle);
  m_drivetrain->GyroArcadeDrive(0.0);
 }

// Make this return true when this Command no longer needs to run execute()
bool MoveThroughAngle::IsFinished() {
    //if(m_timer.Get() >= m_time)  {


      bool atsetpt = fabs(fabs(m_drivetrain->GetGyroAngle()) - fabs(m_angle)) < 1.0;
      //if(m_timer.Get() >= m_time || m_drivetrain->AtSetpoint()) {
      if(m_timer.Get() >= m_time || atsetpt) {  
       m_drivetrain->NoGyroArcadeDrive(0.0, 0.0);
       return true;
       
    }
    else {
       return false;
   }
}

// Called once after isFinished returns true
void MoveThroughAngle::End(bool interrupted) {
  m_drivetrain->NoGyroArcadeDrive(0.0, 0.0);
  //m_driveTrain->SetPID_Parm_Kp(oldPid_Kp1);
  m_drivetrain->SetAngleSetPt(0.0);
  m_drivetrain->SetPidClamp(m_oldclamp);
}
