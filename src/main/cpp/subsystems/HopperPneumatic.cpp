/*----------------------------------------------------------------------------*/
/* Copyright (c) 2019 FIRST. All Rights Reserved.                             */
/* Open Source Software - may be modified and shared by FRC teams. The code   */
/* must be accompanied by the FIRST BSD license file in the root directory of */
/* the project.                                                               */
/*----------------------------------------------------------------------------*/

#include "subsystems/HopperPneumatic.h"

HopperPneumatic::HopperPneumatic() {
    // Let's show everything on LiveWindows
    SetName("HopperPneumatic");
    AddChild("Hopper", &m_pneumaticHopper);
}

void HopperPneumatic::HopperExtend() {
    m_pneumaticHopper.Set(frc::DoubleSolenoid::kForward); // extend hopper
}

void HopperPneumatic::HopperRetract() {
    m_pneumaticHopper.Set(frc::DoubleSolenoid::kReverse); // retract hopper
}

void HopperPneumatic::HopperOff() {
    m_pneumaticHopper.Set(frc::DoubleSolenoid::kOff);
}

void HopperPneumatic::Log() {}

// This method will be called once per scheduler run
void HopperPneumatic::Periodic() {}
