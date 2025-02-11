#ifndef PINOUT_H
#define PINOUT_H

/*
 * pinout.h
 *
 * This header file defines the hardware pinout configuration for the STM32
 * microcontroller used in Axel. The pin assignments reflect the specific
 * connections outlined in the schematic and are designed for peripherals, motor
 * control, and debugging.
 *
 * Notes:
 * - Peripheral instances (e.g., SPI1, UART1) correspond to STM32 documentation.
 * - Pin definitions follow STM32 naming conventions (e.g., PA5 = Port A, Pin
 * 5).
 */

/**************************** Oscillator ****************************/
#define OSC_IN_PIN PH0  // Main oscillator input (8 MHz)
#define OSC_OUT_PIN PH1 // Main oscillator output (8 MHz)

/******************************* GPIO *******************************/
#define LED PA2 // Onboard status LED (LED 1)

/********************* Communication Interfaces *********************/

// UART1 (USART1)
#define UART1_TX PB6 // UART1 Transmit
#define UART1_RX PB7 // UART1 Receive

// SPI1 (Primary SPI)
#define SPI1_CS PC4   // Chip Select for onboard encoder
#define SPI1_CS2 PA4  // Chip Select for external encoder
#define SPI1_SCLK PA5 // SPI1 Clock
#define SPI1_MISO PA6 // SPI1 MISO
#define SPI1_MOSI PA7 // SPI1 MOSI

// SPI3 (Secondary SPI)
#define SPI3_CS PA15   // Chip Select
#define SPI3_SCLK PC10 // SPI3 Clock
#define SPI3_MISO PC11 // SPI3 MISO
#define SPI3_MOSI PC12 // SPI3 MOSI

// I2C3
#define I2C3_SCL PA8 // I2C3 Clock
#define I2C3_SDA PC9 // I2C3 Data

// CAN1
#define CAN1_TX PB9 // CAN1 Transmit
#define CAN1_RX PB8 // CAN1 Receive

// USB OTG HS
#define USB_DP PB15 // USB Data+
#define USB_DM PB14 // USB Data-

/*************************** Motor Control **************************/

// Driver Control
#define M_ENBL PA3    // Motor driver enable
#define M_OC_ADJ PA12 // Overcurrent adjustment
#define M_OCPRT PB3   // Overcurrent protection switch

// PWM Inputs (High Side)
#define INHA PA11 // PWM for high-side bridge A
#define INHB PA10 // PWM for high-side bridge B
#define INHC PA9  // PWM for high-side bridge C

// Current Sensors (ADC1)
#define SOA PB0 // Current sense phase A
#define SOB PB1 // Current sense phase B

// Diagnostic Signals
#define M_FAULT PB5 // Motor driver fault signal
#define M_OVERC PB4 // Overcurrent signal

/***************************** Debugging ****************************/
#define SWDIO PA13 // SWD I/O
#define SWCLK PA14 // SWD Clock

#endif // PINOUT_H
