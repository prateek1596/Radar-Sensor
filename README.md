# Radar Sensor Project

## 📡 Overview

This project uses a radar sensor to detect the presence, speed, and distance of objects within its range. It's ideal for applications like motion tracking, speed detection, object avoidance, and smart surveillance.

## 🚀 Features

- Detects object motion and speed.
- Measures distance from the sensor to the object.
- Real-time data output via serial or display.
- Low-power and compact setup.

## 🛠️ Hardware Used

- Radar Sensor Module 
- Microcontroller (e.g., Arduino UNO / ESP32 / Raspberry Pi)
- Jumper wires
- Breadboard
## 📦 Software Requirements

- Arduino IDE / Python (depending on your setup)
- Serial monitor or terminal for viewing data
- Libraries:
  - `Adafruit_SSD1306` (if using OLED)
  - `Wire.h` (for I2C communication)

## 🔌 Wiring Diagram

| Radar Sensor Pin | Microcontroller Pin |
|------------------|----------------------|
| VCC              | 3.3V / 5V            |
| GND              | GND                  |
| OUT              | Digital Pin (e.g., D2) |

> Note: Some modules may also have CDS or VIN pins.

## 📄 How It Works

- The radar sensor emits microwave signals.
- When an object moves in its field, the sensor detects the Doppler shift.
- Output signal changes (HIGH/LOW) depending on detection.
- Data is processed to calculate motion and optionally display or log it.
