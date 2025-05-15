# BREAVO: Smart Alcohol Detection and Warning System

![BREAVO Device](https://raw.githubusercontent.com/nminhducit/breavo/main/docs/images/banner.png)

## 📋 Overview

BREAVO is an IoT-based Smart Alcohol Detection and Warning System designed to enhance traffic safety by providing accurate blood alcohol concentration (BAC) measurements through breath analysis. The system offers real-time feedback with intuitive visual and audio alerts when alcohol levels exceed legal limits.

## 🔍 Key Features

- **Real-time BAC Measurement**: Uses MQ-3 alcohol sensor for accurate breath analysis
- **Intuitive Interface**: LCD display shows real-time results with clear PASS/FAIL indication
- **Visual & Audio Alerts**: LED indicators and buzzer alarm when BAC exceeds legal threshold
- **Quick Response Time**: Complete measurement cycle in under 15 seconds
- **Portable Design**: Compact and battery-powered for on-the-go use

## 🖼️ Project Gallery

<table>
  <tr>
    <td><img src="https://raw.githubusercontent.com/nminhducit/breavo/main/docs/images/device-standby.png" alt="Standby Mode" width="300"/></td>
    <td><img src="https://raw.githubusercontent.com/nminhducit/breavo/main/docs/images/device-pass.png" alt="Pass Result" width="300"/></td>
    <td><img src="https://raw.githubusercontent.com/nminhducit/breavo/main/docs/images/device-fail.png" alt="Fail Result" width="300"/></td>
  </tr>
</table>

## 🛠️ Hardware Components

- Arduino Uno R3
- MQ-3 Alcohol Sensor
- 16x2 LCD Display with I2C Adapter
- Red and Green LEDs
- Buzzer
- 9V Battery with Connector
- Jumper Wires and Breadboard

## 📊 System Design

The system operates following this workflow:

1. **Initialization**: Warms up the MQ-3 sensor for optimal performance
2. **Standby Mode**: Waits for breath detection with "READY TO TEST" display
3. **Measurement**: Captures and processes BAC readings when breath is detected
4. **Result Display**: Shows "PASS" or "FAIL" with corresponding LEDs/alarms
5. **Reset**: Returns to standby mode after displaying results

![System Flowchart](https://raw.githubusercontent.com/nminhducit/breavo/main/docs/images/flowchart.png)

## ⚡ Circuit Diagram

The hardware connections follow this schematic:

![Circuit Diagram](https://raw.githubusercontent.com/nminhducit/breavo/main/docs/images/circuit-diagra.png)

## 🧪 Performance and Testing

The system has been tested under various conditions to ensure accuracy and reliability:

- **Calibration Tests**: Baseline established after sensor warm-up
- **Low Alcohol Tests**: System correctly identifies BAC below legal threshold
- **High Alcohol Tests**: System accurately detects BAC above legal threshold
- **Response Time**: Less than 2 seconds after breath detection

## 📁 Repository Structure

```
breavo/
├── src/                    # Source code
│   └── main.ino            # Main Arduino sketch
├── hardware/               # Circuit diagrams and hardware specifications
│   ├── circuit_diagram.png
│   └── parts_list.md
├── docs/                   # Documentation
│   ├── images/             # Project images
│   └── report/             # Detailed project report
└── LICENSE                 # License information
```

## 🚀 Getting Started

### Prerequisites

- Arduino IDE (v1.8.x or higher)
- Arduino Uno or compatible board
- Required libraries:
  - Wire.h
  - LiquidCrystal_I2C.h

### Installation

1. Clone this repository:
   ```
   git clone https://github.com/nminhducit/breavo.git
   ```

2. Open the Arduino IDE and load the main sketch:
   ```
   File > Open > [path_to_repository]/src/main.ino
   ```

3. Install required libraries through Arduino IDE:
   ```
   Sketch > Include Library > Manage Libraries...
   ```
   Search for and install:
   - LiquidCrystal I2C by Frank de Brabander

4. Connect your Arduino board and upload the sketch:
   ```
   Sketch > Upload
   ```

5. Assemble the hardware according to the circuit diagram

## 📝 Usage Instructions

1. Power on the device
2. Wait for "READY TO TEST" to appear on the LCD
3. Blow steadily into the MQ-3 sensor for 3-5 seconds
4. View the result on the LCD display:
   - Green LED indicates alcohol level below legal limit
   - Red LED and buzzer indicate alcohol level above legal limit

## ⚠️ Calibration

For optimal performance, the device should be calibrated periodically:

1. Power on the device in a clean-air environment
2. Allow the sensor to warm up for 5 minutes
3. The baseline will be automatically established

## 🔮 Future Enhancements

- IoT connectivity for remote monitoring
- Mobile app integration
- Data storage and analysis capabilities
- Enhanced power management for longer battery life
- Compact enclosure design

## 👥 Contributors

- Nguyen Minh Duc (HE180274)
- Nguyen Tung Duong (HE180156)
- Nguyen Quoc Anh (HE180898)

## 📄 License

This project is licensed under the MIT License - see the [LICENSE](LICENSE) file for details.

## 📚 Related Resources

- [Project Report](docs/report/REPORT_IOT102_SP25-EN.pdf)
- [Traffic Safety Statistics](https://example.com/traffic-safety-stats)
- [MQ-3 Sensor Datasheet](https://example.com/mq3-datasheet)

---

*This project was developed as part of the IoT102 course at FPT University, supervised by Dr. Nguyen Van Toan.*