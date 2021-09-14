/*----------------------------------------------------------------------------*/
/* Copyright (c) 2017-2018 FIRST. All Rights Reserved.                        */
/* Open Source Software - may be modified and shared by FRC teams. The code   */
/* must be accompanied by the FIRST BSD license file in the root directory of */
/* the project.                                                               */
/*----------------------------------------------------------------------------*/

#include "subsystems/WinchMotor.h"

using namespace DriveConstants;


WinchMotor::WinchMotor()
  : m_winchMotor{kWinchMotor}
{
 
   m_winchMotor.SetStatusFramePeriod(StatusFrame::Status_1_General_,5,10);//talon sends new frame every 5ms


   m_winchMotor.Set(ControlMode::PercentOutput, 0);
   m_winchMotor.ConfigPeakOutputForward(1.0,k_TimeoutMs);
   m_winchMotor.ConfigPeakOutputReverse(-1.0,k_TimeoutMs);
   m_winchMotor.SetSensorPhase(false);

/*
m_winchMotor.ConfigPeakCurrentLimit(35, 10); // 35 A 
m_winchMotor.ConfigPeakCurrentDuration(200, 10); // 200ms 
m_winchMotor.ConfigContinuousCurrentLimit(30, 10); // 30A 
m_winchMotor.EnableCurrentLimit(true); // turn it on 
*/

//Closed inhibits motor from running

   m_winchMotor.ConfigForwardLimitSwitchSource(LimitSwitchSource::LimitSwitchSource_FeedbackConnector,
      LimitSwitchNormal::LimitSwitchNormal_NormallyOpen,k_TimeoutMs );


   m_winchMotor.ConfigReverseLimitSwitchSource(LimitSwitchSource::LimitSwitchSource_FeedbackConnector,
      LimitSwitchNormal::LimitSwitchNormal_NormallyOpen,k_TimeoutMs );


//Open inhibits motor from running

/*
   m_winchMotor.ConfigForwardLimitSwitchSource(LimitSwitchSource::LimitSwitchSource_FeedbackConnector,
      LimitSwitchNormal::LimitSwitchNormal_NormallyClosed,k_TimeoutMs );



   m_winchMotor.ConfigReverseLimitSwitchSource(LimitSwitchSource::LimitSwitchSource_FeedbackConnector,
      LimitSwitchNormal::LimitSwitchNormal_NormallyClosed,k_TimeoutMs );
*/

}



// Put methods for controlling this subsystem
// here. Call these from Commands.



void WinchMotor::ZeroAtRevLimitSwt()
{
   m_winchMotor.ConfigSetParameter(ParamEnum::eClearPositionOnLimitR,1,0,0,10);
}


void WinchMotor::ZeroAtFwdLimitSwt()
{
   m_winchMotor.ConfigSetParameter(ParamEnum::eClearPositionOnLimitF,1,0,0,10);
}




bool WinchMotor::IsUpperLimitClosed()
{
    return (m_winchMotor.GetSensorCollection().IsFwdLimitSwitchClosed());
}


bool WinchMotor::IsLowerLimitClosed()
{
    return (m_winchMotor.GetSensorCollection().IsRevLimitSwitchClosed());
}


void WinchMotor::StopMotor()
{
  m_winchMotor.Set(ControlMode::PercentOutput,0.0);
  
}


void WinchMotor::StartMotor(double speed)
{
  m_winchMotor.Set(ControlMode::PercentOutput,speed);
}


bool WinchMotor::IsPercentOutput()
{
  return(m_winchMotor.GetControlMode() == ControlMode::PercentOutput);
}
double WinchMotor::GetOutPutCurrent()
{
  //return(m_winchMotor.GetContinuousCurrent();
  return(m_winchMotor.GetOutputCurrent());
 
}


double WinchMotor::IR_Analog() 
{
   return m_InfraredSwt.GetValue();
}

bool WinchMotor::IR_AtSetpt(double value ,double min, double max) 
{
  if((value >= min)&&(value <= max))
  {
    return(true);
  }
  else
  {
     return(false);
  }
}   
   
/*
std::shared_ptr<frc::AnalogInput> RobotMap::f_InfraredSwt;
bool  atdistance;

  double m_analog_max;
  double m_analog_min;
  
  
double InfraredSwitches::IR_Analog() 
{
   return m_irAnalog->GetValue();
}

f_InfraredSwt.reset(new AnalogInput(IR_SWITCH));
static constexpr int IR_SWITCH            = 0;

double m_analValue = Robot::infraredSwitches->IR_Analog()/1000.0;
 
 joystick0_Button2->WhileHeld(new InfraredPhotocell(1.0,2.0,20.0));
 InfraredPhotocell::InfraredPhotocell(double analog_min, double analog_max, double seconds) {
*/