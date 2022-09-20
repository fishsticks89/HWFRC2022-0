// Copyright (c) FIRST and other WPILib contributors.
// Open Source Software; you can modify and/or share it under the terms of
// the WPILib BSD license file in the root directory of this project.

#pragma once

#include <frc/Encoder.h>
#include <frc/drive/DifferentialDrive.h>
#include <frc/motorcontrol/MotorControllerGroup.h>
#include <frc/motorcontrol/PWMSparkMax.h>
#include <frc2/command/SubsystemBase.h>
#include <frc/motorcontrol/MotorControllerGroup.h>

#include <units/voltage.h>

#include <ctre/Phoenix.h>

#include "Constants.h"

class DriveSubsystem : public frc2::SubsystemBase {
 public:
  DriveSubsystem();

  /**
   * Will be called periodically whenever the CommandScheduler runs.
   */
  void Periodic() override;

  // Subsystem methods go here.

  /**
   * Drives the robot using arcade controls.
   *
   * @param left the commanded left movement
   * @param right the commanded right movement
   */
  void TankDrive(double left, double right);

 private:
  // Components (e.g. motor controllers and sensors) should generally be
  // declared private and exposed only through public methods.

  // The motor controllers
  ctre::phoenix::motorcontrol::can::WPI_VictorSPX m_left1;
  ctre::phoenix::motorcontrol::can::WPI_VictorSPX m_left2;
  ctre::phoenix::motorcontrol::can::WPI_VictorSPX m_right1;
  ctre::phoenix::motorcontrol::can::WPI_VictorSPX m_right2;

  // The motor groups
  frc::MotorControllerGroup g_right;
  frc::MotorControllerGroup g_left;
};
