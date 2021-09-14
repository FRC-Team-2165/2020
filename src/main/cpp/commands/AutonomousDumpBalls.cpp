/*----------------------------------------------------------------------------*/
/* Copyright (c) 2019 FIRST. All Rights Reserved.                             */
/* Open Source Software - may be modified and shared by FRC teams. The code   */
/* must be accompanied by the FIRST BSD license file in the root directory of */
/* the project.                                                               */
/*----------------------------------------------------------------------------*/

#include "commands/AutonomousDumpBalls.h"


AutonomousDumpBalls::AutonomousDumpBalls(DriveTrain* drive, HopperPneumatic* hopperpneumatic,RightWheelEncoder* rightwheelencoder){
  AddCommands(
      //MoveDistance(-84.0,0.5,12,drive,rightwheelencoder),
      MoveDistance(80.0,0.6,12,drive,rightwheelencoder),
      MoveTimed(0.40,2.0,1,drive),
      //WaitSeconds(1.0),
      ExtendHopper(hopperpneumatic) ,
      WaitSeconds(1.0),
      RetractHopper(hopperpneumatic),
      MoveDistance(-130.0,0.6,15,drive,rightwheelencoder));
}
/*
frc2::SequentialCommandGroup{
   DriveToGoal(&m_drive),
   frc2::ParallelCommandGroup{
      RaiseElevator(&m_elevator),
      SetWristPosition(&m_wrist)},
   ScoreTube(&m_wrist)};
   */