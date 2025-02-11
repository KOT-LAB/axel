# Advanced Position Control example

## Overview

This example demonstrates **position control** on the Axel controller using the SimpleFOC library **with inline current sensing**. It is based on the [official SimpleFOC examples](https://github.com/simplefoc/Arduino-FOC/blob/master/examples/motion_control/position_motion_control/magnetic_sensor/angle_control/angle_control.ino) and closely follows the recommended practices for inline current sensing outlined in the [SimpleFOC documentation](https://docs.simplefoc.com/inline_current_sense). The firmware configures the motor for **position-based control**, sets up the on-board encoder and driver, and **activates current sensing** to improve performance, reliability, and protection.

> **Note:** Unlike the [basic_position_control](../basic_position_control) example, this **advanced example** takes advantage of Axel’s **current sensing capability** for better FOC performance and real-time current monitoring.

---

## Objectives

- Show **SimpleFOC's seamless integration** with Axel.
- Set up the Axel's specific hardware: **on-board AS5047P encoder**, **DRV8302 driver** and **current sensing**.
- Demonstrate how to **integrate and utilize current sensing** in Axel’s FOC workflow.
- Show **improved current feedback**, resulting in **more efficient torque controle*.
- Illustrate the recommended initialization order and usage of `current_sense` in code in conjunction with the **on-board DRV8302 driver** and **AS5047P encoder**.

---

## Why Use Current Sensing?

The inclusion of current sensing significantly boosts the controller’s capabilities:

1. **Improved FOC accuracy**: By monitoring phase currents in real time, the controller can maintain **more precise field alignment** and deliver superior torque performance.
2. **Overcurrent protection**: Real-time current feedback helps you **detect and prevent dangerous overcurrent conditions** quickly, safeguarding your hardware.
3. **Enhanced tuning**: Being able to observe and fine-tune current loops offers **deeper insight** into motor behavior, allowing for tighter control and **improved efficiency**.

---

## Setup Instructions

This example uses the same fundamental setup as the **basic_position_control** example, but adds pins and configuration parameters for current sensing.

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

### 3. Configure #define Values in main.cpp

Edit the following parameters to fit your **specific hardware** and tuning needs:

- **Motor pole pairs:** `#define MOTOR_POLE_PAIRS`
- **Power supply voltage:** `#define SUPPLY_VOLTAGE`
- **Control parameters (e.g., PID gains, velocity limits, etc.)`

---

## Building and Running the Example

### 1. Build the Project

Open a terminal in the project directory and run:

```bash
pio run
```

### 2. Upload the Firmware

```bash
pio run --target upload
```

### 3. Monitor the Serial Output

Once uploaded, monitor the serial output:

```bash
pio device monitor -b 115200
```

---

## Expected Behavior

When you run this example, you should observe:

- **Initialize the serial monitor and debugging.**
- **Set up and calibrate the magnetic sensor.**
- **Configure the driver (including any DRV8302-specific settings).**
- **Motor and current sense initialization**
- **Initialize the BLDC motor with the appropriate FOC settings and PID parameters.**
- **Real-time current feedback used within the FOC loop for precise torque control**.
- **Continuously run the FOC algorithm and adjust the motor’s position based on the serial input target.**

---

If anything doesn’t work as expected, check your wiring, power supply, and motor parameters. For further assistance, feel free to reach out! 🚀

