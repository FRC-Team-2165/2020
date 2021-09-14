/*----------------------------------------------------------------------------*/
/* Copyright (c) 2017-2018 FIRST. All Rights Reserved.                        */
/* Open Source Software - may be modified and shared by FRC teams. The code   */
/* must be accompanied by the FIRST BSD license file in the root directory of */
/* the project.                                                               */
/*----------------------------------------------------------------------------*/

#include "subsystems/ArmMotor.h"

using namespace DriveConstants;


ArmMotor::ArmMotor()
  : m_armMotor{kArmMotor}
{
 
   m_armMotor.SetStatusFramePeriod(StatusFrame::Status_1_General_,5,10);//talon sends new frame every 5ms


   m_armMotor.Set(ControlMode::PercentOutput, 0);
   m_armMotor.ConfigPeakOutputForward(1.0,k_TimeoutMs);
   m_armMotor.ConfigPeakOutputReverse(-1.0,k_TimeoutMs);
   m_armMotor.SetSensorPhase(false);


//Closed inhibits motor from running

   m_armMotor.ConfigForwardLimitSwitchSource(LimitSwitchSource::LimitSwitchSource_FeedbackConnector,
      LimitSwitchNormal::LimitSwitchNormal_NormallyOpen,k_TimeoutMs );


   m_armMotor.ConfigReverseLimitSwitchSource(LimitSwitchSource::LimitSwitchSource_FeedbackConnector,
      LimitSwitchNormal::LimitSwitchNormal_NormallyOpen,k_TimeoutMs );


//Open inhibits motor from running

/*
   m_armMotor.ConfigForwardLimitSwitchSource(LimitSwitchSource::LimitSwitchSource_FeedbackConnector,
      LimitSwitchNormal::LimitSwitchNormal_NormallyClosed,k_TimeoutMs );



   m_armMotor.ConfigReverseLimitSwitchSource(LimitSwitchSource::LimitSwitchSource_FeedbackConnector,
      LimitSwitchNormal::LimitSwitchNormal_NormallyClosed,k_TimeoutMs );
*/

}



// Put methods for controlling this subsystem
// here. Call these from Commands.



void ArmMotor::ZeroAtRevLimitSwt()
{
   m_armMotor.ConfigSetParameter(ParamEnum::eClearPositionOnLimitR,1,0,0,10);
}


void ArmMotor::ZeroAtFwdLimitSwt()
{
   m_armMotor.ConfigSetParameter(ParamEnum::eClearPositionOnLimitF,1,0,0,10);
}




bool ArmMotor::IsUpperLimitClosed()
{
    return (m_armMotor.GetSensorCollection().IsFwdLimitSwitchClosed());
}


bool ArmMotor::IsLowerLimitClosed()
{
    return (m_armMotor.GetSensorCollection().IsRevLimitSwitchClosed());
}


void ArmMotor::StopMotor()
{
  m_armMotor.Set(ControlMode::PercentOutput,0.0);
  
}


void ArmMotor::StartMotor(double speed)
{
  m_armMotor.Set(ControlMode::PercentOutput,speed);
}


bool ArmMotor::IsPercentOutput()
{
  return(m_armMotor.GetControlMode() == ControlMode::PercentOutput);
}

void ArmMotor::Log() {}