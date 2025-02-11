## 🚀 Getting Started with Axel

Axel is designed for seamless development using [PlatformIO](https://platformio.org/), a powerful ecosystem for embedded development. All software-related aspects of Axel—including the base firmware, examples, and hardware tests—are structured as **PlatformIO projects** for ease of use.

Follow these steps to set up your development environment and get started with Axel.

---

### 1️⃣ **Get Axel**

Get your Axel on **[Emotor.Market](https://emotor.market/)**.

---

### 2️⃣ **Prepare Your Hardware**

Before flashing firmware or running any tests, ensure your hardware is correctly assembled:

1. **Solder the Motor Phase Wires**

   - Axel has **three motor output phases** labeled **A, B, and C**.
   - Solder these to the appropriate motor wires—typically, BLDC motors have three wires corresponding to these phases.
   - If the motor spins in the wrong direction later, simply swap **any two** of the three phase connections.

2. **Check Power Connections**

   - Ensure your power supply matches **Axel’s voltage range (10-54V)**.
   - Double-check polarity before connecting.

---

### 3️⃣ **Set Up Your Development Environment**

1. **Install PlatformIO**\
   👉 Follow the installation steps in **[docs/simplefoc_support.md](simplefoc_support.md)**.

2. **Clone the Axel Repository**

   ```bash
   git clone https://github.com/KOT-LAB/axel.git
   cd axel
   ```

---

### 4️⃣ **Understanding the Project Structure**

**Axel organizes all software as **PlatformIO projects**, including:**

- `firmware/` – The base firmware for Axel.
- `examples/` – Example projects demonstrating different control modes.
- `tests/` – Hardware tests for debugging.

**A key file used across all projects is:**

- `pinout.h` (found in `firmware/`) – Defines Axel's hardware pin mappings. Always include this in your projects.

---

### 5️⃣ **Run Your First Test: Blinking an LED**

The simplest way to check if your board is functioning is to run the **Blink** example.

1. **Navigate to the example directory:**

   ```bash
   cd examples/blink
   ```

2. **Build and upload the code to your board:**

   ```bash
   pio run --target upload
   ```

4. **Check the LED** – If the LED blinks, your board is ready!

---

### 6️⃣ **Exploring SimpleFOC Examples**

Axel is fully compatible with **[SimpleFOC](https://github.com/simplefoc/Arduino-FOC)**, a popular BLDC motor control library. Before developing your own firmware, review these examples:

1. **Go to the [SimpleFOC repositry](https://github.com/simplefoc/Arduino-FOC).**

2. **Study the example codes**:

   - Open-loop control
   - Torque, velocity, and position control modes
   - Sensor-based feedback examples

---

### 7️⃣ **Run Your First BLDC Control Example**

To start with BLDC motor control, use the **Basic Torque Control** example.

1. **Navigate to the directory:**

   ```bash
   cd examples/basic_torque_control
   ```

2. **Carefully review the `README.md` to understand and set up the example.**

3. **Compile and upload the code:**

   ```bash
   pio run --target upload
   ```

---

### 8️⃣ **Next Steps**

Once comfortable with the basics, explore:
👉 **Firmware Customization** – Modify the `firmware/` and see what happens.
👉 **Advanced Control Modes** – Implement closed-loop control using encoders.
👉 **CAN, SPI, and UART Communication** – Develop multi-board applications.

For further details, visit the respective README files in `firmware/`, `examples/`, and `tests/`.

> **Note:** `firmware/` and `examples/` are still in development. Check out the **[Project Status](#📊-project-status)** section for the latest updates.

---

### 9️⃣ Start Your Own Firmware: Develop and **Have Fun!**

---



