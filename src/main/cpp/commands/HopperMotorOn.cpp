/*----------------------------------------------------------------------------*/
/* Copyright (c) 2019 FIRST. All Rights Reserved.                             */
/* Open Source Software - may be modified and shared by FRC teams. The code   */
/* must be accompanied by the FIRST BSD license file in the root directory of */
/* the project.                                                               */
/*                                                                            */
/* Uses decorator function to terminate command after 1 second                */                                              
/*----------------------------------------------------------------------------*/

#include "commands/HopperMotorOn.h"
#include "Robot.h"
#include "frc/smartdashboard/SmartDashboard.h"

HopperMotorOn::HopperMotorOn(double speed,int fwd_rev,int pressedOrheld,HopperMotor* hoppermotor) 
//: frc2::CommandHelper<frc2::CommandBase, HopperMotorOn>
//ArmMotorOn::HopperMotorOn(double speed,int fwd_rev,HopperMotor* hoppermotor) 
//  : frc2::CommandHelper<frc2::WaitCommand, HopperMotorOn>(1_s)
    :m_hoppermotor(hoppermotor),m_speed(speed),m_fwd_rev(fwd_rev),m_pressedOrheld(pressedOrheld)
   {
   //m_hoppermotor=armmotor;
   //m_speed=speed;
   //m_fwd_rev=fwd_rev;
 
  SetName("HopperMotorOn");
  // Use addRequirements() here to declare subsystem dependencies.
  AddRequirements({m_hoppermotor});
}

// Called when the command is initially scheduled.
void HopperMotorOn::Initialize() {
  if(m_fwd_rev == 0)// forward
  {
     if(m_speed  < 0.0)
       m_speed = -m_speed;
  }
  if(m_fwd_rev > 0)// reverse
  {
     if(m_speed  > 0.0)
       m_speed = -m_speed;
  }
  m_hoppermotor->StartMotor(m_speed);
  frc::SmartDashboard::PutString("HopperMotorOn", "true");

  m_hoppermotor->FlipperRetract();
  m_FlipperUptimer.Reset();
  m_IsFlipperUp = false;
  m_IsFlipperDown = false;
  m_FlipperDowntimer.Reset();
   m_downwait = true;
}

// Called repeatedly when this Command is scheduled to run
/*
void HopperMotorOn::Execute() {

  if( m_hoppermotor->IsFlipperDISet()  && m_IsFlipperUp == false)
  {
        m_hoppermotor->FlipperExtend();
        m_IsFlipperUp = true;
        m_FlipperUptimer.Start();
  }

 if( m_FlipperUptimer.Get() >= 1.0  && m_IsFlipperUp == true)
  {
        m_hoppermotor->FlipperRetract();
        m_IsFlipperUp = false;
        m_FlipperUptimer.Reset();
  }


}
*/



void HopperMotorOn::Execute() {

  if( m_hoppermotor->IsFlipperDISet()  && m_IsFlipperUp == false)
  {
        m_IsFlipperUp = true;
        m_FlipperUptimer.Start();
        //m_downwait = true;
  }

 if( m_FlipperUptimer.Get() >= 0.4 && m_IsFlipperUp == true)
  {
    
     m_FlipperDowntimer.Start();
     m_hoppermotor->FlipperExtend();
     m_FlipperUptimer.Stop();
     m_FlipperUptimer.Reset();
     //m_downwait = false;
   
  }
  
  if( m_FlipperDowntimer.Get() >= 0.5  && m_IsFlipperUp == true && m_IsFlipperDown == false)
  {   
        m_IsFlipperDown = true;
        m_hoppermotor->FlipperRetract();
  }

   if( m_FlipperDowntimer.Get() >= 1.0  && m_IsFlipperDown == true)
  {   
        m_IsFlipperDown = false;
        m_IsFlipperUp = false;
        m_FlipperDowntimer.Stop();
        m_FlipperDowntimer.Reset();
  }
}


// Called once the command ends or is interrupted.
void HopperMotorOn::End(bool interrupted) {
   if(m_pressedOrheld > 0)
   {
       m_hoppermotor->StopMotor();
       m_hoppermotor->FlipperRetract();
       //m_hoppermotor->FlipperOff();
   }
   else
   {
       if(m_speed == 0.0)
       {
           m_hoppermotor->FlipperRetract();
           //m_hoppermotor->FlipperOff();
       }
   }
   
 }

// Returns true when the command should end.
bool HopperMotorOn::IsFinished() { 
  if(m_pressedOrheld == 0)
      return true;
   else   
      return false; 
}
