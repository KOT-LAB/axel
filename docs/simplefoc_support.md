# SimpleFOC Support for Axel

## 🔗 **Compatibility with SimpleFOC**

Axel is fully compatible with **[SimpleFOC](https://github.com/simplefoc/Arduino-FOC)**, a popular open-source library for BLDC motor control. This compatibility allows you to:

- **Simplify Development:** Leverage SimpleFOC’s high-level APIs to control motors without deep expertise in BLDC control algorithms.
- **Quick Start:** Run example projects with minimal setup using pre-configured SimpleFOC code.
- **Flexible Customization:** Modify and extend firmware easily, thanks to SimpleFOC’s modular design.

This integration makes Axel the perfect choice for both beginners and advanced developers working on BLDC projects.

---

## ⚙️ Why it works?

All the main components of Axel are fully supported by SimpleFOC:

- **Motor Driver: TI DRV8302**

  - Supported by SimpleFOC for three-phase motor control.
  - More here: **[DRV8302 SimpleFOC Example](https://docs.simplefoc.com/drv8302_example)**.

- **Encoder: AS5047P**

  - A high-resolution magnetic encoder with full compatibility.
  - More here: **[SimpleFOC AS5047 Driver](https://github.com/simplefoc/Arduino-FOC-drivers/tree/master/src/encoders/as5047)**.

- **Microcontroller: STM32F446RE**

  - Supported by SimpleFOC using the STM32 Arduino framework.
  - More here: **[SimpleFOC MCU Support](https://docs.simplefoc.com/stm32\_mcu)**

---

## 🚀 **Getting Started with SimpleFOC**

#### To begin using SimpleFOC with Axel, follow these steps:

##### 1. Installation in Arduino IDE

1. Open **Arduino IDE** and navigate to **Sketch > Include Library > Manage Libraries**.
2. Search for **SimpleFOC** in the Library Manager.
3. Click **Install** on the latest version.

For more details, refer to the **[SimpleFOC Library Download Guide](https://docs.simplefoc.com/library_download)**.

##### 2. Installation in PlatformIO**

1. Open **PlatformIO** in VS Code.
2. In **platformio.ini**, add the following line:
   ```ini
   lib_deps = SimpleFOC
   ```
3. Save the file and run a build to install the library.

For more details, refer to the **[SimpleFOC PlatformIO Guide](https://docs.simplefoc.com/library_platformio)**.

---

## 📖 **Understanding SimpleFOC**

We also encourage you to study **[SimpleFOC's documentation](https://docs.simplefoc.com/)**, particularly the **[Theory Corner](https://docs.simplefoc.com/theory_corner)**, to gain deeper insights into motor control principles.

---

## 🛠 **Working with Axel**

Now that SimpleFOC is installed, explore the `examples/` directory to see practical implementations of BLDC motor control with Axel.

---

## 🔗 **Additional Resources**

- **[SimpleFOC Documentation](https://docs.simplefoc.com/)**
- **[SimpleFOC GitHub Repository](https://github.com/simplefoc/Arduino-FOC)**



