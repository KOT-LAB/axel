# Axel Examples  

This directory contains example projects demonstrating various control modes and functionalities of the Axel controller. Each example is organized as a standalone **[PlatformIO](https://platformio.org/)** project on the **[Arduino framework](https://docs.platformio.org/en/latest/frameworks/arduino.html)**, making it easy to compile and upload to the board.  

---

## Structure  

Each example follows the standard **[PlatformIO](https://platformio.org/)** project structure:  

```
example/
├── src/                   # Source code files
├── include/               # Header files
├── lib/                   # External libraries (e.g., SimpleFOC)
├── platformio.ini         # Project configuration file
└── README.md              # Description of the example
```

---

## Available Examples  

- `blink`  
- `basic_position_control`  
- `basic_velocity_control`  
- `basic_torque_control`  
- `advanced_position_control`  

Each example has its own `README.md` with details on functionality, usage, and expected behavior.  

---

## Getting Started  

1. Open an example directory in PlatformIO.  
2. Refer to the example-specific README for configuration and usage details.  
3. Build and upload the project to your Axel board.  

---

For more information on using PlatformIO with Axel, refer to the main [firmware/](../firmware/) README.