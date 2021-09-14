/*----------------------------------------------------------------------------*/
/* Copyright (c) 2019 FIRST. All Rights Reserved.                             */
/* Open Source Software - may be modified and shared by FRC teams. The code   */
/* must be accompanied by the FIRST BSD license file in the root directory of */
/* the project.                                                               */
/*----------------------------------------------------------------------------*/

#pragma once

#include <frc2/command/SubsystemBase.h>
#include <frc/DoubleSolenoid.h>
#include "Constants.h"

using namespace PneumaticsConstants;

class RetrieverPneumatic : public frc2::SubsystemBase {
 public:
  RetrieverPneumatic();

  /**
   * Will be called periodically whenever the CommandScheduler runs.
   */
  void Periodic();

  void RetrieverExtend();
  void RetrieverRetract();
  void RetrieverOff();
  void Log();

 private:
  // Components (e.g. motor controllers and sensors) should generally be
  // declared private and exposed only through public methods.
  frc::DoubleSolenoid m_pneumaticRetriever{kTransFwdChan_6, kTransRevChan_7};
};
