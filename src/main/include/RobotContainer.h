/*----------------------------------------------------------------------------*/
/*Test version of ArcadeDr_NewCommandFrame                                    */
/*                                                                            */
/* Copyright (c) 2019 FIRST. All Rights Reserved.                             */
/* Open Source Software - may be modified and shared by FRC teams. The code   */
/* must be accompanied by the FIRST BSD license file in the root directory of */
/* the project.                                                               */
/*----------------------------------------------------------------------------*/

#pragma once

#include <frc/joystick.h>
#include <frc/smartdashboard/SendableChooser.h>
#include <frc2/command/Command.h>
#include <frc2/command/InstantCommand.h>
#include <frc2/command/RunCommand.h>
#include <frc2/command/button/JoystickButton.h>
#include "Constants.h"

// enter include for autonomous command
#include "commands/AutonomousCommand.h" 

// enter includes for subsystems
#include "subsystems/DriveTrain.h"
#include "subsystems/PneumaticShift_2.h"
#include "subsystems/RetrieverMotor.h"
#include "subsystems/ArmMotor.h"
#include "subsystems/HopperMotor.h"
#include "subsystems/WinchMotor.h"
#include "subsystems/HopperPneumatic.h"
#include "subsystems/RetrieverPneumatic.h"
#include "subsystems/ArmReleaseServo.h"
#include "subsystems/RightWheelEncoder.h"
#include "subsystems/UltraSonic.h"
using namespace OIConstants;
/**
 * Test version of New_ArcadeDrive 1/26/20
 * 
 * This class is where the bulk of the robot should be declared.  Since
 * Command-based is a "declarative" paradigm, very little robot logic should
 * actually be handled in the {@link Robot} periodic methods (other than the
 * scheduler calls).  Instead, the structure of the robot (including subsystems,
 * commands, and button mappings) should be declared here.
 */
class RobotContainer {
 public:
  RobotContainer();

  frc2::Command* GetAutonomousCommand(); 
  frc2::Command* GetInitialRobotCommand(); 

// declare method to provide public access to joysticks and buttons

	std::shared_ptr<frc::Joystick> getJoystick0();

	std::shared_ptr<frc2::JoystickButton> getJoystick0_Button1();
	std::shared_ptr<frc2::JoystickButton> getJoystick0_Button2();
	std::shared_ptr<frc2::JoystickButton> getJoystick0_Button3();
	std::shared_ptr<frc2::JoystickButton> getJoystick0_Button4();
	std::shared_ptr<frc2::JoystickButton> getJoystick0_Button5();
	std::shared_ptr<frc2::JoystickButton> getJoystick0_Button6();
	std::shared_ptr<frc2::JoystickButton> getJoystick0_Button7();
	std::shared_ptr<frc2::JoystickButton> getJoystick0_Button8();
	std::shared_ptr<frc2::JoystickButton> getJoystick0_Button9();
	std::shared_ptr<frc2::JoystickButton> getJoystick0_Button10();
	std::shared_ptr<frc2::JoystickButton> getJoystick0_Button11();
	std::shared_ptr<frc2::JoystickButton> getJoystick0_Button12();

	std::shared_ptr<frc::Joystick> getJoystick1();

	std::shared_ptr<frc2::JoystickButton> getJoystick1_Button1();
	std::shared_ptr<frc2::JoystickButton> getJoystick1_Button2();
	std::shared_ptr<frc2::JoystickButton> getJoystick1_Button3();
	std::shared_ptr<frc2::JoystickButton> getJoystick1_Button4();
	std::shared_ptr<frc2::JoystickButton> getJoystick1_Button5();
	std::shared_ptr<frc2::JoystickButton> getJoystick1_Button6();
	std::shared_ptr<frc2::JoystickButton> getJoystick1_Button7();
	std::shared_ptr<frc2::JoystickButton> getJoystick1_Button8();
	std::shared_ptr<frc2::JoystickButton> getJoystick1_Button9();
	std::shared_ptr<frc2::JoystickButton> getJoystick1_Button10();
	std::shared_ptr<frc2::JoystickButton> getJoystick1_Button11();
	std::shared_ptr<frc2::JoystickButton> getJoystick1_Button12();


 static std::unique_ptr<frc2::Command> r_autonomousCommand;
 static std::unique_ptr<frc2::Command> r_initialrobotCommand;
 private:
  // 

