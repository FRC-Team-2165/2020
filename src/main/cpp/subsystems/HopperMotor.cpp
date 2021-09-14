/*----------------------------------------------------------------------------*/
/* Copyright (c) 2017-2018 FIRST. All Rights Reserved.                        */
/* Open Source Software - may be modified and shared by FRC teams. The code   */
/* must be accompanied by the FIRST BSD license file in the root directory of */
/* the project.                                                               */
/*----------------------------------------------------------------------------*/

#include "subsystems/HopperMotor.h"

using namespace DriveConstants;


HopperMotor::HopperMotor()
  : m_hopperMotor{kHopperMotor}
{
 
   m_hopperMotor.SetStatusFramePeriod(StatusFrame::Status_1_General_,5,10);//talon sends new frame every 5ms


   m_hopperMotor.Set(ControlMode::PercentOutput, 0);
   m_hopperMotor.ConfigPeakOutputForward(1.0,k_TimeoutMs);
   m_hopperMotor.ConfigPeakOutputReverse(-1.0,k_TimeoutMs);
   m_hopperMotor.SetSensorPhase(false);


//Closed inhibits motor from running

   m_hopperMotor.ConfigForwardLimitSwitchSource(LimitSwitchSource::LimitSwitchSource_FeedbackConnector,
      LimitSwitchNormal::LimitSwitchNormal_NormallyOpen,k_TimeoutMs );


   m_hopperMotor.ConfigReverseLimitSwitchSource(LimitSwitchSource::LimitSwitchSource_FeedbackConnector,
      LimitSwitchNormal::LimitSwitchNormal_NormallyOpen,k_TimeoutMs );


//Open inhibits motor from running

/*
   m_hopperMotor.ConfigForwardLimitSwitchSource(LimitSwitchSource::LimitSwitchSource_FeedbackConnector,
      LimitSwitchNormal::LimitSwitchNormal_NormallyClosed,k_TimeoutMs );



   m_hopperMotor.ConfigReverseLimitSwitchSource(LimitSwitchSource::LimitSwitchSource_FeedbackConnector,
      LimitSwitchNormal::LimitSwitchNormal_NormallyClosed,k_TimeoutMs );
*/

}



// Put methods for controlling this subsystem
// here. Call these from Commands.



void HopperMotor::ZeroAtRevLimitSwt()
{
   m_hopperMotor.ConfigSetParameter(ParamEnum::eClearPositionOnLimitR,1,0,0,10);
}


void HopperMotor::ZeroAtFwdLimitSwt()
{
   m_hopperMotor.ConfigSetParameter(ParamEnum::eClearPositionOnLimitF,1,0,0,10);
}




bool HopperMotor::IsUpperLimitClosed()
{
    return (m_hopperMotor.GetSensorCollection().IsFwdLimitSwitchClosed());
}


bool HopperMotor::IsLowerLimitClosed()
{
    return (m_hopperMotor.GetSensorCollection().IsRevLimitSwitchClosed());
}


void HopperMotor::StopMotor()
{
  m_hopperMotor.Set(ControlMode::PercentOutput,0.0);
  
}


void HopperMotor::StartMotor(double speed)
{
  m_hopperMotor.Set(ControlMode::PercentOutput,speed);
}


bool HopperMotor::IsPercentOutput()
{
  return(m_hopperMotor.GetControlMode() == ControlMode::PercentOutput);
}


void HopperMotor::FlipperExtend() {
    m_Flipperpneumatic.Set(frc::DoubleSolenoid::kForward); // extend retriever
}

void HopperMotor::FlipperRetract() {
    m_Flipperpneumatic.Set(frc::DoubleSolenoid::kReverse); // retract retriever
}

void HopperMotor::FlipperOff() {
    m_Flipperpneumatic.Set(frc::DoubleSolenoid::kOff);
}


bool HopperMotor::IsFlipperDISet() 
{
 return m_FlipperDI.Get();
}
