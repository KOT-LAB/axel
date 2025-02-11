#include <Arduino.h>
#include <SPI.h>
#include <SimpleFOC.h>
#include <SimpleFOCDrivers.h>
#include <encoders/as5047/MagneticSensorAS5047.h>

#include "pinout.h"

#define MOTOR_POLE_PAIRS 11 // number of pole pairs on your motor

#define PID_VELOCITY_P 0.2f           // proportional constant of PID
#define PID_VELOCITY_I 20.0f          // integral constant of PID
#define PID_VELOCITY_D 0              // derivative constant of PID
#define PID_VELOCITY_OUTPUT_RAMP 1000 // jerk control using voltage voltage ramp
#define SUPPLY_VOLTAGE 24.0f          // maximal voltage to be set to the motor
#define LPF_VELOCITY_Tf                                                        \
  0.01f // velocity low pass filtering time constant. the lower the less
        // filtered

#define INITIAL_TARGET 0.0f     // initial desired position in radians
#define SERIAL_BAUD_RATE 115200 // serial baud rate

BLDCMotor motor(MOTOR_POLE_PAIRS);
BLDCDriver3PWM driver(INHA, INHB, INHC, M_ENBL);
MagneticSensorAS5047 sensor(SPI1_CS);

float target_velocity = INITIAL_TARGET;
Commander command = Commander(Serial);
void doTarget(char *cmd) { command.scalar(&target_velocity, cmd); }

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

  motor.foc_modulation = FOCModulationType::SinePWM; // choose FOC modulation
  motor.controller =
      MotionControlType::velocity; // set motion control loop to be used

  motor.PID_velocity.P = PID_VELOCITY_P;
  motor.PID_velocity.I = PID_VELOCITY_I;
  motor.PID_velocity.D = PID_VELOCITY_D;

  motor.PID_velocity.output_ramp = PID_VELOCITY_OUTPUT_RAMP;

  motor.voltage_limit = SUPPLY_VOLTAGE;
  motor.LPF_velocity.Tf = LPF_VELOCITY_Tf;

  motor.init();    // initialize motor
  motor.initFOC(); // align sensor and start FOC

  command.add('T', doTarget, "target velocity"); // add target command T

  Serial.println(F("Motor ready."));
  Serial.println(F("Set the target velocity using serial terminal:"));
  _delay(1000);
}

void loop() {
  motor.loopFOC();
  motor.move(target_velocity);
  command.run();
}
