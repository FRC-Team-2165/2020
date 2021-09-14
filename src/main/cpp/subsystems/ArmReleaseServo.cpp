/*----------------------------------------------------------------------------*/
/* Copyright (c) 2017-2018 FIRST. All Rights Reserved.                        */
/* Open Source Software - may be modified and shared by FRC teams. The code   */
/* must be accompanied by the FIRST BSD license file in the root directory of */
/* the project.                                                               */
/*----------------------------------------------------------------------------*/

#include "subsystems/ArmReleaseServo.h"

using namespace PWMConstants;


ArmReleaseServo::ArmReleaseServo()
  : m_armReleaseLeft{kArmReleaseLeft},
    m_armReleaseRight{kArmReleaseRight}
{

}


// Put methods for controlling this subsystem
// here. Call these from Commands.

void ArmReleaseServo::SetReleaseValueLeft(double value)//scaled 0 to 1.0 value. 0 corresponds to one extreme, 1.0 the other
{
   m_armReleaseLeft.Set(value);
   
}


void ArmReleaseServo::SetReleaseAngleLeft(double angle)//position by specified by the angle, in degrees(0 to 170)
{
   m_armReleaseLeft.SetAngle(angle);


}


double ArmReleaseServo::GetReleaseValueLeft()
{
   return m_armReleaseLeft.Get();
}


double ArmReleaseServo::GetReleaseAngleLeft()
{
  return m_armReleaseLeft.GetAngle();
}

/*
void ArmReleaseServo::SetReleaseSpeedLeft(double speed)//scaled 0 to 1.0 value. 0 corresponds to one extreme, 1.0 the other
{

   m_armReleaseLeft->SetSpeed(speed);
  
}
*/

void ArmReleaseServo::SetReleaseValueRight(double value)//scaled 0 to 1.0 value. 0 corresponds to one extreme, 1.0 the other
{
   m_armReleaseRight.Set(value);
   
}


void ArmReleaseServo::SetReleaseAngleRight(double angle)//position by specified by the angle, in degrees(0 to 170)
{
   m_armReleaseRight.SetAngle(angle);


}


double ArmReleaseServo::GetReleaseValueRight()
{
   return m_armReleaseRight.Get();
}


double ArmReleaseServo::GetReleaseAngleRight()
{
  return m_armReleaseRight.GetAngle();
}

/*
void ArmReleaseServo::SetReleaseSpeedRight(double speed)//scaled 0 to 1.0 value. 0 corresponds to one extreme, 1.0 the other
{

   m_armReleaseRight->SetSpeed(speed);
  
}
*/