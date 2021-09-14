/*----------------------------------------------------------------------------*/
/* Copyright (c) 2019 FIRST. All Rights Reserved.                             */
/* Open Source Software - may be modified and shared by FRC teams. The code   */
/* must be accompanied by the FIRST BSD license file in the root directory of */
/* the project.                                                               */
/*----------------------------------------------------------------------------*/

#include "commands/DriveJoysticksGyro.h"
//#include <frc/buttons/JoystickButton.h>
#include "RobotContainer.h"
//#include "frc/joystick.h"
#include "Robot.h"
#include <frc/smartDashboard/SmartDashboard.h>
#include <math.h>

//DriveJoysticksGyro::DriveJoysticksGyro(double move,
//  double rotate, DriveTrain* drivetrain) 
//   : m_move(move), m_rotate(rotate), m_drivetrain(drivetrain) {


DriveJoysticksGyro::DriveJoysticksGyro(std::function<double()> move,
  std::function<double()> rotate, DriveTrain* drivetrain) 
  : m_move(move), m_rotate(rotate), m_drivetrain(drivetrain) {

  SetName("DriveJoysticksGyro");

 // Use addRequirements() here to declare subsystem dependencies.
  AddRequirements({m_drivetrain});

  curTransState = false;  // the use of curTransState and prevTransState ensures that
	prevTransState = false; // the transition from rotation to gyro control occurs on falling edge
							            // of the rotation joystick value, i.e. back to neutral rotational position
	noGyroReset = false;
//	m_setZ_Gain = 0.65;   
  m_setZ_Gain = 0.45; 
}

// Called when the command is initially scheduled.
void DriveJoysticksGyro::Initialize() {
  curTransState = false;
	prevTransState = false;
	noGyroReset = false;
	
	m_drivetrain->ZeroAngle();
	m_drivetrain->SetAngleSetPt(0.0);
//	m_drivetrain->>EnableGyroPID();  
	//m_drivetrain->ReleaseWheelBrakes();    
  m_drivetrain->ApplyWheelBrakes(); 
}

// Called repeatedly when this Command is scheduled to run
void DriveJoysticksGyro::Execute() {

    // double m_joyX = m_moveX(); // Mecanum drive - moveX, moveY and rotate must be included in class parameters
    double m_joyY = -m_move();
    //double m_joyZ = pow(m_rotate(),3);
    double m_joyZ = m_rotate();

  frc::SmartDashboard::PutBoolean("IsButton1_ON", m_drivetrain->IsButton1_On()); //ok works
  frc::SmartDashboard::PutBoolean("IsButton2_On", m_drivetrain->IsButton2_On()); //ok works
  frc::SmartDashboard::PutNumber("GetGyroAngle", m_drivetrain->GetGyroAngle());  // ok works
 
// if(RobotContainer::getJoystick1_Button2()->WhenPressed()) {m_joyZ = 0.0;}  // press button 2 to drive straight with no rotation
//    curTransState = (fabs(m_joyZ) >= STRAIGHT_TOL);
 //if(RobotContainer::getJoystick1_Button1()->WhenPressed() ) {curTransState = true;}
 //double m_joyY = Robot::robotContainer->getJoystick1()->GetY();  
 //double m_joyZ = Robot::robotContainer->getJoystick1()->GetZ(); 

 // if(m_drivetrain->IsButton2_On()) {m_joyZ = 0.0;}  // press button 2 to drive straight with no rotation
  if( Robot::robotContainer->getJoystick0()->GetRawButton(2)) {m_joyZ = 0.0;} 
    curTransState = (fabs(m_joyZ) >= STRAIGHT_TOL);  // value of (m_joyZ >= Tolerance) turns off gyro control
  //if(m_drivetrain->IsButton1_On() ) {curTransState = true;} // press trigger to disengage gyro || m_setGyroOff
  if(Robot::robotContainer->getJoystick0()->GetRawButton(1) ) {curTransState = true;} // press trigger to disengage gyro || m_setGyroOff
  frc::SmartDashboard::PutBoolean("curTransState", curTransState);


  if(curTransState) {  // if false drive with gyro control
  // set up for arcade drive
    m_drivetrain->NoGyroArcadeDrive(m_joyY, m_setZ_Gain*m_joyZ); 
  //  m_drivetrain->NoGyroMecanumDrive(m_joyY, -m_joyX, m_setZ_Gain*m_joyZ);  //Macanum Drive   
  }

  else if( (!curTransState && prevTransState) || noGyroReset) {
  // else if true, drive with rot set 0.0 and check to see if abs(gyro) is < a MAXGYRORATE
    m_drivetrain->NoGyroArcadeDrive(m_joyY, 0.0); // drive with zero rotation until gyro rate condition is met
  // m_drivetrain->NoGyroMecanumDrive(m_joyX, -m_joyY);  // Macanum Drive

      if(fabs(m_drivetrain->GetAngleRate()) < MAXGYRORATE) {
        m_drivetrain->ZeroAngle();
        noGyroReset = false;
      }
      else {noGyroReset = true;} // go around again to see if  gyro rate < max rate condition
  }
  else { // if none of the above are true; drive with gyro controlling the rotational mode"
  frc::SmartDashboard::PutNumber("m_joyY drive with gyro", m_joyY);
    m_drivetrain->GyroArcadeDrive(m_joyY);
  // m_drivetrain->GyroMecanmuDrive(m_joyX, -m_joyY);  
  } 
  prevTransState = curTransState;
}  // end of Execute()


// Called once the command ends or is interrupted.
void DriveJoysticksGyro::End(bool interrupted) {
  m_drivetrain->NoGyroArcadeDrive(0.0, 0.0);
}

// Returns true when the command should end.
bool DriveJoysticksGyro::IsFinished() { return false; }
