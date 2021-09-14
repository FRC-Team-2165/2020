/*----------------------------------------------------------------------------*/
/* Copyright (c) 2019 FIRST. All Rights Reserved.                             */
/* Open Source Software - may be modified and shared by FRC teams. The code   */
/* must be accompanied by the FIRST BSD license file in the root directory of */
/* the project.                                                               */
/*----------------------------------------------------------------------------*/

#include "subsystems/RetrieverPneumatic.h"

RetrieverPneumatic::RetrieverPneumatic() {
    // Let's show everything on LiveWindows
    SetName("RetrieverPneumatic");
    AddChild("Retriever", &m_pneumaticRetriever);
}

void RetrieverPneumatic::RetrieverExtend() {
    m_pneumaticRetriever.Set(frc::DoubleSolenoid::kForward); // extend retriever
}

void RetrieverPneumatic::RetrieverRetract() {
    m_pneumaticRetriever.Set(frc::DoubleSolenoid::kReverse); // retract retriever
}

void RetrieverPneumatic::RetrieverOff() {
    m_pneumaticRetriever.Set(frc::DoubleSolenoid::kOff);
}

void RetrieverPneumatic::Log() {}

// This method will be called once per scheduler run
void RetrieverPneumatic::Periodic() {}
