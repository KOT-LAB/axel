# Axel Basic Firmware

Welcome to the **Axel Firmware** directory! This firmware serves as a **foundation** for developing custom BLDC motor control applications using the Axel controller.

---
## ⚠️ Announcement

**In January 2025, we decided to turn Axel from a solely hardware project into a software one as well.** Now, we've started actively working on `/tests`, `/examples`, and `/firmware`. Expect first commits in February!

Currently, we are resolving a **major hardware bug** that was recently discovered. Once this issue is resolved, we will implement the basic firmware according to its description in this file. Development is actively ongoing!

---

## 🚀 Overview

This **basic firmware** is organized as a **[PlatformIO](https://platformio.org/)** project, making it easy to build, upload, and manage dependencies across different development environments. 

For simplicity and ease of development, this firmware is based on **[SimpleFOC](https://github.com/simplefoc/Arduino-FOC)**, a widely-used open-source library for BLDC motor control. Learn more about Axel's compatibility with SimpleFOC [docs/simplefoc_support.md](../docs/simplefoc_support.md).

This **"basic" firmware** aims to:

- Provide **basic motor control functionality** out of the box.
- Ensure the **board operates correctly** with minimal configuration.
- Serve as a **starting point** for custom firmware development.

---

## ⚙️ Features

- **Motor Control:** implements control in position, velocity, and torque modes.
- **Sensor Integration:** uses on-board encoder.
- **Communication Interfaces:** uses CAN FD as a main control bus and can be configured via USB-C for your specific setup.
- **SimpleFOC Integration:** Easy-to-understand APIs for rapid development.

---

## 📂 Directory Structure

```
firmware/
├── src/                   # Source code files
├── include/               # Header files
├── lib/                   # External libraries (SimpleFOC, etc.)
├── platformio.ini         # Project configuration file (PlatformIO)
└── README.md              # This file
```

---

## ⚡ Getting Started

1. **Review our basic getting started guide at [docs/getting_started.md](../docs/getting_started.md)**.

2. **Clone the Repository:**
   ```bash
   git clone https://github.com/KOT-LAB/axel.git
   cd axel/firmware
   ```
3. **Build and Upload:**
   ```bash
   pio run --target upload
   ```

---

## 📚 Documentation

- **Axel Hardware Documentation:** Refer to the `/docs` directory in the main repository.
- **SimpleFOC Documentation:** [https://docs.simplefoc.com/](https://docs.simplefoc.com/)

---

## 🤝 Contributions

We welcome contributions to improve the firmware. Check out the main [CONTRIBUTING.md](../CONTRIBUTING.md) for guidelines.

---

*Happy hacking and motor controlling with Axel!*

