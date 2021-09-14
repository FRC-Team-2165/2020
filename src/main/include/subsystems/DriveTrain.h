/*----------------------------------------------------------------------------*/
/* Copyright (c) 2019 FIRST. All Rights Reserved.                             */
/* Open Source Software - may be modified and shared by FRC teams. The code   */
/* must be accompanied by the FIRST BSD license file in the root directory of */
/* the project.                                                               */
/*----------------------------------------------------------------------------*/

#pragma once

//#include <frc2/PIDSubsystem.h>
//#include <frc2/command/SubsystemBase.h>
#include <frc/controller/SimpleMotorFeedforward.h>  //added by del
#include <frc2/command/PIDSubsystem.h>  // added by del
#include <ctre/Phoenix.h>
#include <frc/SpeedControllerGroup.h>
#include <frc/drive/DifferentialDrive.h>

#include <AHRS.h>
#include <frc/Encoder.h>
#include <units/units.h> // added by del

#include "Constants.h"  //contains namespaces



//class DriveTrain : public frc2::SubsystemBase {
class DriveTrain : public frc2::PIDSubsystem {  // added by del
 public:
  DriveTrain();

  /**
   * Will be called periodically whenever the CommandScheduler runs.
   */
// void Periodic() override;// changed by del

// PID methods 
  void UseOutput(double output, double setpoint) override;
  double GetMeasurement() override;
  bool AtSetpoint();
  void SetAngleSetPt(double);
  
   void SetPidClamp(double);

   double GetPidClamp();

// DriveTrain methods 
  void GyroArcadeDrive( double move);
  void NoGyroArcadeDrive(double move, double rotate);

  void ApplyWheelBrakes();  // set robot coasting
	void ReleaseWheelBrakes();  // brake when inputs to controllers are zero

// Gyro methods  
  AHRS& GetGyro();
  double GetGyroAngle(); // rotation around z-axis
	double GetAngleRate(); // degrees/second
	void ZeroAngle();  // use to set angle to zero
  double GetPitchAngle();  // rotation about y-axis
	double GetRollAngle(); // rotation about x-axis
	double GetYawAngle();  // rotation about z-axis

  void SetButton1_Off();  //  disable gyro during driving
  void SetButton1_On();   //  enablel gyro during driving
  bool IsButton1_On();    //  status of gyro for driving

  void SetButton2_Off();  //  disable gyro during driving
  void SetButton2_On();   //  enablel gyro during driving
  bool IsButton2_On();    //  status of gyro for driving 



// Encoder methods
  //frc::Encoder& GetRightEncoder();

  
  void Log();

 private:
  // Components (e.g. motor controllers and sensors) should generally be
  // declared private and exposed only through public methods.
  WPI_TalonSRX  m_driveTrainFrontLeft;
  WPI_TalonSRX  m_driveTrainRearLeft;
  frc::SpeedControllerGroup m_leftGroup{m_driveTrainFrontLeft, m_driveTrainRearLeft};
  WPI_TalonSRX  m_driveTrainFrontRight;
  WPI_TalonSRX  m_driveTrainRearRight;
  frc::SpeedControllerGroup m_rightGroup{m_driveTrainFrontRight, m_driveTrainRearRight};
  frc::DifferentialDrive m_diffDrive{m_leftGroup, m_rightGroup};

  AHRS m_navxGyro;
  

  double m_rotate = 0.0;
  bool m_button1_status = false;
  bool m_button2_status = false;
  double m_clamp;

};
