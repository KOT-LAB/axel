# Blink Example for Axel

## Overview

This example demonstrates a simple **LED blink** program on the Axel controller using the **Arduino framework**. It verifies that the board is correctly powered and running firmware by toggling the onboard LED.

---

## Objectives

- Verify that the **Axel board** is powered and functioning correctly.
- Demonstrate **basic GPIO control** using the onboard LED.
- Provide a minimal **PlatformIO project setup** for Axel.

---

## Setup Instructions

### 1. General Hardware Setup

Before using this example, ensure your **Axel board is connected properly**. Please refer to **`./docs/hardware_setup.md`** for general setup instructions.

---

### 2. Connecting the Axel Controller

To run this example, follow these steps:

1. **Power the Board:**
   - Ensure that the Axel controller is connected to a **suitable power source**.
2. **Connect USB-C:**
   - Connect **USB-C** to your computer to enable **serial logging and debugging** (if needed).
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

---

### 3. Configure `#define` Values in `main.cpp`

Before building, you can modify the **blink interval** by adjusting the delay values inside `main.cpp`:

```cpp
#define BLINK_DELAY 500 // Change to modify blink rate
```

---

## Building and Running the Example

### 1. Build the Project

In the terminal, navigate to the project directory and run:

```sh
pio run
```

### 2. Upload the Firmware

```sh
pio run --target upload
```

### 3. Monitor Serial Output (Optional)

Although this example does not include serial logging, you can open a serial monitor to confirm board activity:

```sh
pio device monitor -b 115200
```

---

## Expected Output

- The **onboard LED** (connected to `PA2`) should continuously **blink** at a 1-second interval (500ms ON, 500ms OFF).
- If the LED is not blinking, check:
  - Power supply.
  - Upload method (SWD or DFU).
  - Correct PlatformIO configuration.

---

This example provides a simple way to test GPIO functionality on Axel. If the LED is blinking, your board is working correctly! 🚀


