/*----------------------------------------------------------------------------*/
/* Copyright (c) 2017-2018 FIRST. All Rights Reserved.                        */
/* Open Source Software - may be modified and shared by FRC teams. The code   */
/* must be accompanied by the FIRST BSD license file in the root directory of */
/* the project.                                                               */
/*----------------------------------------------------------------------------*/

#pragma once
//#include <frc/WPILib.h>
#include <frc2/command/SubsystemBase.h>
#include "Constants.h"  //contains namespaces
#include <math.h>
#include <frc/Counter.h>
#include <frc/DigitalInput.h>
#include <frc/DigitalOutput.h>
#include "constants.h"


using namespace DIDOConstants;
  

class UltraSonic : public frc2::SubsystemBase {
 private:
  // It's desirable that everything possible under private except
  // for methods that implement subsystem capabilities

  static constexpr double kSpeedOfSoundInchesPerSec  = 13660.0;

	frc::Counter m_sonicCounterFront;
	frc::Counter m_sonicCounterRear;
	frc::DigitalOutput m_digitalOutFront;
	frc::DigitalOutput m_digitalOutRear;



#define ULTRA_FRONT 1
#define ULTRA_REAR 2
#define FRONTSONCNTRL 3
#define REARSONCNTRL 4

  //frc::Counter m_sonicCounterFront(1);
  //frc::Counter m_sonicCounterRear(2);
  //frc::DigitalOutput m_digitalOutFront(3);
  //frc::DigitalOutput m_digitalOutRear(4);


 public:
  UltraSonic();


  double GetRange();
  void SetCounterReset();
  bool IsRangeValid();
	double GetRangeBack();
  void SetCounterResetBack();
  bool IsRangeValidBack();
  void FrontSonicOn();
  void FrontSonicOff();
  void RearSonicOn();
  void RearSonicOff();  
};
