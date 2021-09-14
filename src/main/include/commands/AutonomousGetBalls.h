
#pragma once

#include <frc2/command/CommandBase.h>
#include <frc2/command/CommandHelper.h>
#include <frc2/command/SequentialCommandGroup.h>
#include "commands/MoveDistance.h"
#include "commands/MoveTimed.h"
#include "commands/ExtendRetriever.h"
#include "commands/RetractRetriever.h"
#include "commands/WaitSeconds.h"
#include "commands/RetrieverMotorOn.h"
#include "commands/HopperMotorOn.h"
#include "commands/MoveWithFlipper.h"

class AutonomousGetBalls
    : public frc2::CommandHelper<frc2::SequentialCommandGroup, AutonomousGetBalls> {
 public:
  
    /**
   * Creates a new ComplexAuto.
   *
   * @param drive The drive subsystem this command will run on
   * @param hatch The  subsystems this command will run on
   */
  AutonomousGetBalls(DriveTrain* drive, RetrieverMotor* retrievermotor, HopperMotor* hoppermotor,RetrieverPneumatic* retrieverpneumatic,RightWheelEncoder* rightwheelencoder);
};