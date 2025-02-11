#include <Arduino.h>
#include <SPI.h>
#include <SimpleFOC.h>
#include <SimpleFOCDrivers.h>
#include <encoders/as5047/MagneticSensorAS5047.h>

#include "pinout.h"

#define MOTOR_POLE_PAIRS 11 // number of pole pairs on your motor

#define PID_VELOCITY_P 0.2f  // proportional constant of PID
#define PID_VELOCITY_I 20.0f // integral constant of PID
#define PID_VELOCITY_D 0     // derivative constant of PID
#define SUPPLY_VOLTAGE 24.0f // maximal voltage to be set to the motor
#define VELOCITY_LIMIT 50.0f // maximal velocity of the position control
#define LPF_VELOCITY_Tf                                                        \
  0.01f // velocity low pass filtering time constant. the lower the less
        // filtered
#define ANGLE_P 20.0f // angle P controller

#define INITIAL_TARGET 0.0f     // initial desired position in radians
#define SERIAL_BAUD_RATE 115200 // serial baud rate

#define SHUNT_RESISTOR 56
#define AMPLIFICATION_GAIN 10
#define PHASE_A_ADC_PIN SOA
#define PHASE_B_ADC_PIN SOB

BLDCMotor motor(MOTOR_POLE_PAIRS);
BLDCDriver3PWM driver(INHA, INHB, INHC, M_ENBL);
MagneticSensorAS5047 sensor(SPI1_CS);
InlineCurrentSense current_sense(SHUNT_RESISTOR, AMPLIFICATION_GAIN,
                                 PHASE_A_ADC_PIN, PHASE_B_ADC_PIN);

float target_angle = INITIAL_TARGET;
Commander command = Commander(Serial);
void doTarget(char *cmd) { command.scalar(&target_angle, cmd); }

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

  current_sense.linkDriver(&driver); // link the driver to the current sense

  motor.foc_modulation =
      FOCModulationType::SpaceVectorPWM; // choose FOC modulation
  motor.controller =
      MotionControlType::angle; // set motion control loop to be used

  motor.PID_velocity.P = PID_VELOCITY_P;
  motor.PID_velocity.I = PID_VELOCITY_I;
  motor.PID_velocity.D = PID_VELOCITY_D;

  motor.voltage_limit = SUPPLY_VOLTAGE;
  motor.velocity_limit = VELOCITY_LIMIT;
  motor.LPF_velocity.Tf = LPF_VELOCITY_Tf;
  motor.P_angle.P = ANGLE_P;

  motor.init();                           // initialize motor
  current_sense.init();                   // init current sense
  motor.linkCurrentSense(&current_sense); // link the current sense to the motor
  current_sense.skip_align = true;        // true or false = up to you
  motor.initFOC();                        // align sensor and start FOC

  command.add('T', doTarget, "target angle"); // add target command T

  Serial.println(F("Motor ready."));
  Serial.println(F("Set the target angle using serial terminal:"));
  _delay(1000);
}

void loop() {
  motor.loopFOC();
  motor.move(target_angle);
  command.run();
}
