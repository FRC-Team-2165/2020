/*----------------------------------------------------------------------------*/
/*Test version of ArcadeDr_NewCommandFrame                                    */
/*                                                                            */ 
/*Copyright (c) 2019 FIRST. All Rights Reserved.                              */
/* Open Source Software - may be modified and shared by FRC teams. The code   */
/* must be accompanied by the FIRST BSD license file in the root directory of */
/* the project.                                                               */
/*----------------------------------------------------------------------------*/

#include "RobotContainer.h"

#include <frc/smartdashboard/SmartDashboard.h>
#include <frc/shuffleboard/Shuffleboard.h>
#include "frc/joystick.h"

#include "commands/DriveJoysticksGyro.h"
#include "commands/ShiftToHigh.h"
#include "commands/ShiftToLow.h"

#include "commands/ArmMotorOn.h"
#include "commands/HopperMotorOn.h"
#include "commands/WinchMotorOn.h"
#include "commands/RetrieverMotorOn.h"

#include "commands/ExtendHopper.h"
#include "commands/ExtendRetriever.h"
#include "commands/RetractHopper.h"
#include "commands/RetractRetriever.h"
#include "commands/SetLeftServo.h"
#include "commands/SetRightServo.h"
#include "commands/MoveTimed.h"
#include "commands/MoveDistance.h"
#include "commands/AutonomousGetBalls.h"
#include "commands/AutonomousDumpBalls.h"
#include "commands/MoveThroughAngle.h"
#include "commands/ClimbFrontSonic.h"
#include "Constants.h"
#include "commands/InitialRobot.h"

using namespace OIConstants;
RobotContainer::RobotContainer() 
: m_autonomousCommand(&m_drivetrain, &m_pneumaticshift_2) {

  // Initialize all commands and subsystems here
  frc::SmartDashboard::PutData(&m_drivetrain);
  frc::SmartDashboard::PutData(&m_pneumaticshift_2);

  m_drivetrain.Log();  // remember to declare/define Log() in subsystems
  m_pneumaticshift_2.Log();
    
  m_drivetrain.SetDefaultCommand(DriveJoysticksGyro(
      [this] {return m_joy_0.GetY();}, // fwd/Rev with Y-axis
      [this] {return m_joy_0.GetZ();}, // cw/ccw rotation with Z-axis
      &m_drivetrain));
  
  // Initialize all of your commands and subsystems here

  // Configure the button bindings
  ConfigureButtonBindings();

  // assign joystick pointer to an instance of Joystick()
  joystick1.reset(new frc::Joystick(USB_1));
  joystick0.reset(new frc::Joystick(USB_0));
  // assign joystick buttons to an instance of JoystickButtons()
  

    joystick0_Button1.reset(new frc2::JoystickButton(joystick0.get(), BUTTON_1));  // disengage gyro, Trigger
    joystick0_Button2.reset(new frc2::JoystickButton(joystick0.get(), BUTTON_2));
    joystick0_Button3.reset(new frc2::JoystickButton(joystick0.get(), BUTTON_3));  // disengage gyro, Trigger
    joystick0_Button4.reset(new frc2::JoystickButton(joystick0.get(), BUTTON_4));
    
    
    joystick0_Button5.reset(new frc2::JoystickButton(joystick0.get(), BUTTON_5));  // disengage gyro, Trigger
    joystick0_Button6.reset(new frc2::JoystickButton(joystick0.get(), BUTTON_6));
    joystick0_Button7.reset(new frc2::JoystickButton(joystick0.get(), BUTTON_7));  // disengage gyro, Trigger
    joystick0_Button8.reset(new frc2::JoystickButton(joystick0.get(), BUTTON_8));
    

    joystick0_Button9.reset(new frc2::JoystickButton(joystick0.get(), BUTTON_9));  // disengage gyro, Trigger
    joystick0_Button10.reset(new frc2::JoystickButton(joystick0.get(), BUTTON_10));
    joystick0_Button11.reset(new frc2::JoystickButton(joystick0.get(), BUTTON_11));  // disengage gyro, Trigger
    joystick0_Button12.reset(new frc2::JoystickButton(joystick0.get(), BUTTON_12));
    
    
    joystick1_Button1.reset(new frc2::JoystickButton(joystick1.get(), BUTTON_1));  // disengage gyro, Trigger
    joystick1_Button2.reset(new frc2::JoystickButton(joystick1.get(), BUTTON_2));
    joystick1_Button3.reset(new frc2::JoystickButton(joystick1.get(), BUTTON_3));
    joystick1_Button4.reset(new frc2::JoystickButton(joystick1.get(), BUTTON_4));
    
    
    joystick1_Button5.reset(new frc2::JoystickButton(joystick1.get(), BUTTON_5));  // disengage gyro, Trigger
    joystick1_Button6.reset(new frc2::JoystickButton(joystick1.get(), BUTTON_6));
    joystick1_Button7.reset(new frc2::JoystickButton(joystick1.get(), BUTTON_7));  // disengage gyro, Trigger
    joystick1_Button8.reset(new frc2::JoystickButton(joystick1.get(), BUTTON_8));
    

    joystick1_Button9.reset(new frc2::JoystickButton(joystick1.get(), BUTTON_9));  // disengage gyro, Trigger
    joystick1_Button10.reset(new frc2::JoystickButton(joystick1.get(), BUTTON_10));
    joystick1_Button11.reset(new frc2::JoystickButton(joystick1.get(), BUTTON_11));  // disengage gyro, Trigger
    joystick1_Button12.reset(new frc2::JoystickButton(joystick1.get(), BUTTON_12));



}

