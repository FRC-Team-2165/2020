/*----------------------------------------------------------------------------*/
/* Copyright (c) 2019 FIRST. All Rights Reserved.                             */
/* Open Source Software - may be modified and shared by FRC teams. The code   */
/* must be accompanied by the FIRST BSD license file in the root directory of */
/* the project.                                                               */
/*----------------------------------------------------------------------------*/

#include "subsystems/DriveTrain.h"
#include <frc/controller/PIDController.h>
#include <frc/smartDashboard/SmartDashboard.h>

#include "Constants.h"

using namespace DriveConstants;

DriveTrain::DriveTrain()
    //: frc2::PIDSubsystem(frc2::PIDController(kP, kI, kD)),
    : frc2::PIDSubsystem(frc2::PIDController(0.30, 0.0, .001)),
      m_driveTrainFrontLeft{kFrontLeft},
      m_driveTrainRearLeft{kRearLeft},
      m_driveTrainFrontRight{kFrontRight},
      m_driveTrainRearRight{kRearRight},
      m_navxGyro{AHRS(SPI::Port::kMXP)}
     
     {
       //GetController().SetP(0.5);
      
      m_clamp = 0.30;
      m_navxGyro.Reset(); // calibrate and zero gyro
      
      m_diffDrive.frc::DifferentialDrive::SetSafetyEnabled(false);
      m_diffDrive.frc::DifferentialDrive::SetExpiration(0.5); // sets motor timeout @ 500ms    
    
      m_driveTrainFrontLeft.Set(0.0); // set speed inially to zero
      m_driveTrainRearLeft.Set(0);
      m_driveTrainFrontRight.Set(0.0);
      m_driveTrainRearRight.Set(0.0);

      GetController().EnableContinuousInput(-180.0, 180.0);
     // m_controller.EnableContinuousInput(-180.0, 180.0);  // m_controller is used to get PIDController methods
      //GetController().SetTolerance(0.2);
      GetController().SetTolerance(1.2);
     // m_controller.SetTolerance(0.2); // m_controller is used to get PIDController methods
      
      //m_controller.SetSetpoint(0.0);

      SetSetpoint(0.0); // use setpoint method in PIDSubsystem
      Enable();  // use enable method in PIDSubsystem
      
     
      
     // m_rightEncoder.SetDistancePerPulse(6.0 /*in*/ * M_PI) /
     //                 (256.0  /*CPR */ * 12.0 /*in/ft*/));
     //  m_rightEncoder.SetDistancePerPulse(6.0 * M_PI) /
      //                (256.0 * 12.0 ));
     
    }

// This method will be called once per scheduler run
//void DriveTrain::Periodic() {}

// define virtual pid controller methods
//double DriveTrain::GetMeasurement() {return m_navxGyro.GetAngle();
double DriveTrain::GetMeasurement() {return GetGyroAngle();
frc::SmartDashboard::PutNumber("GetAngle", GetGyroAngle());
}  // pid input - gyro yaw angle

void DriveTrain::UseOutput(double output, double setpoint) {
  //m_rotate = -std::clamp(output, -0.30, 0.30);
  m_rotate = std::clamp(output, -m_clamp, m_clamp);
  frc::SmartDashboard::PutNumber("pid_gyro output", output);
  frc::SmartDashboard::PutNumber("pid_gyro setpoint", setpoint);
}


void DriveTrain::SetPidClamp(double clamp) {
   m_clamp = fabs(clamp);
}

double DriveTrain::GetPidClamp() {
   return m_clamp;
}
// PID methods
void DriveTrain::SetAngleSetPt(double angle) {
  // m_controller.SetSetpoint(angle);
   SetSetpoint(angle);

}
bool DriveTrain::AtSetpoint() {return m_controller.AtSetpoint();}



//DriveTrain Gyro methods
AHRS& DriveTrain::GetGyro()  { return m_navxGyro;}
double DriveTrain::GetGyroAngle() { return m_navxGyro.GetAngle();}
double DriveTrain::GetAngleRate() { return m_navxGyro.GetRate();}
void DriveTrain::ZeroAngle() { m_navxGyro.ZeroYaw();}
double DriveTrain::GetYawAngle() { return m_navxGyro.GetYaw();} 
double DriveTrain::GetPitchAngle() { return m_navxGyro.GetPitch();}
double DriveTrain::GetRollAngle() { return m_navxGyro.GetRoll();}

void DriveTrain::SetButton1_Off() { m_button1_status = false;}
void DriveTrain::SetButton1_On() { m_button1_status = true;}
bool DriveTrain::IsButton1_On() { return m_button1_status;}

void DriveTrain::SetButton2_Off() { m_button2_status = false;}
void DriveTrain::SetButton2_On() { m_button2_status = true;}
bool DriveTrain::IsButton2_On() { return m_button2_status;}

// DriveTrain Encoder methods
//Encoder& DriveTrain::GetRightEncoder() {return m_rightEncoder;}


// DriveTrain methods
void DriveTrain::NoGyroArcadeDrive(double move, double rotate) {
  m_diffDrive.frc::DifferentialDrive::ArcadeDrive(move, rotate, true);
}
void DriveTrain::GyroArcadeDrive(double move) {
  m_diffDrive.frc::DifferentialDrive::ArcadeDrive(move, m_rotate);
  frc::SmartDashboard::PutNumber("gyro input to arcade", m_rotate);
}
void DriveTrain::ApplyWheelBrakes() {
	m_driveTrainFrontLeft.SetNeutralMode(NeutralMode::Brake);
	m_driveTrainRearLeft.SetNeutralMode(NeutralMode::Brake);
	m_driveTrainFrontRight.SetNeutralMode(NeutralMode::Brake);
	m_driveTrainRearRight.SetNeutralMode(NeutralMode::Brake);  
}
void DriveTrain::ReleaseWheelBrakes() {
  m_driveTrainFrontLeft.SetNeutralMode(NeutralMode::Coast);
	m_driveTrainRearLeft.SetNeutralMode(NeutralMode::Coast);
	m_driveTrainFrontRight.SetNeutralMode(NeutralMode::Coast);
	m_driveTrainRearRight.SetNeutralMode(NeutralMode::Coast);  
}
void DriveTrain::Log() {}
