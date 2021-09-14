/*----------------------------------------------------------------------------*/
/* Copyright (c) 2019 FIRST. All Rights Reserved.                             */
/* Open Source Software - may be modified and shared by FRC teams. The code   */
/* must be accompanied by the FIRST BSD license file in the root directory of */
/* the project.                                                               */
/*----------------------------------------------------------------------------*/

#include "commands/AutonomousGetBalls.h"


AutonomousGetBalls::AutonomousGetBalls(DriveTrain* drive, RetrieverMotor* retrievermotor, HopperMotor* hoppermotor,RetrieverPneumatic* retrieverpneumatic,RightWheelEncoder* rightwheelencoder){
//AutonomousGetBalls::AutonomousGetBalls(DriveTrain* drive, HatchSubsystem* hatch) {
  AddCommands(
      
      ExtendRetriever(retrieverpneumatic),
      //WaitSeconds(1.0),
      RetrieverMotorOn(1.0,1,0,retrievermotor) ,
      HopperMotorOn(1.0,0,0,hoppermotor) ,
      //WaitSeconds(2.0), 
      //MoveDistance(-140.0,0.5,20,drive,rightwheelencoder),
      //MoveDistance(-30.0,0.4,20,drive,rightwheelencoder),

      MoveWithFlipper(-140.0,0.5,20,drive,rightwheelencoder,hoppermotor),
      MoveWithFlipper(-30.0,0.4,20,drive,rightwheelencoder,hoppermotor),

      RetractRetriever(retrieverpneumatic),
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