# Hardware Setup for Axel

This guide provides instructions on setting up Axel for running examples, basic firmware, and tests. Following this setup ensures proper functionality and helps users integrate Axel into their own projects.

---

## Mounting Axel

Axel can be used in two configurations:

1. **Attached to the Back of the Motor** – Ideal for compact setups where Axel is mounted directly on the motor.
2. **Placed Remotely from the Motor** – Allows flexibility in placement, though an external encoder may be required if necessary for the desired control mode.

---

## General Setup

1. **Solder the Motor Phase Wires**

   - Axel has **three motor output phases** labeled **A, B, and C**.
   - Solder these to the appropriate motor wires—typically, BLDC motors have three wires corresponding to these phases.
   - If the motor spins in the wrong direction later, simply swap **any two** of the three phase connections.

2. **Check Power Connections**

   - Ensure your power supply matches **Axel’s voltage range (10-54V)**.
   - Double-check polarity before connecting.


---

## Encoder Setup

In our `examples/`, `firmware/`, and `tests/`, we utilize the onboard **AS5047P** magnetic encoder. Users must ensure the following setup:

- A **motor** with a **diametrically polarized magnet** mounted on its output shaft.
- The **magnet should be positioned at a distance of approximately 2mm from the encoder**.
- Proper alignment of the magnet and encoder is crucial – they should be directly on top of each other.
- A misalignment margin of about **1-2mm is acceptable but should be minimized** for optimal performance.

---

By following these guidelines, users can ensure accurate motor control and a stable setup for testing and development with Axel.

> **Note:** `/firmware` and `/examples` are still in development. Check out the [Project Status](#📊-project-status) section for the latest updates.


