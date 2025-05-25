# Positions Buses

A C program that reads the position of magnets using a Hall effect sensor connected to an ADC (Analog-to-Digital Converter). The program continuously monitors whether a magnet is present or not, which can be used to track the position of buses or other moving elements.

---

## 📋 Description

This project provides a basic embedded system implementation to detect the presence or absence of a magnetic field using a Hall effect sensor and an ADC. It prints the detection result to the console in real time.

---

## 🧰 Features

- Reads analog values from a Hall effect sensor via ADC
- Compares the reading against predefined thresholds
- Prints whether a magnet is detected or not
- Intended for embedded platforms with memory-mapped I/O

---

## 📁 File Structure

```
.
├── QuestionnerPositionsBuses.c   # Main logic for reading and processing the Hall sensor
└── QuestionnerPositionsBuses.h   # Definitions and constants for ADC and thresholds
```

---

## 🔧 Configuration

- `HALL_SENSOR_PIN`: ADC channel used for the Hall sensor input (e.g., 25)
- `SEUIL_BAS`: Threshold below which no magnet is detected
- `SEUIL_HAUT`: Threshold above which a magnet is considered detected

You can adjust these values in `QuestionnerPositionsBuses.h` to calibrate for your specific hardware.

---

## ⚙️ How It Works

1. **ADC Initialization**
   - Sets the ADC to read from the specified Hall sensor pin.

2. **Reading Process**
   - Continuously polls the ADC result register until conversion is complete.

3. **Detection Logic**
   - If the result is below `SEUIL_BAS`, no magnet is detected.
   - If the result is above `SEUIL_HAUT`, a magnet is detected.
   - Between the two thresholds, it is treated as "no magnet".

4. **Output**
   - Prints to the console either:
     - `Pas d'aimant détecté`
     - `Aimant détecté`

---

## 🧪 Example Output

```text
Aimant détecté
Pas d'aimant détecté
Pas d'aimant détecté
Aimant détecté
```

---

## 🛠️ Platform Requirements

- C compiler
- Embedded platform or simulation environment that supports memory-mapped I/O
- Hall effect sensor connected to an ADC-capable pin

---

## 📌 Notes

- The ADC addresses (`0x4003B000` and `0x4003B004`) are **example addresses** and may need to be updated depending on your microcontroller or platform.
- You must link this program with hardware-specific startup and peripheral libraries when deploying on a real embedded system.

---

## 📝 License

This project is provided for educational and development purposes. Free to use and modify.
