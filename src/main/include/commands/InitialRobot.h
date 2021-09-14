
#pragma once

#include <frc2/command/CommandBase.h>
#include <frc2/command/CommandHelper.h>
#include <frc2/command/SequentialCommandGroup.h>
#include "commands/MoveDistance.h"
#include "commands/MoveTimed.h"
#include "commands/RetractRetriever.h"
#include "commands/RetractHopper.h"
#include "commands/WaitSeconds.h"
#include "commands/RetrieverMotorOn.h"
#include "commands/HopperMotorOn.h"
#include "commands/ArmMotorOn.h"
#include "commands/WinchMotorOn.h"

class InitialRobot
    : public frc2::CommandHelper<frc2::SequentialCommandGroup, InitialRobot> {
 public:
  
    /**
   * Creates a new ComplexAuto.
   *
   * @param drive The drive subsystem this command will run on
   * @param hatch The  subsystems this command will run on
   */
  InitialRobot(ArmMotor* armmotor, HopperMotor* hoppermotor,RetrieverMotor* retrievermotor, WinchMotor* winchmotor,HopperPneumatic* hopperpneumatic,RetrieverPneumatic* retrieverpneumatic);
};