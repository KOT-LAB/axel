# Axel: Your framework for custom BLDC motor controller

![Axel Board](docs/images/readme.png)  

---

## 🚀 What is Axel?

Axel is an **open-source BLDC motor controller** designed to empower makers, enthusiasts, and researchers. It's a versatile hardware framework for developing custom firmware tailored to your specific application. Think of it as your "**Arduino for BLDC motor control**," combining flexibility, user-friendliness, and powerful performance to support a wide range of projects for both beginners and professionals.

### **Key Advantages:**
- **Flexibility In Motor-Controller Setup:** Features a built-in encoder for direct mounting on the motor and also supports external encoders.
- **Built-in Current Sensing:** Enables true Field-Oriented Control (FOC) for precise and efficient motor control.
- **High-Performance:** Based on the STM32 and a powerful gate driver with external MOSFETs, meets demands of any application.
- **Extensive Connectivity:** Has all most popular interfaces on board, makes the integration with your application seamless.
- **Full compatibility with SimpleFOC:** Makes it easy to start for beginners and enables rapid development for professionals.
- **Flexible Development:** Write your own firmware from scratch to maximize performance, or customize our basic firmware and leverage full SimpleFOC compatibility for rapidness.
- **Beginner-Friendliness:** SimpleFOC support, clear documentation, basic firmware that works out of the box, and an extensive set of examples make getting started easy.

### Applications

- **Legged Robots:** High-speed and high-precision motion control for dynamic robotics.
- **Exoskeletons:** Reliable torque and speed control for assistive devices.
- **Electric Vehicles:** Scalable design for mobility solutions.
- **CNC Machines & 3D Printers:** Precise control in automated manufacturing.
- **Anything else:** The only limit is your imagination!

### **Is Axel for you?**

- **Enthusiasts**: Power *any project* with a *versatile* and *high-performance* BLDC motor controller that’s easy to integrate and customize.
- **Researchers**: Explore cutting-edge motor control concepts with a platform designed for *experimentation and innovation*. Axel provides a *powerful framework* for developing, testing, and iterating on new ideas.
- **Startups**: Jump straight into developing a *tailor-made solution* for your application. No need to set up manufacturing. Its *rich base of examples* and *SimpleFOC support* make firmware development easy and efficient.
- **Enterprises**: Minimize *external dependencies* by building your *custom in-house solution* on Axel. Perfect for *fast internal development* and *prototyping* before committing to large-scale designs.

---

## 📈 Project Status

**In January 2025, we decided to turn Axel from a solely hardware project into a software one as well.** Now, we've started actively working on `/tests`, `/examples`, and `/firmware`. Expect first commits in February!

### **Current Development Stage:**

- **Production Status:** Axel’s production is **currently frozen** due to a recently discovered major hardware bug. We are diligently working to resolve this issue.
- **Example Code Development:** Expanding the `/examples` directory with practical applications and demonstrations.
- **Firmware Development:** Actively working on a basic firmware that serves as a solid foundation for your custom firmware development in `/firmware`.
- **Hardware Tests:** Focused on enriching hardware validation tests to ensure reliable performance in `/tests`.

---

## 📊 Main Parameters

| **Parameter**                   | **Value**                     |
|---------------------------------|-------------------------------|
| **Input Voltage**               | 10-54V                        |
| **Peak Phase Current**          | 100A                          |
| **Peak Electrical Power**       | 3100W                         |
| **Continuous Electrical Power** | 1100W                         |
| **MCU**                         | STM F446RE                    |
| **Driver**                      | TI DRV8302                    |
| **Encoder**                     | AS5047P                       |
| **Interfaces**                  | SPI, I2C, CAN FD, UART, USB-C |
| **Programming interfaces**      | SWD, DFU                      |
| **Dimensions**                  | 50x50x9mm                     |

---

## 🛠️ Dive deeper & How it works

For more in-depth information about Axel, refer to the following documents:

- **[Hardware Details](docs/hardware.md)** – Explore hardware features, the PCB design, schematics, and component choices behind Axel.
- **[SimpleFOC Support](docs/simplefoc_support.md)** – Understand how Axel integrates with SimpleFOC for simplified motor control development.
- **[Getting Started](docs/getting_started.md)** – Begin using Axel with setup instructions, toolchain details, and firmware installation.
- **[Documentation](docs/README.md)** - Learn more about Axel.

These documents provide essential details for both beginners and advanced users who want to make the most of Axel.

---

## 🗂️ Directory Structure

```
Axel/
├── hardware/               # Schematics, PCB layouts, photos, hardware docs, 3D models
│   ├── schematics/         # Circuit diagrams and electrical schematics
│   ├── mechanical/         # 3D models, enclosures, and mounting designs
│   └── media/              # Renders and photos of Axel
├── firmware/               # (coming soon) Base firmware for custom development
├── examples/               # (coming soon) Example code for different control modes
├── tests/                  # (coming soon) Hardware tests
├── utils/                  # Utils for development
├── docs/                   # Additional documentation & images
├── LICENSE                 # MIT License for firmware
├── LICENSE-HARDWARE.md     # CERN-OHL-P License for hardware
└── README.md               # This file
```

---

## 🙏 Credits and Special Thanks

This project wasn't possible without the active members of Axel's team. Special thanks to:

- ***Arsenii Mironov*** - idea, project management, software and setting up manufacturing
- ***Peter Germanovich*** - product management
- ***Andrei Belov*** - electrical engineering
- ***Alina Petrovskaya*** - marketing materials
- ***Richard Unger*** - advising on hardware design
- ***Rostislav Likhogrud*** - general supervision

Axel’s development was inspired by the incredible work of the open-source community. Special thanks to:

- **[MIT Mini Cheetah Controller](https://github.com/bgkatz)** by ***Ben Katz*** – A key reference during Axel’s hardware design.

---

## 🤝 Contribution and Support

We welcome contributions to Axel! Whether it’s code, hardware feedback, or documentation improvements, please check out our **[CONTRIBUTING.md](CONTRIBUTING.md)** to get started.

If you’ve found an issue or have a feature request, feel free to **[open an issue](https://github.com/KOT-LAB/axel/issues)**.

Another great way to support the team and future development is to buy our hardware at **[Emotor.Market](https://emotor.market/)**. Axel will be available again there at the best price once the final bugs are resolved.

---

## 📜 License

Axel is licensed under a dual-license model:

- **Firmware:** Licensed under the **[MIT License](LICENSE)**. This allows for free use, modification, and distribution of the firmware, even for commercial purposes, with proper attribution.
- **Hardware:** Licensed under the **[CERN Open Hardware License (CERN-OHL-P)](LICENSE-HARDWARE.md)**. This ensures that any modifications or derivatives of the hardware design remain open-source.

---

## 📬 Contact

For questions, feedback, or commercial inquiries, reach us at **[made@kot.works](mailto:made@kot.works)**.

---

*Built with passion for makers, innovators, and dreamers. Let Axel power your next big idea!*



