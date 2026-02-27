# LDR-Light-Percentage-Display-on-LED-Matrix
Light intensity monitoring system using LDR sensor and MAX7219 8x8 LED Matrix to display real-time light percentage.
# LDR Percentage Display on LED Matrix (MAX7219)

## 📌 Project Overview
This project reads light intensity using an LDR sensor and displays the light percentage on a MAX7219 8x8 LED Matrix using the MD_Parola library.

The analog value from the LDR (0–1023) is converted into percentage (0–100%) and displayed in real-time on the LED matrix.

---

## 🛠 Components Used
- Arduino
- MAX7219 8x8 LED Matrix (4 Modules)
- LDR (Light Dependent Resistor)
- Resistor (10kΩ recommended)
- Jumper Wires

---

## 📚 Libraries Used
- MD_Parola
- MD_MAX72xx
- SPI

---

## ⚙️ Working Principle
1. The LDR senses light intensity.
2. Arduino reads analog value from pin A0.
3. The value (0–1023) is mapped into percentage (0–100%).
4. The percentage is displayed on the LED Matrix.

Example Output:
ldr45%
ldr87%

---

## 🔌 Pin Configuration
- CS Pin → 10
- LDR → A0
- SPI Pins → Default Arduino SPI pins

---

## 💡 Features
✔ Real-time light monitoring  
✔ Percentage conversion  
✔ LED matrix centered display  
✔ Clean and simple code  

---

## 📷 Project Image
![WhatsApp Image 2026-02-26 at 5 39 48 PM](https://github.com/user-attachments/assets/3266829e-6d67-4add-b263-f29b7a32ae45)


---

## 🚀 Future Improvements
- Auto brightness control based on light
- Scrolling effect
- Threshold-based warning display
- IoT based monitoring system

---

## 👩‍💻 Author
Alka Bhutta
