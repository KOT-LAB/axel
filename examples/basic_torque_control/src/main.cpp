#include <Arduino.h>
#include <SPI.h>
#include <SimpleFOC.h>
#include <SimpleFOCDrivers.h>
#include <encoders/as5047/MagneticSensorAS5047.h>

#include "pinout.h"

#define MOTOR_POLE_PAIRS 11 // number of pole pairs on your motor

#define SUPPLY_VOLTAGE 24.0f     // maximal voltage to be set to the motor
#define VOLTAGE_SENSOR_ALIGN 3.3 // aligning voltage

#define INITIAL_TARGET 0.0f     // initial desired position in radians
#define SERIAL_BAUD_RATE 115200 // serial baud rate

BLDCMotor motor(MOTOR_POLE_PAIRS);
BLDCDriver3PWM driver(INHA, INHB, INHC, M_ENBL);
MagneticSensorAS5047 sensor(SPI1_CS);

float target_voltage = INITIAL_TARGET;
Commander command = Commander(Serial);
void doTarget(char *cmd) { command.scalar(&target_voltage, cmd); }

void setup() {
  Serial.begin(SERIAL_BAUD_RATE);  // use monitoring with serial
  SimpleFOCDebug::enable(&Serial); // enable more verbose output for debugging
  motor.useMonitoring(Serial);

  sensor.init();             // initialise magnetic sensor hardware
  motor.linkSensor(&sensor); // link the motor to the sensor

  // Hardware-specific initialization for the DRV8302
  pinMode(M_OCPRT, OUTPUT);
  digitalWrite(M_OCPRT, LOW); // enable over-current protection
  pinMode(M_OC_ADJ, OUTPUT);
  digitalWrite(M_OC_ADJ, HIGH); // set the maximum over-current limit possible
  driver.voltage_power_supply = SUPPLY_VOLTAGE;
  driver.init();
  motor.linkDriver(&driver); // link the motor and the driver

  motor.voltage_sensor_align = VOLTAGE_SENSOR_ALIGN;

  motor.foc_modulation =
      FOCModulationType::SpaceVectorPWM; // choose FOC modulation
  motor.controller =
      MotionControlType::torque; // set motion control loop to be used

  motor.init();
  motor.initFOC();

  command.add('T', doTarget, "target voltage");

  Serial.println(F("Motor ready."));
  Serial.println(F("Set the target voltage using serial terminal:"));
  _delay(1000);
}

void loop() {

  motor.loopFOC();
  motor.move(target_voltage);
  command.run();
}
