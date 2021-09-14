/*----------------------------------------------------------------------------*/
/* Copyright (c) 2017-2018 FIRST. All Rights Reserved.                        */
/* Open Source Software - may be modified and shared by FRC teams. The code   */
/* must be accompanied by the FIRST BSD license file in the root directory of */
/* the project.                                                               */
/*----------------------------------------------------------------------------*/

#pragma once
#include <frc2/command/SubsystemBase.h>
#include <ctre/Phoenix.h>
#include "Constants.h"  //contains namespaces
#include <math.h>
#include <frc/DoubleSolenoid.h>
#include <frc/DigitalInput.h>

#include "Constants.h"


class HopperMotor : public frc2::SubsystemBase {
 private:
  // It's desirable that everything possible under private except
  // for methods that implement subsystem capabilities
  WPI_TalonSRX  m_hopperMotor;


    //frc::DigitalInput m_FlipperDI(DIDOConstants::kFlipperDI);
    //frc::DoubleSolenoid m_Flipperpneumatic{PneumaticsConstants::kFlipperFwdChan_4, PneumaticsConstants::kFlipperRevChan_5};
    //frc::DigitalInput m_FlipperDI{7};
    //frc::DoubleSolenoid m_Flipperpneumatic{6,7};
    frc::DigitalInput m_FlipperDI{DIDOConstants::kFlipperDI};
    frc::DoubleSolenoid m_Flipperpneumatic{PneumaticsConstants::kFlipperFwdChan_4, PneumaticsConstants::kFlipperRevChan_5};
const int k_SlotIdx = 0;
const int k_TimeoutMs = 10; // blocks config until success, zero to skip checking

 public:
  HopperMotor();
  void ZeroAtRevLimitSwt();
  void ZeroAtFwdLimitSwt();
  bool IsUpperLimitClosed();
  bool IsLowerLimitClosed();
  void StopMotor();
  void StartMotor(double);
  bool IsPercentOutput();

  bool IsFlipperDISet();
  void FlipperExtend();
  void FlipperRetract();
  void FlipperOff();
 
 
 };