void RobotContainer::ConfigureButtonBindings() {
  // Configure your button bindings here

  // Set up joystick buttons to enable methods in commands
  /*
  frc2::JoystickButton(&m_joy_0, kButton_1)
    .WhenPressed(&m_push_button1)
    .WhenReleased(&m_release_button1);

  frc2::JoystickButton(&m_joy_0, kButton_2)
    .WhenPressed(&m_push_button2)
    .WhenReleased(&m_release_button2); 
  */

 //joystick1  button 1 and 2 are used in drivejoysticksgyro
 //button drive no gyro
 //button 2 drive straight no jyro
 frc2::JoystickButton m_ArmOnFwd{&m_joy_0, kButton_3};
 frc2::JoystickButton m_ArmOnRev{&m_joy_0, kButton_4}; 
 frc2::JoystickButton m_ClimbFrontSonic{&m_joy_0, kButton_5}; 
 //frc2::JoystickButton m_MoveDistance{&m_joy_0, kButton_6}; 
  //frc2::JoystickButton m_shiftHigh{&m_joy_0, kButton_7};  // low gear ratio - high speed
  //frc2::JoystickButton m_shiftLow{&m_joy_0, kButton_8};   // high gear ratio - low speed
 /*
  frc2::JoystickButton m_SetLeftServo_0{&m_joy_0, kButton_9}; //start retriever Motor Rev
  frc2::JoystickButton m_SetRightServo_0{&m_joy_0, kButton_10}; //start retriever Motor Fwd
  frc2::JoystickButton m_SetLeftServo_90{&m_joy_0, kButton_11}; //start retriever Motor Rev
  frc2::JoystickButton m_SetRightServo_90{&m_joy_0, kButton_12}; //start retriever Motor Fwd
*/
 frc2::JoystickButton m_InitialRobot{&m_joy_0, kButton_12};

//joystick1  button 1 and 2 are used in drivejoysticksgyro
frc2::JoystickButton m_RetrieverOnFwd{&m_joy_1, kButton_1}; //start retriever Motor Fwd
frc2::JoystickButton m_HopperOnFwd{&m_joy_1, kButton_2}; //start retriever Motor Fwd  
 frc2::JoystickButton m_ExtendHopper{&m_joy_1, kButton_3}; 
frc2::JoystickButton m_RetractHopper{&m_joy_1, kButton_4};
 frc2::JoystickButton m_ExtendRetriever{&m_joy_1, kButton_5}; 
frc2::JoystickButton m_RetractRetriever{&m_joy_1, kButton_6};
//frc2::JoystickButton m_RetrieverOnRev{&m_joy_1, kButton_7};
//frc2::JoystickButton m_HopperOnRev{&m_joy_1, kButton_8};
//frc2::JoystickButton m_WinchOnFwd{&m_joy_1, kButton_9};
//frc2::JoystickButton m_WinchOnRev{&m_joy_1, kButton_10};
//frc2::JoystickButton m_MoveTimed{&m_joy_1, kButton_11};
frc2::JoystickButton m_MoveThroughAngle{&m_joy_1,kButton_12};

  //m_shiftHigh.WhenPressed(ShiftToHigh(&m_pneumaticshift_2));
  //m_shiftLow.WhenPressed(ShiftToLow(&m_pneumaticshift_2));
  //m_autoStart.WhenPressed(AutonomousCommand(&m_drivetrain, &m_pneumaticshift_2));

  //m_RetrieverOnRev.WhileHeld(RetrieverMotorOn(1.0,0,1,&m_retrievermotor));
  m_RetrieverOnFwd.WhileHeld(RetrieverMotorOn(1.0,1,1,&m_retrievermotor));

  m_ArmOnRev.WhileHeld(ArmMotorOn(1.0,1,1,&m_armmotor));
  m_ArmOnFwd.WhileHeld(ArmMotorOn(1.0,0,1,&m_armmotor));
  //m_HopperOnRev.WhileHeld(HopperMotorOn(1.0,1,1,&m_hoppermotor));
  m_HopperOnFwd.WhileHeld(HopperMotorOn(1.0,0,1,&m_hoppermotor));
  //m_WinchOnRev.WhileHeld(WinchMotorOn(0.5,0,1,&m_winchmotor));
  //m_WinchOnFwd.WhileHeld(WinchMotorOn(0.5,1,1,&m_winchmotor));
/*
  m_SetLeftServo_0.WhenPressed(SetLeftServo(0.0,4.0,&m_armreleaseservo));
  m_SetRightServo_0.WhenPressed(SetRightServo(0.0,4.0,&m_armreleaseservo));
  m_SetLeftServo_90.WhenPressed(SetLeftServo(90.0,4.0,&m_armreleaseservo));
  m_SetRightServo_90.WhenPressed(SetRightServo(90.0,4.0,&m_armreleaseservo));
  */
m_InitialRobot.WhenPressed(InitialRobot(&m_armmotor,&m_hoppermotor,&m_retrievermotor,&m_winchmotor,&m_hopperpneumatic,&m_retrieverpneumatic));



  //m_MoveTimed.WhenPressed(MoveTimed(0.5,2.0,0,&m_drivetrain));
 //m_MoveDistance.WhenPressed(MoveDistance(-36.0,0.5,16.0,&m_drivetrain,&m_rightwheelencoder));

  m_MoveThroughAngle.WhenPressed(MoveThroughAngle(179.0, 0.5,5.0,&m_drivetrain));
  
  m_ClimbFrontSonic.WhenPressed(ClimbFrontSonic(14.0,0.4,30.0,&m_winchmotor,&m_ultrasonic));

  m_ExtendHopper.WhenPressed(ExtendHopper(&m_hopperpneumatic));
  m_RetractHopper.WhenPressed(RetractHopper(&m_hopperpneumatic));
  m_ExtendRetriever.WhenPressed(ExtendRetriever(&m_retrieverpneumatic));
  m_RetractRetriever.WhenPressed(RetractRetriever(&m_retrieverpneumatic));

  frc::SmartDashboard::PutNumber("ButtonBindings", 1.1);

}
/*
frc2::Command* RobotContainer::GetAutonomousCommand() {
  // An example command will be run in autonomous
  return &m_autonomousCommand;
}
*/

