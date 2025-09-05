# Ultrasonic Distance Project 

An Arduino project that measures distance using the **HC-SR04 ultrasonic sensor** and displays the result on a **16x2 LCD**.  
The system also uses an **RGB LED** and a **Buzzer** to give visual and sound feedback about the measured distance.

---

## Features
- 📏 **Distance Measurement**: Accurate measurement from 3 cm to 40 cm.  
- 🖥️ **LCD Display**: Shows live distance readings or "Out of Range".  
- 🌈 **RGB LED Indicator**:  
  - 🔴 Red → 3–10 cm  
  - 🟢 Green → 10–20 cm  
  - 🔵 Blue → 20–30 cm  
  - 🟡 Yellow → 30–40 cm  
  - Buzzer Alert**: Beeps when the object is too close (< 3 cm) or too far (> 40 cm).  

---

## ⚙️ How It Works
1. The ultrasonic sensor sends a pulse and measures the echo time.  
2. The Arduino calculates the distance in centimeters.  
3. The LCD displays the measured value or "Out of Range".  
4. The RGB LED color changes according to the distance range.  
5. If out of range, the buzzer gives an audible warning.  
