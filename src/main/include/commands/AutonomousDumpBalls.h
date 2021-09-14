
#pragma once

#include <frc2/command/CommandBase.h>
#include <frc2/command/CommandHelper.h>
#include <frc2/command/SequentialCommandGroup.h>

#include "commands/MoveTimed.h"
#include "commands/MoveDistance.h"
#include "commands/ExtendHopper.h"
#include "commands/WaitSeconds.h"
#include "commands/RetractHopper.h"

class AutonomousDumpBalls
    : public frc2::CommandHelper<frc2::SequentialCommandGroup, AutonomousDumpBalls> {
 public:
  
    /**
   * Creates a new ComplexAuto.
   *
   * @param drive The drive subsystem this command will run on
   * @param hatch The  subsystems this command will run on
   */
  AutonomousDumpBalls(DriveTrain* drive, HopperPneumatic* hopperpneumatic,RightWheelEncoder* rightwheelencoder);
};