/*

frc2::Command* RobotContainer::GetAutonomousCommand() {

  // Runs the chosen command in autonomous

  return new frc2::InstantCommand([] {});

}
*/
frc2::Command* RobotContainer::GetAutonomousCommand() {
  // An example command will be run in autonomous
  
//  Method to get DB/Buttons from Driver Station to run specific autonomous routines
//void Robot::GetButtonAuto() {// method to select autonomous function
	int bval = 0;
	bool buttonstate = false;

	buttonstate = frc::SmartDashboard::GetBoolean("DB/Button 0",false);
	if(buttonstate == true) bval |= 1;

	buttonstate = frc::SmartDashboard::GetBoolean("DB/Button 1",false);
	if(buttonstate == true) bval |= 2;

	buttonstate = frc::SmartDashboard::GetBoolean("DB/Button 2",false);
	if(buttonstate == true) bval |= 4;

	buttonstate = frc::SmartDashboard::GetBoolean("DB/Button 3",false);
	if(buttonstate == true) bval |= 8;

	switch(bval)
	{

		case 0:
    {
      
			r_autonomousCommand.reset(new  MoveDistance(-100.0, 0.5,20.0,&m_drivetrain,&m_rightwheelencoder));
		}
		break;
    case 1:
    {
      
			r_autonomousCommand.reset(new  MoveTimed(0.5,3.0,0,&m_drivetrain));
		}
		break;
		case 2:
		{
			//r_autonomousCommand.reset(new  ArmMotorOn(0.5,1,&m_armmotor));
      
       r_autonomousCommand.reset(new AutonomousGetBalls(&m_drivetrain, &m_retrievermotor, &m_hoppermotor,&m_retrieverpneumatic,&m_rightwheelencoder));
 

		}
		break;

	case 3:
		{
			//r_autonomousCommand.reset(new  ArmMotorOn(0.5,1,&m_armmotor));
      
       r_autonomousCommand.reset(new AutonomousDumpBalls(&m_drivetrain, &m_hopperpneumatic, &m_rightwheelencoder));
 

		}
		break;


//Add other autonomous commands as needed here

		default:
		{
      r_autonomousCommand.reset(new  MoveTimed(0.0,3.0,0,&m_drivetrain));
	//r_autonomousCommand.reset(new  ArmMotorOn(0.5,1,&m_armmotor));
		}
		break;
	}
	


   return r_autonomousCommand.get();
}

