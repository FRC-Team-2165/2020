/*----------------------------------------------------------------------------*/
/* Copyright (c) 2017-2018 FIRST. All Rights Reserved.                        */
/* Open Source Software - may be modified and shared by FRC teams. The code   */
/* must be accompanied by the FIRST BSD license file in the root directory of */
/* the project.                                                               */
/*----------------------------------------------------------------------------*/

#include "subsystems/UltraSonic.h"
#include "frc/smartDashboard/SmartDashboard.h"

using namespace DIDOConstants;



constexpr double UltraSonic:: kSpeedOfSoundInchesPerSec;

UltraSonic::UltraSonic() 
:m_sonicCounterFront{kDIDOSonicCounterFront},
 m_sonicCounterRear{kDIDOSonicCounterRear},
 m_digitalOutFront{kDIDOSonicControlFront},
 m_digitalOutRear{kDIDOSonicControlRear}

{
	
	m_sonicCounterFront.SetMaxPeriod(0.2); //max period for determining pulse duration(seconds)
	m_sonicCounterFront.SetSemiPeriodMode(true); //pulse width of a high pulse (defined by rising edge to falling edge)
	m_sonicCounterFront.Reset();

	m_sonicCounterRear.SetMaxPeriod(0.2); //max period for determining pulse duration(seconds)
	m_sonicCounterRear.SetSemiPeriodMode(true); //pulse width of a high pulse (defined by rising edge to falling edge)
	m_sonicCounterRear.Reset();

	 
	 m_digitalOutFront.Set(false);
	 m_digitalOutRear.Set(false);

}


// Put methods for controlling this subsystem
// here. Call these from Commands.

bool UltraSonic::IsRangeValid()
{

	return (m_sonicCounterFront.Get() > 1); // counter has started
}

double UltraSonic::GetRange()
{
	if(IsRangeValid()) // if count is not at least 1 then the range has not yet been measured
		{
		double distance = m_sonicCounterFront.GetPeriod()*kSpeedOfSoundInchesPerSec / 2.0; // GetPeriod() gets signal on Pin 2-PW
		frc::SmartDashboard::PutNumber("UltraSonic", distance);
		return distance;
		}
	else
		return 0.0; // not valid - set 0.0 since LV-MaxSonar-EZ minimum value is approximatley 6 inches
}

void UltraSonic::SetCounterReset()
{
	m_sonicCounterFront.Reset();
}


bool UltraSonic::IsRangeValidBack()
{

	return (m_sonicCounterRear.Get() > 1); // true condition verifies counter has started
}

double UltraSonic::GetRangeBack()
{
	if(IsRangeValidBack()) // if count is not at least 2 then the range has not yet been measured
		{
		double distance = m_sonicCounterRear.GetPeriod()*kSpeedOfSoundInchesPerSec / 2.0; // GetPeriod() gets signal on Pin 2-PW
		frc::SmartDashboard::PutNumber("UltraSonicBack", distance);
		return distance;
		}
	else
		return 0.0; // not valid - set 0.0 since LV-MaxSonar-EZ minimum value is approximately 6 inches
}

void UltraSonic::SetCounterResetBack()
{
	m_sonicCounterRear.Reset();
}

void UltraSonic::FrontSonicOff() {
	 m_digitalOutFront.Set(false);
}

void UltraSonic::RearSonicOff() {
	 m_digitalOutRear.Set(false);
}

void UltraSonic::FrontSonicOn() {
	 m_digitalOutFront.Set(true);
}

void UltraSonic::RearSonicOn() {
	 m_digitalOutRear.Set(true);
}
