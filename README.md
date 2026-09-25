# 🚗 V2V Accident Alert System

An Arduino-based Vehicle-to-Vehicle (V2V) communication system that detects possible vehicle accidents using an **MPU6050 accelerometer/gyroscope** and **SW-420 vibration sensor**, then wirelessly sends an alert to another vehicle using a **433 MHz RF module**.

## 🔧 Components Used

* Arduino Uno
* Arduino Nano
* MPU6050
* SW-420 vibration sensor
* 433 MHz RF Transmitter
* 433 MHz RF Receiver
* 16×2 I2C LCD
* Buzzer
* LED
* Resistors
* Breadboards
* Jumper wires

## ⚙️ Working

### Transmitter

1. MPU6050 measures the vehicle's tilt angle.
2. SW-420 detects vibration.
3. The Arduino calculates the roll angle.
4. If vibration is detected and the angle exceeds **35°**, the system generates an accident alert.
5. The alert is transmitted using the 433 MHz RF transmitter.

### Receiver

1. The RF receiver receives the transmitted message.
2. The Arduino extracts the status and angle.
3. The LCD displays:

   * `STATUS: ALERT`
   * `STATUS: NORMAL`
   * Detected angle

## 📡 Communication Format

The transmitter sends data in the following format:

```text
A,45
```

`A` = Accident/Alert

or

```text
N,10
```

`N` = Normal

The second value represents the detected angle.

## 🚨 Accident Detection Logic

```text
IF vibration detected
        +
   |angle| > 35°
        ↓
      ALERT
        ↓
433 MHz RF Transmission
        ↓
     Receiver
        ↓
      LCD
```

Otherwise:

```text
NORMAL
```

## 🧠 Concepts Demonstrated

* Embedded C / Arduino programming
* I2C communication
* MPU6050 interfacing
* Sensor integration
* RF wireless communication
* LCD interfacing
* Angle calculation
* Conditional decision making
* Serial communication
* Embedded system design

## 📌 Libraries Used

* `Wire.h`
* `MPU6050.h`
* `RH_ASK.h`
* `SPI.h`
* `LiquidCrystal_I2C.h`

## 🔌 Main Connections

### MPU6050 → Arduino

| MPU6050 | Arduino |
| ------- | ------- |
| VCC     | 5V      |
| GND     | GND     |
| SDA     | A4      |
| SCL     | A5      |

### SW-420

| SW-420 | Arduino |
| ------ | ------- |
| VCC    | 5V      |
| GND    | GND     |
| DO     | D2      |

### RF Transmitter

The RF transmitter uses the **RH_ASK default TX pin (D12)**.

### RF Receiver

The receiver program uses:

```cpp
RH_ASK rf_driver(2000, 2);
```

Therefore, the RF receiver data pin is connected to **D2**.

## 📊 Example Output

```text
STATUS: ALERT
ANGLE: 47
```

or

```text
STATUS: NORMAL
ANGLE: 12
```

## 🚀 Future Improvements

* Add GPS for vehicle location
* Add emergency vehicle priority
* Add blind-spot detection
* Add road-hazard sharing
* Add buzzer-based emergency warning
* Add vehicle identification/authentication
* Add voice alerts
* Upgrade from basic RF to a more robust communication system

## 👨‍💻 Project Type

**Embedded Systems / IoT / V2V Communication**

Built using Arduino, sensors and wireless RF communication.