   std::shared_ptr<frc::Joystick> joystick0;
   std::shared_ptr<frc::Joystick> joystick1;

// shared pointers to joystick buttons
	std::shared_ptr<frc2::JoystickButton> joystick0_Button1;
	std::shared_ptr<frc2::JoystickButton> joystick0_Button2;
	std::shared_ptr<frc2::JoystickButton> joystick0_Button3;
	std::shared_ptr<frc2::JoystickButton> joystick0_Button4;
	std::shared_ptr<frc2::JoystickButton> joystick0_Button5;
	std::shared_ptr<frc2::JoystickButton> joystick0_Button6;
	std::shared_ptr<frc2::JoystickButton> joystick0_Button7;
	std::shared_ptr<frc2::JoystickButton> joystick0_Button8;
	std::shared_ptr<frc2::JoystickButton> joystick0_Button9;
	std::shared_ptr<frc2::JoystickButton> joystick0_Button10;
	std::shared_ptr<frc2::JoystickButton> joystick0_Button11;
	std::shared_ptr<frc2::JoystickButton> joystick0_Button12;

	std::shared_ptr<frc2::JoystickButton> joystick1_Button1;
	std::shared_ptr<frc2::JoystickButton> joystick1_Button2;
	std::shared_ptr<frc2::JoystickButton> joystick1_Button3;
	std::shared_ptr<frc2::JoystickButton> joystick1_Button4;
	std::shared_ptr<frc2::JoystickButton> joystick1_Button5;
	std::shared_ptr<frc2::JoystickButton> joystick1_Button6;
	std::shared_ptr<frc2::JoystickButton> joystick1_Button7;
	std::shared_ptr<frc2::JoystickButton> joystick1_Button8;
	std::shared_ptr<frc2::JoystickButton> joystick1_Button9;
	std::shared_ptr<frc2::JoystickButton> joystick1_Button10;
	std::shared_ptr<frc2::JoystickButton> joystick1_Button11;
	std::shared_ptr<frc2::JoystickButton> joystick1_Button12;

 
  //Add joystick definition
  frc::Joystick m_joy_0{kJoystickUSB_0};
  frc::Joystick m_joy_1{kJoystickUSB_1};
  // Robot's subsystems and commands are defined here...

  //Autonomous routines
  AutonomousCommand m_autonomousCommand{&m_drivetrain, &m_pneumaticshift_2}; 

  // InstantCommands to be bound to buttons
  frc2::InstantCommand m_push_button1{[this]{ m_drivetrain.SetButton1_On();},
    {&m_drivetrain}};
  frc2::InstantCommand m_release_button1{[this] { m_drivetrain.SetButton1_Off();},
    {&m_drivetrain}};

  frc2::InstantCommand m_push_button2{[this]{ m_drivetrain.SetButton2_On();},
    {&m_drivetrain}};
  frc2::InstantCommand m_release_button2{[this] { m_drivetrain.SetButton2_Off();},
    {&m_drivetrain}};  
  
              
  //Chooser fotr autonomous routines
  frc::SendableChooser<frc2::Command*> m_chooser;

  //Autonomous m_autonomousCommand;
  
  
  void ConfigureButtonBindings();

 
  // joystick USB connection
  static constexpr int USB_0 = 0;
  static constexpr int USB_1 = 1; 

  // joystick button numbers
  static constexpr int BUTTON_1 = 1; // trigger
  static constexpr int BUTTON_2 = 2;
  static constexpr int BUTTON_3 = 3;
  static constexpr int BUTTON_4 = 4; // 
  static constexpr int BUTTON_5 = 5;
  static constexpr int BUTTON_6 = 6;
  static constexpr int BUTTON_7 = 7; // 
  static constexpr int BUTTON_8 = 8;
  static constexpr int BUTTON_9 = 9;
   static constexpr int BUTTON_10 = 10; //
  static constexpr int BUTTON_11 = 11;
  static constexpr int BUTTON_12 = 12;


  
  // Robot's subsystems
  PneumaticShift_2 m_pneumaticshift_2;
  DriveTrain m_drivetrain;
  RetrieverMotor m_retrievermotor;
  ArmMotor m_armmotor;
  HopperMotor m_hoppermotor;
  WinchMotor m_winchmotor;
  HopperPneumatic m_hopperpneumatic;
  RetrieverPneumatic m_retrieverpneumatic;
  ArmReleaseServo m_armreleaseservo;
  RightWheelEncoder m_rightwheelencoder;
  //PhotoSensor m_photosensor;
  
  UltraSonic m_ultrasonic;
  

};



