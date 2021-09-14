/*----------------------------------------------------------------------------*/
/* Copyright (c) 2017-2018 FIRST. All Rights Reserved.                        */
/* Open Source Software - may be modified and shared by FRC teams. The code   */
/* must be accompanied by the FIRST BSD license file in the root directory of */
/* the project.                                                               */
/*----------------------------------------------------------------------------*/

#include "subsystems/RetrieverMotor.h"

using namespace DriveConstants;


RetrieverMotor::RetrieverMotor()
  : m_retrieverMotor{kRetrieverMotor}
{
 
   m_retrieverMotor.SetStatusFramePeriod(StatusFrame::Status_1_General_,5,10);//talon sends new frame every 5ms


   m_retrieverMotor.Set(ControlMode::PercentOutput, 0);
   m_retrieverMotor.ConfigPeakOutputForward(1.0,k_TimeoutMs);
   m_retrieverMotor.ConfigPeakOutputReverse(-1.0,k_TimeoutMs);
   m_retrieverMotor.SetSensorPhase(false);


//Closed inhibits motor from running

   m_retrieverMotor.ConfigForwardLimitSwitchSource(LimitSwitchSource::LimitSwitchSource_FeedbackConnector,
      LimitSwitchNormal::LimitSwitchNormal_NormallyOpen,k_TimeoutMs );


   m_retrieverMotor.ConfigReverseLimitSwitchSource(LimitSwitchSource::LimitSwitchSource_FeedbackConnector,
      LimitSwitchNormal::LimitSwitchNormal_NormallyOpen,k_TimeoutMs );


//Open inhibits motor from running

/*
   m_retrieverMotor.ConfigForwardLimitSwitchSource(LimitSwitchSource::LimitSwitchSource_FeedbackConnector,
      LimitSwitchNormal::LimitSwitchNormal_NormallyClosed,k_TimeoutMs );



   m_retrieverMotor.ConfigReverseLimitSwitchSource(LimitSwitchSource::LimitSwitchSource_FeedbackConnector,
      LimitSwitchNormal::LimitSwitchNormal_NormallyClosed,k_TimeoutMs );
*/

}



// Put methods for controlling this subsystem
// here. Call these from Commands.



void RetrieverMotor::ZeroAtRevLimitSwt()
{
   m_retrieverMotor.ConfigSetParameter(ParamEnum::eClearPositionOnLimitR,1,0,0,10);
}


void RetrieverMotor::ZeroAtFwdLimitSwt()
{
   m_retrieverMotor.ConfigSetParameter(ParamEnum::eClearPositionOnLimitF,1,0,0,10);
}




bool RetrieverMotor::IsUpperLimitClosed()
{
    return (m_retrieverMotor.GetSensorCollection().IsFwdLimitSwitchClosed());
}


bool RetrieverMotor::IsLowerLimitClosed()
{
    return (m_retrieverMotor.GetSensorCollection().IsRevLimitSwitchClosed());
}


void RetrieverMotor::StopMotor()
{
  m_retrieverMotor.Set(ControlMode::PercentOutput,0.0);
  
}


void RetrieverMotor::StartMotor(double speed)
{
  m_retrieverMotor.Set(ControlMode::PercentOutput,speed);
}


bool RetrieverMotor::IsPercentOutput()
{
  return(m_retrieverMotor.GetControlMode() == ControlMode::PercentOutput);
}