frc2::Command* RobotContainer::GetInitialRobotCommand() {
  // An example command will be run in autonomous
  		r_initialrobotCommand.reset(new  InitialRobot(&m_armmotor,&m_hoppermotor,&m_retrievermotor,&m_winchmotor,&m_hopperpneumatic,&m_retrieverpneumatic));
	
   return r_initialrobotCommand.get();
}







 	std::shared_ptr<frc::Joystick> RobotContainer::getJoystick0() {return joystick0;}
	std::shared_ptr<frc2::JoystickButton> RobotContainer::getJoystick0_Button1() {return joystick0_Button1;} // disengage gyro
	std::shared_ptr<frc2::JoystickButton> RobotContainer::getJoystick0_Button2() {return joystick0_Button2;} // drive straight by gyro
	std::shared_ptr<frc2::JoystickButton> RobotContainer::getJoystick0_Button3() {return joystick0_Button3;} // low gear ration - fast robot
	std::shared_ptr<frc2::JoystickButton> RobotContainer::getJoystick0_Button4() {return joystick0_Button4;} // high gear ratio - slow robot

	std::shared_ptr<frc2::JoystickButton> RobotContainer::getJoystick0_Button5() {return joystick0_Button5;} // initiates MoveDistance (by encoder)
	std::shared_ptr<frc2::JoystickButton> RobotContainer::getJoystick0_Button6() {return joystick0_Button6;} // initiates MoveFrontSonic (front sonic device)
  std::shared_ptr<frc2::JoystickButton> RobotContainer::getJoystick0_Button7() {return joystick0_Button7;} // initiates MoveRearSonic (rear sonic device)
  std::shared_ptr<frc2::JoystickButton> RobotContainer::getJoystick0_Button8() {return joystick0_Button8;} // initiates MoveThroughAngle CW rotation
  
  std::shared_ptr<frc2::JoystickButton> RobotContainer::getJoystick0_Button9() {return joystick0_Button9;} // initiates MoveThroughAngle CCW rotation
  std::shared_ptr<frc2::JoystickButton> RobotContainer::getJoystick0_Button10() {return joystick0_Button10;}  // initiates move to tape
  std::shared_ptr<frc2::JoystickButton> RobotContainer::getJoystick0_Button11() {return joystick0_Button11;}  // initiates move to tape
  std::shared_ptr<frc2::JoystickButton> RobotContainer::getJoystick0_Button12() {return joystick0_Button12;}  // initiates move to tape

  
 	std::shared_ptr<frc::Joystick> RobotContainer::getJoystick1() {return joystick1;}
	std::shared_ptr<frc2::JoystickButton> RobotContainer::getJoystick1_Button1() {return joystick1_Button1;} // disengage gyro
	std::shared_ptr<frc2::JoystickButton> RobotContainer::getJoystick1_Button2() {return joystick1_Button2;} // drive straight by gyro
	std::shared_ptr<frc2::JoystickButton> RobotContainer::getJoystick1_Button3() {return joystick1_Button3;} // low gear ration - fast robot
	std::shared_ptr<frc2::JoystickButton> RobotContainer::getJoystick1_Button4() {return joystick1_Button4;} // high gear ratio - slow robot
	std::shared_ptr<frc2::JoystickButton> RobotContainer::getJoystick1_Button5() {return joystick1_Button5;} // initiates MoveDistance (by encoder)
	std::shared_ptr<frc2::JoystickButton> RobotContainer::getJoystick1_Button6() {return joystick1_Button6;} // initiates MoveFrontSonic (front sonic device)
  std::shared_ptr<frc2::JoystickButton> RobotContainer::getJoystick1_Button7() {return joystick1_Button7;} // initiates MoveRearSonic (rear sonic device)
  std::shared_ptr<frc2::JoystickButton> RobotContainer::getJoystick1_Button8() {return joystick1_Button8;} // initiates MoveThroughAngle CW rotation
  std::shared_ptr<frc2::JoystickButton> RobotContainer::getJoystick1_Button9() {return joystick1_Button9;} // initiates MoveThroughAngle CCW rotation
  std::shared_ptr<frc2::JoystickButton> RobotContainer::getJoystick1_Button10() {return joystick1_Button10;}  // initiates move to tape
  std::shared_ptr<frc2::JoystickButton> RobotContainer::getJoystick1_Button11() {return joystick1_Button11;}  // initiates move to tape
  std::shared_ptr<frc2::JoystickButton> RobotContainer::getJoystick1_Button12() {return joystick1_Button12;}  // initiates move to tape
  
  std::unique_ptr<frc2::Command> RobotContainer::r_autonomousCommand;
  std::unique_ptr<frc2::Command> RobotContainer::r_initialrobotCommand;