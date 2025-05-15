# BREAVO Smart Alcohol Detector: Hardware Components

This document provides detailed information about the hardware components used in the BREAVO Smart Alcohol Detection and Warning System.

## Components List

| Component | Quantity | Description | Purpose |
|-----------|----------|-------------|---------|
| Arduino Uno R3 | 1 | Microcontroller board based on the ATmega328P | Main processing unit |
| MQ-3 Gas Sensor | 1 | Alcohol gas detector | Detects alcohol concentration in breath |
| LCD Display 16x2 | 1 | 16 columns x 2 rows character LCD | Displays system information and results |
| I2C LCD Interface Module | 1 | I2C adapter for LCD | Reduces pin usage and simplifies connections |
| LED (Green) | 1 | 5mm Green LED | Visual indicator for "PASS" result |
| LED (Red) | 1 | 5mm Red LED | Visual indicator for "FAIL" result |
| Buzzer | 1 | 5V active buzzer | Audio alert for "FAIL" result |
| 9V Battery | 1 | Standard 9V battery | Power supply |
| 9V Battery Connector | 1 | Battery clip with wires | Connects battery to Arduino |
| Resistors (220Ω) | 2 | 220 ohm resistors | Current limiting for LEDs |
| Resistor (4.7kΩ) | 2 | 4.7 kilohm resistors | Pull-up resistors for I2C |
| Breadboard | 1 | Standard solderless breadboard | Prototyping platform |
| Jumper Wires | ~20 | Male-to-male jumper wires | Connections between components |

## Component Specifications

### Arduino Uno R3
- Microcontroller: ATmega328P
- Operating Voltage: 5V
- Input Voltage (recommended): 7-12V
- Digital I/O Pins: 14 (of which 6 provide PWM output)
- Analog Input Pins: 6
- DC Current per I/O Pin: 20 mA
- Clock Speed: 16 MHz
- Flash Memory: 32 KB (0.5KB used by bootloader)
- SRAM: 2 KB
- EEPROM: 1 KB

### MQ-3 Alcohol Sensor
- Operating Voltage: 5V DC
- Current Consumption: 150mA
- Detection Range: 0.04mg/L to 4mg/L (alcohol)
- Response Time: <10 seconds
- Operating Temperature: -10°C to 50°C
- Pins: VCC, GND, Analog output, Digital output
- Sensitivity Adjustment: Potentiometer on the module

### LCD Display with I2C Module
- Display: 16 characters x 2 lines
- Operating Voltage: 5V DC
- I2C Interface: 4-pin (VCC, GND, SDA, SCL)
- Default I2C Address: 0x27 (may vary)
- Backlight: Blue with white text
- Dimensions: 80mm x 36mm x 12mm

### LEDs and Buzzer
- LEDs: Standard 5mm, forward voltage 2V, max current 20mA
- Buzzer: Active 5V buzzer, sound output >85dB, frequency ~2300Hz

## Pin Connections

| Component | Arduino Pin | Notes |
|-----------|-------------|-------|
| MQ-3 Sensor | A0 | Analog input |
| I2C LCD | A4 (SDA) | Serial Data Line |
| I2C LCD | A5 (SCL) | Serial Clock Line |
| Green LED | D6 | With 220Ω resistor |
| Red LED | D7 | With 220Ω resistor |
| Buzzer | D5 | Direct connection |

## Power Requirements

- Input Voltage: 9V (from battery)
- Total Current Consumption: ~200mA
- Estimated Battery Life: ~5 hours with standard 9V alkaline battery

## Enclosure Recommendations

- Dimensions: At least 120mm x 80mm x 40mm
- Material: ABS plastic or 3D printed PLA
- Features:
  - Opening for the MQ-3 sensor to allow breath contact
  - Transparent window for LCD visibility
  - Access port for power switch
  - Ventilation holes for sensor accuracy
  - Battery compartment
  
## Assembly Notes

1. The MQ-3 sensor requires a warm-up period of 1-2 minutes for accurate readings.
2. Place the buzzer and LEDs in visible locations for effective alerts.
3. Ensure proper ventilation around the MQ-3 sensor for accurate readings.
4. Position the alcohol sensor in a way that makes it easy for the user to blow into it.
5. Consider adding a power switch between the battery and Arduino for convenience.

## Future Hardware Upgrades

- Replace breadboard with custom PCB for reliability
- Add Bluetooth module (HC-05/HC-06) for wireless connectivity
- Implement LiPo battery with charging circuit for rechargeable operation
- Add SD card module for data logging capabilities
- Integrate RTC (Real-Time Clock) module for timestamp recording