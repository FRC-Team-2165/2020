/*----------------------------------------------------------------------------*/
/* Copyright (c) 2019 FIRST. All Rights Reserved.                             */
/* Open Source Software - may be modified and shared by FRC teams. The code   */
/* must be accompanied by the FIRST BSD license file in the root directory of */
/* the project.                                                               */
/*----------------------------------------------------------------------------*/

#include "commands/InitialRobot.h"


InitialRobot::InitialRobot(ArmMotor* armmotor, HopperMotor* hoppermotor,RetrieverMotor* retrievermotor, WinchMotor* winchmotor,HopperPneumatic *hopperpneumatic,RetrieverPneumatic* retrieverpneumatic){

  AddCommands(
      RetractRetriever(retrieverpneumatic),
      RetractHopper(hopperpneumatic),
      ArmMotorOn(0.0,0,0,armmotor) ,
      WinchMotorOn(0.0,0,0,winchmotor) ,
      RetrieverMotorOn(0.0,0,0,retrievermotor) ,
      HopperMotorOn(0.0,0,0,hoppermotor) );
    
}

/*
frc2::SequentialCommandGroup{
      ExtendRetriever(retrieverpneumatic),
      WaitSeconds(1.0),
      RetrieverMotorOn(0.5,0,retrievermotor) ,
      HopperMotorOn(0.5,0,hoppermotor) ,
      MoveDistance(180.0,0.5,15,drive,rightwheelencoder),
      WaitSeconds(2.0), 
      RetrieverMotorOn(0.0,0,retrievermotor) ,
      HopperMotorOn(0.0,0,hoppermotor) };
}
*/
/*
frc2::SequentialCommandGroup{
   DriveToGoal(&m_drive),
   frc2::ParallelCommandGroup{
      RaiseElevator(&m_elevator),
      SetWristPosition(&m_wrist)},
   ScoreTube(&m_wrist)};
   */