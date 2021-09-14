/*----------------------------------------------------------------------------*/
/* Copyright (c) 2019 FIRST. All Rights Reserved.                             */
/* Open Source Software - may be modified and shared by FRC teams. The code   */
/* must be accompanied by the FIRST BSD license file in the root directory of */
/* the project.                                                               */
/*----------------------------------------------------------------------------*/

#include "subsystems/PneumaticShift_2.h"

PneumaticShift_2::PneumaticShift_2() {
    // Let's show everything on LiveWindows
    SetName("PneumaticShift_2");
    AddChild("Trans", &m_pneumaticTrans_2);
}

void PneumaticShift_2::HighGearRatio() {
    m_pneumaticTrans_2.Set(frc::DoubleSolenoid::kForward); // high gear ratio - slower robot
}

void PneumaticShift_2::LowGearRatio() {
    m_pneumaticTrans_2.Set(frc::DoubleSolenoid::kReverse); // low gear ration - faster robot
}

void PneumaticShift_2::ShiftOff() {
    m_pneumaticTrans_2.Set(frc::DoubleSolenoid::kOff);
}

void PneumaticShift_2::Log() {}

// This method will be called once per scheduler run
void PneumaticShift_2::Periodic() {}
