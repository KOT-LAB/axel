# Basic Position Control example

## Overview

This example demonstrates **position control** on the Axel controller using the SimpleFOC library. It is based on the [official SimpleFOC example](https://github.com/simplefoc/Arduino-FOC/blob/master/examples/motion_control/position_motion_control/magnetic_sensor/angle_control/angle_control.ino) but has been adapted to work with Axel. The example configures the motor for **position-based control**, setups on-board encoder and driver, and allows position commands via USB-C serial communication.

> **Note:** This is the most basic position control example. It does **not** take advantage of Axel's advanced features like current sensing for FOC. If you need to see how current sensing can be integrated into position control, please refer to the **`[advanced_positin_control](./examples/advanced_position_control)`** directory.

---

## Objectives

- Show **SimpleFOC's seamless integration** with Axel.
- Set up the Axel's specific hardware: **on-board AS5047P encoder** and **DRV8302 driver**.
- Implement **basic positin control** as a foundation for custom firmware enhancements.

---

## Setup Instructions

---

### 1. General Hardware Setup

Before using this example, ensure you have assembled your **motor and controller** correctly. Please refer to **[`hardware_setup.md`](./docs/hardware_setup.md)** for a step-by-step guide.

### 2. Connecting the Axel Controller

To run this example, follow these steps:

1. **Power the Board:**
   - Ensure that the Axel controller is connected to a **suitable power source**.
   - The **main power supply** should match the `#define SUPPLY_VOLTAGE` set in `main.cpp`.
2. **Connect USB-C:**
   - Connect **USB-C** to your computer to enable **serial logging, debugging and control interface**.
3. **Choose an Upload Method:**
   - You can upload the firmware using either **SWD (ST-Link)** or **DFU (Device Firmware Upgrade)**.
   - Edit `platformio.ini` to select the appropriate upload method:

#### **Using ST-Link (default method)**

    ```ini
    upload_protocol = stlink
    ```

#### **Using DFU (alternative method)**

    ```ini
    ; upload_protocol = stlink  ; Comment this out
    upload_protocol = dfu       ; Uncomment this to use DFU mode
    ```

### 3. Configure `#define` Values in `main.cpp`

Before building, make sure to configure the following **user-specific parameters** in `main.cpp` in accordance to your particular setup:

- **Motor pole pairs:** `#define MOTOR_POLE_PAIRS`
- **Power supply voltage:** `#define SUPPLY_VOLTAGE`
- **Control parameters (e.g., PID gains, velocity limits, etc.)`

---

## Building and Running the Example

### 1. Build the Project

From the terminal in the project directory, run:

```sh
pio run
```

### 2. Upload the Firmware

```sh
pio run --target upload
```

### 3. Monitor Serial Output

Once uploaded, monitor the serial output:

```sh
pio device monitor -b 115200
```

---

## Expected Behavior

When you run this example, you can expect it to:

- **Initialize the serial monitor and debugging.**
- **Set up and calibrate the magnetic sensor.**
- **Configure the driver (including any DRV8302-specific settings).**
- **Initialize the BLDC motor with the appropriate FOC settings and PID parameters.**
- **Continuously run the FOC algorithm and adjust the motor’s position based on the serial input target.**

---

If anything doesn’t work as expected, check your wiring, power supply, and motor parameters. For further assistance, feel free to reach out! 🚀


