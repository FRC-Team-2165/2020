/*----------------------------------------------------------------------------*/
/* Copyright (c) 2017-2018 FIRST. All Rights Reserved.                        */
/* Open Source Software - may be modified and shared by FRC teams. The code   */
/* must be accompanied by the FIRST BSD license file in the root directory of */
/* the project.                                                               */
/*----------------------------------------------------------------------------*/

#include "subsystems/RightWheelEncoder.h"
//#include "RobotMap.h"
#include "frc/smartDashboard/SmartDashboard.h"
#include <math.h>

using namespace DIDOConstants;

// initialize PID parameters
  double RightWheelEncoder::Kp2{0.6};
  double RightWheelEncoder::Ki2{0.0};
  double RightWheelEncoder::Kd2{0.001};

RightWheelEncoder::RightWheelEncoder() 
 : m_rightEncoder{kWheelEncoder0,kWheelEncoder1,true,frc::Encoder::EncodingType::k4X},
  m_rightEncoderPID{Kp2, Ki2, Kd2}
 // m_rightEncoderPID{Kp2, Ki2, Kd2, this, this, 0.05}
 {
// encoder inialization
  

  // to calculate Distance/Pulse (for wheel) = (pi*wheel dia)/(encoder rev/shaft rev)/
  // (encoder pulses/encoder rev)
  // transmission encoder - 250 pulse/rev, encoder rev/axial rev =6, wheel dia 6"
    //m_rightEncoder.SetDistancePerPulse(0.01252); // only use pulses/rev,
  //                                             exclude sample mode 4X in calculation
  m_rightEncoder.SetDistancePerPulse(0.07756);
    m_rightEncoder.SetSamplesToAverage(5);
    m_rightEncoder.Reset();
    
// PID initialization

    //m_rightEncoderPID.SetContinuous(false);
    //SetPID_InputRange(400.0);  //set greater than expected range
    //SetPID_OutputRange(0.50);  // limits PID output to motor controller
    //m_rightEncoderPID.Disable();  //initially disabled - must enable to work
    //m_rightEncoderPID.SetPIDSourceType(frc::PIDSourceType::kDisplacement);
    m_outRange = 0.5;
    m_rightEncoderPID.EnableContinuousInput(-400.0,400.0);
    m_rightEncoderPID.SetTolerance(1.0);
    m_rightEncoderPID.SetSetpoint(0.0);
    m_pidout = 0.0;
}


// Put methods for controlling this subsystem
// here. Call these from Commands.

// Encoder methods

void RightWheelEncoder::ResetWheelEncoder() {
    m_rightEncoder.Reset();
}
 
 double RightWheelEncoder::GetEncoderDistance() {
    double distance = m_rightEncoder.GetDistance();
    frc::SmartDashboard::PutNumber("Right Encoder Dist", distance); //should be positive
    //                                                          when moving forward
    return distance;
 }

 double RightWheelEncoder::GetSpeed() {
   double speed = m_rightEncoder.GetRate();
   frc::SmartDashboard::PutNumber(" Right Wheel Speed", speed);
   return speed; //units - inches/sec
 }

 // PID methods

 void RightWheelEncoder::EnablePID() {
   m_rightEncoderPID.EnableContinuousInput(-400.0,400.0);
   //m_rightEncoderPID.Enable();
 }

 void RightWheelEncoder::DisablePID() {
   m_rightEncoderPID.DisableContinuousInput();
  // m_rightEncoderPID.Disable();
 }

 void RightWheelEncoder::SetDistanceSetPt(double distance) {
   m_rightEncoderPID.SetSetpoint(distance); // units - inches
 }

 bool RightWheelEncoder::AtSetPt() {
   return (m_rightEncoderPID.AtSetpoint());
   //return fabs(fabs(GetEncoderDistance()) - fabs(m_rightEncoderPID.GetSetpoint())) < 1.0;
 }

void RightWheelEncoder::PIDWrite(double output)  { // get PID controller output
  m_pidout = output;
  frc::SmartDashboard::PutNumber("Right PID Output", m_pidout); // should be 
  //                                                postive moving forward
}

double RightWheelEncoder::PIDGet() {
  double m_distance = GetEncoderDistance(); 
    frc::SmartDashboard::PutNumber("Right PID Input", m_distance);
    return m_distance; 
}


double RightWheelEncoder::PidOut() { // public access to controller output
  //double m_distance = GetEncoderDistance();
  double setpt = m_rightEncoderPID.GetSetpoint();

  m_pidout = std::clamp(m_rightEncoderPID.Calculate(GetEncoderDistance(), setpt), -m_outRange, m_outRange);
  //m_pidout = m_rightEncoderPID.Calculate(m_distance,setpt);
  return m_pidout; // value from PIDWrite above
}

void RightWheelEncoder::SetPID_OutputRange(double range) {
   m_outRange = fabs(range);
  //m_rightEncoderPID.SetOutputRange(-m_outRange, m_outRange);
}
/*
void RightWheelEncoder::SetPID_InputRange(double range) {
  double m_inRange = fabs(range);
  m_rightEncoderPID.SetInputRange(-m_inRange, m_inRange);
  
}
*/
void RightWheelEncoder::ChangePID_Parm(double p, double i, double d) {
  Kp2 = p, Ki2 = i, Kd2 = d;
}
