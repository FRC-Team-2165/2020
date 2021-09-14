/*----------------------------------------------------------------------------*/
/* Version: ArcadeDrive_3   1/21/2020                                         */
/* Test version of ArcadeDr_NewCommandFrame expanded to include added features*/
/* to the version in 2020 FRC Projects/2020_ArcadeDrive\ArcadeDrive_1         */
/*  - add gyro to DriveTrain and DriveJoysticksGyro                           */
/* Copyright (c) 2017-2019 FIRST. All Rights Reserved.                        */
/* Open Source Software - may be modified and shared by FRC teams. The code   */
/* must be accompanied by the FIRST BSD license file in the root directory of */
/* the project.                                                               */
/*----------------------------------------------------------------------------*/

#include "Robot.h"

#include <frc/smartdashboard/SmartDashboard.h>
#include <frc2/command/CommandScheduler.h>
#include <frc/DriverStation.h>
#include "networktables/NetworkTableEntry.h"
#include "networktables/NetworkTable.h"
#include "networktables/NetworkTableInstance.h"


std::unique_ptr<RobotContainer> Robot::robotContainer = nullptr;

void Robot::RobotInit() {
  robotContainer.reset(new RobotContainer());
  
//cameraSelection = nt::NetworkTableInstance::GetDefault().GetTable("")->GetEntry("CameraSelection");

auto inst = nt::NetworkTableInstance::GetDefault();
auto table = inst.GetTable("");
cameraSelection = table->GetEntry("CameraSelection");



}

/**
 * This function is called every robot packet, no matter the mode. Use
 * this for items like diagnostics that you want to run during disabled,
 * autonomous, teleoperated and test.
 *
 * <p> This runs after the mode specific periodic functions, but before
 * LiveWindow and SmartDashboard integrated updating.
 */
void Robot::RobotPeriodic() { frc2::CommandScheduler::GetInstance().Run(); }

/**
 * This function is called once each time the robot enters Disabled mode. You
 * can use it to reset any subsystem information you want to clear when the
 * robot is disabled.
 */
void Robot::DisabledInit() {}

void Robot::DisabledPeriodic() {}

/**
 * This autonomous runs the autonomous command selected by your {@link
 * RobotContainer} class.
 */
void Robot::AutonomousInit() {
 // m_autonomousCommand = m_container.GetAutonomousCommand();
  m_autonomousCommand = robotContainer->GetAutonomousCommand();

  if (m_autonomousCommand != nullptr) {
    m_autonomousCommand->Schedule();
  }
  
      //m_initialrobotCommand = robotContainer->GetInitialRobotCommand();
      //m_initialrobotCommand->Schedule();
   /*   
    	InitializeRobot.reset(new InitialRobot()); 
      //InitializeRobot->Start();
      InitializeRobot->Schedule();
*/
}

void Robot::AutonomousPeriodic() {}

void Robot::TeleopInit() {
  // This makes sure that the autonomous stops running when
  // teleop starts running. If you want the autonomous to
  // continue until interrupted by another command, remove
  // this line or comment it out.
  if (m_autonomousCommand != nullptr) {
    m_autonomousCommand->Cancel();
    m_autonomousCommand = nullptr;
  }
}

/**
 * This function is called periodically during operator control.
 */
void Robot::TeleopPeriodic() {
/*
  if (joy1.getTriggerPressed()) {
        System.out.println("Setting camera 2");
        cameraSelection.setString(camera2.getName());
    } else if (joy1.getTriggerReleased()) {
        System.out.println("Setting camera 1");
        cameraSelection.setString(camera1.getName());
    }
    */
  // cameraSelection.SetString("Camera1");
  
  //#include <frc/DriverStation.h>
   static bool data_recvd = false;
   std::string gameData;
   if(data_recvd == false)
   {
      gameData = frc::DriverStation::GetInstance().GetGameSpecificMessage();
      if(gameData.length() > 0)
      {
        switch (gameData[0])
        {
           case 'B' :
            //Blue case code
            data_recvd = true;
            break;
          case 'G' :
            //Green case code
            data_recvd = true;
            break;
          case 'R' :
            //Red case code
            data_recvd = true;
            break;
          case 'Y' :
            //Yellow case code
            data_recvd = true;
            break;
          default :
            //This is corrupt data
            break;
        }
      }
      else
      {
        //Code for no data received yet
      }
   }

}

/**
 * This function is called periodically during test mode.
 */
void Robot::TestPeriodic() {}

#ifndef RUNNING_FRC_TESTS
int main() { return frc::StartRobot<Robot>(); }
#endif
