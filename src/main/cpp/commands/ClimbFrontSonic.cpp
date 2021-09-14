/*----------------------------------------------------------------------------*/
/* Copyright (c) 2017-2018 FIRST. All Rights Reserved.                        */
/* Open Source Software - may be modified and shared by FRC teams. The code   */
/* must be accompanied by the FIRST BSD license file in the root directory of */
/* the project.                                                               */
/*----------------------------------------------------------------------------*/

#include "Robot.h"
#include "frc/smartdashboard/SmartDashboard.h"
#include "commands/ClimbFrontSonic.h"
#include <math.h>
#include "RobotContainer.h"


ClimbFrontSonic::ClimbFrontSonic(double distance, double speed,double time,WinchMotor* winchmotor,UltraSonic* ultrasonic)
 :m_winchmotor(winchmotor),m_ultrasonic(ultrasonic),m_speed(speed),m_time(time),m_distance(distance)
 {
    SetName("ClimbFrontSonic");
  // Use addRequirements() here to declare subsystem dependencies.
  AddRequirements({m_winchmotor});
  AddRequirements({m_ultrasonic});

	  m_distance = fabs(m_distance);
	  m_speed = fabs(m_speed);
	  m_tolerance = 2.5;
	  m_quit = false;

	m_ultrasonic->SetCounterReset();
	m_ultrasonic->FrontSonicOff();
}

// Called just before this Command runs the first time
void ClimbFrontSonic::Initialize() {
    m_timer.Reset();
    m_timer.Start();
	m_quit = false;
	m_ultrasonic->FrontSonicOn();
	m_ultrasonic->SetCounterReset();
}

// Called repeatedly when this Command is scheduled to run
void ClimbFrontSonic::Execute() {

    double winchcurrent = m_winchmotor->GetOutPutCurrent();
    frc::SmartDashboard::PutNumber("Winch Current",winchcurrent);
	double m_joyY = Robot::robotContainer->getJoystick1()->GetY();
	m_speed = std::clamp(m_joyY, -1.0, 0.0);
    /*
  	double ultraRange = m_ultrasonic->GetRange();
	if(ultraRange != 0.0) {
		if(ultraRange < m_distance) {
		m_winchmotor->StartMotor(m_speed);// drive backward
		}
		//if(ultraRange > m_distance) {
		//   m_winchmotor->StartMotor(-m_speed);// drive forward
		//}
		if(fabs(m_distance - ultraRange)<= m_tolerance) {
			m_winchmotor->StopMotor();
			m_quit = true;
		}

*/
       double m_infrared_value = m_winchmotor->IR_Analog()/1000.0 ;
       double maxht = 1.00;
       //double minht = 1.00;

	   if( m_infrared_value <maxht)
	   {
		   //m_quit = true;
		   	m_winchmotor->StopMotor();
	   }
	   else
	   {
		   m_winchmotor->StartMotor(m_speed);
		  // if(m_winchmotor->IR_AtSetpt(m_infrared_value,minht,maxht))
		  // {
		//	   	m_winchmotor->StopMotor();
		//	    m_quit = true;
		//   }
	   }
  }
  





// Make this return true when this Command no longer needs to run execute()
bool ClimbFrontSonic::IsFinished() {
  if(m_quit || (m_timer.Get() >= m_time)){
		return true;
	}
	else {
		return false;
	}
}

// Called once after isFinished returns true
void ClimbFrontSonic::End(bool interrupted) {
  m_winchmotor->StopMotor();
  m_ultrasonic->FrontSonicOff();
}
