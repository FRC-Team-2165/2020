/*----------------------------------------------------------------------------*/
/* Copyright (c) 2019 FIRST. All Rights Reserved.                             */
/* Open Source Software - may be modified and shared by FRC teams. The code   */
/* must be accompanied by the FIRST BSD license file in the root directory of */
/* the project.                                                               */
/*----------------------------------------------------------------------------*/

#pragma once

#include <wpi/math>

/**
 * The Constants header provides a convenient place for teams to hold robot-wide
 * numerical or boolean constants.  This should not be used for any other
 * purpose.
 *
 * It is generally a good idea to place constants into subsystem- or
 * command-specific namespaces within this header, which can then be used where
 * they are needed.
 */


namespace DIDOConstants {
// drive motor CAN ID #  
    constexpr int kDIDOPhotoCell= 3; 
    constexpr int kDIDOSonicCounterFront = 4;
    constexpr int kDIDOSonicControlFront = 8;
    constexpr int kDIDOSonicCounterRear = 5;
    constexpr int kDIDOSonicControlRear = 9;
    constexpr int kWheelEncoder0 = 0;
    constexpr int kWheelEncoder1 = 1;
    constexpr int kFlipperDI= 2;
}  // namespace DIDOConstants

namespace PWMConstants {
//   
    constexpr int kArmReleaseLeft = 0; 
    constexpr int kArmReleaseRight = 1;
}
namespace AIConstants {
    constexpr int IR_SWITCH = 0; 
}

namespace DriveConstants {
// drive motor CAN ID #  
/*
    constexpr int kFrontLeft = 6; 
    constexpr int kRearLeft = 3;
    constexpr int kFrontRight = 2;
    constexpr int kRearRight = 5;

    constexpr int kWinchMotor = 7; //8;
    constexpr int kArmMotor = 9;
    constexpr int kHopperMotor = 4;
    constexpr int kRetrieverMotor = 8;//7;
    */

    constexpr int kFrontLeft = 2; 
    constexpr int kRearLeft = 5;
    constexpr int kFrontRight = 3;
    constexpr int kRearRight = 6;

    constexpr int kWinchMotor = 8;
    constexpr int kArmMotor = 4;
    constexpr int kHopperMotor = 1;
    constexpr int kRetrieverMotor = 7;


    constexpr double kP = 0.35;
    constexpr double kI = 0.0;
    constexpr double kD = 0.00;

    constexpr int kEncoderCPR = 256;
    constexpr double kWheelDiameterInches = 6;
    constexpr double kTransmissionRatio = 1.0;
    constexpr double EncoderDistancePerPulse = 
        (kWheelDiameterInches * wpi::math::pi) /
        (kTransmissionRatio * 
        static_cast<double>(kEncoderCPR));
}  // namespace DriveConstants

namespace PneumaticsConstants {
// Transmission Fwd/Rev pneumatic ports     
    constexpr int kTransFwdChan_0 = 0;
    constexpr int kTransRevChan_1 = 1;
    constexpr int kTransFwdChan_2 = 2;//hopper
    constexpr int kTransRevChan_3 = 3;//hopper
    constexpr int kFlipperFwdChan_4 = 4;
    constexpr int kFlipperRevChan_5 = 5;
    constexpr int kTransFwdChan_6 = 6;//retriever
    constexpr int kTransRevChan_7 = 7;//retriever
 

}  // namespace PneumaticsConstants

namespace OIConstants {
// Joysticks USB #    
    constexpr int kJoystickUSB_0 = 0;
    constexpr int kJoystickUSB_1 = 1;
} // namespace OIConstants

// Joystick Buttons
//
    constexpr int kButton_1      = 1;  // disable gyro to allow rotation
    constexpr int kButton_2      = 2;  // enable gyro to prevent rotation
    constexpr int kButton_3      = 3;  // shift to high gear ratio - slower speed
    constexpr int kButton_4      = 4;  // shift to low gear ratio - higher speed
    constexpr int kButton_5      = 5;  //Retriever Motor On Rev
    constexpr int kButton_6      = 6;  //Retriever Motor On Fwd
    constexpr int kButton_7      = 7;  //Arm Motor On Rev
    constexpr int kButton_8      = 8;  //Arm Motor On Fwd
    constexpr int kButton_9      = 9;  //Hopper Motor On Rev
    constexpr int kButton_10      = 10;  //Hopper Motor On Fwd
    constexpr int kButton_11      = 11;  //Winch Motor On Rev
    constexpr int kButton_12      = 12;  //Winch Motor On Fwd
 
 //Joystick1
   // constexpr int kButton_1      = 1;  // disengage the gyro
    //constexpr int kButton_2      = 2;  // locks the gyro

 


