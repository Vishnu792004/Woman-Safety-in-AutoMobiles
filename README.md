## 🚨 Women Safety in Automobiles

## 👨‍💻 Author Details

**Vishnu A**

🎓 **B.Tech – Electronics & Communication Engineering (ECE)**

💻 **Current Learning: Embedded Systems**

📫 **Connect With Me**
LinkedIn: [linkedin.com/in/vishnua2004](https://www.linkedin.com/in/vishnua2004?utm_source=chatgpt.com)

---

## 🚀 About the Author

I am an Electronics & Communication Engineering student with a strong interest in **Embedded Systems, IoT, and Microcontroller Programming**.

I enjoy developing practical hardware and software projects using microcontrollers such as **ESP32, Arduino, ESP8266, and STM32**.

This **Women Safety in Automobiles** project is one of my practical embedded-system projects, developed using **ESP32, GPS, GSM, an emergency push button, buzzer, and LCD** to provide location-based emergency alerts.

I am continuously improving my skills in **Embedded C/C++, microcontroller programming, communication protocols, hardware interfacing, and embedded system design**.

---

## 📌 Project Overview

**Women Safety in Automobiles** is an ESP32-based emergency alert system designed to provide a quick and reliable way to send an emergency alert during dangerous situations.

When the user presses the **SOS emergency button**, the ESP32 activates the buzzer, obtains the user's current location using the **GPS module**, and sends an emergency SMS through the **GSM module**.

The SMS contains the user's location, which can be used with **Google Maps** to identify the current position.

---

## 🎯 Objectives

* Provide a simple emergency alert mechanism.
* Detect emergency button activation quickly.
* Obtain the user's GPS location.
* Process GPS latitude and longitude.
* Send an emergency SMS through GSM.
* Provide an audible alert using a buzzer.
* Display system status using an LCD.
* Develop a practical safety solution for automobile applications.

---

## ⚙️ System Operation

```text
        ┌─────────────────────┐
        │       User          │
        └──────────┬──────────┘
                   │
                   ▼
        ┌─────────────────────┐
        │   SOS Push Button   │
        └──────────┬──────────┘
                   │
                   ▼
        ┌─────────────────────┐
        │        ESP32        │
        │  Main Controller    │
        └──────┬────────┬─────┘
               │        │
          GPS Data     Buzzer
               │        │
               ▼        ▼
        ┌──────────┐   Alert
        │   GPS    │
        │  Module  │
        └────┬─────┘
             │
             ▼
     Latitude & Longitude
             │
             ▼
        ┌─────────────┐
        │ GSM Module  │
        └──────┬──────┘
               │
               ▼
      Emergency SMS Alert
      + Google Maps Link
```

---

## 🔄 Working Principle

### 1. Normal Condition

The ESP32 initializes the GPS, GSM, LCD, and buzzer and waits for the user to press the SOS button.

### 2. SOS Button Press

When the SOS button is pressed:

* ESP32 detects the button press.
* Buzzer is activated.
* GPS data is read.
* Current latitude and longitude are obtained.

### 3. GPS Location Processing

The GPS module provides NMEA data containing location information.

The ESP32 processes the GPS data and extracts:

```text
Latitude
Longitude
```

### 4. Emergency SMS

The ESP32 prepares an emergency message containing the location and sends it through the GSM module to the predefined emergency contact.

The location can be shared using a Google Maps link.

---

## 🛠️ Hardware Components

| Component       | Purpose                    |
| --------------- | -------------------------- |
| ESP32           | Main microcontroller       |
| GPS Module      | Obtains current location   |
| GSM Module      | Sends emergency SMS        |
| SOS Push Button | Emergency activation       |
| Buzzer          | Emergency alert indication |
| 16×2 I2C LCD    | Displays system status     |
| Jumper Wires    | Circuit connections        |
| Power Supply    | Powers the system          |

---

## 💻 Software & Technologies

* **Arduino IDE**
* **Embedded C/C++**
* **ESP32**
* **GPS NMEA Protocol**
* **UART / Serial Communication**
* **GSM AT Commands**
* **I2C LCD**
* **GPS Data Processing**

---

## 🔌 ESP32 Pin Configuration

| Component  | ESP32 Pin |
| ---------- | --------- |
| SOS Button | GPIO 25   |
| Buzzer     | GPIO 13   |
| GPS RX     | GPIO 16   |
| GPS TX     | GPIO 17   |
| GSM RX     | GPIO 26   |
| GSM TX     | GPIO 27   |
| LCD        | I2C       |

---

## 🚨 Emergency Alert Flow

```text
              START
                │
                ▼
       Initialize ESP32
                │
                ▼
       Initialize GPS & GSM
                │
                ▼
        System Ready
                │
                ▼
      Monitor SOS Button
                │
          Button Pressed?
           ┌────┴────┐
          NO        YES
           │          │
           │          ▼
           │    Activate Buzzer
           │          │
           │          ▼
           │    Read GPS Data
           │          │
           │          ▼
           │ Extract Latitude
           │ & Longitude
           │          │
           │          ▼
           │ Prepare SMS
           │          │
           │          ▼
           │ Send Through GSM
           │          │
           │          ▼
           └──── System Ready
```

---

## 📍 GPS Location

The GPS module provides NMEA sentences containing location information.

Example:

```text
$GPGGA,...
```

The ESP32 extracts:

```text
Latitude
Longitude
```

These coordinates are then used to create a location link that can be opened using Google Maps.

---

## ⭐ Key Features

* ✅ SOS emergency button
* ✅ GPS-based location tracking
* ✅ GSM-based SMS alert
* ✅ Google Maps location link
* ✅ Buzzer emergency indication
* ✅ LCD status display
* ✅ ESP32-based system
* ✅ UART communication
* ✅ GPS NMEA data processing
* ✅ Designed for automobile safety

---

## 🧠 Skills Demonstrated

This project helped demonstrate practical experience in:

* Embedded C/C++
* ESP32 programming
* GPS interfacing
* GSM interfacing
* UART communication
* I2C communication
* GSM AT commands
* GPS NMEA protocol
* Hardware interfacing
* Microcontroller programming
* Debugging and troubleshooting
* Embedded system design

---

## 🚀 Future Improvements

The project can be further enhanced by adding:

* 📱 Mobile application integration
* 🌐 IoT-based emergency monitoring
* 📍 Real-time live location tracking
* 📲 Multiple emergency contacts
* 📷 ESP32-CAM integration
* ☁️ Cloud-based monitoring
* 🆘 Automatic accident detection
* 🔋 Battery monitoring
* 🔊 Voice-based emergency alerts

---

## 👨‍💻 Developer

**Vishnu A**

**B.Tech – Electronics & Communication Engineering (ECE)**

**Embedded Systems | IoT | ESP32 | STM32 | Embedded C**

📫 **LinkedIn:** [linkedin.com/in/vishnua2004](https://www.linkedin.com/in/vishnua2004?utm_source=chatgpt.com)

---

## ⭐ Project Purpose

This project was developed as a practical embedded-system solution to demonstrate how **ESP32, GPS, GSM, an emergency button, buzzer, and LCD** can be integrated to create a simple emergency safety system for automobile applications.

If you find this project useful, consider giving the repository a ⭐.

---

## 📜 License

This project is intended for **educational and learning purposes**.
